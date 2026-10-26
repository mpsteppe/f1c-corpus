## ObjectConstructorWithVTableAndResourceReg_00474f40 — UIListTextItemInit

**Summary:** Initializes a UI list text item: calls base class init, sets vtable to off_5A4200, and registers two text resource handles via linked list insertion.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Vtable pointer for UI list text item |

**Written-by note (persistence):**
- this 0x0: set once; external vtable swap survives

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005a4200 | off_5A4200 | R | Vtable for UI list text item |
| 005c6e14 | off_5C6E14 | R | Text handle resource for list item display |
| 005c6e18 | unk_5C6E18 | R | Text handle resource for list item (label/description) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00486f30 | LinkedListInsertWithNodeAllocation | Inserts text handle node into UI list item's string list |
| 0048c070 | sub_48C070 | Base class constructor/initializer |

**Guard conditions:** No guards — always executes fully.
