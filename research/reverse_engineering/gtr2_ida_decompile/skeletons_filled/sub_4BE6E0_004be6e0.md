## sub_4BE6E0_004be6e0 — install class vtable / constructor-style helper

**Summary:** Stores the class vtable pointer `off_70F4C8` at offset 0 of `this` and tail-calls `sub_4D83E0(this)` (a shared routine variant differing from the `sub_4D83B0` used by neighbouring helpers).

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | C++ vtable/class pointer slot; overwritten with `&off_70F4C8` |

**Written-by note (persistence):**
- this 0x0: written unconditionally each call (normally once at construction); an external poke survives until reconstruction/destruction of the object.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0070f4c8 | off_70F4C8 | R | Vtable/class descriptor; its address is stored into `this[0]` |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none — unconditional vtable store followed by the shared call.
