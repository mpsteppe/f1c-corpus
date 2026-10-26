## AIRacingLine_00425920 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AIMainUpdate (00424e70)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x4400)+0x114) | 0xC | R | — | [LLM] |
| *(*(this+0x4400)+0x114) | 0x14 | R | — | [LLM] |
| *(*(this+0x4400)+0x114) | 0x94 | R | — | [LLM] |
| *(*(this+0x4400)+0x114) | 0x9C | R | — | [LLM] |
| *(this+0x4354) | 0x50 | R | — | [LLM] |
| *(this+0x4354) | 0x54 | R | — | [LLM] |
| *(this+0x4400) | 0x0 | R | — | [LLM] |
| *(this+0x4400) | 0x8 | R | — | [LLM] |
| *(this+0x4400) | 0x18 | R | — | [LLM] |
| *(this+0x4400) | 0x114 | R | — | [LLM] |
| this | 0x34F8 | RW | 0 | RenderZ [FACT] |
| this | 0x34FC | RW | 0 | [LLM] |
| this | 0x3500 | RW | 0 | [LLM] |
| this | 0x4354 | R | — | [LLM] |
| this | 0x43A4 | RW | — | [LLM] |
| this | 0x43F8 | RW | 0 | [LLM] |
| this | 0x43FC | RW | 1176255488 → 9999.0f | [LLM] |
| this | 0x4400 | R | — | [LLM] |
| this | 0x4424 | RW | 0 | [LLM] |
| this | 0x4428 | R | — | [LLM] |
| this | 0x4434 | RW | 0 | [LLM] |
| this | 0x4438 | RW | 0 | [LLM] |
| this | 0x443C | RW | 0 | [LLM] |
| this | 0x4440 | R | — | Speed [FACT] (also: actualSpeed) |
| this | 0x445C | RW | — | [LLM] |
| this | 0x4468 | RW | 0 | [LLM] |
| this | 0x446C | R | — | [LLM] |
| this | 0x44B8 | R | — | [LLM] |
| this | 0x44C4 | R | — | [LLM] |
| this | 0x44CC | R | — | [LLM] |
| this | 0x4510 | RW | 5 | driverStatus [CONFIRMED] |
| this | 0x4524 | RW | 0 | [LLM] |
| this | 0x454C | RW | 0 | callToBox [CONFIRMED] |
| this | 0x4550 | RW | 1 | [LLM] |
| this | 0x4554 | R | — | [LLM] |
| this | 0x45F4 | RW | 0 | ActiveFlag [FACT] |

**Written-by note (persistence):**
- this 0x34F8: recalc every frame — external poke does NOT persist
- this 0x34FC: recalc every frame — external poke does NOT persist
- this 0x3500: recalc every frame — external poke does NOT persist
- this 0x43A4: recalc every frame — external poke does NOT persist
- this 0x43F8: recalc every frame — external poke does NOT persist
- this 0x43FC: recalc every frame — external poke does NOT persist
- this 0x4424: recalc every frame — external poke does NOT persist
- this 0x4434: recalc every frame — external poke does NOT persist
- this 0x4438: recalc every frame — external poke does NOT persist
- this 0x443C: recalc every frame — external poke does NOT persist
- this 0x445C: recalc every frame — external poke does NOT persist
- this 0x4468: recalc every frame — external poke does NOT persist
- this 0x4510: recalc every frame — external poke does NOT persist
- this 0x4524: recalc every frame — external poke does NOT persist
- this 0x454C: recalc every frame — external poke does NOT persist
- this 0x4550: recalc every frame — external poke does NOT persist
- this 0x45F4: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e7e8 | flt_59E7E8 | R | TimeScalingConstant [DERIVED] |
| 0059e7ec | flt_59E7EC | R | ZeroConstant [DERIVED] (also: ` — compared constant (5.0f encoded indirectly) |
| 0059e854 | flt_59E854 | R | Flt_Physics_AI_Threshold [DERIVED] |
| 0059e8a0 | flt_59E8A0 | R | InvSqrtThreshold [DERIVED] (also: ` — proximity distance² threshold) |
| 0059e8a4 | flt_59E8A4 | R | ReverseGearThrottleMult [DERIVED] (also: ` â€” reverse gear throttle multiplier) |
| 0059e8a8 | flt_59E8A8 | R | AIOvertakeThreshold [DERIVED] |
| 0059e8ac | flt_59E8AC | R | Unknown_Float_Physics [DERIVED] |
| 0059e8b0 | flt_59E8B0 | R | AIOvertakeDistThreshold [DERIVED] |
| 0059e8b4 | flt_59E8B4 | R | ClampUpperThreshold [DERIVED] |
| 0059e8b8 | flt_59E8B8 | R | AI_VehicleDistanceThreshold [DERIVED] |
| 0059e8bc | flt_59E8BC | R | PhysicsConstant_59E8BC [DERIVED] |
| 0059e8c0 | flt_59E8C0 | R | AIVisionDistanceMult [DERIVED] |
| 0059e8c4 | flt_59E8C4 | R | SteeringDeltaThreshold [DERIVED] |
| 0059e8c8 | flt_59E8C8 | R | Physics_ConvergenceThreshold [DERIVED] (also: ` — convergence threshold (terminates iteration) |
| 005c3160 | byte_5C3160 | RW | TrackConfigByte_5C3160 [DERIVED] |
| 005ea2c0 | dword_5EA2C0 | R | SetupScenePtr [DERIVED] |
| 007c56a4 | dword_7C56A4 | R | SessionType [FACT] |
| 008acfb4 | flt_8ACFB4 | R | IdleSpeedTarget [DERIVED] (also: ` â€” idle/reverse speed target) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00403aa0 | SpatialTreeNearestNeighborSearch | [LLM] |
| 00426430 | sub_426430 | [LLM] |
| 0042a780 | AIComputePassScore | [LLM] |
| 0042ae00 | AIClearStateFlags | [LLM] |
| 004e87e0 | BrakeThermalModel | [LLM] |
| 004e88b0 | TireGripCoefficient | [LLM] |
| 004e8b80 | AerodynamicForceCalc | [LLM] |
| 004e9100 | TireForce | [LLM] |
| 004efb20 | F_3DTransformWithMatrixMultiplication | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
