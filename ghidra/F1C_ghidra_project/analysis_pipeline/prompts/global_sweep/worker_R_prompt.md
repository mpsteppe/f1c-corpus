# WORKER R — F1C Global Variable Consolidation

You are building the comprehensive globals reference for F1 Challenge 99-02.
Worker R of 20.

## STEP 1 — LOAD REFERENCES

1. Read current globals reference:
   `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md`

2. Read the globals usage graph:
   `%USERPROFILE%\Desktop\F1C_ghidra_project\knowledge_graph\globals_usage.json`
   This has every global with its name (if known) and which functions use it.

## YOUR OUTPUT FILE

Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\global_sweep\worker_R.md

## YOUR GLOBALS (43)

747. DAT_007c56a4 — SessionType (7=race)
   module: unknown | used_by: 9 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x00433890__FUN_00433890.c, %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004333e0__FUN_004333e0.c, %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004bc4e0__FUN_004bc4e0.c
748. DAT_0059e7ec — ` — compared constant (5.0f encoded indirectly
   module: unknown | used_by: 4 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0042a740__FUN_0042a740.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c77d0__FUN_004c77d0.c, %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x0045f950__FUN_0045f950.c
749. DAT_0059e774 — ` — position scale factor
   module: unknown | used_by: 3 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050a0f0__FUN_0050a0f0.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050a223__FUN_0050a223.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050a2b4__FUN_0050a2b4.c
750. DAT_005d6d64 — ` / `DAT_005d6d60` � screen dimensions
   module: unknown | used_by: 3 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x0049f870__FUN_0049f870.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dd400__FUN_004dd400.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00494690__FUN_00494690.c
751. DAT_008b8e30 — ` — entry count (max 0x20
   module: unknown | used_by: 3 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053c6f0__FUN_0053c6f0.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053c900__FUN_0053c900.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053c9c0__FUN_0053c9c0.c
752. DAT_0059ed10 — time-step scaling factor
   module: unknown | used_by: 2 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052b561__FUN_0052b561.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0043ff3d__FUN_0043ff3d.c
753. DAT_005c329c — VehicleCount
   module: unknown | used_by: 2 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004333e0__FUN_004333e0.c, %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x0045fc50__FUN_0045fc50.c
754. DAT_005ed434 — analog axis table
   module: unknown | used_by: 2 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00410bc0__FUN_00410bc0.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00411120__FUN_00411120.c
755. DAT_007cde08 — ` — Destination surface/context
   module: unknown | used_by: 2 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00494a70__FUN_00494a70.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00494690__FUN_00494690.c
756. DAT_008acfb4 — ` â€” idle/reverse speed target
   module: unknown | used_by: 2 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00426430__FUN_00426430.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0042acd0__FUN_0042acd0.c
757. DAT_0059e428 — NaN sentinel constant
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054d4e0__FUN_0054d4e0.c
758. DAT_0059e8d0 — ` â€” steering deadband threshold
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00426430__FUN_00426430.c
759. DAT_0059ec48 — )
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004dfce0__FUN_004dfce0.c
760. DAT_0059ef78 — ` — second threshold/reference value
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00454250__FUN_00454250.c
761. DAT_005acb10 — ` — multiplier for cases 3,4
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049f530__FUN_0049f530.c
762. DAT_005aceb4 — � particle count multiplier
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004cc970__FUN_004cc970.c
763. DAT_005ad1f8 — ` — Sentinel value (likely 0.0 or -1.0, indicating "use dynamic"
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ee230__FUN_004ee230.c
764. DAT_005af428 — ` — validation threshold
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051249f__FUN_0051249f.c
765. DAT_005be718 — ` � hot lap directory path
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004b7de0__FUN_004b7de0.c
766. DAT_005c6950 — ` — "ProfileIcon.bmp" string
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x00468ee0__FUN_00468ee0.c
767. DAT_005d30d8 — `/`DAT_005d30d4`/etc — filter category name patterns (copied from static data
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004c6330__FUN_004c6330.c
768. DAT_005d9180 — ..c` â€” polynomial c1 coefficients
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00528cc0__FUN_00528cc0.c
769. DAT_005e9ef4 — ` — reference counter
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00598994__FUN_00598994.c
770. DAT_005ecdcc — ` — per-player data (stride 0x1230
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x0045fc50__FUN_0045fc50.c
771. DAT_007CD0C8 — ` — collision material ID (80
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e4e0__FUN_0044e4e0.c
772. DAT_007c74f8 — ` — camera/view mode global
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f1b50__FUN_004f1b50.c
773. DAT_007ca448 — `, `DAT_007ccbf4`, `DAT_007ca3a8`, `DAT_007ca480`, `DAT_007cc9ec`, `DAT_007ca3d8` â€” audio buffer/source objects identified by address
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044ff50__FUN_0044ff50.c
774. DAT_007cb710 — ` — Env flag (bit 0 = wet
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ade20__FUN_004ade20.c
775. DAT_007cccb0 — ` through `_DAT_007cccbc` — collision configuration variables
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044c9e0__FUN_0044c9e0.c
776. DAT_007ccdac — ` — 5 zeroed fields
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e0c0__FUN_0044e0c0.c
777. DAT_007ccee8 — ` — node element count
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044db80__FUN_0044db80.c
778. DAT_007cd09c — ` through `DAT_007cd0ac` — collision bucket state (zeroed
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e2a0__FUN_0044e2a0.c
779. DAT_007cd458 — `, `DAT_007cd45c`, `DAT_007cd2b0`, `DAT_007cd610` — collision parameter arrays
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00475d30__FUN_00475d30.c
780. DAT_007ce498 — AutoLoadConfigFile
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x00432e70__FUN_00432e70.c
781. DAT_007cf380 — ` -- unknown float global [UNNAMED — needs .c analysis]
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00404970__FUN_00404970.c
782. DAT_007d03e0 — ` â€” AI settings mode (0=simple, nonzero=advanced
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004333e0__FUN_004333e0.c
783. DAT_007d1424 — ` — number of teams/entries
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046ae60__FUN_0046ae60.c
784. DAT_007d2e50 — ` — session message counter
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x0045d890__FUN_0045d890.c
785. DAT_008acaa4 — � particle spawn position tables
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004cc970__FUN_004cc970.c
786. DAT_008afc80 — function pointer from module
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f8c90__FUN_004f8c90.c
787. DAT_008b8f1c — `, `DAT_008b8f20`
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053c4d0__FUN_0053c4d0.c
788. DAT_008d41b4 — ` — global callback function pointer
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00593db8__FUN_00593db8.c
789. DAT_008d5a60 — ` — capacity/limit global constant
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059a473__FUN_0059a473.c

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
