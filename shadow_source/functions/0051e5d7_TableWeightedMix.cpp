// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0051E5D7
// Canonical corpus name: TableWeightedMix
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TableWeightedMix_0051e5d7.c

void UnknownObject::TableWeightedMix()
{
    // Per-pixel channel mixing via multiple byte lookup tables. For each of a4 pixels, reads a source byte row and a destination pixel pointer, then for each output byte (width from this+0x5C) sums, over each channel (count from this+0x64), the table byte at table[channel][source_byte] and writes the summed byte to the destination. The table array base is loaded through the context pointer at this+0x1A4 (dereferenced +24, the this+0x1BC context field).
    // ASSIGNMENT: Load pixel width from field this+0x5C into v4. [field:this:0x0000005C, function:0x0051E5D7, source:raw]
    // ASSIGNMENT: Load channel count from field this+0x64 into result (saved as v12). [field:this:0x00000064, function:0x0051E5D7, source:raw]
    // ASSIGNMENT: Load context pointer at this+0x1A4 and dereference it at +24 (0x18) to obtain the lookup table array base v13 (context field this+0x1BC). [field:this:0x000001A4, field:this:0x000001BC, function:0x0051E5D7, source:raw]
    // GUARD: Skip all per-pixel processing when pixel count a4 <= 0. [abi:lead, function:0x0051E5D7, source:raw]
    // LOOP: Outer loop over a4 pixels: derive source byte row v7 as the pointer stored at byte offset (a2 + 4*pixel_index), recomputed from a2 minus the a3 array base, and destination pixel pointer v17 as the DWORD value at the current a3 element. [abi:lead, function:0x0051E5D7, source:raw]
    // GUARD: Skip the per-pixel mix when width v4 is zero. [field:this:0x0000005C, function:0x0051E5D7, source:raw]
    // LOOP: Inner loop over v4 output bytes per pixel: reset byte accumulator v16 to 0 and advance the destination write pointer v9. [field:this:0x0000005C, function:0x0051E5D7, source:raw]
    // GUARD: Run the channel accumulation only while channel count result (v12) is positive. [field:this:0x00000064, function:0x0051E5D7, source:raw]
    // CALCULATION: For each channel v8, accumulate v16 += byte read from lookup table (DWORD at table_array_base v13 + 4*v8) indexed by source byte *v7; advance v7 to the next channel's source byte and restore result to the saved channel count v12. [field:this:0x000001BC, field:this:0x00000064, function:0x0051E5D7, source:raw]
    // ASSIGNMENT: Write the summed accumulator byte v16 to the destination pointer *v9 and advance it to the next output byte. [function:0x0051E5D7, source:raw]
    // RETURN: Return result, which was restored to the channel count from this+0x64. [field:this:0x00000064, abi:lead, function:0x0051E5D7, source:raw]

    // Conservative worker pseudocode:
    //   int TableWeightedMix(this, a2, a3, a4) {
    //     width = this->field_0x5C;
    //     channel_count = this->field_0x64;
    //     tables = *(DWORD**)(this->field_0x1A4 + 24);
    //     if (a4 <= 0) return channel_count;
    //     for (pixel = 0; pixel < a4; ++pixel) {
    //       src_row = *(BYTE**)(a2 + 4*pixel);
    //       dst_pixel = (BYTE*)a3[pixel];
    //       if (width == 0) continue;
    //       for (j = 0; j < width; ++j) {
    //         sum = 0;
    //         for (c = 0; c < channel_count; ++c) {
    //           sum += tables[c][*src_row++];
    //         }
    //         *dst_pixel++ = (BYTE)sum;
    //       }
    //     }
    //     return channel_count;
    //   }
    // UNRESOLVED: Exact buffer roles of a2 and a3 are ambiguous: a2 is used as a byte-address base from which per-pixel source row pointers are read, while a3 is an array of DWORDs dereferenced as destination pixel pointers; the source data layout behind those pointers is not confirmed.
    // UNRESOLVED: The object pointed to by this+0x1A4, whose +0x18 (0x18) field holds the lookup table array, is unidentified.
    // UNRESOLVED: Why the function returns the channel count rather than a success/error code is unknown.
    // UNRESOLVED: Width this+0x5C is treated as the number of output bytes per pixel; whether it equals a pixel stride or an unrelated row length is unverified.
    // UNRESOLVED: The lookup tables themselves are opaque bytes; no palette or channel-weight semantics are established.
}
