## InitWithSentinelValues_004a8b10 — InitWithSentinelValues

**Summary:** Initializes struct vtable pointer from global off_5ACC08 and sets one DWORD pair at offsets 0x4/0x8 (0 = state/counter, -1 = handle/index). Part of UI control window initialization.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** UIControlWindowInitialization (004a70e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer from global off_5ACC08 |
| this | 0x4 | RW | 0 | state/counter field |
| this | 0x8 | RW | 18446744073709551615 | handle/index (-1 = invalid) |

**Written-by note (persistence):**
- this 0x0: once unconditional (vtable pointer)
- this 0x4: once unconditional (0)
- this 0x8: once unconditional (-1)

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005acc08 | off_5ACC08 | R | PlayerVehicleVTable [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guards. Always writes all 3 DWORD values unconditionally.
