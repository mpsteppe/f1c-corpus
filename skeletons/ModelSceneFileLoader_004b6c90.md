## ModelSceneFileLoader_004b6c90 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GameDataFileIO (004b7300)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x18)+0x0) | 0x0 | R | — | [LLM] |
| *(*(this+0x6C0)+0x4) | 0x4 | R | — | [LLM] |
| *(*(this+0x714)+0x0) | 0x0 | R | — | [LLM] |
| *(this+0x18) | 0x0 | R | — | [LLM] |
| *(this+0x18) | 0x8 | RW | 0 | [LLM] |
| *(this+0x38) | 0x8 | R | — | [LLM] |
| *(this+0x6C0) | 0x0 | R | — | [LLM] |
| *(this+0x6C0) | 0xC | R | — | [LLM] |
| *(this+0x6C4) | 0x4 | RW | — | [LLM] |
| *(this+0x714) | 0x0 | R | — | [LLM] |
| *(this+0x718) | 0x4 | RW | — | [LLM] |
| this | 0x18 | R | — | [LLM] |
| this | 0x38 | R | — | [LLM] |
| this | 0x40 | RW | 0 | [LLM] |
| this | 0x6C0 | RW | 0 | [LLM] |
| this | 0x6C4 | RW | 0 | [LLM] |
| this | 0x6C8 | RW | 0 | [LLM] |
| this | 0x6CC | RW | 0 | [LLM] |
| this | 0x714 | RW | — | [LLM] |
| this | 0x718 | RW | — | [LLM] |
| this | 0x71C | RW | — | [LLM] |
| this | 0x720 | R | — | [LLM] |
| this | 0xF1C | RW | — | [LLM] |
| this | 0xF20 | RW | — | [LLM] |
| this | 0xF24 | R | — | [LLM] |
| this | 0xF2C | R | — | [LLM] |
| this | 0xF30 | RW | 0 | [LLM] |
| this | 0xF34 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- *(this+0x18) 0x8: [LLM: once/conditional? does external poke survive?]
- *(this+0x6C4) 0x4: [LLM: once/conditional? does external poke survive?]
- *(this+0x718) 0x4: [LLM: once/conditional? does external poke survive?]
- this 0x40: [LLM: once/conditional? does external poke survive?]
- this 0x6C0: [LLM: once/conditional? does external poke survive?]
- this 0x6C4: [LLM: once/conditional? does external poke survive?]
- this 0x6C8: [LLM: once/conditional? does external poke survive?]
- this 0x6CC: [LLM: once/conditional? does external poke survive?]
- this 0x714: [LLM: once/conditional? does external poke survive?]
- this 0x718: [LLM: once/conditional? does external poke survive?]
- this 0x71C: [LLM: once/conditional? does external poke survive?]
- this 0xF1C: [LLM: once/conditional? does external poke survive?]
- this 0xF20: [LLM: once/conditional? does external poke survive?]
- this 0xF30: [LLM: once/conditional? does external poke survive?]
- this 0xF34: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b4250 | FileStreamReader | [LLM] |
| 004b43e0 | FileFormatHeaderReader | [LLM] |
| 004b44a0 | sub_4B44A0 | [LLM] |
| 004b5040 | sub_4B5040 | [LLM] |
| 004b5e50 | sub_4B5E50 | [LLM] |
| 004b5f60 | LinkedBufferTransfer | [LLM] |
| 004b8090 | BinaryFloatComparison | [LLM] |
| 004ba780 | ShortComputation_a780 | [LLM] |
| 004ba830 | LinkedListNodeRemoval_a830 | [LLM] |
| 004bacf0 | LinkedListNodeRemoval_acf0 | [LLM] |
| 004bafc0 | MemoryAllocation_afc0 | [LLM] |
| 004bb0c0 | sub_4BB0C0 | [LLM] |
| 004bb200 | MultiLevelAllocation | [LLM] |
| 004bb460 | DestructorWithConditionalFree_b460 | [LLM] |
| 004bb6b0 | sub_4BB6B0 | [LLM] |
| 00566650 | StringCopyWithBufferRealloc | [LLM] |
| 00566c00 | FileWriteWithBackendDispatch | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |
| 00587c03 | OperatorNewNhMallocWrapper | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| *(this+0x6C0) | 0xC | == | 0 | [LLM] |
| this | 0xF24 | <= | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
