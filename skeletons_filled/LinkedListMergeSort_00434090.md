## LinkedListMergeSort_00434090 — LinkedListMergeSortWideChar

**Summary:** Sorts a doubly-linked list of string entries using merge sort with wide-character (2-byte) lexicographic comparison. Reconnects head/tail/prev pointers after sort. File directory enumeration system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DirectoryFileEnumerator (00431db0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(obj+0x4) | 0x4 | RW | 0 | split point: null-terminates left half of list |
| obj | 0x4 | R | — | linked list node: next pointer |
| this | 0x0 | RW | — | result head pointer after merge sort |
| this | 0x4 | RW | — | result tail pointer after merge sort |
| this | 0x8 | RW | — | result head pointer (duplicate for circular/linked consistency) |

**Written-by note (persistence):**
- *(obj+0x4) 0x4: temporarily set to 0 during split, restored during merge
- this 0x0: written once with sorted head, external poke survives
- this 0x4: written once with sorted tail, external poke survives
- this 0x8: written once with sorted head, external poke survives

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00434290 | LinkedListMergeSort_4290 | recursive merge sort helper (uses ANSI strcmp) called on each list half |

**Guard conditions:** returns early if list has fewer than 2 nodes (no sorting needed). during merge, null string pointers replaced with fallback to byte_5EA438 for comparison. comparison uses byte-by-byte wide-char lexicographic comparison (2-byte stride).
