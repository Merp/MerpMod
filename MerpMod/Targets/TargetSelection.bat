
..\..\SharpTune.exe ecumaptool idatohew.xml "..\..\..\SubaruDisassembly\Maps\%TARGETROM%.map" "%TARGETROM%.h" "%TARGETROM%.txt" %TARGETROM% %BUILDCONFIG% %MMVERSION%
Del ..\TargetHeader.h
Copy "%TARGETROM%.h" ..\TargetHeader.h

IF NOT EXIST "%TARGETROM%Config.h" (
goto 2
:2
Copy TemplateConfig.h %TARGETROM%Config.h
) ELSE (
goto exit
)
:exit
Copy "%TARGETROM%Config.h" ..\TargetConfig.h
Copy "%TARGETROM%.txt" ..\LinkerScript.txt
