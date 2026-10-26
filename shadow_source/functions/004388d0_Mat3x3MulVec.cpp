// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004388D0
// Canonical corpus name: Mat3x3MulVec
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/Mat3x3MulVec_004388d0.c

void UnknownObject::Mat3x3MulVec()
{
    // Multiplies a 3x3 matrix (the this object, 9 doubles at offsets 0x0..0x40, indexed this[0]..this[8]) by a 3-element input vector a2 (a2[0..2]) and stores the result into the output vector a3 (a3[0..2]). Row 0 reads this[0]/this[3]/this[6], row 1 reads this[1]/this[4]/this[7], row 2 reads this[2]/this[5]/this[8]. Returns the input vector pointer a2. Structural twin of the Matrix3x3VectorMultiply cluster representative per the cluster prelabel.
    // CALCULATION: Row 0 of the product: a3[0] = this[6] * a2[2] + this[3] * a2[1] + a2[0] * this[0], i.e. matrix elements at this+0x30, this+0x18, this+0x00 times vector components a2[2]/a2[1]/a2[0]. [field:this:0x00000030, field:this:0x00000018, field:this:0x00000000, source:raw]
    // CALCULATION: Row 1 of the product: a3[1] = this[1] * a2[0] + this[7] * a2[2] + this[4] * a2[1], i.e. matrix elements at this+0x08, this+0x38, this+0x20 times vector components a2[0]/a2[2]/a2[1]. [field:this:0x00000008, field:this:0x00000038, field:this:0x00000020, source:raw]
    // CALCULATION: Row 2 of the product: a3[2] = this[2] * a2[0] + this[8] * a2[2] + this[5] * a2[1], i.e. matrix elements at this+0x10, this+0x40, this+0x28 times vector components a2[0]/a2[2]/a2[1]. [field:this:0x00000010, field:this:0x00000040, field:this:0x00000028, source:raw]
    // RETURN: Return the input vector pointer a2 (the caller-visible result; Hex-Rays result alias). [function:0x004388D0, source:raw]

    // Conservative worker pseudocode:
    //   out[0] = m[0][0]*v[0] + m[0][1]*v[1] + m[0][2]*v[2];
    //   out[1] = m[1][0]*v[0] + m[1][1]*v[1] + m[1][2]*v[2];
    //   out[2] = m[2][0]*v[0] + m[2][1]*v[1] + m[2][2]*v[2];
    //   return v;
    // UNRESOLVED: Matrix layout (row-major vs column-major) is not distinguishable from a single 3x3 usage; the description assumes the this[0..8] indexing order shown by the .c.
    // UNRESOLVED: The a2/a3 vector pointer bases are not enumerated among the packet fields; the output vector a3 is written but only matrix fields are tracked.
    // UNRESOLVED: No callees, globals, or guards to corroborate the matrix/vector role beyond the twin-function prelabel (DERIVED).
}
