## TireBrushModelForceSolver_004e8010 — Compute tire forces via brush/slip model

**Summary:** Solves tire longitudinal and lateral forces using the brush model across 4 wheels and 15 slip-ratio samples per frame. Applies load transfer, wet/dry grip scaling, and suspension geometry normalization.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** LargeConfigFunctionWithPhysicsConstants (004e45b0), CollisionWrapperWithLock (004e4910), ActorMotionPostProcessingUpdate (004ed030), RepairServiceStateDispatcher (004ed250), FuelConsumptionAndWear (004ed960), ScaleAudioPitch (004f1510), sub_4F18C0 (004f18c0), LoopWithConditionalSubCall (004f1a60)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x3514 | R | — | vehicle mass (multiplied by -9.81 to compute weight force) |
| this | 0x3518 | R | — | longitudinal stiffness coefficient base |
| this | 0x358C | R | — | wheel lateral position (track width component, used in v90 normalization) |
| this | 0x3594 | R | — | wheel longitudinal position (wheelbase component, used in v94 normalization) |
| this | 0x3610 | R | — | wheel vertical load / corner weight (base of per-wheel load array) |
| this | 0x362C | R | — | wheel slip limit / peak force threshold (per-wheel data, field 0) |
| this | 0x3638 | R | — | wheel friction/grip coefficient (per-wheel data, offset +12) |
| this | 0x3674 | R | — | wheel slip ratio input (per-wheel data, offset +72) |
| this | 0x3684 | R | — | wheel lateral position (track width component for v90) |
| this | 0x368C | R | — | wheel longitudinal position (wheelbase component for v94) |
| this | 0x3708 | R | — | rear axle corner weight (used in load transfer mode 2) |
| this | 0x377C | R | — | wheel lateral position (track width component for v90) |
| this | 0x3784 | R | — | wheel longitudinal position (wheelbase component for v94) |
| this | 0x3800 | R | — | front axle corner weight sum (used in load transfer modes 0 and 1) |
| this | 0x3874 | R | — | wheel lateral position (track width component for v90) |
| this | 0x387C | R | — | wheel longitudinal position (wheelbase component for v94) |
| this | 0x38F8 | R | — | rear axle corner weight sum (used in load transfer modes 1 and 2) |
| this | 0x39B4 | R | — | load transfer distribution mode (0=front bias, 1=balanced avg, 2=rear bias) |
| this | 0x3A30 | R | — | front axle cornering stiffness (used in stiffness ratio sum) |
| this | 0x3A44 | R | — | rear axle cornering stiffness (used in stiffness ratio sum) |
| this | 0x3A6C | R | — | vertical damping coefficient base |
| this | 0x3A70 | R | — | vertical spring rate (scaled by 4096 for force computation) |
| this | 0x3BF4 | R | — | adhesion/grip limit (reciprocal used as scaling factor in dry mode) |
| this | 0x3BFC | RW | — | computed force table normalizer for wheel 0 (1 / speed-normalized slip scale) |
| this | 0x3C3C | RW | — | computed force table normalizer for wheel 1 |
| this | 0x3C40 | R | — | force lookup table base for wheel 0 (15-entry float array) |
| this | 0x3C7C | RW | — | computed force table normalizer for wheel 2 |
| this | 0x3C80 | R | — | force lookup table base for wheel 2 (15-entry float array) |
| this | 0x3CBC | RW | — | computed force table normalizer for wheel 3 |
| this | 0x3CC0 | RW | — | computed force output array (4 wheels × 15 slip samples) |
| this | 0x3CFC | RW | — | force lookup table for wheel 1 / wheel 3 region |
| this | 0x3D3C | RW | — | total longitudinal force output (dry- or wet-scaled) |
| this | 0x3D40 | RW | — | center-of-gravity weight distribution factor |
| this | 0x3D44 | RW | — | vertical load transfer output (damping + spring compression) |
| this | 0x4024 | R | — | brush model global scaling factor |

**Written-by note (persistence):**
- this 0x3BFC: recalc every frame — external poke does NOT persist
- this 0x3C3C: recalc every frame — external poke does NOT persist
- this 0x3C7C: recalc every frame — external poke does NOT persist
- this 0x3CBC: recalc every frame — external poke does NOT persist
- this 0x3CC0: recalc every frame — external poke does NOT persist
- this 0x3CFC: recalc every frame — external poke does NOT persist
- this 0x3D3C: recalc every frame — external poke does NOT persist
- this 0x3D40: recalc every frame — external poke does NOT persist
- this 0x3D44: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e420 | dbl_59E420 | R | BaseDoubleConstant [DERIVED] (also: ` (BaseDoubleConstant = 1.0) |
| 0059e438 | flt_59E438 | R | NormalizationHalf (~0.5f) [DERIVED] |
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e670 | flt_59E670 | R | SentinelFlagConstant [DERIVED] |
| 0059e7f8 | flt_59E7F8 | R | AntiRollMixingFactor [DERIVED] |
| 0059e800 | flt_59E800 | R | AmplitudeLimit [DERIVED] (also: ` — under-relaxation upper bound) |
| 0059e8c8 | flt_59E8C8 | R | Physics_ConvergenceThreshold [DERIVED] (also: ` — convergence threshold (terminates iteration) |
| 005acb44 | flt_5ACB44 | R | WheelbaseOrGearRatio [DERIVED] (also: ` — wheelbase or gear ratio constant) |
| 005acdc4 | flt_5ACDC4 | R | WetSecondaryStiffness [DERIVED] (also: ` — wet secondary scale) |
| 005aceb8 | flt_5ACEB8 | R | SuspensionOffsetConstant [DERIVED] (also: ` — constant offset in brush model) |
| 005acee8 | flt_5ACEE8 | R | FrontRearDistributionWeight [DERIVED] |
| 005ad1b0 | flt_5AD1B0 | R | TireDryGripMult2 [DERIVED] (also: ` — dry grip secondary multiplier) |
| 005ad1b4 | flt_5AD1B4 | R | DryGripMultiplier [DERIVED] |
| 005ad1b8 | flt_5AD1B8 | R | SuspensionMomentArm [DERIVED] (also: ` — moment arm constant) |
| 005ad1bc | flt_5AD1BC | R | RearDistributionWeight [DERIVED] |
| 005ad1c0 | flt_5AD1C0 | R | CorneringStiffnessCoeff [DERIVED] (also: ` — cornering stiffness coefficient) |
| 007d020c | flt_7D020C | R | WetGripMultiplier [DERIVED] |
| 007d0230 | flt_7D0230 | R | WetStiffnessMult [DERIVED] (also: ` — wet stiffness scale) |
| 007d0254 | flt_7D0254 | R | WetForceScale [DERIVED] |
| 007d0278 | flt_7D0278 | R | SpeedScalingDenominator [DERIVED] |
| 007d029c | flt_7D029C | R | SuspensionRefSpeed [DERIVED] (also: ` — reference speed) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005895a2 | sub_5895A2 | floor/clamp double to integer for table index lookup (converts force value to [0,13] index) |

**Guard conditions:** 
- `a2` (bool): selects dry (true) vs wet (false) grip scaling. Dry path multiplies forces by 0.92/0.84 with adhesion factor. Wet path applies globals flt_7D020C, flt_7D0230, flt_7D0254 as grip/stiffness/force multipliers.
- `v21` at this+0x39B4 (load transfer mode): 0 uses front axle weight for CoG factor, 1 uses all-four average, 2 uses rear axle weight.
- Slip index clamping: if v64 < 0 forces use table index 0; if v64 >= 14 clamps to index 13.
- Binary search convergence: loop exits when step size `v82 < 0.4`, indicating slip ratio has converged.
- Division by zero guard: if `v71 == 0.0` (no change in force/slip slope), uses raw slip value. Otherwise interpolates.
- Negative slip clamp: if final slip `v73 < 0.0`, clamps to 0.0.
