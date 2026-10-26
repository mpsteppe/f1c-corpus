// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005604C0
// Canonical corpus name: PixelBufferBlitWithShortToIntConversion
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PixelBufferBlitWithShortToIntConversion_005604c0.c

void UnknownObject::PixelBufferBlitWithShortToIntConversion()
{
    // Pixel blit that copies a rectangular region from a 16-bit source pixel buffer to a 32-bit destination buffer, expanding each 16-bit pixel into a 32-bit word by duplicating it into the low and high halves. Rows of a9 source words are processed; a pixel equal to the reference color a11 is skipped (color-key / transparency). Per-source-word dest stride is doubled (a9 *= 2) because each word becomes two bytes written as one dword pair. Address arithmetic is built from flat base/stride/count parameters rather than surface structs, so the exact buffer layouts are not evidenced.
    // ASSIGNMENT: Store the reference color a11 into v17; it is compared against each source pixel to decide whether to write. [source:raw, function:0x005604C0]
    // ASSIGNMENT: Double the source row word-count a9 (a9 *= 2); used both as the inner-loop counter and in dest pointer stepping because each source word expands to a 32-bit dword. [source:raw]
    // CALCULATION: Compute the source row start as a word pointer: v11 = (a1 + 2*a2 + a3*a4), mixing a base pointer a1, a byte stride a2, and row index a3 over a4 columns. [source:raw]
    // CALCULATION: Compute the destination row start as a dword pointer: v12 = 2*a6 + a7*a8, then v13 = a5 + v12. [source:raw]
    // ASSIGNMENT: Seed the inner pixel counter v14 = a9 and precompute the source row-advance correction v18 = a4 - a9. [source:raw]
    // ASSIGNMENT: Capture the prior dest row stride v15 = _InterlockedExchange(&a8, 2*(a8 - a9)): a8 is updated to the per-row byte advance and its old value (the second-write offset) is kept in v15. The exchange on a stack parameter is almost certainly a decompiler artifact of a plain assignment. [source:raw, abi:lead]
    // LOOP: Nested loop: inner loop writes a9 source words per row; on row end the outer loop advances both pointers and continues while a10 rows remain (break when a10 <= 1 after the decrement). [source:raw]
    // GUARD: Skip the pixel when it equals the reference color: write only if v17 != *v11 (color-key / transparency test). [source:raw]
    // ASSIGNMENT: Expand the 16-bit pixel to 32 bits by duplicating it into the low and high words of v12, then write two dwords: *v13 = v12 and *(v13 + v15) = v12. [source:raw]
    // CALCULATION: Advance per pixel: ++v11 and ++v13, and decrement the inner counter v14 by 2 (two words consumed per dest dword). [source:raw]
    // LOOP: Row end: reset v14 = a9, advance the source row by v18 words and the dest row by the new a8, then decrement the row counter a10 and exit when a10 <= 1. [source:raw]

    // Conservative worker pseudocode:
    //   void PixelBufferBlitWithShortToIntConversion(
    //       int a1, int a2, int a3, int a4, int a5,
    //       int a6, int a7, int a8, int a9, int a10, __int16 a11) {
    //     __int16 ref = a11;
    //     a9 *= 2;
    //     _WORD *src = (_WORD *)(a1 + 2 * a2 + a3 * a4);
    //     _DWORD *dst = (_DWORD *)(a5 + 2 * a6 + a7 * a8);
    //     int inner = a9;
    //     int srcRowAdvance = a4 - a9;
    //     int dstSecondOffset = a8;
    //     a8 = 2 * (a8 - a9);
    //     for (;;) {
    //       if (ref != *src) {
    //         unsigned v = *src;
    //         v = (v << 16) | v;
    //         *dst = v;
    //         *(int*)((char*)dst + dstSecondOffset) = v;
    //       }
    //       ++src; ++dst;
    //       inner -= 2;
    //       if (inner <= 2) {
    //         inner = a9;
    //         src = (_WORD*)((char*)src + srcRowAdvance);
    //         dst = (_DWORD*)((char*)dst + a8);
    //         if (a10-- <= 1) break;
    //       }
    //     }
    //   }
    // UNRESOLVED: Source surface layout (a1/a2/a3/a4) and destination surface layout (a5/a6/a7/a8) are flat parameters, not structs; their exact semantics are unproven.
    // UNRESOLVED: Why two dest dwords are written per source word (v15 = prior a8 offset) is unclear; possibly two interleaved dest buffers or a double-write pattern.
    // UNRESOLVED: The _InterlockedExchange on stack parameter a8 is likely a decompiler artifact; the real write is probably a plain assignment.
    // UNRESOLVED: The reference color a11 is inferred as a color-key/transparency value from the guard, but that role is not named by the evidence.
}
