## PhysicsChannelProcessingWithLocals_004a3820 — AnimationPhaseDistributor

**Summary:** Computes time-phase subdivisions (0.0, 0.25×, 0.5×, 0.75×, and offset-3.6) from an input float value (elapsed time / phase), then distributes them to each array element's sub-element structures via RangeProportionInitializer. Used by PitStopOperationTimer for multi-channel animation timing.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** PitStopOperationTimer (004a6340)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | R | — | Count of elements in the main array |
| this | 0x10 | R | — | Pointer to base of 120-byte-element array |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e7f8 | flt_59E7F8 | R | AntiRollMixingFactor [DERIVED] |
| 0059e7fc | flt_59E7FC | R | BumpDampingConstant [DERIVED] (also: ` — bump damping constants) |
| 005acaf4 | flt_5ACAF4 | R | PathLengthThreshold [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004a1fd0 | RangeProportionInitializer | Sets range/proportion values on a sub-element for animation tweening |

**Guard conditions:** Loop guard on `this[3] > 0`. PASSES when element count is positive (≥1). BLOCKED (entire loop skipped) when count ≤ 0.