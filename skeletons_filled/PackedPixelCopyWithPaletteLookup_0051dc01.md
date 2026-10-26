## PackedPixelCopyWithPaletteLookup_0051dc01 — RGB565PaletteLookupPixelCopy

**Summary:** Copies pixels from packed source to destination using RGB 5-6-5 palette lookup. Reads 3 bytes per pixel (R>>3, G>>2, B>>3) as grid key, looks up palette cell, calls BitstreamTextureBlockCopy if cell empty, writes palette index-minus-1 to output.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1A4) | 0x18 | R | — | grid row-pointer base array (palette cell grid) |
| this | 0x5C | R | — | pixel width (stride in bytes per row) |
| this | 0x1A4 | R | — | context pointer |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0051db31 | BitstreamTextureBlockCopy | populates empty palette grid cell with nearest color match |

**Guard conditions:** if a4 (pixel count) <= 0, skip outer loop. if v5 (width) == 0, skip inner copy loop per pixel (line 33). PASSES when count > 0 and width > 0; BLOCKED otherwise.
