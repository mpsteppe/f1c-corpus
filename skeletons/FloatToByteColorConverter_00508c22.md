## FloatToByteColorConverter_00508c22 — [LLM: short descriptive name]

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
| 0059e6fc | flt_59E6FC | R | RGBChannelMultiplier [DERIVED] (also: ` — RGB channel multiplier (~255.0) |
| 0059fec8 | flt_59FEC8 | R | AlphaChannelMultiplier [DERIVED] |
| 008b009c | dword_8B009C | R | ConversionState [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00506ce2 | DirectXVertexBufferFormatConversion | [LLM] |
| 00507473 | UtilityFunction_7473 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
