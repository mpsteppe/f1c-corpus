## DualListDestruction_00498d90 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** FAILWRONGTRIAGE_8d70 (00498d70)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x48) | 0x0 | R | — | [LLM] |
| *(this+0x90) | 0x48 | R | — | [LLM] |
| this | 0x0 | RW | — | [LLM] |
| this | 0x48 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: once/conditional? does external poke survive?]
- this 0x48: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ac9e8 | off_5AC9E8 | R | VTable_5AC9E8 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00486320 | StructFieldAccessor | [LLM] |
| 00498f60 | ShortComputation_8f60 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
