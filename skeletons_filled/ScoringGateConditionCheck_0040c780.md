## ScoringGateConditionCheck_0040c780 — ScoringGateDelta

**Summary:** Returns a float delta based on scoring gate state. When gate equals 2, computes absolute difference of scoring data; otherwise returns a default float constant. Used as timer decrement by callers.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CameraModeViewportUpdate (00409a00), CameraShake (0040adb0), CameraTransformComputation (0040b710), RandomStateMachineWithTimerAndTrigger (0040c070)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008ab6e4 | dword_8AB6E4 | R | ScoringGate [CONFIRMED] — selects which return value to provide |
| 008ab6ec | dword_8AB6EC | R | ScoringDataPtr [DERIVED] — pointer passed to FloatDifference when gate == 2 |
| 008afe98 | dbl_8AFE98 | R | ScoringDefaultReturn [DERIVED] — default float return value when gate != 2 |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b9cf0 | FloatDifference | computes difference of scoring data for absolute value when gate == 2 |

**Guard conditions:** if dword_8AB6E4 == 2, returns fabs(FloatDifference(ScoringDataPtr)); otherwise returns dbl_8AFE98 (default).
