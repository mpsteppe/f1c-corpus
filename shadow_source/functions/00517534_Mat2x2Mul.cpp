// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00517534
// Canonical corpus name: Mat2x2Mul
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/Mat2x2Mul_00517534.c

void UnknownObject::Mat2x2Mul()
{
    // 2-element row-vector times 2-column matrix product written to a 2-float output vector. Computes out[0] = a2[0]*a3[0] + a2[1]*a3[4] and out[1] = a2[0]*a3[1] + a2[1]*a3[5], where the right operand a3 is addressed with a row stride of 4 floats (columns 0 and 1 of two rows), and returns the output pointer a1. Leaves a3 values read but a3 itself unmodified.
    // CALCULATION: compute v3 = a2[0]*a3[1] + a2[1]*a3[5] and store it as the second output component [field:this:0x00000004, source:raw]
    // ASSIGNMENT: write first output component: *a1 = a2[0]*a3[0] + a2[1]*a3[4] [field:this:0x00000000, source:raw]
    // ASSIGNMENT: write second output component: a1[1] = v3 [field:this:0x00000004, source:raw]
    // RETURN: return the output pointer a1 [source:raw]

    // Conservative worker pseudocode:
    //   float* Mat2x2Mul(float* out, const float* v, const float* m) {
    //       out[0] = v[0] * m[0] + v[1] * m[4];
    //       out[1] = v[0] * m[1] + v[1] * m[5];
    //       return out;
    //   }
    // UNRESOLVED: the right operand a3 is read at elements 4 and 5 (stride 4 floats between rows); the full matrix width/layout of a3 is not established from this body alone
    // UNRESOLVED: no callers or callees in the packet, so the object owning this math routine is unknown
}
