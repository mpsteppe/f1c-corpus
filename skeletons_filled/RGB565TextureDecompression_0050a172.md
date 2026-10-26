## RGB565TextureDecompression_0050a172 — RGB565ToFloatRGBAWithAlphaDecoder

**Summary:** Decodes 16-bit packed RGB565 texture data to 32-bit float RGBA format, extracting 5-6-5 bit color channels and alpha from the upper 5 bits, with signed-channel expansion via sign-extension of 5/3 bit values, under DirectX texture system.

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
| 0059e9e0 | flt_59E9E0 | R | ColorChannelScaleFactor [DERIVED] |
| 005accdc | flt_5ACCDC | R | AlphaChannelScale [DERIVED] (also: ` — alpha channel scale factor) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00507845 | ContactManifoldCleanup | post-process decoded float RGBA buffer (likely alpha blend or edge fix) |

**Guard conditions:** If this[4] (offset +0x10 flag) is non-zero, calls ContactManifoldCleanup on the decoded output; if zero, skips post-processing.
