## LinkedListNodeRemovalByValue_00491d30 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ResourcePoolNodeAllocDealloc (00490940)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(obj+0x4) | 0x0 | R | — | [LLM] |
| *(obj+0x4) | 0x4 | R | — | [LLM] |
| *(obj+0x4) | 0x8 | RW | 0 | [LLM] |
| obj | 0x4 | RW | — | [LLM] |
| this | 0x0 | RW | — | [LLM] |
| this | 0x4 | RW | — | [LLM] |
| this | 0x8 | RW | — | [LLM] |
| this | 0xC | R | — | [LLM] |

**Written-by note (persistence):**
- *(obj+0x4) 0x8: [LLM: once/conditional? does external poke survive?]
- obj 0x4: [LLM: once/conditional? does external poke survive?]
- this 0x0: [LLM: once/conditional? does external poke survive?]
- this 0x4: [LLM: once/conditional? does external poke survive?]
- this 0x8: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bcf | FreeWrapper_7bcf | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
