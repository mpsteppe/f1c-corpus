## LinkedListDispatchWithVTableCalls_004a1d50 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4B0770 (004b0770)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(obj+0x0)+0x0) | 0x0 | R | — | [LLM] |
| *(obj+0x0) | 0x0 | R | — | [LLM] |
| *(this+0xC) | 0x0 | R | — | [LLM] |
| *(this+0xC) | 0x4 | R | — | [LLM] |
| obj | 0x0 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x8 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x8: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00566cf0 | ResourceLookupWithDualPath | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x0 | == | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
