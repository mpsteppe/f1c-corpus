## Steward_Setup_004d36d0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Game_Setup (0042d5d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004d3740 | TimerFrameRateThrottle | R | [LLM] |
| 004d37b0 | TrackTemperatureDisplay | R | [LLM] |
| 005d3b6c | aDDevF119992002_3 | R | aDDevF119992002_3 [DERIVED] |
| 005d41d4 | aPitstop | R | [LLM] |
| 005d41dc | aTiming | R | String_Timing [DERIVED] |
| 005d41e4 | aVehicle | R | VehicleString [DERIVED] |
| 005d41ec | aEnteredSteward | R | EnteredStewardString [DERIVED] |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |
| 008afe64 | dword_8AFE64 | R | RaceTimeDelta [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d7a50 | StringSplitLoop | [LLM] |
| 004d7aa0 | DebugLogWrite | [LLM] |
| 005599d0 | sub_5599D0 | [LLM] |
| 00559a00 | sub_559A00 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
