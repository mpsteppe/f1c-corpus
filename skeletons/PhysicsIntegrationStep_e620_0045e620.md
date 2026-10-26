## PhysicsIntegrationStep_e620_0045e620 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** UtilityFunction_3d50 (00463d50)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e474 | flt_59E474 | R | PhysicsConstant_59E474 [DERIVED] |
| 0059e828 | flt_59E828 | R | FloatOneConstant [DERIVED] (also: ` — float 1.0 constant) |
| 0059eb08 | dbl_59EB08 | R | DoublePi [DERIVED] |
| 0059f10c | flt_59F10C | R | SignedByteScale [DERIVED] |
| 0059f110 | flt_59F110 | R | PhysicsBrakeBias [DERIVED] |
| 007d108c | flt_7D108C | R | MinPenetrationLimit [DERIVED] |
| 007d1158 | dword_7D1158 | R | WheelVelocityThreshold [DERIVED] |
| 007d117c | flt_7D117C | R | InputDeadzoneFloat [DERIVED] |
| 007d11a0 | flt_7D11A0 | R | UIAnimationFloat [DERIVED] |
| 007d11c4 | flt_7D11C4 | R | NetworkPacketInterval [DERIVED] |
| 008afe98 | dbl_8AFE98 | R | ScoringDefaultReturn [DERIVED] (also: ` — default return value (float) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0045ca20 | TerrainSurfaceRoughnessHeightSampling | [LLM] |
| 0045eb00 | Vector3ScalarMultiply | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
