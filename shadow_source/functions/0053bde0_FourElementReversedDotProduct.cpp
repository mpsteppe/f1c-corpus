// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0053BDE0
// Canonical corpus name: F_4ElementDotProduct
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_4ElementDotProduct_0053bde0.c

void UnknownObject::FourElementReversedDotProduct()
{
    // Computes a dot product between a reversed-order integer vector (first lane forced to 0) and a float vector using SSE multiply and horizontal shuffle-add. Returns the scalar result as a float promoted to the double return type.
    // CALCULATION: Build v4 = [0, a1[2], a1[1], a1[0]]; reverses the three input integer components and forces the first lane to 0. [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, source:raw]
    // CALCULATION: v2 = element-wise multiply of v4 by the float vector *a2 (SSE _mm_mul_ps). [source:raw]
    // CALCULATION: Horizontal sum of the four v2 lanes using _mm_shuffle_ps extracts: v2[0] + v2[1] + v2[2] + v2[3]. [source:raw]
    // RETURN: Return the scalar sum, converted to float and promoted to the double return type. [source:raw, function:0x0053BDE0]

    // Conservative worker pseudocode:
    //   vec4 v4 = {0, a1[2], a1[1], a1[0]};
    //   vec4 v2 = v4 * (*a2);
    //   return (float)(v2[0] + v2[1] + v2[2] + v2[3]);
    // UNRESOLVED: Packet lists global flt_59E440 (0x0059E440) as read, but the raw source text has no reference to it; the association may belong to a different function or be a stale label.
    // UNRESOLVED: Existing-analysis claim that this function is used in physics constraint evaluation is unverified by the raw source; the packet carries no callers.
    // UNRESOLVED: Return signature is double while the computed value is single precision; whether the double promotion is semantically meaningful is unknown.
}
