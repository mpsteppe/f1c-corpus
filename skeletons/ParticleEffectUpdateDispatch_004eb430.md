## ParticleEffectUpdateDispatch_004eb430 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** MainGameTickUpdate (0042c690)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x3A9C) | 0x0 | R | — | [LLM] |
| *(this+0x3A9C) | 0x4 | R | — | [LLM] |
| *(this+0x3A9C) | 0x8 | R | — | [LLM] |
| obj | 0x48BC | R | — | [LLM] |
| this | 0x0 | R | — | postProcessInput [CONFIRMED] |
| this | 0xA4 | RW | 0 | [LLM] |
| this | 0xA8 | RW | 1065353216 → 1.0f | [LLM] |
| this | 0xAC | RW | 0 | [LLM] |
| this | 0xB0 | RW | 0 | [LLM] |
| this | 0xB4 | RW | 0 | [LLM] |
| this | 0x6E8 | R | — | [LLM] |
| this | 0x1070 | RW | 1 | [LLM] |
| this | 0x1074 | RW | 0 | [LLM] |
| this | 0x32BC | R | — | [LLM] |
| this | 0x34AC | R | — | [LLM] |
| this | 0x34B0 | R | — | [LLM] |
| this | 0x34B4 | R | — | [LLM] |
| this | 0x34B8 | R | — | elapsedTime (alt) [CONFIRMED] |
| this | 0x34BC | R | — | [LLM] |
| this | 0x34C0 | R | — | [LLM] |
| this | 0x34C4 | R | — | [LLM] |
| this | 0x34C8 | R | — | [LLM] |
| this | 0x34CC | R | — | [LLM] |
| this | 0x34D0 | R | — | [LLM] |
| this | 0x34D4 | R | — | [LLM] |
| this | 0x34D8 | R | — | [LLM] |
| this | 0x34DC | R | — | [LLM] |
| this | 0x34EC | R | — | [LLM] |
| this | 0x34F0 | R | — | RenderX [FACT] |
| this | 0x34F4 | R | — | RenderY [FACT] |
| this | 0x3514 | R | — | [LLM] |
| this | 0x3A9C | R | — | [LLM] |
| this | 0x3B75 | RW | 1 | [LLM] |
| this | 0x3B78 | RW | 0 | [LLM] |
| this | 0x3B79 | R | — | [LLM] |
| this | 0x3B88 | R | — | [LLM] |
| this | 0x3B8C | R | — | [LLM] |
| this | 0x3B90 | R | — | [LLM] |
| this | 0x3FF0 | RW | 1 | [LLM] |

**Written-by note (persistence):**
- this 0xA4: recalc every frame — external poke does NOT persist
- this 0xA8: recalc every frame — external poke does NOT persist
- this 0xAC: recalc every frame — external poke does NOT persist
- this 0xB0: recalc every frame — external poke does NOT persist
- this 0xB4: recalc every frame — external poke does NOT persist
- this 0x1070: recalc every frame — external poke does NOT persist
- this 0x1074: recalc every frame — external poke does NOT persist
- this 0x3B75: recalc every frame — external poke does NOT persist
- this 0x3B78: recalc every frame — external poke does NOT persist
- this 0x3FF0: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004ebc20 | jpt_4EB6B1 | R | [LLM] |
| 004ebc30 | byte_4EBC30 | R | [LLM] |
| 004ebc3c | jpt_4EB96D | R | [LLM] |
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e444 | flt_59E444 | R | FrameDelta [DERIVED] (also: ` — float 0.016667 (1/60, frame delta) |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e478 | flt_59E478 | R | SteeringCenterBoost [DERIVED] |
| 0059e7ec | flt_59E7EC | R | ZeroConstant [DERIVED] (also: ` — compared constant (5.0f encoded indirectly) |
| 0059e800 | flt_59E800 | R | AmplitudeLimit [DERIVED] (also: ` — under-relaxation upper bound) |
| 0059e874 | flt_59E874 | R | AITurnInSpeedThreshold [DERIVED] |
| 005ad1e0 | flt_5AD1E0 | R | Unknown_Float_5AD1E0 [DERIVED] |
| 005ad1e4 | flt_5AD1E4 | R | CollisionResponseThreshold [DERIVED] |
| 005ad1e8 | flt_5AD1E8 | R | BrakeFluidMult [DERIVED] |
| 007cf728 | byte_7CF728 | R | Unknown_Byte_7CF728 [DERIVED] |
| 008aae70 | dword_8AAE70 | RW | RingBufferCounter (QA/weather noise) [DERIVED] |
| 008ab274 | flt_8AB274 | R | WeatherNoiseTable [DERIVED] (also: � random noise table (docs/12) |
| 008ab710 | dword_8AB710 | R | UIWidgetList [DERIVED] |
| 008ad400 | unk_8AD400 | R | VehicleModel_OffsetTable_8AD400 [DERIVED] |
| 008ad404 | unk_8AD404 | R | VehicleSetupBlock [DERIVED] |
| 008ad428 | unk_8AD428 | R | TireWearArray [DERIVED] |
| 008ad42c | unk_8AD42C | R | VehicleArrayOffset_PitCrew [DERIVED] |
| 008adaf8 | dword_8ADAF8 | RW | SlotCounter [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040f4b0 | ModeDispatchWithSwitch | [LLM] |
| 0040f550 | UICameraModeDispatchWithVehicleDataRead | [LLM] |
| 004be340 | GridCellIterate | [LLM] |
| 004be4e0 | SpriteGridRender | [LLM] |
| 004e9630 | PositionChangeMonitor | [LLM] |
| 004e96c0 | sub_4E96C0 | [LLM] |
| 004e9980 | ComputeSlipVelocityNorm | [LLM] |
| 004e9a40 | VehicleBodyToWheelContactDistanceComputation | [LLM] |
| 004e9bd0 | F_3x3MatrixTransformWithTranslation | [LLM] |
| 004ea970 | CollisionDetectionSystem | [LLM] |
| 004ebc60 | VehicleContactForceAccumulation | [LLM] |
| 004ec080 | VehicleTelemetryPositionAccumulator | [LLM] |
| 004f8850 | PerIndexStructFieldSetter | [LLM] |
| 004f8ab0 | ConditionedFloatRead | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x32BC | <= | 1 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
