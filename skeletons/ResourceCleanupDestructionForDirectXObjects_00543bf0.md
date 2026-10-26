## ResourceCleanupDestructionForDirectXObjects_00543bf0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** MutexSemaphoreCleanup (005461b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x148) | 0x2C | R | — | [LLM] |
| *(this+0x154) | 0x48 | R | — | [LLM] |
| *(this+0x18C) | 0x68 | R | — | [LLM] |
| *(this+0x194) | 0x68 | R | — | [LLM] |
| *(this+0x19C) | 0x68 | R | — | [LLM] |
| *(this+0x204) | 0x100 | R | — | [LLM] |
| *(this+0x2B0) | 0x1B4 | R | — | [LLM] |
| this | 0xF8 | RW | 0 | [LLM] |
| this | 0x100 | RW | 0 | [LLM] |
| this | 0x108 | RW | 0 | [LLM] |
| this | 0x110 | R | — | [LLM] |
| this | 0x118 | RW | 0 | [LLM] |
| this | 0x120 | RW | 0 | [LLM] |
| this | 0x128 | RW | 0 | [LLM] |
| this | 0x130 | RW | 0 | [LLM] |
| this | 0x138 | R | — | [LLM] |
| this | 0x140 | R | — | [LLM] |
| this | 0x148 | R | — | [LLM] |
| this | 0x150 | R | — | [LLM] |
| this | 0x154 | R | — | [LLM] |
| this | 0x178 | R | — | [LLM] |
| this | 0x18C | R | — | [LLM] |
| this | 0x194 | R | — | [LLM] |
| this | 0x19C | R | — | [LLM] |
| this | 0x1AC | R | — | [LLM] |
| this | 0x1B8 | R | — | [LLM] |
| this | 0x1C0 | R | — | [LLM] |
| this | 0x1C8 | R | — | [LLM] |
| this | 0x1D0 | R | — | [LLM] |
| this | 0x204 | R | — | [LLM] |
| this | 0x2B0 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0xF8: [LLM: once/conditional? does external poke survive?]
- this 0x100: [LLM: once/conditional? does external poke survive?]
- this 0x108: [LLM: once/conditional? does external poke survive?]
- this 0x118: [LLM: once/conditional? does external poke survive?]
- this 0x120: [LLM: once/conditional? does external poke survive?]
- this 0x128: [LLM: once/conditional? does external poke survive?]
- this 0x130: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008b8f2c | dword_8B8F2C | R | RenderResourceHandle2 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b0170 | EmptyStub_0170 | [LLM] |
| 00544af0 | AudioNetworkStreamCleanup | [LLM] |
| 00544ef0 | SceneGraphTreeDestructor | [LLM] |
| 00545150 | F_3DSoundSourceDestructor | [LLM] |
| 005454a0 | sub_5454A0 | [LLM] |
| 005487e0 | LinkedListWalkWithExitCheck | [LLM] |
| 0054a240 | DestroyFree | [LLM] |
| 005519e0 | DoublyLinkedListNodeRemoval_19e0 | [LLM] |
| 00557280 | CleanupFunction | [LLM] |
| 005593d0 | sub_5593D0 | [LLM] |
| 00560b30 | ConditionalFreeOfStructField | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
