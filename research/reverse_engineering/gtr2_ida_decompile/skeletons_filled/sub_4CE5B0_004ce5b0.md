## sub_4CE5B0_004ce5b0 — Set byte flag at 0x10C

**Summary:** Trivial setter: stores the byte argument a2 into this+0x10C and returns that same value, letting callers chain or read back the stored byte.

**Called by:** sub_48F650 (0048f650), sub_4BBA30 (004bba30)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x10C | RW | — | Byte state/flag written unconditionally from the argument and returned |

**Written-by note (persistence):**
- this 0x10C: written unconditionally every time this function runs; because it is a passive setter, an external poke survives until the next time a caller invokes it.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — the store is unconditional; no values are checked and no early return exists.
