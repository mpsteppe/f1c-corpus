## LinkedListNodeAppend_0048d2b0 — LinkedListNodeAppend

**Summary:** Appends a new value node to a doubly-linked UI list/collection. Allocates a data node (8 bytes) with vtable and stores the input value, then allocates a list node (16 bytes) to link it, updating tail pointer and count.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** PlayerProfileScanner (00468ee0), sub_46A2A0 (0046a2a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x2C | R | — | Vtable method index 44/0x2C — called after insertion to signal change |
| this | 0x0 | R | — | Vtable pointer of the list object |
| this | 0x31C | RW | — | Head pointer of linked list |
| this | 0x320 | RW | — | Tail pointer of linked list (updated to new node) |
| this | 0x324 | RW | — | First-element pointer (set once on initial insert, never updated afterward) |
| this | 0x328 | RW | — | Item count, incremented on each append |

**Written-by note (persistence):**
- this 0x31C: once if list was empty, else unchanged; survives external poke
- this 0x320: every call, always set to new node; survives external poke
- this 0x324: once on first insertion only; survives external poke
- this 0x328: incremented every call; survives external poke

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0048c9a0 | SimpleVTableNullInit | Initialize 8-byte data node with vtable |
| 0048c9e0 | IntSetterAt4 | Store the appended value into data node at offset +4 |
| 0048cc20 | LinkedListSizeCalcWithMaxTracking | Recalculate size stats after insertion |
| 00587c03 | OperatorNewNhMallocWrapper | Heap-allocate 8 bytes (data node) and 16 bytes (list node) |

**Guard conditions:** None — always appends; returns 0 only if data node allocation fails (no early return on empty list, just branches for head-vs-tail linking).
