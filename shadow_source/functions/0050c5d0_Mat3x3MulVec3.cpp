// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050C5D0
// Canonical corpus name: Mat3x3MulVec3
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/Mat3x3MulVec3_0050c5d0.c

void UnknownObject::Mat3x3MulVec3()
{
    // Transformed-vector computation: each output component at a1[0..2] is a three-term sum of products between nine matrix-style elements of a3 and the three input components of a2, where the i-th output component is a3[i]*a2[0] + a3[i+4]*a2[1] + a3[i+8]*a2[2]. Writes the three results into a1 and returns the output pointer a1.
    // CALCULATION: First output component: v4 = a3[8] * a2[2] + a3[4] * a2[1] + a3[0] * a2[0]. [field:this:0x00000000, source:raw]
    // CALCULATION: Second output component: v5 = a3[9] * a2[2] + a3[5] * a2[1] + a3[1] * a2[0]. [field:this:0x00000004, source:raw]
    // CALCULATION: Third output component: v6 = a3[10] * a2[2] + a3[6] * a2[1] + a3[2] * a2[0]. [field:this:0x00000008, source:raw]
    // ASSIGNMENT: Write the first output component into *a1. [field:this:0x00000000, abi:lead]
    // ASSIGNMENT: Write the second output component into a1[1]. [field:this:0x00000004, abi:lead]
    // ASSIGNMENT: Write the third output component into a1[2]. [field:this:0x00000008, abi:lead]
    // RETURN: Return the output vector pointer a1. [function:0x0050C5D0, source:raw]

    // Conservative worker pseudocode:
    //   float *sub_50C5D0(float *out, float *v, float *m) {
    //     out[0] = m[0] * v[0] + m[4] * v[1] + m[8] * v[2];
    //     out[1] = m[1] * v[0] + m[5] * v[1] + m[9] * v[2];
    //     out[2] = m[2] * v[0] + m[6] * v[1] + m[10] * v[2];
    //     return out;
    //   }
    // UNRESOLVED: Index pattern (row i uses m[i], m[i+4], m[i+8]) implies a column-major or stride-4 3x3 layout for a3, but the matrix storage order cannot be confirmed from this packet alone.
    // UNRESOLVED: this+0x0/0x4/0x8 are the three written output floats; a3 elements beyond those offsets are parameter-array accesses, not proven object fields.
}
