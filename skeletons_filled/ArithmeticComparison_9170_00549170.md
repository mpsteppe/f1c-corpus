## ArithmeticComparison_9170_00549170 — MoveMatchingTreeNodesToList

**Summary:** Iterates a linked list from this[0xE8], searches each node's tree for a matching child via RecursiveTreeStringSearch, and moves any found node from the source list (*this) to the target list (this) using LinkedListRemove and DoublyLinkedListAppend_90b0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** AudioEngineInitialization (00546010)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0xFC) | 0x14 | R | — | pNext — forward pointer in the search list nodes |
| this | 0x0 | R | — | Pointer to source list root (nodes removed from here) |
| this | 0xE8 | R | — | Head pointer of the search iteration list |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005452b0 | LinkedListRemove | Removes a node from the source linked list rooted at *this |
| 005490b0 | DoublyLinkedListAppend_90b0 | Appends the found node to the target list (this) |
| 0054bc60 | RecursiveTreeStringSearch | Recursively searches tree structure for a matching child node |

**Guard conditions:** this[0xE8] (search list head) must be non-null for loop to execute. RecursiveTreeStringSearch output v4 must be non-null for LinkedListRemove + DoublyLinkedListAppend_90b0 to execute (node moved). If v4 is null, node is skipped and iteration continues.
