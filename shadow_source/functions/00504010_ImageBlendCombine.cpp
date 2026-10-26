// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00504010
// Canonical corpus name: ImageBlendCombine
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ImageBlendCombine_00504010.c

void UnknownObject::ImageBlendCombine()
{
    // Weighted-average combine of two 16-bit source rows into a 16-bit destination row, matching the legacy ABI lead Blend_two_16_bit_pixel_buffers_using_weighted_av. Reads 16-bit pixels at *(obj+0x18) of the source object (this+0x0) and writes to the destination buffer at destObj+0x18 (object at this+0x4). Geometry (stride, row width, row count) comes from obj+0x1050, obj+0x1058 and obj+0x105C. For each output pixel it reads a 2x2 block of 16-bit words, splits each pixel into two channel groups with masks 0xE3 and 0xFF1C, averages each group across the four pixels with rounding constants 66 and 520, shifts right by 2, and recombines the groups into the output word. Source advances one row per output row; destination advances one row. Returns 0.
    // ASSIGNMENT: Read the source image object pointer from this+0x0 and the destination image object pointer from this+0x4. [field:this:0x00000000, field:this:0x00000004]
    // ASSIGNMENT: Read the source 16-bit pixel buffer pointer from obj+0x18 and the destination pixel buffer pointer reached through the destination object at this+0x4 plus 24. [field:obj:0x00000018, field:this:0x0000001C]
    // ASSIGNMENT: Read the image geometry from the source object: stride at obj+0x1050, row width at obj+0x1058, and row count at obj+0x105C. [field:obj:0x00001050, field:obj:0x00001058, field:obj:0x0000105C]
    // ASSIGNMENT: Read the destination row stride from the destination object at +4176. [field:this:0x00001054]
    // CALCULATION: Compute the source end pointer as source pixel buffer + stride * row count. [field:obj:0x00001050, field:obj:0x0000105C]
    // LOOP: Outer loop over pairs of source rows, running while the source pointer is below the row-count-limited end pointer. [source:raw]
    // CALCULATION: Compute the inner row bound as source pointer + row width, and the second source row as source pointer + stride. [field:obj:0x00001058, field:obj:0x00001050]
    // LOOP: Inner loop over pixel pairs, consuming two 16-bit words per source row for each output word. [source:raw]
    // GUARD: Inner loop terminates when the row source pointer reaches the width bound. [source:raw]
    // CALCULATION: Read the four source 16-bit pixels of the 2x2 block from *(obj+0x18) at byte offsets 0 and 2 of both rows, and split each pixel into two component groups with masks 0xE3 and 0xFF1C. [field:*(obj+0x18):0x00000000, field:*(obj+0x18):0x00000002]
    // CALCULATION: Average each channel group across the four pixels with rounding constants 66 and 520, shift each average right by 2, and recombine the averaged groups into the output word. [source:raw, abi:lead]
    // ASSIGNMENT: Write the blended 16-bit word into the destination pixel buffer. [field:obj:0x00000018]
    // CALCULATION: Advance the source pointer by one source row (stride) and the destination pointer by one destination row (destination stride). [field:obj:0x00001050, field:this:0x00001054]
    // RETURN: Return 0 after all row pairs are processed. [source:raw]

    // Conservative worker pseudocode:
    //   int ImageBlendCombine(void* a1) {
    //     src = *(a1 + 0x0) + 0x18;
    //     dst = *(a1 + 0x4) + 0x18;
    //     stride = srcObj + 0x1050; width = srcObj + 0x1058; rows = srcObj + 0x105C;
    //     dstStride = dstObj + 0x1050;
    //     end = src + stride * rows;
    //     while (src < end) {
    //       row2 = src + stride;
    //       rowEnd = src + width;
    //       for (p = src, q = row2; p < rowEnd; p += 2, q += 2) {
    //         // split each 16-bit pixel into channel groups with masks 0xE3 and 0xFF1C
    //         *dstOut++ = weightedAverage4(p[0], p[1], q[0], q[1]);
    //       }
    //       src += stride; dst += dstStride;
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: Exact 16-bit pixel format (RGB565, ARGB1555 or similar) is not determinable from the packet; the 0xE3/0xFF1C channel-grouping interpretation is DERIVED.
    // UNRESOLVED: The precise channel weights implied by the rounding constants 66 and 520 are not grounded in the packet.
    // UNRESOLVED: The extractor dual-records the destination object accesses (obj+0x18 vs this+0x1C, obj+0x1050 vs this+0x1054); both refer to the same destination object through this+0x4.
}
