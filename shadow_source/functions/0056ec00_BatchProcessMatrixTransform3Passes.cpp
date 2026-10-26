// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0056EC00
// Canonical corpus name: BatchProcessingLoop3Passes
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BatchProcessingLoop3Passes_0056ec00.c

void UnknownObject::BatchProcessMatrixTransform3Passes()
{
    // Batch processing loop that walks three arrays of physics records on the per-frame tick. Pass one iterates the count stored at this+8 over the array base this+0xC with byte stride 48, calling F_3x3MatrixVectorMultiply on every element. Pass two iterates the count at this+16 over the array base this+0x14 with byte stride 48, calling F_3x3MatrixInverseCoordinateTransform. Pass three iterates the count at this+24 over the array base this+0x1C with byte stride 72, calling sub_56D2D0 on every element and re-reading the count each iteration. Returns the last-read third-pass count.
    // GUARD: First pass entered only when the count this+8 (this[2]) is greater than 0 [guard:0, field:this:0x00000008, source:raw]
    // LOOP: First pass iterates count this+8 elements of the array at base this+0xC (this[3]) with byte stride 48 [field:this:0x00000008, field:this:0x0000000C, source:raw]
    // CALL: Per-element 3x3 matrix-vector multiply F_3x3MatrixVectorMultiply on each record [callee:0x0056CF70, source:raw]
    // GUARD: Second pass entered only when the count this+16 (this[4]) is greater than 0 [guard:1, field:this:0x00000010, source:raw]
    // LOOP: Second pass iterates count this+16 elements of the array at base this+0x14 (this[5]) with byte stride 48 [field:this:0x00000010, field:this:0x00000014, source:raw]
    // CALL: Per-element 3x3 inverse coordinate transform F_3x3MatrixInverseCoordinateTransform on each record [callee:0x0056D020, source:raw]
    // CALCULATION: Third-pass count read from this+24 (this[6]) [field:this:0x00000018, source:raw]
    // LOOP: Third pass iterates count this+24 elements of the array at base this+0x1C (this[7]) with byte stride 72, re-reading the count from this+24 at every iteration [field:this:0x00000018, field:this:0x0000001C, source:raw]
    // CALL: Per-element constraint solve step sub_56D2D0 on each record [callee:0x0056D2D0, source:raw]
    // RETURN: Returns the third-pass count this+24 (this[6]) [field:this:0x00000018, source:raw]
    // CALL: Invoked by sub_56ECF0 (0056ECF0) [caller:0x0056ECF0, source:raw]

    // Conservative worker pseudocode:
    //   count1 = this[2];
    //   for (i = 0; i < count1; ++i) F_3x3MatrixVectorMultiply((char*)this[3] + i * 48);
    //   count2 = this[4];
    //   for (i = 0; i < count2; ++i) F_3x3MatrixInverseCoordinateTransform((char*)this[5] + i * 48);
    //   count3 = this[6];
    //   for (i = 0; i < count3; ++i) { sub_56D2D0((char*)this[7] + i * 72); count3 = this[6]; }
    //   return count3;
    // UNRESOLVED: The record stride values (48-byte and 72-byte) are derived only from the raw source pointer increments; the record layouts are undefined here
    // UNRESOLVED: The semantic purpose of each pass (matrix-vector multiply, inverse coordinate transform, constraint solve) is carried from the skeleton fill and is unverified at runtime
    // UNRESOLVED: Pass three reads the count this+24 inside its loop body, so the iteration bound can change between passes in the raw source
}
