# WORKER A — F1C Triage Upgrade

You are writing full documentation entries for functions in the knowledge graph
that have NO `## FUN_` or `### FUN_` entry in any docs/ file.
Worker A of 8, items 1–8.

## STEP 1 — LOAD REFERENCES
1. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md` — named globals
2. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\13-struct-offsets.md` — struct offsets

## OUTPUT FILE
Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\triage_upgrade\worker_A.md

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

1. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00401910__FUN_00401910.c
   [addr: 0x00401910 | target: docs/20-math-utilities.md]
   summary: collision detection
   callees: 0x00401340, 0x004e8ce0
   callers: 0x00401c90

2. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00447160__FUN_00447160.c
   [addr: 0x00447160 | target: docs/20-math-utilities.md]
   summary: physics computation
   callees: none
   callers: 0x00443c07, 0x0042c440, 0x00443b70, 0x00443f71

3. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00457d00__FUN_00457d00.c
   [addr: 0x00457d00 | target: docs/20-math-utilities.md]
   summary: collision detection
   callees: none
   callers: 0x004582c0

4. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049e5b0__FUN_0049e5b0.c
   [addr: 0x0049e5b0 | target: docs/20-math-utilities.md]
   summary: collision detection
   callees: 0x00587bdc
   callers: 0x0049e670, 0x0049e570

5. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d68a0__FUN_004d68a0.c
   [addr: 0x004d68a0 | target: docs/20-math-utilities.md]
   summary: unidentified logic
   callees: none
   callers: 0x004d7150

6. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f8440__FUN_004f8440.c
   [addr: 0x004f8440 | target: docs/20-math-utilities.md]
   summary: vehicle struct access
   callees: 0x004c7bd0, 0x004f6d90, 0x004f8850
   callers: 0x004c8b70

7. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053c1b0__FUN_0053c1b0.c
   [addr: 0x0053c1b0 | target: docs/20-math-utilities.md]
   summary: short computation
   callees: 0x00587b3e
   callers: none

8. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005653f0__thunk_FUN_00565400.c
   [addr: 0x005653f0 | target: docs/20-math-utilities.md]
   summary: --
   callees: none
   callers: 0x00565520

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
