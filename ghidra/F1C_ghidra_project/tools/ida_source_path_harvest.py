"""
Harvest embedded source-file attributions from the F1C binary.

The exe leaks ISI's original __FILE__ assert strings
(D:\\dev\\F1_1999_2002\\Source\\*.cpp). Every function that asserts references
its own file string; the line number is pushed adjacent to the file pointer.

For each file string we walk xrefs -> ref site -> containing function, and scan
a small window of preceding instructions for the pushed line number. Output:

  tools/ida_source_sites.csv   one row per assert site (func, file, line, ea)
  tools/ida_source_funcs.csv   one row per function (dominant file + line span)

Run inside IDA via the MCP py_exec_file tool.
"""
import idautils, ida_bytes, ida_funcs, ida_ua, idc, os, csv, re
from collections import defaultdict

OUT_DIR = r"%USERPROFILE%\Desktop\F1C_ghidra_project\tools"

# 1. collect source-path file strings
FILE_RE = re.compile(r'\.(cpp|cxx|c|hpp|h)$', re.I)
file_strings = {}  # ea -> filename (basename)
for s in idautils.Strings():
    b = ida_bytes.get_strlit_contents(s.ea, s.length, s.strtype) or b''
    txt = b.decode('latin1', 'replace')
    low = txt.lower()
    if ('.cpp' in low or '.cxx' in low) and ('\\dev\\' in low or 'source\\' in low or 'source/' in low):
        base = re.split(r'[\\/]', txt)[-1]
        file_strings[s.ea] = (base, txt)

print("source file strings:", len(file_strings))

def nearest_line(site_ea):
    """Scan up to 6 instructions backward from an insn that pushes the file
    pointer, looking for a `push imm` that looks like a line number."""
    ea = site_ea
    for _ in range(6):
        ea = idc.prev_head(ea)
        if ea == idc.BADADDR:
            break
        mnem = idc.print_insn_mnem(ea)
        if mnem == 'push':
            if idc.get_operand_type(ea, 0) == idc.o_imm:
                val = idc.get_operand_value(ea, 0)
                if 1 <= val <= 200000:
                    return val
        # stop if we cross a call (different site)
        if mnem == 'call':
            break
    return None

sites = []                       # (func_ea, func_name, file, line, site_ea)
func_files = defaultdict(lambda: defaultdict(list))  # func_ea -> file -> [lines]

for str_ea, (base, full) in file_strings.items():
    for xr in idautils.XrefsTo(str_ea):
        site = xr.frm
        f = ida_funcs.get_func(site)
        if not f:
            continue
        fea = f.start_ea
        name = idc.get_func_name(fea)
        line = nearest_line(site)
        sites.append((fea, name, base, line, site))
        func_files[fea][base].append(line)

print("assert sites:", len(sites), "functions touched:", len(func_files))

# per-function dominant file
func_rows = []
multi = 0
for fea, files in func_files.items():
    name = idc.get_func_name(fea)
    # dominant = file with most sites
    best = max(files.items(), key=lambda kv: len(kv[1]))
    dom_file, dom_lines = best
    lines = sorted(l for l in dom_lines if l is not None)
    lo = lines[0] if lines else ''
    hi = lines[-1] if lines else ''
    if len(files) > 1:
        multi += 1
    func_rows.append((("0x%08x" % fea), name, dom_file, len(files), lo, hi,
                      ";".join(sorted(files.keys()))))

os.makedirs(OUT_DIR, exist_ok=True)
with open(os.path.join(OUT_DIR, "ida_source_sites.csv"), "w", newline="") as fp:
    w = csv.writer(fp)
    w.writerow(["func_ea", "func_name", "file", "line", "site_ea"])
    for fea, name, base, line, site in sorted(sites):
        w.writerow(["0x%08x" % fea, name, base, line if line is not None else "", "0x%08x" % site])

with open(os.path.join(OUT_DIR, "ida_source_funcs.csv"), "w", newline="") as fp:
    w = csv.writer(fp)
    w.writerow(["func_ea", "func_name", "dominant_file", "n_distinct_files", "line_lo", "line_hi", "all_files"])
    for row in sorted(func_rows):
        w.writerow(row)

# per-file function counts summary
per_file = defaultdict(set)
for fea, files in func_files.items():
    for base in files:
        per_file[base].add(fea)
print("\n=== functions attributed per file ===")
for base in sorted(per_file, key=lambda b: -len(per_file[b])):
    print("%5d  %s" % (len(per_file[base]), base))
print("\nfunctions with multiple candidate files (ambiguous):", multi)
print("wrote ida_source_sites.csv and ida_source_funcs.csv")
