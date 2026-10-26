## LinkedListDestroyAt0x444_0047fbd0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x444) | 0x0 | R | — | [LLM] |
| *(this+0x448) | 0x4 | R | — | [LLM] |
| this | 0x444 | RW | 0 | [LLM] |
| this | 0x448 | RW | 0 | [LLM] |
| this | 0x44C | RW | 0 | [LLM] |
| this | 0x450 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x444: [LLM: once/conditional? does external poke survive?]
- this 0x448: [LLM: once/conditional? does external poke survive?]
- this 0x44C: [LLM: once/conditional? does external poke survive?]
- this 0x450: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0048ca50 | LinkedListDestructor | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
