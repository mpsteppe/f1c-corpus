# Dump per-function byte MD5 from the EXISTING corpus IDB (old exe, sdk_lab i64).
# Load-only, no re-analysis, no decompile. Fast.
import os
import json
import hashlib
import ida_auto
import idaapi
import idautils
import idc
import ida_bytes

OUT = r"%USERPROFILE%/Desktop/f1_challenge_online_version_08082026/decompiled"

ida_auto.auto_wait()

meta = []
for ea in idautils.Functions():
    name = idc.get_func_name(ea) or ("FUN_%08X" % ea)
    f = idaapi.get_func(ea)
    size = f.size() if f else 0
    try:
        raw = ida_bytes.get_bytes(ea, size) or b""
    except Exception:
        raw = b""
    meta.append({"addr": hex(ea), "name": name, "size": size, "md5": hashlib.md5(raw).hexdigest()})

with open(os.path.join(OUT, "old_functions_meta.jsonl"), "w", encoding="utf-8") as fh:
    for m in meta:
        fh.write(json.dumps(m) + "\n")

print("[dump] DONE total=%d" % len(meta), flush=True)
