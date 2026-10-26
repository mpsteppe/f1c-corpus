# Headless: wait for auto-analysis, write function stats per segment, save IDB.
import idaapi, idautils, idc, ida_segment, ida_hexrays, os, json
idaapi.auto_wait()
out = os.environ.get("GTR2_STATS", "stats.json")
segs = {}
n = 0
for ea in idautils.Functions():
    n += 1
    s = ida_segment.getseg(ea)
    name = ida_segment.get_segm_name(s) if s else "?"
    segs[name] = segs.get(name, 0) + 1
sample = []
try:
    ida_hexrays.init_hexrays_plugin()
    for i, ea in enumerate(idautils.Functions()):
        if i % 1000 == 0 and len(sample) < 10:
            try:
                c = str(ida_hexrays.decompile(ea))
                sample.append({"ea": hex(ea), "ok": True, "lines": c.count("\n")})
            except Exception as e:
                sample.append({"ea": hex(ea), "ok": False, "err": str(e)[:200]})
except Exception as e:
    sample.append({"hexrays": str(e)[:200]})
json.dump({"functions": n, "by_segment": segs, "entry": hex(idc.get_inf_attr(idc.INF_START_IP)), "decompile_sample": sample}, open(out, "w"), indent=1)
idc.save_database(idc.get_idb_path(), 0)
idaapi.qexit(0)
