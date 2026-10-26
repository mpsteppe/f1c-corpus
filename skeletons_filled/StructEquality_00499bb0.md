## StructEquality_00499bb0 — StructFieldEqualityComparison

**Summary:** Compares two object instances by checking equality of six DWORD fields (offsets 0x00, 0x04, 0x08, 0x0C, 0x1C, 0x20) in order. Returns TRUE if all match, FALSE on first mismatch. Fields at offsets 0x10-0x18 and 0x24-0x30 are not compared.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ShortComputation_9bf0 (00499bf0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | compared field |
| this | 0x4 | R | — | compared field |
| this | 0x8 | R | — | compared field |
| this | 0xC | R | — | compared field |
| this | 0x1C | R | — | compared field |
| this | 0x20 | R | — | compared field |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — straight-line equality check chain with short-circuit AND. Returns FALSE immediately on first mismatched field.
