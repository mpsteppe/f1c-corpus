## CollisionObjectListManagement_004b4b50 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4B7860 (004b7860)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x70)+0x0) | 0x4 | R | — | [LLM] |
| *(this+0x70) | 0x0 | R | — | [LLM] |
| *(this+0x70) | 0x4 | RW | — | [LLM] |
| *(this+0x70) | 0x8 | R | — | [LLM] |
| this | 0x0 | RW | 0 | [LLM] |
| this | 0x70 | RW | — | [LLM] |
| this | 0x74 | RW | — | [LLM] |
| this | 0x78 | RW | — | [LLM] |
| this | 0x7C | R | — | [LLM] |

**Written-by note (persistence):**
- *(this+0x70) 0x4: [LLM: once/conditional? does external poke survive?]
- this 0x0: [LLM: once/conditional? does external poke survive?]
- this 0x70: [LLM: once/conditional? does external poke survive?]
- this 0x74: [LLM: once/conditional? does external poke survive?]
- this 0x78: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005acd0c | flt_5ACD0C | R | AudioMergeTolerance [DERIVED] |
| 008ab700 | dword_8AB700 | R | FreeListHead [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004646f0 | ConditionalDestructor_46f0 | [LLM] |
| 0049af30 | LinkedListFree | [LLM] |
| 004b42e0 | FAILWRONGDESCRIPTION_42e0 | [LLM] |
| 004b4470 | FileHandleCloseRegistration | [LLM] |
| 004ba790 | sub_4BA790 | [LLM] |
| 004bab20 | sub_4BAB20 | [LLM] |
| 004bac20 | ShortComputation_ac20 | [LLM] |
| 004bb490 | sub_4BB490 | [LLM] |
| 00582290 | ConditionalFreeByFlagCheck | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |
| 00587c03 | OperatorNewNhMallocWrapper | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x70 | == | 0 | [LLM] |
| this | 0x7C | > | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
