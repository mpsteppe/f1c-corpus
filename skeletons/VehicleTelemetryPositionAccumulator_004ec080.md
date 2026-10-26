## VehicleTelemetryPositionAccumulator_004ec080 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** UICameraModeDispatchWithVehicleDataRead (0040f550), ParticleEffectUpdateDispatch (004eb430), VehicleYawRotationRecoveryController (004f1c40)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x4894 | R | — | [LLM] |
| this | 0x0 | R | — | postProcessInput [CONFIRMED] |
| this | 0x32BC | R | — | [LLM] |
| this | 0x34D4 | RW | — | [LLM] |
| this | 0x34D8 | RW | — | [LLM] |
| this | 0x34DC | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x34D4: recalc every frame — external poke does NOT persist
- this 0x34D8: recalc every frame — external poke does NOT persist
- this 0x34DC: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007c7428 | dbl_7C7428 | R | RaceTimeElapsed [DERIVED] |
| 007cd25c | dword_7CD25C | R | GameModuleManager [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0043e6a0 | RigidBodyTransformUpdate | [LLM] |
| 00463dc0 | ConditionalStridePointerComputation | [LLM] |
| 004b2310 | sub_4B2310 | [LLM] |
| 004b2420 | ArithmeticComparison_2420 | [LLM] |
| 004e16c0 | FieldReadDelegate | [LLM] |
| 004e23d0 | F_3x3MatrixTransform | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
