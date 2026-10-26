## NetworkConnectionThread_0057fc80 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(*(this+0xAC8)+0x0)+0x0) | 0x0 | R | — | [LLM] |
| *(*(this+0xAC8)+0x0) | 0x0 | R | — | [LLM] |
| *(this+0xAC8) | 0x0 | R | — | [LLM] |
| *(this+0xAC8) | 0x8 | R | — | [LLM] |
| obj | 0x4C | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x938 | RW | 18446744073709551615 | [LLM] |
| this | 0x93C | RW | 18446744073709551615 | [LLM] |
| this | 0xA75 | RW | 1 | [LLM] |
| this | 0xAC8 | RW | 0 | [LLM] |
| this | 0xACC | RW | 0 | [LLM] |
| this | 0xAD0 | RW | 0 | [LLM] |
| this | 0xAD4 | RW | 0 | [LLM] |
| this | 0xAD8 | R | — | [LLM] |
| this | 0xADC | R | — | [LLM] |
| this | 0xB38 | RW | 1 | [LLM] |
| this | 0xB3C | R | — | [LLM] |
| this | 0xB40 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x938: [LLM: once/conditional? does external poke survive?]
- this 0x93C: [LLM: once/conditional? does external poke survive?]
- this 0xA75: [LLM: once/conditional? does external poke survive?]
- this 0xAC8: [LLM: once/conditional? does external poke survive?]
- this 0xACC: [LLM: once/conditional? does external poke survive?]
- this 0xAD0: [LLM: once/conditional? does external poke survive?]
- this 0xAD4: [LLM: once/conditional? does external poke survive?]
- this 0xB38: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e1a0 | WaitForSingleObject | R | [LLM] |
| 0059e1a4 | ReleaseMutex | R | [LLM] |
| 0059e2dc | __imp_socket | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0057c860 | TCPSocketInit | [LLM] |
| 0057fb90 | WinsockInit | [LLM] |
| 00585470 | sub_585470 | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
