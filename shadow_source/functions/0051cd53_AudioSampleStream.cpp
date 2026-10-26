// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0051CD53
// Canonical corpus name: AudioSampleStream
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AudioSampleStream_0051cd53.c

void UnknownObject::AudioSampleStream()
{
    // Streams audio samples from input a5 to an output via a sub-struct v7 at this+0x19C, handling partial reads with a single-sample buffer. When the pending flag at v7+0x24 is set, flushes the buffered sample through F_2DArrayBlockCopy and clears the flag. Otherwise computes how many samples to advance (1 or 2, clamped by remaining count v7+0x2C and the a7 - *a6 budget), reads one or two source samples, and dispatches them through the indirect function pointer at v7+0xC. Always advances *a6 by v9 and decrements the remaining count v7+0x2C; when no sample was buffered, advances the stream pointer *a3.
    // ASSIGNMENT: Load v7 = *(this + 0x19C), the audio stream sub-struct pointer [field:this:0x0000019C, source:raw]
    // GUARD: If the pending-sample flag at v7 + 0x24 (offset 0x24) is non-zero, flush the buffered sample; otherwise read fresh samples [field:*(this+0x19C):0x00000024, source:raw]
    // ASSIGNMENT: Set v9 = 1 for the flush path [source:raw]
    // CALL: Call F_2DArrayBlockCopy (0x0051593F) with the pending-sample buffer at v7 + 0x20, destination a5 + 4 * *a6, and the block-copy size at v7 + 0x28 [callee:0x0051593F, field:*(this+0x19C):0x00000020, field:*(this+0x19C):0x00000028, source:raw]
    // ASSIGNMENT: Clear the pending flag at v7 + 0x24 to 0 [field:*(this+0x19C):0x00000024, source:raw]
    // CALCULATION: Else path: default v9 = 2 samples [source:raw]
    // GUARD: If the remaining count at v7 + 0x2C (offset 0x2C) is less than 2, clamp v9 down to that remaining count [guard:0, field:*(this+0x19C):0x0000002C, source:raw]
    // CALCULATION: Compute v14 = a7 - *a6 and clamp v9 to it (v9 = min(v9, v14)) [source:raw]
    // ASSIGNMENT: Read the first source sample v12 = *(a5 + 4 * *a6) [source:raw]
    // GUARD: If v9 <= 1, buffer the single pending sample: store the value from v7 + 0x20 into v13 and set the pending flag at v7 + 0x24 to 1 [field:*(this+0x19C):0x00000020, field:*(this+0x19C):0x00000024, source:raw]
    // ASSIGNMENT: Otherwise read the second sample v13 = v11[1] from the input buffer [source:raw]
    // CALL: Dispatch the sample pair through the indirect function pointer at v7 + 0xC (offset 0xC), called with (a1, a2, *a3, &v12) [field:*(this+0x19C):0x0000000C, source:raw]
    // ASSIGNMENT: Advance the sample counter: *a6 += v9 [source:raw]
    // CALCULATION: Decrement the remaining count at v7 + 0x2C by v9 [field:*(this+0x19C):0x0000002C, source:raw]
    // GUARD: If the pending flag at v7 + 0x24 is still zero (nothing buffered this call), advance the stream cursor *a3 by 1 [field:*(this+0x19C):0x00000024, source:raw]
    // RETURN: Return result: a3 when the stream cursor was advanced, otherwise the F_2DArrayBlockCopy / dispatch call result [source:raw]

    // Conservative worker pseudocode:
    //   // stream samples; buffer a single partial sample when only 1 is available
    //   v7 = *(DWORD*)(this + 412);
    //   if (*(BYTE*)(v7 + 36)) {
    //     v9 = 1;
    //     result = F_2DArrayBlockCopy(v7 + 32, 0, a5 + 4 * *a6, 0, 1, *(DWORD*)(v7 + 40));
    //     *(BYTE*)(v7 + 36) = 0;
    //   } else {
    //     v9 = 2;
    //     if (*(DWORD*)(v7 + 44) < 2)
    //       v9 = *(DWORD*)(v7 + 44);
    //     v14 = a7 - *a6;
    //     if (v9 > v14)
    //       v9 = v14;
    //     v11 = (int*)(a5 + 4 * *a6);
    //     v12 = *v11;
    //     if (v9 <= 1) {
    //       v13 = *(DWORD*)(v7 + 32);
    //       *(BYTE*)(v7 + 36) = 1;
    //     } else {
    //       v13 = v11[1];
    //     }
    //     result = (*(DWORD**)(v7 + 12))(a1, a2, *a3, &v12);
    //   }
    //   *a6 += v9;
    //   *(DWORD*)(v7 + 44) -= v9;
    //   if (!*(BYTE*)(v7 + 36)) {
    //     result = a3;
    //     *a3 = (char*)*a3 + 1;
    //   }
    //   return result;
    // UNRESOLVED: The dispatch function pointer at v7 + 0xC is an indirect call target not resolvable from this packet.
    // UNRESOLVED: The relationship between the 412-byte base offset (0x19C) and any containing class is unknown.
    // UNRESOLVED: The exact meaning of the F_2DArrayBlockCopy size argument at v7 + 0x28 and the returned a3 cursor advance is inferred, not proven by runtime evidence.
}
