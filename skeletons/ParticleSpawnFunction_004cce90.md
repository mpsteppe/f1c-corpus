## ParticleSpawnFunction_004cce90 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** ParticleEffectWorldTransform (004e16f0), sub_4EE2D0 (004ee2d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | [LLM] |
| this | 0x58 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e774 | flt_59E774 | R | ShortToFloatScale [DERIVED] (also: ` — position scale factor) |
| 0059e778 | flt_59E778 | R | AngleToRadians [DERIVED] (also: ` — spread scale factor 2) |
| 0059ed18 | flt_59ED18 | R | ForceReductionFactor [DERIVED] |
| 005ea510 | dword_5EA510 | R | SessionManager [DERIVED] |
| 007c9360 | dbl_7C9360 | R | Unknown_Struct_7C9360 [DERIVED] |
| 008aae70 | dword_8AAE70 | RW | RingBufferCounter (QA/weather noise) [DERIVED] |
| 008ab274 | flt_8AB274 | R | WeatherNoiseTable [DERIVED] (also: � random noise table (docs/12) |
| 008ab6e4 | dword_8AB6E4 | R | ScoringGate [CONFIRMED] |
| 008ab6ec | dword_8AB6EC | R | ScoringDataPtr [DERIVED] |
| 008afe98 | dbl_8AFE98 | R | ScoringDefaultReturn [DERIVED] (also: ` — default return value (float) |
| 008afea0 | dbl_8AFEA0 | R | SessionTime [DERIVED] (also: ` — current session time (passed to FUN_0040f300) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040c870 | VirtualDispatchHelper | [LLM] |
| 0044c550 | CollisionNormalFromFeature | [LLM] |
| 004b9ce0 | Delegation | [LLM] |
| 004b9cf0 | FloatDifference | [LLM] |
| 004b9e30 | VehicleDataAccessor | [LLM] |
| 004cb540 | CircularBufferSlotAlloc | [LLM] |
| 004cc500 | ParticleEffectBillboardQuadSetup | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x58 | > | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
