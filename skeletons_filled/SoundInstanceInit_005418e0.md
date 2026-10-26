## SoundInstanceInit_005418e0 — 3D Sound Instance Constructor / Default Initialiser

**Summary:** Constructs a 3D sound-emitter instance with default parameter values: initialises volume, distance attenuation, cone angles, audio-device pointer, channel config, and runtime playback fields to zero; copies the sound name via strcpy; sets up 3D position/orientation to origin via UtilityFunction_1cd0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_544E90 (00544e90), sub_548AD0 (00548ad0), sub_560C10 (00560c10)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | RW | 1065353216 → 1.0f | sound volume / gain (1.0 = full volume) |
| this | 0x8 | RW | 1148846080 → 1000.0f | max attenuation distance (1000.0 world units default) |
| this | 0xC | RW | 0 | sound playback state / play counter (0 = stopped/unused) |
| this | 0x10 | RW | 0 | sound instance ID or handle (0 = unassigned) |
| this | 0x14 | RW | 0 | priority / channel assignment index |
| this | 0x18 | RW | 0 | playback cursor / time-offset within sound |
| this | 0x1C | RW | 0 | playback flags / loop count |
| this | 0x20 | RW | 0 | sound bank / group identifier |
| this | 0x3C | RW | 0 | 3D-position X (zeroed after UtilityFunction_1cd0) |
| this | 0x40 | RW | 0 | 3D-position Y (zeroed after UtilityFunction_1cd0) |
| this | 0x44 | RW | 0 | 3D-position Z (zeroed after UtilityFunction_1cd0) |
| this | 0x48 | RW | 0 | 3D-velocity / orientation field 1 |
| this | 0x4C | RW | 0 | 3D-velocity / orientation field 2 |
| this | 0x50 | RW | 0 | 3D-velocity / orientation field 3 |
| this | 0x54 | RW | 0 | sound property / effect slot 1 |
| this | 0x58 | RW | 0 | sound property / effect slot 2 |
| this | 0x5C | RW | 0 | sound property / effect slot 3 |
| this | 0x60 | RW | 0 | sound property / filter parameter 4 |
| this | 0x64 | RW | 0 | sound property / filter parameter 5 |
| this | 0x68 | RW | 0 | sound property / filter parameter 6 |
| this | 0x6C | RW | 1119092736 → 90.0f | sound cone inner angle (90 degrees) |
| this | 0x70 | RW | 1117126656 → 75.0f | sound cone outer angle / falloff angle (75 degrees) |
| this | 0x74 | RW | 1065353216 → 1.0f | sound cone outer gain / volume (1.0 = full outside cone) |
| this | 0x78 | RW | 0 | DSP effect / filter slot index |
| this | 0x7C | RW | — | pointer to audio device / mixer configuration (global dword_484848) |
| this | 0x80 | RW | 34 | audio channel count / speaker configuration (34 = stereo/surround constant) |
| this | 0x84 | RW | 18446744073709551615 | sentinel / invalid handle marker (-1 = unset) |
| this | 0x88 | RW | 1065353216 → 1.0f | master pitch / playback rate multiplier (1.0 = normal speed) |
| this | 0x19C | RW | 0 | runtime playback field 1 (late-init, zeroed) |
| this | 0x1A0 | RW | 0 | runtime playback field 2 (late-init, zeroed) |
| this | 0x1A4 | RW | 0 | runtime playback field 3 (late-init, zeroed) |
| this | 0x1A8 | RW | 0 | runtime callback / event data field 4 |
| this | 0x1AC | RW | 0 | runtime callback / event data field 5 |
| this | 0x1B0 | RW | 0 | runtime callback / event data field 6 |
| this | 0x1B4 | RW | 0 | runtime callback / event data field 7 |
| this | 0x1B8 | RW | 0 | runtime callback / event data field 8 |

**Written-by note (persistence):**
- this 0x4: written once during construction — external poke persists unless re-init called
- this 0x8: written once during construction — external poke persists unless re-init called
- this 0xC: written once during construction — external poke persists unless re-init called
- this 0x10: written once during construction — external poke persists unless re-init called
- this 0x14: written once during construction — external poke persists unless re-init called
- this 0x18: written once during construction — external poke persists unless re-init called
- this 0x1C: written once during construction — external poke persists unless re-init called
- this 0x20: written once during construction — external poke persists unless re-init called
- this 0x3C: written once during construction — external poke persists unless re-init called
- this 0x40: written once during construction — external poke persists unless re-init called
- this 0x44: written once during construction — external poke persists unless re-init called
- this 0x48: written once during construction — external poke persists unless re-init called
- this 0x4C: written once during construction — external poke persists unless re-init called
- this 0x50: written once during construction — external poke persists unless re-init called
- this 0x54: written once during construction — external poke persists unless re-init called
- this 0x58: written once during construction — external poke persists unless re-init called
- this 0x5C: written once during construction — external poke persists unless re-init called
- this 0x60: written once during construction — external poke persists unless re-init called
- this 0x64: written once during construction — external poke persists unless re-init called
- this 0x68: written once during construction — external poke persists unless re-init called
- this 0x6C: written once during construction — external poke persists unless re-init called
- this 0x70: written once during construction — external poke persists unless re-init called
- this 0x74: written once during construction — external poke persists unless re-init called
- this 0x78: written once during construction — external poke persists unless re-init called
- this 0x7C: written once during construction — external poke persists unless re-init called
- this 0x80: written once during construction — external poke persists unless re-init called
- this 0x84: written once during construction — external poke persists unless re-init called
- this 0x88: written once during construction — external poke persists unless re-init called
- this 0x19C: written once during construction — external poke persists unless re-init called
- this 0x1A0: written once during construction — external poke persists unless re-init called
- this 0x1A4: written once during construction — external poke persists unless re-init called
- this 0x1A8: written once during construction — external poke persists unless re-init called
- this 0x1AC: written once during construction — external poke persists unless re-init called
- this 0x1B0: written once during construction — external poke persists unless re-init called
- this 0x1B4: written once during construction — external poke persists unless re-init called
- this 0x1B8: written once during construction — external poke persists unless re-init called

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00484848 | dword_484848 | R | global audio-device / mixer configuration pointer (stored into instance) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00541cd0 | UtilityFunction_1cd0 | initialise 3D audio position/orientation fields to origin (all parameters passed as zero) |

**Guard conditions:** None — this is a pure initialisation constructor with unconditional writes. No branches, no early returns (except the final `return 0`).

(End of file - total 101 lines)
