## DynMan_Restart_0042c3b0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Game_Restart (0042d7a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c329c | dword_5C329C | R | VehicleCount [FACT] (also: ` — VehicleCount (set to 0 on join) |
| 005c3334 | aDDevF119992002_12 | R | sBuildPath [DERIVED] |
| 005c338c | aEnteredDynmanR | R | s_DebugEnteredDynmanR [DERIVED] |
| 005ea560 | dword_5EA560 | R | GlobalInstance_5EA560 [CONFIRMED] |
| 007c54dc | dword_7C54DC | W | CurrentPlayerIndex [CONFIRMED] |
| 007c54e0 | dword_7C54E0 | W | postProcessInput [CONFIRMED] (also: unknown (near PlayerVehiclePtr +0x8)) |
| 007c54e4 | dword_7C54E4 | R | CurrentVehicleIndex [DERIVED] |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] |
| 007c5694 | dword_7C5694 | W | TimerOutputInt [DERIVED] (also: ` — timer/angle output global) |
| 007c5698 | dword_7C5698 | W | SessionTickCounter [DERIVED] |
| 007c73e8 | dword_7C73E8 | R | DeviceIdentityHandle1 [DERIVED] |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00410890 | BatchProcessWithFixedStartOffsets | [LLM] |
| 004333e0 | AISettingsFileLoader | [LLM] |
| 004c6d90 | SceneRenderUpdate | [LLM] |
| 004d7a50 | StringSplitLoop | [LLM] |
| 004d7aa0 | DebugLogWrite | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
