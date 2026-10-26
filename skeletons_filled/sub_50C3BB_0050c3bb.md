## sub_50C3BB_0050c3bb — Catmull-Rom Spline Interpolation (3D)

**Summary:** Evaluates Catmull-Rom spline interpolation for a 3-component vector. Uses Catmull-Rom basis with 0.5 scaling factor. Result = 0.5 * (c0*p0 + c1*p1 + c2*p2 + c3*p3) with parameter t=a6.

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
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e46c | flt_59E46C | R | TireSlipOffset [DERIVED] (also: offset value) |
| 0059e478 | flt_59E478 | R | SteeringCenterBoost [DERIVED] |
| 0059e7ec | flt_59E7EC | R | ZeroConstant [DERIVED] (also: compared constant (5.0f encoded indirectly) |
| 0059e800 | flt_59E800 | R | AmplitudeLimit [DERIVED] (also: under-relaxation upper bound) |

**Functions called:** none

**Guard conditions:** unconditional — no branches, no early return.
