## DoublyLinkedListNodeInsert_00497510 — InsertNodeAtDoublyLinkedListTail

**Summary:** Allocates a 16-byte doubly-linked list node initialized with data `a2` and flag=1 (byte at +12). If list empty, sets head/tail to new node; otherwise appends to tail. Increments counter at 0x2C and node count at 0x10 on each call.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_492460 (00492460)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | RW | — | Head pointer of doubly-linked list |
| this | 0x8 | RW | — | Tail pointer of doubly-linked list |
| this | 0xC | RW | — | Secondary pointer (set to head on first insert) |
| this | 0x10 | R | — | Node count (incremented on insert) |
| this | 0x2C | R | — | Operation counter (incremented each call) |

**Written-by note (persistence):**
- this 0x4: Written conditionally (only when list was empty). External poke can survive between non-empty inserts.
- this 0x8: Written each insert. External poke does not survive.
- this 0xC: Written conditionally (only when list was empty). External poke can survive between non-empty inserts.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0054fc40 | SimpleSetter_fc40 | Sets a flag to 1 |
| 0054fdf0 | SimpleSetter_fdf0 | Passes `this` to setter |
| 00587c03 | OperatorNewNhMallocWrapper | Allocates 16-byte node memory |

**Guard conditions:** Parameter a2 must be non-null to proceed with node allocation and insertion. If a2 is zero, only counter increment and setter calls execute.
