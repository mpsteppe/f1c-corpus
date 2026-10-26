## DoublyLinkedListNodeRemovalByFlag_0053ced0 — ListPruneByFlag8

**Summary:** Walks the global doubly-linked list (head at dword_8B8F14, offsets 0x12C/0x130) and removes all nodes that have bit 3 (value 8) set at offset 0x114. Decrements global count for each removal.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** VertexBufferResourceAllocation (00543fa0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008b6ac0 | dword_8B6AC0 | RW | PhysicsObjectCount [DERIVED] |
| 008b8f14 | dword_8B8F14 | RW | ObjLinkedListHead [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00557470 | EmptyStub_7470 | Empty stub (debug/logging hook) |
| 0055fe30 | DualFieldCleanupWithNullChecks | Cleans up two fields of the node with null checks |
| 00587bcf | FreeWrapper_7bcf | Heap free wrapper |

**Guard conditions:** Checks list head (dword_8B8F14) non-null before traversal. Each node's flag at offset 0x114 is checked for bit 3 (value 8): only nodes with this flag set are removed and freed. Prev/next pointers are null-checked before patching reciprocal links.
