// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050F199
// Canonical corpus name: sub_50F199
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_50F199_0050f199.c

void UnknownObject::QuaternionToTransformMatrix()
{
    // Builds a 4x4 column-major transformation matrix into the 16-float buffer a1 from four local parameters v6..v9 produced by a preliminary call to ThunkToFUN0050e3cd. The rotation sub-block uses quadratic products of v6, v7, v8 (1 - 2*axis^2 on the diagonal, -2*axis_a*axis_b off-diagonal), the translation row uses -2*product terms scaled by v9, and the final row is [0,0,0,1]. The input matrix pointer is returned unchanged.
    // CALL: Preliminary call to ThunkToFUN0050e3cd populates the four stack parameters v6, v7, v8, v9 consumed below [callee:0x0050E3DA, source:raw]
    // CALCULATION: Compute doubled negative scale factors: v2 = v6 * -2.0, v4 = v7 * -2.0, v5 = v8 * -2.0 [source:raw]
    // ASSIGNMENT: Write matrix rows 0-2 columns 0-2 (rotation): a1[0] = v6*v2 + 1.0, a1[1] = v4*v6, a1[2] = v5*v6, a1[4] = v7*v2, a1[5] = v7*v4 + 1.0, a1[6] = v5*v7, a1[8] = v8*v2, a1[9] = v8*v4, a1[10] = v8*v5 + 1.0 [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, field:this:0x00000010, field:this:0x00000014, field:this:0x00000018, field:this:0x00000020, field:this:0x00000024, field:this:0x00000028, source:raw]
    // ASSIGNMENT: Write the third-column zeros: a1[3] = 0.0, a1[7] = 0.0, a1[11] = 0.0 [field:this:0x0000000C, field:this:0x0000001C, field:this:0x0000002C, source:raw]
    // ASSIGNMENT: Write the translation row: a1[12] = v9*v2, a1[13] = v9*v4, a1[14] = v9*v5, and the homogeneous final element a1[15] = 1.0 [field:this:0x00000030, field:this:0x00000034, field:this:0x00000038, field:this:0x0000003C, source:raw]
    // RETURN: Return the input matrix pointer a1 unchanged as the result [function:0x0050F199, source:raw]

    // Conservative worker pseudocode:
    //   ThunkToFUN0050e3cd();
    //   v2 = v6 * -2.0; v4 = v7 * -2.0; v5 = v8 * -2.0;
    //   a1[0] = v6*v2 + 1.0;  a1[1] = v4*v6;   a1[2] = v5*v6;   a1[3] = 0.0;
    //   a1[4] = v7*v2;        a1[5] = v7*v4 + 1.0; a1[6] = v5*v7; a1[7] = 0.0;
    //   a1[8] = v8*v2;        a1[9] = v8*v4;   a1[10] = v8*v5 + 1.0; a1[11] = 0.0;
    //   a1[12] = v9*v2;       a1[13] = v9*v4;  a1[14] = v9*v5;  a1[15] = 1.0;
    //   return a1;
    // UNRESOLVED: The four parameters v6..v9 are written by the preliminary thunk call into this function's stack frame, so their concrete values and whether they represent a quaternion or axis-angle decomposition are not observable in this function alone
    // UNRESOLVED: Two read-only float globals flt_59E43C (0x0059E43C) and flt_59E7F0 (0x0059E7F0) are flagged by packet facts but appear nowhere in the raw decompiled source; their role is not verifiable here
    // UNRESOLVED: The matrix is column-major inferred from the assignment layout; the source does not name the convention
}
