## RPMRangeLoader_004f6bf0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

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
| 005651b0 | sub_5651B0 | [LLM] |
| 00565870 | sub_565870 | [LLM] |
| 00566cc0 | ConditionalDispatchBasedOnFlag | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
