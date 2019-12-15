# Microsoft Developer Studio Project File - Name="OPCBatchAuto" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=OPCBatchAuto - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "OPCBatchAuto.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "OPCBatchAuto.mak" CFG="OPCBatchAuto - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "OPCBatchAuto - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "OPCBatchAuto - Win32 Release MinDependency" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "OPCBatchAuto - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "OPCHeaders" /I "OPCAuto" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /debug /machine:I386 /pdbtype:sept
# Begin Custom Build - Performing registration
OutDir=.\Debug
TargetPath=.\Debug\OPCBatchAuto.dll
InputPath=.\Debug\OPCBatchAuto.dll
SOURCE="$(InputPath)"

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "OPCBatchAuto - Win32 Release MinDependency"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "ReleaseMinDependency"
# PROP BASE Intermediate_Dir "ReleaseMinDependency"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "ReleaseMinDependency"
# PROP Intermediate_Dir "ReleaseMinDependency"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "_ATL_STATIC_REGISTRY" /D "_ATL_MIN_CRT" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /O1 /I "." /I "OPCHeaders" /I "OPCAuto" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "_ATL_STATIC_REGISTRY" /Yu"stdafx.h" /FD /c
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /incremental:yes /machine:I386
# Begin Custom Build - Performing registration
OutDir=.\ReleaseMinDependency
TargetPath=.\ReleaseMinDependency\OPCBatchAuto.dll
InputPath=.\ReleaseMinDependency\OPCBatchAuto.dll
SOURCE="$(InputPath)"

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	
# End Custom Build

!ENDIF 

# Begin Target

# Name "OPCBatchAuto - Win32 Debug"
# Name "OPCBatchAuto - Win32 Release MinDependency"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Group "DA source files"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\OPCAuto\OPCAutoServer.cpp
# End Source File
# Begin Source File

SOURCE=.\OPCAuto\OPCBrowser.cpp
# End Source File
# Begin Source File

SOURCE=.\OPCAuto\OPCGroup.cpp
# End Source File
# Begin Source File

SOURCE=.\OPCAuto\OPCGroupCallback.cpp
# End Source File
# Begin Source File

SOURCE=.\OPCAuto\OPCGroups.cpp
# End Source File
# Begin Source File

SOURCE=.\OPCAuto\OPCItem.cpp
# End Source File
# Begin Source File

SOURCE=.\OPCAuto\OPCItems.cpp
# End Source File
# End Group
# Begin Source File

SOURCE=.\Globals.cpp
# End Source File
# Begin Source File

SOURCE=.\OPCBABatchServer.cpp
# End Source File
# Begin Source File

SOURCE=.\OPCBABatchSummary.cpp
# End Source File
# Begin Source File

SOURCE=.\OPCBABatchSummaryCollection.cpp
# End Source File
# Begin Source File

SOURCE=.\OPCBAEnumerationSets.cpp
# End Source File
# Begin Source File

SOURCE=.\OPCBatchAuto.cpp
# End Source File
# Begin Source File

SOURCE=.\OPCBatchAuto.def
# End Source File
# Begin Source File

SOURCE=.\OPCBatchAuto.idl
# ADD MTL /tlb ".\OPCBatchAuto.tlb" /h "OPCBatchAuto.h" /iid "OPCBatchAuto_i.c" /Oicf
# End Source File
# Begin Source File

SOURCE=.\OPCBatchAuto.rc
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Group "DA header files"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\OPCAuto\OPCAuto.h
# End Source File
# Begin Source File

SOURCE=.\OPCAuto\OPCAutoServer.h
# End Source File
# Begin Source File

SOURCE=.\OPCAuto\OPCBrowser.h
# End Source File
# Begin Source File

SOURCE=.\OPCAuto\OPCGroup.h
# End Source File
# Begin Source File

SOURCE=.\OPCAuto\OPCGroupEvent.h
# End Source File
# Begin Source File

SOURCE=.\OPCAuto\OPCItem.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\Globals.h
# End Source File
# Begin Source File

SOURCE=.\OPCBABatchServer.h
# End Source File
# Begin Source File

SOURCE=.\OPCBABatchSummary.h
# End Source File
# Begin Source File

SOURCE=.\OPCBABatchSummaryCollection.h
# End Source File
# Begin Source File

SOURCE=.\OPCBAEnumerationSets.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\OPCBABatchServer.rgs
# End Source File
# Begin Source File

SOURCE=.\OPCBABatchSummary.rgs
# End Source File
# Begin Source File

SOURCE=.\OPCBABatchSummaryCollection.rgs
# End Source File
# Begin Source File

SOURCE=.\OPCBAEnumerationSets.rgs
# End Source File
# End Group
# End Target
# End Project
