## UILinkedListCleanupIterator_00545a10 — Iterate and cleanup list nodes via sub_560C10

**Summary:** Walks linked list from head at offset 0x15C, calling `sub_560C10(this, 0)` on each node. Advances via next pointer at offset 0x34. Returns 0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** VertexBufferResourceAllocation (00543fa0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x190) | 0x34 | R | — | Next-node pointer in linked list |
| this | 0x15C | R | — | Head of linked list |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00560c10 | sub_560C10 | Per-node cleanup/dispatch function |

**Guard conditions:** Loop while head at `this[87]` is non-null.
