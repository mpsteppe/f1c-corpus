## RenderVTableObjectInit_00516883 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_50F632 (0050f632)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x0 | R | — | [LLM] |
| obj | 0x14 | RW | 53 | [LLM] |
| obj | 0x18 | RW | 0 | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x4 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- obj 0x14: [LLM: once/conditional? does external poke survive?]
- obj 0x18: [LLM: once/conditional? does external poke survive?]
- this 0x4: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00515f23 | MemoryAllocator | R | [LLM] |
| 0051601f | MemoryAllocatorWithAlignment | R | [LLM] |
| 005160ad | MemoryAllocatorWithChunking | R | [LLM] |
| 0051613f | ChunkedBufferAlloc | R | [LLM] |
| 005161dd | LinkedListNodeAllocAndInsert | R | [LLM] |
| 0051623e | sub_51623E | R | [LLM] |
| 0051629f | DirectXTextureSurfaceAllocation | R | [LLM] |
| 00516531 | RingBufferWriteWithBoundsCheck | R | [LLM] |
| 0051664f | OffsetValidationWithBufferUpdate | R | [LLM] |
| 00516772 | sub_516772 | R | [LLM] |
| 00516853 | TwoIterationCleanup | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00519346 | MallocWrapper | [LLM] |
| 00587b96 | EmptyStub_7b96 | [LLM] |
| 0058fb7e | StubReturning0 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
