// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050C0A6
// Canonical corpus name: sub_50C0A6
// Owner: MathUtil [DERIVED]
// Raw source: functions/sub_50C0A6_0050c0a6.c

void MathUtil::cubicHermiteInterpolate2D()
{
    // Evaluates a 2-component cubic Hermite spline interpolation. Builds the four standard Hermite basis functions from the parameter t=a6 (h00=2t^3-3t^2+1, h10=t^3-2t^2+t, h01=3t^2-2t^3, h11=t^3-t^2), then blends two 2D endpoint/tangent pairs held in a2..a5 into the output vector a1. No branches, no callees.
    // CALCULATION: Compute t^2 (v6 = a6 * a6). [source:raw]
    // CALCULATION: Compute t^3 (v8 = a6 * v6). [source:raw]
    // CALCULATION: Compute Hermite basis h00 (v10) = 2*t^3 - 3*t^2 + 1. [source:raw]
    // CALCULATION: Compute Hermite basis h10 (v11) = t^3 - 2*t^2 + t. [source:raw]
    // CALCULATION: Compute Hermite basis h01 (v12) = 3*t^2 - 2*t^3. [source:raw]
    // CALCULATION: Compute Hermite basis h11 (v9) = t^3 - t^2. [source:raw]
    // ASSIGNMENT: Write output X component at this+0x0: *a1 = h00*a2[0] + h10*a3[0] + h01*a4[0] + h11*a5[0]. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Write output Y component at this+0x4: a1[1] = h11*a5[1] + h01*a4[1] + h10*a3[1] + h00*a2[1]. [field:this:0x00000004, source:raw]
    // RETURN: Return the output pointer a1. [source:raw]

    // Conservative worker pseudocode:
    //   float *cubicHermiteInterpolate2D(float *out, float *p0, float *m0, float *p1, float *m1, float t) {
    //       float t2 = t * t;
    //       float t3 = t * t2;
    //       float h00 = 2.0f * t3 - 3.0f * t2 + 1.0f;
    //       float h10 = t3 - 2.0f * t2 + t;
    //       float h01 = 3.0f * t2 - 2.0f * t3;
    //       float h11 = t3 - t2;
    //       out[0] = h00 * p0[0] + h10 * m0[0] + h01 * p1[0] + h11 * m1[0];
    //       out[1] = h00 * p0[1] + h10 * m0[1] + h01 * p1[1] + h11 * m1[1];
    //       return out;
    //   }
    // UNRESOLVED: Endpoint/tangent roles of a2..a5 are DERIVED from the Hermite basis structure; the source does not name them.
    // UNRESOLVED: Interpolation parameter a6 being t in [0,1] is DERIVED, not stated.
    // UNRESOLVED: This is a pure math helper with no recovered callers and no static path from the tick root; call context unknown.
    // UNRESOLVED: No structural class evidence ties this to a vehicle or game object; owner MathUtil is a DERIVED convenience label.
}
