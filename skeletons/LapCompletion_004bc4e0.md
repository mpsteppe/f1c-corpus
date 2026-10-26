## LapCompletion_004bc4e0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4B3400 (004b3400), LapSplitTimeEvent (004bc390)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x32C8 | R | — | [LLM] |
| obj | 0x344C | R | — | [LLM] |
| obj | 0x4894 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x4 | R | — | [LLM] |
| this | 0x8 | RW | — | [LLM] |
| this | 0xC | RW | 0 | [LLM] |
| this | 0x18 | RW | — | [LLM] |
| this | 0x1C | R | — | [LLM] |
| this | 0x20 | R | — | [LLM] |
| this | 0x30 | RW | — | [LLM] |
| this | 0x3C | R | — | [LLM] |
| this | 0x40 | RW | 0 | [LLM] |
| this | 0x44 | R | — | [LLM] |
| this | 0x60 | RW | — | [LLM] |
| this | 0x64 | RW | — | [LLM] |
| this | 0x68 | RW | — | [LLM] |
| this | 0x74 | RW | — | [LLM] |
| this | 0x78 | RW | — | [LLM] |
| this | 0x7C | RW | — | [LLM] |
| this | 0x80 | RW | — | [LLM] |
| this | 0x84 | RW | — | [LLM] |
| this | 0x88 | R | — | [LLM] |
| this | 0x8C | R | — | [LLM] |
| this | 0x90 | R | — | [LLM] |
| this | 0x94 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x8: [LLM: once/conditional? does external poke survive?]
- this 0xC: [LLM: once/conditional? does external poke survive?]
- this 0x18: [LLM: once/conditional? does external poke survive?]
- this 0x30: [LLM: once/conditional? does external poke survive?]
- this 0x40: [LLM: once/conditional? does external poke survive?]
- this 0x60: [LLM: once/conditional? does external poke survive?]
- this 0x64: [LLM: once/conditional? does external poke survive?]
- this 0x68: [LLM: once/conditional? does external poke survive?]
- this 0x74: [LLM: once/conditional? does external poke survive?]
- this 0x78: [LLM: once/conditional? does external poke survive?]
- this 0x7C: [LLM: once/conditional? does external poke survive?]
- this 0x80: [LLM: once/conditional? does external poke survive?]
- this 0x84: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004bc984 | jpt_4BC612 | R | [LLM] |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 005c2730 | aIgnoredStopGoP | R | aIgnoredStopGoPenalty [DERIVED] |
| 005c32fc | aLaps_1 | R | LapsLabel [DERIVED] |
| 005c3778 | aDS | R | aDS [DERIVED] |
| 005eb978 | dword_5EB978 | R | GameStatePtrArray3 [DERIVED] |
| 005ec4c0 | byte_5EC4C0 | R | EmptyStringBuffer [DERIVED] |
| 005ec4cc | byte_5EC4CC | RW | MessageDisplayBuffer [DERIVED] (also: ` (byte_5EC4CC) |
| 007c54e4 | dword_7C54E4 | R | CurrentVehicleIndex [DERIVED] |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] |
| 007c569c | dword_7C569C | R | SessionType5 (5=server) [DERIVED] (also: ` — SessionType5 (guards dev logging) |
| 007c56a4 | dword_7C56A4 | R | SessionType [FACT] |
| 007c56a8 | dword_7C56A8 | R | RacePhase [CONFIRMED] (also: ` — race phase (8 = ?) |
| 007ce24c | unk_7CE24C | R | CriticalSection [DERIVED] (also: ` — Session data object) |
| 007ce814 | dword_7CE814 | R | QualifyingDSQEnabled [DERIVED] |
| 008acee0 | dword_8ACEE0 | R | ForceFeedbackBase [CONFIRMED] |
| 008acf8c | dword_8ACF8C | R | TotalRaceLaps [CONFIRMED] |
| 008acf90 | flt_8ACF90 | R | RaceTimeOffset [DERIVED] |
| 008acf94 | flt_8ACF94 | R | RaceTimeThreshold [CONFIRMED] |
| 008acfa0 | byte_8ACFA0 | RW | HalfDistanceFlag [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00419500 | AICornerSpeedComparison | [LLM] |
| 004199e0 | AIRetirementVehicleFailureEvent | [LLM] |
| 0041a8c0 | AISessionEventAudio | [LLM] |
| 00423a00 | BinarySearchInStringTable | [LLM] |
| 0042d140 | sub_42D140 | [LLM] |
| 004a0b20 | sub_4A0B20 | [LLM] |
| 004a0ba0 | RaceFinishHandler | [LLM] |
| 004a0c60 | SessionMenuModeSwitch | [LLM] |
| 004a6d50 | sub_4A6D50 | [LLM] |
| 004bc0e0 | DisqualificationHandler | [LLM] |
| 004bc240 | sub_4BC240 | [LLM] |
| 004d1bc0 | PitStopOrderRank | [LLM] |
| 004d1c40 | sub_4D1C40 | [LLM] |
| 0058815f | StringFormatWithBufferOverflowCheck | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| obj | 0x32C8 | <= | 1 | [LLM] |
| obj | 0x32C8 | == | 3 | [LLM] |
| this | 0xC | == | 1 | [LLM] |
| this | 0x30 | != | 3 | [LLM] |
| this | 0x30 | == | 1 | [LLM] |
| this | 0x3C | > | 0 | [LLM] |
| this | 0x40 | != | 1 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
