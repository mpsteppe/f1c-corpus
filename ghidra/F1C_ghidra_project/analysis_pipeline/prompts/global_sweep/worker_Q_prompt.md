# WORKER Q — F1C Global Variable Consolidation

You are building the comprehensive globals reference for F1 Challenge 99-02.
Worker Q of 20.

## STEP 1 — LOAD REFERENCES

1. Read current globals reference:
   `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md`

2. Read the globals usage graph:
   `%USERPROFILE%\Desktop\F1C_ghidra_project\knowledge_graph\globals_usage.json`
   This has every global with its name (if known) and which functions use it.

## YOUR OUTPUT FILE

Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\global_sweep\worker_Q.md

## YOUR GLOBALS (43)

704. DAT_0059e880 — ` — lower threshold constant
   module: unknown | used_by: 9 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0042e290__FUN_0042e290.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044ba40__FUN_0044ba40.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044b910__FUN_0044b910.c
705. DAT_008ad25c — ` — debug message buffer
   module: unknown | used_by: 5 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x0045fc50__FUN_0045fc50.c, %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x00460520__FUN_00460520.c, %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x00460cb0__FUN_00460cb0.c
706. DAT_0059e600 — ` â€” speed threshold for full-lock steering
   module: unknown | used_by: 3 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00426430__FUN_00426430.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f0f40__FUN_004f0f40.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f1120__FUN_004f1120.c
707. DAT_005d6d60 — ` � screen dimensions
   module: unknown | used_by: 3 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x0049f870__FUN_0049f870.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dd400__FUN_004dd400.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00494690__FUN_00494690.c
708. DAT_008b5a38 — ` — flags
   module: unknown | used_by: 3 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053c6f0__FUN_0053c6f0.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053c900__FUN_0053c900.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053c9c0__FUN_0053c9c0.c
709. DAT_0059eac8 — ` — Thermal constant
   module: unknown | used_by: 2 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d6ae0__FUN_004d6ae0.c, %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004dfce0__FUN_004dfce0.c
710. DAT_005bf9a0 — ` (DriverDataTable
   module: unknown | used_by: 2 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004144f0__FUN_004144f0.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00418b70__FUN_00418b70.c
711. DAT_005ed3f0 — brake input table
   module: unknown | used_by: 2 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00410bc0__FUN_00410bc0.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00411120__FUN_00411120.c
712. DAT_007cddf8 — ` — collision list iterator
   module: unknown | used_by: 2 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00494de0__FUN_00494de0.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00494e60__FUN_00494e60.c
713. DAT_008acf90 — ` — race time offset
   module: unknown | used_by: 2 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004bc4e0__FUN_004bc4e0.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a0ba0__FUN_004a0ba0.c
714. DAT_0059e — ### / _DAT_005ad### � amplitude, frequency, damping, and clamp constants
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004fd8b0__FUN_004fd8b0.c
715. DAT_0059e8b4 — ` — clamp upper threshold
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f0dd0__FUN_004f0dd0.c
716. DAT_0059ec20 — ` — force clamp max
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f1120__FUN_004f1120.c
717. DAT_0059ef58 — ` â€” master sample rate / divider reference
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044ff50__FUN_0044ff50.c
718. DAT_005acaa8 — � Constant
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499b10__FUN_00499b10.c
719. DAT_005aceb0 — � particle offset constant
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004cc970__FUN_004cc970.c
720. DAT_005ad1c0 — ` — cornering stiffness coefficient
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e8010__FUN_004e8010.c
721. DAT_005ade40 — small threshold pointer (near-zero
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050ed19__FUN_0050ed19.c
722. DAT_005be714 — serialization constant
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004b7de0__FUN_004b7de0.c
723. DAT_005c693c — ` � "GrandPrixName" constant
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x00469900__FUN_00469900.c
724. DAT_005d30d4 — `/etc — filter category name patterns (copied from static data
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004c6330__FUN_004c6330.c
725. DAT_005d9160 — ..c` â€” polynomial c0 coefficients
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00528cc0__FUN_00528cc0.c
726. DAT_005e99a0 — Shared parse/lookup table
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00595524__FUN_00595524.c
727. DAT_005ec6e4 — ` -- SeasonScoringDB base pointer (stride 0x48c0
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0042bd60__FUN_0042bd60.c
728. DAT_007CCE14 — 007CCE24` — material coefficients (zeroed
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044dd60__FUN_0044dd60.c
729. DAT_007c7424 — ` — set to 0
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00431c00__FUN_00431c00.c
730. DAT_007ca440 — ` — radius sentinel (-1.0f
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044ce00__FUN_0044ce00.c
731. DAT_007ca530 — ` — max distance (27000
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044eb40__FUN_0044eb40.c
732. DAT_007cccac — ` — collision globals, zeroed
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d700__FUN_0044d700.c
733. DAT_007ccd9c — ` through `DAT_007ccdac` — 5 zeroed fields
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e0c0__FUN_0044e0c0.c
734. DAT_007ccee4 — ` — material property fields (zeroed
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044da60__FUN_0044da60.c
735. DAT_007cd098 — ` — collision bucket/cell index (0x4a
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e2a0__FUN_0044e2a0.c
736. DAT_007cd2b0 — `, `DAT_007cd610` — collision parameter arrays
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00475d30__FUN_00475d30.c
737. DAT_007ce2e4 — � Sleep suppress flag
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a1830__FUN_004a1830.c
738. DAT_007cf2cc — ` — DSP transform parameter
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00448330__FUN_00448330.c
739. DAT_007d0350 — ` — session active flag (near GameState DAT_007d00ec
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040d3c0__FUN_0040d3c0.c
740. DAT_007d1310 — ` â€” handbrake decay rate
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00454da0__FUN_00454da0.c
741. DAT_007d2e48 — SeasonScoringDB (stride 0x48c0)
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004c0910__FUN_004c0910.c
742. DAT_008acaa0 — , DAT_008acaa4 � particle spawn position tables
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004cc970__FUN_004cc970.c
743. DAT_008afc78 — loaded module handle
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f8c90__FUN_004f8c90.c
744. DAT_008b8efc — ` — written from param_2
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00546230__FUN_00546230.c
745. DAT_008d41b0 — ` — CRT debug heap flag
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058a935___malloc.c
746. DAT_008d5a4c — ` -- init guard flag
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00597218__FUN_00597218.c

## TASK

For each global in your list:
1. Look up the global in globals_usage.json for its current name and usage
2. If the global has a known name: verify it, add module/value-range/description
3. If unnamed (name = address or "unknown"): read the .c files that use it,
   determine its purpose, and propose a name

Output one row per global:
```
| DAT_XXXXXXXX | ProposedName | module | type | value_range | description | used_by_count | confidence |
```

For unnamed globals that need .c file analysis, also write:
```
### DAT_XXXXXXXX — ProposedName
Observed in: FUN_AAAAAAAA, FUN_BBBBBBBB
Evidence: [what the .c code does with this global]
Confidence: high/medium/low
```

Write to disk after every 20 globals.

## RULES
0. NEVER move, rename, or delete any files.
1. Process ALL globals in your list.
2. Use the EXISTING name from the knowledge graph if it is meaningful.
3. For unnamed globals, read at least 2 .c files that reference it before naming.
4. Module = which game system owns this global (physics, ai, renderer, session, etc.)
