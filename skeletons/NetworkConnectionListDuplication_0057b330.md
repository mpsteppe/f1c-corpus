## NetworkConnectionListDuplication_0057b330 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x8)+0x4) | 0x4 | R | — | [LLM] |
| *(this+0x18) | 0x8 | R | — | [LLM] |
| *(this+0x1C) | 0x4 | RW | — | [LLM] |
| *(this+0x8) | 0x0 | R | — | [LLM] |
| *(this+0x8) | 0x8 | R | — | [LLM] |
| *(this+0xC) | 0x4 | RW | — | [LLM] |
| this | 0x4 | RW | — | [LLM] |
| this | 0x8 | RW | 0 | [LLM] |
| this | 0xC | RW | 0 | [LLM] |
| this | 0x10 | RW | 0 | [LLM] |
| this | 0x14 | RW | 0 | [LLM] |
| this | 0x18 | RW | 0 | [LLM] |
| this | 0x1C | RW | 0 | [LLM] |
| this | 0x20 | RW | 0 | [LLM] |
| this | 0x24 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- *(this+0x1C) 0x4: [LLM: once/conditional? does external poke survive?]
- *(this+0xC) 0x4: [LLM: once/conditional? does external poke survive?]
- this 0x4: [LLM: once/conditional? does external poke survive?]
- this 0x8: [LLM: once/conditional? does external poke survive?]
- this 0xC: [LLM: once/conditional? does external poke survive?]
- this 0x10: [LLM: once/conditional? does external poke survive?]
- this 0x14: [LLM: once/conditional? does external poke survive?]
- this 0x18: [LLM: once/conditional? does external poke survive?]
- this 0x1C: [LLM: once/conditional? does external poke survive?]
- this 0x20: [LLM: once/conditional? does external poke survive?]
- this 0x24: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059c7bb | SEH_57B330 | R | [LLM] |
| 0059e2d8 | __imp_htonl | R | [LLM] |
| 0059e2f4 | __imp_htons | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004bac20 | ShortComputation_ac20 | [LLM] |
| 00581780 | LinkedListNodeAdvance | [LLM] |
| 00582290 | ConditionalFreeByFlagCheck | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |
| 00587c03 | OperatorNewNhMallocWrapper | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
