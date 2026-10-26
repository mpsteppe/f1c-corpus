## ParamRangeClampedLerp_0049f530 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SteeringWheelAnimation (0049d070)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0049f670 | jpt_49F55C | R | [LLM] |
| 0049f684 | jpt_49F5F5 | R | [LLM] |
| 0059eab0 | dbl_59EAB0 | R | LinearTransformBias [DERIVED] (also: ` — linear transform coefficients) |
| 0059eab8 | dbl_59EAB8 | R | LinearTransformCoeffB [DERIVED] |
| 0059eac0 | dbl_59EAC0 | R | UnitConvCoeffA [DERIVED] |
| 005acafc | flt_5ACAFC | R | TemperatureOffset [DERIVED] (also: ` — additive offset) |
| 005acb10 | flt_5ACB10 | R | AudioAmpScale34 [DERIVED] (also: ` — multiplier for cases 3,4) |
| 007c7428 | dbl_7C7428 | R | RaceTimeElapsed [DERIVED] |
| 007c9174 | dbl_7C9174 | R | ParamBaseValueA [DERIVED] |
| 007c919c | dbl_7C919C | R | ParamBaseValue [DERIVED] (also: ` — parameter base values (case-dependent) |
| 007c91b4 | dbl_7C91B4 | R | ParameterBaseCase1 [DERIVED] |
| 007ce234 | unk_7CE234 | R | DriverAppearanceFlag [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00447bb0 | TireFrictionCurveEval | [LLM] |
| 0049b8d0 | SpeedMultiplier | [LLM] |
| 0049ed00 | FieldSetterTrigger | [LLM] |
| 0049ed10 | GuardedCall | [LLM] |
| 0049ed20 | sub_49ED20 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
