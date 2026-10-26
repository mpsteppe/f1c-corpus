## ParameterizedCurveInterpolation_004f6720 — piecewise-linear curve interpolator (dual output)

**Summary:** Interpolates along a piecewise-linear curve defined by (x, y1, y2) triple points. Returns two interpolated values; if y2 < y1, averages both to midpoint. Handles edge extrapolation and single-point case.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** BrakeTemperatureFadeModel (00430a50), sub_43C250 (0043c250), SuspensionAndWheelPhysics (004e5f60)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x6C4 | R | — | curve point count |
| this | 0x6C8 | R | — | first point x-coordinate (double, low 32 bits) |
| this | 0x6D0 | R | — | first point y1 output (double low 32 bits) |
| this | 0x6D4 | R | — | first point y1 output (double high 32 bits) |
| this | 0x6D8 | R | — | first point y2 output (double low 32 bits) |
| this | 0x6DC | R | — | first point y2 output (double high 32 bits) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e880 | dbl_59E880 | R | HalfStep [DERIVED] (also: ` — lower threshold constant) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Curve point count (0x6C4) must be > 0 to produce output; if 0, both outputs set to 0. If count == 1, copies single point directly without interpolation.
