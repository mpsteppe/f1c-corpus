## LinkedListNodeRemovalByKey_00407be0 — LinkedListNodeRemoveByKey

**Summary:** Removes a linked list node matching a given value pointer by key. Optionally calls a vtable-based release method on the node's data object before freeing the node structure. Two-pass traversal: first finds the node, then finds its predecessor for unlinking.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ObjectConstructorWithVTableAndSubFree (004058a0), AudioResourceRelease (00405b00)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0xC)+0x0) | 0x0 | R | — | value pointer stored in the tail node |
| *(this+0x10) | 0x0 | R | — | value pointer stored in the cursor node |
| *(this+0x8) | 0x0 | R | — | value pointer stored in the head node |
| *(this+0xC) | 0x0 | R | — | value pointer stored in the tail node |
| this | 0x8 | RW | — | head pointer of linked list |
| this | 0xC | RW | — | tail pointer of linked list |
| this | 0x10 | RW | — | traversal cursor, updated during removal |
| this | 0x14 | R | — | count of nodes in linked list |

**Written-by note (persistence):**
- this 0x8: updated if the removed node is the head (head advances to next)
- this 0xC: updated if the removed node is the tail (tail rewinds to previous)
- this 0x10: updated if the removed node matches the current cursor

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bcf | FreeWrapper_7bcf | frees the 12-byte linked list node after unlinking |

**Guard conditions:** Head pointer (this[2]) must be non-null. The value stored in the head node must be non-null. If no node's value matches `a2` in the first traversal pass, function returns null (no removal). If second traversal fails to find the node (list changed between passes), returns null. When a matching node is found, it is unlinked from the list; if flag byte at offset 8 of the node is set and the value pointer is non-null, a vtable release method is called on the value before the node is freed.
