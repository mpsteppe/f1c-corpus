## AudioSamplePlaybackWithPitchModulationAndStereoP_00500210 — Audio sample playback with pitch modulation and stereo panning

**Summary:** Interpolates audio sample playback state: encodes progress event, blends color (RGB) and orientation data between current and target frame, clamping Euler angles to ±15.999 before quantized output. Audio sample playback system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** LinkedListIteratorWithStateUpdate (004b5760), sub_4B6360 (004b6360), sub_4B9AC0 (004b9ac0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | R | — | Current time/position value |
| this | 0x12 | R | — | Packed short component for color blending |
| this | 0x14 | R | — | Packed short component for color blending |
| this | 0x16 | R | — | Packed short component for color blending |
| this | 0x1A | R | — | Packed byte component for color |
| this | 0x1B | R | — | Packed byte for color channel |
| this | 0x1D | R | — | Short for Euler angle Y (pitch) |
| this | 0x1F | R | — | Short for Euler angle Z (roll) |
| this | 0x1B8 | R | — | Target delta position (a2 + 444 equivalent in cross-fade) |
| this | 0x1BC | R | — | Target time field (sentinel check for cross-fade) |
| this | 0x1C0 | R | — | Target short for color blending |
| this | 0x1C2 | R | — | Target short for color blending |
| this | 0x1C4 | R | — | Target short for color blending |
| this | 0x1C6 | R | — | Target short for color blending |
| this | 0x1CA | R | — | Target byte for color |
| this | 0x1CB | R | — | Target byte for color channel |
| this | 0x1CD | R | — | Target short for Euler Y |
| this | 0x1CF | R | — | Target short for Euler Z |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e714 | flt_59E714 | R | FloatToInt16QuantScale [DERIVED] |
| 0059e718 | flt_59E718 | R | AudioVolumeMul [DERIVED] |
| 0059e71c | flt_59E71C | R | Unknown_RendererFloat [DERIVED] |
| 0059e77c | flt_59E77C | R | ShortVertexScale [DERIVED] (also: ` — short-to-float scale/conversion factor) |
| 0059e780 | flt_59E780 | R | VertexScaleFactor [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b21f0 | FloatToRGBColorConversion | Convert float[3] to packed RGB color for output |
| 004b33b0 | ProgressBarEventEncode | Encode progress bar event with mode/position data |
| 004ff8f0 | AudioSampleCrossFadeInterpolation | Cross-fade interpolation when mode bits == 0 |

**Guard conditions:** If packed mode bits (`this+440 >> 18 & 0x3F`) == 0, delegate entirely to `AudioSampleCrossFadeInterpolation` (simple cross-fade). Otherwise proceed with full pitch modulation and stereo panning path. Euler angles clamped to ±15.999f before 2048-quantized output; values outside range snap to -32767 or 0x7FFF.
