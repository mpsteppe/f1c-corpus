## LinkedListAppend_d340_0053d340 — DoublyLinkedListAppend_86C_870

**Summary:** Appends a node to the global registry doubly-linked list (head at dword_8B8E20) with prev/next pointers at offsets 0x86C/0x870. Walks to tail if list non-empty, or initializes head if empty.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_53CFE0 (0053cfe0), SceneFileTopLevelParser (0055b200)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x86C | RW | 0 | Previous node pointer (prev) |
| this | 0x870 | RW | 0 | Next node pointer (next) |

**Written-by note (persistence):**
- this 0x86C: conditional — set to old tail on append, 0 for head; persists for list lifetime
- this 0x870: conditional — set to new node on append, 0 for tail; persists for list lifetime

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008b8e20 | dword_8B8E20 | RW | EntryRegistryHead [DERIVED] (also: ` â€” global linked list head (entry registry) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Checks dword_8B8E20 (list head). If NULL, node becomes head (prev/next = 0). If non-NULL, traverses to last node via next-pointer chain, then appends as new tail.
