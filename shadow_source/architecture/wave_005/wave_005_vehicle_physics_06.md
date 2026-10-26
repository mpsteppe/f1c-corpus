# VehiclePhysics

Scope: `vehicle_physics`  
Trust: `DERIVED`

A DERIVED architecture proposal for the vehicle_physics scope. The packet's 18 functions divide into one large vehicle physics state object (10 functions sharing the 0x32BC mode flag, 0x34B0 rotation matrix, 0x3668 wheel-contact array and body-position block) plus five smaller objects: a wheel angular-velocity integrator float state (0x004E43D0), a spatial-grid float update object (0x005000E0), a collision contact-state object (0x0054D7A0), a 4x4 matrix transform (0x0050D47D, 0x0052401F) and an engine-sound wave-table state (0x00513482). Owners are universally UNKNOWN; every function_roles owner and class boundary is DERIVED or GUESS. Key evidence-linked contracts: the physics processing mode enum at this+0x32BC (0/1/2 in 0x004E4930), the 50.265484 clamp-threshold dispatch (0x004E43D0), the integration sub-step selection (0x004E4E60), the contact-state low-bit encoding 1/2/4 (0x0054D7A0), and the wheel-contact surface contract (surface ids at +0x30/+0x34 behind entry pointer at +0x54). Several offsets are overloaded across the packet's own functions (0x32BC, 0x34B8, 0x3508) and are flagged as unresolved rather than resolved.

## Function roles

- `0x004E43D0` **WheelAngularVelocityState** — Per-frame angular-velocity integrator over a float state vector; accumulates rotation, drives the velocity state toward a sign-selected bounded target with gain and convergence factor, and dispatches through InterruptDispatch when |this+0x24| exceeds the 50.265484 clamp threshold.
- `0x004E4930` **VehiclePhysicsState** — Routes vehicle physics processing by the mode flag at this+0x32BC: 0 full initialization, 1 sub-step integration, 2 team-color load, else no-op.
- `0x004E4E60` **VehiclePhysicsState** — Vehicle physics time-integration driver: selects an integration sub-step size from wheel-speed squared, writes it to 4 wheel slots at this+0x35F0 (62-DWORD stride), then runs the sub-step count of suspension/tire physics chain iterations.
- `0x004E4F40` **VehiclePhysicsState** — Per-frame suspension force initialization and damping-rate recomputation: zeroes per-wheel spring/damper accumulators, runs brake-cooling post-treatment when enabled, and re-selects/recomputes damping rates when the requested rate index changes.
- `0x004E9600` **VehiclePhysicsState** — Instance method that refreshes a 3x3 suspension transform matrix via F_3x3MatrixTransform and returns the result of an unresolved FieldReadDelegate tail helper.
- `0x004E9A40` **VehiclePhysicsState** — Computes the distance from the predicted body position to the wheel-contact reference and writes a 13-element contact array into the network packet; returns the norm of the local contact vector clamped to the stored minimum.
- `0x004EBC60` **VehiclePhysicsState** — Per-frame contact-impulse accumulation for a vehicle: transforms local contact basis and impulse through the rotation matrix, accumulates world-space linear and angular impulses, then dispatches on this+0x32BC (physics impulse / collision sparks / pointer-chain short-vector processing).
- `0x004ED220` **VehiclePhysicsState** — Per-frame physics timing step: clamps the accumulated time delta, then applies the global physics damping scale dbl_7C7428 unless the gate at this+0x32BC is set.
- `0x004ED420` **VehiclePhysicsState** — Vehicle geometry proximity/contact test: transforms a probe point into the vehicle-local frame, iterates up to four vehicle corners, and on a hit computes an anisotropic contact response with signed depth projection.
- `0x004F0F40` **VehiclePhysicsState** — Aggregates wheel contact forces across the 4 wheels for a given surface type, grip-weighted, and stores the normalized result via PerIndexStructFieldSetter (index 2).
- `0x004F1120` **VehiclePhysicsState** — Aggregates wheel forces across the 4 wheels for a given surface type, speed-weighted by a clamped speed parameter, and stores the normalized result via PerIndexStructFieldSetter (index 1).
- `0x004F12E0` **VehiclePhysicsState** — Per-frame vehicle sound/HUD trigger on the wheel-contact path: walks the wheel array, aggregates forces per unique surface, and drives HUD elements 5, 42 and 38 via HUDElementConfig.
- `0x004F1C40` **VehiclePhysicsState** — Per-frame vehicle yaw-recovery controller: detects sustained excessive yaw rotation or loss of ground contact and restores the vehicle by resetting dynamics, rebuilding orientation, and re-anchoring to the racing line.
- `0x005000E0` **SpatialGridFloatState** — Conditionally updates a float field (a1[3], this+0xC) by adding a2 after validating the position vector with a spatial-grid query; returns 1 on update, 0 otherwise.
- `0x0050D47D` **Matrix4x4Transform** — Initializes a 4x4 matrix at a1 to a diagonal form (a2/a3/a4 on the diagonal, 1.0 homogeneous), zeroing every other element.
- `0x00513482` **EngineSoundWaveTableState** — Generates PCM wave tables for engine-sound synthesis: quality selector picks a multi-channel 16-bit table array or a 256-byte mono ramp table; samples converted with CRTFtol and normalized through read-only double constants.
- `0x0052401F` **Matrix4x4Transform** — Composes a 4x4 transformation matrix from a scale value, an optional rotation matrix (inverse/adjugate), an optional origin matrix and an optional additive translation, using 3DNow math.
- `0x0054D7A0` **CollisionContactState** — Computes the distance between two collision feature offsets and classifies the contact state stored in the low bits of the state word at this+0x14 (1 potential, 2 separated, 4 contact); bit 0x10 selects a plane-based path.

## Proposed classes

### VehiclePhysicsState

Primary per-frame vehicle physics object. Owns the physics mode flag, rotation matrix, body/stored position, wheel contact array, contact-impulse accumulators, suspension damping-rate tables, and yaw-recovery state read and written by the packet's vehicle-physics functions.

Methods: `0x004E4930`, `0x004E4E60`, `0x004E4F40`, `0x004E9600`, `0x004E9A40`, `0x004EBC60`, `0x004ED220`, `0x004ED420`, `0x004F0F40`, `0x004F1120`, `0x004F12E0`, `0x004F1C40`

- `this+0x00000000` `void* postProcessInputPtr` (read, DERIVED)
- `this+0x000005FC` `uint8_t hudTimerFlag` (write, DERIVED)
- `this+0x0000072C` `float localContactAnchorX` (read, DERIVED)
- `this+0x00000730` `float localContactAnchorY` (read, DERIVED)
- `this+0x00000734` `float localContactAnchorZ` (read, DERIVED)
- `this+0x000007A4` `float hudTimerValue` (read, DERIVED)
- `this+0x00000828` `ContactEntry[4] cornerContactEntries` (read, DERIVED)
- `this+0x00000868` `uint8_t cornerContactActiveByte` (read, DERIVED)
- `this+0x000032BC` `int32_t physicsModeFlag` (read_write, DERIVED)
- `this+0x00003498` `int32_t integrationSubstepCount` (read, DERIVED)
- `this+0x0000349C` `float integrationSpeedThreshold` (read, DERIVED)
- `this+0x000034A0` `float integrationSmallStep` (read, DERIVED)
- `this+0x000034A4` `float integrationLargeStep` (read, DERIVED)
- `this+0x000034A8` `float selectedIntegrationStep` (write, DERIVED)
- `this+0x000034AC` `double frameTime` (write, DERIVED)
- `this+0x000034B0` `float rotationMatrix00` (read, DERIVED)
- `this+0x000034B4` `float rotationMatrix01` (read, DERIVED)
- `this+0x000034B8` `float rotationMatrix02` (read, DERIVED)
- `this+0x000034BC` `float rotationMatrix10` (read, DERIVED)
- `this+0x000034C0` `float rotationMatrix11` (read, DERIVED)
- `this+0x000034C4` `float rotationMatrix12` (read, DERIVED)
- `this+0x000034C8` `float rotationMatrix20` (read, DERIVED)
- `this+0x000034CC` `float rotationMatrix21` (read, DERIVED)
- `this+0x000034D0` `float rotationMatrix22` (read, DERIVED)
- `this+0x000034D4` `float bodyPositionX` (read_write, DERIVED)
- `this+0x000034D8` `float bodyPositionY` (read_write, DERIVED)
- `this+0x000034DC` `float bodyPositionZ` (read_write, DERIVED)
- `this+0x000034E0` `float eulerAngleX` (write, DERIVED)
- `this+0x000034E4` `float eulerAngleYaw` (write, DERIVED)
- `this+0x000034E8` `float eulerAngleZ` (write, DERIVED)
- `this+0x000034EC` `float worldLinImpulseX` (read_write, DERIVED)
- `this+0x000034F0` `float worldLinImpulseY` (read_write, DERIVED)
- `this+0x000034F4` `float worldLinImpulseZ` (read_write, DERIVED)
- `this+0x000034F8` `float accLocalImpulseX` (read_write, DERIVED)
- `this+0x000034FC` `float accLocalImpulseY` (read_write, DERIVED)
- `this+0x00003500` `float accLocalImpulseZ` (read_write, DERIVED)
- `this+0x00003504` `float angImpulseX` (read_write, DERIVED)
- `this+0x00003508` `float angImpulseY` (read_write, DERIVED)
- `this+0x0000350C` `float angImpulseZ` (read_write, DERIVED)
- `this+0x00003518` `float frameFactor` (read, DERIVED)
- `this+0x00003528` `float angScaleX` (read, DERIVED)
- `this+0x0000352C` `float angScaleY` (read, DERIVED)
- `this+0x00003530` `float angScaleZ` (read, DERIVED)
- `this+0x0000354C` `float springAccumulatorFR` (write, DERIVED)
- `this+0x00003550` `float springAccumulatorFL` (write, DERIVED)
- `this+0x00003554` `float springAccumulatorRR` (write, DERIVED)
- `this+0x00003558` `float springAccumulatorRL` (write, DERIVED)
- `this+0x0000355C` `float damperAccumulator0` (write, DERIVED)
- `this+0x00003560` `float damperAccumulator1` (write, DERIVED)
- `this+0x00003594` `float[62*4] cornerPositions` (read, DERIVED)
- `this+0x000035E4` `float suspRateType2Base` (read, DERIVED)
- `this+0x000035E8` `float suspRateType2` (read_write, DERIVED)
- `this+0x000035EC` `float suspRateType2Inv` (write, DERIVED)
- `this+0x000035F0` `float[62*4] wheelStepSlots` (write, DERIVED)
- `this+0x00003610` `float cornerThresholdSq` (read, DERIVED)
- `this+0x00003668` `WheelContactEntry[4] wheelContactArray` (read, DERIVED)
- `this+0x000036E0` `float suspRateType2Copy` (read_write, DERIVED)
- `this+0x000036E4` `float suspRateType2CopyInv` (write, DERIVED)
- `this+0x000037D4` `float suspRateType0Base` (read, DERIVED)
- `this+0x000037D8` `float suspRateType0` (write, DERIVED)
- `this+0x000037DC` `float suspRateType0Inv` (write, DERIVED)
- `this+0x000038D0` `float suspRateType0Copy` (write, DERIVED)
- `this+0x000038D4` `float suspRateType0CopyInv` (write, DERIVED)
- `this+0x00003988` `float dampingRateFactor` (read, DERIVED)
- `this+0x000039B4` `int32_t suspensionTypeSelector` (read, DERIVED)
- `this+0x000039B8` `float warningThresholdLo` (read, DERIVED)
- `this+0x000039C4` `float warningThresholdHi` (read, DERIVED)
- `this+0x000039C8` `float dampingRateValue` (read_write, DERIVED)
- `this+0x000039F0` `int32_t dampingRateIndexRequested` (read, DERIVED)
- `this+0x000039F4` `int32_t dampingRateIndexCached` (read_write, DERIVED)
- `this+0x00003A04` `float brakeCoolingThreshold` (read, DERIVED)
- `this+0x00003A58` `float velocityDeltaX` (read, DERIVED)
- `this+0x00003A5C` `float velocityDeltaY` (read, DERIVED)
- `this+0x00003A60` `float velocityDeltaZ` (read, DERIVED)
- `this+0x00003ABC` `float[13] contactDataArray` (read, DERIVED)
- `this+0x00003AC0` `float contactDataArray2` (read, DERIVED)
- `this+0x00003B60` `float predictedBodyPosX` (read, DERIVED)
- `this+0x00003B64` `float predictedBodyPosY` (read, DERIVED)
- `this+0x00003B68` `float predictedBodyPosZ` (read, DERIVED)
- `this+0x00003B6C` `float minContactDistance` (read, DERIVED)
- `this+0x00003FF4` `float recoveryAccumulator` (read_write, DERIVED)
- `this+0x00004008` `float storedPosX` (read, DERIVED)
- `this+0x0000400C` `float storedPosY` (read, DERIVED)
- `this+0x00004010` `float storedPosZ` (read, DERIVED)

### WheelAngularVelocityState

Per-frame float state vector integrated by WheelAngularVelocityIntegrator (rotation accumulation, sign-aware convergence of the velocity state toward a bounded target, clamp-threshold dispatch).

Methods: `0x004E43D0`

- `this+0x00000010` `float rotationAccumulator` (read_write, DERIVED)
- `this+0x00000024` `float integratedValue` (read_write, DERIVED)
- `this+0x00000030` `float velocityState` (read_write, DERIVED)
- `this+0x00000034` `float rotationBias` (read, DERIVED)
- `this+0x00000054` `float targetBase` (read, DERIVED)
- `this+0x00000058` `float targetBound` (read, DERIVED)
- `this+0x00000060` `float baseRotation` (read, DERIVED)
- `this+0x0000006C` `float gain` (read, DERIVED)
- `this+0x00000070` `float convergenceFactor` (read_write, DERIVED)

### SpatialGridFloatState

Small float state object whose scalar field is updated conditionally only after a spatial-grid validation of its position vector.

Methods: `0x005000E0`

- `this+0x00000008` `float positionX` (read, DERIVED)
- `this+0x0000000C` `float scalarField` (read_write, DERIVED)
- `this+0x00000010` `float positionZ` (read, DERIVED)

### CollisionContactState

Collision feature pair state used to classify contact: low bits of the state word encode 1=potential, 2=separated, 4=contact; bit 0x10 selects the plane-based classification path.

Methods: `0x0054D7A0`

- `this+0x00000014` `int32_t contactStateWord` (read_write, DERIVED)
- `this+0x00000018` `float planeThreshold` (read, DERIVED)
- `this+0x000000F4` `float innerRadius` (read, DERIVED)
- `this+0x000000F8` `float outerRadius` (read, DERIVED)
- `this+0x000000FC` `int32_t planeCount` (read, DERIVED)

### Matrix4x4Transform

4x4 row-major float matrix (element stride 4) initialized to a diagonal form by TransformInit and composed from scale/rotation/origin/translation by Matrix4x4TransformationConstructor.

Methods: `0x0050D47D`, `0x0052401F`

- `this+0x00000000` `float m00` (write, DERIVED)
- `this+0x00000004` `float m01` (write, DERIVED)
- `this+0x00000008` `float m02` (write, DERIVED)
- `this+0x0000000C` `float m03` (write, DERIVED)
- `this+0x00000010` `float m10` (write, DERIVED)
- `this+0x00000014` `float m11` (write, DERIVED)
- `this+0x00000018` `float m12` (write, DERIVED)
- `this+0x0000001C` `float m13` (write, DERIVED)
- `this+0x00000020` `float m20` (write, DERIVED)
- `this+0x00000024` `float m21` (write, DERIVED)
- `this+0x00000028` `float m22` (write, DERIVED)
- `this+0x0000002C` `float m23` (write, DERIVED)
- `this+0x00000030` `float m30` (read_write, DERIVED)
- `this+0x00000034` `float m31` (write, DERIVED)
- `this+0x00000038` `float m32` (read_write, DERIVED)
- `this+0x0000003C` `float m33` (write, DERIVED)

### EngineSoundWaveTableState

Engine-sound synthesis table state: quality selector, mode words, quantization shift, per-entry pointer array and mono ramp table that EngineSoundWaveTableGenerator fills with normalized PCM samples.

Methods: `0x00513482`

- `this+0x00000060` `int32_t modeWord` (read, DERIVED)
- `this+0x00000061` `uint8_t modeBits` (read, DERIVED)
- `this+0x00000116` `uint8_t channelModeBits` (read, DERIVED)
- `this+0x00000117` `uint8_t qualitySelector` (read, DERIVED)
- `this+0x0000012C` `int32_t quantizationShift` (write, DERIVED)
- `this+0x00000130` `float enableFlag` (read, DERIVED)
- `this+0x00000138` `uint8_t* monoTablePtr` (write, DERIVED)
- `this+0x00000144` `int16_t** tableArrayPtr` (write, DERIVED)
- `this+0x00000150` `uint8_t amplitudeCh0` (read, DERIVED)
- `this+0x00000151` `uint8_t amplitudeCh1` (read, DERIVED)
- `this+0x00000152` `uint8_t amplitudeCh2` (read, DERIVED)
- `this+0x00000153` `uint8_t amplitudeMean` (read, DERIVED)

### WheelContactEntry

Per-wheel contact entry in the wheel-contact array (stride 248 bytes / 62 dwords); its surface-struct pointer selects the surface type for force aggregation.

Methods: 

- `*(this+0x3668)+0x00000054` `void* surfaceStructPtr` (read, DERIVED)

### WheelContactSurface

Contact surface-struct reachable at wheel entry +0x54; holds the force (0x30) and contact (0x34) surface-type identifiers used to deduplicate and select wheels for aggregation.

Methods: 

- `*(*(this+0x3668)+0x54)+0x00000030` `int32_t forceSurfaceId` (read, DERIVED)
- `*(*(this+0x3668)+0x54)+0x00000034` `int32_t contactSurfaceId` (read, DERIVED)

### VehiclePostProcessInput

Control/input object referenced through the postProcessInput pointer at vehicle this+0x0; holds the base-object field read for the mode-2 pointer chain and the control-mode flag (bit 8) gating yaw recovery.

Methods: 

- `obj+0x00004894` `int32_t baseObjectField` (read, DERIVED)
- `obj+0x000048BC` `int32_t controlModeFlag` (read, DERIVED)

## Compatibility contracts

- **PhysicsProcessingModeDispatch** — this+0x32BC selects vehicle physics processing: 0 runs full initialization (PitStateUpdateMachine, VehiclePhysicsIntegrationStep, VehicleSetupInitialization), 1 runs sub-step integration (PitStateUpdateMachine, PhysicsIntegrationStateMachine), 2 stores the input time at this+0x34AC and loads team colors; any other value is a no-op.
- **AngularVelocityClampDispatch** — When |this+0x24| exceeds the 50.265484 threshold (dbl_59ED28 / flt_5AD180), the accumulated value is passed to InterruptDispatch and written back to this+0x24.
- **IntegrationSubstepSelection** — The integration sub-step size is selected by comparing wheel-speed squared (this+0x3508) with the threshold this+0x349C: small step this+0x34A0, or large step this+0x34A4 with an incremented count; the selected step is written to 4 wheel slots at this+0x35F0 (62-DWORD stride).
- **ContactStateEncoding** — Contact state is encoded in the low bits of the state word at this+0x14: 1 potential contact, 2 separated, 4 contact. Bit 0x10 selects the plane-based classification path; otherwise an inner/outer radius test (this+0xF4/this+0xF8) decides.
- **WheelContactSurfaceContract** — Wheel contact entries at this+0x3668 (stride 248 bytes / 62 dwords) expose a surface-struct pointer at entry +0x54; the surface struct holds a force id at +0x30 and a contact id at +0x34. Aggregation helpers (0x004F0F40, 0x004F1120) select wheels whose surface id matches the requested surface type, weighted by grip/speed, and store results via PerIndexStructFieldSetter (indices 2 and 1).
- **TimeDeltaDampingContract** — Each frame the accumulated time delta is clamped (AccumulatorClamp) and then scaled by the global physics damping source dbl_7C7428 unless the gate at this+0x32BC is set; the same global is used as the physics object for integration and angular-impulse accumulation.

## Unresolved

- All 18 packet functions have UNKNOWN owners; no class boundary in this proposal is proven. VehiclePhysicsState is DERIVED from shared-field usage, and the five smaller classes (WheelAngularVelocityState, SpatialGridFloatState, CollisionContactState, EngineSoundWaveTableState, WheelContactEntry/WheelContactSurface/VehiclePostProcessInput) are GUESS groupings on equal base 'this' offsets that the packet itself cannot prove are the same objects.
- this+0x32BC is overloaded across the packet's own functions: physics mode (0x004E4930), contact-processing mode (0x004EBC60), grip-factor gate (0x004F0F40), rigid-body status (0x004F12E0), yaw-rotation counter gate (0x004F1C40) and damping gate (0x004ED220). The packet gives no evidence that these are the same semantic field.
- this+0x34B8 is read as a rotation-matrix element in 0x004EBC60 and as a yaw forward-axis component in 0x004F1C40, while existing analysis labels it elapsedTime [CONFIRMED]; the conflict is not resolvable from this packet.
- this+0x3508 is read as wheel speed in 0x004E4E60 and as an angular-impulse accumulator component in 0x004EBC60; the interpretation depends on the vehicle-struct layout, which the packet does not pin.
- WheelAngularVelocityIntegrator's wheel attribution and owner object type are DERIVED from the caller sub_4E5AE0's vehicle context, not independently confirmed; the physical meaning of this+0x30, this+0x54/0x58 and the 50.265484 threshold is undetermined.
- The FieldReadDelegate tail in 0x004E9600 is not in the packet callee list; its identity and purpose are unresolved.
- sub_4F1FE0's role beyond receiving the elapsed time is unverified; the constants folded into 0x004F1C40's comparisons (0.70710677, 5.0, 3.0) cannot be attributed to individual globals from the raw source.
- In 0x005000E0, v9 is read before any visible assignment (likely a SpatialGridQuery output or compiler-eliminated callee result), and locals v5..v8 are initialized but never consumed.
- The per-shift phase-step lookup dword_5D799C referenced by 0x00513482 is absent from the packet globals; sub_5881F0's role is not grounded.
- The 4x4 matrix objects (a1) for 0x0050D47D and 0x0052401F have no callers recorded in the packet, so whether a2/a3/a4 are scale, translation or another diagonal interpretation is unknown.
- The wheel-contact array layout (stride 62 dwords), the corner contact layout (stride 296, active byte at +64), and sub_4EA930's exact transform are reached only through relative-offset arithmetic and are DERIVED, not confirmed.
- Seven read-only globals flagged by packet facts in each of 0x004F0F40, 0x004F1120, 0x004F12E0 and 0x004F1C40 appear nowhere in the raw decompiled source and are recorded in unresolved_evidence_refs rather than asserted as physics constants.
- The contact response units, the 0.025 prediction scale (flt_59E87C) binding, and the NetworkPacketDataWriter 13-element wire layout are outside this packet's evidence.
- Globals flagged not-in-raw for the aggregation/sound/recovery helpers (0x0059E478, 0x0059E600, 0x0059E7EC, 0x0059E800, 0x0059E824, 0x0059E84C, 0x0059E86C, 0x0059E8A0, 0x0059E8CC, 0x0059E9E4, 0x0059EC20, 0x005AC988, 0x005AD1C4, 0x005AD230, 0x005AD234, 0x005AD238) are listed in unresolved_evidence_refs.
- The 'wheel/physics' prose labels (spring/damper accumulators, combined rate/inverse pairs, elapsedTime, timer/HUD element semantics) are inherited from the packet's existing-analysis layer and are DERIVED; they are not independently confirmed by raw source.
