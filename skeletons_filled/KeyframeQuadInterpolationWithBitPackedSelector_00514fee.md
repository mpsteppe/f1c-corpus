## KeyframeQuadInterpolationWithBitPackedSelector_00514fee — DxtBlockDecompressor

**Summary:** Decompress 4×4 DXT/BC block to 16 float4 colors. Decode two 16-bit 5:6:5 endpoint colors, interpolate 2 or 4 color palette based on endpoint ordering, then expand 32-bit selector bitmask to select output color per pixel.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_51512C (0051512c), sub_5151AF (005151af)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | float R — output red channel (written per pixel) |
| this | 0x4 | RW | — | float G — output green channel (written per pixel) |
| this | 0x8 | RW | — | float B — output blue channel (written per pixel) |
| this | 0xC | RW | — | float A — output alpha channel (written per pixel) |

**Written-by note (persistence):**
- this 0x0-0xC: all 16 output float4s overwritten each call; survives until overwritten

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e450 | flt_59E450 | R | degrees-to-radians constant |
| 0059e98c | flt_59E98C | R | acceleration tuning factor |
| 005ad1f4 | flt_5AD1F4 | R | audio lerp coefficient |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00513d63 | F_16BitColorToFloat4Decoder | decode 16-bit 5:6:5 endpoint colors to float4 |

**Guard conditions (deterministic — field vs literal):**

No guard conditions — function always executes unconditionally.

**Interpolation modes:**
- color0 > color1 (WORD): 4-color mode — compute 1/3 and 2/3 interpolation points (BC3-style)
- color0 <= color1: 2-color mode — compute midpoint only, other slots zeroed (BC1 transparent-style)
