@echo off
REM - CALL "$(SolutionDir)scripts\prebuild-win.bat" "$(TargetExt)" "$(BINARY_NAME)" "$(Platform)" "$(TargetPath)" "$(OutDir)"
REM set FORMAT=%1
REM set NAME=%2
REM set PLATFORM=%3
REM set BUILT_BINARY=%4

REM build DSP

soul generate --cpp --output=../DSP.h ../DSP.soulpatch
if %errorlevel% neq 0 exit /b %errorlevel%
