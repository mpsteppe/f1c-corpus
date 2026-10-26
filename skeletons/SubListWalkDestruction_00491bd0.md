## SubListWalkDestruction_00491bd0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_496E90 (00496e90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(obj+0xC)+0x4) | 0x4 | R | — | [LLM] |
| *(obj+0x14) | 0x0 | R | — | [LLM] |
| *(obj+0x14) | 0x4 | R | — | [LLM] |
| *(obj+0xC) | 0x0 | R | — | [LLM] |
| *(obj+0xC) | 0x8 | R | — | [LLM] |
| obj | 0xC | RW | 0 | [LLM] |
| obj | 0x10 | RW | 0 | [LLM] |
| obj | 0x14 | RW | 0 | [LLM] |
| obj | 0x18 | RW | 0 | [LLM] |
| this | 0x0 | R | — | [LLM] |

**Written-by note (persistence):**
- obj 0xC: [LLM: once/conditional? does external poke survive?]
- obj 0x10: [LLM: once/conditional? does external poke survive?]
- obj 0x14: [LLM: once/conditional? does external poke survive?]
- obj 0x18: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00490aa0 | LinkedListNodePrepend | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
