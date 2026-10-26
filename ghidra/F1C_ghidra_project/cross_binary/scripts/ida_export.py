r"""IDA headless exporter for cross-binary delta finding.

Exports byte_sigs + strings for ONE binary into cross_binary/_fingerprints/.
Output name comes from env var XBIN_NAME (e.g. scgt, f1_2000, f1_2002_demo).

Run (PowerShell, reuse or create DB):
  $env:XBIN_NAME="scgt"
  & "C:\Program Files\IDA Professional 9.1\idat.exe" -A -B `
    -S"%USERPROFILE%\Desktop\F1C_ghidra_project\cross_binary\scripts\ida_export.py" `
    "C:\...\Spcar.exe"

Then: python cross_binary/scripts/xbin_match.py <XBIN_NAME>
"""
import ida_funcs, ida_name, ida_auto, ida_bytes, ida_nalt, idautils, idc
import hashlib, os

ida_auto.auto_wait()

name = os.environ.get('XBIN_NAME')
if not name:
    b = os.path.basename(ida_nalt.get_input_file_path()).lower()
    name = os.path.splitext(b)[0].replace(' ', '_')

out = r"%USERPROFILE%\Desktop\F1C_ghidra_project\cross_binary\_fingerprints"
os.makedirs(out, exist_ok=True)

# --- byte sigs ---
sig_p = os.path.join(out, f"{name}_byte_sigs.csv")
n = 0
with open(sig_p, 'w') as f:
    f.write("address,name,size,head_bytes,full_hash\n")
    for ea in idautils.Functions():
        fn = ida_funcs.get_func(ea)
        if not fn:
            continue
        size = fn.size()
        if size < 8:
            continue
        head = ida_bytes.get_bytes(ea, min(64, size))
        if not head:
            continue
        full = ida_bytes.get_bytes(ea, size)
        h = hashlib.md5(full).hexdigest() if full else ''
        f.write(f"0x{ea:08x},{ida_name.get_name(ea)},{size},{head.hex()},{h}\n")
        n += 1

# --- strings + referencing funcs ---
str_p = os.path.join(out, f"{name}_strings.csv")
import ida_xref
sc = 0
with open(str_p, 'w', encoding='utf-8', errors='replace') as f:
    f.write("address,string,length,type,referencing_functions\n")
    for si in idautils.Strings():
        s = str(si)
        ea = si.ea
        refs = []
        xr = ida_xref.get_first_dref_to(ea)
        while xr != idc.BADADDR:
            fn = ida_funcs.get_func(xr)
            if fn:
                refs.append(f"0x{fn.start_ea:08x}")
            xr = ida_xref.get_next_dref_to(ea, xr)
        s_clean = s.replace('"', "'").replace('\n', ' ').replace(',', ' ')
        f.write(f'0x{ea:08x},"{s_clean}",{si.length},{si.strtype},{";".join(sorted(set(refs)))}\n')
        sc += 1

print(f"[{name}] {n} sigs -> {sig_p}")
print(f"[{name}] {sc} strings -> {str_p}")
idc.qexit(0)
