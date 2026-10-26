// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0052625B
// Canonical corpus name: sub_52625B
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_52625B_0052625b.c

void UnknownObject::Weighted3PointSumScalar3DNow()
{
    // Stdcall 3DNow! routine computing a non-affine weighted sum over a 6-entry coefficient table a3, driven by three weight scalars read from a2 (two packed in a2[0], the third as the low dword of a2[1]). a1[0] = w0*a3[0] + w1*a3[2] + w2*a3[4]; the second slot stores only the low 32 bits of w0*a3[1] + w1*a3[3] + w2*a3[5] as a scalar int. Unlike its twin sub_5261EA it omits the a3[6]/a3[7] addend terms and stores a scalar instead of a full pair in the second output slot. Emits _m_femms() on entry and again before returning the destination pointer a1. No branches or calls.
    // CALL: Execute _m_femms() on entry to clear 3DNow!/MMX state before the packed math. [source:raw]
    // CALCULATION: Load and broadcast the first weight: v4 = punpckldq(a2->m64_u64, a2->m64_u64) duplicates the low float of a2[0] into both lanes. [source:raw]
    // CALCULATION: Load the third weight scalar v5 = cvtsi32_si64(a2[1].m64_u32[0]) from the low dword of the second input slot. [source:raw]
    // CALCULATION: Load and broadcast the second weight: v6 = punpckhdq(a2->m64_u64, a2->m64_u64) duplicates the high float of a2[0] into both lanes. [source:raw]
    // CALCULATION: Broadcast the third weight v7 = punpckldq(v5, v5) so both lanes carry w2. [source:raw]
    // CALCULATION: Compute second-slot result v8 = pfadd(pfmul(v4, a3[1]), pfadd(pfmul(v6, a3[3]), pfmul(v7, a3[5]))): w0*a3[1] + w1*a3[3] + w2*a3[5] (no addend term). [source:raw]
    // ASSIGNMENT: Write first output pair a1->m64_u64 = pfadd(pfmul(v4, a3[0]), pfadd(pfmul(v6, a3[2]), pfmul(v7, a3[4]))): w0*a3[0] + w1*a3[2] + w2*a3[4] (no addend term) into the low output slot at this+0x0. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Write scalar into the high output slot a1[1].m64_i32[0] = cvtsi64_si32(v8): only the low 32 bits of the second-slot result are stored, at this+0x8. [field:this:0x00000008, source:raw]
    // CALL: Execute _m_femms() before returning to clear 3DNow!/MMX state. [source:raw]
    // RETURN: Return the destination pointer a1. [function:0x0052625B, source:raw]

    // Conservative worker pseudocode:
    //   // 3DNow! weighted sum (no offset): three weights from a2, six-pair table a3, pair + scalar outputs in a1.
    //   _m_femms();
    //   w0 = dup_low32(a2[0]);               // broadcast a2[0] low float
    //   w2 = cvtsi32_si64(a2[1].m64_u32[0]);
    //   w1 = dup_high32(a2[0]);              // broadcast a2[0] high float
    //   w2 = dup(w2);
    //   a1[0] = w0*a3[0] + w1*a3[2] + w2*a3[4];
    //   a1[1].lo32 = w0*a3[1] + w1*a3[3] + w2*a3[5];
    //   _m_femms();
    //   return a1;
    // UNRESOLVED: The intended meaning of the three weights in a2 and the role of the six-pair table a3 are not established by this packet alone; the omission of the a3[6]/a3[7] addend terms and the scalar store distinguish this routine from its twin sub_5261EA but do not reveal its consumer.
    // UNRESOLVED: Packet field base 'this' covers only the output pointer a1; the input pointers a2 and a3 have no identity in the fact table.
    // UNRESOLVED: The prelabel claims a structural twin of sub_410AF0, but that function's raw source is an array swap-remove with an entirely different body; the cluster relationship is layout-level only and does not prove shared semantics.
}
