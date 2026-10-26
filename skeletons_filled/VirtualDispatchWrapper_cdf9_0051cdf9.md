## VirtualDispatchWrapper_cdf9_0051cdf9 — Virtual dispatch with pointer advancement

**Summary:** Dispatches a single-element operation via a virtual method call on a sub-struct, then advances both the input pointer and output count by 1. Thin wrapper around a vtable-based processing function.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x19C) | 0xC | R | — | vtable[3] — method called for single-element processing |
| this | 0x19C | R | — | Pointer to sub-struct with vtable for virtual dispatch |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guards — unconditional virtual dispatch and pointer advancement.
