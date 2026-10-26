## RenderingBranchOnDAT005d79dc_0052855a — AudioRenderingBranchOnMode

**Summary:** Branch between MPEG audio codec transforms based on global rendering mode flag. Routes same parameters to either AudioCodecMDCTFFTTransform or MPEGAudioLayer3IMDCT depending on byte_5D79DC.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x11C | R | — | Buffer offset from a1 (284 = 0x11C) plus 128 used as output parameter to both transforms |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d79dc | byte_5D79DC | R | RenderingModeFlag [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0052a6ec | MPEGAudioLayer3IMDCT | MPEG Layer 3 IMDCT transform (standard rendering path) |
| 0052ab4e | AudioCodecMDCTFFTTransform | Audio codec MDCT/FFT transform (high-quality rendering path) |

**Guard conditions:** Check `byte_5D79DC` (global rendering mode flag). If non-zero: PASS to AudioCodecMDCTFFTTransform (high-quality path). If zero: PASS to MPEGAudioLayer3IMDCT (standard path).
