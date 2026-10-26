// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005608F6
// Canonical corpus name: sub_5608F6
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_5608F6_005608f6.c

void UnknownObject::ImageBlitTransparent16()
{
    // 16-bit image blit with transparent-color support. Stores the transparent color a7 into the global dword_5DD804, computes per-row source/destination strides from the 16-bit pixel width a5, then dispatches on the guard (a7 != 0xFFFF || (2*a5 & 7) != 0): the per-pixel path copies each word from the source to the destination except pixels equal to the transparent color, while the aligned-0xFFFF fast path copies 64-bit MMX chunks (2*a5 >> 3 QWORDs per row) plus a byte tail, row by row for a6 rows.
    // ASSIGNMENT: Store the transparent color argument a7 into the global transparent-color register dword_5DD804. [global:0x005DD804, source:raw]
    // CALCULATION: Compute byte width v10 = 2 * a5 and the per-row source/destination strides v17 = a2 - v10 and v18 = a4 - v10. [source:raw]
    // GUARD: Dispatch on (a7 != 0xFFFF || (v10 & 7) != 0): take the per-pixel transparent-copy path, otherwise take the aligned 64-bit fast path. [source:raw]
    // LOOP: Per-pixel path: nested do-while loops over a5 columns per row and a6 rows. [source:raw]
    // ASSIGNMENT: Per-pixel copy: read the next 16-bit pixel from the source pointer (this field 0x0, the source pixel data) and write it to the destination only when it differs from dword_5DD804, i.e. transparent pixels are skipped; advance both pointers. [field:this:0x00000000, global:0x005DD804, source:raw]
    // CALCULATION: Advance source/destination pointers to the next row by v17/v18 at the end of each row in the per-pixel path. [source:raw]
    // LOOP: Fast path: 64-bit MMX copy loop, v10 >> 3 QWORDs per row, over a6 rows. [source:raw]
    // ASSIGNMENT: Fast path tail: qmemcpy the remaining (v10 & 7) bytes per row when the width is not 8-byte aligned, and advance both pointers by that remainder. [source:raw]
    // CALCULATION: Advance source/destination pointers by v17/v18 between rows in the fast path. [source:raw]
    // RETURN: Return void; _m_empty() performs MMX-state cleanup before returning. [source:raw]

    // Conservative worker pseudocode:
    //   void ImageBlitTransparent16(_WORD *src, int srcRowStride, _WORD *dst, int dstRowStride, int widthPixels, int heightRows, unsigned short transparent) {
    //     dword_5DD804 = transparent;
    //     int rowBytes = 2 * widthPixels;
    //     int srcRowStep = srcRowStride - rowBytes;
    //     int dstRowStep = dstRowStride - rowBytes;
    //     if (transparent != 0xFFFF || (rowBytes & 7) != 0) {
    //       for (int y = heightRows; y != 0; --y) {
    //         for (int x = widthPixels; x != 0; --x) {
    //           _WORD p = *src++;
    //           if (p != dword_5DD804) *dst = p;
    //           dst++;
    //         }
    //         src = (_WORD *)((char *)src + srcRowStep);
    //         dst = (_WORD *)((char *)dst + dstRowStep);
    //       }
    //     } else {
    //       for (int y = heightRows; y != 0; --y) {
    //         int n = rowBytes >> 3;
    //         do { *(__int64 *)dst = *(__int64 *)src; src += 4; dst += 4; } while (--n);
    //         if ((rowBytes & 7) != 0) { memcpy(dst, src, rowBytes & 7); src = (_WORD *)((char *)src + (rowBytes & 7)); dst = (_WORD *)((char *)dst + (rowBytes & 7)); }
    //         src = (_WORD *)((char *)src + srcRowStep);
    //         dst = (_WORD *)((char *)dst + dstRowStep);
    //       }
    //     }
    //     _m_empty();
    //   }
    // UNRESOLVED: Semantic role of dword_5DD804 beyond the transparent-color comparison is unknown; the global persists across calls.
    // UNRESOLVED: The 0xFFFF + 8-byte-aligned case assumes the source has no transparent pixels and performs a raw 64-bit copy; whether callers guarantee that is caller-dependent.
    // UNRESOLVED: Pixel format (RGB565 or similar) and the meaning of the row strides a2/a4 depend on the caller's image layout.
}
