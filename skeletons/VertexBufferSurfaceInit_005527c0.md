## VertexBufferSurfaceInit_005527c0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_53EB70 (0053eb70), sub_552470 (00552470)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x10) | 0x8 | RW | 0 | [LLM] |
| *(this+0x10) | 0xC | RW | 1065353216 → 1.0f | [LLM] |
| *(this+0xC) | 0x0 | RW | 34 | [LLM] |
| *(this+0xC) | 0x4 | RW | — | [LLM] |
| *(this+0xC) | 0x8 | RW | 28 | [LLM] |
| *(this+0xC) | 0xC | RW | 768 | [LLM] |
| this | 0xC | RW | — | [LLM] |
| this | 0x10 | RW | — | [LLM] |
| this | 0x24 | R | — | [LLM] |

**Written-by note (persistence):**
- *(this+0x10) 0x8: [LLM: once/conditional? does external poke survive?]
- *(this+0x10) 0xC: [LLM: once/conditional? does external poke survive?]
- *(this+0xC) 0x0: [LLM: once/conditional? does external poke survive?]
- *(this+0xC) 0x4: [LLM: once/conditional? does external poke survive?]
- *(this+0xC) 0x8: [LLM: once/conditional? does external poke survive?]
- *(this+0xC) 0xC: [LLM: once/conditional? does external poke survive?]
- this 0xC: [LLM: once/conditional? does external poke survive?]
- this 0x10: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008b78a0 | dword_8B78A0 | R | SoundManager [DERIVED] |
| 008cef78 | dword_8CEF78 | R | VertexBuffer_Stride [DERIVED] (also: ` â€” vertex buffer resource data pointer) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00540df0 | sub_540DF0 | [LLM] |
| 00540f00 | BufferLockAllocate | [LLM] |
| 00540f90 | ArithmeticComparison_0f90 | [LLM] |
| 00587c03 | OperatorNewNhMallocWrapper | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| *(this+0xC) | 0xC | > | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
