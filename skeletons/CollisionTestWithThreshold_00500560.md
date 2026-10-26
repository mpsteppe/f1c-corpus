## CollisionTestWithThreshold_00500560 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** UtilityFunction_3d50 (00463d50)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1BC | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e600 | flt_59E600 | R | SteeringForceThreshold [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b3a90 | ArithmeticComparison_3a90 | [LLM] |
| 004ff680 | AudioParameterInterpolation | [LLM] |
| 004ff8f0 | AudioSampleCrossFadeInterpolation | [LLM] |
| 005000e0 | PhysicsFloatUpdateWithCompare | [LLM] |
| 005001d0 | FieldCompareConstant | [LLM] |
| 005001f0 | FloatComparisonCheck | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
