// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00520FC6
// Canonical corpus name: sub_520FC6
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_520FC6_00520fc6.c

void UnknownObject::NormalizeVectorWithFallback()
{
    // 3DNow! conditional 2-float vector normalize. Computes the packed length-squared of the input vector a1 (two packed halves), compares it against a tiny threshold constant 0x80000000800000 via pfcmpge, and branches: below/at threshold writes a packed {1.0, -1.0} fallback (0xBF8000003F800000) and zeroes the outputs, otherwise refines the reciprocal sqrt with a Newton step and writes normalized components to a2, plus a scaled component to a3 via SquareRootApproximation and the scale constant 0x4000000040000000. Returns the branch flag.
    // ASSIGNMENT: Load the two packed float halves of input a1: first half at +0x0 into m64_u64 and second half at +0x8 into v4. [field:this:0x00000000, field:this:0x00000008, source:raw]
    // CALCULATION: Compute packed per-lane squared components v5 = pfadd(pfmul(m64_u64, m64_u64), pfmul(v4, v4)). [source:raw]
    // CALCULATION: Accumulate both lanes with pfacc to produce the packed length-squared value v6. [source:raw]
    // CALCULATION: Take the packed reciprocal square root v7 = pfrsqrt(v6). [source:raw]
    // GUARD: Compare length-squared v6 against the tiny threshold 0x80000000800000 (packet global VectorLengthSquaredThreshold 0x005AF970) with pfcmpge; a true result selects the fallback branch. [global:0x005AF970, source:raw]
    // GUARD: Fallback branch: write the fallback output only when a2 is non-null. [source:raw]
    // ASSIGNMENT: Fallback branch: write the packed constant 0xBF8000003F800000 (packet global SSEZeroThreshold 0x005AF8F0, {1.0, -1.0}) to a2 and zero the following dword. [global:0x005AF8F0, source:raw]
    // GUARD: Fallback branch: write zero to a3 only when a3 is non-null. [source:raw]
    // ASSIGNMENT: Fallback branch: clear a3 to zero. [source:raw]
    // CALCULATION: Normalize branch: refine the reciprocal length with the Newton step pfrsqit1(pfmul(v7, v7), v6) then pfrcpit2, producing v11. [source:raw]
    // GUARD: Normalize branch: write normalized components only when a2 is non-null. [source:raw]
    // ASSIGNMENT: Normalize branch: write the normalized packed vector to a2, first half m64_u64 * v11 and second half v11 * v4 at a2 + 8. [source:raw]
    // GUARD: Normalize branch: when a3 is non-null, invoke the reciprocal-sqrt approximation helper. [callee:0x00529000, source:raw]
    // CALL: Call SquareRootApproximation(a3, a2). [callee:0x00529000, source:raw]
    // ASSIGNMENT: Normalize branch: write the scaled component to a3 = punpckhdq(v4, v4) * 0x4000000040000000 (packet global OutputLengthScale 0x005AF908). [global:0x005AF908, source:raw]
    // RETURN: Emit the 3DNow! femms state-clear and return the branch result. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_520FC6(__m64* a1, int a2, _DWORD* a3) {
    //     __m64 m64_u64 = a1[0];
    //     __m64 v4 = a1[1];
    //     __m64 v5 = _m_pfadd(_m_pfmul(m64_u64, m64_u64), _m_pfmul(v4, v4));
    //     __m64 v6 = _m_pfacc(v5, v5);
    //     __m64 v7 = _m_pfrsqrt(v6);
    //     int result = _mm_cvtsi64_si32(_m_pfcmpge((__m64)0x80000000800000LL, v6));
    //     if (result) {
    //       if (a2) { *(_QWORD*)(a2 + 4) = 0; *(_DWORD*)a2 = _mm_cvtsi64_si32((__m64)0xBF8000003F800000uLL); }
    //       if (a3) *a3 = _mm_cvtsi64_si32(0);
    //     } else {
    //       __m64 v10 = _m_pfmul(v7, v7);
    //       if (a2) {
    //         __m64 v11 = _m_pfrcpit2(_m_pfrsqit1(v10, v6), v7);
    //         *(__m64*)a2 = _m_pfmul(m64_u64, v11);
    //         *(_DWORD*)(a2 + 8) = _mm_cvtsi64_si32(_m_pfmul(v11, v4));
    //       }
    //       if (a3) {
    //         result = SquareRootApproximation(a3, a2);
    //         *a3 = _mm_cvtsi64_si32(_m_pfmul(_m_punpckhdq(v4, v4), (__m64)0x4000000040000000LL));
    //       }
    //     }
    //     _m_femms();
    //     return result;
    //   }
    // UNRESOLVED: The association of the three packet globals with the immediate constants (0x005AF970 threshold, 0x005AF8F0 fallback, 0x005AF908 scale) follows the existing analysis naming and is DERIVED, not stated in the raw source.
    // UNRESOLVED: The exact semantic of the pfcmpge argument order (threshold compared against length-squared) is inferred; the fallback-vs-normalize branch polarity is taken from the existing analysis.
    // UNRESOLVED: The meaning of the a3 output (scaled component) and the purpose of the a2/a3 buffer pair is unknown without callers.
}
