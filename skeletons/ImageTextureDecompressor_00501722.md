## ImageTextureDecompressor_00501722 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DirectXSurfaceFormatNegotiation (00502a15)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 22 | [LLM] |
| this | 0x4 | RW | — | [LLM] |
| this | 0xC | RW | — | [LLM] |
| this | 0x10 | RW | — | [LLM] |
| this | 0x14 | RW | 1 | [LLM] |
| this | 0x30 | RW | — | [LLM] |
| this | 0x34 | RW | 0 | [LLM] |
| this | 0x38 | RW | 1 | [LLM] |
| this | 0x40 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: once/conditional? does external poke survive?]
- this 0x4: [LLM: once/conditional? does external poke survive?]
- this 0xC: [LLM: once/conditional? does external poke survive?]
- this 0x10: [LLM: once/conditional? does external poke survive?]
- this 0x14: [LLM: once/conditional? does external poke survive?]
- this 0x30: [LLM: once/conditional? does external poke survive?]
- this 0x34: [LLM: once/conditional? does external poke survive?]
- this 0x38: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005016e0 | VTableDispatchWithLongjmp | R | [LLM] |
| 005016fc | loc_5016FC | R | [LLM] |
| 00501711 | BufferPointerAdjust | R | [LLM] |
| 005114d5 | AudioVideoDecodeSubbandLoop | R | [LLM] |
| 00511686 | VtableDispatchThunk | R | [LLM] |
| 0051dfca | nullsub_4 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0050f632 | sub_50F632 | [LLM] |
| 0050f6f2 | VTableDtorNullFields | [LLM] |
| 0050f904 | StateMachineDispatcher | [LLM] |
| 0050f9ab | StateMachineDispatch_f9ab | [LLM] |
| 0050fab7 | StreamBufferReadStateMachine | [LLM] |
| 0050fb3b | StateMachineWithDispatch | [LLM] |
| 0050fc7d | sub_50FC7D | [LLM] |
| 0051177c | sub_51177C | [LLM] |
| 00587c03 | OperatorNewNhMallocWrapper | [LLM] |
| 0058a7ec | Setjmp3MSVCJmpBufSave | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x0 | == | 22 | [LLM] |
| this | 0x0 | == | 50 | [LLM] |
| this | 0x40 | == | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
