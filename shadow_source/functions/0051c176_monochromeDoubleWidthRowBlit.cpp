// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0051C176
// Canonical corpus name: MonochromeBufferByteDuplicateCopy
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MonochromeBufferByteDuplicateCopy_0051c176.c

void UnknownObject::monochromeDoubleWidthRowBlit()
{
    // Copies each source byte twice into consecutive destination bytes, doubling horizontal width, per row. Outer loop iterates a row count (this+0x110) of destination row pointers; inner loop duplicates bytes up to a row-end boundary derived from a row-width field (this+0x5C).
    // ASSIGNMENT: Read the destination row pointer array from *a4 into v6. [source:raw]
    // GUARD: Enter the outer row loop only when the row count at this+0x110 is greater than zero. [guard:0, field:this:0x00000110, source:raw]
    // LOOP: Iterate over destination rows while the processed counter is below the row count at this+0x110. [field:this:0x00000110, source:raw]
    // CALCULATION: Compute the source row pointer for the current destination row from an offset against the destination row base. [source:raw]
    // CALCULATION: Compute the end-of-row boundary for the current destination row as its base plus the row-width value at this+0x5C. [field:this:0x0000005C, source:raw]
    // GUARD: Enter the inner duplication loop only while the current destination byte pointer is below the row-end boundary. [field:this:0x0000005C, source:raw]
    // LOOP: Write each source byte twice into consecutive destination bytes until the row-end boundary is reached. [source:raw]
    // RETURN: Return the accumulated row counter, which after the loop equals the row count at this+0x110. [source:raw, abi:lead]

    // Conservative worker pseudocode:
    //   void monochromeDoubleWidthRowBlit(int a1, int a2, int a3, _BYTE ***a4) {
    //       _BYTE **v6 = *a4;
    //       int v13 = a3 - (int)v6;
    //       int v14 = 0;
    //       while (v14 < *(int *)(a1 + 272)) {
    //           _BYTE *v8 = *v6;
    //           _BYTE *v9 = *(_BYTE **)((char *)v6 + v13);
    //           _BYTE *v10 = &v6[0][*(int *)(a1 + 92)];
    //           if ((unsigned int)v8 < (unsigned int)v10) {
    //               do { *v8++ = *v9++; *v8++ = *v9++; } while ((unsigned int)v8 < (unsigned int)v10);
    //           }
    //           ++v6;
    //           ++v14;
    //       }
    //   }
    //   
    // UNRESOLVED: Owner object type is unknown; no caller or object identity evidence in the packet.
    // UNRESOLVED: The returned value is the post-increment row counter, not the original a4; the caller's contract for this return is unknown.
    // UNRESOLVED: The purpose of parameters a2 and a3 (base/offset for the source row selection) is only structurally grounded, not semantically confirmed.
    // UNRESOLVED: The row-width field this+0x5C and row-count field this+0x110 semantics are DERIVED from the loop structure, not confirmed by an external source.
}
