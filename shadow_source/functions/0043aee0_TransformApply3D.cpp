// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0043AEE0
// Canonical corpus name: TransformApply3D
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TransformApply3D_0043aee0.c

void UnknownObject::TransformApply3D()
{
    // Applies a 3D affine transform to a 3-vector: this is a 3x3 matrix of doubles (row-major, offsets +0x0..+0x40) with a2 the translation vector and a3 the input vector. Computes v4 = row1 dot a3 and v6 = row2 dot a3, then writes a4[0] = row0 dot a3 + a2[0], a4[1] = v4 + a2[1], a4[2] = v6 + a2[2], i.e. a4 = this*a3 + a2. Returns the translation vector pointer a2. Pure coordinate-transform helper with no branches, globals, or callees; structural twin of Matrix3x3VectorMultiply with translation added; on frame path and used by vehicle physics setup/integration callers.
    // CALCULATION: v4 = this[3]*a3[0] + this[4]*a3[1] + this[5]*a3[2] (matrix row 1, offsets +0x18/+0x20/+0x28). [field:this:0x00000018, field:this:0x00000020, field:this:0x00000028, source:raw]
    // ASSIGNMENT: Set result = a2 (the return value is the translation vector pointer). [source:raw]
    // CALCULATION: v6 = this[6]*a3[0] + this[7]*a3[1] + this[8]*a3[2] (matrix row 2, offsets +0x30/+0x38/+0x40). [field:this:0x00000030, field:this:0x00000038, field:this:0x00000040, source:raw]
    // CALCULATION: a4[0] = this[0]*a3[0] + this[1]*a3[1] + this[2]*a3[2] + a2[0] (matrix row 0, offsets +0x0/+0x8/+0x10, plus translation x). [field:this:0x00000000, field:this:0x00000008, field:this:0x00000010, source:raw]
    // CALCULATION: a4[1] = v4 + a2[1] (row 1 result plus translation y). [source:raw]
    // CALCULATION: a4[2] = v6 + a2[2] (row 2 result plus translation z). [source:raw]
    // RETURN: Return result (the translation vector pointer a2). [source:raw]

    // Conservative worker pseudocode:
    //   double* TransformApply3D(double* this, double* a2, double* a3, double* a4) {
    //     double v4 = this[3]*a3[0] + this[4]*a3[1] + this[5]*a3[2];
    //     double* result = a2;
    //     double v6 = this[6]*a3[0] + this[7]*a3[1] + this[8]*a3[2];
    //     a4[0] = this[0]*a3[0] + this[1]*a3[1] + this[2]*a3[2] + a2[0];
    //     a4[1] = v4 + a2[1];
    //     a4[2] = v6 + a2[2];
    //     return result;
    //   }
    // UNRESOLVED: The exact semantics of the 3x3 matrix block (pure rotation vs combined scale/rotation) are not verified; treated as a linear transform.
    // UNRESOLVED: The owner class is unknown; no owning class is evidenced in the packet.
    // UNRESOLVED: The purpose of returning the translation vector a2 in the caller context is unknown.
}
