## LinkedListMergeSort_47d0_004647d0 — Linked list merge sort (recursive)

**Summary:** Recursive merge sort for singly-linked list. Counts nodes, splits at midpoint into two halves, recursively sorts each half, then merges based on comparison of sort key at (*node)[2] (offset 0x8 of node's pointed-to data).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ChampionshipStandingsReOrdering (00462a10)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x4) | 0x4 | RW | 0 | Node's next pointer; temporarily cleared to split list |

**Written-by note (persistence):**
- *(this+0x4) 0x4: temporarily zeroed during split, restored during merge

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004647d0 | LinkedListMergeSort_47d0 | Recursive call to sort each half |

**Guard conditions:** If input pointer a1 is NULL, return NULL. If list has fewer than 2 nodes (count < 2), return unsorted.
