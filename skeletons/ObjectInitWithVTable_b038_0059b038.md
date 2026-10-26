## ObjectInitWithVTable_b038_0059b038 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ExceptionThrowWrapper (0059afff)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005b9d8c | ??_7out_of_range@std@@6B@ | R | StdOutOfRangeVtable [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0059ae7d | CObjectConstructorWithVtable | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
