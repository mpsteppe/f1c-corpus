// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0051DB31
// Canonical corpus name: BitstreamTextureBlockCopy
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BitstreamTextureBlockCopy_0051db31.c

void UnknownObject::BitstreamTextureBlockCopy()
{
    // Bitstream texture block quantize-and-copy helper (__usercall). Given a texture object a2, a source block coordinate set a1/a3/a4 and a destination word-table base reached as *(*(a2+420)+24), it quantizes the source region to nearest palette colors via PaletteVectorQuantizationNearestNeighbor, derives the per-block index stream through sub_51DA17, then writes the encoded block into the table as 4x8 groups of 4 words (*index + 1), stepping the write cursor by 64 bytes per row. Returns the final cursor position.
    // CALCULATION: Compute scaled per-side coordinates from the packed inputs: v18 = a4 >> 2 and v16 = a3 >> 2. [source:raw]
    // ASSIGNMENT: Load the destination word-table base v14 = *(*(a2 + 420) + 24), reached by following the a2 texture object's pointer at +420 to a structure whose +24 field holds the table. [source:raw]
    // CALCULATION: Compute block geometry: v4 = a1 >> 3, row-advance v13 = 32 * v18 + 4, and v15 = 2 * (4 * v18 + (v4 << 8)). [source:raw]
    // CALL: Call PaletteVectorQuantizationNearestNeighbor(a2, 32*(a1>>3)+2, 32*v16+4, v13, v11) to quantize the source block to the nearest palette colors, filling the local buffer v11. [callee:0x0051D897, source:raw]
    // CALL: Call sub_51DA17(a2, 32*v16+4, 32*v4+2, v13, v5, v11, v12) to derive the block's palette-index stream into the local buffer v12. [callee:0x0051DA17, source:raw]
    // ASSIGNMENT: Point v6 at the index stream v12 and v7 at v14 + 16*v16, the target word-table slot for this block. [source:raw]
    // LOOP: Nested loops (4 x 8 x 4) write the encoded block into the word table: each inner group stores 4 words of (*v6++ + 1), the row cursor advances by 64 bytes per inner pass, and the outer loop advances the table slot v7 by one element per pass. [source:raw]
    // RETURN: Return the final word-cursor position reached while writing the block. [source:raw]
    // CALL: Invoked by PackedPixelCopyWithPaletteLookup (0x0051DC01) and BlockTextureDecompression (0x0051DCAA) to store a palette-quantized texture block. [caller:0x0051DC01, caller:0x0051DCAA, source:raw]

    // Conservative worker pseudocode:
    //   word *BitstreamTextureBlockCopy(int a1, int a2, int a3, int a4) {
    //     int v18 = a4 >> 2, v16 = a3 >> 2;
    //     int v14 = *(int *)(*(int *)(a2 + 420) + 24);
    //     int v4 = a1 >> 3;
    //     int v13 = 32 * v18 + 4;
    //     int v5 = PaletteVectorQuantizationNearestNeighbor(a2, 32*(a1>>3)+2, 32*v16+4, v13, v11);
    //     sub_51DA17(a2, 32*v16+4, 32*v4+2, v13, v5, v11, v12);
    //     word *src = v12;
    //     int v15 = 2 * (4 * v18 + (v4 << 8));
    //     dword *slot = v14 + 16 * v16;
    //     for (int q = 0; q < 4; ++q) {
    //       int row = v15;
    //       for (int r = 0; r < 8; ++r) {
    //         word *dst = row + *slot;
    //         for (int w = 0; w < 4; ++w) *dst++ = *src++ + 1;
    //         row += 64;
    //       }
    //       ++slot;
    //     }
    //     return dst;
    //   }
    // UNRESOLVED: Identity of a2: a texture/palette manager whose +420 field points to a structure whose +24 field holds the destination word table.
    // UNRESOLVED: Exact pixel-layout semantics of the 32-scaled source window and the 4x8x4 word write pattern.
    // UNRESOLVED: Meaning of the sub_51DA17 return value v5 and of the +1 increment applied to stored index words.
}
