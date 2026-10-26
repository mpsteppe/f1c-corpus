## AudioResampler_00532aa0 — MMX-accelerated audio resampler

**Summary:** Resamples audio via MMX-accelerated polyphase filter matrix multiplication. Reads phase counter, calls F_3DTransformWithSIMD for frequency-domain transform, then applies MMX pmaddwd convolution with coefficient tables (stereo: unk_8B3724, mono: unk_5B730C + unk_5B6F0C). Writes interleaved 16-bit PCM output.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CompressedAudioDecoder (0052e6f0), TextureDecompression_1250 (00531250)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x24BC | RW | — | phase/counter (this+9404), 4-bit decrementing ring offset for polyphase filter |
| this | 0x24CC | R | — | channel count / sample stride (this+9420), ==2 selects stereo coefficient path |

**Written-by note (persistence):**
- this 0x24BC: decremented and masked to 4 bits each call; phase advances cyclically

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005b730c | unk_5B730C | R | AudioDSPTable [DERIVED] — mono polyphase coefficient table |
| 008b1924 | unk_8B1924 | R | AudioWavetableBuffer [DERIVED] — stereo coefficient table (480*phase offset) |
| 008b3724 | unk_8B3724 | R | Unk_MMX_Const [DERIVED] — stereo MMX convolution constants (544*phase offset) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00534120 | F_3DTransformWithSIMD | apply MMX-based frequency-domain transform (subband synthesis) |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x24CC | == | 2 | channel count (this+9420) |
| this | 0x24CC | > | 0 | channel count (this+9420) |

**Guard interpretation:** Entire processing loop skipped when this[0x24CC] (channel count) <= 0. When a2 (output PCM buffer) is NULL, F_3DTransformWithSIMD is called but PCM output mixing is skipped. When this[0x24CC] == 2, uses stereo coefficient path (unk_8B3724, 2-channel interleave with phase-dependent sub-band mixing). When != 2, uses mono path (unk_5B730C + unk_5B6F0C tables).
