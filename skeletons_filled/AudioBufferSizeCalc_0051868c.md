## AudioBufferSizeCalc_0051868c — TextureBufferSizeSetup

**Summary:** Calculates and allocates texture/surface buffer dimensions (row stride, buffer size) based on image width, bit depth, color type, and interlace/compression flags. Part of image decoding pipeline.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ConditionalDispatchWithGuard (00511b5c), sub_511B7C (00511b7c)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x5C | RW | — | flags register; sets bit 6 (0x40) after allocation |
| this | 0x60 | R | — | unknown/read-only config |
| this | 0x68 | RW | 0 | texture/color transform state, reset to 0 |
| this | 0xB8 | R | — | image width in pixels |
| this | 0xBC | R | — | image height / row count |
| this | 0xC0 | RW | — | image bytes-per-row (stride) |
| this | 0xC8 | R | — | interlace flag |
| this | 0xCC | RW | — | output width (post-decompress pixel count) |
| this | 0xD0 | RW | — | output row size in bytes |
| this | 0xD8 | RW | — | source data buffer pointer (allocated) |
| this | 0xDC | RW | — | temporary scanline buffer pointer (allocated) |
| this | 0x10A | R | — | interlace step flag (controls stride divisor) |
| this | 0x113 | R | — | color type (0=grayscale, 2=RGB, 3=indexed, 4=grayscale+alpha, 6=RGBA) |
| this | 0x114 | R | — | interlace method (0=standard, 1=Adam7) |
| this | 0x116 | R | — | compression method (0=deflate) |
| this | 0x117 | R | — | filter method |
| this | 0x119 | R | — | bit depth |

**Written-by note (persistence):**
- this 0x5C: bit 6 set after allocation; external poke survives but may skip ready flag
- this 0x68: reset to 0 unconditionally; external poke might be restored
- this 0xC0: calculated based on width*bpp; external poke corrupts stride
- this 0xCC: calculated from width; external poke corrupts dimensions
- this 0xD0: calculated row size; external poke corrupts buffer layout
- this 0xD8: allocated pointer; external poke leaks/crashes
- this 0xDC: allocated pointer; external poke leaks/crashes

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005afaa0 | dword_5AFAA0 | R | CodecBlockSizeTable [DERIVED] |
| 005afabc | dword_5AFABC | R | Zlib_StrideTable [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0051378b | TextureImageColorTransform | applies color mode transform before buffer calc |
| 00517e92 | sub_517E92 | allocate memory block |
| 00517f04 | MemsetWithByteFill | zero-fill allocated buffer with inline fill |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x10A | != | 0 | interlace step flag non-zero |
| this | 0x117 | < | 8 | filter method value range |

**Guard interpretation:** If interlace flag (0x10A) is non-zero (PASSES), stride is calculated with sub-sampled width using dword_5AFAAO/dword_5AFABC tables. If zero (BLOCKED), uses full width directly. Filter method at 0x117 must be < 8 for valid bounds on stride table lookup.
