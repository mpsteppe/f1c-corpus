// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0051941D
// Canonical corpus name: TextureRowCopy
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TextureRowCopy_0051941d.c

void UnknownObject::TextureRowCopy()
{
    // Copies per-element texture row data for a playback/render pass. Driven by an element count at this+0x20, it walks an array of element descriptors (base this+0xC4, stride 21 dwords) computing a scaled work amount v4 = desc[0] * desc[+24] / this+0x114, then performs three nested copy passes between per-element source and destination buffers read from the pointer arrays at this+0x1B8 and this+0x1BC. Called by PlaybackStateController (0051984b).
    // GUARD: Skip all row copying when the element count at this+0x20 is not greater than zero [guard:0, field:this:0x00000020, source:raw]
    // ASSIGNMENT: Initialize per-call state: v1 = pointer-array base at this+0x180, v20 = divisor at this+0x114, result = descriptor base at this+0xC4, index v25 = 0 [field:this:0x00000180, field:this:0x00000114, field:this:0x000000C4, source:raw]
    // LOOP: Iterate element descriptors starting at this+0xC4 + 12, advancing 21 dwords per element, until the index v25 reaches the count at this+0x20 [field:this:0x000000C4, field:this:0x00000020, source:raw]
    // CALCULATION: Compute the scaled work amount for the current element: v4 = desc[0] (at this+0xD0, first dword of the per-element descriptor) times desc[6] (at this+0xE8) divided by the divisor this+0x114 [field:this:0x000000D0, field:this:0x000000E8, field:this:0x00000114, source:raw]
    // ASSIGNMENT: Fetch per-element buffer pointers: source from the this+0x1B8 pointer array at index v25, destination from the this+0x1BC pointer array at index v25, plus the row value v6 read at this+0x188 [field:this:0x000001B8, field:this:0x000001BC, field:this:0x00000188, source:raw]
    // LOOP: First copy pass, running while v4 * (v20 + 2) is positive: read a dword from the source at offset (v6 - v5), write it to the destination and to a second destination at offset (v17 - v5), expanding a single value across two buffer positions [source:raw]
    // LOOP: Second copy pass, running while 2 * v4 is positive: interleaved copy between a destination base at v5 + 4*v20*v4 and a source base at v6 + 4*v4*(v20 - 2), writing each dword to both sides of the row [source:raw]
    // LOOP: Third copy pass, running while v4 is positive: walk backward from the source pointer minus v4 dwords, writing the source value into each of the v4 preceding slots [source:raw]
    // RETURN: Advance the element index (result = ++v25) and return it once the loop condition is met; the caller PlaybackStateController (0051984b) uses the return as the last processed index [function:0x0051941D, caller:0x0051984B, source:raw]

    // Conservative worker pseudocode:
    //   count = this[+0x20];
    //   v1 = this[+0x180]; v20 = this[+0x114];
    //   result = this[+0xC4]; idx = 0;
    //   if (count > 0) {
    //     for (desc = result + 12; idx < count; desc += 21, ++idx) {
    //       v4 = desc[0] * desc[6] / v20;
    //       src = v1[14][idx]; dst = v1[15][idx]; row = v1[2 + idx];
    //       for (n = v4*(v20+2); n; --n) spread(dst, src, row, dst2);
    //       for (n = 2*v4; n; --n) interleave(dst + 4*v20*v4, src + 4*v4*(v20-2));
    //       for (n = v4; n; --n) *(--src) = *src_orig;
    //     }
    //   }
    //   return idx;
    // UNRESOLVED: The geometric meaning of the three copy passes (fill labels them horizontal expansion/interpolation, but the dual destination at +0x1B8/+0x1BC suggests an interleaved two-buffer layout) is not pinned from this packet
    // UNRESOLVED: The row value read at this+0x188 advances one dword per element while the descriptor base strides 21 dwords, implying this+0x180 points at a parallel per-element array rather than a contiguous descriptor block; the exact layout is unverifiable here
}
