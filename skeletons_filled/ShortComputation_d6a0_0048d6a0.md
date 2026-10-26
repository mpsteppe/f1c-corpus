## ShortComputation_d6a0_0048d6a0 — MenuItemVTableInit

**Summary:** Sets vtable to off_5AC280 (VTable_MenuItem_5AC280) and delegates to ConstructorWithVTableSet for the remainder of initialization. A minimal constructor stub.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ShortComputation_d680 (0048d680)

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

**Guard conditions:** None — unconditional.
