"""
Automated IDA-vs-docs structural verifier for all documented F1C functions.

Runs INSIDE IDA (py_exec_file). For every canonical `## FUN_<addr>` doc entry,
parses the deterministically-checkable claims from the entry body and tests each
against the real IDA function:

  EXISTS   IDA has a function starting at <addr>
           (Ghidra/IDA boundary disagreements fail here)
  FUN refs every FUN_<other> mentioned in the body is actually related to this
           function (appears in its refs-from OR its callers) -- catches
           fabricated call-chain / "calls FUN_x" claims
  OFFSETS  every `+0xNNN` mentioned in the body appears as a real immediate or
           displacement operand in the function -- catches wrong struct offsets

Output:
  tools/ida_doc_verification.csv   per-entry scores
  stdout                           aggregate factual-rate + worst offenders

Note: absence of a claim is not a failure; rates are over *checkable* claims.
"""
import idautils, ida_funcs, ida_bytes, idc, os, re, csv
from collections import Counter, defaultdict

ROOT = r"%USERPROFILE%\Desktop\F1C_ghidra_project"
DOCS = os.path.join(ROOT, "docs")

hdr  = re.compile(r'^##\s+FUN_([0-9a-fA-F]{8})\b')
funref = re.compile(r'FUN_([0-9a-fA-F]{8})')
offref = re.compile(r'\+0x([0-9a-fA-F]{1,5})\b')

# ---- 1. parse doc entries ----
entries = {}   # addr(int) -> dict(doc, fun_refs:set, offs:set)
for fn in sorted(os.listdir(DOCS)):
    if not fn.endswith(".md"):
        continue
    path = os.path.join(DOCS, fn)
    lines = open(path, encoding="utf-8", errors="replace").read().splitlines()
    i = 0
    while i < len(lines):
        m = hdr.match(lines[i])
        if not m:
            i += 1; continue
        addr = int(m.group(1), 16)
        # gather body until next '## ' header
        j = i + 1
        body = []
        while j < len(lines) and not lines[j].startswith("## "):
            body.append(lines[j]); j += 1
        text = "\n".join(body)
        frefs = {int(x, 16) for x in funref.findall(text)} - {addr}
        offs  = {int(x, 16) for x in offref.findall(text)}
        if addr not in entries:      # first (canonical) entry wins
            entries[addr] = dict(doc=fn, fun_refs=frefs, offs=offs)
        i = j

print("documented FUN_ entries:", len(entries))

# ---- 2. per-function IDA facts ----
def func_facts(fea):
    f = ida_funcs.get_func(fea)
    if not f:
        return None
    refs_from = set()     # code+data targets referenced anywhere in the func
    opervals  = set()     # immediate + displacement constants
    for head in idautils.Heads(f.start_ea, f.end_ea):
        for xr in idautils.CodeRefsFrom(head, 0):
            refs_from.add(xr)
        for xr in idautils.DataRefsFrom(head):
            refs_from.add(xr)
        insn = idc.print_insn_mnem(head)
        if not insn:
            continue
        for op in range(4):
            t = idc.get_operand_type(head, op)
            if t == idc.o_imm:
                opervals.add(idc.get_operand_value(head, op) & 0xffffffff)
            elif t in (idc.o_displ, idc.o_phrase):
                v = idc.get_operand_value(head, op) & 0xffffffff
                if v:
                    opervals.add(v)
    callers = {x.frm for x in idautils.XrefsTo(f.start_ea, 0)}
    # map refs_from to owning function starts too (for "calls FUN_x" where x is
    # reached indirectly via a thunk/adjacent head)
    ref_funcs = set()
    for r in refs_from:
        rf = ida_funcs.get_func(r)
        if rf:
            ref_funcs.add(rf.start_ea)
    caller_funcs = set()
    for c in callers:
        cf = ida_funcs.get_func(c)
        if cf:
            caller_funcs.add(cf.start_ea)
    return dict(refs_from=refs_from, ref_funcs=ref_funcs,
                caller_funcs=caller_funcs, opervals=opervals)

rows = []
agg = Counter()
fun_claim_total = fun_claim_ok = 0
off_claim_total = off_claim_ok = 0
worst = []   # (score, addr, doc, detail)

for addr, e in entries.items():
    facts = func_facts(addr)
    exists = facts is not None
    agg["entries"] += 1
    if not exists:
        agg["not_a_function"] += 1
        rows.append((("0x%08x" % addr), e["doc"], 0, "", len(e["fun_refs"]), 0,
                     len(e["offs"]), 0, "NOT_A_FUNCTION"))
        worst.append((-1.0, addr, e["doc"], "not a function in IDA"))
        continue
    agg["exists"] += 1
    related = facts["ref_funcs"] | facts["caller_funcs"] | facts["refs_from"]
    fok = sum(1 for r in e["fun_refs"] if r in related)
    ftot = len(e["fun_refs"])
    ook = sum(1 for o in e["offs"] if o in facts["opervals"])
    otot = len(e["offs"])
    fun_claim_total += ftot; fun_claim_ok += fok
    off_claim_total += otot; off_claim_ok += ook
    checkable = ftot + otot
    score = (fok + ook) / checkable if checkable else None
    rows.append((("0x%08x" % addr), e["doc"], 1,
                 ("%.2f" % score) if score is not None else "",
                 ftot, fok, otot, ook, ""))
    if score is not None and checkable >= 2 and score < 0.5:
        det = "fun %d/%d off %d/%d" % (fok, ftot, ook, otot)
        worst.append((score, addr, e["doc"], det))

# ---- 3. write + summarize ----
with open(os.path.join(ROOT, "tools", "ida_doc_verification.csv"), "w", newline="") as fp:
    w = csv.writer(fp)
    w.writerow(["addr", "doc", "exists", "score", "n_fun_claims", "fun_ok",
                "n_off_claims", "off_ok", "flag"])
    for r in sorted(rows):
        w.writerow(r)

print("\n=== AGGREGATE ===")
print("entries:", agg["entries"])
print("exist as IDA function: %d (%.1f%%)  |  NOT a function: %d"
      % (agg["exists"], 100*agg["exists"]/agg["entries"], agg["not_a_function"]))
print("FUN-reference claims:  %d checked, %d resolve (%.1f%%)"
      % (fun_claim_total, fun_claim_ok,
         100*fun_claim_ok/fun_claim_total if fun_claim_total else 0))
print("+offset claims:        %d checked, %d present (%.1f%%)"
      % (off_claim_total, off_claim_ok,
         100*off_claim_ok/off_claim_total if off_claim_total else 0))

# per-doc rollup: mean score
bydoc = defaultdict(list)
for r in rows:
    if r[3] != "":
        bydoc[r[1]].append(float(r[3]))
print("\n=== per-doc mean structural score (files with >=20 scored entries) ===")
for doc in sorted(bydoc, key=lambda d: sum(bydoc[d])/len(bydoc[d])):
    v = bydoc[doc]
    if len(v) >= 20:
        print("  %.2f  %-34s (n=%d)" % (sum(v)/len(v), doc, len(v)))

print("\n=== worst offenders (score<0.5, >=2 claims), first 25 ===")
for score, addr, doc, det in sorted(worst)[:25]:
    tag = "NOTFUNC" if score < 0 else ("%.2f" % score)
    print("  %s  0x%08x  %-30s %s" % (tag, addr, doc, det))

print("\nwrote tools/ida_doc_verification.csv")
