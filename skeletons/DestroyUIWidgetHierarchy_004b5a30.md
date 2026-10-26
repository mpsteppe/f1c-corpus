## DestroyUIWidgetHierarchy_004b5a30 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4B41D0 (004b41d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x6C0)+0x4) | 0x4 | R | — | [LLM] |
| *(*(this+0x6D4)+0x4) | 0x4 | R | — | [LLM] |
| this | 0x6C0 | RW | 0 | [LLM] |
| this | 0x6C4 | RW | 0 | [LLM] |
| this | 0x6C8 | RW | 0 | [LLM] |
| this | 0x6CC | RW | 0 | [LLM] |
| this | 0x6D4 | RW | 0 | [LLM] |
| this | 0x6D8 | RW | 0 | [LLM] |
| this | 0x6DC | RW | 0 | [LLM] |
| this | 0x6E0 | RW | 0 | [LLM] |
| this | 0x704 | R | — | [LLM] |
| this | 0x70C | R | — | [LLM] |
| this | 0x724 | R | — | [LLM] |
| this | 0x72C | R | — | [LLM] |
| this | 0xF94 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x6C0: [LLM: once/conditional? does external poke survive?]
- this 0x6C4: [LLM: once/conditional? does external poke survive?]
- this 0x6C8: [LLM: once/conditional? does external poke survive?]
- this 0x6CC: [LLM: once/conditional? does external poke survive?]
- this 0x6D4: [LLM: once/conditional? does external poke survive?]
- this 0x6D8: [LLM: once/conditional? does external poke survive?]
- this 0x6DC: [LLM: once/conditional? does external poke survive?]
- this 0x6E0: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004646f0 | ConditionalDestructor_46f0 | [LLM] |
| 0049af30 | LinkedListFree | [LLM] |
| 004b0170 | EmptyStub_0170 | [LLM] |
| 004b52a0 | ListRebuildWithNodeTransfer | [LLM] |
| 004b5e50 | sub_4B5E50 | [LLM] |
| 004b5f60 | LinkedBufferTransfer | [LLM] |
| 004b6130 | SpriteOverlayListCleanup | [LLM] |
| 004ba8c0 | NodeDestructor | [LLM] |
| 004ba900 | LinkedListNodeDestructor_a900 | [LLM] |
| 004ba9f0 | LinkedListDestruction | [LLM] |
| 004baeb0 | LinkedListDestructorWithCallback | [LLM] |
| 004bb400 | LinkedListDestructor_b400 | [LLM] |
| 004bb4f0 | LinkedListDestructionWithRefCountLoop | [LLM] |
| 004bb650 | ListFullDestruction | [LLM] |
| 005668d0 | SubCallWithConditionalFieldFree | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
