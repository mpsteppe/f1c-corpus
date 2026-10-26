## PitTimer_004d2e50 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4D4580 (004d4580)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | [LLM] |
| this | 0xB0 | RW | 2139095039 | [LLM] |
| this | 0xB4 | RW | — | [LLM] |
| this | 0xC2 | RW | 1 | [LLM] |
| this | 0xD8 | RW | 2139095039 | [LLM] |
| this | 0xF4 | R | — | [LLM] |
| this | 0x104 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0xB0: [LLM: once/conditional? does external poke survive?]
- this 0xB4: [LLM: once/conditional? does external poke survive?]
- this 0xC2: [LLM: once/conditional? does external poke survive?]
- this 0xD8: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004d3490 | jpt_4D2E8B | R | [LLM] |
| 0059e420 | dbl_59E420 | R | BaseDoubleConstant [DERIVED] (also: ` (BaseDoubleConstant = 1.0) |
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e46c | flt_59E46C | R | TireSlipOffset [DERIVED] (also: ` — offset value) |
| 0059e478 | flt_59E478 | R | SteeringCenterBoost [DERIVED] |
| 0059e800 | flt_59E800 | R | AmplitudeLimit [DERIVED] (also: ` — under-relaxation upper bound) |
| 0059e808 | flt_59E808 | R | EngineTempThreshold [DERIVED] |
| 0059e80c | flt_59E80C | R | PitlaneTimeThreshold [DERIVED] |
| 0059e8d8 | flt_59E8D8 | R | BrakingSpeedThreshold3 [DERIVED] |
| 0059e968 | flt_59E968 | R | AIQualifyPushFrequency [DERIVED] |
| 0059e99c | flt_59E99C | R | PhysicsConversionFactor [DERIVED] (also: ` — conversion factor) |
| 0059f118 | flt_59F118 | R | RaceTimeThreshold [DERIVED] (also: ` — cell size constant (float) |
| 005acef8 | flt_5ACEF8 | R | Flt_5ACEF8_Render [DERIVED] |
| 005acefc | flt_5ACEFC | R | TrackSurfaceScale [DERIVED] |
| 005c329c | dword_5C329C | R | VehicleCount [FACT] (also: ` — VehicleCount (set to 0 on join) |
| 005d4194 | aSD02d02d | R | TimeFormatString [DERIVED] |
| 005d41a4 | aTimeRemaining | R | String_TimeRemaining [DERIVED] |
| 005d41b4 | a0001 | R | StrTimerDisplay [DERIVED] |
| 005d41bc | aTimeUntilPitCl | R | TimeUntilPitClosedField [DERIVED] |
| 005ea510 | dword_5EA510 | R | SessionManager [DERIVED] |
| 005eb978 | dword_5EB978 | R | GameStatePtrArray3 [DERIVED] |
| 005ec4c0 | byte_5EC4C0 | R | EmptyStringBuffer [DERIVED] |
| 005ec4cc | byte_5EC4CC | RW | MessageDisplayBuffer [DERIVED] (also: ` (byte_5EC4CC) |
| 007c54e8 | dword_7C54E8 | R | PlayerVehiclePtr [FACT] |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] |
| 007c569c | dword_7C569C | R | SessionType5 (5=server) [DERIVED] (also: ` — SessionType5 (guards dev logging) |
| 007c56a4 | dword_7C56A4 | R | SessionType [FACT] |
| 007c56a8 | dword_7C56A8 | R | RacePhase [CONFIRMED] (also: ` — race phase (8 = ?) |
| 007cd204 | dword_7CD204 | R | ResourceDispatch_007CD204 [DERIVED] |
| 007cd25c | dword_7CD25C | R | GameModuleManager [DERIVED] |
| 007cebf4 | dword_7CEBF4 | R | SessionRaceState [DERIVED] |
| 007cec30 | dword_7CEC30 | R | ReconPitOpen [DERIVED] |
| 007cec78 | byte_7CEC78 | R | PitTimerVisible [DERIVED] |
| 007ced8c | dword_7CED8C | R | UIRacePhaseFlag [DERIVED] |
| 007cee88 | dword_7CEE88 | R | SessionInitFlags [DERIVED] |
| 008afe98 | dbl_8AFE98 | R | ScoringDefaultReturn [DERIVED] (also: ` — default return value (float) |
| 008afea0 | dbl_8AFEA0 | R | SessionTime [DERIVED] (also: ` — current session time (passed to FUN_0040f300) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040cde0 | GameActionStateMachine | [LLM] |
| 0040d100 | GameStateBranchDispatch | [LLM] |
| 0040dd80 | ShortComputation_dd80 | [LLM] |
| 0040de60 | sub_40DE60 | [LLM] |
| 0040e170 | TickUpdateDispatch | [LLM] |
| 0041a500 | TimeBasedMessageChain | [LLM] |
| 0041a6b0 | DisplayMessage0x113 | [LLM] |
| 00423a00 | BinarySearchInStringTable | [LLM] |
| 0042d140 | sub_42D140 | [LLM] |
| 0045bd10 | TextLineWrappingAndRendering | [LLM] |
| 0045bde0 | ShortComputation_bde0 | [LLM] |
| 0045bdf0 | ShortComputation_bdf0 | [LLM] |
| 00461db0 | SessionStateCheckWrapper | [LLM] |
| 004bc9b0 | sub_4BC9B0 | [LLM] |
| 004d0ec0 | ArithmeticComparison_0ec0 | [LLM] |
| 004d11d0 | sub_4D11D0 | [LLM] |
| 004d1cd0 | SingleCallWrapper_1cd0 | [LLM] |
| 004d2210 | PitCloseTeamReadyCheck | [LLM] |
| 004d2e20 | ArithmeticComparison_2e20 | [LLM] |
| 0058815f | StringFormatWithBufferOverflowCheck | [LLM] |
| 0058957a | InterruptDispatch | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x0 | == | 2 | [LLM] |
| this | 0xF4 | == | 2 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
