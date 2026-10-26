## MergeSort_b2e0_004bb2e0 — Recursive merge sort on singly-linked list

**Summary:** Classic merge sort for singly-linked list sorted by float key value (descending). Splits list at midpoint, recursively sorts halves, then merges by comparing data[0] as float. Modifies next pointers in place.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SortedLinkedListInsert (004b81a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(*(this+0x4)+0x4)+0x0) | 0x0 | R | — | Sort key float value from third-level pointer chain |
| *(*(this+0x4)+0x4) | 0x0 | R | — | Data pointer in right-half node |
| *(*(this+0x4)+0x4) | 0x4 | R | — | Next pointer in right-half node |
| *(this+0x4) | 0x4 | RW | 0 | Split point: mid node's next set to 0 to separate halves |
| obj | 0x0 | R | — | Node data pointer (dereferenced to float sort key) |
| this | 0x0 | R | — | List head pointer (during recursion, current sublist head) |
| this | 0x4 | RW | — | Node next pointer (rearranged during merge) |

**Written-by note (persistence):**
- *(this+0x4) 0x4: set to 0 at split point; persists until merge re-links
- this 0x4: overwritten during merge; persists as sorted list links

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004bb2e0 | MergeSort_b2e0 | Recursive self-call for left and right sublists |

**Guard conditions:** Returns a1 unchanged if null or count < 2.
