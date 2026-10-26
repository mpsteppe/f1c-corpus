// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005273D6
// Canonical corpus name: sub_5273D6
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_5273D6_005273d6.c

void UnknownObject::NormalizedCrossDirection()
{
    // SIMD routine (3DNow!) that reads two components of three input vectors (a2, a3, a4), builds cross-product-like perpendicular terms from their differences, computes a squared-length and performs a guarded reciprocal-square-root normalization (Newton-refined) against a denormal epsilon threshold, then writes a normalized direction pair into the output a1. The output is forced to zero when the squared length is at or below the epsilon guard.
    // CALL: _m_femms(): initialize 3DNow! floating-point state (exit MMX integer mode). [source:raw, function:0x005273D6]
    // ASSIGNMENT: Load y-components from the +0x8 dword of a2/a3/a4 (a2[1].m64_u32[0], a3[1].m64_u32[0], a4[1].m64_u32[0]) and compute v5 = pfsub(punpckldq(v4,v4), punpckldq(cvtsi32_si64(a4[1].low), a3[1].low)): y-difference (a2.y - a4.y) broadcast into both lanes. [field:this:0x00000008]
    // CALCULATION: Compute x-component differences from the 64-bit first word of a2/a3/a4: v6 = a2.x - a4.x; v7 = pfsub(0, v6) negation; v8 = a2.x - a3.x. [field:this:0x00000000]
    // CALCULATION: v9 = pxor(pfacc(pfmul(punpckhdq(v8,v7), v5), pfmul(punpckldq(punpckhdq(v5, 0x8000000000000000), v8), punpckldq(v7,v5))), 0x8000000000000000): assemble perpendicular/cross term from the packed differences and flip a sign bit with the xor mask. [source:raw]
    // CALCULATION: v10 = pfmul(punpckhdq(v6, punpckldq(v6,v7)), v8); v11 = pfacc(v10,v10); v12 = psllqi(v11, 0x20): form the dot-style accumulated term and shift lanes for the squared-length sum. [source:raw]
    // CALCULATION: v13 = pfadd(pfmul(v9,v9), pfmul(v12,v12)); v14 = pfacc(v13,v13): squared length of the perpendicular term. [source:raw]
    // GUARD: v16 = pfcmpgt(v14, 0x80000000800000LL): packed compare of squared length against a denormal epsilon threshold; guards the normalize path against degenerate (near-zero) input vectors. [source:raw]
    // CALCULATION: Newton-Raphson refinement of reciprocal square root: v15 = pfrsqrt(v14); v17 = pfrcpit2(pfrsqit1(v14, pfmul(v15,v15)), v15): refined 1/sqrt(length^2). [source:raw]
    // ASSIGNMENT: v19 = pfmul(pand(v9,v16), v17); v20 = pfmul(pand(v11,v16), v17): apply the guard mask (resulting in zero lanes when length^2 <= epsilon) and scale by the refined reciprocal root. [source:raw]
    // ASSIGNMENT: v21 = pfmul(v19, a2->m64_u64): multiply the first normalized component by the a2 first word. [field:this:0x00000000]
    // ASSIGNMENT: Write outputs into a1: a1->m64_u64 = v19; a1[1].m64_u64 = pxor(punpckldq(v20, pfadd(pfacc(v21,v21), pfmul(v20,v4))), 0x8000000000000000): store the normalized direction pair with a sign flip on the second lane. [field:this:0x00000000]
    // CALL: _m_femms(): tear down 3DNow! floating-point state. [source:raw, function:0x005273D6]
    // RETURN: Return a1 (pointer to the output normalized direction pair). [source:raw, function:0x005273D6]

    // Conservative worker pseudocode:
    //   init_femms();
    //   yDiff = pfsub(load_y(a2), load_y(a4));
    //   xDiffA = a2.x - a4.x;  xDiffB = a2.x - a3.x;
    //   perpendicular = build_cross(xDiffA, xDiffB, yDiff, signMask);
    //   squaredLen = pfacc(perpendicular^2 + shiftedTerm^2);
    //   guardMask = pfcmpgt(squaredLen, epsilonThreshold);
    //   invSqrt = newton_rsqrt(squaredLen);
    //   out[0] = perpendicular & guardMask * invSqrt;
    //   out[1] = xor_pack(secondTerm, signMask);
    //   a1[0] = out[0]; a1[1] = out[1];
    //   fini_femms();
    //   return a1;
    // UNRESOLVED: Globals qword_5AF970 / qword_5AF980 do not appear in the raw source text; the fill's claimed roles (VectorLengthSquaredThreshold / SIMD_Const_5AF980) are DERIVED prose and unconfirmed by this packet.
    // UNRESOLVED: Exact semantic meaning of the two output lanes (cross vs dot / which world direction) is not fully derivable from decompiler output alone.
    // UNRESOLVED: Function owner is unknown; no static callers found (indirect-only or top-level).
    // UNRESOLVED: Use of a2[1].low only (not a3[1].low/a4[1].low directly as operands) suggests lane assembly whose exact source layout is ambiguous.
}
