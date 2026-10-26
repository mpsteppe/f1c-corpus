## FloatToRGBColorConversion_004b21f0 — Float to packed RGB color conversion

**Summary:** Converts 3 float color channel values (R, G, B) to a packed 40-bit color format by clamping to [-65536, 65536] range, scaling by 32768, and packing into 3 output dword/byte fields. Part of rendering/color pipeline.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** CameraShakeRingBufferWrite (0040f600), VectorToShort3Conversion (004b2c80), AudioSamplePlaybackWithPitchModulationAndStereoP (00500210)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Packed color word 0 (R and G channels combined) |
| this | 0x4 | RW | — | Packed color word 1 (B and G channels combined) |
| this | 0x8 | RW | — | Packed color byte 2 (high byte of B channel) |

**Written-by note (persistence):**
- this 0x0: recalc every frame — external poke does NOT persist
- this 0x4: recalc every frame — external poke does NOT persist
- this 0x8: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005acc84 | flt_5ACC84 | R | ColorChannelMultiplier [DERIVED] (also: ` — color multiplier (float) |
| 005acc88 | flt_5ACC88 | R | ColorConvClampLower [DERIVED] |
| 005acc8c | flt_5ACC8C | R | ColorQuantize_Max [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Float input values are clamped to [-65535.988, 65535.988] before scaling — values outside range are saturated to INT_MIN/INT_MAX.
