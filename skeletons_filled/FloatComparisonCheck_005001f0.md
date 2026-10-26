## FloatComparisonCheck_005001f0 — Float sentinel comparison (not equal to FLT_MAX-like value)

**Summary:** Returns TRUE if `this[3]` (offset 0xC) is NOT equal to `9.9999997e37` (FLT_MAX-like sentinel). Checks whether a float field has been initialized. Shared utility used by many collision/iteration functions.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** ConditionalStridePointerComputation (00463dc0), FloatComparisonListIteration (004b5380), LinkedListValidationWalk (004b54a0), CollisionFilterAABBCull (004b5630), LinkedListIteratorWithStateUpdate (004b5760), sub_4B9000 (004b9000), sub_4B9AC0 (004b9ac0), CollisionStateUpdate (00500010), CollisionTestWithThreshold (00500560)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | R | — | Float sentinel/initialization field; compared against FLT_MAX-like sentinel |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ad34c | flt_5AD34C | R | Flt_Sentinel_StructInit [DERIVED] (sentinel value 9.9999997e37) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Returns `this[3] != 9.9999997e37`. Passes (TRUE) when field has been written; blocked (FALSE) when field still holds uninitialized sentinel.
