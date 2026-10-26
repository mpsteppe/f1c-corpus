## DDSTextureFormatValidationDecoding_00500fca — DDSTextureFormatDecode

**Summary:** Validates DDS header and pixel format, maps DDS pixel formats to internal format IDs, allocates output buffer, and decodes pixel data to 32-bit BGRA. Handles palette expansion (8-bit indexed), RLE decompression (type 2), and uncompressed formats (1/4/8/16/24/32-bit).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** BMPHeaderValidation (005029e5), DirectXSurfaceFormatNegotiation (00502a15)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Decoded format ID (internal enum, e.g. 20/21/22/23/24/25/26/29/30/31/34/41/51) |
| this | 0x4 | RW | — | Output pixel data buffer pointer (allocated or assigned from DDS data) |
| this | 0x8 | RW | — | Palette buffer pointer (allocated for 8-bit indexed formats) |
| this | 0xC | RW | — | Width in pixels |
| this | 0x10 | RW | — | Height in pixels |
| this | 0x14 | RW | 1 | Flag (1 = top-down image orientation) |
| this | 0x30 | RW | — | Row stride in bytes |
| this | 0x34 | RW | 0 | Zero-initialized flag/field |
| this | 0x38 | RW | 1 | Pixel data ownership flag (1=owns buffer, 0=external pointer to DDS data) |
| this | 0x3C | RW | 1 | Palette expanded flag (1=palette data processed) |
| this | 0x40 | R | — | Palette format request flag (input from caller: non-zero requests palette expansion for format 41) |

**Written-by note (persistence):**
- this 0x0: Written once per call to decoded format ID
- this 0x4: Written once per call to allocated/assigned pixel buffer
- this 0x8: Written once per call to allocated palette buffer (if indexed format)
- this 0xC: Written once per call to decoded width
- this 0x10: Written once per call to decoded height
- this 0x14: Written once per call to constant 1 (direction flag)
- this 0x30: Written once per call to computed row stride
- this 0x34: Written once per call to constant 0
- this 0x38: Written once per call to ownership flag (0 or 1)
- this 0x3C: Written once per call to constant 1

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587c03 | OperatorNewNhMallocWrapper | Allocate heap memory for pixel output buffer and palette |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x40 | == | 0 | Input palette flag: non-zero enables palette expansion for format 41 |

**Guard interpretation:** DDS header size < 0x28 → return error. Structure size < 0x28 → return error. Bits per pixel not in {1,4,8,16,24,32} for uncompressed formats → return error. Channel bitmask mismatches → return error. If this+0x40 != 0 AND format == 41 (indexed), allocate/expand palette. Otherwise palette path skipped.
