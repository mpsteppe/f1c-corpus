# WORKER D — F1C Triage Upgrade

You are writing full documentation entries for functions in the knowledge graph
that have NO `## FUN_` or `### FUN_` entry in any docs/ file.
Worker D of 8, items 25–32.

## STEP 1 — LOAD REFERENCES
1. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md` — named globals
2. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\13-struct-offsets.md` — struct offsets

## OUTPUT FILE
Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\triage_upgrade\worker_D.md

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

25. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00414900__FUN_00414900.c
   [addr: 0x00414900 | target: docs/20-math-utilities.md]
   summary: short computation
   callees: 0x00566650, 0x0058ba36, 0x00587dd0
   callers: 0x00414e60, 0x00414600, 0x00414a90

26. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044dfa0__FUN_0044dfa0.c
   [addr: 0x0044dfa0 | target: docs/20-math-utilities.md]
   summary: collision detection
   callees: none
   callers: none

27. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046e590__FUN_0046e590.c
   [addr: 0x0046e590 | target: docs/20-math-utilities.md]
   summary: short computation
   callees: 0x00433eb0, 0x00487010, 0x00498d00
   callers: none

28. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004baa50__FUN_004baa50.c
   [addr: 0x004baa50 | target: docs/20-math-utilities.md]
   summary: memory allocation
   callees: 0x004b4f50, 0x00587c03
   callers: 0x004b5c50

29. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e19d0__FUN_004e19d0.c
   [addr: 0x004e19d0 | target: docs/20-math-utilities.md]
   summary: vehicle state + game state access
   callees: 0x0040c870, 0x004b9ce0, 0x004e21d0, 0x004e3090, 0x0054b450
   callers: 0x004f0430

30. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051427f__FUN_0051427f.c
   [addr: 0x0051427f | target: docs/20-math-utilities.md]
   summary: unidentified logic
   callees: 0x00513e5d
   callers: 0x005147ea

31. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054f2f0__FUN_0054f2f0.c
   [addr: 0x0054f2f0 | target: docs/20-math-utilities.md]
   summary: vehicle struct access
   callees: 0x0054eb40, 0x00559a30
   callers: 0x0054f5c0

32. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00582dc0__FUN_00582dc0.c
   [addr: 0x00582dc0 | target: docs/20-math-utilities.md]
   summary: --
   callees: 0x0047aa60, 0x00587bcf, 0x0058a5f7
   callers: 0x0057bce0

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
