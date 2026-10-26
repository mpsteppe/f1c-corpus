// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0055EF88
// Canonical corpus name: F_4x4MatrixMultiply_ef88
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_4x4MatrixMultiply_ef88_0055ef88.c

void UnknownObject::MultiplyMatrix4x4()
{
    // 4x4 matrix multiply a3 = a1 * a2, row-based. Loops exactly 4 times (counter v6 seeded to 4, do-while v6-- > 1); each iteration computes one output row of 4 floats as four dot products of the current a1 row against the a2 columns (a2[0..15]), then advances a1 and a3 by 4 floats. Pure math utility with no branches, calls, globals or guards.
    // ASSIGNMENT: Initialize loop counter v6 = 4 for the four matrix rows. [source:raw]
    // LOOP: do-while row loop that executes exactly 4 iterations while v6-- > 1, processing one output row per pass. [source:raw]
    // CALCULATION: Output row column 0: *a3 = *a1 * *a2 + a1[3]*a2[12] + a1[2]*a2[8] + a1[1]*a2[4]. [source:raw]
    // CALCULATION: Output row column 1: a3[1] = *a1*a2[1] + a1[3]*a2[13] + a1[2]*a2[9] + a1[1]*a2[5]. [source:raw]
    // CALCULATION: Output row column 2: a3[2] = *a1*a2[2] + a1[3]*a2[14] + a1[2]*a2[10] + a1[1]*a2[6]. [source:raw]
    // CALCULATION: Output row column 3: a3[3] = *a1*a2[3] + a1[3]*a2[15] + a1[2]*a2[11] + a1[1]*a2[7]. [source:raw]
    // ASSIGNMENT: Advance both row pointers a1 += 4 and a3 += 4 to the next row of the first matrix and of the destination. [source:raw]
    // CALCULATION: Read the field-annotated matrix row elements at byte offsets 0x0, 0x4, 0x8, 0xC (a2[0..3]) as operands of the four column dot products. [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, source:raw]

    // Conservative worker pseudocode:
    //   void sub_55EF88(float* a1, float* a2, float* a3) {
    //     int v6 = 4;
    //     do {
    //       a3[0] = a1[0]*a2[0] + a1[1]*a2[4] + a1[2]*a2[8] + a1[3]*a2[12];
    //       a3[1] = a1[0]*a2[1] + a1[1]*a2[5] + a1[2]*a2[9] + a1[3]*a2[13];
    //       a3[2] = a1[0]*a2[2] + a1[1]*a2[6] + a1[2]*a2[10] + a1[3]*a2[14];
    //       a3[3] = a1[0]*a2[3] + a1[1]*a2[7] + a1[2]*a2[11] + a1[3]*a2[15];
    //       a1 += 4;
    //       a3 += 4;
    //     } while (v6-- > 1);
    //   }
    // UNRESOLVED: Field evidence is keyed to base 'this' with offsets 0x0..0xC, but the raw source has no this pointer; attribution of those reads to the second matrix a2[0..3] is DERIVED from the arithmetic.
    // UNRESOLVED: Matrix layout (row-major vs column-major storage of a2) and the calling semantic role of the a3 destination are not confirmed beyond the arithmetic.
    // UNRESOLVED: Called by WrapperTo55EF88 (0053b000); frame-path membership is NOT_FOUND.
}
