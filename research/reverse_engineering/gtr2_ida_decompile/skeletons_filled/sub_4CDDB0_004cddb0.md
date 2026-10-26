## sub_4CDDB0_004cddb0 — SyncEnabledFlagFromPredicate

**Summary:** Refreshes an enabled/available byte from a virtual predicate: byte 0x134 is set to (predicate-at-vtable+0xA0 == 0), then a second virtual method (vtable+0xA4) is invoked for refresh/notification. Always returns 0.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0xA0 | R | — | Virtual method (vtable+0xA0) predicate; its result is inverted (== 0) into byte 0x134 |
| obj | 0xA4 | R | — | Virtual method (vtable+0xA4) called afterwards; return value ignored (refresh/notify hook) |
| this | 0x0 | R | — | Vtable pointer used to reach both virtual methods |
| this | 0x134 | RW | — | Byte flag (this[308]) latched to (predicate result == 0): 1 when the predicate failed, 0 when it succeeded |

**Written-by note (persistence):**
- this 0x134: Written unconditionally on every call from the predicate result — an external poke would be overwritten by the next invocation

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No branch in this function — execution is straight-line: virtual(vtable+0xA0) → latch this[0x134] = (result == 0) → virtual(vtable+0xA4) → return 0. Nothing is skipped; the predicate's result only controls the stored byte value, not control flow.
