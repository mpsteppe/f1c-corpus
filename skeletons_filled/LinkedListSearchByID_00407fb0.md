## LinkedListSearchByID_00407fb0 — LinkedListIDExistsCheck

**Summary:** Searches a linked list for a node whose ID field (offset 0x5C) matches the input. Returns 1 if found, 0 otherwise. Boolean variant of the ID lookup pattern.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** MemoryAllocation_5160 (00405160)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x20) | 0x5C | R | — | ID field at offset 0x5C within the current node's data |
| this | 0x18 | R | — | head pointer of linked list |
| this | 0x20 | RW | — | traversal cursor, updated as iteration advances |
| this | 0x24 | R | — | count of nodes in linked list |

**Written-by note (persistence):**
- this 0x20: overwritten every call — cursor is reset to head, then advanced per node during traversal

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If input `a2` (ID) is -1, function returns 0 immediately (invalid search key). Head pointer must be non-null and list non-empty. Returns 1 when a node with matching ID is found; returns 0 if traversal reaches end.
