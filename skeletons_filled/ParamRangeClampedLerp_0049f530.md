## ParamRangeClampedLerp_0049f530 — ParamClampedLerpDispatch

**Summary:** Reads a parameter value (speed, temperature, pressure, friction) based on mode index (0-4), applies unit conversion and range clamping, then stores the normalized range and offset into struct a2 and calls field setter/guarded call chain.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SteeringWheelAnimation (0049d070)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0049f670 | jpt_49F55C | R | Jump table pointer for outer switch (cases 0-4) |
| 0049f684 | jpt_49F5F5 | R | Jump table pointer for inner switch (unit conversion cases) |
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
| 00447bb0 | TireFrictionCurveEval | Evaluates tire friction curve from elapsed time |
| 0049b8d0 | SpeedMultiplier | Returns speed multiplier value (mode 0) |
| 0049ed00 | FieldSetterTrigger | Stores normalized offset into struct field |
| 0049ed10 | GuardedCall | Guarded call chain processing |
| 0049ed20 | sub_49ED20 | Additional field processing after guard |

**Guard conditions:** Checks a1 <= 4 && a3 != 0 — PASSES (process param), BLOCKED (return); inner guard: checks a1==1/2 for temp conversion, a1==3/4 for pressure conversion
