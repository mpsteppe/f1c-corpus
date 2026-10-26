## IntSetInsert_0057b230 — IntSetInsertWithDedup

**Summary:** Checks if integer a2 exists in set (linked list at offset 0x18). Linear scan comparing node data against a2. If found returns 1 (already present). If not found allocates 4 bytes for value, appends node via LinkedListNodeAppend_6000, returns 0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1C) | 0x0 | R | — | node data pointer; compared against a2 during search |
| this | 0x18 | R | — | list head (this[6]); start of traversal |
| this | 0x1C | R | — | list node pointer for data comparison |
| this | 0x20 | R | — | list-related field |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00586000 | LinkedListNodeAppend_6000 | appends node to global list with flag arg 1 |
| 00587c03 | OperatorNewNhMallocWrapper | allocates 4 bytes for storing integer value |

**Guard conditions:** Head null → insert path (PASSES). Traversal exhausts (next null) → insert path (PASSES). Node with matching data found → return 1 (duplicate, BLOCKED/stop).

