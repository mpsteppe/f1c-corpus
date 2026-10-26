// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00519019
// Canonical corpus name: sub_519019
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_519019_00519019.c

void UnknownObject::PNGIDATDecompress()
{
    // PNG image-data (IDAT) decompression driver operating on a decompression-context object at a2. It first computes per-pass dimensions for a 7-pass interlace scheme (Adam7-like) using the global lookup tables dword_5AFAA0/dword_5AFABC (pass widths) and dword_5AFAD8/dword_5AFAF4 (pass heights), storing them at +208 and +204. If the data has not been decompressed yet (byte at +92 bit 0x20 clear), it loops reading IDAT chunks through a callback, feeds them to sub_517ADC (inflate), and aborts via GuardedCallWithLongjmp on short data, decompression errors, or trailing data. On completion it sets the done flags (+88 bit 8, +92 bit 0x20), resets the stream via ResourceResetWithCounter, and returns the final status. Invoked by sub_511B7C (00511B7C).
    // ASSIGNMENT: v2 = a2; result = &dword[+212]; increment the dword at +212 (row/chunk processing counter) [source:raw]
    // GUARD: Guard: process only when the counter at +212 reaches the value at +192 (expected row count) [source:raw]
    // GUARD: Guard on the interlace byte at +275: when set, compute per-pass dimensions before decompressing [source:raw]
    // ASSIGNMENT: Reset the counter at +212 to 0 and zero the scanline/pass buffer at the pointer stored at +216, size (+200)+1, via MemsetWithByteFill (00517F04) [callee:0x00517F04, source:raw]
    // LOOP: Loop over the 7 interlace passes: pass v4 = ++byte[+276]; break when v4 reaches 7 [source:raw]
    // CALCULATION: Compute pass width: result = (dword[+184] - dword_5AFAA0[v4] + dword_5AFABC[v4] - 1) / dword_5AFABC[v4]; store dword[+208] = result [global:0x005AFAA0, global:0x005AFABC, source:raw]
    // CALCULATION: Compute pass row byte size: v5 = ((result * byte[+281] + 7) >> 3) + 1; store dword[+204] = v5 [source:raw]
    // GUARD: Guard on byte at +96 bit 2 clear: compute pass height result = (dword[+188] - dword_5AFAD8[v4] + dword_5AFAF4[v4] - 1) / dword_5AFAF4[v4], store dword[+192] = result, and continue the pass loop when dword[+208] == 0 [global:0x005AFAD8, global:0x005AFAF4, source:raw]
    // RETURN: Return the computed pass dimension (interlace path returns per-pass result) [function:0x00519019, source:raw]
    // GUARD: Guard on byte at +92 bit 0x20 clear: decompression has not yet completed, run the inflate loop [source:raw]
    // ASSIGNMENT: Initialize the inflate state: store &a2 at +112 and set the flag at +116 to 1 [source:raw]
    // LOOP: Outer inflate loop: runs until sub_517ADC (00517ADC) reports completion (returns 1) [source:raw]
    // GUARD: When the input-buffer count at +104 is 0, fetch the next chunk: inner loop while the pending count at +252 is 0 [source:raw]
    // CALL: Call sub_518828 (00518828) with (a2, 0) before reading the next chunk [callee:0x00518828, source:raw]
    // CALL: Call CallbackDispatchWithNullGuard (00513BD1) with (a2, v12, 4) to obtain 4 chunk-length bytes [callee:0x00513BD1, source:raw]
    // ASSIGNMENT: Store the pending chunk byte count at +252 = ByteArrayToInt(v12) (00517F35) [callee:0x00517F35, source:raw]
    // CALL: Call AnimationHandleAlloc (00513CD8) with the context [callee:0x00513CD8, source:raw]
    // CALL: Call sub_517F58 (00517F58) with (a2, a2+268, 4) to read the 4-byte chunk type into +268 [callee:0x00517F58, source:raw]
    // GUARD: If the chunk type at +268 is not the 'IDAT' literal (global aIdat_0), abort via GuardedCallWithLongjmp (00511869) with the 'Not enough image data' message (global aNotEnoughImage) [callee:0x00511869, global:0x005AFB10, global:0x005AF3B4, source:raw]
    // ASSIGNMENT: Prepare the input window: dword[+104] = dword[+160]; dword[+100] = dword[+156]; clamp dword[+104] to dword[+252] when dword[+160] exceeds it [source:raw]
    // CALL: Call sub_517F58 (00517F58) with (a2, dword[+156], dword[+104]) to fetch the compressed bytes [callee:0x00517F58, source:raw]
    // CALCULATION: Decrease the pending chunk count: dword[+252] -= dword[+104] [source:raw]
    // CALL: Call sub_517ADC (00517ADC) with the stream window at +100 and flag 1; returns v10 (1 = decompression complete) [callee:0x00517ADC, source:raw]
    // GUARD: If v10 == 1, break the outer inflate loop (done) [source:raw]
    // GUARD: If v10 is nonzero, abort: take the error string at +124 (defaulting to the 'Decompression Error' literal at aDecompressionE_0) and call GuardedCallWithLongjmp (00511869) [callee:0x00511869, global:0x005AFF88, source:raw]
    // GUARD: If the flag at +116 is 0, abort via GuardedCallWithLongjmp (00511869) with the 'Extra compressed data' literal (aExtraCompresse) [callee:0x00511869, global:0x005AF388, source:raw]
    // GUARD: After the loop, if flag +116 is 0 or the counts at +104/+252 are nonzero, abort via GuardedCallWithLongjmp (00511869) with 'Extra compressed data' [callee:0x00511869, global:0x005AF388, source:raw]
    // STATE_TRANSITION: Mark decompression complete: dword[+88] |= 8; dword[+92] |= 0x20; dword[+116] = 0 [source:raw]
    // GUARD: If the counts at +252 or +104 are nonzero after completion, abort via GuardedCallWithLongjmp (00511869) with 'Extra compression data' (aExtraCompressi) [callee:0x00511869, global:0x005AFF70, source:raw]
    // CALL: Reset the stream: result = ResourceResetWithCounter (00517963) on the window at +100; then dword[+88] |= 8 [callee:0x00517963, source:raw]
    // RETURN: Return the final result (decompression status) [function:0x00519019, source:raw]
    // CALL: Invoked by sub_511B7C (00511B7C) to drive IDAT decompression [caller:0x00511B7C, source:raw]

    // Conservative worker pseudocode:
    //   v2 = a2;
    //   ++dword(v2+212);
    //   if (dword(v2+212) >= dword(v2+192)) {
    //     if (byte(v2+275)) {
    //       dword(v2+212) = 0;
    //       MemsetWithByteFill(a1, v2, *(char**)(v2+216), 0, dword(v2+200)+1);
    //       while (1) {
    //         v4 = ++byte(v2+276);
    //         if (v4 >= 7) break;
    //         result = (dword(v2+184) - dword_5AFAA0[v4] + dword_5AFABC[v4] - 1) / dword_5AFABC[v4];
    //         dword(v2+208) = result;
    //         dword(v2+204) = ((result * byte(v2+281) + 7) >> 3) + 1;
    //         if ((byte(v2+96) & 2) == 0) {
    //           result = (dword(v2+188) - dword_5AFAD8[v4] + dword_5AFAF4[v4] - 1) / dword_5AFAF4[v4];
    //           dword(v2+192) = result;
    //           if (dword(v2+208) == 0) continue;
    //         }
    //         return result;
    //       }
    //     }
    //     if ((byte(v2+92) & 0x20) == 0) {
    //       dword(v2+112) = &a2; dword(v2+116) = 1;
    //       while (1) {
    //         if (dword(v2+104) == 0) {
    //           while (dword(v2+252) == 0) {
    //             sub_518828(v2, 0);
    //             CallbackDispatchWithNullGuard(v2, v12, 4);
    //             dword(v2+252) = ByteArrayToInt(v12);
    //             AnimationHandleAlloc(v2);
    //             sub_517F58(v2, v2+268, 4);
    //             if (dword(v2+268) != *(int*)"IDAT")
    //               GuardedCallWithLongjmp(v2, "Not enough image data");
    //           }
    //           dword(v2+104) = dword(v2+160); dword(v2+100) = dword(v2+156);
    //           if (dword(v2+160) > dword(v2+252)) dword(v2+104) = dword(v2+252);
    //           sub_517F58(v2, dword(v2+156), dword(v2+104));
    //           dword(v2+252) -= dword(v2+104);
    //         }
    //         v10 = sub_517ADC((unsigned char**)(v2+100), 1);
    //         if (v10 == 1) break;
    //         if (v10) {
    //           v11 = *(char**)(v2+124);
    //           if (!v11) v11 = "Decompression Error";
    //           GuardedCallWithLongjmp(v2, v11);
    //         }
    //         if (dword(v2+116) == 0) GuardedCallWithLongjmp(v2, "Extra compressed data");
    //       }
    //       if (dword(v2+116) == 0 || dword(v2+104) || dword(v2+252))
    //         GuardedCallWithLongjmp(v2, "Extra compressed data");
    //       dword(v2+88) |= 8; dword(v2+92) |= 0x20; dword(v2+116) = 0;
    //     }
    //     if (dword(v2+252) || dword(v2+104))
    //       GuardedCallWithLongjmp(v2, "Extra compression data");
    //     result = ResourceResetWithCounter((_DWORD*)(v2+100));
    //     dword(v2+88) |= 8;
    //   }
    //   return result;
    // UNRESOLVED: The decompression context is accessed only through raw pointer offsets at a2; no struct type is recovered for it in this packet
    // UNRESOLVED: The pairing of the global tables (dword_5AFAA0/dword_5AFABC for pass widths and dword_5AFAD8/dword_5AFAF4 for pass heights) as Adam7-style interlace tables is inferred from the 7-pass structure and is DERIVED, not independently proven
    // UNRESOLVED: Whether sub_517ADC is the inflate primitive itself or a wrapper is not verifiable from this function alone
}
