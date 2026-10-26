## LinkedListInsertTail_005419d0 — Unlink node and insert at tail of list

**Summary:** Unlinks node a2 from its current linked list position (updating prev/next pointers and global tail if a2 was the global tail), then appends it to the tail of this list. Sets a2's list owner to this.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_55A060 (0055a060)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x368)+0x1B8) | 0x1B8 | RW | — | global list tail pointer — updated if a2 was the current tail |
| *(this+0x368) | 0x1B8 | R | — | next pointer of a node reached via this[0x368] |
| this | 0x1B0 | RW | — | head pointer of this linked list |

**Written-by note (persistence):**
- *(*(this+0x368)+0x1B8) 0x1B8: conditionally written if a2 was the global tail; persists until next list modification.
- this 0x1B0: written on first insertion (head = a2) or unchanged if list already non-empty; persists between calls.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008b8f28 | dword_8B8F28 | R | UIRootContextPtr [DERIVED] (also: global context pointer) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No early-return guard. All branches handle both null and non-null pointer cases naturally via linked-list traversal logic.
