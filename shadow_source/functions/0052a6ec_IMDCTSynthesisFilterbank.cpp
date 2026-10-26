// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0052A6EC
// Canonical corpus name: MPEGAudioLayer3IMDCT
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MPEGAudioLayer3IMDCT_0052a6ec.c

void UnknownObject::IMDCTSynthesisFilterbank()
{
    // MPEG Audio Layer 3 IMDCT synthesis filterbank stage. Stage one runs an 8-iteration butterfly over 64 16-bit subband samples (a1, a2) with fixed integer rotation coefficients (6270/4433/15137/20995/9633/16069/3196/7373/2446/16819/25172/12299), writing eight rounded int results ((x + 1024) >> 11) to the a3 output buffer. Stage two runs a second 8-iteration butterfly over that buffer, then performs four rounds of windowed byte-coefficient lookup into a6 (index ((x + 0x20000) >> 18) & 0x3FF) per output, packing four bytes into each of two dwords written through the a5 + a4[offset] pointer.
    // LOOP: Stage-one loop: do-while 8 iterations (v50 countdown from 8); each iteration advances the input pointers a1/a2 and the output pointer v48 by one 16-bit element. [source:raw]
    // CALCULATION: Butterfly group on element indices 0/16/32/48 (a1 and a2): products a2[16]*a1[16], a2[48]*a1[48] combined with coefficients 6270/4433/15137, plus (a1[0]*a2[0] +/- a1[32]*a2[32]) << 13, forming v52/v57/v61/v63/v65/v67. [field:this:0x00000000, field:this:0x00000020, field:this:0x00000040, field:this:0x00000060, source:raw]
    // CALCULATION: Butterfly group on element indices 8/24/40/56 (a1 and a2): products combined with coefficients 20995/9633/16069/3196/7373/2446/16819/25172/12299, forming v53/v58/v69/v14-v25. [field:this:0x00000010, field:this:0x00000030, field:this:0x00000050, field:this:0x00000070, source:raw]
    // ASSIGNMENT: Store eight rounded stage-one results into the a3 output buffer at indices 0/8/16/24/32/40/48/56: (term + 1024) >> 11. [source:raw]
    // LOOP: Stage-two loop: do-while 8 iterations (v51 countdown from 8); each iteration reads a dword index from the a4 offset table (v74 += 4) and forms the output pointer v27 = a5 + index. [source:raw]
    // CALCULATION: Second butterfly pass over the stage-one a3 buffer (v49[0..7]): recomputes the same rotation structure with coefficients 6270/4433/15137/20995/9633/16069/3196/7373/2446/16819/25172/12299 to form v54/v59/v62/v64/v66/v68/v70-v73. [source:raw]
    // CALCULATION: Window lookup: four rounds per output pack v42 and v43 by reading bytes from the a6 coefficient table at index ((x + 0x20000) >> 18) & 0x3FF, shifting each accumulated byte up by 8. [source:raw]
    // ASSIGNMENT: Write the two packed dwords to the output region: v27[0] = v42 and v27[1] = v43. [source:raw]
    // RETURN: Return the stage-two loop countdown result (the final value of v51, which reaches 0). [function:0x0052A6EC, source:raw]
    // CALL: Invoked by RenderingBranchOnDAT005d79dc (0x0052855A) to convert frequency-domain subband samples for the audio output path. [caller:0x0052855A, source:raw]

    // Conservative worker pseudocode:
    //   v48 = a3;
    //   for (n = 8; n; --n) {
    //     v6 = a2[48]*a1[48]; v7 = a2[16]*a1[16];
    //     v52 = 4433*(v6+v7) - 15137*v6; v57 = 4433*(v6+v7) + 6270*v7;
    //     v10 = a2[0]*a1[0]; v11 = a2[32]*a1[32];
    //     v12 = (v10+v11)<<13; v13 = (v10-v11)<<13;
    //     v61 = v57+v12; v63 = v52+v13; v65 = v12-v57; v67 = v13-v52;
    //     /* second group on indices 8/24/40/56 with 20995/9633/16069/3196/7373/2446/16819/25172/12299 * /
    //     v48[32]=(v65-v22+1024)>>11; v48[24]=(v65+v22+1024)>>11;
    //     v48[40]=(v67-v23+1024)>>11; v48[48]=(v63-v24+1024)>>11;
    //     v48[16]=(v67+v23+1024)>>11; v48[8]=(v63+v24+1024)>>11;
    //     v48[56]=(v61-v25+1024)>>11; v48[0]=(v25+v61+1024)>>11;
    //     ++a1; ++v48; ++a2;
    //   }
    //   v49 = a3;
    //   for (n = 8; n; --n) {
    //     v27 = a5 + a4[i++];
    //     /* second butterfly over v49[0..7], then four window byte lookups * /
    //     v42 = 0; v43 = 0;
    //     v42 = (v42<<8)|a6[((v42+v66+0x20000)>>18)&0x3FF]; /* x4 * /
    //     v43 = (v43<<8)|a6[((v62-v44+0x20000)>>18)&0x3FF]; /* x4 * /
    //     v27[0] = v42; v27[1] = v43;
    //     v49 += 8;
    //   }
    // UNRESOLVED: Exact layout of the frequency-domain inputs a1/a2 beyond the accessed 16-bit indices (0..56 step 8) and the interpretation of the a4/a5 pointer construction are inferred, not documented.
    // UNRESOLVED: The a6 byte coefficient table and the 0x20000 rounding offset are part of the MPEG synthesis windowing; the table's provenance is not resolvable from this function alone.
    // UNRESOLVED: ABI prototype is recorded from legacy evidence only (abi:lead) and has not been independently verified.
    // UNRESOLVED: No guard conditions exist in the raw source; both loops are fixed-count with no early exit.
}
