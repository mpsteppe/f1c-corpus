// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00518248
// Canonical corpus name: TextureHorizontalStretch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TextureHorizontalStretch_00518248.c

void UnknownObject::TextureHorizontalStretch()
{
    // Stretches a texture row horizontally by replicating each source pixel a number of times into an output row buffer (a2). The stretch factor is the stride-table entry dword_5AFABC[a3]; the stretched width is that factor times the source width (this+0x0). The bits-per-pixel byte (this+0xB) selects the packing path: 1, 2, or 4-bit values are read from the packed source bitstream and written with bit-level mask-clear/insert into the output bitstream, while any value >= 8 uses a byte-copy path (bytes per pixel = this+0xB >> 3). On completion this+0x0 is updated to the stretched width and this+0x4 to the output byte count ((stretched width * this+0xB + 7) >> 3). Returns void.
    // GUARD: Guard: return without work when the output buffer a2 or the info pointer a1 is null. [abi:lead, caller:0x00511B7C, source:raw]
    // CALCULATION: Compute target width as dword_5AFABC[a3] * source width (this+0x0); the same table entry is retained as the per-pixel stretch factor. [global:0x005AFABC, field:this:0x00000000, source:raw]
    // GUARD: Guard: bits-per-pixel byte (this+0xB) == 1 selects the single-bit replication path. [field:this:0x0000000B, source:raw]
    // LOOP: 1bpp path: for each of the source-width pixels (this+0x0), read one bit from the packed source bitstream and, in an inner loop, write that bit (mask-clear then insert) the stretch-factor number of times into the output bitstream. [field:this:0x00000000, global:0x005AFABC, source:raw]
    // GUARD: Guard: bits-per-pixel byte (this+0xB) == 2 selects the 2-bit replication path. [field:this:0x0000000B, guard:1, source:raw]
    // LOOP: 2bpp path: for each source pixel, read a 2-bit value and replicate it the stretch-factor number of times at 2-bit alignment in the output bitstream. [field:this:0x00000000, global:0x005AFABC, source:raw]
    // GUARD: Guard: bits-per-pixel byte (this+0xB) == 4 selects the 4-bit replication path. [field:this:0x0000000B, guard:0, source:raw]
    // LOOP: 4bpp path: for each source pixel, read a 4-bit value and replicate it the stretch-factor number of times at 4-bit alignment in the output bitstream. [field:this:0x00000000, global:0x005AFABC, source:raw]
    // GUARD: Guard: else path for bits-per-pixel >= 8, where bytes per pixel = this+0xB >> 3. [field:this:0x0000000B, source:raw]
    // LOOP: Byte path: copy each source row chunk (bytes per pixel times source width) into a local buffer and copy that buffer the stretch-factor number of times into the output row, iterating source-width times. [field:this:0x00000000, global:0x005AFABC, source:raw]
    // ASSIGNMENT: Finalize: update this+0x0 to the stretched width and this+0x4 to the output byte count (stretched width * this+0xB + 7) >> 3. [field:this:0x00000000, field:this:0x00000004, field:this:0x0000000B, source:raw]
    // RETURN: Function returns void; no value is produced. [function:0x00518248, source:raw]

    // Conservative worker pseudocode:
    //   void TextureHorizontalStretch(int *ctx, int out_buf, int table_index)
    //   {
    //     if ( !out_buf || !ctx )
    //       return;
    //     int src_width = ctx[0];
    //     int factor = dword_5AFABC[table_index];
    //     int dst_width = factor * src_width;
    //     int bpp = ((unsigned char *)ctx)[0xB];
    //     if ( bpp == 1 )
    //       /* per source bit: read 1 bit, write it factor times at 1-bit alignment * /
    //     else if ( bpp == 2 )
    //       /* per source 2-bit value: write it factor times at 2-bit alignment * /
    //     else if ( bpp == 4 )
    //       /* per source 4-bit value: write it factor times at 4-bit alignment * /
    //     else
    //       /* bpp >= 8: per source chunk of (bpp >> 3) bytes, copy the chunk factor times * /
    //     ctx[0] = dst_width;
    //     ctx[1] = (dst_width * bpp + 7) >> 3;
    //   }
    // UNRESOLVED: The meaning of the stride-table index a3 and the table dword_5AFABC entries is unconfirmed; the entry is both a stretch factor and a width multiplier.
    // UNRESOLVED: The bit-packed replication loops use precomputed mask values (32639, 16191, 3855) to preserve higher bits during mask-clear/insert; their exact relationship to the bit depth is unconfirmed.
    // UNRESOLVED: The object owner is unknown; the layout of this+0x0, 0x4 and 0xB beyond the accessed offsets is unconfirmed.
    // UNRESOLVED: Whether this function stretches a full multi-row texture or a single row is unconfirmed; the source here iterates only over the width dimension.
}
