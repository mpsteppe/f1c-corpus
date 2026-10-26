## NetworkBufferRead_004b7c80 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4B7DE0 (004b7de0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x714) | 0x0 | R | — | [LLM] |
| *(this+0x714) | 0x4 | R | — | [LLM] |
| this | 0x714 | R | — | [LLM] |
| this | 0x71C | RW | — | [LLM] |
| this | 0x720 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x71C: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00566bd0 | ConditionalDispatch_6bd0 | [LLM] |
| 00566c00 | FileWriteWithBackendDispatch | [LLM] |
| 00566d70 | FileSizeQueryWithFallback | [LLM] |
| 00566db0 | sub_566DB0 | [LLM] |
| 00566e20 | ResourceLookupDispatcher | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
