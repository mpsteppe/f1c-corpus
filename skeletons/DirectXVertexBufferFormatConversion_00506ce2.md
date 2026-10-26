## DirectXVertexBufferFormatConversion_00506ce2 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_507079 (00507079), TemporaryStateWrapper (00507779), VertexColorFloatToByte (005078b5), TextureFloatTo32bitARGBPack (005079a1), ColorValuePackingWithScaledFloatInput (00507ac4), ColorVertexTransform (00507bc5), ConvertFloatColorTo16Bit (00507cc6), TextureEncode16Bit (00507dc7), TextureEncoderRGBA4444 (00507ee4), TextureEncode8BitDXTS3TCQuantization (00508007), ByteColorTransform (00508105), F_15BitTo16BitTextureDithering (005081ae), DXTColorEncoder (005082d1), TextureColorConvert10 (005083d2), Color565Transform (005084f5), VertexColorTransform (005085c5), FindNearestVertexWeight (005086dd), DXTColorEncoder_87a2 (005087a2), TextureEncode16BitMatrix (00508867), DXTColorEncoder_895d (0050895d), TextureFloatTo16bitPack (00508a48), VertexColorTransform_8b1d (00508b1d), FloatToByteColorConverter (00508c22), TextureColorCacheFill (00508d2d), TextureEncode16BitPair (00508e67), TextureEncoderRGB565 (00508f3d), TextureEncode32BitRGB10A2 (00509047), TextureColorSpaceTransform (0050917d), TextureColorGradient (00509244), FloatToByteColorConverter_930b (0050930b), VertexCoordinateTransformToScreen (005093f9), TextureEncoderRGBA8888Packed (005094e8), CopyTextureSurface (0050aeae)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | [LLM] |
| this | 0x1048 | R | — | [LLM] |
| this | 0x104C | R | — | [LLM] |
| this | 0x1058 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e800 | flt_59E800 | R | AmplitudeLimit [DERIVED] (also: ` — under-relaxation upper bound) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x1048 | == | 3 | [LLM] |
| this | 0x1048 | == | 2 | [LLM] |
| this | 0x1048 | == | 1 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
