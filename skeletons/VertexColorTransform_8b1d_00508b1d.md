## VertexColorTransform_8b1d_00508b1d — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x2C | R | — | [LLM] |
| this | 0x1048 | R | — | [LLM] |
| this | 0x1058 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059eed0 | flt_59EED0 | R | BrightnessMultiplierRB [DERIVED] (also: ` — brightness multiplier for R/B channels) |
| 005accd8 | flt_5ACCD8 | R | DXT_GreenChannelScale [DERIVED] (also: ` — G channel scale factor (different precision) |
| 008b009c | dword_8B009C | R | ConversionState [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00506ce2 | DirectXVertexBufferFormatConversion | [LLM] |
| 00507473 | UtilityFunction_7473 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
