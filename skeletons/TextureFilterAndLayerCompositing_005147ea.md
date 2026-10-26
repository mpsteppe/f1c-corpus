## TextureFilterAndLayerCompositing_005147ea — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** FileIOWrapper (005152eb), QuantizationColorSpaceConversion (00515303), sub_515417 (00515417)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | [LLM] |
| this | 0x8 | R | — | [LLM] |
| this | 0xC | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e98c | flt_59E98C | R | AccelerationTuningFactor [DERIVED] (also: ` â€” acceleration tuning) |
| 0059e9e0 | flt_59E9E0 | R | ColorChannelScaleFactor [DERIVED] |
| 005accd0 | flt_5ACCD0 | R | RGBChannelScaleR [DERIVED] (also: ` — R/B channel scale factor (fixed-point multiplier) |
| 005accd4 | flt_5ACCD4 | R | ChannelDecodeScale [DERIVED] (also: ` — Float scale factor for 5/6-bit channel decoding) |
| 005accd8 | flt_5ACCD8 | R | DXT_GreenChannelScale [DERIVED] (also: ` — G channel scale factor (different precision) |
| 005accdc | flt_5ACCDC | R | AlphaChannelScale [DERIVED] (also: ` — alpha channel scale factor) |
| 005ad1f4 | flt_5AD1F4 | R | AudioLerpCoeff [DERIVED] |
| 005adb14 | flt_5ADB14 | R | DegreeWrap360 [DERIVED] (also: ` — 360.0 (degree wrap) |
| 005af618 | unk_5AF618 | R | ImagePaletteData [DERIVED] |
| 005af628 | unk_5AF628 | R | PNGDataBuffer [DERIVED] |
| 005af634 | flt_5AF634 | R | AudioFilterCoeff [DERIVED] |
| 005af638 | flt_5AF638 | R | AudioResampleCoeff2 [DERIVED] |
| 005af63c | flt_5AF63C | R | Flt_AudioResampleCoeff [DERIVED] |
| 005d79bc | flt_5D79BC | R | BVHMinBounds [DERIVED] |
| 005d79c0 | flt_5D79C0 | R | Audio3DPositionFloat [DERIVED] |
| 005d79c4 | flt_5D79C4 | R | RenderSurfaceScale [DERIVED] |
| 005d79cc | flt_5D79CC | R | Unknown_Float_Render [DERIVED] |
| 005d79d0 | flt_5D79D0 | R | TextureQuantScale [DERIVED] |
| 005d79d4 | flt_5D79D4 | R | TextureProcConstant [DERIVED] |
| 008b00a0 | dword_8B00A0 | R | FPUControlStore [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00513d63 | F_16BitColorToFloat4Decoder | [LLM] |
| 00513e5d | FPUControlWordMerger | [LLM] |
| 00513e80 | sub_513E80 | [LLM] |
| 0051427f | OBBFittingAndProjection | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
