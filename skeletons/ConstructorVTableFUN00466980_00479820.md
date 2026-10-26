## ConstructorVTableFUN00466980_00479820 — Constructor setting vtable pointer

**Summary:** Sets up an object instance: calls VtableSetWithInitCall with range parameters, then assigns vtable pointer off_5A5150 to the object's first field.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer; set to address of off_5A5150 |

**Written-by note (persistence):**
- this 0x0: written once during construction; cannot be determined if external modification persists

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005a5150 | off_5A5150 | R | vtable (virtual method table) for this object type |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00466980 | VtableSetWithInitCall | initializes vtable-related fields with range params (-1073741824, 0x40000000) |

**Guard conditions:** none — unconditional straight-line init
