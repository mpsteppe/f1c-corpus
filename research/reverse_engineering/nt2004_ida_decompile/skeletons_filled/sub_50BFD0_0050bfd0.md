## sub_50BFD0_0050bfd0 — PostProcessVehicleVisuals

**Summary:** Post-physics vehicle update handling cockpit detection, damage animations, steering indicator, and flap state transitions. Updates per-wheel sub-structures (4 wheels × 304-byte stride), checks cockpit camera mode, processes smoothed steering input with exponential moving average, and dispatches conditional animation/state changes via ConditionalDispatchByFlag.

**Called by:** sub_51CDC0 (0051cdc0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x62A0 | R | — | Vehicle ID field at +25248 — compared for player-vehicle check |
| this | 0x0 | R | — | Vehicle root pointer — dereferenced for ID comparison |
| this | 0x4-0x18 | R | — | Position/orientation values passed to sub_59E170 for main body |
| this | 0x1D8-0x1F8 | R | — | Wheel sub-struct fields at +472 region — per-wheel position/orientation passed to sub_59E170 |
| this | 0x9F0-0xA08 | R | — | Smoothed steering input fields — this+705 (raw), this+706 (smoothed), this+708-710 (axis) |
| this | 0xA28 | R | — | Count of front flap elements (this+650) — guarded > 0 for loop |
| this | 0xA2C | R | — | Front flap data array base (this+2604) |
| this | 0xA38 | R | — | Front flap state array base (this+2616) |
| this | 0xA60 | R | — | Count of rear flap elements (this+664) |
| this | 0xA64 | R | — | Rear flap data array base (this+2660) |
| this | 0xA70 | R | — | Rear flap state array base (this+2672) |
| this | 0xA98 | RW | 1 | Flap activation flag (this+2712) — set to 0 when vehicle matches player, 1 otherwise |
| this | 0xB00 | R | — | Flag at this+636 — enables flap processing |
| this | 0xB04 | R | — | Flag at this+637 — enables flap processing |
| this | 0xB08 | RW | — | Flap state at this+638 — updated via sub_5A2930 |
| this | 0xB10 | R | — | Flag at this+640 — enables cockpit mode check |
| this | 0xB14 | R | — | Flag at this+641 — enables secondary state toggle |
| this | 0xB18 | R | — | Flag at this+642 — enables lap-based state |
| this | 0xB34 | R | — | State byte at this+2884 — previous flap toggle state |
| this | 0xB3D | R | — | State byte at this+2885 — secondary toggle input |
| this | 0xB44 | RW | — | State byte at this+2884 — updated flap toggle state (compared to previous) |
| this | 0xB45 | R | — | State byte at this+2886 — condition for flap activation |
| this | 0xB46 | R | — | State byte at this+2887 — previous secondary toggle state |
| this | 0xB47 | RW | — | State byte at this+2887 — updated secondary toggle state |
| this | 0xB48 | R | — | State byte at this+2888 — alternate flap trigger condition |
| this | 0xB4C | R | — | Float at this+723 — threshold for fmod comparison |
| this | 0xB54 | RW | — | Float at this+725 — lap-based index counter |
| this | 0xB58 | R | — | Float at this+726 — base time reference for lap counter |
| this | 0xB5C | R | — | Float at this+727 — threshold for lap counter range |

**Written-by note (persistence):**
- this 0xA98: conditional — written when vehicle not matching player; poke survives until player state changes
- this 0xB08: conditional — written when state changes; poke survives until next toggle
- this 0xB44: conditional — written when flap state differs; poke survives
- this 0xB47: conditional — written when secondary state differs; poke survives
- this 0xB54: conditional — written when lap index changes; poke survives

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005fb99c | aCockpit | R | String "Cockpit" — compared against camera mode name |
| 006291cc | dword_6291CC | R | Camera mode pointer — passed to sub_40C460 for cockpit check |
| 0075aac0 | dword_75AAC0 | R | Active vehicle index |
| 0075aad0 | dword_75AAD0 | R | Vehicle array — used to compare vehicle IDs |
| 00767b5c | flt_767B5C | R | Scaling factor for lap-based counter |
| 00767bec | dword_767BEC | R | Flag — > 0 contributes to player-vehicle check |
| 007680e4 | dword_7680E4 | R | Flag — controls wheel processing path |
| 00768108 | dword_768108 | R | Flag — !dword_768108 && cockpit → short-circuit |
| 007d5da4 | dword_7D5DA4 | R | State value — == 2 triggers alternate path |
| 007d5dac | dword_7D5DAC | R | Data container for sub_4D9E20 time query |
| 007da9d0 | dbl_7DA9D0 | R | Global timer/clock — used for fmod and lap timing |
| 007dab04 | flt_7DAB04 | R | Input A for average calculation |
| 007dab08 | flt_7DAB08 | R | Input B for average calculation |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040c460 | sub_40C460 | Get camera mode object from dword_6291CC |
| 00459b80 | PathAccessor_28e0 [structural] | Get camera mode name string from camera object |
| 00459bc0 | sub_459BC0 | Extract vector and flags from camera object |
| 004d9e20 | sub_4D9E20 | Query float value from dword_7D5DAC |
| 004eed40 | sub_4EED40 | Query boolean from vehicle root — selects raw vs smoothed steering |
| 0050c800 | sub_50C800 | Update per-wheel sub-struct with float parameter |
| 0050e400 | sub_50E400 | Reset/initialize per-wheel sub-struct (called in loops of 4) |
| 00579930 | sub_579930 | Convert axis-angle to rotation matrix for steering indicator |
| 0059e0f0 | sub_59E0F0 | Apply rotation matrix for steering indicator |
| 0059e170 | sub_59E170 | Update position/orientation with 6 float params |
| 005a2930 | sub_5A2930 | Trigger state change callback with boolean and two flags |
| 005adbf0 | ConditionalDispatchByFlag [exact] | Dispatch flap animation update with flag, state pointer, and value |
| 005bf290 | __strcmpi | Compare camera mode name against "Cockpit" |
| 005c057a | __CIfmod | Floating-point modulo for periodic flap toggle |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0xA28 | > | 0 | Front flap count > 0 — enables front flap animation loop |
| this | 0xA60 | > | 0 | Rear flap count > 0 — enables rear flap animation loop |

**Guard interpretation:** Main processing gated by: (NOT cockpit mode) AND (player vehicle OR global state == 2). Per-wheel sub-structs updated unconditionally (4 wheels). Flap animations: when vehicle matches player, use v42+0.975 as parameter; when not matching and not yet activated, use 1.0 and set activation flag. Cockpit toggle: fmod-based periodic check vs threshold 0.335, alternate toggle via average of two inputs.
