## BufferQueryReturnPtrSizeIfValid_00587580 — Query buffer pointer and size if valid

**Summary:** Returns buffer pointer (offset 0x0) and stored size (offset 0x8) via output parameters if capacity (offset 0x4) is > 0. Otherwise zeroes outputs and returns 0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** StructuredMemoryCopyWithHeaderPrepend (0057d5d0), BoundedMemoryCopyWithSizeValidation (00586a10), sub_587120 (00587120), DecompressionDecode (00587260), StructInitParse (00587490)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | Pointer to buffer data; returned via *a2 on success |
| this | 0x4 | R | — | Buffer capacity/size validity flag; must be > 0 |
| this | 0x8 | R | — | Stored data size; returned via *a3 on success |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x4 | > | 0 | Capacity/validity field: PASSES if > 0 (buffer has data) |

**Guard interpretation:** If `this[1]` (offset 0x4) > 0, buffer is valid — outputs pointer and stored size, returns 1. BLOCKED if ≤ 0 — zeroes outputs, returns 0.
