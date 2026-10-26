## TerrainHeightComparison_004624e0 — TerrainHeightThresholdCheck

**Summary:** Samples terrain height at a position and returns true if the sampled height exceeds the given threshold (or a default minimum penetration limit).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_49F870 (0049f870)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | This pointer dereference |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | Zero threshold (~0.0f, physics clamp) [DERIVED] |
| 007d108c | flt_7D108C | R | Minimum penetration limit (fallback when a3 < 0) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0045ca20 | TerrainSurfaceRoughnessHeightSampling | Sample terrain surface height at given position |

**Guard conditions:** When a3 < 0.0, uses flt_7D108C (min penetration limit) as threshold instead.
