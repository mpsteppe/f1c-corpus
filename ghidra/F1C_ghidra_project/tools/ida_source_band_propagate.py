"""
Propagate source-file attribution across contiguous translation-unit bands.

MSVC lays each .cpp's functions out contiguously in .text, in source order.
The 124 assert-anchored functions (ida_source_funcs.csv) are known waypoints
whose line numbers rise monotonically with address. Between two consecutive
anchors of the SAME file, every intervening function belongs to that file
(tier=STRONG). Anchors themselves are tier=FACT. Address gaps that fall
between anchors of DIFFERENT files are left unattributed (tier=NONE) — the
TU boundary is uncertain there.

Output: tools/ida_source_funcs_expanded.csv
Run inside IDA via MCP py_exec_file.
"""
import idautils, ida_funcs, idc, os, csv

OUT_DIR = r"%USERPROFILE%\Desktop\F1C_ghidra_project\tools"
ANCHORS = os.path.join(OUT_DIR, "ida_source_funcs.csv")

# load anchors (skip ambiguous multi-file ones for banding)
anchors = {}  # func_ea -> file
with open(ANCHORS) as fp:
    r = csv.DictReader(fp)
    for row in r:
        if int(row["n_distinct_files"]) == 1:
            anchors[int(row["func_ea"], 16)] = row["dominant_file"]

# ordered list of all functions in the image
all_funcs = sorted(idautils.Functions())
anchor_eas = sorted(anchors)
print("anchors (unambiguous):", len(anchor_eas), "total funcs:", len(all_funcs))

# build bands: walk anchors; a band is a maximal run where consecutive anchors
# share a file AND no differently-filed anchor sits between them.
# Assign every function whose ea is in [band_lo, band_hi] to the band file.
attrib = {}   # func_ea -> (file, tier)
for ea in anchor_eas:
    attrib[ea] = (anchors[ea], "FACT")

# For each pair of adjacent anchors with the same file, fill the gap.
for a, b in zip(anchor_eas, anchor_eas[1:]):
    if anchors[a] == anchors[b]:
        f = anchors[a]
        for fe in all_funcs:
            if a < fe < b and fe not in attrib:
                attrib[fe] = (f, "STRONG")

# coverage summary
from collections import Counter
tier_counts = Counter(t for _, t in attrib.values())
file_counts = Counter(f for f, _ in attrib.values())
print("attributed:", len(attrib), tier_counts)

with open(os.path.join(OUT_DIR, "ida_source_funcs_expanded.csv"), "w", newline="") as fp:
    w = csv.writer(fp)
    w.writerow(["func_ea", "func_name", "file", "tier"])
    for fe in all_funcs:
        if fe in attrib:
            f, t = attrib[fe]
            w.writerow(["0x%08x" % fe, idc.get_func_name(fe), f, t])

print("\n=== expanded coverage per file (top 20) ===")
for f, n in file_counts.most_common(20):
    print("%5d  %s" % (n, f))
print("\nwrote ida_source_funcs_expanded.csv")
