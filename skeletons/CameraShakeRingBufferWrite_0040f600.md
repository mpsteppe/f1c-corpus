## CameraShakeRingBufferWrite_0040f600 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** SceneObjectLoaderStateMachine (0040f1c0), PerVehicleCameraUpdateIterator (004109d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x20) | 0x24 | R | — | [LLM] |
| *(this+0x20) | 0xD8 | R | — | [LLM] |
| *(this+0x20) | 0xE0 | R | — | [LLM] |
| *(this+0x20) | 0xE8 | R | — | [LLM] |
| *(this+0x20) | 0xF0 | R | — | [LLM] |
| *(this+0x20) | 0x100 | R | — | [LLM] |
| *(this+0x20) | 0x108 | R | — | [LLM] |
| *(this+0x20) | 0x110 | R | — | [LLM] |
| *(this+0x20) | 0x118 | R | — | [LLM] |
| *(this+0x20) | 0x120 | R | — | [LLM] |
| *(this+0x20) | 0x130 | R | — | [LLM] |
| *(this+0x20) | 0x138 | R | — | [LLM] |
| *(this+0x20) | 0x140 | R | — | [LLM] |
| *(this+0x20) | 0x148 | R | — | [LLM] |
| *(this+0x20) | 0x150 | R | — | [LLM] |
| *(this+0x20) | 0x158 | R | — | [LLM] |
| *(this+0x20) | 0x160 | R | — | [LLM] |
| this | 0x8 | R | — | [LLM] |
| this | 0xA | RW | 0 | [LLM] |
| this | 0x1C | R | — | [LLM] |
| this | 0x20 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0xA: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0040fae4 | jpt_40F65F | R | [LLM] |
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
| 004b21f0 | FloatToRGBColorConversion | [LLM] |
| 004b33b0 | ProgressBarEventEncode | [LLM] |
| 00588570 | FloatConvertWrapper | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
