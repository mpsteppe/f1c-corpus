## StringCopyNodeAlloc_005493b0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_55A790 (0055a790)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x110)+0x14) | 0x14 | RW | — | [LLM] |
| this | 0xFC | RW | 0 | [LLM] |
| this | 0x110 | R | — | [LLM] |

**Written-by note (persistence):**
- *(*(this+0x110)+0x14) 0x14: [LLM: once/conditional? does external poke survive?]
- this 0xFC: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00548e00 | ShortComputation_8e00 | [LLM] |
| 00587c03 | OperatorNewNhMallocWrapper | [LLM] |
| 00589901 | sub_589901 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
