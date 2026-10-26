## RendererVtableDispatchWrapper_00519828 — RendererVtableDispatchWrapper

**Summary:** Dispatches a renderer call through a vtable function pointer at *(this+0x188)+4, passing three zero-valued initial arguments followed by the three caller arguments. Simple wrapper for renderer API calls.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x188) | 0x4 | R | — | vtable function pointer (renderer API call) |
| this | 0x188 | R | — | pointer to renderer vtable/interface struct |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None. Always dispatches through vtable with no validation.
