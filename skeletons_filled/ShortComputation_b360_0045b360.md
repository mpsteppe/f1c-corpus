## ShortComputation_b360_0045b360 — RenderUIObjectInit

**Summary:** Initializes a 3D UI/render object with 8 viewport sub-structures. Sets vtable to RenderUIObject table (off_59F080), initializes sub-object at offset 4, configures 8 viewport blocks (92 bytes each) with default values (-1, -1.0f, 3), calls per-index field resetter for each viewport, and clears remaining state fields (0x31C, 0x320, 0x324, 0x328).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ShortComputation_bb40 (0045bb40)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer, set to RenderUIObject vtable (off_59F080) |
| this | 0x2C | RW | 0 | sub-object field: cleared to 0 during init |
| this | 0x30 | RW | 18446744073709551615 | sub-object field: set to -1 (0xFFFFFFFF) |
| this | 0x3C | RW | 0 | viewport[0] block start: first byte cleared to 0 |
| this | 0x8C | RW | 18446744073709551615 | viewport[0] field at offset 80: set to -1 |
| this | 0x90 | RW | 18446744072627421184 → -1.0f | viewport[0] field at offset 84: set to -1.0f |
| this | 0x94 | RW | 3 | viewport[0] field at offset 88: set to 3 |
| this | 0x31C | RW | 0 | state field: cleared to 0 |
| this | 0x320 | RW | 0 | byte field at offset 800: cleared to 0 |
| this | 0x324 | RW | 0 | state field: cleared to 0 |
| this | 0x328 | RW | 0 | state field: cleared to 0 |

**Written-by note (persistence):**
- this 0x0: written once to vtable pointer. Survives until externally modified.
- this 0x2C: written once to 0. Survives until externally modified.
- this 0x30: written once to -1. Survives until externally modified.
- this 0x3C: written once to 0 (first byte of viewport[0]). Survives until externally modified.
- this 0x8C: written once to -1. Survives until externally modified.
- this 0x90: written once to -1.0f. Survives until externally modified.
- this 0x94: written once to 3. Survives until externally modified.
- this 0x31C: written once to 0. Survives until externally modified.
- this 0x320: written once to 0. Survives until externally modified.
- this 0x324: written once to 0. Survives until externally modified.
- this 0x328: written once to 0. Survives until externally modified.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059f080 | off_59F080 | R | Vtable_RenderUIObject [DERIVED] — vtable assigned to this object |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0045b430 | PerIndexStructFieldResetter | reset per-viewport index-specific fields (called once per viewport, i=0..7) |
| 004dcb70 | ShortComputation_cb70 | initialize sub-object at this+4 (viewport manager) |
| 004dcf80 | sub_4DCF80 | additional initialization for sub-object at this+4 |

**Guard conditions:** None — unconditional initialization of all fields and structures. Loop counts are hardcoded (8 iterations).
