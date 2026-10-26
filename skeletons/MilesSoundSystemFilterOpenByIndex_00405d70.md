## MilesSoundSystemFilterOpenByIndex_00405d70 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x54 | R | — | [LLM] |
| this | 0x60 | RW | — | [LLM] |
| this | 0x64 | RW | — | [LLM] |
| this | 0x68 | RW | — | [LLM] |
| this | 0xE4 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x60: [LLM: once/conditional? does external poke survive?]
- this 0x64: [LLM: once/conditional? does external poke survive?]
- this 0x68: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e3b0 | _AIL_enumerate_filters@12 | R | [LLM] |
| 0059e3b4 | _AIL_open_filter@8 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00404fa0 | sub_404FA0 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
