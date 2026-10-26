## sub_5FCD10_005fcd10 — Update a queued record's payload

**Summary:** For record index a2 (below capacity at this+0x2C) it looks up the stride-132 record at this+0x34 and, if the record is queued (0x100 bit set), calls the payload handler sub_5D83E0 on the record's data at +20 with (a3, a4, a5), sets the record's 0x40000 "touched" bit, and clears the object-level 0x400000 flag.

**Called by:** sub_5438E0 (005438e0), sub_543B10 (00543b10), sub_543C80 (00543c80), sub_543E60 (00543e60), sub_544320 (00544320), sub_548800 (00548800), sub_54A630 (0054a630)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Object flag word; bit 0x400000 is cleared (`*this &= ~0x400000`) whenever a record update is applied |
| this | 0x2C | R | — | Capacity (this[11]); a2 must be below it |
| this | 0x34 | R | — | Base of the 132-byte record array (this[13]); record = base + 132*a2 |

**Written-by note (persistence):**
- this 0x0: conditional masked clear of bit 0x400000, only when a queued record update runs; other bits untouched, so pokes to other flag bits survive. An external poke setting 0x400000 is cleared again by the next qualifying call.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005d83e0 | sub_5D83E0 | Payload handler for the record's data block at record+20, invoked with (a3, a4, a5) |

**Guard conditions:** Two gates before anything happens: `a2 < this[11]` (index below capacity) and the record's flag dword must have bit 0x100 set (`(v7 & 0x100) != 0`, i.e. the record is queued). If either fails, the function is fully BLOCKED — no call, no writes. When both pass: sub_5D83E0(record+20, a3, a4, a5) runs, record flag |= 0x40000, and the object flag 0x400000 is cleared.
