## ConstructorDualSubInit_0048d660 — MenuItemConstructor

**Summary:** Constructs a menu item by calling ConstructorInitVTable with params (1, -1), setting vtable to VTable_MenuItem_5AC280, and calling SimpleSetter_8bc0 with value 2.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_493FC0 (00493fc0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Vtable pointer set to off_5AC280 |

**Written-by note (persistence):**
- this 0x0: set every call; survives external poke (vtable init)

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ac280 | off_5AC280 | R | VTable_MenuItem_5AC280 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00488b00 | ConstructorInitVTable | Base initialization with type/depth params |
| 00488bc0 | SimpleSetter_8bc0 | Setter for a configuration field |

**Guard conditions:** None — unconditional constructor.
