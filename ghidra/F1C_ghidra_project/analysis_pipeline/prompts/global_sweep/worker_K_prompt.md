# WORKER K — F1C Global Variable Consolidation

You are building the comprehensive globals reference for F1 Challenge 99-02.
Worker K of 20.

## STEP 1 — LOAD REFERENCES

1. Read current globals reference:
   `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md`

2. Read the globals usage graph:
   `%USERPROFILE%\Desktop\F1C_ghidra_project\knowledge_graph\globals_usage.json`
   This has every global with its name (if known) and which functions use it.

## YOUR OUTPUT FILE

Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\global_sweep\worker_K.md

## YOUR GLOBALS (44)

441. DAT_008ac490 — SceneArray (stride 0x18c)
   module: unknown | used_by: 12 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040c3b0__FUN_0040c3b0.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c28d0__FUN_004c28d0.c, %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004c18b0__FUN_004c18b0.c
442. DAT_005accd4 — ` — Float scale factor for 5/6-bit channel decoding
   module: unknown | used_by: 5 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005098b7__FUN_005098b7.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00509959__FUN_00509959.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00509812__FUN_00509812.c
443. DAT_008b8e20 — ` â€” global linked list head (entry registry
   module: unknown | used_by: 4 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053cfe0__FUN_0053cfe0.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053d3a0__FUN_0053d3a0.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053d340__FUN_0053d340.c
444. DAT_005aceb8 — ` — constant offset in brush model
   module: unknown | used_by: 3 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e8010__FUN_004e8010.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e8b80__FUN_004e8b80.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ee2d0__FUN_004ee2d0.c
445. DAT_007d0fe8 — Global state (used via uint cast
   module: unknown | used_by: 3 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00461ed0__FUN_00461ed0.c, %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x00461de0__FUN_00461de0.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045d260__FUN_0045d260.c
446. DAT_0059e8d8 — `, `_DAT_0059e468`, `_DAT_0059e8d4` â€” speed thresholds for braking zone levels (0/1/2/3
   module: unknown | used_by: 2 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00426430__FUN_00426430.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00507ee4__FUN_00507ee4.c
447. DAT_005ad348 — ` — default value
   module: unknown | used_by: 2 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00500190__FUN_00500190.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005001d0__FUN_005001d0.c
448. DAT_005ea408 — ` — threshold
   module: unknown | used_by: 2 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c6d90__FUN_004c6d90.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049b6d0__FUN_0049b6d0.c
449. DAT_007ccbf4 — ` — grid size (37
   module: unknown | used_by: 2 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044cec0__FUN_0044cec0.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044ff50__FUN_0044ff50.c
450. DAT_007d0410 — RaceMode (4=?)
   module: unknown | used_by: 2 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004c2a80__FUN_004c2a80.c, %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004637a0__FUN_004637a0.c
451. DAT_008d3ebc — ` — error display flag
   module: unknown | used_by: 2 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058a2a6____amsg_exit.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058a2cb__FUN_0058a2cb.c
452. DAT_0059e778 — � angle-to-radians conversion (docs/18
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ee2d0__FUN_004ee2d0.c
453. DAT_0059eab8 — `, `DAT_0059eab0` — linear transform coefficients
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049f530__FUN_0049f530.c
454. DAT_0059ef08 — ` — output scale factor
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00447bb0__FUN_00447bb0.c
455. DAT_0059f204 — ` â€” low-speed threshold
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00466650__FUN_00466650.c
456. DAT_005acd64 — ` — global float constants
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b8c40__FUN_004b8c40.c
457. DAT_005ad178 — ` — caster angle threshold
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e3d00__FUN_004e3d00.c
458. DAT_005adb14 — ` — 360.0 (degree wrap
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050e9e6__FUN_0050e9e6.c
459. DAT_005b8d48 — , _DAT_005b8d50 � CRT heap boundary globals
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058bc68__FUN_0058bc68.c
460. DAT_005c3f6c — Lookup/config data
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00461ed0__FUN_00461ed0.c
461. DAT_005ccef0 — format string
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049e170__FUN_0049e170.c
462. DAT_005d8fe0 — ` etc. — polynomial coefficients
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005289e0__FUN_005289e0.c
463. DAT_005dc640 — � resource identifiers
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00560340__FUN_00560340.c
464. DAT_005ec408 — ` — override path pointer (docs/19
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044f540__FUN_0044f540.c
465. DAT_007CC9F8 — ` — material coefficient (1.0f
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044cfe0__FUN_0044cfe0.c
466. DAT_007c73e8 — `, `DAT_007c73f0`, `DAT_007c73f8`, `DAT_007c7404`, `_DAT_007c7408` to `_DAT_007c7424` — set to 0
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00431c00__FUN_00431c00.c
467. DAT_007ca40c — ` — region threshold (9000
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044ec00__FUN_0044ec00.c
468. DAT_007ca4e0 — ` — node element count
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044ea80__FUN_0044ea80.c
469. DAT_007ccbfc — ` — -1.0f sentinel
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044cec0__FUN_0044cec0.c
470. DAT_007ccd54 — ` through `_DAT_007ccd64` — collision bucket state (zeroed
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d3a0__FUN_0044d3a0.c
471. DAT_007cce8c — ` through `DAT_007cce9c` — region parameters
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044dd00__FUN_0044dd00.c
472. DAT_007cd01c — ` — collision object index/type
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e840__FUN_0044e840.c
473. DAT_007cd190 — ` — initialized to -1.0f (invalid/null index sentinel
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044cbc0__FUN_0044cbc0.c
474. DAT_007cde2c — ` — collision sound/event resource handles
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00494900__FUN_00494900.c
475. DAT_007ce874 — `, `DAT_007ce88c` — mode flags
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00438cc0__FUN_00438cc0.c
476. DAT_007d020c — ` — wet grip multiplier
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e8010__FUN_004e8010.c
477. DAT_007d1044 — ` — flags for message display
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x0045d890__FUN_0045d890.c
478. DAT_007d2410 — ` â€” per-sample rate divisors
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044ff50__FUN_0044ff50.c
479. DAT_008ac4cc — , DAT_008ac4d0, DAT_008ac4c4 — global singleton/manager pointers
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c8350__FUN_004c8350.c
480. DAT_008ad3ec — ` — sound/effect array
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e2230__FUN_004e2230.c
481. DAT_008b8e34 — ` — renderer state/flag mask (not in docs/12; likely renderer visibility or active-state mask
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00556930__FUN_00556930.c
482. DAT_008d3e90 — ` -- string table pointer
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005984aa__FUN_005984aa.c
483. DAT_008d4680 — 8c` — Global state buffer
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045d260__FUN_0045d260.c
484. DAT_007cf080 — WeatherMode (0-5)
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
