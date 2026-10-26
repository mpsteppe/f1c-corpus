## StateMachineDispatch_0050f86a — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** StateMachineDispatch_f9ab (0050f9ab)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x0 | R | — | [LLM] |
| obj | 0x14 | RW | 18 | [LLM] |
| obj | 0x18 | RW | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x10 | RW | 202 | [LLM] |
| this | 0x14 | R | — | [LLM] |
| this | 0x1C | R | — | [LLM] |
| this | 0x18C | R | — | [LLM] |
| this | 0x190 | R | — | [LLM] |

**Written-by note (persistence):**
- obj 0x14: [LLM: once/conditional? does external poke survive?]
- obj 0x18: [LLM: once/conditional? does external poke survive?]
- this 0x10: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0050f6f7 | sub_50F6F7 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
