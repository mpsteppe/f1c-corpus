## EngineFailureCheck_004bec55 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e4e8 | flt_59E4E8 | R | PhysicsScale_E4E8 [DERIVED] (also: ` — physics/math scaling constant) |
| 0059e7fc | flt_59E7FC | R | BumpDampingConstant [DERIVED] (also: ` — bump damping constants) |
| 0059e8b4 | flt_59E8B4 | R | ClampUpperThreshold [DERIVED] |
| 0059e8fc | flt_59E8FC | R | AccelAccumLimit [DERIVED] |
| 005acaec | flt_5ACAEC | R | AITireGripThreshold [DERIVED] |
| 005acaf0 | flt_5ACAF0 | R | ABNormalThreshold2 [DERIVED] |
| 005acdd8 | flt_5ACDD8 | R | CrashDetectionThreshold [DERIVED] |
| 005acddc | flt_5ACDDC | R | AIDecisionRandomizer [DERIVED] |
| 007c56a4 | dword_7C56A4 | R | SessionType [FACT] |
| 008aae70 | dword_8AAE70 | RW | RingBufferCounter (QA/weather noise) [DERIVED] |
| 008aae74 | flt_8AAE74 | R | TrigLookup256 [DERIVED] (also: ` — 256-entry trig lookup table) |
| 008acf90 | flt_8ACF90 | R | RaceTimeOffset [DERIVED] |
| 008afea0 | dbl_8AFEA0 | RW | SessionTime [DERIVED] (also: ` — current session time (passed to FUN_0040f300) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0042ae90 | StateFlagsLookup | [LLM] |
| 004b33b0 | ProgressBarEventEncode | [LLM] |
| 004bbfc0 | PitCrewStateMachine | [LLM] |
| 004bea10 | RandomVariationScaler | [LLM] |
| 004bef60 | AICollision | [LLM] |
| 004bf390 | AIDriverSorting | [LLM] |
| 004bf4f0 | AITickUpdate | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
