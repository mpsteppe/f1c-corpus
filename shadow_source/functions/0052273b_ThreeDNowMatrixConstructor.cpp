// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0052273B
// Canonical corpus name: F_3DNowMatrixConstructor
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_3DNowMatrixConstructor_0052273b.c

void UnknownObject::ThreeDNowMatrixConstructor()
{
    // Builds a 4x4 transformation matrix stored as 8 __m64 slots (each 8 bytes = two floats) in a1. Enters 3DNow mode, seeds the matrix with identity-like constants (1.0f at this+0x0 and this+0x28, packed 1.0f/1.0f at this+0x10), then packs the three float parameters a2, a3, a4 into the last two rows: this+0x30 receives punpckldq(a2, a3) and this+0x38 receives punpckldq(a4, 1.0f), forming the translation-plus-homogeneous row. Exits 3DNow mode and returns a1.
    // CALL: Enter 3DNow mode with _m_femms() to reset the MMX/3DNow state before SIMD writes [source:raw]
    // ASSIGNMENT: Seed the matrix with identity-like constants drawn from the read-only SIMD constant globals qword_5AF9C0 and qword_5AF9C8: this+0x0 = 1065353216 (1.0f), this+0x8 = 0, this+0x10 = 0x3F80000000000000LL (1.0f pair), this+0x18 = 0, this+0x20 = 0, this+0x28 = 1065353216 (1.0f) [field:this:0x00000000, field:this:0x00000008, field:this:0x00000010, field:this:0x00000018, field:this:0x00000020, field:this:0x00000028, global:0x005AF9C0, global:0x005AF9C8, source:raw]
    // CALCULATION: Build the translation row at this+0x30 by unpacking the low dwords of a2 and a3 with _m_punpckldq, giving (X, Y) in the first two float cells [field:this:0x00000030, source:raw]
    // CALCULATION: Build the final row at this+0x38 by unpacking a4 with the constant 1065353216 (1.0f) using _m_punpckldq, giving (Z, homogeneous 1.0) [field:this:0x00000038, source:raw]
    // CALL: Exit 3DNow mode with _m_femms() after the matrix writes are complete [source:raw]
    // RETURN: Return a1, the fully constructed 4x4 matrix [function:0x0052273B, source:raw]

    // Conservative worker pseudocode:
    //   femms();
    //   m[0] = 1065353216; m[1] = 0;
    //   m[2] = 0x3F80000000000000LL; m[3] = 0;
    //   m[4] = 0; m[5] = 1065353216;
    //   m[6] = punpckldq(a2, a3);
    //   m[7] = punpckldq(a4, 1065353216);
    //   femms();
    //   return m;
    // UNRESOLVED: The exact association between the two SIMD constant globals qword_5AF9C0 / qword_5AF9C8 and each specific literal (1065353216 vs 0x3F80000000000000LL) is not evidenced; the raw source inlines the constants
    // UNRESOLVED: The float meaning of the packed components a2/a3/a4 (translation vs orientation) is inferred from the homogeneous row layout, not evidenced in this packet
}
