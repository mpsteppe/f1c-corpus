## LinkedListInsertOperation_00407450 — LinkedListStringInsertUnique

**Summary:** Inserts a string into a linked list if not already present. Part of a string-list management system that maintains a unique set of strings with head/tail/cursor pointers.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x28 | RW | — | head pointer of linked list |
| this | 0x2C | RW | — | tail pointer of linked list |
| this | 0x30 | RW | — | traversal cursor, set to head at start |
| this | 0x34 | R | — | count of nodes in list |

**Written-by note (persistence):**
- this 0x28: set once on first insertion when list was empty (this[10] = v10)
- this 0x2C: updated on every insertion (this[11] = v10)
- this 0x30: written at function start (set to head) and during traversal (advances to next node)

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00566650 | StringCopyWithBufferRealloc | copies input string a2 into an allocated 8-byte buffer node |
| 00587c03 | OperatorNewNhMallocWrapper | allocates 8-byte string buffer node or 12-byte linked list node |
| 00588410 | sub_588410 | compares two strings, returns 0 when they match |

**Guard conditions:** If `a2` (input string) is null, the function returns immediately — no insertion occurs. If `a2` is non-null, the list is traversed; if a node whose string matches `a2` is found, the function returns without inserting (duplicate prevention). If no match found or list is empty, a new node is inserted at the tail.
