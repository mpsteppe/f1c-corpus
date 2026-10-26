## DynMan_Init_0042c1a0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Game_Init (0042d6b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e8a4 | flt_59E8A4 | R | ReverseGearThrottleMult [DERIVED] (also: ` â€” reverse gear throttle multiplier) |
| 0059e9d0 | flt_59E9D0 | R | Flt_59E9D0_Race [DERIVED] |
| 0059e9d4 | flt_59E9D4 | R | Flt_Physics_Const_E9D4 [DERIVED] |
| 005c329c | dword_5C329C | R | VehicleCount [FACT] (also: ` — VehicleCount (set to 0 on join) |
| 005c3334 | aDDevF119992002_12 | R | sBuildPath [DERIVED] |
| 005c3374 | aEnteredDynmanI | R | EnteredDynManIString [DERIVED] |
| 005ea560 | dword_5EA560 | R | GlobalInstance_5EA560 [CONFIRMED] |
| 005ef9a0 | dword_5EF9A0 | R | VEH[0].0x32C8 [LLM: field purpose] |
| 007c54e4 | dword_7C54E4 | R | CurrentVehicleIndex [DERIVED] |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] |
| 007c5690 | byte_7C5690 | R | InitStateFlag [DERIVED] |
| 007c56a4 | dword_7C56A4 | R | SessionType [FACT] |
| 007c73e0 | dword_7C73E0 | R | ModuleCallbackTable [DERIVED] |
| 007c73e8 | dword_7C73E8 | R | DeviceIdentityHandle1 [DERIVED] |
| 007c87a0 | dword_7C87A0 | R | SuspensionStatePtr [DERIVED] |
| 007ce498 | byte_7CE498 | R | AutoLoadConfigFile [DERIVED] |
| 007cebc4 | byte_7CEBC4 | R | FormationLap [DERIVED] |
| 007d0410 | dword_7D0410 | R | ChampionshipMode [FACT] (also: RaceMode) |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040fe50 | sub_40FE50 | [LLM] |
| 0042bbd0 | SetPlayerVehicleIndex | [LLM] |
| 0042bc40 | SetPlayerVehicleIndex_bc40 | [LLM] |
| 0042bc80 | BuildActiveVehiclePointerArray | [LLM] |
| 004326e0 | PlayerNameSetup | [LLM] |
| 004336f0 | LoadAIDriverNamesFromConfig | [LLM] |
| 004b1520 | sub_4B1520 | [LLM] |
| 004bfd90 | AIDriverCountSetup | [LLM] |
| 004bff70 | sub_4BFF70 | [LLM] |
| 004c01a0 | sub_4C01A0 | [LLM] |
| 004c6c40 | VehgenScnFileLoader | [LLM] |
| 004d7a50 | StringSplitLoop | [LLM] |
| 004d7aa0 | DebugLogWrite | [LLM] |
| 004f9480 | sub_4F9480 | [LLM] |
| 005895a2 | sub_5895A2 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
