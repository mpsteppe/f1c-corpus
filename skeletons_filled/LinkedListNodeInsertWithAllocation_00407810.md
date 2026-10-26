## LinkedListNodeInsertWithAllocation_00407810 — ViewProjectionLinkedListInsert

**Summary:** Allocates and initializes a view/projection structure (108 bytes) via ViewProjectionStructInit and inserts it into a linked list. Part of a 3D rendering or camera system that manages view/projection data structures.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | RW | — | head pointer of linked list |
| this | 0xC | RW | — | tail pointer of linked list |
| this | 0x10 | RW | — | persistent reference to first node (set once on first insertion) |
| this | 0x14 | R | — | count of nodes in linked list |
| this | 0x88 | R | — | enable/disable gate flag; function returns 0 if zero |

**Written-by note (persistence):**
- this 0x8: set once on first insertion when list was empty (this[2] = v7)
- this 0xC: updated on every successful insertion (this[3] = v7)
- this 0x10: set once on first insertion, same as head (this[4] = v7)

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004057f0 | ViewProjectionStructInit | initializes 108-byte view/projection structure with parameters (a2, a3, a4, this) |
| 00587c03 | OperatorNewNhMallocWrapper | allocates 108-byte struct or 12-byte linked list node |

**Guard conditions:** If `this[34]` (offset 0x88, enable flag) is zero, function returns 0 immediately. If `a2` is null, returns 0. If 108-byte allocation fails or ViewProjectionStructInit returns null, returns 0. If 12-byte linked list node allocation fails, the initialized struct is still returned (node is null) — in this case the list is not updated but return value is non-null.
