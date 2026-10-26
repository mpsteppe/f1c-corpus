// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0051C6E1
// Canonical corpus name: sub_51C6E1
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_51C6E1_0051c6e1.c

void UnknownObject::PixelBlitWithColorLookupTable()
{
    // Per-row pixel blit with four color lookup tables. For each of a5 output rows it reads four source pointers from an a2 array at byte offset 4*a3 + 4*row, then for each pixel reads three channel bytes plus an alpha byte, indexes the four tables by those bytes, and writes four output bytes (three transformed color channels plus a copied source byte). Each output channel is computed as base + 255 minus a table value minus a luma byte; the middle channel averages two tables with a >> 16 blend. Rows are skipped when row count is non-positive and per-row pixel work is skipped when row width is zero.
    // ASSIGNMENT: Load the LUT sub-object pointer v5 from this->+0x1A0 (a1[104]); its entries v5[2..5] hold the four color lookup tables. [field:this:0x000001A0, source:raw]
    // ASSIGNMENT: Read the row width from this->+0x5C (a1[23]) and the additive base from this->+0x11C (a1[71]). [field:this:0x0000005C, field:this:0x0000011C, source:raw]
    // ASSIGNMENT: Read the four lookup-table pointers from v5[2] (+0x1A8), v5[3] (+0x1AC), v5[4] (+0x1B0) and v5[5] (+0x1B4). [field:this:0x000001A8, field:this:0x000001AC, field:this:0x000001B0, field:this:0x000001B4, source:raw]
    // GUARD: When a5 - 1 < 0 the whole row loop is skipped and the function returns early. [source:raw]
    // LOOP: Outer do-while over a5 rows; per row the byte offset v9 = 4*a3 + 4*row selects the row's pointers in the a2 array. [source:raw]
    // ASSIGNMENT: Per row, load the four source pointers a2[0..3] at byte offset v9 and take the next destination row from the a4++ pointer array. [source:raw]
    // GUARD: Per row, pixel processing is skipped entirely when the row width (a1[23]) is zero. [field:this:0x0000005C, source:raw]
    // CALCULATION: Derive per-channel source offsets v13/v14/v25 as each loaded source pointer value minus the base source pointer v11. [source:raw]
    // LOOP: Inner per-pixel while loop over rowWidth pixels, advancing source and destination four bytes per pixel. [field:this:0x0000005C, source:raw]
    // ASSIGNMENT: Per pixel, read three channel bytes v11[v13], v11[v14], *v11 and the alpha byte v11[v25] from the source row. [source:raw]
    // CALCULATION: Compute each output channel as base + 255 - LUT[index] - luma byte; the middle channel blends two tables and shifts the sum >> 16. [field:this:0x0000011C, field:this:0x000001A8, field:this:0x000001AC, field:this:0x000001B0, field:this:0x000001B4, source:raw]
    // ASSIGNMENT: Write four output bytes per pixel: three transformed color channels plus the copied source alpha byte. [source:raw]
    // RETURN: Return the final destination pointer (a5 - 1 when no row was processed). [source:raw]

    // Conservative worker pseudocode:
    //   _BYTE* PixelBlitWithColorLookupTable(_DWORD* obj, _DWORD* srcArr, int planeBase, _BYTE** dstArr, int rowCount) {
    //     _DWORD* lut = (_DWORD*)obj[104];
    //     int rowWidth = obj[23];
    //     int base = obj[71];
    //     int t0 = lut[2], t1 = lut[3], t2 = lut[4], t3 = lut[5];
    //     _BYTE* result = (_BYTE*)(rowCount - 1);
    //     if (rowCount - 1 >= 0) {
    //       int off = 4 * planeBase;
    //       int n = rowCount;
    //       do {
    //         int p0 = *(int*)(off + srcArr[0]);
    //         unsigned char* src = *(unsigned char**)(off + srcArr[1]);
    //         int p2 = *(int*)(off + srcArr[2]);
    //         int p3 = *(int*)(off + srcArr[3]);
    //         _BYTE* dst = *dstArr++;
    //         off += 4;
    //         if (rowWidth) {
    //           int d0 = p0 - (int)src;
    //           int d1 = p2 - (int)src;
    //           int d2 = p3 - (int)src;
    //           int cnt = rowWidth;
    //           while (1) {
    //             int y = src[d0];
    //             int i2 = 4 * src[d1];
    //             int i3 = 4 * *src;
    //             *dst = base - *(int*)(i2 + t0) - y + 255;
    //             dst[1] = base - ((*(int*)(i2 + t2) + *(int*)(i3 + t3)) >> 16) - y + 255;
    //             dst[2] = base - *(int*)(i3 + t1) - y + 255;
    //             dst[3] = (src++)[d2];
    //             dst += 4;
    //             if (!--cnt) break;
    //             d0 = p0 - (int)src;
    //             d1 = p2 - (int)src;
    //           }
    //         }
    //       } while (--n);
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Exact color-space meaning of the four lookup tables and the base + 255 - table arithmetic; the pattern resembles a YUV-style inverse conversion but is not runtime-confirmed.
    // UNRESOLVED: Identity of object a1 and caller; no static callers or frame-path evidence exist.
    // UNRESOLVED: Meaning of the copied alpha byte v11[v25] and the stride it encodes.
    // UNRESOLVED: Semantic role of a3 (plane/row base) and the four-slot layout of the a2 source-pointer array.
}
