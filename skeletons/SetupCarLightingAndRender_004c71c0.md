## SetupCarLightingAndRender_004c71c0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** PitTimingUpdate (004b7a90), TireTemperatureSimStep (004c77d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x73C | R | — | [LLM] |
| this | 0x105D | R | — | [LLM] |
| this | 0x1067 | R | — | [LLM] |
| this | 0x1069 | R | — | [LLM] |
| this | 0x344C | R | — | [LLM] |
| this | 0x357C | R | — | ThrottleFactor [CONFIRMED] |
| this | 0x3580 | R | — | [LLM] |
| this | 0x3584 | R | — | BrakeFactor [CONFIRMED] |
| this | 0x35BC | R | — | [LLM] |
| this | 0x39A0 | R | — | EngineRPM [CONFIRMED] |
| this | 0x39FC | R | — | CurrentGear [FACT] (also: gearNumber) |
| this | 0x4024 | R | — | [LLM] |
| this | 0x4028 | R | — | [LLM] |
| this | 0x4894 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e444 | flt_59E444 | R | FrameDelta [DERIVED] (also: ` — float 0.016667 (1/60, frame delta) |
| 007c54dc | dword_7C54DC | R | CurrentPlayerIndex [CONFIRMED] |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] |
| 008afea0 | dbl_8AFEA0 | R | SessionTime [DERIVED] (also: ` — current session time (passed to FUN_0040f300) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b2310 | sub_4B2310 | [LLM] |
| 004b2480 | UtilityFunction_2480 | [LLM] |
| 004b25d0 | FloatToFixedConversionWithClamp | [LLM] |
| 004b2750 | FloatToShortClampedConversion | [LLM] |
| 004b2840 | FloatToByteShortEncoding | [LLM] |
| 004b2930 | FloatToBitfieldPack | [LLM] |
| 004b29b0 | BitfieldInsert | [LLM] |
| 004b2a10 | ShortComputation_2a10 | [LLM] |
| 004b2a40 | FloatToBitfieldEncoder | [LLM] |
| 004b2aa0 | BitfieldSetClearByIndex | [LLM] |
| 004b2ae0 | sub_4B2AE0 | [LLM] |
| 004b2b10 | FunctionCallWrapper_2b10 | [LLM] |
| 004b2b60 | BitfieldSetter | [LLM] |
| 004b33b0 | ProgressBarEventEncode | [LLM] |
| 004c7c00 | Constant5 | [LLM] |
| 004e18c0 | SubsystemReadyQuery | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
