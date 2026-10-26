## LinkedListStringInsert_005492f0 — Insert string node at end of linked list

**Summary:** Appends a new string node to a linked list of strings. If list head (this+0xF8) is non-null, walks to tail via node+0x14 next pointer; otherwise sets head. Allocates 24-byte node, initializes via ShortComputation_8e00, copies input string via strcpy, and calls sub_589901 for final processing. Part of string/name registration system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_55A790 (0055a790)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x10C)+0x14) | 0x14 | RW | — | Tail next-pointer of secondary list accessed through callees |
| this | 0xF8 | RW | 0 | Head of string linked list; set to new node on first insertion |
| this | 0x10C | R | — | Pointer to secondary structure accessed through callee sub_589901 |

**Written-by note (persistence):**
- *(*(this+0x10C)+0x14) 0x14: written conditionally through callee sub_589901 when list is non-empty
- this 0xF8: written once on first insertion (to new node) or to 0 if allocation fails; subsequent insertions only modify tail next-pointer

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00548e00 | ShortComputation_8e00 | Initialize newly allocated 24-byte node; returns char pointer to string buffer |
| 00587c03 | OperatorNewNhMallocWrapper | Allocate 24 bytes for new string node |
| 00589901 | sub_589901 | Finalize/register the inserted string node; return result code |

**Guard conditions:** If `this[0xF8]` (head pointer) is non-null → walk to end of list via node+0x14 next pointers, then allocate and append. If null → allocate new node and set as head directly. Allocation failure (OperatorNewNhMallocWrapper returns null) BLOCKS initialization — head set to 0 if first insertion fails.
