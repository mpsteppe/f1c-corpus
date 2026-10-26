# IDA Pro headless COMPREHENSIVE export for F1 Challenge Online.exe
# Run from PowerShell for reliable output (bat/cmd may swallow subprocess output)

$IDA  = "C:\Program Files\IDA Professional 9.1\idat.exe"
$BIN  = "%USERPROFILE%\Desktop\F1 Challenge V10\F1 Challenge Online.exe"
$SCR  = Join-Path $PSScriptRoot "ida_export_all.py"

if (-not (Test-Path $IDA)) {
    Write-Host "ERROR: idat.exe not found at $IDA" -ForegroundColor Red
    exit 1
}

Write-Host "=" * 70
Write-Host "IDA Comprehensive Export v2"
Write-Host "=" * 70
Write-Host "Binary:  $BIN"
Write-Host "Script:  $SCR"
Write-Host ""
Write-Host "Exports: functions, vtables, xrefs, data_xrefs, strings,"
Write-Host "         imports, segments, switches, stack_frames, exceptions,"
Write-Host "         gaps, decompile (all IDA-only via Hex-Rays)"
Write-Host "=" * 70
Write-Host ""

# -A = autonomous (no dialog boxes)
# -B = batch mode (exit after script)
# No -c flag = reuse existing database (much faster)
& $IDA -A -B "-S$SCR" $BIN

Write-Host ""
Write-Host "Done. Check tools\ for ida_*.csv and decompiled_ida\*.c" -ForegroundColor Green
