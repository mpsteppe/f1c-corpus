## FloatRangeConstructor_00479a40 — Constructor with [-1.0, 1.0] range and zeroed dword at 0x100

**Summary:** Object constructor calling VtableSetWithInitCall with range -1.0f and 1.0f, setting vtable to off_5A5938, and zeroing a dword field at offset 0x100.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer; set to address of off_5A5938 |
| this | 0x100 | RW | 0 | counter/accumulator/state field; initialized to 0 |

**Written-by note (persistence):**
- this 0x0: written once during construction; cannot be determined if external modification persists
- this 0x100: written once during construction to 0; may be modified externally

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005a5938 | off_5A5938 | R | vtable for this object type |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00466980 | VtableSetWithInitCall | initializes range fields with -1.0f and 1.0f |

**Guard conditions:** none — unconditional straight-line init
