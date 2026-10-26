## VertexColorFloatToByte_005078b5 — FloatVertexColorToByte

**Summary:** Converts floating-point vertex colors to 8-bit byte values by multiplying by 255.0 and writing consecutive RGB bytes.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x2C | R | — | Vertex data base pointer offset |
| this | 0x1048 | R | — | Format conversion flag — if set, calls DirectXVertexBufferFormatConversion to transform vertex buffer format |
| this | 0x1058 | R | — | Vertex count — number of vertices to process |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059fec8 | flt_59FEC8 | R | AlphaChannelMultiplier [DERIVED] |
| 008b009c | dword_8B009C | R | ConversionState [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00506ce2 | DirectXVertexBufferFormatConversion | Transforms input vertex buffer format for compatibility |
| 00507473 | UtilityFunction_7473 | Unknown utility — called unconditionally before loop |

**Guard conditions:** checks this[1042] (0x1048) — if non-zero, calls DirectXVertexBufferFormatConversion before proceeding. Reads vertex count from this[1046] (0x1058) — if zero, for loop body skipped entirely, only utility call and return executed.
