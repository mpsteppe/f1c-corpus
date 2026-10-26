## F_4FieldPropagation_004e4590 — FourFieldPropagate

**Summary:** Propagates integer value a2 across four fields at offsets 0x0, 0x8, 0x6E4, and 0x32C0. Synchronization/initialization of sub-structures within the physics tire system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** LargeStructFieldSetterWithStoredReference (00424040)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | postProcessInput [CONFIRMED] |
| this | 0x8 | RW | — | matching field in sub-structure at offset 0x8 |
| this | 0x6E4 | RW | — | matching field in sub-structure at offset 0x6E4 |
| this | 0x32C0 | RW | — | matching field in sub-structure at offset 0x32C0 |

**Written-by note (persistence):**
- this 0x0: overwritten each call
- this 0x8: overwritten each call
- this 0x6E4: overwritten each call
- this 0x32C0: overwritten each call

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — always writes all four fields.
