r"""IDA Hex-Rays decompiler for cross-binary functions.

Modes:
  XBIN_ALL=1        decompile EVERY function in the binary (full corpus)
  XBIN_ADDRS=file   decompile only the hex addresses listed (targeted)
  XBIN_CALLEES=1    also pull one level of callees (targeted mode only)

Output: one <addr>__<name>.c per function into XBIN_OUT (absolute dir).
Defaults to cross_binary/_decomp/<XBIN_NAME>/ if XBIN_OUT unset.

Run (PowerShell, existing DB reused):
  $env:XBIN_NAME="f1_2002"; $env:XBIN_ALL="1"
  $env:XBIN_OUT="C:\...\source_material\F1 2002\decompiled"
  & "C:\Program Files\IDA Professional 9.1\idat.exe" -A `
    -S"C:\...\cross_binary\scripts\ida_decompile.py" "C:\...\f1_2002.exe.i64"
"""
import ida_hexrays, ida_funcs, ida_name, ida_auto, idautils, idc
import os

ida_auto.auto_wait()
if not ida_hexrays.init_hexrays_plugin():
    print("Hex-Rays not available"); idc.qexit(1)

name = os.environ.get('XBIN_NAME', 'unknown')
addr_file = os.environ.get('XBIN_ADDRS')
want_all = os.environ.get('XBIN_ALL') == '1'
want_callees = os.environ.get('XBIN_CALLEES') == '1'
outdir = os.environ.get('XBIN_OUT') or os.path.join(
    r"%USERPROFILE%\Desktop\F1C_ghidra_project\cross_binary\_decomp", name)
os.makedirs(outdir, exist_ok=True)

targets = []
if want_all:
    targets = list(idautils.Functions())
else:
    with open(addr_file) as f:
        for line in f:
            line = line.strip()
            if line and not line.startswith('#'):
                targets.append(int(line, 16))
    # optionally add one level of callees
    if want_callees:
        for ea in list(targets):
            fn = ida_funcs.get_func(ea)
            if not fn:
                continue
            for head in idautils.FuncItems(ea):
                for xr in idautils.CodeRefsFrom(head, 0):
                    cf = ida_funcs.get_func(xr)
                    if cf and cf.start_ea != ea and cf.start_ea not in targets:
                        targets.append(cf.start_ea)

done = 0
total = len(targets)
for i, ea in enumerate(targets):
    if want_all and i % 1000 == 0:
        print(f"  ... {i}/{total} ({done} written)")
    fn = ida_funcs.get_func(ea)
    if not fn:
        continue
    try:
        cf = ida_hexrays.decompile(fn.start_ea)
    except Exception as e:
        print(f"  fail {ea:#x}: {e}"); continue
    if not cf:
        print(f"  fail {ea:#x}: no output"); continue
    nm = ida_name.get_name(fn.start_ea) or f"sub_{fn.start_ea:x}"
    safe = nm.replace('?', '_').replace(':', '_').replace('<', '_').replace('>', '_')[:60]
    path = os.path.join(outdir, f"0x{fn.start_ea:08x}__{safe}.c")
    with open(path, 'w', encoding='utf-8', errors='replace') as out:
        out.write(f"// {name}  {fn.start_ea:#010x}  size={fn.size()}\n")
        out.write(str(cf))
    done += 1

print(f"[{name}] decompiled {done}/{len(targets)} -> {outdir}")
idc.qexit(0)
