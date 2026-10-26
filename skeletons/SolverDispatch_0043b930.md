## SolverDispatch_0043b930 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** ConditionalMathDispatch (004f1860)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0043b9d8 | jpt_43B947 | R | [LLM] |
| 0043b9f8 | byte_43B9F8 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00436470 | QuadraticSpringEval | [LLM] |
| 0043ba20 | ConstraintForceSolver | [LLM] |
| 0043bb00 | DeltaUpdateTracking | [LLM] |
| 0043bb30 | QuadFunctionEval | [LLM] |
| 0043bb80 | QuadraticForceTorqueCalculator | [LLM] |
| 0043bbd0 | SpringDamperCompute | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
