## AIBehaviorInitialization_004bf0a0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** AIOvertake (004beb10)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x34C | R | — | [LLM] |
| this | 0x354 | RW | — | [LLM] |
| this | 0x358 | RW | — | [LLM] |
| this | 0x35C | R | — | [LLM] |
| this | 0x360 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x354: [LLM: once/conditional? does external poke survive?]
- this 0x358: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004bf380 | jpt_4BF119 | R | [LLM] |
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 005acdb0 | dword_5ACDB0 | R | SessionScoringParameter [DERIVED] |
| 005acde0 | flt_5ACDE0 | R | AIDifficultyScaler [DERIVED] |
| 005c329c | dword_5C329C | R | VehicleCount [FACT] (also: ` — VehicleCount (set to 0 on join) |
| 005ea3fc | flt_5EA3FC | R | TrackRefSpeed [DERIVED] (also: ` â€” waypoint accumulation weight) |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] |
| 007c56a4 | dword_7C56A4 | R | SessionType [FACT] |
| 007ce5ec | dword_7CE5EC | R | SettingsFilePath [DERIVED] |
| 007cea5c | dword_7CEA5C | R | EngineWearMode (0/2/3) [DERIVED] |
| 007d01a0 | dword_7D01A0 | R | AIDifficultySlider [CONFIRMED] |
| 008ab6e4 | dword_8AB6E4 | R | ScoringGate [CONFIRMED] |
| 008acf90 | flt_8ACF90 | R | RaceTimeOffset [DERIVED] |
| 008acf9c | flt_8ACF9C | R | TotalRaceLaps [DERIVED] |
| 008afea0 | dbl_8AFEA0 | R | SessionTime [DERIVED] (also: ` — current session time (passed to FUN_0040f300) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0042ae90 | StateFlagsLookup | [LLM] |
| 004ba140 | ArithmeticComparison_a140 | [LLM] |
| 004be760 | sub_4BE760 | [LLM] |
| 004be9e0 | AnimationStateSetter | [LLM] |
| 004bea10 | RandomVariationScaler | [LLM] |
| 004bf390 | AIDriverSorting | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
