## sub_6CD1F0_006cd1f0 — append node chain into indexed arrays

**Summary:** Walks a node chain (starting at table[this[1]+0x14][a3], following redirect link node+0x38 until -1, then next link node+0x8) and appends chain indices into per-slot counter/offset/output arrays whenever the node's referenced record lacks flag bit 0x10 — incrementing counters and optionally storing back-references.

**Called by:** sub_6CD265 (006cd265), sub_6CD9DB (006cd9db)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | Pointer to a container whose +0x10 table (record pointers indexed by node id) and +0x14 table (node pointers indexed by a3) are consulted |
| this | 0x8 | R | — | Counter array, one dword per slot; incremented each time a node is accepted |
| this | 0xC | R | — | Offset array, one dword per slot; summed with the counter array at 0x8 to form the output index |
| this | 0x10 | R | — | Output array pointer; when non-null, stores a3 at index (count[0x8] + offset[0xC]) for slot v4 |
| this | 0x14 | R | — | Read as (value at 0x4)+16: record pointer table indexed by node id v6; record's byte +4 is tested against 0x10 |
| this | 0x18 | R | — | Read as (value at 0x4)+20: node pointer table indexed by a3; yields the node v5 whose chain is walked |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Inner loop: while node+0x38 (v5[14]) != -1, a3 = that field and the node is re-fetched (redirect chain resolved before processing). Append/increment happens only when ((record byte +4) & 0x10) == 0; the back-reference store additionally requires this[4] (0x10) != 0. Outer traversal: while node+0x8 (v5[2]) != -1, continue with a3 = v5[2]; terminates and returns that field (-1).
