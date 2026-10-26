## sub_5FCAC0_005fcac0 — Enqueue element record into the ordered update list

**Summary:** Registration helper: given record index a2 (stride-132 record array at this+0x34), it checks both a2 and the running count (this+0x30) are below capacity (this+0x2C); if the record's 0x100 bit is clear it assigns the record the next sequence number, computes its destination buffer offset as this+0x60 + count*this+0x24*64, stores the record pointer in the list at this+0x38, sets the record's 0x100 bit and increments the count.

**Called by:** sub_543C80 (00543c80), sub_543E60 (00543e60), sub_544680 (00544680), sub_544880 (00544880)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x24 | R | — | Element size multiplier (this[9]) used in the 64-byte-scaled offset formula |
| this | 0x2C | R | — | Capacity (this[11]); both count and record index must be below it |
| this | 0x30 | R | — | Current count (this[12]): sequence number source, list index, and post-incremented |
| this | 0x34 | R | — | Base of the 132-byte record array (this[13]); record = base + 132*a2 |
| this | 0x38 | R | — | Array of record pointers (this[14]); slot at index this[12] receives the record |
| this | 0x60 | R | — | Destination data base (this[24]) added to the computed offset written at record+128 |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Two early gates: the pair `(v3 < v2 && a2 < v2)` — i.e. current count (< this[0x2C]) and the requested record index a2 must both be below capacity; if either fails, nothing happens. Inside, the record's flag dword is tested: when `(*record & 0x100) != 0` (already queued) the update is BLOCKED — no writes at all. When both pass: record[+4] = current count, record[+128] = this[0x60] + (count*this[9])<<6, list[count] = record, record flag |= 0x100, and the count (this+0x30) is incremented.
