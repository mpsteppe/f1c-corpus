# WORKER N — F1C Global Variable Consolidation

You are building the comprehensive globals reference for F1 Challenge 99-02.
Worker N of 20.

## STEP 1 — LOAD REFERENCES

1. Read current globals reference:
   `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md`

2. Read the globals usage graph:
   `%USERPROFILE%\Desktop\F1C_ghidra_project\knowledge_graph\globals_usage.json`
   This has every global with its name (if known) and which functions use it.

## YOUR OUTPUT FILE

Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\global_sweep\worker_N.md

## YOUR GLOBALS (44)

573. DAT_008afe90 — ` — cooling rate per frame
   module: unknown | used_by: 11 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c77d0__FUN_004c77d0.c, %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004612e0__FUN_004612e0.c, %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x00461d20__FUN_00461d20.c
574. DAT_0083ee60 — ` -- ring buffer counter
   module: unknown | used_by: 5 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004fc650__FUN_004fc650.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c77d0__FUN_004c77d0.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ef4f0__FUN_004ef4f0.c
575. DAT_0059e4dc — ` — full response threshold (float
   module: unknown | used_by: 3 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00460dd0__FUN_00460dd0.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004cc970__FUN_004cc970.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00405f80__FUN_00405f80.c
576. DAT_005adb20 — ` — channel 2 blend weight
   module: unknown | used_by: 3 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00509244__FUN_00509244.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050930b__FUN_0050930b.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00508867__FUN_00508867.c
577. DAT_008afe68 — ` — value at that index
   module: unknown | used_by: 3 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f9160__FUN_004f9160.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f91b0__FUN_004f91b0.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f9200__FUN_004f9200.c
578. DAT_0059e9e0 — ` — color channel scale factor
   module: unknown | used_by: 2 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050a172__FUN_0050a172.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e9630__FUN_004e9630.c
579. DAT_005be880 — ` — unknown string constant [UNNAMED — needs .c analysis]
   module: unknown | used_by: 2 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040c3b0__FUN_0040c3b0.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040c240__FUN_0040c240.c
580. DAT_005ec440 — ` â€” settings directory
   module: unknown | used_by: 2 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x00433890__FUN_00433890.c, %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x00468ee0__FUN_00468ee0.c
581. DAT_007cd2ac — � base address for sort priority table
   module: unknown | used_by: 2 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00465d70__FUN_00465d70.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00465460__FUN_00465460.c
582. DAT_008aae70 — RingBufferCounter (QA/weather noise)
   module: unknown | used_by: 2 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ef4f0__FUN_004ef4f0.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004cc970__FUN_004cc970.c
583. DAT_0059EA60 — ` — float scale factor (damping B
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0043ec50__FUN_0043ec50.c
584. DAT_0059e828 — ` — float 1.0 constant
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e5080__FUN_004e5080.c
585. DAT_0059eb40 — ` — Scaling constant
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d6ae0__FUN_004d6ae0.c
586. DAT_0059ef38 — ` — double, subdivision threshold (max edge length
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044aae0__FUN_0044aae0.c
587. DAT_005ACDAC — ` — global threshold/reference value (used as default
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004be700__FUN_004be700.c
588. DAT_005ace18 — ` — global param for type 5
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c9a50__FUN_004c9a50.c
589. DAT_005ad1b4 — ` — dry grip multiplier
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e8010__FUN_004e8010.c
590. DAT_005adc00 — `–`_DAT_005adc14` — 3×4 color transformation matrix (float
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050a92d__FUN_0050a92d.c
591. DAT_005b9bc0 — primary vtable pointer
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00598af5__FUN_00598af5.c
592. DAT_005c5b88 — ` — "terrain.ini" string constant
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x00460a10__FUN_00460a10.c
593. DAT_005cd138 — ` — prefix string A
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a1b20__FUN_004a1b20.c
594. DAT_005d9050 — ` — channel mask
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005289e0__FUN_005289e0.c
595. DAT_005dd1e0 — , DAT_005dd1f8, DAT_005dc628, DAT_005dc640 � resource identifiers
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00560340__FUN_00560340.c
596. DAT_005ec4a8 — ` — Camera index increment
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ade20__FUN_004ade20.c
597. DAT_007CCC80 — ` — collision material ID (19
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d5e0__FUN_0044d5e0.c
598. DAT_007c73f4 — `, `_DAT_007c73fc` — set to -1
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00431c00__FUN_00431c00.c
599. DAT_007ca418 — `, `_DAT_007ca41c` — collision parameters
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d2e0__FUN_0044d2e0.c
600. DAT_007ca51c — ` — grid size (97
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044eb40__FUN_0044eb40.c
601. DAT_007ccc34 — ` — collision configuration variables
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d760__FUN_0044d760.c
602. DAT_007ccd6c — ` through `_DAT_007ccd7c` — 5 reset fields
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e060__FUN_0044e060.c
603. DAT_007cceb8 — ` — constraint count/size
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044dac0__FUN_0044dac0.c
604. DAT_007cd030 — ` — collision limit (set to 27000
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e840__FUN_0044e840.c
605. DAT_007cd268 — ` — int, lock state (-1 = unlocked
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045bf90__FUN_0045bf90.c
606. DAT_007ce258 — , DAT_007ce260, DAT_007ce269, DAT_007ce26c
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a0fb0__FUN_004a0fb0.c
607. DAT_007ce934 — ` — scale factor
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00438cc0__FUN_00438cc0.c
608. DAT_007d0278 — ` — speed scaling denominator
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e8010__FUN_004e8010.c
609. DAT_007d12a4 — ` â€” steering rate
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00454da0__FUN_00454da0.c
610. DAT_007d2dc8 — ` � linked list of race results (stride 4+ per entry
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x00469900__FUN_00469900.c
611. DAT_008ac830 — , DAT_008ac83c � particle visual config tables
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004cc970__FUN_004cc970.c
612. DAT_008adaf8 — slot counter
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ea010__FUN_004ea010.c
613. DAT_008b8ef0 — ` — buffer pointer/reference
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00546010__FUN_00546010.c
614. DAT_008d3f38 — � default locale
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00595dc8__FUN_00595dc8.c
615. DAT_008d48e4 — locale
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00597f6d____mbsnbicoll.c
616. DAT_007d01a0 — AIDifficultySlider
   module: unknown | used_by: 0 functions
   sample .c files: no .c files found

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
