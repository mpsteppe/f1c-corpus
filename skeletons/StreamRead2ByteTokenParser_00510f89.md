## StreamRead2ByteTokenParser_00510f89 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CommandDispatchStateMachine (0051126a)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x14)+0x0) | 0x0 | R | — | [LLM] |
| *(this+0x14) | 0x0 | RW | — | [LLM] |
| *(this+0x14) | 0x4 | RW | — | [LLM] |
| *(this+0x14) | 0xC | R | — | [LLM] |
| obj | 0x0 | R | — | [LLM] |
| obj | 0x4 | R | — | [LLM] |
| obj | 0x14 | RW | 81 | [LLM] |
| obj | 0x18 | RW | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x14 | R | — | [LLM] |
| this | 0xFC | RW | — | [LLM] |

**Written-by note (persistence):**
- *(this+0x14) 0x0: [LLM: once/conditional? does external poke survive?]
- *(this+0x14) 0x4: [LLM: once/conditional? does external poke survive?]
- obj 0x14: [LLM: once/conditional? does external poke survive?]
- obj 0x18: [LLM: once/conditional? does external poke survive?]
- this 0xFC: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
