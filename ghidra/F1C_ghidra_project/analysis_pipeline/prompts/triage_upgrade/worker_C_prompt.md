# WORKER C — F1C Triage Upgrade

You are writing full documentation entries for functions in the knowledge graph
that have NO `## FUN_` or `### FUN_` entry in any docs/ file.
Worker C of 8, items 17–24.

## STEP 1 — LOAD REFERENCES
1. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md` — named globals
2. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\13-struct-offsets.md` — struct offsets

## OUTPUT FILE
Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\triage_upgrade\worker_C.md

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

17. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040c870__FUN_0040c870.c
   [addr: 0x0040c870 | target: docs/20-math-utilities.md]
   summary: short computation
   callees: none
   callers: 0x004cdb20, 0x0040ca30, 0x00434820, 0x004cc840, 0x004b3dc0

18. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044dbe0__FUN_0044dbe0.c
   [addr: 0x0044dbe0 | target: docs/20-math-utilities.md]
   summary: collision detection
   callees: none
   callers: none

19. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004651c0__FUN_004651c0.c
   [addr: 0x004651c0 | target: docs/20-math-utilities.md]
   summary: collision detection
   callees: 0x00464ef0, 0x00568cf0, 0x00587bcf
   callers: 0x0045f710

20. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004adf10__FUN_004adf10.c
   [addr: 0x004adf10 | target: docs/20-math-utilities.md]
   summary: vehicle struct access
   callees: 0x004646c0, 0x0047f1f0, 0x004b1de0, 0x004b20d0
   callers: 0x004732d0, 0x004ade20

21. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dfca0__FUN_004dfca0.c
   [addr: 0x004dfca0 | target: docs/20-math-utilities.md]
   summary: arithmetic/comparison
   callees: 0x004ded20, 0x00587bcf
   callers: 0x004e4570

22. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00502bea__FUN_00502bea.c
   [addr: 0x00502bea | target: docs/20-math-utilities.md]
   summary: short computation
   callees: none
   callers: 0x0050070d, 0x005007ef

23. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054a340__FUN_0054a340.c
   [addr: 0x0054a340 | target: docs/20-math-utilities.md]
   summary: vehicle struct access
   callees: none
   callers: 0x00556e70

24. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0056bd40__FUN_0056bd40.c
   [addr: 0x0056bd40 | target: docs/20-math-utilities.md]
   summary: --
   callees: none
   callers: 0x0043e4b0, 0x005691d0, 0x00435410, 0x004389b0, 0x00439210

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
