# WORKER M — F1C Global Variable Consolidation

You are building the comprehensive globals reference for F1 Challenge 99-02.
Worker M of 20.

## STEP 1 — LOAD REFERENCES

1. Read current globals reference:
   `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md`

2. Read the globals usage graph:
   `%USERPROFILE%\Desktop\F1C_ghidra_project\knowledge_graph\globals_usage.json`
   This has every global with its name (if known) and which functions use it.

## YOUR OUTPUT FILE

Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\global_sweep\worker_M.md

## YOUR GLOBALS (44)

529. DAT_008ac4c4 — ` -- init status
   module: unknown | used_by: 11 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c82c0__FUN_004c82c0.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00411740__FUN_00411740.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004184f0__FUN_004184f0.c
530. DAT_005c32c8 — ` — UI/text handle (near VehicleCount
   module: unknown | used_by: 5 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004715d0__FUN_004715d0.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004733a0__FUN_004733a0.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004716d0__FUN_004716d0.c
531. DAT_0059e4d8 — physics constant
   module: unknown | used_by: 3 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050a488__FUN_0050a488.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050a3ce__FUN_0050a3ce.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00405e60__FUN_00405e60.c
532. DAT_005adb1c — ` — channel 1 blend weight
   module: unknown | used_by: 3 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00509244__FUN_00509244.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050930b__FUN_0050930b.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00508867__FUN_00508867.c
533. DAT_008acf8c — ` — total race laps
   module: unknown | used_by: 3 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004bc4e0__FUN_004bc4e0.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a5700__FUN_004a5700.c, %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x0042e530__FUN_0042e530.c
534. DAT_0059e99c — ` — conversion factor
   module: unknown | used_by: 2 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e8b80__FUN_004e8b80.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f0dd0__FUN_004f0dd0.c
535. DAT_005be860 — ` â€” format string for path construction
   module: unknown | used_by: 2 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045c0c0__FUN_0045c0c0.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044f540__FUN_0044f540.c
536. DAT_005ec3d8 — SeasonDir
   module: unknown | used_by: 2 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004a3910__FUN_004a3910.c, %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x00460a10__FUN_00460a10.c
537. DAT_007cd158 — ` — material stride (0x20 = 32 bytes per material entry
   module: unknown | used_by: 2 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044cce0__FUN_0044cce0.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044ff50__FUN_0044ff50.c
538. DAT_007d1b08 — ` — global action type array
   module: unknown | used_by: 2 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046a9c0__FUN_0046a9c0.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046a980__FUN_0046a980.c
539. DAT_0059E43C — ` — float threshold for contact aging overflow
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045c7e0__FUN_0045c7e0.c
540. DAT_0059e7f0 — ` — sentinel value (use default from table
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004144f0__FUN_004144f0.c
541. DAT_0059ead8 — ` — epsilon threshold (double
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00435290__FUN_00435290.c
542. DAT_0059ef30 — ` — -FLT_MAX
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044b910__FUN_0044b910.c
543. DAT_0059f20c — ` â€” deceleration factor
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00466650__FUN_00466650.c
544. DAT_005ace14 — ` — global param for types 1-2
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c9a50__FUN_004c9a50.c
545. DAT_005ad1b0 — ` — dry grip secondary multiplier
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e8010__FUN_004e8010.c
546. DAT_005adba4 — ` — RGB channel scale
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00509ab8__FUN_00509ab8.c
547. DAT_005b8e48 — ` — divisor constant (likely 10 for decimal divisibility test
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058df5c__FUN_0058df5c.c
548. DAT_005c406c — global string constant used for initialization
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059abcd__FUN_0059abcd.c
549. DAT_005cd12c — ` — prefix string B
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a1b20__FUN_004a1b20.c
550. DAT_005d9040 — ` etc. — scaling coefficients
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005289e0__FUN_005289e0.c
551. DAT_005dc7b8 — , DAT_005dd1e0, DAT_005dd1f8, DAT_005dc628, DAT_005dc640 � resource identifiers
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00560340__FUN_00560340.c
552. DAT_005ec438 — WeatherDir
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004c6c40__FUN_004c6c40.c
553. DAT_007CCBBC — ` — material coefficient (1.0f
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044c860__FUN_0044c860.c
554. DAT_007c73f0 — `, `DAT_007c73f8`, `DAT_007c7404`, `_DAT_007c7408` to `_DAT_007c7424` — set to 0
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00431c00__FUN_00431c00.c
555. DAT_007ca414 — `, `_DAT_007ca418`, `_DAT_007ca41c` — collision parameters
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d2e0__FUN_0044d2e0.c
556. DAT_007ca514 — ` — initial contact separation normal
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044cd40__FUN_0044cd40.c
557. DAT_007ccc20 — ` through `_DAT_007ccc34` — collision configuration variables
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d760__FUN_0044d760.c
558. DAT_007ccd68 — ` — version/magic byte
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e060__FUN_0044e060.c
559. DAT_007ccea0 — ` — collision state block (type=0x32
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044dca0__FUN_0044dca0.c
560. DAT_007cd02c — ` — 4 zeroed fields
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e840__FUN_0044e840.c
561. DAT_007cd264 — ` — HANDLE, mutex handle
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045bf90__FUN_0045bf90.c
562. DAT_007ce238 — , DAT_005ccbb8, DAT_005ccbbc
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049d700__FUN_0049d700.c
563. DAT_007ce910 — Data source pointer
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004716d0__FUN_004716d0.c
564. DAT_007d0254 — ` — wet force scale
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e8010__FUN_004e8010.c
565. DAT_007d1074 — ` — global flag (near DAT_007d00ec GameState range
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00461440__FUN_00461440.c
566. DAT_007d2dc0 — ` / `DAT_007d2dc8` � linked list of race results (stride 4+ per entry
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x00469900__FUN_00469900.c
567. DAT_008ac82c — , DAT_008ac830, DAT_008ac83c � particle visual config tables
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004cc970__FUN_004cc970.c
568. DAT_008adac0 — overflow slot
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ea010__FUN_004ea010.c
569. DAT_008b8eec — ` — half buffer size
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00546010__FUN_00546010.c
570. DAT_008d3ec0 — ` — 64-bit system timestamp tick (new global
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058b59f__FUN_0058b59f.c
571. DAT_008d46bc — locale
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00597f6d____mbsnbicoll.c
572. DAT_007cfe88 — unknown (found in 0x0040cde0) [UNNAMED — needs .c analysis]
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
