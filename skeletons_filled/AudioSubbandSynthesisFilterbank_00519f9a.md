## AudioSubbandSynthesisFilterbank_00519f9a — MpegAudioSynthesisFilterbank

**Summary:** Performs MPEG audio subband synthesis — applies inverse quantization, inverse modified DCT, and polyphase filterbank to reconstruct PCM samples from 32 subband frequency-domain data. Part of the MPEG Layer 2/3 audio decoding subsystem.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x110) | 0x0 | R | — | output buffer base pointer for current channel |
| *(this+0x110) | 0x2 | R | — | output buffer word 1 (PCM sample destination) |
| *(this+0x110) | 0x4 | R | — | output buffer word 2 |
| *(this+0x110) | 0x10 | R | — | output buffer word 8 |
| *(this+0x110) | 0x12 | R | — | output buffer word 9 |
| *(this+0x110) | 0x20 | R | — | output buffer word 16 |
| this | 0x4 | R | — | vtable pointer for allocator/decode callbacks |
| this | 0x20 | R | — | number of audio channels |
| this | 0x24 | R | — | number of subbands (typically 32) |
| this | 0x7C | R | — | input buffer read position (frame data cursor) |
| this | 0x80 | R | — | input buffer sub-position / bit offset |
| this | 0x84 | R | — | input buffer end |
| this | 0x88 | R | — | current subband block index (0..nrof_blocks-1) |
| this | 0xC4 | R | — | pointer to per-channel synthesis state array (84 bytes per channel) |
| this | 0xD0 | R | — | per-channel state: block/gr size (offset 0xC in channel state) |
| this | 0xE0 | R | — | per-channel state: subband count (offset 0x1C in channel state) |
| this | 0xE4 | R | — | per-channel state: sample counter (offset 0x20 in channel state) |
| this | 0xE8 | R | — | per-channel state: sample stride (offset 0x24 in channel state) |
| this | 0xF4 | R | — | per-channel state: subband data pointer (offset 0x4C in channel state) |
| this | 0x110 | R | — | pointer to per-channel output buffer array (current channel) |
| this | 0x118 | R | — | number of subband blocks per channel (granule count) |
| this | 0x168 | R | — | zero-padding flag — affects output position calculation |
| this | 0x184 | R | — | offset to output buffer base (frame header parameter) |
| this | 0x18C | R | — | decode callback — fetches next granule of subband samples |
| this | 0x198 | R | — | vtable offset for PCM output callback |
| this | 0x19D | R | — | per-channel state: channel enabled flag (offset 0x30 in channel state) |
| this | 0x1CC | R | — | per-channel state: IMDCT window index / phase (offset 0x34?) |
| this | 0x1F4 | R | — | per-channel state: synthesis filter history buffer (offset 0x64?) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00515986 | sub_515986 | inverse quantization + inverse modified DCT (IMDCT) on one subband sample |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x20 | <= | 0 | channel count; if ≤0 → skip synthesis entirely (no channels to process) |
| this | 0x168 | == | 0 | zero-padding flag; if 0 → output cursor adjustment is reduced by 1 |

**Guard interpretation:** Two guard points. (1) Channel count at this+0x20: if 0 or negative, entire filterbank is skipped (no PCM output). (2) Zero-padding flag at this+0x168: controls whether `a1[32] > a1[34] + 1` or `a1[32] > a1[34] + 0` in the input-buffer drain condition; when the flag is 0, the buffer-drain threshold is relaxed by one unit, affecting when the decoder requests more frame data.
