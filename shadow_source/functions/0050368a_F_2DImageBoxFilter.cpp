// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050368A
// Canonical corpus name: F_2DImageBoxFilter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_2DImageBoxFilter_0050368a.c

void UnknownObject::F_2DImageBoxFilter()
{
    // C-level 2D box filter over a packed 32-bit pixel buffer. A row/column double loop averages each 2x2 neighborhood (four dword taps at offsets 0, +4, +row-stride, +row-stride+4) by summing the taps under the 0xFF00 and 0xFF00FF channel masks, adding rounding constants 512 and 131074, re-masking with 0x3FC00 and 0x3FC03FC, and shifting right by 2 before storing. The output pointer advances by a6 bytes per row while the input row span advances by 2*a5 dwords, implying an output span half the input span per row. Returns 0.
    // CALCULATION: v13 = a2 + a5 * a4; compute the end offset of the rectangular region (start plus rows times vertical stride). [source:raw]
    // GUARD: if (a2 < v13) — only run the filter when the region end is strictly after its start, i.e. a non-empty region. [source:raw]
    // CALCULATION: v16 = a2 + 4 * a3; compute the end offset of the first row (a3 spans of one 32-bit pixel each). [source:raw]
    // LOOP: Outer loop, do/while, repeats while the current row offset v7 stays below the region end v13. [source:raw]
    // GUARD: if (v7 < v16) — process the row only when the current offset is below the row end. [source:raw]
    // LOOP: Inner loop, do/while, iterating v14 = ((v16 - v7 - 1) >> 3) + 1 times, advancing the read pointer by two dwords per step; the loop-termination flag is the decrement reaching 1. [source:raw]
    // CALCULATION: v9 = ( (tap(+stride) & 0xFF00) + (tap(+stride-4) & 0xFF00) + (tap(-4) & 0xFF00) + (tap(0) & 0xFF00) + 512 ) & 0x3FC00 | ( (tap(+stride) & 0xFF00FF) + (tap(+stride-4) & 0xFF00FF) + (tap(-4) & 0xFF00FF) + (tap(0) & 0xFF00FF) + 131074 ) & 0x3FC03FC; sum four neighboring dwords (current row and one vertical stride ahead, current and one dword left) under two channel masks with additive rounding, then combine the two masked sums. [source:raw]
    // ASSIGNMENT: *v15 = v9 >> 2; write the shifted-by-2 average of the 2x2 neighborhood to the current output dword, then advance the output pointer by one dword. [source:raw]
    // ASSIGNMENT: Advance row state: a1 += a6 (destination pointer by byte pitch a6), v16 += 2 * a5 and v7 += 2 * a5 (row span by twice the vertical stride); v6 is reloaded from a5 each inner step. [source:raw]
    // RETURN: return 0; the function always finishes with integer status 0. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_50368A(unsigned int* buf, unsigned int start, int row_span, int rows, int stride, int dst_pitch) {
    //       unsigned int end = start + stride * rows;
    //       if (start < end) {
    //           unsigned int row_end = start + 4 * row_span;
    //           do {
    //               unsigned int* dst = buf;
    //               if (v7 < row_end) {
    //                   for (count = ((row_end - v7 - 1) >> 3) + 1; count != 1; count--) {
    //                       v9 = ((tap[+stride] & 0xFF00) + (tap[+stride-4] & 0xFF00) + (tap[-4] & 0xFF00) + (tap[0] & 0xFF00) + 512) & 0x3FC00
    //                          | ((tap[+stride] & 0xFF00FF) + (tap[+stride-4] & 0xFF00FF) + (tap[-4] & 0xFF00FF) + (tap[0] & 0xFF00FF) + 131074) & 0x3FC03FC;
    //                       *dst++ = v9 >> 2;
    //                   }
    //                   v7 = start;
    //               }
    //               buf = (unsigned int*)((char*)buf + dst_pitch);
    //               row_end += 2 * stride;
    //               v7 += 2 * stride;
    //           } while (v7 < end);
    //       }
    //       return 0;
    //   }
    // UNRESOLVED: Exact pixel-format split implied by the 0xFF00 / 0xFF00FF masks (high and low byte groups of a packed RGBA/ARGB word) is inferred from the arithmetic, not directly proven by the packet.
    // UNRESOLVED: The output pointer advances by a6 bytes while the row span advances by 2*a5 dwords, so the output row span appears to be half the input span (2x2 box downsample); the precise output-buffer layout contract is inferred, not stated.
    // UNRESOLVED: Parameter units (a3 as dword span, a5 as byte stride, a6 as byte pitch) are read from the pointer arithmetic in the raw source and are DERIVED.
    // UNRESOLVED: No caller evidence: how this filter is invoked or where its input/output buffers come from is not present in the packet.
}
