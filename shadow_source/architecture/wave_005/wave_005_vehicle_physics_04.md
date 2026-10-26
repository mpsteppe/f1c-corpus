# VehiclePhysics

Scope: `vehicle_physics`  
Trust: `DERIVED`

Reconstructs the vehicle-physics/collision layer from 30 validated functions. Twelve unconditional initializers (0x0044E600, 0x0044E6C0, 0x0044E7E0, 0x0044E840, 0x0044E8A0, 0x0044E900, 0x0044E9C0, 0x0044EA20, 0x0044EB40, 0x0044EBA0, 0x0044EC00, 0x0044ECC0) write fixed 24-byte global collision blocks (block tag, four/five zeroed state dwords, terminal threshold 9000/18000/27000); their owners are UNKNOWN and the blocks are kept unmerged because each has a distinct base. One DERIVED class PhysicsTransformComponent (0x00459010 init, 0x00458DF0 velocity/direction update, 0x00459070 suspension wheel-force solver, 0x004584C0 angular response filter) is held together by a same-this call chain (0x00458DF0 calls 0x00459070 and 0x004584C0). A GUESS CollisionContactAccumulator (0x004599C0, 0x00459A40) shares the double displacement/accumulator triple at 0xD8/0xE0/0xE8; a GUESS CollisionImpulseAccumulator (0x0044FEE0) accumulates six double fields at 0x560..0x588. Three small GUESS classes cover 0x0044F7F0 (device-backed response compute), 0x00457A00 (random perturbation, called by CameraShake) and 0x00464A40 (collision sensor init). Two GUESS classes cover the physics-channel max query (0x0045B5C0) and the wheel-audio trigger (0x0049D280). The collision mutex (0x0045BF90), the two collision distance/flag global-pair resets (0x00465FD0, 0x00466030), the vehicle time-gap formatter (0x0046B830), the weighted collision update (0x0047C960) and the grid-cell decoder (0x0049B670) are global-state-only functions kept unowned. Two GUESS interfaces model the device query vtable at +0x14 and the suspension spline evaluator at 0x004582C0. Two GUESS state machines capture the suspension first-call direction selection and the one-shot active-flag reset.

## Function roles

- `0x0044E600` **UnknownObject** — One-time initializer of the second collision-global block (0x007CCA2C): writes block tag 83, zeroes four following state dwords, sets the maximum-distance value 9000 at 0x007CCA40, returns 0. No branches, no calls.
- `0x0044E6C0` **UnknownObject** — Static initializer of the six-dword collision block 0x007CD064..0x007CD078: writes block tag 85, zeroes four state/mapping dwords, stores threshold 27000 at 0x007CD078, returns 0. No static callers.
- `0x0044E7E0` **UnknownObject** — Static initializer of the six-dword collision block 0x007CD080..0x007CD094: writes block tag 88, zeroes four state/render dwords, stores threshold 18000 at 0x007CD094, returns 0. No static callers.
- `0x0044E840` **UnknownObject** — Static initializer of the six-dword collision block 0x007CD01C..0x007CD030: writes block tag 89, zeroes four object-index/data dwords, stores threshold 27000 at 0x007CD030, returns 0. No static callers.
- `0x0044E8A0` **UnknownObject** — Third collision-globals block initializer (0x007CA534..0x007CA548): writes block tag 90, zeroes the five following fields, returns 0. No branches or calls.
- `0x0044E900` **UnknownObject** — Third collision-state block initializer (0x007CA564..0x007CA578): writes block tag 91, zeroes the four following fields, sets 9000 at 0x007CA578, returns 0. No branches or calls.
- `0x0044E9C0` **UnknownObject** — One-time initializer of collision block eleven (0x007CCA54..0x007CCA68): writes block tag 93, zeroes five state fields, stores 27000 at 0x007CCA68, returns 0. No branches or calls.
- `0x0044EA20` **UnknownObject** — Unconditional reset of collision block twelve (0x007CA4B8..0x007CA4CC): writes block tag 94, zeroes the five following bucket/state fields, returns 0. No branches or calls.
- `0x0044EB40` **UnknownObject** — Straight-line initializer of the collision-grid block 0x007CA51C..0x007CA530: sets grid size/tag 97, zeroes five state fields, sets maximum distance 27000 at 0x007CA530, returns 0. No branches or calls; no static callers.
- `0x0044EBA0` **UnknownObject** — One-time initializer of the collision state block 0x007CA420..0x007CA434: writes block tag 98, zeroes five state fields, returns 0. No branches or calls.
- `0x0044EC00` **UnknownObject** — Initializer of the fixed collision-region block 0x007CA3F8..0x007CA40C: writes region tag 99, zeroes four region fields, sets region threshold 9000 at 0x007CA40C, returns 0. No branches or callees.
- `0x0044ECC0` **UnknownObject** — Initializer of the fixed collision-table block 0x007CA458..0x007CA46C: writes table tag 101, zeroes four consecutive table fields, sets table index/threshold 27000 at 0x007CA46C, returns 0. No branches or callees.
- `0x0044F7F0` **CollisionResponseComputer** — Device-backed collision response computation: guards on a device pointer at this+0x80, builds a request block (24, 16, a2, 1), invokes the device vtable method at +0x14 with command id 4, and on success computes range endpoints, inverse-range scaling, an interpolated position and half-span into the a3..a8 outputs. Skips all computation when the device pointer is null or the query fails.
- `0x0044FEE0` **CollisionImpulseAccumulator** — Impulse accumulator: adds the three components of input vector a2 into the double accumulator triple at this+0x560/0x568/0x570 and the three components of input vector a3 into the second triple at this+0x578/0x580/0x588. Unconditional, no branches; returns a3. Invoked by AccumulateAngularImpulse (0x0043E5D0).
- `0x00457A00` **CollisionResponsePerturber** — Collision response with random perturbation: saves/restores a state activation flag via 0x00457B00, reads the position components at this+0x90/0x94/0x98, draws three random values from UtilityFunction_6010 (0x00456010) and reduces each to a +1.0/-1.0 sign via a parity idiom, scales by a2*a3*0.5 clamped at 0.5, perturbs the components, writes back through VectorCopy (0x00456130). Called by CameraShake (0x0040ADB0).
- `0x004584C0` **PhysicsTransformComponent** — Angular collision response filter: compares the wrapped angular difference between source (a2) and target (a3) Euler triples against the scaled threshold this[0xA4] * a5 * total; when the difference is zero or within threshold, copies the source Euler triple unchanged to a4; otherwise converts both to quaternions (0x00567030), slerps by a clamped factor (0x00567580), converts back (0x00567010) and writes a4. Angle wrap/normalize via 0x00455F90 / 0x00455FD0. Called by 0x00458DF0.
- `0x00458DF0` **PhysicsTransformComponent** — Velocity/direction update on a physics transform object: snapshots the previous state triple at this+0x18/0x1C/0x20, clears the one-shot reset flag at this+0xA0, optionally runs the suspension force calculation (0x00459070) when this+0xB0 is non-zero, accumulates the input delta into the position triple at this+0xC/0x10/0x14, optionally writes two scaled force outputs to this+0x38/0x3C when bit 0 of this+0x74 is set (inputs read via 0x00456040), normalizes the direction, computes a yaw from the normalized X/Z (CRT float convert via 0x00588570), applies the angular collision-response filter (0x004584C0) when this+0xA4 is positive, and copies the triple back via VectorCopy (0x00456130).
- `0x00459010` **PhysicsTransformComponent** — Transform/physics component initializer: zeroes a local vector and copies it into the base fields via StructFieldCopy (0x00456150), sets the dword at this+0xBC to 0, clears the byte at this+0xCC, sets the scale factor at this+0xAC to 1065353216 (1.0f), copies the base transform into the saved slot at this+144 via VectorCopy (0x00456130), sets the active flag byte at this+0xA0 to 1, returns this.
- `0x00459070` **PhysicsTransformComponent** — Per-wheel suspension force solver: reads the wheel position (this+0x0C..0x14), the flags byte at this+0x74 and the init flag at this+0xCC. On first use (flag bit 1 of this+0x74 clear, this+0xCC zero) it evaluates the suspension spline object at this+0xB0 via GuardedFunctionWithFlagSet (0x004582C0) at two parameters (second read from this+0xB8), picks the candidate nearest the contact point, and stores the direction sign at this+0xAC. The normal path scales contact velocity magnitude by the spring scale this+0xA8, multiplies by the stored direction and time delta, adds the bias this+0xBC, evaluates the spline, copies the force vector via F_3VectorCopyToStruct (0x00456110), and derives velocity as finite difference before StructFieldCopy (0x00456150).
- `0x004599C0` **CollisionContactAccumulator** — Collision contact impulse term: stores a3 at this+0x24 and a3+100.0 at this+0x20, scales the a2 direction components by the a2 magnitude factor into v7, builds a delta v6 between the double body-state triple at this+0xD8/0xE0/0xE8 and the a2 position, and returns the cross-product rotation accumulation result of F_3DVectorCrossProductRotationAccumulation (0x00569670). Invoked by ModeDispatchWithSwitch (0x0040F4B0).
- `0x00459A40` **CollisionContactAccumulator** — Frame-path vehicle physics integrator: scales body-state velocity components of the a2 state array by the factor a2[2], adds each into the position/displacement accumulator doubles at this[27..29] (offsets 0xD8/0xE0/0xE8), writes the accumulated doubles back, emits the integrated displacement as floats to a3, and forwards them to ThreeFieldSetterWithSubCall (0x0054B3B0), returning its result.
- `0x0045B5C0` **PhysicsChannelSet** — Maximum normalized-coordinate query across the active physics channels: obtains the channel count via FloatArrayThresholdSearch (0x0045BB00), iterates, resolves each flat index via FindActivePhysicsChannelByIndex (0x0045B580), reads the two input fields via DoubleFieldGetterAt0x300x34 (0x00456040), computes the normalized coordinate at 92*v3 + this + 60 via NormalizedCoordinateCalculator (0x004DD400), and keeps the largest. Returns 0.0 when the count is not positive.
- `0x0045BF90` **UnknownObject** — Collision system startup: clears the global mutex handle slot dword_7CD264, the initialized flag byte_7CD26C, and the lock state dword_7CD268 (to -1, unlocked), then creates an unnamed inheritable mutex via the imported CreateMutexA (global import slot 0x0059E1AC), records the handle, and sets the initialized flag when creation succeeded. Returns the mutex handle.
- `0x00464A40` **CollisionSensor** — Collision sensor initializer on a this object: writes near -FLT_MAX to the float at this+0x71, clears the byte at this+0x6C, zeros the dword at this+0x68, returns 0. Linear, no guards or calls. Called by 0x00464C10 and 0x00464D30.
- `0x00465FD0` **UnknownObject** — Zero-argument void reset under the vehicle subsystem: writes decimal 0 into global dword_7CD460 and -1 into the adjacent global dword_7CD464. No callers, callees, fields or guards in the packet.
- `0x00466030` **UnknownObject** — Zero-argument void initializer under the vehicle subsystem: writes decimal 0 into global dword_7CD468 and -1 into the adjacent global dword_7CD46C. No callers, callees, fields or guards in the packet.
- `0x0046B830` **UnknownObject** — Vehicle time-gap/speed formatter for the FTIM timer display: for race-style sessions (session type 0-6) loads the slot vehicle from the global vehicle-pointer array (0x007C54F0), scans for the leader vehicle, computes the lap-time gap and writes an MM:SS.fff string into the caller buffer using the format helper 0x0058815F and CRT float-to-int 0x00587BDC (with an InterruptDispatch call 0x0058957A on the raw gap). For session type 7 it computes average speed from the distance counter, the track reference constant flt_5EA3FC, and the elapsed time, converts via the unit flag byte_7D0474, and writes a %6.2f speed string. Session type from dword_7C56A4, vehicle count from dword_5C329C. Called by 0x0046B5F0.
- `0x0047C960` **UnknownObject** — Weighted collision value update on a global collision/scoring object: clamps the float input a1 to [0.0, 1.0], computes v1 = ThunkToFUN004b9c80() (0x0047C9D0) * clamped input, adds the vehicle lifetime average read from the global object at 0x008AB6EC via VehicleLifetimeAverageAccessor (0x004B9CB0), and passes the result back through a single-argument wrapper. Always executes its computation.
- `0x0049B670` **UnknownObject** — Quantizing cell decoder: truncates the float input a1 to integer (CRTFtol, 0x00587BDC), computes the count of whole 3600-unit 'hours' via the 1/3600 factor, writes it through a2, computes the residual after removing whole hours, and delegates grid-cell computation from the residual to SpatialGridCell (0x0049B630). __stdcall; no caller evidence.
- `0x0049D280` **WheelAudioTrigger** — Wheel-rotation audio trigger for a driver: requires all four audio-source handles at this+0x20..0x2C to be non-null and one of the two activity flags at dword_7C54E0+3984/+3964 to be non-zero; reads a driver appearance bitmask via 0x0049B7A0(&unk_7CE234) and calls AudioEffectTrigger (0x0049E4E0) once per wheel (bits 0..3) with the corresponding handle. Called by SteeringWheelAnimation (0x0049D070).

## Proposed classes

### PhysicsTransformComponent

Physics/transform object holding the position triple at 0x0C..0x14, previous-state triple at 0x18..0x20, optional force outputs at 0x38/0x3C, a flag byte at 0x74, the active/reset flag at 0xA0, the angular-response scale at 0xA4, the suspension spring scale at 0xA8, a direction/scale factor at 0xAC, the suspension spline object pointer at 0xB0 and its second parameter at 0xB8, the bias at 0xBC, and the init flag at 0xCC. Grouped on a same-this call chain: 0x00459010 initializes it, 0x00458DF0 updates velocity/direction (calling 0x00459070 and 0x004584C0 on the same this), 0x00459070 solves per-wheel suspension force, 0x004584C0 filters the angular response.

Methods: `0x004584C0`, `0x00458DF0`, `0x00459010`, `0x00459070`

- `this+0x0000000C` `float position_x` (read_write, DERIVED)
- `this+0x00000010` `float position_y` (read_write, DERIVED)
- `this+0x00000014` `float position_z` (read_write, DERIVED)
- `this+0x00000018` `float previous_state_x` (read, DERIVED)
- `this+0x0000001C` `float previous_state_y` (read, DERIVED)
- `this+0x00000020` `float previous_state_z` (read, DERIVED)
- `this+0x00000038` `float force_output_x` (write, GUESS)
- `this+0x0000003C` `float force_output_y` (write, GUESS)
- `this+0x00000074` `byte flag_bits` (read_write, DERIVED)
- `this+0x000000A0` `byte active_flag` (read_write, DERIVED)
- `this+0x000000A4` `float angular_response_scale` (read, GUESS)
- `this+0x000000A8` `float spring_scale` (read, GUESS)
- `this+0x000000AC` `float direction_or_scale_factor` (read_write, GUESS)
- `this+0x000000B0` `void* suspension_spline_obj` (read, GUESS)
- `this+0x000000B8` `float spline_second_param` (read, GUESS)
- `this+0x000000BC` `float bias` (read_write, GUESS)
- `this+0x000000CC` `byte init_flag` (read_write, DERIVED)

### CollisionContactAccumulator

Collision contact state holder: stores contact terms at 0x20/0x24 and maintains the double displacement/position accumulator triple at 0xD8/0xE0/0xE8. 0x004599C0 computes a contact impulse term and accumulates the cross-product rotation term; 0x00459A40 integrates scaled state velocity into the same accumulator triple and forwards the result.

Methods: `0x004599C0`, `0x00459A40`

- `this+0x00000020` `float contact_store` (write, GUESS)
- `this+0x00000024` `float contact_magnitude` (write, GUESS)
- `this+0x000000D8` `double displacement_accel_x` (read_write, DERIVED)
- `this+0x000000E0` `double displacement_accel_y` (read_write, DERIVED)
- `this+0x000000E8` `double displacement_accel_z` (read_write, DERIVED)

### CollisionImpulseAccumulator

Collision impulse accumulator: six consecutive double fields at 0x560/0x568/0x570 and 0x578/0x580/0x588 receive the components of two input 3-vectors. Single method 0x0044FEE0, invoked by AccumulateAngularImpulse (0x0043E5D0). Whether the two input vectors are linear vs angular impulse is inferred from the caller name only.

Methods: `0x0044FEE0`

- `this+0x00000560` `double first_accel_x` (read_write, DERIVED)
- `this+0x00000568` `double first_accel_y` (read_write, DERIVED)
- `this+0x00000570` `double first_accel_z` (read_write, DERIVED)
- `this+0x00000578` `double second_accel_x` (read_write, DERIVED)
- `this+0x00000580` `double second_accel_y` (read_write, DERIVED)
- `this+0x00000588` `double second_accel_z` (read_write, DERIVED)

### CollisionResponseComputer

Device-backed collision response compute: guards on a device object pointer at this+0x80, queries it through the vtable method at +0x14 with a request block, and derives range endpoints, inverse-range scaling and an interpolated position from the response. Single method 0x0044F7F0.

Methods: `0x0044F7F0`

- `this+0x00000080` `void* query_device_ptr` (read, DERIVED)

### CollisionResponsePerturber

Collision response with random perturbation on a position triple at this+0x90/0x94/0x98: draws random signs, scales by a clamped factor, perturbs each component and writes back. Single method 0x00457A00, invoked by CameraShake (0x0040ADB0).

Methods: `0x00457A00`

- `this+0x00000090` `float position_x` (read_write, DERIVED)
- `this+0x00000094` `float position_y` (read_write, DERIVED)
- `this+0x00000098` `float position_z` (read_write, DERIVED)

### CollisionSensor

Collision sensor state: contact counter at 0x68, collision-detection flag byte at 0x6C, and sensor detection value float at 0x71. Single method 0x00464A40 initializes the three fields; called by 0x00464C10 and 0x00464D30.

Methods: `0x00464A40`

- `this+0x00000068` `dword contact_count` (write, GUESS)
- `this+0x0000006C` `byte collision_detection_flag` (write, GUESS)
- `this+0x00000071` `float sensor_detection_value` (write, GUESS)

### PhysicsChannelSet

Set of active physics channels: two input field values near this+0x04 and a channel region at this+0x60 with a 92-byte stride. No fields carry allowed evidence refs in this packet, so the field table is empty; the layout is noted as unresolved. Single method 0x0045B5C0 computes the maximum normalized coordinate across the active channels.

Methods: `0x0045B5C0`


### WheelAudioTrigger

Wheel-rotation audio trigger: four audio-source handles at this+0x20..0x2C, gated on vehicle activity flags and a driver appearance bitmask, dispatched one AudioEffectTrigger call per wheel. Single method 0x0049D280, invoked by SteeringWheelAnimation (0x0049D070).

Methods: `0x0049D280`

- `this+0x00000020` `void* audio_source_0` (read, GUESS)
- `this+0x00000024` `void* audio_source_1` (read, GUESS)
- `this+0x00000028` `void* audio_source_2` (read, GUESS)
- `this+0x0000002C` `void* audio_source_3` (read, GUESS)

## Compatibility contracts

- **CollisionGlobalBlockLayout** — The collision subsystem keeps fixed 24-byte global blocks whose first dword is a per-block tag (observed 83, 85, 88, 89, 90, 91, 93, 94, 97, 98, 99, 101), followed by four or five zeroed state dwords and a terminal threshold (9000, 18000 or 27000). Blocks are initialized by twelve unconditional initializers at bases 0x007CCA2C, 0x007CD064, 0x007CD080, 0x007CD01C, 0x007CA534, 0x007CA564, 0x007CCA54, 0x007CA4B8, 0x007CA51C, 0x007CA420, 0x007CA3F8 and 0x007CA458. A replacement must reproduce the tag/state/threshold layout and the tag values.
- **CollisionLockState** — The collision system owns a global mutex record: handle slot dword_7CD264, lock state dword_7CD268 (-1 marks unlocked), and an initialized flag byte_7CD26C. Startup creates an unnamed inheritable mutex through the imported CreateMutexA (import slot global 0x0059E1AC) and sets the initialized flag on success. The lock/unlock pairing is outside the visible scope.
- **CollisionDistanceStatePairs** — Two adjacent dword-pair records are reset to (0, -1): dword_7CD460/dword_7CD464 by 0x00465FD0 and dword_7CD468/dword_7CD46C by 0x00466030. The -1 sentinel is preserved verbatim; its meaning (invalid/cleared marker) is not asserted by the packet.
- **CollisionDeviceQuery** — Collision response computation queries a device object stored at this+0x80 through its vtable method at slot +0x14 with a request block of (24, 16, a2, 1) and command id 4; a zero return means success, and only then are the response outputs read. The request block layout and command semantics are opaque without the device interface contract.
- **SuspensionSplineEvaluation** — The suspension solver evaluates a spline object at this+0xB0 through GuardedFunctionWithFlagSet (0x004582C0). First call (flag bit 1 of this+0x74 clear and this+0xCC zero) evaluates at parameter 0.0 and a second spline parameter from this+0xB8 to pick the direction nearest the contact point, stored as +1.0/-1.0 at this+0xAC. The normal path feeds the spline input v5 = |a3| * this+0xA8 * this+0xAC * delta + this+0xBC.

## Unresolved

- Twelve collision global-block initializers (0x0044E600, 0x0044E6C0, 0x0044E7E0, 0x0044E840, 0x0044E8A0, 0x0044E900, 0x0044E9C0, 0x0044EA20, 0x0044EB40, 0x0044EBA0, 0x0044EC00, 0x0044ECC0) are kept unowned and unmerged because each writes a distinct global base; the semantic role of each tag and threshold is not packet-evidenced, and prior DERIVED names (CollisionContactCount, CollisionMaxDistance, AudioSourceDepth, etc.) are unverified proposals.
- PhysicsTransformComponent: the same-this grouping of 0x004584C0/0x00458DF0/0x00459010/0x00459070 is supported by the 0x00458DF0 call chain and shared offsets (0x74, 0xA0, 0xA4, 0xAC, 0xBC, 0xCC, 0xB0), but equal offsets on unrelated thiscall pointers are not proof of a single C++ class.
- PhysicsTransformComponent: this+0xAC is written as 1.0f by 0x00459010 (described as scale) and as the +1.0/-1.0 direction sign by 0x00459070; both readings are consistent with a direction/scale factor but neither is independently confirmed.
- PhysicsTransformComponent: which of the two force outputs at 0x38/0x3C feeds which caller, and the meaning of the remaining bits of the flag byte at 0x74, are unknown.
- CollisionContactAccumulator: 0x004599C0 and 0x00459A40 share the double triple at 0xD8/0xE0/0xE8 but are reached from different callers (0x0040F4B0 vs the frame path); common ownership is GUESS, not proven.
- CollisionContactAccumulator: the a2 layout (magnitude at index 1, direction at indices 8-10, position at indices 5-7) is inferred from raw float indexing; the double reads at 0xD8/0xE0/0xE8 as contact body state are DERIVED prose.
- CollisionImpulseAccumulator: whether the two input 3-vectors are specifically linear vs angular impulse is inferred from the caller name AccumulateAngularImpulse; contiguity of the six doubles derives from index arithmetic.
- CollisionResponseComputer: the request block layout (24, 16, a2, 1), the command id 4, and the device vtable slot +0x14 contract are opaque without the device interface; the response outputs written to a3..a8 are unnamed.
- CollisionResponsePerturber: VectorCopy writes the perturbed vector into the object but the exact destination offset (0x90..0x98 or object base) is inside 0x00456130; the parity/RNG semantics of UtilityFunction_6010 are not verified.
- CollisionMutexInitialization (0x0045BF90): the lock/unlock pairing of dword_7CD268 and the intended usage site are not visible; the three artifact globals 0xFF00000000005450/51/52 are decompiler artifacts with no real operation.
- CollisionDistanceStatePairs (0x00465FD0, 0x00466030): the collision-distance/flag semantics of the two dword pairs and the -1 sentinel meaning are not established; no read sites exist in the packet.
- VehicleTimeGapFormatter (0x0046B830): vehicle offsets 16480/16484 (session-state codes), 16540 (lap time), 16568 (elapsed time) and 16444 (distance counter) are grounded only by this function's usage; the InterruptDispatch call on the gap value is unexplained.
- CollisionGridCellDecoder (0x0049B670): the a1 input is ambiguous (3600-unit 'hours' quantization suggests session time, delegation to SpatialGridCell suggests an angular grid); destinations a2/a3/a4 and the caller are undocumented.
- CollisionSystemInit (0x0047C960): the final single-argument wrapper call is not independently evidenced; the type of the global object at 0x008AB6EC is unknown.
- PhysicsChannelSet (0x0045B5C0): the 92-byte channel stride at this+0x60 and the normalized-coordinate meaning depend on the physics-channel layout, which is not established.
- CollisionSensor (0x00464A40): field roles at 0x68/0x6C/0x71 come from existing analysis (DERIVED); the owner class is unknown though callers suggest the large struct initialized by 0x00464C10.
- WheelAudioTrigger (0x0049D280): the driver-appearance bitmask semantics from 0x0049B7A0 and the one-bit-per-wheel mapping are unverified; the activity flags at dword_7C54E0+3984/+3964 are unnamed.
- A set of globals listed in the packet (0x0059E43C, 0x0059E440, 0x0059E450, 0x0059E670, 0x0059E6A4, 0x0059E6F8, 0x0059E84C, 0x0059E9B8, 0x0059E9BC, 0x0059E9C0, 0x0059E9C8, 0x0059EA08, 0x0059EFA4, 0x0059F130, 0x0059FB48, 0x0059FB50) appears in the packet fact tables but nowhere in the raw decompiled bodies; their roles are unverifiable and they are preserved only as unresolved evidence.
- The legacy ABI label Object_Camera_Target_Positioning on 0x00458DF0 conflicts with the physics-update behavior seen in the raw source and is unverified.
