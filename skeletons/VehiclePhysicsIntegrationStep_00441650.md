## VehiclePhysicsIntegrationStep_00441650 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehiclePhysicsModeDispatcher (004e4930)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x15F0) | 0x4 | R | — | [LLM] |
| *(this+0x15F0) | 0xC | R | — | [LLM] |
| *(this+0x15F0) | 0x14 | R | — | [LLM] |
| *(this+0x15F0) | 0x1C | R | — | [LLM] |
| *(this+0x15F0) | 0x24 | R | — | [LLM] |
| *(this+0x15F0) | 0x2C | R | — | [LLM] |
| *(this+0x15F0) | 0x34 | R | — | [LLM] |
| *(this+0x15F0) | 0x3C | R | — | [LLM] |
| *(this+0x15F0) | 0x44 | R | — | [LLM] |
| *(this+0x15F0) | 0x4C | R | — | [LLM] |
| *(this+0x15F0) | 0x54 | R | — | [LLM] |
| *(this+0x15F0) | 0x5C | R | — | [LLM] |
| *(this+0x3EC) | 0x1C | R | — | [LLM] |
| *(this+0x3EC) | 0x34 | R | — | [LLM] |
| *(this+0x3EC) | 0x4C | R | — | [LLM] |
| this | 0x60 | RW | — | [LLM] |
| this | 0x68 | R | — | [LLM] |
| this | 0x310 | R | — | [LLM] |
| this | 0x318 | R | — | [LLM] |
| this | 0x338 | RW | — | [LLM] |
| this | 0x3E0 | R | — | [LLM] |
| this | 0x3EC | R | — | [LLM] |
| this | 0x450 | R | — | [LLM] |
| this | 0x844 | R | — | [LLM] |
| this | 0x850 | R | — | [LLM] |
| this | 0xCB4 | R | — | [LLM] |
| this | 0x1118 | R | — | [LLM] |
| this | 0x141C | R | — | [LLM] |
| this | 0x15F0 | R | — | [LLM] |
| this | 0x1658 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x60: recalc every frame — external poke does NOT persist
- this 0x338: recalc every frame — external poke does NOT persist
- this 0x1658: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e420 | dbl_59E420 | R | BaseDoubleConstant [DERIVED] (also: ` (BaseDoubleConstant = 1.0) |
| 0059e830 | dbl_59E830 | R | TempWarningThreshold [DERIVED] (also: ` — dot product comparison threshold) |
| 0059e880 | dbl_59E880 | R | HalfStep [DERIVED] (also: ` — lower threshold constant) |
| 0059ed28 | dbl_59ED28 | R | PhysicsMinDeltaThreshold [DERIVED] |
| 0059ed30 | dbl_59ED30 | R | MinVelocityThreshold [DERIVED] |
| 0059ed38 | dbl_59ED38 | R | SpeedSmoothingGain [DERIVED] (also: ` — sub-step stability multiplier) |
| 005d6d70 | dbl_5D6D70 | R | EngineBrakeTorqueFactor [DERIVED] (also: ` — integration enabled flag (shared timestep variable) |
| 007ce254 | byte_7CE254 | R | DisableHUDFlag [CONFIRMED] |
| 007ce958 | dword_7CE958 | R | TireModelMode [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00438130 | VehicleDynamicsForceAccumulatorIntegration | [LLM] |
| 00438690 | PhysicsCollisionDamageDNFDetection | [LLM] |
| 0043ef20 | EngineStressSimulation | [LLM] |
| 00441360 | StateAccumulateDelta | [LLM] |
| 00441450 | PhysicsSubObjectFree | [LLM] |
| 004414d0 | WheelDataCopy | [LLM] |
| 00441600 | PhysicsStepFrame | [LLM] |
| 00441d60 | PhysicsIntegrationStep | [LLM] |
| 004441f0 | VehicleMainPhysicsUpdate | [LLM] |
| 00567740 | FPUControlWordMaskExtract | [LLM] |
| 00567780 | EmptyStub_7780 | [LLM] |
| 005692a0 | F_3x3InertiaTensorTransform | [LLM] |
| 00569410 | InertiaTensorWorldSpaceTransform | [LLM] |
| 0056bde0 | sub_56BDE0 | [LLM] |
| 0058957a | InterruptDispatch | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
