// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00526CFD
// Canonical corpus name: sub_526CFD
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_526CFD_00526cfd.c

void UnknownObject::Matrix2x2VectorMultiply()
{
    // 3DNow 2x2 matrix-vector multiply. The two packed singles of the input vector a2 are duplicated into low/high lanes (v4 = {x,x}, v5 = {y,y}), multiplied respectively against the packed-single pairs at a3[0] and a3[2], and summed pairwise into the output a1->m64_u64. a1 is returned.
    // STATE_TRANSITION: Emit _m_femms() before and after the 3DNow arithmetic to exit the MMX state. [source:raw]
    // CALCULATION: Duplicate the low lane of a2 into both lanes (v4) and the high lane of a2 into both lanes (v5). [source:raw]
    // CALCULATION: Multiply v4 by the packed pair at a3[0] and v5 by the packed pair at a3[2], then add the two products pairwise. [source:raw]
    // ASSIGNMENT: Store the packed-single sum into a1->m64_u64, treating a1 as the destination this object at offset 0. [field:this:0x00000000, source:raw]
    // RETURN: Return the output pointer a1. [function:0x00526CFD, source:raw]

    // Conservative worker pseudocode:
    //   __m64 *Matrix2x2VectorMultiply(__m64 *out, __m64 *vec, __m64 *m) {
    //     _m_femms();
    //     __m64 v4 = _m_punpckldq(vec->m64_u64, vec->m64_u64);
    //     __m64 v5 = _m_punpckhdq(vec->m64_u64, vec->m64_u64);
    //     out->m64_u64 = _m_pfadd(_m_pfmul(v4, m[0]), _m_pfmul(v5, m[2]));
    //     _m_femms();
    //     return out;
    //   }
    // UNRESOLVED: Whether a1 aliases a2 (in-place transform) is not established; both are distinct arguments.
    // UNRESOLVED: The prelabel cluster_copy notes a structural twin relationship to FloatClamp (004646c0), but the raw source shows a linear 2x2 matrix-vector multiply rather than a clamping operation; cluster affinity is DERIVED and not used as the semantic name.
    // UNRESOLVED: The two packed-single pairs at a3[0] and a3[2] are read but the surrounding layout of a3 is not evidenced here.
}
