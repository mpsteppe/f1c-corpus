## BufferPoolAllocatorInitialization_004b71e0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x6C0)+0x0) | 0x4 | R | — | [LLM] |
| *(*(this+0x6C0)+0x4) | 0x4 | R | — | [LLM] |
| *(this+0x6C0) | 0x0 | R | — | [LLM] |
| *(this+0x6C0) | 0xC | R | — | [LLM] |
| *(this+0x9A4) | 0x0 | RW | — | [LLM] |
| this | 0x6C0 | RW | 0 | [LLM] |
| this | 0x6C4 | RW | 0 | [LLM] |
| this | 0x6C8 | RW | 0 | [LLM] |
| this | 0x6CC | RW | 0 | [LLM] |
| this | 0x6D0 | RW | 0 | [LLM] |
| this | 0x9A4 | R | — | [LLM] |
| this | 0x9B0 | RW | 0 | [LLM] |
| this | 0x9B4 | RW | 96 | [LLM] |
| this | 0x9B8 | RW | 18446744073709551615 | [LLM] |
| this | 0x9BC | RW | 18446744073709551615 | [LLM] |
| this | 0xF38 | RW | 0 | [LLM] |
| this | 0xF3C | RW | 0 | [LLM] |
| this | 0xF8C | RW | 5 | [LLM] |

**Written-by note (persistence):**
- *(this+0x9A4) 0x0: [LLM: once/conditional? does external poke survive?]
- this 0x6C0: [LLM: once/conditional? does external poke survive?]
- this 0x6C4: [LLM: once/conditional? does external poke survive?]
- this 0x6C8: [LLM: once/conditional? does external poke survive?]
- this 0x6CC: [LLM: once/conditional? does external poke survive?]
- this 0x6D0: [LLM: once/conditional? does external poke survive?]
- this 0x9B0: [LLM: once/conditional? does external poke survive?]
- this 0x9B4: [LLM: once/conditional? does external poke survive?]
- this 0x9B8: [LLM: once/conditional? does external poke survive?]
- this 0x9BC: [LLM: once/conditional? does external poke survive?]
- this 0xF38: [LLM: once/conditional? does external poke survive?]
- this 0xF3C: [LLM: once/conditional? does external poke survive?]
- this 0xF8C: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b52a0 | ListRebuildWithNodeTransfer | [LLM] |
| 004b5e50 | sub_4B5E50 | [LLM] |
| 004b5f60 | LinkedBufferTransfer | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
