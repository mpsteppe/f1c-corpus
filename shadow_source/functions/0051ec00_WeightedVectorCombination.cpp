// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0051EC00
// Canonical corpus name: sub_51EC00
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_51EC00_0051ec00.c

void UnknownObject::WeightedVectorCombination()
{
    // SIMD weighted linear combination. Computes *a1 = a3[3] + (element 0 of a2[0]) * a3[0] + (element 0 of a2[1]) * a3[1], where the scale factors are the lowest 32-bit elements of the two source vectors a2[0] and a2[1], splatted across the lanes via shuffle. Straight-line __m128 store; no branching beyond the three input vectors.
    // CALCULATION: Splat the first element of a2[0] across all four lanes and multiply lane-wise with a3[0]. [source:raw]
    // CALCULATION: Splat the first element of a2[1] across all four lanes and multiply lane-wise with a3[1]. [source:raw]
    // CALCULATION: Sum the two scaled products with a3[3] (the additive or translation term). [source:raw]
    // ASSIGNMENT: Store the resulting 128-bit vector into the output pointer a1 (this field 0). [field:this:0x00000000]

    // Conservative worker pseudocode:
    //   out = a3[3] + splat(a2[0].x) * a3[0] + splat(a2[1].x) * a3[1];
    //   *a1 = out;
    // UNRESOLVED: Semantic purpose unknown: the expression is a two-term weighted combination with an additive term, but the packet does not identify whether a2 and a3 are matrices, quaternions, or blend weights.
    // UNRESOLVED: The packet prelabel assigns this function as a structural twin of FloatClamp (004646c0), but the SIMD multiply-accumulate shape does not match clamping semantics; the cluster-copy label is treated as DERIVED and not relied on.
    // UNRESOLVED: a2 elements are typed unsigned int in the prototype but are reinterpreted as packed floats by the SIMD operations.
}
