## TextureColorSpaceTransform_0050917d — RGBToLuminance16

**Summary:** Converts float RGB to 16-bit luminance using BT.709 coefficients (0.2125 R + 0.7154 G + 0.0721 B), scaled by 65535.0, writing single 16-bit value per pixel.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x2C | R | — | Vertex data base pointer offset |
| this | 0x1048 | R | — | Format conversion flag — if set, calls DirectXVertexBufferFormatConversion before processing |
| this | 0x1058 | R | — | Vertex count — number of vertices to process (loop bound) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059f120 | flt_59F120 | R | IntensityMultiplier [DERIVED] |
| 005adb18 | flt_5ADB18 | R | SkinningDotCoeff0 [DERIVED] (also: /1c/20` — dot-product coefficients) |
| 005adb1c | flt_5ADB1C | R | BlendWeightChannel1 [DERIVED] (also: ` — channel 1 blend weight) |
| 005adb20 | flt_5ADB20 | R | ColorTransformChannel2Weight [DERIVED] (also: ` — channel 2 blend weight) |
| 008b009c | dword_8B009C | R | ConversionState [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00506ce2 | DirectXVertexBufferFormatConversion | Transforms input vertex buffer format for compatibility |
| 00507473 | UtilityFunction_7473 | Unknown utility — called unconditionally before loop |

**Guard conditions:** checks this[1042] (0x1048) — if non-zero, calls DirectXVertexBufferFormatConversion first. Reads vertex count from this[1046] (0x1058) — if zero, for loop body skipped entirely.
