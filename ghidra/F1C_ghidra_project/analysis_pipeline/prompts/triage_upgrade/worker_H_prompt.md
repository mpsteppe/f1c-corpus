# WORKER H — F1C Triage Upgrade

You are writing full documentation entries for functions in the knowledge graph
that have NO `## FUN_` or `### FUN_` entry in any docs/ file.
Worker H of 8, items 57–63.

## STEP 1 — LOAD REFERENCES
1. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md` — named globals
2. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\13-struct-offsets.md` — struct offsets

## OUTPUT FILE
Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\triage_upgrade\worker_H.md

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

## YOUR FUNCTIONS (7)

57. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00441650__FUN_00441650.c
   [addr: 0x00441650 | target: docs/20-math-utilities.md]
   summary: game state logic
   callees: 0x00438130, 0x00438690, 0x0043ef20, 0x00441360, 0x00441450
   callers: 0x004e4930

58. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00457b60__FUN_00457b60.c
   [addr: 0x00457b60 | target: docs/20-math-utilities.md]
   summary: float computation
   callees: 0x00415c30, 0x00456040, 0x00456060, 0x00456080, 0x004560a0
   callers: 0x0040b030

59. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00498030__FUN_00498030.c
   [addr: 0x00498030 | target: docs/20-math-utilities.md]
   summary: collision detection
   callees: none
   callers: 0x00486730, 0x00496930

60. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004cce90__FUN_004cce90.c
   [addr: 0x004cce90 | target: docs/20-math-utilities.md]
   summary: scoring/standings access
   callees: 0x0040c870, 0x0044c550, 0x004b9ce0, 0x004b9cf0, 0x004b9e30
   callers: 0x004e16f0, 0x004ee2d0

61. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f6ab0__FUN_004f6ab0.c
   [addr: 0x004f6ab0 | target: docs/20-math-utilities.md]
   summary: references game state
   callees: 0x00566650
   callers: none

62. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052ab4e__FUN_0052ab4e.c
   [addr: 0x0052ab4e | target: docs/20-math-utilities.md]
   summary: unidentified logic
   callees: none
   callers: 0x0052855a

63. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00565080__FUN_00565080.c
   [addr: 0x00565080 | target: docs/20-math-utilities.md]
   summary: --
   callees: 0x00564dd0
   callers: 0x00563410

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
