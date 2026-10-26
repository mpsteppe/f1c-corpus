# WORKER D — F1C Stub Upgrade to Lightweight Entries

You are upgrading table-row-only function stubs to lightweight `### FUN_` entries.
Worker D of 10, items 25–32.

## STEP 1 — LOAD REFERENCES

Read these before starting:
1. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md` — known globals
2. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\13-struct-offsets.md` — known struct offsets

## YOUR OUTPUT FILE

Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\stub_upgrade\worker_D.md

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

25. %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x0042db20__FUN_0042db20.c
   [addr: 0x0042DB20 | target: docs/01-engine-architecture.md]
26. %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004c8b20__FUN_004c8b20.c
   [addr: 0x004C8B20 | target: docs/01-engine-architecture.md]
27. %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x00455c60__FUN_00455c60.c
   [addr: 0x00455C60 | target: docs/01-engine-architecture.md]
28. %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004fad00__FUN_004fad00.c
   [addr: 0x004FAD00 | target: docs/01-engine-architecture.md]
29. %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004a0eb0__FUN_004a0eb0.c
   [addr: 0x004A0EB0 | target: docs/01-engine-architecture.md]
30. %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004a24d0__FUN_004a24d0.c
   [addr: 0x004A24D0 | target: docs/09-track-system.md]
31. %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004d75d0__FUN_004d75d0.c
   [addr: 0x004D75D0 | target: docs/10-vehicle-physics.md]
32. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00441bb0__FUN_00441bb0.c
   [addr: 0x00441BB0 | target: docs/10-vehicle-physics.md]

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
4. Write to %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\stub_upgrade\worker_D.md after each entry.
5. ALWAYS use `### FUN_XXXXXXXX — Name` format. Address from filename.
6. If function is empty (bare return): write `### FUN_X — Empty Stub` with one bullet.
7. If function is a thunk: write `### FUN_X — Thunk to FUN_Y` with one bullet.
