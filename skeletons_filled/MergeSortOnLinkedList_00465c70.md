## MergeSortOnLinkedList_00465c70 — MergeSortAscendingOnLinkedList

**Summary:** Merge sort on singly linked list comparing float at (data+4). Ascending order by float key. Recursive split/merge pattern.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** EntityVisibilityGridManager (00465460)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x8) | 0x4 | R | — | next pointer from split-midpoint node in left half |
| obj | 0x4 | R | — | next pointer in a linked list node |
| this | 0x0 | R | — | data pointer in first/current node of a sublist |
| this | 0x4 | RW | — | next pointer being rewritten during merge |
| this | 0x8 | RW | 0 | sentinel/terminator for merged output tail |
| this | 0xC | R | — | node count (used to find midpoint) |

**Written-by note (persistence):**
- this 0x4: conditional — rewritten during merge to relink nodes. Survives (stable pointer field).
- this 0x8: rewritten to 0 at split boundary then to sublist head during merge. Non-persistent (local).

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00465c70 | MergeSortOnLinkedList | recursive call to sort each half |

**Guard conditions:** If a1 (input list head) is NULL → return a1 unchanged (empty list, blocked). If node count < 2 → return a1 unchanged (already sorted, blocked).
