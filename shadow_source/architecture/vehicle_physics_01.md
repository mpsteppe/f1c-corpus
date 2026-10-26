# VehiclePhysics

Scope: `vehicle_physics`  
Trust: `DERIVED`

Reconstructed proposal for the vehicle_physics subsystem from ten validated function IR entries: a suspension-strut solver chain (VehicleSuspensionForceCalculation -> SweptSuspensionCollisionDetection -> PhysicsNodePropagationWithDistanceFalloff) owned by a VehiclePhysicsNode class, a per-wheel spring/damper force kernel (WheelSpringDamperForceAndSteering), a tire-model initializer (TireModelFullInitialize, owner VehicleTireModel), a vehicle control/steering layer (VehicleMainPhysicsUpdate, SteeringGeometryUpdate), a physics timestep and wheel-dynamics state (VehiclePhysicsTimeStep, WheelStateReset) and a physics state buffer clearer (PhysicsBufferClear). Class membership, field names and contracts are DERIVED/GUESS proposals; common ownership of the control-state this object is unproven and recorded in unresolved.

## Function roles

- `0x00401340` **VehiclePhysicsNode** — Per-strut suspension contact solver: iterates the suspension strut array (this+0x134, stride 316, count this+0x130), queries the spatial grid for the node/feature contact pair, builds a contact frame, applies gravity compensation, runs ray-sphere intersection tests and writes penetration depth and contact force per strut.
- `0x00401910` **VehiclePhysicsNode** — Swept-strut contact solver: Euler-advances each strut position over the strut array, sweeps the travel axis over a small window calling the suspension and tire force solvers at every sample, and commits the sample position that maximizes contact force.
- `0x00401C90` **VehiclePhysicsNode** — Per-frame force propagation: runs the swept suspension solver then the full-grid suspension solver, propagates tire and grip forces along each strut's linked node chain with distance falloff into strut+136/+140, computes the maximum propagated force at this+0x148, then applies a grip-multiplier pass (sub_4FB260) and a per-strut finalization pass (sub_4FAF60).
- `0x004358F0` **PhysicsStateBuffer** — Clears the 40-dword physics state buffer (dwords 0..38) and, if the pointer at +0x9C is non-null, frees it through FreeWrapper_7bcf and nulls the slot; returns the previous buffer pointer.
- `0x0043C250` **VehicleTireModel** — Full per-wheel tire physics initialization: builds each wheel's compliance matrix and stiffness/damper/thermal state, looks up and applies the tire brand and compound, computes front/rear suspension compliance and attach-point geometry, copies the session setup envelope, allocates and pre-fills the interpolated tire-curve table, seeds wear/thermal session tables, pulls session-state values and finishes by zeroing run state and setting init markers (this+0x30=-2, this+0x34=3).
- `0x00442060` **VehicleControlState** — Per-wheel steering geometry update: scales steering input to radians, adds deterministic trig-table noise, accumulates per-wheel steering angles with clamping, frees the physics sub-object, then transforms the wheel contact geometry through the coordinate frames of the matching contact bodies and sets a secondary-state steering flag on threshold.
- `0x004441F0` **VehicleControlState** — Main per-frame vehicle control tick: snapshots raw controller bytes, maps inputs into steering/throttle/brake commands, runs steering damping, heading-limit clamps, tire-force projection against the track center line, collision/obstacle avoidance, lap/position state transitions, control-mode speed logic, per-wheel torque/brake distribution and final gearbox dispatch.
- `0x004C73F0` **VehiclePhysicsBody** — Per-frame physics timestep: computes frame delta time, decodes the packed input packet via the bitfield/short-vector helper family, transforms state into the vehicle struct, runs per-wheel suspension updates, dispatches mode-specific state machines (mode 2 = full setup copy + subsystem loop; mode 3 = vibration + subsystem loop) and derives braking/audio/bit flags.
- `0x004E3D00` **WheelSpringDamperState** — Per-frame spring/damper force and steering computation for one wheel: builds an orthonormal frame from the suspension axis (near-vertical fast path and 2D fallback), computes contact-frame forces, updates spring stiffness and force magnitude, tracks contact-patch displacement, clamps forces to the friction/grip circle and writes the force components back along the wheel local axes.
- `0x004E4790` **VehiclePhysicsBody** — Per-frame reset of the vehicle wheel-dynamics state: first-frame WheelDynamicsInit guard, frees the heap object at this+0x39A4, zeroes the per-frame physics accumulator block, resets four per-wheel dynamics records (62 dwords each, identity 1.0 entries) and writes the frame sentinel this+0x39F4 = -2.

## Proposed classes

### VehiclePhysicsNode

Owns the vehicle suspension strut array and the per-frame suspension solver chain: per-strut contact solving, swept contact detection, and tire/grip force propagation with distance falloff.

Methods: `0x00401340`, `0x00401910`, `0x00401C90`

- `this+0x00000130` `int strutCount` (read_write, DERIVED)
- `this+0x00000134` `void* (strut array, stride 316 bytes) strutArrayBase` (read, DERIVED)
- `this+0x00000148` `float maximumPropagatedForce` (read_write, DERIVED)

### VehicleTireModel

Tire physics configuration object: per-wheel compliance matrices, tire compound application, suspension compliance and attach-point geometry, session setup envelope, interpolated curve table, and thermal/wear session state.

Methods: `0x0043C250`

- `this+0x00000030` `int initMarkerPrimary` (write, DERIVED)
- `this+0x00000034` `int initMarkerSecondary` (write, DERIVED)
- `this+0x00000070` `byte hudDisableFlag` (write, DERIVED)
- `this+0x00001458` `int tireBrandId` (write, DERIVED)
- `this+0x0000145C` `int tireCompoundId` (write, DERIVED)
- `this+0x00001CFC` `float* curveTableBuffer` (write, DERIVED)
- `this+0x00001D08` `int curveTableEntryCount` (read, DERIVED)
- `this+0x00001DB4` `float wearSeedValue` (read_write, DERIVED)

### VehiclePhysicsBody

Vehicle physics timestep and wheel-dynamics state: decodes the packed input packet, dispatches mode-specific setup/vibration paths, drives the subsystem and vibration state machines, and owns the per-wheel dynamics record array and the per-frame accumulator block.

Methods: `0x004C73F0`, `0x004E4790`

- `this+0x000032BC` `int wheelDynamicsInitFlag` (read, DERIVED)
- `this+0x000032C8` `int vehicleMode` (read, DERIVED)
- `this+0x000035A0` `struct[4] (stride 62 dwords) wheelDynamicsRecords` (read_write, DERIVED)
- `this+0x000039F4` `int frameResetSentinel` (write, DERIVED)
- `this+0x00001040` `float clampedSteering` (write, DERIVED)
- `this+0x00001044` `float steeringFactorScale` (read, DERIVED)
- `this+0x00001054` `void* audioControllerPtr` (read, DERIVED)
- `this+0x000048B4` `int lastSetupTime` (read_write, DERIVED)
- `this+0x000048B8` `int lastFrameTime` (read_write, DERIVED)

### WheelSpringDamperState

Per-wheel spring/damper force computation: builds the suspension frame, computes spring/damper forces from wheel velocity, clamps to the friction/grip circle and writes force components along the wheel local axes.

Methods: `0x004E3D00`

- `this+0x00000038` `float suspensionAxisX` (read, DERIVED)
- `this+0x0000003C` `float suspensionAxisY` (read, DERIVED)
- `this+0x00000040` `float suspensionAxisZ` (read, DERIVED)
- `this+0x00000018` `float wheelVelocityX` (read, DERIVED)
- `this+0x0000001C` `float wheelVelocityY` (read, DERIVED)
- `this+0x00000020` `float wheelVelocityZ` (read, DERIVED)
- `this+0x00000048` `float springStiffness` (write, DERIVED)
- `this+0x0000004C` `float springForceMagnitude` (write, DERIVED)
- `this+0x00000050` `float forceActiveFlag` (write, DERIVED)
- `this+0x000000BC` `float simplifiedRotationFlag` (read, DERIVED)
- `this+0x000000C4` `float contactPosX` (read_write, DERIVED)
- `this+0x000000C8` `float contactPosY` (read_write, DERIVED)
- `this+0x000000D8` `float forceOutX` (write, DERIVED)
- `this+0x000000DC` `float forceOutY` (write, DERIVED)
- `this+0x000000E0` `float forceOutZ` (write, DERIVED)

### VehicleControlState

Vehicle control and steering state: maps raw controller input into steering/throttle/brake commands, applies steering damping and geometry per wheel, runs collision avoidance and lap/position transitions, and distributes torque/brake to the wheels.

Methods: `0x004441F0`, `0x00442060`

- `this+0x00000000` `float steeringOutput` (write, DERIVED)
- `this+0x00000008` `float throttleOutput` (write, DERIVED)
- `this+0x00000010` `float brakeOutput` (write, DERIVED)
- `this+0x00000020` `float offsetOutput` (write, DERIVED)
- `this+0x00000034` `int sessionType` (read, DERIVED)
- `this+0x00000068` `byte throttleInputRaw` (read, DERIVED)
- `this+0x00000070` `byte brakeInputRaw` (read, DERIVED)
- `this+0x000000B4` `void* collisionProbePtr` (read_write, DERIVED)
- `this+0x0000011C` `void* collisionProbeSecondaryPtr` (read, DERIVED)
- `this+0x000015F0` `void* physicsBodyPtr` (read, DERIVED)
- `this+0x00001D30` `int pitLimiterState` (read_write, DERIVED)
- `this+0x00001EF0` `int lapState` (read, DERIVED)
- `this+0x00001554` `float brakeBiasScale` (read, DERIVED)
- `this+0x0000155C` `float torqueScale` (read, DERIVED)
- `this+0x00001564` `float torqueSplit` (read, DERIVED)
- `this+0x000015BC` `int wheelContactCount` (read, DERIVED)
- `this+0x000015C0` `void* wheelContactArray` (read, DERIVED)
- `this+0x00005F68` `dword secondaryStateFlags` (write, DERIVED)

### PhysicsStateBuffer

Small physics state buffer object cleared per-frame; owns a heap buffer pointer at +0x9C that is freed through the free wrapper when present.

Methods: `0x004358F0`

- `this+0x0000009C` `void* heapBufferPtr` (read_write, DERIVED)

## Compatibility contracts

- **SuspensionStrutArrayLayout** — The vehicle physics node exposes a suspension strut array at this+0x134 with stride 316 bytes and element count this+0x130. Per strut the solver writes contact state (penetration depths at +112/+116, gravity-compensated contact force at +120/+124/+128), force propagation results at +136/+140 and a candidate force slot at +144, reads the wheel position at +148/+152/+156 and travel scale at +24, and requires linked-node (+268) and contact-feature (+272) pointers to be non-null for contact processing. VehicleSuspensionForceCalculation / SweptSuspensionCollisionDetection / PhysicsNodePropagationWithDistanceFalloff all share this array and per-strut ABI.
- **PhysicsStateBufferClearContract** — PhysicsBufferClear zeroes dwords 0..38 of the 40-dword buffer on the this object, frees the pointer stored at +0x9C through the free wrapper (0x00587BCF) and nulls it, returning the previous pointer (or 0). Callers are ConstructorStub (004353F0), SuspensionSetupSectionReader (00435410) and WheelDynamicsInit (0043E230), so the buffer is reset during vehicle/tire construction and wheel-dynamics initialization.
- **WheelDynamicsRecordArrayLayout** — The vehicle physics body owns four wheel-dynamics records at this+0x35A0 with stride 62 dwords. VehiclePhysicsTimeStep stores per-wheel force values at this+0x35BC + i*62 dwords (mode 2), while WheelStateReset re-initializes the records each frame, setting identity 1.0 at record-relative indices 22/23/39 and zeroing the leading accumulator entries, and the first-frame guard this+0x32BC drives WheelDynamicsInit(0x007C7428).
- **PackedInputPacketFormat** — Per-frame vehicle input arrives as a packed packet: the region at packet+8 encodes orientation components, a steering bitfield, per-wheel data, a velocity short-vector, floats and subsystem bits decoded by the helper family 0x004B2420..0x004B2AD0. Auxiliary words at packet+52/+56/+59 carry flags: packet+52 bit 0x80 -> byte this+0x1069, packet+56 bits 0x8000000/0x4000000/0x2000000 -> braking byte this+0x105D and effect bytes this+0x1065/0x1067, and packet+59 bit 1 -> byte this+0x4024.
- **VehicleSessionInitMarkers** — TireModelFullInitialize ends a session by setting this+0x30 = -2 and this+0x34 = 3 with this+0x38/+0x3C zeroed. VehicleMainPhysicsUpdate reads this+0x30 for the position-change state machine, and VehiclePhysicsTimeStep branches on the vehicle mode this+0x32C8. A replacement must preserve these sentinel semantics across tire-model init, control-state updates and the physics timestep.

## Unresolved

- Common ownership of the this objects across VehicleControlState members (VehicleMainPhysicsUpdate, SteeringGeometryUpdate) and VehiclePhysicsBody members (VehiclePhysicsTimeStep, WheelStateReset) is NOT proven by the packet; VehicleControlState is a GUESS grouping on overlapping offset ranges (both touch this+0x1F00, steering outputs and contact arrays). VehiclePhysicsBody is stronger (both touch the mode fields this+0x32BC/0x32C8 and the stride-62 wheel-dynamics records at this+0x35A0).
- The suspension strut element layout behind the 316-byte stride (strut-relative +24/+72/+112..+156/+268/+272) is accessed by raw offsets only and is not defined anywhere in the packet; strut-relative offsets are recorded as source:raw prose, not as field evidence refs.
- The read-only .rdata constants 0x0059E420..0x0059EEB8 and 0x005AD148..0x005AD178 are flagged as read by the packet facts but Hex-Rays inlines them into FPU literals, so each global cannot be mapped to a specific inlined value (273.16, 3.14159, 0.825, 0.985, 0.7071, 16000.0, 1050.0 ...) from this packet.
- Globals 0x007CA590, 0x008ACEE0 and 0x008AD254 are flagged as read by the packet facts but have no visible use site in the recovered raw source; producers/consumers unknown.
- Tire-block fields *(*(this+0x1F00)+0x32E0)+0x7C (temperature accumulation) and +0x84 (wear scalar) and gearbox-related fields this+0x5BC, this+0x670, this+0x6D8/+0x6DC/+0x6E0/+0x6E4/+0x6E8/+0x6EC are read per the facts but not visible in the .c (likely consumed inside the Gearbox or inlined wheel/tire helpers).
- WheelSpringDamperForceAndSteering consumes a second parameter a2 (contact-patch frame, 9 floats) whose layout is inferred from usage and not described by the packet; the damper-state combination branch depends on compiler comparison flags (v21|v22) whose source-level condition is not recoverable.
- The purpose of the a2 single-strut selector in VehicleSuspensionForceCalculation and the role of the a3 argument forwarded by PhysicsNodePropagationWithDistanceFalloff to SweptSuspensionCollisionDetection are not documented in the packet.
- The 0x18-byte qmemcpy to this+0xB8, the collision-probe copy to this+0x120, and the per-wheel strided accumulator blocks touched at the end of VehicleMainPhysicsUpdate (two groups of four entries, 1124-byte stride, offsets not enumerated) are not representable from the packet field set.
- The wheel-state copy and aging loops in VehicleMainPhysicsUpdate use 1124-byte strided blocks anchored at this+0x504/0x508/0x514/0x518 and this+0x690; the semantic of each block element is not defined in the packet.
- VehiclePhysicsTimeStep calls ShortComputation_2b00, PropertySetter, BitfieldExtract_2b80 and BitfieldExtractionWithScale, which the packet lists only as named raw-source calls with no addresses.
- The dbl_7C7428 double buffer passed to WheelDynamicsInit and the slot-8 redirect into the global struct at dword_5C7530+64 (session-state lookups, traction-ratio divisor) have contents/layouts outside the packet evidence set.
- The exact identity of the object behind the slip-interpolation reads *(*(this+0xB4)+0x10C) versus *(*(this+0xB4)+0x110) is ambiguous because the two sign branches of the load-normalizing divisor select different chained objects.
- The v77==8 ratio-slot and slot-8 redirect special cases, the wear-mode enum semantics of dword_7CEA5C (0 / 1..3) and the mode-7 session-type case in dword_7C56A4 are DERIVED from the packet and not independently confirmed.
- The globals dbl_59E890, dbl_59ED60..dbl_59ED78 (SteeringGeometryUpdate) are not present in the raw source text; they are likely steering/suspension geometry constants consumed by helper code.
