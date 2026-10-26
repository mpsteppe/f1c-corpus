"""
Apply IDA-harvested source-file attributions to canonical docs/ entries.

Targets ONLY level-2 `## FUN_<addr>` headers (the canonical doc entry per
iron rule 7). For each, locate the `Source:` line in the entry body and
rewrite it to the IDA ground-truth file, tagged with tier. Classifies each:
  CONFIRM  doc basename already == IDA file
  CORRECT  doc claimed a different / fabricated source
  FILL     doc had 'unknown' or no Source line

Dry-run by default: prints classification + sample diffs, writes nothing.
Pass --apply to edit docs and emit a corrections log fragment.
"""
import csv, re, os, glob, sys, io
from collections import Counter
try:
    sys.stdout.reconfigure(encoding="utf-8")
except Exception:
    pass

ROOT = r"%USERPROFILE%\Desktop\F1C_ghidra_project"
APPLY = "--apply" in sys.argv

FACT_ONLY = "--with-strong" not in sys.argv
attr = {}
with open(os.path.join(ROOT, "tools/ida_source_funcs_expanded.csv")) as fp:
    for r in csv.DictReader(fp):
        if FACT_ONLY and r["tier"] != "FACT":
            continue
        attr[r["func_ea"][2:].lower()] = (r["file"], r["tier"])

hdr = re.compile(r'^##\s+FUN_([0-9a-fA-F]{8})\b')
src = re.compile(r'^(\s*)Source:\s*(.*)$', re.I)

CPP_TOK = re.compile(r'`?([A-Za-z0-9_]+\.(?:cpp|cxx|c|hpp|h))`?', re.I)

def base_in(text):
    m = CPP_TOK.search(text or '')
    return m.group(1).lower() if m else None

def rewrite_source(old, ida_file, tier):
    """Swap only the source-file token, preserving any inline description."""
    repl = f"{ida_file} [ida:{tier.lower()}]"
    m = CPP_TOK.search(old)
    if m:                                   # replace the .cpp token in place
        return old[:m.start()] + repl + old[m.end():]
    if re.search(r'\bunknown\b', old, re.I): # fill the 'unknown' placeholder
        return re.sub(r'\bunknown\b', repl, old, count=1, flags=re.I)
    # non-cpp source note (e.g. 'memory manager'): prepend the file
    return re.sub(r'(Source:\s*)', r'\1' + repl + '; ', old, count=1, flags=re.I)

cls = Counter()
corrections = []          # (addr, docfile, old_source, new_file)
edits = []                # (docpath, lineidx, newline)
samples = []

for d in sorted(glob.glob(os.path.join(ROOT, "docs", "*.md"))):
    lines = open(d, encoding="utf-8", errors="replace").read().splitlines()
    changed = False
    i = 0
    while i < len(lines):
        m = hdr.match(lines[i])
        if not m:
            i += 1; continue
        a = m.group(1).lower()
        if a not in attr:
            i += 1; continue
        ida_file, tier = attr[a]
        # find Source: within this entry (until next '## ' header, cap 25 lines)
        sidx = None
        for j in range(i + 1, min(i + 25, len(lines))):
            if lines[j].startswith("## "):
                break
            if src.match(lines[j]):
                sidx = j; break
        tag = f"[ida:{tier.lower()}]"
        newsrc = f"Source: {ida_file} {tag}"
        if sidx is None:
            cls["FILL_nosrcline"] += 1
            # insert a Source line right after a blank line following header
            ins = i + 1
            while ins < len(lines) and lines[ins].strip() == "":
                ins += 1
            edits.append((d, ins, "INSERT", newsrc))
            corrections.append((a, os.path.basename(d), "(none)", ida_file))
        else:
            old = lines[sidx]
            oldbase = base_in(old)
            newline = rewrite_source(old, ida_file, tier)
            if oldbase == ida_file.lower():
                cls["CONFIRM"] += 1
            elif oldbase is None or "unknown" in old.lower():
                cls["FILL_unknown"] += 1
                corrections.append((a, os.path.basename(d), old.strip(), ida_file))
            else:
                cls["CORRECT"] += 1
                corrections.append((a, os.path.basename(d), old.strip(), ida_file))
                if len(samples) < 20:
                    samples.append((a, os.path.basename(d), old.strip(), newline.strip()))
            if newline != old:
                edits.append((d, sidx, "REPLACE", newline))
        i += 1

print("classification:", dict(cls))
print("total doc entries touched:", sum(cls.values()), "| corrections+fills:", len(corrections))
print("\n--- sample CORRECT (fabricated -> real) ---")
for a, df, old, new in samples:
    print(f"  FUN_{a} [{df}]\n    - {old}\n    + {new}")

if APPLY:
    # group edits per file, apply from bottom up to keep indices valid
    byfile = {}
    for d, idx, op, payload in edits:
        byfile.setdefault(d, []).append((idx, op, payload))
    for d, ops in byfile.items():
        raw = open(d, "rb").read()
        eol = "\r\n" if b"\r\n" in raw else "\n"
        lines = raw.decode("utf-8", "replace").splitlines()
        for idx, op, payload in sorted(ops, reverse=True):
            if op == "REPLACE":
                lines[idx] = payload
            else:  # INSERT
                lines.insert(idx, payload)
                lines.insert(idx + 1, "")
        with open(d, "w", encoding="utf-8", newline="") as fp:
            fp.write(eol.join(lines) + eol)
    # corrections log fragment
    logp = os.path.join(ROOT, "tools", "source_attribution_corrections.md")
    with open(logp, "w", encoding="utf-8") as fp:
        fp.write("## [CORRECTION] IDA source-file attribution pass (443-func map)\n\n")
        fp.write("| addr | doc | old Source | -> IDA file |\n|---|---|---|---|\n")
        for a, df, old, new in corrections:
            fp.write(f"| FUN_{a} | {df} | {old} | {new} |\n")
    print(f"\nAPPLIED. edits: {len(edits)}. corrections log -> tools/source_attribution_corrections.md")
else:
    print("\n(dry-run — pass --apply to write)")
