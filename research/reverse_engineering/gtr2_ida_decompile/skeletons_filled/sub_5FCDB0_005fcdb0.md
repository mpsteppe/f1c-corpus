## sub_5FCDB0_005fcdb0 — Mark queued record element dirty (write value at element+24)

**Summary:** Conditional dirty-updater: when the object has flag 0x200 set and a2 is a valid record index, it locates the stride-132 record and, if the record is queued (0x100), optionally writes a4 into the record's data at element offset a3*64+24 (only when flag 0x400 is set) and always sets the object's 0x80000 "needs re-upload" flag.

**Called by:** sub_5452C0 (005452c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Flag word: 0x200 enables the update, 0x400 enables the per-element value write, 0x80000 is OR-set to signal pending re-upload |
| this | 0x2C | R | — | Capacity (this[11]); a2 must be below it |
| this | 0x34 | R | — | Base of the 132-byte record array (this[13]); record = base + 132*a2 |

**Written-by note (persistence):**
- this 0x0: 0x80000 is conditionally OR-set each qualifying call and is never cleared here — it persists until an upload path clears it; other bits are only read, so external pokes to them survive unchanged.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Three stacked gates, all required: `(*this & 0x200) != 0` (feature enabled) and `a2 < this[11]` (valid index); then the record's own `0x100` queued bit; then, for the actual value write only, `(*this & 0x400) != 0` — if 0x400 is clear the write `*(record[32] + (a3<<6) + 24) = a4` is skipped. When the 0x200/0x100 gates pass, flag 0x80000 is set regardless of 0x400. Any failing gate blocks everything after it.
