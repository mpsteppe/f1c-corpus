## VehicleYawRotationRecoveryController_004f1c40 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** MainGameTickUpdate (0042c690)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x48BC | R | — | [LLM] |
| this | 0x0 | R | — | postProcessInput [CONFIRMED] |
| this | 0x828 | R | — | [LLM] |
| this | 0x868 | R | — | [LLM] |
| this | 0x32BC | R | — | [LLM] |
| this | 0x34B8 | R | — | elapsedTime (alt) [CONFIRMED] |
| this | 0x34C0 | R | — | [LLM] |
| this | 0x34D0 | R | — | [LLM] |
| this | 0x34D4 | RW | — | [LLM] |
| this | 0x34D8 | RW | — | [LLM] |
| this | 0x34DC | RW | — | [LLM] |
| this | 0x34E0 | RW | 0 | [LLM] |
| this | 0x34E4 | RW | — | [LLM] |
| this | 0x34E8 | RW | 0 | [LLM] |
| this | 0x3668 | R | — | [LLM] |
| this | 0x3FF4 | RW | 0 | [LLM] |
| this | 0x4008 | RW | — | [LLM] |
| this | 0x400C | RW | — | [LLM] |
| this | 0x4010 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x34D4: recalc every frame — external poke does NOT persist
- this 0x34D8: recalc every frame — external poke does NOT persist
- this 0x34DC: recalc every frame — external poke does NOT persist
- this 0x34E0: recalc every frame — external poke does NOT persist
- this 0x34E4: recalc every frame — external poke does NOT persist
- this 0x34E8: recalc every frame — external poke does NOT persist
- this 0x3FF4: recalc every frame — external poke does NOT persist
- this 0x4008: recalc every frame — external poke does NOT persist
- this 0x400C: recalc every frame — external poke does NOT persist
- this 0x4010: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e478 | flt_59E478 | R | SteeringCenterBoost [DERIVED] |
| 0059e7ec | flt_59E7EC | R | ZeroConstant [DERIVED] (also: ` — compared constant (5.0f encoded indirectly) |
| 0059e84c | flt_59E84C | R | VelocityRateLimit [DERIVED] (also: ` — display message threshold) |
| 0059e8a0 | flt_59E8A0 | R | InvSqrtThreshold [DERIVED] (also: ` — proximity distance² threshold) |
| 005ad1c4 | flt_5AD1C4 | R | CollisionVelocityThreshold [DERIVED] |
| 007c749f | byte_7C749F | R | Byte_PlayerControlFlag [DERIVED] |
| 007c74a3 | byte_7C74A3 | R | VehicleFlagByte_7C74A3 [DERIVED] |
| 007d0af8 | byte_7D0AF8 | R | Byte_DriverFlag [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004ebc60 | VehicleContactForceAccumulation | [LLM] |
| 004ec080 | VehicleTelemetryPositionAccumulator | [LLM] |
| 004ed420 | VehicleGeometryProximityTest | [LLM] |
| 004ef7c0 | AIVehiclePathPositionTracking | [LLM] |
| 004efb20 | F_3DTransformWithMatrixMultiplication | [LLM] |
| 004f1fe0 | sub_4F1FE0 | [LLM] |
| 004f2320 | VehicleDynamicsStateReset | [LLM] |
| 00566e40 | EulerToRotationMatrix | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
