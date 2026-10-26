## VehicleSetupInitialization_004e49b0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehiclePhysicsModeDispatcher (004e4930)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x34B0 | R | — | [LLM] |
| this | 0x34B4 | R | — | [LLM] |
| this | 0x34B8 | R | — | elapsedTime (alt) [CONFIRMED] |
| this | 0x34BC | R | — | [LLM] |
| this | 0x34C0 | R | — | [LLM] |
| this | 0x34C4 | R | — | [LLM] |
| this | 0x34C8 | R | — | [LLM] |
| this | 0x34CC | R | — | [LLM] |
| this | 0x34D0 | R | — | [LLM] |
| this | 0x34D4 | RW | — | [LLM] |
| this | 0x34D8 | RW | — | [LLM] |
| this | 0x34DC | RW | — | [LLM] |
| this | 0x34E0 | RW | — | [LLM] |
| this | 0x34E4 | RW | — | [LLM] |
| this | 0x34E8 | RW | 0 | [LLM] |
| this | 0x34EC | RW | — | [LLM] |
| this | 0x34F0 | RW | — | RenderX [FACT] |
| this | 0x34F4 | RW | — | RenderY [FACT] |
| this | 0x34F8 | RW | — | RenderZ [FACT] |
| this | 0x34FC | RW | — | [LLM] |
| this | 0x3500 | RW | — | [LLM] |
| this | 0x3504 | RW | — | [LLM] |
| this | 0x3508 | RW | — | [LLM] |
| this | 0x350C | RW | — | [LLM] |
| this | 0x3510 | R | — | [LLM] |
| this | 0x3514 | RW | — | [LLM] |
| this | 0x3518 | RW | — | [LLM] |
| this | 0x3534 | RW | — | [LLM] |
| this | 0x3538 | RW | — | [LLM] |
| this | 0x353C | RW | — | [LLM] |
| this | 0x3540 | RW | — | [LLM] |
| this | 0x3544 | RW | — | [LLM] |
| this | 0x3548 | RW | — | [LLM] |
| this | 0x3570 | RW | — | [LLM] |
| this | 0x3574 | RW | — | [LLM] |
| this | 0x3578 | RW | — | [LLM] |
| this | 0x35B0 | R | — | [LLM] |
| this | 0x36A8 | R | — | [LLM] |
| this | 0x37A0 | R | — | [LLM] |
| this | 0x3898 | R | — | [LLM] |
| this | 0x3964 | RW | — | [LLM] |
| this | 0x3978 | RW | — | [LLM] |
| this | 0x3994 | RW | — | [LLM] |
| this | 0x39B4 | R | — | [LLM] |
| this | 0x39F0 | RW | — | [LLM] |
| this | 0x3D48 | RW | — | [LLM] |
| this | 0x3D4C | RW | — | [LLM] |
| this | 0x3D50 | RW | — | [LLM] |
| this | 0x3D64 | RW | 18446744072627421184 → -1.0f | [LLM] |

**Written-by note (persistence):**
- this 0x34D4: recalc every frame — external poke does NOT persist
- this 0x34D8: recalc every frame — external poke does NOT persist
- this 0x34DC: recalc every frame — external poke does NOT persist
- this 0x34E0: recalc every frame — external poke does NOT persist
- this 0x34E4: recalc every frame — external poke does NOT persist
- this 0x34E8: recalc every frame — external poke does NOT persist
- this 0x34EC: recalc every frame — external poke does NOT persist
- this 0x34F0: recalc every frame — external poke does NOT persist
- this 0x34F4: recalc every frame — external poke does NOT persist
- this 0x34F8: recalc every frame — external poke does NOT persist
- this 0x34FC: recalc every frame — external poke does NOT persist
- this 0x3500: recalc every frame — external poke does NOT persist
- this 0x3504: recalc every frame — external poke does NOT persist
- this 0x3508: recalc every frame — external poke does NOT persist
- this 0x350C: recalc every frame — external poke does NOT persist
- this 0x3514: recalc every frame — external poke does NOT persist
- this 0x3518: recalc every frame — external poke does NOT persist
- this 0x3534: recalc every frame — external poke does NOT persist
- this 0x3538: recalc every frame — external poke does NOT persist
- this 0x353C: recalc every frame — external poke does NOT persist
- this 0x3540: recalc every frame — external poke does NOT persist
- this 0x3544: recalc every frame — external poke does NOT persist
- this 0x3548: recalc every frame — external poke does NOT persist
- this 0x3570: recalc every frame — external poke does NOT persist
- this 0x3574: recalc every frame — external poke does NOT persist
- this 0x3578: recalc every frame — external poke does NOT persist
- this 0x3964: recalc every frame — external poke does NOT persist
- this 0x3978: recalc every frame — external poke does NOT persist
- this 0x3994: recalc every frame — external poke does NOT persist
- this 0x39F0: recalc every frame — external poke does NOT persist
- this 0x3D48: recalc every frame — external poke does NOT persist
- this 0x3D4C: recalc every frame — external poke does NOT persist
- this 0x3D50: recalc every frame — external poke does NOT persist
- this 0x3D64: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e420 | dbl_59E420 | R | BaseDoubleConstant [DERIVED] (also: ` (BaseDoubleConstant = 1.0) |
| 0059e430 | dbl_59E430 | R | ZeroSentinel [DERIVED] (also: ` (ZeroSentinel ~0.0) |
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e7f8 | flt_59E7F8 | R | AntiRollMixingFactor [DERIVED] |
| 0059e7fc | flt_59E7FC | R | BumpDampingConstant [DERIVED] (also: ` — bump damping constants) |
| 007c7428 | dbl_7C7428 | R | RaceTimeElapsed [DERIVED] |
| 007c7430 | dbl_7C7430 | R | PoseInterpDuration [DERIVED] |
| 007c7438 | dbl_7C7438 | R | Physics_Orientation_7C7438 [DERIVED] |
| 007c74ac | dbl_7C74AC | R | VehicleVelocityVector [DERIVED] |
| 007c75c4 | dbl_7C75C4 | R | GlobalSpeedTime (double) [DERIVED] |
| 007c7918 | unk_7C7918 | R | VehicleDynamics_State [DERIVED] |
| 007c8a18 | dword_7C8A18 | R | Ptr_VehicleTransformBase [DERIVED] |
| 007c8a24 | dbl_7C8A24 | R | SteeringGeometry_dbl_7C8A24 [DERIVED] |
| 007c9084 | dbl_7C9084 | R | CameraTransformDouble [DERIVED] |
| 007c911c | dbl_7C911C | R | SteeringWheelDouble [DERIVED] |
| 007c91dc | dbl_7C91DC | R | DoubleCarOrientationThreshold [CONFIRMED] |
| 007c920c | dbl_7C920C | R | VehiclePhysicsState [DERIVED] |
| 007c9214 | dbl_7C9214 | R | Unknown_Double_Suspension [DERIVED] |
| 007c921c | dbl_7C921C | R | SpeedComparisonThreshold [DERIVED] |
| 007c9318 | dword_7C9318 | R | VehicleOrientationBlock [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0043aee0 | TransformApply3D | [LLM] |
| 00588570 | FloatConvertWrapper | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
