// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050D6AC
// Canonical corpus name: sub_50D6AC
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_50D6AC_0050d6ac.c

void UnknownObject::RotationMatrixZAxis()
{
    // Builds a 4x4 rotation matrix into the 16-float output buffer a1 from the angle a2. Computes v3 = cos(a2) and v4 = sin(a2), then writes the 2x2 rotation block [[v3, v4], [-v4, v3]] in the first two rows, zeros elsewhere except 1.0 at a1[10] and a1[15], and returns the input matrix pointer a1 unchanged. A standalone math helper; the prelabel identifies it as a structural twin of F_4x4MatrixMultiply (0050cbb6), cluster_copy, DERIVED.
    // CALCULATION: Compute the trigonometic coefficients: v3 = cos(a2) and v4 = sin(a2); both are used to fill the rotation sub-block. [source:raw]
    // ASSIGNMENT: Write the top-left 2x2 rotation sub-block: a1[0] = v3, a1[1] = v4, a1[4] = -v4, a1[5] = v3. [field:this:0x00000000, field:this:0x00000004, field:this:0x00000010, field:this:0x00000014]
    // ASSIGNMENT: Write the second column of the rotation block as zeros: a1[2] = 0.0, a1[3] = 0.0, a1[6] = 0.0, a1[7] = 0.0. [field:this:0x00000008, field:this:0x0000000C, field:this:0x00000018, field:this:0x0000001C]
    // ASSIGNMENT: Write the third row: a1[8] = 0.0, a1[9] = 0.0, a1[10] = 1.0, a1[11] = 0.0. [field:this:0x00000020, field:this:0x00000024, field:this:0x00000028, field:this:0x0000002C]
    // ASSIGNMENT: Write the fourth row: a1[12] = 0.0, a1[13] = 0.0, a1[14] = 0.0, a1[15] = 1.0. [field:this:0x00000030, field:this:0x00000034, field:this:0x00000038, field:this:0x0000003C]
    // RETURN: Return the input matrix pointer a1 unchanged as the result. [function:0x0050D6AC, source:raw]

    // Conservative worker pseudocode:
    //   float* RotationMatrixZAxis(float* a1, float a2) {
    //     float c = cos(a2);
    //     float s = sin(a2);
    //     a1[0] = c;  a1[1] = s;  a1[2] = 0.0f; a1[3] = 0.0f;
    //     a1[4] = -s; a1[5] = c;  a1[6] = 0.0f; a1[7] = 0.0f;
    //     a1[8] = 0.0f; a1[9] = 0.0f; a1[10] = 1.0f; a1[11] = 0.0f;
    //     a1[12] = 0.0f; a1[13] = 0.0f; a1[14] = 0.0f; a1[15] = 1.0f;
    //     return a1;
    //   }
    // UNRESOLVED: The cos/sin calls are rendered by the decompiler but the packet lists no callees, so the concrete math library implementations are not evidenced here.
    // UNRESOLVED: The axis of rotation and the row/column-major layout convention are inferred from the coefficient placement, not named by any packet evidence.
    // UNRESOLVED: The function is a standalone math helper attributed to no class; the cluster_copy twin relationship to F_4x4MatrixMultiply is DERIVED only.
}
