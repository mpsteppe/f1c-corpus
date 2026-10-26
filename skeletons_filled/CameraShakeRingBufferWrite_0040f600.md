## CameraShakeRingBufferWrite_0040f600 — Camera Shake Ring Buffer Write / Telemetry Encode

**Summary:** Writes camera shake / vehicle telemetry data into a ring buffer (432 bytes per entry, max 1023 entries). Encodes vehicle position, orientation (as atan2 angles), velocity, and angular velocity as quantized 16-bit integers. Dispatches progress-bar HUD events based on a case-switch over a mode field at this+0x1C (cases 0-5).

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** SceneObjectLoaderStateMachine (0040f1c0), PerVehicleCameraUpdateIterator (004109d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x20) | 0x24 | R | — | source data: 3x3 rotation matrix element (row 1, col 1) at v5+4 offset |
| *(this+0x20) | 0xD8 | R | — | source data: position/velocity double at v5+68 |
| *(this+0x20) | 0xE0 | R | — | source data: position/velocity double at v5+76 |
| *(this+0x20) | 0xE8 | R | — | source data: position/velocity double at v5+28 |
| *(this+0x20) | 0xF0 | R | — | source data: position/velocity double at v5+44 |
| *(this+0x20) | 0xF8 | R | — | source data: position/velocity double at v5+92 |
| *(this+0x20) | 0x100 | R | — | source data: position/velocity double at v5+52 |
| *(this+0x20) | 0x108 | R | — | source data: position/velocity double at v5+60 |
| *(this+0x20) | 0x110 | R | — | source data: velocity double at v5+100 |
| *(this+0x20) | 0x118 | R | — | source data: velocity double at v5+108 |
| *(this+0x20) | 0x120 | R | — | source data: velocity double at v5+116 |
| *(this+0x20) | 0x130 | R | — | source data: angular velocity double at v5+124 |
| *(this+0x20) | 0x138 | R | — | source data: angular velocity double at v5+132 |
| *(this+0x20) | 0x140 | R | — | source data: angular velocity double at v5+140 |
| *(this+0x20) | 0x148 | R | — | source data: position double at v5+4 |
| *(this+0x20) | 0x150 | R | — | source data: position double at v5+12 |
| *(this+0x20) | 0x158 | R | — | source data: position double at v5+20 |
| *(this+0x20) | 0x160 | R | — | source data: position double at v5+4 (dup) |
| this | 0x8 | R | — | ring buffer entry header: mode/type identifier (word) |
| this | 0xA | RW | 0 | ring buffer entry: active/inactive flag byte (cleared each write) |
| this | 0x1C | R | — | event mode selector (0-5 for progress bar cases, default for telemetry) |
| this | 0x20 | R | — | pointer to source data structure (vehicle state) |

**Written-by note (persistence):**
- this 0xA: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0040fae4 | jpt_40F65F | R | jump table for switch-case dispatch (6 entries, cases 0-5) |
| 0059e420 | dbl_59E420 | R | BaseDoubleConstant [DERIVED] (also: ` (BaseDoubleConstant = 1.0) |
| 0059e430 | dbl_59E430 | R | ZeroSentinel [DERIVED] (also: ` (ZeroSentinel ~0.0) |
| 0059e6fc | flt_59E6FC | R | RGBChannelMultiplier [DERIVED] (also: ` — RGB channel multiplier (~255.0) |
| 0059e700 | flt_59E700 | R | UIRingBufferTimeConst [DERIVED] |
| 0059e704 | flt_59E704 | R | RaceGrid_TeamID [DERIVED] |
| 0059e708 | flt_59E708 | R | SoundVolumeLowThreshold [DERIVED] (also: ` — low threshold) |
| 0059e70c | flt_59E70C | R | FFBMinThreshold [DERIVED] (also: ` — FFB minimum threshold) |
| 0059e710 | flt_59E710 | R | FFB_SaturationThreshold [DERIVED] (also: ` — FFB maximum threshold) |
| 0059e714 | flt_59E714 | R | FloatToInt16QuantScale [DERIVED] |
| 0059e718 | flt_59E718 | R | AudioVolumeMul [DERIVED] |
| 0059e71c | flt_59E71C | R | Unknown_RendererFloat [DERIVED] |
| 007c54e4 | dword_7C54E4 | R | CurrentVehicleIndex [DERIVED] |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] |
| 0083ee60 | dword_83EE60 | RW | RingBufferCount [DERIVED] (also: ` -- ring buffer counter) |
| 008aae64 | dword_8AAE64 | RW | RingBufferWritePtr [DERIVED] (also: ` -- ring buffer offset) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b21f0 | FloatToRGBColorConversion | converts float values to RGB color components |
| 004b33b0 | ProgressBarEventEncode | encodes a progress bar HUD event with type, index, vehicle ID, value, and mode |
| 00588570 | FloatConvertWrapper | wraps float conversion (trigonometric normalization) |

**Guard conditions:** The switch at this+0x1C dispatches on cases 0-5 (progress bar events) vs default (telemetry-only encoding). Cases 0-5 call ProgressBarEventEncode with varying type indices (1-6). Ring buffer write only happens when dword_83EE60 < 1023 (ring buffer not full).
