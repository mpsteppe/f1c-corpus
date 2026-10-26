## FloatToFixedConversionWithClamp_004b25d0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** VehicleOrientationFromEulerAngles (004b2dd0), sub_4B32A0 (004b32a0), SetupCarLightingAndRender (004c71c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x24 | RW | — | [LLM] |
| this | 0x25 | RW | 127 | [LLM] |
| this | 0x26 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x24: [LLM: once/conditional? does external poke survive?]
- this 0x25: [LLM: once/conditional? does external poke survive?]
- this 0x26: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e8ec | flt_59E8EC | R | SpeedDeadzone [DERIVED] |
| 0059e91c | flt_59E91C | R | ShortConversionMult [DERIVED] (also: conversion multipliers) |
| 005acca0 | flt_5ACCA0 | R | ClampLowerBound [DERIVED] (also: clamp bounds) |
| 005acca4 | flt_5ACCA4 | R | ClampUpper_ColorB [DERIVED] |
| 005acca8 | flt_5ACCA8 | R | NormalClampLower [DERIVED] |
| 005accac | flt_5ACCAC | R | NormalClampUpper [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
