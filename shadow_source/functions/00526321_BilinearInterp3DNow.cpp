// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00526321
// Canonical corpus name: BilinearInterp3DNow
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BilinearInterp3DNow_00526321.c

void UnknownObject::BilinearInterp3DNow()
{
    // Stdcall 3DNow! bilinear interpolation between three reference points. Given a base point a2, an x-delta point a3 and a y-delta point a4 (each a packed pair of floats), with two scalar weights a5 (x) and a6 (y), it writes a1[0] = a2[0] + (a3[0]-a2[0])*w0 + (a4[0]-a2[0])*w1 as a full packed pair and a1[1] as the low-dword scalar cvtsi64_si32(a2[1].lo + (a3[1].lo-a2[1].lo)*w0 + (a4[1].lo-a2[1].lo)*w1). The weights are broadcast with punpckldq, each reference value is scaled by its weight via pfsub/pfmul and combined with pfadd. Emits _m_femms() before returning the destination pointer a1. No branches or calls.
    // CALCULATION: Load the x weight scalar v6 = cvtsi32_si64(a5). [source:raw]
    // CALCULATION: Load the base scalar v7 = cvtsi32_si64(a2[1].m64_u32[0]) used for the second output component. [source:raw]
    // CALCULATION: Load the y weight scalar v8 = cvtsi32_si64(a6). [source:raw]
    // CALCULATION: Broadcast both weights: v10 = punpckldq(v6, v6) and v11 = punpckldq(v8, v8). [source:raw]
    // CALCULATION: Compute second-component scalar v12 = pfadd(pfadd(pfmul(pfsub(cvtsi32_si64(a3[1].m64_u32[0]), v7), v10), v7), pfmul(pfsub(cvtsi32_si64(a4[1].m64_u32[0]), v7), v11)): base + (a3.1-base)*w0 + (a4.1-base)*w1. [source:raw]
    // ASSIGNMENT: Write first output pair a1->m64_u64 = pfadd(pfadd(pfmul(pfsub(a3[0], a2[0]), v10), a2[0]), pfmul(pfsub(a4[0], a2[0]), v11)): base + (a3-base)*w0 + (a4-base)*w1 for both lanes, into the low output slot at this+0x0. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Write second-component scalar a1[1].m64_i32[0] = cvtsi64_si32(v12) into the high output slot at this+0x8. [field:this:0x00000008, source:raw]
    // CALL: Execute _m_femms() before returning to clear 3DNow!/MMX state. [source:raw]
    // RETURN: Return the destination pointer a1. [function:0x00526321, source:raw]

    // Conservative worker pseudocode:
    //   // 3DNow! bilinear interpolation: a1 = a2 + (a3-a2)*w0 + (a4-a2)*w1.
    //   w0 = cvtsi32_si64(a5);
    //   b1 = cvtsi32_si64(a2[1].m64_u32[0]);
    //   w1 = cvtsi32_si64(a6);
    //   w0 = dup(w0);  w1 = dup(w1);
    //   a1[0]     = a2[0] + (a3[0]-a2[0])*w0 + (a4[0]-a2[0])*w1;
    //   a1[1].lo32 = cvtsi64_si32(b1 + (a3[1].lo-b1)*w0 + (a4[1].lo-b1)*w1);
    //   _m_femms();
    //   return a1;
    // UNRESOLVED: The consumer of this bilinear interpolation (e.g. terrain heightfield, camera path, texture/sampling path) is not established by this packet alone.
    // UNRESOLVED: The weights a5/a6 are declared unsigned int in the prototype but are reinterpreted as floats by cvtsi32_si64; the bit-level float values supplied by callers are outside this packet.
    // UNRESOLVED: Packet field base 'this' covers only the output pointer a1; the reference points a2/a3/a4 have no identity in the fact table.
}
