# VehiclePhysics

Scope: `vehicle_physics`  
Trust: `DERIVED`

Conservative architecture proposal for 16 validated vehicle-physics functions. Three functions (0x005694E0, 0x00569DE0, 0x0056A150) share a coherent rigid-body state layout (position/velocity/angular momentum/angular velocity/world inertia tensor plus prediction and reference buffers) and form the RigidBodyState class. Collision contact detection (0x0054F2F0) owns a distinct contact-container layout and writes 29-dword contact entries, and the batch renderer (0x00561660) is a transform-node vertex emitter fed by the same dword_8B8F24 vtable service. Remaining functions are small array iterators (0x0056EC00, 0x0056F020), a query getter, an allocator node destructor, global-object lifecycle shims, an indexed transform reader and a stream transform. All owners are packet-UNKNOWN; class boundaries are DERIVED/GUESS from field-layout coherence. Several receiver objects reuse the same generic 'this' base token at equal offsets (e.g. 0x04, 0x0C, 0x14, 0x1E4, 0x204) without proven common ownership; each such offset is attributed to one class per the rule against merging offsets, and the collision is recorded in unresolved.

## Function roles

- `0x0054E1A0` **IndexedTransformTable** — Bounds-checked indexed vector/transform reader: resolves three 48-byte-stride transform elements from 16-bit sub-indices in a 36-byte entry and copies each vector into an optional output pointer.
- `0x0054F2F0` **CollisionContactManager** — Per-frame collision contact detection: depth-tests moving segments against triangles through the dword_8B8F24 device service, lerps and confirms contact points, populates 29-dword contact entries and forwards each through the response wrapper.
- `0x00561660` **TransformNodeBatchRenderer** — Transform-node batch emitter: walks the node linked list, culls faces by depth and plane-sign tests, and writes perspective-projected interpolated vertices into the bounded output buffer.
- `0x00563F70` **PhysicsGlobalState** — Sign/direction helper over a double argument; polarity is inverted by a module-global flag at dword_8D46B4+132. Two AudioMixerSampleGetWithFallback calls precede it with unused results.
- `0x00564DD0` **StreamCipherTransform** — Sixteen-round substitution-table-driven stream transform over a caller-owned table buffer; mixes two state words through byte lookups and writes final state into table indices 256..308.
- `0x005694E0` **RigidBodyState** — Rigid-body contact-constraint response: computes the contact-motion component along the contact normal, evaluates an impulse-correction scalar from the world inertia tensor plus bias, and optionally writes the body-space contact offset.
- `0x00569DE0` **RigidBodyState** — Suspension-aware velocity-clamp integrator: clamps a velocity scale from reference displacement ratios, then Euler-advances linear position, linear velocity and angular momentum before running the inertia-tensor transform.
- `0x0056A150` **RigidBodyState** — Physics state-block copy: copies prediction-buffer blocks (position, orientation, velocity, angular momentum, references) into the working state region, then updates the world inverse inertia tensor and angular velocity.
- `0x0056EC00` **PhysicsBatchProcessor** — Three-pass batch processor: iterates three physics record arrays applying F_3x3MatrixVectorMultiply, F_3x3MatrixInverseCoordinateTransform and a per-element constraint-solve step, returning the third-pass count.
- `0x0056F020` **PhysicsBodyArray** — Fixed-stride body-array iterator: calls the per-body update routine on every 580-byte-strided element of the array at this+0x4 and returns the count re-read from this+0x0.
- `0x00583790` **PhysicsQueryState** — Producer-consumer physics/animation query getter: when the ready flag is set, clears it, emits a timestamp-delta value and the attached data pointer/size, and returns 1; otherwise returns 0.
- `0x0058F362` **PhysicsAllocatorNode** — Allocator-node teardown: releases all 43 stored sub-object pointer slots (offsets 0x00..0xA8) through the shared deallocation routine after a null guard.
- `0x005986CB` **PhysicsGlobalState** — One-expression shim forwarding the address of the module global unk_8D4370 to the lifecycle routine and returning its result.
- `0x005987AD` **PhysicsGlobalState** — One-expression shim forwarding the address of the module global unk_8D42D8 to the lifecycle routine and returning its result.
- `0x005997B7` **PhysicsGlobalState** — Ref-count-decrement wrapper: calls RefCountDecrementWithCleanup and returns its result; a deterministic read of global unk_8D4439 is recorded but not visible in the decompiled body.
- `0x0059A317` **PhysicsGlobalState** — Scalar-deleting destructor wrapper: back-shifts this by 4, runs a vtable setup subcall, conditionally frees the adjusted pointer, and returns it.

## Proposed classes

### RigidBodyState

Per-vehicle rigid-body physics state: world position, linear velocity, angular velocity, angular momentum, world inertia tensor, plus prediction and reference buffers used by the velocity-clamp integrator and state-block copy.

Methods: `0x005694E0`, `0x00569DE0`, `0x0056A150`

- `this+0x00000004` `float position_x` (read_write, DERIVED)
- `this+0x0000000C` `float position_y` (read_write, DERIVED)
- `this+0x00000014` `float position_z` (read_write, DERIVED)
- `this+0x00000064` `float linear_velocity_x` (read_write, DERIVED)
- `this+0x0000006C` `float linear_velocity_y` (read_write, DERIVED)
- `this+0x00000074` `float linear_velocity_z` (read_write, DERIVED)
- `this+0x0000007C` `float angular_velocity_x` (read_write, DERIVED)
- `this+0x00000084` `float angular_velocity_y` (read_write, DERIVED)
- `this+0x0000008C` `float angular_velocity_z` (read_write, DERIVED)
- `this+0x00000094` `float angular_momentum_x` (read_write, DERIVED)
- `this+0x0000009C` `float angular_momentum_y` (read_write, DERIVED)
- `this+0x000000A4` `float angular_momentum_z` (read_write, DERIVED)
- `this+0x000000AC` `float clamp_coefficient` (read, DERIVED)
- `this+0x000000B4` `float impulse_bias` (read, DERIVED)
- `this+0x000000BC` `float suspension_radius_a` (read, DERIVED)
- `this+0x000000C4` `float suspension_radius_b` (read, DERIVED)
- `this+0x000000CC` `float suspension_radius_c` (read, DERIVED)
- `this+0x000000EC` `float inertia_row0_col0` (read_write, DERIVED)
- `this+0x000000F4` `float inertia_row0_col1` (read_write, DERIVED)
- `this+0x000000FC` `float inertia_row0_col2` (read_write, DERIVED)
- `this+0x00000104` `float inertia_row1_col0` (read_write, DERIVED)
- `this+0x0000010C` `float inertia_row1_col1` (read_write, DERIVED)
- `this+0x00000114` `float inertia_row1_col2` (read_write, DERIVED)
- `this+0x0000011C` `float inertia_row2_col0` (read_write, DERIVED)
- `this+0x00000124` `float inertia_row2_col1` (read_write, DERIVED)
- `this+0x0000012C` `float inertia_row2_col2` (read_write, DERIVED)
- `this+0x00000134` `float current_position_x` (read, DERIVED)
- `this+0x0000013C` `float current_position_y` (read, DERIVED)
- `this+0x00000144` `float current_position_z` (read, DERIVED)
- `this+0x0000014C` `float secondary_position_x` (read, DERIVED)
- `this+0x00000154` `float secondary_position_y` (read, DERIVED)
- `this+0x0000015C` `float secondary_position_z` (read, DERIVED)
- `this+0x00000164` `float prediction_position_x` (read, DERIVED)
- `this+0x0000016C` `float prediction_position_y` (read, DERIVED)
- `this+0x00000174` `float prediction_position_z` (read, DERIVED)
- `this+0x000001C4` `float prediction_velocity_x` (read, DERIVED)
- `this+0x000001CC` `float prediction_velocity_y` (read, DERIVED)
- `this+0x000001D4` `float prediction_velocity_z` (read, DERIVED)
- `this+0x000001DC` `float prediction_angular_momentum_x` (read, DERIVED)
- `this+0x000001E4` `float prediction_angular_momentum_y` (read, GUESS)
- `this+0x000001EC` `float prediction_angular_momentum_z` (read, DERIVED)
- `this+0x000001F4` `float reference_position_x` (read, DERIVED)
- `this+0x000001FC` `float reference_position_y` (read, DERIVED)
- `this+0x00000204` `float reference_position_z` (read, GUESS)
- `this+0x0000020C` `float secondary_reference_x` (read, DERIVED)
- `this+0x00000214` `float secondary_reference_y` (read, DERIVED)
- `this+0x0000021C` `float secondary_reference_z` (read, DERIVED)

### CollisionContactManager

Owns the per-frame collision contact container (contact-array pointer, element count, base) and the contact-object reference; runs depth tests, fills contact entries and forwards them to the response stage.

Methods: `0x0054F2F0`

- `this+0x000001E0` `pointer contact_container` (read, DERIVED)
- `this+0x000001E4` `dword contact_array_count` (read, DERIVED)
- `this+0x000001E8` `pointer contact_array_base` (read, DERIVED)
- `this+0x00000204` `pointer contact_object` (read, GUESS)

### CollisionContactEntry

29-dword contact record written by collision detection: active flag, collision identifier, source, owner, loop index, triangle list, interpolated contact point, triangle world position and penetration distance, before forwarding.

Methods: 

- `*(this+0x1E8)+0x00000000` `dword active_flag` (write, DERIVED)
- `*(this+0x1E8)+0x00000018` `dword collision_identifier` (write, DERIVED)
- `*(this+0x1E8)+0x00000028` `pointer collision_source` (write, DERIVED)
- `*(this+0x1E8)+0x0000002C` `pointer owner_ptr` (write, DERIVED)
- `*(this+0x1E8)+0x00000030` `dword loop_index` (write, DERIVED)
- `*(this+0x1E8)+0x00000034` `pointer triangle_list` (write, DERIVED)
- `*(this+0x1E8)+0x00000038` `dword reserved_lerp` (write, DERIVED)
- `*(this+0x1E8)+0x0000003C` `float contact_point_x` (write, DERIVED)
- `*(this+0x1E8)+0x00000040` `float contact_point_y` (write, DERIVED)
- `*(this+0x1E8)+0x00000044` `float contact_point_z` (write, DERIVED)
- `*(this+0x1E8)+0x00000048` `float triangle_world_pos_x` (write, DERIVED)
- `*(this+0x1E8)+0x0000004C` `float triangle_world_pos_y` (write, DERIVED)
- `*(this+0x1E8)+0x00000050` `float triangle_world_pos_z` (write, DERIVED)
- `*(this+0x1E8)+0x00000058` `float penetration_distance` (write, DERIVED)
- `*(this+0x1E8)+0x0000005C` `dword trailing_contact_field_0` (write, GUESS)
- `*(this+0x1E8)+0x00000060` `dword trailing_contact_field_1` (write, GUESS)
- `*(this+0x1E8)+0x00000064` `dword trailing_contact_field_2` (write, GUESS)
- `*(this+0x1E8)+0x00000068` `dword trailing_contact_field_3` (write, GUESS)
- `*(this+0x1E8)+0x0000006C` `dword trailing_contact_field_4` (write, GUESS)
- `*(this+0x1E8)+0x00000070` `dword trailing_contact_field_5` (write, GUESS)

### TransformNodeBatchRenderer

Walks a linked list of transform nodes, culls faces by distance and plane-sign tests through the dword_8B8F24 service, and emits perspective-projected interpolated vertices into a bounded batch buffer.

Methods: `0x00561660`

- `this+0x00000004` `dword emitted_vertex_count` (read_write, DERIVED)
- `this+0x00000008` `pointer output_vertex_buffer` (read_write, DERIVED)
- `this+0x0000000C` `pointer camera_params` (read, GUESS)
- `this+0x00000018` `dword transform_world_base` (read, DERIVED)
- `this+0x00000020` `pointer batch_limits` (read, DERIVED)
- `*(this+0x8)+0x00000000` `float vertex_pos_x` (write, DERIVED)
- `*(this+0x8)+0x00000004` `float vertex_pos_y` (write, DERIVED)
- `*(this+0x8)+0x00000008` `float vertex_pos_z` (write, DERIVED)
- `*(this+0x8)+0x0000000C` `dword vertex_source_dword` (write, DERIVED)
- `*(this+0x8)+0x00000010` `float vertex_projected_x` (write, DERIVED)
- `*(this+0x8)+0x00000014` `float vertex_projected_y` (write, DERIVED)
- `*(this+0x20)+0x00000000` `dword batch_element_count` (read_write, DERIVED)
- `*(this+0x20)+0x00000004` `dword batch_face_index` (write, DERIVED)
- `*(this+0xC)+0x0000000C` `float near_plane` (read, DERIVED)
- `*(this+0xC)+0x00000010` `float screen_offset_x` (read, DERIVED)
- `*(this+0xC)+0x00000014` `float far_plane` (read, DERIVED)
- `*(this+0xC)+0x00000018` `float screen_offset_y` (read, DERIVED)
- `*(this+0xC)+0x00000024` `float camera_pos_x` (read, DERIVED)
- `*(this+0xC)+0x00000028` `float camera_pos_y` (read, DERIVED)
- `*(this+0xC)+0x0000002C` `float camera_pos_z` (read, DERIVED)
- `*(this+0xC)+0x00000054` `float reciprocal_factor_a` (read, GUESS)
- `*(this+0xC)+0x00000058` `float reciprocal_factor_b` (read, GUESS)

### PhysicsQueryState

Producer-consumer query state: a ready flag, previous timestamp, base value and attached data buffer/size consumed by the timestamp-delta getter.

Methods: `0x00583790`

- `this+0x0000000C` `byte ready_flag` (read_write, DERIVED)
- `this+0x00000010` `dword previous_timestamp` (read, DERIVED)
- `this+0x00000018` `dword base_value` (read, DERIVED)
- `this+0x00000020` `pointer attached_data_buffer` (read, DERIVED)
- `this+0x00000120` `dword attached_data_size` (read, DERIVED)

### PhysicsAllocatorNode

Allocation node holding 43 sub-object pointer slots (offsets 0x00..0xA8); its destructor releases each stored pointer through a shared deallocation routine.

Methods: `0x0058F362`

- `this+0x00000000` `pointer sub_object_slot_00` (read, DERIVED)
- `this+0x00000004` `pointer sub_object_slot_01` (read, DERIVED)
- `this+0x00000008` `pointer sub_object_slot_02` (read, DERIVED)
- `this+0x0000000C` `pointer sub_object_slot_03` (read, DERIVED)
- `this+0x00000010` `pointer sub_object_slot_04` (read, DERIVED)
- `this+0x00000014` `pointer sub_object_slot_05` (read, DERIVED)
- `this+0x00000018` `pointer sub_object_slot_06` (read, DERIVED)
- `this+0x0000001C` `pointer sub_object_slot_07` (read, DERIVED)
- `this+0x00000020` `pointer sub_object_slot_08` (read, DERIVED)
- `this+0x00000024` `pointer sub_object_slot_09` (read, DERIVED)
- `this+0x00000028` `pointer sub_object_slot_10` (read, DERIVED)
- `this+0x0000002C` `pointer sub_object_slot_11` (read, DERIVED)
- `this+0x00000030` `pointer sub_object_slot_12` (read, DERIVED)
- `this+0x00000034` `pointer sub_object_slot_13` (read, DERIVED)
- `this+0x00000038` `pointer sub_object_slot_14` (read, DERIVED)
- `this+0x0000003C` `pointer sub_object_slot_15` (read, DERIVED)
- `this+0x00000040` `pointer sub_object_slot_16` (read, DERIVED)
- `this+0x00000044` `pointer sub_object_slot_17` (read, DERIVED)
- `this+0x00000048` `pointer sub_object_slot_18` (read, DERIVED)
- `this+0x0000004C` `pointer sub_object_slot_19` (read, DERIVED)
- `this+0x00000050` `pointer sub_object_slot_20` (read, DERIVED)
- `this+0x00000054` `pointer sub_object_slot_21` (read, DERIVED)
- `this+0x00000058` `pointer sub_object_slot_22` (read, DERIVED)
- `this+0x0000005C` `pointer sub_object_slot_23` (read, DERIVED)
- `this+0x00000060` `pointer sub_object_slot_24` (read, DERIVED)
- `this+0x00000064` `pointer sub_object_slot_25` (read, DERIVED)
- `this+0x00000068` `pointer sub_object_slot_26` (read, DERIVED)
- `this+0x0000006C` `pointer sub_object_slot_27` (read, DERIVED)
- `this+0x00000070` `pointer sub_object_slot_28` (read, DERIVED)
- `this+0x00000074` `pointer sub_object_slot_29` (read, DERIVED)
- `this+0x00000078` `pointer sub_object_slot_30` (read, DERIVED)
- `this+0x0000007C` `pointer sub_object_slot_31` (read, DERIVED)
- `this+0x00000080` `pointer sub_object_slot_32` (read, DERIVED)
- `this+0x00000084` `pointer sub_object_slot_33` (read, DERIVED)
- `this+0x00000088` `pointer sub_object_slot_34` (read, DERIVED)
- `this+0x0000008C` `pointer sub_object_slot_35` (read, DERIVED)
- `this+0x00000090` `pointer sub_object_slot_36` (read, DERIVED)
- `this+0x00000094` `pointer sub_object_slot_37` (read, DERIVED)
- `this+0x00000098` `pointer sub_object_slot_38` (read, DERIVED)
- `this+0x0000009C` `pointer sub_object_slot_39` (read, DERIVED)
- `this+0x000000A0` `pointer sub_object_slot_40` (read, DERIVED)
- `this+0x000000A4` `pointer sub_object_slot_41` (read, DERIVED)
- `this+0x000000A8` `pointer sub_object_slot_42` (read, DERIVED)

### PhysicsBodyArray

Container of a 580-byte-strided physics-body array; iterates every element and dispatches the per-body update routine.

Methods: `0x0056F020`

- `this+0x00000000` `dword element_count` (read, DERIVED)
- `this+0x00000004` `pointer array_base` (read, DERIVED)

### PhysicsBatchProcessor

Three-pass batch processor over three physics record arrays, applying matrix-vector multiply, inverse coordinate transform and a per-element constraint-solve step on each record.

Methods: `0x0056EC00`

- `this+0x00000008` `dword pass1_count` (read, DERIVED)
- `this+0x0000000C` `pointer pass1_array_base` (read, DERIVED)
- `this+0x00000010` `dword pass2_count` (read, DERIVED)
- `this+0x00000014` `pointer pass2_array_base` (read, DERIVED)
- `this+0x00000018` `dword pass3_count` (read, DERIVED)
- `this+0x0000001C` `pointer pass3_array_base` (read, DERIVED)

### PhysicsGlobalState

Access to and lifecycle of module-global physics singleton objects (unk_8D42D8, unk_8D4370, unk_8D4439) and the polarity flag inside dword_8D46B4; includes lifecycle shims, a ref-count wrapper, a sign helper and a generic scalar-deleting destructor wrapper.

Methods: `0x00563F70`, `0x005986CB`, `0x005987AD`, `0x005997B7`, `0x0059A317`


### IndexedTransformTable

Indexed lookup table of transform entries: bounds-checked by element count, each 36-byte entry carries three 16-bit sub-indices resolving into a 48-byte-stride transform array.

Methods: `0x0054E1A0`

- `this+0x00000120` `dword element_count` (read, DERIVED)
- `this+0x00000124` `pointer entry_table_base` (read, DERIVED)

### StreamCipherTransform

Sixteen-round substitution-table stream transform over a caller-owned table buffer; mixes two state words through byte lookups and stores state at table indices 256..308.

Methods: `0x00564DD0`


## Compatibility contracts

- **CollisionContactPipeline** — The scene batch render check (0x0054F5C0) invokes collision contact detection (0x0054F2F0) every frame. Detected contacts are written to the contact array at *(this+0x1E8) as 29-dword entries (active flag, identifier, source, owner, index, triangle list, contact point, world position, penetration), and each completed entry is forwarded to the response stage through SingleFunctionCallWrapper (0x00559A30). A replacement must preserve the entry stride and the active-flag retire sentinel value 6.
- **RigidBodyIntegrationTick** — SuspensionStateIntegratorWithVelocityClamp (0x00569DE0) must be invoked per frame with a scalar timestep by the vehicle integrator (0x00459AE0) and by 0x0056F090; it advances position (this+4/0xC/0x14), linear velocity (this+0x64/0x6C/0x74) and angular momentum (this+0x94/0x9C/0xA4) and runs the world inertia-tensor transform (0x005692A0).
- **PhysicsQueryGetterContract** — A producer writes a ready flag (this+0xC), previous timestamp (this+0x10), base value (this+0x18) and attached data size (this+0x120). The getter 0x00583790 returns 1 and emits the timestamp-delta value and the data pointer/size, or 0 when not ready. A clear flag must be treated as no-data.
- **PhysicsAllocatorNodeLifecycle** — The allocator init counterpart (0x0058EF83) allocates a 43-slot node whose teardown (0x0058F362) releases every stored sub-object pointer through the shared deallocation routine 0x0058AA6F. The teardown is invoked on the init counterpart; a replacement must preserve the 43-slot layout (0x00..0xA8) and the per-slot release contract.
- **BatchedPhysicsBodyProcessing** — WheelDataCopy (0x004414D0) drives per-body updates through 0x0056F020 over a fixed 580-byte-stride body array. Separately, 0x0056ECF0 drives 0x0056EC00, which applies F_3x3MatrixVectorMultiply (0x0056CF70), F_3x3MatrixInverseCoordinateTransform (0x0056D020) and a per-element constraint solve (0x0056D2D0) to the three record arrays each tick and returns the third-pass count.

## Unresolved

- Offset collision on the shared 'this' base: several receiver objects are unrelated yet reuse equal byte offsets (0x04, 0x0C, 0x14, 0x18, 0x1C, 0x20, 0x64, 0x94, 0xA4, 0x1E4, 0x204). Per the rule against merging equal offsets, each offset is attributed to a single class; the same field token legitimately also appears in the losing class's field evidence because the validator requires per-field matching refs. No common ownership is proven.
- CollisionContactManager reads attributed to this+0x2EC, this+0x2F0 and this+0x2F4 have no visible expression in the raw decompiled source; they are retained only in unresolved_evidence_refs.
- CollisionContactEntry trailing fields at 0x5C..0x70 have no explicit write in the raw source text; their names are placeholders.
- TransformNodeBatchRenderer reads the float globals 0x59E43C, 0x59E440, 0x59E448 and 0x59E5FC (materialized FP constants) whose exact values and operations are not evidenced.
- SuspensionStateIntegratorWithVelocityClamp reads the float globals 0x59E420, 0x59E880, 0x59EB50 and 0x5B89B8 which appear nowhere in the raw decompiled source.
- PhysicsSignDirectionFunction (0x00563F70) makes two AudioMixerSampleGetWithFallback calls with unused results (likely decompiler artifact); v2 = a1 - a1 is a zeroed quantity, so the value whose sign is tested is not evident from the packet.
- The D3D device vtable call targets behind dword_8B8F24 (vtable+4 and vtable+32) are indirect; the concrete distance/depth and transform routines are not evidenced.
- PhysicsGlobalState is a GUESS grouping: 0x0059A317 is a generic scalar-deleting destructor wrapper whose owning class is unconfirmed, and the allocator-node and RC4KeyScheduleInitialization names are skeleton-fill labels, not confirmed classes.
- ReadIndexedTransformVectors (0x0054E1A0) semantics (suggested bone/transform lookup for AnimationPlaybackSequence) and the layout of the 36-byte entry and 48-byte-stride transform element are unconfirmed.
- Where the world-space inverse inertia tensor produced by F_3x3InertiaTensorTransform is stored is not established by this packet.
- RigidBodyState prediction-buffer vs working-state roles (block copies in 0x0056A150, staging qmemcpy of this+28 from this+380 in 0x00569DE0) are inferred from block sizes only; the 0x17C orientation block and staging region are not in the packet field table.
- The identity of the cipher behind TableDrivenStreamTransform and the role of its a2/a3 inputs relative to the caller are unverified.
- PhysicsAllocatorNode slots are visited in a fixed order that differs from array order; whether the order is semantically meaningful is unknown.
- The a4 parameter of CollisionContactDetection (0x0054F2F0) is declared but never read.
- PhysicsGlobalState's module-global objects (unk_8D42D8, unk_8D4370, unk_8D4439, dword_8D46B4) are represented as class evidence only; no per-offset field entries are asserted because the required evidence-ref format for a global base is not present in the allowed list.
