// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005274BA
// Canonical corpus name: sub_5274BA
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_5274BA_005274ba.c

void UnknownObject::WeightedVectorLerp3DNow()
{
    // 3DNow! SIMD weighted linear interpolation between two endpoint vectors a3 and a4 using a2 as the weight vector. Builds the interpolation denominator as the lane-summed difference of the weight vector's partial dot products with the two endpoints (dot(a2, a3 - a4)), guards against a zero denominator by returning null, then interpolates the x/y lane pair and the z component of a3 toward a4 into a1. Clears MMX/3DNow! state before returning.
    // CALCULATION: Compute the lane-pair difference v5 = (a2 dot a3) - (a2 dot a4), then fold both lanes with pfacc into v7 = dot(a2, a3 - a4), the interpolation weight denominator. [source:raw]
    // GUARD: Zero-denominator guard: _m_pfcmpeq(0, v7) tests whether the accumulated weight is 0.0; when true, return null (0) and write nothing to a1. [source:raw]
    // CALCULATION: Build the refined reciprocal weight: v8 = pfrcp(v7) with pfrcpit1/pfrcpit2 Newton steps, scaled by the lane-summed numerator to form the interpolation factor t. [source:raw]
    // CALCULATION: Lerp the x/y lane pair into the output first m64 at a1[0] (this+0x0): a1[0] = a3[0] + (a4[0] - a3[0]) * t. [field:this:0x00000000, source:raw]
    // CALCULATION: Lerp the z component and store it into the low dword of a1[1] (this+0x8): a1[1] = a3[1] + (a4[1] - a3[1]) * t. [field:this:0x00000008, source:raw]
    // CALL: Clear MMX/3DNow! state with _m_femms() after the SIMD arithmetic. [source:raw]
    // RETURN: Return the output pointer a1 on the success path, or null when the denominator was zero. [function:0x005274BA, source:raw]

    // Conservative worker pseudocode:
    //   // a1..a4 are pairs of __m64 lanes viewed as 3D vectors plus a padding lane
    //   v5 = (a2[0]*a3[0] + a2[1]*a3[1].low) - (a2[0]*a4[0] + a2[1]*a4[1].low);
    //   v7 = pfacc(v5, v5);                 // dot(a2, a3 - a4)
    //   if (pfcmpeq(0, v7) low lane nonzero) return 0;
    //   t = (v11.x + v11.y) / v7;           // refined reciprocal weight
    //   a1[0]     = a3[0] + (a4[0] - a3[0]) * t;
    //   a1[1].low = a3[1].low + (a4[1].low - a3[1].low) * t;
    //   femms();
    //   return a1;
    // UNRESOLVED: The read-only global qword_5AF8F0 (0x005AF8F0) is flagged by the fact store but absent from the decompiled source, which inlines the constant 1065353216 (1.0f) instead; whether the global is the source of that constant is not verifiable here.
    // UNRESOLVED: The exact geometric meaning of the weight vector a2 (which physical component each 3DNow! lane corresponds to) is derived from lane shuffles and is not documented in the function.
    // UNRESOLVED: The upper dword of a1[1] is not written; the caller's use of the residual fourth component is unknown.
}
