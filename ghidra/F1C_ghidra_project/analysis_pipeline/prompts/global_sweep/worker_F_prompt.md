# WORKER F — F1C Global Variable Consolidation

You are building the comprehensive globals reference for F1 Challenge 99-02.
Worker F of 20.

## STEP 1 — LOAD REFERENCES

1. Read current globals reference:
   `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md`

2. Read the globals usage graph:
   `%USERPROFILE%\Desktop\F1C_ghidra_project\knowledge_graph\globals_usage.json`
   This has every global with its name (if known) and which functions use it.

## YOUR OUTPUT FILE

Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\global_sweep\worker_F.md

## YOUR GLOBALS (44)

221. DAT_007cd8c0 — ` — game command dispatch interface pointer
   module: unknown | used_by: 18 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00478200__FUN_00478200.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a0ad0__FUN_004a0ad0.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046fe50__FUN_0046fe50.c
222. DAT_007ce254 — ` � disable HUD flag
   module: unknown | used_by: 6 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x0049f870__FUN_0049f870.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a0e70__FUN_004a0e70.c, %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x0045d890__FUN_0045d890.c
223. DAT_007d0398 — � photo/free camera mode flag
   module: unknown | used_by: 4 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00466350__FUN_00466350.c, %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x0049f870__FUN_0049f870.c, %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x00460e90__FUN_00460e90.c
224. DAT_0059eb58 — ` — damper 2 rate coefficient
   module: unknown | used_by: 3 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0043e890__FUN_0043e890.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0043e980__FUN_0043e980.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0043eae0__FUN_0043eae0.c
225. DAT_007cddfc — ` — collision state counters/flags (all zeroed
   module: unknown | used_by: 3 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00494600__FUN_00494600.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00494de0__FUN_00494de0.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00494e60__FUN_00494e60.c
226. DAT_0059e868 — ` â€” steering response gain
   module: unknown | used_by: 2 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00426430__FUN_00426430.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00429fd0__FUN_00429fd0.c
227. DAT_005accb4 — ` — Scale factor for RGB10A2 encoding
   module: unknown | used_by: 2 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00509047__FUN_00509047.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00508f3d__FUN_00508f3d.c
228. DAT_005e6c80 — ` — global array of CRITICAL_SECTION pointers
   module: unknown | used_by: 2 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058dfea__FUN_0058dfea.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058e04b__FUN_0058e04b.c
229. DAT_007ca388 — ` — material property table (8 entries
   module: unknown | used_by: 2 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044a450__FUN_0044a450.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044aa30__FUN_0044aa30.c
230. DAT_007cf6a4 — `, `DAT_007cf6c8` — renderer camera scale factors
   module: unknown | used_by: 2 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00409970__FUN_00409970.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00409970__FUN_00409970.c
231. DAT_008b8e48 — audio channel count
   module: unknown | used_by: 2 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00556700__FUN_00556700.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005566d0__FUN_005566d0.c
232. DAT_0059e65c — ` — camera shake multiplier / conversion factor (docs/09, 19
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00409970__FUN_00409970.c
233. DAT_0059e9e4 — ` — force bias term
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f0f40__FUN_004f0f40.c
234. DAT_0059ed50 — ` — velocity damping factor
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00441d60__FUN_00441d60.c
235. DAT_0059f0c0 — ` / `DAT_0059e970` / `DAT_0059f124` � layout constants
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x0049f870__FUN_0049f870.c
236. DAT_005acca8 — , DAT_005acca4, DAT_005acca0 - clamp bounds
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b25d0__FUN_004b25d0.c
237. DAT_005ad — ### � amplitude, frequency, damping, and clamp constants
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004fd8b0__FUN_004fd8b0.c
238. DAT_005ad230 — ` — grip/multiplier for contact force
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f0f40__FUN_004f0f40.c
239. DAT_005b8968 — ` -- singularity threshold
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00566ee0__FUN_00566ee0.c
240. DAT_005c30b8 — /b4/b0/ac` — delimiter/separator character constants
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004236f0__FUN_004236f0.c
241. DAT_005cc9d8 — , DAT_005cc9d0, DAT_005cc9c8 � surface config data
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00494690__FUN_00494690.c
242. DAT_005d7814 — renderer function pointer
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050de19__FUN_0050de19.c
243. DAT_005d9260 — /c` â€” linear transform coefficients
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00528cc0__FUN_00528cc0.c
244. DAT_005ea608 — , DAT_005ea5f8, DAT_005ea5e8
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00414210__FUN_00414210.c
245. DAT_005f0f6c — ` — per-player scene data (stride 0x1230
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x0045fc50__FUN_0045fc50.c
246. DAT_007c5770 — ` — base of global array, stride 0x40, accessed via (a*11 + b
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004672c0__FUN_004672c0.c
247. DAT_007ca3c0 — ` — extended material table
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044a450__FUN_0044a450.c
248. DAT_007ca4b8 — ` — collision bucket/cell index (0x5e
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044ea20__FUN_0044ea20.c
249. DAT_007cca2c — ` — collision global, int count = 0x53
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e600__FUN_0044e600.c
250. DAT_007ccd0c — ` through `DAT_007ccd1c` — region parameters
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d580__FUN_0044d580.c
251. DAT_007cce54 — ` — collision system data block
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044de20__FUN_0044de20.c
252. DAT_007ccf70 — ` through `_DAT_007ccf7c` — collision configuration variables
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d160__FUN_0044d160.c
253. DAT_007cd144 — ` — max distance (27000
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e3c0__FUN_0044e3c0.c
254. DAT_007cde04 — , DAT_007cde08, DAT_007cde0c � surface 1 refs
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00494690__FUN_00494690.c
255. DAT_007ce73c — ` — referenced but not in docs/12
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00471540__FUN_00471540.c
256. DAT_007cfdc4 — Dispatch mode selector (0-3
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040d0b0__FUN_0040d0b0.c
257. DAT_007d0dcc — ` — alternate game filter path
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004c0db0__FUN_004c0db0.c
258. DAT_007d20f8 — `, `DAT_007d22f0`, `DAT_007d23a4`, `DAT_007d2434` â€” gain envelope curve selectors per channel
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044ff50__FUN_0044ff50.c
259. DAT_008ab708 — global pool/pre-allocated node
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b48e0__FUN_004b48e0.c
260. DAT_008ad254 — , DAT_008ad258 — state/flag pair
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d5c40__FUN_004d5c40.c
261. DAT_008b0324 — ` — codebook selector array (32 entries
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052e6f0__FUN_0052e6f0.c
262. DAT_008cef74 — � loaded resource 2
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00560340__FUN_00560340.c
263. DAT_008d43c8 — ` — locale management structure
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d1f8__Unwind_0059d1f8.c
264. DAT_005ec410 — LoadPath / directory pointer
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
