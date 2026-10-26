## VertexBufferOffsetSetup_00519375 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** MediaBufferAlloc (005198b3)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x180) | 0x38 | RW | — | [LLM] |
| *(this+0x180) | 0x3C | RW | — | [LLM] |
| *(this+0x4) | 0x0 | R | — | [LLM] |
| *(this+0xC4) | 0xC | R | — | [LLM] |
| *(this+0xC4) | 0x24 | R | — | [LLM] |
| this | 0x4 | R | — | [LLM] |
| this | 0x20 | R | — | [LLM] |
| this | 0xC4 | R | — | [LLM] |
| this | 0x114 | R | — | [LLM] |
| this | 0x180 | R | — | [LLM] |

**Written-by note (persistence):**
- *(this+0x180) 0x38: [LLM: once/conditional? does external poke survive?]
- *(this+0x180) 0x3C: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x20 | > | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
