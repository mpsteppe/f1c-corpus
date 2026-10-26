## RatioCalculator_0042dd00 — Table2DRatioCalculator

**Summary:** Computes weighted ratio from 2D lookup table. Takes row index (a2) and column index (a3), looks up base and weight values from two parallel arrays, and returns (scale * rowWeight * colWeight) / (rowBase * colBase * divisor). Returns 0 on any bounds or zero-value check.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** SessionStateIndexedLookup (0042ed00), VehicleSetupValueFormatter (0042f470)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | rowCount |
| this | 0x4 | R | — | rowDataArrayPtr |
| this | 0x8 | R | — | colCount |
| this | 0xC | R | — | colDataArrayPtr |
| this | 0x10 | R | — | divisor |
| this | 0x14 | R | — | scaleFactor |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e430 | dbl_59E430 | R | ZeroSentinel [DERIVED] (also: ` (ZeroSentinel ~0.0) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Returns 0.0 if: a2 < 0, a2 >= rowCount, a3 < 0, a3 >= colCount, row data entry baseValue <= 0, col data entry baseValue <= 0, or divisor <= 0. Only computes ratio when all guards pass.
