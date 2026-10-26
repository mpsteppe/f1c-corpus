## ShortConstructor_004a8b30 — UIWidgetConstructor

**Summary:** Initializes struct vtable pointer from global off_5ACBFC and sets one DWORD pair at offsets 0x4/0x8 (counter=0, handle=-1). UI widget base constructor called from UIControlWindowInitialization.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** UIControlWindowInitialization (004a70e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer from global off_5ACBFC |
| this | 0x4 | RW | 0 | state/counter field |
| this | 0x8 | RW | 18446744073709551615 | handle/index (-1 = invalid) |

**Written-by note (persistence):**
- this 0x0: once unconditional (vtable pointer)
- this 0x4: once unconditional (0)
- this 0x8: once unconditional (-1)

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005acbfc | off_5ACBFC | R | UIWidgetVTableSlot [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guards. Always writes all 3 DWORD values unconditionally.
