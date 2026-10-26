import idaapi
import idautils
import idc
import ida_hexrays
import os

ida_hexrays.init_hexrays_plugin()

OUT_DIR = os.environ.get("DEC_OUT", r"%USERPROFILE%/Desktop/F1/research/reverse_engineering/gtr2_ida_decompile/functions")
os.makedirs(OUT_DIR, exist_ok=True)

idaapi.auto_wait()

hf = idaapi.hexrays_failure_t()
ok = 0
fail = 0
skip = 0

import ida_segment
# GTR2: skip SecuROM sections (age/agis/quod/.rld); only real game code
funcs = [ea for ea in idautils.Functions() if ida_segment.get_segm_name(ida_segment.getseg(ea)) == ".text"]
total = len(funcs)

for i, ea in enumerate(funcs):
    name = idc.get_func_name(ea) or f"FUN_{ea:08X}"
    safe_name = "".join(c if c.isalnum() or c in "_" else "_" for c in name)
    fname = os.path.join(OUT_DIR, f"{safe_name}_{ea:08x}.c")

    if os.path.exists(fname):
        skip += 1
        continue

    try:
        cfunc = idaapi.decompile(ea, hf)
        if cfunc is None:
            fail += 1
            continue
        code = str(cfunc)
        with open(fname, "w", encoding="utf-8") as f:
            f.write(code)
        ok += 1
    except Exception:
        fail += 1

with open(r"%USERPROFILE%/Desktop/F1/research/reverse_engineering/gtr2_ida_decompile/batch_result.txt", "w") as f:
    f.write(f"total={total} ok={ok} fail={fail} skip={skip}\n")

idaapi.qexit(0)
