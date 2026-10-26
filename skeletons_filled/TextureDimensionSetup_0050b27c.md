## TextureDimensionSetup_0050b27c — QuantizeColorChannelsToTextureFormat

**Summary:** Reads a texture format identifier to determine per-channel bit depth, then quantizes float RGBA channel values to match the target format (R5G6B5 for color, 4-bit or 8-bit alpha). Writes back quantized values and stores the max channel value and its reciprocal.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | Texture format identifier (FourCC-like DWORD); 0x32554D44 or 0x33554D44 selects 4-bit alpha (max=15), else 8-bit (max=255) |
| this | 0x1C | RW | — | R channel float value — quantized to 5 bits (0-31), rewritten as normalized float |
| this | 0x20 | RW | — | G channel float value — quantized to 6 bits (0-63), rewritten as normalized float |
| this | 0x24 | RW | — | B channel float value — quantized to 5 bits (0-31), rewritten as normalized float |
| this | 0x28 | RW | — | Alpha channel float value — quantized to max_value bits, rewritten as normalized float |
| this | 0x106C | RW | — | Max channel value (15.0 or 255.0) set based on format identifier |
| this | 0x1070 | RW | — | Reciprocal of max channel value (1.0/max_value) |

**Written-by note (persistence):**
- this 0x1C: rewritten once; persists as quantized R value
- this 0x20: rewritten once; persists as quantized G value
- this 0x24: rewritten once; persists as quantized B value
- this 0x28: rewritten once; persists as quantized A value
- this 0x106C: written once; max value persists for lifetime
- this 0x1070: written once; reciprocal persists for lifetime

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e8d8 | flt_59E8D8 | R | BrakingSpeedThreshold3 [DERIVED] |
| 0059fec8 | flt_59FEC8 | R | AlphaChannelMultiplier [DERIVED] |
| 005accd0 | flt_5ACCD0 | R | RGBChannelScaleR [DERIVED] (also: ` — R/B channel scale factor (fixed-point multiplier) |
| 005accd4 | flt_5ACCD4 | R | ChannelDecodeScale [DERIVED] (also: ` — Float scale factor for 5/6-bit channel decoding) |
| 005accd8 | flt_5ACCD8 | R | DXT_GreenChannelScale [DERIVED] (also: ` — G channel scale factor (different precision) |
| 005accdc | flt_5ACCDC | R | AlphaChannelScale [DERIVED] (also: ` — alpha channel scale factor) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none — runs unconditionally on the provided this pointer.
