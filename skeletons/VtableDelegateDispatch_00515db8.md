## VtableDelegateDispatch_00515db8 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** UIScreenStateMachine (00515df2)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x184) | 0x0 | R | — | [LLM] |
| *(this+0x184) | 0x4 | R | — | [LLM] |
| *(this+0x18C) | 0x0 | RW | — | [LLM] |
| *(this+0x194) | 0x0 | R | — | [LLM] |
| this | 0x184 | R | — | [LLM] |
| this | 0x18C | R | — | [LLM] |
| this | 0x194 | R | — | [LLM] |

**Written-by note (persistence):**
- *(this+0x18C) 0x0: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00515bb0 | AudioVoiceChannelAllocation | [LLM] |
| 00515d26 | ObjectBufferCopyWithValidation | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
