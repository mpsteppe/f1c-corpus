## AudioMixerFloatingPointTo16BitPCMConversion_00531830 — Float MDCT mix to 16-bit PCM

**Summary:** Converts floating-point MDCT-transformed audio samples to 16-bit PCM output. Runs MDCT transform per channel, applies matrix mixing with coefficients from unk_5B666C, clamps to signed 16-bit range [-32768, 32767], and writes interleaved stereo/mono output. Core audio mixer stage.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CompressedAudioDecoder (0052e6f0), TextureDecompression_1250 (00531250)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x24BC | RW | — | phase/counter (this[2351], this+9404), 4-bit decrementing ring counter |
| this | 0x24CC | R | — | channel count / sample stride (this[2355], this+9420) |

**Written-by note (persistence):**
- this 0x24BC: decremented and masked to 4 bits each call; phase advances cyclically

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005b666c | unk_5B666C | R | AudioMixCoeffTable [DERIVED] — coefficient table base for audio mixing |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00531b50 | F_32PointMDCTAudioTransform | apply 32-point MDCT (Modified Discrete Cosine Transform) to audio buffer |

**Guard conditions:** Entire processing loop skipped when this[0x24CC] (channel count) <= 0. When a2 (output PCM buffer) is NULL, MDCT transform is still called but PCM conversion + clamping is skipped.
