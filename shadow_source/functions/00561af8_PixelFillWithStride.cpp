// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00561AF8
// Canonical corpus name: PixelFillWithStride
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PixelFillWithStride_00561af8.c

void UnknownObject::PixelFillWithStride()
{
    // Writes a constant dword value a3 to a2 pixels starting at byte address 4 * a1 + a5, advancing by stride 4 * a4 bytes after each write. Returns a3. Used by DrawRectangle (0x00553D70) to paint a scanline or row of a bitmap.
    // ASSIGNMENT: Initialize result to a3; this value is returned unchanged after the loop. [source:raw]
    // CALCULATION: Compute the starting pixel pointer v5 as a1 + a1 + a1 + a1 + a5, i.e. 4 * a1 + a5. [source:raw]
    // CALCULATION: Compute the per-iteration byte stride v8 as 4 * a4. [source:raw]
    // LOOP: do-while loop that runs a2 times using a countdown counter; the body always executes at least once because the first write is unconditional. [source:raw]
    // ASSIGNMENT: Write the pixel value: *v5 = a3. [source:raw]
    // CALCULATION: Advance the pixel pointer by the stride: v5 += v8 (4 * a4 bytes). [source:raw]
    // RETURN: Return a3 (the fill value) as the function result. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_561AF8(int a1, int a2, int a3, int a4, int a5) {
    //     _DWORD *p = (_DWORD *)(4 * a1 + a5);
    //     int stride = 4 * a4;
    //     int result = a3;
    //     do { *p = a3; p = (_DWORD *)((char *)p + stride); --a2; } while (a2);
    //     return result;
    //   }
    // UNRESOLVED: Interpretation of a1 and a5 as (pixel row, base address) components is caller-supplied and unverified.
    // UNRESOLVED: Whether the dword is a packed pixel (RGBA) or another 32-bit payload is not established.
    // UNRESOLVED: a4 as a row/plane stride is DERIVED from the caller DrawRectangle context, not proven.
}
