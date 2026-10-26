## sub_510ACC_00510acc — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CommandDispatchStateMachine (0051126a)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x14) | 0x0 | R | — | [LLM] |
| obj | 0x0 | R | — | [LLM] |
| obj | 0x4 | R | — | [LLM] |
| obj | 0x14 | RW | 29 | [LLM] |
| obj | 0x18 | RW | — | [LLM] |
| obj | 0x1C | RW | — | [LLM] |
| obj | 0x20 | RW | — | [LLM] |
| obj | 0x24 | RW | — | [LLM] |
| obj | 0x28 | RW | — | [LLM] |
| obj | 0x2C | RW | — | [LLM] |
| obj | 0x30 | RW | — | [LLM] |
| obj | 0x34 | RW | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x14 | RW | — | [LLM] |
| this | 0x18 | RW | — | [LLM] |
| this | 0x20 | R | — | [LLM] |

**Written-by note (persistence):**
- obj 0x14: [LLM: once/conditional? does external poke survive?]
- obj 0x18: [LLM: once/conditional? does external poke survive?]
- obj 0x1C: [LLM: once/conditional? does external poke survive?]
- obj 0x20: [LLM: once/conditional? does external poke survive?]
- obj 0x24: [LLM: once/conditional? does external poke survive?]
- obj 0x28: [LLM: once/conditional? does external poke survive?]
- obj 0x2C: [LLM: once/conditional? does external poke survive?]
- obj 0x30: [LLM: once/conditional? does external poke survive?]
- obj 0x34: [LLM: once/conditional? does external poke survive?]
- this 0x14: [LLM: once/conditional? does external poke survive?]
- this 0x18: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00516990 | BufferAccessNullTerminate | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
