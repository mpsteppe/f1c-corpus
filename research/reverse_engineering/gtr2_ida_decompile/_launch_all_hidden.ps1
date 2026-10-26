# Start every skeleton worker hidden (no windows). Logs -> %TEMP%\gtr2_workers\.
# Stop all: _stop_all_workers.ps1. Re-run anytime: finished chunks are skipped.
$root = $PSScriptRoot
$logs = Join-Path $env:TEMP 'gtr2_workers'
New-Item -ItemType Directory -Force $logs | Out-Null
$empty = Join-Path $logs 'empty_stdin.txt'; Set-Content $empty ''
Get-ChildItem $root -Filter '_launch_skel_*.ps1' | Where-Object { $_.Name -ne '_launch_skel_PILOT.ps1' } | ForEach-Object {
    $n = $_.BaseName -replace '_launch_skel_', ''
    Start-Process powershell -WindowStyle Hidden -WorkingDirectory $root `
        -ArgumentList '-NoProfile', '-ExecutionPolicy', 'Bypass', '-File', $_.FullName `
        -RedirectStandardOutput (Join-Path $logs "$n.out.txt") -RedirectStandardError (Join-Path $logs "$n.err.txt") `
        -RedirectStandardInput $empty
    Start-Sleep -Milliseconds 1500
}
"started; logs in $logs"
