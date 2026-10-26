// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050E760
// Canonical corpus name: F_4ComponentVector43MatrixTransform
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_4ComponentVector43MatrixTransform_0050e760.c

void UnknownObject::F_4ComponentVector43MatrixTransform()
{
    // Straight-line affine transform of a 2-component input vector (a2, only elements 0 and 1 consumed) by a 4x4 matrix (a3), producing a 4-component output vector stored to a1 (elements 0..3). With a3 read row-major and the input treated as [x, y, 0, 1], the math matches a row-vector matrix multiply out = [x, y, 0, 1] * a3: out[0] = x*a3[0] + y*a3[4] + a3[12], out[1] = x*a3[1] + y*a3[5] + a3[13], out[2] = x*a3[2] + y*a3[6] + a3[14], out[3] = x*a3[3] + y*a3[7] + a3[15]. Columns 2 of the matrix and component z of the vector are unused, consistent with a 2D affine transform embedded in 4D homogeneous space. Returns a1. No branches, calls, globals, or guards.
    // CALCULATION: v4 = a3[0]*a2[0] + a3[4]*a2[1] + a3[12] (result component 0; x*a3 col0 + y*a3 col1 + a3 col3, row-vector affine convention) [source:raw]
    // CALCULATION: v5 = a3[1]*a2[0] + a3[5]*a2[1] + a3[13] (result component 1) [source:raw]
    // CALCULATION: v6 = a3[2]*a2[0] + a3[6]*a2[1] + a3[14] (result component 2) [source:raw]
    // CALCULATION: v7 = a3[3]*a2[0] + a3[7]*a2[1] + a3[15] (result component 3; note a3 rows 2 and 3 of the matrix columns, i.e. a3[8..11], are never read) [source:raw]
    // ASSIGNMENT: Store v4 to output element 0 at this+0x0 [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Store v5 to output element 1 at this+0x4 [field:this:0x00000004, source:raw]
    // ASSIGNMENT: Store v6 to output element 2 at this+0x8 [field:this:0x00000008, source:raw]
    // ASSIGNMENT: Store v7 to output element 3 at this+0xC [field:this:0x0000000C, source:raw]
    // RETURN: Return a1 (the output vector pointer) as the function result [function:0x0050E760, source:raw]

    // Conservative worker pseudocode:
    //   out[0] = a3[0]*in[0] + a3[4]*in[1] + a3[12];
    //   out[1] = a3[1]*in[0] + a3[5]*in[1] + a3[13];
    //   out[2] = a3[2]*in[0] + a3[6]*in[1] + a3[14];
    //   out[3] = a3[3]*in[0] + a3[7]*in[1] + a3[15];
    //   return out;
    // UNRESOLVED: Exact storage layout of a3 (row-major vs column-major) is not proven by the raw source alone; the row-vector interpretation above is DERIVED and matches the structural twin F_4DAffineTransform (0050c525).
    // UNRESOLVED: Whether a1, a2, a3 are fields of a single class or independent pointer arguments is unproven (no owner evidence).
    // UNRESOLVED: Semantic role of the result (position transform vs other affine usage) is unproven; canonical name and prelabel suggest a 4-component vector / 4x3-matrix transform.
}
