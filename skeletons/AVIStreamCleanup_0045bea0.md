## AVIStreamCleanup_0045bea0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_45BE80 (0045be80)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x38 | RW | 0 | [LLM] |
| this | 0x3C | RW | 0 | [LLM] |
| this | 0x40 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x38: [LLM: once/conditional? does external poke survive?]
- this 0x3C: [LLM: once/conditional? does external poke survive?]
- this 0x40: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00534ae6 | AVIFileRelease | [LLM] |
| 00534aec | AVIStreamRelease | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
