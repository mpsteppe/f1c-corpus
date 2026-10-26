## UIComponentInit2_00479c80 — Constructor with [0.0, 1.0] range via InitVTableSet

**Summary:** Object constructor calling InitVTableSet with range 0.0f and 1.0f, then setting vtable to off_5A5C18.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer; set to address of off_5A5C18 |

**Written-by note (persistence):**
- this 0x0: written once during construction; cannot be determined if external modification persists

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005a5c18 | off_5A5C18 | R | vtable for this object type |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004668e0 | InitVTableSet | initializes range fields with 0.0f and 1.0f |

**Guard conditions:** none — unconditional straight-line init
