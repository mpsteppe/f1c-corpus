## SuspensionDamperForceAccumulation_0043e890 — SuspensionDamperForceAccumulator

**Summary:** Accumulates suspension damper forces with scaling and clamping, then evaluates the damper force curve via quadratic function. Scales input by damper-specific rates (0.23 and 0.18) and clamps accumulators to upper bounds from reference field plus offset. Part of vehicle suspension force computation.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** PhysicsForceScaleDispatch (0043ebd0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x17A8 | RW | — | damper 1 force accumulator (scaled by 0.23 rate) |
| this | 0x17C0 | RW | — | damper 2 force accumulator (scaled by 0.18 rate) |
| this | 0x1C00 | R | — | reference value for damper 1 (upper clamp bound base) |
| this | 0x1C08 | R | — | reference value for damper 2 (upper clamp bound base) |
| this | 0x1C10 | R | — | index/selector for quadratic function evaluation |

**Written-by note (persistence):**
- this 0x17A8: recalc every frame — external poke does NOT persist
- this 0x17C0: recalc every frame — external poke does NOT persist

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
| 0043bb30 | QuadFunctionEval | evaluates quadratic force function from accumulated damper state |

**Guard conditions:** clamp logic — if accumulator exceeds reference+offset, cap at reference+offset; if accumulator below reference, reset to reference. Prevents accumulator from diverging.
