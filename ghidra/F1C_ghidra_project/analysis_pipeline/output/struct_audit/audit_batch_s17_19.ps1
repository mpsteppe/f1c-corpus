# Batch struct audit - verify offsets against .c files
$analyzed = "%USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed"

# ============ SECTION 17: ViewportStruct ============
Write-Host "=== Section 17: ViewportStruct ==="
$f1 = "$analyzed\0x005425a0__FUN_005425a0.c"
$f2 = "$analyzed\0x0054c110__FUN_0054c110.c"
Select-String $f1 -Pattern '\+ 0x54|\+ 0x58|\+ 0x68|\+ 0x15c|\+ 100' | ForEach-Object { Write-Host "  $($_.LineNumber): $($_.Line.Trim())" }
Select-String $f2 -Pattern '\+ 0x234|\+ 0x238|\+ 0x3c' | ForEach-Object { Write-Host "  $($_.LineNumber): $($_.Line.Trim())" }

# ============ SECTION 18: LinkedList ============
Write-Host "=== Section 18: LinkedList ==="
$f3 = "$analyzed\0x00586000__FUN_00586000.c"
Select-String $f3 -Pattern 'param_1\[0\]|param_1\[1\]|param_1\[2\]|param_1\[3\]|\*param_1' | ForEach-Object { Write-Host "  $($_.LineNumber): $($_.Line.Trim())" }

# ============ SECTION 19: RigidBodyState ============
Write-Host "=== Section 19: RigidBodyState spot-check ==="
$funcs = @(
    "0x00569a20__FUN_00569a20.c", "0x005694e0__FUN_005694e0.c", "0x00569860__FUN_00569860.c",
    "0x0043e5d0__FUN_0043e5d0.c", "0x00441d60__FUN_00441d60.c", "0x00438930__FUN_00438930.c",
    "0x004359a0__FUN_004359a0.c", "0x00448e90__FUN_00448e90.c", "0x00431390__FUN_00431390.c",
    "0x0056d1c0__FUN_0056d1c0.c", "0x005691d0__FUN_005691d0.c", "0x00569670__FUN_00569670.c"
)

$offsets_rigidbody = @("0x004","0x00c","0x014","0x018","0x01c","0x024","0x02c","0x034","0x03c","0x044","0x04c","0x054","0x05c")
foreach ($f in $funcs) {
    $path = Join-Path $analyzed $f
    if (Test-Path $path) {
        $matches = Select-String $path -Pattern '\+ 0x004|\+ 0x00c|\+ 0x018|\+ 0x01c|\+ 0x02c|\+ 0x034'
        foreach ($m in $matches) { Write-Host "  $f : $($m.Line.Trim())" }
    }
}
