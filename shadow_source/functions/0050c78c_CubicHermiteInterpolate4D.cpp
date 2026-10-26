// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050C78C
// Canonical corpus name: sub_50C78C
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_50C78C_0050c78c.c

void UnknownObject::CubicHermiteInterpolate4D()
{
    // Evaluates a cubic Hermite interpolation of a 4-component vector. Computes the four cubic Hermite basis coefficients from parameter t=a6 (h00=2t^3-3t^2+1, h10=t^3-2t^2+t, h01=3t^2-2t^3, h11=t^3-t^2) and writes each output component of a1 as the weighted sum of the corresponding input components of a2..a5, returning a1.
    // CALCULATION: Compute the cubic Hermite basis coefficients from t=a6: h00=2t^3-3t^2+1 (v9), h10=t^3-2t^2+t (v10), h01=3t^2-2t^3 (v11), h11=t^3-t^2 (v12). [source:raw]
    // ASSIGNMENT: Write output component this+0x0 (a1[0]) = h00*a2[0] + h10*a3[0] + h01*a4[0] + h11*a5[0]. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Write output component this+0x4 (a1[1]) = h11*a5[1] + h01*a4[1] + h10*a3[1] + h00*a2[1]. [field:this:0x00000004, source:raw]
    // ASSIGNMENT: Write output component this+0x8 (a1[2]) = h11*a5[2] + h01*a4[2] + h10*a3[2] + h00*a2[2]. [field:this:0x00000008, source:raw]
    // ASSIGNMENT: Write output component this+0xC (a1[3]) = h11*a5[3] + h01*a4[3] + h10*a3[3] + h00*a2[3]. [field:this:0x0000000C, source:raw]
    // RETURN: Return the output buffer pointer a1. [source:raw]

    // Conservative worker pseudocode:
    //   float* CubicHermiteInterpolate4D(float* a1, float* a2, float* a3, float* a4, float* a5, float t) {
    //     float t2 = t * t;
    //     float t3 = t2 * t;
    //     float h00 = 2*t3 - 3*t2 + 1;
    //     float h10 = t3 - 2*t2 + t;
    //     float h01 = 3*t2 - 2*t3;
    //     float h11 = t3 - t2;
    //     a1[0] = h00*a2[0] + h10*a3[0] + h01*a4[0] + h11*a5[0];
    //     a1[1] = h00*a2[1] + h10*a3[1] + h01*a4[1] + h11*a5[1];
    //     a1[2] = h00*a2[2] + h10*a3[2] + h01*a4[2] + h11*a5[2];
    //     a1[3] = h00*a2[3] + h10*a3[3] + h01*a4[3] + h11*a5[3];
    //     return a1;
    //   }
    // UNRESOLVED: flt_59E43C and flt_59E478 are listed as read globals but do not appear in the raw body; they are likely consumed by an inlined subexpression or an earlier caller.
    // UNRESOLVED: Which four input points a2..a5 represent (e.g. keyframe values vs. tangents) and the interpolation domain of t are not grounded by the packet.
}
