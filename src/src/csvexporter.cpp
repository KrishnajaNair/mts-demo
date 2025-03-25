/*! \file **********************************************************************

  COMPANY:              Continental Automotive Systems Lindau

  PROJECT:              MTS

  COMPONENT:            Exporter

  MODULNAME:            csvexporter.cpp

  DESCRIPTION:          <description>

  AUTHOR:               <Author>

  CREATION DATE:        10.04.2008

  VERSION:              $Revision: 1.55 $

  ---*/ /*---
  CHANGES:              $Log: csvexporter.cpp  $
  CHANGES:              Revision 1.55 2022/03/16 11:07:30CET Suresh, Onteru (uie66724) (uie66724) 
  CHANGES:              Updating the MO for Dword and long data types.
  CHANGES:              Revision 1.54 2021/12/21 12:20:03CET Karindi, Aditya (uidn1546) 
  CHANGES:              Provided fix for few signals displaying junk values when Floating Precision option is set to TRUE in CSV Exporter MO with x64 release
  CHANGES:              Revision 1.53 2021/10/06 16:35:36CEST Karindi, Aditya (uidn1546) 
  CHANGES:              Implemented option to set precision for floating point values in CSVExporter MO
  CHANGES:              Revision 1.52 2020/08/25 13:52:13CEST Kapuluru, VamsiKrishna (uidj4496) (uidj4496) 
  CHANGES:              format specifier updated for int64 and uint64
  CHANGES:              Revision 1.51 2020/08/05 09:42:36CEST Kumar, Pravin02 (uids9855) 
  CHANGES:              To update the member revision.
  CHANGES:              Revision 1.50 2019/12/11 04:59:57CET Gopalreddy, Nithya (uids9569) 
  CHANGES:              Fixed the value mismatch between csv and table visualization
  CHANGES:              Revision 1.49 2019/06/10 05:32:31CEST Gopalreddy, Nithya (uids9569) 
  CHANGES:              Code updated to fix the Datatype format specifier mismatch
  CHANGES:              Revision 1.48 2019/05/28 05:17:51CEST Gopalreddy, Nithya (uids9569) 
  CHANGES:              code updated to fix the Data type format specifier mismatch
  CHANGES:              Revision 1.47 2019/03/29 11:08:47CET Kumar, Pravin02 (uids9855) 
  CHANGES:              Fixed the issue of No cycles available for selection in the cycle selection dropdown menu of CSVExporter MO
  CHANGES:              Revision 1.46 2019/03/27 11:57:23CET Kumar, Pravin02 (uids9855) 
  CHANGES:              Code updated to fix the csv exporter crash while entering more than one delimiter.
  CHANGES:              Revision 1.45 2019/03/27 05:44:22CET Kumar, Pravin02 (uids9855) 
  CHANGES:              Code updated to fix the issue CSV Exporter Crash.
  CHANGES:              Revision 1.44 2019/03/20 07:12:22CET Kumar, Pravin02 (uids9855) 
  CHANGES:              Code has been updated to fix the CSV exporter crash while entering more than one delimiter.
  CHANGES:              Revision 1.43 2019/03/06 13:13:37CET Kumar, Pravin02 (uids9855) 
  CHANGES:              Added feature to select and use the column delimiter for exporting.
  CHANGES:              Revision 1.42 2018/08/22 11:58:19CEST Kumar, Pravin02 (uids9855) 
  CHANGES:              Code updated to use Signal's original data type for the export.
  CHANGES:              Revision 1.41 2018/08/22 07:14:19CEST Kumar, Pravin02 (uids9855) 
  CHANGES:              Code updated to remove the trailing delimiter.
  CHANGES:              Revision 1.40 2018/07/11 08:08:39CEST Kumar, Pravin02 (uids9855) 
  CHANGES:              Code updated to fix the not possible to run several CSV exporters at the same time.
  CHANGES:              Revision 1.39 2017/11/09 09:57:51CET Fernandez, Christopher (uidp7755) 
  CHANGES:              Changed the pop-up that is displayed when the file permission is read-only.
  CHANGES:              Revision 1.38 2017/08/23 11:04:24CEST Naganna, Sujatha (uidq6105) 
  CHANGES:              Code updated to fix the issue of MTS crash when the "Split large files into parts" option is selected in CSVExporter: config.
  CHANGES:              Revision 1.37 2017/07/04 11:45:09CEST Shree, Smitha (uid33240) 
  CHANGES:              Updated and addressed external code review comments
  CHANGES:              Revision 1.36 2017/06/30 07:49:13CEST Shree, Smitha (uid33240) 
  CHANGES:              Fixed for CSVExporter which was rewriting on the CSV exported file when it already exists and has the same name
  CHANGES:              Revision 1.35 2017/02/17 08:16:13CET Crista, Ovidiu (uidu9556) 
  CHANGES:              Updates to remove compiler warnings/
  CHANGES:              Treat Warning As Errors introduced
  CHANGES:              Revision 1.34 2016/07/18 10:37:13CEST Barac, Cristian (uidt4719) 
  CHANGES:              added fix for x64 export
  CHANGES:              Revision 1.33 2016/02/16 13:29:04CET Crista, Ovidiu (uidu9556) 
  CHANGES:              Updated the usage of SDataPackageEx structure (after review)
  CHANGES:              Revision 1.32 2016/02/12 08:59:44CET Crista, Ovidiu (uidu9556) 
  CHANGES:              Updated the usage of SDataPackageEx structure
  CHANGES:              Revision 1.31 2013/10/31 08:23:44CET Bunin-EXT, Grygoriy (x-buning) 
  CHANGES:              Removed ANSI compatibility
  CHANGES:              - Added comments -  x-buning [Oct 31, 2013 8:23:44 AM CET]
  CHANGES:              Change Package : 203596:1 http://mks-psad:7002/im/viewissue?selection=203596
  CHANGES:              Revision 1.30 2012/09/11 17:19:02CEST Morut, Adrian (uid95484) 
  CHANGES:              Added new handling and a checkbox to allow the usage of output paths relative to the current user \data\ path.
  CHANGES:              --- Added comments ---  uid95484 [Sep 11, 2012 5:19:02 PM CEST]
  CHANGES:              Change Package : 151937:1 http://mks-psad:7002/im/viewissue?selection=151937
  CHANGES:              Revision 1.29 2012/07/18 17:08:50CEST Morut, Adrian (uid95484)
  CHANGES:              Changed detection method for non-cycle trigger-signal to use the Cycle State instead of the Cycle ID = 0.
  CHANGES:              Changed BOOL-to-bool conversion warning workaround.
  CHANGES:              --- Added comments ---  uid95484 [Jul 18, 2012 5:08:54 PM CEST]
  CHANGES:              Change Package : 122864:1 http://mks-psad:7002/im/viewissue?selection=122864
  CHANGES:              Revision 1.28 2012/07/10 16:45:06CEST Morut, Adrian (uid95484)
  CHANGES:              Added explanations for warning elimination via "!!" operator pairs.
  CHANGES:              Renamed SetTriggerType() to improve code readability.
  CHANGES:              --- Added comments ---  uid95484 [Jul 10, 2012 4:45:06 PM CEST]
  CHANGES:              Change Package : 138082:1 http://mks-psad:7002/im/viewissue?selection=138082
  CHANGES:              Revision 1.27 2012/07/06 13:15:38CEST Morut, Adrian (uid95484)
  CHANGES:              Added call to set the Write Parameters also for a Trigger Type loaded from a CFG.
  CHANGES:              Fixed a logical && condition.
  CHANGES:              Eliminated several useless int-to-bool warnings.
  CHANGES:              --- Added comments ---  uid95484 [Jul 6, 2012 1:15:39 PM CEST]
  CHANGES:              Change Package : 84289:34 http://mks-psad:7002/im/viewissue?selection=84289
  CHANGES:              Revision 1.26 2012/02/09 10:13:40CET Morut, Adrian (uid95484)
  CHANGES:              Fixed signal-trigger condition to allow the use of non-cycle signals that are never followed by a cycle_end packet.
  CHANGES:              --- Added comments ---  uid95484 [Feb 9, 2012 10:13:41 AM CET]
  CHANGES:              Change Package : 93684:1 http://mks-psad:7002/im/viewissue?selection=93684
  CHANGES:              Revision 1.25 2012/02/08 18:44:47CET Morut, Adrian (uid95484)
  CHANGES:              Reworked the time period editbox handling so that the entered text is always processed ~400ms after the last user action, with no more need to change focus to save the data.
  CHANGES:              Reworked the output file writing methods to eliminate code duplication and confusion.
  CHANGES:              Reworked trigger-specific file-writing options setting to make it clear what's being done for which trigger type.
  CHANGES:              Re-arranged the existing controls on the Config tab to make it clear that 4 distinct and mutually exclusive trigger types are available.
  CHANGES:
  CHANGES:              Added a new triggering mechanism to write a new line to the output file every time a specified trigger-signal has been received (but only at the end of its host cycle, so that at least the signals from the same cycle will all have updated values).
  CHANGES:              --- Added comments ---  uid95484 [Feb 8, 2012 6:44:47 PM CET]
  CHANGES:              Change Package : 93684:1 http://mks-psad:7002/im/viewissue?selection=93684
  CHANGES:              Revision 1.24 2012/02/08 18:27:25CET Morut, Adrian (uid95484)
  CHANGES:              Improved symbol naming and enforced some coding guidelines.
  CHANGES:              Replaced fake BOOL types with true bool types wherever possible.
  CHANGES:              --- Added comments ---  uid95484 [Feb 8, 2012 6:27:26 PM CET]
  CHANGES:              Change Package : 93684:1 http://mks-psad:7002/im/viewissue?selection=93684
  CHANGES:              Revision 1.23 2012/01/30 15:43:28CET Morut, Adrian (uid95484)
  CHANGES:              Improved symbol naming and enforced some coding guidelines.
  CHANGES:              Replaced fake BOOL types with true bool types wherever possible.
  CHANGES:              --- Added comments ---  uid95484 [Jan 30, 2012 3:43:31 PM CET]
  CHANGES:              Change Package : 93684:1 http://mks-psad:7002/im/viewissue?selection=93684
  CHANGES:              Revision 1.22 2011/09/26 15:46:09CEST Morut, Adrian (uid95484)
  CHANGES:              Reintroduce erroneously eliminated Unicode2ANSI conversion of the URL strings.
  CHANGES:              --- Added comments ---  uid95484 [Sep 26, 2011 3:46:09 PM CEST]
  CHANGES:              Change Package : 79623:1 http://mks-psad:7002/im/viewissue?selection=79623
  CHANGES:              Revision 1.21 2011/08/12 17:33:09CEST Morut Adrian (uid95484) (uid95484)
  CHANGES:              Applied the changes from rev1.20 in 3 more places where they were relevant.
  CHANGES:              --- Added comments ---  uid95484 [Aug 12, 2011 5:33:09 PM CEST]
  CHANGES:              Change Package : 74622:2 http://mks-psad:7002/im/viewissue?selection=74622
  CHANGES:              Revision 1.20 2011/08/03 13:54:37CEST Morut Adrian (uid95484) (uid95484)
  CHANGES:              Returned to CString implementation of WriteCycleDataToCSV() in order to preserve the old approximation method for double values (as implemented in CString::Format()).
  CHANGES:              Used CStringA instead of CString to ensure ANSI output.
  CHANGES:              --- Added comments ---  uid95484 [Aug 3, 2011 1:54:37 PM CEST]
  CHANGES:              Change Package : 70197:1 http://mks-psad:7002/im/viewissue?selection=70197
  CHANGES:              Revision 1.18 2011/05/10 09:53:01CEST Bejan Cristian (uid95887) (uid95887)
  CHANGES:              Text in csv files should be ANSI
  CHANGES:              --- Added comments ---  uid95887 [May 10, 2011 9:53:01 AM CEST]
  CHANGES:              Change Package : 66644:1 http://mks-psad:7002/im/viewissue?selection=66644
  CHANGES:              Revision 1.17 2010/11/02 11:45:50CET Erik Verhoeven (verhoevene)
  CHANGES:              Ported to UNICODE and ICSVExporterControl2
  CHANGES:              --- Added comments ---  verhoevene [Nov 2, 2010 11:45:50 AM CET]
  CHANGES:              Change Package : 51637:3 http://mks-psad:7002/im/viewissue?selection=51637
  CHANGES:              Revision 1.16 2010/09/30 13:40:26CEST Erik Verhoeven (verhoevene)
  CHANGES:              Prepare x64 compilation
  CHANGES:              --- Added comments ---  verhoevene [Sep 30, 2010 1:40:26 PM CEST]
  CHANGES:              Change Package : 51637:3 http://mks-psad:7002/im/viewissue?selection=51637
  CHANGES:              Revision 1.15 2010/01/13 09:55:25CET ostepan
  CHANGES:              Ignore packages with timestamp from the past.
  CHANGES:              --- Added comments ---  ostepan [2010/01/13 08:55:25Z]
  CHANGES:              Change Package : 35800:1 http://LISS014:6001/im/viewissue?selection=35800
  CHANGES:              Revision 1.14 2009/11/04 12:12:46EET Ioana Luputi (iluputi)
  CHANGES:              split issue solved
  CHANGES:              --- Added comments ---  iluputi [2009/11/04 10:12:46Z]
  CHANGES:              Change Package : 33548:1 http://LISS014:6001/im/viewissue?selection=33548
  CHANGES:              Revision 1.13 2009/08/05 18:45:35EEST tbass
  CHANGES:              change open state
  CHANGES:              --- Added comments ---  tbass [2009/08/05 15:45:35Z]
  CHANGES:              Change Package : 29580:1 http://LISS014:6001/im/viewissue?selection=29580
  CHANGES:              Revision 1.12 2009/07/14 17:16:42CEST Ovidiu Stepan (ostepan)
  CHANGES:              Packages from the past - just export them without proccessing.
  CHANGES:              --- Added comments ---  ostepan [2009/07/14 15:16:42Z]
  CHANGES:              Change Package : 28453:1 http://LISS014:6001/im/viewissue?selection=28453
  CHANGES:              Revision 1.11 2009/07/07 14:37:53EEST Ovidiu Stepan (ostepan)
  CHANGES:              Correctly handling for packages from the past.
  CHANGES:              --- Added comments ---  ostepan [2009/07/07 11:37:53Z]
  CHANGES:              Change Package : 28453:1 http://LISS014:6001/im/viewissue?selection=28453
  CHANGES:              Revision 1.10 2009/02/11 16:52:57EET Cristian02 Bejan (c02bejan)
  CHANGES:              Bug fix after prerelease tests.
  CHANGES:              --- Added comments ---  c02bejan [2009/02/11 14:52:57Z]
  CHANGES:              Change Package : 21476:1 http://LISS014:6001/im/viewissue?selection=21476
  CHANGES:              Revision 1.9 2009/01/26 17:48:58EET Ovidiu Stepan (ostepan)
  CHANGES:              Update GUI on load settings.
  CHANGES:              --- Added comments ---  ostepan [2009/01/26 15:48:58Z]
  CHANGES:              Change Package : 21472:1 http://LISS014:6001/im/viewissue?selection=21472
  CHANGES:              Revision 1.8 2009/01/26 12:37:22EET Ovidiu Stepan (ostepan)
  CHANGES:              Improve exporting of time-based signals.
  CHANGES:              --- Added comments ---  ostepan [2009/01/26 10:37:22Z]
  CHANGES:              Change Package : 21471:1 http://LISS014:6001/im/viewissue?selection=21471
  CHANGES:              Revision 1.7 2008/06/26 10:19:18CEST dfroehlich
  CHANGES:              * change: added file splitting for large files
  CHANGES:              * change: added file settings dialog
  CHANGES:              --- Added comments ---  dfroehlich [2008/06/26 08:19:18Z]
  CHANGES:              Change Package : 14290:1 http://liss014:6001/im/viewissue?selection=14290
  CHANGES:              Revision 1.6 2008/06/24 10:39:48CEST gbunin
  CHANGES:              Show a warning if the selected cycle doesn't exist
  CHANGES:              --- Added comments ---  gbunin [2008/06/24 13:55:48Z]
  CHANGES:              Change Package : 14288:12 http://liss014:6001/im/viewissue?selection=14288
  CHANGES:              Revision 1.5 2008/06/20 13:55:49CEST gbunin
  CHANGES:              Added DetachPage() in Terminate()
  CHANGES:              --- Added comments ---  gbunin [2008/06/20 12:05:46Z]
  CHANGES:              Change Package : 14288:10 http://liss014:6001/im/viewissue?selection=14288
  CHANGES:              Revision 1.4 2008/06/12 11:03:33CEST gbunin
  CHANGES:              Clear cycles only if the config page exists
  CHANGES:              --- Added comments ---  gbunin [2008/06/12 09:51:37Z]
  CHANGES:              Change Package : 12239:1 http://liss014:6001/im/viewissue?selection=12239
  CHANGES:              Revision 1.3 2008/05/09 16:31:12CEST everhoeven
  CHANGES:              Migration 221.37 from Jens Allendörfer
  CHANGES:              --- Added comments ---  everhoeven [2008/05/09 14:31:12Z]
  CHANGES:              Change Package : 12845:1 http://liss014:6001/im/viewissue?selection=12845
  CHANGES:              Revision 1.2 2008/04/28 16:50:03CEST dfroehlich
  CHANGES:              * change: enable/disable overwriting of files
  CHANGES:              --- Added comments ---  dfroehlich [2008/04/28 14:50:03Z]
  CHANGES:              Change Package : 12339:1 http://liss014:6001/im/viewissue?selection=12339
  CHANGES:              Revision 1.1 2008/04/24 13:29:38CEST rhecker
  CHANGES:              Initial revision
  CHANGES:              Member added to project /nfs/projekte1/tools/custom/mts/sw/src/exporter/csvexporter/project.pj

**************************************************************************** */
#include "stdafx.h"
#include "resource.h"
#include "CSVExporter.h"


const wchar_t CCSVExporter::CSV_OUTFILE_EXTENSION[_MAX_EXT] = L".csv";


std::wstring CCSVExporter::m_arrayIndexToDelimiterString[] =
{ L"Semicolon", L"Tab",
L"Comma", L"Space",
L"Other" };

std::wstring CCSVExporter::m_arrayIndexToTimestampString[] =
{ L"MTS_Timestamp", L"UTC_HW_Timestamp",
L"Both_Timestamp" };

CCSVExporter::CCSVExporter() :
	m_pageControl(static_cast<IInterfaceAccess*>(this)),
	m_pageConfig(static_cast<IInterfaceAccess*>(this)),
	m_bTrigSignalDetected(false),
	m_dwTrigSignalCycleID(0),
	m_iSelectedDelimiter(0),
	m_iSelectedTimestamp(0),
	m_EnumDelimiterTypeInterpr(PC_Enumeration),
	m_EnumTimestampTypeInterpr(PC_Enumeration),
	m_strDelimiter(";"),
	bMTS_Timestamp(true),
	bUTC_HW_Timestamp(false)
{
    m_hIcon16 = static_cast<HICON>( LoadImage ( static_cast<HINSTANCE> (g_hModule),
                                                MAKEINTRESOURCE (IDI_ICON_MATLAB_RECORDER),
                                                IMAGE_ICON,
                                                16,
                                                16,
                                                LR_DEFAULTCOLOR));
    m_hIcon32 = static_cast<HICON>( LoadImage ( static_cast<HINSTANCE> (g_hModule),
                                                MAKEINTRESOURCE (IDI_ICON_MATLAB_RECORDER),
                                                IMAGE_ICON,
                                                32,
                                                32,
                                                LR_DEFAULTCOLOR));
    m_hIcon48 = static_cast<HICON>( LoadImage ( static_cast<HINSTANCE> (g_hModule),
                                                MAKEINTRESOURCE (IDI_ICON_MATLAB_RECORDER),
                                                IMAGE_ICON,
                                                48,
                                                48,
                                                LR_DEFAULTCOLOR));

    // default values
    m_bIsExporting = false;
    m_bAllowOverwriteOutput = true;
    m_bFirstPacketAfterStart = false;

    m_bConstrainFileSize = false;
    m_dwMaxFileSize = 100;
    m_dwGenericOutputFilePart = 0;
    m_ssOutFilePartSuffix = L"_part";

    m_sWriteParams.bCycleSpecificOutFile = CSV_OUTFILE_GENERIC;
    m_sWriteParams.bWriteCycleCounter =    CSV_DONTWRITE_CYCLECOUNTER;
    m_sWriteParams.bExcludeOtherCycles =   CSV_DONTEXCLUDE_OTHERCYCLES;
    m_sWriteParams.bExcludeNonCycleData =  CSV_DONTEXCLUDE_NONCYCLEDATA;

    // Not using Set...() functions for the output directory members here because we just want a simple init.
    m_bIsOutDirRelative = true;
    m_ssOutputDirectory_RelPath = L"\\";
    m_ssOutputDirectory_AbsPath = GetMTSDirectory( data_dir );

    SetOutputBaseFileName( L"Export", TRUE );

    SetTriggerTypeAndWriteParams( CSV_TRIGGER_ALLCYCLES );
    SetSignalSelected( L"" );
    SetCycleSelected( L"" );
    SetTriggerPeriod( 100000 );

    m_hControlPageDlgTabHandle = NULL;
    m_hConfigPageDlgTabHandle = NULL;
	m_bIsFloatingPrecisionEnabled = false;
	m_iFloatingPrecisionDigits = 6;

	m_EnumDelimiterTypeInterpr.sEnumerationProperty.dwStructSize = sizeof(m_EnumDelimiterTypeInterpr.sEnumerationProperty);
	m_EnumDelimiterTypeInterpr.sEnumerationProperty.iNumberOfEnumerationMembers = static_cast<int> (m_nDelimiterTypes);
	m_EnumDelimiterTypeInterpr.sEnumerationProperty.rgiEnumerationIndices = new int[m_nDelimiterTypes];
	m_EnumDelimiterTypeInterpr.sEnumerationProperty.rgszEnumerationStrings = new LPCTSTR[m_nDelimiterTypes];

    int nIdx;
    for (nIdx = 0; nIdx < m_EnumDelimiterTypeInterpr.sEnumerationProperty.iNumberOfEnumerationMembers; ++nIdx)
    {
		m_EnumDelimiterTypeInterpr.sEnumerationProperty.rgiEnumerationIndices[nIdx] = nIdx;
		m_EnumDelimiterTypeInterpr.sEnumerationProperty.rgszEnumerationStrings[nIdx] = m_arrayIndexToDelimiterString[nIdx].c_str();
	}

	m_EnumTimestampTypeInterpr.sEnumerationProperty.dwStructSize = sizeof(m_EnumTimestampTypeInterpr.sEnumerationProperty);
	m_EnumTimestampTypeInterpr.sEnumerationProperty.iNumberOfEnumerationMembers = static_cast<int> (m_nTimestampTypes);
	m_EnumTimestampTypeInterpr.sEnumerationProperty.rgiEnumerationIndices = new int[m_nTimestampTypes];
	m_EnumTimestampTypeInterpr.sEnumerationProperty.rgszEnumerationStrings = new LPCTSTR[m_nTimestampTypes];

	int nIdx1;
	for (nIdx1 = 0; nIdx1 < m_EnumTimestampTypeInterpr.sEnumerationProperty.iNumberOfEnumerationMembers; ++nIdx1)
	{
		m_EnumTimestampTypeInterpr.sEnumerationProperty.rgiEnumerationIndices[nIdx1] = nIdx1;
		m_EnumTimestampTypeInterpr.sEnumerationProperty.rgszEnumerationStrings[nIdx1] = m_arrayIndexToTimestampString[nIdx1].c_str();
	}
}

CCSVExporter::~CCSVExporter( void )
{
    delete[] m_EnumDelimiterTypeInterpr.sEnumerationProperty.rgiEnumerationIndices;
    delete[] m_EnumDelimiterTypeInterpr.sEnumerationProperty.rgszEnumerationStrings;

	delete[] m_EnumTimestampTypeInterpr.sEnumerationProperty.rgiEnumerationIndices;
	delete[] m_EnumTimestampTypeInterpr.sEnumerationProperty.rgszEnumerationStrings;


    DestroyIcon(m_hIcon16);
    DestroyIcon(m_hIcon32);
    DestroyIcon(m_hIcon48);
}


void* CCSVExporter::GetInterface( LPCWSTR szIfcName )
{
    void* pInterface = __super::GetInterface (szIfcName);
    if ( pInterface )
        return pInterface;

    if ( 0 == wcscmp(szIfcName, L"ICSVExporterControl2") )
        pInterface = static_cast<ICSVExporterControl2*>( this );

    if ( 0 == wcscmp(szIfcName, L"IExporterControl") )
        pInterface = static_cast<IExporterControl*>( this );

    return pInterface;
}


BOOL CCSVExporter::Initialize()
{
    // Make sure m_bIsExporting doesn't mess with our init. if it's already true because of a CFG
    bool bWasExporting = false;
    if( m_bIsExporting )
    {
        bWasExporting = true;
        m_bIsExporting = false;
    }

    try
    {
        // create control page
        m_pageControl.Create( GetConfigWnd() );

        // access docking interface
        IDockingWindowAccess* pDockingWindowAccess = GetMTSEngineIfc<IDockingWindowAccess>();
        if( pDockingWindowAccess != NULL )
        {
            SDockingTabInfo dockingTabInfo;
            ::memset( &dockingTabInfo, 0, sizeof(SDockingTabInfo) );
            dockingTabInfo.dwFlags = dtf_type_fixed;
            dockingTabInfo.dwState = dts_tab_is_activated;
            dockingTabInfo.hTabIcon = m_pageControl.m_hIcon;
            dockingTabInfo.dwObjectHandle = GetHandle();

            // Set title and description for tab
            CString sTitle = ::GetObjectProperty<CString>( GetHandle(), L"Name" );
            sTitle.Append( L": control" );
            // check for length of the tab name
            if( sTitle.GetLength() >= TAB_TITLE_SIZE )
            {
                // shorten tab title; delete three more characters than allowed
                sTitle.Delete( TAB_TITLE_SIZE-4, sTitle.GetLength() );
                // append points
                sTitle.Append( L"..." );
            }
            swprintf( dockingTabInfo.szTabTitle, _countof(dockingTabInfo.szTabTitle), sTitle );
            swprintf( dockingTabInfo.szTabDescription, _countof(dockingTabInfo.szTabDescription), L"CSV Exporter control page" );
            m_hControlPageDlgTabHandle = pDockingWindowAccess->InsertDockingWindow( m_pageControl.m_hWnd, dockingTabInfo );
            if( m_hControlPageDlgTabHandle == NULL )
            {
                ATLTRACE( L"Initialize(): Could not insert docking window" );
                if( m_pageControl.IsWindow() )
                {
                    m_pageControl.DestroyWindow();
                }
            }
        }
        // if no docking interface is available attach as a property page
        else
        {
            AttachPage( m_pageControl.m_hWnd, L"Control page", NULL, m_pageControl.m_hIcon );
        }

        ///////////////////////////////////////////////////////////////////////

        // create config page
        m_pageConfig.Create( GetConfigWnd() );

        // access docking interface
        if( pDockingWindowAccess != NULL )
        {
            SDockingTabInfo dockingTabInfo;
            ::memset( &dockingTabInfo, 0, sizeof(SDockingTabInfo) );
            dockingTabInfo.dwFlags = dtf_type_fixed;
            dockingTabInfo.dwState = dts_tab_is_activated;
            dockingTabInfo.hTabIcon = m_pageConfig.m_hIcon;
            dockingTabInfo.dwObjectHandle = GetHandle();

            // Set title and description for tab
            CString sTitle = ::GetObjectProperty<CString>( GetHandle(), L"Name" );
            sTitle.Append( L": config" );
            // check for length of the tab name
            if( sTitle.GetLength() >= TAB_TITLE_SIZE )
            {
                // shorten tab title; delete three more characters than allowed
                sTitle.Delete( TAB_TITLE_SIZE-4, sTitle.GetLength() );
                // append points
                sTitle.Append( L"..." );
            }
            swprintf( dockingTabInfo.szTabTitle, _countof(dockingTabInfo.szTabTitle), sTitle );
            swprintf( dockingTabInfo.szTabDescription, _countof(dockingTabInfo.szTabDescription), L"CSV Exporter config page" );
            m_hConfigPageDlgTabHandle = pDockingWindowAccess->InsertDockingWindow(m_pageConfig.m_hWnd, dockingTabInfo );
            if( m_hConfigPageDlgTabHandle == NULL )
            {
                ATLTRACE(L"Initialize(): Could not insert docking window");
                if( m_pageConfig.IsWindow() )
                {
                    m_pageConfig.DestroyWindow();
                }
            }
        }

        // if no docking interface is available attach as a property page
        else
        {
            AttachPage( m_pageConfig.m_hWnd, L"Config page", NULL, m_pageConfig.m_hIcon );
        }
    }
    catch( std::bad_alloc& )
    {
        return FALSE;
    }

    CPropVariant pv;

    GetProperty( PROP_BASE_FILE_NAME, pv );
    m_ssBaseFileName = pv;

    GetProperty( PROP_IS_OUTDIR_RELATIVE, pv );
    m_bIsOutDirRelative = pv;

    GetProperty( PROP_OUTPUT_DIRECTORY, pv );
    m_ssOutputDirectory_RelPath = pv;

    GetProperty( PROP_USE_REC, pv );
    m_bUseRecFileName = pv;

    GetProperty( PROP_CONSTRAIN_FILE_SIZE, pv );
    m_bConstrainFileSize = pv;

    GetProperty( PROP_MAX_FILE_SIZE, pv );
    m_dwMaxFileSize = pv;

    GetProperty( PROP_FILE_PART_NAME, pv );
    m_ssOutFilePartSuffix = pv;

    // Not doing SetOutDirRelative2Data() to set m_bIsOutDirRelative here because it has side-effects over
    //  the output path variables and we don't want these side-effects at init. time
    // By contrast, SetOutputDirectory() is allowed to produce its side-effects over m_bIsOutDirRelative
    //  because the user's choice of output path must have priority over the Relative2Data checkbox setting
    SetOutputDirectory( m_ssOutputDirectory_RelPath.c_str() );
    SetOutputBaseFileName( m_ssBaseFileName.c_str(), m_bUseRecFileName );

    GetProperty( PROP_SIGNAL_URLS_COUNT, pv );
    m_dwNumberOfSignals = pv;

    GetProperty( PROP_SIGNAL_URLS, pv );
    m_vecAttachedSigURLs.clear();
    m_pageConfig.ClearSignalURLs();
    for( unsigned int nIndex = 0; nIndex < m_dwNumberOfSignals; ++nIndex )
    {
        std::wstring ssURL;
        pv.get( ssURL, nIndex );

        m_vecAttachedSigURLs.push_back( ssURL );
        m_pageConfig.AddSignalURL( ssURL.c_str() );
    }

    // === Make sure the TriggerType values from old CFGs are interpreted correctly ===
    // Process old cycle-based TriggerTypes
    // Only reinterpret a cycle-based trigger if the "IsCycleSelected" property is found in the CFG
    // (The only way to read it as "true" is if it's really present in the file, otherwise it's "false".)
    if(    GetProperty( PROP_ISCYCLESELECTED, pv )
       && ( true == (bool)pv )
       && ( 0 == m_dwTriggerType )
       )
    {
        // (Old_TriggerType = 0 && Old_IsCycleSelected = true) <=> (New_TriggerType = Cycle)
        m_dwTriggerType = CSV_TRIGGER_CYCLE;
    }

    // Process old time-based TriggerTypes
    if( (0 == m_dwTriggerPeriod) && (1 == m_dwTriggerType) )
    {
        // (Old_TriggerType = 1 && TriggerPeriod = 0) <=> "On each signal change" <=> (New_TriggerType = AllSignals)
        m_dwTriggerType = CSV_TRIGGER_ALLSIGNALS;
    }

    // Set the Write Parameters in accordance with the loaded TriggerType
    SetTriggerTypeAndWriteParams( m_dwTriggerType );

    // initialize UDEX exporter
    IInterfaceAccess* pInterfaceAccess = CreateUDEXExporter();
    if( NULL == pInterfaceAccess )
    {
        return FALSE;
    }
    m_pUDEXDataExporter = static_cast<IUDEXDataExport*>( pInterfaceAccess->GetInterface(L"IUDEXDataExport") );
    if( NULL == m_pUDEXDataExporter )
    {
        return FALSE;
    }

    // Start exporting if m_bIsExporting was true when this function started
    if( bWasExporting )
    {
        StartExporting();
    }

    return TRUE;
}


void CCSVExporter::Terminate()
{
    // use the tab handle to remove the docking windows
    IDockingWindowAccess* pDockingWindowAccess = GetMTSEngineIfc<IDockingWindowAccess>();
    if ( pDockingWindowAccess != NULL )
    {
        if ( m_hControlPageDlgTabHandle != NULL )
        {
            if (!pDockingWindowAccess->RemoveDockingWindow(m_hControlPageDlgTabHandle))
            {
                ATLTRACE(L"Terminate: could not remove control docking window");
            }
            m_hControlPageDlgTabHandle = NULL;
        }
        if ( m_hConfigPageDlgTabHandle != NULL )
        {
            if (!pDockingWindowAccess->RemoveDockingWindow(m_hConfigPageDlgTabHandle))
            {
                ATLTRACE(L"Terminate: could not remove config docking window");
            }
            m_hConfigPageDlgTabHandle = NULL;
        }
    }

    // if no docking interface is available detach the property page
    else
    {
        DetachPage( m_pageControl.m_hWnd );
        DetachPage( m_pageConfig.m_hWnd );
    }

    // destroy the dialog (otherwise crashes might occur when terminating MTS)
    if( m_pageControl.IsWindow() )
    {
        m_pageControl.DestroyWindow();
    }

    // destroy the dialog (otherwise crashes might occur when terminating MTS)
    if( m_pageConfig.IsWindow() )
    {
        m_pageConfig.DestroyWindow();
    }

    if( m_bIsExporting )
    {
        StopExporting();
    }
}


void CCSVExporter::ValidateData( SDataPackageEx& packet )
{
    // Data is not of any interest when not exporting
    if( !m_bIsExporting )
    {
        return;
    }

	// If this is the first packet after starting to export, save its timestamp
	if (m_bFirstPacketAfterStart)
	{
		m_uqiLastExportTimeStamp = packet.qiTimestamp;
		m_uqiLastExportHWTimeStamp = packet.uqiUtcTimestamp;
		m_bFirstPacketAfterStart = false;
	}

    // Save the current packet's source and cycle properties
    m_dwLatestPacket_SrcHandle = packet.dwSrcHandle;
    m_wLatestPacket_TaskID = packet.wTaskID;
    m_uqiLatestPacket_CycleCounter = packet.uqiCycleCnt;

    // Make the UDEx Exporter update m_pExportSignals[] with the data we just received,
    //    unless we're doing time-based exporting
    bool bUDExSetDataSucceeded = false;
    if( CSV_TRIGGER_TIMEPERIOD != m_dwTriggerType )
    {
        // Avoided BOOL-to-bool conversion warning by making the conversion via comparison with FALSE
        bUDExSetDataSucceeded = ( m_pUDEXDataExporter->SetData(packet) != FALSE );
    }

    switch( m_dwTriggerType )
    {
    default:
        ATLASSERT( L" ! Unknown trigger type" );
        // Fall through

    case CSV_TRIGGER_CYCLE:
        {
            // If the selected cycle doesn't exist, show a warning
            if( 0 == m_SelectedCycle.first )
            {
                if( m_bWarnIfTriggerInexistent )
                {
                    // Get MO name
                    wstring strMOName;
                    CPropVariant pv;
                    if( TRUE == GetProperty( L"Name", pv ) )
                    {
                        strMOName = wstring( pv );
                    }
                    else
                    {
                        strMOName = L"CSV Exporter";
                    }

                    WCHAR szErrMsg[256];
                    swprintf( szErrMsg, _countof(szErrMsg),
                              L"Selected cycle '%s' does not exist,\nno data will be exported!", m_ssSelectedCycle.c_str() );
                    ::MTSWarningBox( szErrMsg, strMOName.c_str() );

                    // Don't show this warning next time
                    m_bWarnIfTriggerInexistent = false;
                }
            }
            // ... otherwise check the cycle conditions and do the export
            else if(   ( SDataPackageEx::cycle_end == packet.eCycleState )
                    && ( m_SelectedCycle.first == packet.dwSrcHandle )
                    && ( m_SelectedCycle.second == packet.wTaskID ) )
            {
			if (bMTS_Timestamp && !bUTC_HW_Timestamp)
			{
				WriteDataToOutputFile(packet.qiTimestamp + m_uqiRelRecStartTime, 0);
            }
			else  if (bUTC_HW_Timestamp && !bMTS_Timestamp)
			{
				WriteDataToOutputFile(0, packet.uqiUtcTimestamp);
			}
			else
			{
				WriteDataToOutputFile(packet.qiTimestamp + m_uqiRelRecStartTime, packet.uqiUtcTimestamp);
			}
		}
	}
	break;

    case CSV_TRIGGER_ALLCYCLES:
        {
            // For all-cycle exporting we write data after each cycle_end packet (for any ID or source),
            //    but only data from the current cycle or non-cycle data
            if( SDataPackageEx::cycle_end == packet.eCycleState )
            {
			if (bMTS_Timestamp && !bUTC_HW_Timestamp)
			{
				WriteDataToOutputFile(packet.qiTimestamp + m_uqiRelRecStartTime, 0);
			}
			else  if (bUTC_HW_Timestamp && !bMTS_Timestamp)
			{
				WriteDataToOutputFile(0, packet.uqiUtcTimestamp);
			}
			else
			{
				WriteDataToOutputFile(packet.qiTimestamp + m_uqiRelRecStartTime, packet.uqiUtcTimestamp);
			}
		}
	}
	break;

    case CSV_TRIGGER_SIGNAL:
        {
            if( m_bWarnIfTriggerInexistent )
            {
                // Extract the source name from the trigger-signal's URL
                int iSeparatorPos = (int)m_ssSelectedSignal.find( L'.' );
                std::wstring ssTrigSigSource = m_ssSelectedSignal.substr( 0, iSeparatorPos );

                // Check if the trigger-signal's source is still connected to the CSV Exporter
                bool bTrigSigSourceFound = false;
                int iSrcIdx = 0;
                while( !bTrigSigSourceFound && (iSrcIdx < GetConnectListLen()) )
                {
                    MTSHANDLE dwSrcHandle = GetConnectListEntry( iSrcIdx );
                    if( ssTrigSigSource == GetObjectProperty<std::wstring>(dwSrcHandle, L"Name") )
                    {
                        bTrigSigSourceFound = true;
                    }
                    ++iSrcIdx;
                }

                // If the source is no longer connected, issue a warning
                if( !bTrigSigSourceFound )
                {
                    // Get MO name
                    wstring strMOName;
                    CPropVariant pv;
                    if( TRUE == GetProperty( L"Name", pv ) )
                    {
                        strMOName = wstring( pv );
                    }
                    else
                    {
                        strMOName = L"CSV Exporter";
                    }

                    WCHAR szErrMsg[256];
                    swprintf( szErrMsg, _countof(szErrMsg),
                              L"Selected trigger-signal source '%s' not connected,\nno data will be exported!", ssTrigSigSource.c_str() );
                    ::MTSWarningBox( szErrMsg, strMOName.c_str() );

                    // Don't show this warning next time
                    m_bWarnIfTriggerInexistent = false;
                }
            }

            // Check if the trigger signal has been received
            if( bUDExSetDataSucceeded )
            {
                for( UINT uiIdx = 0; uiIdx < m_dwNumberOfSignals; ++uiIdx )
                {
                    if(   ( 0 == m_ssSelectedSignal.compare(m_pExportSignals[uiIdx].szURL) )
                       &&  m_pExportSignals[uiIdx].bChanged )
                    {
                        m_bTrigSignalDetected = true;
                        m_dwTrigSignalCycleID = packet.wTaskID;
                    }
                }
            }

            // Check if the cycle_end of the trigger-signal's cycle has arrived
            //  (only after detecting the trigger-signal, else it doesn't matter)
            bool bTrigSignalCycleEndDetected = false;
            if(m_bTrigSignalDetected
                && (   ( SDataPackageEx::no_cycle == packet.eCycleState ) // no cycle_end is expected
                                                                          //   for non-cycle data
                    || ( (SDataPackageEx::cycle_end == packet.eCycleState) && (m_dwTrigSignalCycleID == packet.wTaskID ) )
                   )
               )
            {
                bTrigSignalCycleEndDetected = true;
            }

		// Export new data only if we've received a new value for the trigger-signal AND
		//  if we're at the end of a cycle (so that at least the values of the signals
		//  from the same cycle as the trigger-signal are all synchronized)
		if (bTrigSignalCycleEndDetected)
		{
			if (bMTS_Timestamp && !bUTC_HW_Timestamp)
			{
				WriteDataToOutputFile(packet.qiTimestamp + m_uqiRelRecStartTime, 0);
			}
			else  if (bUTC_HW_Timestamp && !bMTS_Timestamp)
			{
				WriteDataToOutputFile(0, packet.uqiUtcTimestamp);
			}
			else
			{
				WriteDataToOutputFile(packet.qiTimestamp + m_uqiRelRecStartTime, packet.uqiUtcTimestamp);
			}
			m_bTrigSignalDetected = false;
		}
	}
	break;

	case CSV_TRIGGER_ALLSIGNALS:
	{
		// If there's any new data in the current packet, export it right now
		if (bUDExSetDataSucceeded)
		{
			if (bMTS_Timestamp && !bUTC_HW_Timestamp)
			{
				WriteDataToOutputFile(packet.qiTimestamp + m_uqiRelRecStartTime, 0);
			}
			else  if (bUTC_HW_Timestamp && !bMTS_Timestamp)
			{
				WriteDataToOutputFile(0, packet.uqiUtcTimestamp);
			}
			else
			{
				WriteDataToOutputFile(packet.qiTimestamp + m_uqiRelRecStartTime, packet.uqiUtcTimestamp);
			}
		}
	}
	break;

	case CSV_TRIGGER_TIMEPERIOD:
	{
			// Only process packets that are not "from the past"
		if (bMTS_Timestamp && !bUTC_HW_Timestamp)
		{
			if (packet.qiTimestamp >= m_uqiLastExportTimeStamp)
			{
				// If multiple trigger periods have passed since the last export, make sure to export
				//    the most recent available data, writing 1 copy for each of these periods
				while (packet.qiTimestamp - m_uqiLastExportTimeStamp > m_dwTriggerPeriod)
				{
					WriteDataToOutputFile(m_uqiLastExportTimeStamp + m_dwTriggerPeriod + m_uqiRelRecStartTime, 0);
					m_uqiLastExportTimeStamp += m_dwTriggerPeriod;
				}
			}
		}
		else  if (bUTC_HW_Timestamp && !bMTS_Timestamp)
		{
			if (packet.uqiUtcTimestamp >= m_uqiLastExportHWTimeStamp)
			{
				// If multiple trigger periods have passed since the last export, make sure to export
				//    the most recent available data, writing 1 copy for each of these periods
				while (packet.uqiUtcTimestamp - m_uqiLastExportHWTimeStamp > m_dwTriggerPeriod)
				{
					WriteDataToOutputFile(0, m_uqiLastExportHWTimeStamp + m_dwTriggerPeriod);
					m_uqiLastExportHWTimeStamp += m_dwTriggerPeriod;
				}
			}

		}
		else
		{
			if (packet.qiTimestamp >= m_uqiLastExportTimeStamp && packet.uqiUtcTimestamp >= m_uqiLastExportHWTimeStamp)
			{
				while (packet.qiTimestamp - m_uqiLastExportTimeStamp > m_dwTriggerPeriod && packet.uqiUtcTimestamp - m_uqiLastExportHWTimeStamp > m_dwTriggerPeriod)
				{
					WriteDataToOutputFile(m_uqiLastExportTimeStamp + m_dwTriggerPeriod + m_uqiRelRecStartTime, m_uqiLastExportHWTimeStamp + m_dwTriggerPeriod);
					m_uqiLastExportTimeStamp += m_dwTriggerPeriod;
					m_uqiLastExportHWTimeStamp += m_dwTriggerPeriod;
				}
			}
		}

		// Get the UDEx Exporter to update m_pExportSignals[] with the data we just received
		// In this case we do it _after_ the writing phase because we don't want to write
		//    the newest data until the end of the current m_dwTriggerTimePeriod
		(void)m_pUDEXDataExporter->SetData(packet);
	}
	break;
	}
}


void CCSVExporter::ConnectionChanged()
{
    // Clear all cycles on the config page
    if( m_pageConfig.m_hWnd )
    {
        m_pageConfig.ClearCycles();
    }

    // Clear internal cycles map
    m_mapCycles.clear();

    // Clear selected cycle
    m_SelectedCycle = SSourceCycle( 0, 0 );

    // Show a warning if the selected trigger (signal/cycle) isn't attached to the CSV Exporter (anymore)
    m_bWarnIfTriggerInexistent = true;

    // Go through all sources
    for( int iSrcIdx = 0; iSrcIdx < GetConnectListLen(); ++iSrcIdx )
    {
        // Find out which cycles the current source provides
        MTSHANDLE dwSourceHandle = GetConnectListEntry( iSrcIdx );
        IExDevCycle* pSrcDevCycle = GetMeasObject<IExDevCycle>( dwSourceHandle );
        SDevCycleInfo CycleInfo;
        if( NULL != pSrcDevCycle )
        {
            for( DWORD dwCycleIndex = 0; dwCycleIndex < pSrcDevCycle->GetDevCycleInfoCount(); dwCycleIndex++ )
            {
                if( pSrcDevCycle->GetDevCycleInfo(dwCycleIndex, CycleInfo) && ( CycleInfo.ubCycleID != 0 ) )
                {
                    // Cycle name string = L"MO_name - CycleID"
                    wchar_t szBuffer[256];
                    swprintf( szBuffer, _countof(szBuffer), L"%s - %u",
                              GetObjectProperty<std::wstring>( dwSourceHandle, L"Name" ).c_str(),
                              CycleInfo.ubCycleID );
                    std::wstring ssCycleName( szBuffer );

                    // Add this cycle to the control page
                    m_pageConfig.AddCycle( szBuffer );

                    // Add cycle to the cycles map
                    SSourceCycle sourceCycle( dwSourceHandle, CycleInfo.ubCycleID );
                    m_mapCycles.insert( make_pair(ssCycleName, sourceCycle) );

                    // If this cycle name was previously selected select it again
                    if( 0 == ssCycleName.compare(m_ssSelectedCycle) )
                    {
                        m_SelectedCycle = sourceCycle;
                    }
                }
            }
        }
    }

    // Update config page
    if( m_pageConfig.m_hWnd )
    {
        m_pageConfig.UpdateGUI();
    }

    // Restart recording
    if( m_bIsExporting )
    {
        StopExporting();
        StartExporting();
    }
}


BOOL CCSVExporter::SetSignalURLs( LPCWSTR* rgszSignalsURLs, unsigned int iURLsCount )
{
    if( m_bIsExporting )
    {
        return FALSE;
    }

    // More than MAX_SIGNAL_URL_ARRAY signals are not possible
    if( iURLsCount > CSV_MAX_NR_OF_SIGNALS )
    {
        CPropVariant pv;
        GetProperty( L"Name", pv );
        std::wstring ssMOName = pv;

        wchar_t szErr[1024];
        swprintf( szErr, _countof(szErr), L"CSV Exporter can export up to %u signals (%u signals selected)\nThe remaining signals will be ignored", CSV_MAX_NR_OF_SIGNALS, iURLsCount );
        ::MTSWarningBox( szErr, ssMOName.c_str() );

        iURLsCount = CSV_MAX_NR_OF_SIGNALS;
    }

    // Set signals property
    CPropVariant pv;
    m_vecAttachedSigURLs.clear();
    m_pageConfig.ClearSignalURLs();
    int iValidSignals = 0;
    for( unsigned int iIndex = 0; iIndex < iURLsCount; ++iIndex )
    {
        if( rgszSignalsURLs[iIndex] != '\0' )
        {
            iValidSignals++;
            // Add the signal to the list of signals attached for exporting
            m_vecAttachedSigURLs.push_back( std::wstring( rgszSignalsURLs[iIndex] ) );
            pv.set( std::wstring( rgszSignalsURLs[iIndex] ), iIndex );
            // Add the signal to the list on the Config Page
            m_pageConfig.AddSignalURL( rgszSignalsURLs[iIndex] );
        }
    }
    SetProperty( PROP_SIGNAL_URLS, pv );

    // Set signals count property
    pv = iValidSignals;
    SetProperty( PROP_SIGNAL_URLS_COUNT, pv );
    m_dwNumberOfSignals = iValidSignals;

    m_pageConfig.UpdateGUI();
    return TRUE;
}


BOOL CCSVExporter::GetSignalURL (unsigned int nURL, LPWSTR pBuffer, unsigned int& nBufferSize) const
{
    if( nURL >= m_vecAttachedSigURLs.size() )
    {
        return FALSE;
    }

    wcsncpy(pBuffer, m_vecAttachedSigURLs[nURL].c_str(), nBufferSize - 1);
    nBufferSize = nBufferSize < (unsigned int)m_vecAttachedSigURLs[nURL].length() ? nBufferSize : (unsigned int)m_vecAttachedSigURLs[nURL].length();
    return TRUE;
}


bool CCSVExporter::GetOutDirRelative2Data( bool &bIsRelative2Data ) const
{
    bIsRelative2Data = m_bIsOutDirRelative;
    return true;
}


bool CCSVExporter::SetOutDirRelative2Data( const bool bOutDirRelative )
{
    CStringW strOutputPath( m_ssOutputDirectory_RelPath.c_str() );

    // Make corrections if the path should be relative but isn't
    //  (For relative output paths we will enforce a format where the first character should always be a '\'.)
    if(    bOutDirRelative
        && ( (0 != strOutputPath.Find(L'\\')) || (0 == strOutputPath.Find(L"\\\\")) )
        && !PathIsRelative(strOutputPath.GetString())
       )
    {
        // If our absolute path points to \data\ or below, truncate the path to its relative component
        int iDataDirPosition = strOutputPath.Find( GetMTSDirectory(data_dir) );
        if( 0 == iDataDirPosition )
        {
            strOutputPath.Delete( 0, GetMTSDirectory(data_dir).GetLength() );
            if( L'\\' != strOutputPath[0] )
            {
                strOutputPath.Insert( 0, L"\\" );
            }
        }
        else // just empty it out and let the user enter/select something relative
        {
            strOutputPath = L"";
        }
    }
    else if(   !bOutDirRelative
            && (   ( (0 == strOutputPath.Find(L'\\')) && (0 != strOutputPath.Find(L"\\\\")) )
                || PathIsRelative(strOutputPath.GetString()) // this function doesn't treat "\\[^\\].*" as relative
                )
            )
    {
        // Set output path = the absolute interpretation of the existing relative path
        if( 0 != strOutputPath.Find(L'\\') )
        {
            strOutputPath.Insert( 0, L'\\' );
        }
        // Strip any final backslash from the data_dir and then prepend it to our relative path
        CStringW strDataDir = GetMTSDirectory( data_dir );
        strDataDir.TrimRight( L'\\' );
        strOutputPath.Insert( 0, strDataDir.GetString() );
    }

    SaveOutputDirOptions( bOutDirRelative, strOutputPath );

    return true;
}


BOOL CCSVExporter::SetOutputDirectory( LPCWSTR szOutputDirName )
{
    if( m_bIsExporting )
    {
        return FALSE;
    }

    bool bOutDirRelative = m_bIsOutDirRelative;
    CStringW strOutputPath( szOutputDirName );
    // Make corrections if the path should be relative but isn't
    //  (For relative output paths we will enforce a format where the first character should always be a '\'.)
    if(    bOutDirRelative
        && ( (0 != strOutputPath.Find(L'\\')) || (0 == strOutputPath.Find(L"\\\\")) )
        && !PathIsRelative(strOutputPath.GetString())
       )
    {
        // If our absolute path points to \data\ or below, truncate the path to its relative component
        int iDataDirPosition = strOutputPath.Find( GetMTSDirectory(data_dir) );
        if( 0 == iDataDirPosition )
        {
            strOutputPath.Delete( 0, GetMTSDirectory(data_dir).GetLength() );
        }
        else // the user is insisting on using a non-relative path => deselect the OutDirRelative option
        {
            bOutDirRelative = false;
        }
    }
    else if(   !bOutDirRelative
            && (   ( (0 == strOutputPath.Find(L'\\')) && (0 != strOutputPath.Find(L"\\\\")) )
                || PathIsRelative(szOutputDirName) // this function doesn't treat "\\[^\\].*" as relative
                )
            )
    {
        // User has explicitly entered a relative path => enable the corresponding checkbox
        bOutDirRelative = true;
    }

    SaveOutputDirOptions( bOutDirRelative, strOutputPath );

    return TRUE;
}


void CCSVExporter::SaveOutputDirOptions( bool bRelative2Data, CString strOutputPath )
{
    // If we have a relative path, make sure it begins with a '\\'
    if( bRelative2Data && (L'\\' != strOutputPath[0]) )
    {
        strOutputPath.Insert( 0, L'\\' );
    }

    // Also, the path should always end with a '\\' so that filenames can be appended directly to it
    if(   strOutputPath.IsEmpty()
       || ( strOutputPath.ReverseFind(L'\\') != strOutputPath.GetLength() - 1 )
       )
    {
        strOutputPath.AppendChar( L'\\' );
    }

    // Store the new values in the corresponding members
    m_bIsOutDirRelative = bRelative2Data;
    m_ssOutputDirectory_RelPath = strOutputPath.GetString();
    m_ssOutputDirectory_AbsPath = m_ssOutputDirectory_RelPath;

    // If a relative output path has been entered, we must rebuild the absolute path
    if( m_bIsOutDirRelative )
    {
        m_ssOutputDirectory_AbsPath.insert( 0, GetMTSDirectory(data_dir).GetString() );
    }

    // Check if the path exists and create it if it doesn't
    if(   !::PathIsDirectory(m_ssOutputDirectory_AbsPath.c_str())
       && ( ERROR_SUCCESS != ::SHCreateDirectoryEx(NULL, m_ssOutputDirectory_AbsPath.c_str(), NULL) )
       )
    {
        ::MTSErrorBox( L"The output folder does not exist and could not be created.", L"CSV Exporter" );

        // If exporting is already enabled (via CFG-load), then disable it
        if( m_bIsExporting )
        {
            (void)StopExporting();
        }

        return;
    }

    // Save the corresponding properties
    CPropVariant pv;
    pv = m_bIsOutDirRelative;
    SetProperty( PROP_IS_OUTDIR_RELATIVE, pv );
    pv = std::wstring( m_ssOutputDirectory_RelPath );
    SetProperty( PROP_OUTPUT_DIRECTORY, pv );
}


BOOL CCSVExporter::GetOutputDirectory( LPWSTR pBuffer, unsigned int& nBufferSize ) const
{
    wcsncpy( pBuffer, m_ssOutputDirectory_RelPath.c_str(), nBufferSize - 1 );
    nBufferSize  = static_cast<unsigned int>(  m_ssOutputDirectory_RelPath.length() < nBufferSize
                                             ? m_ssOutputDirectory_RelPath.length()
                                             : nBufferSize );
    return TRUE;
}


BOOL CCSVExporter::SetOutputBaseFileName( LPCWSTR szOutputBaseFileName, BOOL bUseRecFileName )
{
    if( m_bIsExporting )
    {
        return FALSE;
    }

    CPropVariant pv;

    if( NULL != szOutputBaseFileName )
    {
        m_ssBaseFileName = szOutputBaseFileName;
        pv = std::wstring( szOutputBaseFileName );
        SetProperty( PROP_BASE_FILE_NAME, pv );
    }

    // Avoided BOOL-to-bool conversion warning by making the conversion via comparison with FALSE
    m_bUseRecFileName = ( bUseRecFileName != FALSE );
    pv = bUseRecFileName;
    SetProperty( PROP_USE_REC, pv );

    return TRUE;
}


BOOL CCSVExporter::GetOutputBaseFileName( LPWSTR pBuffer, unsigned int& nBufferSize, BOOL &bUseRecFileName ) const
{
    bUseRecFileName = m_bUseRecFileName;
    wcsncpy(pBuffer, m_ssBaseFileName.c_str(), nBufferSize - 1);
    nBufferSize = static_cast<unsigned int>( m_ssBaseFileName.length() < nBufferSize ? m_ssBaseFileName.length() : nBufferSize );
    return TRUE;
}


BOOL CCSVExporter::StartExporting()
{
    // Nothing to do if already exporting
    if( m_bIsExporting )
    {
        return TRUE;
    }

    if (m_strDelimiter.IsEmpty())
    {
        ::MTSErrorBox(L"Please enter a valid delimiter", L"Delimiter Error");
        return TRUE;
    }
	
    // Can't export without a properly defined trigger
    if( m_dwTriggerType > CSV_TRIGGER_TYPE_LAST )
    {
        wchar_t szErrMessage[MAX_PATH];
        swprintf( szErrMessage, _countof(szErrMessage), L"Unknown trigger type: %u", m_dwTriggerType );
        ::MTSErrorBox( szErrMessage, L"CSV Exporter" );
        return false;
    }
    // Some trigger types need additional data to function
    switch( m_dwTriggerType )
    {
    case CSV_TRIGGER_CYCLE:
        {
            // Just make sure the SelectedCycle name string isn't empty
            //  ValidateData() will check the contents of the string later
            if( L"" == m_ssSelectedCycle )
            {
                wchar_t szErrMessage[MAX_PATH];
                swprintf( szErrMessage, _countof(szErrMessage), L"No cycle selected for cycle-based export!" );
                ::MTSErrorBox( szErrMessage, L"CSV Exporter" );
                return false;
            }
        }
        break;
    case CSV_TRIGGER_SIGNAL:
        {
            m_bTrigSignalDetected = false;
            m_dwTrigSignalCycleID = 0;
            // Just make sure the SelectedSignal URL string isn't empty
            //  ValidateData() will check the contents of the string later
            if( L"" == m_ssSelectedSignal )
            {
                wchar_t szErrMessage[MAX_PATH];
                swprintf( szErrMessage, _countof(szErrMessage), L"No signal selected for signal-based export!" );
                ::MTSErrorBox( szErrMessage, L"CSV Exporter" );
                return false;
            }
        }
        break;
    case CSV_TRIGGER_TIMEPERIOD:
        {
            // Reject value 0 for triggering period
            if( 0 == m_dwTriggerPeriod )
            {
                wchar_t szErrorMessage[MAX_PATH];
                swprintf( szErrorMessage, _countof(szErrorMessage), L"Cannot export data every 0 microseconds!" );
                ::MTSErrorBox( szErrorMessage, L"CSV Exporter" );
                return false;
            }
            // Warn about very short exporting periods
            else if( m_dwTriggerPeriod < CSV_REASONABLE_TRIGGERPERIOD )
            {
                wchar_t szWarnMessage[MAX_PATH];
                swprintf( szWarnMessage, _countof(szWarnMessage), L"Very short exporting period selected: %u microseconds.\n"
                                                                  L"This may cause performance problems.",
                                                                  m_dwTriggerPeriod );
                ::MTSWarningBox( szWarnMessage, L"CSV Exporter" );
            }
        }
        break;
    default:
        {
            // nothing to do
        }
    }

    // Number of attached signals
    m_dwNumberOfSignals = static_cast<DWORD>( m_vecAttachedSigURLs.size() );

    // Prepare an array with all attached signals
    m_pExportSignals = new ExportSignal_t[ m_dwNumberOfSignals ];
    for ( DWORD i = 0; i < m_dwNumberOfSignals; i++ )
    {
        m_pExportSignals[i].szURL           = m_vecAttachedSigURLs[i].c_str();
        m_pExportSignals[i].nArrayLength    = 0;
        m_pExportSignals[i].bChanged        = FALSE;
    }

    // Initialize UDEX exporter
    m_pUDEXDataExporter->Prepare( GetHandle(), static_cast<int>( m_vecAttachedSigURLs.size() ), m_pExportSignals, UDEXEXP_FLAG_CAST_DOUBLE );

    // Get the timestamp offset if we have a player
    MTSHANDLE dwPlayerHandle = ::FindMeasObjectHandle( FOI_MASK_TYPE, player );
    if( 0 != dwPlayerHandle )
    {
        m_uqiRelRecStartTime = GetObjectProperty<unsigned __int64>( dwPlayerHandle, L"RelativeRecStartTime" );
    }
    else
    {
        m_uqiRelRecStartTime = 0;
    }
    ::ReportError( err_severity_debug,
                   err_category_data,
                   0, 0, GetHandle(),
                   L"Relative recording start time set to %I64d", m_uqiRelRecStartTime );

    // Reset the last exported time stamp value
    m_uqiLastExportTimeStamp = 0;
	m_uqiLastExportHWTimeStamp = 0;

    // Set the flag to indicate the first run after starting export
    m_bFirstPacketAfterStart = true;

    // We have no CSV file yet
    m_bGenericOutputFileExists = false;
    m_dwGenericOutputFilePart = 0;

    // Ready to do our exporting
    m_bIsExporting = true;

    if(m_pageConfig.IsWindow() && m_pageConfig.IsWindowVisible() )
    {
        m_pageConfig.UpdateGUI();
    }

    return TRUE;
}

BOOL CCSVExporter::StopExporting()
{
    // Only when recording has been started
    if( !m_bIsExporting )
    {
        return TRUE;
    }

    // close all opened files
    std::map<SSourceCycle, CAtlFile*>::iterator iter;
    for ( iter = m_mapCycleSpecificOutputFiles.begin(); iter != m_mapCycleSpecificOutputFiles.end(); iter++ )
    {
        iter->second->Close();
        delete iter->second;
    }
    m_mapCycleSpecificOutputFiles.clear();

    m_mapCycSpecificOutFileParts.clear();

    if( m_bGenericOutputFileExists )
    {
        m_GenericOutputFile.Close();
        m_bGenericOutputFileExists = false;
    }

    // finish exporting process
    m_pUDEXDataExporter->Finish();

    // delete all signals
    delete[] m_pExportSignals;

    // Exporting has been stopped
    m_bIsExporting = false;

    if( m_pageConfig.IsWindow() && m_pageConfig.IsWindowVisible() )
    {
        m_pageConfig.UpdateGUI();
    }

    return TRUE;
}

inline BOOL CCSVExporter::IsExporting() const
{
    return m_bIsExporting;
}


inline bool CCSVExporter::SetTriggerTypeAndWriteParams( DWORD dwTriggerType )
{
    m_dwTriggerType = dwTriggerType;

    // Update the trigger-specific output file writing options
    switch( m_dwTriggerType )
    {
    case CSV_TRIGGER_CYCLE:
        {
            m_sWriteParams.bCycleSpecificOutFile =  CSV_OUTFILE_CYCLESPECIFIC;
            m_sWriteParams.bWriteCycleCounter =     CSV_WRITE_CYCLECOUNTER;
            m_sWriteParams.bExcludeOtherCycles =    CSV_DONTEXCLUDE_OTHERCYCLES;
        }
        break;
    case CSV_TRIGGER_ALLCYCLES:
        {
            m_sWriteParams.bCycleSpecificOutFile =  CSV_OUTFILE_CYCLESPECIFIC;
            m_sWriteParams.bWriteCycleCounter =     CSV_WRITE_CYCLECOUNTER;
            m_sWriteParams.bExcludeOtherCycles =    CSV_EXCLUDE_OTHERCYCLES;
        }
        break;
    case CSV_TRIGGER_SIGNAL:
        {
            m_sWriteParams.bCycleSpecificOutFile =  CSV_OUTFILE_GENERIC;
            m_sWriteParams.bWriteCycleCounter =     CSV_DONTWRITE_CYCLECOUNTER;
            m_sWriteParams.bExcludeOtherCycles =    CSV_DONTEXCLUDE_OTHERCYCLES;
        }
        break;
    case CSV_TRIGGER_ALLSIGNALS:
        {
            m_sWriteParams.bCycleSpecificOutFile =  CSV_OUTFILE_GENERIC;
            m_sWriteParams.bWriteCycleCounter =     CSV_DONTWRITE_CYCLECOUNTER;
            m_sWriteParams.bExcludeOtherCycles =    CSV_DONTEXCLUDE_OTHERCYCLES;
        }
        break;
    case CSV_TRIGGER_TIMEPERIOD:
        {
            m_sWriteParams.bCycleSpecificOutFile =  CSV_OUTFILE_GENERIC;
            m_sWriteParams.bWriteCycleCounter =     CSV_DONTWRITE_CYCLECOUNTER;
            m_sWriteParams.bExcludeOtherCycles =    CSV_DONTEXCLUDE_OTHERCYCLES;
        }
        break;
    default:
        {
            // no params to set for unknown trigger type
        }
    }

    m_pageConfig.UpdateGUI();
    return true;
}

inline DWORD CCSVExporter::GetTriggerType() const
{
    return m_dwTriggerType;
}


inline void CCSVExporter::SetTriggerPeriod( DWORD dwTriggerTime )
{
    m_dwTriggerPeriod = dwTriggerTime;
    m_pageConfig.UpdateGUI();
}


inline DWORD CCSVExporter::GetTriggerPeriod() const
{
    return m_dwTriggerPeriod;
}


bool CCSVExporter::SetCycleSelected( LPCWSTR szCycleName )
{
    m_ssSelectedCycle = szCycleName;
    if( L"" != m_ssSelectedCycle )
    {
        std::map<std::wstring, SSourceCycle>::iterator iter = m_mapCycles.find( std::wstring(szCycleName) );
        if( iter != m_mapCycles.end() )
        {
            m_SelectedCycle = iter->second;
        }
        else
        {
            ATLASSERT( !L"Selected cycle doesn't exist, this should not happen" );
            m_SelectedCycle = SSourceCycle( 0, 0 );
            m_ssSelectedCycle = L"";
        }
    }
    else // deselect requested
    {
        m_SelectedCycle = SSourceCycle( 0, 0 );
    }

    m_bWarnIfTriggerInexistent = true;

    m_pageConfig.UpdateGUI();
    return true;
}


bool CCSVExporter::GetSelectedCycle( LPWSTR szCycleName, int nCycleNameLen )
{
    if( !szCycleName || !nCycleNameLen )
    {
        return false;
    }
    wcsncpy( szCycleName, m_ssSelectedCycle.c_str(), nCycleNameLen - 1 );

    return true;
}


bool CCSVExporter::SetSignalSelected( LPCWSTR szSignalURL )
{
    m_ssSelectedSignal = szSignalURL;

    if( L"" != m_ssSelectedSignal )
    {
        // Look for the requested signal on our list of exportable signals
        bool bRequestedSigFound = false;
        UINT uiIdx = 0;
        while( !bRequestedSigFound && (uiIdx < m_vecAttachedSigURLs.size()) )
        {
            if( m_ssSelectedSignal == m_vecAttachedSigURLs[uiIdx] )
            {
                bRequestedSigFound = true;
            }
            ++uiIdx;
        }

        // Issue a warning if the signal wasn't found
        if( !bRequestedSigFound )
        {
            ATLASSERT( !L"Selected signal not attached for exporting!" );
            m_ssSelectedSignal = L"";
        }
    }
    else // deselection requested
    {
        // nothing to do
    }

    m_bWarnIfTriggerInexistent = true;

    m_pageConfig.UpdateGUI();
    return true;
}


bool CCSVExporter::GetSelectedSignal( LPWSTR szSignalURL, int iSignalURLLen )
{
    if( !szSignalURL || !iSignalURLLen )
    {
        return false;
    }
    wcsncpy( szSignalURL, m_ssSelectedSignal.c_str(), iSignalURLLen - 1 );

    return true;
}


HWND CCSVExporter::CreatePropertyPage( HWND hParentWnd )
{
    HWND hWnd = NULL;
    try
    {
        hWnd = m_pageConfig.m_hWnd ? m_pageConfig.m_hWnd : m_pageConfig.Create ( hParentWnd );
        LONG lStyle = m_pageConfig.GetWindowLong( GWL_STYLE );
        lStyle &= ~(WS_POPUP);
        lStyle |= WS_CHILD;
        m_pageConfig.SetWindowLong( GWL_STYLE, lStyle );
        m_pageConfig.SetParent( hParentWnd );
    }
    catch (...)
    {
    }
    return hWnd;
}


bool CCSVExporter::GenerateOutputFileName( std::wstring& ssOutputFileName, DWORD dwOutputFilePart )
{
    std::wstring ssBaseFileName;
    bool bRecFileNameExtracted = false;
    if( m_bUseRecFileName )
    {
        // Get the rec file name if we have a player
        MTSHANDLE dwPlayerHandle = ::FindMeasObjectHandle( FOI_MASK_TYPE, player );
        if( 0 != dwPlayerHandle )
        {
            std::wstring ssCurrentFile =
                GetObjectProperty<std::wstring>( dwPlayerHandle, L"CurrentFile" );

            // get the file name only (without directory path)
            wchar_t szFile[_MAX_FNAME];
            wchar_t szExtension[_MAX_EXT];
            _wsplitpath( ssCurrentFile.c_str(), NULL, NULL, szFile, szExtension );
            ssBaseFileName = std::wstring(szFile) + std::wstring(szExtension);
            bRecFileNameExtracted = true;
        }
    }

    // Use the base file name if the rec file name should not be used
    //    or could not be extracted
    if( !bRecFileNameExtracted )
    {
        ssBaseFileName = m_ssBaseFileName;
    }

    // Construct a full path to a CSV file
    WCHAR szPathConstructionBuffer[MAX_PATH];
    int iEndOfString = swprintf( szPathConstructionBuffer, _countof(szPathConstructionBuffer), L"%s%s_",
                                 m_ssOutputDirectory_AbsPath.c_str(),
                                 ssBaseFileName.c_str() );

    // Append trigger-specific suffixes
    switch( m_dwTriggerType )
    {
    case CSV_TRIGGER_CYCLE:
    case CSV_TRIGGER_ALLCYCLES: // In both these cases we're writing only the file for the current cycle
        {
            iEndOfString += swprintf( szPathConstructionBuffer + iEndOfString, _countof(szPathConstructionBuffer) - iEndOfString,
                                      L"%s_%u",
                                      GetObjectProperty<std::wstring>(m_dwLatestPacket_SrcHandle, L"Name").c_str(),
                                      m_wLatestPacket_TaskID );
        }
        break;
    case CSV_TRIGGER_SIGNAL:
    case CSV_TRIGGER_ALLSIGNALS: // In both these cases we're writing a generic file with all signals in it
        {
            iEndOfString += swprintf( szPathConstructionBuffer + iEndOfString, _countof(szPathConstructionBuffer) - iEndOfString,
                                      L"all" );
        }
        break;
    case CSV_TRIGGER_TIMEPERIOD:
        {
            iEndOfString += swprintf( szPathConstructionBuffer + iEndOfString, _countof(szPathConstructionBuffer) - iEndOfString,
                                      L"%uus", m_dwTriggerPeriod );
        }
        break;
    default:
        {
            // Can't generate file name for unknown trigger type
            return false;
        }
    }

    // Add a file part suffix if necessary
    if( m_bConstrainFileSize )
    {
        // Complete file part suffix = user text + part number
        iEndOfString += swprintf( szPathConstructionBuffer + iEndOfString, _countof(szPathConstructionBuffer) - iEndOfString,
                                  L"%s%u", m_ssOutFilePartSuffix.c_str(), dwOutputFilePart );
    }

    // Finally, append the file extension
    iEndOfString += swprintf( szPathConstructionBuffer + iEndOfString, _countof(szPathConstructionBuffer) - iEndOfString,
                              L"%s", CSV_OUTFILE_EXTENSION );

    // Check if the file already exists, choose a different name if it does
    std::wstring ssTestPath = szPathConstructionBuffer;
    if( !m_bAllowOverwriteOutput )
    {
        UINT iExtraIndex = 0;
        while( ::PathFileExists(ssTestPath.c_str()) && (iExtraIndex < UINT_MAX) )
        {
            ::ReportError(err_severity_warning,
                           err_category_file_io,
                           0, 0, GetHandle(),
                           L"The file '%s' already exists and the option - \"Overwrite existing files\" is disabled. Trying a different file name.", szPathConstructionBuffer );            //Displayed as warning

            // Try with the new value of the Extra Index
            ssTestPath = szPathConstructionBuffer;
            WCHAR szExtraIndex[_MAX_INT_DIG];
            swprintf( szExtraIndex, _countof(szExtraIndex), L"_%u", iExtraIndex );
            ssTestPath.insert( ssTestPath.length() - CSV_FILE_EXTENSION_LENGTH, szExtraIndex );                 //  File Rename

            ++iExtraIndex;
        }
    }
    ssOutputFileName = ssTestPath;

    return true;
}


CAtlFile* CCSVExporter::FindOrCreateOutputFile()
{
    CAtlFile *pOutputFile = NULL;
    SSourceCycle scCurrentCycle( m_dwLatestPacket_SrcHandle, m_wLatestPacket_TaskID );

    // First, check if an output file already exists
    if( m_sWriteParams.bCycleSpecificOutFile )
    {
        std::map<SSourceCycle, CAtlFile*>::iterator iter = m_mapCycleSpecificOutputFiles.find( scCurrentCycle );
        if( (iter != m_mapCycleSpecificOutputFiles.end()) && (iter->second != NULL) )
        {
            // Store this pointer temporarily for continued checks
            pOutputFile = iter->second;
        }
    }
    else if( m_bGenericOutputFileExists )
    {
        pOutputFile = &m_GenericOutputFile;
    }
    // Next, check if we have a partial file exceeding its size limit
    if( m_bConstrainFileSize && (pOutputFile != NULL) )
    {
        unsigned __int64 uqiFileSize = ~0;
        pOutputFile->GetSize( uqiFileSize );
        if( uqiFileSize >= m_dwMaxFileSize * 1024 * 1024 )
        {
            // Size limit reached, close this partial file and reset the pointer
            pOutputFile->Close();
            pOutputFile = NULL;
        }
    }

    // If no suitable file has been found, create a new output file
    if( NULL == pOutputFile )
    {
        // Generate a new file part number if necessary
        DWORD dwOutFilePart = 0;
        if( m_bConstrainFileSize )
        {
            if( m_sWriteParams.bCycleSpecificOutFile )
            {
                // Read the current output file part number for the current cycle, if available, and update it
                std::map<SSourceCycle, DWORD>::iterator itFileParts = m_mapCycSpecificOutFileParts.find( scCurrentCycle );
                if( itFileParts != m_mapCycSpecificOutFileParts.end() )
                {
                    dwOutFilePart = itFileParts->second;
                    dwOutFilePart++;
                }

                // Try to store the new or updated output file part number
                pair< map<SSourceCycle, DWORD>::iterator, bool > prInsertResult;
                prInsertResult = m_mapCycSpecificOutFileParts.insert( make_pair(scCurrentCycle, dwOutFilePart) );
                if( false == prInsertResult.second )
                {
                    // Couldn't insert the new value, assume key already exists and try to replace
                    m_mapCycSpecificOutFileParts.erase( scCurrentCycle );
                    prInsertResult = m_mapCycSpecificOutFileParts.insert( make_pair(scCurrentCycle, dwOutFilePart) );
                    if( false == prInsertResult.second )
                    {
                        // Still can't do it, something is very wrong
                        ::ReportError( err_severity_error, err_category_file_io, 0, 0, GetHandle(),
                                       L"Cannot store the new partial file number." );
                        return NULL;
                    }
                }
            }
            else // Process the part number for the generic output file
            {
                dwOutFilePart = ++m_dwGenericOutputFilePart;
            }
        }

        // Generate an appropriate filename
        std::wstring ssOutputFileName;
        if( !GenerateOutputFileName(ssOutputFileName, dwOutFilePart) )
        {
            ::ReportError( err_severity_error, err_category_file_io, 0, 0, GetHandle(),
                           L"Failed to generate the name of the CSV file." );
            return NULL;
        }

        // Create the file itself
		pOutputFile = new (std::nothrow) CAtlFile;

		// Check for NULL 
		if (NULL == pOutputFile)
		{
			::ReportError(err_severity_error, err_category_file_io, 0, 0, GetHandle(),
				L"Failed to generate the CSV Export file");
			return NULL;
		}
		else
		{
			if (S_OK != pOutputFile->Create(ssOutputFileName.c_str(), FILE_WRITE_DATA, FILE_SHARE_READ, CREATE_ALWAYS))
			{
				DWORD  dwErrorVal = GetLastError();  // Get the error
				std::wstring wsMsgDisp = L"";
				
				switch (dwErrorVal)
				{
				case ERROR_SHARING_VIOLATION: wsMsgDisp = L" The csv file to be exported is opened in another application and hence cannot be modified. Please close the opened file. "; //if the file is open
					break;
				case ERROR_PATH_NOT_FOUND: wsMsgDisp = L" Unable to create the .csv file. Kindly check if the given path exists. ";   //if Path is not found
					break;
				case ERROR_ACCESS_DENIED: wsMsgDisp = L" Unable to create the .csv file. Check if the file permission is read-only. ";//if access permission is not given  
					break;
				case ERROR_INVALID_NAME: wsMsgDisp = L" Unable to create the .csv file. The filename, directory name, or volume label syntax is incorrect. ";//if the name is not given properly      
					break;
				default: wsMsgDisp = L" Unable to create the .csv file. ";// if there are other errors   
					break;
				}
				::MTSErrorBox(wsMsgDisp.c_str(), L"CSV Exporter");

				if (S_OK != pOutputFile->Create(ssOutputFileName.c_str(), FILE_WRITE_DATA, FILE_SHARE_READ, CREATE_ALWAYS))
				{
					::ReportError(err_severity_error, err_category_file_io, 0, 0, GetHandle(),
						L"The output file could not be created and the export process has been stopped");
					StopExporting();
					delete pOutputFile;
					pOutputFile = NULL;
					return NULL;
				}
			}
		}

        // Do any necessary post-creation actions
        if( m_sWriteParams.bCycleSpecificOutFile )
        {
            // Add the new file to the map of cycle-specific output files
            pair< map<SSourceCycle, CAtlFile*>::iterator, bool > prInsertResult;
            prInsertResult = m_mapCycleSpecificOutputFiles.insert( std::make_pair(scCurrentCycle, pOutputFile) );
            if( false == prInsertResult.second )
            {
                // Couldn't insert the new value, assume key already exists and try to replace
                m_mapCycleSpecificOutputFiles.erase( scCurrentCycle );
                prInsertResult = m_mapCycleSpecificOutputFiles.insert( std::make_pair(scCurrentCycle, pOutputFile) );
                if( false == prInsertResult.second )
                {
                    // Still can't do it, something is very wrong
                    delete pOutputFile;
                    // No more sense keeping a part number in store for this cycle either
                    m_mapCycSpecificOutFileParts.erase( scCurrentCycle );

                    ::ReportError( err_severity_error, err_category_file_io, 0, 0, GetHandle(),
                                   L"Cannot store the new cycle-specific file pointer." );
                    return NULL;
                }
            }
        }
        else // Update all indications about the newly created generic output file
        {
            m_bGenericOutputFileExists = true;
            m_GenericOutputFile = *pOutputFile; // copy the file object
            delete pOutputFile;
            pOutputFile = &m_GenericOutputFile; // point to the copy
        }

        // Write the table header row to the new output file
        WriteTableHeaderToOutputFile( pOutputFile );
    }

    return pOutputFile;
}


bool CCSVExporter::WriteTableHeaderToOutputFile( CAtlFile* pCSVFile )
{
    // Can't do anything with a NULL file pointer
    if( NULL == pCSVFile )
    {
        return false;
    }

	CStringA strOutput;
	// Use ANSI CString to ensure the CSV contents will be ANSI for now
	if (bMTS_Timestamp && !bUTC_HW_Timestamp)
	{
		strOutput.Append("MTS Time stamp");
	}
	else  if (bUTC_HW_Timestamp && !bMTS_Timestamp)
	{
		strOutput.Append("UTC HW Time stamp");
	}
	else
	{
		strOutput.Append("MTS Time stamp");
		strOutput.Append(m_strDelimiter + "UTC HW Time stamp");
	}

	if (m_sWriteParams.bWriteCycleCounter)
	{
		strOutput.Append(m_strDelimiter + "Cycle counter");
	}
	for (DWORD dwSigIdx = 0; dwSigIdx < m_dwNumberOfSignals; dwSigIdx++)
	{
		// First, decide if the current signal should be written
		bool bSignalRelevant = true; // by default, assume all signals are relevant

        // Mark this signal as irrelevant if it belongs to a different cycle and we're excluding other cycles
        if(    m_sWriteParams.bExcludeOtherCycles
           && ( 1 != m_pExportSignals[dwSigIdx].dwCycleID ) // don't apply this condition to non-cycle signals
           && (   ( m_dwLatestPacket_SrcHandle != m_pExportSignals[dwSigIdx].dwHandle )
               || ( m_wLatestPacket_TaskID != m_pExportSignals[dwSigIdx].dwCycleID ) )
           )
        {
            bSignalRelevant = false;
        }
        // Mark this signal as irrelevant if it's not cycle-based and we're excluding non-cycle data
        if(    m_sWriteParams.bExcludeNonCycleData
           && ( 1 == m_pExportSignals[dwSigIdx].dwCycleID ) )
        {
            bSignalRelevant = false;
        }

        // Write data only if this is a relevant signal
        if( bSignalRelevant )
        {
            if( m_pExportSignals[dwSigIdx].nArrayLength > 1 ) // array
            {
                for( int iValIdx = 0; iValIdx < m_pExportSignals[dwSigIdx].nArrayLength; iValIdx++ )
                {
					strOutput.Append(m_strDelimiter);
                    strOutput.AppendFormat("%s", (LPCSTR)CSV_CONVERT_WSTR_TO_ANSI(m_pExportSignals[dwSigIdx].szURL));
                    strOutput.AppendFormat("[%u]", iValIdx);
                }
            }
            else if( m_pExportSignals[dwSigIdx].nArrayLength == 1 ) // single value
            {
				strOutput.Append(m_strDelimiter);
                strOutput.AppendFormat("%s", (LPCSTR)CSV_CONVERT_WSTR_TO_ANSI(m_pExportSignals[dwSigIdx].szURL));
            }
            else // missing signal?
            {
                strOutput.Append(m_strDelimiter);
            }
        }
    }
    strOutput.Append( "\n" );
	

    if( S_OK == pCSVFile->Write(strOutput, strOutput.GetLength()) )
    {
        return true;
    }

    return false;
}


bool CCSVExporter::WriteDataToOutputFile(unsigned __int64 uqiTimeStamp, unsigned __int64 uqiUtcTimestamp)
{
    CString strFormatedData;
    double dSignalValue = 0.0;

    // Can only write if exporting has started
    if( !m_bIsExporting )
    {
        return true;
    }

    // Get the file pointer
    CAtlFile* pCSVFile = FindOrCreateOutputFile();
    if( NULL == pCSVFile )
    {
        return false;
    }

	// First, write the packet's timestamp
	// Use ANSI CString to ensure the CSV contents will be ANSI for now
	CStringA strOutput;
	if (bMTS_Timestamp && !bUTC_HW_Timestamp)
	{
		strOutput.Format("%I64u", uqiTimeStamp);
	}
	else  if (bUTC_HW_Timestamp && !bMTS_Timestamp)
	{
		strOutput.Format("%I64u", uqiUtcTimestamp);
	}
	else
	{
		strOutput.Format("%I64u", uqiTimeStamp);
		strOutput.AppendFormat(m_strDelimiter + "%I64u", uqiUtcTimestamp);
	}

    // Second, write the Cycle Counter if so requested
    if( m_sWriteParams.bWriteCycleCounter )
    {
		strOutput.Append(m_strDelimiter);
        strOutput.AppendFormat( "%I64u", m_uqiLatestPacket_CycleCounter );
    }

	pCSVFile->Write(strOutput, strOutput.GetLength());

    // Third, write all the signal values (except those marked for exclusion)
    strOutput = "";
    for( DWORD dwSigIdx = 0; dwSigIdx < m_dwNumberOfSignals; dwSigIdx++ )
    {
        // First, decide if the current signal should be written
        bool bSignalRelevant = true; // by default, assume all signals are relevant

        // Mark this signal as irrelevant if it belongs to a different cycle and we're excluding other cycles
        if(    m_sWriteParams.bExcludeOtherCycles
           && ( 1 != m_pExportSignals[dwSigIdx].dwCycleID ) // don't apply this condition to non-cycle signals
           && (   ( m_dwLatestPacket_SrcHandle != m_pExportSignals[dwSigIdx].dwHandle )
               || ( m_wLatestPacket_TaskID != m_pExportSignals[dwSigIdx].dwCycleID ) )
           )
        {
            bSignalRelevant = false;
        }
        // Mark this signal as irrelevant if it's not cycle-based and we're excluding non-cycle data
        if(    m_sWriteParams.bExcludeNonCycleData
           && ( 1 == m_pExportSignals[dwSigIdx].dwCycleID ) )
        {
            bSignalRelevant = false;
        }

        // Write data only if this is a relevant signal
        if( bSignalRelevant )
        {
            // Export only if a signal is available
            if( m_pExportSignals[dwSigIdx].nArrayLength > 0 )
            {
                EDataType eCurrent_signal_type = m_pExportSignals[dwSigIdx].iDataType;
                for (int iValIdx = 0; iValIdx < m_pExportSignals[dwSigIdx].nArrayLength; iValIdx++)
                {
                    dSignalValue = *(reinterpret_cast<double*>(m_pExportSignals[dwSigIdx].pData) + iValIdx);
					strOutput.Append(m_strDelimiter);

					if (eCurrent_signal_type == EDataType::dtQWord) {
						strOutput.AppendFormat("%I64u", (unsigned __int64)dSignalValue);
					}
					else if (eCurrent_signal_type == EDataType::dtInt64) {
						strOutput.AppendFormat("%I64d", (__int64)dSignalValue);
					}
					else if (eCurrent_signal_type == EDataType::dtDWord) {
						std::string ssTempStr = std::to_string(dSignalValue);
						strOutput.AppendFormat("%s", ssTempStr.c_str());
					}
					else if (eCurrent_signal_type == EDataType::dtLong) {
						std::string ssTempStr = std::to_string(dSignalValue);
						strOutput.AppendFormat("%s", ssTempStr.c_str());
					}
					else {
						if (m_bIsFloatingPrecisionEnabled)
						{
							CStringA strTemp = "";
							strTemp.Format("%.64lg", dSignalValue);
							if (strTemp.Find("e") > 0)
							{
								std::stringstream ssFloatValue;
								ssFloatValue << std::fixed << std::setprecision(64) << dSignalValue <<L"\\0";
								strTemp.Format("%s", ssFloatValue.str().c_str());
							}
							int dotIndex = strTemp.Find(".");
							if(dotIndex > 0)
							{
								if (strTemp.GetLength() > m_iFloatingPrecisionDigits + dotIndex + 1)
								{
									strTemp.Truncate(dotIndex + m_iFloatingPrecisionDigits + 1);
								}
							}
							strOutput.AppendFormat("%s", strTemp);
						}
						else
						{
							strOutput.AppendFormat("%lg", dSignalValue);
						}
					}
                }
                m_pExportSignals[dwSigIdx].bChanged = FALSE;
            }
            else
            {
                strOutput.Append( m_strDelimiter );
            }
        }
    }
    strOutput.Append( "\n" );
    pCSVFile->Write( strOutput, strOutput.GetLength() );

    return true;
}


MTSHANDLE CCSVExporter::GetCSVExporterHandle()
{
    return GetHandle();
}

bool CCSVExporter::IsFileSizeConstrained()
{
    return m_bConstrainFileSize;
}

bool CCSVExporter::SetFileSizeConstrained( bool bConstrainFileSize )
{
    m_bConstrainFileSize = bConstrainFileSize;

    CPropVariant pv = bConstrainFileSize;

    // Avoided BOOL-to-bool conversion warning by making the conversion via comparison with FALSE
    return ( SetProperty(PROP_CONSTRAIN_FILE_SIZE, pv) != FALSE );
}

bool CCSVExporter::SetMaxFileSize( DWORD dwMaxFileSize )
{
    m_dwMaxFileSize = dwMaxFileSize;

    CPropVariant pv = dwMaxFileSize;

    // Avoided BOOL-to-bool conversion warning by making the conversion via comparison with FALSE
    return ( SetProperty(PROP_MAX_FILE_SIZE, pv) != FALSE );
}

DWORD CCSVExporter::GetMaxFileSize( )
{
    return m_dwMaxFileSize;
}

bool CCSVExporter::SetFilePartSuffix( LPCWSTR szFilePartName )
{
    m_ssOutFilePartSuffix = szFilePartName;
    CPropVariant pv = szFilePartName;

    // Avoided BOOL-to-bool conversion warning by making the conversion via comparison with FALSE
    return ( SetProperty(PROP_FILE_PART_NAME, pv) != FALSE );
}

bool CCSVExporter::GetFilePartSuffix( LPWSTR szFilePartSuffix, int iFilePartSuffixLen )
{
    wcsncpy( szFilePartSuffix, m_ssOutFilePartSuffix.c_str(), iFilePartSuffixLen - 1 );

    return TRUE;
}

bool CCSVExporter::IsFileOverwrite()
{
    return m_bAllowOverwriteOutput;
}

bool CCSVExporter::SetFileOverwrite( bool bOverwrite )
{
    m_bAllowOverwriteOutput = bOverwrite ? true : false;

    CPropVariant pv = bOverwrite;

    // Avoided BOOL-to-bool conversion warning by making the conversion via comparison with FALSE
    return ( SetProperty(PROP_OVERWRITE_OUTPUT, pv) != FALSE );
}

void CCSVExporter::SetDelimiter(CString &strDelimiter)
{
    m_strDelimiter = strDelimiter;
}
void CCSVExporter::PropertyChanged(LPCWSTR szName)
{
	if (_wcsicmp(szName, L"ConnectList") == 0)
	{
		ConnectionChanged();
	}
	else if (0 == wcscmp(szName, L"SelectTimestamp"))
	{
		switch (m_iSelectedTimestamp)
		{
		case 0:
		{
			bMTS_Timestamp = true;
			bUTC_HW_Timestamp = false;
			break;
		}
		case 1:
		{
			bUTC_HW_Timestamp = true;
			bMTS_Timestamp = false;
			break;
		}
		case 2:
		{
			bMTS_Timestamp = true;
			bUTC_HW_Timestamp = true;
			break;
		}
		default:
		{
			break;
		}
		}
	}
    else if (0 == wcscmp(szName, L"ColumnDelimiter"))
    {
        switch (m_iSelectedDelimiter)
        {
        case 0:
        {
			m_Properties.m_strPropPageDelimiter = L";";
            break;
        }
        case 1:
        {
			m_Properties.m_strPropPageDelimiter = L"    ";
            break;
        }
        case 2:
        {
			m_Properties.m_strPropPageDelimiter = L",";
            break;
        }
        case 3:
        {
			m_Properties.m_strPropPageDelimiter = L" ";
            break;
        }
        default:
        {
            break;
        }
        }
		m_strDelimiter = m_Properties.m_strPropPageDelimiter;
        m_pageConfig.UpdateConfigPageDelSel(m_iSelectedDelimiter);
    }
    else if (0 == wcscmp(szName, L"Delimiter"))
    {
        if (m_iSelectedDelimiter == 4)
        {
			unsigned int uiLength = m_Properties.m_strPropPageDelimiter.StringLength(m_Properties.m_strPropPageDelimiter);
			if (uiLength == 1)
			{
				m_strDelimiter = m_Properties.m_strPropPageDelimiter;
				m_pageConfig.UpdateConfigPageEditDelimiter(m_strDelimiter);
			}
			else
			{
				m_Properties.m_strPropPageDelimiter = m_strDelimiter;
				::MTSWarningBox(L"Enter a valid delimiter of single delimiter",
					L"Delimiter");
			}
            
        }
        else
        {
             m_Properties.m_strPropPageDelimiter = m_strDelimiter;
            ::MTSWarningBox(L"Please select 'other' from the Column delimiter option",
                L"Select column delimiter");
        }
    }
}
void CCSVExporter::UpdatePropPageDelimiterSelection(int &nIdx)
{
    m_iSelectedDelimiter = nIdx;
}

void CCSVExporter::UpdatePropPageDelimiter(CString &strDelimiter)
{
    m_Properties.m_strPropPageDelimiter = strDelimiter;
}
