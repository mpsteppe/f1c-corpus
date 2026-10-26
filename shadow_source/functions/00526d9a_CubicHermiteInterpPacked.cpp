// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00526D9A
// Canonical corpus name: sub_526D9A
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_526D9A_00526d9a.c

void UnknownObject::CubicHermiteInterpPacked()
{
    // Cubic Hermite spline interpolation of packed float pairs using 3DNow! SIMD. The factor t (low 32 bits of a6) is expanded to a packed 64-bit value, its powers t^2 and t^3 are computed, and the four standard Hermite basis functions are derived from them: h00 = 2t^3 - 3t^2 + 1, h10 = t^3 - 2t^2 + t, h01 = 3t^2 - 2t^3, h11 = t^3 - t^2. Each basis weight is duplicated across both float lanes (_m_punpckldq) and multiplied against one of the four packed control-point pairs a2-a5; the four products are summed and the full 64-bit packed result is written to a1[0]. Straight-line control flow, no branches. The packed scalar constants 1.0f, 2.0f, 3.0f come from the globals qword_5AF988, qword_5AF998, qword_5AF9A0.
    // CALCULATION: Build packed factor: v6 = _mm_cvtsi32_si64(a6) converts unsigned int t into a packed 64-bit value; v7 = t*t and v8 = t*t*t via _m_pfmul [function:0x00526D9A, source:raw]
    // CALCULATION: h11 basis = t^3 - t^2 (v9 = v8 - v7 via _m_pfsub) [source:raw]
    // CALCULATION: h10 basis = t^3 - 2*t^2 + t: v10 = v7 * packed 2.0f, then v15 = (v8 - v10) + v6; the 2.0f packed constant is read from either qword_5AF998 or qword_5AF9A0 [global:0x005AF998, global:0x005AF9A0, source:raw]
    // CALCULATION: h01 basis = 3*t^2 - 2*t^3: v13 = v7 * packed 3.0f, v12 = v8 * packed 2.0f, then v14 = v13 - v12; the 2.0f/3.0f packed constants are read from qword_5AF998 and qword_5AF9A0 [global:0x005AF998, global:0x005AF9A0, source:raw]
    // CALCULATION: h00 basis = 2*t^3 - 3*t^2 + 1: v16 = (v12 - v13) + packed 1.0f, where the packed 1.0f constant is read from qword_5AF988 [global:0x005AF988, source:raw]
    // CALCULATION: Final blend: _m_punpckldq duplicates the low 32-bit float lane of each weight so the same weight applies to both floats of a control-point pair, then result = h00*dup(a2) + h10*dup(a3) + h01*dup(a4) + h11*dup(a5), accumulated with _m_pfmul and _m_pfadd over the packed 64-bit values of a2-a5 [function:0x00526D9A, source:raw]
    // ASSIGNMENT: Write the full 64-bit packed interpolation result to the output at this+0x0 (a1->m64_u64), the only field accessed; overwrites both float lanes on every call [field:this:0x00000000, source:raw]
    // RETURN: Return the output pointer a1 unchanged; 3DNow! MMX state is flushed via _m_femms both before and after the computation [source:raw]

    // Conservative worker pseudocode:
    //   t = packed(a6)
    //   t2 = t*t; t3 = t2*t
    //   h11 = t3 - t2
    //   h10 = t3 - 2.0f*t2 + t
    //   h01 = 3.0f*t2 - 2.0f*t3
    //   h00 = 2.0f*t3 - 3.0f*t2 + 1.0f
    //   result = h00 * a2 + h10 * a3 + h01 * a4 + h11 * a5   // per-lane, weights duplicated across both float lanes
    //   a1[0] = result
    // UNRESOLVED: The exact assignment of the two packed scalar constants (2.0f vs 3.0f) to qword_5AF998 versus qword_5AF9A0 is not established by the packet; Hex-Rays emits them as inline 64-bit literals and the DERIVED global names (MMMX_PolyCoeffAF998, SIMD_Coeff_3DNow_2) do not disambiguate them
    // UNRESOLVED: The meaning of each packed control-point pair (e.g. (x,y), (u,v), (angle,speed)) and the caller context are unknown; there are no static callers in the packet
    // UNRESOLVED: No function owner or owning subsystem is attested; the packet records none
}
