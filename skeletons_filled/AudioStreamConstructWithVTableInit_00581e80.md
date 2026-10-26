## AudioStreamConstructWithVTableInit_00581e80 — Audio stream object constructor with vtable

**Summary:** Initializes audio stream object: sets vtable to off_5B8B3C via ConstructorVTableSetInit, zeros WORD at +0x12C and DWORD at +0x130, calls SmallStructFieldInit for additional field zeroing/init. Returns this pointer.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Vtable pointer; set to off_5B8B3C (audio stream vtable) |
| this | 0x12C | RW | 0 | WORD-sized field (300), zeroed during init — possibly stream state or flags |
| this | 0x130 | RW | 0 | DWORD-sized field (304), zeroed during init — possibly buffer size or timer |

**Written-by note (persistence):**
- this 0x0: Set to vtable once. Persists for lifetime of object.
- this 0x12C: Zeroed once. Persists until modified by stream operations.
- this 0x130: Zeroed once. Persists until modified by stream operations.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059cbc8 | SEH_581E80 | R | Exception handler registration for this function |
| 005b8b3c | off_5B8B3C | R | VTable_5B8B3C — audio stream vtable pointer assigned to this+0x0 |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0057a160 | ConstructorVTableSetInit | Generic constructor prologue — initialize base fields |
| 0057a1e0 | SmallStructFieldInit | Initialize additional small struct fields to zero/default |

**Guard conditions:** None — unconditional initialization.
