## F_16BitColorToFloat4Decoder_00513d63 — Decode16BitColorToFloat4

**Summary:** Decode 16-bit RGB 5:6:5 packed color to 4 floats (R, G, B, A=1.0). Output written to result pointer. Used in texture filtering and keyframe interpolation.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** TextureFilterAndLayerCompositing (005147ea), KeyframeQuadInterpolationWithBitPackedSelector (00514fee)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | float R — decoded red channel (written) |
| this | 0x4 | RW | — | float G — decoded green channel (written) |
| this | 0x8 | RW | — | float B — decoded blue channel (written) |
| this | 0xC | RW | — | float A — alpha always set to 1.0 (written) |

**Written-by note (persistence):**
- this 0x0-0xC: all four floats overwritten each call; external poke survives until next decode

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005accd4 | flt_5ACCD4 | R | 0.032258064 — red (5-bit) and blue (5-bit) scale factor (1/31) |
| 005accdc | flt_5ACCDC | R | 0.015873017 — green (6-bit) scale factor (1/63) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

No guard conditions — function always executes unconditionally.
