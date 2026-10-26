## AudioNetworkStreamCleanup_00544af0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** RenderTargetCleanup (0053f270), ResourceCleanupDestructionForDirectXObjects (00543bf0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x1EC)+0x4C) | 0x4C | R | — | [LLM] |
| *(this+0x154) | 0x4C | R | — | [LLM] |
| *(this+0x1B0) | 0x68 | R | — | [LLM] |
| *(this+0x204) | 0x104 | R | — | [LLM] |
| this | 0xEC | RW | — | [LLM] |
| this | 0x100 | R | — | [LLM] |
| this | 0x108 | R | — | [LLM] |
| this | 0x148 | R | — | [LLM] |
| this | 0x160 | RW | 0 | [LLM] |
| this | 0x164 | RW | 0 | [LLM] |
| this | 0x1EC | R | — | [LLM] |

**Written-by note (persistence):**
- this 0xEC: [LLM: once/conditional? does external poke survive?]
- this 0x160: [LLM: once/conditional? does external poke survive?]
- this 0x164: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008b78a0 | dword_8B78A0 | R | SoundManager [DERIVED] |
| 008b8dbc | dword_8B8DBC | RW | AudioStreamHandleA [DERIVED] (also: ` — Stream handle A) |
| 008b8dc0 | dword_8B8DC0 | RW | StreamHandleB [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00540760 | sub_540760 | [LLM] |
| 00541420 | SubBufferFree | [LLM] |
| 00542e50 | sub_542E50 | [LLM] |
| 00544e20 | TreeActiveCheck | [LLM] |
| 005478b0 | DoublyLinkedListNodeRemovalWithArrayCleanup | [LLM] |
| 005502c0 | DestructorWithConditionalFreeFlagClear | [LLM] |
| 00557470 | EmptyStub_7470 | [LLM] |
| 00557630 | TextureFlagTestWithDispatch | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x160 | > | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
