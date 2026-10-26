// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0052835F
// Canonical corpus name: AudioFIRConvolutionFilter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AudioFIRConvolutionFilter_0052835f.c

void UnknownObject::applyFIRConvolution()
{
    // Applies a frequency-domain FIR-like convolution plus lookup-table decode to audio channel data and writes the interleaved result out. Reads a coefficient base from a2+80 and the wave-table base from a1+284 (field 0x11C, +128 offset), runs an 8-iteration channel loop that skips channels 6/4/2 and accumulates four weighted 16-bit product pairs (29692/6967/5906/10426) shifted and rounded by 4096 then >>13, then a 2-iteration output loop that looks up 8-bit samples from the wave table at (sum >>20 & 0x3FF) and writes them to a5 indexed through a4. Returns the buffer pointer after both loops.
    // ASSIGNMENT: Load v5 = *(a2 + 80) as the coefficient base and v6 = *(a1 + 284) + 128 as the wave-table base; initialize v22 = v6, output cursor v23/v7 = v21, channel counter v24 = 8, and v8/v9 = a3+48 / v5+48. [field:this:0x0000011C, source:raw]
    // GUARD: Channel guard: when v24 is 6, 4, or 2 the channel is skipped entirely; only the other channels are processed. [source:raw]
    // GUARD: Per-channel guard: when *v8 or v8[-16] or v8[16] or v8[32] is nonzero the full convolution path runs, otherwise a scaled-passthrough path is taken. [source:raw]
    // CALCULATION: Convolution accumulate: v13 = (v11 * v10) << 15 and v14 = 29692*(v8[-16]*v9[-16]) + 6967*(v8[16]*v9[16]) - 5906*(v8[32]*v9[32]) - 10426*(*v8**v9), using signed 16-bit operands. [abi:lead, source:raw]
    // ASSIGNMENT: Write the lowpass-ish sum result: *v23 = (v14 + v13 + 4096) >> 13. [source:raw]
    // ASSIGNMENT: Compute the highpass-ish difference v12 = (v13 - v14 + 4096) >> 13 (or, on the passthrough path, v12 = 4 * v11 * v10 and *v7 = v12), then store the second tap v7[8] = v12. [source:raw]
    // LOOP: Advance v8, v7, v9 each iteration, decrement v24, persist v23 = v7, and repeat while v24 > 0 across the 8 channels. [source:raw]
    // ASSIGNMENT: Output loop setup: v25 = 0, result = v21, then v16 = a5 + *(a4 + 4 * v25) selects the destination sample via the index array. [source:raw]
    // GUARD: Output guard: when any of result[0], result[1], result[3], or result[5] (dword indexing) is nonzero the FIR lookup path runs, otherwise the passthrough decode runs. [source:raw]
    // CALCULATION: FIR lookup math: v19 = v17 << 15 and v20 = 6967*result[10] + 29692*result[2] - 10426*result[6] - 5906*result[14] in signed 16-bit units. [abi:lead, source:raw]
    // ASSIGNMENT: Decode the first output byte: *v16 = byte at (((v20 + v19 + 0x80000) >> 20) & 0x3FF) + v22 from the wave table; on the passthrough path *v16 = byte at (((v17 + 16) >> 5) & 0x3FF) + v6. [field:this:0x0000011C, source:raw]
    // ASSIGNMENT: Store the second output byte v16[1] = v18, completing the interleaved pair. [source:raw]
    // LOOP: Advance result by 32 bytes, increment v25, and repeat while v25 < 2 for the two interleaved output samples. [source:raw]
    // RETURN: Return result (the advanced v21 buffer pointer) after both loops complete. [function:0x0052835F, source:raw]

    // Conservative worker pseudocode:
    //   _BYTE *applyFIRConvolution(int a1, int a2, int a3, int a4, int a5) {
    //     coeffBase = *(int*)(a2 + 80);
    //     tableBase = *(int*)(a1 + 284) + 128;
    //     v7 = v21; v22 = tableBase; v23 = v21; v24 = 8;
    //     v8 = a3 + 48; v9 = coeffBase + 48;
    //     do {
    //       if (v24 != 6 && v24 != 4 && v24 != 2) {
    //         v10 = *(short*)(v9 - 24); v11 = *(short*)(v8 - 24);
    //         if (*v8 | (unsigned short)(v8[-16] | v8[16] | v8[32])) {
    //           v13 = (v11 * v10) << 15;
    //           v14 = 29692 * (short)(v8[-16]*v9[-16]) + 6967 * (short)(v8[16]*v9[16])
    //               - 5906 * (short)(v8[32]*v9[32]) - 10426 * (short)(*v8**v9);
    //           *v23 = (v14 + v13 + 4096) >> 13;
    //           v12 = (v13 - v14 + 4096) >> 13;
    //         } else { v12 = 4 * v11 * v10; *v7 = v12; }
    //         v7[8] = v12;
    //       }
    //       ++v8; ++v7; ++v9; --v24; v23 = v7;
    //     } while (v24 > 0);
    //     result = v21; v25 = 0;
    //     do {
    //       v16 = (_BYTE*)(a5 + *(int*)(a4 + 4 * v25));
    //       if (result[5] | result[1] | result[3] | result[7]) {
    //         v19 = v17 << 15;
    //         v20 = 6967 * result[10] + 29692 * result[2] - 10426 * result[6] - 5906 * result[14];
    //         *v16 = byte[(v20 + v19 + 0x80000) >> 20 & 0x3FF) + v22];
    //         v18 = byte[((v19 - v20 + 0x80000) >> 20 & 0x3FF) + v6];
    //       } else {
    //         v18 = byte[(((v17 + 16) >> 5) & 0x3FF) + v6]; *v16 = v18;
    //       }
    //       result += 32; ++v25; v16[1] = v18;
    //     } while (v25 < 2);
    //     return result;
    //   }
    // UNRESOLVED: a2+80, a3+48, a4 index array and a5 buffer are reads/writes on pointers whose owner objects are unknown; only field 0x11C (a1+284) is in the packet field list.
    // UNRESOLVED: The exact semantic roles of the two 8-channel accumulators (v14+v13 lowpass vs v13-v14 highpass) and the channel-skip pattern (6/4/2) are not grounded in packet evidence.
}
