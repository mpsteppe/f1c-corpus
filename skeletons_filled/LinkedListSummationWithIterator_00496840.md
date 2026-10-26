## LinkedListSummationWithIterator_00496840 — LinkedListSummationWithIterator

**Summary:** Iterates a linked list starting from head (offset 0x4) using a cursor (offset 0xC), calling ShortComputation_58d0 on each node's value (first DWORD of node) and summing results. Stops when cursor is NULL or node value is zero. Returns accumulated sum. Part of a list-processing summation utility.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_485B90 (00485b90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | List head pointer (first node) — initial value for the iteration cursor |
| this | 0xC | RW | — | Iterator cursor (current node pointer); initialized from head, advanced by next pointer at node+4 |
| this | 0x10 | R | — | unknown — not directly accessed in this function (possibly list terminator or count) |

**Written-by note (persistence):**
- this 0xC: iterator cursor updated each loop iteration to next node; persists across calls

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004958d0 | ShortComputation_58d0 | Compute a value from each node's data field (accumulated into sum) |

**Guard conditions:** Cursor at 0xC is NULL → break (end of list). Node value (first DWORD of node) is 0 → break (sentinel/empty node). Both conditions terminate iteration early.
