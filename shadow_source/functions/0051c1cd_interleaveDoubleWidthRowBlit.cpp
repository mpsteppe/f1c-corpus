// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0051C1CD
// Canonical corpus name: BufferInterleaveCopy
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BufferInterleaveCopy_0051c1cd.c

void UnknownObject::interleaveDoubleWidthRowBlit()
{
    // Interleaved row blit that doubles each source byte horizontally into every other destination row, then duplicates the filled row to the adjacent row via F_2DArrayBlockCopy. Outer loop advances the destination row index by two and the source row pointer by one until the row count at this+0x110 is reached.
    // ASSIGNMENT: Initialize the destination row index v6 to zero and read the base index i from *a4. [source:raw]
    // LOOP: Iterate while the destination row index v6 is below the row count at this+0x110, stepping the row index by two each pass. [field:this:0x00000110, source:raw]
    // ASSIGNMENT: Read the source row pointer from *a3 and the destination row pointer from the index base at offset 4*v6. [source:raw]
    // CALCULATION: Compute the end-of-row boundary for the destination row as its base plus the row-width value at this+0x5C. [field:this:0x0000005C, source:raw]
    // GUARD: Enter the inner duplication loop only while the destination byte pointer is below the row-end boundary. [field:this:0x0000005C, source:raw]
    // LOOP: Write each source byte twice into consecutive destination bytes until the row-end boundary is reached. [source:raw]
    // CALL: Call F_2DArrayBlockCopy with the destination row v6 as both source and target, adjacent row v6+1 as the copy target, and the row-width value at this+0x5C as the block width, duplicating the filled row vertically. [callee:0x0051593F, field:this:0x0000005C, source:raw]
    // ASSIGNMENT: Advance the source row pointer a3 to the next source row. [source:raw]
    // RETURN: Return a4, the pointer value threaded through the block-copy call. [source:raw, abi:lead]

    // Conservative worker pseudocode:
    //   const void **interleaveDoubleWidthRowBlit(int a1, int a2, char **a3, int *a4) {
    //       int v5 = *a4;
    //       int v6 = 0;
    //       for (int i = *a4; v6 < *(int *)(a1 + 272); v6 += 2) {
    //           char *v7 = *a3;
    //           _BYTE *v8 = *(_BYTE **)(v5 + 4 * v6);
    //           _BYTE *v9 = &v8[*(int *)(a1 + 92)];
    //           if (v8 < v9) {
    //               do { *v8++ = *v7++; *v8++ = *v7++; } while (v8 < v9);
    //               v5 = i;
    //           }
    //           F_2DArrayBlockCopy(v5, v6, v5, v6 + 1, 1, *(int *)(a1 + 92));
    //           ++a3;
    //       }
    //       return (const void **)a4;
    //   }
    //   
    // UNRESOLVED: Owner object type is unknown; no caller or object identity evidence in the packet.
    // UNRESOLVED: The exact semantics of the F_2DArrayBlockCopy arguments (index-to-row mapping) are inferred from the call shape, not confirmed externally.
    // UNRESOLVED: The row-width field this+0x5C and row-count field this+0x110 semantics are DERIVED from the loop structure, not confirmed by an external source.
    // UNRESOLVED: Why only every other destination row is filled directly (interleave pattern) before vertical duplication is structural inference.
}
