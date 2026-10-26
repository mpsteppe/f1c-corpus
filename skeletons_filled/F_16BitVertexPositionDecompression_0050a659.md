## F_16BitVertexPositionDecompression_0050a659 — Uint16_3DToFloatRGBAVertexDecoder

**Summary:** Decompresses 48-bit vertex position data (three uint16 values packed in 6 bytes per vertex) to 32-bit float RGBA format (XYZ positions, alpha=1.0), under DirectX vertex/texture system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x10 | R | — | flag to enable post-processing step |
| this | 0x18 | R | — | pointer to source vertex data |
| this | 0x1050 | R | — | source row pitch (bytes per row) |
| this | 0x1054 | R | — | source slice stride (rows per image) |
| this | 0x1058 | R | — | number of vertices to decode |
| this | 0x1064 | R | — | total source byte count (loop end offset) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ad290 | flt_5AD290 | R | LuminanceDecodeScale [DERIVED] (also: ` — Float scale factor for luminance decoding) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00507845 | ContactManifoldCleanup | post-process decoded float RGBA buffer (likely alpha blend or edge fix) |

**Guard conditions:** If this[4] (offset +0x10 flag) is non-zero, calls ContactManifoldCleanup on the decoded output; if zero, skips post-processing.
