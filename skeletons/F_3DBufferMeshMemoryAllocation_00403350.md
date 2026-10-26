## F_3DBufferMeshMemoryAllocation_00403350 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_402690 (00402690)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | RW | 1 | [LLM] |
| this | 0xC | RW | — | [LLM] |
| this | 0x10 | RW | — | [LLM] |
| this | 0x14 | RW | — | [LLM] |
| this | 0x150 | RW | — | [LLM] |
| this | 0x154 | RW | — | [LLM] |
| this | 0x158 | RW | — | [LLM] |
| this | 0x15C | R | — | [LLM] |
| this | 0x160 | R | — | [LLM] |
| this | 0x164 | R | — | [LLM] |
| this | 0x168 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x8: [LLM: once/conditional? does external poke survive?]
- this 0xC: [LLM: once/conditional? does external poke survive?]
- this 0x10: [LLM: once/conditional? does external poke survive?]
- this 0x14: [LLM: once/conditional? does external poke survive?]
- this 0x150: [LLM: once/conditional? does external poke survive?]
- this 0x154: [LLM: once/conditional? does external poke survive?]
- this 0x158: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bcf | FreeWrapper_7bcf | [LLM] |
| 00587c03 | OperatorNewNhMallocWrapper | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x160 | > | 0 | [LLM] |
| this | 0x164 | > | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
