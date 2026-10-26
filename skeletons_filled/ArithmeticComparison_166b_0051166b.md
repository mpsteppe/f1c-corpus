## ArithmeticComparison_166b_0051166b — Dispatch chain caller

**Summary:** Calls a chain of functions: vfunc 2 on the object (third vtable entry), then sub_516959, UtilityFunction_9ca4, and VtableDispatchThunk. Returns the thunk result.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x8 | R | — | third vtable entry — function pointer called on this object |
| this | 0x0 | R | — | pointer to vtable/state dispatcher object |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00516959 | sub_516959 | unknown — called with a1 as parameter |
| 00589ca4 | UtilityFunction_9ca4 | utility function called with literal 1 |
| address | VtableDispatchThunk | called with a1, result returned (function not in callee table — implicit from context) |

**Guard conditions:** No conditional guards — all calls execute unconditionally.
