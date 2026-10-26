## FloatToShortClampedConversion_004b2750 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** VehicleOrientationFromEulerAngles (004b2dd0), sub_4B32A0 (004b32a0), SetupCarLightingAndRender (004c71c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x28 | RW | — | [LLM] |
| this | 0x2A | RW | 32767 | [LLM] |

**Written-by note (persistence):**
- this 0x28: [LLM: once/conditional? does external poke survive?]
- this 0x2A: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005accb4 | flt_5ACCB4 | R | RGB10A2QuantScale [DERIVED] (also: ` — Scale factor for RGB10A2 encoding) |
| 005accb8 | flt_5ACCB8 | R | ShortConversionClampLow [DERIVED] |
| 005accbc | flt_5ACCBC | R | FloatQuantizeUpperBound [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
