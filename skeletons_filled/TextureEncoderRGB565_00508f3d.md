## TextureEncoderRGB565_00508f3d — FloatVertexColorToRGB32HighPrecision

**Summary:** Converts floating-point vertex colors to packed 32-bit format: R=10 bits (scale 512), G=11 bits (scale 1024), B=11 bits (scale 1024).

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
| 005accb4 | flt_5ACCB4 | R | RGB10A2QuantScale [DERIVED] (also: ` — Scale factor for RGB10A2 encoding) |
| 005acee4 | flt_5ACEE4 | R | G6B5ScaleFactor [DERIVED] |
| 008b009c | dword_8B009C | R | ConversionState [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00506ce2 | DirectXVertexBufferFormatConversion | Transforms input vertex buffer format for compatibility |
| 00507473 | UtilityFunction_7473 | Unknown utility — called unconditionally before loop |

**Guard conditions:** checks this[1042] (0x1048) — if non-zero, calls DirectXVertexBufferFormatConversion first. Reads vertex count from this[1046] (0x1058) — if zero, entire do-while loop body skipped.
