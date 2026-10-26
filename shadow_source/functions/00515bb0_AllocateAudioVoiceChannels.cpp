// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00515BB0
// Canonical corpus name: AudioVoiceChannelAllocation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AudioVoiceChannelAllocation_00515bb0.c

void UnknownObject::AllocateAudioVoiceChannels()
{
    // Negotiates and allocates audio voice channels. For mode this+0x120 == 1 a single stream is copied directly into the negotiated fields; otherwise invalid modes (<= 0 or > 4) report an error through the object vtable at this+0x0, and valid multi-stream modes compute per-stream voice counts with ceiling division (callee 0x00515917), fill each stream descriptor's allocation fields, cap the total voice-slot count at 10, and record the stream index into the voice-slot table at this+0x140 onward.
    // ASSIGNMENT: Read the mode selector v1 from a1[72] at this+0x120. [field:this:0x00000120, source:raw]
    // GUARD: Branch when v1 == 1: take the single-stream fast path that bypasses ceiling-division negotiation. [field:this:0x00000120, source:raw]
    // ASSIGNMENT: Single-stream path: copy the descriptor values into the negotiated fields this+0x134 = descriptor+0x1C, this+0x138 = descriptor+0x20, set this+0x13C = 1 (voice slot count) and this+0x140 = 0; initialize descriptor allocation fields descriptor+0x40 = descriptor+0x24, descriptor+0x34/0x38/0x3C/0x44 = 1, and descriptor+0x48 = floored sample remainder. [field:this:0x00000134, field:this:0x00000138, field:this:0x0000013C, field:this:0x00000140, field:*(this+0x124):0x0000001C, field:*(this+0x124):0x00000020, field:*(this+0x124):0x00000024, field:*(this+0x124):0x00000040, field:*(this+0x124):0x00000034, field:*(this+0x124):0x00000038, field:*(this+0x124):0x0000003C, field:*(this+0x124):0x00000044, field:*(this+0x124):0x00000048, source:raw]
    // CALCULATION: Single-stream sample distribution: result = descriptor+0x20 / descriptor+0xC, remainder v5 = descriptor+0x20 % descriptor+0xC floored up to descriptor+0xC when zero, stored to descriptor+0x48. [field:*(this+0x124):0x00000020, field:*(this+0x124):0x0000000C, field:*(this+0x124):0x00000048, source:raw]
    // GUARD: Reject invalid modes: v1 <= 0 or v1 > 4 reports an allocation error. [field:this:0x00000120, source:raw]
    // ASSIGNMENT: Fill the error report record on the object behind this+0x0: obj+0x14 = 24, obj+0x18 = v1 (a1[72]), obj+0x1C = 4. [field:obj:0x00000014, field:obj:0x00000018, field:obj:0x0000001C, field:this:0x00000120, source:raw]
    // CALL: Dispatch the error through the vtable pointer at obj+0x0 (this+0x0), passing a1 as the sole argument. [field:obj:0x00000000, field:this:0x00000000, source:raw]
    // CALCULATION: Negotiate multi-stream totals with ceiling division: this+0x134 = CeilingDivision(this+0x18, 8 * this+0x10C), this+0x138 = CeilingDivision(this+0x1C, 8 * this+0x110), and reset this+0x13C = 0. [callee:0x00515917, field:this:0x00000134, field:this:0x00000138, field:this:0x0000013C, field:this:0x00000018, field:this:0x0000001C, field:this:0x0000010C, field:this:0x00000110, source:raw]
    // GUARD: Guard on this+0x120 <= 0: skip stream iteration entirely when no streams are active. [guard:0, field:this:0x00000120, source:raw]
    // LOOP: Iterate the stream descriptor pointer list starting at this+0x124 (a1 + 73) into the this+0x130 region, one entry per stream, while the stream index stays below a1[72]. [field:this:0x00000124, field:this:0x00000130, source:raw]
    // CALCULATION: Per-stream allocation math on the descriptor: descriptor+0x40 = blockAlign(descriptor+0x8) * multiplier(descriptor+0x24); descriptor+0x34 = descriptor+0x8; descriptor+0x38 = descriptor+0xC; descriptor+0x3C = descriptor+0x8 * descriptor+0xC; descriptor+0x44 = descriptor+0x1C % descriptor+0x8 (floored to descriptor+0x8 when zero); descriptor+0x48 = descriptor+0x20 % descriptor+0xC (floored to descriptor+0xC when zero). [field:*(this+0x124):0x00000008, field:*(this+0x124):0x0000000C, field:*(this+0x124):0x0000001C, field:*(this+0x124):0x00000020, field:*(this+0x124):0x00000024, field:*(this+0x124):0x00000034, field:*(this+0x124):0x00000038, field:*(this+0x124):0x0000003C, field:*(this+0x124):0x00000040, field:*(this+0x124):0x00000044, field:*(this+0x124):0x00000048, source:raw]
    // GUARD: Cap the total voice-slot count: when the accumulated slot count (this+0x13C plus this stream's voice count descriptor+0x3C) exceeds 10, report the overflow error. [field:this:0x0000013C, field:obj:0x00000014, source:raw]
    // CALL: Dispatch the voice-cap overflow error through the vtable pointer at obj+0x0 (this+0x0). [field:obj:0x00000000, field:this:0x00000000, source:raw]
    // LOOP: Fill the voice-slot table: write the stream index v16 into a1[this+0x13C++ + 80], covering this+0x140 and the following slot region (this+0x144, this+0x148, this+0x158, this+0x15C, this+0x160, this+0x164, this+0x168) while per-stream voices remain. [field:this:0x00000140, field:this:0x00000144, field:this:0x00000148, field:this:0x00000158, field:this:0x0000015C, field:this:0x00000160, field:this:0x00000164, field:this:0x00000168, source:raw]
    // RETURN: Return the final allocation result (last negotiated or computed value). [source:raw]

    // Conservative worker pseudocode:
    //   int AllocateAudioVoiceChannels(int *audio) {
    //     int mode = audio[72];
    //     if (mode == 1) {
    //       int *sd = (int*)audio[73];
    //       audio[77] = sd[7]; audio[78] = sd[8];
    //       unsigned m = sd[3]; sd[16] = sd[9];
    //       sd[13] = sd[14] = sd[15] = sd[17] = 1;
    //       int r = sd[8] % m; sd[18] = r ? r : m;
    //       audio[80] = 0; audio[79] = 1;
    //     } else {
    //       if (mode <= 0 || mode > 4) report_error(24, mode, 4);
    //       audio[77] = CeilingDivision(audio[6], 8 * audio[67]);
    //       audio[78] = CeilingDivision(audio[7], 8 * audio[68]);
    //       audio[79] = 0;
    //       int n = 0;
    //       int *p = audio + 73;
    //       while (n < audio[72]) {
    //         int *sd = (int*)*p;
    //         int ba = *(int*)(*p + 8); int ch = *(int*)(*p + 12);
    //         sd[16] = ba * *(int*)(*p + 36);
    //         sd[14] = ch; sd[13] = ba; int voices = ba * ch; sd[15] = voices;
    //         int r1 = sd[7] % ba; sd[17] = r1 ? r1 : ba;
    //         int r2 = sd[8] % sd[3]; sd[18] = r2 ? r2 : sd[3];
    //         if (voices + audio[79] > 10) report_error(11, 0, 0);
    //         while (voices > 0) { audio[audio[79]++ + 80] = n; --voices; }
    //         ++n; ++p;
    //       }
    //     }
    //     return result;
    //   }
    // UNRESOLVED: this+0x16C is not referenced by the reconstructed body; it may belong to a following stream slot or a neighboring member.
    // UNRESOLVED: The vtable error dispatcher at this+0x0 is an opaque handler supplied by the owning audio object; its target address is not visible in this function.
    // UNRESOLVED: The exact descriptor object type behind this+0x124 and the meaning of the multiplier field descriptor+0x24 are unknown.
    // UNRESOLVED: The 8 x channel-count scaling on this+0x10C / this+0x110 assumes bytes-per-frame semantics that are not proven by packet evidence.
}
