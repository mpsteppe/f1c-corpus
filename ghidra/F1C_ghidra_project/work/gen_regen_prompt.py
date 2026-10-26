"""Generate re-documentation prompt for functions that failed cross-validation."""
import re, os

CORRECTIONS = r'%USERPROFILE%\Desktop\F1C_ghidra_project\work\CORRECTIONS_phase1.md'
DOCS_DIR    = r'%USERPROFILE%\Desktop\F1C_ghidra_project\docs'
ANALYZED    = r'%USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed'
DECOMPILED  = r'%USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all'
PROMPTS_DIR = r'%USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\prompts\cross_validate'
OUTPUT_FILE = r'%USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\cross_validate\worker_REGEN.md'

content = open(CORRECTIONS, encoding='utf-8').read()
blocks = re.split(r'(?=<!-- worker:)', content)

regen_addrs = set()
addr_errors = {}
for block in blocks:
    if '**Corrected entry:**' in block:
        continue
    if 'FAIL' not in block:
        continue
    # skip dismissed false positives (NO_DOC_ENTRY)
    if 'NO_DOC_ENTRY' in block or 'MISSING_ENTRY' in block:
        continue
    addr_m = re.search(r'FUN_([0-9A-Fa-f]{8})', block)
    if not addr_m:
        continue
    addr = addr_m.group(1).lower()
    errs_m = re.search(r'\*\*Errors?:\*\*\s*(.+?)(?=\n\n|\Z)', block, re.DOTALL)
    if errs_m:
        regen_addrs.add(addr)
        addr_errors[addr] = errs_m.group(1).strip()[:200]

# 5 cross-file refs — workers logged errors but wrote no corrected blocks
for addr in ['0056a390', '004ee2d0', '0059b490', '004c13c0', '00548e20']:
    regen_addrs.add(addr)

# Build addr -> c_path index
addr_to_c = {}
for d in [ANALYZED, DECOMPILED]:
    if not os.path.isdir(d):
        continue
    for f in os.listdir(d):
        if not f.endswith('.c'):
            continue
        m = re.match(r'0x([0-9A-Fa-f]{8})__', f)
        if m:
            addr_to_c[m.group(1).lower()] = os.path.join(d, f)

# Find target doc for each addr
addr_to_doc = {}
for fname in os.listdir(DOCS_DIR):
    if not fname.endswith('.md'):
        continue
    c = open(os.path.join(DOCS_DIR, fname), encoding='utf-8', errors='ignore').read()
    for m in re.finditer(r'^## FUN_([0-9A-Fa-f]{8})', c, re.M):
        addr_to_doc[m.group(1).lower()] = fname

items = []
for addr in sorted(regen_addrs):
    c_path = addr_to_c.get(addr)
    doc = addr_to_doc.get(addr, 'unknown')
    err = addr_errors.get(addr, 'see cross-validate output')
    items.append((addr, c_path, doc, err))

no_source = [(a, d, e) for a, c, d, e in items if not c]
with_source = [(a, c, d, e) for a, c, d, e in items if c]

print(f"Total regen needed: {len(items)}")
print(f"With .c source:     {len(with_source)}")
print(f"No .c source (skip):{len(no_source)}")
for a, d, e in no_source:
    print(f"  {a} in {d} -- {e[:80]}")

file_list_lines = []
for i, (addr, c_path, doc, err) in enumerate(with_source):
    file_list_lines.append(
        f"{i+1}. FUN_{addr.upper()}\n"
        f"   source: {c_path}\n"
        f"   target doc: docs/{doc}\n"
        f"   known errors: {err[:120]}"
    )
file_list = '\n'.join(file_list_lines)

os.makedirs(PROMPTS_DIR, exist_ok=True)
os.makedirs(os.path.dirname(OUTPUT_FILE), exist_ok=True)

prompt = f"""# WORKER REGEN — F1C Re-documentation ({len(with_source)} functions)

You are re-writing documentation for {len(with_source)} functions whose existing entries
were found to have errors during cross-validation. Read each source .c file and
write a complete, accurate replacement entry.

## STEP 1 — LOAD REFERENCES

Before processing any functions, read these files:
1. %USERPROFILE%\\Desktop\\F1C_ghidra_project\\docs\\12-globals-reference.md
2. %USERPROFILE%\\Desktop\\F1C_ghidra_project\\docs\\13-struct-offsets.md

## YOUR OUTPUT FILE

Write ALL output to:
{OUTPUT_FILE}

Format:
```
=== TRIAGE LINES ===

=== FULL ENTRIES ===
<!-- target: docs/XX-name.md -->
## FUN_00XXXXXX — Name
...
```

Leave TRIAGE LINES section empty. Write each <!-- target: --> comment before its entry.
Write to the output file after every 5 functions to avoid data loss.

## FUNCTIONS TO RE-DOCUMENT ({len(with_source)})

{file_list}

## ENTRY FORMAT

```
<!-- target: docs/XX-name.md -->
## FUN_00XXXXXX — Descriptive Name

Source: filename.cpp | Confidence: high/medium/low
One-line summary.

**Key logic:**
- Step-by-step behavior, exact constants, all branches
- Name algorithms (dot product, lerp, clamp, PID, etc.)

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|

**Globals:**
- `DAT_XXXXXXXX` (KnownName if in docs/12) — read / written

**Calls:** FUN_AAAAAA (purpose), FUN_BBBBBB (purpose)

**Moddability:** configurable | hardcoded | hookable
```

## GHIDRA PATTERNS
- `*(double *)(ptr + 0x1330)` = struct field at offset +0x1330, type double
- `param_1[0x4a]` = byte offset 0x4a * 4 = 0x128
- `unaff_EBX/ESI/EBP` = register-allocated `this` pointer
- `DAT_XXXXXXXX` = global — resolve from docs/12 if possible

## RULES
1. NEVER skip a function. Write an entry for all {len(with_source)} functions.
2. Read the .c source carefully — accuracy is critical, prior entries had errors.
3. The "known errors" field tells you what was wrong — fix those specifically.
4. Write `<!-- target: docs/XX-name.md -->` before EVERY entry using the doc given.
5. For each function: read .c file, write entry, append to output file.
6. DO NOT modify any existing files. Only write to the output file above.
"""

prompt_path = os.path.join(PROMPTS_DIR, 'worker_REGEN_prompt.md')
open(prompt_path, 'w', encoding='utf-8').write(prompt)
print(f"\nPrompt written: {prompt_path}")
print(f"Items in prompt: {len(with_source)}")
