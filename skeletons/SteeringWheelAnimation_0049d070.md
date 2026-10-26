## SteeringWheelAnimation_0049d070 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ShortComputation_f070 (0049f070)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x64) | 0x1C | R | — | [LLM] |
| *(this+0x64) | 0x20 | R | — | [LLM] |
| *(this+0xB0) | 0x54 | R | — | [LLM] |
| this | 0x4 | R | — | [LLM] |
| this | 0x10 | R | — | [LLM] |
| this | 0x4C | R | — | [LLM] |
| this | 0x50 | R | — | [LLM] |
| this | 0x54 | R | — | [LLM] |
| this | 0x58 | R | — | [LLM] |
| this | 0x5C | R | — | [LLM] |
| this | 0x64 | R | — | [LLM] |
| this | 0xA0 | R | — | [LLM] |
| this | 0xA4 | R | — | [LLM] |
| this | 0xA8 | R | — | [LLM] |
| this | 0xAC | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 007c54e0 | dword_7C54E0 | R | postProcessInput [CONFIRMED] (also: unknown (near PlayerVehiclePtr +0x8)) |
| 007c9081 | byte_7C9081 | R | EngineModeFlag [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0049d280 | WheelRotationAnimation | [LLM] |
| 0049d320 | TrackPositionNameFormatter | [LLM] |
| 0049d3f0 | GlobalStateBranchFormat | [LLM] |
| 0049d440 | FormatRegisterDispatch | [LLM] |
| 0049d480 | LocalBufferSubsystemCall | [LLM] |
| 0049d4c0 | sub_49D4C0 | [LLM] |
| 0049d5d0 | sub_49D5D0 | [LLM] |
| 0049e4e0 | AudioEffectTrigger | [LLM] |
| 00543440 | RenderDrawOperationWithClipping | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
