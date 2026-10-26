## VTableSetterWithFloatParams_004798e0 — Constructor with range and off_5A5430 vtable

**Summary:** Object constructor calling VtableSetWithInitCall with -1.0f/1.0f range, then setting vtable to off_5A5430.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer; set to address of off_5A5430 |

**Written-by note (persistence):**
- this 0x0: written once during construction; cannot be determined if external modification persists

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005a5430 | off_5A5430 | R | vtable for this object type |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00466980 | VtableSetWithInitCall | initializes range fields with -1.0f and 1.0f |

**Guard conditions:** none — unconditional straight-line init
