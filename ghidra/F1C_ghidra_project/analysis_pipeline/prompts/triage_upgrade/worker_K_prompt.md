# WORKER K — F1C Triage Upgrade

You are writing full documentation entries for functions in the knowledge graph
that have NO `## FUN_` or `### FUN_` entry in any docs/ file.
Worker K of 20, items 34–36.

## STEP 1 — LOAD REFERENCES
1. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md` — named globals
2. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\13-struct-offsets.md` — struct offsets

## OUTPUT FILE
Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\triage_upgrade\worker_K.md

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

## YOUR FUNCTIONS (3)

34. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044dbe0__FUN_0044dbe0.c
   [addr: 0x0044dbe0 | target: docs/20-math-utilities.md]
   summary: collision detection
   callees: none
   callers: none

35. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ca2d0__FUN_004ca2d0.c
   [addr: 0x004ca2d0 | target: docs/20-math-utilities.md]
   summary: unidentified logic
   callees: 0x0054c230
   callers: 0x004cfcc0

36. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054a340__FUN_0054a340.c
   [addr: 0x0054a340 | target: docs/20-math-utilities.md]
   summary: vehicle struct access
   callees: none
   callers: 0x00556e70

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
