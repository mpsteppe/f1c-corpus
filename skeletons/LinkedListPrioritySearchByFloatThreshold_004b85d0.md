## LinkedListPrioritySearchByFloatThreshold_004b85d0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** MenuActionDispatch (004b9da0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x6C8)+0x0) | 0x0 | R | — | [LLM] |
| *(this+0x6C4) | 0x0 | R | — | [LLM] |
| *(this+0x6C8) | 0x0 | R | — | [LLM] |
| *(this+0x6C8) | 0x4 | R | — | [LLM] |
| *(this+0x6C8) | 0x8 | R | — | [LLM] |
| this | 0x6C0 | R | — | [LLM] |
| this | 0x6C4 | R | — | [LLM] |
| this | 0x6C8 | RW | 0 | [LLM] |
| this | 0x6CC | R | — | [LLM] |
| this | 0xF38 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x6C8: [LLM: once/conditional? does external poke survive?]
- this 0xF38: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005acd20 | flt_5ACD20 | R | SilenceClippingThreshold [DERIVED] (also: ` — search epsilon tolerance) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
