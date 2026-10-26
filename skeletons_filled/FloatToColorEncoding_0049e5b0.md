## FloatToColorEncoding_0049e5b0 — Float to color gradient encoding

**Summary:** Maps a float value (range 30-150) to a 32-bit ARGB color gradient. Low values map to blue, mid values to green, high values to red with clamped endpoints.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SuspensionCornerCheck (0049e570)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] |
| 0059e468 | flt_59E468 | R | BrakingZoneSpeedThreshold2 [DERIVED] |
| 0059e87c | flt_59E87C | R | TimeStepMultiplier [DERIVED] |
| 0059fec8 | flt_59FEC8 | R | AlphaChannelMultiplier [DERIVED] |
| 005acb00 | flt_5ACB00 | R | Threshold_LowerBound_5ACB00 [DERIVED] |
| 005acb04 | flt_5ACB04 | R | ColorThreshold_5ACB04 [DERIVED] |
| 005acb08 | flt_5ACB08 | R | FloatThreshold_5ACB08 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bdc | CRTFtol | converts double to long (used for color channel computation) |

**Guard conditions:** If input < 30: clamped to 30, returns blue-range color. If > 150: clamped to 150, returns red-range color. If 30-70: blue-green gradient. If 110-150: yellow-red gradient. If 70-110: green-dominant color. No early-exit guard — always returns a valid color.
