# WORKER P — F1C Global Variable Consolidation

You are building the comprehensive globals reference for F1 Challenge 99-02.
Worker P of 20.

## STEP 1 — LOAD REFERENCES

1. Read current globals reference:
   `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md`

2. Read the globals usage graph:
   `%USERPROFILE%\Desktop\F1C_ghidra_project\knowledge_graph\globals_usage.json`
   This has every global with its name (if known) and which functions use it.

## YOUR OUTPUT FILE

Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\global_sweep\worker_P.md

## YOUR GLOBALS (43)

661. DAT_0059e670 — ` — sentinel flag constant
   module: unknown | used_by: 9 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004144f0__FUN_004144f0.c, %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004b7de0__FUN_004b7de0.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00454da0__FUN_00454da0.c
662. DAT_008ac488 — SceneFileCount
   module: unknown | used_by: 5 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c28d0__FUN_004c28d0.c, %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004c18b0__FUN_004c18b0.c, %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004c5940__FUN_004c5940.c
663. DAT_0059e5fc — ` â€” global frame-rate correction
   module: unknown | used_by: 3 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00454da0__FUN_00454da0.c, %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004637a0__FUN_004637a0.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004fb6d0__FUN_004fb6d0.c
664. DAT_005bf8d4 — � data value for index 1
   module: unknown | used_by: 3 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00414180__FUN_00414180.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004141a0__FUN_004141a0.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004117b0__FUN_004117b0.c
665. DAT_008afee8 — � track grip constants (docs/07, 18
   module: unknown | used_by: 3 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ee2d0__FUN_004ee2d0.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00404460__FUN_00404460.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00429fd0__FUN_00429fd0.c
666. DAT_0059ea60 — ` — angular threshold for partial response
   module: unknown | used_by: 2 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00460dd0__FUN_00460dd0.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0043ebd0__FUN_0043ebd0.c
667. DAT_005bf8d0 — ` -- alternate field value
   module: unknown | used_by: 2 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00414160__FUN_00414160.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004117b0__FUN_004117b0.c
668. DAT_005ed3ac — throttle input table
   module: unknown | used_by: 2 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00410bc0__FUN_00410bc0.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00411120__FUN_00411120.c
669. DAT_007cddf4 — ` — collision list tail pointer
   module: unknown | used_by: 2 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00494de0__FUN_00494de0.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00494e60__FUN_00494e60.c
670. DAT_008ac4c8 — , DAT_008ac4cc, DAT_008ac4d0, DAT_008ac4c4 — global singleton/manager pointers
   module: unknown | used_by: 2 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c8350__FUN_004c8350.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c8580__FUN_004c8580.c
671. DAT_0059F120 — ` — float scale factor (screen coordinate conversion
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005093f9__FUN_005093f9.c
672. DAT_0059e85c — ` -- max threshold
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c2cb0__FUN_004c2cb0.c
673. DAT_0059eba0 — ` — energy-to-damage conversion factor
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004390a0__FUN_004390a0.c
674. DAT_0059ef48 — ` — extent scale factor
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044b910__FUN_0044b910.c
675. DAT_005ac988 — ` — UV coordinate scale factor
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00494a70__FUN_00494a70.c
676. DAT_005aceac — `, `_DAT_0059e450`, `_DAT_0059ed18` — float constants
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004cc840__FUN_004cc840.c
677. DAT_005ad1bc — ` — rear distribution weight
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e8010__FUN_004e8010.c
678. DAT_005adc44 — /40/3c/38` â€” YCbCrâ†’RGB matrix coefficients
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050ab51__FUN_0050ab51.c
679. DAT_005b9c5c — ` — locale vtable pointer
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00599bf0__FUN_00599bf0.c
680. DAT_005c66f8 — ` — "ProfileIcon_DFT.bmp" default icon
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x00468ee0__FUN_00468ee0.c
681. DAT_005d3074 — ` — "*.tga" filter string constant
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004c3a00__FUN_004c3a00.c
682. DAT_005d9150 — ..c` â€” final add coefficients
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00528cc0__FUN_00528cc0.c
683. DAT_005e523c — � double constants (joint stiffness
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0056a390__FUN_0056a390.c
684. DAT_005ec4cc — ` — message display buffer
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x00461d20__FUN_00461d20.c
685. DAT_007CCE10 — ` — collision material ID (52
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044dd60__FUN_0044dd60.c
686. DAT_007c7408 — ` to `_DAT_007c7424` — set to 0
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00431c00__FUN_00431c00.c
687. DAT_007ca420 — ` — collision state block (type=0x62
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044eba0__FUN_0044eba0.c
688. DAT_007ca52c — ` — grid state (zeroed
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044eb40__FUN_0044eb40.c
689. DAT_007ccc9c — `-`DAT_007cccac` — collision globals, zeroed
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d700__FUN_0044d700.c
690. DAT_007ccd98 — ` — collision object index/type
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e0c0__FUN_0044e0c0.c
691. DAT_007cced4 — ` through `DAT_007ccee4` — material property fields (zeroed
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044da60__FUN_0044da60.c
692. DAT_007cd048 — ` — region threshold (9000
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e480__FUN_0044e480.c
693. DAT_007cd2a0 — ` — track/scene refresh flag (0 = no refresh needed
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00462140__FUN_00462140.c
694. DAT_007ce25d — ` -- global flag
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a0da0__FUN_004a0da0.c
695. DAT_007cf014 — External reference stored
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00470cc0__FUN_00470cc0.c
696. DAT_007d0308 — RaceActiveFlag
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0041f220__FUN_0041f220.c
697. DAT_007d12ec — ` â€” brake/clutch decay rate
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00454da0__FUN_00454da0.c
698. DAT_007d2e44 — ` -- scoring gate enable flag
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0042bc10__FUN_0042bc10.c
699. DAT_008ac840 — ` — global array base (not in docs/12
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004cc840__FUN_004cc840.c
700. DAT_008aeec0 — ` — aero/suspension mode selector (0=fixed, 1=blended, 2=fixed-alt
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00431850__FUN_00431850.c
701. DAT_008b8ef8 — ` — buffer ready counter
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00546010__FUN_00546010.c
702. DAT_008d4078 — Initialization flag (0 = uninitialized, >0 = initialized
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005921c5__FUN_005921c5.c
703. DAT_008d4908 — � OS version
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059325d__FUN_0059325d.c

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
