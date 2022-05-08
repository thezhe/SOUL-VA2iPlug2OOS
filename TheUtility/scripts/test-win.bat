@echo off

REM Powershell: run PLUG-QA and put results in 'results-win'

echo Populating 'results-win (PLUG-QA)'
echo:

cd ../

if exist results-win rmdir results-win /s /q > nul
mkdir results-win

cd ..\SOUL-VA\PLUG-QA
call octave qa.m ../../TheUtility/build-win/TheUtility.vst3 > ..\..\TheUtility\results-win\qa.log
if %errorlevel% neq 0 exit /b %errorlevel%

del /f /q /s ..\..\TheUtility\results-win\qa.log > nul
xcopy results\ ..\..\TheUtility\results-win\ /s /e /h /y /i /q > nul
cd ..\..\TheUtility

echo DONE!
echo:

