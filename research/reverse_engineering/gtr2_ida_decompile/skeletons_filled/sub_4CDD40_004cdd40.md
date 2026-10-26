## sub_4CDD40_004cdd40 — RevertStateTransition

**Summary:** Rollback counterpart of the state-transition dispatcher: state 2 triggers virtual (*(*this+0x2C))(this, 0) and state 3 triggers (*(*this+0x2C))(this, 1); all paths clear the result code at 0x108 and return 0.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x2C | R | — | Virtual method slot (vtable+0x2C) invoked with 0 (state 2) or 1 (state 3) to revert the transition |
| this | 0x0 | R | — | Vtable pointer used to reach the virtual method |
| this | 0x84 | R | — | State word (this[33]); 2 and 3 select which revert argument is used |
| this | 0x108 | RW | 0 | Result/status code (this[66]); cleared to 0 on every path |

**Written-by note (persistence):**
- this 0x108: Written unconditionally to 0 on every execution path — an external poke would be overwritten by the next invocation

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x84 | == | 3 | State word selects the virtual(this, 1) revert branch |
| this | 0x84 | == | 2 | State word selects the virtual(this, 0) revert branch |

**Guard interpretation:** this[0x84] == 2 → PASS into virtual(this, 0) branch; this[0x84] == 3 → PASS into virtual(this, 1) branch; any other value → no virtual call, straight to clearing 0x108. All paths then set this[0x108] = 0 and return 0 — nothing is blocked outright; the guards only select the revert argument.
