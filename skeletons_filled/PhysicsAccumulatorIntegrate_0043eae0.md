## PhysicsAccumulatorIntegrate_0043eae0 — PhysicsAccumulatorIntegrate

**Summary:** Accumulates physics state with scaled input (0.23 and 0.18 rates), clamps accumulators against reference-plus-offset bounds, then evaluates quadratic force/torque via QuadraticForceTorqueCalculator. Structurally identical pattern to SuspensionDamperForceAccumulation and ClampedSpringIntegrator. Part of vehicle physics damping system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** PhysicsDampingScaleApplication (0043ec50)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x17D8 | RW | — | physics accumulator 1 (scaled by 0.23 rate) |
| this | 0x17F0 | RW | — | physics accumulator 2 (scaled by 0.18 rate) |
| this | 0x1C38 | R | — | physics reference value 1 (upper clamp bound base, +0.25) |
| this | 0x1C40 | R | — | physics reference value 2 (upper clamp bound base, +0.20) |
| this | 0x1C48 | R | — | index/selector for quadratic force/torque calculation |

**Written-by note (persistence):**
- this 0x17D8: recalc every frame — external poke does NOT persist
- this 0x17F0: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059eb28 | dbl_59EB28 | R | Damper2MaxAdd [DERIVED] (also: ` — damper 2 max add (range limit) |
| 0059eb50 | dbl_59EB50 | R | InputScaleFactor [DERIVED] |
| 0059eb58 | dbl_59EB58 | R | Damper2RateCoefficient [DERIVED] |
| 0059ec78 | dbl_59EC78 | R | Damper1RateCoeff [DERIVED] (also: ` — damper 1 rate coefficient) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0043bb80 | QuadraticForceTorqueCalculator | computes force/torque from accumulated physics state |

**Guard conditions:** clamp logic — if accumulator exceeds reference+offset, cap; if below reference, reset to reference.
