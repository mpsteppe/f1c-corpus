## StructInitWithDefaultScale_00551a30 — StructInitZeroWithUnitScale

**Summary:** Zero-initializes struct via global helper, zeros two leading dword fields, and sets the fourth field (scale) to 1.0f.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_546450 (00546450), ObjectCreationWithRollbackOnFailure (00551f10)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 0 | First dword field (vtable/pointer — zeroed) |
| this | 0x4 | RW | 0 | Second dword field (zeroed) |
| this | 0x10 | RW | 1065353216 → 1.0f | Scale factor initialized to 1.0 |

**Written-by note (persistence):**
- this 0x0: Written unconditionally to 0; external poke overwritten on init
- this 0x4: Written unconditionally to 0; external poke overwritten on init
- this 0x10: Written unconditionally to 1.0f; external poke overwritten on init

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0053c2a0 | GlobalZeroInit_c2a0 | Zero-initialize entire struct memory |

**Guard conditions:** none — always executes fully, no branches.
