## VertexTextureDecoder1010102_0050a3ce — RGB10A2SignedToFloatRGBAVertexDecoder

**Summary:** Decodes 32-bit packed RGB10A2 signed texture data to 32-bit float RGBA format, extracting 10-bit sign-extended color channels and setting alpha=1.0, under DirectX texture system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x10 | R | — | flag to enable post-processing step |
| this | 0x18 | R | — | pointer to source texture pixel data |
| this | 0x1050 | R | — | source row pitch (bytes per row) |
| this | 0x1054 | R | — | source slice stride (rows per image) |
| this | 0x1058 | R | — | number of pixels to decode |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e4d8 | flt_59E4D8 | R | physics constant [DERIVED] |
| 005acf38 | flt_5ACF38 | R | GBChannelScaleFactor [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00507845 | ContactManifoldCleanup | post-process decoded float RGBA buffer (likely alpha blend or edge fix) |

**Guard conditions:** If this[4] (offset +0x10 flag) is non-zero, calls ContactManifoldCleanup on the decoded output; if zero, skips post-processing.
