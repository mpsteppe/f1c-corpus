// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050F0BF
// Canonical corpus name: F_4x4MatrixReflectionTransform
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_4x4MatrixReflectionTransform_0050f0bf.c

void UnknownObject::F_4x4MatrixReflectionTransform()
{
    // Builds a 4x4 transformation matrix (a1) that applies a reflection/householder-style transform. A callee (0x0050E3DA) produces four coefficients v11..v14 (the reflection plane data); the function forms the outer-product matrix a1[i][j] = -v_i * a2[j] + (i==j ? dot(v,a2) : 0), where the dot product v4 = v11*a2[0] + v12*a2[1] + v13*a2[2] + v14*a2[3] is added only on the diagonal. Returns a1. The integer argument a3 does not appear in the body; it is consumed by the callee.
    // CALL: Call ThunkToFUN0050e3cd (0x0050E3DA), which supplies the reflection coefficients v11, v12, v13, v14 read later in the body; argument a3 is consumed inside this call. [callee:0x0050E3DA]
    // CALCULATION: Compute the dot product v4 = v11*a2[0] + v12*a2[1] + v13*a2[2] + v14*a2[3]. [source:raw]
    // CALCULATION: Negate the coefficients: v5 = -v11, v6 = -v12, v7 = -v13, v8 = -v14. [source:raw]
    // ASSIGNMENT: First output column from a2[0]: a1[0] = -v11*a2[0] + v4, a1[4] = -v12*a2[0], a1[8] = -v13*a2[0], a1[12] = -v14*a2[0]. [field:this:0x00000000, field:this:0x00000010, field:this:0x00000020, field:this:0x00000030]
    // ASSIGNMENT: Second output column from a2[1]: a1[1] = -v11*a2[1], a1[5] = -v12*a2[1] + v4, a1[9] = -v13*a2[1], a1[13] = -v14*a2[1]. [field:this:0x00000004, field:this:0x00000014, field:this:0x00000024, field:this:0x00000034]
    // ASSIGNMENT: Third output column from a2[2]: a1[2] = -v11*a2[2], a1[6] = -v12*a2[2], a1[10] = -v13*a2[2] + v4, a1[14] = -v14*a2[2]. [field:this:0x00000008, field:this:0x00000018, field:this:0x00000028, field:this:0x00000038]
    // ASSIGNMENT: Fourth output column from a2[3]: a1[3] = -v11*a2[3], a1[7] = -v12*a2[3], a1[11] = -v13*a2[3], a1[15] = -v14*a2[3] + v4. [field:this:0x0000000C, field:this:0x0000001C, field:this:0x0000002C, field:this:0x0000003C]
    // RETURN: Return the output matrix pointer a1. [source:raw]

    // Conservative worker pseudocode:
    //   float* sub_50F0BF(float* out, float* a2, int a3) {
    //     float v11, v12, v13, v14;
    //     ThunkToFUN0050e3cd(&v11, &v12, &v13, &v14, a3); /* supplies coefficients * /
    //     float v4 = v11*a2[0] + v12*a2[1] + v13*a2[2] + v14*a2[3];
    //     out[0] = -v11*a2[0] + v4;  out[4] = -v12*a2[0]; out[8] = -v13*a2[0]; out[12] = -v14*a2[0];
    //     out[1] = -v11*a2[1];       out[5] = -v12*a2[1] + v4; out[9] = -v13*a2[1]; out[13] = -v14*a2[1];
    //     out[2] = -v11*a2[2];       out[6] = -v12*a2[2]; out[10] = -v13*a2[2] + v4; out[14] = -v14*a2[2];
    //     out[3] = -v11*a2[3];       out[7] = -v12*a2[3]; out[11] = -v13*a2[3]; out[15] = -v14*a2[3] + v4;
    //     return out;
    //   }
    // UNRESOLVED: v11..v14 are used before any visible assignment in the raw body; the packet implies they are produced by callee 0x0050E3DA, but the exact calling mechanism (pointer args vs. registers/stack) is not evidenced.
    // UNRESOLVED: The role of the integer argument a3 is unknown; it does not appear in the body and is assumed passed to the callee.
    // UNRESOLVED: The semantic meaning of a2 (a single vector vs. a matrix row/column) and the exact reflection formulation are inferred from the arithmetic and the abi name; not grounded by the packet.
}
