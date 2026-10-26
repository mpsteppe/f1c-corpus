# WORKER E — F1C Stub Upgrade to Lightweight Entries

You are upgrading table-row-only function stubs to lightweight `### FUN_` entries.
Worker E of 10, items 33–40.

## STEP 1 — LOAD REFERENCES

Read these before starting:
1. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md` — known globals
2. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\13-struct-offsets.md` — known struct offsets

## YOUR OUTPUT FILE

Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\stub_upgrade\worker_E.md

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

33. %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x0042c130__FUN_0042c130.c
   [addr: 0x0042C130 | target: docs/01-engine-architecture.md]
34. %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004c8ca0__FUN_004c8ca0.c
   [addr: 0x004C8CA0 | target: docs/01-engine-architecture.md]
35. %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x00455d50__FUN_00455d50.c
   [addr: 0x00455D50 | target: docs/01-engine-architecture.md]
36. %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004b4030__FUN_004b4030.c
   [addr: 0x004B4030 | target: docs/01-engine-architecture.md]
37. %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004b1820__FUN_004b1820.c
   [addr: 0x004B1820 | target: docs/08-file-formats.md]
38. %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x00455290__FUN_00455290.c
   [addr: 0x00455290 | target: docs/09-track-system.md]
39. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005215db__FUN_005215db.c
   [addr: 0x005215DB | target: docs/10-vehicle-physics.md]
40. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051e2ba__FUN_0051e2ba.c
   [addr: 0x0051E2BA | target: docs/10-vehicle-physics.md]

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
4. Write to %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\stub_upgrade\worker_E.md after each entry.
5. ALWAYS use `### FUN_XXXXXXXX — Name` format. Address from filename.
6. If function is empty (bare return): write `### FUN_X — Empty Stub` with one bullet.
7. If function is a thunk: write `### FUN_X — Thunk to FUN_Y` with one bullet.
