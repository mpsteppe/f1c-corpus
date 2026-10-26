## SessionConfigWriteback_00461900 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ClientGridDisplayTimer (00460380), AutoJoinRetryLoop (004637a0), GameMode (0046d6d0), MultiplayerSessionJoinHandler (0046de10)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x60 | R | — | [LLM] |
| this | 0x64 | R | — | [LLM] |
| this | 0x66 | R | — | [LLM] |
| this | 0x67 | R | — | [LLM] |
| this | 0x68 | R | — | [LLM] |
| this | 0x69 | R | — | [LLM] |
| this | 0x6A | R | — | [LLM] |
| this | 0x6B | R | — | [LLM] |
| this | 0x6C | R | — | [LLM] |
| this | 0x6D | R | — | [LLM] |
| this | 0x74 | R | — | [LLM] |
| this | 0x76 | R | — | [LLM] |
| this | 0x78 | R | — | [LLM] |
| this | 0x7A | R | — | [LLM] |
| this | 0x7C | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e600 | flt_59E600 | R | SteeringForceThreshold [DERIVED] |
| 007ce498 | byte_7CE498 | R | AutoLoadConfigFile [DERIVED] |
| 007ce874 | byte_7CE874 | RW | InputModeFlag [DERIVED] |
| 007ce876 | byte_7CE876 | R | Byte_WeatherFlag [DERIVED] |
| 007ce877 | byte_7CE877 | R | SessionConfigFlagByte [DERIVED] |
| 007ce88c | byte_7CE88C | RW | VehicleModeFlag [DERIVED] (also: ` — mode flags) |
| 007ce88e | byte_7CE88E | R | AudioConfigFlag [DERIVED] |
| 007ce88f | byte_7CE88F | R | ConfigBitFlag [DERIVED] |
| 007ce958 | dword_7CE958 | RW | TireModelMode [DERIVED] |
| 007ce960 | dword_7CE960 | R | ConfigFieldName_7CE960 [DERIVED] |
| 007ce964 | dword_7CE964 | R | TireModelModeTarget [DERIVED] |
| 007ce97c | byte_7CE97C | RW | TireModelFlag [DERIVED] |
| 007ce97e | byte_7CE97E | R | Setup_ExtraFlag2 [DERIVED] |
| 007ce97f | byte_7CE97F | R | TireModelOptionByte [DERIVED] |
| 007ceb10 | dword_7CEB10 | RW | RaceSetting_Flag1 [DERIVED] |
| 007ceb18 | dword_7CEB18 | R | RaceSetupParam [DERIVED] |
| 007ceb1c | dword_7CEB1C | R | ReconSettings_e1c [DERIVED] |
| 007cec30 | dword_7CEC30 | RW | ReconPitOpen [DERIVED] |
| 007cec38 | dword_7CEC38 | R | PitWindowTimerConfig [DERIVED] |
| 007cec3c | dword_7CEC3C | R | PitWindowTimer [DERIVED] |
| 007cec54 | dword_7CEC54 | RW | ReconPitClosed [DERIVED] |
| 007cec5c | dword_7CEC5C | R | NetSessionTimeout [DERIVED] |
| 007cec60 | dword_7CEC60 | R | PitWindowClosedTimer [DERIVED] |
| 007ced44 | dword_7CED44 | RW | Flag_DamageDisplay [DERIVED] |
| 007ced4c | dword_7CED4C | R | RaceSetupParam2 [DERIVED] |
| 007ced50 | dword_7CED50 | R | SessionInitFlags [DERIVED] |
| 007cee40 | dword_7CEE40 | RW | ConfigFieldHandler [DERIVED] |
| 007cee48 | dword_7CEE48 | R | Config_FlagDWORD_02 [DERIVED] |
| 007cee4c | dword_7CEE4C | R | Setup_Option_7CEE4C [DERIVED] |
| 007cef3c | dword_7CEF3C | RW | PenaltyConfigFlag [DERIVED] |
| 007cef44 | dword_7CEF44 | R | Unknown_Flag_7CEF44 [DERIVED] |
| 007cef48 | dword_7CEF48 | R | PenaltyTimeThreshold [DERIVED] |
| 007cf038 | dword_7CF038 | RW | OptionByte_7CF038 [DERIVED] |
| 007cf040 | dword_7CF040 | R | Unknown_Flag_7CF040 [DERIVED] |
| 007cf044 | dword_7CF044 | R | Flag7CF044 [DERIVED] |
| 007cf134 | dword_7CF134 | RW | WeatherModeUI (0-5) [DERIVED] |
| 007cf13c | dword_7CF13C | R | Config_FlagDWORD_01 [DERIVED] |
| 007cf140 | dword_7CF140 | R | Weather_Config_7CF140 [DERIVED] |
| 007d0014 | dword_7D0014 | RW | updateGameLevels [CONFIRMED] (also: Setup_AIDriverSkill) |
| 007d001c | dword_7D001C | R | SessionConfigField [DERIVED] |
| 007d0020 | dword_7D0020 | R | [LLM] |
| 007d0134 | dword_7D0134 | RW | SessionOptionFlags [DERIVED] |
| 007d013c | dword_7D013C | R | SessionConfigValue_7D013C [DERIVED] |
| 007d0140 | dword_7D0140 | R | Dword_GameOptions [DERIVED] |
| 007d084c | flt_7D084C | RW | UIPercentageSlider [DERIVED] |
| 007d0854 | flt_7D0854 | R | WeatherModeConfig [DERIVED] |
| 007d0858 | flt_7D0858 | R | ServerAddressParam [DERIVED] |
| 007d0a44 | dword_7D0A44 | RW | GameModePlayerCount [DERIVED] |
| 007d0a4c | dword_7D0A4C | R | RaceModeIndex [DERIVED] |
| 007d0a50 | dword_7D0A50 | R | TimeAccelSetting [DERIVED] |
| 007d0c18 | dword_7D0C18 | RW | OptionAutoReverse [DERIVED] |
| 007d0c20 | dword_7D0C20 | R | ConfigFieldName_7D0C20 [DERIVED] |
| 007d0c24 | dword_7D0C24 | R | TireWearMultTarget [DERIVED] |
| 007d0d14 | dword_7D0D14 | RW | Flag_Unknown_d14 [DERIVED] |
| 007d0d1c | dword_7D0D1C | R | GameOptionConfigValue [DERIVED] |
| 007d0d20 | dword_7D0D20 | R | Setup_MaxVehicles [DERIVED] |
| 007d0ebc | dword_7D0EBC | RW | Int_RaceSetupFuelStrat [DERIVED] |
| 007d0ec4 | dword_7D0EC4 | R | SessionConfigValue_7D0EC4 [DERIVED] |
| 007d0ec8 | dword_7D0EC8 | R | OptionFlagBuffer [DERIVED] |
| 007d0f4c | dword_7D0F4C | RW | Setup_OptionFlag_0F4C [DERIVED] |
| 007d0f54 | dword_7D0F54 | R | NetQualifyingTime [DERIVED] |
| 007d0f58 | dword_7D0F58 | R | PitWindowTimer [DERIVED] |
| 007d0fc4 | dword_7D0FC4 | RW | RaceSetupByte_0FC4 [DERIVED] |
| 007d0fcc | dword_7D0FCC | R | PlayerConfigOption [DERIVED] |
| 007d0fd0 | dword_7D0FD0 | R | [LLM] |
| 007d108c | flt_7D108C | RW | MinPenetrationLimit [DERIVED] |
| 007d1094 | flt_7D1094 | R | SessionConfigFloatPair [DERIVED] |
| 007d1098 | flt_7D1098 | R | Flt_7D1098_pair [DERIVED] |
| 008ac368 | unk_8AC368 | R | VehicleSetupBase [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004615f0 | BitFlagTestAt0x6E | [LLM] |
| 004646c0 | FloatClamp | [LLM] |
| 00464720 | ByteClamp | [LLM] |
| 0047f1f0 | ClampByRange | [LLM] |
| 004b0ef0 | sub_4B0EF0 | [LLM] |
| 004b1410 | NameCompareAndFormat | [LLM] |
| 004c54f0 | AIW | [LLM] |
| 004c5690 | SceneDataParser | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
