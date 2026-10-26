## SceneInstanceCollection_00545bb0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** VertexBufferResourceAllocation (00543fa0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(*(*(this+0x204)+0xEC)+0x204)+0x10) | 0x10 | R | — | [LLM] |
| *(*(*(*(this+0x204)+0xEC)+0x204)+0x10) | 0x14 | R | — | [LLM] |
| *(*(*(this+0x204)+0xEC)+0x4C) | 0x4C | R | — | [LLM] |
| *(*(this+0x204)+0xEC) | 0x204 | R | — | [LLM] |
| *(*(this+0x30C)+0x10) | 0x10 | R | — | [LLM] |
| *(*(this+0x30C)+0x10) | 0x14 | R | — | [LLM] |
| *(this+0x154) | 0x4C | R | — | [LLM] |
| *(this+0x204) | 0x4 | R | — | [LLM] |
| *(this+0x204) | 0xEC | R | — | [LLM] |
| *(this+0x204) | 0x104 | R | — | [LLM] |
| this | 0x100 | R | — | [LLM] |
| this | 0x108 | R | — | [LLM] |
| this | 0x174 | R | — | [LLM] |
| this | 0x178 | RW | — | [LLM] |
| this | 0x30C | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x178: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b0170 | EmptyStub_0170 | [LLM] |
| 00548e00 | ShortComputation_8e00 | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |
| 00587c03 | OperatorNewNhMallocWrapper | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x174 | > | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
