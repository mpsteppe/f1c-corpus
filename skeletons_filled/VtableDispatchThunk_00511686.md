## VtableDispatchThunk_00511686 — Vtable thunk with stack buffer

**Summary:** Allocates a 200-byte stack buffer and dispatches through vtable entry +0xC (fourth vfunc). The buffer is passed as a parameter, likely for output data. Returns the vfunc result.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0xC | R | — | fourth vtable entry — function called with a1 and stack buffer |
| this | 0x0 | R | — | pointer to vtable/state dispatcher object |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No conditional guards — call executes unconditionally.
