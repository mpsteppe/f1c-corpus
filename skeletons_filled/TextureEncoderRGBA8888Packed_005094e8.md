## TextureEncoderRGBA8888Packed_005094e8 — FloatVertexColorToRGBA64Packed

**Summary:** Converts floating-point vertex colors to packed 64-bit format: all 4 channels scaled by 65535.0 (16-bit each), interleaved into a 64-bit quad word.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x18 | R | — | Output buffer base pointer |
| this | 0x2C | R | — | Bias data pointer offset — source for per-vertex bias float |
| this | 0x1048 | R | — | Format conversion flag — if set, calls DirectXVertexBufferFormatConversion before processing |
| this | 0x1050 | R | — | Stride for a2 dimension — byte stride for output buffer indexing |
| this | 0x1054 | R | — | Stride for a3 dimension — byte stride for output buffer indexing |
| this | 0x1058 | R | — | Vertex count — number of vertices to process (loop bound) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059f120 | flt_59F120 | R | IntensityMultiplier [DERIVED] |
| 008b009c | dword_8B009C | R | ConversionState [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00506ce2 | DirectXVertexBufferFormatConversion | Transforms input vertex buffer format for compatibility |
| 00507473 | UtilityFunction_7473 | Unknown utility — called unconditionally before loop |

**Guard conditions:** checks this[1042] (0x1048) — if non-zero, calls DirectXVertexBufferFormatConversion first. Reads vertex count from this[1046] (0x1058) — if zero, entire do-while loop body skipped.
