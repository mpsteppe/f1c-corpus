# VehiclePhysics

Scope: `vehicle_physics`  
Trust: `DERIVED`

DERIVED architecture for the vehicle_physics scope from 32 validated functions. A central VehiclePhysicsBody object (DERIVED) carries the per-frame physics: 0x00441600 (PhysicsStepFrame) shifts wheel-state history, runs the suspension wheel-dynamics solver and two batch-iteration helpers over the workspace at this+0x15AC, performs a minimum-finding iteration and copies suspension data into physics sub-objects; 0x00441D60 (PhysicsIntegrationStep) runs one integration substep (counter helper on this+0x15AC, setup passes, damper/spring with anti-roll, velocity damping gated on this+0x19C, -9.81 gravity per attached body, torque accumulation, rigid-body constraint solve against the block at *(this+0x15F0), and two linear/angular delta batches); 0x004423B0 (PhysicsWheelGroundContactStep) resolves per-wheel grip, ground planes and penetration impulses; 0x00446FD0 transforms collision contact positions using the body rotation/position; 0x00447B10 generates a randomized physics parameter from a trig-table draw. A separate VehiclePhysicsState (DERIVED, per packet owner) packs the telemetry buffer (0x00447F30). A RigidBodyStateBlock (GUESS), GroundContactSurface (GUESS) and VehicleContactState (GUESS) describe the indirect objects at *(this+0x15F0), *(this+0x16E0) and *(this+0x1F00). Collision build/query helpers CollisionBodyAABB, CollisionGeometryBuilder, QuadraticSurfaceTestObject and CollisionMaterialTable (all GUESS) and a large CollisionGlobalState (GUESS) family of straight-line init functions that seed [typeID, 0.0] global pairs and chain into tail helpers complete the picture. All owners, field names, enum values and the -1.0f/1.0f bit-pattern readings are worker proposals; none are packet-confirmed.

## Function roles

- `0x00441600` **VehiclePhysicsBody** — Per-frame physics step: shifts wheel-state history (0x004412F0), runs the suspension wheel-dynamics solver with the step value a2 (0x0043F7F0), applies two batch-iteration helpers (0x0056ECF0, 0x0056EE40) to the suspension workspace at this+1387 dwords, performs a minimum-value iteration (0x0056F090), then copies suspension data into the physics sub-objects (0x00441450). No branches; the full sequence always runs. Invoked from VehiclePhysicsIntegrationStep (0x00441650).
- `0x00441D60` **VehiclePhysicsBody** — Physics integration substep on the vehicle physics object: runs the counter helper 0x0056EB90 on this+0x15AC, two unnamed setup passes (0x004423B0, 0x00442C90), and DamperSpringForceComputationWithAntiRoll (0x004432F0); conditionally applies VelocityDampingFromSpeedError (0x00441AD0) when the double at this+0x19C is zero; applies a -9.81 acceleration term to each body in the array at this+0x15B0 (count this+0x15AC, stride 580); accumulates torques (0x00441BB0), solves rigid-body constraints (0x004359A0) against the block at *(this+0x15F0), and accumulates two batches of linear/angular velocity deltas into that block. Returns a pointer to the block angular-velocity accumulator. Sole packet caller is VehiclePhysicsIntegrationStep (0x00441650).
- `0x004423B0` **VehiclePhysicsBody** — Per-frame wheel ground-contact physics step: computes per-wheel track grip (uniform copy or position-projected 1D-table lookup via 0x004E9630 and F_1DTableLookupWithLerp 0x004FD7E0), queries the spatial grid (0x0044C4C0) for the body ground plane, generates collision contacts and friction response for 4 wheels (0x00436870), resolves ground penetration into angular-momentum impulses (0x00569AD0) plus a per-frame impact packet, and optionally applies a per-wheel contact impulse loop gated by the suspension flag at this+0x1724. Called from the integration step (0x00441D60).
- `0x00446FD0` **VehiclePhysicsBody** — Collision-position transform on the vehicle physics object: rotates a part-local contact vector (at *(1124*a2 + this + 1000) + 4) by the rigid-body rotation matrix (at *(this+0x15F0) + 4) through F_3DVectorTransformBy33Matrix (0x004361D0) into a3, subtracts the vehicle world position (this+0x15FC / 0x1604 / 0x160C) to make it vehicle-relative, then applies F_33MatrixMultiply (0x0056C740) to a4 and returns F_33MatrixMultiply(a5). Invoked by sub_4F0430 during collision geometry processing.
- `0x00447B10` **VehiclePhysicsBody** — Randomized physics parameter generator in [0.0, 1.0]: returns 0.0 when the active flag byte this[0x1C59] is unset or the input this[0x19C] <= 0.0, 1.0 when this[0x19C] >= 0.9, otherwise interpolates between this[0x19C]+0.1 and this[0x19C]+1.6 using a trig-table pseudo-random value from TrigTableLookup (0x00447AB0) and clamps to 1.0.
- `0x00447F30` **VehiclePhysicsState** — Packs a flat float telemetry array a2 from the vehicle physics state: world position, orientation basis, a yaw angle from the rotation matrix via atan2, world-frame velocity (body-frame vector rotated by the 3x3 matrix via Mat3x3MulVec 0x004388D0 and scaled), rotation-rate unit conversions, linear-state doubles, and per-wheel suspension/tire data from a bounded four-wheel loop. Called on the frame path from DebugLogInit (0x004D5960) for external/telemetry consumption.
- `0x00448E90` **CollisionBodyAABB** — AABB collision body initializer: zeroes the 24-byte header of the object, then sets the next/link pointer at +0x1C to 0, the body type byte at +0x19 to 0, the word handle at +0x1A to -1 (INVALID sentinel) and the active flag byte at +0x18 to 1. Returns the constructed object.
- `0x004499E0` **CollisionGlobalState** — Resets the collision subsystem global root state: clears the 8-byte collision global double at 0x007C9360 to 0.0, then runs collision-tree node cleanup over the same global base and returns its result. Free function with no object context.
- `0x0044A070` **QuadraticSurfaceTestObject** — Quadratic surface collision test: performs a three-axis slab cull (per-axis dot against the this float table compared to the bound at this+0x38), evaluates the conic surface equation from the six double coefficients at this+0x0/0x8/0x10/0x18/0x20/0x28, accepts the hit when the residual <= the max threshold at a2+24 and |residual| < the current best at a2+32, then records the nearest-hit distance (a2+32), hit object pointer (a2+48) and surface value (a2+40) and returns 1. Invoked by BVHTreeTraversal (0x0044AA30) and SpatialGridQuery (0x0044C4C0).
- `0x0044A450` **CollisionMaterialTable** — Collision material property lookup from global tables keyed by material index a1: basic materials (index 0..7) take dword_7CA388 / unk_7CA3A4; extended materials (index >7) take flt_7CA3C0 with a negative index and negated flt_7CA36C values. Returns the a3 output pointer.
- `0x0044AAE0` **CollisionGeometryBuilder** — Recursively subdivides triangle (a1, a2, a3) for collision-mesh generation: computes each edge with Vec3Subtract (0x004484C0) and its squared length with EmptyFunction (0x004484F0), selects the longest edge still exceeding the squared-length threshold 22500.0 (dbl_59EF38), splits it at its midpoint via WeightedAverageInterpolation (0x00448480) and recurses on the two halves; when all edges are below the threshold, emits the triangle via TriangleMeshAdjacencyBuilder (0x004493A0).
- `0x0044AF20` **CollisionGeometryBuilder** — Gathers six component values from three vertex-source pointers referenced by the input array a2 into the output buffer a1: source 0 at offsets 0 and 8, source 1 at offsets 8 and 16, source 2 at offset 16 and 0. Returns the source-2 pointer.
- `0x0044B040` **CollisionGeometryBuilder** — Copies a capsule/collision shape payload (0x18 bytes from a1) into a stack AABB collision body initialized by AABBCollisionBodyInitializer (0x00448E90), applies a small-struct copy from a2 (0x00448EC0), then fits a HAT polygon surface (0x00449A80) onto the result and returns the fit result.
- `0x0044C620` **CollisionGlobalState** — Collision-state initializer: sets dword_7CA490 = 1, flt_7CA494 = 0.0, flt_7CA498 = 0.0 and dword_7CA49C = 1065353216 (IEEE-754 bit pattern of 1.0f, preserved as written). No guards, fields or callees.
- `0x0044C740` **CollisionGlobalState** — Collision-grid initializer for the 0x7CA470 block: sets the grid size dword_7CA470 = 4, zeroes flt_7CA474 and flt_7CA47C, and stores the integer bit pattern -1082130432 into dword_7CA478. No branches and no calls.
- `0x0044C7A0` **CollisionGlobalState** — Collision-state initializer: sets the state/type word dword_7CD198 = 5, two float fields flt_7CD19C / flt_7CD1A0 to 0.0, and dword_7CD1A4 to the literal 1065353216 (1.0f bit pattern). Unconditional writes, no guards and no callees.
- `0x0044C800` **CollisionGlobalState** — Collision-region initializer: sets dword_7CA3C8 = 6, flt_7CA3CC = 0.0, dword_7CA3D0 = -1082130432 (-1.0f bit pattern, preserved as written) and flt_7CA3D4 = 0.0. Unconditional writes, no guards and no callees.
- `0x0044C8C0` **CollisionGlobalState** — Collision-friction initializer: sets dword_7CCFB0 = 8, flt_7CCFB4 = 0.0, dword_7CCFB8 = -1082130432 (-1.0f bit pattern) and flt_7CCFBC = 0.0. Unconditional writes, no guards and no callees.
- `0x0044C920` **CollisionGlobalState** — Collision-global initializer: writes dword_7CCA6C = 9, flt_7CCA70 = 0.0, flt_7CCA74 = 0.0 and dword_7CCA78 = 1065353216 (1.0f bit pattern). No guards, callees, arguments or return value.
- `0x0044C980` **CollisionGlobalState** — Collision-global initializer: writes dword_7CCF80 = 10, flt_7CCF84 = 0.0, dword_7CCF88 = -1082130432 (-1.0f bit pattern) and flt_7CCF8C = 0.0. No guards, callees, arguments or return value.
- `0x0044C9E0` **CollisionGlobalState** — Collision-global settings block initializer: sets dword_7CCCB0 = 11 and flt_7CCCB4 = 0.0, then calls SteeringSensitivityInit to initialize steering-sensitivity state. Free function with no object context.
- `0x0044CA40` **CollisionGlobalState** — Collision-static initializer: writes dword_7CCA7C = 12, flt_7CCA80 = 0.0, dword_7CCA84 = -1082130432 (-1.0f bit pattern) and flt_7CCA88 = 0.0. No guards, callees, arguments or return value.
- `0x0044CB60` **CollisionGlobalState** — Collision-global initializer: writes 104 to dword_7CD108, 0.0 to flt_7CD10C, then calls InputHandlerGlobalReset (present in the raw source text only; no callee entry or address in the packet). No return value.
- `0x0044CBC0` **CollisionGlobalState** — Collision-global initializer: sets dword_7CD188 = 105, clears flt_7CD18C to 0.0, then calls GlobalStateInitNegOne (raw-source name only). No arguments, no return value.
- `0x0044CC20` **CollisionGlobalState** — Collision-global initializer: sets dword_7CA3B8 = 30, clears flt_7CA3BC to 0.0, then calls CameraViewZoomInitializer (raw-source name only). No arguments, no return value.
- `0x0044CC80` **CollisionGlobalState** — Collision-state initializer: writes dword_7CC9BC = 31 and flt_7CC9C0 = 0.0, then calls the AudioRendererFloatConstantInitializer helper (raw-source name only). No branches, arguments or local state.
- `0x0044CCE0` **CollisionGlobalState** — Collision-material initializer: writes dword_7CD158 = 32 and flt_7CD15C = 0.0, then calls the sub_44CCF4 helper (raw-source name only). No branches, arguments or local state.
- `0x0044CD40` **CollisionGlobalState** — Collision-global initializer: writes dword_7CA50C = 33 and flt_7CA510 = 0.0, then calls the InitializePhysicsConstants helper (0x0044CD54). No branches, arguments or local state.
- `0x0044CD54` **CollisionGlobalState** — Physics constant initializer: stores the fixed signed integer -1082130432 into dword_7CA514 and 0.0 into flt_7CA518. Trivial state seeding with no guards, calls or arguments. Called from CollisionGlobalsInit (0x0044CD40).
- `0x0044CDA0` **CollisionGlobalState** — Collision-state initializer: seeds dword_7CD0F8 with 34 and flt_7CD0FC with 0.0, then delegates to CollisionScaleInit (0x0044CDB4) to set collision-scale globals. No arguments, guards or other calls in this packet's evidence.
- `0x0044CDB4` **CollisionGlobalState** — Collision scale initializer: stores 0.0 into flt_7CD100 and the fixed signed integer 1065353216 into dword_7CD104. Trivial state seeding with no guards, calls or arguments. Called from CollisionStateInit_cda0 (0x0044CDA0).
- `0x0044CEC0` **CollisionGlobalState** — Collision-grid initializer for the 0x7CCBF4 block: sets dword_7CCBF4 = 37, zeroes flt_7CCBF8, then calls InitFloatConstants (raw-source name only). No branches.

## Proposed classes

### VehiclePhysicsBody

Per-frame vehicle physics object: advances the suspension/wheel workspace, integrates attached bodies with a rigid-body constraint solve, resolves wheel ground contact and penetration impulses, transforms collision contact positions, and draws randomized physics parameters.

Methods: `0x00441600`, `0x00441D60`, `0x004423B0`, `0x00446FD0`, `0x00447B10`

- `this+0x00000060` `double per_frame_timestep` (read, DERIVED)
- `this+0x00000064` `double solver_parameter` (read, GUESS)
- `this+0x000000EC` `double linear_delta_batch_a_x` (read, GUESS)
- `this+0x000000F4` `double linear_delta_batch_a_y` (read, GUESS)
- `this+0x000000FC` `double linear_delta_batch_a_z` (read, GUESS)
- `this+0x00000104` `double angular_delta_batch_a_x` (read, GUESS)
- `this+0x0000010C` `double angular_delta_batch_a_y` (read, GUESS)
- `this+0x00000114` `double angular_delta_batch_a_z` (read, GUESS)
- `this+0x0000019C` `double input_parameter` (read, DERIVED)
- `this+0x00000474` `array wheel_data_base` (read, DERIVED)
- `this+0x000004FC` `array wheel_grip_array` (read_write, DERIVED)
- `this+0x000015AC` `int attached_body_count` (read, DERIVED)
- `this+0x000015B0` `array attached_body_array` (read, DERIVED)
- `this+0x000015F0` `pointer rigid_body_block_ptr` (read_write, DERIVED)
- `this+0x000015FC` `double world_position_x` (read, DERIVED)
- `this+0x00001604` `double world_position_y` (read, DERIVED)
- `this+0x0000160C` `double world_position_z` (read, DERIVED)
- `this+0x00001660` `array wheel_contact_point_array` (read, DERIVED)
- `this+0x00001668` `double wheel_contact_offset_x` (read, GUESS)
- `this+0x00001670` `double wheel_contact_offset_z` (read, GUESS)
- `this+0x000016E0` `array wheel_hit_surface_array` (read_write, DERIVED)
- `this+0x000016F0` `array wheel_penetration_array` (read_write, DERIVED)
- `this+0x00001718` `byte ground_contact_flag` (read_write, DERIVED)
- `this+0x0000171C` `double max_ground_impulse` (read_write, DERIVED)
- `this+0x00001724` `byte contact_impulse_flag` (read, DERIVED)
- `this+0x00001748` `double wheel_velocity_x` (read, GUESS)
- `this+0x00001750` `double wheel_velocity_y` (read, GUESS)
- `this+0x00001758` `double wheel_velocity_z` (read, GUESS)
- `this+0x00001904` `pointer ground_surface_ptr` (write, DERIVED)
- `this+0x00001908` `double ground_height` (write, DERIVED)
- `this+0x0000190C` `double ground_height_fallback_b` (write, DERIVED)
- `this+0x00001910` `double ground_fallback_a` (read, GUESS)
- `this+0x00001914` `double ground_fallback_b` (read, GUESS)
- `this+0x00001918` `double query_world_pos_x` (read, DERIVED)
- `this+0x00001920` `double query_world_pos_y` (read, DERIVED)
- `this+0x00001928` `double query_world_pos_z` (read, DERIVED)
- `this+0x00001C59` `byte random_parameter_active_flag` (read, DERIVED)
- `this+0x00001F00` `pointer vehicle_config_ptr` (read_write, DERIVED)
- `this+0x00001F04` `double linear_delta_batch_b_x` (read, GUESS)
- `this+0x00001F0C` `double linear_delta_batch_b_y` (read, GUESS)
- `this+0x00001F14` `double linear_delta_batch_b_z` (read, GUESS)
- `this+0x00001F1C` `double angular_delta_batch_b_x` (read, GUESS)
- `this+0x00001F24` `double angular_delta_batch_b_y` (read, GUESS)
- `this+0x00001F2C` `double angular_delta_batch_b_z` (read, GUESS)

### VehiclePhysicsState

Packs the flat float telemetry buffer from the vehicle physics state (world position, orientation basis, yaw, world-frame velocity, rotation rates, linear-state doubles, per-wheel suspension/tire data). Likely the same underlying object as VehiclePhysicsBody; split here because the packet owner tag for 0x00447F30 is the DERIVED name VehiclePhysicsState.

Methods: `0x00447F30`

- `this+0x00000000` `double linear_state_0` (read, GUESS)
- `this+0x00000008` `double linear_state_1` (read, GUESS)
- `this+0x00000010` `double linear_state_2` (read, GUESS)
- `this+0x00000018` `double linear_state_3` (read, GUESS)
- `this+0x00000020` `double linear_state_4` (read, GUESS)
- `this+0x00000040` `double linear_state_5` (read, GUESS)
- `this+0x00000048` `double linear_state_6` (read, GUESS)
- `this+0x00000050` `double linear_state_7` (read, GUESS)
- `this+0x00000060` `double world_position_first_component` (read, DERIVED)
- `this+0x00000474` `array wheel_telemetry_base` (read, DERIVED)
- `this+0x000015F0` `pointer rigid_body_block_ptr` (read, DERIVED)
- `this+0x000016F0` `array wheel_penetration_array` (read, DERIVED)
- `this+0x00001C5C` `double rotation_rate_channel_a` (read, DERIVED)
- `this+0x00001D4C` `double telemetry_tail_double_a` (read, GUESS)
- `this+0x00001D8C` `double telemetry_tail_double_b` (read, GUESS)
- `this+0x00001EF0` `int telemetry_tail_int` (read, GUESS)

### RigidBodyStateBlock

Data block at *(this+0x15F0): world translation, a 3x3 double rotation matrix, impulse terms, a velocity scale, and the linear/angular velocity accumulators the integration substep writes into. No methods in this packet.

Methods: 

- `*(this+0x15F0)+0x00000004` `double translation_x` (read, DERIVED)
- `*(this+0x15F0)+0x0000000C` `double translation_y` (read, DERIVED)
- `*(this+0x15F0)+0x00000014` `double translation_z` (read, DERIVED)
- `*(this+0x15F0)+0x0000001C` `double rotation_m00` (read, GUESS)
- `*(this+0x15F0)+0x00000024` `double rotation_m01` (read, GUESS)
- `*(this+0x15F0)+0x0000002C` `double rotation_m02` (read, GUESS)
- `*(this+0x15F0)+0x00000034` `double rotation_m10` (read, GUESS)
- `*(this+0x15F0)+0x0000003C` `double rotation_m11` (read, GUESS)
- `*(this+0x15F0)+0x00000044` `double rotation_m12` (read, GUESS)
- `*(this+0x15F0)+0x0000004C` `double rotation_m20` (read, GUESS)
- `*(this+0x15F0)+0x00000054` `double rotation_m21` (read, GUESS)
- `*(this+0x15F0)+0x0000005C` `double rotation_m22` (read, GUESS)
- `*(this+0x15F0)+0x00000064` `double impulse_term_x` (read, GUESS)
- `*(this+0x15F0)+0x0000006C` `double impulse_term_y` (read, GUESS)
- `*(this+0x15F0)+0x00000074` `double impulse_term_z` (read, GUESS)
- `*(this+0x15F0)+0x0000007C` `double impulse_term_b_x` (read, GUESS)
- `*(this+0x15F0)+0x00000084` `double impulse_term_b_y` (read, GUESS)
- `*(this+0x15F0)+0x0000008C` `double impulse_term_b_z` (read, GUESS)
- `*(this+0x15F0)+0x000000B4` `double velocity_scale` (read, DERIVED)
- `*(this+0x15F0)+0x00000134` `double linear_velocity_accum_x` (read_write, DERIVED)
- `*(this+0x15F0)+0x0000013C` `double linear_velocity_accum_y` (read_write, DERIVED)
- `*(this+0x15F0)+0x00000144` `double linear_velocity_accum_z` (read_write, DERIVED)
- `*(this+0x15F0)+0x0000014C` `double angular_velocity_accum_x` (read_write, DERIVED)
- `*(this+0x15F0)+0x00000154` `double angular_velocity_accum_y` (read_write, DERIVED)
- `*(this+0x15F0)+0x0000015C` `double angular_velocity_accum_z` (read_write, DERIVED)

### GroundContactSurface

Hit-result surface objects referenced by the per-wheel hit pointer array at *(this+0x16E0): carry the contact plane normal and further surface terms used to derive the ground-contact impulse. Data-only; no methods in this packet.

Methods: 

- `*(this+0x16E0)+0x00000000` `double normal_x` (read, GUESS)
- `*(this+0x16E0)+0x00000008` `double normal_y` (read, GUESS)
- `*(this+0x16E0)+0x00000010` `double normal_z` (read, GUESS)
- `*(this+0x16E0)+0x00000018` `double surface_term_a` (read, GUESS)
- `*(this+0x16E0)+0x00000020` `double surface_term_b` (read, GUESS)

### VehicleContactState

State container at *(this+0x1F00) that receives the per-frame ground-impact contact packet (magnitude comparison, strength, response, wheel world position) and carries the contact-active pointer and post-processing flag that gate the body ground-query path.

Methods: 

- `*(this+0x1F00)+0x000000B0` `double contact_packet_compare` (read, GUESS)
- `*(this+0x1F00)+0x000000B8` `double contact_packet_strength` (write, GUESS)
- `*(this+0x1F00)+0x000000BC` `double contact_packet_response` (write, GUESS)
- `*(this+0x1F00)+0x000000C0` `double contact_packet_wheel_pos` (write, GUESS)
- `*(this+0x1F00)+0x00000CD4` `pointer contact_active_ptr` (read, DERIVED)
- `*(this+0x1F00)+0x00000D14` `byte contact_postprocess_flag` (read, DERIVED)

### CollisionBodyAABB

Stack/heap AABB collision body: 24-byte zeroed header plus an active flag, body type byte, INVALID word handle and next/link pointer. Initialized by AABBCollisionBodyInitializer.

Methods: `0x00448E90`

- `this+0x00000018` `byte active_flag` (write, DERIVED)
- `this+0x00000019` `byte body_type` (write, DERIVED)
- `this+0x0000001A` `word handle` (write, DERIVED)
- `this+0x0000001C` `pointer next_ptr` (write, DERIVED)

### CollisionGeometryBuilder

Collision-mesh build helpers: recursive longest-edge-first triangle subdivision, face-vertex component gather, and capsule-shape copy into an initialized AABB body with HAT polygon surface fit. The three functions share the collision-pipeline caller pair 0x0044B110 / 0x0044B370.

Methods: `0x0044AAE0`, `0x0044AF20`, `0x0044B040`


### QuadraticSurfaceTestObject

Quadratic surface collision proxy: six double conic coefficients (A x*x, B x*z, C z*z, D x, E z, F), slab-cull data, and the slab bound; tested by QuadraticSurfaceCollisionTest from BVHTreeTraversal and SpatialGridQuery.

Methods: `0x0044A070`

- `this+0x00000000` `double coeff_xx` (read, DERIVED)
- `this+0x00000008` `double coeff_xz` (read, DERIVED)
- `this+0x00000010` `double coeff_zz` (read, DERIVED)
- `this+0x00000018` `double coeff_x` (read, DERIVED)
- `this+0x00000020` `double coeff_z` (read, DERIVED)
- `this+0x00000028` `double coeff_const` (read, DERIVED)
- `this+0x00000034` `float slab_normal_axis` (read, GUESS)
- `this+0x00000038` `float slab_bound` (read, GUESS)

### CollisionMaterialTable

Material-indexed property lookup over the global tables flt_7CA36C, dword_7CA388, unk_7CA3A4 and flt_7CA3C0; basic materials (index 0..7) and extended materials (index >7) take different table paths and the a3 output pointer is returned.

Methods: `0x0044A450`


### CollisionGlobalState

Family of straight-line collision-global initializers: each seeds a global block with a subsystem type ID and a companion 0.0 float, then chains into a tail helper (named only in raw source for most); includes the global root reset and the two leaf constant initializers. Sequential type IDs (4..37, 104, 105) and reciprocal helper calls suggest a single ordered init cascade.

Methods: `0x004499E0`, `0x0044C620`, `0x0044C740`, `0x0044C7A0`, `0x0044C800`, `0x0044C8C0`, `0x0044C920`, `0x0044C980`, `0x0044C9E0`, `0x0044CA40`, `0x0044CB60`, `0x0044CBC0`, `0x0044CC20`, `0x0044CC80`, `0x0044CCE0`, `0x0044CD40`, `0x0044CD54`, `0x0044CDA0`, `0x0044CDB4`, `0x0044CEC0`


## Compatibility contracts

- **VehicleFramePhysicsSequence** — The per-frame physics step 0x00441600 must run unconditionally and in order: WheelStateHistoryShift (0x004412F0), SuspensionWheelDynamicsSolver with the step value (0x0043F7F0), the two batch-iteration helpers (0x0056ECF0, 0x0056EE40) over the suspension workspace at this+1387 dwords (this+0x15AC), IterateAndFindMinimumValueFromFunction (0x0056F090), then the suspension-to-physics-subobject copy (0x00441450). No branch may skip the sequence.
- **PhysicsIntegrationSubstep** — The integration substep 0x00441D60 must run the counter helper on this+0x15AC, the setup passes (0x004423B0, 0x00442C90) and DamperSpringForceComputationWithAntiRoll (0x004432F0); velocity damping (0x00441AD0) applies only when the double at this+0x19C is zero; a fixed -9.81 term accumulates into the vertical accumulator of every body in the array at this+0x15B0 (count this+0x15AC, stride 580); then torque accumulation (0x00441BB0), the rigid-body constraint solve (0x004359A0) against the block at *(this+0x15F0) with solver parameters this+0x60/this+0x64, and the two delta batches (this+0xEC..0xFC, this+0x1F04..0x1F2C) into the block linear (+0x134/0x13C/0x144) and angular (+0x14C/0x154/0x15C) accumulators.
- **RigidBodyBlockLayout** — The rigid-body block at *(this+0x15F0) keeps the world translation at +0x4/+0xC/+0x14, the 3x3 double rotation matrix at +0x1C..+0x5C, impulse terms at +0x64..+0x8C, the velocity scale at +0xB4, and the linear (+0x134/+0x13C/+0x144) and angular (+0x14C/+0x154/+0x15C) velocity accumulators that 0x00441D60, 0x004423B0 and 0x00447F30 read.
- **WheelGroundContactModel** — The wheel ground-contact step 0x004423B0 must preserve the grip fill/table-lookup branch on flt_8AFEEC/flt_8AFEE8, the ground-query gate on *(this+0x1F00)+0xCD4 and +0xD14, the ground-separation store to this+0x16F0 (biased by 0.01 under dword_7CE958), the penetration impulse v64 = -385000*separation - 17500*slip feeding AccumulateAngularMomentum (0x00569AD0), the impact-packet update at *(this+0x1F00)+0xB0/+0xB8/+0xBC/+0xC0 with strength clamped to 1.0 and distance to 2.0, and the final per-wheel 160000*offset - 6500*velocity impulse loop gated by this+0x1724.
- **CollisionMaterialIndex** — CollisionMaterialLookup 0x0044A450 must keep the material index split at 7: indexes 0..7 read dword_7CA388[a1] and the unk_7CA3A4 table backwards by a1; indexes >7 read flt_7CA3C0[-a1] and the negation of flt_7CA36C[a1]; the a3 output pointer is returned in eax.
- **CollisionTriangleSubdivision** — RecursiveTriangleEdgeSubdivisionForCollision 0x0044AAE0 must subdivide the longest edge while its squared length exceeds 22500.0 (dbl_59EF38), split at the midpoint via WeightedAverageInterpolation (0x00448480), and emit the triangle via TriangleMeshAdjacencyBuilder (0x004493A0) once all three edges are below the threshold.
- **CollisionGlobalInitPairs** — Each CollisionGlobalState initializer writes a subsystem type ID (4, 5, 6, 8, 9, 10, 11, 12, 30, 31, 32, 33, 34, 37, 104, 105) into a global dword and 0.0 into the adjacent float, then chains to a tail helper (InitializePhysicsConstants 0x0044CD54 from 0x0044CD40, CollisionScaleInit 0x0044CDB4 from 0x0044CDA0; the rest are raw-source names only). The paired [typeID, 0.0] layout and the cascade order are the observable contract.

## Unresolved

- The two batch-iteration helpers sub_56ECF0 / sub_56EE40, the minimum-finding IterateAndFindMinimumValueFromFunction (0x0056F090), the counter helper sub_56EB90 and the setup pass sub_442C90 have no recoverable identity or purpose from this packet.
- The exact meaning of the step value a2 passed to 0x00441600 / 0x00441D60 (time delta or iteration count) is caller-defined and unknown here; it is not proven to be the same quantity as this+0x60.
- The 15 read-only constant globals read by 0x004423B0 (dbl_59E420, dbl_59E430, flt_59E43C, flt_59E800, dbl_59E880, dbl_59EB20, dbl_59EC60, dbl_59ED80..0x59EDA8, dbl_7C9360, unk_8AFEC0) are folded into inlined literals (for example 0.15, 385000, 17500, 6500, 160000); the exact one-to-one binding is not deterministically recovered.
- The per-element body stride 580 and the body+308/312/316/324/328 self-copy and accumulator fields inside the 0x00441D60 loop are not individually listed as packet fields; their semantics are inferred from copy sizes only.
- The origin of the two delta batches (this+0xEC..0xFC and this+0x1F04..0x1F2C) and how they differ is unknown; both land in the same block+308 / block+332 accumulators.
- The telemetry packer fields this+0x5D8 and this+0x1E38 are not visible in the Hex-Rays raw source; the globals dbl_59E420, dbl_59E430, dbl_59EA38 are read but not byte-referenced (they likely back the 9.549296585513721 = 60/(2*pi) unit-conversion factor and atan2 scale terms).
- The init-cascade tail helpers named only in raw source (SteeringSensitivityInit, InputHandlerGlobalReset, CameraViewZoomInitializer, AudioRendererFloatConstantInitializer, sub_44CCF4, InitFloatConstants, GlobalStateInitNegOne) and the reset-path CollisionTreeNodeCleanup have no callee entries or addresses in the packet.
- The semantic meaning of the type IDs 104/105 and 30..37 and of the -1.0f / 1.0f bit patterns written as signed decimals (-1082130432, 1065353216) is DERIVED from bit layout and analysis prose only; the consumers of each global block are not established.
- VehiclePhysicsBody and VehiclePhysicsState are split only because the packet owner tag for 0x00447F30 is the DERIVED name VehiclePhysicsState; the two share field offsets (this+0x60, this+0x474, this+0x15F0, this+0x16F0) and are likely the same underlying object.
- The RigidBodyStateBlock, GroundContactSurface and VehicleContactState groupings and all of their field names are GUESS; only the offsets are packet-grounded.
- The a4 and a5 matrix arguments of CollisionPositionTransform (0x00446FD0) and the identity of the object consumed by 0x0044A450 (the a2/a3 outputs labeled friction/restitution by prose) are not established.
- The CollisionGeometryBuilder grouping is inferred from the shared caller pair 0x0044B110 / 0x0044B370 and the collision-pipeline theme; the packet lists no owner for any of its three functions.
- The hit surface reads at object offsets +20/+24/+36/+44 inside 0x004423B0 and the wheel contact struct at this+0x28C are derived from raw dereferences; only the *(this+0x16E0) +0/+8/+10/+18/+20 offsets have field evidence refs.
- The part-entry stride 1124 at this+1000 inside 0x00446FD0 is a computed offset with no field evidence ref; the legacy ABI names (abi:lead) carry LEGACY trust, not worker-confirmed identity.
- The claim that dbl_59E430/dbl_59ED50 supply the -9.81 gravity term, and the exact role of this[0x19C] as both a velocity-damping gate and a random-parameter input, are DERIVED and not cross-confirmed.
- 0x0044AF20 reads a2-relative component offsets +8 and +16 through the packet's field:this bases; those refs are listed as unresolved rather than assigned to a class because their true base is the input array a2, not an object.
- Whether the a1 index space of 0x0044A450 is a material ID enum or a bitmask is unverified.
