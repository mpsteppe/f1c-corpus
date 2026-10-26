## ConstructorWithRangeInitAndFlag_00479cd0 — Constructor with [20.0, 100.0] range and enable flag

**Summary:** Object constructor calling UIConstructorWithVTableParams with ~20.0f and ~100.0f, setting vtable to off_5A5CD0, and setting enable flag at offset 0xF0 to 1.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer; set to address of off_5A5CD0 |
| this | 0xF0 | RW | 1 | boolean/enable flag; initialized to 1 (active) |

**Written-by note (persistence):**
- this 0x0: written once during construction; cannot be determined if external modification persists
- this 0xF0: written once during construction to 1; may be toggled externally

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005a5cd0 | off_5A5CD0 | R | vtable for this object type |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0048d3a0 | UIConstructorWithVTableParams | initializes UI object fields with float range ~20.0f and ~100.0f |

**Guard conditions:** none — unconditional straight-line init
