"""IDA script: export functions, strings, and byte sigs from NASCAR 2004."""
import ida_funcs, ida_name, ida_auto, ida_bytes, idautils, idc, hashlib, os, csv

ida_auto.auto_wait()
base = r"%USERPROFILE%\Desktop\F1C_ghidra_project\tools"

# Functions
count = 0
with open(os.path.join(base, "nascar04_functions.csv"), 'w') as f:
    f.write("address,name,size,flags\n")
    for ea in idautils.Functions():
        name = ida_name.get_name(ea)
        func = ida_funcs.get_func(ea)
        size = func.size() if func else 0
        flags = func.flags if func else 0
        f.write(f"0x{ea:08x},{name},{size},0x{flags:x}\n")
        count += 1
print(f"Functions: {count}")

# Strings
str_count = 0
with open(os.path.join(base, "nascar04_strings.csv"), 'w') as f:
    f.write("address,string,length,type,referencing_functions\n")
    for si in idautils.Strings():
        s = str(si)
        if not s or len(s) < 4:
            continue
        refs = []
        for xref in idautils.XrefsTo(si.ea):
            func = ida_funcs.get_func(xref.frm)
            if func:
                refs.append(f"0x{func.start_ea:08x}")
        refs = list(set(refs))
        s_escaped = s.replace('"', '""')
        f.write(f'0x{si.ea:08x},"{s_escaped}",{len(s)},{si.strtype},{";".join(refs)}\n')
        str_count += 1
print(f"Strings: {str_count}")

# Byte sigs
sig_count = 0
with open(os.path.join(base, "nascar04_byte_sigs.csv"), 'w') as f:
    f.write("address,name,size,head_bytes,full_hash\n")
    for ea in idautils.Functions():
        func = ida_funcs.get_func(ea)
        if not func or func.size() < 8:
            continue
        name = ida_name.get_name(ea)
        size = func.size()
        head_len = min(64, size)
        head_bytes = ida_bytes.get_bytes(ea, head_len)
        if not head_bytes:
            continue
        full_bytes = ida_bytes.get_bytes(ea, size)
        full_hash = hashlib.md5(full_bytes).hexdigest() if full_bytes else ''
        f.write(f"0x{ea:08x},{name},{size},{head_bytes.hex()},{full_hash}\n")
        sig_count += 1
print(f"Byte sigs: {sig_count}")

idc.qexit(0)
