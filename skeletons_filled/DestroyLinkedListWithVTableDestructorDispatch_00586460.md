## DestroyLinkedListWithVTableDestructorDispatch_00586460 — DestroyLinkedListWithCallbackLoop

**Summary:** Frees all nodes in linked list rooted at offset 0x0. For each node with flag byte set at +8 and non-null data pointer at +0, dereferences the data pointer's first DWORD (vtable-like) and calls NTimeCallbackLoopWithSEH on it (size 1048, count from *(data-4), callback EmptyStub_0170). Frees adjusted data pointer, freed data wrapper, and node. Clears all list fields to 0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_583AE0 (00583ae0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(obj+0x0) | 0x0 | R | — | Dereferenced content pointer from node data (vtable-like dispatch target) |
| obj | 0x0 | R | — | Data pointer stored in linked list node |
| obj | 0x8 | R | — | Flag byte in node: if non-zero, node data pointer is valid and needs callback cleanup |
| this | 0x0 | RW | 0 | Linked list head pointer |
| this | 0x4 | RW | 0 | Linked list tail pointer |
| this | 0x8 | RW | 0 | Auxiliary/current pointer |
| this | 0xC | RW | 0 | List node count |

**Written-by note (persistence):**
- this 0x0: set to 0 at end; survives as external write until destruct
- this 0x4: set to 0 at end
- this 0x8: set to 0 at end
- this 0xC: set to 0 at end

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004b0170 | EmptyStub_0170 | R | No-op callback passed to NTimeCallbackLoopWithSEH |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bcf | FreeWrapper_7bcf | Free heap-allocated node and node data wrapper |
| 0058a5f7 | NTimeCallbackLoopWithSEH | SEH-protected callback loop on node data (size 1048, count from *(data-4), callback EmptyStub_0170) |

**Guard conditions:** Iterates list from this[0]; processes node only if node flag at +8 is non-zero AND node data pointer at +0 is non-null AND *(node[0]) (first DWORD of data) is non-null. If list head is NULL, returns immediately.
