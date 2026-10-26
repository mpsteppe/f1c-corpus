// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00522B22
// Canonical corpus name: sub_522B22
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_522B22_00522b22.c

void UnknownObject::Construct4x4IdentityMatrix3DNow()
{
    // Builds a 4x4 identity matrix in eight qword slots of a1 with 3DNow! intrinsics: slots 0 and 5 hold the 1.0f constant, slots 2 and 7 hold a punpck-reshuffled pair of 1.0f values, and slots 1, 3, 4, 6 are zeroed, placing ones on the diagonal and zeroes off it.
    // CALCULATION: Load the 1.0f constant as a 32-bit MMX value [source:raw]
    // ASSIGNMENT: Store the 1.0f value into slot 0 at offset 0 [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Zero slot 1 at offset 8 [field:this:0x00000008, source:raw]
    // CALCULATION: Build a qword containing two 1.0f words by punpck-reshuffling the loaded value [source:raw]
    // ASSIGNMENT: Store the reshuffled qword into slot 2 at offset 16 [field:this:0x00000010, source:raw]
    // ASSIGNMENT: Zero slot 3 at offset 24 [field:this:0x00000018, source:raw]
    // ASSIGNMENT: Zero slot 4 at offset 32 [field:this:0x00000020, source:raw]
    // ASSIGNMENT: Store the 1.0f value into slot 5 at offset 40 [field:this:0x00000028, source:raw]
    // ASSIGNMENT: Zero slot 6 at offset 48 [field:this:0x00000030, source:raw]
    // ASSIGNMENT: Store the reshuffled qword into slot 7 at offset 56 [field:this:0x00000038, source:raw]
    // CALL: Emit 3DNow! femms to flush the MMX state [source:raw]
    // CALL: Invoked by F_3DNowVectorTransform (00526B55) [caller:0x00526B55, source:raw]
    // RETURN: Return the output identity matrix base a1 [function:0x00522B22, source:raw]

    // Conservative worker pseudocode:
    //   v1 = 1.0f;
    //   a1[0] = v1; a1[1] = 0;
    //   v3 = punpck(1.0f words);
    //   a1[2] = v3; a1[3] = 0;
    //   a1[4] = 0; a1[5] = v1;
    //   a1[6] = 0; a1[7] = v3;
    //   femms();
    //   return a1;
    // UNRESOLVED: The packet lists qword_5AF8F0 as a referenced global but the raw source builds the identity constants inline and never reads it; its role is unverified
    // UNRESOLVED: The caller F_3DNowVectorTransform (00526B55) usage context is not visible from this function
}
