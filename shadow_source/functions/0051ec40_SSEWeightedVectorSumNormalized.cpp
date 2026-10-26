// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0051EC40
// Canonical corpus name: sub_51EC40
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_51EC40_0051ec40.c

void UnknownObject::SSEWeightedVectorSumNormalized()
{
    // SSE vector helper (stdcall): builds a weighted sum v3 = a2[0].x * a3[0] + a2[1].x * a3[1] + a3[3] where the weights are broadcast from the x-lanes of the two a2 dwords, then performs a reciprocal-based homogeneous divide (v4 = rcp(v3), v5 = v4*v4*v3, result = v3 * broadcast(v5.w)) that scales v3 so its w-component is approximately 1, stores the low 2 floats of the result to a1, and returns a1. Combines the weighted-vector-sum pattern with a translation term and a perspective/homogeneous normalization.
    // CALCULATION: Broadcast scalar weights from the x-lane of a2[0] (mask 0) and a2[1].x (mask 0) for the two weighted terms. [source:raw]
    // CALCULATION: Weighted sum v3 = a2[0].x * a3[0] + a2[1].x * a3[1] + a3[3]; the a3[3] term acts as an additive offset/translation on top of the two scaled vectors. [source:raw]
    // CALCULATION: Approximate reciprocal of the sum v4 = rcp(v3). [source:raw]
    // CALCULATION: Reciprocal refinement step v5 = v4 * v4 * v3, yielding a tighter approximation of 1 / v3. [source:raw]
    // CALCULATION: Scale the sum by the broadcast w-lane of v5 (shuffle mask 255); this homogeneous divide normalizes v3 so its w-component is approximately 1. [source:raw]
    // ASSIGNMENT: Store the low 2 floats (x,y) of the normalized result into a1. [source:raw]
    // RETURN: Return a1 as the result pointer; a direct math helper with no calls, globals, or branches. [function:0x0051EC40, abi:lead, source:raw]

    // Conservative worker pseudocode:
    //   // a2 dwords provide scalar weights from their x-lanes; a3 is a vector array
    //   v3 = a2[0].x * a3[0] + a2[1].x * a3[1] + a3[3];  // weighted sum + offset
    //   inv = rcp(v3);                                   // approximate 1/v3
    //   ref = inv * inv * v3;                            // refine reciprocal
    //   store2(a1, v3 * broadcast_w(ref));               // homogeneous divide, low 2 lanes
    //   return a1;
    // UNRESOLVED: Purpose of the a3[3] additive term (position offset vs. bias) is not established.
    // UNRESOLVED: The exact use of the refined reciprocal v5 differs from a plain rcp; the intent of normalizing the w-component to 1 depends on the caller's coordinate convention.
    // UNRESOLVED: a1 holds only 2 floats (storel); the discarded z/w lanes of the normalized result are not explained by this packet.
}
