## TireBrushModelForceSolver_004e8010 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** LargeConfigFunctionWithPhysicsConstants (004e45b0), CollisionWrapperWithLock (004e4910), ActorMotionPostProcessingUpdate (004ed030), RepairServiceStateDispatcher (004ed250), FuelConsumptionAndWear (004ed960), ScaleAudioPitch (004f1510), sub_4F18C0 (004f18c0), LoopWithConditionalSubCall (004f1a60)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x3514 | R | — | [LLM] |
| this | 0x3518 | R | — | [LLM] |
| this | 0x358C | R | — | [LLM] |
| this | 0x3594 | R | — | [LLM] |
| this | 0x3610 | R | — | [LLM] |
| this | 0x362C | R | — | [LLM] |
| this | 0x3638 | R | — | [LLM] |
| this | 0x3674 | R | — | [LLM] |
| this | 0x3684 | R | — | [LLM] |
| this | 0x368C | R | — | [LLM] |
| this | 0x3708 | R | — | [LLM] |
| this | 0x377C | R | — | [LLM] |
| this | 0x3784 | R | — | [LLM] |
| this | 0x3800 | R | — | [LLM] |
| this | 0x3874 | R | — | [LLM] |
| this | 0x387C | R | — | [LLM] |
| this | 0x38F8 | R | — | [LLM] |
| this | 0x39B4 | R | — | [LLM] |
| this | 0x3A30 | R | — | [LLM] |
| this | 0x3A44 | R | — | [LLM] |
| this | 0x3A6C | R | — | [LLM] |
| this | 0x3A70 | R | — | [LLM] |
| this | 0x3BF4 | R | — | [LLM] |
| this | 0x3BFC | RW | — | [LLM] |
| this | 0x3C3C | RW | — | [LLM] |
| this | 0x3C40 | R | — | [LLM] |
| this | 0x3C7C | RW | — | [LLM] |
| this | 0x3C80 | R | — | [LLM] |
| this | 0x3CBC | RW | — | [LLM] |
| this | 0x3CC0 | RW | — | [LLM] |
| this | 0x3CFC | RW | — | [LLM] |
| this | 0x3D3C | RW | — | [LLM] |
| this | 0x3D40 | RW | — | [LLM] |
| this | 0x3D44 | RW | — | [LLM] |
| this | 0x4024 | R | — | [LLM] |

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
| 005895a2 | sub_5895A2 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
