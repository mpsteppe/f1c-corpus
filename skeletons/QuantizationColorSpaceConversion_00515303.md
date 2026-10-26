## QuantizationColorSpaceConversion_00515303 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DelegationWithErrorCheck (005158af)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 0 | [LLM] |
| this | 0x4 | W | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: once/conditional? does external poke survive?]
- this 0x4: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e8d8 | flt_59E8D8 | R | BrakingSpeedThreshold3 [DERIVED] |
| 0059e9e0 | flt_59E9E0 | R | ColorChannelScaleFactor [DERIVED] |
| 005ac108 | flt_5AC108 | R | TexDecompress_1_15th [DERIVED] (also: ` — 4-bit color scale factor (1/15 ≈ 0.0667) |
| 005adb14 | flt_5ADB14 | R | DegreeWrap360 [DERIVED] (also: ` — 360.0 (degree wrap) |
| 005af634 | flt_5AF634 | R | AudioFilterCoeff [DERIVED] |
| 005af638 | flt_5AF638 | R | AudioResampleCoeff2 [DERIVED] |
| 005af63c | flt_5AF63C | R | Flt_AudioResampleCoeff [DERIVED] |
| 008b00a0 | dword_8B00A0 | R | FPUControlStore [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00513e5d | FPUControlWordMerger | [LLM] |
| 005147ea | TextureFilterAndLayerCompositing | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
