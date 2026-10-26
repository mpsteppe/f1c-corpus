## TextureHorizontalStretch_00518248 — TextureHorizontalStretch

**Summary:** Stretches a single-row texture horizontally by duplicating/repeating pixels to fill a target width. Handles 1/2/4/8+ bits per pixel formats using stride table for output dimensions.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_511B7C (00511b7c)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | source width; updated to stretched output width |
| this | 0x4 | RW | — | source row byte size; updated to stretched output size |
| this | 0xB | R | — | bits per pixel (1, 2, 4, or 8+) |

**Written-by note (persistence):**
- this 0x0: overwritten with stretched width; external poke changes dimensions
- this 0x4: recomputed from stretched width * bpp; external poke corrupts row size

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005afabc | dword_5AFABC | R | Zlib_StrideTable [DERIVED] — provides stride multiplier for output width calculation |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0xB | == | 4 | bits per pixel = 4 |
| this | 0xB | == | 2 | bits per pixel = 2 |

**Guard interpretation:** BPP at 0xB selects the pixel packing path: 4bpp uses 4-bit nibble operations, 2bpp uses 2-bit operations, 1bpp uses single-bit operations, and any other value (8+) uses full byte copies. Source pixel is read from input buffer at source position, replicated horizontally, and written to output buffer at stretched position. Each path computes its own bit-indexing for byte-aligned memory.
