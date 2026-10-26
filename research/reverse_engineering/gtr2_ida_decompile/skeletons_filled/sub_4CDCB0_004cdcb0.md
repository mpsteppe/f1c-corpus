## sub_4CDCB0_004cdcb0 — ValidateStatePairOrReset

**Summary:** Validates a stored state word (0x84) against an expected value; if it matches, the value is returned untouched, otherwise both the state word and its companion word (0x80) are cleared to 0 and 0 is returned. Simple conditional state-check/reset helper.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x80 | RW | 0 | Companion word (this[32]) zeroed together with the state word when validation fails |
| this | 0x84 | RW | 0 | State word (this[33]) compared against argument a2; returned when equal, cleared when not |

**Written-by note (persistence):**
- this 0x80: Conditional — written only inside the mismatch branch (set to 0); not refreshed on the matching path, so an external poke survives any call where the state matches
- this 0x84: Conditional — written only inside the mismatch branch (set to 0); otherwise left alone, so an external poke survives while it equals the expected argument a2

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Reads this[0x84] and compares to a2. If equal: PASS — no writes, returns this[0x84] (== a2). If not equal: both this[0x84] and this[0x80] are set to 0 and the function returns 0.
