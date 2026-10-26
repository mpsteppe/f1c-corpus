## VertexColorPackRGBto16_0050a92d — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_50AB51 (0050ab51), DestructorWithResourceCleanup_b830 (0050b830)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x18 | R | — | [LLM] |
| this | 0x1050 | R | — | [LLM] |
| this | 0x1054 | R | — | [LLM] |
| this | 0x106C | R | — | [LLM] |
| this | 0x1070 | R | — | [LLM] |
| this | 0x1074 | R | — | [LLM] |
| this | 0x1078 | R | — | [LLM] |
| this | 0x107C | R | — | [LLM] |
| this | 0x1080 | R | — | [LLM] |
| this | 0x1084 | R | — | [LLM] |
| this | 0x108C | RW | 0 | [LLM] |
| this | 0x1090 | R | — | [LLM] |
| this | 0x1094 | R | — | [LLM] |
| this | 0x1098 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x108C: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 005adbf8 | flt_5ADBF8 | R | Render_ColorMatrix_DBF8 [DERIVED] |
| 005adbfc | flt_5ADBFC | R | LightAttenuationConst [DERIVED] |
| 005adc00 | flt_5ADC00 | R | ColorMatrixCol1 [DERIVED] |
| 005adc04 | flt_5ADC04 | R | ColorMatrixCoeff_04 [DERIVED] |
| 005adc08 | flt_5ADC08 | R | VertexMatrixCoeff [DERIVED] |
| 005adc0c | flt_5ADC0C | R | ColorMatrixCoeff [DERIVED] |
| 005adc10 | flt_5ADC10 | R | VertexColorMatrixCoeff [DERIVED] |
| 005adc14 | flt_5ADC14 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
