## SuspensionWheelForceCalculation_00459070 — SuspensionWheelForceCalculation

**Summary:** Computes suspension forces for wheel contact using spline-based force curve lookup. On first initialization (flag at 0xCC==0 with bit 1 of 0x74 set), determines suspension direction by evaluating two spline positions at different parameters and sets direction sign (0xAC) to ±1.0f. Normal path computes force from velocity magnitude, direction sign, time delta, and bias, evaluates suspension spline via GuardedFunctionWithFlagSet, then derives velocity from position change over time delta.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_458DF0 (00458df0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | R | — | position X (current suspension/contact position) |
| this | 0x10 | R | — | position Y |
| this | 0x14 | R | — | position Z |
| this | 0x74 | R | — | flags byte: bit 1 selects initialization path vs normal computation |
| this | 0xA8 | R | — | suspension stiffness/damping scale factor |
| this | 0xAC | RW | 1065353216 → 1.0f | direction sign (±1.0f); set during initial direction determination |
| this | 0xB8 | R | — | second suspension spline parameter (t value for direction test) |
| this | 0xBC | R | — | suspension offset/bias added to computed force |
| this | 0xCC | R | — | initialization flag: 0 triggers direction setup on first call |

**Written-by note (persistence):**
- this 0xAC: written once on first initialization (direction determination) to 1.0f or -1.0f. Survives until externally modified.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e670 | flt_59E670 | R | SentinelFlagConstant [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00456110 | F_3VectorCopyToStruct | copy 3-float result from local buffer back into struct fields |
| 00456150 | StructFieldCopy | zero-initialize or copy computed velocity/force vector to struct fields |
| 004582c0 | GuardedFunctionWithFlagSet | evaluate suspension spline curve at given parameter t; returns interpolated position/force vector |

**Guard conditions:** Checks byte at 0x74 bit 1. If set AND byte at 0xCC == 0 → enter initialization path: determine suspension direction by comparing distances from two spline query points, set 0xAC direction sign, then early return. If bit 1 not set OR 0xCC != 0 → normal path: compute force from velocity magnitude, direction sign, delta, and bias, evaluate spline, compute velocity derivative. If a4 <= 0 → zero velocity output.
