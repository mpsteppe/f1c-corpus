## ResourceNodeLookupByStringOrID_00407e40 — ResourceLookupByStringOrID

**Summary:** Looks up a resource node in a linked list by either integer ID (offset 0x10 within data) or string name (offset 0x04 within data). Dual-mode lookup where a3 == -1 selects string mode, otherwise ID mode.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ShortComputation_5050 (00405050), MemoryAllocation_5160 (00405160)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x38) | 0x4 | R | — | next pointer in the 12-byte linked list node (head_node->next) |
| *(this+0x40) | 0x10 | R | — | ID field at offset 0x10 within the resource data node (data[4]) |
| this | 0x38 | R | — | head pointer of linked list |
| this | 0x40 | RW | — | traversal cursor, updated as iteration advances |
| this | 0x44 | R | — | count of nodes in linked list |

**Written-by note (persistence):**
- this 0x40: overwritten every call — cursor is reset to head, then advanced per node during traversal

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00588410 | sub_588410 | compares two strings; returns 0 on match (like strcmp) |

**Guard conditions:** If a3 (ID) is not -1: list must be non-null (this[14] != 0); returns 0 if no node with matching ID is found. If a3 is -1: a2 (string) must be non-null; list must be non-null; returns 0 if no node with matching string is found. In both modes, returns the data pointer of the matching node.
