## LinkedListNodeAppend_0048d2b0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** PlayerProfileScanner (00468ee0), sub_46A2A0 (0046a2a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x2C | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x31C | RW | — | [LLM] |
| this | 0x320 | RW | — | [LLM] |
| this | 0x324 | RW | — | [LLM] |
| this | 0x328 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x31C: [LLM: once/conditional? does external poke survive?]
- this 0x320: [LLM: once/conditional? does external poke survive?]
- this 0x324: [LLM: once/conditional? does external poke survive?]
- this 0x328: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0048c9a0 | SimpleVTableNullInit | [LLM] |
| 0048c9e0 | IntSetterAt4 | [LLM] |
| 0048cc20 | LinkedListSizeCalcWithMaxTracking | [LLM] |
| 00587c03 | OperatorNewNhMallocWrapper | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
