// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050E634
// Canonical corpus name: F_44Matrix4VectorMultiply
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_44Matrix4VectorMultiply_0050e634.c

void UnknownObject::F_44Matrix4VectorMultiply()
{
    // Multiplies a 16-element 4x4 matrix a3 by a 4-component vector a2 and writes the four result components to the output vector a1, returning a1. Straight-line computation of four dot products (one per output component) with no branches or calls.
    // CALCULATION: v4 = a2[0]*a3[0] + a2[1]*a3[4] + a2[2]*a3[8] + a2[3]*a3[12] (dot product of vector a2 with matrix row 0) [source:raw]
    // CALCULATION: v5 = a2[0]*a3[1] + a2[1]*a3[5] + a2[2]*a3[9] + a2[3]*a3[13] (dot product of vector a2 with matrix row 1) [source:raw]
    // CALCULATION: v6 = a2[0]*a3[2] + a2[1]*a3[6] + a2[2]*a3[10] + a2[3]*a3[14] (dot product of vector a2 with matrix row 2) [source:raw]
    // CALCULATION: v7 = a2[0]*a3[3] + a2[1]*a3[7] + a2[2]*a3[11] + a2[3]*a3[15] (dot product of vector a2 with matrix row 3) [source:raw]
    // ASSIGNMENT: a1[0] = v4; write result component 0 to output vector first element [field:this:0x00000000]
    // ASSIGNMENT: a1[1] = v5; write result component 1 to output vector second element [field:this:0x00000004]
    // ASSIGNMENT: a1[2] = v6; write result component 2 to output vector third element [field:this:0x00000008]
    // ASSIGNMENT: a1[3] = v7; write result component 3 to output vector fourth element [field:this:0x0000000C]
    // RETURN: return a1 (pointer to the output vector) [function:0x0050E634]

    // Conservative worker pseudocode:
    //   v4 = a2[0]*a3[0] + a2[1]*a3[4] + a2[2]*a3[8] + a2[3]*a3[12];
    //   v5 = a2[0]*a3[1] + a2[1]*a3[5] + a2[2]*a3[9] + a2[3]*a3[13];
    //   v6 = a2[0]*a3[2] + a2[1]*a3[6] + a2[2]*a3[10] + a2[3]*a3[14];
    //   v7 = a2[0]*a3[3] + a2[1]*a3[7] + a2[2]*a3[11] + a2[3]*a3[15];
    //   a1[0] = v4; a1[1] = v5; a1[2] = v6; a1[3] = v7;
    //   return a1;
    // UNRESOLVED: a3 treated as a 16-float 4x4 matrix (indices 0..15); exact storage convention (row-major versus column-major) is not resolved by the packet evidence
    // UNRESOLVED: aliasing of a1 with a2 or a3 is not asserted; all four components are computed before any write so in-place operation would be safe, but it is not evidenced
}
