## CMpegBase_ProcessHeader_0052da30 — MPEGAudioHeaderParser

**Summary:** Parses a 32-bit MPEG audio frame header, extracting layer, bitrate, sampling rate, channel mode, protection, and other fields into the decoder state structure. Computes frame size and samples-per-frame from lookup tables. Part of the MPEG audio decoding subsystem.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** MediaFileDecodeHeader (0052dc90), BitstreamDecoder_dd50 (0052dd50), NetworkPacketSend (0052ddc0), NetworkColorIsDefault (0052de00), ArithmeticComparison_de40 (0052de40)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x2484 | RW | — | bitrate value (bps, from table lookup dword_5B4764[bitrate_index]) |
| this | 0x2488 | RW | — | duplicate copy of bitrate value (used as denominator in frame-size calc) |
| this | 0x2490 | RW | — | MPEG layer index (4 - ((header>>17)&3): 1=Layer3, 2=Layer2, 3=Layer1) |
| this | 0x2494 | RW | — | frame size in bytes (from table word_5B4684 indexed by params) |
| this | 0x2498 | RW | — | computed frame size minus 4 bytes (adjusted for padding/correction) |
| this | 0x24BD | RW | 1 | original/copyright flag (set from sampling rate index decode) |
| this | 0x24BE | RW | 1 | sampling rate flag (set from header bits; guard checks != 0 before bitrate calc) |
| this | 0x24BF | RW | — | emphasis value (computed from sampling rate + mode extension bits) |
| this | 0x24C1 | RW | — | emphasis flag (from header bit 19: (a2 & 0x80000) != 0) |
| this | 0x24C2 | RW | — | copyright flag (from header byte 2 bit 0) |
| this | 0x24C3 | RW | — | bitrate index (from header bits 12-15: (a2>>12) & 0xF) |
| this | 0x24C4 | RW | — | bitrate index byte (stored for table lookup, adjusted by sampling rate) |
| this | 0x24C5 | RW | — | protection bit (from header bit 9: (a2 & 0x200) != 0) |
| this | 0x24C6 | RW | — | channel mode (from header bits 6-7: (a2>>6) & 3; 0=stereo, 1=joint, 2=dual, 3=mono) |
| this | 0x24C7 | RW | — | mode extension (from header bits 4-5: (a2>>4) & 3, for joint stereo) |
| this | 0x24C8 | RW | — | original/media flag (from header bit 3: (a2 & 8) != 0) |
| this | 0x24C9 | RW | — | emphasis flag (from header bit 2: (a2 & 4) != 0) |
| this | 0x24CC | RW | — | number of channels (1 for mono, 2 for stereo/joint/dual) |
| this | 0x24D0 | RW | — | PCM samples per frame (32 * num_channels) |

**Written-by note (persistence):**
- All fields: once (written unconditionally each time a header is parsed; external writes survive between frames)

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005b4684 | word_5B4684 | R | Unknown_Word_5B4684 [DERIVED] |
| 005b4764 | dword_5B4764 | R | Dword_EncodingConstant [DERIVED] |
| 005da564 | aSDS_0 | R | sSDS_Format [DERIVED] |
| 005da574 | aDDevAudiodevSh | R | AudioDevicePath [DERIVED] |
| 005da5a4 | aCmpegbaseProce | R | CmpegBaseProceString [DERIVED] |
| 005da5e0 | aAudioAssert | R | StrAudioAssert [DERIVED] |
| 005da714 | off_5DA714 | R | AssertHaltFuncPtr [DERIVED] |
| 005da718 | off_5DA718 | R | FileStreamVTable [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0052e4e0 | sub_52E4E0 | unknown (called externally, not in this function's C) |
| 0052e520 | HaltAssertHandler | called via off_5DA714 function pointer; logs assert message and halts on bad header |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x24BE | != | 0 | sampling rate flag: PASSES when sampling rate is determined, enabling bitrate table lookup path |

**Guard interpretation:** this+0x24BE != 0 → PASSES: sampling rate identified, proceeds to compute bitrate_index with adjustment offset; BLOCKED: skips the adjusted bitrate path and falls through to simpler computation
