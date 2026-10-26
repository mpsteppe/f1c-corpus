// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00526E32
// Canonical corpus name: sub_526E32
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_526E32_00526e32.c

void UnknownObject::BilinearInterpolate()
{
    // Packed two-lane bilinear interpolation helper using 3DNow! MMX intrinsics. Treats the four __m64 operands as pairs of single-precision floats and computes a1 = a2 + (a3 - a2) * a5 + (a4 - a2) * a6, with the two interpolation weights a5/a6 duplicated into both 32-bit lanes. Returns the output pointer a1. The clustering prelabel named FloatClamp as a structural twin, but the raw source shows interpolation, not clamping.
    // ASSIGNMENT: Convert the 32-bit weight a5 into an MMX register with _mm_cvtsi32_si64(a5). [source:raw]
    // ASSIGNMENT: Convert the 32-bit weight a6 into an MMX register with _mm_cvtsi32_si64(a6). [source:raw]
    // ASSIGNMENT: Save the output pointer: result = a1. [source:raw]
    // CALCULATION: Duplicate the low 32-bit lane of the weight registers with _m_punpckldq so every lane holds the same weight bit pattern. [source:raw]
    // CALCULATION: Compute the two per-lane deltas with _m_pfsub: a3 - a2 and a4 - a2. [source:raw]
    // CALCULATION: Weight the deltas with _m_pfmul and accumulate with _m_pfadd into the output: a1 = a2 + (a3 - a2) * a5 + (a4 - a2) * a6. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Store the packed result into a1->m64_u64 (two float lanes). [field:this:0x00000000]
    // UNKNOWN: _m_femms() exits MMX/3DNow! state after the packed float math. [source:raw]
    // RETURN: Return the output pointer a1. [source:raw]

    // Conservative worker pseudocode:
    //   __m64 *BilinearInterpolate(__m64 *out, __m64 *base, __m64 *corner1, __m64 *corner2,
    //                             unsigned int weight1, unsigned int weight2) {
    //     __m64 w1 = _m_punpckldq(_mm_cvtsi32_si64(weight1), _mm_cvtsi32_si64(weight1));
    //     __m64 w2 = _m_punpckldq(_mm_cvtsi32_si64(weight2), _mm_cvtsi32_si64(weight2));
    //     out->m64_u64 = _m_pfadd(_m_pfadd(base->m64_u64,
    //       _m_pfmul(_m_pfsub(corner1->m64_u64, base->m64_u64), w1)),
    //       _m_pfmul(_m_pfsub(corner2->m64_u64, base->m64_u64), w2));
    //     _m_femms();
    //     return out;
    //   }
    // UNRESOLVED: Whether the weights a5/a6 are integer or float bit patterns is caller-defined; both lanes are interpreted as packed single-precision floats by the pf* instructions.
    // UNRESOLVED: Callers and the owning object are unknown; the only cross-reference is the cluster prelabel naming FloatClamp (004646c0) as a structural twin.
    // UNRESOLVED: The 64-bit lane meaning (two floats vs one double) depends on how the caller uses the two output lanes.
}
