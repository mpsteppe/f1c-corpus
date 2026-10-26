// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050C15E
// Canonical corpus name: HermiteCubicSplineInterpolation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/HermiteCubicSplineInterpolation_0050c15e.c

void UnknownObject::HermiteCubicSplineInterpolation()
{
    // Evaluates a Catmull-Rom Hermite cubic spline for a 2-component vector. Given parameter t=a6 and four 2D control points a2..a5, computes the four Catmull-Rom basis coefficients v10 = 2t^2 - t^3 - t, v11 = 3t^3 - 5t^2 + 2, v12 = 4t^2 - 3t^3 + t and v9 = t^3 - t^2, then writes the weighted blend scaled by 0.5 into the output vector a1 (x at a1[0], y at a1[1]). A standalone math helper with no branches and no callees; the prelabel name is retained.
    // CALCULATION: Compute the Catmull-Rom basis coefficients from t=a6: v10 = 2t^2 - t^3 - t, v11 = 3t^3 - 5t^2 + 2, v12 = 4t^2 - 3t^3 + t, v9 = t^3 - t^2. [source:raw]
    // ASSIGNMENT: Write the interpolated X component: a1[0] = 0.5 * (v10 * a2[0] + v11 * a3[0] + v12 * a4[0] + v9 * a5[0]). [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Write the interpolated Y component: a1[1] = 0.5 * (v9 * a5[1] + v12 * a4[1] + v11 * a3[1] + v10 * a2[1]). [field:this:0x00000004, source:raw]
    // RETURN: Return the output vector pointer a1 unchanged. [function:0x0050C15E, source:raw]

    // Conservative worker pseudocode:
    //   float* HermiteCubicSplineInterpolation(float* a1, float* a2, float* a3, float* a4, float* a5, float t) {
    //     float t2 = t * t;
    //     float t3 = t2 * t;
    //     float c0 = 2.0f*t2 - t3 - t;
    //     float c1 = 3.0f*t3 - 5.0f*t2 + 2.0f;
    //     float c2 = 4.0f*t2 - 3.0f*t3 + t;
    //     float c3 = t3 - t2;
    //     a1[0] = 0.5f * (c0*a2[0] + c1*a3[0] + c2*a4[0] + c3*a5[0]);
    //     a1[1] = 0.5f * (c3*a5[1] + c2*a4[1] + c1*a3[1] + c0*a2[1]);
    //     return a1;
    //   }
    // UNRESOLVED: The packet lists five read-only globals (flt_59E450 0x0059E450, flt_59E46C 0x0059E46C, flt_59E478 0x0059E478, flt_59E7EC 0x0059E7EC, flt_59E800 0x0059E800) but the raw source shows no explicit global loads; they are likely constants folded into the spline literals, but which literal each backs is not pinned by the packet.
    // UNRESOLVED: The DERIVED names in the skeleton fill (DegreesToRadians, TireSlipOffset, SteeringCenterBoost, ZeroConstant, AmplitudeLimit) are not supported by this packet's evidence and are not used here.
    // UNRESOLVED: Input vectors a2..a5 are read but the packet only evidences the output fields (this 0x0, this 0x4).
}
