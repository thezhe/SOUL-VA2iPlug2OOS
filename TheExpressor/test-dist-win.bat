@echo off

REM Powershell: populate 'results-win' and 'TheExpressor-win.zip'

echo Populating 'results-win (PLUG-QA)'
echo:

if exist results-win rmdir results-win /s /q > nul
mkdir results-win

cd ..\SOUL-VA\PLUG-QA
call octave qa.m ../../TheExpressor/build-win/TheExpressor.vst3 > ..\..\TheExpressor\results-win\qa.log
if %errorlevel% neq 0 exit /b %errorlevel%

del /f /q /s ..\..\TheExpressor\results-win\qa.log > nul
xcopy results\ ..\..\TheExpressor\results-win\ /s /e /h /y /i /q > nul
cd ..\..\TheExpressor

echo Populating 'results-win' (pluginval)
echo:

pluginval --strictness-level 5 --validate-in-process --block-sizes 44100,48000,88200,96000,176400,192000 --validate build-win\TheExpressor.vst3 > results-win\Pluginval_TheExpressor_VST3_Win10_x64.log
if %errorlevel% neq 0 exit /b %errorlevel%

del /f /q /s results-win\Pluginval_TheExpressor_VST3_Win10_x64.log > nul

echo Populating 'TheExpressor-win.zip'
echo:

for /f "delims=" %%i in ('findstr PLUG_VERSION_STR config.h') do set VERSION=%%i
if %errorlevel% neq 0 exit /b %errorlevel%
set VERSION=%VERSION:~26,-1%
if %errorlevel% neq 0 exit /b %errorlevel%

if exist TheExpressor-%VERSION%-win rmdir TheExpressor-%VERSION%-win /s /q > nul
mkdir TheExpressor-%VERSION%-win

copy /y manual\README-win.txt TheExpressor-%VERSION%-win\README.txt > nul
if %errorlevel% neq 0 exit /b %errorlevel%
xcopy build-win\TheExpressor.vst3\* TheExpressor-%VERSION%-win\TheExpressor.vst3 /e /h /y /i /q > nul
if %errorlevel% neq 0 exit /b %errorlevel%

if exist TheExpressor-win.zip del TheExpressor-win.zip /f /q /s > nul
powershell -command "Compress-Archive -LiteralPath TheExpressor-%VERSION%-win -DestinationPath TheExpressor-win.zip"
rmdir TheExpressor-%VERSION%-win /s /q > nul

echo DONE!
echo:

