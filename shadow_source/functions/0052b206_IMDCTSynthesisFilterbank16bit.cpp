// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0052B206
// Canonical corpus name: MPEGAudioLayer3IMDCT_b206
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MPEGAudioLayer3IMDCT_b206_0052b206.c

void UnknownObject::IMDCTSynthesisFilterbank16bit()
{
    // 16-bit variant of the MPEG Audio Layer 3 IMDCT synthesis filterbank, structurally a twin of IMDCTSynthesisFilterbank (0052a6ec). Stage one runs an 8-iteration butterfly over two 16-bit frequency-domain inputs (a1, a3) with reduced-precision rotation coefficients (362/473/669/277 applied with >> 8) and writes eight results to the a2 output buffer. Stage two re-reads that buffer and performs eight windowed byte-coefficient lookups into a6 (index (x >> 5) & 0x3FF) per iteration, writing eight output bytes through the a5 + a4[offset] pointer.
    // LOOP: Stage-one loop: do-while 8 iterations (v50 countdown from 8); each iteration advances input pointers a1/a3 and the output pointer v47 by one 16-bit element. [source:raw]
    // CALCULATION: Butterfly group on element indices 0/16/32/48 (a1 and a3): products a1[i]*a3[i] combined with the 362 (>>8) rotation coefficient, forming v52/v53/v57/v59/v10/v11/v54/v61. [field:this:0x00000000, field:this:0x00000020, field:this:0x00000040, field:this:0x00000060, source:raw]
    // CALCULATION: Butterfly group on element indices 8/24/40/56 (a1 and a3): products combined with rotation coefficients 473/669/277/362 (all >> 8), forming v63/v64/v20-v24/v12-v19. [field:this:0x00000010, field:this:0x00000030, field:this:0x00000050, field:this:0x00000070, source:raw]
    // ASSIGNMENT: Store eight stage-one results into the a2 output buffer as 16-bit pair sums/differences at indices 0/8/16/24/32/40/48/56: v47[0]=v57+v19, v47[56]=v57-v19, v47[8]=v61+v23, v47[48]=v61-v23, v47[16]=v54+v24, v47[40]=v54-v24, v47[32]=v59+v20, v47[24]=v59-v20. [source:raw]
    // LOOP: Stage-two loop: do-while 8 iterations (v51 countdown from 8); each iteration reads a dword index from the a4 offset table (v49 += 4) and forms the output pointer v25 = a5 + index. [source:raw]
    // CALCULATION: Second butterfly pass over the stage-one a2 buffer (v48[0..7]): recomputes the same rotation structure with coefficients 362/473/669/277 to form v55/v56/v58/v60/v62/v65-v67/v40-v43. [source:raw]
    // CALCULATION: Window lookup: eight byte coefficient reads per iteration from the a6 table at index (x >> 5) & 0x3FF, written to output bytes v25[0..7] (pair sums and differences). [source:raw]
    // RETURN: Return the stage-two loop countdown result (the final value of v51, which reaches 0). [function:0x0052B206, source:raw]
    // CALL: Invoked by RenderModeBranch (0x005285A6) to synthesize time-domain audio samples. [caller:0x005285A6, source:raw]

    // Conservative worker pseudocode:
    //   v47 = a2;
    //   for (n = 8; n; --n) {
    //     v6 = a3[32]*a1[32]; v7 = a3[48]*a1[48]; v52 = a3[0]*a1[0];
    //     v8 = v6 + v52; v53 = v52 - v6;
    //     v9 = a3[16]*a1[16]; v57 = v7 + v9 + v8; v59 = v8 - (v7 + v9);
    //     v10 = ((362*(v9 - v7)) >> 8) - (v7 + v9); v11 = v10 + v53; v54 = v53 - v10; v61 = v11;
    //     /* second group on indices 8/24/40/56 with 473/669/277/362 * /
    //     v47[0]=v57+v19; v47[56]=v57-v19; v47[8]=v61+v23; v47[48]=v61-v23;
    //     v47[16]=v54+v24; v47[40]=v54-v24; v47[32]=v59+v20; v47[24]=v59-v20;
    //     ++a1; ++a3; ++v47;
    //   }
    //   v48 = a2;
    //   for (n = 8; n; --n) {
    //     v25 = a5 + a4[i++];
    //     /* second butterfly over v48[0..7], then 8 window byte lookups (x >> 5) & 0x3FF * /
    //     v25[0] = a6[(v58+v39)>>5 & 0x3FF]; v25[7] = a6[(v58-v39)>>5 & 0x3FF];
    //     v25[1] = a6[(v62+v43)>>5 & 0x3FF]; v25[6] = a6[(v62-v43)>>5 & 0x3FF];
    //     v25[2] = a6[(v56+v40)>>5 & 0x3FF]; v25[5] = a6[(v56-v40)>>5 & 0x3FF];
    //     v25[4] = a6[(v60+v67)>>5 & 0x3FF]; v25[3] = a6[(v60-v67)>>5 & 0x3FF];
    //     v48 += 8;
    //   }
    // UNRESOLVED: Prelabel is a cluster-copy from structural twin IMDCTSynthesisFilterbank (0052a6ec) at DERIVED trust; the exact coefficient/scale differences (362/473/669/277 vs 6270/4433/15137/... and >>5 vs >>18 window indexing) are observed but not independently proven as a distinct filter variant.
    // UNRESOLVED: ABI prototype is recorded from legacy evidence only (abi:lead) and has not been independently verified.
    // UNRESOLVED: No guard conditions exist in the raw source; both loops are fixed-count with no early exit.
    // UNRESOLVED: The a6 coefficient table and the a4/a5 pointer construction share the same inference caveat as 0052a6ec.
}
