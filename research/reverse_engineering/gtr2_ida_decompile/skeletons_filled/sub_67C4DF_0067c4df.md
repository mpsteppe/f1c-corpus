## sub_67C4DF_0067c4df — row dithering (RGB/RGBA → palette index)

**Summary:** Dithers one decoded row: quantizes 8-bit RGB (and RGBA, ignoring the alpha byte) samples into a 15-bit color index looked up in the supplied palette table, rewriting the row descriptor to palette format; for palette rows it instead maps every palette index byte through the dither lookup table.

**Called by:** sub_67CA0D (0067ca0d)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | row width in pixels — number of pixels converted |
| this | 0x4 | RW | — | rowbytes — recomputed after RGB/RGBA conversion as bytes for the new 1-channel format |
| this | 0x8 | RW | 3 | color type — tested for 2 (RGB), 6 (RGBA), 3 (palette); set to 3 after a conversion |
| this | 0x9 | R | — | bit depth — only 8 is handled; read again when recomputing the descriptor |
| this | 0xA | RW | 1 | channels — set to 1 after a conversion |
| this | 0xB | RW | — | pixel depth — set to the bit depth after a conversion |

**Written-by note (persistence):**
- this 0x4: recomputed only when an RGB/RGBA conversion runs — an external poke would not survive such a call, but survives palette-only dithering.
- this 0x8: forced to 3 on every RGB/RGBA conversion; otherwise unchanged.
- this 0xA: forced to 1 on every RGB/RGBA conversion; otherwise unchanged.
- this 0xB: forced to the bit depth on every RGB/RGBA conversion; otherwise unchanged.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x9 | == | 8 | bit depth — only 8-bit rows are converted or dither-mapped |

**Guard interpretation:** RGB (type 2) rows pass only with an 8-bit depth and a non-NULL palette table a3: each pixel's three samples are folded into index ((r & 0xF8) << 7) | ((g & 0xF8) << 2) | (b >> 3), the result byte overwrites the pixel and the descriptor is converted (color type 3, channels 1, pixel depth = bit depth, rowbytes = (width × 8 + 7) >> 3). RGBA (type 6) does the same for three samples and skips the fourth (alpha). A NULL a3 leaves RGB/RGBA rows untouched. Palette rows (type 3) are remapped byte-by-byte through the dither table a4 only when a4 is non-NULL and the depth is 8; otherwise they are untouched. All other color types and depths return the width unchanged with no writes, and the caller verifies the recomputed rowbytes is non-zero after a conversion.
