## DoublyLinkedListNodeRemoval_004ba7a0 — Value-match linked list node removal

**Summary:** Finds a node by value in a singly-linked list with head/tail/count tracking, unlinks it, decrements count, and conditionally frees attached data. Returns 1 on success, 0 on failure.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** NetworkMessageDispatch (004b54e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x4 | RW | — | Node next pointer (unlinked during removal) |
| obj | 0x8 | R | — | Node free-data flag byte (checked before freeing data) |
| obj | 0xC | RW | 0 | Node data pointer (freed if flag set) |
| this | 0x0 | RW | — | List head pointer (updated if removing first node) |
| this | 0x4 | RW | — | List tail pointer (updated if removing last node) |
| this | 0x8 | RW | — | List current/iterator pointer (updated if removing current) |
| this | 0xC | R | — | List node count (decremented on removal) |

**Written-by note (persistence):**
- obj 0x4: overwritten during unlink; persists in node memory until freed
- obj 0xC: left unchanged; data pointer persists until freed
- this 0x0: updated if head removed; persists across calls
- this 0x4: updated if tail removed; persists across calls
- this 0x8: updated if current node removed; persists across calls

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b0170 | EmptyStub_0170 | Empty stub (no-op) |
| 00587bcf | FreeWrapper_7bcf | Memory deallocation wrapper |

**Guard conditions:** Early return 0 if a2 is null or list is empty or value not found. Conditionally frees node data if byte at node+0x8 is non-zero AND a3 is non-zero.
