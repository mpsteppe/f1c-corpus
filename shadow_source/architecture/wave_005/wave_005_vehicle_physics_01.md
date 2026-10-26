# VehiclePhysics

Scope: `vehicle_physics`  
Trust: `DERIVED`

The packet groups 19 functions around the vehicle physics frame path. A central per-wheel/suspension object (VehicleWheelPhysics) owns the tire/ground contact and friction solver, wheel-force aggregation, collision energy, damping and spring/damper force splits, suspension-to-rigid-body data copy, wheel-state history advance, and state resets. A smaller physics-state object (VehiclePhysicsState) owns mode-dispatched physics vector conversion and camera/UI telemetry reads. Camera transform, sound/transform sub-object allocation, vehicle-subsystem cleanup, global physics-state reset, and race-time formatting are peripheral but evidence-linked. Almost all owners are UNKNOWN in the packet; classes are DERIVED/GUESS groupings based on shared field offsets and shared callees, not on any struct definition.

## Function roles

- `0x0040AA20` **TransformSoundObjectOwner** — Lazily allocates and initializes up to five 3D sound/transform sub-objects (four 200-byte blocks into this+0x10..0x1C and one 204-byte refcounted block into this+0x20), writing the 360.0f dword triple into this+0xA8/0xAC/0xB0; invoked during object setup by 0x0040C140.
- `0x0040B710` **CameraTransformState** — Selects the current camera entry (stride 208, base this+0x0C, index this+0x14) and, when the enable flag this+0x04 is set, computes the camera transform: transforms a point, loads the player velocity from dword_7C54E0, dispatches the entry vtable method at +24, reads the entry position/orientation, converts angle fields to radians and applies the camera rotation, then returns a float from entry +72.
- `0x0040EF70` **VehiclePhysicsState** — Converts a 13-float physics state vector a2 into owner and sub-object state: dispatches on mode this+0x1C, writes offset-scaled position into the sub-object at this+0x20, copies position into this+0x0C/0x10/0x14, forwards position and velocity groups to sub_54B4D0, F_3x3RotationTensorMatrixTransform and Copy6DwordsToStructCall, and returns the result of sub_40F0D0.
- `0x0040F550` **VehiclePhysicsState** — Mode-dispatched frame update on the selector this+0x1C: for modes 0-5 integrates physics state into the position fields this+0x0C and sets the activity flag byte this+0x0A; for mode 6 copies the 3-dword position triplet from sub-object offset 0x34D4 into this+0x0C/0x10/0x14; any other mode returns immediately. Invoked by ParticleEffectUpdateDispatch (0x004EB430).
- `0x00424010` **VehicleObject** — Vehicle-subsystem cleanup: when the resource pointer at this+0x44A8 is non-null, frees it through the free wrapper; then runs the empty stub unconditionally and returns the computation performed on the sub-structure at this+0x0C.
- `0x0042BDD0` **VehicleTimingFormatter** — Formats a vehicle timing line into a caller-supplied buffer: in a race session (dword_7C56A4 == 7) emits the finished race time, the gap to the leader (+m:ss.fff or +N laps), or a placeholder; outside a race emits the raw session time or '--:--.---'; a status field decides whether a retirement/out label is written (return 3) or not (return 0).
- `0x00430600` **VehicleWheelPhysics** — Aggregates six per-wheel force outputs: evaluates six index/multiplier/base parameter triples from the owning physics object, feeds them into polynomial, tire-force, quadratic and linear force models, and sums the model outputs into the lateral component *a3 and the longitudinal component *a4.
- `0x00431390` **VehiclePhysicsState** — Unconditional physics-state initializer: clears the change-flag byte this+0x19A4, sets the activation-flag byte this+0x00, writes a float into the indexed state slot at 4*a2+7336, then triggers pressure/force-field remapping via sub_4313C0.
- `0x00431A70` **VehicleWheelPhysics** — Writes a float into a per-wheel physics grid: computes the float-grid index as a3 + 3*(a2+617), stores parameter a4 there, sets the occupancy flag byte at this + a2 + 7400, and returns the index.
- `0x00431C00` **GlobalPhysicsState** — Resets the global physics-state block at dword_7C73E8: sets three sentinel dwords (0x7C73EC/0x7C73F4/0x7C73FC) to -1, zeroes the remaining eleven dwords, tears down the block via the linked-list cleanup, and returns its result.
- `0x004363F0` **CollisionContactRecord** — Copies a collision-result record from a source buffer into the destination owned by this: copies a one-byte type marker, swaps the two six-dword payload halves (source 28-48 into dest slots 1-6, source 4-24 into slots 7-12), copies two trailing dwords into slots 17-18 and zeroes slots 19-24; the bulk copy is skipped when the type marker is zero.
- `0x00436870` **VehicleWheelPhysics** — Per-frame tire/ground contact and friction solver: generates 3 (or 5) candidate contact patches from suspension geometry, queries the spatial grid for terrain height, derives the contact plane, computes penetration depth, selects the nearest stored contact, and applies friction/normal impulses with torque to the rigid body. Called by 0x004423B0.
- `0x004389B0` **VehicleWheelPhysics** — Copies suspension geometry data (Euler-derived rotation matrix and inertia tensor) into one or two physics engine body structs (this+0x15C and optionally this+0x160), with an active path and an inactive reference-copy path; on the vehicle physics frame path.
- `0x004390A0` **VehicleWheelPhysics** — Accumulates collision energy over a four-element damage-parameter array and evaluates six force/torque models fed by polynomial curve inputs, returning the sum of the six single-float outputs as a double. Called by VehiclePhysicsInitializer (0x00439210).
- `0x0043E360` **VehicleWheelPhysics** — Resets suspension and wheel physics state: zeroes a variable-length list of 24-byte blocks off this+0x15B0 (count this+0x15AC), zeroes four per-wheel suspension block pairs starting at this+0x348, and zeroes two 12-dword ranges this+0xEC..0x118 and this+0x1F04..0x1F30.
- `0x0043EAE0` **VehicleWheelPhysics** — Accumulates scaled input a2 into two damping accumulators (this+0x17D8 at rate 0.23, this+0x17F0 at rate 0.18), clamps each against its reference base (this+0x1C40, this+0x1C48) and base-plus-offset upper bound, then evaluates quadratic force/torque via sub_43BB80. Per-frame damping integration.
- `0x0043EBD0` **VehicleWheelPhysics** — Force-split dispatch: scales an incoming force a2 by 0.25 into SuspensionDamperForceAccumulation and by 0.75 into ClampedSpringIntegrator, distributing a single input between the damper and spring subsystems. Called by FloatParameterForwarder (0x004ED1C0).
- `0x0043EC50` **VehicleWheelPhysics** — Frame-path damping split: integrates the vehicle physics accumulator with a quarter of the incoming time step, then clamps the accumulator with the remaining three quarters of the step. Structural twin of PhysicsForceScaleDispatch per packet prelabel.
- `0x004414D0` **VehicleWheelPhysics** — Advances wheel-state history (copies history headers forward and rotates per-wheel slots), copies per-wheel delta buffers from previous into current state, then dispatches the suspension wheel dynamics solver, two batch iterators, a per-body update pass, and the physics sub-object free routine. Invoked by VehiclePhysicsIntegrationStep (0x00441650).

## Proposed classes

### TransformSoundObjectOwner

Owns up to five lazily allocated 3D sound/transform sub-objects and an angle-default triple; the allocator initializes the sub-objects and a refcounted payload during object setup.

Methods: `0x0040AA20`

- `this+0x00000010` `pointer subObjectSlot0` (write, GUESS)
- `this+0x00000014` `pointer subObjectSlot1` (write, GUESS)
- `this+0x00000018` `pointer subObjectSlot2` (write, GUESS)
- `this+0x0000001C` `pointer subObjectSlot3` (write, GUESS)
- `this+0x00000020` `pointer refcountedSubObject` (write, GUESS)
- `this+0x000000A8` `float angleTripleX` (write, GUESS)
- `this+0x000000AC` `float angleTripleY` (write, GUESS)
- `this+0x000000B0` `float angleTripleZ` (write, GUESS)

### CameraTransformState

Holds the camera enable flag, the stride-208 camera entry array base and current index, and computes the current view transform by dispatching the selected entry's vtable method with the transformed point, transform data, and the local player velocity.

Methods: `0x0040B710`

- `this+0x00000004` `bool enableFlag` (read, GUESS)
- `this+0x0000000C` `pointer cameraEntryArrayBase` (read, GUESS)
- `this+0x00000014` `int cameraEntryIndex` (read, GUESS)

### VehiclePhysicsState

Physics state object whose mode selector drives position and sub-object sync: converts 13-float physics state vectors into position fields and a child state object, integrates state into the position fields on the frame path, and re-initializes indexed state slots.

Methods: `0x0040EF70`, `0x0040F550`, `0x00431390`

- `this+0x00000000` `bool activationFlag` (write, GUESS)
- `this+0x0000000A` `bool activityFlag` (write, GUESS)
- `this+0x0000000C` `float positionX` (write, GUESS)
- `this+0x00000010` `float positionY` (write, GUESS)
- `this+0x00000014` `float positionZ` (write, GUESS)
- `this+0x0000001C` `int modeSelector` (read, GUESS)
- `this+0x00000020` `pointer subObjectPointer` (read, GUESS)
- `this+0x000019A4` `bool changeFlag` (write, GUESS)
- `*(this+0x20)+0x0000001C` `dword subObjectParamBlockDword` (write, GUESS)
- `*(this+0x20)+0x000034D4` `float telemetryPositionX` (read, GUESS)
- `*(this+0x20)+0x000034D8` `float telemetryPositionY` (read, GUESS)
- `*(this+0x20)+0x000034DC` `float telemetryPositionZ` (read, GUESS)

### VehicleWheelPhysics

Per-frame suspension and wheel physics object: tire/ground contact and friction solving against a rigid body, per-wheel force aggregation and collision energy, damping accumulator integration and force splits, suspension geometry transfer into physics body structs, wheel-state history advance, and suspension/wheel state resets.

Methods: `0x00430600`, `0x00431A70`, `0x00436870`, `0x004389B0`, `0x004390A0`, `0x0043E360`, `0x0043EAE0`, `0x0043EBD0`, `0x0043EC50`, `0x004414D0`

- `this+0x000000BC` `float frictionCouplingTerm` (read, GUESS)
- `this+0x000000E4` `float slipImpulseX` (read_write, GUESS)
- `this+0x000000EC` `float slipImpulseY` (read_write, GUESS)
- `this+0x000000F0` `dword suspensionStateRange0` (write, GUESS)
- `this+0x000000F4` `float slipImpulseZ` (read_write, GUESS)
- `this+0x000000F8` `dword suspensionStateRange1` (write, GUESS)
- `this+0x000000FC` `dword contactTimestamp` (read_write, GUESS)
- `this+0x00000100` `dword contactSentinel` (read_write, GUESS)
- `this+0x00000104` `dword suspensionStateRange2` (write, GUESS)
- `this+0x00000108` `dword suspensionStateRange3` (write, GUESS)
- `this+0x0000010C` `dword suspensionStateRange4` (write, GUESS)
- `this+0x00000110` `dword suspensionStateRange5` (write, GUESS)
- `this+0x00000114` `dword suspensionStateRange6` (write, GUESS)
- `this+0x00000118` `dword suspensionStateRange7` (write, GUESS)
- `this+0x00000124` `float frictionConeThresholdLow` (read, GUESS)
- `this+0x0000012C` `float frictionConeThresholdHigh` (read, GUESS)
- `this+0x00000134` `double tangentialMagnitudeLo` (read_write, GUESS)
- `this+0x00000138` `double tangentialMagnitudeHi` (read_write, GUESS)
- `this+0x0000013C` `double longitudinalForceLo` (read_write, GUESS)
- `this+0x00000140` `double longitudinalForceHi` (read_write, GUESS)
- `this+0x00000144` `float tractionCoefficient` (read_write, GUESS)
- `this+0x00000148` `float tractionClampOne` (write, GUESS)
- `this+0x0000014C` `float tractionSqrtLo` (write, GUESS)
- `this+0x00000150` `float tractionSqrtHi` (write, GUESS)
- `this+0x00000154` `double finalTangentialImpulseLo` (write, GUESS)
- `this+0x00000158` `double finalTangentialImpulseHi` (write, GUESS)
- `this+0x0000015C` `pointer physicsBodyA` (read, GUESS)
- `this+0x00000160` `pointer physicsBodyB` (read, GUESS)
- `this+0x000001C4` `bool contactActiveFlag` (read, GUESS)
- `this+0x000001C5` `bool secondaryFlag` (read, GUESS)
- `this+0x0000020C` `float contactOffset1` (read, GUESS)
- `this+0x00000214` `float contactOffset2` (read, GUESS)
- `this+0x0000021C` `float contactOffset3` (read, GUESS)
- `this+0x00000224` `float contactOffset4` (read, GUESS)
- `this+0x00000228` `float contactOffset5` (read, GUESS)
- `this+0x0000022C` `float velocityContactTerm1` (read, GUESS)
- `this+0x00000234` `float velocityContactTerm2` (read, GUESS)
- `this+0x0000023C` `float cubicForceCoeff0` (read, GUESS)
- `this+0x00000244` `float cubicForceCoeff1` (read, GUESS)
- `this+0x0000024C` `float cubicForceCoeff2` (read, GUESS)
- `this+0x00000254` `float cubicForceCoeff3` (read, GUESS)
- `this+0x0000025C` `float cubicForceCap` (read, GUESS)
- `this+0x00000264` `pointer selectedContactRecord` (read_write, GUESS)
- `this+0x00000268` `float longitudinalBaseZero` (write, GUESS)
- `this+0x0000026C` `float longitudinalBaseOne` (write, GUESS)
- `this+0x00000270` `float frictionTerm0` (read, GUESS)
- `this+0x00000278` `float frictionTerm1` (read, GUESS)
- `this+0x00000280` `float frictionTerm2` (read, GUESS)
- `this+0x00000288` `float frictionTerm3` (read, GUESS)
- `this+0x00000290` `float frictionTerm4` (read, GUESS)
- `this+0x00000298` `float longitudinalCurve0` (read, GUESS)
- `this+0x000002A0` `float longitudinalCurve1` (read, GUESS)
- `this+0x000002A8` `float longitudinalCurve2` (read, GUESS)
- `this+0x000002B0` `float longitudinalCurve3` (read, GUESS)
- `this+0x000002B8` `float lateralCurve0` (read, GUESS)
- `this+0x000002C0` `float lateralCurve1` (read, GUESS)
- `this+0x000002C8` `float lateralCurve2` (read, GUESS)
- `this+0x000002D0` `float lateralCurve3` (read, GUESS)
- `this+0x000002E4` `float tractionPeakLimit` (read, GUESS)
- `this+0x000002EC` `float steeringCurve0` (read, GUESS)
- `this+0x000002F4` `float steeringCurve1` (read, GUESS)
- `this+0x000002FC` `float steeringCurve2` (read, GUESS)
- `this+0x00000304` `float steeringCurve3` (read, GUESS)
- `this+0x0000030C` `float steeringCurve4` (read, GUESS)
- `this+0x00000314` `float slipAngle` (read_write, GUESS)
- `this+0x0000031C` `double normalForceImpulseLo` (read_write, GUESS)
- `this+0x00000320` `double normalForceImpulseHi` (read_write, GUESS)
- `this+0x00000324` `double penetrationDepthLo` (read_write, GUESS)
- `this+0x00000328` `double penetrationDepthHi` (read_write, GUESS)
- `this+0x0000032C` `pointer contactSpatialReference` (read, GUESS)
- `this+0x00000340` `dword wheelHistory0A` (read_write, GUESS)
- `this+0x00000344` `dword wheelHistory0B` (read_write, GUESS)
- `this+0x00000348` `dword wheelHistory1A` (read_write, GUESS)
- `this+0x0000034C` `dword wheelHistory1B` (read_write, GUESS)
- `this+0x00000350` `dword wheelHistory2A` (read_write, GUESS)
- `this+0x00000354` `dword wheelHistory2B` (read_write, GUESS)
- `this+0x0000039C` `float terrainCoefficient` (read, GUESS)
- `this+0x00000DF0` `double forceTripleA_base` (read, GUESS)
- `this+0x00000DF8` `double forceTripleA_multiplier` (read, GUESS)
- `this+0x00000E04` `int forceTripleA_index` (read, GUESS)
- `this+0x00000E30` `double forceTripleB_base` (read, GUESS)
- `this+0x00000E38` `double forceTripleB_multiplier` (read, GUESS)
- `this+0x00000E44` `int forceTripleB_index` (read, GUESS)
- `this+0x00001270` `double forceTripleC_base` (read, GUESS)
- `this+0x00001278` `double forceTripleC_multiplier` (read, GUESS)
- `this+0x00001284` `int forceTripleC_index` (read, GUESS)
- `this+0x000012B0` `double forceTripleD_base` (read, GUESS)
- `this+0x000012B8` `double forceTripleD_multiplier` (read, GUESS)
- `this+0x000012C4` `int forceTripleD_index` (read, GUESS)
- `this+0x000012F0` `double forceTripleE_base` (read, GUESS)
- `this+0x000012F8` `double forceTripleE_multiplier` (read, GUESS)
- `this+0x00001304` `int forceTripleE_index` (read, GUESS)
- `this+0x00001330` `double forceTripleF_base` (read, GUESS)
- `this+0x00001338` `double forceTripleF_multiplier` (read, GUESS)
- `this+0x00001344` `int forceTripleF_index` (read, GUESS)
- `this+0x000015AC` `int wheelStateCount` (read, GUESS)
- `this+0x000015B0` `pointer previousStateBuffer` (read, GUESS)
- `this+0x0000162C` `pointer currentStateBuffer` (read, GUESS)
- `this+0x000017D8` `float dampingAccumulator1` (read_write, GUESS)
- `this+0x000017F0` `float dampingAccumulator2` (read_write, GUESS)
- `this+0x00001C38` `float dampingSelector` (read, GUESS)
- `this+0x00001C40` `float dampingClampBase1` (read, GUESS)
- `this+0x00001C48` `float dampingClampBase2` (read, GUESS)
- `this+0x00001C5C` `dword historyHeaderA_prev0` (read_write, GUESS)
- `this+0x00001C60` `dword historyHeaderA_prev1` (read_write, GUESS)
- `this+0x00001C64` `dword historyHeaderA_curr0` (write, GUESS)
- `this+0x00001C68` `dword historyHeaderA_curr1` (write, GUESS)
- `this+0x00001E38` `dword historyHeaderB_prev0` (read_write, GUESS)
- `this+0x00001E3C` `dword historyHeaderB_prev1` (read_write, GUESS)
- `this+0x00001E40` `dword historyHeaderB_curr0` (write, GUESS)
- `this+0x00001E44` `dword historyHeaderB_curr1` (write, GUESS)
- `this+0x00001F04` `dword secondaryState0` (write, GUESS)
- `this+0x00001F08` `dword secondaryState1` (write, GUESS)
- `this+0x00001F0C` `dword secondaryState2` (write, GUESS)
- `this+0x00001F10` `dword secondaryState3` (write, GUESS)
- `this+0x00001F14` `dword secondaryState4` (write, GUESS)
- `this+0x00001F18` `dword secondaryState5` (write, GUESS)
- `this+0x00001F1C` `dword secondaryState6` (write, GUESS)
- `this+0x00001F20` `dword secondaryState7` (write, GUESS)
- `this+0x00001F24` `dword secondaryState8` (write, GUESS)
- `this+0x00001F28` `dword secondaryState9` (write, GUESS)
- `this+0x00001F2C` `dword secondaryState10` (write, GUESS)
- `this+0x00001F30` `dword secondaryState11` (write, GUESS)
- `*(this+0x15C)+0x00000004` `float bodyPositionX` (read, GUESS)
- `*(this+0x15C)+0x0000000C` `float bodyPositionY` (read, GUESS)
- `*(this+0x15C)+0x00000014` `float bodyPositionZ` (read, GUESS)
- `*(this+0x15C)+0x0000001C` `float bodyAxisForward0` (read, GUESS)
- `*(this+0x15C)+0x0000002C` `float bodyAxisForward1` (read, GUESS)
- `*(this+0x15C)+0x00000034` `float bodyAxisForward2` (read, GUESS)
- `*(this+0x15C)+0x00000044` `float bodyAxisTangent0` (read, GUESS)
- `*(this+0x15C)+0x0000004C` `float bodyAxisTangent1` (read, GUESS)
- `*(this+0x15C)+0x0000005C` `float bodyAxisTangent2` (read, GUESS)
- `*(this+0x15C)+0x00000064` `float bodyAxisThird0` (read, GUESS)
- `*(this+0x15C)+0x0000006C` `float bodyAxisThird1` (read, GUESS)
- `*(this+0x15C)+0x00000074` `float bodyAxisThird2` (read, GUESS)
- `*(this+0x15C)+0x0000007C` `float inverseInertiaRow0` (read, GUESS)
- `*(this+0x15C)+0x00000084` `float inverseInertiaRow1` (read, GUESS)
- `*(this+0x15C)+0x0000008C` `float inverseInertiaRow2` (read, GUESS)
- `*(this+0x15C)+0x00000134` `float bodyTorqueAccum0` (write, GUESS)
- `*(this+0x15C)+0x0000013C` `float bodyTorqueAccum1` (write, GUESS)
- `*(this+0x15C)+0x00000144` `float bodyTorqueAccum2` (write, GUESS)
- `*(this+0x15C)+0x0000014C` `float bodySlipAngular0` (read, GUESS)
- `*(this+0x15C)+0x00000154` `float bodySlipAngular1` (read, GUESS)
- `*(this+0x15C)+0x0000015C` `float bodySlipAngular2` (read, GUESS)
- `*(this+0x264)+0x00000054` `pointer contactCoefficientsPointer` (read, GUESS)
- `*(*(this+0x264)+0x54)+0x00000008` `float terrainCoeff0` (read, GUESS)
- `*(*(this+0x264)+0x54)+0x0000000C` `float terrainCoeff1` (read, GUESS)
- `*(*(this+0x264)+0x54)+0x00000010` `float terrainCoeff2` (read, GUESS)

### CollisionContactRecord

Destination record for per-frame collision-response results: holds a one-byte type marker, two swapped six-dword payload halves, two trailing dwords, and a zeroed trailing range.

Methods: `0x004363F0`

- `this+0x00000000` `byte typeMarker` (write, GUESS)
- `this+0x00000004` `dword payloadSlot1` (write, GUESS)
- `this+0x00000008` `dword payloadSlot2` (write, GUESS)
- `this+0x0000000C` `dword payloadSlot3` (write, GUESS)
- `this+0x00000010` `dword payloadSlot4` (write, GUESS)
- `this+0x00000014` `dword payloadSlot5` (write, GUESS)
- `this+0x00000018` `dword payloadSlot6` (write, GUESS)
- `this+0x0000001C` `dword payloadSlot7` (write, GUESS)
- `this+0x00000020` `dword payloadSlot8` (write, GUESS)
- `this+0x00000024` `dword payloadSlot9` (write, GUESS)
- `this+0x00000028` `dword payloadSlot10` (write, GUESS)
- `this+0x0000002C` `dword payloadSlot11` (write, GUESS)
- `this+0x00000030` `dword payloadSlot12` (write, GUESS)
- `this+0x00000044` `dword trailingDword1` (write, GUESS)
- `this+0x00000048` `dword trailingDword2` (write, GUESS)
- `this+0x0000004C` `dword zeroedSlot1` (write, GUESS)
- `this+0x00000050` `dword zeroedSlot2` (write, GUESS)
- `this+0x00000054` `dword zeroedSlot3` (write, GUESS)
- `this+0x00000058` `dword zeroedSlot4` (write, GUESS)
- `this+0x0000005C` `dword zeroedSlot5` (write, GUESS)
- `this+0x00000060` `dword zeroedSlot6` (write, GUESS)

### VehicleObject

Vehicle object owning a dynamically allocated subsystem resource pointer and a sub-structure at +0x0C; the cleanup path frees the resource and runs a final sub-structure computation.

Methods: `0x00424010`

- `this+0x0000000C` `pointer substructure` (read, DERIVED)
- `this+0x000044A8` `pointer subsystemResource` (read, DERIVED)

### VehicleTimingFormatter

Formats vehicle race/session timing, gap, lap-difference, and retirement/out labels into caller buffers using the active vehicle pointer array, the session-state global, and the string table.

Methods: `0x0042BDD0`


### GlobalPhysicsState

Global physics-state block anchored at dword_7C73E8; the reset path sets three sentinel dwords to -1, zeroes the remaining block dwords, and tears down the block's linked list.

Methods: `0x00431C00`


## Compatibility contracts

- **VehicleRaceStateLayoutForTimingDisplay** — The race/session formatting path reads per-vehicle fields at fixed offsets from the active vehicle pointers in dword_7C54F0: laps completed at +16444, finished/leader flag at +16480, status at +16484, failure-category id at +16488, session time at +16540, and race time at +16568. It also reads the vehicle count dword_5C329C and the session-state dword_7C56A4 (value 7 selects the race-time formatting path). A replacement must preserve this layout.
- **GlobalPhysicsStateBlockReset** — The global physics-state block at dword_7C73E8 is reset by setting three sentinel dwords (0x7C73EC, 0x7C73F4, 0x7C73FC) to -1, zeroing the remaining eleven dwords of the block, and tearing down the block's linked list. A replacement must keep this block reachable and reset it the same way.
- **CameraTransformPlayerVelocitySource** — Camera transform computation reads the local player vehicle velocity from dword_7C54E0 +88/+92/+96 and transforms a point via F_3DTransformPointByMatrixAndTranslation; the selected camera entry's vtable dispatch at +24 must accept the transformed point, transform data, velocity, and two float parameters.
- **StringTableLabelLookup** — The timing formatter resolves retirement/out labels and lap strings through BinarySearchInStringTable(byte_5EC4C0, label key, byte_5EC4CC) and FailureCategoryNameLookup, and emits all output through StringFormatWithBufferOverflowCheck using formats '%d:%02.2d:%06.3f', '+%d %s', '+%d:%06.3f', '%d:%06.3f' and the placeholder '--:--.---'. A replacement must provide these string-table and formatting services.
- **TireContactSolverStateLocations** — The per-frame tire solver reads the contact flag at this+0x1C4, the first rigid body at this+0x15C, and the selected contact record at this+0x264 (with a coefficient block at record +0x54), and writes the normal-force impulse to this+0x31C, penetration depth to this+0x324, and tangential impulses to this+0x134/0x144/0x154. No-contact is signalled by sentinels 0xFC == -1 and 0x100 == 0xFFEFFFFF. A replacement physics engine must preserve these observable state locations and sentinel semantics.

## Unresolved

- Several functions share the same `this` byte offsets with unrelated meanings across clusters (e.g. this+0x04 as camera enable flag versus collision payload slot; this+0x144 as traction coefficient versus damage-parameter selector; this+0x1C as mode selector versus collision payload slot). Equal offsets on a shared `this` base do not prove a single object; ownership across clusters is not established.
- The sub-object, rigid-body and contact-record layouts (*(this+0x20), *(this+0x15C), *(this+0x264), *(*(this+0x264)+0x54)) are inferred from read patterns only, not from any struct definition.
- The packet summary states 0x0043EC50 is called once per frame by PhysicsTimeStep (0x004ED220), but caller:0x004ED220 is outside the allowed evidence set and could not be cited.
- Many packet-flagged globals are not visible in the raw decompiled bodies and their roles are unconfirmed: flt_59E65C, flt_59E6F8, flt_59E440, dbl_59E430, dbl_59EBA0, flt_59E880, flt_59E890, flt_59E898, flt_59E900, the asc/dbl string-table constants around 0x59E9A4..0x59E9C8, the friction-curve constants 0x59EAF0..0x59EB28, dbl_59EB58, dbl_59EC78 and dword_7C9360.
- The exact pairing of dbl_59EA60 / dbl_59EB50 to the inlined constants 0.25/0.75 (PhysicsForceScaleDispatch, PhysicsDampingScaleApplication) and 0.23/0.18/0.25/0.2 (PhysicsAccumulatorIntegrate) is not established; the raw source shows only the folded literals.
- Camera-entry stride-208 layout (+12..+32 position/orientation, +72 float, vtable dispatch at +24) is DERIVED from the raw source only.
- The status-value semantics (2 = failure category in a race session, 3 = retirement label) in 0x0042BDD0 are inferred from the formatting output only.
- The indirect virtual dispatch through the fifth sound sub-object vtable slot +28 in 0x0040AA20 has no static callee address.
- 0x0040B710 returns an uninitialized value when the enable flag is zero (decompiler artifact).
- The two batch-iterator callees 0x0056ECF0 and 0x0056EE40 have unknown semantics beyond taking the wheel-state region at this+0x15AC.
- The 580-byte, 48-byte and 1124-byte strides in 0x0043E360 and 0x004414D0 are inferred from loop arithmetic; the meaning of the copied 24-byte records is not confirmed.
- The 617 constant and grid dimensions in 0x00431A70, and the relation between the float grid and the byte-flag region at +7400, are unknown.
- The source argument layout in 0x004389B0 (matrix at offset 28, position at offsets 124/132/140) is read but its defining structure is not present in this packet.
- The damage-parameter array stride of 704 bytes and the per-element double coefficients in 0x004390A0 are not present in the packet field set.
- Whether StringCopyWithBufferRealloc mutates byte_5EA438 or the sub-object in 0x0040AA20 is unresolved; the return value is discarded.
- The roles of the collision-result type marker, the destination-only zeroed range, and the swapped payload halves in 0x004363F0 are unexplained.
