## ShortComputation_63c0_004863c0 — LinkedListIndexLookup

**Summary:** Looks up a node by zero-based index in a singly-linked list rooted at this+0x90. Returns the node pointer at the given index, or null if the index is out of range or negative.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** UIListManagementHandler (0048a3c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x11C) | 0x8C | R | — | next-node pointer within each linked list node (offset 0x8C from node base) |
| this | 0x90 | R | — | head pointer of the linked list |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** checks `a2 >= 0` — if negative, returns 0 immediately (BLOCKED). Then checks this[36] (offset 0x90) != NULL — if null, returns 0 (BLOCKED). Then if a2 > 0, loops a2 steps following next pointers at node+0x8C; null node encountered mid-traversal breaks loop and returns the null (BLOCKED). Returns the node pointer at the target index (PASSES).
