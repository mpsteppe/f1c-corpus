## MultiShortStructWriter_00491300 — RectOrAABBInitializer

**Summary:** Initializes a struct with 4 shorts (AABB/rect coordinates) at offsets 0x0-0x6 and zeros a DWORD at offset 0xC. Simple struct constructor.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** RenderDispatchWithIteration (004993d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Stores a2 (first short coordinate, e.g. x1) |
| this | 0x2 | RW | — | Stores a3 (second short coordinate, e.g. y1) |
| this | 0x4 | RW | — | Stores a4 (third short coordinate, e.g. x2) |
| this | 0x6 | RW | — | Stores a5 (fourth short coordinate, e.g. y2) |
| this | 0xC | RW | 0 | DWORD field zeroed at init |

**Written-by note (persistence):**
- this 0x0: written once at init with a2; survives until explicitly changed
- this 0x2: written once at init with a3; survives until explicitly changed
- this 0x4: written once at init with a4; survives until explicitly changed
- this 0x6: written once at init with a5; survives until explicitly changed
- this 0xC: written once to 0 at init; survives until explicitly changed

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditionally writes all 4 shorts and zeros offset 0xC.
