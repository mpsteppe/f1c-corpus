## VtableDeleteWrapper_0057ef80 — virtual destructor delete wrapper

**Summary:** Calls through object vtable to invoke scalar deleting destructor (slot 0, flag=1). Null-safe: returns 0 if pointer is NULL.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x0 | R | — | Vtable pointer (first DWORD of object) |
| this | 0x0 | R | — | Object this pointer passed to destructor |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If `a1` is NULL → return 0 (no delete). Otherwise call virtual destructor.
