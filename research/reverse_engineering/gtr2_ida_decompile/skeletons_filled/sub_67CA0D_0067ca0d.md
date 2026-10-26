## sub_67CA0D_0067ca0d — PNG row read-transformation pipeline

**Summary:** Applies the enabled PNG read transformations to the current row buffer in a fixed order (palette/bit expansion, filler, bit pack/unpack, shift, dither, swap/invert family), selected by the transformation-flag bytes at +0x60/+0x61. Aborts through the error helper when the row buffer is null or when dithering leaves rowbytes at zero.

**Called by:** sub_67AC9B (0067ac9b)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x5C | R | — | Dword parameter passed to the sub_67B9F4 transform |
| this | 0x60 | R | — | Transformation flags, low byte (bits 0x40/0x10/0x08/0x04/0x01 selected here) |
| this | 0x61 | R | — | Transformation flags, high byte (bits 0x80/0x20/0x10/0x04 selected here) |
| this | 0xDC | R | — | Row buffer pointer; null triggers the "NULL row buffer" error |
| this | 0xF4 | R | — | row_info rowbytes, validated after the dither step |
| this | 0xF8 | R | — | row_info color_type; == 3 selects the palette expand path |
| this | 0x104 | R | — | Palette pointer passed to the palette expand step |
| this | 0x10A | R | — | 16-bit transparency count / expand parameter |
| this | 0x116 | R | — | Gate byte for the high-byte 0x20 transform (== 3 skips it) |
| this | 0x11E | R | — | 16-bit parameter passed to the sub_67B9F4 transform |
| this | 0x12C | R | — | Dword parameter passed to sub_67BC29 |
| this | 0x138 | R | — | Pointer parameter passed to sub_67BC29 |
| this | 0x144 | R | — | Dword parameter passed to sub_67BC29 |
| this | 0x15C | R | — | Transparency array pointer (passed only when the count at +0x10A is nonzero) |
| this | 0x174 | R | — | Palette lookup pointer passed to the dither step |
| this | 0x178 | R | — | Dither lookup pointer passed to the dither step |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0073cbd8 | aPngDoDitherRet | R | Error message "png_do_dither returned rowbytes=0" reported via the error helper |
| 0073cbfc | aNullRowBuffer | R | Error message "NULL row buffer" reported via the error helper |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00679f05 | GuardedCallWithLongjmp [structural] | Reports a fatal error with the given message (longjmp-based error helper) |
| 0067b4ef | sub_67B4EF | Row transform gated by low-byte transformation bit 0x10 |
| 0067b522 | sub_67B522 | Row transform gated by low-byte transformation bit 0x01 |
| 0067b719 | BitPackingUnpacking [structural] | Bit pack/unpack row transform (low-byte bit 0x04) |
| 0067b82c | sub_67B82C | Row transform for low-byte bit 0x08, using a byte table inside the object |
| 0067b9aa | BitExpandDecompress [structural] | Bit expand row transform (high-byte bit 0x04) |
| 0067b9f4 | sub_67B9F4 | Row transform for high-byte bit 0x80, with the 16-bit +0x11E and dword +0x5C parameters |
| 0067bc29 | sub_67BC29 | Row transform for high-byte bit 0x20, with three stored parameters |
| 0067bf7b | sub_67BF7B | Palette expand step (color_type == 3) for high-byte bit 0x10: palette, transparency array, count |
| 0067c186 | BitmapDecompression [structural] | Non-palette expand step for high-byte bit 0x10 (transparency pointer when the count is nonzero, else null) |
| 0067c4df | sub_67C4DF | Dither row transform (low-byte bit 0x40); its rowbytes result is validated afterwards |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x61 | < | 0 | High transformation byte with bit 0x80 set (tested as signed char): selects the sub_67B9F4 transform |
| this | 0xF8 | == | 3 | row_info color_type palette: takes the sub_67BF7B palette expand path instead of sub_67C186 |
| this | 0x116 | != | 3 | High-byte 0x20 transform gate: value 3 skips the sub_67BC29 step |

**Guard interpretation:** Each transform step runs only when its bit is set in the transformation-flag bytes at +0x60/+0x61: low byte 0x40 (dither), 0x10, 0x08, 0x04, 0x01 and high byte 0x80, 0x20, 0x10, 0x04. BLOCKED: a null row buffer at +0xDC aborts via "NULL row buffer" before any transform; with color_type == 3 the palette expand (sub_67BF7B) replaces the generic expand; when +0x116 == 3 the high-byte 0x20 step is skipped; and if dithering leaves rowbytes (+0xF4) zero the "png_do_dither returned rowbytes=0" error aborts the row.

**String literals referenced (deterministic):**

- `NULL row buffer`
