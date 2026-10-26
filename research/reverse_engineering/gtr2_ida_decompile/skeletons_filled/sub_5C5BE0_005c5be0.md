## sub_5C5BE0_005c5be0 — constructor / vtable installer (two-level)

**Summary:** Trivial constructor that stores two consecutive vtable pointers into the object's first field: first the base-class vtable `off_72A1F0`, then the derived-class vtable `off_726A24`, leaving the object bound to the derived vtable. Part of a C++ class hierarchy initialization in the GTR2 codebase.

**Called by:** sub_5C5BC0 (005c5bc0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Object vtable pointer (first written with base vtable `off_72A1F0`, then immediately overwritten with derived vtable `off_726A24`) |

**Written-by note (persistence):**
- this 0x0: written twice unconditionally in straight-line code every call; final stored value is the derived vtable `off_726A24`. An external poke would survive only until the next call to this constructor; the function itself is deterministic with no branches or side conditions.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0072a1f0 | off_72A1F0 | R | Base-class vtable pointer, read and stored to `this[0]` before being replaced |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — no branches, no reads of object state. The function unconditionally overwrites `this[0]` twice; both stores execute on every call, so nothing is blocked or skipped.
