"""
extract_param_offsets.py — Map vehicle parameter names to struct offsets

Scans decompiled .c files for ISIMotor2 key-value parser calls:
  FUN_00565aa0(s_PARAMNAME_ADDR, param_1 + 0xOFFSET, ...)   <- read: file -> struct
  FUN_00566c30(out, s_PARAMNAME_ADDR, *(param_1 + 0xOFFSET)) <- write: struct -> file
  FUN_0042e1f0(x, s_RANGE, s_SETTING, ...)                   <- range+setting pair

Outputs: param_offset_map.md — definitive parameter name -> struct offset table

Usage: python tools/extract_param_offsets.py
"""

import re
import os
from pathlib import Path
from collections import defaultdict

DECOMPILED_DIRS = [
    'decompiled_all',
    'Isolated Workspace/analyzed',
]

# Parser function signatures seen in decompiled output
# Pattern A: FUN_00565aa0(s_NAME_ADDR, param_1 + 0xOFFSET, ...)
RE_READ = re.compile(
    r'FUN_00565aa0\s*\('
    r'\s*s_([A-Za-z0-9_]+?)_[0-9a-fA-F]{6,8}'  # string name
    r'\s*,\s*param_1\s*\+\s*(0x[0-9a-fA-F]+)'   # offset
    r'[,)]'
)

# Pattern B: FUN_00566c30(x, s_NAME_ADDR, *(param_1 + 0xOFFSET))
RE_WRITE = re.compile(
    r'FUN_00566c30\s*\([^,]+,\s*'
    r's_([A-Za-z0-9_]+?)_[0-9a-fA-F]{6,8}'
    r'[^,]*,\s*\*\([^)]+\)\s*\(\s*param_1\s*\+\s*(0x[0-9a-fA-F]+)\s*\)'
)

# Pattern B2: FUN_00566c30(x, s_NAME_ADDR, value_from_param_1_offset) — looser
RE_WRITE2 = re.compile(
    r'FUN_00566c30\s*\([^,]*,\s*'
    r's_([A-Za-z0-9_]+?)_[0-9a-fA-F]{6,8}'
    r'[^,]*,\s*\*\(undefined4 \*\)\(param_1\s*\+\s*(0x[0-9a-fA-F]+)\)'
)

# Pattern C: FUN_0042e1f0(x, s_RANGE, s_SETTING_ADDR, ...) — setting name second
RE_SETTING = re.compile(
    r'FUN_0042e1f0\s*\([^,]+,\s*'
    r's_[A-Za-z0-9_]+?_[0-9a-fA-F]{6,8}'       # range string (skip)
    r'\s*,\s*s_([A-Za-z0-9_]+?)_[0-9a-fA-F]{6,8}'  # setting string name
)

# Pattern D: any call with s_NAME and param_1 + offset on the same line
RE_GENERIC = re.compile(
    r's_([A-Za-z0-9_]+?)_[0-9a-fA-F]{6,8}'
    r'.*?param_1\s*\+\s*(0x[0-9a-fA-F]+)'
)
RE_GENERIC2 = re.compile(
    r'param_1\s*\+\s*(0x[0-9a-fA-F]+)'
    r'.*?s_([A-Za-z0-9_]+?)_[0-9a-fA-F]{6,8}'
)

# ── collect results ──────────────────────────────────────────────────────────────

# param_name -> {offset -> [source_files]}
results = defaultdict(lambda: defaultdict(list))

def clean_name(raw):
    # strip trailing format specifiers Ghidra appends
    raw = re.sub(r'__[dfis]$', '', raw)
    raw = re.sub(r'_[dfis]$', '', raw)
    return raw

def process_file(path):
    try:
        text = path.read_text(encoding='utf-8', errors='replace')
    except Exception:
        return

    fname = path.name

    for line in text.splitlines():
        for pat, swap in [(RE_READ, False), (RE_WRITE, False),
                          (RE_WRITE2, False)]:
            for m in pat.finditer(line):
                name   = clean_name(m.group(1))
                offset = int(m.group(2), 16)
                results[name][offset].append(fname)

        for m in RE_GENERIC.finditer(line):
            name   = clean_name(m.group(1))
            offset = int(m.group(2), 16)
            results[name][offset].append(fname)

        for m in RE_GENERIC2.finditer(line):
            offset = int(m.group(1), 16)
            name   = clean_name(m.group(2))
            results[name][offset].append(fname)

# ── scan all files ───────────────────────────────────────────────────────────────

c_files = []
for d in DECOMPILED_DIRS:
    if os.path.isdir(d):
        c_files.extend(Path(d).glob('*.c'))

print(f"Scanning {len(c_files)} files ...")
for i, cf in enumerate(c_files):
    process_file(cf)
    if (i+1) % 1000 == 0:
        print(f"  {i+1}/{len(c_files)} ...")

print(f"Found {len(results)} unique parameter names.")

# ── write report ─────────────────────────────────────────────────────────────────

# Physics-relevant keywords for priority sorting
PHYSICS_KEYS = {
    'brake', 'tire', 'tyre', 'spring', 'damper', 'fuel', 'camber', 'toe',
    'ride', 'wing', 'aero', 'gear', 'clutch', 'engine', 'diff', 'suspension',
    'wear', 'temp', 'grip', 'slip', 'load', 'mass', 'inertia', 'torque',
    'downforce', 'drag', 'steer', 'bump', 'rebound', 'preload', 'pressure',
    'cooling', 'heating', 'compound', 'rpm', 'power', 'weight', 'cg', 'wheel'
}

def is_physics(name):
    n = name.lower()
    return any(k in n for k in PHYSICS_KEYS)

out_path = 'monitor_output/param_offset_map.md'
with open(out_path, 'w', encoding='utf-8') as f:
    def w(line=''):
        f.write(line + '\n')

    w('# Parameter Name → Struct Offset Map')
    w(f'Extracted from {len(c_files)} decompiled files.')
    w(f'Total unique parameters found: {len(results)}')
    w()

    # split physics vs other
    physics = {n: v for n, v in results.items() if is_physics(n)}
    other   = {n: v for n, v in results.items() if not is_physics(n)}

    w(f'## Vehicle Physics Parameters ({len(physics)})')
    w()
    w('| Parameter | Offset(s) | Source file(s) |')
    w('|-----------|-----------|----------------|')
    for name in sorted(physics.keys()):
        offsets = physics[name]
        # pick most common offset if multiple
        best = sorted(offsets.items(), key=lambda x: -len(x[1]))
        offset_str = ', '.join(f'`+{hex(o)}`' for o, _ in best[:3])
        files = set()
        for _, flist in best[:3]:
            files.update(flist[:2])
        file_str = ', '.join(sorted(files)[:3])
        w(f'| `{name}` | {offset_str} | {file_str} |')

    w()
    w(f'## Other Parameters ({len(other)})')
    w()
    w('| Parameter | Offset(s) | Source file(s) |')
    w('|-----------|-----------|----------------|')
    for name in sorted(other.keys()):
        offsets = other[name]
        best = sorted(offsets.items(), key=lambda x: -len(x[1]))
        offset_str = ', '.join(f'`+{hex(o)}`' for o, _ in best[:3])
        files = set()
        for _, flist in best[:3]:
            files.update(flist[:2])
        file_str = ', '.join(sorted(files)[:3])
        w(f'| `{name}` | {offset_str} | {file_str} |')

print(f'Written: {out_path}')
