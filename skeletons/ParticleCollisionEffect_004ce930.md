## ParticleCollisionEffect_004ce930 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** TireSlipForceCalculation (004472b0), sub_4EE2D0 (004ee2d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x20 | R | — | [LLM] |
| this | 0x24 | R | — | [LLM] |
| this | 0x28 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e454 | flt_59E454 | R | PhysicsConstant_59E454 [DERIVED] |
| 0059e7f8 | flt_59E7F8 | R | AntiRollMixingFactor [DERIVED] |
| 0059e84c | flt_59E84C | R | VelocityRateLimit [DERIVED] (also: ` — display message threshold) |
| 0059e868 | flt_59E868 | R | SteeringResponseGain [DERIVED] |
| 005acecc | flt_5ACECC | R | ParticleEffectConst [DERIVED] |
| 005aced0 | flt_5ACED0 | R | Rain_ParticleScale [DERIVED] |
| 007c5698 | dword_7C5698 | R | SessionTickCounter [DERIVED] |
| 007cf8a8 | dword_7CF8A8 | R | RenderThrottleFrames [DERIVED] |
| 007cf9bc | byte_7CF9BC | R | SmokeEnabledFlag [DERIVED] |
| 007cf9ec | byte_7CF9EC | R | Byte_RendererFlag_F9EC [DERIVED] |
| 008aae70 | dword_8AAE70 | RW | RingBufferCounter (QA/weather noise) [DERIVED] |
| 008ab274 | flt_8AB274 | R | WeatherNoiseTable [DERIVED] (also: � random noise table (docs/12) |
| 008ab6e4 | dword_8AB6E4 | R | ScoringGate [CONFIRMED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004cbc50 | ParticleTrailEmitter | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
