## sub_4FCEE0_004fcee0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GamePostMainLoop (0042d8a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x5C)+0x0) | 0x0 | R | — | [LLM] |
| *(*(this+0x5C)+0x0) | 0x4 | R | — | [LLM] |
| *(*(this+0x5C)+0x0) | 0x8 | R | — | [LLM] |
| *(this+0x5C) | 0x0 | R | — | [LLM] |
| *(this+0x5C) | 0x4 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x4 | RW | 1065353216 → 1.0f | [LLM] |
| this | 0x8 | RW | — | [LLM] |
| this | 0xC | RW | — | [LLM] |
| this | 0x10 | RW | — | [LLM] |
| this | 0x14 | RW | 1 | [LLM] |
| this | 0x18 | RW | — | [LLM] |
| this | 0x1C | RW | 0 | [LLM] |
| this | 0x20 | R | — | [LLM] |
| this | 0x24 | R | — | [LLM] |
| this | 0x28 | R | — | [LLM] |
| this | 0x2C | R | — | [LLM] |
| this | 0x40 | RW | 0 | [LLM] |
| this | 0x44 | RW | 18446744073701163007 | [LLM] |
| this | 0x48 | RW | — | [LLM] |
| this | 0x4C | RW | — | [LLM] |
| this | 0x50 | RW | — | [LLM] |
| this | 0x5C | RW | — | [LLM] |
| this | 0xA4 | RW | — | [LLM] |
| this | 0xA8 | R | — | [LLM] |
| this | 0xAC | R | — | [LLM] |
| this | 0xB0 | R | — | [LLM] |
| this | 0xB4 | R | — | [LLM] |
| this | 0xB8 | R | — | [LLM] |
| this | 0xBC | R | — | [LLM] |
| this | 0xC0 | R | — | [LLM] |
| this | 0xC4 | R | — | [LLM] |
| this | 0xC8 | R | — | [LLM] |
| this | 0xCC | R | — | [LLM] |
| this | 0xD0 | R | — | [LLM] |
| this | 0xD4 | R | — | [LLM] |
| this | 0xD8 | R | — | [LLM] |
| this | 0xDC | R | — | [LLM] |
| this | 0xE0 | R | — | [LLM] |
| this | 0xE4 | R | — | [LLM] |
| this | 0xE8 | R | — | [LLM] |
| this | 0xEC | R | — | [LLM] |
| this | 0xF0 | R | — | [LLM] |
| this | 0xF4 | R | — | [LLM] |
| this | 0xF8 | R | — | [LLM] |
| this | 0xFC | R | — | [LLM] |
| this | 0x100 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x4: [LLM: once/conditional? does external poke survive?]
- this 0x8: [LLM: once/conditional? does external poke survive?]
- this 0xC: [LLM: once/conditional? does external poke survive?]
- this 0x10: [LLM: once/conditional? does external poke survive?]
- this 0x14: [LLM: once/conditional? does external poke survive?]
- this 0x18: [LLM: once/conditional? does external poke survive?]
- this 0x1C: [LLM: once/conditional? does external poke survive?]
- this 0x40: [LLM: once/conditional? does external poke survive?]
- this 0x44: [LLM: once/conditional? does external poke survive?]
- this 0x48: [LLM: once/conditional? does external poke survive?]
- this 0x4C: [LLM: once/conditional? does external poke survive?]
- this 0x50: [LLM: once/conditional? does external poke survive?]
- this 0x5C: [LLM: once/conditional? does external poke survive?]
- this 0xA4: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e444 | flt_59E444 | R | FrameDelta [DERIVED] (also: ` — float 0.016667 (1/60, frame delta) |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e46c | flt_59E46C | R | TireSlipOffset [DERIVED] (also: ` — offset value) |
| 0059e8e4 | flt_59E8E4 | R | WetGripThreshold [DERIVED] |
| 0059e8fc | flt_59E8FC | R | AccelAccumLimit [DERIVED] |
| 0059e97c | flt_59E97C | R | LapTimeDeltaScale [DERIVED] |
| 0059ef78 | flt_59EF78 | R | ContactNormalizationFactor [DERIVED] (also: ` — second threshold/reference value) |
| 0059fec8 | flt_59FEC8 | R | AlphaChannelMultiplier [DERIVED] |
| 005acd48 | flt_5ACD48 | R | TireGripThreshold [DERIVED] |
| 005ad294 | flt_5AD294 | R | ViewportTransformConstant [DERIVED] |
| 005ad298 | flt_5AD298 | R | ParticleEmitRate [DERIVED] |
| 005ad29c | flt_5AD29C | R | Float5AD29C [DERIVED] |
| 005ad2a0 | flt_5AD2A0 | R | FloatConst_5AD2A0 [DERIVED] |
| 005ad2a4 | flt_5AD2A4 | R | Unknown_Float_5AD2A4 [DERIVED] |
| 005ad2a8 | flt_5AD2A8 | R | ParticleLifeScale [DERIVED] |
| 005ad2ac | flt_5AD2AC | R | TireSpinThreshold [DERIVED] |
| 005ad2b0 | flt_5AD2B0 | R | PhysicsEffectFloat [DERIVED] |
| 005ad2b4 | flt_5AD2B4 | R | UnknownPhysicsConst [DERIVED] |
| 005ad2b8 | dbl_5AD2B8 | R | SteeringNoise_dbl_5AD2B8 [DERIVED] |
| 005c329c | dword_5C329C | R | VehicleCount [FACT] (also: ` — VehicleCount (set to 0 on join) |
| 005d6f78 | aNightlight | R | NightLightString [DERIVED] |
| 007c56a0 | dword_7C56A0 | R | MultiplayerFlags [DERIVED] |
| 007cf8a8 | dword_7CF8A8 | R | RenderThrottleFrames [DERIVED] |
| 007cfec4 | flt_7CFEC4 | R | Flt_7CFEC4_Render [DERIVED] |
| 0083ee60 | dword_83EE60 | RW | RingBufferCount [DERIVED] (also: ` -- ring buffer counter) |
| 008aae64 | dword_8AAE64 | RW | RingBufferWritePtr [DERIVED] (also: ` -- ring buffer offset) |
| 008ab6e4 | dword_8AB6E4 | R | ScoringGate [CONFIRMED] |
| 008acea0 | dword_8ACEA0 | R | ScoringGridBase [DERIVED] |
| 008acea8 | dword_8ACEA8 | R | Unknown_Scene_Value [DERIVED] |
| 008aceac | dword_8ACEAC | R | Session_RaceConfig_CEAC [DERIVED] |
| 008acfb0 | flt_8ACFB0 | R | RaceTimingConstant [DERIVED] |
| 008afe88 | dword_8AFE88 | R | CollisionGeometryHandle [DERIVED] (also: ` — global collision geometry handle) |
| 008afe98 | dbl_8AFE98 | R | ScoringDefaultReturn [DERIVED] (also: ` — default return value (float) |
| 008afea0 | dbl_8AFEA0 | R | SessionTime [DERIVED] (also: ` — current session time (passed to FUN_0040f300) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b33b0 | ProgressBarEventEncode | [LLM] |
| 004cefe0 | StridedArraySearchAndCall | [LLM] |
| 004fc170 | RenderColorUpdate | [LLM] |
| 004fc650 | StringCopyWithRingBuffer | [LLM] |
| 004fc870 | sub_4FC870 | [LLM] |
| 004fdeb0 | AudioADSREnvelope | [LLM] |
| 00543870 | UIElementPositionSetter | [LLM] |
| 005438b0 | AudioPanUpdate | [LLM] |
| 00543920 | BoundedFloatSetterWithFlag | [LLM] |
| 00545670 | CameraPositionGetter | [LLM] |
| 005457c0 | LinkedListTraversal | [LLM] |
| 005457f0 | LinkedListNthElement | [LLM] |
| 00545820 | LinkedIndexedAccess | [LLM] |
| 0055d2f0 | BitFlagSetterWithDXUpdate | [LLM] |
| 0055d410 | UIPropertyValueSetter | [LLM] |
| 00587bdc | CRTFtol | [LLM] |
| 00588640 | sub_588640 | [LLM] |
| 0058957a | InterruptDispatch | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| *(*(this+0x5C)+0x0) | 0x4 | == | 1 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
