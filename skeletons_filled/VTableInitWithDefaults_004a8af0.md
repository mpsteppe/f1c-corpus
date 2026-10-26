## VTableInitWithDefaults_004a8af0 — VTableInitWithDefaults

**Summary:** Initializes struct vtable pointer from global off_5ACBF0 and fills 6 DWORD fields with alternating 0/-1 default pairs (offsets 0x4-0x18). Three (state/counter=0, handle/index=-1) pairs. Part of UI control window initialization.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** UIControlWindowInitialization (004a70e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer from global off_5ACBF0 |
| this | 0x4 | RW | 0 | first state/counter field |
| this | 0x8 | RW | 18446744073709551615 | first handle/index (-1 = invalid) |
| this | 0xC | RW | 0 | second state/counter field |
| this | 0x10 | RW | 18446744073709551615 | second handle/index (-1 = invalid) |
| this | 0x14 | RW | 0 | third state/counter field |
| this | 0x18 | RW | 18446744073709551615 | third handle/index (-1 = invalid) |

**Written-by note (persistence):**
- this 0x0: once unconditional (vtable pointer)
- this 0x4: once unconditional (0)
- this 0x8: once unconditional (-1)
- this 0xC: once unconditional (0)
- this 0x10: once unconditional (-1)
- this 0x14: once unconditional (0)
- this 0x18: once unconditional (-1)

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005acbf0 | off_5ACBF0 | R | VTable_VideoPlayback_5ACBF0 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guards. Always writes all 7 DWORD values unconditionally.
