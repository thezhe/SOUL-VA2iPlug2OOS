@echo off

REM Powershell: populate 'results-win' and 'TheChorus-win.zip'

echo Populating 'results-win (PLUG-QA)'
echo:

if exist results-win rmdir results-win /s /q > nul
mkdir results-win

cd ..\SOUL-VA\PLUG-QA
call octave qa.m ../../TheChorus/build-win/TheChorus.vst3 > ..\..\TheChorus\results-win\qa.log
if %errorlevel% neq 0 exit /b %errorlevel%

del /f /q /s ..\..\TheChorus\results-win\qa.log > nul
xcopy results\ ..\..\TheChorus\results-win\ /s /e /h /y /i /q > nul
cd ..\..\TheChorus

echo Populating 'results-win' (pluginval)
echo:

pluginval --strictness-level 5 --validate-in-process --block-sizes 44100,48000,88200,96000,176400,192000 --validate build-win\TheChorus.vst3 > results-win\Pluginval_TheChorus_VST3_Win10_x64.log
if %errorlevel% neq 0 exit /b %errorlevel%

del /f /q /s results-win\Pluginval_TheChorus_VST3_Win10_x64.log > nul

echo Populating 'TheChorus-win.zip'
echo:

for /f "delims=" %%i in ('findstr PLUG_VERSION_STR config.h') do set VERSION=%%i
if %errorlevel% neq 0 exit /b %errorlevel%
set VERSION=%VERSION:~26,-1%
if %errorlevel% neq 0 exit /b %errorlevel%

if exist TheChorus-%VERSION%-win rmdir TheChorus-%VERSION%-win /s /q > nul
mkdir TheChorus-%VERSION%-win

copy /y manual\README-win.txt TheChorus-%VERSION%-win\README.txt > nul
if %errorlevel% neq 0 exit /b %errorlevel%
xcopy build-win\TheChorus.vst3\* TheChorus-%VERSION%-win\TheChorus.vst3 /e /h /y /i /q > nul
if %errorlevel% neq 0 exit /b %errorlevel%

if exist TheChorus-win.zip del TheChorus-win.zip /f /q /s > nul
powershell -command "Compress-Archive -LiteralPath TheChorus-%VERSION%-win -DestinationPath TheChorus-win.zip"
rmdir TheChorus-%VERSION%-win /s /q > nul

echo DONE!
echo:

