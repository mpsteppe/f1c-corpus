## TextureEncode8BitDXTS3TCQuantization_00508007 — FloatVertexColorToRGB332

**Summary:** Converts floating-point vertex colors to packed 8-bit RGB332 format (R=3 bits, G=3 bits, B=2 bits) using scale factors 7.0 for R/G and 3.0 for B.

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
| 0059e478 | flt_59E478 | R | SteeringCenterBoost [DERIVED] |
| 0059e864 | flt_59E864 | R | ColorQuantScale [DERIVED] (also: ` — Quantization scale for color channels) |
| 008b009c | dword_8B009C | R | ConversionState [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00506ce2 | DirectXVertexBufferFormatConversion | Transforms input vertex buffer format for compatibility |
| 00507473 | UtilityFunction_7473 | Unknown utility — called unconditionally before loop |

**Guard conditions:** checks this[1042] (0x1048) — if non-zero, calls DirectXVertexBufferFormatConversion first. Reads vertex count from this[1046] (0x1058) — if zero, entire do-while loop body skipped.
