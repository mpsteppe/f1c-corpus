// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0052717C
// Canonical corpus name: F_3DNowBarycentricInterpolation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_3DNowBarycentricInterpolation_0052717c.c

void UnknownObject::BarycentricInterpolation3DNow()
{
    // Performs a two-weight barycentric interpolation on two packed float pairs using 3DNow! intrinsics. Converts the two scalar weights a5 and a6 into replicated packed pairs v9 and v10 via cvtsi32_si64 and punpckldq, then computes each output pair as a2 + v9*(a3-a2) + v10*(a4-a2) componentwise; the first component pair goes into a1[0] and the second into a1[1]. MMX state is cleared with _m_femms before returning the output buffer a1. The packet's prelabel (cluster twin of 00410AF0) is DERIVED-trust; the canonical name F_3DNowBarycentricInterpolation matches the recovered math.
    // CALCULATION: Convert scalar weight a5 into a packed pair v9 (cvtsi32_si64 then punpckldq replicates it across both 32-bit lanes). [source:raw]
    // CALCULATION: Convert scalar weight a6 into a packed pair v10 (cvtsi32_si64 then punpckldq replicates it across both 32-bit lanes). [source:raw]
    // CALCULATION: Compute the first component pair as a2[0] + v9*(a3[0]-a2[0]) + v10*(a4[0]-a2[0]) using pfmul/pfsub/pfadd over the first packed pair of each input. [field:this:0x00000000, source:raw]
    // CALCULATION: Compute the second component pair as a2[1] + v9*(a3[1]-a2[1]) + v10*(a4[1]-a2[1]) using pfmul/pfsub/pfadd over the second packed pair of each input. [field:this:0x00000008, source:raw]
    // ASSIGNMENT: Store the first interpolated component pair into a1 at offset 0x0. [field:this:0x00000000]
    // ASSIGNMENT: Store the second interpolated component pair into a1 at offset 0x8. [field:this:0x00000008]
    // STATE_TRANSITION: Clear MMX/3DNow state via _m_femms. [source:raw]
    // RETURN: Return the output buffer pointer a1. [function:0x0052717C, source:raw]

    // Conservative worker pseudocode:
    //   u = (float)a5; v = (float)a6;
    //   p0 = a2[0] + u * (a3[0] - a2[0]) + v * (a4[0] - a2[0]);
    //   p1 = a2[1] + u * (a3[1] - a2[1]) + v * (a4[1] - a2[1]);
    //   a1[0] = p0; a1[1] = p1;
    //   femms();
    //   return a1;
    // UNRESOLVED: Owner is UNKNOWN; the packet carries no owner evidence and no static callers.
    // UNRESOLVED: Whether a1 may alias one of the input buffers a2/a3/a4 is not stated and would change the semantics.
    // UNRESOLVED: The exact meaning of the two weights (u,v) as interpolation factors versus scale factors is DERIVED from the arithmetic; not packet-stated.
    // UNRESOLVED: The DERIVED cluster-twin prelabel names the function after 00410AF0, but the raw source here is a pure 3DNow math routine with no array swap-remove logic.
}
