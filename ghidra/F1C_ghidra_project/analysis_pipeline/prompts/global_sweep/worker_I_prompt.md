# WORKER I — F1C Global Variable Consolidation

You are building the comprehensive globals reference for F1 Challenge 99-02.
Worker I of 20.

## STEP 1 — LOAD REFERENCES

1. Read current globals reference:
   `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md`

2. Read the globals usage graph:
   `%USERPROFILE%\Desktop\F1C_ghidra_project\knowledge_graph\globals_usage.json`
   This has every global with its name (if known) and which functions use it.

## YOUR OUTPUT FILE

Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\global_sweep\worker_I.md

## YOUR GLOBALS (44)

353. DAT_0059fec8 — ` — float multiplier for alpha channel
   module: unknown | used_by: 12 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005081ae__FUN_005081ae.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00508c22__FUN_00508c22.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00508c22__FUN_00508c22.c
354. DAT_0059f120 — ` — intensity multiplier
   module: unknown | used_by: 5 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050917d__FUN_0050917d.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00509244__FUN_00509244.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050930b__FUN_0050930b.c
355. DAT_008b89a0 — ` — global game state device object (virtual dispatch
   module: unknown | used_by: 4 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005544c0__FUN_005544c0.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00554510__FUN_00554510.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00554610__FUN_00554610.c
356. DAT_0059eed0 — ` — brightness multiplier for R/B channels
   module: unknown | used_by: 3 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00508b1d__FUN_00508b1d.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e2230__FUN_004e2230.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050ab51__FUN_0050ab51.c
357. DAT_007cf884 — ` â€” detail level (â‰¤1 = load pitcrew meshes
   module: unknown | used_by: 3 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004a2a90__FUN_004a2a90.c, %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004a3910__FUN_004a3910.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a3390__FUN_004a3390.c
358. DAT_0059e8a4 — ` â€” reverse gear throttle multiplier
   module: unknown | used_by: 2 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00454da0__FUN_00454da0.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b5da0__FUN_004b5da0.c
359. DAT_005ad148 — ` — contact proximity threshold
   module: unknown | used_by: 2 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e3d00__FUN_004e3d00.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004df110__FUN_004df110.c
360. DAT_005ea3ec — ` â€” left-hand pit flag
   module: unknown | used_by: 2 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004a2a90__FUN_004a2a90.c, %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004a3910__FUN_004a3910.c
361. DAT_007ca438 — ` — node element count (35
   module: unknown | used_by: 2 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044ce00__FUN_0044ce00.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044ff50__FUN_0044ff50.c
362. DAT_007d0038 — ` — global flag
   module: unknown | used_by: 2 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a06e0__FUN_004a06e0.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b97e0__FUN_004b97e0.c
363. DAT_008b8f18 — `, `DAT_008b8f1c`, `DAT_008b8f20`
   module: unknown | used_by: 2 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053c4d0__FUN_0053c4d0.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053b0d0__FUN_0053b0d0.c
364. DAT_0059e70c — ` — FFB minimum threshold
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e2760__FUN_004e2760.c
365. DAT_0059ea58 — /60/50/48 � Tire formula constants
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00430750__FUN_00430750.c
366. DAT_0059eef78 — � normalization factor
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004df110__FUN_004df110.c
367. DAT_0059f128 — ` — aero constant
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f0dd0__FUN_004f0dd0.c
368. DAT_005accf8 — final scale factor
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b3ce0__FUN_004b3ce0.c
369. DAT_005ad16c — `, `_DAT_005ad170` — track/camber factors
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e3d00__FUN_004e3d00.c
370. DAT_005ad360 — ..DAT_005ad3ec` â€” gain envelope curve data tables (X/Y pairs
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044ff50__FUN_0044ff50.c
371. DAT_005b897c — ` â€” FOV horizontal multiplier
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00542050__FUN_00542050.c
372. DAT_005c32a4 — registered
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00471750__FUN_00471750.c
373. DAT_005ccbc0 — , DAT_007ce238, DAT_005ccbb8, DAT_005ccbbc
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049d700__FUN_0049d700.c
374. DAT_005d8fa0 — ` — merge mask
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005289e0__FUN_005289e0.c
375. DAT_005dc164 — ` — unknown scaling factor (float [UNNAMED — needs .c analysis]
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005567e1__FUN_005567e1.c
376. DAT_005ebb20 — ` — zeroed
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00418db0__FUN_00418db0.c
377. DAT_007CA4B4 — ` — range/threshold constant (18000
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044ec60__FUN_0044ec60.c
378. DAT_007c7380 — ` / `DAT_007c7384` — indexed menu globals array
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004674e0__FUN_004674e0.c
379. DAT_007ca3d8 — ` â€” audio buffer/source objects identified by address
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044ff50__FUN_0044ff50.c
380. DAT_007ca4d0 — ` — collision object index/type
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d340__FUN_0044d340.c
381. DAT_007cca4c — ` — radius or sentinel value (-1.0f
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044c680__FUN_0044c680.c
382. DAT_007ccd38 — ` — node element count
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d400__FUN_0044d400.c
383. DAT_007cce6c — ` — grid state (zeroed
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044dc40__FUN_0044dc40.c
384. DAT_007ccf88 — ` — collision global, float = -1.0f
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044c980__FUN_0044c980.c
385. DAT_007cd164 — ` — float 1.0 (friction/restitution default
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044cce0__FUN_0044cce0.c
386. DAT_007cde20 — , DAT_007cde24 � surface 3 refs
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00494690__FUN_00494690.c
387. DAT_007ce838 — ` — damping enable flag
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00441ad0__FUN_00441ad0.c
388. DAT_007d00c8 — Data source pointer
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004734a0__FUN_004734a0.c
389. DAT_007d0f28 — ` — join timeout threshold
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004637a0__FUN_004637a0.c
390. DAT_007d2338 — `, `DAT_007d2410` â€” per-sample rate divisors
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044ff50__FUN_0044ff50.c
391. DAT_008ac3e8 — ` — .SCN file path buffer
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004c54f0__FUN_004c54f0.c
392. DAT_008ad2a0 — Event dispatch enable flag
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004082b0__FUN_004082b0.c
393. DAT_008b8dd4 — ` â€” screen dimensions (width/height ratio
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00542050__FUN_00542050.c
394. DAT_008d3e28 — ` — Window handle for async socket messages
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057c860__FUN_0057c860.c
395. DAT_008d45a0 — cleanup context data
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d328__Unwind_0059d328.c
396. DAT_007cea5c — EngineWearMode (0/2/3)
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
