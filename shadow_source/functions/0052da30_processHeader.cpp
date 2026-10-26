// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0052DA30
// Canonical corpus name: CMpegBase_ProcessHeader
// Owner: CMpegBase [DERIVED]
// Raw source: functions/CMpegBase_ProcessHeader_0052da30.c

void CMpegBase::processHeader()
{
    // Parses a 32-bit MPEG audio frame header a2 into the decoder state object at this: validates the 0xFFF00000 sync-word pattern, extracts layer, bitrate, sampling-rate, channel-mode and flag fields, derives the bitrate and frame-size from lookup tables word_5B4684/dword_5B4764, and returns 0 on success or -1 on invalid header or on the assert path.
    // GUARD: Validate the header sync word: if (a2 & 0xFFF00000) != 0xFFF00000, return -1 immediately. [source:raw]
    // ASSIGNMENT: Decode and store the MPEG layer index: v11 = 4 - ((a2 >> 17) & 3) written to this+0x2490. [field:this:0x00002490, source:raw]
    // ASSIGNMENT: Extract header fields into state bytes: channel mode (a2>>6)&3 to 0x24C6, mode extension (a2>>4)&3 to 0x24C7, protection flag (a2&0x200)!=0 to 0x24C5, copyright flag BYTE2(a2)&1 to 0x24C2, original flag (a2&8)!=0 to 0x24C8, emphasis flag (a2&4)!=0 to 0x24C9, emphasis flag (a2&0x80000)!=0 to 0x24C1, and bitrate index (a2>>12)&0xF to 0x24C3. [field:this:0x000024C6, field:this:0x000024C7, field:this:0x000024C5, field:this:0x000024C2, field:this:0x000024C8, field:this:0x000024C9, field:this:0x000024C1, field:this:0x000024C3, source:raw]
    // ASSIGNMENT: Decode sampling-rate dependent flags: if (a2 & 0x100000) is set write this+0x24BE = (a2 & 0x80000) == 0 and this+0x24BD = 0; otherwise write this+0x24BE = 1 and this+0x24BD = 1. [field:this:0x000024BE, field:this:0x000024BD, source:raw]
    // GUARD: Branch on the stored sampling-rate flag (deterministic guard record: this+0x24BE != 0; the raw source reads this+0x24BD for this condition) to select the bitrate-index adjustment path. [guard:0, field:this:0x000024BE, field:this:0x000024BD, source:raw]
    // ASSIGNMENT: Compute and store the bitrate index: when the flag is set, this+0x24C4 = ((a2>>10)&3) + 6; otherwise this+0x24C4 = ((a2>>10)&3) + 3 * this+0x24BE and this+0x24BF = ((a2>>10)&3) + (this+0x24BE ? 0 : 3). [field:this:0x000024C4, field:this:0x000024BE, field:this:0x000024BF, field:this:0x000024BD, source:raw]
    // ASSIGNMENT: Compute channel count v4 = (channel-mode != 3) + 1, store to this+0x24CC, and PCM samples-per-frame = 32 * v4 stored to this+0x24D0. [field:this:0x000024CC, field:this:0x000024D0, source:raw]
    // CALCULATION: Look up the bitrate from dword_5B4764[bitrate index this+0x24C4] and store the result into both this+0x2484 and this+0x2488 (bitrate value and its copy used as a denominator). [global:0x005B4764, field:this:0x00002484, field:this:0x00002488, field:this:0x000024C4, source:raw]
    // CALCULATION: When bitrate index v3 (this+0x24C3) is nonzero, look up the frame size from word_5B4684[48 * this+0x24BE + 16 * v11 + v3] and store it to this+0x2494. [global:0x005B4684, field:this:0x00002494, field:this:0x000024BE, field:this:0x000024C3, source:raw]
    // CALCULATION: Compute the final frame size into this+0x2498 using layer-specific formulas: for v11 == 1, 4 * (padding + 12000 * frame_size / bitrate) - 4; otherwise 144000 * frame_size / bitrate, incremented when protection flag (0x24C5) is set, then decremented by 4. Return 0 on success. [field:this:0x00002498, field:this:0x00002488, field:this:0x00002494, field:this:0x000024C5, source:raw]
    // CALL: Assert path when bitrate index v3 is zero: call off_5DA714 with aAudioAssert, then off_5DA714 with format string aSDS_0 and args aDDevAudiodevSh, 1310, aCmpegbaseProce, then off_5DA718, and return -1. HaltAssertHandler is reached through the off_5DA714/off_5DA718 function-pointer path (DERIVED). [global:0x005DA5E0, global:0x005DA564, global:0x005DA574, global:0x005DA5A4, global:0x005DA714, global:0x005DA718, callee:0x0052E520, source:raw]

    // Conservative worker pseudocode:
    //   int processHeader(int this, unsigned int hdr) {
    //     if ((hdr & 0xFFF00000) != 0xFFF00000) return -1;
    //     this+0x2490 = 4 - ((hdr >> 17) & 3);
    //     this+0x24C6 = (hdr >> 6) & 3;
    //     this+0x24C7 = (hdr >> 4) & 3;
    //     this+0x24C5 = (hdr & 0x200) != 0;
    //     this+0x24C2 = (hdr >> 16) & 1;
    //     this+0x24C8 = (hdr & 8) != 0;
    //     this+0x24C9 = (hdr & 4) != 0;
    //     this+0x24C1 = (hdr & 0x80000) != 0;
    //     this+0x24C3 = (hdr >> 12) & 0xF;
    //     if (hdr & 0x100000) { this+0x24BE = (hdr & 0x80000) == 0; this+0x24BD = 0; }
    //     else { this+0x24BE = 1; this+0x24BD = 1; }
    //     if (this+0x24BD) this+0x24C4 = ((hdr >> 10) & 3) + 6;
    //     else { int t = (hdr >> 10) & 3; this+0x24C4 = t + 3 * this+0x24BE; this+0x24BF = t + (this+0x24BE ? 0 : 3); }
    //     int channels = (this+0x24C6 != 3) + 1;
    //     this+0x24CC = channels;
    //     this+0x24D0 = 32 * channels;
    //     int bitrate = dword_5B4764[this+0x24C4];
    //     this+0x2484 = bitrate;
    //     this+0x2488 = bitrate;
    //     if (this+0x24C3) {
    //       this+0x2494 = word_5B4684[48 * this+0x24BE + 16 * this+0x2490 + this+0x24C3];
    //       if (this+0x2490 == 1)
    //         this+0x2498 = 4 * (this+0x24C5 + 12000 * this+0x2494 / this+0x2488) - 4;
    //       else {
    //         this+0x2498 = 144000 * this+0x2494 / this+0x2488;
    //         if (this+0x24C5) this+0x2498 += 1;
    //         this+0x2498 -= 4;
    //       }
    //       return 0;
    //     }
    //     off_5DA714(aAudioAssert);
    //     off_5DA714("%s(%d) : %s\n", aDDevAudiodevSh, 1310, aCmpegbaseProce);
    //     off_5DA718();
    //     return -1;
    //   }
    // UNRESOLVED: Callee sub_52E4E0 appears in the callee record but has no visible direct call in the raw source; it may be a second indirect target of the off_5DA714/off_5DA718 function pointers, but its role here is not deterministically established.
    // UNRESOLVED: The deterministic guard record flags this+0x24BE != 0, while the raw source branch condition reads this+0x24BD; the two offsets differ by one byte and the exact flag selected by the extraction is not fully reconciled.
    // UNRESOLVED: Semantic labels of the individual flag bytes (protection/copyright/original/emphasis) are DERIVED prose from the existing fill, not proven by this packet.
}
