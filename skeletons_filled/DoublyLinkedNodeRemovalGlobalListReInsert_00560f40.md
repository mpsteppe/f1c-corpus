## DoublyLinkedNodeRemovalGlobalListReInsert_00560f40 — DoublyLinkedListNodeReinsertGlobal

**Summary:** Removes a node from its current doubly linked list, then re-inserts it at the tail of a global UI/context linked list (dword_8B8F28+348), clearing the node's active flag (bit 2).

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** DoublyLinkedListNodeTransplant (0054baa0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x2C | RW | — | list head pointer (this[11], updated if removed node was head) |

**Written-by note (persistence):**
- this 0x2C: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008b8f28 | dword_8B8F28 | R | UIRootContextPtr [DERIVED] (also: ` — unknown context/state pointer) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If node's prev is non-null → link prev->next = node->next. If node's next is non-null → link next->prev = node->prev. If node is list head (this[11] == node) → update head to node->next. If dword_8B8F28 is null → skip global re-insert (BLOCKED: no global list). If global list head at dword_8B8F28+348 is null → set as head. Otherwise traverse to tail and append. Always clears node flag bit 2 (active).
