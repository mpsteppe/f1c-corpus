## LapSpeedComparisonWithSwitchSelectableThresholds_004b66e0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4B6360 (004b6360)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x9AC | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004b67ac | jpt_4B66EC | R | [LLM] |
| 004b67bc | jpt_4B6755 | R | [LLM] |
| 0059e444 | flt_59E444 | R | FrameDelta [DERIVED] (also: ` — float 0.016667 (1/60, frame delta) |
| 0059e44c | flt_59E44C | R | Flt_CollisionTolerance [DERIVED] |
| 0059e800 | flt_59E800 | R | AmplitudeLimit [DERIVED] (also: ` — under-relaxation upper bound) |
| 0059e8f4 | flt_59E8F4 | R | PhysicsThreshold_59E8F4 [DERIVED] |
| 005acd3c | flt_5ACD3C | R | AeroDragCoefficient [DERIVED] (also: ` — aero constant) |
| 005acd40 | flt_5ACD40 | R | TireGripScaleFactor [DERIVED] |
| 005acd44 | flt_5ACD44 | R | TireLateralForceCoeff1 [DERIVED] |
| 005acd48 | flt_5ACD48 | R | TireGripThreshold [DERIVED] |
| 005acd4c | flt_5ACD4C | R | WheelRateInterpMult [DERIVED] |
| 005acd50 | flt_5ACD50 | R | SuspensionBumpStopScale [DERIVED] |
| 005acd54 | flt_5ACD54 | R | WheelSlipThreshold [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
