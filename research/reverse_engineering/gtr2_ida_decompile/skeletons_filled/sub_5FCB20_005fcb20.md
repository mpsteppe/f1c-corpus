## sub_5FCB20_005fcb20 — Dequeue element record with swap-with-last compaction

**Summary:** Removal counterpart of the list registration: for record index a2 it checks count > 0 and a2 < capacity, then if the record's 0x100 flag is set it compacts the list — the last list entry (this+0x38, slot count-1) is copied into the removed record's data slot (qmemcpy of this[9]<<6 bytes at this+0x60-based offsets), given the removed record's sequence number and list slot — and finally clears the record's 0x100 bit and decrements the count.

**Called by:** sub_544320 (00544320), sub_5452C0 (005452c0), sub_548230 (00548230), sub_548800 (00548800), sub_548BA0 (00548ba0), sub_548F30 (00548f30), sub_54A630 (0054a630), sub_5FCBD0 (005fcbd0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x24 | R | — | Element size multiplier (this[9]); byte count for the move is this[9]<<6 |
| this | 0x2C | R | — | Capacity (this[11]); a2 must be below it |
| this | 0x30 | R | — | Current count (this[12]); must be > 0 and is decremented after removal |
| this | 0x34 | R | — | Base of the 132-byte record array (this[13]); record = base + 132*a2 |
| this | 0x38 | R | — | List array of record pointers (this[14]); last slot (4*count-4) is the swap source |
| this | 0x60 | R | — | Destination data base (this[24]) used with (this[9]*seq)<<6 offsets for the move |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Outer gates: `count > 0` (this+0x30) and `a2 < this[0x2C]` (capacity) must both hold, else nothing runs. The record's flag must have bit 0x100 set (`(*v4 & 0x100) != 0`) — if clear (not queued) the function is BLOCKED with no writes. Inside, the compaction move runs only when the last list pointer differs from the record and is non-null; if the last entry IS the record (or null) the move is skipped but the 0x100 bit is still cleared and the count decremented.
