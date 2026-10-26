## UtilityFunction_84b0_004184b0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xAF0 | RW | 0 | [LLM] |
| this | 0xAF4 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0xAF0: [LLM: once/conditional? does external poke survive?]
- this 0xAF4: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00411680 | ShortArrayInit | [LLM] |
| 004144d0 | StructInitWithSentinelValues | [LLM] |
| 004186a0 | BufferInitWith10fDefaults | [LLM] |
| 004b0170 | EmptyStub_0170 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
