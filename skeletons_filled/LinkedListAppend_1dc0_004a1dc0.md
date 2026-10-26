## LinkedListAppend_1dc0_004a1dc0 — LinkedListAppend

**Summary:** Appends a new node containing data to a linked list. Allocates a 12-byte node, populates it with data pointer and zeroed next/flag fields, then inserts at the tail. Updates head (if first node), tail, and element count.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ShortComputation_1b70 (004a1b70)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x4) | 0x4 | RW | — | previous tail's next pointer (when list non-empty) |
| this | 0x0 | RW | — | head pointer of linked list |
| this | 0x4 | RW | — | tail pointer of linked list |
| this | 0x8 | RW | — | second tracker pointer (set to new node when list empty; not written when non-empty) |
| this | 0xC | RW | — | element count of linked list |
| this | 0x10 | R | — | guard flag; must be non-zero for append to proceed |

**Written-by note (persistence):**
- *(this+0x4) 0x4: written once per append when list non-empty; persists as linked list linkage
- this 0x0: written once on first append; persists as head
- this 0x4: written every append (new tail); persists
- this 0x8: written once on first append; survives as first-node tracker
- this 0xC: incremented every append; persists as count

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587c03 | OperatorNewNhMallocWrapper | Allocates 12-byte linked list node |

**Guard conditions:** Flag byte at offset 0x10 must be non-zero AND a2 (data pointer) must be non-null. If either is false, returns 0 (no append). Otherwise allocates node and appends.
