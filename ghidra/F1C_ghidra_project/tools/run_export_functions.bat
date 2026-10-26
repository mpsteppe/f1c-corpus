@echo off
REM Phase 0 Step 1: Export function sizes from Ghidra project
REM Run this first, then run binary_coverage_audit.py

set GHIDRA=%USERPROFILE%\Desktop\ghidra_12.1.2_PUBLIC_20260605\ghidra_12.1.2_PUBLIC
set PROJECT_DIR=%USERPROFILE%\Desktop\F1C_ghidra_project
set PROJECT_NAME=F1C_Analysis
set SCRIPT_DIR=%PROJECT_DIR%\scripts

echo Running Ghidra headless to export function sizes...
"%GHIDRA%\support\analyzeHeadless.bat" ^
    "%PROJECT_DIR%" %PROJECT_NAME% ^
    -noanalysis ^
    -scriptPath "%SCRIPT_DIR%" ^
    -postScript ExportFunctionSizes.java

echo.
echo Done. Check work\function_sizes.csv
echo Then run: python tools\binary_coverage_audit.py
pause
