## PitExit_0041c0f0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CarSelectionStateMachine (00434460)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0041c3bc | jpt_41C243 | R | [LLM] |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e800 | flt_59E800 | R | AmplitudeLimit [DERIVED] (also: ` — under-relaxation upper bound) |
| 0059e838 | dbl_59E838 | R | PositionThreshold [DERIVED] |
| 005c329c | dword_5C329C | R | VehicleCount [FACT] (also: ` — VehicleCount (set to 0 on join) |
| 005ea618 | flt_5EA618 | R | PointerTableEntry [DERIVED] |
| 005f0738 | dword_5F0738 | R | VEH[0].0x4060 = position [CONFIRMED] |
| 005f0f74 | dword_5F0F74 | R | VEH[0].0x489C = DriverID [FACT] |
| 007c54e8 | dword_7C54E8 | R | PlayerVehiclePtr [FACT] |
| 007cf3c8 | flt_7CF3C8 | R | TrackConditionState [CONFIRMED] |
| 007d0308 | dword_7D0308 | R | RaceActiveFlag [FACT] |
| 007d0410 | dword_7D0410 | R | ChampionshipMode [FACT] (also: RaceMode) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004144d0 | StructInitWithSentinelValues | [LLM] |
| 004144f0 | DriverDataTableLookupAndTimeConversion | [LLM] |
| 00418560 | InsertDriverTableEntry | [LLM] |
| 005884ed | RandLCGRandomNumberGenerator | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
