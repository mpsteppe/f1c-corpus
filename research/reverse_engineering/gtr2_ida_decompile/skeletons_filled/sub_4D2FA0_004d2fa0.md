## sub_4D2FA0_004d2fa0 — SetBoundsSource

**Summary:** Stores the source bounds/rect structure pointer a2 at 0x34 and derives two extent counts at 0x4 and 0x8 from differences of a2's fields (a2[4]-a2[3] and a2[2]-a2[1]), each clamped to 0 and incremented by 1 only when the difference is positive.

**Called by:** sub_4A0FF6 (004a0ff6)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | RW | — | first extent derived from a2[4]-a2[3]: 0 if delta ≤ 0, else delta+1 |
| this | 0x8 | RW | 0 | second extent derived from a2[2]-a2[1]: 0 if delta ≤ 0, else delta+1; also the return value when positive |
| this | 0x34 | RW | — | pointer to the source bounds structure a2 (matches the 0x34 pointer consumed by sub_4D2FE0) |

**Written-by note (persistence):**
- this 0x4: recalculated from a2 on every non-null call; an external poke survives until the setter is invoked again.
- this 0x8: recalculated from a2 on every non-null call; also zeroed on the delta ≤ 0 path; poke survives until next call.
- this 0x34: pointer overwritten with a2 on every non-null call; poke survives until next call.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** a2 == 0 → entire body is skipped (no fields written) and a2 (NULL) is returned. a2 != 0 → 0x34 is written; then per extent: difference ≤ 0 stores 0, difference > 0 stores difference+1. Final return is the second extent value (0 or delta+1).
