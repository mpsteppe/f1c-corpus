## KeyframeQuadInterpolationWithBitPackedSelector_00514fee — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_51512C (0051512c), sub_5151AF (005151af)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | [LLM] |
| this | 0x4 | RW | — | [LLM] |
| this | 0x8 | RW | — | [LLM] |
| this | 0xC | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: once/conditional? does external poke survive?]
- this 0x4: [LLM: once/conditional? does external poke survive?]
- this 0x8: [LLM: once/conditional? does external poke survive?]
- this 0xC: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e98c | flt_59E98C | R | AccelerationTuningFactor [DERIVED] (also: ` â€” acceleration tuning) |
| 005ad1f4 | flt_5AD1F4 | R | AudioLerpCoeff [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00513d63 | F_16BitColorToFloat4Decoder | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
