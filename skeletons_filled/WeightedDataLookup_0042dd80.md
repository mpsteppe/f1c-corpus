## WeightedDataLookup_0042dd80 — Weighted1DRatioCalculator

**Summary:** Computes weighted ratio from 1D lookup table. Looks up base and weight values by index a2, returns (scale * weightValue) / (baseValue * divisor). Returns 0 if index out of bounds or values non-positive.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AIPathNodeDelegate (0042ed30)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | dataCount |
| this | 0xC | R | — | dataArrayPtr |
| this | 0x10 | R | — | divisor |
| this | 0x14 | R | — | scaleFactor |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e430 | dbl_59E430 | R | ZeroSentinel [DERIVED] (also: ` (ZeroSentinel ~0.0) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Returns 0.0 if: a2 < 0, a2 >= dataCount, base data value <= 0, or divisor <= 0. Only computes ratio when all guards pass.
