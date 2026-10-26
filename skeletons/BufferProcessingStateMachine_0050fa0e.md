## BufferProcessingStateMachine_0050fa0e — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** StateMachineWithDispatch (0050fb3b)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x17C) | 0x0 | R | — | [LLM] |
| *(this+0x17C) | 0x4 | R | — | [LLM] |
| *(this+0x17C) | 0x8 | R | — | [LLM] |
| *(this+0x180) | 0x4 | R | — | [LLM] |
| *(this+0x8) | 0x0 | R | — | [LLM] |
| *(this+0x8) | 0x4 | RW | — | [LLM] |
| *(this+0x8) | 0x8 | RW | — | [LLM] |
| this | 0x8 | R | — | [LLM] |
| this | 0x10 | RW | 204 | [LLM] |
| this | 0x41 | R | — | [LLM] |
| this | 0x60 | R | — | [LLM] |
| this | 0x78 | RW | 0 | [LLM] |
| this | 0x17C | R | — | [LLM] |
| this | 0x180 | R | — | [LLM] |

**Written-by note (persistence):**
- *(this+0x8) 0x4: [LLM: once/conditional? does external poke survive?]
- *(this+0x8) 0x8: [LLM: once/conditional? does external poke survive?]
- this 0x10: [LLM: once/conditional? does external poke survive?]
- this 0x78: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x10 | != | 204 | [LLM] |
| this | 0x41 | != | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
