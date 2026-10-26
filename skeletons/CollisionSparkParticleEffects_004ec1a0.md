## CollisionSparkParticleEffects_004ec1a0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehicleContactForceAccumulation (004ebc60)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | postProcessInput [CONFIRMED] |
| this | 0x4 | R | — | [LLM] |
| this | 0x828 | R | — | [LLM] |
| this | 0x868 | R | — | [LLM] |
| this | 0xCC8 | R | — | [LLM] |
| this | 0xD08 | R | — | [LLM] |
| this | 0xD0C | R | — | [LLM] |
| this | 0xD4C | R | — | [LLM] |
| this | 0xD50 | R | — | [LLM] |
| this | 0xD90 | R | — | [LLM] |
| this | 0x32BC | R | — | [LLM] |
| this | 0x3440 | R | — | [LLM] |
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
| this | 0x34E0 | R | — | [LLM] |
| this | 0x34E4 | R | — | [LLM] |
| this | 0x34E8 | R | — | [LLM] |
| this | 0x34EC | R | — | [LLM] |
| this | 0x34F0 | R | — | RenderX [FACT] |
| this | 0x34F4 | R | — | RenderY [FACT] |
| this | 0x3590 | R | — | [LLM] |
| this | 0x3594 | R | — | [LLM] |
| this | 0x39B4 | R | — | [LLM] |
| this | 0x3D78 | R | — | [LLM] |
| this | 0x3D7C | R | — | [LLM] |
| this | 0x3D80 | R | — | [LLM] |
| this | 0x3D84 | R | — | [LLM] |
| this | 0x3D88 | R | — | [LLM] |
| this | 0x3D8C | R | — | [LLM] |
| this | 0x3D90 | R | — | [LLM] |
| this | 0x3D94 | R | — | [LLM] |
| this | 0x3D98 | R | — | [LLM] |
| this | 0x3D9C | R | — | [LLM] |
| this | 0x3DA0 | R | — | [LLM] |
| this | 0x3DA4 | R | — | [LLM] |
| this | 0x3DC4 | R | — | [LLM] |
| this | 0x3DC8 | R | — | [LLM] |
| this | 0x3DCC | R | — | [LLM] |
| this | 0x3DD0 | R | — | [LLM] |
| this | 0x3DD4 | R | — | [LLM] |
| this | 0x3DF4 | R | — | [LLM] |
| this | 0x3DF8 | R | — | [LLM] |
| this | 0x3DFC | R | — | [LLM] |
| this | 0x3E90 | R | — | [LLM] |
| this | 0x3EB4 | R | — | [LLM] |
| this | 0x3EB8 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e430 | dbl_59E430 | R | ZeroSentinel [DERIVED] (also: ` (ZeroSentinel ~0.0) |
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e444 | flt_59E444 | R | FrameDelta [DERIVED] (also: ` — float 0.016667 (1/60, frame delta) |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e670 | flt_59E670 | R | SentinelFlagConstant [DERIVED] |
| 0059e7e8 | flt_59E7E8 | R | TimeScalingConstant [DERIVED] |
| 0059e7ec | flt_59E7EC | R | ZeroConstant [DERIVED] (also: ` — compared constant (5.0f encoded indirectly) |
| 0059e8b4 | flt_59E8B4 | R | ClampUpperThreshold [DERIVED] |
| 005ad1ec | flt_5AD1EC | R | SuspensionForceLimit [DERIVED] |
| 005ad1f0 | flt_5AD1F0 | R | Flt_Unknown_Damage [DERIVED] |
| 005ad1f4 | flt_5AD1F4 | R | AudioLerpCoeff [DERIVED] |
| 005ea560 | dword_5EA560 | R | GlobalInstance_5EA560 [CONFIRMED] |
| 007c54e8 | dword_7C54E8 | R | PlayerVehiclePtr [FACT] |
| 007c56a8 | dword_7C56A8 | R | RacePhase [CONFIRMED] (also: ` — race phase (8 = ?) |
| 007c7428 | dbl_7C7428 | R | RaceTimeElapsed [DERIVED] |
| 007c749f | byte_7C749F | R | Byte_PlayerControlFlag [DERIVED] |
| 007c74a4 | byte_7C74A4 | R | Unknown_Flag_7C74A4 [DERIVED] |
| 007d0014 | dword_7D0014 | R | updateGameLevels [CONFIRMED] (also: Setup_AIDriverSkill) |
| 0083ee60 | dword_83EE60 | RW | RingBufferCount [DERIVED] (also: ` -- ring buffer counter) |
| 008aae64 | dword_8AAE64 | RW | RingBufferWritePtr [DERIVED] (also: ` -- ring buffer offset) |
| 008aae70 | dword_8AAE70 | RW | RingBufferCounter (QA/weather noise) [DERIVED] |
| 008aae74 | flt_8AAE74 | R | TrigLookup256 [DERIVED] (also: ` — 256-entry trig lookup table) |
| 008ab274 | flt_8AB274 | R | WeatherNoiseTable [DERIVED] (also: � random noise table (docs/12) |
| 008afea0 | dbl_8AFEA0 | R | SessionTime [DERIVED] (also: ` — current session time (passed to FUN_0040f300) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00411330 | ShortComputation_1330 | [LLM] |
| 00442060 | SteeringGeometryUpdate | [LLM] |
| 004a56b0 | StateTransition | [LLM] |
| 004b33b0 | ProgressBarEventEncode | [LLM] |
| 004ed1c0 | FloatParameterForwarder | [LLM] |
| 004ed1f0 | ForceApplicationRouter | [LLM] |
| 004ed220 | PhysicsTimeStep | [LLM] |
| 004ed250 | RepairServiceStateDispatcher | [LLM] |
| 004efae0 | TireScrubReset | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x32BC | != | 1 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
