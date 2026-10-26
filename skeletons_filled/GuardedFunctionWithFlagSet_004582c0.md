## GuardedFunctionWithFlagSet_004582c0 — GuardedSplineEvaluate

**Summary:** Wraps CubicSplineInterpolation with null-pointer guard and active flag. If keyframe array pointer (this[0]) is NULL, returns 0 immediately without side effects. Otherwise sets flag at offset 0x1C to 1, delegates to CubicSplineInterpolation(this, a2), and returns the interpolation result.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4348B0 (004348b0), SteeringInterpolationCameraFollow (00434d60), SuspensionWheelForceCalculation (00459070)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | pointer to keyframe array; NULL-check guard |
| this | 0x1C | RW | 1 | active flag: set to 1 before spline evaluation |

**Written-by note (persistence):**
- this 0x1C: written to 1 every call when this[0] != NULL. External poke overwritten each call.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If this[0] == NULL → return 0 immediately, skip flag set and interpolation. NULL keyframe array means uninitialized path data.
