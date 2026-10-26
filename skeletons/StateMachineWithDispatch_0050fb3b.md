## StateMachineWithDispatch_0050fb3b — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ImageTextureDecompressor (00501722)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x18C) | 0x0 | R | — | [LLM] |
| *(this+0x18C) | 0x10 | R | — | [LLM] |
| *(this+0x8) | 0x0 | R | — | [LLM] |
| *(this+0x8) | 0x4 | R | — | [LLM] |
| *(this+0x8) | 0x8 | RW | — | [LLM] |
| obj | 0x0 | R | — | [LLM] |
| obj | 0x14 | RW | 18 | [LLM] |
| obj | 0x18 | RW | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x8 | R | — | [LLM] |
| this | 0x10 | RW | 203 | [LLM] |
| this | 0x40 | R | — | [LLM] |
| this | 0x7C | R | — | [LLM] |
| this | 0x84 | RW | — | [LLM] |
| this | 0x118 | R | — | [LLM] |
| this | 0x18C | R | — | [LLM] |

**Written-by note (persistence):**
- *(this+0x8) 0x8: [LLM: once/conditional? does external poke survive?]
- obj 0x14: [LLM: once/conditional? does external poke survive?]
- obj 0x18: [LLM: once/conditional? does external poke survive?]
- this 0x10: [LLM: once/conditional? does external poke survive?]
- this 0x84: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0050fa0e | BufferProcessingStateMachine | [LLM] |
| 00516f76 | ObjectConstructor_6f76 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x10 | == | 202 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
