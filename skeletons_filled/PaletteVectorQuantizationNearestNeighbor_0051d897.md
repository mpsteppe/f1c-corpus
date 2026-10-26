## PaletteVectorQuantizationNearestNeighbor_0051d897 — PaletteNearestColorSearch

**Summary:** Performs nearest-neighbor search in a three-component palette for a target color. Computes weighted squared distance per channel with threshold-based deviation penalties, returns indices of palette entries within best distance threshold to output buffer.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** BitstreamTextureBlockCopy (0051db31)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x74) | 0x0 | R | — | palette component 0 array (R channel) |
| *(this+0x74) | 0x4 | R | — | palette component 1 array (G channel) |
| *(this+0x74) | 0x8 | R | — | palette component 2 array (B channel) |
| this | 0x70 | R | — | palette entry count (number of palette colors) |
| this | 0x74 | R | — | palette structure pointer (3 component arrays) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** if palette count <= 0 (v35 > 0 false), skip entire nearest-neighbor search loop (line 45). PASSES when palette has entries; BLOCKED when empty palette.
