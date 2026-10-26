## sub_4CE5C0_004ce5c0 — Reset state, dispatch virtuals

**Summary:** Clears three byte flags at 0x224-0x226 and a dword at 0x228, then calls two virtual methods through the object's vtable — slot at vtable+0x2C with argument 0, and slot at vtable+0x94 with this — returning the second call's result. A state-reset/reinit helper using virtual dispatch.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x2C | R | — | vtable slot (function pointer) invoked with argument 0 |
| obj | 0x94 | R | — | vtable slot (function pointer) invoked with this; its return value is propagated to the caller |
| this | 0x0 | R | — | Object vtable pointer, loaded twice for the two virtual dispatches |
| this | 0x224 | RW | 0 | Byte flag cleared to 0 |
| this | 0x225 | RW | 0 | Byte flag cleared to 0 |
| this | 0x226 | RW | 0 | Byte flag cleared to 0 |
| this | 0x228 | RW | 0 | Dword field cleared to 0 |

**Written-by note (persistence):**
- this 0x224: zeroed unconditionally on every call — an external poke is lost at the next invocation.
- this 0x225: zeroed unconditionally on every call — an external poke is lost at the next invocation.
- this 0x226: zeroed unconditionally on every call — an external poke is lost at the next invocation.
- this 0x228: zeroed unconditionally on every call (after the first virtual call, before the second) — an external poke is lost at the next invocation.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — all four clears and both virtual calls execute unconditionally; no values are tested and no early return exists.
