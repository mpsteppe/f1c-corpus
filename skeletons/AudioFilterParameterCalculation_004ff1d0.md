## AudioFilterParameterCalculation_004ff1d0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** PitRaceStatusMessageDispatcher (0041be60)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x38)+0xC) | 0xC | R | — | [LLM] |
| *(this+0x38) | 0x0 | R | — | [LLM] |
| *(this+0x38) | 0x8 | R | — | [LLM] |
| this | 0x20 | R | — | [LLM] |
| this | 0x24 | R | — | [LLM] |
| this | 0x38 | R | — | [LLM] |
| this | 0x104 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 005ad338 | flt_5AD338 | R | UI_ScrollRange [DERIVED] |
| 005ad33c | flt_5AD33C | R | SessionTypeFloatSelect [DERIVED] |
| 007c56a4 | dword_7C56A4 | R | SessionType [FACT] |
| 008afea0 | dbl_8AFEA0 | R | SessionTime [DERIVED] (also: ` — current session time (passed to FUN_0040f300) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004feaa0 | ThresholdBasedReturn | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
