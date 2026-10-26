## NetworkPacketSend_0c10_00580c10 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x640 | R | — | [LLM] |
| this | 0x644 | R | — | [LLM] |
| this | 0xAC8 | RW | — | [LLM] |
| this | 0xACC | RW | — | [LLM] |
| this | 0xAD0 | RW | — | [LLM] |
| this | 0xAD4 | R | — | [LLM] |
| this | 0xAD8 | R | — | [LLM] |
| this | 0xADC | R | — | [LLM] |
| this | 0xB38 | R | — | [LLM] |
| this | 0xB3C | R | — | [LLM] |
| this | 0xB40 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0xAC8: [LLM: once/conditional? does external poke survive?]
- this 0xACC: [LLM: once/conditional? does external poke survive?]
- this 0xAD0: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059cacb | SEH_580C10 | R | [LLM] |
| 0059e1a0 | WaitForSingleObject | R | [LLM] |
| 0059e1a4 | ReleaseMutex | R | [LLM] |
| 0059e2d8 | __imp_htonl | R | [LLM] |
| 0059e2f4 | __imp_htons | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0057b780 | ObjectInitWithVTableFieldSet | [LLM] |
| 0057b9f0 | Copy4DwordsStructToStruct | [LLM] |
| 0057dd40 | sub_57DD40 | [LLM] |
| 00587370 | CopyBufferHeaderFieldsCallInit | [LLM] |
| 00587c03 | OperatorNewNhMallocWrapper | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
