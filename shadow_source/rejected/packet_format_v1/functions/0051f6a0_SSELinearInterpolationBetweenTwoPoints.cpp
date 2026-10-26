// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0051F6A0
// Canonical corpus name: SSELinearInterpolationBetweenTwoPoints
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SSELinearInterpolationBetweenTwoPoints_0051f6a0.c

void UnknownObject::SSELinearInterpolationBetweenTwoPoints()
{
    // SSE helper performing a weighted interpolation across three input points: loads a2 as the base, then computes base + (a3 - base)*a5 + (a4 - base)*a6, stores the packed result into output a1, and returns a1.
    // CALCULATION: Load packed a2 into SSE register v6 (upper lanes) as the base. [source:raw]
    // CALCULATION: Compute (a3 - v6) and scale by a5 via SSE sub, mul and shuffle-0 broadcast. [source:raw]
    // CALCULATION: Compute (a4 - v6) and scale by a6 via SSE sub, mul and shuffle-0 broadcast. [source:raw]
    // CALCULATION: Add both scaled deltas to base v6 to produce the interpolated result. [source:raw]
    // ASSIGNMENT: Store the packed result into output a1 via SSE store-high. [source:raw]
    // RETURN: Return output pointer a1. [function:0x0051F6A0]

    // Conservative worker pseudocode:
    //   v6 = _mm_loadh_ps(a2);
    //   result = v6 + (a3 - v6) * a5 + (a4 - v6) * a6;
    //   _mm_storeh_ps(a1, result);
    //   return a1;
}
