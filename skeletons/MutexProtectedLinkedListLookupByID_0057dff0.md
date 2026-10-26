## MutexProtectedLinkedListLookupByID_0057dff0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_57CB50 (0057cb50), sub_57D6C0 (0057d6c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(*(this+0xAB4)+0x4)+0x0) | 0x2 | R | — | [LLM] |
| *(*(*(this+0xAB4)+0x4)+0x0) | 0x4 | R | — | [LLM] |
| *(*(*(this+0xAB4)+0x4)+0x0) | 0x12 | R | — | [LLM] |
| *(*(*(this+0xAB4)+0x4)+0x0) | 0x14 | R | — | [LLM] |
| *(*(this+0xAB4)+0x4) | 0x0 | R | — | [LLM] |
| *(this+0xAAC) | 0x0 | R | — | [LLM] |
| *(this+0xAB4) | 0x4 | R | — | [LLM] |
| this | 0xAAC | R | — | [LLM] |
| this | 0xAB4 | RW | — | [LLM] |
| this | 0xABC | R | — | [LLM] |
| this | 0xAC0 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0xAB4: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e1a0 | WaitForSingleObject | R | [LLM] |
| 0059e1a4 | ReleaseMutex | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0057de30 | sub_57DE30 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
