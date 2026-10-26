## sub_5E5AE0_005e5ae0 — Reset two counter fields

**Summary:** Unconditionally zeroes two dword fields at this+0x17C and this+0x180 and returns 0. A small reset/clear helper, likely reinitializing a pair of counters or pointers before reuse.

**Called by:** sub_414450 (00414450)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x17C | RW | 0 | First dword cleared to zero (counter/timer/pointer slot) |
| this | 0x180 | RW | 0 | Second dword cleared to zero (counter/timer/pointer slot) |

**Written-by note (persistence):**
- this 0x17C: Unconditional store on every invocation; no conditions guard the write. An external poke survives only until this function is called again; call frequency cannot be determined from this function alone.
- this 0x180: Unconditional store on every invocation; no conditions guard the write. An external poke survives only until this function is called again; call frequency cannot be determined from this function alone.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — both stores execute unconditionally and the function always returns 0.
