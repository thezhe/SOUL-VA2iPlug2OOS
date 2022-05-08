@echo off

REM Powershell: populate 'results-win' and 'TheSplit-win.zip'

echo Populating 'results-win (PLUG-QA)'
echo:

if exist results-win rmdir results-win /s /q > nul
mkdir results-win

cd ..\SOUL-VA\PLUG-QA
call octave qa.m ../../TheSplit/build-win/TheSplit.vst3 > ..\..\TheSplit\results-win\qa.log
if %errorlevel% neq 0 exit /b %errorlevel%

del /f /q /s ..\..\TheSplit\results-win\qa.log > nul
xcopy results\ ..\..\TheSplit\results-win\ /s /e /h /y /i /q > nul
cd ..\..\TheSplit

echo Populating 'results-win' (pluginval)
echo:

pluginval --strictness-level 5 --validate-in-process --block-sizes 44100,48000,88200,96000,176400,192000 --validate build-win\TheSplit.vst3 > results-win\Pluginval_TheSplit_VST3_Win10_x64.log
if %errorlevel% neq 0 exit /b %errorlevel%

del /f /q /s results-win\Pluginval_TheSplit_VST3_Win10_x64.log > nul

echo Populating 'TheSplit-win.zip'
echo:

for /f "delims=" %%i in ('findstr PLUG_VERSION_STR config.h') do set VERSION=%%i
if %errorlevel% neq 0 exit /b %errorlevel%
set VERSION=%VERSION:~26,-1%
if %errorlevel% neq 0 exit /b %errorlevel%

if exist TheSplit-%VERSION%-win rmdir TheSplit-%VERSION%-win /s /q > nul
mkdir TheSplit-%VERSION%-win

copy /y manual\README-win.txt TheSplit-%VERSION%-win\README.txt > nul
if %errorlevel% neq 0 exit /b %errorlevel%
xcopy build-win\TheSplit.vst3\* TheSplit-%VERSION%-win\TheSplit.vst3 /e /h /y /i /q > nul
if %errorlevel% neq 0 exit /b %errorlevel%

if exist TheSplit-win.zip del TheSplit-win.zip /f /q /s > nul
powershell -command "Compress-Archive -LiteralPath TheSplit-%VERSION%-win -DestinationPath TheSplit-win.zip"
rmdir TheSplit-%VERSION%-win /s /q > nul

echo DONE!
echo:

