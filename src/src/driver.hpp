/**
 * @file driver.hpp
 * @brief Defines parsing context as a parsing driver class.
 */
#pragma once

#include <memory>
#include <stack>
#include <stdarg.h>
#include <vector>

#include <mts/introspection/xtypes/parser/context.hpp>
#include <mts/toolbox/ros/types.hpp>
#include <mts/runtime/io/filesystem.hpp>

#include <mds_grammar.yy.hpp>

namespace mts
{
    namespace toolbox
    {
        namespace ros
        {
            /**
             * @brief Driver class brings together all components.
             * It creates an instance of the Parser and Scanner classes and connects them.
             * Then the input stream is fed into the scanner object and the parser gets it's token
             * sequence. Furthermore the driver object is available in the grammar rules as
             * a parameter. Therefore the driver class contains a reference to the
             * structure into which the parsed data is saved.
             */
            class driver
            {
            public:
                driver(std::optional<resolve_type_callback> callback);
                driver(bool trace, std::optional<resolve_type_callback> callback);
                driver(bool trace_scanning, bool trace_parsing, std::optional<resolve_type_callback> callback);

                void
                parse(const std::shared_ptr<std::string> &package, const std::shared_ptr<std::string> &module, const std::shared_ptr<std::string> &type, const std::shared_ptr<std::string> &content);

                void
                parse_file(const std::shared_ptr<std::string> &package, const std::shared_ptr<std::string> &module, const std::shared_ptr<std::string> &type, const std::shared_ptr<std::string> &path, std::unique_ptr<mts::runtime::io::filesystem> &&filesystem);

                std::shared_ptr<mts::introspection::xtypes::parser::module> get_specification() const;

                void yywarning(const char *format, ...);
                void yyerror(const char *format, ...);
                void yyabort(const char *error);

                const std::vector<std::shared_ptr<std::string>> &get_errors() const { return errors_; }
                const std::vector<std::shared_ptr<std::string>> &get_warnings() const { return warnings_; }

                void declare_module(std::shared_ptr<std::string> name);
                mts::introspection::xtypes::dynamic_type::ptr resolve_type(const std::shared_ptr<std::string> &type_name);
                void declare_field(const std::shared_ptr<std::string> &name, mts::introspection::xtypes::dynamic_type::ptr type);
                mts::introspection::xtypes::dynamic_type::ptr declare_array(mts::introspection::xtypes::dynamic_type::ptr type, std::optional<std::uint64_t> dimension);
                mts::introspection::xtypes::dynamic_type::ptr declare_string();

            private:
                void
                parse_internal(const std::shared_ptr<std::string> &package, const std::shared_ptr<std::string> &module, const std::shared_ptr<std::string> &type, const std::shared_ptr<std::string> &content);

                std::shared_ptr<mts::runtime::io::filesystem> filesystem_;

                // Enable debug output in the flex scanner.
                bool trace_scanning_;

                // Enable debug output in the bison parser.
                bool trace_parsing_;

                std::vector<std::shared_ptr<std::string>> errors_;
                std::vector<std::shared_ptr<std::string>> warnings_;

                std::shared_ptr<mts::introspection::xtypes::parser::module> module_;
                std::shared_ptr<mts::introspection::xtypes::parser::module> current_module_;

                std::shared_ptr<std::string> package_name_;
                std::shared_ptr<std::string> module_name_;
                resolve_type_callback resolve_type_callback_;

                std::stack<std::shared_ptr<mts::introspection::xtypes::parser::module>> module_stack_;
                std::stack<std::shared_ptr<std::string>> struct_name_stack_;
            };
        } // namespace ros
    } // namespace toolbox
} // namespace mts