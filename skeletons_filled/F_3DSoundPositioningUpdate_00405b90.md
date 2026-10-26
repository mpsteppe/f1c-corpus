## F_3DSoundPositioningUpdate_00405b90 — 3D Audio Position/Attenuation Update

**Summary:** Computes 3D spatial audio parameters (distance attenuation, stereo pan, Doppler pitch shift) for a positional sound source relative to a listener, then applies them via Miles AIL API calls (volume, playback rate, position). Part of the Miles/3D audio subsystem.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** MilesAudioSamplePlaybackSetup (00405900)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x54) | 0x58 | R | — | listener/target position X (world coordinate) |
| *(this+0x54) | 0x5C | R | — | listener/target position Y (world coordinate) |
| *(this+0x54) | 0x60 | R | — | listener/target position Z (world coordinate) |
| *(this+0x54) | 0x8C | R | — | Doppler/pitch reference speed factor from target |
| *(this+0x58) | 0x10 | R | — | AIL sample handle (HSAMPLE) for the audio sample |
| obj | 0x1C | R | — | vtable method at index 7 — state query (returns 1 if condition prevents playback) |
| this | 0x0 | R | — | vtable pointer (used for virtual call at offset 0x1C/28) |
| this | 0x14 | R | — | sound state flag (1 = active/already playing; triggers vtable re-check) |
| this | 0x18 | R | — | behavior bitmask flags (bit0=skip pan, bit2=skip attenuation, bit3=skip distance, bit4=randomized position) |
| this | 0x28 | R | — | sound source position X (world coordinate) |
| this | 0x2C | R | — | sound source position Y (world coordinate) |
| this | 0x30 | R | — | sound source position Z (world coordinate) |
| this | 0x40 | R | — | base volume/attenuation level (float) |
| this | 0x44 | R | — | playback rate multiplier component A (float) |
| this | 0x48 | R | — | playback rate multiplier component B (float) |
| this | 0x54 | R | — | pointer to listener/target object (has position + Doppler data) |
| this | 0x58 | R | — | pointer to sample wrapper object (contains AIL HSAMPLE handle) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e3b8 | _AIL_set_sample_volume_levels@12 | R | Miles AIL API — sets left/right volume for stereo panning |
| 0059e3bc | _AIL_set_sample_playback_rate@8 | R | Miles AIL API — sets sample playback rate (Doppler effect) |
| 0059e3c0 | _AIL_set_sample_position@8 | R | Miles AIL API — sets sample playback position (random offset) |
| 0059e3c4 | _AIL_start_sample@4 | R | Miles AIL API — starts sample playback |
| 0059e3d4 | _AIL_resume_sample@4 | R | Miles AIL API — resumes a paused/stopped sample |
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 008aae70 | dword_8AAE70 | RW | RingBufferCounter (QA/weather noise) [DERIVED] |
| 008aae74 | flt_8AAE74 | R | TrigLookup256 [DERIVED] (also: ` — 256-entry trig lookup table) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00405f80 | ScaledDotProductWithClamp | computes scaled dot product of direction vector with listener orientation for stereo pan |
| 00406020 | SmoothstepInterpolation | smooths distance value for attenuation falloff curve |
| 00406060 | DotProductWithScaleOffset | computes dot product with scale/offset to derive volume attenuation factor |
| 00406100 | ShortComputation_6100 | updates internal sound state (likely advances playback position tracking) |
| 00587bdc | CRTFtol | C runtime float-to-long conversion (used for sample position from trig lookup) |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x14 | == | 1 | sound state flag: 1 = already active, triggers vtable re-check; != 1 = inactive, treated as needing start |

**Guard interpretation:** When this+0x14 == 1 (sound marked active), an additional vtable method check runs — if it returns 1, v3 becomes 0 (block playback); otherwise v3 stays 1 (allow). When this+0x14 != 1, v3 remains 1 unconditionally (always allow). v3=0 suppresses ScaledDotProductWithClamp pan computation and skips sample start/resume. v3=1 triggers AIL_start_sample or AIL_resume_sample (depending on bit 4 of bitmask) and uses random position if bit 4 is set.
