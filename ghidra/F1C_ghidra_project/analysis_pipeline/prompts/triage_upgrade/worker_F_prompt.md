# WORKER F — F1C Triage Upgrade

You are writing full documentation entries for functions in the knowledge graph
that have NO `## FUN_` or `### FUN_` entry in any docs/ file.
Worker F of 8, items 41–48.

## STEP 1 — LOAD REFERENCES
1. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md` — named globals
2. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\13-struct-offsets.md` — struct offsets

## OUTPUT FILE
Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\triage_upgrade\worker_F.md

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

41. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00433370__FUN_00433370.c
   [addr: 0x00433370 | target: docs/20-math-utilities.md]
   summary: physics computation
   callees: 0x00433290
   callers: none

42. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e960__FUN_0044e960.c
   [addr: 0x0044e960 | target: docs/20-math-utilities.md]
   summary: collision detection
   callees: none
   callers: none

43. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004950e0__FUN_004950e0.c
   [addr: 0x004950e0 | target: docs/20-math-utilities.md]
   summary: short computation
   callees: 0x004f9f00, 0x004f9f30, 0x00553700
   callers: 0x00497100

44. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c2f20__FUN_004c2f20.c
   [addr: 0x004c2f20 | target: docs/20-math-utilities.md]
   summary: unidentified logic
   callees: 0x00587bcf
   callers: 0x004bfa00

45. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e88b0__FUN_004e88b0.c
   [addr: 0x004e88b0 | target: docs/20-math-utilities.md]
   summary: vehicle struct access
   callees: none
   callers: 0x00426cf0, 0x00425920

46. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00519361__FUN_00519361.c
   [addr: 0x00519361 | target: docs/20-math-utilities.md]
   summary: short computation
   callees: none
   callers: 0x0051629f

47. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005527c0__FUN_005527c0.c
   [addr: 0x005527c0 | target: docs/20-math-utilities.md]
   summary: --
   callees: 0x00540df0, 0x00540f00, 0x00540f90, 0x00587c03
   callers: 0x0053eb70, 0x00552470

48. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058a8a3__FUN_0058a8a3.c
   [addr: 0x0058a8a3 | target: docs/20-math-utilities.md]
   summary: Float NaN/inf classification — decode exponent bits, return type code
   callees: 0x00591d2e
   callers: 0x0058df5c

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
