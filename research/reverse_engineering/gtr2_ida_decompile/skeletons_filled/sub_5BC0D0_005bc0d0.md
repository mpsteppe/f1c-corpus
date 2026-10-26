## sub_5BC0D0_005bc0d0 — install vtable/class pointer at object offset 0

**Summary:** One-line constructor-style stub that overwrites the first dword of the object with the global pointer/value off_729664 — i.e., installs the class's vtable (or type descriptor) into `this+0`. No other fields touched.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Vtable/class pointer slot; assigned `off_729664` on every call. |

**Written-by note (persistence):**
- this 0x0: written unconditionally each call from the global off_729664; an external poke survives until the next call re-installs the pointer.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00729664 | off_729664 | R | Source value copied into the object's first dword — the class vtable/type pointer (or data object) installed by this stub. |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — the assignment executes unconditionally; no checks, nothing blocked.
