# WORKER D — F1C Global Variable Consolidation

You are building the comprehensive globals reference for F1 Challenge 99-02.
Worker D of 20.

## STEP 1 — LOAD REFERENCES

1. Read current globals reference:
   `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md`

2. Read the globals usage graph:
   `%USERPROFILE%\Desktop\F1C_ghidra_project\knowledge_graph\globals_usage.json`
   This has every global with its name (if known) and which functions use it.

## YOUR OUTPUT FILE

Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\global_sweep\worker_D.md

## YOUR GLOBALS (44)

133. DAT_008afea0 — ` — current session time (passed to FUN_0040f300
   module: unknown | used_by: 19 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00411120__FUN_00411120.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a0ba0__FUN_004a0ba0.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ef4f0__FUN_004ef4f0.c
134. DAT_0059e6fc — ` — RGB channel multiplier (~255.0
   module: unknown | used_by: 6 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00508c22__FUN_00508c22.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00508d2d__FUN_00508d2d.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00508a48__FUN_00508a48.c
135. DAT_007c54e8 — ` � PlayerVehiclePtr
   module: unknown | used_by: 4 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004b7de0__FUN_004b7de0.c, %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004a2a90__FUN_004a2a90.c, %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004c2a80__FUN_004c2a80.c
136. DAT_0059eae0 — ` — infinity/FLT_MAX return value
   module: unknown | used_by: 3 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004352c0__FUN_004352c0.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005085c5__FUN_005085c5.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d5ea0__FUN_004d5ea0.c
137. DAT_007cd2b8 — ` / `DAT_007cd470` — array bases
   module: unknown | used_by: 3 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046c7b0__FUN_0046c7b0.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046c750__FUN_0046c750.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046cb00__FUN_0046cb00.c
138. DAT_0059e7fc — ` — bump damping constants
   module: unknown | used_by: 2 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e3d00__FUN_004e3d00.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048c170__FUN_0048c170.c
139. DAT_0059f124 — ` � layout constants
   module: unknown | used_by: 2 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x0049f870__FUN_0049f870.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004636a0__FUN_004636a0.c
140. DAT_005e5238 — ` — Tire traction constant squared
   module: unknown | used_by: 2 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0043e050__FUN_0043e050.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0056a390__FUN_0056a390.c
141. DAT_007c7404 — `, `_DAT_007c7408` to `_DAT_007c7424` — set to 0
   module: unknown | used_by: 2 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00431c00__FUN_00431c00.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00431c70__FUN_00431c70.c
142. DAT_007ce2e8 — ` — conditional flag
   module: unknown | used_by: 2 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a1b70__FUN_004a1b70.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a1da0__FUN_004a1da0.c
143. DAT_008b5a3c — ` — entry array base (stride 0x84
   module: unknown | used_by: 2 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053c6f0__FUN_0053c6f0.c, %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053c900__FUN_0053c900.c
144. DAT_0059e4e4 — Small epsilon/prevent-division-by-zero (~0.0f
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00405f80__FUN_00405f80.c
145. DAT_0059e9b0 — ` — conversion multiplier
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0042bda0__FUN_0042bda0.c
146. DAT_0059ed40 — ` — speed error gain
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00441ad0__FUN_00441ad0.c
147. DAT_0059f0b4 — ` — initial open flag value
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x004612e0__FUN_004612e0.c
148. DAT_005acca0 — clamp bounds
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b25d0__FUN_004b25d0.c
149. DAT_005acf50 — ` — text render param
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dba00__FUN_004dba00.c
150. DAT_005ad228 — , _DAT_005ad224, _DAT_005ad220 � brake force thresholds
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ee2d0__FUN_004ee2d0.c
151. DAT_005b05c8 — Source data table
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051e512__FUN_0051e512.c
152. DAT_005bf9a4 — ` (DriverDataTable + 4
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004144f0__FUN_004144f0.c
153. DAT_005cc9c8 — � surface config data
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00494690__FUN_00494690.c
154. DAT_005d77e4 — ` — function pointer (indirect jump target
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050c2b3__thunk_FUN_0050c2a6.c
155. DAT_005d9210 — /c` â€” linear transform offsets
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00528cc0__FUN_00528cc0.c
156. DAT_005ea5e8 — None [UNNAMED — needs .c analysis]
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00414210__FUN_00414210.c
157. DAT_005f0774 — ` — shared network data buffer (stride 0x1230
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\decompiled_all\0x0045d890__FUN_0045d890.c
158. DAT_007c5694 — ` — timer/angle output global
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0042bda0__FUN_0042bda0.c
159. DAT_007ca36c — ` — extended response table
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044a450__FUN_0044a450.c
160. DAT_007ca490 — ` — collision cell initial count (1
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044c620__FUN_0044c620.c
161. DAT_007cc9fc — `...`DAT_007cca10` — collision system data block
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e5a0__FUN_0044e5a0.c
162. DAT_007cccec — ` — grid state (zeroed
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d4c0__FUN_0044d4c0.c
163. DAT_007cce3c — ` — collision globals, zeroed
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044de80__FUN_0044de80.c
164. DAT_007ccf60 — ` — collision global, int = 0x6b
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d100__FUN_0044d100.c
165. DAT_007cd134 — `–`_DAT_007cd140` — grid state (zeroed
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e3c0__FUN_0044e3c0.c
166. DAT_007cd9cc — ` — pool descriptor pointer
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004906e0__FUN_004906e0.c
167. DAT_007ce6f4 — ` to `DAT_007ce7a8` — 11 byte brake/diff settings
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00438cc0__FUN_00438cc0.c
168. DAT_007cf788 — enable flag
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d8880__FUN_004d8880.c
169. DAT_007d0ad4 — ` — global float offset
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00411330__FUN_00411330.c
170. DAT_007d2068 — ` â€” independent left/right channel mute flags
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044ff50__FUN_0044ff50.c
171. DAT_008aae74 — ` — lookup table, 256 floats
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00447ab0__FUN_00447ab0.c
172. DAT_008acfec — ` — count (not in docs/12
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d7b00__FUN_004d7b00.c
173. DAT_008b0124 — ` — decoded sample workspace (32 floats
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052e6f0__FUN_0052e6f0.c
174. DAT_008c5f40 — ` — set from FUN_0054f710
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054f7a0__FUN_0054f7a0.c
175. DAT_008d42d8 — ` — cleanup descriptor/type info block
   module: unknown | used_by: 1 functions
   sample .c files: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059af17__FUN_0059af17.c
176. DAT_005bf9b0 — DriverDataTable
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
