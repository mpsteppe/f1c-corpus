# WORKER T — F1C Triage Upgrade

You are writing full documentation entries for functions in the knowledge graph
that have NO `## FUN_` or `### FUN_` entry in any docs/ file.
Worker T of 20, items 61–63.

## STEP 1 — LOAD REFERENCES
1. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md` — named globals
2. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\13-struct-offsets.md` — struct offsets

## OUTPUT FILE
Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\triage_upgrade\worker_T.md

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

61. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046e590__FUN_0046e590.c
   [addr: 0x0046e590 | target: docs/20-math-utilities.md]
   summary: short computation
   callees: 0x00433eb0, 0x00487010, 0x00498d00
   callers: none

62. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f6ab0__FUN_004f6ab0.c
   [addr: 0x004f6ab0 | target: docs/20-math-utilities.md]
   summary: references game state
   callees: 0x00566650
   callers: none

63. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00582dc0__FUN_00582dc0.c
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
