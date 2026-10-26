## Camera_004a3b50 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4A00A0 (004a00a0), PitCrewAnimationMASSetup (004a3910)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x64 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e448 | flt_59E448 | R | TileSteppingMultiplier [DERIVED] |
| 0059e670 | flt_59E670 | R | SentinelFlagConstant [DERIVED] |
| 0059e84c | flt_59E84C | R | VelocityRateLimit [DERIVED] (also: ` — display message threshold) |
| 0059e8b4 | flt_59E8B4 | R | ClampUpperThreshold [DERIVED] |
| 0059e940 | flt_59E940 | R | Flt_PhysicsLimit_9E940 [DERIVED] |
| 005acb28 | flt_5ACB28 | R | AISteerAngleThreshold [DERIVED] |
| 005acb2c | flt_5ACB2C | R | LateralForceThreshold [DERIVED] |
| 005acb30 | flt_5ACB30 | R | PhysicsForceThreshold [DERIVED] |
| 005ea2c0 | dword_5EA2C0 | R | SetupScenePtr [DERIVED] |
| 007c54e8 | dword_7C54E8 | R | PlayerVehiclePtr [FACT] |
| 007c9360 | dbl_7C9360 | R | Unknown_Struct_7C9360 [DERIVED] |
| 008aae70 | dword_8AAE70 | RW | RingBufferCounter (QA/weather noise) [DERIVED] |
| 008ab274 | flt_8AB274 | R | WeatherNoiseTable [DERIVED] (also: � random noise table (docs/12) |
| 008acee0 | dword_8ACEE0 | R | ForceFeedbackBase [CONFIRMED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00403640 | sub_403640 | [LLM] |
| 0044c4c0 | SpatialGridQuery | [LLM] |
| 004a2800 | Vec3CopyToStruct | [LLM] |
| 004d1140 | RenderCallWithGuard | [LLM] |
| 004dd550 | BoundingBoxComputation | [LLM] |
| 00566e40 | EulerToRotationMatrix | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
