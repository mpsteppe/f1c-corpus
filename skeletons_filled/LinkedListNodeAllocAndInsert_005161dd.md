## LinkedListNodeAllocAndInsert_005161dd — AllocLinkedListNodeInsertHead

**Summary:** Allocates a 120-byte node via MemoryAllocator, populates it with caller-supplied data (a4, a5, a6, a3) and metadata, then inserts at head of singly-linked list at this+0x44. Returns new node pointer.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x0 | R | — | first field of sub-object, read for vtable dispatch |
| obj | 0x14 | RW | 12 | written with constant 12 when a2 != 1 |
| obj | 0x18 | RW | — | written with category a2 when a2 != 1 |
| this | 0x0 | R | — | vtable pointer for virtual dispatch |
| this | 0x4 | R | — | base pointer for allocator state |
| this | 0x44 | RW | — | head pointer of linked list, updated to point to new node |

**Written-by note (persistence):**
- obj 0x14: written conditionally (when a2 != 1) with constant 12
- obj 0x18: written conditionally (when a2 != 1) with a2 value
- this 0x44: updated each call to point to new head node, persistent list anchor

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00515f23 | MemoryAllocator | allocates 0x78 (120) byte node block |

**Guard conditions:**
1. a2 != 1: if category is not 1 — writes constant 12 and category to obj, dispatches via vtable before proceeding with allocation
