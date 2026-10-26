"""
Decompile the 4 giant-gap functions using Hex-Rays.
Writes .c files to analysis_pipeline/analyzed/
Debug log: tools/ida_decompile_gaps.log

Run:
    & "C:\Program Files\IDA Professional 9.1\idat.exe" -A -B "-S%USERPROFILE%\Desktop\F1C_ghidra_project\tools\ida_decompile_gaps.py" "%USERPROFILE%\Desktop\F1 Challenge V10\F1 Challenge Online.exe"
"""

import os, sys, traceback

LOG = r"%USERPROFILE%\Desktop\F1C_ghidra_project\tools\ida_decompile_gaps.log"

def log(msg):
    with open(LOG, "a", encoding="utf-8") as f:
        f.write(msg + "\n")
    print(msg)

# clear log
open(LOG, "w").close()
log("=== ida_decompile_gaps.py started ===")

try:
    import idc
    log("idc OK")
    import idaapi
    log("idaapi OK")
    import idautils
    log("idautils OK")
    import ida_funcs
    log("ida_funcs OK")
except Exception as e:
    log(f"IMPORT ERROR: {e}")
    sys.exit(1)

try:
    idaapi.auto_wait()
    log("auto_wait done")
except Exception as e:
    log(f"auto_wait ERROR: {e}")

# Try loading Hex-Rays
try:
    import ida_hexrays
    log("ida_hexrays imported")
    hr_ok = ida_hexrays.init_hexrays_plugin()
    log(f"init_hexrays_plugin = {hr_ok}")
except Exception as e:
    log(f"Hex-Rays ERROR: {e}\n{traceback.format_exc()}")
    hr_ok = False

TARGETS = [0x0056fa96, 0x00575bbd, 0x00578f76, 0x00579ccf]
OUT_DIR = r"%USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed"

log(f"OUT_DIR exists: {os.path.isdir(OUT_DIR)}")

for ea in TARGETS:
    log(f"\n--- 0x{ea:08x} ---")
    fn = ida_funcs.get_func(ea)
    log(f"  get_func = {fn}")
    if fn is None:
        log("  SKIP: no function")
        continue

    log(f"  size = {fn.size()}")
    name = idc.get_func_name(ea) or f"FUN_{ea:08x}"
    log(f"  name = {name}")

    if not hr_ok:
        log("  SKIP: Hex-Rays not available")
        continue

    try:
        cfunc = ida_hexrays.decompile(ea)
        log(f"  decompile = {cfunc}")
    except Exception as e:
        log(f"  decompile ERROR: {e}\n{traceback.format_exc()}")
        continue

    if cfunc is None:
        log("  decompile returned None")
        continue

    code = str(cfunc)
    log(f"  code length = {len(code)}")

    fname = f"0x{ea:08x}__FUN_{ea:08x}.c"
    out_path = os.path.join(OUT_DIR, fname)
    try:
        with open(out_path, "w", encoding="utf-8") as f:
            f.write(f"// Address: 0x{ea:08x}\n// Size: {fn.size()} bytes\n// Name: {name}\n\n")
            f.write(code)
        log(f"  WRITTEN: {fname}")
    except Exception as e:
        log(f"  write ERROR: {e}")

log("\n=== done ===")
try:
    idc.exit(0)
except Exception:
    pass
