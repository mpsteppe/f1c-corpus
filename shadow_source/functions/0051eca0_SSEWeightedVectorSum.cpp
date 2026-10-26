// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0051ECA0
// Canonical corpus name: SSEWeightedVectorSum
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SSEWeightedVectorSum_0051eca0.c

void UnknownObject::SSEWeightedVectorSum()
{
    // SSE vector helper (stdcall): computes a weighted vector sum v = a2[0].x * a3[0] + a2[1].x * a3[1] where the two scalar weights are broadcast from the x-lanes of the a2 dwords, stores the low 2 floats of the result to a1, and returns a1. Straightforward blend/interpolation helper with no branches, calls, or globals.
    // CALCULATION: Broadcast scalar weights from the x-lane of a2[0] (mask 0) and a2[1].x (mask 0). [source:raw]
    // CALCULATION: Weighted sum v = a2[0].x * a3[0] + a2[1].x * a3[1]; each weight scales its corresponding vector before the vectors are added. [source:raw]
    // ASSIGNMENT: Store the low 2 floats (x,y) of the weighted sum into a1. [source:raw]
    // RETURN: Return a1 as the result pointer. [function:0x0051ECA0, abi:lead, source:raw]

    // Conservative worker pseudocode:
    //   // a2 dwords provide scalar weights from their x-lanes; a3 is a vector array
    //   v = a2[0].x * a3[0] + a2[1].x * a3[1];  // weighted vector sum
    //   store2(a1, v);
    //   return a1;
    // UNRESOLVED: Whether the two vectors a3[0]/a3[1] are basis/edge vectors or endpoints of a segment depends on the caller.
    // UNRESOLVED: Only the low 2 floats are written to a1; the z/w lanes are discarded, so the caller's vector dimension is unknown.
}
