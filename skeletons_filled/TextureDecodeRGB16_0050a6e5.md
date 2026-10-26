## TextureDecodeRGB16_0050a6e5 — RGBA16PackedToFloatRGBAConverter

**Summary:** Decodes 128-bit packed RGBA texture data (four uint16 values per pixel in 8 bytes) to 32-bit float RGBA format using sub_58A870 for channel decoding, under DirectX texture system.

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
| 005ad290 | flt_5AD290 | R | LuminanceDecodeScale [DERIVED] (also: ` — Float scale factor for luminance decoding) |
| 005adb14 | flt_5ADB14 | R | DegreeWrap360 [DERIVED] (also: ` — 360.0 (degree wrap) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00507845 | ContactManifoldCleanup | post-process decoded float RGBA buffer (likely alpha blend or edge fix) |
| 0058a870 | sub_58A870 | decode/convert single 16-bit channel value to float RGB channel |

**Guard conditions:** If local variable a1[4] (decompiler temp for this->field_10 after loop restores pointer) is non-zero, calls ContactManifoldCleanup on decoded output; if zero, skips post-processing.
