// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005609DE
// Canonical corpus name: sub_5609DE
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_5609DE_005609de.c

void UnknownObject::ImageBlitTransparent24()
{
    // Blits a 24-bit RGB image with transparent-color support. A global stores the transparent color (a7 masked to 24 bits) and a global stores the scanline byte width (3 * a5). When the transparent color is 0xFFFFFF the fast path copies whole scanlines with qmemcpy; otherwise each scanline copies pixels individually, skipping any pixel equal to the transparent color. Source and destination rows advance by precomputed stride differences after each scanline.
    // ASSIGNMENT: Store the transparent color from the last argument masked to 24 bits: dword_5DD804 = a7 & 0xFFFFFF. [global:0x005DD804, source:raw]
    // ASSIGNMENT: Store the scanline byte width: dword_5DD814 = 3 * a5. [global:0x005DD814, source:raw]
    // CALCULATION: Compute per-row advance past the copied region for source (v17 = a2 - 3 * a5) and destination (v18 = a4 - 3 * a5). [source:raw]
    // GUARD: Branch on whether the transparent color (a7 & 0xFFFFFF) equals 0xFFFFFF: selects the bulk-copy path vs the per-pixel path. [global:0x005DD804, source:raw]
    // LOOP: Fast path: for each scanline, qmemcpy dword_5DD814 bytes from source to destination, then advance both pointers by the copied width plus the stored row advance. [global:0x005DD814, source:raw]
    // LOOP: Slow path: for each scanline, copy a5 pixels one at a time; advance source and destination by their row-advance values at the end of the scanline. [source:raw]
    // CALCULATION: Reconstruct one 24-bit pixel: read the low 16 bits from the word at source offset 0, shift, and read the third byte at source offset 2. [field:this:0x00000000, field:this:0x00000002, source:raw]
    // ASSIGNMENT: If the reconstructed pixel differs from the stored transparent color, write the pixel as a 32-bit value at the destination; advance the destination by 3 bytes per pixel. [global:0x005DD804, source:raw]
    // LOOP: Both paths iterate per scanline using a countdown on the row-count argument; loop continues while the countdown has not reached 1. [source:raw]

    // Conservative worker pseudocode:
    //   void ImageBlitTransparent24(char *src, int srcRowStride, char *dst, int dstRowStride, int pixelsPerRow, int rows, int color) {
    //     dword_5DD804 = color & 0xFFFFFF;
    //     dword_5DD814 = 3 * pixelsPerRow;
    //     int srcAdv = srcRowStride - dword_5DD814;
    //     int dstAdv = dstRowStride - dword_5DD814;
    //     if (dword_5DD804 == 0xFFFFFF) {
    //       do { qmemcpy(dst, src, dword_5DD814); src += dword_5DD814 + srcAdv; dst += dword_5DD814 + dstAdv; } while (rows-- > 1);
    //     } else {
    //       do {
    //         int p = pixelsPerRow;
    //         do {
    //           unsigned v = *(unsigned short *)src | (((unsigned char)src[2]) << 16);
    //           src += 3;
    //           if (v != dword_5DD804) *(unsigned *)dst = v;
    //           dst += 3;
    //         } while (--p > 1);
    //         src += srcAdv; dst += dstAdv;
    //       } while (rows-- > 1);
    //     }
    //   }
    // UNRESOLVED: Caller AudioPlaybackDispatcher (005401a0) is the only known caller; the exact source pixel layout and stride units are not evidenced beyond the 3-byte pixel reads.
    // UNRESOLVED: The extra high byte written by the 32-bit store in the per-pixel path may write one byte past the logical pixel; not evidenced here.
}
