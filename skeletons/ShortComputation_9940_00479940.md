## ShortComputation_9940_00479940 — Constructor with enable flag at 0xF0

**Summary:** Object constructor calling VtableSetWithInitCall with range [0.0, 1.0], setting vtable to off_5A55A0, and setting a byte flag at offset 0xF0 to 1 (enabled).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer; set to address of off_5A55A0 |
| this | 0xF0 | RW | 1 | boolean/enable flag; initialized to 1 (active) |

**Written-by note (persistence):**
- this 0x0: written once during construction; cannot be determined if external modification persists
- this 0xF0: written once during construction to 1; may be toggled externally

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005a55a0 | off_5A55A0 | R | vtable for this object type |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00466980 | VtableSetWithInitCall | initializes range fields with 0.0f and 1.0f |

**Guard conditions:** none — unconditional straight-line init
