# WORKER J — F1C Global Variable Consolidation

You are building the comprehensive globals reference for F1 Challenge 99-02.
Worker J of 20.

## STEP 1 — LOAD REFERENCES

1. Read current globals reference:
   `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md`

2. Read the globals usage graph:
   `%USERPROFILE%\Desktop\F1C_ghidra_project\knowledge_graph\globals_usage.json`
   This has every global with its name (if known) and which functions use it.

## YOUR OUTPUT FILE

Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\global_sweep\worker_J.md

## YOUR GLOBALS (44)

397. DAT_007c569c — SessionType5 (5=server)
   module: unknown | used_by: 12 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044f150__FUN_0044f150.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044f4a0__FUN_0044f4a0.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044f460__FUN_0044f460.c
398. DAT_005ac108 — ` — color normalization factor
   module: unknown | used_by: 5 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00509a09__FUN_00509a09.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00509de6__FUN_00509de6.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050a067__FUN_0050a067.c
399. DAT_008b8dc8 — ` — global resource/data pointer
   module: unknown | used_by: 4 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00495020__FUN_00495020.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d8a30__FUN_004d8a30.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00495120__FUN_00495120.c
400. DAT_005accd8 — ` — G channel scale factor (different precision
   module: unknown | used_by: 3 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00507bc5__FUN_00507bc5.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00508b1d__FUN_00508b1d.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b2a40__FUN_004b2a40.c
401. DAT_007d00ec — GameState (1-7)
   module: unknown | used_by: 3 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00461440__FUN_00461440.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040d3c0__FUN_0040d3c0.c, %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004c0910__FUN_004c0910.c
402. DAT_0059e8c8 — ` — convergence threshold (terminates iteration
   module: unknown | used_by: 2 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e8010__FUN_004e8010.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c7de0__FUN_004c7de0.c
403. DAT_005ad198 — Global force scaling multiplier
   module: unknown | used_by: 2 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d9d7__FUN_0059d9d7.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00464a10__FUN_00464a10.c
404. DAT_005ea404 — ` — track reference values
   module: unknown | used_by: 2 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d7b00__FUN_004d7b00.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d7c10__FUN_004d7c10.c
405. DAT_007ca50c — ` — collision contact limit / iteration count
   module: unknown | used_by: 2 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044cd40__FUN_0044cd40.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044ff50__FUN_0044ff50.c
406. DAT_007d02e4 — ` — global reference stored in object
   module: unknown | used_by: 2 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004733a0__FUN_004733a0.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045bd10__FUN_0045bd10.c
407. DAT_008cef78 — ` â€” vertex buffer resource data pointer
   module: unknown | used_by: 2 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053eb70__FUN_0053eb70.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00560340__FUN_00560340.c
408. DAT_0059e710 — ` — FFB maximum threshold
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e2760__FUN_004e2760.c
409. DAT_0059eab0 — ` — linear transform coefficients
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049f530__FUN_0049f530.c
410. DAT_0059ef00 — ` — output value at saturation
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00447bb0__FUN_00447bb0.c
411. DAT_0059f130 — ` — default sensor value
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00464a40__FUN_00464a40.c
412. DAT_005acd3c — ` — aero constant
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f0dd0__FUN_004f0dd0.c
413. DAT_005ad170 — ` — track/camber factors
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e3d00__FUN_004e3d00.c
414. DAT_005ad3ec — ` â€” gain envelope curve data tables (X/Y pairs
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044ff50__FUN_0044ff50.c
415. DAT_005b8c80 — , _DAT_005b8d48, _DAT_005b8d50 � CRT heap boundary globals
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058bc68__FUN_0058bc68.c
416. DAT_005c32a8 — registered
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00471750__FUN_00471750.c
417. DAT_005ccec8 — format string
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049d3f0__FUN_0049d3f0.c
418. DAT_005d8fb0 — ` etc. — overflow detection masks
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005289e0__FUN_005289e0.c
419. DAT_005dc628 — , DAT_005dc640 � resource identifiers
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00560340__FUN_00560340.c
420. DAT_005ebb24 — ` — zeroed
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00418db0__FUN_00418db0.c
421. DAT_007CC9EC — ` — collision material ID (40
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044cfe0__FUN_0044cfe0.c
422. DAT_007c7384 — ` — indexed menu globals array
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004674e0__FUN_004674e0.c
423. DAT_007ca3f8 — ` — region type (99
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044ec00__FUN_0044ec00.c
424. DAT_007ca4d8 — ` — initialized to -1.0f (invalid/null index sentinel
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d340__FUN_0044d340.c
425. DAT_007ccbf8 — ` — zero
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044cec0__FUN_0044cec0.c
426. DAT_007ccd50 — ` — collision bucket/cell index (0xd
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d3a0__FUN_0044d3a0.c
427. DAT_007cce88 — ` — region type (51
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044dd00__FUN_0044dd00.c
428. DAT_007cd004 — ` — collision state block (type=0x4e
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e420__FUN_0044e420.c
429. DAT_007cd188 — ` — collision object index/type
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044cbc0__FUN_0044cbc0.c
430. DAT_007cde24 — � surface 3 refs
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00494690__FUN_00494690.c
431. DAT_007ce850 — ` — stored in param_1[199]
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004715d0__FUN_004715d0.c
432. DAT_007d01c4 — ` — Physics randomization flags (bit 2 = enable random speed noise
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d9b5__FUN_0059d9b5.c
433. DAT_007d0f94 — Global boolean flag
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045d490__FUN_0045d490.c
434. DAT_007d23a4 — `, `DAT_007d2434` â€” gain envelope curve selectors per channel
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044ff50__FUN_0044ff50.c
435. DAT_008ac438 — ` — .AIW file path buffer
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004c54f0__FUN_004c54f0.c
436. DAT_008ad398 — , _39c, _3a0, _3a4, _3a8 — state handles
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d8a30__FUN_004d8a30.c
437. DAT_008b8dd8 — ` / `DAT_008b8dd4` â€” screen dimensions (width/height ratio
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00542050__FUN_00542050.c
438. DAT_008d3e44 — ` — not in docs/12; written with return value from FUN_0058bca6
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00587b7f__FUN_00587b7f.c
439. DAT_008d463c — Reference count array (indexed by extraout_ECX[9]
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059a86c__FUN_0059a86c.c
440. DAT_007cebc4 — FormationLap
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
