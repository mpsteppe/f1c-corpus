## SceneGraphTreeDestructor_00544ef0 — SceneGraphTreeDestructor

**Summary:** Recursively destroys a scene graph tree structure. Processes child nodes at offsets 0x1B0 and 0x1B8 (conditional on both 0x1AC and 0x1B8 being non-null), removes the node from its doubly linked list via DoublyLinkedListNodeRemoval_5090, and frees memory.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ResourceCleanupDestructionForDirectXObjects (00543bf0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1AC | R | — | first child node pointer (this[107]); checked alongside this[110] |
| this | 0x1B0 | R | — | second child node pointer (this[108]); recursed unconditionally |
| this | 0x1B8 | R | — | third child node pointer (this[110]); recursed only when this[107] is also set |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b0170 | EmptyStub_0170 | stub function |
| 00544ef0 | SceneGraphTreeDestructor | recursive self-call for child nodes |
| 00545090 | DoublyLinkedListNodeRemoval_5090 | remove node from doubly linked list |
| 00557470 | EmptyStub_7470 | stub function |
| 00587bcf | FreeWrapper_7bcf | free/deallocate memory |

**Guard conditions:** BLOCKED recursion to this[108] when 0; BLOCKED recursion to this[110] when this[107] is 0 or this[110] is 0.
