"""IDA script: export functions and strings from NASCAR 2003.
Run with: idat.exe -A -B -c -S"this_script.py" "NASCAR_Thunder_2003_Demo.exe"
"""
import ida_funcs
import ida_name
import ida_auto
import ida_bytes
import ida_nalt
import ida_xref
import idautils
import idc
import os

ida_auto.auto_wait()

base = r"%USERPROFILE%\Desktop\F1C_ghidra_project\tools"

# Export functions
func_path = os.path.join(base, "nascar03_functions.csv")
count = 0
named = 0
with open(func_path, 'w') as f:
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
print(f"Functions: {count} total, {named} named -> {func_path}")

# Export strings with referencing functions
str_path = os.path.join(base, "nascar03_strings.csv")
str_count = 0
with open(str_path, 'w') as f:
    f.write("address,string,length,type,referencing_functions\n")
    for si in idautils.Strings():
        s = str(si)
        if not s or len(s) < 4:
            continue
        # Find xrefs to this string
        refs = []
        for xref in idautils.XrefsTo(si.ea):
            func = ida_funcs.get_func(xref.frm)
            if func:
                refs.append(f"0x{func.start_ea:08x}")
        refs = list(set(refs))  # deduplicate
        
        # Escape CSV
        s_escaped = s.replace('"', '""')
        refs_str = ";".join(refs)
        f.write(f'0x{si.ea:08x},"{s_escaped}",{len(s)},{si.strtype},{refs_str}\n')
        str_count += 1

print(f"Strings: {str_count} -> {str_path}")
idc.qexit(0)
