#!/usr/bin/env python3
r"""Extract F1C's floating-point constant pool with values + referencing funcs.

IDA already tagged 1959 FP constants (dbl_/flt_) and who reads them in
tools/ida_data_xrefs.csv, but only by symbol, not value. This reads the actual
double/float bytes from the exe and joins them with the referencing functions and
their source files (via work/source_file_map_expanded.csv) — turning "dbl_59E430"
into "0x0059e430 = 0.75  read by tire_manager funcs". These are the real physics /
math magic numbers, unattributed until now.

Output: work/fp_constants.csv
  addr, type, value, ref_count, files, ref_funcs
sorted by ref_count desc.
"""
import csv, os, re, struct

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
EXE = r"%USERPROFILE%\Desktop\F1 Challenge V10\F1 Challenge Online.exe"
DXREFS = os.path.join(ROOT, "tools", "ida_data_xrefs.csv")
SFMAP = os.path.join(ROOT, "work", "source_file_map_expanded.csv")
OUT = os.path.join(ROOT, "work", "fp_constants.csv")
IB = 0x400000

FP = re.compile(r"^(dbl|flt)_[0-9A-Fa-f]+$")


def main():
    d = open(EXE, "rb").read()
    pe = d.index(b"PE\0\0"); coff = pe + 4
    optsz = struct.unpack_from("<H", d, coff + 16)[0]
    sh = coff + 20 + optsz
    nsec = struct.unpack_from("<H", d, coff + 2)[0]
    secs = []
    for i in range(nsec):
        b = sh + i * 40
        vs, va = struct.unpack_from("<II", d, b + 8)
        rs, ro = struct.unpack_from("<II", d, b + 16)
        secs.append((IB + va, IB + va + vs, ro))

    def foff(va):
        for a, b, ro in secs:
            if a <= va < b:
                return ro + (va - a)
        return None

    # func -> source file (usable rows only)
    ffile = {}
    if os.path.exists(SFMAP):
        for r in csv.DictReader(open(SFMAP, encoding="utf-8", errors="replace")):
            if r.get("confidence") in ("ANCHOR", "HIGH") and r.get("file"):
                ffile[r["func_addr"].lower()] = r["file"]

    # gather FP consts + referencing funcs
    kind = {}       # addr -> 'dbl'/'flt'
    refs = {}       # addr -> set(func)
    for r in csv.DictReader(open(DXREFS, encoding="utf-8", errors="replace")):
        gn = (r.get("global_name") or "").strip()
        if not FP.match(gn):
            continue
        ga = (r.get("global_addr") or "").strip().lower()
        if not ga:
            continue
        kind[ga] = gn.split("_")[0]
        refs.setdefault(ga, set()).add((r.get("func_addr") or "").lower())

    rows = []
    for ga in refs:
        va = int(ga, 16)
        off = foff(va)
        sz = 8 if kind[ga] == "dbl" else 4
        if off is None or off + sz > len(d):
            continue          # BSS / uninitialized .data — no file bytes
        val = struct.unpack_from("<d" if sz == 8 else "<f", d, off)[0]
        rf = sorted(f for f in refs[ga] if f)
        files = sorted(set(ffile[f] for f in rf if f in ffile))
        rows.append(dict(addr="0x%08x" % va, type=kind[ga],
                         value=repr(round(val, 8)), ref_count=len(rf),
                         files="|".join(files), ref_funcs="|".join(rf[:8])))

    rows.sort(key=lambda r: -r["ref_count"])
    with open(OUT, "w", newline="", encoding="utf-8") as f:
        w = csv.DictWriter(f, fieldnames=["addr", "type", "value", "ref_count", "files", "ref_funcs"])
        w.writeheader()
        for r in rows:
            w.writerow(r)

    from collections import Counter
    filed = [r for r in rows if r["files"]]
    print(f"{len(rows)} FP constants  |  {len(filed)} attributed to a source file")
    print(f"-> {OUT}")
    print("most-referenced constants:")
    for r in rows[:15]:
        print(f"   {r['addr']}  {r['type']}  {r['value']:>16}  x{r['ref_count']:<3}  {r['files']}")


if __name__ == "__main__":
    main()
