## ArithmeticComparison_9ad0_004f9ad0 — GlobalTimeAccumulatorUpdate

**Summary:** Advances multiple time accumulator globals (SessionTime, InputAxisDeadZone, EngineCoolingRate, ScoringDefaultReturn) by the same delta value obtained from sub_556730.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** AutoJoinRetryLoop (004637a0), Options_Setup (004a0eb0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008afe64 | dword_8AFE64 | R | RaceTimeDelta [DERIVED] |
| 008afe90 | dbl_8AFE90 | RW | EngineCoolingRate [DERIVED] (also: ` — cooling rate per frame) — Set each call (delta from sub_556730) |
| 008afe94 | byte_8AFE94 | R | RaceTimeAbsolute2 [DERIVED] |
| 008afe98 | dbl_8AFE98 | W | ScoringDefaultReturn [DERIVED] (also: ` — default return value (float) — Copied from delta |
| 008afe9c | byte_8AFE9C | W | TimeAccumulator_A [DERIVED] |
| 008afea0 | dbl_8AFEA0 | RW | SessionTime [DERIVED] (also: ` — current session time (passed to FUN_0040f300) — Incremented by delta |
| 008afea8 | dbl_8AFEA8 | RW | InputAxisDeadZone [DERIVED] (also: ` — axis threshold (float) — Incremented by delta |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00556730 | sub_556730 | Returns frame delta time value used to advance accumulators |

**Guard conditions:** None.
