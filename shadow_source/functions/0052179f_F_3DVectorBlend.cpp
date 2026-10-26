// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0052179F
// Canonical corpus name: F_3DVectorBlend
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_3DVectorBlend_0052179f.c

void UnknownObject::F_3DVectorBlend()
{
    // Blends two vector pairs into an output vector using SIMDVectorNormalization with a smoothness weighting. First normalizes/combines (a2, a5) into temporary v8 and (a3, a4) into temporary v9 using factor a6; then computes a per-lane coefficient from a6 as 2.0 * (a6 - a6*a6) using the packed constant 0x4000000040000000LL (two 2.0f floats, backed by qword_5AF908), and performs a final SIMDVectorNormalization of v8 and v9 into a1 with that coefficient. Flushes the MMX state (_m_femms) before returning.
    // CALL: Call SIMDVectorNormalization(v8, a2, a5, a6) to produce the first intermediate vector v8 from inputs a2 and a5 under factor a6. [callee:0x005215DB, source:raw]
    // CALL: Call SIMDVectorNormalization(v9, a3, a4, a6) to produce the second intermediate vector v9 from inputs a3 and a4 under factor a6. [callee:0x005215DB, source:raw]
    // CALCULATION: Compute the blend coefficient per lane as 2.0 * (a6 - a6*a6): _m_pfsub(a6, _m_pfmul(a6, a6)) multiplied by the packed constant 0x4000000040000000LL (two 2.0f floats) loaded from qword_5AF908; a6 is moved into 64-bit SIMD lanes via _mm_cvtsi32_si64. [source:raw, global:0x005AF908]
    // CALL: Call SIMDVectorNormalization(a1, v8, v9, coefficient) to combine the two intermediates into the final output vector stored at a1. [callee:0x005215DB, source:raw]
    // RETURN: Flush the MMX/SIMD state with _m_femms() and return the pointer to the output at a1. [source:raw]

    // Conservative worker pseudocode:
    //   v8 = SIMDVectorNormalization(a2, a5, a6);
    //   v9 = SIMDVectorNormalization(a3, a4, a6);
    //   coef = packed2(2.0) * (a6 - a6*a6);
    //   out = SIMDVectorNormalization(v8, v9, coef);
    //   _m_femms();
    //   return out;
    // UNRESOLVED: Exact semantics of SIMDVectorNormalization's fourth argument (how the factor/coefficient affects the combine) are unknown; only the call shape is visible in this function.
    // UNRESOLVED: Purpose of the two-stage structure (pair-wise combination followed by a weighted combine) is inferred from argument order and the a6-derived coefficient; not confirmed.
    // UNRESOLVED: No existing analysis or fill for this function; owner and subsystem remain unverified.
}
