# WORKER C — F1C Stub Upgrade to Lightweight Entries

You are upgrading table-row-only function stubs to lightweight `### FUN_` entries.
Worker C of 10, items 17–24.

## STEP 1 — LOAD REFERENCES

Read these before starting:
1. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md` — known globals
2. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\13-struct-offsets.md` — known struct offsets

## YOUR OUTPUT FILE

Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\stub_upgrade\worker_C.md

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

17. %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x0042d7a0__FUN_0042d7a0.c
   [addr: 0x0042D7A0 | target: docs/01-engine-architecture.md]
18. %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004c8ae0__FUN_004c8ae0.c
   [addr: 0x004C8AE0 | target: docs/01-engine-architecture.md]
19. %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x00455bf0__FUN_00455bf0.c
   [addr: 0x00455BF0 | target: docs/01-engine-architecture.md]
20. %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004fac00__FUN_004fac00.c
   [addr: 0x004FAC00 | target: docs/01-engine-architecture.md]
21. %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004a1930__FUN_004a1930.c
   [addr: 0x004A1930 | target: docs/01-engine-architecture.md]
22. %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004ca480__FUN_004ca480.c
   [addr: 0x004CA480 | target: docs/09-track-system.md]
23. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d6ae0__FUN_004d6ae0.c
   [addr: 0x004D6AE0 | target: docs/10-vehicle-physics.md]
24. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0043e770__FUN_0043e770.c
   [addr: 0x0043E770 | target: docs/10-vehicle-physics.md]

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
4. Write to %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\stub_upgrade\worker_C.md after each entry.
5. ALWAYS use `### FUN_XXXXXXXX — Name` format. Address from filename.
6. If function is empty (bare return): write `### FUN_X — Empty Stub` with one bullet.
7. If function is a thunk: write `### FUN_X — Thunk to FUN_Y` with one bullet.
