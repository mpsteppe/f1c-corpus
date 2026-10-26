// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0051C099
// Canonical corpus name: TrackMapPixelFill
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TrackMapPixelFill_0051c099.c

void UnknownObject::TrackMapPixelFill()
{
    // Expands track-map pixel rows: reads a per-pixel fill width and a row-repeat count from a secondary structure, stretches each source byte into a repeated 4-byte pattern filled for the pixel width, then duplicates each row downwards via F_2DArrayBlockCopy for vertical expansion. Iterates a1[68] rows, each a1[23] bytes wide.
    // ASSIGNMENT: v4 = *a4: load the destination row-pointer array base. [source:raw]
    // CALCULATION: v6 = *(a2 + 4) + a1[103]: form a secondary structure pointer by adding the self field at +0x19C to the pointer stored at a2+4. [field:this:0x0000019C, source:raw]
    // ASSIGNMENT: Read two control bytes from the secondary structure: v21 = byte at v6+140 (per-pixel fill width in bytes) and v18 = byte at v6+150 (row-repeat count). Save v16 = *a4 as the restore value for dstBase. [source:raw]
    // LOOP: Outer loop over rows: iterate while rowIndex v9 < a1[68] (row count from self field at +0x110); advance rowIndex by rowRepeatCount each pass. [field:this:0x00000110]
    // ASSIGNMENT: Per row: v10 = *a3 (source pixel row string); v11 = row pointer from the destination array v4[4 * v9]; v12 = v11 + a1[23] sets the row-end cursor using the self field at +0x5C as pitch. [field:this:0x0000005C, source:raw]
    // LOOP: Inner loop over the current row: while the destination pixel cursor v19 is below the row end v12, consume the next source byte v13 = *v10++. [source:raw]
    // GUARD: If v21 > 0, expand the current source pixel; otherwise skip expansion (v19 is not advanced and the loop condition is unaffected). [source:raw]
    // ASSIGNMENT: Expand pixel value v13 into the repeated 4-byte pattern v14 = (v13<<8 | v13) << 16 | (v13<<8 | v13); fill v21 bytes at v19 with memset32 for the aligned part plus memset for the trailing v21 & 3 bytes; advance v19 += v21 and restore v4 = v16. [source:raw]
    // GUARD: After the inner loop, if v18 > 1, duplicate the finished row downwards by the remaining v18-1 copies. [source:raw]
    // CALL: F_2DArrayBlockCopy(v4, v9, v4, v9 + 1, v18 - 1, a1[23]): copy a block v18-1 rows tall and a1[23] bytes wide from source row v9 to row v9+1 onward, producing the vertical expansion. [callee:0x0051593F, field:this:0x0000005C]
    // CALCULATION: Advance to the next source row: v9 += v18 and ++a3; preserve v18 as the returned pointer value. [source:raw]
    // RETURN: Return the row-repeat/result pointer (v18, or the last F_2DArrayBlockCopy result). [function:0x0051C099, source:raw]

    // Conservative worker pseudocode:
    //   rowRepeatCount = byte(secPtr + 150);
    //   pixelFillWidth = byte(secPtr + 140);
    //   dstBase = *dstRowArray;
    //   rowIndex = 0;
    //   while (rowIndex < self[68]) {
    //     srcCursor = *srcRowTable;
    //     dstRow = dstBase[rowIndex];
    //     rowEnd = dstRow + self[23];
    //     dstCursor = dstRow;
    //     while (dstCursor < rowEnd) {
    //       px = *srcCursor++;
    //       if (pixelFillWidth > 0) {
    //         fill = (px << 8 | px) << 16 | (px << 8 | px);
    //         memset32(dstCursor, fill, pixelFillWidth >> 2);
    //         memset(dstCursor + 4 * (pixelFillWidth >> 2), fill, pixelFillWidth & 3);
    //         dstCursor += pixelFillWidth;
    //       }
    //     }
    //     if (rowRepeatCount > 1)
    //       F_2DArrayBlockCopy(dstBase, rowIndex, dstBase, rowIndex + 1, rowRepeatCount - 1, self[23]);
    //     rowIndex += rowRepeatCount;
    //     srcRowTable++;
    //   }
    // UNRESOLVED: The object type behind a2+4 and the meaning of the control bytes at v6+140 / v6+150 are unnamed; they gate per-pixel fill width and row-repeat count but their source class is unknown.
    // UNRESOLVED: memset32 and memset are treated as compiler intrinsics, not listed callees; the packet records only F_2DArrayBlockCopy as a call target.
    // UNRESOLVED: When v21 == 0 the inner loop never advances v19, so per-source-byte consumption and the v19 < v12 bound could diverge; the decompiled control flow does not resolve this case.
    // UNRESOLVED: Whether self fields +0x5C (pitch) and +0x110 (row count) belong to the same object as the secondary structure at a2+4 is not established.
}
