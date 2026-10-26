## TextureDecodeRGB565_00509d34 — ARGB_3_3_2_8ToFloatRGBAConverter

**Summary:** Decodes 16-bit packed ARGB texture (first byte = RGB 3-3-2, second byte = alpha) to 32-bit float RGBA format, under DirectX texture system.

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
| 0059e460 | flt_59E460 | R | AlphaScaleFactor [DERIVED] |
| 0059e98c | flt_59E98C | R | AccelerationTuningFactor [DERIVED] (also: ` — acceleration tuning) |
| 005ad210 | flt_5AD210 | R | ThreeBitChannelScale [DERIVED] (also: ` — float multiplier for 3-bit channels) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00507845 | ContactManifoldCleanup | post-process decoded float RGBA buffer (likely alpha blend or edge fix) |

**Guard conditions:** If this[4] (offset +0x10 flag) is non-zero, calls ContactManifoldCleanup on the decoded output; if zero, skips post-processing.
