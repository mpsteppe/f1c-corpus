## BlockTextureDecompression_0051dcaa — BlockDitherTextureDecompress

**Summary:** Decompresses block-compressed texture with serpentine-scan error diffusion. Alternates left-to-right/right-to-left per row using toggle flag, looks up palette grid, calls BitstreamTextureBlockCopy for unpopulated cells, computes and distributes quantization error to neighboring pixels.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1C4) | 0x0 | RW | — | dither error buffer channel 0 (accumulated error) |
| *(this+0x1C4) | 0x2 | RW | — | dither error buffer channel 1 (accumulated error) |
| *(this+0x1C4) | 0x4 | RW | — | dither error buffer channel 2 (accumulated error) |
| this | 0x5C | R | — | pixel width per row |
| this | 0x74 | R | — | palette structure pointer |
| this | 0x78 | R | — | palette offset (component stride) |
| this | 0x7C | R | — | palette offset (component stride) |
| this | 0x11C | R | — | unknown context field |
| this | 0x1A4 | R | — | context pointer |
| this | 0x1BC | R | — | unknown context field |
| this | 0x1C4 | R | — | dither error buffer pointer |
| this | 0x1C8 | RW | 1 | scan-direction toggle flag (alternates per row) |
| this | 0x1CC | R | — | unknown context field |

**Written-by note (persistence):**
- *(this+0x1C4) 0x0: error accumulation, updated every decompressed pixel; survives across calls
- *(this+0x1C4) 0x2: same as above
- *(this+0x1C4) 0x4: same as above
- this 0x1C8: toggle bit flipped each row; survives between calls

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0051db31 | BitstreamTextureBlockCopy | populates empty palette grid cell with nearest color match |

**Guard conditions:** if a4 (pixel count) <= 0, skip outer loop (line 71). Inner loop iterates over width (v38). Direction determined by toggle at *(v4+36): 0 = left-to-right (v40=1, v52=3), 1 = right-to-left (v40=-1, v52=-3). Any width > 0 proceeds with decompression.
