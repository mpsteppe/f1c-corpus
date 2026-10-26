# WORKER A — F1C Stub Upgrade to Lightweight Entries

You are upgrading table-row-only function stubs to lightweight `### FUN_` entries.
Worker A of 10, items 1–8.

## STEP 1 — LOAD REFERENCES

Read these before starting:
1. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md` — known globals
2. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\13-struct-offsets.md` — known struct offsets

## YOUR OUTPUT FILE

Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\stub_upgrade\worker_A.md

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

1. %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x0042d5d0__FUN_0042d5d0.c
   [addr: 0x0042D5D0 | target: docs/01-engine-architecture.md]
2. %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004c8a20__FUN_004c8a20.c
   [addr: 0x004C8A20 | target: docs/01-engine-architecture.md]
3. %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x0049f0d0__FUN_0049f0d0.c
   [addr: 0x0049F0D0 | target: docs/01-engine-architecture.md]
4. %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004fa320__FUN_004fa320.c
   [addr: 0x004FA320 | target: docs/01-engine-architecture.md]
5. %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x0040cce0__FUN_0040cce0.c
   [addr: 0x0040CCE0 | target: docs/01-engine-architecture.md]
6. %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004d4a80__FUN_004d4a80.c
   [addr: 0x004D4A80 | target: docs/09-track-system.md]
7. %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004cfed0__FUN_004cfed0.c
   [addr: 0x004CFED0 | target: docs/09-track-system.md]
8. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005692a0__FUN_005692a0.c
   [addr: 0x005692A0 | target: docs/10-vehicle-physics.md]

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
4. Write to %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\stub_upgrade\worker_A.md after each entry.
5. ALWAYS use `### FUN_XXXXXXXX — Name` format. Address from filename.
6. If function is empty (bare return): write `### FUN_X — Empty Stub` with one bullet.
7. If function is a thunk: write `### FUN_X — Thunk to FUN_Y` with one bullet.
