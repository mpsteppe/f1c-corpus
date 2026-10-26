## VtableMethodDispatchWrapper_00476050 — VTableMethodAtOffset8Dispatch

**Summary:** Thunk that dispatches to the third vtable method (offset +8 from vtable base) of the object, passing fields at 0x14 and 0x18 as additional arguments.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x8 | R | — | Vtable method pointer at index 2 (offset +8) |
| this | 0x0 | R | — | Vtable pointer of the object |
| this | 0x14 | R | — | First argument passed to vtable method |
| this | 0x18 | R | — | Second argument passed to vtable method |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guards — always dispatches.
