// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0053B4C0
// Canonical corpus name: sub_53B4C0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_53B4C0_0053b4c0.c

void UnknownObject::QuaternionToRotationMatrix()
{
    // Converts a quaternion stored in this[0..3] into a 3x3 rotation matrix written to the 11-float output array a2 (columns at indices 0,1,2; 4,5,6; 8,9,10, with index 3, 7 skipped). Builds double-precision products of doubled quaternion components (v3=2*w, v4=2*x, v5=2*y) and combines them into diagonal 1.0 - sum-of-squares terms and off-diagonal cross terms. Called by sub_551210 (00551210) and PerEntityDataBlockCopyFromParameterTable (00551390).
    // CALCULATION: Double the quaternion components and form the squared products: v3 = 2*w, v4 = 2*x, v5 = 2*y, v14 = v4*this[1], v10 = v5*this[2], v11 = v5*this[0], v9 = v4*this[0], v12 = v4*this[3], v13 = v3*this[3], v6 = v3*this[0], v8 = v5*this[3], v7 = v5*this[1] [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, source:raw]
    // ASSIGNMENT: Row 0: a2[0] = 1.0 - (v10 + v14) (w*w term diagonal), a2[1] = v9 - v8, a2[2] = v12 + v11 [source:raw]
    // ASSIGNMENT: Row 1: a2[4] = v8 + v9, a2[5] = 1.0 - (v10 + v6) (y*y term diagonal), a2[6] = v7 - v13 [source:raw]
    // ASSIGNMENT: Row 2: a2[8] = v11 - v12, a2[9] = v7 + v13, a2[10] = 1.0 - (v14 + v6) (x*x term diagonal) [source:raw]
    // RETURN: Returns the output array pointer a2 to the caller [function:0x0053B4C0, source:raw]
    // CALL: Invoked by sub_551210 (00551210) and PerEntityDataBlockCopyFromParameterTable (00551390) to produce a rotation matrix from a stored orientation quaternion [caller:0x00551210, caller:0x00551390, source:raw]

    // Conservative worker pseudocode:
    //   v3 = this[0] + this[0];
    //   v4 = this[1] + this[1]; v14 = v4 * this[1];
    //   v5 = this[2] + this[2]; v10 = v5 * this[2];
    //   v11 = v5 * this[0]; v9 = v4 * this[0];
    //   v12 = v4 * this[3]; v13 = v3 * this[3];
    //   v6 = v3 * this[0]; v8 = v5 * this[3]; v7 = v5 * this[1];
    //   a2[0]  = 1.0 - (v10 + v14);
    //   a2[1]  = v9 - v8;
    //   a2[2]  = v12 + v11;
    //   a2[4]  = v8 + v9;
    //   a2[5]  = 1.0 - (v10 + v6);
    //   a2[6]  = v7 - v13;
    //   a2[8]  = v11 - v12;
    //   a2[9]  = v7 + v13;
    //   a2[10] = 1.0 - (v14 + v6);
    //   return a2;
    // UNRESOLVED: Output layout of a2 skips indices 3 and 7, which reads as a 3x3 matrix stored at stride 4; the unused slots are not written and their meaning is not defined here
    // UNRESOLVED: Read-only float global flt_59E43C (0x0059E43C) is flagged by packet facts but appears nowhere in the raw decompiled source; its role is not verifiable here
    // UNRESOLVED: The orientation coordinate convention (w/x/y/z ordering) is inferred from the matrix construction pattern only
}
