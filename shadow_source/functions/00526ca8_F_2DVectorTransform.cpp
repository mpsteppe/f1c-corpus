// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00526CA8
// Canonical corpus name: sub_526CA8
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_526CA8_00526ca8.c

void UnknownObject::F_2DVectorTransform()
{
    // 3DNow! 2-component vector transform (__stdcall). Reads the two input floats a2[0] as a packed pair, duplicates them into per-lane copies with punpckldq/punpckhdq (v4 = low duplicated, v5 = high duplicated), then transforms against the 4x4 coefficient matrix a3: a1[0] = a3[0]*v4 + a3[2]*v5 + a3[6] and a1[1] = a3[1]*v4 + a3[3]*v5 + a3[7] (nested pfmul/pfadd). Writes both output __m64 slots a1[0] and a1[1], emits _m_femms() at entry and exit, and returns a1. No guards, no callees.
    // STATE_TRANSITION: Emit _m_femms() at function entry and again before return to exit MMX/3DNow state. [source:raw]
    // CALCULATION: Load the input packed pair m64_u64 = a2[0] and duplicate lanes: v4 = punpckldq(m64_u64, m64_u64) (low dword into both lanes) and v5 = punpckhdq(m64_u64, m64_u64) (high dword into both lanes). [field:this:0x00000000, source:raw]
    // CALCULATION: Compute the first output quad a1[0] = pfadd(pfadd(pfmul(v4, a3[0]), a3[6]), pfmul(v5, a3[2])): each input component times its matrix column, plus the a3[6] translation/row term. [field:this:0x00000008, source:raw]
    // CALCULATION: Compute the second output quad v6 = pfadd(pfadd(pfmul(v4, a3[1]), a3[7]), pfmul(v5, a3[3])): the remaining two matrix columns plus the a3[7] term. [field:this:0x00000008, source:raw]
    // ASSIGNMENT: Store both results into the output buffer: a1[0] = computed first quad and a1[1] = v6. [field:this:0x00000000, source:raw]
    // RETURN: Return the output buffer pointer a1. [function:0x00526CA8, source:raw]

    // Conservative worker pseudocode:
    //   void F_2DVectorTransform(__m64* a1 /*out 2 slots* /, __m64* a2 /*in: 2 floats* /, __m64* a3 /*4x4 matrix* /) {
    //     _m_femms();
    //     __m64 m = a2[0];
    //     __m64 v4 = _m_punpckldq(m, m);
    //     __m64 v5 = _m_punpckhdq(m, m);
    //     a1[0] = _m_pfadd(_m_pfadd(_m_pfmul(v4, a3[0]), a3[6]), _m_pfmul(v5, a3[2]));
    //     a1[1] = _m_pfadd(_m_pfadd(_m_pfmul(v4, a3[1]), a3[7]), _m_pfmul(v5, a3[3]));
    //     _m_femms();
    //   }
    // UNRESOLVED: Prelabel cluster_copy names sub_410AF0 as a structural twin, but sub_410AF0 is an array slot-swap helper (functions/sub_410AF0_00410af0.c); the cluster assignment does not match this 3DNow math body and was not adopted.
    // UNRESOLVED: The exact column-major layout of the 8-slot matrix a3 (which slot pairs form columns 0..3 and translation) is inferred from the multiply-accumulate order, not independently verified against a consumer.
    // UNRESOLVED: Whether a1[1] holds a z/w result or is ignored by callers is not determinable from this function alone.
    // UNRESOLVED: Owner is UNKNOWN; the packet carries no owner evidence and no static callers/callees.
}
