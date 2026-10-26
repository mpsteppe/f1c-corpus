// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0052E6F0
// Canonical corpus name: CompressedAudioDecoder
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CompressedAudioDecoder_0052e6f0.c

void UnknownObject::DecodeCompressedAudioFrame()
{
    // Decodes one frame of compressed audio from the input bitstream into 16-bit PCM output. Returns -1 when the bitstream buffer pointer (this[2345]) is null. When the codec is initialized (dword_8B0108 nonzero) it reads nibble-coded selectors, decodes Huffman-coded VQ index pairs (stereo, mode 2) or single-selector VQ (mono) via DecodeHuffmanPair and table lookups, then resamples 12 blocks with AudioResampler. When uninitialized it reads raw selectors (8-bit split in stereo, 4-bit in mono), dequantizes against flt_5B11A4 and converts 12 blocks with AudioMixerFloatingPointTo16BitPCMConversion. The output cursor advances by 2*this[2356] per block. Called by sub_52DF10.
    // GUARD: Load the input bitstream buffer pointer this[2345]; when null, return -1 immediately. [field:this:0x000024A4]
    // GUARD: Branch on the codec-initialized flag dword_8B0108: nonzero selects the table/Huffman decode path, zero selects the raw uninitialized decode path. [global:0x008B0108]
    // GUARD: Mode guard on this[2355] == 2 (stereo) versus mono: stereo reads two nibbles per byte and processes paired channels, mono reads one nibble stream. [field:this:0x000024CC, guard:0]
    // CALCULATION: Read selector nibbles from the bitstream at buffer + (cursor >> 3): each byte splits into a high and a low nibble; the block consumes 256 bits (stereo) or 128 bits (mono) of cursor advance on this[2346]. [field:this:0x000024A4, field:this:0x000024A8]
    // CALCULATION: For each nonzero selector, read a 6-bit VLC value from the bitstream via a byte-swapped big-endian shift (byteswap >> (6 - cursor & 7)) masked to 6 bits; each such read advances the cursor by 6 bits. Values land in the selector-index workspace (stack v162 in the initialized path, dword_8B0124 in the raw path). [field:this:0x000024A8, field:this:0x000024A4, global:0x008B0124]
    // LOOP: Stereo initialized path: 12 iterations, each calling DecodeHuffmanPair 32 times (pair index 0..31) against codebook table unk_5B2BA4, decoding Huffman-coded VQ index pairs into successive 128-byte blocks. [callee:0x0052E5E0, global:0x005B2BA4]
    // LOOP: Stereo initialized path: 12 iterations of AudioResampler, resampling each decoded 128-sample block to the output buffer; the output pointer advances by 2*this[2356] per block. [callee:0x00532AA0, field:this:0x000024D0]
    // CALCULATION: Mono initialized path: 12 blocks of 30-sample VQ decode. Each selector reads Huffman bits using the length/code table dword_5B4788[sel+1] and the base table dword_5B4820[sel], indexed into codebook dword_5B2CA4[64*sel + index], producing 16-bit output words per block. [global:0x005B4788, global:0x005B4820, global:0x005B2CA4]
    // CALCULATION: Raw (uninitialized) selector read: stereo reads one byte per sample and splits it into two 4-bit nibbles (advancing 8 bits); mono reads 4 bits per sample (advancing 4 bits). Selectors are stored in workspace unk_8B0324. [global:0x008B0324]
    // CALCULATION: Raw (uninitialized) dequantize: 12 blocks of 32 samples; each nonzero selector computes a residual against workspace dword_8B0224 and scales it by the float table flt_5B11A4[64*sel + code] into float sample workspace. [global:0x008B0224, global:0x005B11A4]
    // LOOP: Raw path: 12 iterations of AudioMixerFloatingPointTo16BitPCMConversion converting each float sample block to 16-bit PCM at the output pointer, which advances by 2*this[2356] per block. [callee:0x00531830, field:this:0x000024D0]
    // RETURN: Return 0 on success after the decode loops, or -1 when no input bitstream buffer is present. [field:this:0x000024A4]
    // CALL: Invoked by sub_52DF10 (0052df10) to decode one frame of compressed audio. [caller:0x0052DF10]

    // Conservative worker pseudocode:
    //   if (this[2345] == 0) return -1;
    //   if (dword_8B0108) {
    //     if (this[2355] == 2) {
    //       read 32 selector nibble pairs; cursor += 256 bits;
    //       read 6-bit VLC values for nonzero selectors;
    //       for (b = 0; b < 12; ++b)
    //         for (i = 0; i < 32; ++i) DecodeHuffmanPair(this, i, ..., &unk_5B2BA4);
    //       for (b = 0; b < 12; ++b) AudioResampler(out, block);
    //     } else {
    //       read selectors + 6-bit VLC;
    //       for (b = 0; b < 12; ++b) {
    //         for (s = 0; s < 30; ++s)
    //           if (sel[s]) word = huffman_vq(dword_5B4788, dword_5B4820, dword_5B2CA4);
    //       }
    //       for (b = 0; b < 12; ++b) AudioResampler(out, block);
    //     }
    //   } else {
    //     read raw selectors (8-bit split stereo / 4-bit mono) into unk_8B0324;
    //     read 6-bit VLC into dword_8B0124;
    //     for (b = 0; b < 12; ++b) {
    //       for (s = 0; s < 32; ++s)
    //         sample[s] = (residual(dword_8B0224) ) * flt_5B11A4[64*sel + code];
    //       AudioMixerFloatingPointTo16BitPCMConversion(out, sample);
    //     }
    //   }
    //   return 0;
    // UNRESOLVED: Three read-only dword globals (dword_5B4798, dword_5B47A0, dword_5B47A8) are flagged by the packet facts but do not appear in the raw decompiled source; their roles (possible table pointers folded into indexed expressions) are not verifiable here.
    // UNRESOLVED: The exact compressed-audio codec variant (Huffman-coded VQ with 6-bit VLC selectors) is inferred from the decode shape; the format name and bit layout beyond 4/6/8-bit reads are unknown.
    // UNRESOLVED: The mono initialized path outputs are consumed by AudioResampler directly from the stack words; the stereo/raw paths differ in block stride (128 vs 64), which is not reconciled here.
}
