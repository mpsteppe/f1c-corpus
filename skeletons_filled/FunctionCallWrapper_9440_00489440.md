## FunctionCallWrapper_9440_00489440 — NetCommVTableInit

**Summary:** Sets vtable to NetCommVTable and calls sub_485EB0 for base initialization. Constructor fragment for net communication objects.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DestructorWithSubObjectFree (004698c0), ShortComputation_be90 (0047be90), UIComponentDtor (0047fba0), FieldFreeUIDtor (00485ae0), ScalarDeletingDestructor (00485b20)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Vtable pointer — set to NetCommVTable |

**Written-by note (persistence):**
- this 0x0: Written once during construction. Not modified after init.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005abd78 | off_5ABD78 | R | NetCommVtable [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional init.
