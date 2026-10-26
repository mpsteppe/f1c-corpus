## FieldCompareConstant_005001d0 — Field sentinel comparison (not equal to FLT_MIN-like value)

**Summary:** Returns TRUE if `this[111]` (offset 0x1BC) is NOT equal to `-9.9999997e37` (a very large negative sentinel). Used to check whether a struct field has been initialized/set. Shared utility across many callers.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** FloatComparisonListIteration (004b5380), ListWalkWithUserCancelCheck (004b5460), CollisionFilterAABBCull (004b5630), LinkedListIteratorWithStateUpdate (004b5760), sub_4B9000 (004b9000), sub_4B9AC0 (004b9ac0), AudioSampleCrossFadeInterpolation (004ff8f0), CollisionTestWithThreshold (00500560)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1BC | R | — | Sentinel/initialization-status field; compared against -FLT_MAX-like value |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ad348 | flt_5AD348 | R | SetupDefaultSentinel [DERIVED] (also: ` — default sentinel value -9.9999997e37) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Returns `this[111] != -9.9999997e37`. Passes (TRUE) when field has been written to; blocked (FALSE) when field still holds the uninitialized sentinel value.
