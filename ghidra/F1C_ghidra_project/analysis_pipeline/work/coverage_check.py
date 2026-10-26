import os, re

analyzed_dir = r"%USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed"
docs_dir     = r"%USERPROFILE%\Desktop\F1C_ghidra_project\docs"
triage_file  = r"%USERPROFILE%\Desktop\F1C_ghidra_project\docs\decompiled_full_index_final.md"

# Full ## FUN_ entries in docs/
documented = set()
for fname in os.listdir(docs_dir):
    if not fname.endswith('.md'):
        continue
    with open(os.path.join(docs_dir, fname), encoding='utf-8', errors='ignore') as f:
        for line in f:
            m = re.match(r'^##+ FUN_([0-9A-Fa-f]{8})', line)
            if m:
                documented.add(m.group(1).lower())

# Triage-indexed addresses
triaged = set()
with open(triage_file, encoding='utf-8', errors='ignore') as f:
    for line in f:
        m = re.match(r'^\| 0x([0-9a-f]{8})', line)
        if m:
            triaged.add(m.group(1).lower())

# Categorize analyzed files by size
small, large = [], []
for fname in os.listdir(analyzed_dir):
    if not fname.endswith('.c'):
        continue
    m = re.search(r'FUN_([0-9A-Fa-f]{8})', fname)
    if not m:
        continue
    addr = m.group(1).lower()
    size = os.path.getsize(os.path.join(analyzed_dir, fname))
    (small if size < 2048 else large).append(addr)

not_digested_small = []
for addr in small:
    if addr not in triaged and addr not in documented:
        not_digested_small.append(addr)

def report(addr_list, label):
    s = set(addr_list)
    in_docs   = len(s & documented)
    tri_only  = len((s & triaged) - documented)
    neither   = len(s) - in_docs - tri_only
    print(f"\n{label} ({len(s)} files)")
    print(f"  ## FUN_ full entry : {in_docs:4d} ({100*in_docs/len(s):5.1f}%)")
    print(f"  Triage line only   : {tri_only:4d} ({100*tri_only/len(s):5.1f}%)")
    print(f"  NOT DIGESTED       : {neither:4d} ({100*neither/len(s):5.1f}%)")

report(small, "SMALL <2KB")
report(large, "LARGE >=2KB")
report(small + large, "ALL analyzed")

print(f"\nSmall files not digested at all: {len(not_digested_small)}")
if not_digested_small:
    for a in sorted(not_digested_small)[:20]:
        print(f"  0x{a}")
    if len(not_digested_small) > 20:
        print(f"  ... and {len(not_digested_small)-20} more")
