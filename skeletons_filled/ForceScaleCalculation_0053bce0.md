## ForceScaleCalculation_0053bce0 — ForceAxisScaleComputation

**Summary:** Computes a 3-component force vector for one axis using SSE: multiplies scaled direction components from a1 (indices 6-9) by transform constants from a2 (indices 17-19) and a fixed 255 scale factor. Used in physics force computation.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x18 | R | — | Force direction Z component (a1[6]) |
| this | 0x1C | R | — | Force direction Y component (a1[7]) |
| this | 0x20 | R | — | Force direction X component (a1[8]) |
| this | 0x24 | R | — | Force magnitude (a1[9]) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059fec8 | flt_59FEC8 | R | AlphaChannelMultiplier [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guard conditions — all pointers are assumed valid, no null checks performed.
