## AudioPhysicsMixWithLerp_0040e2b0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** ShortComputation_e770 (0040e770), ConditionalAudioParamSetup (004dfa60)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e458 | flt_59E458 | R | ConstraintForceEpsilon [DERIVED] (also: ` — constraint force threshold (near-zero) |
| 0059e6e8 | flt_59E6E8 | R | TireDampingBlendFactor [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040e1f0 | GlobalVectorOffsetUpdate | [LLM] |
| 004dd550 | BoundingBoxComputation | [LLM] |
| 0054b3b0 | ThreeFieldSetterWithSubCall | [LLM] |
| 0054b420 | TripleFieldQuery | [LLM] |
| 0054c230 | LinkedListIndexedAccessor_c230 | [LLM] |
| 0054e100 | PackedArrayTotalSize | [LLM] |
| 0054e120 | PackedArrayIndexLookup | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
