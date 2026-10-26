## QueuePop_004b7a00 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4B7500 (004b7500), LoadingPhase1 (004b87c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x714) | 0x0 | R | — | [LLM] |
| *(this+0x718) | 0x0 | R | — | [LLM] |
| this | 0x714 | R | — | [LLM] |
| this | 0x718 | R | — | [LLM] |
| this | 0x71C | RW | — | [LLM] |
| this | 0x720 | R | — | [LLM] |
| this | 0xF30 | RW | 0 | [LLM] |
| this | 0xF34 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x71C: [LLM: once/conditional? does external poke survive?]
- this 0xF30: [LLM: once/conditional? does external poke survive?]
- this 0xF34: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b7860 | sub_4B7860 | [LLM] |
| 00566d70 | FileSizeQueryWithFallback | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x720 | <= | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
