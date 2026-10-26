## LinkedListNodeDestructor_004677e0 — LinkedListNodeDestructor

**Summary:** Destructor that walks and frees all nodes in an embedded linked list, clears head/tail/count fields, calls vtable cleanup, and optionally frees the object itself based on a flag. Belongs to linked-list data structure cleanup system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0xF8) | 0x0 | R | — | first node's data pointer (head node payload) |
| *(this+0xFC) | 0x4 | R | — | first node's next pointer (tail node payload) |
| this | 0xF8 | RW | 0 | linked list head pointer (this[62]) |
| this | 0xFC | RW | 0 | linked list tail pointer (this[63]) |
| this | 0x100 | RW | 0 | element count (this[64]) |
| this | 0x104 | RW | 0 | capacity/size field (this[65]) |

**Written-by note (persistence):**
- this 0xF8: written to 0 on every call (list emptied).
- this 0xFC: written to 0 on every call.
- this 0x100: written to 0 on every call.
- this 0x104: written to 0 on every call.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00487f30 | VTableSetCleanup | performs vtable-based cleanup on the object |
| 00587bcf | FreeWrapper_7bcf | frees heap-allocated memory (node data, node struct, optionally this) |

**Guard conditions:** For each linked list node, checks byte at node+8 (flag whether inner data should be freed). If non-zero (PASSES), frees the node's data pointer first, then the node struct. If zero (BLOCKED), only frees the node struct. After list cleanup, checks a2 & 1 flag; if set (PASSES), frees the `this` object itself.
