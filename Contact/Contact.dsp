# Microsoft Developer Studio Project File - Name="Contact" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=Contact - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Contact.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Contact.mak" CFG="Contact - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Contact - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "Contact - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Contact - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "Contact - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "Contact - Win32 Release"
# Name "Contact - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\ChkPswdDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Contact.cpp
# End Source File
# Begin Source File

SOURCE=.\Contact.rc
# End Source File
# Begin Source File

SOURCE=.\ContactDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\EditPersonDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\EditPswdDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\EditTeamDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\FindDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\FPTeamDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\InCsvDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\InTxtDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\KillGrpDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\KillPsnDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\MPage1Dlg.cpp
# End Source File
# Begin Source File

SOURCE=.\MPage2Dlg.cpp
# End Source File
# Begin Source File

SOURCE=.\MPage3Dlg.cpp
# End Source File
# Begin Source File

SOURCE=.\MPage4Dlg.cpp
# End Source File
# Begin Source File

SOURCE=.\MPage5Dlg.cpp
# End Source File
# Begin Source File

SOURCE=.\NewDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\NewPsnDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\NewTeamDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Person.cpp
# End Source File
# Begin Source File

SOURCE=.\PosDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\ReplaceDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\SwAllDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\WelcomeDlg.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE="..\..\..\..\..\Program Files\Microsoft Visual Studio\VC98\MFC\Include\AFX.INL"
# End Source File
# Begin Source File

SOURCE=.\ChkPswdDlg.h
# End Source File
# Begin Source File

SOURCE=.\Contact.h
# End Source File
# Begin Source File

SOURCE=.\ContactDlg.h
# End Source File
# Begin Source File

SOURCE=.\EditPersonDlg.h
# End Source File
# Begin Source File

SOURCE=.\EditPswdDlg.h
# End Source File
# Begin Source File

SOURCE=.\EditTeamDlg.h
# End Source File
# Begin Source File

SOURCE=.\FindDlg.h
# End Source File
# Begin Source File

SOURCE=.\FPTeamDlg.h
# End Source File
# Begin Source File

SOURCE=.\InCsvDlg.h
# End Source File
# Begin Source File

SOURCE=.\InTxtDlg.h
# End Source File
# Begin Source File

SOURCE=.\KillGrpDlg.h
# End Source File
# Begin Source File

SOURCE=.\KillPsnDlg.h
# End Source File
# Begin Source File

SOURCE=.\MPage1Dlg.h
# End Source File
# Begin Source File

SOURCE=.\MPage2Dlg.h
# End Source File
# Begin Source File

SOURCE=.\MPage3Dlg.h
# End Source File
# Begin Source File

SOURCE=.\MPage4Dlg.h
# End Source File
# Begin Source File

SOURCE=.\MPage5Dlg.h
# End Source File
# Begin Source File

SOURCE=.\NewDlg.h
# End Source File
# Begin Source File

SOURCE=.\NewPsnDlg.h
# End Source File
# Begin Source File

SOURCE=.\NewTeamDlg.h
# End Source File
# Begin Source File

SOURCE=.\Person.h
# End Source File
# Begin Source File

SOURCE=.\PosDlg.h
# End Source File
# Begin Source File

SOURCE=.\ReplaceDlg.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\SwAllDlg.h
# End Source File
# Begin Source File

SOURCE=.\WelcomeDlg.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\ACER.ICO
# End Source File
# Begin Source File

SOURCE=.\res\Book.ico
# End Source File
# Begin Source File

SOURCE=.\res\Bookshelf.ico
# End Source File
# Begin Source File

SOURCE=.\res\cc.ICO
# End Source File
# Begin Source File

SOURCE=.\res\Charfx.ico
# End Source File
# Begin Source File

SOURCE=.\res\CheckBook.ico
# End Source File
# Begin Source File

SOURCE=.\res\Contact.ico
# End Source File
# Begin Source File

SOURCE=.\res\Contact.rc2
# End Source File
# Begin Source File

SOURCE=.\res\Excel.ICO
# End Source File
# Begin Source File

SOURCE=.\res\Find.ico
# End Source File
# Begin Source File

SOURCE=".\res\folder users.ico"
# End Source File
# Begin Source File

SOURCE=.\res\icon15.ico
# End Source File
# Begin Source File

SOURCE=".\res\Log File LOG.ico"
# End Source File
# Begin Source File

SOURCE=".\res\Network Neighbourhood.ico"
# End Source File
# Begin Source File

SOURCE=.\res\Note.ico
# End Source File
# Begin Source File

SOURCE=.\res\User.ico
# End Source File
# Begin Source File

SOURCE=.\res\WindowsC.ico
# End Source File
# Begin Source File

SOURCE=".\res\Œﬁ±ÍÃ‚.bmp"
# End Source File
# End Group
# Begin Source File

SOURCE=.\1.wav
# End Source File
# Begin Source File

SOURCE=.\2.wav
# End Source File
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# Begin Source File

SOURCE=.\start.wav
# End Source File
# End Target
# End Project
