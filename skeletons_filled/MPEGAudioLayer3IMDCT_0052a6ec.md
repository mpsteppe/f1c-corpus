## MPEGAudioLayer3IMDCT_0052a6ec — MPEGLayer3IMDCT

**Summary:** Inverse Modified Discrete Cosine Transform (IMDCT) for MPEG Audio Layer 3 decoding. Converts frequency-domain subband samples to time-domain audio via butterfly rotation and windowed overlap-add with coefficient table lookup.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** RenderingBranchOnDAT005d79dc (0052855a)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | first frequency-domain input vector (16-bit) |
| this | 0x10 | R | — | second frequency-domain input vector |
| this | 0x20 | R | — | third frequency-domain input vector |
| this | 0x30 | R | — | fourth frequency-domain input vector |
| this | 0x40 | R | — | fifth frequency-domain input vector |
| this | 0x50 | R | — | sixth frequency-domain input vector |
| this | 0x60 | R | — | seventh frequency-domain input vector |
| this | 0x70 | R | — | eighth frequency-domain input vector |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none — two fixed-count loops (8 iterations each) with no early exit
