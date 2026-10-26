# WORKER H — F1C Stub Upgrade to Lightweight Entries

You are upgrading table-row-only function stubs to lightweight `### FUN_` entries.
Worker H of 10, items 57–64.

## STEP 1 — LOAD REFERENCES

Read these before starting:
1. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md` — known globals
2. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\13-struct-offsets.md` — known struct offsets

## YOUR OUTPUT FILE

Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\stub_upgrade\worker_H.md

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

57. %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x0042c3b0__FUN_0042c3b0.c
   [addr: 0x0042C3B0 | target: docs/01-engine-architecture.md]
58. %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x0049ef70__FUN_0049ef70.c
   [addr: 0x0049EF70 | target: docs/01-engine-architecture.md]
59. %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x00455f00__FUN_00455f00.c
   [addr: 0x00455F00 | target: docs/01-engine-architecture.md]
60. %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004b4170__FUN_004b4170.c
   [addr: 0x004B4170 | target: docs/01-engine-architecture.md]
61. %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004b1900__FUN_004b1900.c
   [addr: 0x004B1900 | target: docs/08-file-formats.md]
62. %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004ceec0__FUN_004ceec0.c
   [addr: 0x004CEEC0 | target: docs/09-track-system.md]
63. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a2840__FUN_004a2840.c
   [addr: 0x004A2840 | target: docs/10-vehicle-physics.md]
64. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004414d0__FUN_004414d0.c
   [addr: 0x004414D0 | target: docs/10-vehicle-physics.md]

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
4. Write to %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\stub_upgrade\worker_H.md after each entry.
5. ALWAYS use `### FUN_XXXXXXXX — Name` format. Address from filename.
6. If function is empty (bare return): write `### FUN_X — Empty Stub` with one bullet.
7. If function is a thunk: write `### FUN_X — Thunk to FUN_Y` with one bullet.
