@echo off
REM Build red_flag.dll and inject.exe using MSYS2 mingw32 (32-bit)
REM Uses C:\msys64\mingw32\bin\gcc.exe — already installed on this machine

set MINGW=C:\msys64\mingw32\bin
set CC=%MINGW%\gcc.exe
set PATH=%MINGW%;%PATH%

if not exist %CC% (
    echo ERROR: %CC% not found.
    echo Install via MSYS2: pacman -S mingw-w64-i686-gcc
    pause
    exit /b 1
)

echo Building red_flag.dll...
%CC% -shared -o red_flag.dll red_flag.c -lkernel32 -O2 -Wall
if errorlevel 1 (
    echo FAILED: red_flag.dll
    pause
    exit /b 1
)

echo Building inject.exe...
%CC% -o inject.exe inject.c -lkernel32 -O2 -Wall
if errorlevel 1 (
    echo FAILED: inject.exe
    pause
    exit /b 1
)

echo.
echo Done.
echo   red_flag.dll  ^<-- inject into game
echo   inject.exe    ^<-- run after starting the game
echo.
echo Usage:  inject.exe red_flag.dll
pause
