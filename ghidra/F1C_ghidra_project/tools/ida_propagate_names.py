"""
Propagate Ghidra doc names into the IDA database.

For every canonical `## FUN_<addr> - <Label>` doc entry, sanitize the human
label into a C identifier and apply it to the IDA function (only if that
function is still anonymous: sub_/nullsub_/j_/unknown_). Names are unique;
collisions get a short address suffix.

Trust note: doc labels are GUESS-tier (~90%), so propagated names inherit that
accuracy INCLUDING known mislabels (e.g. the AI/commentary cluster). They are
navigation aids, not ground truth -- re-derive from typed decompiles later.

Non-destructive: touches only the IDB. Reverse with set_name(ea,"").
Dry-run by default; pass --apply to write, then idb_save separately.
Output: tools/ida_name_propagation.csv
"""
import idautils, idc, ida_funcs, ida_name, os, re, csv, sys

ROOT = r"%USERPROFILE%\Desktop\F1C_ghidra_project"
DOCS = os.path.join(ROOT, "docs")
APPLY = "--apply" in sys.argv or os.environ.get("F1C_NAME_APPLY") == "1"
# match 2-4 hash headers so Class::Method() names under #### are harvested too
hdr = re.compile(r'^#{2,4}\s+FUN_([0-9a-fA-F]{8})\s*[—–\-]+\s*(.+?)\s*$')
# status/audit words that are NOT function names
JUNK = {"fail", "pass", "partial", "unknown", "unidentified", "todo", "tbd",
        "na", "none", "null", "confirmed", "correction", "verified", "guess",
        "partialunknown", "unidentifiedlogic", "wrong", "ok"}
CPPSIG = re.compile(r'[A-Za-z_]\w*::[~A-Za-z_]\w*')

def sanitize(label):
    label = re.split(r'\s+[/|]\s+', label)[0]      # first meaning
    label = re.sub(r'\([^)]*\)', ' ', label)       # drop parentheticals
    label = label.replace("::", "_")               # keep class/method as Class_Method
    toks = re.findall(r'[A-Za-z0-9]+', label)
    if not toks:
        return None
    name = "".join(t[:1].upper() + t[1:] for t in toks)
    if name[0].isdigit():
        name = "F_" + name
    return name[:48]

def label_rank(label):
    """higher = better name source"""
    if CPPSIG.search(label):
        return 3                                    # real Class::Method()
    low = re.sub(r'[^a-z]', '', label.lower())
    if low in JUNK or len(low) < 4:
        return 0                                    # status token / too short
    return 1 + min(len(re.findall(r'[A-Za-z]+', label)), 1)  # prose: 2

# collect ALL labels per addr, keep best-ranked
cand = {}   # addr -> (rank, label)
for fn in sorted(os.listdir(DOCS)):
    if not fn.endswith(".md"):
        continue
    for ln in open(os.path.join(DOCS, fn), encoding="utf-8", errors="replace"):
        m = hdr.match(ln)
        if not m:
            continue
        a = int(m.group(1), 16)
        lab = m.group(2)
        r = label_rank(lab)
        if r == 0:
            continue
        if a not in cand or r > cand[a][0] or (r == cand[a][0] and len(lab) > len(cand[a][1])):
            cand[a] = (r, lab)

labels = {}
for a, (r, lab) in cand.items():
    nm = sanitize(lab)
    if nm and re.sub(r'[^a-z]', '', nm.lower()) not in JUNK:
        labels[a] = nm

print("addrs with usable label:", len(labels),
      "| Class::Method sourced:", sum(1 for a in cand if cand[a][0] == 3))

used = set()
# seed used-set with existing meaningful names to avoid collisions
for f in idautils.Functions():
    n = idc.get_func_name(f)
    if not n.startswith(("sub_", "nullsub_", "j_", "unknown_")):
        used.add(n)

rows = []
stat = dict(applied=0, skip_named=0, skip_nofunc=0, collided=0, unchanged=0)
for a, base in sorted(labels.items()):
    f = ida_funcs.get_func(a)
    if not f or f.start_ea != a:
        stat["skip_nofunc"] += 1
        continue
    cur = idc.get_func_name(a)
    if not cur.startswith(("sub_", "nullsub_", "j_", "unknown_")):
        stat["skip_named"] += 1
        continue
    name = base
    if name in used:
        name = f"{base}_{a & 0xffff:04x}"
        stat["collided"] += 1
    if name in used:
        stat["unchanged"] += 1
        continue
    used.add(name)
    rows.append((("0x%08x" % a), cur, name))
    if APPLY:
        if ida_name.set_name(a, name, ida_name.SN_NOCHECK | ida_name.SN_FORCE):
            stat["applied"] += 1

with open(os.path.join(ROOT, "tools", "ida_name_propagation.csv"), "w", newline="", encoding="utf-8") as fp:
    w = csv.writer(fp)
    w.writerow(["addr", "old_name", "new_name"])
    for r in rows:
        w.writerow(r)

print("planned renames:", len(rows), "| stats:", stat)
print("\n--- sample (first 20) ---")
for a, old, new in rows[:20]:
    print(f"  {a}  {old:14s} -> {new}")
if not APPLY:
    print("\n(dry-run -- pass --apply to write, then idb_save)")
else:
    print(f"\nAPPLIED {stat['applied']} names. Run idb_save to persist.")
