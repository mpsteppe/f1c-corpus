## DecompressionDecode_00587260 — Decode/decompress data block with appended fields

**Summary:** Validates output buffer capacity via AddConstantWrapper, copies variable-length data block from queried buffer, then appends three struct fields (DWORD at 0x10, DWORD at 0x14, BYTE at 0x18). Returns total written size in `*a3`.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_585870 (00585870)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x10 | R | — | First trailing DWORD appended after data block |
| this | 0x14 | R | — | Second trailing DWORD appended after data block |
| this | 0x18 | R | — | Trailing BYTE appended after data block |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587250 | AddConstantWrapper | Returns size/cap value v4 used for capacity check against *a3 |
| 00587580 | BufferQueryReturnPtrSizeIfValid | Resolves buffer pointer/size for data block copy |

**Guard conditions:** `v4 > *a3` → output buffer too small, returns 0 immediately. Inner block guarded by `BufferQueryReturnPtrSizeIfValid` succeeding.
