## FloatValueConstructor_0047a550 — FloatValueObjectInit

**Summary:** Object initializer: calls InitVTableSet with float values 0.05 and 1.0, then overrides vtable pointer to off_5A61D8. Returns this.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Vtable pointer (set to off_5A61D8) |

**Written-by note (persistence):**
- this 0x0: Written once with vtable pointer; persists unless external code overrides

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005a61d8 | off_5A61D8 | R | Vtable pointer for this object type |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004668e0 | InitVTableSet | Initializes vtable reference and writes two float fields (0.05, 1.0) at offsets determined by arg order |

**Guard conditions:** None — unconditional.
