// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0051EA90
// Canonical corpus name: CodecModeSelect
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CodecModeSelect_0051ea90.c

void UnknownObject::CodecModeSelect()
{
    // Selects a codec/processing mode for an audio-style buffer: reads the mode selector at this+0x4C and the channel count at this+0x64 (== 3), then assigns a codec function pointer (TableWeightedMix, ChecksumComputeType03Stream, ChecksumComputeType1, AudioSynthesis3ChannelSampleGenerator, or PixelDataConvolutionViaLookupTable) into the sub-buffer at this+0x1A4 (offset +4) according to mode/channel combination. Modes 1 and 2 additionally perform conditional sub-buffer initialization: mode 1 zeros sub-buffer+48 and, when sub-buffer+28 is clear, calls sub_51E3E7, and when sub-buffer+52 is clear, calls PerIndexTableGenerationWithDivision; mode 2 zeros sub-buffer+84 and, when sub-buffer+68 is clear, calls VirtualArrayFill, then MemoryZeroFill clears each of this+0x64 entries of size 2*this+0x5C+4. Mode >= 3 sets the object error code to 47 (obj+0x14) and invokes the virtual handler through the vtable at this+0x0.
    // ASSIGNMENT: Copy mode/format information from the sub-buffer into the parent: this+0x74 = sub-buffer+16 (this+0x1B4) and this+0x70 = sub-buffer+20 (this+0x1B8). [field:this:0x000001A4, field:this:0x000001B4, field:this:0x000001B8, field:this:0x00000074, field:this:0x00000070, source:raw]
    // GUARD: Dispatch on the mode selector this+0x4C: 0 -> base assignment path, 1 -> channel-count path, 2 -> convolution/zero-fill path, >=3 -> error path. [field:this:0x0000004C, source:raw]
    // ASSIGNMENT: Mode 0: when the channel count this+0x64 == 3 (guard), install ChecksumComputeType03Stream; otherwise install TableWeightedMix into sub-buffer+4 (this+0x1A8). [field:this:0x00000064, field:this:0x000001A8, global:0x0051E65F, global:0x0051E5D7, guard:0, source:raw]
    // ASSIGNMENT: Mode 1: when this+0x64 == 3 install AudioSynthesis3ChannelSampleGenerator, else install ChecksumComputeType1, into sub-buffer+4 (this+0x1A8); then zero sub-buffer+48 (this+0x1D4). [field:this:0x00000064, field:this:0x000001A8, global:0x0051E7D7, global:0x0051E6EC, field:this:0x000001D4, guard:0, source:raw]
    // CALL: Mode 1: when sub-buffer+28 (this+0x1C0) is zero, initialize via sub_51E3E7(a1). [field:this:0x000001C0, callee:0x0051E3E7, guard:1, source:raw]
    // CALL: Mode 1: when sub-buffer+52 (this+0x1D8) is zero, generate a per-index table via PerIndexTableGenerationWithDivision(a1). [field:this:0x000001D8, callee:0x0051E512, source:raw]
    // ASSIGNMENT: Mode 2: install PixelDataConvolutionViaLookupTable into sub-buffer+4 (this+0x1A8) and zero sub-buffer+84 (this+0x1F8). [field:this:0x000001A8, global:0x0051E8D6, field:this:0x000001F8, source:raw]
    // CALL: Mode 2: when sub-buffer+68 (this+0x1E8) is zero, allocate/fill the virtual array via VirtualArrayFill(a1). [field:this:0x000001E8, callee:0x0051EA5A, guard:2, source:raw]
    // LOOP: Mode 2: for each of this+0x64 entries, MemoryZeroFill the entry pointer (advancing through the sub-buffer+68 array) with size 2*this+0x5C + 4. [callee:0x005159A8, field:this:0x00000064, field:this:0x0000005C, source:raw]
    // STATE_TRANSITION: Mode >=3 (unknown selector): set the object error code to 47 at obj+0x14 (obj = vtable at this+0x0) and invoke the virtual error handler (*(obj))(a1). [field:obj:0x00000000, field:obj:0x00000014, field:this:0x00000000, source:raw]

    // Conservative worker pseudocode:
    //   void sub_51EA90(int a1) {
    //     int sub = *(DWORD*)(a1 + 0x1A4);
    //     *(DWORD*)(a1 + 0x74) = *(DWORD*)(sub + 16);
    //     *(DWORD*)(a1 + 0x70) = *(DWORD*)(sub + 20);
    //     int mode = *(DWORD*)(a1 + 0x4C);
    //     if (mode != 0) {
    //       if (mode != 1) {
    //         if (mode == 2) {
    //           *(BYTE*)(sub + 84) = 0;
    //           *(DWORD*)(sub + 4) = PixelDataConvolutionViaLookupTable;
    //           if (*(DWORD*)(sub + 68) == 0) VirtualArrayFill(a1);
    //           int size = 2 * *(DWORD*)(a1 + 0x5C) + 4;
    //           for (int i = 0; i < *(DWORD*)(a1 + 0x64); ++i)
    //             MemoryZeroFill(*(DWORD**)(sub + 68 + 4*i), size);
    //         } else {
    //           *(DWORD*)(*(DWORD*)a1 + 20) = 47;
    //           (*(void (__cdecl **)(int))*a1)(a1);
    //         }
    //       } else {
    //         *(DWORD*)(sub + 4) = (*(DWORD*)(a1 + 0x64) == 3)
    //           ? AudioSynthesis3ChannelSampleGenerator : ChecksumComputeType1;
    //         *(DWORD*)(sub + 48) = 0;
    //         if (*(BYTE*)(sub + 28) == 0) sub_51E3E7(a1);
    //         if (*(DWORD*)(sub + 52) == 0) PerIndexTableGenerationWithDivision(a1);
    //       }
    //     } else {
    //       *(DWORD*)(sub + 4) = (*(DWORD*)(a1 + 0x64) == 3)
    //         ? ChecksumComputeType03Stream : TableWeightedMix;
    //     }
    //   }
    // UNRESOLVED: The legacy ABI label Codec_Mode_Select is consistent with the reading but carries LEGACY trust; the exact codec semantics of each selected function pointer (TableWeightedMix, ChecksumComputeType1/03Stream, AudioSynthesis3ChannelSampleGenerator, PixelDataConvolutionViaLookupTable) are not grounded by this packet.
    // UNRESOLVED: Fields this+0x1A8, this+0x1B4, this+0x1B8, this+0x1C0, this+0x1D4, this+0x1D8, this+0x1E8, this+0x1F8 are folded sub-buffer-relative offsets (sub-buffer = *(this+0x1A4)); the field naming as this-based offsets is the extractor's flattening, not evidence of a this-sized struct at those addresses.
    // UNRESOLVED: The meaning of the mode values themselves (0/1/2 vs >=3) and the semantic distinction between ChecksumComputeType03Stream and ChecksumComputeType1 is unknown.
    // UNRESOLVED: The virtual handler invoked on the error path (mode >=3) is the same vtable call seen elsewhere in the corpus; its identity is unproven here.
}
