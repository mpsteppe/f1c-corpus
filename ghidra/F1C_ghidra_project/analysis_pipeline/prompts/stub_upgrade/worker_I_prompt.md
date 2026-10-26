# WORKER I — F1C Stub Upgrade to Lightweight Entries

You are upgrading table-row-only function stubs to lightweight `### FUN_` entries.
Worker I of 10, items 65–72.

## STEP 1 — LOAD REFERENCES

Read these before starting:
1. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md` — known globals
2. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\13-struct-offsets.md` — known struct offsets

## YOUR OUTPUT FILE

Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\stub_upgrade\worker_I.md

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

65. %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x0042c9f0__FUN_0042c9f0.c
   [addr: 0x0042C9F0 | target: docs/01-engine-architecture.md]
66. %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x0049efa0__FUN_0049efa0.c
   [addr: 0x0049EFA0 | target: docs/01-engine-architecture.md]
67. %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004fa000__FUN_004fa000.c
   [addr: 0x004FA000 | target: docs/01-engine-architecture.md]
68. %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x0040c920__FUN_0040c920.c
   [addr: 0x0040C920 | target: docs/01-engine-architecture.md]
69. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c6980__FUN_004c6980.c
   [addr: 0x004C6980 | target: docs/08-file-formats.md]
70. %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004cf070__FUN_004cf070.c
   [addr: 0x004CF070 | target: docs/09-track-system.md]
71. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004af220__FUN_004af220.c
   [addr: 0x004AF220 | target: docs/10-vehicle-physics.md]
72. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054f5c0__FUN_0054f5c0.c
   [addr: 0x0054F5C0 | target: docs/10-vehicle-physics.md]

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
4. Write to %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\stub_upgrade\worker_I.md after each entry.
5. ALWAYS use `### FUN_XXXXXXXX — Name` format. Address from filename.
6. If function is empty (bare return): write `### FUN_X — Empty Stub` with one bullet.
7. If function is a thunk: write `### FUN_X — Thunk to FUN_Y` with one bullet.
