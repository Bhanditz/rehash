# Microsoft Developer Studio Project File - Name="rehash" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 5.00
# ** NICHT BEARBEITEN **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=rehash - Win32 Debug
!MESSAGE Dies ist kein gültiges Makefile. Zum Erstellen dieses Projekts mit\
 NMAKE
!MESSAGE verwenden Sie den Befehl "Makefile exportieren" und führen Sie den\
 Befehl
!MESSAGE 
!MESSAGE NMAKE /f "rehash.mak".
!MESSAGE 
!MESSAGE Sie können beim Ausführen von NMAKE eine Konfiguration angeben
!MESSAGE durch Definieren des Makros CFG in der Befehlszeile. Zum Beispiel:
!MESSAGE 
!MESSAGE NMAKE /f "rehash.mak" CFG="rehash - Win32 Debug"
!MESSAGE 
!MESSAGE Für die Konfiguration stehen zur Auswahl:
!MESSAGE 
!MESSAGE "rehash - Win32 Release" (basierend auf\
  "Win32 (x86) Console Application")
!MESSAGE "rehash - Win32 Debug" (basierend auf\
  "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "rehash - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "../bin_win/release"
# PROP Intermediate_Dir "../bin_win/release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD BASE RSC /l 0x407 /d "NDEBUG"
# ADD RSC /l 0x407 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386

!ELSEIF  "$(CFG)" == "rehash - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "../bin_win/debug"
# PROP Intermediate_Dir "../bin_win/debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /W3 /WX /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD BASE RSC /l 0x407 /d "_DEBUG"
# ADD RSC /l 0x407 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "rehash - Win32 Release"
# Name "rehash - Win32 Debug"
# Begin Group "Main"

# PROP Default_Filter ""
# Begin Group "Util"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\rehash\clutil.cpp
# End Source File
# Begin Source File

SOURCE=..\rehash\clutil.h
# End Source File
# Begin Source File

SOURCE=..\rehash\fnpattern.cpp
# End Source File
# Begin Source File

SOURCE=..\rehash\fnpattern.h
# End Source File
# End Group
# Begin Group "Common"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\rehash\rhcommon.cpp
# End Source File
# Begin Source File

SOURCE=..\rehash\rhcommon.h
# End Source File
# End Group
# Begin Source File

SOURCE=..\rehash\benchmark.cpp
# End Source File
# Begin Source File

SOURCE=..\rehash\benchmark.h
# End Source File
# Begin Source File

SOURCE=..\rehash\hashmgr.cpp
# End Source File
# Begin Source File

SOURCE=..\rehash\hashmgr.h
# End Source File
# Begin Source File

SOURCE=..\rehash\hashoutput.cpp
# End Source File
# Begin Source File

SOURCE=..\rehash\hashoutput.h
# End Source File
# Begin Source File

SOURCE=..\rehash\rehash.cpp
# End Source File
# Begin Source File

SOURCE=..\rehash\rehash.h
# End Source File
# Begin Source File

SOURCE=..\rehash\selftest.cpp
# End Source File
# Begin Source File

SOURCE=..\rehash\selftest.h
# End Source File
# End Group
# Begin Group "Algorithms"

# PROP Default_Filter ""
# Begin Group "Base"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\src_algo\hashalgo.cpp
# End Source File
# Begin Source File

SOURCE=..\src_algo\hashalgo.h
# End Source File
# Begin Source File

SOURCE=..\src_algo\hmac.cpp
# End Source File
# Begin Source File

SOURCE=..\src_algo\hmac.h
# End Source File
# End Group
# Begin Group "Checksum"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\src_algo\adler32.cpp
# End Source File
# Begin Source File

SOURCE=..\src_algo\adler32.h
# End Source File
# Begin Source File

SOURCE=..\src_algo\crc16.cpp
# End Source File
# Begin Source File

SOURCE=..\src_algo\crc16.h
# End Source File
# Begin Source File

SOURCE=..\src_algo\crc32.cpp
# End Source File
# Begin Source File

SOURCE=..\src_algo\crc32.h
# End Source File
# Begin Source File

SOURCE=..\src_algo\crc64.cpp
# End Source File
# Begin Source File

SOURCE=..\src_algo\crc64.h
# End Source File
# Begin Source File

SOURCE=..\src_algo\elfhash.cpp
# End Source File
# Begin Source File

SOURCE=..\src_algo\elfhash.h
# End Source File
# Begin Source File

SOURCE=..\src_algo\fcs.cpp
# End Source File
# Begin Source File

SOURCE=..\src_algo\fcs.h
# End Source File
# Begin Source File

SOURCE=..\src_algo\fnvhash.cpp
# End Source File
# Begin Source File

SOURCE=..\src_algo\fnvhash.h
# End Source File
# Begin Source File

SOURCE=..\src_algo\ghash.cpp
# End Source File
# Begin Source File

SOURCE=..\src_algo\ghash.h
# End Source File
# Begin Source File

SOURCE=..\src_algo\sizehash.cpp
# End Source File
# Begin Source File

SOURCE=..\src_algo\sizehash.h
# End Source File
# Begin Source File

SOURCE=..\src_algo\xumhash.cpp
# End Source File
# Begin Source File

SOURCE=..\src_algo\xumhash.h
# End Source File
# End Group
# Begin Group "CryptoHash"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\src_algo\ed2khash.cpp
# End Source File
# Begin Source File

SOURCE=..\src_algo\ed2khash.h
# End Source File
# Begin Source File

SOURCE=..\src_algo\gosthash.cpp
# End Source File
# Begin Source File

SOURCE=..\src_algo\gosthash.h
# End Source File
# Begin Source File

SOURCE=..\src_algo\haval256_3.cpp
# End Source File
# Begin Source File

SOURCE=..\src_algo\haval256_3.h
# End Source File
# Begin Source File

SOURCE=..\src_algo\haval256_4.cpp
# End Source File
# Begin Source File

SOURCE=..\src_algo\haval256_4.h
# End Source File
# Begin Source File

SOURCE=..\src_algo\haval256_5.cpp
# End Source File
# Begin Source File

SOURCE=..\src_algo\haval256_5.h
# End Source File
# Begin Source File

SOURCE=..\src_algo\md2.cpp
# End Source File
# Begin Source File

SOURCE=..\src_algo\md2.h
# End Source File
# Begin Source File

SOURCE=..\src_algo\md4.cpp
# End Source File
# Begin Source File

SOURCE=..\src_algo\md4.h
# End Source File
# Begin Source File

SOURCE=..\src_algo\md5.cpp
# End Source File
# Begin Source File

SOURCE=..\src_algo\md5.h
# End Source File
# Begin Source File

SOURCE=..\src_algo\ripemd.cpp
# End Source File
# Begin Source File

SOURCE=..\src_algo\ripemd.h
# End Source File
# Begin Source File

SOURCE=..\src_algo\sha1.cpp
# End Source File
# Begin Source File

SOURCE=..\src_algo\sha1.h
# End Source File
# Begin Source File

SOURCE=..\src_algo\sha2.cpp
# End Source File
# Begin Source File

SOURCE=..\src_algo\sha2.h
# End Source File
# Begin Source File

SOURCE=..\src_algo\tiger.cpp
# End Source File
# Begin Source File

SOURCE=..\src_algo\tiger.h
# End Source File
# End Group
# Begin Group "Encoding"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\src_algo\base64.cpp
# End Source File
# Begin Source File

SOURCE=..\src_algo\base64.h
# End Source File
# End Group
# End Group
# End Target
# End Project
