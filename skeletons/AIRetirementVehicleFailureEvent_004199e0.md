## AIRetirementVehicleFailureEvent_004199e0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** LapCompletion (004bc4e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4060 | R | — | position [CONFIRMED] |
| this | 0x40D0 | R | — | [LLM] |
| this | 0x40D4 | R | — | [LLM] |
| this | 0x4894 | R | — | [LLM] |
| this | 0x8130 | R | — | [LLM] |
| this | 0x8134 | R | — | [LLM] |
| this | 0x8138 | R | — | [LLM] |
| this | 0x896C | R | — | [LLM] |
| this | 0x8970 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00419c0c | jpt_419B98 | R | [LLM] |
| 00419c18 | byte_419C18 | R | [LLM] |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 005ea618 | flt_5EA618 | R | PointerTableEntry [DERIVED] |
| 007c54e0 | dword_7C54E0 | R | postProcessInput [CONFIRMED] (also: unknown (near PlayerVehiclePtr +0x8)) |
| 007c54e8 | dword_7C54E8 | R | PlayerVehiclePtr [FACT] |
| 007c56a4 | dword_7C56A4 | R | SessionType [FACT] |
| 007c56a8 | dword_7C56A8 | R | RacePhase [CONFIRMED] (also: ` — race phase (8 = ?) |
| 007ce234 | unk_7CE234 | R | DriverAppearanceFlag [DERIVED] |
| 007cf3c8 | flt_7CF3C8 | R | TrackConditionState [CONFIRMED] |
| 007d0308 | dword_7D0308 | R | RaceActiveFlag [FACT] |
| 008acf8c | dword_8ACF8C | R | TotalRaceLaps [CONFIRMED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004144d0 | StructInitWithSentinelValues | [LLM] |
| 004144f0 | DriverDataTableLookupAndTimeConversion | [LLM] |
| 00418560 | InsertDriverTableEntry | [LLM] |
| 0049b6d0 | LapTimeGapCalculation | [LLM] |
| 00587bdc | CRTFtol | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x8138 | != | 2 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
