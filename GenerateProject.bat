@echo off
setlocal EnableDelayedExpansion


echo.
echo.
echo ______________________________________________________________________________________
echo.
echo    Configuration to your System
echo ______________________________________________________________________________________
echo.
echo.
echo.

echo Supported versions of Visual Studio: 2013, 2015 or 2017
:invalidVSVersionInput
set /p visualStudioYear=Use version: 
if "%visualStudioYear%"=="2013" set visualStudioVersion=Visual Studio 12 2013
if "%visualStudioYear%"=="2015" set visualStudioVersion=Visual Studio 14 2015
if "%visualStudioYear%"=="2017" set visualStudioVersion=Visual Studio 15 2017
if not defined visualStudioVersion goto invalidVSVersionInput

echo.
echo Supported platforms: 32, 64 (bit)
:invalidPlatformInput
set /p archNumber=Use platfrom: 
set archNumber=%archNumber:~0,2%
if "%archNumber%"=="32" (
  set archDir=Win32
  set arch=
)
if "%archNumber%"=="64" (
  set archDir=Win64
  set arch= Win64
)
if not defined archDir goto invalidPlatformInput

:checkVSDirAgain
if exist vs\%archDir% (
  echo.
  echo The target directory for Visual Studio project files exists already.
  rmdir /S vs\%archDir%
  goto checkVSDirAgain
)

echo.
:repeatDefaultLibSelection
choice /C YN /N /M "Use default LIBRARIES_BASE_PATH [Yes/No]? "
if %errorlevel%==1 echo OK, continue with default LIBRARIES_BASE_PATH.
if %errorlevel%==2 set /p LIBRARIES_BASE_PATH=New LIBRARIES_BASE_PATH ^= 
if %errorlevel%==0 goto repeatDefaultLibSelection

echo.
echo.
echo ______________________________________________________________________________________
echo.
echo    Generating %visualStudioVersion% (%archNumber% bit) project files
echo ______________________________________________________________________________________
echo.
echo.
echo.
pause

if not exist vs (
  mkdir vs
)
mkdir vs\%archDir%
cd vs\%archDir%

cmake ..\.. -G "%visualStudioVersion%%arch%" %options%

if errorlevel 1 (
  pause
  exit
)

echo.
echo.
echo ______________________________________________________________________________________
echo.
echo    Open with %visualStudioVersion%
echo ______________________________________________________________________________________
echo.
echo.
echo.
pause

for /r %%i in (*.sln) do (
  powershell "$s=(New-Object -COM WScript.Shell).CreateShortcut('..\..\%%~ni (%archNumber% bit).lnk');$s.TargetPath='%%i';$s.Save()"
  start %%~nxi
)

popd
