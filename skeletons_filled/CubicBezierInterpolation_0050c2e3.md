## CubicBezierInterpolation_0050c2e3 — Cubic Hermite Spline Interpolation (3D)

**Summary:** Evaluates cubic Hermite/Bezier interpolation for a 3-component vector. Uses standard Hermite basis functions (2t^3-3t^2+1, t^3-2t^2+t, -2t^3+3t^2, t^3-t^2) with parameter t=a6.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Output X component |
| this | 0x4 | RW | — | Output Y component |
| this | 0x8 | RW | — | Output Z component |

**Written-by note (persistence):**
- this 0x0: written once per call with interpolated value; output-only, no external persistence
- this 0x4: same as above
- this 0x8: same as above

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: float threshold for contact aging overflow) |
| 0059e478 | flt_59E478 | R | SteeringCenterBoost [DERIVED] |

**Functions called:** none

**Guard conditions:** unconditional — no branches, no early return.
