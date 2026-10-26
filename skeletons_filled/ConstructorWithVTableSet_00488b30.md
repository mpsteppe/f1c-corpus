## ConstructorWithVTableSet_00488b30 — UIWidgetVTableInit

**Summary:** Sets vtable to UIWidget and calls sub_485EB0 for further initialization. Lightweight constructor fragment.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_47EB30 (0047eb30), LinkedListPoolDestructor (0048aaa0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Vtable pointer — set to UIWidget vtable |

**Written-by note (persistence):**
- this 0x0: Written once during construction. Not modified after init.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005abc28 | off_5ABC28 | R | Vtable_UIWidget [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional init.
