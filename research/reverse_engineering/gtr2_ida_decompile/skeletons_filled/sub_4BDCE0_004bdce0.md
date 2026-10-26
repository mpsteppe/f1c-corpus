## sub_4BDCE0_004bdce0 — install class vtable / constructor helper

**Summary:** Minimal C++ constructor-style routine: stores the class vtable pointer `off_70E408` at offset 0 of `this`, then tail-calls `sub_4D83B0()` (likely a base-class constructor or shared init).

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | C++ vtable/class pointer slot; overwritten with `&off_70E408` |

**Written-by note (persistence):**
- this 0x0: written unconditionally on every call, once during object construction; an external poke survives only until the object is reconstructed — any later construction of the same object resets it.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0070e408 | off_70E408 | R | Vtable/class descriptor table; its address is taken and stored into `this[0]` |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none — no branches; vtable is stored and the callee invoked unconditionally.
