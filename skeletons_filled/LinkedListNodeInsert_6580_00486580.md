## LinkedListNodeInsert_6580_00486580 — List5InsertWithStringData

**Summary:** Allocates a string data buffer and a node wrapper, then appends the node to the tail of linked list 5 (rooted at this+0x54). Tracks head, tail, and node count. The node owns its data string.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_492A40 (00492a40)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x54 | RW | — | head pointer of linked list 5 (this[21]); set on first insertion |
| this | 0x58 | RW | — | tail pointer of linked list 5 (this[22]); updated every insertion |
| this | 0x5C | RW | — | alternate tail or previous pointer (this[23]); set on first insertion |
| this | 0x60 | R | — | node counter (this[24]); incremented on each successful insertion |

**Written-by note (persistence):**
- this 0x54: conditionally set on first insertion; external writes before next append survive
- this 0x58: unconditional update per insertion; external writes before next insertion survive
- this 0x5C: conditionally set on first insertion; external writes before first insertion survive

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00566650 | StringCopyWithBufferRealloc | copy source string into allocated data buffer |
| 00587c03 | OperatorNewNhMallocWrapper | allocate heap memory (8 bytes for data, 12 bytes for node) |

**Guard conditions:** first OperatorNewNhMallocWrapper(8) must succeed to create data buffer (if null, v4=0 and entire insertion is SKIPPED). Second OperatorNewNhMallocWrapper(12) must succeed to create node (if null, result=0 and node is SKIPPED, but v4 data buffer leaks). Then checks this[21] (head) != NULL to decide linking: if head non-null, links after tail at (this[22]+4); if null, sets head and this[23]. Counter at this[24] incremented only when v4 (data buffer) is non-null.
