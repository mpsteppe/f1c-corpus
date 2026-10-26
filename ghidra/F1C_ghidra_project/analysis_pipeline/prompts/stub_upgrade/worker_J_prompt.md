# WORKER J — F1C Stub Upgrade to Lightweight Entries

You are upgrading table-row-only function stubs to lightweight `### FUN_` entries.
Worker J of 10, items 73–79.

## STEP 1 — LOAD REFERENCES

Read these before starting:
1. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md` — known globals
2. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\13-struct-offsets.md` — known struct offsets

## YOUR OUTPUT FILE

Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\stub_upgrade\worker_J.md

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

## YOUR FILES (7)

73. %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x0042ca70__FUN_0042ca70.c
   [addr: 0x0042CA70 | target: docs/01-engine-architecture.md]
74. %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x0049f000__FUN_0049f000.c
   [addr: 0x0049F000 | target: docs/01-engine-architecture.md]
75. %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004fa2f0__FUN_004fa2f0.c
   [addr: 0x004FA2F0 | target: docs/01-engine-architecture.md]
76. %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x0040c9e0__FUN_0040c9e0.c
   [addr: 0x0040C9E0 | target: docs/01-engine-architecture.md]
77. %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004accfa__FUN_004accfa.c
   [addr: 0x004ACCFA | target: docs/09-track-system.md]
78. %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004cfc90__FUN_004cfc90.c
   [addr: 0x004CFC90 | target: docs/09-track-system.md]
79. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c6810__FUN_004c6810.c
   [addr: 0x004C6810 | target: docs/10-vehicle-physics.md]

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
4. Write to %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\stub_upgrade\worker_J.md after each entry.
5. ALWAYS use `### FUN_XXXXXXXX — Name` format. Address from filename.
6. If function is empty (bare return): write `### FUN_X — Empty Stub` with one bullet.
7. If function is a thunk: write `### FUN_X — Thunk to FUN_Y` with one bullet.
