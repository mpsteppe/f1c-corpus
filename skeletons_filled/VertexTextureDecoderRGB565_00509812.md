## VertexTextureDecoderRGB565_00509812 — RGB565ToFloatRGBAVertexDecoder

**Summary:** Decodes 16-bit RGB565 packed texture data to 32-bit float RGBA format (alpha=1.0), using 5-6-5 bit channel extraction with per-channel scale factors, under DirectX texture system.

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
| 005accd4 | flt_5ACCD4 | R | ChannelDecodeScale [DERIVED] (also: ` — Float scale factor for 5/6-bit channel decoding) |
| 005accdc | flt_5ACCDC | R | AlphaChannelScale [DERIVED] (also: ` — alpha channel scale factor) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00507845 | ContactManifoldCleanup | post-process decoded float RGBA buffer (likely alpha blend or edge fix) |

**Guard conditions:** If this[4] (offset +0x10 flag) is non-zero, calls ContactManifoldCleanup on the decoded output; if zero, skips post-processing.
