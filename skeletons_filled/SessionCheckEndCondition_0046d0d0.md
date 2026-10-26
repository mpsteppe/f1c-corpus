## SessionCheckEndCondition_0046d0d0 — Session end condition checker

**Summary:** Evaluates multiple session-end conditions (race completion, qualifying, vehicle state, timeout) and invokes a vtable callback with the result (1 = end session). Central decision function for session lifecycle.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x38 | R | — | vtable offset 56 — callback invoked with end-session boolean result |
| this | 0x0 | R | — | vtable pointer |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c329c | dword_5C329C | R | VehicleCount — number of vehicles in session |
| 007c54e8 | dword_7C54E8 | R | PlayerVehiclePtr — pointer to player's vehicle object |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray — array of vehicle pointers |
| 007c56a4 | dword_7C56A4 | R | SessionType — current session type (5 = race, 7 = qualifying, etc.) |
| 007c56a8 | dword_7C56A8 | R | RacePhase — race phase (5, 8 = active/ended phases) |
| 007cd25c | dword_7CD25C | R | GameModuleManager — passed to SessionStateCheckWrapper |
| 007ce814 | dword_7CE814 | R | QualifyingDSQEnabled — flag for qualifying DSQ (disqualification) |
| 007d0410 | dword_7D0410 | R | ChampionshipMode — 3 or 4 for certain championship modes |
| 008acee0 | dword_8ACEE0 | R | ForceFeedbackBase — passed to sub_4D24A0 |
| 008acf8c | dword_8ACF8C | R | TotalRaceLaps — total laps in race session |
| 008acf94 | flt_8ACF94 | R | RaceTimeThreshold — time threshold for session timeout |
| 008afea0 | dbl_8AFEA0 | R | SessionTime — current elapsed session time |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00461db0 | SessionStateCheckWrapper | checks session manager state; returns true if session should evaluate end |
| 004d24a0 | sub_4D24A0 | evaluates force-feedback/input condition for session end |

**Guard conditions:** Entry: sets v5=0 (don't end). First block: if (NOT QualifyingDSQEnabled AND sub_4D24A0 returns non-zero) OR (SessionType non-zero OR ChampionshipMode 3/4) AND vehicle field+16484==3 → BLOCKS further checks and sets v5=1 (end). SessionType==7 branch: if vehicle field+13000==0 AND field+16484 non-zero → BLOCKS to v5=1. SessionType==5 branch: if vehicle field+13000==0 AND NOT QualifyingDSQEnabled AND vehicle field+16444 >= TotalRaceLaps-1 → BLOCKS to v5=1. SessionStateCheckWrapper true path: if VehicleCount <=0 or all vehicles have field+13000 non-zero → BLOCKS to v5=1. Final: if RacePhase 8 or 5 AND RaceTimeThreshold < SessionTime → v5=1. Result passed to vtable callback at offset 56.
