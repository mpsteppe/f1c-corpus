## DoubleAccumulatorClamp_0043ea70 — SingleAccumulatorClamp

**Summary:** Accumulates a single value with 0.37 scaling factor and clamps against reference-plus-offset upper bound. Single-accumulator variant of the pattern seen in SuspensionDamperForceAccumulation and ClampedSpringIntegrator. Part of vehicle physics force scaling.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** RandomWeightedAudioMix (0043ec00), PhysicsDampingScaleApplication (0043ec50)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1BC0 | RW | — | single accumulator (scaled by 0.37 rate) |
| this | 0x1C30 | R | — | reference value for upper clamp bound (+0.40 offset) |

**Written-by note (persistence):**
- this 0x1BC0: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059ec80 | dbl_59EC80 | R | InputOffsetBias [DERIVED] |
| 0059ec88 | dbl_59EC88 | R | FuelConsumptionRate [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** clamp logic — if accumulator exceeds reference+0.40, cap; if below reference, reset to reference. Single accumulator variant.
