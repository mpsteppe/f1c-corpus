## DirectXVertexBufferFormatConversion_00506ce2 — Vertex float format conversion (normalized ↔ signed)

**Summary:** Converts vertex float data between normalized [0..1] and signed [-1..1] coordinate ranges based on format codes in this[2] (dest) and this[1042] (source). Processes each vertex element with 16-byte stride. Returns output pointer this[1043]. Formats: 1=map to (val+1)*0.5, 2=map from val*2-1, 3=direct/passthrough.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_507079 (00507079), TemporaryStateWrapper (00507779), VertexColorFloatToByte (005078b5), TextureFloatTo32bitARGBPack (005079a1), ColorValuePackingWithScaledFloatInput (00507ac4), ColorVertexTransform (00507bc5), ConvertFloatColorTo16Bit (00507cc6), TextureEncode16Bit (00507dc7), TextureEncoderRGBA4444 (00507ee4), TextureEncode8BitDXTS3TCQuantization (00508007), ByteColorTransform (00508105), F_15BitTo16BitTextureDithering (005081ae), DXTColorEncoder (005082d1), TextureColorConvert10 (005083d2), Color565Transform (005084f5), VertexColorTransform (005085c5), FindNearestVertexWeight (005086dd), DXTColorEncoder_87a2 (005087a2), TextureEncode16BitMatrix (00508867), DXTColorEncoder_895d (0050895d), TextureFloatTo16bitPack (00508a48), VertexColorTransform_8b1d (00508b1d), FloatToByteColorConverter (00508c22), TextureColorCacheFill (00508d2d), TextureEncode16BitPair (00508e67), TextureEncoderRGB565 (00508f3d), TextureEncode32BitRGB10A2 (00509047), TextureColorSpaceTransform (0050917d), TextureColorGradient (00509244), FloatToByteColorConverter_930b (0050930b), VertexCoordinateTransformToScreen (005093f9), TextureEncoderRGBA8888Packed (005094e8), CopyTextureSurface (0050aeae)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | this[2] — dest format selector (1=normalized, 2=signed, 3=other) |
| this | 0x1048 | R | — | this[1042] — source format selector (1/2/3) for inner switch |
| this | 0x104C | R | — | this[1043] — output buffer pointer (returned) |
| this | 0x1058 | R | — | this[1046] — vertex count (loop bound) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] — float constant used in coordinate scale (0.5, 2.0) |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] — float constant for range conversion |
| 0059e800 | flt_59E800 | R | AmplitudeLimit [DERIVED] — float constant used in vertex transform |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x1048 | == | 3 | source format = direct/passthrough (case 3) |
| this | 0x1048 | == | 2 | source format = signed (-1..1, converted via *2-1) |
| this | 0x1048 | == | 1 | source format = normalized (0..1, converted via (val+1)*0.5) |

**Guard interpretation:** Switches on this[2] (dest format: 1/2/3), then inner switch on this[1042] (source format: 1/2/3). Only specific valid combos (1-2, 1-3, 2-1, 2-3, 3-1, 3-2) have code; invalid combos fall through with no conversion. PASS: valid combo → processes all vertices with format conversion. BLOCKED: invalid combo → no conversion, returns this[1043] unchanged.
