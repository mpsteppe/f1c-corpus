// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00532AA0
// Canonical corpus name: AudioResampler
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AudioResampler_00532aa0.c

void UnknownObject::AudioResampler()
{
    // MMX-accelerated polyphase audio resampler. Decrements and masks a 4-bit phase counter at this+0x24BC, then, while the channel count at this+0x24CC is positive, iterates channels and calls F_3DTransformWithSIMD (00534120) on each source block. Per block it applies a pmaddwd/packssdw convolution: a stereo path when the channel count equals 2 uses the coefficient tables unk_8B3724 (544-byte phase stride) and unk_8B1924 (480-byte phase stride), while the mono path uses unk_5B730C (2-byte back-offset stride). Convolution results are packed and written as interleaved 16-bit PCM to the output word pointer. Invoked by CompressedAudioDecoder (0052E6F0) and TextureDecompression_1250 (00531250) during audio decode.
    // CALCULATION: Phase counter advance: reads the byte at this+0x24BC, decrements it and masks to 4 bits, writes the result back; the masked phase selects an even/odd offset used to index the coefficient tables [field:this:0x000024BC, source:raw]
    // GUARD: Processing runs only while the signed channel count at this+0x24CC is greater than 0 (packet guard) [guard:1, field:this:0x000024CC]
    // LOOP: Per-channel loop: iterates once per channel, using the count at this+0x24CC, advancing the transform argument and output pointer by fixed strides each iteration [field:this:0x000024CC, source:raw]
    // CALL: F_3DTransformWithSIMD (00534120) applied to each channel's block; the transform argument is offset by the live phase counter byte at this+0x24BC [callee:0x00534120, field:this:0x000024BC, source:raw]
    // GUARD: Within a channel, the convolution splits on whether the channel count at this+0x24CC equals 2: equal selects the stereo coefficient path, otherwise the mono path is used (packet guard) [guard:0, field:this:0x000024CC]
    // CALCULATION: Stereo convolution: 16-bit multiply-add (pmaddwd) and multiply-high (pmulhw) accumulation of the transform block against the unk_8B3724 table (544 * phase) and unk_8B1924 table (480 * phase), with packssdw conversion, written as interleaved 16-bit PCM to the output pointer [global:0x008B3724, global:0x008B1924, guard:0]
    // CALCULATION: Mono convolution: same pmaddwd/pmulhw accumulation against the unk_5B730C mono coefficient table, addressed with a 2-byte back-offset scaled by the phase, written as single-channel PCM [global:0x005B730C, source:raw]
    // RETURN: Returns the terminal channel iteration count (derived from the this+0x24CC loop bound) [function:0x00532AA0, source:raw]
    // CALL: Invoked by CompressedAudioDecoder (0052E6F0) and TextureDecompression_1250 (00531250) as part of the audio decode/render path [caller:0x0052E6F0, caller:0x00531250]

    // Conservative worker pseudocode:
    //   phase = ((byte)this[0x24BC] - 1) & 0xF;
    //   this[0x24BC] = phase;
    //   index = phase + (phase & 1 ? 0 : 1);
    //   if (this[0x24CC] > 0) {
    //     for (ch = 0; ch < this[0x24CC]; ++ch) {
    //       F_3DTransformWithSIMD(src + ((phase + this[0x24BC]) & 0xF), dst, arg);
    //       if (dst) {
    //         if (this[0x24CC] == 2) {
    //           stereo MMX convolution via unk_8B3724 + 544*index and unk_8B1924 + 480*index;
    //         } else {
    //           mono MMX convolution via unk_5B730C - 2*index;
    //         }
    //         pack and write 16-bit PCM samples to dst;
    //       }
    //       src += 1152; dst++; arg += 64;
    //     }
    //   }
    //   return ch;
    // UNRESOLVED: The mono convolution's raw source reads a family of contiguous coefficient tables around unk_5B6F0C through unk_5B72A4; the packet lists only unk_5B730C, so the region is treated as one evidence ref
    // UNRESOLVED: The stereo tap count (68 taps for the second table region) and the meaning of the 0x10 shift in the pmulhw paths are unverified
    // UNRESOLVED: Channel count at this+0x24CC being a signed count rather than a flag is a DERIVED interpretation of the >0 and ==2 guards
}
