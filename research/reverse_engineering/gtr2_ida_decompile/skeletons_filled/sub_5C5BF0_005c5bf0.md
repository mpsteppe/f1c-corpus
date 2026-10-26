## sub_5C5BF0_005c5bf0 — vtable/global pointer installer

**Summary:** Minimal constructor-like function that writes the pointer value held in global `off_72A1F8` into the object's first field (`this[0]`). Initializes the object's vtable/class pointer slot for a C++ class in the GTR2 code.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Object vtable/class pointer slot; receives the pointer loaded from global `off_72A1F8` |

**Written-by note (persistence):**
- this 0x0: written unconditionally once per call, straight-line, no branches; survives until the object is re-initialized or this function runs again. An external poke to this slot would persist until any subsequent call re-stores the global's current value.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0072a1f8 | off_72A1F8 | R | Global holding the vtable/class pointer value that is loaded and stored into `this[0]` |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — single unconditional store, no reads of object state, nothing checked, nothing blocked.
