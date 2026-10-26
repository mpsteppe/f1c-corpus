## LinkedListTraversalWithCallback_00486630 — List2TraverseWithCallback

**Summary:** Iterates over linked list 2 (head at this+0xD0), calling sub_49A5D0 once per node. Traverses via next-pointer at node+0x18.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** MultiStageVTableDispatch (00487e70)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0xE8) | 0x18 | R | — | next-pointer (offset 0x18) within linked list nodes for traversal |
| this | 0xD0 | R | — | head pointer of linked list 2 (this[52]) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0049a5d0 | sub_49A5D0 | per-node callback invoked once per list element |

**Guard conditions:** iterates while current node pointer is non-null; null node terminates the loop. If list head at this[52] (offset 0xD0) is null, loop body never executes (BLOCKED).
