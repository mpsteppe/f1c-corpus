# Full Hex-Rays decompile of every sibling engine into per-game decompiled/ folders.
# Sequential (one IDA instance at a time). Reuses existing .i64 DBs.
$ErrorActionPreference = "Continue"
$idat = "C:\Program Files\IDA Professional 9.1\idat.exe"
$script = "%USERPROFILE%\Desktop\F1C_ghidra_project\cross_binary\scripts\ida_decompile.py"
$sm = "%USERPROFILE%\Desktop\F1C_ghidra_project\source_material"

# name ; DB (.i64) ; output decompiled dir
$jobs = @(
  @("f1_2002",  "$sm\F1 2002\Game\f1_2002.exe.i64",                                              "$sm\F1 2002\decompiled"),
  @("nascar03", "$sm\Nascar Thunder 2003\NASCAR Thunder TM 2003 Demo\NASCAR_Thunder_2003_Demo.exe.i64", "$sm\Nascar Thunder 2003\decompiled"),
  @("nascar04", "$sm\Nascar Thunder 2004\NASCAR Thunder TM 2004 Demo\NASCAR_Thunder_2004_Demo.exe.i64", "$sm\Nascar Thunder 2004\decompiled"),
  @("scgt",     "$sm\Sports Car GT\Game\Spcar.exe.i64",                                          "$sm\Sports Car GT\decompiled")
)

foreach ($j in $jobs) {
  $name = $j[0]; $db = $j[1]; $out = $j[2]
  $log = "%USERPROFILE%\Desktop\F1C_ghidra_project\cross_binary\decompile_${name}.log"
  Write-Host "==== decompiling $name -> $out ===="
  if (-not (Test-Path $db)) { Write-Host "  MISSING DB: $db  (skip)"; continue }
  $env:XBIN_NAME = $name
  $env:XBIN_ALL  = "1"
  $env:XBIN_OUT  = $out
  $env:XBIN_ADDRS = ""
  $env:XBIN_CALLEES = ""
  & $idat -A -L"$log" -S"$script" "$db"
  $n = (Get-ChildItem -Path $out -Filter *.c -ErrorAction SilentlyContinue | Measure-Object).Count
  Write-Host "  $name done: $n .c files (exit $LASTEXITCODE)"
}
Write-Host "ALL DECOMPILE JOBS COMPLETE"
