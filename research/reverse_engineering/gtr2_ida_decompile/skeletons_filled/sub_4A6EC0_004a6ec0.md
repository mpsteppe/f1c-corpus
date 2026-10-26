## sub_4A6EC0_004a6ec0 — conditional teardown / close handler

**Summary:** Object teardown helper: if the "already handled" flag at this+0x255 is clear, it runs a state-reset call (sub_4D4060 with arguments 0, 1), then unconditionally clears that flag and continues the teardown chain (final cleanup call visible in the body).

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x255 | RW | 0 | "Handled/closed" flag byte: tested before the reset call, then always cleared to 0 |

**Written-by note (persistence):**
- this 0x255: cleared unconditionally on every invocation; an external poke to 1 would only survive until the next call to this function and would suppress the sub_4D4060(0,1) reset for that invocation only.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d4060 | sub_4D4060 | Reset/state routine invoked with constants (0, 1) when the flag is clear; exact meaning unknown |

**Guard conditions:** Checks `this[597]` (0x255). If it is 0 (not yet handled) → sub_4D4060(0, 1) is called. If nonzero → that call is skipped. In both cases the byte is then set to 0 and the remaining teardown step runs; there is no early return.
