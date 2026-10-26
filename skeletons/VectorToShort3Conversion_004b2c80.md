## VectorToShort3Conversion_004b2c80 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** EntityVisibilityGridManager (00465460)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x9 | RW | — | [LLM] |
| this | 0xB | RW | — | [LLM] |
| this | 0xD | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x9: [LLM: once/conditional? does external poke survive?]
- this 0xB: [LLM: once/conditional? does external poke survive?]
- this 0xD: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e708 | flt_59E708 | R | SoundVolumeLowThreshold [DERIVED] (also: ` — low threshold) |
| 0059e70c | flt_59E70C | R | FFBMinThreshold [DERIVED] (also: ` — FFB minimum threshold) |
| 0059e710 | flt_59E710 | R | FFB_SaturationThreshold [DERIVED] (also: ` — FFB maximum threshold) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b21f0 | FloatToRGBColorConversion | [LLM] |
| 004b2580 | ShortVectorToFloatWithScale | [LLM] |
| 004b2980 | BitfieldExtractScale | [LLM] |
| 004b29f0 | ShortComputation_29f0 | [LLM] |
| 004b2b90 | FloatThresholdClassification | [LLM] |
| 004b2c20 | BitfieldUpdateFromFloat | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
