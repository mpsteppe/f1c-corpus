# WORKER G — F1C Stub Upgrade to Lightweight Entries

You are upgrading table-row-only function stubs to lightweight `### FUN_` entries.
Worker G of 10, items 49–56.

## STEP 1 — LOAD REFERENCES

Read these before starting:
1. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md` — known globals
2. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\13-struct-offsets.md` — known struct offsets

## YOUR OUTPUT FILE

Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\stub_upgrade\worker_G.md

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

49. %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x0042c1a0__FUN_0042c1a0.c
   [addr: 0x0042C1A0 | target: docs/01-engine-architecture.md]
50. %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x0049ef40__FUN_0049ef40.c
   [addr: 0x0049EF40 | target: docs/01-engine-architecture.md]
51. %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x00455e70__FUN_00455e70.c
   [addr: 0x00455E70 | target: docs/01-engine-architecture.md]
52. %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004b40a0__FUN_004b40a0.c
   [addr: 0x004B40A0 | target: docs/01-engine-architecture.md]
53. %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004b18d0__FUN_004b18d0.c
   [addr: 0x004B18D0 | target: docs/08-file-formats.md]
54. %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004cee90__FUN_004cee90.c
   [addr: 0x004CEE90 | target: docs/09-track-system.md]
55. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052835f__FUN_0052835f.c
   [addr: 0x0052835F | target: docs/10-vehicle-physics.md]
56. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005418e0__FUN_005418e0.c
   [addr: 0x005418E0 | target: docs/10-vehicle-physics.md]

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
4. Write to %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\stub_upgrade\worker_G.md after each entry.
5. ALWAYS use `### FUN_XXXXXXXX — Name` format. Address from filename.
6. If function is empty (bare return): write `### FUN_X — Empty Stub` with one bullet.
7. If function is a thunk: write `### FUN_X — Thunk to FUN_Y` with one bullet.
