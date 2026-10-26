## ClampedSpringIntegrator_0043e980 — ClampedSpringIntegrator

**Summary:** Accumulates spring state with scaled input (0.23 and 0.18 rates), clamps accumulators against reference-plus-offset bounds, then computes spring-damper force via SpringDamperCompute. Part of vehicle suspension spring force system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** PhysicsForceScaleDispatch (0043ebd0), RandomWeightedAudioMix (0043ec00)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1808 | RW | — | spring accumulator 1 (scaled by 0.23 rate) |
| this | 0x1818 | RW | — | spring accumulator 2 (scaled by 0.18 rate) |
| this | 0x1C18 | R | — | spring reference value 1 (upper clamp bound base, +0.25) |
| this | 0x1C20 | R | — | spring reference value 2 (upper clamp bound base, +0.20) |
| this | 0x1C28 | R | — | index/selector for spring-damper computation |

**Written-by note (persistence):**
- this 0x1808: recalc every frame — external poke does NOT persist
- this 0x1818: recalc every frame — external poke does NOT persist

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
| 0043bbd0 | SpringDamperCompute | computes spring-damper force from accumulated spring state |

**Guard conditions:** clamp logic — if accumulator exceeds reference+offset, cap; if below reference, reset to reference. Prevents spring accumulator divergence.
