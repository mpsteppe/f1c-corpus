## VehicleSetupInitialization_004e49b0 — VehiclePhysicsStateSnapshotUpdate

**Summary:** Per-frame tick copies vehicle dynamics state (orientation matrix, position, steering geometry, suspension deflection, camera projection) from global physics globals into a local snapshot struct for the vehicle setup/rendering system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehiclePhysicsModeDispatcher (004e4930)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x34B0 | R | — | orientMatrix m00 (row0 col0, copy from dword_7C8A18+28) |
| this | 0x34B4 | R | — | orientMatrix m10 (row1 col0, copy from dword_7C8A18+36) |
| this | 0x34B8 | R | — | elapsedTime (alt) [CONFIRMED] |
| this | 0x34BC | R | — | orientMatrix m01 (row0 col1, from dword_7C8A18+52) |
| this | 0x34C0 | R | — | orientMatrix m11 (row1 col1, from dword_7C8A18+60) |
| this | 0x34C4 | R | — | orientMatrix m21 (row2 col1, from dword_7C8A18+68); guarded for gimbal lock (abs==1.0) |
| this | 0x34C8 | R | — | orientMatrix m02 (row0 col2, from dword_7C8A18+76) |
| this | 0x34CC | R | — | orientMatrix m12 (row1 col2, from dword_7C8A18+84) |
| this | 0x34D0 | R | — | orientMatrix m22 (row2 col2, from dword_7C8A18+92) |
| this | 0x34D4 | RW | — | steeringGeometryResult X (TransformApply3D output v24[0]) |
| this | 0x34D8 | RW | — | steeringGeometryResult Y (v24[1]) |
| this | 0x34DC | RW | — | steeringGeometryResult Z (v24[2]) |
| this | 0x34E0 | RW | — | negSteeringAngle (negated FloatConvertWrapper result on m21) |
| this | 0x34E4 | RW | — | pitchAngle (atan2: gimbal-lock branch uses -m02/m00, else m20/m22) |
| this | 0x34E8 | RW | 0 | rollAngle (atan2: 0 in gimbal-lock branch, else m10/m11) |
| this | 0x34EC | RW | — | vehicleWorldPos X (copied from dword_7C8A18+100) |
| this | 0x34F0 | RW | — | RenderX [FACT] |
| this | 0x34F4 | RW | — | RenderY [FACT] |
| this | 0x34F8 | RW | — | RenderZ [FACT] |
| this | 0x34FC | RW | — | localVelocityY (orientMatrix col1 dot worldPos) |
| this | 0x3500 | RW | — | localVelocityZ (orientMatrix col2 dot worldPos) |
| this | 0x3504 | RW | — | worldSpaceOrigin X (inverse-transform of vehicle position) |
| this | 0x3508 | RW | — | worldSpaceOrigin Y |
| this | 0x350C | RW | — | worldSpaceOrigin Z |
| this | 0x3510 | R | — | prevSpeedValue (read to blend with new speed) |
| this | 0x3514 | RW | — | smoothedSpeed (0.75 * globalSpeed + 0.25 * prev) |
| this | 0x3518 | RW | — | invSmoothedSpeed (1.0 / smoothedSpeed) |
| this | 0x3534 | RW | — | localCameraX (cameraProj dot orientMatrix col0) |
| this | 0x3538 | RW | — | localCameraY (cameraProj dot orientMatrix col1) |
| this | 0x353C | RW | — | localCameraZ (cameraProj dot orientMatrix col2) |
| this | 0x3540 | RW | — | cameraProjX (transform * scale applied to vehicle pos) |
| this | 0x3544 | RW | — | cameraProjY |
| this | 0x3548 | RW | — | cameraProjZ |
| this | 0x3570 | RW | — | poseInterpDuration (copied from dbl_7C7430) |
| this | 0x3574 | RW | — | velocityTimesRaceTime (vel * raceTime from dbl_7C74AC * dbl_7C7428) |
| this | 0x3578 | RW | — | vehicleOrientationScalar (copied from dbl_7C7438) |
| this | 0x35B0 | R | — | suspensionDeflectionRear (index 0 suspension data) |
| this | 0x36A8 | R | — | suspensionDeflectionRear2 (index 1 suspension data) |
| this | 0x37A0 | R | — | suspensionDeflectionFront (index 2 suspension data) |
| this | 0x3898 | R | — | suspensionDeflectionFront2 (index 3 suspension data) |
| this | 0x3964 | RW | — | avgSuspensionDeflection (averaged per mode: 2-wheel or 4-wheel) |
| this | 0x3978 | RW | — | globalSpeedTime (copied from dbl_7C75C4) |
| this | 0x3994 | RW | — | cameraInputClamped (clamped dbl_7C9084 between 0 and dbl_7C911C) |
| this | 0x39B4 | R | — | playerVehicleModeSelector (0=4wheel avg, 1=front, 2=rear) |
| this | 0x39F0 | RW | — | vehicleOrientationBlockPtr (set to dword_7C9318) |
| this | 0x3D48 | RW | — | physicsStateValue0 (from dbl_7C920C when orientation <= 0) |
| this | 0x3D4C | RW | — | physicsStateValue1 (from dbl_7C9214) |
| this | 0x3D50 | RW | — | physicsStateValue2 (from dbl_7C921C) |
| this | 0x3D64 | RW | 18446744072627421184 → -1.0f | signOrThresholdFlag (set to -1.0f when dbl_7C91DC <= 0 and field >= 0) |

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
| 0043aee0 | TransformApply3D | Computes 3x3 matrix * vector transform for steering geometry (inputs: transform base+28, base+4, dbl_7C8A24 → v24) |
| 00588570 | FloatConvertWrapper | Applies conversion/processing to the orientation matrix float data (operates on this+13488 area) |

**Guard conditions:** Field this+0x34C4 (orientMatrix m21): checked `fabs(...) == 1.0` — gimbal-lock detection: if m21 magnitude is 1.0 (singular), pitch uses atan2(-m02, m00) and roll=0; else pitch uses atan2(m20, m22) and roll uses atan2(m10, m11). Field this+0x39B4 (playerVehicleModeSelector): 0 → average all 4 suspension deflections / 4; 1 → average front pair / 2; 2 → average rear pair / 2. Field dbl_7C91DC: if <= 0.0, conditionally sets physics state fields and sign flag to -1.0f.
