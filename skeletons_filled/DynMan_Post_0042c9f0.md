## DynMan_Post_0042c9f0 — DynMan_Post

**Summary:** Dynamic management post-race handler: processes AI random selection for all vehicles, initializes wheel dynamics, resets season scoring, destroys graphics resources.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Game_Post (0042da30)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c329c | dword_5C329C | R | VehicleCount [FACT] (also: ` — VehicleCount (set to 0 on join) |
| 005c3334 | aDDevF119992002_12 | R | sBuildPath [DERIVED] |
| 005c3498 | aEnteredDynmanP | R | StringEnteredDynManP [DERIVED] |
| 005ea560 | dword_5EA560 | R | GlobalInstance_5EA560 [CONFIRMED] |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] |
| 007c7428 | dbl_7C7428 | R | RaceTimeElapsed [DERIVED] |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0042bd60 | SeasonScoringReset | Reset season scoring state for all vehicles |
| 0043e230 | WheelDynamicsInit | Initialize wheel dynamics with race elapsed time |
| 004c6e80 | sub_4C6E80 | Process AI random selection reset for each vehicle |
| 004d7a50 | StringSplitLoop | Process build path string with delimiter and max length |
| 004d7aa0 | DebugLogWrite | Write debug log message to debug output buffer |

**Guard conditions:** StringSplitLoop returns 0: skip DebugLogWrite. VehicleCount == 0: skip per-vehicle AI processing loop. All other operations unconditional: wheel dynamics init, season scoring reset, graphics resource destruction.
