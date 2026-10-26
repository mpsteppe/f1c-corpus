## FloatWrapTableInterpolation_004d7cf0 — WrappedFloatLerpFactorComputer

**Summary:** Wraps float a2 into range [0, this[9]), calls FloatRangeIndexLookup to get the segment index, then computes linear interpolation factor: (a2 - this[v6+6]) / (this[v6+9] - this[v6+6]). Optionally writes index to *a3.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** PitSelectionStateMachine (0041b3c0), sub_4BCCC0 (004bccc0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x24 | R | — | wrap range (period) — value is wrapped into [0, this[9]) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d7c10 | FloatRangeIndexLookup | finds which segment index v6 the wrapped value falls into |

**Guard conditions:** If a2 < 0, wraps into positive range by adding this[9]. If a2 > this[9], wraps down by subtracting this[9]. If a3 pointer is non-null, writes the computed segment index.
