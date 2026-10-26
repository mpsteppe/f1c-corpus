// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00522A6C
// Canonical corpus name: F_4x4TransformMatrixFrom3Ints
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_4x4TransformMatrixFrom3Ints_00522a6c.c

void UnknownObject::F_4x4TransformMatrixFrom3Ints()
{
    // Constructs a 4x4 diagonal scale matrix over eight qword slots in a1 from three integer inputs (a2, a3, a4) using 3DNow! intrinsics: a2 becomes the low dword of slot 0, a3 is shifted left 32 bits into the high dword of slot 2, a4 becomes the low dword of slot 5, slot 7 carries the homogeneous 1.0 constant, and slots 1, 3, 4, 6 are zeroed.
    // CALL: Emit 3DNow! femms to flush the MMX state around the pack stores [source:raw]
    // ASSIGNMENT: Store a2 as the low dword of slot 0 at offset 0 [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Zero slot 1 at offset 8 [field:this:0x00000008, source:raw]
    // CALCULATION: Shift a3 left 32 bits to place it in the high dword of slot 2 [field:this:0x00000010, source:raw]
    // ASSIGNMENT: Store the shifted a3 into slot 2 at offset 16 [field:this:0x00000010, source:raw]
    // ASSIGNMENT: Zero slot 3 at offset 24 [field:this:0x00000018, source:raw]
    // ASSIGNMENT: Zero slot 4 at offset 32 [field:this:0x00000020, source:raw]
    // ASSIGNMENT: Store a4 as the low dword of slot 5 at offset 40 [field:this:0x00000028, source:raw]
    // ASSIGNMENT: Zero slot 6 at offset 48 [field:this:0x00000030, source:raw]
    // ASSIGNMENT: Store the homogeneous 1.0 qword constant into slot 7 at offset 56 [field:this:0x00000038, source:raw]
    // RETURN: Return the output matrix base a1 [function:0x00522A6C, source:raw]

    // Conservative worker pseudocode:
    //   femms();
    //   a1[0] = a2;
    //   a1[1] = 0;
    //   a1[2] = a3 << 32;
    //   a1[3] = 0;
    //   a1[4] = 0;
    //   a1[5] = a4;
    //   a1[6] = 0;
    //   a1[7] = 1.0 qword constant;
    //   femms();
    //   return a1;
    // UNRESOLVED: The three integer inputs are interpreted as bit patterns of floats by the caller; the exact transform semantics are not documented here
    // UNRESOLVED: The packet lists qword_5AF9C0 as a referenced global but the raw source builds the constant inline and never reads it
}
