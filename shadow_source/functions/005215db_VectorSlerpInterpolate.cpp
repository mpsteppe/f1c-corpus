// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005215DB
// Canonical corpus name: SIMDVectorNormalization
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SIMDVectorNormalization_005215db.c

void UnknownObject::VectorSlerpInterpolate()
{
    // 3DNow! vector interpolation between two input vectors a2 and a3 with parameter a4, writing the result to a1. Computes the dot product, extracts its sign and magnitude, and branches on |dot|: when |dot| is small enough (<= ~0.9999) it takes the full path computing 1/sin(theta) via pfrsqrt(1-dot^2) with Newton-Raphson refinement (F_3DVectorNormalize_8f00, sub_529700) to build sin-based blend weights; otherwise it uses the simple (1-t, t) weights. The final per-lane products (weight-a2 and weight-a3, lanes combined with sign restoration) are written to a1->m64_u64 and a1[1].m64_u64.
    // CALL: _m_femms() at entry to switch the CPU into MMX/3DNow state. [source:raw]
    // CALCULATION: Dot product v4 = a2[0]*a3[0] + a2[1]*a3[1] built from per-lane pfadd(pfmul) of the two 64-bit halves of a2 and a3. [source:raw]
    // CALCULATION: Broadcast the parameter: v5 = cvtsi32_si64(a4), and compute v6 = 1.0 - t by subtracting v5 from the packed 0x3F800000 (single-precision 1.0) constant. [source:raw]
    // CALCULATION: Horizontal fold v7 = pfacc(v4, v4) collapses the two dot lanes; v8 = pand(pfcmpge(0, v7), 0x8000000080000000) extracts the sign lane; v9 = pxor(v7, v8) yields the magnitude |dot|. [source:raw]
    // CALCULATION: v10 = 1 - |dot|^2 computed as pfsubr(v9*v9, packed 0x3F800000 1.0). [source:raw]
    // GUARD: Branch on pfcmpge(0x3F7FFF58 (packed ~0.9999), v9): the full slerp path runs only while |dot| stays below the near-parallel threshold. [source:raw]
    // CALL: v11 = pfrsqrt(v10), the reciprocal square root approximating 1/sin(theta). [source:raw]
    // CALL: F_3DVectorNormalize_8f00() performs a Newton-Raphson refinement step on the intermediate. [callee:0x00528F00, source:raw]
    // CALL: First sub_529700() helper call advancing the interpolation computation. [callee:0x00529700, source:raw]
    // CALCULATION: Fold the parameter into the weights: v20 and v12 combine a4 and (1.0 - t) with the reciprocal-sin intermediate. [source:raw]
    // CALL: Second sub_529700() helper call completing the refinement stage. [callee:0x00529700, source:raw]
    // CALCULATION: v13 = refined reciprocal-sin factor (Newton-Raphson via pfrsqit1/pfrcpit2); v6 and v5 are then scaled by v13 into the final sin-based blend weights, and the sign lane v8 is re-derived. [source:raw]
    // ASSIGNMENT: result = a1; v15 = pxor(v5, v8) restores the signed weight; v16/v17 duplicate the two blend weights across both lanes via punpckldq. [source:raw]
    // CALCULATION: Per-lane lerp: lane products (weight-a2[0], weight-a2[1], weight-a3[0], weight-a3[1]) are multiplied and summed so the first lane is v18 + weight-a3[0] and the second is the pfadd of the two lane terms. [source:raw]
    // ASSIGNMENT: Write the interpolated lanes: a1->m64_u64 (this+0) gets the first combined lane and a1[1].m64_u64 (this+8) gets the second. [field:this:0x00000000, field:this:0x00000008, source:raw]
    // CALL: _m_femms() at exit to leave the MMX/3DNow state. [source:raw]
    // RETURN: Return a1 (the output vector pointer); called from MMX3DNowVectorTransform and F_3DVectorBlend. [caller:0x00521712, caller:0x0052179F, function:0x005215DB, source:raw]

    // Conservative worker pseudocode:
    //   __m64* VectorSlerpInterpolate(__m64* out, __m64* a, __m64* b, unsigned int t) {
    //     femms();
    //     dot = pfadd(pfmul(a[0], b[0]), pfmul(a[1], b[1]));
    //     dot = pfacc(dot, dot);
    //     sign = pand(pfcmpge(0, dot), 0x8000000080000000);
    //     absdot = pxor(dot, sign);
    //     oneMinusTSq = pfsubr(pfmul(absdot, absdot), 0x3F8000003F800000);
    //     if (pfcmpge(0x3F7FFF583F7FFF58, absdot)) {
    //       rsqrt = pfrsqrt(oneMinusTSq);
    //       F_3DVectorNormalize_8f00();
    //       sub_529700();
    //       sub_529700();
    //       refined = pfrcpit2(pfrsqit1(oneMinusTSq, pfmul(rsqrt, rsqrt)), rsqrt);
    //       w0 = pfmul(broadcast(1.0 - t), refined);
    //       w1 = pfmul(broadcast(t), refined);
    //     } else {
    //       w0 = broadcast(1.0 - t); w1 = broadcast(t);
    //     }
    //     w1 = pxor(w1, sign);
    //     w0 = punpckldq(w0, w0); w1 = punpckldq(w1, w1);
    //     out[0] = pfadd(pfmul(w0, a[0]), pfmul(w1, b[0]));
    //     out[1] = pfadd(pfmul(w0, a[1]), pfmul(w1, b[1]));
    //     femms();
    //     return out;
    //   }
    // UNRESOLVED: Three read-only globals flagged by packet facts (qword_5AF988, qword_5AF9D0, qword_5AF9E8) appear nowhere in the raw decompiled text; the existing analysis labels them PackedMathOne, SIMD_Mask3DNow and Unknown_QWord_Compare, all unverifiable from this packet.
    // UNRESOLVED: The exact contribution of sub_529700 (called twice) and F_3DVectorNormalize_8f00 to the interpolation formula is not visible here.
    // UNRESOLVED: The relation between the a4 parameter and the final blend weights in the simple (non-slerp) branch is not proven to be a plain (1-t, t) lerp.
    // UNRESOLVED: The domain of a4 (expected range and whether it is clamped) is not evidenced.
}
