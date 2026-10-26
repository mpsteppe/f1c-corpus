## LinkedListDestructor_8480_004b8480 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** MenuActionDispatch (004b9da0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x6C0)+0x0) | 0x4 | R | — | [LLM] |
| *(*(this+0x6C0)+0x4) | 0x4 | R | — | [LLM] |
| *(this+0x6C0) | 0x0 | R | — | [LLM] |
| *(this+0x6C0) | 0xC | R | — | [LLM] |
| this | 0x6C0 | RW | 0 | [LLM] |
| this | 0x6C4 | RW | 0 | [LLM] |
| this | 0x6C8 | RW | 0 | [LLM] |
| this | 0x6CC | RW | 0 | [LLM] |
| this | 0x6D0 | RW | 1 | [LLM] |

**Written-by note (persistence):**
- this 0x6C0: [LLM: once/conditional? does external poke survive?]
- this 0x6C4: [LLM: once/conditional? does external poke survive?]
- this 0x6C8: [LLM: once/conditional? does external poke survive?]
- this 0x6CC: [LLM: once/conditional? does external poke survive?]
- this 0x6D0: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bcf | FreeWrapper_7bcf | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
