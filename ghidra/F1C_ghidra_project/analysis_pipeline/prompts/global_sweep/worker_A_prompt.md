# WORKER A — F1C Global Variable Consolidation

You are building the comprehensive globals reference for F1 Challenge 99-02.
Worker A of 20.

## STEP 1 — LOAD REFERENCES

1. Read current globals reference:
   `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md`

2. Read the globals usage graph:
   `%USERPROFILE%\Desktop\F1C_ghidra_project\knowledge_graph\globals_usage.json`
   This has every global with its name (if known) and which functions use it.

## YOUR OUTPUT FILE

Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\global_sweep\worker_A.md

## YOUR GLOBALS (44)

1. DAT_0059e440 — ZeroThreshold (~0.0f, physics clamp)
   module: unknown | used_by: 79 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040c070__FUN_0040c070.c, %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x0049f870__FUN_0049f870.c, %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004b7de0__FUN_004b7de0.c
2. DAT_0059e98c — ` â€” acceleration tuning
   module: unknown | used_by: 7 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00466650__FUN_00466650.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050a488__FUN_0050a488.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00509c20__FUN_00509c20.c
3. DAT_005accdc — ` — alpha channel scale factor
   module: unknown | used_by: 4 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050a172__FUN_0050a172.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00509812__FUN_00509812.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00513d63__FUN_00513d63.c
4. DAT_0059e8cc — ` — wheel speed threshold (not in docs/12
   module: unknown | used_by: 3 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00426330__FUN_00426330.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004cc970__FUN_004cc970.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00429fd0__FUN_00429fd0.c
5. DAT_005ea438 — unknown directory/file path [UNNAMED — needs .c analysis]
   module: unknown | used_by: 3 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044f540__FUN_0044f540.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048e4b0__FUN_0048e4b0.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dcf80__FUN_004dcf80.c
6. DAT_0059e708 — ` — low threshold
   module: unknown | used_by: 2 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e2230__FUN_004e2230.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e2760__FUN_004e2760.c
7. DAT_0059f07c — ` — rendering context/parameter
   module: unknown | used_by: 2 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045bd10__FUN_0045bd10.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045b480__FUN_0045b480.c
8. DAT_005c5d28 — SeasonRacesSuffix2
   module: unknown | used_by: 2 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004c5ae0__FUN_004c5ae0.c, %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x00460a10__FUN_00460a10.c
9. DAT_007c56a0 — ` — multiplayer flags
   module: unknown | used_by: 2 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004fe060__FUN_004fe060.c, %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004637a0__FUN_004637a0.c
10. DAT_007cde1c — ` -- subsystem instance pointer
   module: unknown | used_by: 2 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00495060__FUN_00495060.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00494690__FUN_00494690.c
11. DAT_008afe6c — ` — current index
   module: unknown | used_by: 2 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f9160__FUN_004f9160.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f9240__FUN_004f9240.c
12. DAT_0059e458 — ` — constraint force threshold (near-zero
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00454250__FUN_00454250.c
13. DAT_0059e8e0 — ` â€” waypoint reacquire distance threshold
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00426430__FUN_00426430.c
14. DAT_0059ece0 — ` — double threshold constant for lifetime clamp
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00447280__FUN_00447280.c
15. DAT_0059f078 — ` — penalty scale factor
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045be00__FUN_0045be00.c
16. DAT_005acb58 — `, `_DAT_005acd64` — global float constants
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b8c40__FUN_004b8c40.c
17. DAT_005acee8 — ` — front/rear distribution weight
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e8010__FUN_004e8010.c
18. DAT_005ad21c — , _DAT_005ad218, _DAT_005ad214 � brake force ramp thresholds
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ee2d0__FUN_004ee2d0.c
19. DAT_005af904 — ` — SIMD constant (high word
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00524553__FUN_00524553.c
20. DAT_005be83c — serialization constant
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004056a0__FUN_004056a0.c
21. DAT_005c7530 — ` — not in docs/12; used as base pointer for global data struct
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d948__FUN_0059d948.c
22. DAT_005d3214 — ` — "Abbreviation" section name constant
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004c6a10__FUN_004c6a10.c
23. DAT_005d91d0 — ..c` â€” selection combine masks
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00528cc0__FUN_00528cc0.c
24. DAT_005ea440 — ` — static buffer/handle
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00404fe0__FUN_00404fe0.c
25. DAT_005f0708 — ` — config array, stride 0x48c0 per session
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00463d10__FUN_00463d10.c
26. DAT_007CD464 — ` — collision sentinel (-1
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00465fd0__FUN_00465fd0.c
27. DAT_007c9174 — `, `DAT_007c919c` — parameter base values (case-dependent
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049f530__FUN_0049f530.c
28. DAT_007ca478 — ` — -1.0f sentinel
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044c740__FUN_0044c740.c
29. DAT_007cc4c8 — ` -- check flag
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b8ae0__FUN_004b8ae0.c
30. DAT_007cccd4 — ` — collision system data block
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d6a0__FUN_0044d6a0.c
31. DAT_007ccddc — ` — 5 zeroed fields
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d940__FUN_0044d940.c
32. DAT_007ccf14 — ` — collision bucket state (zeroed
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044db20__FUN_0044db20.c
33. DAT_007cd0c4 — ` — max search distance (9000
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e300__FUN_0044e300.c
34. DAT_007cd614 — ` — current collision config version
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00475d30__FUN_00475d30.c
35. DAT_007ce64c — ` — game filter data path
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004c0db0__FUN_004c0db0.c
36. DAT_007cf680 — ` — camera center/target position
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00409970__FUN_00409970.c
37. DAT_007d0434 — SeasonPath
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x00460a10__FUN_00460a10.c
38. DAT_007d1fd8 — ` â€” flag for race-mode audio (higher gain heads
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044ff50__FUN_0044ff50.c
39. DAT_008B6AC0 — ` — global physics object count
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053ce40__FUN_0053ce40.c
40. DAT_008acedc — � particle index counter (wraps at 0x80
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004cc970__FUN_004cc970.c
41. DAT_008aff00 — ` — session ready flag
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x0045d890__FUN_0045d890.c
42. DAT_008b8f30 — ` — temp file read buffer
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00550ad0__FUN_00550ad0.c
43. DAT_008d41e4 — � global exception handler function pointer
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005972bd__FUN_005972bd.c
44. DAT_008d7220 — , DAT_008d7228 — additional constant vectors
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00534120__FUN_00534120.c

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
