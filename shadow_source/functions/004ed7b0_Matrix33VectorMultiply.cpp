// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004ED7B0
// Canonical corpus name: F_33MatrixVectorMultiply
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_33MatrixVectorMultiply_004ed7b0.c

void UnknownObject::Matrix33VectorMultiply()
{
    // Multiplies a 3x3 matrix (nine floats at this, offsets 0x0..0x20) by a three-component vector a2 and stores the result in a3. Three output components are each a dot product of one matrix row with the input vector. Returns the original input vector pointer a2. Pure math utility used for rigid-body transforms; called by VehicleGeometryProximityTest and RayTriangleIntersectionWithBarycentricCoordinate.
    // ASSIGNMENT: result = a2, so the caller receives back the input vector pointer. [source:raw]
    // CALCULATION: a3[0] = this[0]*a2[0] + this[1]*a2[1] + this[2]*a2[2]: row 0 of the matrix (this+0x0, this+0x4, this+0x8) dotted with a2. [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, source:raw]
    // CALCULATION: a3[1] = this[3]*a2[0] + this[4]*a2[1] + this[5]*a2[2]: row 1 of the matrix (this+0xC, this+0x10, this+0x14) dotted with a2. [field:this:0x0000000C, field:this:0x00000010, field:this:0x00000014, source:raw]
    // CALCULATION: a3[2] = this[6]*a2[0] + this[7]*a2[1] + this[8]*a2[2]: row 2 of the matrix (this+0x18, this+0x1C, this+0x20) dotted with a2. [field:this:0x00000018, field:this:0x0000001C, field:this:0x00000020, source:raw]
    // RETURN: Return result, which is the unmodified a2 pointer. [source:raw]

    // Conservative worker pseudocode:
    //   float *sub_4ED7B0(float *m, float *v, float *out) {
    //     out[0] = m[0]*v[0] + m[1]*v[1] + m[2]*v[2];
    //     out[1] = m[3]*v[0] + m[4]*v[1] + m[5]*v[2];
    //     out[2] = m[6]*v[0] + m[7]*v[1] + m[8]*v[2];
    //     return v;
    //   }
    // UNRESOLVED: Row-major matrix layout is inferred from the index pattern; the actual storage order of the caller's 3x3 transform is not proven.
    // UNRESOLVED: Whether the 3x3 matrix is an orientation-only rotation or an upper-left sub-block of a 4x4 transform depends on the callers.
}
