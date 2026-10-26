## CollisionGridCellDecoder_0049b670 — AngleTimeToGridCellDecoder

**Summary:** Converts a float value (angle in degrees or time in seconds) to integer hours via multiplication by 1/3600, computes the remainder after removing whole-hour chunks, then delegates to SpatialGridCell for grid cell lookup.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e9b8 | flt_59E9B8 | R | RemainderScaleFactor [DERIVED] (also: ` — float, ~1.0f (scale factor for remainder computation) |
| 0059e9bc | flt_59E9BC | R | AngleConversionFactor [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0049b630 | SpatialGridCell | Computes spatial grid cell from remainder angle |
| 00587bdc | CRTFtol | Float-to-int conversion for hour quantization |

**Guard conditions:** none — always computes hours and remainder unconditionally
