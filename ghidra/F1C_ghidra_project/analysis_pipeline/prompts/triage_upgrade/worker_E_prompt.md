# WORKER E — F1C Triage Upgrade

You are writing full documentation entries for functions in the knowledge graph
that have NO `## FUN_` or `### FUN_` entry in any docs/ file.
Worker E of 8, items 33–40.

## STEP 1 — LOAD REFERENCES
1. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md` — named globals
2. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\13-struct-offsets.md` — struct offsets

## OUTPUT FILE
Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\triage_upgrade\worker_E.md

Structure:
```
=== TRIAGE LINES ===

=== FULL ENTRIES ===
<!-- target: docs/XX-name.md -->
## FUN_00XXXXXX — Name
...
```

Leave `=== TRIAGE LINES ===` EMPTY.
Write `<!-- target: docs/XX-name.md -->` before EVERY `## FUN_` block.
Write to disk after EVERY entry.

## YOUR FUNCTIONS (8)

33. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00421570__FUN_00421570.c
   [addr: 0x00421570 | target: docs/20-math-utilities.md]
   summary: memory allocation
   callees: 0x00414370, 0x00587bcf
   callers: none

34. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e360__FUN_0044e360.c
   [addr: 0x0044e360 | target: docs/20-math-utilities.md]
   summary: collision detection
   callees: none
   callers: none

35. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047f080__FUN_0047f080.c
   [addr: 0x0047f080 | target: docs/20-math-utilities.md]
   summary: short computation
   callees: 0x00488b00
   callers: none

36. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bea10__FUN_004bea10.c
   [addr: 0x004bea10 | target: docs/20-math-utilities.md]
   summary: unidentified logic
   callees: 0x005881f0, 0x005884ed
   callers: 0x004beb10, 0x004bf0a0, 0x004bec55

37. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e2a00__FUN_004e2a00.c
   [addr: 0x004e2a00 | target: docs/20-math-utilities.md]
   summary: arithmetic/comparison
   callees: 0x0054c210, 0x0054c230
   callers: 0x004e2ca0

38. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00514fee__FUN_00514fee.c
   [addr: 0x00514fee | target: docs/20-math-utilities.md]
   summary: unidentified logic
   callees: 0x00513d63
   callers: 0x0051512c, 0x0050afe2, 0x005151af

39. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00551cf0__FUN_00551cf0.c
   [addr: 0x00551cf0 | target: docs/20-math-utilities.md]
   summary: --
   callees: 0x00543210, 0x00543230
   callers: 0x0048e4b0, 0x004f9b70, 0x0048e250

40. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00589c49__FUN_00589c49.c
   [addr: 0x00589c49 | target: docs/20-math-utilities.md]
   summary: --
   callees: 0x0058c674
   callers: 0x0048b560

## ENTRY FORMAT

```
<!-- target: docs/XX-name.md -->
## FUN_00XXXXXX — Descriptive Name

Source: likely_source.cpp | Confidence: high/medium/low
One-line summary.

**Key logic:**
- Step by step, with exact constants and thresholds
- All branches and what triggers each

**Struct offsets (if accessed):**
| Offset | Field name (from docs/13) | Type | Notes |

**Globals:** (if game logic)
- `DAT_XXXXXXXX` (KnownName) — read/written

**Calls:**
- FUN_XXXXXXXX — purpose

**Used by system:** docs/XX-name.md

**Moddability:** configurable | hardcoded | hookable
```

## RULES
0. NEVER move, rename, or delete any files.
1. Full `## FUN_` entry for EVERY function — no skipping.
2. `<!-- target: docs/XX-name.md -->` before EVERY entry.
3. Use target doc from your file list.
4. Resolve DAT_ to known names from docs/12.
5. Resolve offsets to field names from docs/13.
6. ALWAYS `## FUN_XXXXXXXX — Name` format. Never `## Unwind_...` etc.
