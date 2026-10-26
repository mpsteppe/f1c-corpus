## ??1filebuf@@UAE@XZ_004e3d90 — filebuf destructor/reset (std stream buffer)

**Summary:** Per the IDB name, the std::filebuf destructor: it nulls the object's first and third dwords, writes -1 to the second, and invokes the string helper on the WindowName global. Effectively a full reset of the object's three leading fields.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 0 | first field reset to 0 (pointer/flags slot) |
| this | 0x4 | RW | 18446744073709551615 | second field reset to -1 (invalid/handle sentinel, e.g. fd) |
| this | 0x8 | RW | 0 | third field reset to 0 (pointer/count slot) |

**Written-by note (persistence):**
- this 0x0: written unconditionally on every call — an external poke is overwritten on the next invocation.
- this 0x4: written unconditionally on every call — an external poke is overwritten on the next invocation.
- this 0x8: written unconditionally on every call — an external poke is overwritten on the next invocation.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006e5588 | ??1filebuf@@UAE@XZ_SEH | R | exception-handler descriptor for this function (unwind metadata) |
| 006f16bc | WindowName | R | passed as the argument to sub_615860 (default window name string) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00615860 | StringCopyWithBufferRealloc [structural] | string helper invoked with the WindowName global; per its name it copies a string into a reallocated buffer |

**Guard conditions:** None — straight-line body with no branches; all three fields are reset unconditionally and the string helper is always invoked.
