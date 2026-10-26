## sub_40CEE0_0040cee0 — Positional audio update (volume/rate/pan)

**Summary:** Updates one 3D sound using Miles AIL: computes the distance from the sound source to the listener, applies inverse distance attenuation and a directional blend (inner/outer cone volumes), then sets the sample volume, pan/level pair and playback rate and refreshes the positional state. Part of the spatial audio system.

**Called by:** sub_40D380 (0040d380), sub_40D430 (0040d430)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x54) | 0x58 | R | — | source object +88: position X of the sound source |
| *(this+0x54) | 0x5C | R | — | source object +92: position Y |
| *(this+0x54) | 0x60 | R | — | source object +96: position Z |
| *(this+0x54) | 0x70 | R | — | source object +112: cone/direction vector X |
| *(this+0x54) | 0x74 | R | — | source object +116: cone/direction vector Y |
| *(this+0x54) | 0x78 | R | — | source object +120: cone/direction vector Z |
| *(this+0x54) | 0x8C | R | — | source object +140: pitch/rate scale factor |
| *(this+0x58) | 0x10 | R | — | sample handle at this[22]+16 passed to the AIL calls |
| obj | 0x1C | R | — | this[7] — attenuation curve input |
| this | 0x0 | R | — | vtable pointer; slot 28 called to test the listener mode |
| this | 0x14 | R | — | float this[5] — compared against dword_16C9A28 (listener object pointer/mode) |
| this | 0x18 | R | — | dword this[6] — sound flags word (bits 1, 4, 8, 0x10) |
| this | 0x1C | R | — | float this[7] — distance attenuation multiplier |
| this | 0x20 | R | — | float this[8] — distance attenuation offset |
| this | 0x24 | R | — | float this[9] — extra attenuation strength |
| this | 0x28 | R | — | float this[10] — listener position X |
| this | 0x2C | R | — | float this[11] — listener position Y |
| this | 0x30 | R | — | float this[12] — listener position Z |
| this | 0x40 | R | — | float this[16] — base volume (scaled by attenuation) |
| this | 0x44 | R | — | float this[17] — pitch base factor |
| this | 0x48 | R | — | float this[18] — pitch/Doppler factor |
| this | 0x54 | R | — | this[21] — source object pointer (position and cone vectors) |
| this | 0x58 | R | — | this[22] — sample wrapper pointer (handle at +16) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f1644 | _AIL_set_sample_volume_levels@12 | R | Miles AIL import — set the sample's volume levels (left/right) |
| 006f1648 | _AIL_set_sample_playback_rate@8 | R | Miles AIL import — set the sample playback rate |
| 006f16b8 | flt_6F16B8 | R | float constant (0.6 used as the directional blend factor) |
| 006f16c8 | flt_6F16C8 | R | float constant (0.5 blend base) |
| 006f1e84 | flt_6F1E84 | R | float constant used in the attenuation math |
| 00731ce8 | String2 | R | unknown |
| 00be08a0 | dword_BE08A0 | R | RNG index/table base used by the audio random helpers |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004015c0 | sub_4015C0 | convert the pitch factor into a playback rate value |
| 0040ac90 | ScaledDotProductWithClamp [structural] | update the listener-relative position (pan/direction) |
| 0040c340 | sub_40C340 | refresh the positional sample state after the rate/volume changes |

**Guard conditions:** The listener mode at this[5] is compared to dword_16C9A28; when equal the mode comes from vtable slot 28 (`!= 1`). If `(flags & 8) == 0` the distance attenuation curve runs and the volume is recomputed only when `distance*this[7]+this[8] >= 1.0`. When the direction is available (`(flags & 4) == 0 || (flags & 8) == 0`) it recomputes the directional blend `((dot*0.6+1.0)*0.5)`. The listener update is skipped when the mode is nonzero or `(flags & 1)` is set. The sample-state refresh runs only when this[22] is non-null AND its +16 handle is non-null. The final jump targets (0x40D0C0 / 0x40D100 / 0x40D10D) select one of three continuations based on the mode and flag 0x10.

