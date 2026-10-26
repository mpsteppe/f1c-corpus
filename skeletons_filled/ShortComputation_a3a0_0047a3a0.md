## ShortComputation_a3a0_0047a3a0 — ObjectInitWithVtableB

**Summary:** Object initializer: calls InitVTableSet (setting default float 1.0 at offset 0), overrides vtable pointer to off_5A6120, zeroes byte at offset 0x104. Returns this.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Vtable pointer (set to off_5A6120) |
| this | 0x104 | RW | 0 | Byte field zeroed on init |

**Written-by note (persistence):**
- this 0x0: Written once with vtable pointer; persists unless external code overrides
- this 0x104: Written once to 0; persists until explicitly modified

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005a6120 | off_5A6120 | R | Vtable pointer for this object type |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004668e0 | InitVTableSet | Initializes vtable reference and writes float 1.0 at offset 0 (vtable then overridden by direct assignment) |

**Guard conditions:** None — unconditional; all three operations always execute.
