## TireCompoundPerWheelPhysicsApplication_0043da10 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_43C250 (0043c250), sub_4F18C0 (004f18c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xAC | RW | — | [LLM] |
| this | 0x145C | R | — | [LLM] |

**Written-by note (persistence):**
- this 0xAC: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e420 | dbl_59E420 | R | BaseDoubleConstant [DERIVED] (also: ` (BaseDoubleConstant = 1.0) |
| 0059e430 | dbl_59E430 | R | ZeroSentinel [DERIVED] (also: ` (ZeroSentinel ~0.0) |
| 0059e890 | dbl_59E890 | R | YawErrorToleranceRad [DERIVED] (also: ` â€” yaw error tolerance (radians) |
| 0059e898 | dbl_59E898 | R | CamberAngleLimitDeg [DERIVED] (also: ` = 90.0 (camber angle limit, degrees) |
| 0059eac8 | dbl_59EAC8 | R | ThermalTempOffset [DERIVED] (also: ` = 273.15 (C→K) |
| 0059eb40 | dbl_59EB40 | R | PositionScalingConstant [DERIVED] |
| 0059ec48 | dbl_59EC48 | R | TireThermalMult [DERIVED] |
| 0059ec50 | dbl_59EC50 | R | [LLM] |
| 0059ec58 | dbl_59EC58 | R | Unknown_Double_59EC58 [DERIVED] |
| 0059ec60 | dbl_59EC60 | R | SuspensionTravelOffset [DERIVED] |
| 0059ec68 | dbl_59EC68 | R | Unknown_Double_59EC68 [DERIVED] |
| 005c421c | aDDevF119992002 | R | SourcePathPrefix [DERIVED] |
| 005c4328 | aTireOptimumCam | R | TireOptimumCamString [DERIVED] |
| 005c4364 | aCouldNotFindOn | R | StringCouldNotFindOn [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 007c569c | dword_7C569C | R | SessionType5 (5=server) [DERIVED] (also: ` — SessionType5 (guards dev logging) |
| 007ce958 | dword_7CE958 | R | TireModelMode [DERIVED] |
| 007d0c60 | dword_7D0C60 | R | TireWearMultiplier [DERIVED] |
| 008acea8 | dword_8ACEA8 | R | Unknown_Scene_Value [DERIVED] |
| 008aceac | dword_8ACEAC | R | Session_RaceConfig_CEAC [DERIVED] |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00438100 | TorqueForceProductComputation | [LLM] |
| 004d5c70 | QuaternionTransformComputation | [LLM] |
| 004d5ee0 | TireLoadFactorSetter | [LLM] |
| 004d6830 | CubicHermiteInterpolation | [LLM] |
| 004d6ae0 | VehicleSuspensionForceHelper | [LLM] |
| 004d7570 | CompoundIndexLookup | [LLM] |
| 004d75d0 | TireSlipCurveNameLookup | [LLM] |
| 004d7a50 | StringSplitLoop | [LLM] |
| 004d7aa0 | DebugLogWrite | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
