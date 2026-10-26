## F_5LoopInitCall_004a48c0 — FiveSubStructInit

**Summary:** Initializes 5 consecutive sub-structures (each 0x40 bytes, at offsets 0x18, 0x58, 0x98, 0xD8, 0x118) via StructInitializer, zeros 3 DWORD fields at offsets 0xC-0x14, then calls UIComponentCleanup. Part of physics tire system construction.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** PhysicsTireSystemConstructor (004e4500)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | RW | 0 | DWORD counter/pointer, zeroed |
| this | 0x10 | RW | 0 | DWORD counter/pointer, zeroed |
| this | 0x14 | RW | 0 | DWORD counter/pointer, zeroed |

**Written-by note (persistence):**
- this 0xC: once unconditional (0)
- this 0x10: once unconditional (0)
- this 0x14: once unconditional (0)

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0042e1c0 | StructInitializer | initializes each 0x40-byte sub-struct in the 5-element array |
| 004a4db0 | UIComponentCleanup | performs UI component resource cleanup after initialization |

**Guard conditions:** No guards. Always runs 5-iteration init loop, zeros 3 fields, then calls UIComponentCleanup.
