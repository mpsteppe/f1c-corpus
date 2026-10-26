## sub_4BDF20_004bdf20 — dispatch vtable slot +0x24, clear byte at 0x115

**Summary:** Calls the virtual method at vtable offset 0x24 with `(this, 0)`, saves its return value, then clears the byte flag at `this + 0x115` to 0. Behave like a "reset/disable" wrapper that also drops an enabling flag.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x24 | R | — | Virtual function pointer slot (vtable index 9); invoked with args `(this, 0)` |
| this | 0x0 | R | — | C++ vtable/class pointer slot; read to reach the virtual method |
| this | 0x115 | RW | 0 | Boolean state flag byte; cleared to 0 on every call |

**Written-by note (persistence):**
- this 0x115: unconditionally cleared to 0 each call — a "sticky off" reset; a poke of 1 would survive until this routine runs again (e.g. on disable/despawn).

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none — virtual call and flag clear execute unconditionally.
