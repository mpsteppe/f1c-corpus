"""IDA script: export all function names from 3DConfig.exe (debug build).
Run with: idat.exe -A -B -c -S"this_script.py" "path/to/3DConfig.exe"
"""
import ida_funcs
import ida_name
import ida_auto
import idautils
import idc
import os

# Wait for auto-analysis
ida_auto.auto_wait()

outpath = r"%USERPROFILE%\Desktop\F1C_ghidra_project\tools\3dconfig_functions.csv"

count = 0
named = 0
with open(outpath, 'w') as f:
    f.write("address,name,size,flags\n")
    for ea in idautils.Functions():
        name = ida_name.get_name(ea)
        func = ida_funcs.get_func(ea)
        size = func.size() if func else 0
        flags = func.flags if func else 0
        f.write(f"0x{ea:08x},{name},{size},0x{flags:x}\n")
        count += 1
        if name and not name.startswith("sub_") and not name.startswith("j_"):
            named += 1

print(f"Exported {count} functions ({named} named) to {outpath}")
idc.qexit(0)
