## TimeBasedMessageChain_0041a500 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** PitTimer (004d2e50)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e808 | flt_59E808 | R | EngineTempThreshold [DERIVED] |
| 0059e80c | flt_59E80C | R | PitlaneTimeThreshold [DERIVED] |
| 0059e810 | flt_59E810 | R | LapTimeThreshold1 [DERIVED] |
| 0059e814 | flt_59E814 | R | OscillationMax [DERIVED] |
| 0059e818 | flt_59E818 | R | EngineRPMThreshold1 [DERIVED] |
| 0059e81c | flt_59E81C | R | LeadInPositionThreshold [DERIVED] |
| 005ea618 | flt_5EA618 | R | PointerTableEntry [DERIVED] |
| 005eb10c | dword_5EB10C | R | SoundSystemPtr [DERIVED] (also: ` — engine interface pointer) |
| 007cf3c8 | flt_7CF3C8 | R | TrackConditionState [CONFIRMED] |
| 007d0308 | dword_7D0308 | R | RaceActiveFlag [FACT] |
| 008afe98 | dbl_8AFE98 | R | ScoringDefaultReturn [DERIVED] (also: ` — default return value (float) |
| 008afea0 | dbl_8AFEA0 | R | SessionTime [DERIVED] (also: ` — current session time (passed to FUN_0040f300) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004144d0 | StructInitWithSentinelValues | [LLM] |
| 004144f0 | DriverDataTableLookupAndTimeConversion | [LLM] |
| 00418560 | InsertDriverTableEntry | [LLM] |
| 004186a0 | BufferInitWith10fDefaults | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
