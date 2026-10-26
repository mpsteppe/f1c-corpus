// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005261EA
// Canonical corpus name: sub_5261EA
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_5261EA_005261ea.c

void UnknownObject::Weighted3PointBlend3DNow()
{
    // Stdcall 3DNow! routine that computes two packed output pairs as affine weighted sums over an 8-pair coefficient table a3, driven by three weight scalars read from a2 (two packed in a2[0], the third as the low dword of a2[1]). a1[0] = w0*a3[0] + w1*a3[2] + w2*a3[4] + a3[6]; a1[1] = w0*a3[1] + w1*a3[3] + w2*a3[5] + a3[7], where each a3[n] is a packed pair of floats and the weights are broadcast across both lanes. Emits _m_femms() on entry and again before returning the destination pointer a1. No branches or calls.
    // CALL: Execute _m_femms() on entry to clear 3DNow!/MMX state before the packed math. [source:raw]
    // CALCULATION: Load and broadcast the first weight: v4 = punpckldq(a2->m64_u64, a2->m64_u64) duplicates the low float of a2[0] into both lanes. [source:raw]
    // CALCULATION: Load the third weight scalar v5 = cvtsi32_si64(a2[1].m64_u32[0]) from the low dword of the second input slot. [source:raw]
    // CALCULATION: Load and broadcast the second weight: v6 = punpckhdq(a2->m64_u64, a2->m64_u64) duplicates the high float of a2[0] into both lanes. [source:raw]
    // CALCULATION: Broadcast the third weight v7 = punpckldq(v5, v5) so both lanes carry w2. [source:raw]
    // CALCULATION: Compute second output pair v8 = pfadd(pfadd(pfmul(v4, a3[1]), a3[7]), pfadd(pfmul(v6, a3[3]), pfmul(v7, a3[5]))): w0*a3[1] + a3[7] + w1*a3[3] + w2*a3[5]. [source:raw]
    // ASSIGNMENT: Write first output pair a1->m64_u64 = pfadd(pfadd(pfmul(v4, a3[0]), a3[6]), pfadd(pfmul(v6, a3[2]), pfmul(v7, a3[4]))): w0*a3[0] + a3[6] + w1*a3[2] + w2*a3[4] into the low output slot at this+0x0. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Write second output pair a1[1].m64_u64 = v8 into the high output slot at this+0x8. [field:this:0x00000008, source:raw]
    // CALL: Execute _m_femms() before returning to clear 3DNow!/MMX state. [source:raw]
    // RETURN: Return the destination pointer a1. [function:0x005261EA, source:raw]

    // Conservative worker pseudocode:
    //   // 3DNow! affine blend: three weights from a2, eight-pair table a3, two output pairs in a1.
    //   _m_femms();
    //   w0 = dup_low32(a2[0]);               // broadcast a2[0] low float
    //   w2 = cvtsi32_si64(a2[1].m64_u32[0]);
    //   w1 = dup_high32(a2[0]);              // broadcast a2[0] high float
    //   w2 = dup(w2);
    //   a1[0] = w0*a3[0] + w1*a3[2] + w2*a3[4] + a3[6];
    //   a1[1] = w0*a3[1] + w1*a3[3] + w2*a3[5] + a3[7];
    //   _m_femms();
    //   return a1;
    // UNRESOLVED: The intended meaning of the three weights in a2 and the role of the eight-pair table a3 (e.g. quadratic/spline basis evaluation or a terrain heightfield patch) are not established by this packet alone.
    // UNRESOLVED: Packet field base 'this' covers only the output pointer a1; the input pointers a2 and a3 have no identity in the fact table.
    // UNRESOLVED: The prelabel claims a structural twin of sub_410AF0, but that function's raw source is an array swap-remove with an entirely different body; the cluster relationship is layout-level only and does not prove shared semantics.
}
