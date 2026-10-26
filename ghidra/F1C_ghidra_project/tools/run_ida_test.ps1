# Minimal IDA test — run this first to verify headless works
# Run: powershell -ExecutionPolicy Bypass -File tools\run_ida_test.ps1

$IDA  = "C:\Program Files\IDA Professional 9.1\idat.exe"
$BIN  = "%USERPROFILE%\Desktop\F1 Challenge V10\F1 Challenge Online.exe"
$SCR  = "%USERPROFILE%\Desktop\F1C_ghidra_project\tools\ida_test.py"
$LOG  = "%USERPROFILE%\Desktop\F1C_ghidra_project\tools\ida_run.log"

Write-Host "Testing IDA headless..."
Write-Host "IDA:    $IDA"
Write-Host "Binary: $BIN"
Write-Host "Script: $SCR"
Write-Host ""

# Capture all stdout+stderr to log
& $IDA -A -B "-S$SCR" $BIN *>&1 | Tee-Object -FilePath $LOG

Write-Host ""
Write-Host "--- IDA console log saved to: $LOG ---"
Write-Host ""

# Check if test output was written
$testOut = "%USERPROFILE%\Desktop\F1C_ghidra_project\tools\ida_test_output.txt"
if (Test-Path $testOut) {
    Write-Host "--- Test output: ---"
    Get-Content $testOut
} else {
    Write-Host "WARNING: ida_test_output.txt was NOT created" -ForegroundColor Red
    Write-Host "IDA script did not execute. Check ida_run.log for errors."
}

Write-Host ""
Read-Host "Press Enter to close"
