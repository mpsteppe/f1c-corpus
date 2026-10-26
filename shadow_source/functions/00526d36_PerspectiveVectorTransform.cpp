// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00526D36
// Canonical corpus name: sub_526D36
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_526D36_00526d36.c

void UnknownObject::PerspectiveVectorTransform()
{
    // 3DNow perspective-style vector transform. Loads the two packed singles of a2, duplicates them into low/high lanes (v4 = {x,x}, v5 = {y,y}), and forms two linear combinations with the packed pairs at a3[0], a3[2] and a3[1], a3[3] plus the offset pairs at a3[6] and a3[7]. The second lane of the a3[1]/a3[3]/a3[7] combination is used as a perspective divisor via a reciprocal-approximation sequence, and the first combination scaled by that divisor is stored into a1->m64_u64. a1 is returned.
    // STATE_TRANSITION: Emit _m_femms() before and after the 3DNow arithmetic to exit the MMX state. [source:raw]
    // ASSIGNMENT: Load a2->m64_u64 into the local m64_u64 register for lane manipulation. [source:raw]
    // CALCULATION: Duplicate the low lane of the loaded vector into both lanes (v4) and the high lane into both lanes (v5). [source:raw]
    // CALCULATION: Compute v6 as v5 multiplied by the packed pair at a3[2]. [source:raw]
    // CALCULATION: Compute v7 as v4 times the packed pair at a3[1] plus the packed pair at a3[7] plus v5 times the packed pair at a3[3]. [source:raw]
    // CALCULATION: Duplicate the high lane of v7 into both lanes (v8) and build a refined reciprocal approximation of it via the pfrcp, pfrcpit1, pfrcpit2 sequence (v9). [source:raw]
    // ASSIGNMENT: Compute v4 times the packed pair at a3[0] plus the packed pair at a3[6] plus v6, multiply by the reciprocal of v8, and store the result into a1->m64_u64, treating a1 as the destination this object at offset 0. [field:this:0x00000000, source:raw]
    // RETURN: Return the output pointer a1. [function:0x00526D36, source:raw]

    // Conservative worker pseudocode:
    //   __m64 *PerspectiveVectorTransform(__m64 *out, __m64 *vec, __m64 *m) {
    //     _m_femms();
    //     __m64 v4 = _m_punpckldq(vec->m64_u64, vec->m64_u64);
    //     __m64 v5 = _m_punpckhdq(vec->m64_u64, vec->m64_u64);
    //     __m64 v6 = _m_pfmul(v5, m[2]);
    //     __m64 v7 = _m_pfadd(_m_pfadd(_m_pfmul(v4, m[1]), m[7]), _m_pfmul(v5, m[3]));
    //     __m64 v8 = _m_punpckhdq(v7, v7);
    //     __m64 v9 = _m_pfrcp(v8);
    //     out->m64_u64 = _m_pfmul(_m_pfadd(_m_pfadd(_m_pfmul(v4, m[0]), m[6]), v6),
    //                             _m_pfrcpit2(_m_pfrcpit1(v8, v9), v9));
    //     _m_femms();
    //     return out;
    //   }
    // UNRESOLVED: Whether the division is a genuine perspective divide or a normalization against the transformed y-lane depends on the caller's geometry conventions, which are not evidenced here.
    // UNRESOLVED: The prelabel cluster_copy notes a structural twin relationship to FloatClamp (004646c0), but the raw source shows a scaled transform with reciprocal division rather than a clamping operation; cluster affinity is DERIVED and not used as the semantic name.
    // UNRESOLVED: a3 is treated as an array of packed-single pairs at indices 0, 1, 2, 3, 6 and 7; the full stride and layout of a3 are not evidenced here.
}
