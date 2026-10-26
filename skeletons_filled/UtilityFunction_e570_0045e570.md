## UtilityFunction_e570_0045e570 — PhysicsYGuardAnimationUpdate

**Summary:** Checks physics Y flag byte; if zero, triggers animation timing update with parameter set. Returns the flag value.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SessionSynchronizer (0045f950), TrackOpeningProgressTimer (004612e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x20 | R | — | PhysY [FACT] — guard flag: if nonzero, skip animation update |
| this | 0x3FB8 | R | — | Parameter set pointer passed to AnimationTimingUpdateWithParamSet |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0057a5a0 | AnimationTimingUpdateWithParamSet | Update animation timing with parameter set |

**Guard conditions:**
- this+0x20 (PhysY) != 0 → early return (skip animation update, return PhysY value).
- this+0x20 == 0 → call AnimationTimingUpdateWithParamSet(this+0x3FB8), return 0.
