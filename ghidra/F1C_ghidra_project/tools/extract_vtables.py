#!/usr/bin/env python3
r"""Recover C++ vtables from .rdata (RTTI-less object model).

F1C is /GR- (no RTTI) so IDA's vtable scan is empty. But virtual dispatch tables
physically exist as arrays of code pointers in .rdata. This scans them, splits
back-to-back tables at their referenced base addresses (a constructor does
`mov [ecx], offset vtable`), excludes switch/jump tables, and attributes each
vtable to the function(s) that load its base.

Inputs (static):
  the exe                     .rdata bytes + section map
  tools/ida_switches.csv      jtable_addr -> exclude these (they are switch tables)
  tools/ida_data_xrefs.csv    func_addr, global_addr -> who references a .rdata addr

Output: work/vtables.csv
  vtable_addr, slots, class, ctor_funcs, method_addrs
    class      = derived tag (from ctor func if named, else vtbl_<addr>)
    ctor_funcs = functions that load this vtable base (the constructors)
    method_addrs = the slot targets (virtual methods), '|'-joined

A slot count of N means the class has N virtual methods (in table order).
"""
import csv, os, re, struct
from bisect import bisect_left

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
EXE = r"%USERPROFILE%\Desktop\F1 Challenge V10\F1 Challenge Online.exe"
SWITCHES = os.path.join(ROOT, "tools", "ida_switches.csv")
DXREFS = os.path.join(ROOT, "tools", "ida_data_xrefs.csv")
FUNCS = os.path.join(ROOT, "tools", "ida_functions.csv")
OUT = os.path.join(ROOT, "work", "vtables.csv")
IB = 0x400000
MIN_SLOTS = 3


def h(s):
    s = s.strip()
    return int(s, 16) if s else None


def main():
    d = open(EXE, "rb").read()
    pe = d.index(b"PE\0\0"); coff = pe + 4
    optsz = struct.unpack_from("<H", d, coff + 16)[0]
    sh = coff + 20 + optsz
    nsec = struct.unpack_from("<H", d, coff + 2)[0]
    secs = {}
    for i in range(nsec):
        b = sh + i * 40
        nm = d[b:b+8].rstrip(b"\0").decode("latin1")
        vs, va = struct.unpack_from("<II", d, b + 8)
        rs, ro = struct.unpack_from("<II", d, b + 16)
        secs[nm] = (va, vs, ro, rs)

    code = [(IB + va, IB + va + vs) for nm, (va, vs, ro, rs) in secs.items()
            if nm in (".text", ".text1")]

    def is_code(v):
        return any(a <= v < b for a, b in code)

    rva, vs, ro, rs = secs[".rdata"]
    rbase, rend = ro, ro + vs
    rd_va = IB + rva

    def file_off(va):
        return ro + (va - rd_va)

    # switch jump tables to exclude
    switch_tables = set()
    for r in csv.DictReader(open(SWITCHES, encoding="utf-8", errors="replace")):
        j = h(r.get("jtable_addr", "") or "")
        if j:
            switch_tables.add(j)

    # data xrefs: addr referenced -> list of referencing funcs
    ref_by = {}
    for r in csv.DictReader(open(DXREFS, encoding="utf-8", errors="replace")):
        g = h(r.get("global_addr", "") or "")
        f = r.get("func_addr", "")
        if g:
            ref_by.setdefault(g, []).append(f)
    ref_addrs = sorted(ref_by)

    # function names
    fname = {}
    for r in csv.DictReader(open(FUNCS, encoding="utf-8", errors="replace")):
        a = h(r.get("addr", "") or "")
        if a is not None:
            nm = r.get("name") or ""
            fname[a] = nm

    # scan .rdata for runs of >=1 consecutive code pointers
    runs = []
    i = rbase; start = None; cur = 0
    while i + 4 <= rend:
        v = struct.unpack_from("<I", d, i)[0]
        if is_code(v):
            if cur == 0:
                start = rd_va + (i - ro)
            cur += 1
        else:
            if cur:
                runs.append((start, cur))
            cur = 0
        i += 4
    if cur:
        runs.append((start, cur))

    # split each run at referenced addresses (each = a new vtable base)
    vtables = []
    for base, n in runs:
        span_end = base + n * 4
        # cut points = referenced addresses inside (base, span_end)
        lo = bisect_left(ref_addrs, base)
        cuts = [base]
        j = lo
        while j < len(ref_addrs) and ref_addrs[j] < span_end:
            if ref_addrs[j] > base:
                cuts.append(ref_addrs[j])
            j += 1
        cuts.append(span_end)
        cuts = sorted(set(c for c in cuts if (c - base) % 4 == 0))
        for k in range(len(cuts) - 1):
            vb, ve = cuts[k], cuts[k + 1]
            slots = (ve - vb) // 4
            if slots < MIN_SLOTS:
                continue
            vtables.append((vb, slots))

    rows = []
    for vb, slots in vtables:
        is_switch = vb in switch_tables
        ctors = ref_by.get(vb, [])
        # class tag from first named ctor
        cls = ""
        for c in ctors:
            a = h(c)
            nm = fname.get(a, "")
            if nm and not nm.startswith("sub_"):
                cls = nm
                break
        if not cls:
            cls = "vtbl_%08x" % vb
        methods = []
        for s in range(slots):
            methods.append("0x%08x" % struct.unpack_from("<I", d, file_off(vb) + s * 4)[0])
        kind = "switch" if is_switch else ("vtable" if ctors else "unref")
        rows.append(dict(vtable_addr="0x%08x" % vb, slots=slots, kind=kind,
                         cls=cls, ctor_funcs="|".join(ctors[:5]),
                         method_addrs="|".join(methods)))

    rows.sort(key=lambda r: (r["kind"] != "vtable", -r["slots"]))
    with open(OUT, "w", newline="", encoding="utf-8") as f:
        w = csv.DictWriter(f, fieldnames=["vtable_addr", "slots", "kind", "cls",
                                          "ctor_funcs", "method_addrs"])
        w.writeheader()
        for r in rows:
            w.writerow(r)

    from collections import Counter
    kc = Counter(r["kind"] for r in rows)
    vt = [r for r in rows if r["kind"] == "vtable"]
    print(f"{len(rows)} tables  |  vtable(ref'd)={kc['vtable']}  unref={kc['unref']}  switch={kc['switch']}")
    print(f"vtable method slots total: {sum(r['slots'] for r in vt)}")
    print(f"-> {OUT}")
    print("largest referenced vtables:")
    for r in vt[:15]:
        print(f"   {r['vtable_addr']}  {r['slots']:4d} slots  ctor={r['ctor_funcs'][:11]}  {r['cls']}")


if __name__ == "__main__":
    main()
