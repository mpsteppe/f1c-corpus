// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050C887
// Canonical corpus name: CatmullRomSplineInterpolation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CatmullRomSplineInterpolation_0050c887.c

void UnknownObject::CatmullRomSplineInterpolation()
{
    // Evaluates Catmull-Rom spline interpolation for a 4-component vector: output = 0.5 * (c0*p0 + c1*p1 + c2*p2 + c3*p3) where coefficients c0..c3 derive from parameter a6 and control points are the input pointers a2..a5. Writes four output components at this+0x0..this+0xC and returns the output pointer.
    // CALCULATION: Compute powers of parameter a6: t2 = a6 * a6 and t3 = a6 * t2. [source:raw]
    // ASSIGNMENT: c0 = t2 * 2.0 - t3 - a6 (Catmull-Rom coefficient on first control point). [source:raw]
    // ASSIGNMENT: c1 = t3 * 3.0 - t2 * 5.0 + 2.0 (Catmull-Rom coefficient on second control point). [source:raw]
    // ASSIGNMENT: c2 = t2 * 4.0 - t3 * 3.0 + a6 (Catmull-Rom coefficient on third control point). [source:raw]
    // ASSIGNMENT: c3 = t3 - t2 (Catmull-Rom coefficient on fourth control point). [source:raw]
    // ASSIGNMENT: Write output component at this+0x0 = (c0*p0[0] + c1*p1[0] + c2*p2[0] + c3*p3[0]) * 0.5. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Write output component at this+0x4 = (c0*p0[1] + c1*p1[1] + c2*p2[1] + c3*p3[1]) * 0.5. [field:this:0x00000004, source:raw]
    // ASSIGNMENT: Write output component at this+0x8 = (c0*p0[2] + c1*p1[2] + c2*p2[2] + c3*p3[2]) * 0.5. [field:this:0x00000008, source:raw]
    // ASSIGNMENT: Write output component at this+0xC = (c0*p0[3] + c1*p1[3] + c2*p2[3] + c3*p3[3]) * 0.5. [field:this:0x0000000C, source:raw]
    // RETURN: Return the output pointer (a1 / this). [source:raw]

    // Conservative worker pseudocode:
    //   float *CatmullRomSplineInterpolation(float *out, float *p0, float *p1, float *p2, float *p3, float t) {
    //     float t2 = t * t, t3 = t2 * t;
    //     float c0 = 2.0f*t2 - t3 - t;
    //     float c1 = 3.0f*t3 - 5.0f*t2 + 2.0f;
    //     float c2 = 4.0f*t2 - 3.0f*t3 + t;
    //     float c3 = t3 - t2;
    //     out[0] = 0.5f * (c0*p0[0] + c1*p1[0] + c2*p2[0] + c3*p3[0]);
    //     out[1] = 0.5f * (c0*p0[1] + c1*p1[1] + c2*p2[1] + c3*p3[1]);
    //     out[2] = 0.5f * (c0*p0[2] + c1*p1[2] + c2*p2[2] + c3*p3[2]);
    //     out[3] = 0.5f * (c0*p0[3] + c1*p1[3] + c2*p2[3] + c3*p3[3]);
    //     return out;
    //   }
    // UNRESOLVED: Five static globals (flt_59E450, flt_59E46C, flt_59E478, flt_59E7EC, flt_59E800) are recorded as read by this function, but the decompiled body is a pure local computation with no visible global loads; their role is unclear and may stem from shared floating-point constants or static attribution.
    // UNRESOLVED: Which input pointer (a2..a5) maps to which spline control point (p0..p3) is DERIVED from coefficient usage and is not independently evidenced.
}
