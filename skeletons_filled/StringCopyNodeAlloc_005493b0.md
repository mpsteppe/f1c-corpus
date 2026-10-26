## StringCopyNodeAlloc_005493b0 — Allocate and append string copy node to list

**Summary:** Appends a new string copy node to a linked list (head at this+0xFC). Walks to tail via node+0x14 next pointer if non-empty; otherwise sets head. Allocates 24-byte node, initializes via ShortComputation_8e00, copies input string with strcpy, and returns result of sub_589901. Mirror of LinkedListStringInsert pattern with different list head offset.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_55A790 (0055a790)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x110)+0x14) | 0x14 | RW | — | Tail next-pointer of list; linked to new node |
| this | 0xFC | RW | 0 | Head of string copy linked list; set on first insertion |
| this | 0x110 | R | — | Pointer to secondary list structure accessed through callee sub_589901 |

**Written-by note (persistence):**
- *(*(this+0x110)+0x14) 0x14: written once per insertion (tail next-pointer set to new node); overwritten each insertion
- this 0xFC: written once on first insertion (to new node) or to 0 if allocation fails

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00548e00 | ShortComputation_8e00 | Initialize newly allocated 24-byte node; returns char pointer to string buffer |
| 00587c03 | OperatorNewNhMallocWrapper | Allocate 24 bytes for new string copy node |
| 00589901 | sub_589901 | Finalize/register the inserted node; return result code |

**Guard conditions:** If `this[0xFC]` (head) is non-null → walk to tail via node+0x14 next pointers, then append new node. If null → allocate new node as head. Allocation failure BLOCKS initialization: head set to 0 if first insertion, or tail next-pointer left unchanged if appending.
