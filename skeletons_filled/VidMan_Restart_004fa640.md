## VidMan_Restart_004fa640 — VidManRestartStateInit

**Summary:** Reinitializes video manager state on game restart — writes debug log, resets rendering mode flags per session type, resets session timer, axis dead zone, and render display list pointers.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Game_Restart (0042d7a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004fa7b8 | jpt_4FA689 | R | switch dispatch table for session type cases |
| 005d6dc4 | aDDevF119992002_26 | R | PathPrefix [DERIVED] |
| 005d6eb4 | aEnteredVidmanR | R | StringEnteredVidManR [DERIVED] |
| 005ea43c | dword_5EA43C | R | SetupDirSuffix [DERIVED] |
| 007c569c | dword_7C569C | R | SessionType5 (5=server) [DERIVED] (also: ` — SessionType5 (guards dev logging) |
| 007c56a4 | dword_7C56A4 | R | SessionType [FACT] |
| 007cd25c | dword_7CD25C | R | GameModuleManager [DERIVED] |
| 007ce254 | byte_7CE254 | R | DisableHUDFlag [CONFIRMED] |
| 008ab6e4 | dword_8AB6E4 | R | ScoringGate [CONFIRMED] |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |
| 008afca8 | dword_8AFCA8 | R | RenderDisplayListPtr [DERIVED] |
| 008afcac | dword_8AFCAC | R | Unknown_RaceDynamics_Value [DERIVED] |
| 008afe64 | dword_8AFE64 | R | RaceTimeDelta [DERIVED] |
| 008afe84 | dword_8AFE84 | W | Unknown_Race_DynamicsValue [DERIVED] |
| 008afea8 | dbl_8AFEA8 | W | InputAxisDeadZone [DERIVED] (also: ` â€” axis threshold (float) |
| 008afeac | byte_8AFEAC | W | Unknown_8AFEAC [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00404f10 | ConditionalFlagReturn | check if a flag/condition is set at given address |
| 0042d210 | sub_42D210 | set/clear some state variable at address |
| 00461db0 | SessionStateCheckWrapper | validate current session state |
| 004d7a50 | StringSplitLoop | format message string with path prefix |
| 004d7aa0 | DebugLogWrite | write debug log message |
| 004f8f10 | ConditionalInitBranch | conditionally initialize/relink render list pointer |
| 004f9f70 | GlobalFloatSetter | set a global float value (returns it) |
| 004f9fc0 | sub_4F9FC0 | reset session time and performance-counter timer |
| 0054a200 | GlobalFlagSetClear | set or clear a bit flag |

**Guard conditions:** StringSplitLoop returns 0 → skip debug log. dword_7C56A4 switch determines rendering flag (64/128/256) set/clear pattern. Case 6-7 sub-guard: dword_7C56A4==7 AND dword_8AB6E4!=2 AND ConditionalFlagReturn(&dword_5EA43C)==0 AND byte_7CE254!=0 AND SessionStateCheckWrapper==0 → call sub_42D210 with 1 (set additional state). Cases 0-5 always set flag 256=1; case 6-7 set flag 256=0.
