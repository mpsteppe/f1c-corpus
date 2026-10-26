## SessionStateIndexedLookup_0042ed00 — IndexedRatioLookup

**Summary:** Looks up weighted ratio from gear config table indexed by a2 via RatioCalculator. Uses gear ratio table at this+0x1970, row index from lookup array, and column index from this[0x1644]. Negates result when a2 equals 43.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** BrakeTemperatureFadeModel (00430a50), PressureForceFieldMapping (004313c0), TireSuspensionForceComputation (00431850), sub_43C250 (0043c250), SuspensionAndWheelPhysics (004e5f60)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1644 | R | — | ratioColumnIndex |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0042dd00 | RatioCalculator | Computes weighted ratio from 2D lookup table using row/column indices |

**Guard conditions:** If a2 == 43, negates the RatioCalculator result. Otherwise returns result as-is. All bounds checks handled inside RatioCalculator.
