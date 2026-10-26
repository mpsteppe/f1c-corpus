## CollisionSystemInit_0047c960 — CollisionSystemTimeUpdate

**Summary:** Clamps input parameter to [0.0, 1.0], computes weighted collision value as (thunkResult * clamp(input) + vehicleLifetimeAverage), and updates global collision state via SingleCallWrapper_9cd0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** TimerBasedFloatDispatch (0047ca30)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] — float threshold for collision calculations |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] — epsilon for zero comparison |
| 008ab6ec | dword_8AB6EC | R | ScoringDataPtr [DERIVED] — global scoring/collision data pointer |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0047c9d0 | ThunkToFUN004b9c80 | retrieve base physics value for weighted collision calculation |
| 004b9cb0 | VehicleLifetimeAverageAccessor | retrieve vehicle lifetime average value from scoring data |

**Guard conditions:** none — always executes; input clamped to [0.0, 1.0] before computation
