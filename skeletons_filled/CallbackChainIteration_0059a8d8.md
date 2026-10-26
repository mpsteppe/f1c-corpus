## CallbackChainIteration_0059a8d8 — Callback chain linked-list iteration

**Summary:** Iterates a singly-linked callback list rooted at this+0x1C. For each node, calls the function pointer at node offset 0x8 with (a2, this, node_userdata), where node_userdata is at offset 0x4.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_59A980 (0059a980)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1C) | 0x0 | R | — | Linked-list next pointer (node->next) |
| *(this+0x1C) | 0x4 | R | — | User data/context passed to callback |
| *(this+0x1C) | 0x8 | R | — | Function pointer invoked for callback |
| this | 0x1C | R | — | Head of callback linked list |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Loop continues while current node pointer is non-null.
