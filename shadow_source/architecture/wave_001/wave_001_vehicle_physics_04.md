# VehiclePhysics

Scope: `vehicle_physics`  
Trust: `DERIVED`

Proposed VehiclePhysics subsystem reconstructed from sixteen validated functions. A per-vehicle runtime state object (GUESS, owner unconfirmed in packet) carries the wheel-space transform state: the 3x3 orientation matrix at +0x34B0..+0x34D0, setup/wheel vectors at +0x34D4..+0x350C and +0x3534..+0x3548, body-motion state at +0xFE4..+0xFF8, climb/vibration fields at +0x3994..+0x39C4, per-wheel data at +0x35B0 (62-dword stride, four entries) and the physics-mode selector at +0x32BC. VehiclePhysicsTick dispatches on that selector (cases 0-3) and is the per-frame integration hub; VehicleSetupDataCopy feeds it from VehiclePhysicsTimeStep; VehicleYawRecoveryStateMachine and VehicleDynamicsStateReset run under VehicleYawRotationRecoveryController. A shared physics buffer (dbl_7C7428) backs suspension/body-motion fallbacks. Configuration parsers (damage, engine, per-wheel brake/suspension, damping validation, engine-map field definitions) share a token-stream helper family and validate inputs with session-gated debug logging. All class ownership and field semantics are DERIVED/GUESS; only the address-level function boundaries and call relationships are packet-confirmed.

## Function roles

- `0x004EFA40` **Vehicle** — Adjust vehicle climb/throttle value: when the rigid-body constraint pointer at +0x32BC is non-zero, clamp climb (+0x3994) to the minimum (+0x399C) or recompute a climb vibration level from the weather-noise ring buffer (flt_8AB274 / dword_8AAE70) into +0x39B8..; when the pointer is null, fall back to SuspensionVibration on the shared dbl_7C7428 buffer.
- `0x004EFB20` **Vehicle** — Transform a point by the stored 3x3 matrix (+0x34B0..+0x34D0) plus translation (+0x34D4..+0x34DC) after sampling RideHeightDelta, copy three dwords (+0x34E0..+0x34E8) into a3, and return the middle copied dword. Called from eleven sites including AIRacingLine, VehicleMainPhysicsUpdate, SessionStateTransition and VehicleYawRotationRecoveryController.
- `0x004F0430` **Vehicle** — Per-frame vehicle physics update dispatched on the mode selector at +0x32BC (cases 0-3 via jpt_4F046E): integrates the wheel-space transform chain, updates HUD elements 43/44, queries body-motion state, runs per-wheel collision/suspension/vibration geometry, and triggers vehicle sound on an instance-id match; then runs SteeringForceWithRandom and, for handled modes, VehicleStateUpdate plus a 16-tick damping/flag governor.
- `0x004F1650` **Vehicle** — Copy setup vectors from six sources (a2..a7) plus a 0x24-byte orientation matrix block into +0x34B0..+0x350C / +0x3534..+0x353C and compute two 3x3 matrix-vector transforms (+0x34F8..+0x3500 and +0x3540..+0x3548) for render coordinates; store a8 at +0x39F0 and return it. Called per frame from VehiclePhysicsTimeStep.
- `0x004F1FE0` **Vehicle** — Per-frame yaw-recovery state machine branching on the state dword at obj+0x4064: the non-zero path accumulates time at +0x4004 and, past a 15.0 threshold, resets counters and (session 7, audio flag +0x1051) fires an audio effect; the zero path runs off-track detection (obj+0x4170, dword_7CE814, wheel array, +0x3994) and position recovery via nearest-path lookup (sub_403640) and a lateral-distance bound test, marking +0x3D60 = 2 and emitting render/AI-tracking notifications in session 7.
- `0x004F2320` **Vehicle** — Vehicle dynamics state reset: zero the nine dwords +0x34EC..+0x350C, zero the four per-wheel entries at +0x35B0 (62-dword stride), and when the enable flag +0x32BC is clear also zero the shared suspension physics buffer (dbl_7C7428); returns the per-wheel array base or the conditional call's result.
- `0x004F24F0` **VehicleDamageModel** — Parse the vehicle damage configuration stream: open in binary-read mode, locate the Physical subsection, and decode collision/detach/aero/random-damage parameters into a flat struct (general physics, front/rear wing, four wheels, eight detachable parts) with generated Wheel%d/Part%d keys; returns 0 on success, -1 when the stream cannot be opened. Invoked by TheSvmHdvVehicleFileParser.
- `0x004F2B50` **TireModel** — Zero a 16-element array at the object base then write a block of physics default constants through the target (DWORD indices 18..65); returns the target. Called from TireModelDataInit.
- `0x004F2C60` **PerWheelBrakeSuspensionDataLoader** — Parse per-wheel brake/suspension configuration doubles from a shared token stream (handle 384) into a double array (bump/rebound travel, bump-stop params, brake torque/wear/fade/thermal, pushrod values, Celsius-to-Kelvin brake optimum at this+0xB8), then normalize 11 range/setting pairs into the corner block (704-byte stride by wheel index) with a deg-to-rad camber multiplier. Called by TheSvmHdvVehicleFileParser.
- `0x004F31F0` **TireModel** — Zero-initializer: clear six DWORDs per iteration over six iterations from this+4, then explicitly zero +0x90..+0xA4, and return this. Called by TireModelDataInit.
- `0x004F3240` **HdvFileParser** — Damping-direction sign validation during .hdv loading: parse three damping doubles from a token into a 24-byte triple selected by direction index (0-5) and log per-axis warnings when the damping sign opposes expected motion, suppressed in session type 5.
- `0x004F3C10` **EngineSetup** — Engine-map field-definition registration: register three range/setting pairs (rev limit, engine map, engine braking multiplier) on the setup target via CRTMathHelper_e1f0 with RPM-scale and unit scales. Invoked by EngineSectionParser and TheSvmHdvVehicleFileParser.
- `0x004F3C80` **EngineSectionParser** — Parse the [ENGINE] section of the vehicle engine configuration: fuel/inertia, idle/launch/rev-limit (RPM converted to rad/s), the RPM-torque curve, lifetime and thermal parameters, with idle/launch/curve ordering and point-count validation logged in non-server sessions; ends with stream cleanup. Invoked by TheSvmHdvVehicleFileParser.
- `0x004F69E0` **WheelParameterEvaluator** — Evaluate linear combinations of three scalar inputs against per-field coefficients and biases on the 'this' object, writing two force component magnitudes (fabs of +0x444 / +0x47C) and a combined output into a5 and a6; unconditional on the per-frame physics path.
- `0x004FB260` **Vehicle** — Lerp-interpolate a base value between two prior float fields by factor a2, store it at +0xA0, then write three coefficient-scaled plus bias-adjusted outputs to +0x94/+0x98/+0x9C; returns the float bit pattern of the +0x9C output. Per-frame physics state propagation with distance/time falloff.
- `0x004FB2E0` **Vehicle** — Compute closest-approach proximity distances from this vehicle to two target entities by projecting position+direction lines: target1 via the +0x110 pointer, target2 via the +0x114 pointer, own data via the +0x10C block; parallel directions store a sentinel, self references store 0, otherwise the smaller line distance is stored at +0xB0/+0xB4.

## Proposed classes

### Vehicle

Per-vehicle runtime physics and state object (packet 'this' base): wheel-space transform matrix +0x34B0..+0x34D0, setup/wheel/velocity vectors +0x34D4..+0x350C and +0x3534..+0x3548, world position/velocity +0x10..+0x54, body-motion state +0xFE4..+0xFF8, per-wheel data +0x35B0, climb/vibration +0x3994..+0x39C4, proximity links +0x10C/0x110/0x114, recovery counters, and the physics-mode selector +0x32BC.

Methods: `0x004EFA40`, `0x004EFB20`, `0x004F0430`, `0x004F1650`, `0x004F1FE0`, `0x004F2320`, `0x004FB260`, `0x004FB2E0`

- `this+0x00000000` `ptr ObjectBasePtr` (read, GUESS)
- `this+0x00000004` `int32 VehicleIndex` (read, GUESS)
- `this+0x00000010` `float WorldPositionX` (read_write, GUESS)
- `this+0x00000014` `float WorldPositionY` (read_write, GUESS)
- `this+0x00000018` `float WorldPositionZ` (read_write, GUESS)
- `this+0x0000004C` `float WorldVelocityX` (read_write, GUESS)
- `this+0x00000050` `float WorldVelocityY` (read_write, GUESS)
- `this+0x00000054` `float WorldVelocityZ` (read_write, GUESS)
- `this+0x00000058` `float ContactPositionX` (read_write, GUESS)
- `this+0x0000005C` `float ContactPositionY` (read_write, GUESS)
- `this+0x00000060` `float ContactPositionZ` (read_write, GUESS)
- `this+0x00000094` `float MotionOutput0` (read_write, GUESS)
- `this+0x00000098` `float MotionOutput1` (read_write, GUESS)
- `this+0x0000009C` `float MotionOutput2` (read_write, GUESS)
- `this+0x000000A0` `float MotionLerpBase` (read_write, GUESS)
- `this+0x000000A4` `float DirectionX` (read_write, GUESS)
- `this+0x000000AC` `float DirectionY` (read_write, GUESS)
- `this+0x000000B0` `float ProximityTarget1` (write, GUESS)
- `this+0x000000B4` `float ProximityTarget2` (write, GUESS)
- `this+0x0000010C` `ptr OwnMotionDataBlockPtr` (read, GUESS)
- `this+0x00000110` `ptr ProximityTarget1Ptr` (read, GUESS)
- `this+0x00000114` `ptr ProximityTarget2Ptr` (read, GUESS)
- `this+0x00000828` `ptr WheelEntityArrayBase` (read, GUESS)
- `this+0x00000868` `byte WheelCollisionActiveFlag` (read, GUESS)
- `this+0x00000FE4` `float BodyMotionPosX` (read_write, GUESS)
- `this+0x00000FE8` `float BodyMotionPosY` (read_write, GUESS)
- `this+0x00000FEC` `float BodyMotionPosZ` (read_write, GUESS)
- `this+0x00000FF0` `float BodyMotionOrientX` (read_write, GUESS)
- `this+0x00000FF4` `float BodyMotionOrientY` (read_write, GUESS)
- `this+0x00000FF8` `float BodyMotionOrientZ` (read_write, GUESS)
- `this+0x00001030` `float DampingInput` (read, GUESS)
- `this+0x00001034` `float ClampedBodyMotionValue` (read_write, GUESS)
- `this+0x00001048` `float AudioEffectValue` (read, GUESS)
- `this+0x00001051` `byte AudioTriggerFlag` (read_write, GUESS)
- `this+0x00001059` `byte VelocityThresholdFlag` (read_write, GUESS)
- `this+0x0000105B` `byte DampingGovernorFlag` (read_write, GUESS)
- `this+0x0000105D` `byte StateFlag` (read_write, GUESS)
- `this+0x000032BC` `int32 PhysicsModeSelector` (read, GUESS)
- `this+0x000034AC` `float PreviousTimestamp` (read, GUESS)
- `this+0x000034B0` `float OrientationMatrix0` (read_write, GUESS)
- `this+0x000034B4` `float OrientationMatrix1` (read_write, GUESS)
- `this+0x000034B8` `float OrientationMatrix2` (read_write, GUESS)
- `this+0x000034BC` `float OrientationMatrix3` (read_write, GUESS)
- `this+0x000034C0` `float OrientationMatrix4` (read_write, GUESS)
- `this+0x000034C4` `float OrientationMatrix5` (read_write, GUESS)
- `this+0x000034C8` `float OrientationMatrix6` (read_write, GUESS)
- `this+0x000034CC` `float OrientationMatrix7` (read_write, GUESS)
- `this+0x000034D0` `float OrientationMatrix8` (read_write, GUESS)
- `this+0x000034D4` `float WheelPositionX` (read_write, GUESS)
- `this+0x000034D8` `float WheelPositionY` (read_write, GUESS)
- `this+0x000034DC` `float WheelPositionZ` (read_write, GUESS)
- `this+0x000034E0` `float WheelOffsetX` (read_write, GUESS)
- `this+0x000034E4` `float WheelOffsetY` (read_write, GUESS)
- `this+0x000034E8` `float WheelOffsetZ` (read_write, GUESS)
- `this+0x000034EC` `float WheelVelocityX` (read_write, GUESS)
- `this+0x000034F0` `float WheelVelocityY` (read_write, GUESS)
- `this+0x000034F4` `float WheelVelocityZ` (read_write, GUESS)
- `this+0x000034F8` `float TransformedVelocityX` (read_write, GUESS)
- `this+0x000034FC` `float TransformedVelocityY` (read_write, GUESS)
- `this+0x00003500` `float TransformedVelocityZ` (read_write, GUESS)
- `this+0x00003504` `float TorqueAxisX` (read_write, GUESS)
- `this+0x00003508` `float TorqueAxisY` (read_write, GUESS)
- `this+0x0000350C` `float TorqueAxisZ` (read_write, GUESS)
- `this+0x00003534` `float SecondaryVectorX` (read_write, GUESS)
- `this+0x00003538` `float SecondaryVectorY` (read_write, GUESS)
- `this+0x0000353C` `float SecondaryVectorZ` (read_write, GUESS)
- `this+0x00003540` `float TransformedSecondaryX` (read_write, GUESS)
- `this+0x00003544` `float TransformedSecondaryY` (read_write, GUESS)
- `this+0x00003548` `float TransformedSecondaryZ` (read_write, GUESS)
- `this+0x00003570` `float MotionSourceValue` (read, GUESS)
- `this+0x00003574` `float UnclampedBodyMotionValue` (read, GUESS)
- `this+0x00003578` `float SpeedThresholdValue` (read, GUESS)
- `this+0x000035A4` `float WheelTorqueAccum` (read_write, GUESS)
- `this+0x000035A8` `float TorqueProduct` (read_write, GUESS)
- `this+0x000035B0` `ptr PerWheelDataArray` (read_write, GUESS)
- `this+0x000036A0` `float TorqueProductCopy` (read_write, GUESS)
- `this+0x00003960` `float WheelTorqueInput` (read, GUESS)
- `this+0x00003978` `float ClimbEnableCheck` (read, GUESS)
- `this+0x00003994` `float ClimbValue` (read_write, GUESS)
- `this+0x0000399C` `float ClimbMinimum` (read, GUESS)
- `this+0x000039B8` `float ClimbVibrationLevel` (write, GUESS)
- `this+0x000039BC` `float VibrationBias` (read, GUESS)
- `this+0x000039C0` `float VibrationScale` (read, GUESS)
- `this+0x000039C4` `float VibrationOffset` (read, GUESS)
- `this+0x000039F0` `float SetupReturnValue` (read_write, GUESS)
- `this+0x00003A9C` `ptr NearestPathData` (write, GUESS)
- `this+0x00003D48` `int32 RecoveryCounter0` (write, GUESS)
- `this+0x00003D4C` `int32 RecoveryCounter1` (write, GUESS)
- `this+0x00003D50` `int32 RecoveryCounter2` (write, GUESS)
- `this+0x00003D60` `int32 RecoveryState` (read_write, GUESS)
- `this+0x00003FF8` `float RecoveryOutputPosX` (read_write, GUESS)
- `this+0x00003FFC` `float RecoveryOutputPosY` (read_write, GUESS)
- `this+0x00004000` `float RecoveryOutputPosZ` (read_write, GUESS)
- `this+0x00004004` `float RecoveryAccumulator` (read_write, GUESS)
- `this+0x00004018` `byte HudElement43Flag` (read, GUESS)
- `this+0x0000401C` `float HudElement44Value` (read_write, GUESS)
- `this+0x00004020` `byte PhysicsTickCounter` (read_write, GUESS)

### VehicleBodyObject

Object reached by dereferencing this[0] (packet 'obj' base): carries the post-process input state dword (+0x4064), an off-track distance (+0x4170, FLT_MAX sentinel), a mode/lap-line field (+0x3450) and the instance id (+0x4894) used to gate the vehicle sound trigger.

Methods: 

- `obj+0x00003450` `int32 LapLineIndex` (read, GUESS)
- `obj+0x00004064` `int32 PostProcessInputState` (read, GUESS)
- `obj+0x00004170` `float OffTrackDistance` (read, GUESS)
- `obj+0x00004894` `int32 InstanceId` (read, GUESS)

### MotionLineEntity

Position+direction line object (packet bases *(this+0x10C) own data block and *(this+0x110) target1): position at +0x94/+0x9C, direction at +0xA4/+0xAC, plus an internal self pointer (+0x110) on target1. Consumed by VehicleProximity for closest-approach projection.

Methods: 

- `*(this+0x10C)+0x00000094` `float PositionX` (read, GUESS)
- `*(this+0x10C)+0x0000009C` `float PositionY` (read, GUESS)
- `*(this+0x10C)+0x000000A4` `float DirectionX` (read, GUESS)
- `*(this+0x10C)+0x000000AC` `float DirectionY` (read, GUESS)
- `*(this+0x110)+0x00000094` `float PositionX` (read, GUESS)
- `*(this+0x110)+0x0000009C` `float PositionY` (read, GUESS)
- `*(this+0x110)+0x000000A4` `float DirectionX` (read, GUESS)
- `*(this+0x110)+0x000000AC` `float DirectionY` (read, GUESS)
- `*(this+0x110)+0x00000110` `ptr SelfObjectPtr` (read, GUESS)

### ProximityTargetEntity

Second proximity target object (packet base *(this+0x114)): a different layout from the motion-line objects, exposing position at +0x0/+0x8 only. Used by VehicleProximity's target2 projection.

Methods: 

- `*(this+0x114)+0x00000000` `float PositionX` (read, GUESS)
- `*(this+0x114)+0x00000008` `float PositionY` (read, GUESS)

### VehicleDamageModel

Flat vehicle damage configuration struct populated by ParseVehicleDamageConfig: general physics, front/rear wing, four wheels and eight detachable parts. Damage parameter slots (this+0..this+132 observed) are not field-evidenced by the packet.

Methods: `0x004F24F0`


### EngineSetup

Engine setup configuration struct populated by ParseEngineSection with field definitions registered by EngineMapSetupFieldDefinitions: idle/launch/rev-limit RPM (rad/s), RPM-torque curve, idle throttle clamp, lifetime RPM/temperature and optimum oil temperature (+0x12C8).

Methods: `0x004F3C10`

- `this+0x0000068C` `float IdleRpmMin` (read_write, GUESS)
- `this+0x00000694` `float IdleRpmMax` (read_write, GUESS)
- `this+0x0000069C` `float IdleThrottle` (read_write, GUESS)
- `this+0x000006A0` `float IdleThrottleClamp` (read_write, GUESS)
- `this+0x000006AC` `float LaunchRpmMin` (read_write, GUESS)
- `this+0x000006B4` `float LaunchRpmMax` (read_write, GUESS)
- `this+0x000006BC` `float RevLimit` (read_write, GUESS)
- `this+0x000006C4` `int32 RpmTorquePointCount` (read_write, GUESS)
- `this+0x000006C8` `ptr RpmTorqueCurveBase` (read_write, GUESS)
- `this+0x000006D0` `float RpmTorqueThrottle` (read_write, GUESS)
- `this+0x000006D8` `float RpmTorqueBrake` (read_write, GUESS)
- `this+0x000012C8` `float OptimumOilTemp` (read_write, GUESS)
- `this+0x00001310` `float LifetimeRpmMin` (read_write, GUESS)
- `this+0x00001318` `float LifetimeRpmMax` (read_write, GUESS)
- `this+0x00001320` `float LifetimeOilTempMin` (read_write, GUESS)

### PerWheelBrakeSuspensionDataLoader

Parser object for per-wheel brake/suspension configuration (token stream to double array, then corner-block normalization). Only this+0xB8 (brake optimum temperature, Kelvin) is field-evidenced; the remaining double-array element mapping is derived from token names.

Methods: `0x004F2C60`

- `this+0x000000B8` `double BrakeOptimumTempKelvin` (read_write, GUESS)

### HdvFileParser

Vehicle .hdv loading helper: validates damping-direction signs per axis (VehicleDampingDirectionValidation) with session-gated debug logging. Class identity is GUESS; no field layout is evidenced.

Methods: `0x004F3240`


### TireModel

Tire model data object initialized by tireModelZeroInit and PhysicsDefaultsInitializer during TireModelDataInit: head region and trailing fields +0x90..+0xA4 are zeroed, then a block of physics default constants is written (DWORD indices 18..65, offsets not field-evidenced).

Methods: `0x004F2B50`, `0x004F31F0`

- `this+0x00000010` `int32 TireState0` (write, GUESS)
- `this+0x00000014` `int32 TireState1` (write, GUESS)
- `this+0x00000090` `float TireField90` (write, GUESS)
- `this+0x00000094` `float TireField94` (write, GUESS)
- `this+0x00000098` `float TireField98` (write, GUESS)
- `this+0x0000009C` `float TireField9C` (write, GUESS)
- `this+0x000000A0` `float TireFieldA0` (write, GUESS)
- `this+0x000000A4` `float TireFieldA4` (write, GUESS)

### WheelParameterEvaluator

Per-frame wheel parameter evaluator: computes linear combinations of three scalar inputs against coefficient/bias doubles (this+0x3F4..+0x530) producing two force magnitudes and a combined output. Field names and physical meaning are GUESS; the packet proves only the linear structure.

Methods: `0x004F69E0`

- `this+0x000003F4` `double CoefficientBias0` (read, GUESS)
- `this+0x000003FC` `double CoefficientInput4` (read, GUESS)
- `this+0x00000444` `double ForceComponent0` (read, GUESS)
- `this+0x0000047C` `double ForceComponent1` (read, GUESS)
- `this+0x000004AC` `double CombinedOutputBias` (read, GUESS)
- `this+0x00000518` `double CoefficientInput2` (read, GUESS)
- `this+0x00000520` `double CoefficientInput3` (read, GUESS)
- `this+0x00000528` `double CoefficientInput1` (read, GUESS)
- `this+0x00000530` `double CoefficientInput0` (read, GUESS)

## Compatibility contracts

- **PerVehiclePhysicsStateLayout** — A replacement executable must preserve the per-vehicle state object ('this' base) layout touched every frame: orientation matrix block +0x34B0..+0x34D0, wheel/setup vectors +0x34D4..+0x350C and +0x3534..+0x3548, world position/velocity +0x10..+0x54, body-motion state +0xFE4..+0xFF8, per-wheel data at +0x35B0 (four entries, 62-dword stride), climb/vibration +0x3994..+0x39C4, and the physics-mode selector at +0x32BC (dispatched by VehiclePhysicsTick and read by VehicleYawRecoveryStateMachine, VehicleDynamicsStateReset and VehicleClimbAdjust).
- **SharedPhysicsBufferAndRegistry** — dbl_7C7428 is the shared suspension/body-motion physics object read and reset by VehicleClimbAdjust, VehicleDynamicsStateReset and VehiclePhysicsTick; dword_7C54F0[dword_7C54DC] selects the active vehicle whose instance id (obj+0x4894) gates the sound trigger; dword_7C8B44/0x7C8B48 are reset before the trigger.
- **VehicleStateArrayStride** — Vehicle state array rooted at global 0x5EC6D8 is indexed by the vehicle index field (this+0x4) with a 18624-byte (0x48C0) stride during VehiclePhysicsTick case-3 delegation to VehiclePhysicsTimeStep.
- **SessionTypeGatedDiagnostics** — Debug warnings during configuration load are suppressed when session type dword_7C569C == 5 (server), and recovery/audio notifications require dword_7C56A4 == 7; these globals gate diagnostic and notification side effects and must keep their semantics.
- **HudElement43_44Contract** — VehiclePhysicsTick emits HUDElementConfig(43/44,...) each handled frame driven by the flags this+0x4018 (element 43) and this+0x401C (element 44, scaled by dbl_7C7598*4 clamped to 1.0); a replacement must reproduce these HUD updates or accept missing HUD output.
- **DampingGovernorSemantics** — After each handled physics mode, the damping governor recomputes this+0x105B from v75 = 0.94 - this+0x1030*0.9 against globals flt_8AFECC/8AFEE8/8AFEEC every 16 ticks (counter this+0x4020); external pokes to +0x105B do not persist because the field is recomputed.

## Unresolved

- Class ownership is GUESS: the packet declares UnknownObject owners for eight of the sixteen functions; grouping them into a single Vehicle class (plus VehicleBodyObject for the 'obj' base reached via this[0]) is worker synthesis, not packet-proven common ownership.
- The 'this' base offsets 0x94..0xA0 appear on both Vehicle (motion outputs, per physics functions) and TireModel (zero-init region). The packet does not prove these are the same object, so they are kept as distinct field identities per rule 8.
- VehiclePhysicsTick reads twelve float/double constants (flt_59E43C, flt_59E440, flt_59E444, flt_59E450, flt_59E46C, flt_59E670, flt_59E824, dbl_59ED28, flt_5ACD48, flt_5ACDC0, flt_5AD164, flt_5AD180) that do not appear directly in the raw source; their roles are unknown and they are carried in unresolved_evidence_refs.
- The config-token string globals (0x005D4E90..0x005D572C) are read by the parse functions as Wheel%d/Part%d key templates and scalar tokens whose text content is not recovered in the packet; the exact token-to-offset mapping is DERIVED from the operation prose and unconfirmed.
- Unreferenced-by-body globals dbl_5AD278/5AD280 (VehicleProximity epsilon candidates), flt_59E43C (PropagateLerpedPhysicsState), and dword_5EB978/0x008ACEE0 (VehicleYawRecoveryStateMachine) plus the VehicleYawRecoveryStateMachine flt_59E84C/59E864/59E8D8/59EAE0 and dbl_59E420/59EA38/59EAC8/5AD258 (ParseEngineSection constant candidates) are listed by the IDB but absent from the decompiled bodies; they are carried in unresolved_evidence_refs.
- VehicleYawRecoveryStateMachine status flags v8/v9 and v22/v23 are read without a visible assignment (Hex-Rays artifacts); the comparisons that set them are unresolved.
- The SuspensionVibration fallback called by VehicleClimbAdjust and the suspension state-zeroing routine named in VehicleDynamicsStateReset's raw source are not in the packet callee lists; their addresses are unverified.
- TransformPointByMatrix matrix layout (row-major vs column-major at +0x34B0..+0x34D0), the meaning of the 3-dword copy into a3 and the returned a3[1], and the behavior of RideHeightDelta are not recoverable from this packet.
- PhysicsDefaultsInitializer reads v1 before assignment; the literal write target (DWORD indices 18..65, ~192 bytes) is ambiguous and its byte offsets are not field-evidenced.
- LoadPerWheelBrakeSuspensionData's 704-byte corner-block stride and offsets 176..816 are observed from the body but not packet field-evidenced; a3 is unused in the visible body.
- VehicleDampingDirectionValidation's six force-apply log strings and section token are referenced by address only; their text content is not recovered and dbl_59E430 as a 0.0 sentinel is DERIVED.
- EngineMapSetupFieldDefinitions/ParseEngineSection target pointers at this+5488/+5552/+5616 have no field evidence refs; the layout they index is not defined here.
- VehicleProximity writes the large float sentinel 2139095039 at +0xB4 for the non-self parallel case only in raw source beyond the packet truncation; the sentinel value is not a packet field.
- evaluateLinearVehicleParameters output written through a6 is computed but never read inside the function; its downstream consumer is not in the packet.
