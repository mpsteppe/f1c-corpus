## sub_67CD1D_0067cd1d — PackRGB565FromFloat

**Summary:** Clamps a 3-float RGB color to [0,1] and quantizes/packs it into a 16-bit RGB565 value (red 5 bits << 11, green 6 bits << 5, blue 5 bits) with round-to-nearest.

**Called by:** sub_67D6C7 (0067d6c7)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | red channel (float) |
| this | 0x4 | R | — | green channel (float) |
| this | 0x8 | R | — | blue channel (float) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f16b8 | flt_6F16B8 | R | float constant used in the clamp/quantization math |
| 006f16c8 | flt_6F16C8 | R | float constant used in the clamp/quantization math |
| 0071bedc | flt_71BEDC | R | float constant used in the clamp/quantization math |
| 0071bef8 | flt_71BEF8 | R | float constant used in the clamp/quantization math |
| 00731ce8 | String2 | R | IDB-named constant referenced by the compiled math; exact use not visible in the decompiled body — unknown |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No early exits. Per channel: value < 0.0 → clamped to 0.0; value > 1.0 → clamped to 1.0; in-range values pass through unchanged. Channels are then scaled (R and B by 31.0, G by 63.0), rounded by adding 0.5, and truncated to ints; the packed result is returned.
