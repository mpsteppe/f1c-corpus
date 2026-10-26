## StructInitializationWithVTable_0057aec0 — DynamicsSolverObjectInit

**Summary:** Initializes a dynamics solver object struct: stores vtable pointer (DynamicsSolverObj_VTable) at offset 0, zeroes byte at offset 4 and 8 DWORDs at offsets 8 through 0x24.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer, set to off_5B8A1C (DynamicsSolverObj_VTable) |
| this | 0x4 | RW | 0 | byte field, zeroed |
| this | 0x8 | RW | 0 | DWORD field, zeroed |
| this | 0xC | RW | 0 | DWORD field, zeroed |
| this | 0x10 | RW | 0 | DWORD field, zeroed |
| this | 0x14 | RW | 0 | DWORD field, zeroed |
| this | 0x18 | RW | 0 | DWORD field, zeroed |
| this | 0x1C | RW | 0 | DWORD field, zeroed |
| this | 0x20 | RW | 0 | DWORD field, zeroed |
| this | 0x24 | RW | 0 | DWORD field, zeroed |

**Written-by note (persistence):**
- this 0x0: written once per call (vtable ptr); survives
- this 0x4: written once per call (0); survives
- this 0x8: written once per call (0); survives
- this 0xC: written once per call (0); survives
- this 0x10: written once per call (0); survives
- this 0x14: written once per call (0); survives
- this 0x18: written once per call (0); survives
- this 0x1C: written once per call (0); survives
- this 0x20: written once per call (0); survives
- this 0x24: written once per call (0); survives

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005b8a1c | off_5B8A1C | R | DynamicsSolverObj_VTable [DERIVED] — vtable pointer stored at offset 0 |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none — unconditional initialization

