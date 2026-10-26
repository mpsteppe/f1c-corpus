## SessionConfigBuilder_00461610 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** WeatherSurfaceUpdate (004628a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x60 | RW | — | [LLM] |
| this | 0x64 | RW | — | [LLM] |
| this | 0x65 | RW | 0 | [LLM] |
| this | 0x66 | RW | — | [LLM] |
| this | 0x67 | RW | — | [LLM] |
| this | 0x68 | RW | — | [LLM] |
| this | 0x69 | RW | — | [LLM] |
| this | 0x6A | RW | — | [LLM] |
| this | 0x6B | RW | — | [LLM] |
| this | 0x6C | RW | — | [LLM] |
| this | 0x6D | RW | — | [LLM] |
| this | 0x74 | RW | — | [LLM] |
| this | 0x76 | RW | — | [LLM] |
| this | 0x78 | RW | — | [LLM] |
| this | 0x7A | RW | — | [LLM] |
| this | 0x7C | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x60: [LLM: once/conditional? does external poke survive?]
- this 0x64: [LLM: once/conditional? does external poke survive?]
- this 0x65: [LLM: once/conditional? does external poke survive?]
- this 0x66: [LLM: once/conditional? does external poke survive?]
- this 0x67: [LLM: once/conditional? does external poke survive?]
- this 0x68: [LLM: once/conditional? does external poke survive?]
- this 0x69: [LLM: once/conditional? does external poke survive?]
- this 0x6A: [LLM: once/conditional? does external poke survive?]
- this 0x6B: [LLM: once/conditional? does external poke survive?]
- this 0x6C: [LLM: once/conditional? does external poke survive?]
- this 0x6D: [LLM: once/conditional? does external poke survive?]
- this 0x74: [LLM: once/conditional? does external poke survive?]
- this 0x76: [LLM: once/conditional? does external poke survive?]
- this 0x78: [LLM: once/conditional? does external poke survive?]
- this 0x7A: [LLM: once/conditional? does external poke survive?]
- this 0x7C: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004618b4 | jpt_461818 | R | [LLM] |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e874 | flt_59E874 | R | AITurnInSpeedThreshold [DERIVED] |
| 0059f120 | flt_59F120 | R | IntensityMultiplier [DERIVED] |
| 007ce5d0 | dword_7CE5D0 | R | CurrentTrackPath [DERIVED] |
| 007ce874 | byte_7CE874 | R | InputModeFlag [DERIVED] |
| 007ce88c | byte_7CE88C | R | VehicleModeFlag [DERIVED] (also: ` — mode flags) |
| 007ce958 | dword_7CE958 | R | TireModelMode [DERIVED] |
| 007ce97c | byte_7CE97C | R | TireModelFlag [DERIVED] |
| 007ceb10 | dword_7CEB10 | R | RaceSetting_Flag1 [DERIVED] |
| 007cec30 | dword_7CEC30 | R | ReconPitOpen [DERIVED] |
| 007cec54 | dword_7CEC54 | R | ReconPitClosed [DERIVED] |
| 007ced44 | dword_7CED44 | R | Flag_DamageDisplay [DERIVED] |
| 007cee40 | dword_7CEE40 | R | ConfigFieldHandler [DERIVED] |
| 007cef3c | dword_7CEF3C | R | PenaltyConfigFlag [DERIVED] |
| 007cf038 | dword_7CF038 | R | OptionByte_7CF038 [DERIVED] |
| 007cf134 | dword_7CF134 | R | WeatherModeUI (0-5) [DERIVED] |
| 007d0014 | dword_7D0014 | R | updateGameLevels [CONFIRMED] (also: Setup_AIDriverSkill) |
| 007d0134 | dword_7D0134 | R | SessionOptionFlags [DERIVED] |
| 007d0434 | dword_7D0434 | R | SeasonPath [DERIVED] |
| 007d084c | flt_7D084C | R | UIPercentageSlider [DERIVED] |
| 007d0a44 | dword_7D0A44 | R | GameModePlayerCount [DERIVED] |
| 007d0c18 | dword_7D0C18 | R | OptionAutoReverse [DERIVED] |
| 007d0d14 | dword_7D0D14 | R | Flag_Unknown_d14 [DERIVED] |
| 007d0e50 | dword_7D0E50 | R | NetCommReadyFlag [DERIVED] (also: ` — readiness flag) |
| 007d0e98 | dword_7D0E98 | W | Unknown_Flag_7D0E98 [DERIVED] |
| 007d0ea0 | dword_7D0EA0 | R | NetworkSessionState [DERIVED] |
| 007d0ea4 | dword_7D0EA4 | R | UI_LapDisplayFlags [DERIVED] |
| 007d0f4c | dword_7D0F4C | R | Setup_OptionFlag_0F4C [DERIVED] |
| 007d0f70 | dword_7D0F70 | R | SessionConfigByte [DERIVED] |
| 007d0fc4 | dword_7D0FC4 | R | RaceSetupByte_0FC4 [DERIVED] |
| 007d108c | flt_7D108C | R | MinPenetrationLimit [DERIVED] |
| 008ac368 | unk_8AC368 | R | VehicleSetupBase [DERIVED] |
| 008ac48c | dword_8AC48C | R | CurrentSceneIndex [DERIVED] (also: ` — module list index) |
| 008ac490 | dword_8AC490 | R | SceneArray (stride 0x18c) [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00415c30 | NullSafePointerDereference | [LLM] |
| 004336d0 | SafeStringCopy | [LLM] |
| 004615c0 | UtilityFunction_15c0 | [LLM] |
| 004618d0 | ReversePathSearchForBackslash | [LLM] |
| 004c5690 | SceneDataParser | [LLM] |
| 00587dd0 | sub_587DD0 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
