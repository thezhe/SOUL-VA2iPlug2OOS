@echo off

REM TheZhe Modifications
REM - No args (full/zip hardcoded)
REM - VST3 only
REM - zipping requires 7zip in %ProgramFiles%\7-Zip\7z.exe

cd %~dp0\..

echo "Touching source"
echo:

copy /b *.cpp+,, > nul

echo "Building ..."
echo:

set CMDLINE_DEFINES="DEMO_VERSION=0"
msbuild TheUtility.sln /t:TheUtility-vst3 /p:configuration=release /p:platform=x64 /nologo /verbosity:minimal /fileLogger /m /flp:logfile=build-win.log;errorsonly;append

echo "Making artifact ..."
echo:

for /f "delims=" %%i in ('findstr PLUG_VERSION_STR config.h') do set VERSION=%%i
if %errorlevel% neq 0 exit /b %errorlevel%
set VERSION=%VERSION:~26,-1%
if %errorlevel% neq 0 exit /b %errorlevel%

set BUILDDIR="build-win\out\TheUtility-%VERSION%-win"

if exist %BUILDDIR% rmdir %BUILDDIR% /s /q > nul
mkdir %BUILDDIR%

copy /y manual\README-win.txt %BUILDDIR%\README.txt > nul
if %errorlevel% neq 0 exit /b %errorlevel%
xcopy build-win\TheUtility.vst3\* %BUILDDIR%\TheUtility.vst3 /e /h /y /i /q > nul
if %errorlevel% neq 0 exit /b %errorlevel%

echo "Printing log..."
echo:

type build-win.log

exit /B 0