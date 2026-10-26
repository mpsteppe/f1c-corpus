## NetworkThreadConnectionCleanup_0057edd0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0xB04) | 0x0 | R | — | [LLM] |
| *(this+0xB04) | 0x4 | RW | 0 | [LLM] |
| *(this+0xB04) | 0x8 | RW | 0 | [LLM] |
| *(this+0xB04) | 0xC | RW | 0 | [LLM] |
| this | 0xB00 | R | — | [LLM] |
| this | 0xB04 | R | — | [LLM] |
| this | 0xB08 | R | — | [LLM] |
| this | 0xB10 | R | — | [LLM] |
| this | 0xB14 | R | — | [LLM] |

**Written-by note (persistence):**
- *(this+0xB04) 0x4: [LLM: once/conditional? does external poke survive?]
- *(this+0xB04) 0x8: [LLM: once/conditional? does external poke survive?]
- *(this+0xB04) 0xC: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e1a0 | WaitForSingleObject | R | [LLM] |
| 0059e1a4 | ReleaseMutex | R | [LLM] |
| 0059e2d8 | __imp_htonl | R | [LLM] |
| 0059e2f4 | __imp_htons | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0057b9f0 | Copy4DwordsStructToStruct | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
