# WORKER G — F1C Triage Upgrade

You are writing full documentation entries for functions in the knowledge graph
that have NO `## FUN_` or `### FUN_` entry in any docs/ file.
Worker G of 8, items 49–56.

## STEP 1 — LOAD REFERENCES
1. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md` — named globals
2. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\13-struct-offsets.md` — struct offsets

## OUTPUT FILE
Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\triage_upgrade\worker_G.md

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

49. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00435e60__FUN_00435e60.c
   [addr: 0x00435e60 | target: docs/20-math-utilities.md]
   summary: physics computation
   callees: 0x004361d0, 0x0056c740, 0x00588570
   callers: 0x00447100

50. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00456170__FUN_00456170.c
   [addr: 0x00456170 | target: docs/20-math-utilities.md]
   summary: unidentified
   callees: 0x00456280, 0x00566650
   callers: 0x00408e20, 0x00408870, 0x0040aa20

51. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00497c40__FUN_00497c40.c
   [addr: 0x00497c40 | target: docs/20-math-utilities.md]
   summary: unidentified
   callees: 0x00494fd0, 0x00542e50, 0x00557470, 0x00587bcf, 0x00588410
   callers: 0x004692b0, 0x0046cd20

52. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ca2d0__FUN_004ca2d0.c
   [addr: 0x004ca2d0 | target: docs/20-math-utilities.md]
   summary: unidentified logic
   callees: 0x0054c230
   callers: 0x004cfcc0

53. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e9a40__FUN_004e9a40.c
   [addr: 0x004e9a40 | target: docs/20-math-utilities.md]
   summary: vehicle struct access
   callees: 0x0054fa00
   callers: 0x004e9ca0, 0x0040f380, 0x004eb430

54. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051a87e__FUN_0051a87e.c
   [addr: 0x0051a87e | target: docs/20-math-utilities.md]
   summary: unidentified logic
   callees: 0x0051a794
   callers: 0x0051af57, 0x005107fb, 0x0051b154, 0x0051a9c6, 0x0051b45f

55. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00564220__FUN_00564220.c
   [addr: 0x00564220 | target: docs/20-math-utilities.md]
   summary: String tokenizer (strtok-like) using DAT_008cfae4 state
   callees: none
   callers: 0x00564390, 0x00564110

56. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059491a__FUN_0059491a.c
   [addr: 0x0059491a | target: docs/20-math-utilities.md]
   summary: --
   callees: 0x0058bb10
   callers: 0x0059325d, 0x00594c12

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
