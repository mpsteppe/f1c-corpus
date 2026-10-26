"""
Force-define the 802 documented addresses that IDA has no function at.

For each canonical `## FUN_<addr>` whose address is not a function in IDA:
  1. if the bytes are undefined, undefine any stale item then try create_insn
  2. attempt ida_funcs.add_func(addr)
  3. classify: CREATED (now a function) | FAILED (can't -> likely not code / a
     Ghidra hallucination -> doc-error candidate)

Newly CREATED functions get a quick structural re-score (offset + FUN-ref claims)
so we see whether their docs verify once the boundary exists.

Does NOT idb_save automatically -- prints a summary; save is a separate step.
Output: tools/ida_define_results.csv
Run inside IDA via py_exec_file.
"""
import idautils, ida_funcs, ida_bytes, ida_ua, idc, os, re, csv
from collections import Counter

ROOT = r"%USERPROFILE%\Desktop\F1C_ghidra_project"
DOCS = os.path.join(ROOT, "docs")
hdr    = re.compile(r'^##\s+FUN_([0-9a-fA-F]{8})\b')
funref = re.compile(r'FUN_([0-9a-fA-F]{8})')
offref = re.compile(r'\+0x([0-9a-fA-F]{1,5})\b')

# parse canonical entries + their claims
entries = {}
for fn in sorted(os.listdir(DOCS)):
    if not fn.endswith(".md"):
        continue
    lines = open(os.path.join(DOCS, fn), encoding="utf-8", errors="replace").read().splitlines()
    i = 0
    while i < len(lines):
        m = hdr.match(lines[i])
        if not m:
            i += 1; continue
        addr = int(m.group(1), 16)
        j = i + 1; body = []
        while j < len(lines) and not lines[j].startswith("## "):
            body.append(lines[j]); j += 1
        if addr not in entries:
            text = "\n".join(body)
            entries[addr] = dict(doc=fn,
                                 fun_refs={int(x,16) for x in funref.findall(text)} - {addr},
                                 offs={int(x,16) for x in offref.findall(text)})
        i = j

missing = [a for a in entries if not ida_funcs.get_func(a)]
print("missing (no IDA function):", len(missing))

def try_define(addr):
    # if inside another function already, treat as covered
    if ida_funcs.get_func(addr):
        return "already"
    fl = ida_bytes.get_flags(addr)
    if not ida_bytes.is_code(fl):
        # undefine stale data item, then try to make an instruction
        ida_bytes.del_items(addr, ida_bytes.DELIT_SIMPLE, 16)
        if ida_ua.create_insn(addr) == 0:
            return "notcode"
    if ida_funcs.add_func(addr):
        return "created"
    return "failed"

def facts(fea):
    f = ida_funcs.get_func(fea)
    if not f:
        return None
    refs, ops = set(), set()
    for h in idautils.Heads(f.start_ea, f.end_ea):
        for xr in idautils.CodeRefsFrom(h, 0): refs.add(xr)
        for xr in idautils.DataRefsFrom(h):    refs.add(xr)
        for op in range(4):
            t = idc.get_operand_type(h, op)
            if t == idc.o_imm:
                ops.add(idc.get_operand_value(h, op) & 0xffffffff)
            elif t in (idc.o_displ, idc.o_phrase):
                v = idc.get_operand_value(h, op) & 0xffffffff
                if v: ops.add(v)
    rf = set()
    for r in refs:
        g = ida_funcs.get_func(r)
        if g: rf.add(g.start_ea)
    return rf, ops

res = Counter()
rows = []
rescored = []
for a in missing:
    st = try_define(a)
    res[st] += 1
    ok = ""
    if st in ("created", "already"):
        ff = facts(a)
        if ff:
            rf, ops = ff
            e = entries[a]
            fok = sum(1 for r in e["fun_refs"] if r in rf)
            ook = sum(1 for o in e["offs"] if o in ops)
            tot = len(e["fun_refs"]) + len(e["offs"])
            sc = (fok + ook) / tot if tot else None
            if sc is not None:
                rescored.append(sc)
                ok = "%.2f" % sc
    rows.append((("0x%08x" % a), entries[a]["doc"], st, ok))

with open(os.path.join(ROOT, "tools", "ida_define_results.csv"), "w", newline="") as fp:
    w = csv.writer(fp)
    w.writerow(["addr", "doc", "result", "rescore"])
    for r in sorted(rows):
        w.writerow(r)

print("\n=== define results ===", dict(res))
if rescored:
    good = sum(1 for s in rescored if s >= 0.5)
    print("newly-scored functions: %d | mean score %.2f | >=0.5: %d (%.0f%%)"
          % (len(rescored), sum(rescored)/len(rescored), good, 100*good/len(rescored)))
print("\ndoc-error candidates (still not code) -> tools/ida_define_results.csv result=notcode/failed")
notcode = [r for r in rows if r[2] in ("notcode", "failed")]
print("still-not-a-function:", len(notcode), "(these docs likely describe non-functions)")
for r in sorted(notcode)[:15]:
    print("  ", r[0], r[1], r[2])
print("\nNOTE: changes are in-memory only until idb_save.")
