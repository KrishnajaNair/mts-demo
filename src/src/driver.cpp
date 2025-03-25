
#include "driver.hpp"
#include "scanner.hpp"
#include "util.hpp"

#include <fstream>
#include <sstream>
#include <type_traits>

#include <mts/introspection/xtypes/annotation.hpp>
#include <mts/platform/filesystem.hpp>
#include <mts/runtime/io/file_stream.hpp>
#include <mts/utility/encoding.hpp>

#include <mts/toolbox/ros/util.hpp>

namespace mts
{
    namespace toolbox
    {
        namespace ros
        {
            driver::driver(std::optional<resolve_type_callback> callback) : driver(false, callback)
            {
            }

            driver::driver(bool trace, std::optional<resolve_type_callback> callback) : driver(trace, trace, callback)
            {
            }

            driver::driver(bool trace_scanning, bool trace_parsing, std::optional<resolve_type_callback> callback)
                : trace_scanning_(trace_scanning), trace_parsing_(trace_parsing)
            {
                if (callback.has_value())
                {
                    resolve_type_callback_ = callback.value();
                }
            }

            std::shared_ptr<mts::introspection::xtypes::parser::module> driver::get_specification() const
            {
                // Return the result of the parsing
                return module_;
            }

            void driver::yywarning(const char *format, ...)
            {
                char buffer[1024];
                va_list args;
                va_start(args, format);
                vsnprintf(buffer, sizeof(buffer), format, args);
                va_end(args);
                warnings_.push_back(buffer);
            }

            void driver::yyerror(const char *format, ...)
            {
                char buffer[1024];
                va_list args;
                va_start(args, format);
                vsnprintf(buffer, sizeof(buffer), format, args);
                va_end(args);
                errors_.push_back(buffer);
            }

            void driver::yyabort(const char *error)
            {
                throw std::runtime_error(error);
            }

            void
            driver::parse_file(const std::shared_ptr<std::string> &package, const std::shared_ptr<std::string> &module, const std::shared_ptr<std::string> &type, const std::shared_ptr<std::string> &path, std::unique_ptr<mts::runtime::io::filesystem> &&filesystem)
            {
                auto file = filesystem->open(path, "r", true);
                std::shared_ptr<mts::runtime::io::file> shared_file_ptr{std::move(file)};

                filesystem_ = std::move(filesystem);

                // Use the iostream wrapper for an MTS instrumented file
                // to read the file content into a string.
                mts::runtime::io::file_iostream stream(shared_file_ptr);
                std::shared_ptr<std::string> content(std::istreambuf_iterator<char>(stream), {});

                auto type_name = type;
                if (type_name.empty())
                {
                    // Try use filename as type name if the specified type name was empty
                    type_name = std::filesystem::path(shared_file_ptr->filename()).stem().string();
                }

                parse(package, module, type_name, content);
            }

            void
            driver::parse(const std::shared_ptr<std::string> &package, const std::shared_ptr<std::string> &module, const std::shared_ptr<std::string> &type, const std::shared_ptr<std::string> &content)
            {
                // Store package and module name for type name callback.
                //
                // For example, parsing 'CameraInfo.msg' with package = 'sensor_msgs' and module = 'msg'
                // and we encounter a field 'RegionOfInterest roi' (without full type name) then for the 'RegionOfInterest' type resolution we assume the
                // same package and message as the ones specified at the top level
                package_name_ = package;
                module_name_ = module;
                // Create the top level XTypes modules which will host all parsed types
                module_ = std::make_shared<mts::introspection::xtypes::parser::module>();
                // The current XTypes module is the top level one
                current_module_ = module_;
                // Clear internal state for previous parsing operations (if any)
                errors_.clear();
                warnings_.clear();
                std::stack<std::shared_ptr<std::string>> empty;
                struct_name_stack_.swap(empty);
                parse_internal(package, module, type, content);
            }

            void
            driver::parse_internal(const std::shared_ptr<std::string> &package, const std::shared_ptr<std::string> &module, const std::shared_ptr<std::string> &type, const std::shared_ptr<std::string> &content)
            {
                // This function must be reentrant. Whenever a parser has to resolve a type the current parsing is "suspended"
                // and a new (type) parsing starts by calling this function
                using namespace mts::utility;

                // Handle various text encodings that we may receive as input
                std::shared_ptr<std::string> decoded_content = decode_string(reinterpret_cast<const uint8_t *>(content.data()), content.size(), mts::utility::encoding::encoding_utf8);

                std::shared_ptr<std::string>stream stream(decoded_content);

                // Create lexical scanner
                auto scanner_ptr = std::make_unique<scanner>(*this, &stream);
                if (trace_scanning_)
                    scanner_ptr->set_debug(1);
                // Create grammar parser
                auto parser_ptr = std::make_unique<bison_parser>((*scanner_ptr) /* scanner */, (*this) /* driver */);
                if (trace_parsing_)
                    parser_ptr->set_debug_level(1);

                // Push on the stack the current module
                // which has to be restored after the parsing step
                module_stack_.push(current_module_);

                // Restore current module to root
                current_module_ = module_;
                // If package was specified create a module,
                // otherwise an anonymous module will be used
                if (!package.empty())
                    declare_module(package);
                // Declare 'msg' submodule
                declare_module(module);

                // Does the current module already have the specified type
                if (!current_module_->has_structure(type))
                {
                    // Declare the structure
                    current_module_->structure_decl(std::make_shared<mts::introspection::xtypes::struct_type>(type));
                    // Push on the stack the currently parsed type name
                    struct_name_stack_.push(type);

                    // Start parsing the message definition
                    if (0 != parser_ptr->parse())
                    {
                        throw std::runtime_error("an error occurred while parsing the message definition file");
                    }
                    // Restore the currently parsed type name
                    struct_name_stack_.pop();
                }

                // Restore current module to previous
                current_module_ = module_stack_.top();
                module_stack_.pop();
            }

            void driver::declare_module(std::shared_ptr<std::string> name)
            {
                if (current_module_ == nullptr)
                    throw std::runtime_error("unexpected module logic");

                // Does the module already has a submodule declared?
                if (current_module_->has_submodule(name))
                {
                    // Yes, set the current module to the submodule
                    current_module_ = current_module_->submodule(name);
                }
                else
                {
                    // No, create the submodule and then set the current module to the submodule
                    current_module_->create_submodule(name);
                    current_module_ = current_module_->submodule(name);
                }
            }

            void driver::declare_field(const std::shared_ptr<std::string> &name, mts::introspection::xtypes::dynamic_type::ptr type)
            {
                // The parser calls this function to add a member (field) to the currently parsed type
                if (current_module_->has_structure(struct_name_stack_.top()))
                {
                    // From the current module access the structure being currently parsed
                    auto &structure = current_module_->get_structure(struct_name_stack_.top());
                    // Add member
                    structure.add_member(name, *type);
                    // Ugly hack: copy type annotations (if present) as member annotations
                    if (!type->annotations().empty())
                    {
                        for (const auto &annotation : type->annotations())
                        {
                            structure.annotate_member(name, annotation);
                        }
                    }
                }
                else
                {
                    throw std::invalid_argument("unexpected parser state");
                }
            }

            mts::introspection::xtypes::dynamic_type::ptr driver::declare_array(mts::introspection::xtypes::dynamic_type::ptr type, std::optional<std::uint64_t> dimension)
            {
                // Create a fixed or bounded/unbounded array
                auto array_type = mts::introspection::xtypes::array_type(*type, static_cast<std::size_t>(dimension.value_or(255U)));
                if (!dimension.has_value())
                {
                    // Not a fixed size array, annotate the array type with 'unbounded' annotation
                    array_type.add_annotation(mts::introspection::xtypes::annotation::unbounded_annotation());
                }
                return array_type;
            }

            mts::introspection::xtypes::dynamic_type::ptr driver::declare_string()
            {
                // Declares a string as fixed size char array
                auto array_type = mts::introspection::xtypes::array_type(mts::introspection::xtypes::declare_primitive_type<char>(), 255U);
                array_type.add_annotation(mts::introspection::xtypes::annotation::unbounded_annotation());
                return array_type;
            }

            mts::introspection::xtypes::dynamic_type::ptr driver::resolve_type(const std::shared_ptr<std::string> &type_name)
            {
                // Resolves (non-primitive) types encountered in the current parsing context
                auto scoped_type_name = type_name;
                if (type_name == "Header")
                    scoped_type_name = "std_msgs/msg/Header";

                // Delegate type resolution to the parent parser.
                // This should give us the message definition of the type we are trying to resolve
                auto type_content = resolve_type_callback_(scoped_type_name);

                // Get parts of the scoped type name
                auto [package, module, type] = get_package_resource_name_parts(scoped_type_name);

                if (package.empty())
                    package = package_name_;
                if (module.empty())
                    module = module_name_;

                // "Fork" parsing the type
                parse_internal(package, module, type, type_content);

                // After the parsing finished, we should have the dynamic type introduced into the module hierarchy
                auto xtypes_scoped_type_name = package.append(module_->type_delimiter()).append(module).append(module_->type_delimiter()).append(type);
                auto resolved_type = module_->get_type(xtypes_scoped_type_name);
                if (!resolved_type)
                    throw std::invalid_argument(std::shared_ptr<std::string>("cannot resolve type '").append(type_name).append("'"));
                // Give back the parser the XTypes dynamic type representing the resolved type
                return resolved_type;
            }
        } // namespace ros
    } // namespace toolbox
} // namespace mts
