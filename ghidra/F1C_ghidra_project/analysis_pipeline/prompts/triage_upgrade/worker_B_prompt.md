# WORKER B — F1C Triage Upgrade

You are writing full documentation entries for functions in the knowledge graph
that have NO `## FUN_` or `### FUN_` entry in any docs/ file.
Worker B of 8, items 9–16.

## STEP 1 — LOAD REFERENCES
1. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md` — named globals
2. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\13-struct-offsets.md` — struct offsets

## OUTPUT FILE
Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\triage_upgrade\worker_B.md

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

9. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00405b90__FUN_00405b90.c
   [addr: 0x00405b90 | target: docs/20-math-utilities.md]
   summary: Miles Sound System call
   callees: 0x00405f80, 0x00406020, 0x00406060, 0x00406100, 0x00587bdc
   callers: 0x00405900

10. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004493a0__FUN_004493a0.c
   [addr: 0x004493a0 | target: docs/20-math-utilities.md]
   summary: resizable container
   callees: 0x00448480, 0x00448510, 0x004485d0, 0x00448e50, 0x00448e90
   callers: 0x0044aae0, 0x0044b370

11. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045c0a0__FUN_0045c0a0.c
   [addr: 0x0045c0a0 | target: docs/20-math-utilities.md]
   summary: short computation
   callees: none
   callers: 0x0045d530

12. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a5fa0__FUN_004a5fa0.c
   [addr: 0x004a5fa0 | target: docs/20-math-utilities.md]
   summary: vehicle struct access
   callees: 0x00403f70, 0x0042adb0, 0x004a5c80, 0x004efb20, 0x00566e40
   callers: 0x004a6e50

13. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dd9f0__FUN_004dd9f0.c
   [addr: 0x004dd9f0 | target: docs/20-math-utilities.md]
   summary: unidentified logic
   callees: none
   callers: 0x004df110, 0x004de610, 0x0044acb0

14. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004fb2e0__FUN_004fb2e0.c
   [addr: 0x004fb2e0 | target: docs/20-math-utilities.md]
   summary: unidentified logic
   callees: none
   callers: 0x00404460, 0x00486080, 0x004047d0

15. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053d470__FUN_0053d470.c
   [addr: 0x0053d470 | target: docs/20-math-utilities.md]
   summary: arithmetic/comparison
   callees: 0x0053c2c0, 0x0053c360, 0x00587c03
   callers: 0x004fa000

16. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00567340__FUN_00567340.c
   [addr: 0x00567340 | target: docs/20-math-utilities.md]
   summary: --
   callees: 0x00588570
   callers: 0x004e24a0, 0x004e2540, 0x00409a00

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
