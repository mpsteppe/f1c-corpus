// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00503533
// Canonical corpus name: ImageBlendingCompositing
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ImageBlendingCompositing_00503533.c

void UnknownObject::ImageBlendingCompositing()
{
    // Scalar 2x2 box-average image compositor. Processes a4 output rows; for each output pixel it averages a 2x2 source neighborhood (left pixel, current pixel, and the two pixels one source row below via stride a5) using channel-separated byte math with rounding constant 131074 and carry base 0x00800080, writing one dword to the destination cursor a1. Source advances 2*dword per output dword and two source rows per output row, so the pass is a 2:1 box downsample. The MMX wrapper 0x00503772 dispatches here as its misalignment fallback.
    // GUARD: Empty-range guard: when a2 is not below v14 = a2 + a5*a4 the source range is empty, so skip the pass and return 0. [source:raw]
    // LOOP: Outer loop over the a4 output rows while v6 stays below v14 = a2 + a5*a4; each iteration advances the destination pointer a1 by a6 bytes and the source position by 2*a5 bytes (two source rows consumed per output row). [source:raw]
    // GUARD: Per-row guard: when the current source column v6 has already reached the row end v20 = a2 + 4*a3, skip the row's pixel loop. [source:raw]
    // LOOP: Inner pixel loop running ((v20 - v6 - 1) >> 3) + 1 times; each iteration advances the source window v8 by 8 bytes (2 dwords) and the destination cursor v18 by one dword, giving the 2:1 horizontal downsample. [source:raw]
    // CALCULATION: Gather the 2x2 source neighborhood around the current dword v8: left pixel *(v8 - 1), current pixel *v8, below pixel *(v8 + a5) (v19), and below-left pixel *(v8 + a5 - 4) (v17). [source:raw]
    // CALCULATION: Channel-separated 4-tap average: mask and sum each of the 0xFF00FF byte pairs of the four pixels, add rounding 131074, shift right by 2; fold the shifted high-byte sums (masked 0x3FC03FC0 and 0xFFC03FC0, base 0x00800080, subtract 8388480) so the middle byte is recovered without cross-byte carry. [source:raw, global:0x00800080]
    // ASSIGNMENT: Write the averaged dword to the destination at the incrementing cursor v18. [source:raw]
    // RETURN: Return 0 on the empty-range path. [source:raw]

    // Conservative worker pseudocode:
    //   int ImageBlendingCompositing(unsigned int* dst, unsigned int src, int a3, int a4, int a5, int a6) {
    //     unsigned int end = src + a5 * a4;
    //     if (src < end) {
    //       unsigned int rowEnd = src + 4 * a3;
    //       do {
    //         unsigned int* out = dst;
    //         if (src < rowEnd) {
    //           unsigned int p = src + 4;
    //           unsigned int n = ((rowEnd - src - 1) >> 3) + 1;
    //           do {
    //             unsigned int ul = *(unsigned int*)(p + a5 - 4);
    //             unsigned int bl = *(unsigned int*)(p + a5);
    //             unsigned int u = p[-1];
    //             unsigned int cur = *(unsigned int*)p;
    //             *out++ = avg4(ul, bl, u, cur); /* channel-separated, rounding 131074, base 0x00800080 * /
    //             p += 8;
    //           } while (--n != 0);
    //         }
    //         dst = (unsigned int*)((char*)dst + a6);
    //         src += 2 * a5;
    //       } while (src < end);
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: The exact buffer identity and purpose (mipmap generation, background downsample, or a compositing stage) are DERIVED from the 2x2 average structure; no runtime evidence in this packet confirms which surfaces a1/a2 address.
    // UNRESOLVED: Caller 0x00503772 dispatches to this function when its row width is not 4-byte aligned ((a3 & 3) != 0); the caller relationship is evidenced but the surrounding compositing context is not.
    // UNRESOLVED: Whether a2 is an absolute buffer address or an offset into a larger image, and how the caller supplies a1/a2, are not evidenced here.
}
