// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050C2E3
// Canonical corpus name: CubicBezierInterpolation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CubicBezierInterpolation_0050c2e3.c

void UnknownObject::CubicBezierInterpolation()
{
    // Evaluates a cubic Hermite/Bezier interpolation for a 3-component vector. With parameter t=a6, computes the four standard Hermite basis coefficients (2t^3-3t^2+1, t^3-2t^2+t, -2t^3+3t^2, t^3-t^2), then blends the three components of four input vectors (a2, a3, a4, a5) into the output vector a1 (X at this+0x0, Y at this+0x4, Z at this+0x8) and returns a1. No branches, no calls, no globals touched in the raw source.
    // CALCULATION: v6 = a6 * a6; v8 = a6 * v6; square and cube the interpolation parameter t [source:raw]
    // CALCULATION: compute the four cubic Hermite basis coefficients: v10 = 2t^3 - 3t^2 + 1, v11 = t^3 - 2t^2 + t, v12 = -2t^3 + 3t^2, v9 = t^3 - t^2 [source:raw]
    // ASSIGNMENT: this+0x0 = v10*a2[0] + v11*a3[0] + v12*a4[0] + v9*a5[0]; write the blended X component of the output vector [field:this:0x00000000, source:raw]
    // ASSIGNMENT: this+0x4 = v9*a5[1] + v12*a4[1] + v11*a3[1] + v10*a2[1]; write the blended Y component of the output vector [field:this:0x00000004, source:raw]
    // ASSIGNMENT: this+0x8 = v9*a5[2] + v12*a4[2] + v11*a3[2] + v10*a2[2]; write the blended Z component of the output vector [field:this:0x00000008, source:raw]
    // RETURN: return a1; yield the output vector base pointer [function:0x0050C2E3, source:raw]

    // Conservative worker pseudocode:
    //   float h11 = a6 * a6;
    //   float h10 = a6 * (a6 * a6);
    //   float w0 = 2.0*h10 - 3.0*h11 + 1.0;
    //   float w1 = h10 - 2.0*h11 + a6;
    //   float w2 = 3.0*h11 - 2.0*h10;
    //   float w3 = h10 - h11;
    //   a1[0] = w0*a2[0] + w1*a3[0] + w2*a4[0] + w3*a5[0];
    //   a1[1] = w3*a5[1] + w2*a4[1] + w1*a3[1] + w0*a2[1];
    //   a1[2] = w3*a5[2] + w2*a4[2] + w1*a3[2] + w0*a2[2];
    //   return a1;
    // UNRESOLVED: the packet lists flt_59E43C and flt_59E478 as referenced globals, but the raw source reads and writes only its pointer arguments; the global references likely come from a stale field/global join and their role is unverified
    // UNRESOLVED: the interpolation semantics (Hermite vs Bezier) and which concrete game object supplies the four input vectors are not named by the packet
    // UNRESOLVED: whether the returned output pointer aliases a persistent vehicle-field vector is unknown; the caller graph is empty
}
