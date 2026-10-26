# WORKER E — F1C Global Variable Consolidation

You are building the comprehensive globals reference for F1 Challenge 99-02.
Worker E of 20.

## STEP 1 — LOAD REFERENCES

1. Read current globals reference:
   `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md`

2. Read the globals usage graph:
   `%USERPROFILE%\Desktop\F1C_ghidra_project\knowledge_graph\globals_usage.json`
   This has every global with its name (if known) and which functions use it.

## YOUR OUTPUT FILE

Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\global_sweep\worker_E.md

## YOUR GLOBALS (44)

177. DAT_0059e430 — ` — NaN/zero sentinel
   module: unknown | used_by: 18 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005438b0__FUN_005438b0.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00449000__FUN_00449000.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044ba40__FUN_0044ba40.c
178. DAT_005be704 — ` — UI/text handle
   module: unknown | used_by: 6 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004715d0__FUN_004715d0.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004733a0__FUN_004733a0.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004716d0__FUN_004716d0.c
179. DAT_007ce260 — ` -- init guard flag
   module: unknown | used_by: 4 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045d500__FUN_0045d500.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a0dc0__FUN_004a0dc0.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a0fb0__FUN_004a0fb0.c
180. DAT_0059eb28 — ` — damper 2 max add (range limit
   module: unknown | used_by: 3 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0043e890__FUN_0043e890.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0043e980__FUN_0043e980.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0043eae0__FUN_0043eae0.c
181. DAT_007cddf0 — ` through `_DAT_007cddfc` — collision state counters/flags (all zeroed
   module: unknown | used_by: 3 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00494600__FUN_00494600.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00494de0__FUN_00494de0.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00494e60__FUN_00494e60.c
182. DAT_0059e864 — ` — Quantization scale for color channels
   module: unknown | used_by: 2 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00508007__FUN_00508007.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005081ae__FUN_005081ae.c
183. DAT_005acafc — ` — additive offset
   module: unknown | used_by: 2 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ed810__FUN_004ed810.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049f530__FUN_0049f530.c
184. DAT_005e5240 — ` — Tire traction constant (computed
   module: unknown | used_by: 2 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0043e050__FUN_0043e050.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0056a390__FUN_0056a390.c
185. DAT_007c7418 — ` — set to 0
   module: unknown | used_by: 2 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00431c00__FUN_00431c00.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00431c70__FUN_00431c70.c
186. DAT_007ce958 — TireModelMode
   module: unknown | used_by: 2 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0043e050__FUN_0043e050.c, %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004dfce0__FUN_004dfce0.c
187. DAT_008b6ac4 — undocumented global, gates flag manipulation
   module: unknown | used_by: 2 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005504d0__FUN_005504d0.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00551fb0__FUN_00551fb0.c
188. DAT_0059e4e8 — ` — physics/math scaling constant
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00406060__FUN_00406060.c
189. DAT_0059e9b8 — ` — float, ~1.0f (scale factor for remainder computation
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00567700__FUN_00567700.c
190. DAT_0059ed48 — ` — reference speed (double
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00441ad0__FUN_00441ad0.c
191. DAT_0059f0b8 — ` — float constants (timeout/default
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x00464290__FUN_00464290.c
192. DAT_005acca4 — , DAT_005acca0 - clamp bounds
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b25d0__FUN_004b25d0.c
193. DAT_005acf54 — ` — text render param
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dba00__FUN_004dba00.c
194. DAT_005ad22c — ` — clamp lower threshold
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f0dd0__FUN_004f0dd0.c
195. DAT_005b666c — ` — coefficient table base for audio mixing
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00531830__FUN_00531830.c
196. DAT_005c2aac — ` — backslash character (docs/08 path_util.cpp
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045ce30__FUN_0045ce30.c
197. DAT_005cc9d0 — , DAT_005cc9c8 � surface config data
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00494690__FUN_00494690.c
198. DAT_005d7810 — renderer function pointer
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050d0af__FUN_0050d0af.c
199. DAT_005d9250 — ..c` â€” delta correction coefficients
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00528cc0__FUN_00528cc0.c
200. DAT_005ea5f8 — , DAT_005ea5e8
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00414210__FUN_00414210.c
201. DAT_005f0cf8 — ` — player name array (stride 0x48c0
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x0045fc50__FUN_0045fc50.c
202. DAT_007c56a8 — ` — race phase (8 = ?
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004bc4e0__FUN_004bc4e0.c
203. DAT_007ca3b8 — `, `DAT_007cc9bc`, `DAT_007cd158`, `DAT_007ca50c`, `DAT_007cd0f8`, `DAT_007ca438`, `DAT_007ca448`, `DAT_007ccbf4`, `DAT_007ca3a8`, `DAT_007ca480`, `DAT_007cc9ec`, `DAT_007ca3d8` â€” audio buffer/source objects identified by address
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044ff50__FUN_0044ff50.c
204. DAT_007ca49c — ` — collision cell scale (1.0f
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044c620__FUN_0044c620.c
205. DAT_007cca10 — ` — collision system data block
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e5a0__FUN_0044e5a0.c
206. DAT_007ccd08 — ` — region type (18
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d580__FUN_0044d580.c
207. DAT_007cce40 — `...`_DAT_007cce54` — collision system data block
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044de20__FUN_0044de20.c
208. DAT_007ccf68 — ` — collision global, float = -1.0f
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d100__FUN_0044d100.c
209. DAT_007cd140 — ` — grid state (zeroed
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e3c0__FUN_0044e3c0.c
210. DAT_007cd9d0 — ` — allocator handle
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004906e0__FUN_004906e0.c
211. DAT_007ce718 — referenced by field 199
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00471750__FUN_00471750.c
212. DAT_007cfbb4 — , PTR_DAT_005be704, DAT_005c32c8
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00473e50__FUN_00473e50.c
213. DAT_007d0c60 — TireWearMultiplier
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004dfce0__FUN_004dfce0.c
214. DAT_007d208c — `, `DAT_007d2284`, `DAT_007d2338`, `DAT_007d2410` â€” per-sample rate divisors
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044ff50__FUN_0044ff50.c
215. DAT_008ab274 — � random noise table (docs/12
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004cc970__FUN_004cc970.c
216. DAT_008acff0 — ` — data array base (not in docs/12
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d7b00__FUN_004d7b00.c
217. DAT_008b0224 — ` — VLC decoded values workspace
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052e6f0__FUN_0052e6f0.c
218. DAT_008c5f44 — ` — UI focus flag (cleared
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054f7a0__FUN_0054f7a0.c
219. DAT_008d4330 — ` — static type descriptor used in MSVC exception handling data
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d1c8__Unwind_0059d1c8.c
220. DAT_005ea3d8 — DAT_005ea3d8 (track ref speed)
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
