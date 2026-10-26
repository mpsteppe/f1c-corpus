// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00534120
// Canonical corpus name: F_3DTransformWithSIMD
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_3DTransformWithSIMD_00534120.c

void UnknownObject::F_3DTransformWithSIMD()
{
    // MMX subband-synthesis transform for the audio path: splits each of the eight 64-bit input lanes into low and high 16-bit halves, builds per-octave difference terms (psubw) and sum terms (paddw), then applies two banks of 16-row pmaddwd matrix products against constant coefficient tables (unk_8D7200 rows and qword_8D7000 qwords), folding each 32-bit accumulation with psrlqi/paddd, arithmetic-shifting right by 0xE, and storing 16-bit results into two output word buffers. Invoked by AudioResampler.
    // CALCULATION: Setup: split each of the eight 64-bit input lanes into low and high 16-bit halves (punpckhdq/psrlqi/punpckldq), then compute the per-octave difference terms (psubw) and sum terms (paddw) consumed by both coefficient banks. [source:raw]
    // CALCULATION: Stage 1: for each of 16 rows, accumulate pmaddwd products of the sum terms against the unk_8D7200 coefficient rows, fold with psrlqi/paddd, arithmetic-shift right by 0xE, and store the resulting 16-bit words into output buffer slots (a1[256..0] and a2[0..224]). [global:0x008D7200, field:this:0x00000000, field:this:0x00000020, field:this:0x00000040, field:this:0x00000060, field:this:0x00000080, field:this:0x000000A0, field:this:0x000000C0, field:this:0x000000E0]
    // CALCULATION: Stage 2: for each of 16 rows, accumulate pmaddwd products of the difference terms against the qword_8D7000 constant qwords, fold with psrlqi/paddd, arithmetic-shift right by 0xE, and store the resulting 16-bit words into output buffer slots (a1[240..16] and a2[16..240]). [global:0x008D7000, field:this:0x00000100, field:this:0x00000120, field:this:0x00000140, field:this:0x00000160, field:this:0x00000180, field:this:0x000001A0, field:this:0x000001C0, field:this:0x000001E0, field:this:0x00000200]
    // RETURN: Return the qword_8D7000 constant-table pointer as the function result; the routine is invoked by the AudioResampler. [function:0x00534120, global:0x008D7000, caller:0x00532AA0]

    // Conservative worker pseudocode:
    //   for each of the 8 input lanes: split low and high 16-bit halves
    //   diff[i] = a3[i] - high[i]; sum[i] = a3[i] + high[i];   // 4 octaves
    //   for each of 16 rows: out1[row] = pmaddwd(unk_8D7200, sum) >> 0xE
    //   for each of 16 rows: out2[row] = pmaddwd(qword_8D7000, diff) >> 0xE
    // UNRESOLVED: exact mapping between the field:this offsets and the a1/a2 word indices is not resolvable from this packet alone
    // UNRESOLVED: purpose of the returned qword_8D7000 pointer is unknown
}
