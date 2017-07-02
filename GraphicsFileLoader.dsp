# Microsoft Developer Studio Project File - Name="GraphicsFileLoader" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=GraphicsFileLoader - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "GraphicsFileLoader.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "GraphicsFileLoader.mak" CFG="GraphicsFileLoader - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "GraphicsFileLoader - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "GraphicsFileLoader - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "GraphicsFileLoader - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "GraphicsFileLoader - Win32 Debug"

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
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /I "./" /I "../mathlib/" /I "./Interface" /I "./Control" /I "./Graphics" /I "./Structure" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 winmm.lib opengl32.lib glu32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "GraphicsFileLoader - Win32 Release"
# Name "GraphicsFileLoader - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\DummyModifier.cpp
# End Source File
# Begin Source File

SOURCE=.\DummySceneLoader.cpp
# End Source File
# Begin Source File

SOURCE=.\HoofdScherm.cpp
# End Source File
# Begin Source File

SOURCE=.\Scherm.cpp
# End Source File
# Begin Source File

SOURCE=.\SelectionGroups.cpp
# End Source File
# Begin Source File

SOURCE=.\Selector.cpp
# End Source File
# Begin Source File

SOURCE=.\TextureManager.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\DummyModifier.h
# End Source File
# Begin Source File

SOURCE=.\DummySceneLoader.h
# End Source File
# Begin Source File

SOURCE=.\HoofdScherm.h
# End Source File
# Begin Source File

SOURCE=..\MathLib\mathlib.h
# End Source File
# Begin Source File

SOURCE=.\Scherm.h
# End Source File
# Begin Source File

SOURCE=.\SelectionGroups.h
# End Source File
# Begin Source File

SOURCE=.\Selector.h
# End Source File
# Begin Source File

SOURCE=.\TextureManager.h
# End Source File
# End Group
# Begin Group "Control"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Control\ControlCameraTool.cpp
# End Source File
# Begin Source File

SOURCE=.\Control\ControlCameraTool.h
# End Source File
# Begin Source File

SOURCE=.\Control\ControlSelectionTool.cpp
# End Source File
# Begin Source File

SOURCE=.\Control\ControlSelectionTool.h
# End Source File
# Begin Source File

SOURCE=.\Control\ControlToolArguments.cpp
# End Source File
# Begin Source File

SOURCE=.\Control\ControlToolArguments.h
# End Source File
# End Group
# Begin Group "Interface"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Interface\flag.h
# End Source File
# Begin Source File

SOURCE=.\Interface\ICamera.h
# End Source File
# Begin Source File

SOURCE=.\Interface\IGroup.h
# End Source File
# Begin Source File

SOURCE=.\Interface\IMaterial.h
# End Source File
# Begin Source File

SOURCE=.\Interface\IModifier.h
# End Source File
# Begin Source File

SOURCE=.\Interface\IPoint.h
# End Source File
# Begin Source File

SOURCE=.\Interface\IScene.h
# End Source File
# Begin Source File

SOURCE=.\Interface\ISceneLoader.h
# End Source File
# Begin Source File

SOURCE=.\Interface\ISelection.h
# End Source File
# Begin Source File

SOURCE=.\Interface\ITexCoord.h
# End Source File
# Begin Source File

SOURCE=.\Interface\ITool.h
# End Source File
# Begin Source File

SOURCE=.\Interface\IToolArguments.h
# End Source File
# Begin Source File

SOURCE=.\Interface\ITriangle.h
# End Source File
# Begin Source File

SOURCE=.\Interface\IVertex.h
# End Source File
# End Group
# Begin Group "Graphics"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Graphics\GraphicsCamera.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\GraphicsCamera.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\GraphicsCube.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\GraphicsCube.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\GraphicsEngine.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\GraphicsEngine.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\GraphicsObjects.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\GraphicsObjects.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\GraphicsRectangle.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\GraphicsRectangle.h
# End Source File
# Begin Source File

SOURCE=.\Graphics\GraphicsView.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics\GraphicsView.h
# End Source File
# End Group
# Begin Group "Structure"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\structure\StructureGroup.cpp
# End Source File
# Begin Source File

SOURCE=.\structure\StructureGroup.h
# End Source File
# Begin Source File

SOURCE=.\structure\StructureMaterial.cpp
# End Source File
# Begin Source File

SOURCE=.\structure\StructureMaterial.h
# End Source File
# Begin Source File

SOURCE=.\structure\StructureScene.cpp
# End Source File
# Begin Source File

SOURCE=.\structure\StructureScene.h
# End Source File
# Begin Source File

SOURCE=.\structure\StructureSceneManager.cpp
# End Source File
# Begin Source File

SOURCE=.\structure\StructureSceneManager.h
# End Source File
# Begin Source File

SOURCE=.\structure\StructureTexCoord.cpp
# End Source File
# Begin Source File

SOURCE=.\structure\StructureTexCoord.h
# End Source File
# Begin Source File

SOURCE=.\structure\StructureTriangle.cpp
# End Source File
# Begin Source File

SOURCE=.\structure\StructureTriangle.h
# End Source File
# Begin Source File

SOURCE=.\structure\StructureVertex.cpp
# End Source File
# Begin Source File

SOURCE=.\structure\StructureVertex.h
# End Source File
# End Group
# Begin Source File

SOURCE=..\MathLib\Debug\MathLib.lib
# End Source File
# End Target
# End Project
