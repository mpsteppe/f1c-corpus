## FloatConstructorWithRangeSetup_00479850 — Constructor with float range [-1.0, 1.0]

**Summary:** Object constructor that calls VtableSetWithInitCall with float values -1.0f and 1.0f (encoded as int32), then sets vtable to off_5A5208.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer; set to address of off_5A5208 |

**Written-by note (persistence):**
- this 0x0: written once during construction; cannot be determined if external modification persists

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005a5208 | off_5A5208 | R | vtable for this float-range object type |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00466980 | VtableSetWithInitCall | initializes range fields with -1.0f (0xBF800000) and 1.0f (0x3F800000) |

**Guard conditions:** none — unconditional straight-line init
