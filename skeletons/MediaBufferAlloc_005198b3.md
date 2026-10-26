## MediaBufferAlloc_005198b3 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_516C7B (00516c7b)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x19C) | 0x8 | R | — | [LLM] |
| *(this+0x4) | 0x0 | R | — | [LLM] |
| *(this+0x4) | 0x8 | R | — | [LLM] |
| *(this+0xC4) | 0x24 | R | — | [LLM] |
| obj | 0x0 | R | — | [LLM] |
| obj | 0x14 | RW | 46 | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x4 | R | — | [LLM] |
| this | 0x20 | R | — | [LLM] |
| this | 0xC4 | R | — | [LLM] |
| this | 0x114 | R | — | [LLM] |
| this | 0x180 | RW | — | [LLM] |
| this | 0x19C | R | — | [LLM] |

**Written-by note (persistence):**
- obj 0x14: [LLM: once/conditional? does external poke survive?]
- this 0x180: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0051984b | PlaybackStateController | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00519375 | VertexBufferOffsetSetup | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x20 | > | 0 | [LLM] |
| this | 0x114 | < | 2 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
