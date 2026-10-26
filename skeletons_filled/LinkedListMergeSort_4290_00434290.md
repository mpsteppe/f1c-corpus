## LinkedListMergeSort_4290_00434290 — LinkedListMergeSortRecursive

**Summary:** Recursive merge sort implementation for singly-linked list of string entries using ANSI strcmp comparison. Splits list in half, sorts each half recursively, then merges. File directory enumeration system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DirectoryFileEnumerator (00431db0), LinkedListMergeSort (00434090)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x4) | 0x4 | RW | 0 | split point: null-terminates left half of list |

**Written-by note (persistence):**
- *(this+0x4) 0x4: temporarily set to 0 during split, restored during merge

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00434290 | LinkedListMergeSort_4290 | recursive self-call on each list half |

**Guard conditions:** returns input pointer unchanged if null or fewer than 2 nodes. null string pointers replaced with byte_5EA438 fallback for strcmp. merge picks smaller string via strcmp >= 0 for left vs right ordering.
