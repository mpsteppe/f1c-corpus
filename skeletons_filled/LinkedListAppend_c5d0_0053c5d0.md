## LinkedListAppend_c5d0_0053c5d0 — DoublyLinkedListAppend_1E4_1E8

**Summary:** Appends a node to a global doubly-linked list (head at dword_8B8F28) with prev/next pointers at offsets 0x1E4/0x1E8. Walks to tail if list non-empty, or initializes head if empty.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** AudioEngineInitialization (00546010)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1E4 | RW | 0 | Previous node pointer (prev) |
| this | 0x1E8 | RW | 0 | Next node pointer (next) |

**Written-by note (persistence):**
- this 0x1E4: conditional — set to old tail on append, 0 for head; persists for list lifetime
- this 0x1E8: conditional — set to new node on append, 0 for tail; persists for list lifetime

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008b8f28 | dword_8B8F28 | RW | UIRootContextPtr [DERIVED] (also: ` — unknown context/state pointer) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Checks dword_8B8F28 (list head). If NULL, node becomes the head (both prev/next set to 0). If non-NULL, traverses to last node via next pointer chain, then appends node as new tail.
