@echo off
:: IDA Pro headless COMPREHENSIVE export for F1 Challenge Online.exe
:: v2 — exports 12 data types + decompiles all IDA-only functions
::
:: IMPORTANT: Run from PowerShell for reliable output:
::   & "C:\Program Files\IDA Professional 9.1\idat.exe" -A -B -S"C:\...\ida_export_all.py" "C:\...\F1 Challenge Online.exe"
::
:: This bat file works but may swallow some output due to async subprocess handling.

set IDA_PATH=C:\Program Files\IDA Professional 9.1
set BINARY=%USERPROFILE%\Desktop\F1 Challenge V10\F1 Challenge Online.exe
set SCRIPT=%~dp0ida_export_all.py
set IDAT=%IDA_PATH%\idat.exe

if not exist "%IDAT%" (
    echo ERROR: idat.exe not found at %IDA_PATH%
    pause
    exit /b 1
)

echo ================================================================
echo IDA Comprehensive Export v2
echo ================================================================
echo Binary: %BINARY%
echo Script: %SCRIPT%
echo.
echo Exports: functions, vtables, xrefs, data_xrefs, strings,
echo          imports, segments, switches, stack_frames, exceptions,
echo          gaps, decompile (all IDA-only via Hex-Rays)
echo.
echo NOTE: Reusing existing IDA database (no -c flag).
echo       For first run, add -c flag manually.
echo ================================================================
echo.

"%IDAT%" -A -B -S"%SCRIPT%" "%BINARY%"

echo.
echo ================================================================
echo Done. Check tools\ for:
echo   ida_functions.csv    ida_vtables.csv     ida_xrefs.csv
echo   ida_data_xrefs.csv   ida_strings.csv     ida_imports.csv
echo   ida_segments.csv     ida_switches.csv    ida_stack_frames.csv
echo   ida_exceptions.csv   ida_gaps.csv        decompiled_ida\*.c
echo ================================================================
pause
