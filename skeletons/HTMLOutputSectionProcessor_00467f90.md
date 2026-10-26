## HTMLOutputSectionProcessor_00467f90 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** MenuLayoutCalculator (00467dc0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x100) | 0x0 | R | — | [LLM] |
| *(this+0x48) | 0x4 | R | — | [LLM] |
| *(this+0xF8) | 0x0 | R | — | [LLM] |
| this | 0x44 | RW | 0 | [LLM] |
| this | 0x48 | RW | 0 | [LLM] |
| this | 0x4C | RW | 0 | [LLM] |
| this | 0x50 | RW | 0 | [LLM] |
| this | 0xF8 | R | — | [LLM] |
| this | 0x100 | RW | — | [LLM] |
| this | 0x104 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x44: [LLM: once/conditional? does external poke survive?]
- this 0x48: [LLM: once/conditional? does external poke survive?]
- this 0x4C: [LLM: once/conditional? does external poke survive?]
- this 0x50: [LLM: once/conditional? does external poke survive?]
- this 0x100: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c6714 | aHeader2 | R | Header2String [DERIVED] |
| 005c6720 | aHeader_0 | R | String_Header [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00418d60 | DestructorWithDoubleFreePattern | [LLM] |
| 00486f30 | LinkedListInsertWithNodeAllocation | [LLM] |
| 00588410 | sub_588410 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
