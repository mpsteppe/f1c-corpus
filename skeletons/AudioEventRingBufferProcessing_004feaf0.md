## AudioEventRingBufferProcessing_004feaf0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4FCC30 (004fcc30)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(*(this+0x54)+0x4)+0x4) | 0x4 | R | — | [LLM] |
| *(*(this+0x54)+0x4) | 0x4 | RW | 0 | [LLM] |
| *(this+0x3C) | 0x8 | R | — | [LLM] |
| *(this+0x54) | 0x4 | R | — | [LLM] |
| *(this+0x58) | 0x4 | RW | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x4 | RW | 0 | [LLM] |
| this | 0x24 | R | — | [LLM] |
| this | 0x38 | RW | — | [LLM] |
| this | 0x3C | R | — | [LLM] |
| this | 0x54 | RW | — | [LLM] |
| this | 0x58 | RW | — | [LLM] |
| this | 0x5C | RW | — | [LLM] |
| this | 0x60 | R | — | [LLM] |

**Written-by note (persistence):**
- *(*(this+0x54)+0x4) 0x4: [LLM: once/conditional? does external poke survive?]
- *(this+0x58) 0x4: [LLM: once/conditional? does external poke survive?]
- this 0x4: [LLM: once/conditional? does external poke survive?]
- this 0x38: [LLM: once/conditional? does external poke survive?]
- this 0x54: [LLM: once/conditional? does external poke survive?]
- this 0x58: [LLM: once/conditional? does external poke survive?]
- this 0x5C: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e454 | flt_59E454 | R | PhysicsConstant_59E454 [DERIVED] |
| 0059e458 | flt_59E458 | R | ConstraintForceEpsilon [DERIVED] (also: ` — constraint force threshold (near-zero) |
| 0059e470 | flt_59E470 | R | TrackNodeSearchRadiusSq [DERIVED] |
| 0059e4e0 | flt_59E4E0 | R | ForceIncrementClamp [DERIVED] (also: ` — scroll auto-repeat threshold (delta time gate) |
| 0059e5fc | flt_59E5FC | R | FrameRateCorrectionFactor [DERIVED] (also: ` â€” global frame-rate correction) |
| 0059e7f8 | flt_59E7F8 | R | AntiRollMixingFactor [DERIVED] |
| 0059e800 | flt_59E800 | R | AmplitudeLimit [DERIVED] (also: ` — under-relaxation upper bound) |
| 0059e80c | flt_59E80C | R | PitlaneTimeThreshold [DERIVED] |
| 0059e8b4 | flt_59E8B4 | R | ClampUpperThreshold [DERIVED] |
| 0059e8cc | flt_59E8CC | R | WheelSpeedThreshold [DERIVED] (also: ` — wheel speed threshold (not in docs/12) |
| 0059e940 | flt_59E940 | R | Flt_PhysicsLimit_9E940 [DERIVED] |
| 0059ef64 | flt_59EF64 | R | HeadlightRangeFactor [DERIVED] |
| 005acb3c | flt_5ACB3C | R | PitDensityThreshold [DERIVED] |
| 005acd3c | flt_5ACD3C | R | AeroDragCoefficient [DERIVED] (also: ` — aero constant) |
| 005acd94 | flt_5ACD94 | R | Flt_AiAudioFreqGain_CD94 [DERIVED] |
| 005ad144 | flt_5AD144 | R | DeformationOffsetConst [DERIVED] (also: � offset constant for deformation) |
| 005c329c | dword_5C329C | R | VehicleCount [FACT] (also: ` — VehicleCount (set to 0 on join) |
| 007cf8cc | flt_7CF8CC | R | TrackGripNoiseAmp [DERIVED] |
| 007cf8f0 | flt_7CF8F0 | R | RainIntensityFactor [DERIVED] |
| 008aae70 | dword_8AAE70 | RW | RingBufferCounter (QA/weather noise) [DERIVED] |
| 008aae74 | flt_8AAE74 | R | TrigLookup256 [DERIVED] (also: ` — 256-entry trig lookup table) |
| 008ab274 | flt_8AB274 | R | WeatherNoiseTable [DERIVED] (also: � random noise table (docs/12) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004fde00 | sub_4FDE00 | [LLM] |
| 004fdeb0 | AudioADSREnvelope | [LLM] |
| 004ff2b0 | sub_4FF2B0 | [LLM] |
| 00587c03 | OperatorNewNhMallocWrapper | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
