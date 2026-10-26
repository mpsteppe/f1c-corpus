## TexturePixelPaletteLookup_00509f0c — PaletteIndexToFloatRGBAConverter

**Summary:** Look up each 8-bit palette index from source texture data into a floating-point RGBA palette table embedded in the struct (starting at +0x30, 4 floats per entry), producing 32-bit float RGBA output, under DirectX texture system.

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

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00507845 | ContactManifoldCleanup | post-process decoded float RGBA buffer (likely alpha blend or edge fix) |

**Guard conditions:** If this[4] (offset +0x10 flag) is non-zero, calls ContactManifoldCleanup on the decoded output; if zero, skips post-processing.
