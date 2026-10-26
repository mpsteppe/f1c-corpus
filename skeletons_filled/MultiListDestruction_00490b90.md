## MultiListDestruction_00490b90 — MultiLinkedListDestructor

**Summary:** Destructor for a struct containing 3 embedded linked lists and an array of list elements. Destroys all list iterators, frees each list's nodes (with conditional ShortComputation_1e60 for active entries), frees the array, zeroes the struct.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ConditionalDestructor_1740 (00491740)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x1C)+0x4) | 0x4 | R | — | Next pointer of first node in second sub-list |
| *(*(this+0x2C)+0x4) | 0x4 | R | — | Next pointer of first node in third sub-list |
| *(*(this+0xC)+0x4) | 0x4 | R | — | Next pointer of first node in first sub-list |
| *(this+0x1C) | 0x0 | R | — | Head pointer of second sub-list |
| *(this+0x1C) | 0x8 | R | — | Flags byte (+8) of first node in second sub-list |
| *(this+0x2C) | 0x0 | R | — | Head pointer of third sub-list |
| *(this+0x2C) | 0x8 | R | — | Flags byte (+8) of first node in third sub-list |
| *(this+0xC) | 0x0 | R | — | Value pointer of first node in first sub-list |
| *(this+0xC) | 0x8 | R | — | Flags byte (+8) of first node in first sub-list |
| this | 0x0 | R | — | Count of array entries (iterations for array destruction) |
| this | 0x8 | R | — | Pointer to array of 16-byte list elements |
| this | 0xC | RW | 0 | First sub-list head/sentinel (4 DWORDs zeroed after walk) |
| this | 0x10 | RW | 0 | First sub-list field 2 |
| this | 0x14 | RW | 0 | First sub-list field 3 |
| this | 0x18 | RW | 0 | First sub-list field 4 |
| this | 0x1C | RW | 0 | Second sub-list head (4 DWORDs zeroed after walk) |
| this | 0x20 | RW | 0 | Second sub-list field 2 |
| this | 0x24 | RW | 0 | Second sub-list field 3 |
| this | 0x28 | RW | 0 | Second sub-list field 4 |
| this | 0x2C | RW | 0 | Third sub-list head (4 DWORDs zeroed after walk) |
| this | 0x30 | RW | 0 | Third sub-list field 2 |
| this | 0x34 | RW | 0 | Third sub-list field 3 |
| this | 0x38 | RW | 0 | Third sub-list field 4 |

**Written-by note (persistence):**
- this 0xC: zeroed after walk; destroyed
- this 0x10: zeroed after walk; destroyed
- this 0x14: zeroed after walk; destroyed
- this 0x18: zeroed after walk; destroyed
- this 0x1C: zeroed after walk; destroyed
- this 0x20: zeroed after walk; destroyed
- this 0x24: zeroed after walk; destroyed
- this 0x28: zeroed after walk; destroyed
- this 0x2C: zeroed after walk; destroyed
- this 0x30: zeroed after walk; destroyed
- this 0x34: zeroed after walk; destroyed
- this 0x38: zeroed after walk; destroyed

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004910d0 | ListIteratorFullDestruction | Destroy list iterator/sentinel struct (3 embedded + array entries) |
| 00491db0 | LinkedListDestructor_1db0 | Destructor for individual linked list element in array |
| 00491e60 | ShortComputation_1e60 | Short computation called with arg=1 when freeing active/live node |
| 004b0170 | EmptyStub_0170 | Empty stub called on value pointer for first sub-list nodes |
| 00587bcf | FreeWrapper_7bcf | Free heap memory for list nodes and array |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x0 | > | 0 | Array element count — PASS: destroy each array entry; BLOCKED: skip |

**Guard interpretation:** If `this[0]` (count) > 0, iterate from 0 to count-1 calling ListIteratorFullDestruction on each 16-byte array element. If `this[2]` (array pointer) non-null, free array. Then walk each of the 3 sub-lists: if head pointer non-null, walk nodes freeing each; if node byte at +8 is non-zero AND node value is non-zero, call ShortComputation_1e60(1) before free (for first list, also call EmptyStub_0170 on value).
