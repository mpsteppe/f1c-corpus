"""IDA script: export function byte signatures for cross-binary matching.
Exports first 32 bytes + size + hash for each function.
Run on both F1C and NASCAR to compare.
"""
import ida_funcs
import ida_name
import ida_auto
import ida_bytes
import idautils
import idc
import hashlib
import os

ida_auto.auto_wait()

# Determine which binary this is
import ida_nalt
binary_name = os.path.basename(ida_nalt.get_input_file_path())
if 'NASCAR' in binary_name or 'nascar' in binary_name:
    prefix = 'nascar03'
elif 'F1' in binary_name or 'Challenge' in binary_name:
    prefix = 'f1c'
else:
    prefix = 'unknown'

outpath = os.path.join(r"%USERPROFILE%\Desktop\F1C_ghidra_project\tools", f"{prefix}_byte_sigs.csv")

count = 0
with open(outpath, 'w') as f:
    f.write("address,name,size,head_bytes,full_hash\n")
    for ea in idautils.Functions():
        func = ida_funcs.get_func(ea)
        if not func:
            continue
        size = func.size()
        if size < 8:
            continue
        
        name = ida_name.get_name(ea)
        
        # Read first 64 bytes (enough for signature matching)
        head_len = min(64, size)
        head_bytes = ida_bytes.get_bytes(ea, head_len)
        if not head_bytes:
            continue
        head_hex = head_bytes.hex()
        
        # Full function hash
        full_bytes = ida_bytes.get_bytes(ea, size)
        if full_bytes:
            full_hash = hashlib.md5(full_bytes).hexdigest()
        else:
            full_hash = ''
        
        f.write(f"0x{ea:08x},{name},{size},{head_hex},{full_hash}\n")
        count += 1

print(f"Exported {count} function signatures to {outpath}")
idc.qexit(0)
