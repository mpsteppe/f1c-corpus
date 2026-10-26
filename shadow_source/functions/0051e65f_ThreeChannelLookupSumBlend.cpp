// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0051E65F
// Canonical corpus name: ChecksumComputeType03Stream
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ChecksumComputeType03Stream_0051e65f.c

void UnknownObject::ThreeChannelLookupSumBlend()
{
    // Blends 3-channel pixel data by summing three lookup-table reads into a single output byte per source pixel. Reads a context pointer from this+0x1A4, from which an array of three table base pointers is loaded at +0x18. For each pixel descriptor in the a3 array (a4 total), reads a source byte pointer and destination byte pointer, then for each of this+0x5C bytes accumulates LUT0[src0] + LUT1[src1] + LUT2[src2] into the destination. Outer loop is skipped when a4 <= 0; the inner blend loop is skipped when this+0x5C is zero.
    // CALCULATION: Read context pointer from this+0x1A4, then load the lookup-table array base from that context at +0x18 [field:this:0x000001A4, field:*(this+0x1A4):0x00000018]
    // ASSIGNMENT: Load the three table base pointers into v18, v17, v16 from the table array indices 0, 4, 8 [field:*(*(this+0x1A4)+0x18):0x00000000, field:*(*(this+0x1A4)+0x18):0x00000004, field:*(*(this+0x1A4)+0x18):0x00000008]
    // ASSIGNMENT: Load the per-pixel byte count (stride) from this+0x5C into v7; this value is the inner loop bound and is saved/restored around each pixel [field:this:0x0000005C]
    // GUARD: Outer processing is skipped entirely when the pixel count a4 is not greater than 0 [source:raw]
    // LOOP: Iterate over a4 pixel descriptors in the a3 array; each descriptor contributes a destination pointer (*v8) and a source pointer computed from a2 [source:raw]
    // GUARD: Per-pixel inner blend only runs when the saved stride v7 is non-zero; a zero stride skips the lookup-sum for that pixel [source:raw]
    // LOOP: Inner loop walks v7 source bytes; each iteration reads one byte through each of the three tables and advances the source pointer by three bytes [source:raw]
    // CALCULATION: Output byte = LUT0[src byte 0] + LUT1[src byte 1] + LUT2[src byte 2], accumulated as a character sum [source:raw]
    // ASSIGNMENT: Store the summed byte into the destination pointer and advance it [source:raw]
    // RETURN: Return the leftover pointer-difference value (a2 - a3); not a meaningful checksum result [function:0x0051E65F, source:raw]

    // Conservative worker pseudocode:
    //   tables = *(uint8_t **)(**(void **)(this + 0x1A4) + 0x18);
    //   lut0 = tables[0]; lut1 = tables[1]; lut2 = tables[2];
    //   stride = *(int *)(this + 0x5C);
    //   for (pix = 0; pix < a4; ++pix) {
    //     dst = *(uint8_t **)&desc[pix]; src = *(uint8_t **)((char *)&desc[pix] + (a2 - (uint32_t)a3));
    //     if (stride != 0) {
    //       for (i = 0; i < stride; ++i) {
    //         *dst++ = lut2[src[2]] + (lut1[src[1]] + lut0[src[0]]);
    //         src += 3;
    //       }
    //     }
    //   }
    // UNRESOLVED: The ABI label ChecksumCompute_Type0_3Stream (LEGACY trust) describes this as a checksum computation, but the raw source shows a three-table lookup sum into a byte buffer, which is inconsistent with checksum semantics
    // UNRESOLVED: The exact role of this+0x5C (labeled pixel width/stride in the skeleton fill) is inferred; the descriptor layout of the a3 array is not defined in this packet
}
