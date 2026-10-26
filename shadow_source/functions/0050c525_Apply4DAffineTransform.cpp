// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050C525
// Canonical corpus name: F_4DAffineTransform
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_4DAffineTransform_0050c525.c

void UnknownObject::Apply4DAffineTransform()
{
    // 4D affine (homogeneous) transform: multiplies a column-major 4x4 matrix (a3, 16 floats) by a 3-component input vector (a2, components 0-2 read; implicit homogeneous component 1) and writes the resulting 4-component vector (a1[0..3]) into this+0x0/+0x4/+0x8/+0xC. output.x = a3[0]*x + a3[4]*y + a3[8]*z + a3[12], and similarly rows 1-3, so column 3 of the matrix (a3[12..15]) acts as the translation/affine part. Unconditional and branchless; returns the output pointer a1.
    // CALCULATION: Compute v4 = a3[8]*a2[2] + a3[4]*a2[1] + a3[0]*a2[0] + a3[12]: output X = dot(matrix row 0, input) + translation component 0. [source:raw]
    // CALCULATION: Compute v5 = a3[9]*a2[2] + a3[5]*a2[1] + a3[1]*a2[0] + a3[13]: output Y = dot(matrix row 1, input) + translation component 1. [source:raw]
    // CALCULATION: Compute v6 = a3[10]*a2[2] + a3[6]*a2[1] + a3[2]*a2[0] + a3[14]: output Z = dot(matrix row 2, input) + translation component 2. [source:raw]
    // CALCULATION: Compute v7 = a3[11]*a2[2] + a3[7]*a2[1] + a3[3]*a2[0] + a3[15]: output W = dot(matrix row 3, input) + translation component 3 (homogeneous coordinate). [source:raw]
    // ASSIGNMENT: Store output X into *a1 = this+0x0. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Store output Y into a1[1] = this+0x4. [field:this:0x00000004, source:raw]
    // ASSIGNMENT: Store output Z into a1[2] = this+0x8. [field:this:0x00000008, source:raw]
    // ASSIGNMENT: Store output W into a1[3] = this+0xC. [field:this:0x0000000C, source:raw]
    // RETURN: Return the output vector pointer a1. [source:raw, function:0x0050C525]

    // Conservative worker pseudocode:
    //   float outX = a3[0]*a2[0] + a3[4]*a2[1] + a3[8]*a2[2] + a3[12];
    //   float outY = a3[1]*a2[0] + a3[5]*a2[1] + a3[9]*a2[2] + a3[13];
    //   float outZ = a3[2]*a2[0] + a3[6]*a2[1] + a3[10]*a2[2] + a3[14];
    //   float outW = a3[3]*a2[0] + a3[7]*a2[1] + a3[11]*a2[2] + a3[15];
    //   a1[0] = outX; a1[1] = outY; a1[2] = outZ; a1[3] = outW;
    //   return a1;
    // UNRESOLVED: Input vector a2 reads only components 0-2 (x, y, z); the fourth homogeneous component is implicitly 1 via the matrix translation column a3[12..15]. Whether callers always supply 4-component vectors is outside this packet.
    // UNRESOLVED: The column-major 4x4 layout with translation in a3[12..15] is DERIVED from the arithmetic in raw source; the packet carries no matrix type or struct definition.
    // UNRESOLVED: Arguments a2 and a3 are dereferenced but have no field evidence refs in the packet; they are treated as external float pointers.
    // UNRESOLVED: Owner object identity is not established; this (the output buffer this+0x0..+0xC) is only an ephemeral write destination.
    // UNRESOLVED: No callers or callees are evidenced in this packet; frame-path and call frequency are UNKNOWN.
}
