## BufferAppendWithMemset_005992ef — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_598E9E (00598e9e), sub_5990AE (005990ae), sub_599ED6 (00599ed6), sub_59A103 (0059a103)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | [LLM] |
| this | 0x8 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x8: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005b9c38 | dword_5B9C38 | R | SetupConstantValue [DERIVED] (also: setup constant) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058bb10 | sub_58BB10 | [LLM] |
| 00599560 | sub_599560 | [LLM] |
| 0059ad49 | sub_59AD49 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
