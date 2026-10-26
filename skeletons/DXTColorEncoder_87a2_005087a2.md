## DXTColorEncoder_87a2_005087a2 — [LLM: short descriptive name]

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
| 0059fec8 | flt_59FEC8 | R | AlphaChannelMultiplier [DERIVED] |
| 005adb18 | flt_5ADB18 | R | SkinningDotCoeff0 [DERIVED] (also: /1c/20` — dot-product coefficients) |
| 005adb1c | flt_5ADB1C | R | BlendWeightChannel1 [DERIVED] (also: ` — channel 1 blend weight) |
| 005adb20 | flt_5ADB20 | R | ColorTransformChannel2Weight [DERIVED] (also: ` — channel 2 blend weight) |
| 008b009c | dword_8B009C | R | ConversionState [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00506ce2 | DirectXVertexBufferFormatConversion | [LLM] |
| 00507473 | UtilityFunction_7473 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
