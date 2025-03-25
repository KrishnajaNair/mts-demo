/*! \file **********************************************************************

  COMPANY:              Continental Automotive Systems Lindau

  PROJECT:              MTS

  COMPONENT:            Exporter

  MODULNAME:            csvexporter.h

  DESCRIPTION:          <description>

  AUTHOR:               Erik Verhoeven, Grygoriy Bunin

  CREATION DATE:        10.04.2008

  VERSION:              $Revision: 1.23 $

  ---*/ /*---
  CHANGES:              $Log: csvexporter.h  $
  CHANGES:              Revision 1.23 2021/10/06 16:34:07CEST uidn1546 
  CHANGES:              Implemented option to set precision for floating point values in CSVExporter MO
  CHANGES:              Revision 1.22 2020/08/05 09:45:19CEST Kumar, Pravin02 (uids9855) 
  CHANGES:              To update the member revision.
  CHANGES:              Revision 1.21 2019/12/11 04:44:25CET Gopalreddy, Nithya (uids9569) 
  CHANGES:              Updated to fix the value mismatch
  CHANGES:              Revision 1.20 2019/03/06 13:14:28CET Kumar, Pravin02 (uids9855) 
  CHANGES:              Added feature to select and use the column delimiter for exporting.
  CHANGES:              Revision 1.19 2018/08/22 11:51:54CEST Kumar, Pravin02 (uids9855) 
  CHANGES:              Code updated to use Signal's original data type for the export.
  CHANGES:              Revision 1.18 2018/07/11 08:10:01CEST Kumar, Pravin02 (uids9855) 
  CHANGES:              Code updated to fix the not possible to run several CSV exporters at the same time.
  CHANGES:              Revision 1.17 2017/06/30 07:52:19CEST Shree, Smitha (uid33240) 
  CHANGES:              Fixed for CSVExporter which was rewriting on the CSV exported file when it already exists and has the same name
  CHANGES:              Revision 1.16 2016/02/16 13:29:39CET Crista, Ovidiu (uidu9556) 
  CHANGES:              Updated the usage of SDataPackageEx structure (after review)
  CHANGES:              Revision 1.15 2013/03/14 09:49:27CET Bejan, Cristian02 (uid95887) 
  CHANGES:              Removed unused macros:
  CHANGES:              DECLARE_SYNCHRONOUS_PROCESSING()
  CHANGES:              DECLARE_ASYNCHRONOUS_PROCESSING()
  CHANGES:              DECLARE_MESSAGE_LOOP_PROCESSING()
  CHANGES:              - Added comments -  uid95887 [Mar 14, 2013 9:49:27 AM CET]
  CHANGES:              Change Package : 177421:1 http://mks-psad:7002/im/viewissue?selection=177421
  CHANGES:              Revision 1.14 2012/09/11 17:19:02CEST Morut, Adrian (uid95484) 
  CHANGES:              Added new handling and a checkbox to allow the usage of output paths relative to the current user \data\ path.
  CHANGES:              --- Added comments ---  uid95484 [Sep 11, 2012 5:19:03 PM CEST]
  CHANGES:              Change Package : 151937:1 http://mks-psad:7002/im/viewissue?selection=151937
  CHANGES:              Revision 1.13 2012/07/10 16:45:07CEST Morut, Adrian (uid95484)
  CHANGES:              Added explanations for warning elimination via "!!" operator pairs.
  CHANGES:              Renamed SetTriggerType() to improve code readability.
  CHANGES:              --- Added comments ---  uid95484 [Jul 10, 2012 4:45:07 PM CEST]
  CHANGES:              Change Package : 138082:1 http://mks-psad:7002/im/viewissue?selection=138082
  CHANGES:              Revision 1.12 2012/02/08 18:44:49CET Morut, Adrian (uid95484)
  CHANGES:              Reworked the time period editbox handling so that the entered text is always processed ~400ms after the last user action, with no more need to change focus to save the data.
  CHANGES:              Reworked the output file writing methods to eliminate code duplication and confusion.
  CHANGES:              Reworked trigger-specific file-writing options setting to make it clear what's being done for which trigger type.
  CHANGES:              Re-arranged the existing controls on the Config tab to make it clear that 4 distinct and mutually exclusive trigger types are available.
  CHANGES:
  CHANGES:              Added a new triggering mechanism to write a new line to the output file every time a specified trigger-signal has been received (but only at the end of its host cycle, so that at least the signals from the same cycle will all have updated values).
  CHANGES:              --- Added comments ---  uid95484 [Feb 8, 2012 6:44:49 PM CET]
  CHANGES:              Change Package : 93684:1 http://mks-psad:7002/im/viewissue?selection=93684
  CHANGES:              Revision 1.11 2012/02/08 18:27:27CET Morut, Adrian (uid95484)
  CHANGES:              Improved symbol naming and enforced some coding guidelines.
  CHANGES:              Replaced fake BOOL types with true bool types wherever possible.
  CHANGES:              --- Added comments ---  uid95484 [Feb 8, 2012 6:27:27 PM CET]
  CHANGES:              Change Package : 93684:1 http://mks-psad:7002/im/viewissue?selection=93684
  CHANGES:              Revision 1.10 2012/01/30 15:43:42CET Morut, Adrian (uid95484)
  CHANGES:              Improved symbol naming and enforced some coding guidelines.
  CHANGES:              Replaced fake BOOL types with true bool types wherever possible.
  CHANGES:              --- Added comments ---  uid95484 [Jan 30, 2012 3:43:42 PM CET]
  CHANGES:              Change Package : 93684:1 http://mks-psad:7002/im/viewissue?selection=93684
  CHANGES:              Revision 1.9 2011/09/26 15:47:30CEST Morut Adrian (uid95484) (uid95484)
  CHANGES:              Use a more read-friendly name for the "ATL::CW2A" macro.
  CHANGES:              --- Added comments ---  uid95484 [Sep 26, 2011 3:47:30 PM CEST]
  CHANGES:              Change Package : 79623:1 http://mks-psad:7002/im/viewissue?selection=79623
  CHANGES:              Revision 1.8 2011/07/21 13:49:09CEST Verhoeven Erik (verhoevene) (verhoevene)
  CHANGES:              Fixed issues concerning system stability during measurement configuring,
  CHANGES:              offline support and enforced resetting of connections.
  CHANGES:              --- Added comments ---  verhoevene [Jul 21, 2011 1:49:09 PM CEST]
  CHANGES:              Change Package : 71837:1 http://mks-psad:7002/im/viewissue?selection=71837
  CHANGES:              Revision 1.7 2010/11/02 11:45:50CET Verhoeven Erik (verhoevene) (verhoevene)
  CHANGES:              Ported to UNICODE and ICSVExporterControl2
  CHANGES:              --- Added comments ---  verhoevene [Nov 2, 2010 11:45:50 AM CET]
  CHANGES:              Change Package : 51637:3 http://mks-psad:7002/im/viewissue?selection=51637
  CHANGES:              Revision 1.6 2010/09/30 13:40:27CEST Erik Verhoeven (verhoevene)
  CHANGES:              Prepare x64 compilation
  CHANGES:              --- Added comments ---  verhoevene [Sep 30, 2010 1:40:27 PM CEST]
  CHANGES:              Change Package : 51637:3 http://mks-psad:7002/im/viewissue?selection=51637
  CHANGES:              Revision 1.5 2009/01/26 11:37:30CET ostepan
  CHANGES:              Improve exporting of time-based signals.
  CHANGES:              --- Added comments ---  ostepan [2009/01/26 10:37:30Z]
  CHANGES:              Change Package : 21471:1 http://LISS014:6001/im/viewissue?selection=21471
  CHANGES:              Revision 1.4 2008/06/26 10:19:18CEST dfroehlich
  CHANGES:              * change: added file splitting for large files
  CHANGES:              * change: added file settings dialog
  CHANGES:              --- Added comments ---  dfroehlich [2008/06/26 08:19:18Z]
  CHANGES:              Change Package : 14290:1 http://liss014:6001/im/viewissue?selection=14290
  CHANGES:              Revision 1.3 2008/06/24 10:18:27CEST gbunin
  CHANGES:              Show a warning if the selected cycle doesn't exist
  CHANGES:              --- Added comments ---  gbunin [2008/06/24 13:55:49Z]
  CHANGES:              Change Package : 14288:12 http://liss014:6001/im/viewissue?selection=14288
  CHANGES:              Revision 1.2 2008/04/28 16:50:04CEST dfroehlich
  CHANGES:              * change: enable/disable overwriting of files
  CHANGES:              --- Added comments ---  dfroehlich [2008/04/28 14:50:04Z]
  CHANGES:              Change Package : 12339:1 http://liss014:6001/im/viewissue?selection=12339
  CHANGES:              Revision 1.1 2008/04/24 13:29:39CEST rhecker
  CHANGES:              Initial revision
  CHANGES:              Member added to project /nfs/projekte1/tools/custom/mts/sw/src/exporter/csvexporter/project.pj

**************************************************************************** */

#pragma once


#include "CSVExporterProps.h"
#include "ConfigPageDlg.h"
#include "ControlPageDlg.h"
#include <MTSDocking.h>


#define CSV_CONVERT_WSTR_TO_ANSI    CW2A

#define CSV_OUTFILE_CYCLESPECIFIC   true
#define CSV_OUTFILE_GENERIC         false

#define CSV_WRITE_CYCLECOUNTER      true
#define CSV_DONTWRITE_CYCLECOUNTER  false

#define CSV_EXCLUDE_OTHERCYCLES     true
#define CSV_DONTEXCLUDE_OTHERCYCLES false

#define CSV_EXCLUDE_NONCYCLEDATA        true
#define CSV_DONTEXCLUDE_NONCYCLEDATA    false

//! The length of the csv file extension inlcuding the dot. i.e., ".csv"
#define CSV_FILE_EXTENSION_LENGTH   4


//! Type that identifies a cycle by the source Handle and the Cycle ID
typedef std::pair<MTSHANDLE, DWORD> SSourceCycle;

//! Type that holds together the trigger-specific parameters of the output file writing process
typedef struct
{
    bool bCycleSpecificOutFile;
    bool bWriteCycleCounter;
    bool bExcludeOtherCycles;
    bool bExcludeNonCycleData;
} STrigSpecificWriteParams;


class CCSVExporter :
    public CMTSMeasObject,
    public ICSVExporterControl2
{
public:
// Construction / Destruction
    CCSVExporter();
   ~CCSVExporter();

// MTS Meas. object declarations
    DECLARE_DATAPROCESSOR()
    DECLARE_CLASS_NAME( L"CSVExporter" )
    DECLARE_DESCRIPTION( L"Export chosen signals to a .csv file" )
    DECLARE_AUTHOR(L"Erik Verhoeven, Grygoriy Bunin")
    DECLARE_PROJECT(L"MTS")
    DECLARE_INPUT_TYPE(L"UDEX*\0\0")
    DECLARE_ICON16(m_hIcon16)
    DECLARE_ICON32(m_hIcon32)
    DECLARE_ICON48(m_hIcon48)

    // Property table
    BEGIN_PROPERTY_TABLE()
        CHAIN_PROPERTY_TABLE_BASE(CMTSMeasObject)
        CHAIN_PROPERTY_TABLE(m_Properties)

        CPropertyInterpretation notEditableBool( PC_Bool );
        notEditableBool.bIsNotEditable = TRUE;

        CPropertyInterpretation notEditableText( PC_Text );
        notEditableText.bIsNotEditable = TRUE;

        CPropertyInterpretation notEditableNumber( PC_Number );
        notEditableNumber.bIsNotEditable = TRUE;

        PROPERTY_ENTRY_EXT( PROP_IS_EXPORTING,     m_bIsExporting,     PROP_CATEGORY_GENERAL, L"TRUE if export is active", notEditableBool );
        PROPERTY_ENTRY_EXT( PROP_OVERWRITE_OUTPUT, m_bAllowOverwriteOutput, PROP_CATEGORY_GENERAL, L"True if overwriting of output files is allowed. If not a unique file name is used.", notEditableBool);

        PROPERTY_ENTRY_EXT( PROP_TRIGGER_TYPE,     m_dwTriggerType,    PROP_CATEGORY_TRIGGER, L"Selected trigger type (timebase for writing new lines to the CSV file). 0 = all cycles, 1 = time based trigger, 2 = cycle based trigger, 3 = all signals, 4 = signal based trigger.", notEditableNumber );
        PROPERTY_ENTRY_EXT( PROP_SELECTED_CYCLE,   m_ssSelectedCycle,  PROP_CATEGORY_TRIGGER, L"Name of the selected cycle (only for trigger type = cycle)", notEditableText );
        PROPERTY_ENTRY_EXT( PROP_COLUMN_DELIMITER, m_iSelectedDelimiter, PROP_CATEGORY_GENERAL, L"", m_EnumDelimiterTypeInterpr);
		PROPERTY_ENTRY_EXT(PROP_SELECT_TIMESTAMP, m_iSelectedTimestamp, PROP_CATEGORY_GENERAL, L"", m_EnumTimestampTypeInterpr);

        PROPERTY_ENTRY_EXT( PROP_SELECTED_SIGNAL,  m_ssSelectedSignal, PROP_CATEGORY_TRIGGER, L"URL of the selected signal (only for trigger type = signal)", notEditableText );
        PROPERTY_ENTRY_EXT( PROP_TRIGGER_PERIOD,   m_dwTriggerPeriod,  PROP_CATEGORY_TRIGGER, L"Selected trigger period (only for trigger type = time period)", notEditableNumber );

        // Legacy property to ensure backward compatibility with existing CFGs
        // Remove this when reasonably certain that old CFGs are no longer being used
        //  *Old CFG = any CFG saved with MTS 2.4 build CW05(2012) or older versions
        PROPERTY_ENTRY_EXT( PROP_ISCYCLESELECTED,  m_bIsCycleSelected, PROP_CATEGORY_TRIGGER, L"True if trigger type = cycle. (Legacy prop. for backward compatibility.)", notEditableBool );
        
		PROPERTY_ENTRY_EXT(L"EnableFloatingPrecision", m_bIsFloatingPrecisionEnabled, PROP_CATEGORY_GENERAL, L"Enable precision for float values", propcatBool)
        PROPERTY_ENTRY_EXT(L"FloatingPrecisionDigits", m_iFloatingPrecisionDigits, PROP_CATEGORY_GENERAL, L"Set the digits of precision", propcatRange(1, 64))
			 
    END_PROPERTY_TABLE()

// MO Overridables

// IInterfaceAccess interface
// Get interface should direct the calls to the aggregated UDEXExporter
    virtual void*   GetInterface(LPCWSTR szIfcName);

    virtual BOOL    Initialize();
    virtual void    Terminate();
    virtual void    ConnectionChanged();
    virtual void    ValidateData( SDataPackageEx& packet );

    // ICSVExporterControl2 - declarations overlapping with those from IExporterControl (?!)
    virtual BOOL    SetSignalURLs(LPCWSTR* rgszSignalsURLs, unsigned int nURLsCount);
    virtual BOOL    GetSignalURL(unsigned int nURL, LPWSTR pBuffer, unsigned int& nBufferSize) const;
    virtual bool    SetOutDirRelative2Data( const bool bRelative2Data );
    virtual bool    GetOutDirRelative2Data( bool &bIsRelative2Data ) const;
    virtual BOOL    SetOutputDirectory( LPCWSTR szOutputDirName );
    virtual BOOL    GetOutputDirectory( LPWSTR pBuffer, unsigned int& nBufferSize ) const;
    virtual BOOL    SetOutputBaseFileName(LPCWSTR szOutputBaseFileName, BOOL bUseRecFileName );
    virtual BOOL    GetOutputBaseFileName(LPWSTR pBuffer, unsigned int& nBufferSize, BOOL &bUseRecFileName ) const;
    virtual BOOL    StartExporting();
    virtual BOOL    StopExporting();
    virtual BOOL    IsExporting() const;
    // ICSVExporterControl2 - unique declarations
    virtual bool    GetSelectedCycle( LPWSTR szCycleName, int nCycleNameLen );
    virtual bool    SetCycleSelected( LPCWSTR szCycleName );
    virtual bool    SetSignalSelected( LPCWSTR szSignalName );
    virtual bool    GetSelectedSignal( LPWSTR szSignalName, int nSignalNameLen );
    virtual bool    SetTriggerTypeAndWriteParams( DWORD dwTriggerType );
    virtual DWORD   GetTriggerType() const;
    virtual void    SetTriggerPeriod( DWORD dwTriggerTime );
    virtual DWORD   GetTriggerPeriod() const;
    virtual MTSHANDLE GetCSVExporterHandle();
    virtual HWND    CreatePropertyPage(HWND hParentWnd);

    virtual bool IsFileSizeConstrained();
    virtual bool SetFileSizeConstrained( bool bConstrainFileSize );
    virtual bool SetMaxFileSize( DWORD dwMaxFileSize );
    virtual DWORD GetMaxFileSize();
    virtual bool SetFilePartSuffix( LPCWSTR szFilePartName );
    virtual bool GetFilePartSuffix( LPWSTR szFilePartName, int nFilePartNameLen );

    virtual bool IsFileOverwrite();
    virtual bool SetFileOverwrite( bool bOverwrite );
    virtual void PropertyChanged(LPCWSTR szName);

    /**
    * @brief         Sets the delimiter to be written in the file.
    * @remarks       The user selected/entered delimiter will be set to 
    *                write into the file.
    *
    * @param[in]     strDelimiter      The delimiter which has to be written in
    *                                  in the output file
    * @author        Pravinkumar
    */
    virtual void SetDelimiter(CString &strDelimiter);

    /**
    * @brief         Updates the delimiter slection in Property page.
    * @remarks       Updates the user selected or entered delimiter 
    *                from file config page to property page.
    *
    * @param[in]     nIdx      The selected delimiter index value
    *                          to update the delimiter selection in property page.
    * @author        Pravinkumar
    */
    virtual void UpdatePropPageDelimiterSelection(int &nIdx);

    /**
    * @brief         Updates the delimiter in the property page.
    * @remarks       The user selected/entered delimiter will be set to
    *                write into the file.
    *
    * @param[in]     strDelimiter      The delimiter which has been selected 
    *                                  to be written in the output file
    * @author        Pravinkumar
    */
    virtual void UpdatePropPageDelimiter(CString & strDelimiter);

private:
    /**
     * Generate a generic output file name or a file name for a
     * specific cycle, with an optional part number suffix.
     *
     * @param ssOutputFileName The generated name of the output file
     * @param dwOutputFilePart The part number of the output file
     * @return Returns @b true if successful
     */
    bool GenerateOutputFileName( std::wstring& ssOutputFileName, DWORD dwOutputFilePart );

    /**
     * Find or create a cycle-specific output file for the given source
     * cycle or a generic, non-cycle-specific output file.
     *
     * @return A pointer to CAtlFile if successful, NULL otherwise.
     */
    CAtlFile* FindOrCreateOutputFile();

    /**
     *
     *
     * @param pCSVFile Pointer to a CAtlFile corresponding to the file
     *                 that must be written to.
     *
     * @return true if data was successfully written to the output file,
     *         false if some error occured
     */
    bool WriteTableHeaderToOutputFile( CAtlFile* pCSVFile );

    /**
     * Write timestamps, cycle counters (optional) and all relevant
     * signal values to the output file.
     *
     * @return true if data was successfully written to the output file,
     *         false if some error occured
     */
    bool WriteDataToOutputFile( unsigned __int64 uqiTimeStamp, unsigned __int64 uqiUtcTimestamp);

    /**
     * Save the values of the output path properties: the flag for relative output
	 *  path handling and the output path string.
     */
    void SaveOutputDirOptions( bool bRelative2Data, CString strOutputPath );

    /// MO Icons
    HICON                   m_hIcon16;
    HICON                   m_hIcon32;
    HICON                   m_hIcon48;

    // UDEXExporter
    IUDEXDataExport*        m_pUDEXDataExporter;

    static const int		m_nDelimiterTypes = 5;
	static const int		m_nTimestampTypes = 3;

    static std::wstring     m_arrayIndexToDelimiterString[m_nDelimiterTypes];
	static std::wstring     m_arrayIndexToTimestampString[m_nTimestampTypes];

    //! Flag to indicate if exporting is active
    bool                    m_bIsExporting;

    //! Trigger type - cycle(s), signal(s) or time period
    DWORD                   m_dwTriggerType;

    // Cycle used as trigger
    bool                    m_bIsCycleSelected; // CFG backward-compatibility
    SSourceCycle            m_SelectedCycle;
    std::wstring            m_ssSelectedCycle;

    // Signal used as trigger
    bool                    m_bTrigSignalSelected;
    std::wstring            m_ssSelectedSignal;

    CPropertyInterpretation m_EnumDelimiterTypeInterpr;
	CPropertyInterpretation m_EnumTimestampTypeInterpr;
    int                     m_iSelectedDelimiter;
	int						m_iSelectedTimestamp;

    STrigSpecificWriteParams m_sWriteParams;

    //! Time period used to generate triggers [us]
    DWORD                   m_dwTriggerPeriod;
    //! Minimum acceptable trigger period [us]
    static const DWORD      CSV_REASONABLE_TRIGGERPERIOD = 1000;
    //! Flag to indicate the first packet received after starting to export
    bool                    m_bFirstPacketAfterStart;
    //! Timestamp of the most recent data row written to the output file
    unsigned __int64        m_uqiLastExportTimeStamp;
	unsigned __int64        m_uqiLastExportHWTimeStamp;
    // Source and cycle data of the latest packet
    MTSHANDLE               m_dwLatestPacket_SrcHandle;
    WORD                    m_wLatestPacket_TaskID;
    unsigned __int64        m_uqiLatestPacket_CycleCounter;

    bool                    m_bUseRecFileName;
    bool                    m_bIsOutDirRelative;
    std::wstring            m_ssOutputDirectory_AbsPath;
    std::wstring            m_ssOutputDirectory_RelPath;
    std::wstring            m_ssBaseFileName;
    CURLsVector             m_vecAttachedSigURLs;

    // MO Properties
    CCSVExporterProps       m_Properties;

    // MO property pages
    CConfigPageDlg          m_pageConfig;
    CControlPageDlg         m_pageControl;

    ExportSignal_t*         m_pExportSignals;
    DWORD                   m_dwNumberOfSignals;

    static const wchar_t    CSV_OUTFILE_EXTENSION[_MAX_EXT];

    //! Map with output files for each cycle, for cycle based export only
    std::map<SSourceCycle, CAtlFile*> m_mapCycleSpecificOutputFiles;

    /**
     * @brief Flag to indicate if we should show a warning if the
     *          cycle/signal that is currently selected as trigger doesn't
     *          exist, for cycle based export only
     */
    bool                    m_bWarnIfTriggerInexistent;

    //! Flag to indicate if overwriting of output files is allowed
    bool                    m_bAllowOverwriteOutput;

    CAtlFile                m_GenericOutputFile; //!< for time based export only
    bool                    m_bGenericOutputFileExists; //!< for time based export only
    DWORD                   m_dwGenericOutputFilePart; //!< for time based export only
    std::wstring            m_ssOutFilePartSuffix; //!< CSV file part name

    std::map<SSourceCycle, DWORD> m_mapCycSpecificOutFileParts;

    // File size constraints
    bool                    m_bConstrainFileSize;   //!< True if file size is constrained
    DWORD                   m_dwMaxFileSize;    //!< Max. size of CSV files [MB]

    std::map<std::wstring, SSourceCycle> m_mapCycles;

    unsigned __int64        m_uqiRelRecStartTime; //! Rec file offset (for offline only)

    // TabHandles for docking windows
    TabHandle               m_hControlPageDlgTabHandle;
    TabHandle               m_hConfigPageDlgTabHandle;

    bool m_bTrigSignalDetected;
    DWORD m_dwTrigSignalCycleID;

    //Column Delimiter
    CStringA m_strDelimiter;

	bool bMTS_Timestamp;
	bool bUTC_HW_Timestamp;
	bool          m_bIsFloatingPrecisionEnabled;
	int           m_iFloatingPrecisionDigits;
};

