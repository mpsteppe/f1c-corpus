# WORKER F — F1C Stub Upgrade to Lightweight Entries

You are upgrading table-row-only function stubs to lightweight `### FUN_` entries.
Worker F of 10, items 41–48.

## STEP 1 — LOAD REFERENCES

Read these before starting:
1. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md` — known globals
2. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\13-struct-offsets.md` — known struct offsets

## YOUR OUTPUT FILE

Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\stub_upgrade\worker_F.md

Use this structure:
```
=== TRIAGE LINES ===

=== FULL ENTRIES ===
<!-- target: docs/01-engine-architecture.md -->
### FUN_00XXXXXX — Short Name
...
```

Leave `=== TRIAGE LINES ===` EMPTY.
Write `<!-- target: docs/XX-name.md -->` before EVERY `### FUN_` block.

## YOUR FILES (8)

41. %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x0042c170__FUN_0042c170.c
   [addr: 0x0042C170 | target: docs/01-engine-architecture.md]
42. %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004c8d00__FUN_004c8d00.c
   [addr: 0x004C8D00 | target: docs/01-engine-architecture.md]
43. %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x00455da0__FUN_00455da0.c
   [addr: 0x00455DA0 | target: docs/01-engine-architecture.md]
44. %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004b4060__FUN_004b4060.c
   [addr: 0x004B4060 | target: docs/01-engine-architecture.md]
45. %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004b1870__FUN_004b1870.c
   [addr: 0x004B1870 | target: docs/08-file-formats.md]
46. %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x00463160__FUN_00463160.c
   [addr: 0x00463160 | target: docs/09-track-system.md]
47. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00410f60__FUN_00410f60.c
   [addr: 0x00410F60 | target: docs/10-vehicle-physics.md]
48. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c2e20__FUN_004c2e20.c
   [addr: 0x004C2E20 | target: docs/10-vehicle-physics.md]

## ENTRY FORMAT

```
<!-- target: docs/XX-name.md -->
### FUN_00XXXXXX — Short Name

One-line summary.

**Key logic:**
- 2–4 bullets: main behavior, key constants, branches
- Name algorithms if recognizable

**Calls:** FUN_AAAAAA (what it does), FUN_BBBBBB (what it does)
```

Note: these are `###` (h3) entries, NOT `##` (h2). Lightweight format.

## GHIDRA PATTERNS
- `*(double *)(ptr + 0x1330)` → offset +0x1330, type double
- `param_1[0x4a]` → int-indexed: byte offset = 0x4a × 4
- `DAT_XXXXXXXX` → global — resolve name from docs/12

## RULES
0. NEVER move, rename, or delete any files.
1. Write a `### FUN_` entry for EVERY file in your list.
2. Write `<!-- target: docs/XX-name.md -->` before EVERY entry.
3. Use the target doc given in your file list.
4. Write to %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\stub_upgrade\worker_F.md after each entry.
5. ALWAYS use `### FUN_XXXXXXXX — Name` format. Address from filename.
6. If function is empty (bare return): write `### FUN_X — Empty Stub` with one bullet.
7. If function is a thunk: write `### FUN_X — Thunk to FUN_Y` with one bullet.
