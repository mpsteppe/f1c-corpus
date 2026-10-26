## ConditionalDualCleanup_00499b50 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DestructorWithFreeCondition (00477ee0), ConditionalConstructorDestructor (00485720), DestructorWithTripleFree (00485870), DestructorWithConditionalFree_5900 (00485900), UIListObjectDestructor (00485960), LinkedListDtor (004859d0), DualCleanupWithConditionalFree (004881b0), TreeNodeRecursiveDestructor (00499da0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x2C | R | — | [LLM] |
| this | 0x30 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x30: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008afe64 | dword_8AFE64 | R | RaceTimeDelta [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005539f0 | ResourceCascadeCleanup | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
