# Batch decompile of F1 Challenge Online.exe (v49) into decompiled/functions/
# Mirrors corpus layout: one .c per function, <name>_<addr>.c
# Also dumps per-function byte MD5 (for byte-level compare) and strings index.
import os
import json
import hashlib
import ida_auto
import idaapi
import idautils
import idc
import ida_bytes

OUT = r"%USERPROFILE%/Desktop/f1_challenge_online_version_08082026/decompiled"
FUNCDIR = os.path.join(OUT, "functions")
os.makedirs(FUNCDIR, exist_ok=True)

ida_auto.auto_wait()

hf = idaapi.hexrays_failure_t()
funcs = list(idautils.Functions())
meta = []
ok = 0
fail = 0

for i, ea in enumerate(funcs):
    name = idc.get_func_name(ea) or ("FUN_%08X" % ea)
    f = idaapi.get_func(ea)
    size = f.size() if f else 0
    try:
        raw = ida_bytes.get_bytes(ea, size) or b""
    except Exception:
        raw = b""
    try:
        cfunc = idaapi.decompile(ea, hf)
    except Exception:
        cfunc = None
    if cfunc is None:
        fail += 1
        meta.append({"addr": hex(ea), "name": name, "size": size, "md5": hashlib.md5(raw).hexdigest(), "decompiled": False})
        continue
    code = str(cfunc)
    safe = "".join(c if c.isalnum() or c in "_" else "_" for c in name)
    with open(os.path.join(FUNCDIR, "%s_%08x.c" % (safe, ea)), "w", encoding="utf-8") as fh:
        fh.write(code)
    ok += 1
    meta.append({"addr": hex(ea), "name": name, "size": size, "md5": hashlib.md5(raw).hexdigest(), "decompiled": True})
    if (i + 1) % 500 == 0:
        print("[batch] %d/%d ok=%d fail=%d" % (i + 1, len(funcs), ok, fail), flush=True)

with open(os.path.join(OUT, "functions_meta.jsonl"), "w", encoding="utf-8") as fh:
    for m in meta:
        fh.write(json.dumps(m) + "\n")

st = []
for s in idautils.Strings():
    try:
        st.append({"ea": hex(s.ea), "len": s.length, "str": str(s)})
    except Exception:
        pass
with open(os.path.join(OUT, "strings_index.json"), "w", encoding="utf-8") as fh:
    json.dump(st, fh, indent=1)

try:
    idc.save_database(os.path.join(OUT, "F1_Challenge_Online_v49.i64"))
except Exception as e:
    print("[batch] save_database failed: %s" % e, flush=True)

print("[batch] DONE ok=%d fail=%d total=%d" % (ok, fail, len(funcs)), flush=True)
