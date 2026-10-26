// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050C3BB
// Canonical corpus name: sub_50C3BB
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_50C3BB_0050c3bb.c

void UnknownObject::CatmullRomInterpolate3D()
{
    // Evaluates a Catmull-Rom spline interpolation at parameter a6 for a 3-component vector. Computes the four Catmull-Rom basis coefficients from powers of a6, blends the four control vectors a2..a5 (each with 3 components) and writes the result into a1[0..2]. Unconditional; no branches, no global reads.
    // CALCULATION: Compute t-squared: v6 = a6 * a6. [source:raw]
    // CALCULATION: Compute t-cubed: v8 = a6 * v6. [source:raw]
    // CALCULATION: Catmull-Rom basis coefficient for control point 0 (a2): v10 = 2*t2 - t3 - t. [source:raw]
    // CALCULATION: Catmull-Rom basis coefficient for control point 1 (a3): v11 = 3*t3 - 5*t2 + 2. [source:raw]
    // CALCULATION: Catmull-Rom basis coefficient for control point 2 (a4): v12 = 4*t2 - 3*t3 + t. [source:raw]
    // CALCULATION: Catmull-Rom basis coefficient for control point 3 (a5): v9 = t3 - t2. [source:raw]
    // ASSIGNMENT: Write interpolated X: a1[0] = 0.5 * (v10*a2[0] + v11*a3[0] + v12*a4[0] + v9*a5[0]). [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Write interpolated Y: a1[1] = 0.5 * (v9*a5[1] + v12*a4[1] + v11*a3[1] + v10*a2[1]). [field:this:0x00000004, source:raw]
    // ASSIGNMENT: Write interpolated Z: a1[2] = 0.5 * (v9*a5[2] + v12*a4[2] + v11*a3[2] + v10*a2[2]). [field:this:0x00000008, source:raw]
    // RETURN: Return the output pointer a1 (result). [source:raw]

    // Conservative worker pseudocode:
    //   float *CatmullRomInterpolate3D(float *out, const float *p0, const float *p1,
    //                                  const float *p2, const float *p3, float t) {
    //     double t2 = t * t, t3 = t * t2;
    //     double c0 = 2*t2 - t3 - t;
    //     double c1 = 3*t3 - 5*t2 + 2;
    //     double c2 = 4*t2 - 3*t3 + t;
    //     double c3 = t3 - t2;
    //     out[0] = 0.5f * (c0*p0[0] + c1*p1[0] + c2*p2[0] + c3*p3[0]);
    //     out[1] = 0.5f * (c3*p3[1] + c2*p2[1] + c1*p1[1] + c0*p0[1]);
    //     out[2] = 0.5f * (c3*p3[2] + c2*p2[2] + c1*p1[2] + c0*p0[2]);
    //     return out;
    //   }
    // UNRESOLVED: Caller context unknown; the identity of the four control vectors a2..a5 and the parameter source a6 are caller-defined.
    // UNRESOLVED: Packet lists five globals (flt_59E450, flt_59E46C, flt_59E478, flt_59E7EC, flt_59E800) but the raw source reads no globals; the attribution appears inherited from skeleton cross-reference data rather than from this function's body.
}
