## LinkedListTraversalByID_00408000 — LinkedListFindByIDAndInvoke

**Summary:** Searches a linked list for a node with matching ID (offset 0x5C) and calls sub_406A70 on its data when found. Find-and-invoke pattern with no return value.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

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
| 00406a70 | sub_406A70 | invoked on the matching node's data when a node with the target ID is found |

**Guard conditions:** If input `a2` (ID) is -1, function returns immediately. Head pointer must be non-null and list non-empty. When a node with matching ID is found, sub_406A70 is called and function returns. If traversal reaches end without match, function returns silently.
