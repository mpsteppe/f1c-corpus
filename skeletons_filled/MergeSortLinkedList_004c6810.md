## MergeSortLinkedList_004c6810 — Recursive merge sort for linked lists

**Summary:** Standard top-down merge sort for a singly-linked list. Counts nodes, splits at midpoint, recursively sorts both halves, then merges using `SceneSortComparator` for ordering. Returns pointer to sorted list head.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SceneFileFilterBuilder (004c6330)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x4) | 0x4 | RW | 0 | Next pointer in list node (modified during split and merge) |

**Written-by note (persistence):**
- *(this+0x4) 0x4: temporarily set to 0 during split (midpoint terminator); rewritten during merge to rewire sorted order

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004c5d30 | SceneSortComparator | Compare two filter property nodes by scene order position and name |
| 004c6810 | MergeSortLinkedList | Recursive call for left and right halves of split list |

**Guard conditions:** Returns input pointer unchanged if list is null or contains fewer than 2 nodes (already sorted).
