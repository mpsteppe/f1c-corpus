## SentinelSlotFill_004bd760 — SentinelSlotFill

**Summary:** Searches a fixed-size array of 10 slots (starting at this+56) for a sentinel value -1, fills the first empty slot with this[2], and returns the slot index; if no slot is free, returns 10.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** PostPitCleanup (0042a6f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | value to insert into slot |
| this | 0xE0 | R | — | first slot of 10-element sentinel-terminated array |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0xE0 | != | 18446744073709551615 | sentinel check on slot entry |

**Guard interpretation:** Loops through array of 10 entries at this+56 scanning for -1 (all bits set). First sentinel found → fill with this[2], return index. BLOCKED when all 10 slots are full (no -1 found) → return 10 (no insert).
