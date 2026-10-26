## MultiFieldFree_004cb4f0 — SpecialFXMultiFieldCleanup

**Summary:** Frees two heap-allocated buffers (at this+0x5C and this+0x68), removes a doubly-linked list node (at this+0x54), and clears intermediate fields (0x58, 0x64). Called during SpecialFX_Post cleanup.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SpecialFX_Post (004cfed0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x54 | RW | 0 | Doubly-linked list node pointer; removed from list and cleared |
| this | 0x58 | RW | 0 | Intermediate field cleared to 0 (flag/counter reset) before freeing at 0x5C |
| this | 0x5C | RW | 0 | Heap-allocated buffer pointer (with 4-byte allocation header); freed and cleared |
| this | 0x64 | RW | 0 | Intermediate field cleared to 0 (flag/counter reset) before freeing at 0x68 |
| this | 0x68 | RW | 0 | Heap-allocated buffer pointer; freed and cleared |

**Written-by note (persistence):**
- this 0x54: Written to 0 after list removal. Survives until set again.
- this 0x58: Written to 0. Survives until set again.
- this 0x5C: Written to 0 after free. Survives until set again.
- this 0x64: Written to 0. Survives until set again.
- this 0x68: Written to 0 after free. Survives until set again.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008afe88 | dword_8AFE88 | R | CollisionGeometryHandle [DERIVED] (also: ` — global collision geometry handle) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005592b0 | DoublyLinkedListNodeRemovalByPointer | Removes node at this+0x54 from its doubly-linked list |
| 00587bcf | FreeWrapper_7bcf | Frees heap allocations at this+0x5C (with -4 header adjust) and this+0x68 |

**Guard conditions:** Each non-null check gates the free/list-removal for its field. If pointer is null, the corresponding cleanup is skipped.
