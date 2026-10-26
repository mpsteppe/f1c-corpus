## sub_4CDCE0_004cdce0 — TransitionStateOrFail

**Summary:** State-transition dispatcher: state 0 triggers virtual call (*(*this+0x2C))(this, 2) and state 1 triggers (*(*this+0x2C))(this, 3); any other state returns -1 immediately. After dispatching, if flag 0xF4 is set and sub_4E29B0(state) reports > 0, it records result code 2 at 0x108 and returns -1.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x2C | R | — | Virtual method slot (vtable+0x2C) invoked with the state-dependent argument 2 or 3; performs the actual transition |
| this | 0x0 | R | — | Vtable pointer used to reach the virtual method |
| this | 0x84 | R | — | State word (this[33]); only 0 and 1 are accepted, any other value aborts with -1 |
| this | 0xF4 | R | — | Flag (this[61]); when nonzero enables the post-transition error check |
| this | 0x108 | RW | 2 | Result/status code (this[66]); written to 2 on the checked failure path |

**Written-by note (persistence):**
- this 0x108: Conditional — written only when this[0xF4] is nonzero and sub_4E29B0(state) returns > 0; an external poke survives whenever that failure condition does not fire

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004e29b0 | sub_4E29B0 | Query/predicate over the state value; a result > 0 signals the error condition that turns the transition into a failure (exact semantics unknown) |

**Guard conditions:** On this[0x84]: value 0 → PASS through the virtual(this, 2) branch; value 1 → PASS through the virtual(this, 3) branch; any other value → BLOCKED, returns -1. Post-dispatch check: if this[0xF4] != 0 AND sub_4E29B0(this[0x84]) > 0 → this[0x108] = 2 and returns -1; otherwise returns 0.
