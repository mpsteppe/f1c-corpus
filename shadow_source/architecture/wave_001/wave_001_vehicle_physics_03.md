# VehiclePhysics

Scope: `vehicle_physics`  
Trust: `DERIVED`

Reconstructs the vehicle physics subsystem from 15 validated functions sharing a single 'this'-base object (VehiclePhysicsObject). The object carries default-initialized suspension/contact constants (0x0..0x144), a 74-float-stride wheel-state block at 0xD4, respawn/reset/collision-zone state (0x828..0x990), audio playback sub-slots, per-frame integration fields (0x3498..0x34AC), a 3x3 orientation matrix plus world position (0x34B0..0x34DC), a camera/rendering snapshot block, rigid-body point transforms, and collision damage-feedback thresholds. Behavior is split between respawn/reset drivers (0x4E0800, 0x4E09E0), per-frame step configuration (0x4E45B0), force/torque solving over four wheels (0x4E5470), lock-guarded physics-node propagation (0x4E4910), per-frame setup snapshots (0x4E49B0), vehicle audio config loading (0x4E3360), and collision spark/damage feedback (0x4EC1A0), supported by shared helper services (tire-brush solver, HDV parser, audio-stream record parser, transform math, lifecycle reset, collision feedback, memory).

## Function roles

- `0x004D68A0` **VehiclePhysicsObject** — Default-initializer for the unnamed vehicle physics-state object: writes 82 DWORD literals into this[0..81] (offsets 0x0..0x144) - -1/0 sentinel slots at 0x130..0x144 followed by contact/geometry, suspension/strut and scalar/vector default constant blocks. No reads, globals, branches or calls. Invoked once by TireBrandFileParser.
- `0x004D6AE0` **VehiclePhysicsObject** — Temperature-scaled suspension force helper: force = (this+0x118 + 273.16) * a2 * 0.002778858444950814 * (this+0x38) + (this+0x40). Reads the Kelvin-conversion term, an input factor and two field scalars; returns the computed force.
- `0x004E0800` **VehiclePhysicsObject** — Vehicle respawn / race-restart state reset: clears the respawn marker byte, runs a conditional aux reset (sub_5506A0) on a prior-collision flag, computes a random respawn delay from the rotating noise table, re-initializes substructures (MultiSystemStructInitializer, optional StateArrayReset), writes a progress-bar event when the base object is not in an active race, resets audio/sound state and scale propagation, zeroes collision force/torque accumulators, writes sentinel IDs, computes a speed scale, dispatches per-contact-zone resets and clears pending-cleanup entries.
- `0x004E09E0` **VehiclePhysicsObject** — Full vehicle state reset/destructor path: conditional multi-system re-init, 3D sound-source destruction and collision-status copy from the geometry object; zeroes timer/counter/wheel/sensor/audio field runs; runs embedded-array init/destructor loops (4x stride-296, 17-element and 68-byte loops, 11x stride-748 dual-array destructors); frees and nulls the pointer slot at this+0x2BD4 and returns the freed pointer.
- `0x004E23D0` **VehiclePhysicsObject** — 3x3 rotation-plus-translation transform: copies rotation angles to this+0x14..0x1C, a 0x24-byte 3x3 rotation matrix to this+0x20..0x40, and the translation vector to this+0x54..0x5C; computes matrix * (this+0x48..0x50) + translation into this+0x8/0xC/0x10 and returns a pointer to that result.
- `0x004E24A0` **VehiclePhysicsObject** — Per-wheel suspension parameter update (wheel index a2, 74-float per-wheel stride): computes ride-height offset v5 = a3 - this+0x4C, stores it into two per-wheel slots, computes the new damper angle a5 + stored angle, stores the steering angle; only on an actual damper-angle change saves the angle and rebuilds the 3x3 rotation matrix via F_33RotationMatrixFromEulerAngles; copies a 0x24-byte wheel-state block and returns the Y-axis Euler extraction of the steering orientation.
- `0x004E3360` **VehiclePhysicsObject** — Vehicle audio/sound configuration loader: resolves the vehicle name from the vehicle-database array, parses its .hdv file, opens the audio stream, reads restriction-sphere and force-field-sphere records (counting and allocating per-record slots), initializes per-vehicle audio playback sub-slots (base slot, two conditional slots, 8 stride-68 group entries) via sub_4DE610, then frees scratch allocations and returns the leftover pointer.
- `0x004E4570` **VehiclePhysicsObject** — Cleanup/destructor sequence: calls sub_4E4790(this), runs DualArrayDestructorLoopFree on the dual-array storage at this+441, then returns the result of a thunk dispatch on (this+2).
- `0x004E45B0` **VehiclePhysicsObject** — Per-frame vehicle physics configuration and one integration step: calls sub_4E4790, gates on a mode flag at this+0x32BC (0 = one-time TireModelInit into dbl_7C7428; 1..3 = step; else early return), parses the vehicle HDV file twice, clamps the integration sub-step count at this+0x3498 to [1,64], derives four step-size fields, runs SuspensionAndWheelPhysics and TireBrushModelForceSolver, frees temp allocations and returns the leftover pointer.
- `0x004E4910` **VehiclePhysicsObject** — Thin lock-guarded wrapper around the tire-brush solver and physics-node propagation: acquires TireBrushModelForceSolver(1), runs PhysicsNodePropagationWithDistanceFalloff over the node set dword_5EA2C0, releases TireBrushModelForceSolver(0), returns the solver result.
- `0x004E49B0` **VehiclePhysicsObject** — Per-frame setup/rendering snapshot copy from global physics state: steering-geometry result via TransformApply3D, 3x3 orientation matrix copy, gimbal-lock-guarded pitch/roll atan2, world position copy, camera-projection rows, a 4-entry per-corner camera-data copy, mode-selected suspension-ride-height average, camera scale/offset calculations; returns the physics-global base pointer.
- `0x004E5470` **VehiclePhysicsObject** — Per-frame suspension force/torque computation over all 4 wheels (stride 62 floats): transforms per-wheel vectors through the wheel-space rotation matrix plus world offset, computes steer cross products and cos/sin of the steering-angle product, runs TireContactForceComputation and WheelSpringDamperForceAndSteering per wheel, applies body-roll torque redistribution gated on a matrix element > 0.7, damps per-wheel values and accumulates forces/torques back into per-wheel slots.
- `0x004E9BD0` **VehiclePhysicsObject** — Rigid-body point transform: transforms the local offset vector at this+0x3B54..0x3B5C by the 3x3 rotation matrix at this+0x34B0, adds the body world position at this+0x34D4..0x34DC, stores the world-space result at this+0x3B60/0x3B64/0x3B68.
- `0x004EC1A0` **VehiclePhysicsObject** — Per-frame collision visual/damage feedback: gated by vehicle identity vs dword_7C54E8 and restricted-mode/race-phase guards, scales the impact impulse, fires spark/damage events into a ring buffer (ProgressBarEventEncode + StateTransition), runs two body-zone repair-service blocks, an 8-zone body loop and a 4-zone wheel loop with RepairServiceStateDispatcher/ShortComputation_1330, applies steering-geometry deformation and tire-scrub reset on severe impacts.
- `0x004EF6C0` **VehiclePhysicsObject** — Coordinate transform with offset: builds a 3x3 rotation matrix from Euler input a3, computes the ride-height delta 3-vector, rotates it by the matrix, adds the position offset at this+0x34D4..0x34DC, and writes into a4 the difference between (a2 + position offset) and the transformed vector.

## Proposed classes

### VehiclePhysicsObject

Per-vehicle physics and state object: default-initialized contact/geometry and suspension/strut constant block (0x0..0x144), 74-float-stride wheel-state block based at 0xD4, collision/respawn/reset state (0x828..0x990), audio playback sub-slots (0x5E4..0x6AD, count at 0xBA8), body/wheel collision-zone gating (0xCC8..0xD90), pointer slot pair at 0x2BD0, per-frame integration fields (0x3498..0x34AC), 3x3 orientation matrix + world position (0x34B0..0x34DC), camera/rendering snapshot block (0x3510..0x39F0), rigid-body contact point transform (0x3B54..0x3B68), and collision damage-feedback thresholds (0x3D48..0x3EB8).

Methods: `0x004D68A0`, `0x004D6AE0`, `0x004E0800`, `0x004E09E0`, `0x004E23D0`, `0x004E24A0`, `0x004E3360`, `0x004E4570`, `0x004E45B0`, `0x004E4910`, `0x004E49B0`, `0x004E5470`, `0x004E9BD0`, `0x004EC1A0`, `0x004EF6C0`

- `this+0x00000008` `float transform_result_x` (write, DERIVED)
- `this+0x0000000C` `float transform_result_y` (write, DERIVED)
- `this+0x00000010` `float transform_result_z` (write, DERIVED)
- `this+0x00000014` `float rotation_angle_0` (write, GUESS)
- `this+0x00000018` `float rotation_angle_1` (write, GUESS)
- `this+0x0000001C` `float rotation_angle_2` (write, GUESS)
- `this+0x00000020` `float rotation_matrix_3x3_block` (write, DERIVED)
- `this+0x00000048` `float transform_input_vector` (read, DERIVED)
- `this+0x0000004C` `float chassis_reference_height` (read, DERIVED)
- `this+0x00000054` `float translation_vector` (write, DERIVED)
- `this+0x00000038` `float suspension_force_scale` (read, GUESS)
- `this+0x00000040` `float suspension_force_addend` (read, GUESS)
- `this+0x000000D4` `float wheel_state_block_base` (read_write, DERIVED)
- `this+0x00000118` `float temperature_kelvin_input` (read, GUESS)
- `this+0x00000130` `dword sentinel_slot_0` (write, GUESS)
- `this+0x00000134` `dword sentinel_slot_1` (write, GUESS)
- `this+0x00000138` `dword sentinel_slot_2` (write, GUESS)
- `this+0x0000013C` `dword sentinel_slot_3` (write, GUESS)
- `this+0x00000140` `dword sentinel_slot_4` (write, GUESS)
- `this+0x00000144` `dword sentinel_slot_5` (write, GUESS)
- `this+0x000005E4` `pointer audio_subslot_2_ptr` (read, GUESS)
- `this+0x00000628` `pointer audio_subslot_3_ptr` (read, GUESS)
- `this+0x00000624` `byte audio_subslot_2_enable_0` (read, GUESS)
- `this+0x00000625` `byte audio_subslot_2_enable_1` (read, GUESS)
- `this+0x00000668` `byte audio_group_entries_base` (read, GUESS)
- `this+0x00000669` `byte audio_group_entry_enable_0` (read, GUESS)
- `this+0x0000066C` `byte audio_group_entry_enable_1` (read, GUESS)
- `this+0x000006AC` `byte audio_group_entry_enable_2` (read, GUESS)
- `this+0x000006AD` `byte audio_group_entry_enable_3` (read, GUESS)
- `this+0x00000BA8` `dword active_audio_subslot_count` (read_write, DERIVED)
- `this+0x00000828` `dword wheel_zone_gate_dword` (read, GUESS)
- `this+0x00000868` `byte wheel_zone_gate_byte` (read, GUESS)
- `this+0x00000CC8` `dword body_zone_a_gate_dword` (read, GUESS)
- `this+0x00000D08` `byte body_zone_a_gate_byte` (read, GUESS)
- `this+0x00000D0C` `dword body_zone_b_gate_dword` (read, GUESS)
- `this+0x00000D4C` `byte body_zone_b_gate_byte` (read, GUESS)
- `this+0x00000D50` `dword body_zone_loop_gate_dword` (read, GUESS)
- `this+0x00000D90` `byte body_zone_loop_gate_byte` (read, GUESS)
- `this+0x00000898` `dword contact_zone_dispatch_enable` (read, DERIVED)
- `this+0x000008A4` `byte prior_collision_flag` (read, GUESS)
- `this+0x000008B4` `dword contact_zone_count` (read, GUESS)
- `this+0x000008B8` `pointer contact_zone_handle` (read, GUESS)
- `this+0x000008C4` `pointer contact_zone_params` (read, GUESS)
- `this+0x0000094C` `float respawn_delay` (write, DERIVED)
- `this+0x00000964` `pointer audio_handle` (read, GUESS)
- `this+0x0000096C` `byte respawn_audio_flag_0` (write, GUESS)
- `this+0x0000096D` `byte respawn_audio_flag_1` (write, GUESS)
- `this+0x00000974` `byte respawn_marker_byte` (write, GUESS)
- `this+0x00000934` `float collision_force_torque_accum_0` (write, DERIVED)
- `this+0x00000938` `float collision_force_torque_accum_1` (write, DERIVED)
- `this+0x0000093C` `float collision_force_torque_accum_2` (write, DERIVED)
- `this+0x00000940` `float collision_force_torque_accum_3` (write, DERIVED)
- `this+0x00000944` `float collision_force_torque_accum_4` (write, DERIVED)
- `this+0x00000948` `float collision_force_torque_accum_5` (write, DERIVED)
- `this+0x00000979` `byte post_audio_clear_byte` (write, GUESS)
- `this+0x00000980` `dword sentinel_id_minus1` (write, DERIVED)
- `this+0x00000984` `dword sentinel_id_minus8388609` (write, DERIVED)
- `this+0x00000988` `float speed_scale` (write, DERIVED)
- `this+0x0000098C` `byte pending_cleanup_byte` (read_write, GUESS)
- `this+0x00000990` `bytearray pending_cleanup_entries_base` (write, GUESS)
- `this+0x00002BD0` `pointer object_ptr_slot` (write, DERIVED)
- `this+0x00002BD4` `pointer freed_object_ptr` (read_write, DERIVED)
- `this+0x000032BC` `dword restricted_mode_flag` (read_write, DERIVED)
- `this+0x00003440` `byte race_phase_byte_gate` (read, GUESS)
- `this+0x00003498` `dword integration_substep_count` (write, DERIVED)
- `this+0x0000349C` `float step_size_squared_input` (write, DERIVED)
- `this+0x000034A0` `float step_size_1_over_40n` (write, DERIVED)
- `this+0x000034A4` `float step_size_1_over_8_5n5` (write, DERIVED)
- `this+0x000034A8` `float step_size_copy` (write, DERIVED)
- `this+0x000034AC` `float session_race_time` (read_write, DERIVED)
- `this+0x000034B0` `float orientation_matrix_0` (read_write, DERIVED)
- `this+0x000034B4` `float orientation_matrix_1` (read_write, DERIVED)
- `this+0x000034B8` `float orientation_matrix_2` (read_write, DERIVED)
- `this+0x000034BC` `float orientation_matrix_3` (read_write, DERIVED)
- `this+0x000034C0` `float orientation_matrix_4` (read_write, DERIVED)
- `this+0x000034C4` `float orientation_matrix_5` (read_write, DERIVED)
- `this+0x000034C8` `float orientation_matrix_6` (read_write, DERIVED)
- `this+0x000034CC` `float orientation_matrix_7` (read_write, DERIVED)
- `this+0x000034D0` `float orientation_matrix_8` (read_write, DERIVED)
- `this+0x000034D4` `float world_position_0` (read_write, DERIVED)
- `this+0x000034D8` `float world_position_1` (read_write, DERIVED)
- `this+0x000034DC` `float world_position_2` (read_write, DERIVED)
- `this+0x000034E0` `float negated_m21` (write, DERIVED)
- `this+0x000034E4` `float pitch_angle` (write, DERIVED)
- `this+0x000034E8` `float roll_angle` (write, DERIVED)
- `this+0x000034EC` `float setup_world_position_0` (write, DERIVED)
- `this+0x000034F0` `float setup_world_position_1` (write, DERIVED)
- `this+0x000034F4` `float setup_world_position_2` (write, DERIVED)
- `this+0x000034F8` `float dot_product_row_0` (write, DERIVED)
- `this+0x000034FC` `float dot_product_row_1` (write, DERIVED)
- `this+0x00003500` `float dot_product_row_2` (write, DERIVED)
- `this+0x00003504` `float camera_vector_0` (write, DERIVED)
- `this+0x00003508` `float camera_vector_1` (write, DERIVED)
- `this+0x0000350C` `float camera_vector_2` (write, DERIVED)
- `this+0x00003510` `float camera_scalar_input` (read, GUESS)
- `this+0x00003514` `float camera_scale_composite` (write, DERIVED)
- `this+0x00003518` `float camera_scale_inverse` (write, DERIVED)
- `this+0x00003534` `float camera_dot_row_0` (write, DERIVED)
- `this+0x00003538` `float camera_dot_row_1` (write, DERIVED)
- `this+0x0000353C` `float camera_dot_row_2` (write, DERIVED)
- `this+0x00003540` `float camera_transform_row_0` (write, DERIVED)
- `this+0x00003544` `float camera_transform_row_1` (write, DERIVED)
- `this+0x00003548` `float camera_transform_row_2` (write, DERIVED)
- `this+0x0000354C` `float accumulated_force_torque_0` (read_write, DERIVED)
- `this+0x00003550` `float accumulated_force_torque_1` (read_write, DERIVED)
- `this+0x00003554` `float accumulated_force_torque_2` (read_write, DERIVED)
- `this+0x00003558` `float accumulated_force_torque_3` (read_write, DERIVED)
- `this+0x0000355C` `float accumulated_force_torque_4` (read_write, DERIVED)
- `this+0x00003560` `float accumulated_force_torque_5` (read_write, DERIVED)
- `this+0x00003570` `float camera_value_0` (write, GUESS)
- `this+0x00003574` `float camera_product` (write, GUESS)
- `this+0x00003578` `float camera_value_1` (write, GUESS)
- `this+0x00003588` `float wheel_transform_slot_0` (write, DERIVED)
- `this+0x0000358C` `float wheel_transform_slot_1` (write, DERIVED)
- `this+0x00003590` `float wheel_transform_slot_2` (write, DERIVED)
- `this+0x00003594` `float wheel_transform_slot_3` (write, DERIVED)
- `this+0x00003598` `float wheel_transform_slot_4` (write, DERIVED)
- `this+0x0000359C` `float wheel_transform_slot_5` (write, DERIVED)
- `this+0x000035A0` `float wheel_transform_slot_6` (write, DERIVED)
- `this+0x000035A8` `float steer_angle_product` (write, DERIVED)
- `this+0x000035B0` `float per_corner_camera_base_0` (write, DERIVED)
- `this+0x000036A8` `float per_corner_camera_base_1` (write, DERIVED)
- `this+0x000037A0` `float per_corner_camera_base_2` (write, DERIVED)
- `this+0x00003898` `float per_corner_camera_base_3` (write, DERIVED)
- `this+0x000035C4` `float per_wheel_damper_force` (read_write, DERIVED)
- `this+0x000035E0` `float wheel_transform_input_2` (read, GUESS)
- `this+0x000035F4` `float per_wheel_damper_term` (read, GUESS)
- `this+0x00003600` `float per_wheel_multiplier` (read, GUESS)
- `this+0x0000363C` `float steer_cos` (write, DERIVED)
- `this+0x00003640` `float steer_sin` (write, DERIVED)
- `this+0x00003734` `float steer_cos_copy` (write, DERIVED)
- `this+0x00003738` `float steer_sin_copy` (write, DERIVED)
- `this+0x000036A0` `float steer_angle_product_copy` (write, DERIVED)
- `this+0x00003960` `float steer_angle_term` (read, GUESS)
- `this+0x00003964` `float suspension_ride_height_average` (write, DERIVED)
- `this+0x00003974` `float roll_redistribution_scale` (read, GUESS)
- `this+0x00003978` `float camera_value_2` (write, GUESS)
- `this+0x00003994` `float camera_clamped_value` (write, GUESS)
- `this+0x000039B4` `dword suspension_average_mode` (read_write, DERIVED)
- `this+0x000039F0` `dword camera_global_copy` (write, GUESS)
- `this+0x00003B54` `float rigid_body_local_offset_0` (read, DERIVED)
- `this+0x00003B58` `float rigid_body_local_offset_1` (read, DERIVED)
- `this+0x00003B5C` `float rigid_body_local_offset_2` (read, DERIVED)
- `this+0x00003B60` `float rigid_body_world_point_0` (write, DERIVED)
- `this+0x00003B64` `float rigid_body_world_point_1` (write, DERIVED)
- `this+0x00003B68` `float rigid_body_world_point_2` (write, DERIVED)
- `this+0x00003D48` `float camera_collision_value_0` (write, GUESS)
- `this+0x00003D4C` `float camera_collision_value_1` (write, GUESS)
- `this+0x00003D50` `float camera_collision_value_2` (write, GUESS)
- `this+0x00003D64` `float sign_flip_value` (write, GUESS)
- `this+0x00003D78` `float impact_ramp_addend` (read, GUESS)
- `this+0x00003D7C` `float impact_ramp_scale` (read, GUESS)
- `this+0x00003D80` `float impact_clamp` (read, GUESS)
- `this+0x00003D84` `float tire_scrub_force_threshold` (read, GUESS)
- `this+0x00003D88` `float damage_scale` (read, GUESS)
- `this+0x00003D8C` `float damage_threshold` (read, GUESS)
- `this+0x00003D90` `float spark_scale` (read, GUESS)
- `this+0x00003D94` `float body_zone_a_force_threshold` (read, GUESS)
- `this+0x00003D98` `float body_zone_a_random_threshold` (read, GUESS)
- `this+0x00003D9C` `float body_zone_a_ref_0` (read, GUESS)
- `this+0x00003DA0` `float body_zone_a_ref_1` (read, GUESS)
- `this+0x00003DA4` `float body_zone_a_ref_2` (read, GUESS)
- `this+0x00003DC4` `float body_zone_b_force_threshold` (read, GUESS)
- `this+0x00003DC8` `float body_zone_b_random_threshold` (read, GUESS)
- `this+0x00003DCC` `float body_zone_b_ref_0` (read, GUESS)
- `this+0x00003DD0` `float body_zone_b_ref_1` (read, GUESS)
- `this+0x00003DD4` `float body_zone_b_ref_2` (read, GUESS)
- `this+0x00003DF4` `float wheel_zone_force_band_lo` (read, GUESS)
- `this+0x00003DF8` `float wheel_zone_force_band_hi` (read, GUESS)
- `this+0x00003DFC` `float wheel_zone_random_threshold` (read, GUESS)
- `this+0x00003E90` `float body_zone_force_threshold` (read, GUESS)
- `this+0x00003EB4` `float body_zone_anchor_0` (read, GUESS)
- `this+0x00003EB8` `float body_zone_anchor_1` (read, GUESS)

## Compatibility contracts

- **VehiclePhysicsObjectLayout** — A replacement executable must preserve the vehicle physics-state layout: wheel-state block with 74-float (296-byte) stride based at this+0xD4, 3x3 orientation matrix at 0x34B0..0x34D0, world position at 0x34D4..0x34DC, integration fields at 0x3498..0x34AC, and the 0x3D48..0x3EB8 collision feedback threshold block.
- **TireBrushModelLockProtocol** — Callers of the tire-brush solver must bracket work with TireBrushModelForceSolver(1) to acquire and TireBrushModelForceSolver(0) to release; the physics step and the collision wrapper both follow this protocol.
- **IntegrationSubstepClamp** — The integration sub-step count stored at this+0x3498 must be clamped to [1,64]; step-size fields derive as 1.0/(40*v6) and 1.0/(8*(5*v6+5)) and this+0x34AC mirrors the global race-time double.
- **PhysicsGlobalStateBlocks** — Per-frame setup reads global physics state: dword_7C8A18 (physics base; +28 orientation, +100 world position), dword_7C7918 (per-corner camera copy source), dbl_7C7428 (shared tire-model buffer), dword_5EA2C0 (physics node set), and the rotating noise table dword_8AAE70/flt_8AAE74 for randomized delays and damage draws.
- **SuspensionForceFormula** — The temperature-scaled suspension force is computed as (temperature_term + 273.16) * input_factor * 0.002778858444950814 * scale + addend; a replacement must reproduce this arithmetic.
- **CollisionFeedbackRingBuffer** — Collision spark/damage events are encoded into a 432-byte-strided ring buffer: dword_83EE60 counts live slots (cap 1023), dword_8AAE64 is the advancing slot base, ProgressBarEventEncode writes the slot header and direction bytes at slot+8..+14.

## Unresolved

- Owner identity of the 'this' base across all 15 functions is inferred to be a single VehiclePhysicsObject from overlapping field evidence (orientation/world block 0x34B0..0x34DC shared by 0x4E49B0/0x4E5470/0x4E9BD0/0x4EC1A0/0x4EF6C0; wheel-state 74-float stride base 0xD4 shared by 0x4E24A0 and the 0x4E09E0 InitWithDualCall loop; init/reset overlap at 0x48..0x8C). The packet does not prove common ownership; audio config (0x5E4..0x6AD + 0xBA8), body collision zones (0xCC8..0xD90) and the camera snapshot block (0x3510..0x39F0) may be separate sub-objects.
- The 82 DWORD literals written by the initializer (0x0..0x144) are not individually interpreted; the float meanings (contact/geometry, suspension/strut constants, scalar/vector defaults) are DERIVED prose, not packet evidence. Only the sentinel slots and transform-related early fields are modeled as named fields.
- Per-wheel relative offsets inside the 74-float stride block (slots +53/+83/+100/+103/+104/+115/+116/+128/+140/+208) and the per-wheel bases in 0x4E5470 (float indices 3424/3429/3458/3480) are not packet fields; they are inferred from the raw source and preserved only as prose.
- The 'obj'-base fields (0x32C8, 0x4894, 0x4898) belong to a caller-side base-object view (base-object counter, collision status, vehicle database slot). Identity of that base with the 'this' base is not established; they are not merged into VehiclePhysicsObject.
- Read-only constant globals in the 0x59E4xx/0x5AD1xx ranges have no visible use in the decompiled bodies; they are likely tuning constants consumed by the called force/math routines, or .rdata slots backing double literals (e.g. 273.16, 0.002778858444950814). They are preserved in unresolved_evidence_refs.
- Several per-frame setup fields (camera transform 0x3534..0x3548, dot rows 0x34F8..0x3500, 0x3D48..0x3D64) have no semantic names in the packet and are left as offsets with GUESS names.
- unresolved_evidence_refs below preserves every required material ref not otherwise modeled in the architecture (remaining per-offset fields of the 0x0..0x144 initializer block and other field zones, globals without a data dependency, and the two annotative refs the packet listed verbatim).
