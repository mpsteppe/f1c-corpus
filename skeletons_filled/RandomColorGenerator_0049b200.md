## RandomColorGenerator_0049b200 — TimeBasedTriangularWaveColor

**Summary:** Computes a packed RGB color value from a time-based triangular wave oscillation. Uses session time (dbl_8AFEA0 + a3) to generate a value in [0,1] via triangle wave, clamps, then converts to a 24-bit integer via three CRTFtol conversions.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** F_2DTextRenderingWithScissorRectangle (0049b370), ShortComputation_f070 (0049f070)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e420 | dbl_59E420 | R | BaseDoubleConstant [DERIVED] (also: ` (BaseDoubleConstant = 1.0) |
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 008afea0 | dbl_8AFEA0 | R | SessionTime [DERIVED] (also: ` — current session time (passed to FUN_0040f300) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bdc | CRTFtol | Float-to-int conversion for each color channel |
| 0058957a | InterruptDispatch | Unknown side-effect call with the time value |

**Guard conditions:** none — always executes the wave computation unconditionally
