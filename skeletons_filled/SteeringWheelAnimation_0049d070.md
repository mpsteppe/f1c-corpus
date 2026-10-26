## SteeringWheelAnimation_0049d070 — Steering wheel animation update/render

**Summary:** Renders steering wheel animation HUD element. Conditionally selects audio trigger path or sub-function chain based on engine input mode state, then updates five animation parameters via clamped lerp.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ShortComputation_f070 (0049f070)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x64) | 0x1C | R | — | sub-struct steering input field |
| *(this+0x64) | 0x20 | R | — | sub-struct steering input field |
| *(this+0xB0) | 0x54 | R | — | sub-struct animation target field |
| this | 0x4 | R | — | render context pointer (checked non-null) |
| this | 0x10 | R | — | display/UI resource pointer (checked non-null) |
| this | 0x4C | R | — | animation parameter source 0 pointer |
| this | 0x50 | R | — | animation parameter source 1 pointer |
| this | 0x54 | R | — | animation parameter source 2 pointer |
| this | 0x58 | R | — | animation parameter source 3 pointer |
| this | 0x5C | R | — | animation parameter source 4 pointer |
| this | 0x64 | R | — | sub-struct pointer (steering input data) |
| this | 0xA0 | R | — | animation target storage (via ParamRangeClampedLerp) |
| this | 0xA4 | R | — | animation target storage (via ParamRangeClampedLerp) |
| this | 0xA8 | R | — | animation target storage (via ParamRangeClampedLerp) |
| this | 0xAC | R | — | animation target storage (via ParamRangeClampedLerp) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 007c54e0 | dword_7C54E0 | R | postProcessInput [CONFIRMED] (also: unknown (near PlayerVehiclePtr +0x8)) |
| 007c9081 | byte_7C9081 | R | EngineModeFlag [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0049d280 | WheelRotationAnimation | animates wheel rotation display |
| 0049d320 | TrackPositionNameFormatter | formats track position text for HUD |
| 0049d3f0 | GlobalStateBranchFormat | formats global/race state text for HUD |
| 0049d440 | FormatRegisterDispatch | dispatches formatted register data to display |
| 0049d480 | LocalBufferSubsystemCall | calls local buffer/text subsystem |
| 0049d4c0 | sub_49D4C0 | unknown (called when formatting chain runs without audio) |
| 0049d5d0 | sub_49D5D0 | finalize/cleanup step after main rendering block |
| 0049e4e0 | AudioEffectTrigger | triggers engine/steering audio effect |
| 00543440 | RenderDrawOperationWithClipping | renders draw operation with clipping applied |

**Guard conditions:** Reads `dword_7C54E0 + 13000` (input mode value). If 0: uses `byte_7C9081` (EngineModeFlag) for v12, v15 = (flag == 0). If 1-2 and `*(dword_7C54E0 + 14752) > 0.0f`: v12=1, v15=1. Otherwise: v12=0, v15=1. Then checks `this[4]` (0x10) non-null, `*(this[4]+84)` non-null, `this[1]` (0x4) non-null — blocks entire render block if any fail. `v12` controls formatting chain: 1=run chain, 0=skip to AudioEffectTrigger only. Within chain, v15 selects AudioEffectTrigger (true) vs sub_49D4C0 (false).
