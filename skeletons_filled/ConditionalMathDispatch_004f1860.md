## ConditionalMathDispatch_004f1860 — ConditionalSolverDispatch

**Summary:** Dispatches solver call when rigid body constraint is absent. Part of physics solver dispatch system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** PitStopOperationTimer (004a6340)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x32BC | R | — | Rigid body constraint pointer (dispatch gate) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007c7428 | dbl_7C7428 | R | RaceTimeElapsed [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0043b930 | SolverDispatch | Dispatches physics solver with race time and parameters |

**Guard conditions:** Checks rigid body ptr (this+0x32BC). PASSES (dispatches solver) when ptr is zero. BLOCKED (no action) when ptr is nonzero.
