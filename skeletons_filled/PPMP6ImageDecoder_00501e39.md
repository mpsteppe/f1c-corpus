## PPMP6ImageDecoder_00501e39 — PPMP6ImageDecoder

**Summary:** Decodes PPM P3 (ASCII) or P6 (binary) image data into 32-bit BGRA pixel buffer. Parses header (magic, width, height, max value), allocates output buffer, and converts RGB samples with max-value normalization to 4-byte BGRA pixels.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DirectXSurfaceFormatNegotiation (00502a15)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 22 | Format ID (22 = RGB-to-BGRA conversion) |
| this | 0x4 | RW | — | Output pixel buffer (allocated for decoded image) |
| this | 0xC | RW | — | Width in pixels (parsed from PPM header) |
| this | 0x10 | RW | — | Height in pixels (parsed from PPM header) |
| this | 0x14 | RW | 1 | Direction flag (always 1) |
| this | 0x30 | RW | — | Row stride in bytes (4 * width) |
| this | 0x34 | RW | 0 | Zero-initialized flag field |
| this | 0x38 | RW | 1 | Pixel ownership flag (1 = owns allocated buffer) |

**Written-by note (persistence):**
- this 0x0: Written once per call to format 22
- this 0x4: Written once per call to allocated pixel buffer
- this 0xC: Written once per call to parsed width
- this 0x10: Written once per call to parsed height
- this 0x14: Written once per call to constant 1
- this 0x30: Written once per call to computed stride
- this 0x34: Written once per call to constant 0
- this 0x38: Written once per call to constant 1

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587c03 | OperatorNewNhMallocWrapper | Allocate pixel output buffer |
| 00589b9e | sub_589B9E | Check if character is digit (0-9) |
| 00589bf3 | sub_589BF3 | Check if character is whitespace (space, tab, newline) |

**Guard conditions:** Input buffer size < 2 → return error. First byte != 'P' (80) → return error. Second byte != '3' (51 = P3 ASCII) and != '6' (54 = P6 binary) → return error. Whitespace skipping loop. If max value (v16) > 255 → return error. If pixel data incomplete → return error (0x80004005).
