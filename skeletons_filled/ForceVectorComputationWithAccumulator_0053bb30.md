## ForceVectorComputationWithAccumulator_0053bb30 — ForceVectorFractionComputation

**Summary:** Computes a 3-component force/torque vector contribution using SSE SIMD: scales direction components by a magnitude factor, applies transform constants, optionally accumulates with an existing vector, and multiplies by 255 fixed-point scale. Used in physics force computation.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x17C | R | — | Accumulator X component (a1[95]) |
| this | 0x180 | R | — | Accumulator Y component (a1[96]) |
| this | 0x184 | R | — | Accumulator Z component (a1[97]) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059fec8 | flt_59FEC8 | R | AlphaChannelMultiplier [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Checks a1 (accumulator pointer): if non-null, accumulator vector at offsets 0x17C-0x184 is added into the result. If null, no accumulation is performed.
