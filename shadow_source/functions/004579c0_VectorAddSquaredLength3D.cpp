// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004579C0
// Canonical corpus name: EmptyStub
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/EmptyStub_004579c0.c

void UnknownObject::VectorAddSquaredLength3D()
{
    // Element-wise adds two 3D vectors and returns the squared length of the sum. Reads X/Y/Z from this+0x7C (this[31]), this+0x80 (this[32]) and this+0x84 (this[33]) and adds a2[0], a2[1], a2[2] respectively, then returns v3*v3 + v2*v2 + v4*v4 (sum of squares, no square root). Pure computation with no branches, guards, globals or callees; called by MinimumDistanceSearch (0x0040ACD0) and ShortComputation (0x0040B630).
    // CALCULATION: Compute v4 = this[31] (this+0x7C) + a2[0], the X component of the summed vector. [field:this:0x0000007C, source:raw]
    // CALCULATION: Compute v2 = this[32] (this+0x80) + a2[1], the Y component of the summed vector. [field:this:0x00000080, source:raw]
    // CALCULATION: Compute v3 = this[33] (this+0x84) + a2[2], the Z component of the summed vector. [field:this:0x00000084, source:raw]
    // CALCULATION: Return the squared length of the summed vector: v3*v3 + v2*v2 + v4*v4. [abi:lead, source:raw]
    // CALL: Invoked from MinimumDistanceSearch (0x0040ACD0) and ShortComputation (0x0040B630), consistent with distance-squared use. [caller:0x0040ACD0, caller:0x0040B630]

    // Conservative worker pseudocode:
    //   double VectorAddSquaredLength3D(float* this, float* a2) {
    //     double v4 = this[31] + a2[0];  // this+0x7C
    //     double v2 = this[32] + a2[1];  // this+0x80
    //     double v3 = this[33] + a2[2];  // this+0x84
    //     return v3 * v3 + v2 * v2 + v4 * v4;
    //   }
    // UNRESOLVED: The interpretation of the sum as a geometric distance computation ('squared Euclidean distance') is DERIVED from existing analysis prose; the raw source proves only the element-wise add and sum-of-squares return.
}
