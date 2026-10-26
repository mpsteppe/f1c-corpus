## UIComponentInit_00479730 — UIComponentInit

**Summary:** UI component constructor: calls VtableSetWithInitCall with default float (0.2 = 1045220557), sets vtable to off_5A4DB8.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | off_5A4DB8 | vtable pointer for UI component type |

**Written-by note (persistence):**
- this 0x0: once per call, set to off_5A4DB8 (vtable init, overrides VtableSetWithInitCall)

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005a4db8 | off_5A4DB8 | R | vtable pointer assigned to UI component |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00466980 | VtableSetWithInitCall | base UI component constructor with init params (0, 0.2f) |

**Guard conditions:** none (no branches — unconditional initialization)
