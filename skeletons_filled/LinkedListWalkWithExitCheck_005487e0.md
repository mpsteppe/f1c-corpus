## LinkedListWalkWithExitCheck_005487e0 — ReleaseReferenceCountedResourcesInChain

**Summary:** Walks a linked chain of reference-counted resources, releasing each via ReferenceCountedResourceRelease. Returns -1 if any release fails, 0 if all succeed or list is empty.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ResourceCleanupDestructionForDirectXObjects (00543bf0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0xE4) | 0xC0 | R | — | Next-node pointer in the linked list chain |
| this | 0x24 | R | — | Head pointer to the first reference-counted resource node |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005469c0 | ReferenceCountedResourceRelease | Decrements resource ref count; returns -1 on failure |

**Guard conditions:** Checks `this[0x24]` (head pointer): if NULL, returns 0 immediately (no work). Loop checks each node's `[0xC0]` (next pointer): if NULL, returns 0 (end of chain reached normally). Early exit when ReferenceCountedResourceRelease returns -1: returns -1 immediately.
