"""
Build a compact evidence bundle for a 1/10 stratified sample of documented
functions, for semantic label-vs-behavior audit.

For each sampled `## FUN_<addr>` doc entry, emit ONE block:
  doc label (independent of IDA names) + struct score (from verifier) +
  IDA-independent evidence: prototype, callee TARGET addrs, strings, notable
  immediate constants, referenced global addrs.

Strings/constants/proto are ground truth the name-propagation never touched, so a
label that contradicts them is a real mislabel. Output: work/spotcheck_evidence.txt
Run inside IDA via py_exec_file.
"""
import idautils, ida_funcs, ida_bytes, idc, os, re, csv

ROOT = r"%USERPROFILE%\Desktop\F1C_ghidra_project"
DOCS = os.path.join(ROOT, "docs")
OUT  = os.path.join(ROOT, "work", "spotcheck_evidence.txt")

hdr = re.compile(r'^#{2,4}\s+FUN_([0-9a-fA-F]{8})\s*[—–\-]+\s*(.+?)\s*$')
JUNK = {"fail","pass","partial","unknown","unidentified","todo","tbd","na","none",
        "null","confirmed","correction","verified","guess","wrong","ok"}
CPPSIG = re.compile(r'[A-Za-z_]\w*::[~A-Za-z_]\w*')

def rank(lab):
    if CPPSIG.search(lab): return 3
    low = re.sub(r'[^a-z]','',lab.lower())
    if low in JUNK or len(low) < 4: return 0
    return 2

# best descriptive label per addr
cand = {}
for fn in sorted(os.listdir(DOCS)):
    if not fn.endswith(".md"): continue
    for ln in open(os.path.join(DOCS,fn),encoding="utf-8",errors="replace"):
        m = hdr.match(ln)
        if not m: continue
        a = int(m.group(1),16); lab = m.group(2); r = rank(lab)
        if r == 0: continue
        if a not in cand or r > cand[a][0] or (r==cand[a][0] and len(lab)>len(cand[a][1])):
            cand[a] = (r, lab, fn)

# struct scores from earlier verifier
score = {}
vpath = os.path.join(ROOT,"tools","ida_doc_verification.csv")
if os.path.exists(vpath):
    for r in csv.DictReader(open(vpath)):
        score[int(r["addr"],16)] = r["score"]

addrs = sorted(cand)
sample = addrs[::10]     # 1/10 stratified by address

def facts(fea):
    f = ida_funcs.get_func(fea)
    if not f: return None
    strings, consts, callee_addrs, glob_addrs = [], [], [], []
    for h in idautils.Heads(f.start_ea, f.end_ea):
        for xr in idautils.CodeRefsFrom(h,0):
            g = ida_funcs.get_func(xr)
            if g and g.start_ea != f.start_ea and g.start_ea not in callee_addrs:
                callee_addrs.append(g.start_ea)
        for xr in idautils.DataRefsFrom(h):
            s = idc.get_strlit_contents(xr, -1, -1)
            if s:
                t = s.decode("latin1","replace")
                if t not in strings: strings.append(t)
            elif xr not in glob_addrs:
                glob_addrs.append(xr)
        for op in range(3):
            if idc.get_operand_type(h,op) == idc.o_imm:
                v = idc.get_operand_value(h,op) & 0xffffffff
                if 8 <= v <= 0x7fffffff and v not in consts:
                    consts.append(v)
    return dict(size=f.end_ea-f.start_ea, proto=idc.get_type(fea) or "",
                strings=strings[:6], consts=consts[:6],
                callees=callee_addrs[:6], globs=glob_addrs[:5])

lines = []
n = 0
for a in sample:
    fx = facts(a)
    _, lab, fn = cand[a]
    sc = score.get(a, "?")
    if not fx:
        lines.append(f"0x{a:08x} | {fn} | s={sc} | LABEL: {lab}\n  <NOT A FUNCTION IN IDA>\n")
        continue
    n += 1
    st = "; ".join('"%s"' % s[:28] for s in fx["strings"]) or "-"
    cs = ",".join(hex(c) for c in fx["consts"]) or "-"
    ce = ",".join("0x%x"%c for c in fx["callees"]) or "-"
    gl = ",".join("0x%x"%g for g in fx["globs"]) or "-"
    lines.append(
        f"0x{a:08x} | {fn} | s={sc} sz={fx['size']} | LABEL: {lab}\n"
        f"  proto: {fx['proto']}\n"
        f"  strings: {st}\n"
        f"  consts: {cs}\n"
        f"  callees: {ce}   globals: {gl}\n")

open(OUT,"w",encoding="utf-8").write("\n".join(lines))
print(f"sampled {len(sample)} of {len(addrs)} documented entries (1/10)")
print(f"functions with IDA facts: {n} | not-a-function: {len(sample)-n}")
print(f"wrote {OUT}")
