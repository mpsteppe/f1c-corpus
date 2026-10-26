## LinkedListDestructor_8480_004b8480 — LinkedListFullDestructor

**Summary:** Frees all nodes in the linked list (including inner data if the byte flag is set), then zeros head, tail, cursor, and count. Full teardown of the overlay display list.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** MenuActionDispatch (004b9da0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x6C0)+0x0) | 0x4 | R | — | inner data struct string pointer (freed if flag set) |
| *(*(this+0x6C0)+0x4) | 0x4 | R | — | second node's data string pointer (unused in this function - only walks node list directly) |
| *(this+0x6C0) | 0x0 | R | — | node's inner data pointer |
| *(this+0x6C0) | 0xC | R | — | byte flag: if non-zero, free inner data string and struct |
| this | 0x6C0 | RW | 0 | linked list head pointer (zeroed after free) |
| this | 0x6C4 | RW | 0 | linked list tail pointer (zeroed after free) |
| this | 0x6C8 | RW | 0 | cursor pointer (zeroed after free) |
| this | 0x6CC | RW | 0 | element count (zeroed after free) |
| this | 0x6D0 | RW | 1 | dirty flag (set to 1 before freeing) |

**Written-by note (persistence):**
- this 0x6C0: set to 0 always; list becomes empty
- this 0x6C4: set to 0 always; list becomes empty
- this 0x6C8: set to 0 always; list becomes empty
- this 0x6CC: set to 0 always; list becomes empty
- this 0x6D0: set to 1 each call; persists as sorted flag

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bcf | FreeWrapper_7bcf | frees node frame and inner data |

**Guard conditions:** If head pointer is null, the while loop body is never entered — list is already empty. Always executes cleanup.
