// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005271ED
// Canonical corpus name: F_3DNowCubicPolynomialInterpolation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_3DNowCubicPolynomialInterpolation_005271ed.c

void UnknownObject::CubicHermiteInterpolate3DNow()
{
    // Straight-line 3DNow (MMX) cubic interpolation kernel. Broadcasts scalar unsigned parameter a6 into the low 32-bit lane and drives the packed 3DNow math (each __m64 holds two 32-bit float lanes). Computes the four cubic Hermite basis weights h00 = 2*t^3 - 3*t^2 + 1, h10 = t^3 - 2*t^2 + t, h01 = 3*t^2 - 2*t^3 and h11 = t^3 - t^2 from t, t^2 and t^3 using the folded-in constant pairs 1.0f/2.0f/3.0f, duplicates each weight across both lanes with punpckldq, then writes two blended pairs: a1[0] (this+0) and a1[1] (this+8), each the weighted sum h00*a2 + h10*a3 + h01*a4 + h11*a5 for its lane. Emits femms on entry and exit and returns the output pointer a1. No branches, no calls and no explicit global access in the decompiled body; the read-only globals qword_5AF988/qword_5AF998/qword_5AF9A0 are R-marked in the fact tables but absent from the source text, so they likely supply the folded-in constant pairs and are left unresolved.
    // CALL: Emit 3DNow state transition on entry via _m_femms(), clearing pending 3DNow state before the packed float math. [source:raw, function:0x005271ED]
    // CALCULATION: Move unsigned int parameter a6 into an __m64 via _mm_cvtsi32_si64; its 32-bit value supplies the interpolation parameter for both lanes (treated as float by the packed 3DNow multiplies). [source:raw]
    // CALCULATION: Compute t^2 = t*t and t^3 = t^2*t with _m_pfmul, one packed pair each. [source:raw]
    // CALCULATION: Form the four cubic basis weights per lane against the folded-in constant pairs 2.0f (0x4000000040000000), 3.0f (0x4040000040400000) and 1.0f (0x3F8000003F800000): h11 = t^3 - t^2, h01 = 3*t^2 - 2*t^3, h10 = t^3 - 2*t^2 + t, h00 = 2*t^3 - 3*t^2 + 1. [source:raw]
    // CALCULATION: Duplicate each basis weight into both 32-bit lanes with _m_punpckldq (v17 from v9, v18 from v14, v21 from v15, v22 from v16). [source:raw]
    // CALCULATION: Compute lane-0 weighted sum v19 = h01 * a4[0] (h01 broadcast times the low control point pair a4). [source:raw]
    // CALCULATION: Combine the four basis-weighted terms for lane 1 into v23 = h01*a4[1] + h11*a5[1] + h00*a2[1] + h10*a3[1]. [source:raw, field:this:0x00000008]
    // ASSIGNMENT: Write lane-0 result this+0x0: a1[0] = h00*a2[0] + h11*a5[0] + h01*a4[0] + h10*a3[0] (v19 plus the other three weighted pairs). [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Write lane-1 result this+0x8: a1[1] = v23, the packed second output pair. [field:this:0x00000008, source:raw]
    // CALL: Emit 3DNow state transition on exit via _m_femms() before returning. [source:raw, function:0x005271ED]
    // RETURN: Return result = a1, the caller-supplied output pointer. [source:raw, function:0x005271ED]

    // Conservative worker pseudocode:
    //   // Each __m64 holds two 32-bit float lanes; the same weights apply to both.
    //   __m64 *CubicHermiteInterpolate3DNow(__m64 *out, __m64 *p0, __m64 *p1, __m64 *dp0, __m64 *dp1, unsigned int u)
    //   {
    //       femms();
    //       __m64 t  = mm_cvtsi32_si64(u);          // low 32-bit lane = parameter
    //       __m64 t2 = t * t;
    //       __m64 t3 = t2 * t;
    //       __m64 h11 = t3 - t2;                    // t^3 - t^2
    //       __m64 h01 = 3.0f * t2 - 2.0f * t3;      // 3*t^2 - 2*t^3
    //       __m64 h10 = t3 - 2.0f * t2 + t;         // t^3 - 2*t^2 + t
    //       __m64 h00 = 2.0f * t3 - 3.0f * t2 + 1.0f; // 2*t^3 - 3*t^2 + 1
    //       out[0] = h00 * p0[0] + h10 * p1[0] + h01 * dp0[0] + h11 * dp1[0];
    //       out[1] = h00 * p0[1] + h10 * p1[1] + h01 * dp0[1] + h11 * dp1[1];
    //       femms();
    //       return out;
    //   }
    // UNRESOLVED: Owner is UnknownObject: the packet carries no owner evidence, and the DERIVED prelabel (structural twin of CubicInterp3DNow 00526392) is not a citable evidence ref, so no owner proposal is grounded in this packet.
    // UNRESOLVED: Read-only globals qword_5AF988, qword_5AF998 and qword_5AF9A0 are R-marked in the fact tables but have no textual reference in the decompiled body; likely the 1.0f/2.0f/3.0f constant pairs folded into the immediates, but the association is unproven.
    // UNRESOLVED: Argument roles are inferred from the Hermite basis shape: p0/p1 read as the interpolated endpoints (weights h00/h10) and dp0/dp1 as the derivative-weighted terms (weights h01/h11); no packet evidence names the semantics of a4/a5.
    // UNRESOLVED: The scalar parameter a6 is moved as raw 32-bit bits into the low lane and reinterpreted as float by the packed 3DNow math; the intended numeric scale of a6 is not stated in the packet.
}
