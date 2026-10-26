## sub_4BE0F0_004be0f0 — install class vtable / constructor helper

**Summary:** Stores the class vtable pointer `off_70ECA8` at offset 0 of `this` and tail-calls the shared routine `sub_4D83B0()` (same callee as `sub_4BDCE0`, `sub_4BDF60`, `sub_4BE0A0`). Standard MSVC constructor/vtable-install shape.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | C++ vtable/class pointer slot; overwritten with `&off_70ECA8` |

**Written-by note (persistence):**
- this 0x0: written unconditionally each call (normally once at construction); an external poke survives until object reconstruction/destruction.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0070eca8 | off_70ECA8 | R | Vtable/class descriptor; its address is stored into `this[0]` |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none — unconditional vtable store followed by the shared call.
