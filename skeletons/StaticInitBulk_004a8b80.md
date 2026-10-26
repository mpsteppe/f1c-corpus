## StaticInitBulk_004a8b80 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ProfileAlreadyExistsPageHandler (0046cb50)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(obj+0x0) | 0x4 | R | — | [LLM] |
| obj | 0x0 | R | — | [LLM] |
| obj | 0x8 | R | — | [LLM] |
| this | 0x0 | RW | 0 | [LLM] |
| this | 0x4 | RW | 0 | [LLM] |
| this | 0x8 | RW | 0 | [LLM] |
| this | 0xC | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: once/conditional? does external poke survive?]
- this 0x4: [LLM: once/conditional? does external poke survive?]
- this 0x8: [LLM: once/conditional? does external poke survive?]
- this 0xC: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004aa1b0 | FreeTwoPointers | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00401030 | ArrayDestructorIterator | [LLM] |
| 00414370 | ShortComputation_4370 | [LLM] |
| 004aa170 | MultiPointerFree_a170 | [LLM] |
| 004aa1b0 | FreeTwoPointers | [LLM] |
| 004c1700 | DoubleListCleanup | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
