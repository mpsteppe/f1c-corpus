// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0052278B
// Canonical corpus name: F_3DNowQuaternionFromAngle
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_3DNowQuaternionFromAngle_0052278b.c

void UnknownObject::F_3DNowQuaternionFromAngle()
{
    // 3DNow! routine that normalizes an axis vector (a3) via F_3DVectorNormalize_7578 into a 16-byte working pair, then combines it with a quaternion/vector pair (a2) using packed-Float multiply/accumulate and packed sign-flip (XOR 0x8000000080000000) to fill all 8 __m64 slots of output a1, forming a 4x4 rotation-style matrix. Straight-line, no branches.
    // CALL: Call F_3DVectorNormalize_7578 to normalize the axis vector a3 into the 16-byte working pair v14/v15. MMX state is flushed (femms) around the computation. [callee:0x00527578, source:raw]
    // ASSIGNMENT: Load the input quaternion/vector pair a2: m64_u64 = a2[0], v5 = a2[1]. [source:raw]
    // CALCULATION: Compute v6 = v5 * v15 (pfmul) and v7 = a2[0] * v14 + v6 (pfmul + pfadd), a dot-product-like combination of the quaternion with the normalized axis. [source:raw]
    // CALCULATION: Negate both halves of the normalized axis by XOR with the packed sign-flip mask 0x8000000080000000: v8 = v14 XOR mask, v9 = v15 XOR mask. The mask corresponds to the SIMD_Mask3DNow global qword_5AF9D0 per the existing analysis. [global:0x005AF9D0, source:raw]
    // CALCULATION: Reorder/accumulate working values: v10 = pfacc(v7, v7), v11 = punpckldq(v6, v10), v12 = psllqi(v10, 0x20), v13 = psrlqi(v11, 0x20). [source:raw]
    // ASSIGNMENT: Write all 8 output __m64 slots of a1 (this+0x0, this+0x8, this+0x10, this+0x18, this+0x20, this+0x28, this+0x30, this+0x38) combining negated/unnegated axis halves with the quaternion via pfmul/pfadd, forming the 4x4 rotation-style matrix. [field:this:0x00000000, field:this:0x00000008, field:this:0x00000010, field:this:0x00000018, field:this:0x00000020, field:this:0x00000028, field:this:0x00000030, field:this:0x00000038]
    // RETURN: Flush MMX state (femms) and return the output matrix pointer a1. [function:0x0052278B, source:raw]

    // Conservative worker pseudocode:
    //   femms();
    //   F_3DVectorNormalize_7578(&v14, a3);   // v14/v15 = normalized axis
    //   q0 = a2[0]; q1 = a2[1];
    //   t = q1 * v15;
    //   sum = q0 * v14 + t;
    //   neg0 = v14 XOR 0x8000000080000000;   // -v14 packed
    //   neg1 = v15 XOR 0x8000000080000000;   // -v15 packed
    //   acc = pfacc(sum, sum);
    //   lo = punpckldq(t, acc);
    //   hi = psllqi(acc, 0x20);
    //   sh = psrlqi(lo, 0x20);
    //   a1[0] = punpckldq(neg0,neg0)*q0 + sh;
    //   a1[1] = punpckldq(neg0,neg0)*q1;
    //   a1[2] = punpckhdq(neg0,neg0)*q0 + hi;
    //   a1[3] = punpckhdq(neg0,neg0)*q1;
    //   a1[4] = punpckldq(neg1,neg1)*q0;
    //   a1[5] = punpckldq(neg1,neg1)*q1 + sh;
    //   a1[6] = punpckhdq(neg1,neg1)*q0;
    //   a1[7] = punpckhdq(neg1,neg1)*q1 + hi;
    //   femms();
    //   return a1;
    // UNRESOLVED: The raw decompiled source presents the sign-flip mask as the literal 0x8000000080000000; the tie to global qword_5AF9D0 (SIMD_Mask3DNow) comes only from existing analysis, not the raw source.
    // UNRESOLVED: The exact rotation-axis versus quaternion semantics (which input is the quaternion and which the axis) are inferred from the normalization call and combination math, not confirmed.
    // UNRESOLVED: No caller evidence: function is top-level or indirectly reached.
}
