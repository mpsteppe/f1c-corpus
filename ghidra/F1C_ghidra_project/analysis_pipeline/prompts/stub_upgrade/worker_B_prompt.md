# WORKER B — F1C Stub Upgrade to Lightweight Entries

You are upgrading table-row-only function stubs to lightweight `### FUN_` entries.
Worker B of 10, items 9–16.

## STEP 1 — LOAD REFERENCES

Read these before starting:
1. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md` — known globals
2. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\13-struct-offsets.md` — known struct offsets

## YOUR OUTPUT FILE

Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\stub_upgrade\worker_B.md

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

9. %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x0042d6b0__FUN_0042d6b0.c
   [addr: 0x0042D6B0 | target: docs/01-engine-architecture.md]
10. %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004c8ab0__FUN_004c8ab0.c
   [addr: 0x004C8AB0 | target: docs/01-engine-architecture.md]
11. %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x0049f120__FUN_0049f120.c
   [addr: 0x0049F120 | target: docs/01-engine-architecture.md]
12. %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004fa640__FUN_004fa640.c
   [addr: 0x004FA640 | target: docs/01-engine-architecture.md]
13. %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004a18d0__FUN_004a18d0.c
   [addr: 0x004A18D0 | target: docs/01-engine-architecture.md]
14. %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x00421cd0__FUN_00421cd0.c
   [addr: 0x00421CD0 | target: docs/09-track-system.md]
15. %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004cfff0__FUN_004cfff0.c
   [addr: 0x004CFFF0 | target: docs/09-track-system.md]
16. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040ef70__FUN_0040ef70.c
   [addr: 0x0040EF70 | target: docs/10-vehicle-physics.md]

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
4. Write to %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\stub_upgrade\worker_B.md after each entry.
5. ALWAYS use `### FUN_XXXXXXXX — Name` format. Address from filename.
6. If function is empty (bare return): write `### FUN_X — Empty Stub` with one bullet.
7. If function is a thunk: write `### FUN_X — Thunk to FUN_Y` with one bullet.
