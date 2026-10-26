## RPMRangeLoader_004f6bf0 — RPMRangeLoader

**Summary:** Parses MinRPM, MaxRPM, and NatRPM string key-value pairs for a given gear index (0-4), converts RPM to rad/s (multiply by pi/30), and stores result in `this[3*a3 + {1,2,3}]`. Natural RPM stores the inverse (1/value).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4F7460 (004f7460)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e420 | dbl_59E420 | R | BaseDoubleConstant [DERIVED] (also: ` (BaseDoubleConstant = 1.0) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 005ad258 | dbl_5AD258 | R | PhysicsConstant_5AD258 [DERIVED] |
| 005d67d4 | aNaturalrpm | R | NaturalrpmString [DERIVED] |
| 005d67e0 | aMaximumrpm | R | MaximumRPMStr [DERIVED] |
| 005d67ec | aMinimumrpm | R | MinimumRPMString [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005651b0 | sub_5651B0 | Reads/advances parser state; returns 0 for data, 2 for EOF/error |
| 00565870 | sub_565870 | Parses float value from key-value string pair by key name |
| 00566cc0 | ConditionalDispatchBasedOnFlag | Initializes/iterates configuration parsing loop |

**Guard conditions:** `a3 <= 4` — PASSES if gear index 0-4, BLOCKED if >=5 (range guard). Loop runs while `ConditionalDispatchBasedOnFlag` returns non-zero. sub_5651B0 returning 2 causes early return (EOF/error). Natural RPM value > 0.0 required for inverse computation, else stores 0.0.
