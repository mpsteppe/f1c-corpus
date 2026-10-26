# VehiclePhysics

Scope: `vehicle_physics`  
Trust: `DERIVED`

DERIVED architecture for the vehicle_physics scope from 13 validated functions. One main VehiclePhysicsBody object (DERIVED) carries the per-frame physics: 0x00439210 initializer, 0x0043E230 wheel-dynamics init, 0x00441450 suspension-dataset copy, and 0x00441650 RK2 integration driver. A separate SuspensionPhysicsSnapshot (DERIVED) snapshots per-frame suspension state, RelativeSpeedCalculator (DERIVED) computes AI target relative speed, and Matrix3x3 (GUESS) provides the row-major double-matrix vector transform. The remaining functions sit on unproven objects (GUESS): WheelSurfaceResolver, GearShiftController, VehicleConfigValidator, SuspensionSetup, and VehicleListContainer. Two shared global data services (GlobalVehicleArray, PhysicsParseBuffer) and a spatial query structure (dword_5EA2C0) are consumed across classes. All owners, field names and enums are worker proposals; none are packet-confirmed.

## Function roles

- `0x00404250` **WheelSurfaceResolver** — Resolves per-wheel surface contact hits against a spatial nearest-neighbor structure (dword_5EA2C0) and computes a grip scale for the wheel array; runs two query passes per wheel (primary plane test, secondary signed-plane bound test).
- `0x00415780` **VehicleListContainer** — Rebuilds the vehicle list container from the global vehicle array (dword_8AC390 count, dword_8AC394 base, stride 1060), destroying existing nodes and appending one 176-byte entry per vehicle.
- `0x004159B0` **VehicleListContainer** — Builds a deduplicated vehicle-name commentary list from the global vehicle array (dword_8AC390/dword_8AC394, stride 1060), clearing and rebuilding the commentary sub-list at this+0x10..0x1C.
- `0x00423B10` **RelativeSpeedCalculator** — Computes signed longitudinal (dot-product) or lateral (2D cross-product) relative speed against a target vehicle for AI steering; stores magnitudes in this+0x24 and a normalized relative speed in this+0x30.
- `0x00426330` **GearShiftController** — Per-frame AI gear-shift control: blocks shifts while the shift timer is positive, forces reverse gear in driverStatus==6 state and neutral in carConditions==2 pit mode, and upshifts on RPM threshold with a 0.8 traction guard, capped at max gear.
- `0x00433ED0` **VehicleConfigValidator** — Validates a vehicle configuration by parsing the default and override SVM/HDV files into byte_7C56C0; returns 0 only when both parses succeed and commits the override path into this+0/this+8 string slots when the commit flag is set.
- `0x00435410` **SuspensionSetup** — Parses a suspension setup configuration section: reads head mass/inertia, min/max position and orientation (deg-to-rad), grows the spring array (this+0x94 capacity, this+0x98 count, this+0x9C pointer) and classifies each spring sliding/normal/free-damping (0/1/2).
- `0x004361D0` **Matrix3x3** — Pure 3D vector transform by a row-major 3x3 double matrix: computes the difference vector (a3 - a2), applies rows this[0..8], writes the result into a4 and returns a4.
- `0x00439210` **VehiclePhysicsBody** — Per-frame physics initializer on the vehicle body: loads per-corner suspension setup, computes ride-height/weight-distribution/center-of-mass, builds body-coupling transforms and corner force structures, selects tire compound, runs steering geometry and per-element update passes; called each frame from TireModelInit.
- `0x0043BC20` **SuspensionPhysicsSnapshot** — Per-frame suspension physics snapshot copy: copies two collision-geometry blocks from a3, evaluates quadratic-spring/force/torque terms from the descriptor a2, then copies force/torque parameters, wheel/damper blocks and quad/spring-damper results into the snapshot struct.
- `0x0043E230` **VehiclePhysicsBody** — Wheel dynamics initialization: pushes contact constraints, parameters and a 3-slot physics grid for 4 wheels into the global setter buffer, tears down resources, zeroes the whole object (0x1F38 bytes) and fills 4 strided wheel-struct blocks (1124-byte stride, wheel 0 at this+0x5D8) with a default pattern.
- `0x00441450` **VehiclePhysicsBody** — Copies four suspension datasets into the physics engine via SuspensionDataCopyToPhysicsEngine; wheels 0/1 use their own suspension pointers, the remaining two branch on a shared suspension-ID selector at this[1287].
- `0x00441650` **VehiclePhysicsBody** — Per-frame physics integration driver: saves/restores the FPU control word, runs the main physics update, executes a sub-stepped (RK2 midpoint) integration loop over the accumulated timestep, accumulates wheel forces, detects collision damage/DNF, and transforms inertia tensors for four wheel-link sub-objects.

## Proposed classes

### VehiclePhysicsBody

Per-frame vehicle physics object: initializes mass/center-of-mass/suspension, integrates motion with RK2 sub-steps, accumulates wheel forces, transforms inertia tensors into world space, initializes wheel dynamics and copies suspension datasets into the physics engine.

Methods: `0x00439210`, `0x0043E230`, `0x00441450`, `0x00441650`

- `this+0x00000060` `double time_accumulator` (read_write, DERIVED)
- `this+0x00000068` `double timestep` (read, DERIVED)
- `this+0x000000D4` `float center_of_mass_x` (write, GUESS)
- `this+0x000000DC` `float center_of_mass_y` (write, GUESS)
- `this+0x000000E4` `float center_of_mass_z` (write, GUESS)
- `this+0x000001D4` `pointer body_sub_object` (read_write, DERIVED)
- `this+0x000001E8` `pointer self_pointer` (read, DERIVED)
- `this+0x00000310` `array wheel_link_block_base` (read, DERIVED)
- `this+0x00000318` `float wheel_link_vector` (read, GUESS)
- `this+0x00000338` `array wheel_force_block_base` (read, DERIVED)
- `this+0x000003E0` `float wheel_delta_source` (read, GUESS)
- `this+0x000003E8` `array corner_body_array` (read, DERIVED)
- `this+0x000003EC` `int corner_body_count` (read, DERIVED)
- `this+0x00000400` `float corner_rotation_dot_a` (write, GUESS)
- `this+0x00000420` `float corner_rotation_dot_b` (write, GUESS)
- `this+0x00000428` `float corner_rotation_dot_c` (write, GUESS)
- `this+0x00000430` `float corner_rotation_dot_d` (write, GUESS)
- `this+0x00000450` `byte subobj_active_flag` (read, DERIVED)
- `this+0x00000451` `byte corner_activity_flag` (write, GUESS)
- `this+0x00000454` `int corner_index` (write, GUESS)
- `this+0x00000458` `float corner_damper_rate` (write, GUESS)
- `this+0x0000045C` `float corner_anti_roll` (write, GUESS)
- `this+0x00000464` `float corner_field_0x464` (write, GUESS)
- `this+0x0000046C` `float corner_field_0x46C` (write, GUESS)
- `this+0x00000470` `float corner_field_0x470` (write, GUESS)
- `this+0x000005D8` `struct wheel_struct_base` (read_write, DERIVED)
- `this+0x000005DC` `float wheel_pattern_b` (read_write, GUESS)
- `this+0x000005E0` `float wheel_pattern_c` (read_write, GUESS)
- `this+0x000005E4` `float wheel_pattern_d` (read_write, GUESS)
- `this+0x000005E8` `float wheel_pattern_e` (read_write, GUESS)
- `this+0x000005EC` `float wheel_pattern_f` (read_write, GUESS)
- `this+0x000006B8` `array wheel_setter_anchor` (read, DERIVED)
- `this+0x00000844` `float wheel_delta_mid` (read, GUESS)
- `this+0x00000850` `pointer suspension_ptr_front` (read, DERIVED)
- `this+0x00000CB0` `pointer corner_geometry_ptr_a` (read, DERIVED)
- `this+0x00000CB4` `pointer suspension_ptr_3` (read, GUESS)
- `this+0x00001114` `pointer corner_geometry_ptr_b` (read, DERIVED)
- `this+0x00001118` `pointer suspension_ptr_4` (read, GUESS)
- `this+0x0000141C` `pointer coupled_body_ptr` (read_write, DERIVED)
- `this+0x00001420` `float coupling_rotation_intermediate` (read_write, GUESS)
- `this+0x00001428` `float angular_state_a` (write, GUESS)
- `this+0x0000142C` `float angular_state_b` (write, GUESS)
- `this+0x00001430` `float angular_rate_term` (write, GUESS)
- `this+0x00001448` `float collision_energy_scaled_a` (write, GUESS)
- `this+0x00001450` `float collision_energy_scaled_b` (write, GUESS)
- `this+0x000015AC` `int attached_body_count` (read, DERIVED)
- `this+0x000015B0` `array attached_body_array` (read, DERIVED)
- `this+0x000015B4` `int contact_pair_count` (read, DERIVED)
- `this+0x000015B8` `array contact_pair_base` (read, DERIVED)
- `this+0x000015BC` `int secondary_contact_count` (read, GUESS)
- `this+0x000015C0` `array secondary_contact_base` (read, GUESS)
- `this+0x000015C4` `int coupling_element_count` (read, GUESS)
- `this+0x000015C8` `array coupling_element_base` (read, GUESS)
- `this+0x000015F0` `pointer corner_rotation_object_ptr` (read, DERIVED)
- `this+0x000015F4` `float total_body_mass` (read_write, DERIVED)
- `this+0x000015F8` `float anchor_pos_delta` (write, GUESS)
- `this+0x00001614` `float cg_anchor_delta_x` (write, GUESS)
- `this+0x0000161C` `float cg_anchor_delta_y` (write, GUESS)
- `this+0x00001624` `float cg_anchor_delta_z` (write, GUESS)
- `this+0x0000162C` `pointer heap_ptr_optional_a` (read_write, GUESS)
- `this+0x00001658` `float post_loop_commit` (write, GUESS)
- `this+0x00001CFC` `pointer heap_ptr_optional_b` (read_write, GUESS)
- `this+0x00001D4C` `double setter_double_source` (read, GUESS)
- `this+0x00001F00` `pointer vehicle_config` (read_write, DERIVED)
- `this+0x00001F34` `float corner_setup_weighted_sum` (write, GUESS)
- `*(this+0x1D4)+0x000000AC` `double body_mass` (read_write, DERIVED)
- `*(this+0x1D4)+0x000000B0` `double body_inverse_mass` (read_write, DERIVED)
- `*(this+0x1D4)+0x000000B4` `double body_mass_2` (read_write, GUESS)
- `*(this+0x1D4)+0x000000B8` `double body_mass_3` (read_write, GUESS)
- `*(this+0x1F00)+0x00000738` `float corner_force_result_a` (write, GUESS)
- `*(this+0x1F00)+0x0000073C` `float corner_force_result_b` (write, GUESS)
- `*(this+0x1F00)+0x00000740` `float corner_force_result_c` (write, GUESS)
- `*(this+0x1F00)+0x0000076C` `float track_width` (read, DERIVED)
- `*(this+0x1F00)+0x000008C8` `array corner_setup_array_a` (read, DERIVED)
- `*(this+0x1F00)+0x000008CC` `array corner_setup_array_b` (read, DERIVED)
- `*(this+0x3EC)+0x0000001C` `float subobj_velocity_x` (read, DERIVED)
- `*(this+0x3EC)+0x00000034` `float subobj_velocity_y` (read, DERIVED)
- `*(this+0x3EC)+0x0000004C` `float subobj_velocity_z` (read, DERIVED)
- `*(this+0x3EC)+0x000000AC` `float corner_suspension_travel` (read, DERIVED)
- `*(this+0x141C)+0x000000AC` `float coupled_suspension_travel` (read, GUESS)
- `*(this+0x1114)+0x00000004` `float corner_offset_a_x` (read, DERIVED)
- `*(this+0x1114)+0x0000000C` `float corner_offset_a_y` (read, DERIVED)
- `*(this+0x1114)+0x00000014` `float corner_offset_a_z` (read, DERIVED)
- `*(this+0xCB0)+0x00000004` `float corner_offset_b_x` (read, DERIVED)
- `*(this+0xCB0)+0x0000000C` `float corner_offset_b_y` (read, DERIVED)
- `*(this+0xCB0)+0x00000014` `float corner_offset_b_z` (read, DERIVED)

### WheelSurfaceResolver

Per-wheel surface collision pass: queries the spatial nearest-neighbor structure for the wheel array and computes a grip scale and per-element contact pointers/heights.

Methods: `0x00404250`

- `this+0x00000010` `int resolution_threshold` (read, GUESS)
- `this+0x00000130` `int wheel_count` (read, DERIVED)
- `this+0x00000134` `array wheel_array_base` (read, DERIVED)
- `this+0x00000170` `float grip_scale` (read_write, DERIVED)
- `this+0x00000174` `int phase_flag` (write, DERIVED)

### VehicleListContainer

Holds two linked lists rebuilt from the global vehicle array: the vehicle list (this+0x0..0xC, 12-byte nodes wrapping 176-byte entries) and the deduplicated commentary name list (this+0x10..0x1C, nodes wrapping 172-byte entries).

Methods: `0x00415780`, `0x004159B0`

- `this+0x00000000` `pointer vehicle_list_head` (read_write, DERIVED)
- `this+0x00000004` `pointer vehicle_list_tail` (read_write, DERIVED)
- `this+0x00000008` `pointer vehicle_list_secondary` (read_write, DERIVED)
- `this+0x0000000C` `int vehicle_list_count` (read_write, DERIVED)
- `this+0x00000010` `pointer commentary_list_head` (read_write, DERIVED)
- `this+0x00000014` `pointer commentary_list_next` (read_write, DERIVED)
- `this+0x00000018` `pointer commentary_list_secondary` (read_write, DERIVED)
- `this+0x0000001C` `int commentary_list_count` (read_write, DERIVED)
- `obj+0x00000000` `pointer node_data` (read, GUESS)
- `obj+0x00000008` `byte node_flag` (read, GUESS)

### RelativeSpeedCalculator

Computes signed relative speed between the owning AI object and a target vehicle: longitudinal closing speed via dot product or lateral speed via 2D cross product, with a normalized longitudinal speed.

Methods: `0x00423B10`

- `this+0x00000000` `pointer target_object_ptr` (read, DERIVED)
- `this+0x00000024` `float signed_speed` (read_write, DERIVED)
- `this+0x00000030` `float normalized_speed` (write, DERIVED)
- `obj+0x000034E0` `float target_position_x` (read, DERIVED)
- `obj+0x000034E8` `float target_position_y` (read, DERIVED)
- `obj+0x000034F8` `float target_velocity_x` (read, DERIVED)
- `obj+0x00003500` `float target_velocity_y` (read, DERIVED)

### GearShiftController

Per-frame AI gear-shift control over vehicle state fields: shift-timer block, reverse/pit-mode force requests, RPM-threshold upshift with traction guard and max-gear cap.

Methods: `0x00426330`

- `this+0x000037CC` `float traction_x` (read, DERIVED)
- `this+0x000038C4` `float traction_y` (read, DERIVED)
- `this+0x000039A0` `float engine_rpm` (read, DERIVED)
- `this+0x000039FC` `int current_gear` (read, DERIVED)
- `this+0x00003A04` `int max_gear` (read, DERIVED)
- `this+0x00003A10` `float shift_timer` (read, DERIVED)
- `this+0x00003A18` `float shift_rpm_threshold` (read, DERIVED)
- `this+0x00003D6C` `int car_conditions` (read, DERIVED)
- `this+0x00004510` `int driver_status` (read, DERIVED)

### VehicleConfigValidator

Validates a vehicle configuration file by parsing the default and override SVM/HDV files and optionally committing the override path into the object's string slots.

Methods: `0x00433ED0`

- `this+0x00000000` `char* path_string_src` (read, DERIVED)
- `this+0x00000008` `char* path_string_dst` (write, DERIVED)

### SuspensionSetup

Parsed suspension setup: setup index, body anchor and rotation reference, min/max position and orientation, and a growing spring array (capacity/count/pointer) of 100-byte classified spring entries.

Methods: `0x00435410`

- `this+0x00000000` `int setup_index` (read_write, DERIVED)
- `this+0x00000004` `float body_anchor_x` (read, DERIVED)
- `this+0x0000000C` `float body_anchor_y` (read, DERIVED)
- `this+0x00000014` `float body_anchor_z` (read, DERIVED)
- `this+0x00000064` `float min_orientation_x` (read_write, DERIVED)
- `this+0x0000006C` `float min_orientation_y` (read_write, DERIVED)
- `this+0x00000074` `float min_orientation_z` (read_write, DERIVED)
- `this+0x0000007C` `float max_orientation_x` (read_write, DERIVED)
- `this+0x00000084` `float max_orientation_y` (read_write, DERIVED)
- `this+0x0000008C` `float max_orientation_z` (read_write, DERIVED)
- `this+0x00000094` `int spring_capacity` (read, DERIVED)
- `this+0x00000098` `int spring_count` (read_write, DERIVED)
- `this+0x0000009C` `pointer spring_array_ptr` (read_write, DERIVED)
- `obj+0x000000AC` `double head_mass` (write, DERIVED)
- `obj+0x000000B4` `double head_mass_reciprocal` (write, DERIVED)

### Matrix3x3

Row-major 3x3 double matrix used as a linear-algebra transform; F_3DVectorTransformBy33Matrix multiplies a difference vector by this matrix and writes the result to the output vector.

Methods: `0x004361D0`

- `this+0x00000000` `double m00` (read, GUESS)
- `this+0x00000008` `double m01` (read, GUESS)
- `this+0x00000010` `double m02` (read, GUESS)
- `this+0x00000018` `double m10` (read, GUESS)
- `this+0x00000020` `double m11` (read, GUESS)
- `this+0x00000028` `double m12` (read, GUESS)
- `this+0x00000030` `double m20` (read, GUESS)
- `this+0x00000038` `double m21` (read, GUESS)
- `this+0x00000040` `double m22` (read, GUESS)

### SuspensionPhysicsSnapshot

Per-frame snapshot of suspension physics state: copies collision-geometry blocks, wheel/damper and force/torque blocks from the source physics object, evaluates quadratic-spring/force/torque terms from a parameter descriptor, and mirrors selected results.

Methods: `0x0043BC20`

- `this+0x00001900` `byte state_flag` (read_write, DERIVED)
- `this+0x00001904` `int reserved_zero` (write, GUESS)
- `this+0x00001910` `int force_param_a` (read_write, DERIVED)
- `this+0x00001914` `int force_param_b` (read_write, DERIVED)
- `this+0x00001938` `int torque_param_a` (read_write, DERIVED)
- `this+0x0000193C` `int torque_param_b` (read_write, DERIVED)
- `this+0x00001940` `int torque_param_c` (read_write, DERIVED)
- `this+0x00001944` `int torque_param_d` (read_write, DERIVED)
- `this+0x000017A8` `int force_rate_0` (read_write, DERIVED)
- `this+0x000017AC` `int force_rate_1` (read_write, DERIVED)
- `this+0x000017B0` `int force_rate_2` (read_write, DERIVED)
- `this+0x000017B4` `int force_rate_3` (read_write, DERIVED)
- `this+0x000017B8` `int force_rate_4` (read_write, DERIVED)
- `this+0x000017BC` `int force_rate_5` (read_write, DERIVED)
- `this+0x000017C0` `int force_torque_vec_0` (read_write, DERIVED)
- `this+0x000017C4` `int force_torque_vec_1` (read_write, DERIVED)
- `this+0x000017C8` `int force_torque_vec_2` (read_write, DERIVED)
- `this+0x000017CC` `int force_torque_vec_3` (read_write, DERIVED)
- `this+0x000017D0` `int force_torque_vec_4` (read_write, DERIVED)
- `this+0x000017D4` `int force_torque_vec_5` (read_write, DERIVED)
- `this+0x000017D8` `int quad_force_param_0` (read_write, DERIVED)
- `this+0x000017DC` `int quad_force_param_1` (read_write, DERIVED)
- `this+0x000017E0` `int quad_force_param_2` (read_write, DERIVED)
- `this+0x000017E4` `int quad_force_param_3` (read_write, DERIVED)
- `this+0x000017E8` `int quad_force_param_4` (read_write, DERIVED)
- `this+0x000017EC` `int quad_force_param_5` (read_write, DERIVED)
- `this+0x000017F0` `int quad_force_torque_vec_0` (read_write, DERIVED)
- `this+0x000017F4` `int quad_force_torque_vec_1` (read_write, DERIVED)
- `this+0x000017F8` `int quad_force_torque_vec_2` (read_write, DERIVED)
- `this+0x000017FC` `int quad_force_torque_vec_3` (read_write, DERIVED)
- `this+0x00001800` `int quad_force_torque_vec_4` (read_write, DERIVED)
- `this+0x00001804` `int quad_force_torque_vec_5` (read_write, DERIVED)
- `this+0x00001808` `double spring_offset_src` (read, GUESS)
- `this+0x0000180C` `double spring_scalar_0` (read_write, DERIVED)
- `this+0x00001810` `double spring_geometry_0` (read_write, DERIVED)
- `this+0x00001814` `double spring_geometry_1` (read_write, DERIVED)
- `this+0x00001818` `double spring_scalar_1` (read_write, DERIVED)
- `this+0x0000181C` `double spring_scalar_2` (read_write, DERIVED)
- `this+0x00001820` `double spring_geometry_2` (read_write, DERIVED)
- `this+0x00001824` `double spring_geometry_3` (read_write, DERIVED)
- `this+0x00001828` `int ft_result_a` (read_write, DERIVED)
- `this+0x0000182C` `int ft_result_b` (read_write, DERIVED)
- `this+0x00001830` `int ft_result_c` (read_write, DERIVED)
- `this+0x00001834` `int ft_result_d` (read_write, DERIVED)
- `this+0x00001A08` `byte quad_result_flag` (read_write, DERIVED)
- `this+0x00001A14` `int quad_result_a` (read_write, DERIVED)
- `this+0x00001A18` `int quad_result_b` (read_write, DERIVED)
- `this+0x00001AE4` `int ft_vec_0` (read_write, DERIVED)
- `this+0x00001AE8` `int ft_vec_1` (read_write, DERIVED)
- `this+0x00001AEC` `int ft_vec_2` (read_write, DERIVED)
- `this+0x00001AF0` `int ft_vec_3` (read_write, DERIVED)
- `this+0x00001AF4` `int ft_vec_4` (read_write, DERIVED)
- `this+0x00001AF8` `int ft_vec_5` (read_write, DERIVED)
- `this+0x00001B94` `double spring_offset_rhs` (read, GUESS)
- `this+0x00001BBC` `byte sd_result_flag` (read_write, DERIVED)
- `this+0x00001BC0` `double sd_result_scalar` (read_write, DERIVED)
- `this+0x00001BC8` `int sd_result_dword_0` (read_write, DERIVED)
- `this+0x00001BCC` `int sd_result_dword_1` (read_write, DERIVED)
- `this+0x00001BD0` `int sd_result_dword_2` (read_write, DERIVED)
- `this+0x00001BD4` `int sd_result_dword_3` (read_write, DERIVED)
- `this+0x00001BD8` `int sd_result_dword_4` (read_write, DERIVED)
- `this+0x00001BDC` `int sd_result_dword_5` (read_write, DERIVED)
- `this+0x00001BE0` `int sd_result_dword_6` (read_write, DERIVED)
- `this+0x00001BE4` `int sd_result_dword_7` (read_write, DERIVED)
- `this+0x00001C08` `double mirror_force_rate_a` (write, GUESS)
- `this+0x00001C0C` `double mirror_force_rate_b` (write, GUESS)
- `this+0x00001C10` `double mirror_force_torque_a` (write, GUESS)
- `this+0x00001C14` `double mirror_force_torque_b` (write, GUESS)
- `this+0x00001C20` `double mirror_spring_scalar_0` (write, GUESS)
- `this+0x00001C24` `double mirror_spring_scalar_1` (write, GUESS)
- `this+0x00001C28` `double mirror_spring_scalar_2` (write, GUESS)
- `this+0x00001C2C` `double mirror_spring_scalar_3` (write, GUESS)
- `this+0x00001C30` `double mirror_sd_result` (write, GUESS)
- `this+0x00001C40` `double mirror_quad_a` (write, GUESS)
- `this+0x00001C44` `double mirror_quad_b` (write, GUESS)
- `this+0x00001C48` `double mirror_quad_c` (write, GUESS)
- `this+0x00001C4C` `double mirror_quad_d` (write, GUESS)

## Compatibility contracts

- **WheelSurfaceContactResolution** — Per-frame wheel contact pass must preserve the grip-scale formula 1.0 - (flt_8AFEE8 + flt_8AFEEC)*0.5 stored at this+0x170, the wheel array stride of 316 bytes with count at this+0x130 and base this+0x134, the two nearest-neighbor queries (flag 1 primary, flag 0 secondary signed-plane bound test) on dword_5EA2C0, and the phase-flag reset this+0x174 = -1 at exit.
- **PhysicsIntegrationGates** — Per-frame physics integration must early-out when the physics-override double at 0x005D6D70 equals 1.0 or the enable byte at 0x007CE254 is zero, must save and restore the FPU control word, and must preserve the RK2 midpoint sub-stepping (half-step wheel-data copies, accumulator this+0x60) over the timestep field this+0x68.
- **VehicleFileValidation** — ValidateVehicleConfigurationFile returns 0 only when both the default and override SVM/HDV parses succeed; on success the parse buffer byte_7C56C0 is cleared, the cost-display mode backup dword_7C56C4 = dword_7D0450 is taken before parsing, and when the commit flag is set the override path is copied into the caller's this+0 / this+8 string slots via StringCopyWithBufferRealloc and sub_568B00.
- **VehicleArrayLayout** — Consumers of the global vehicle array (dword_8AC390 count, dword_8AC394 base, stride 1060) rely on the driver-name byte at entry+124 and the driver-file path at entry+188; a replacement must preserve those field offsets and the array stride.
- **SuspensionSetupSection** — SuspensionSetupSectionReader must keep the degree-to-radian conversion factor 0.0174532925199433 for orientation fields, the spring-array growth rule (capacity +3 slots of 100 bytes via OperatorNewNhMallocWrapper with per-slot category init), and the spring classification enums sliding/normal/free-damping (0/1/2).

## Unresolved

- VehiclePhysicsBody grouping is a worker proposal: the packet lists the owners of 0x00439210/0x0043E230/0x00441450/0x00441650 as UnknownObject/UNKNOWN; a single shared physics object is inferred from overlapping fields (this+0x3EC, this+0x15F0, 1124-byte wheel strides) and caller relationships.
- 0x00404250 and 0x00426330 operate on 'this' objects with no packet-identified owner; WheelSurfaceResolver and GearShiftController are GUESS proposals, not packet-confirmed.
- 18 physics-constant globals (0x0059E420..0x0059EC08, 0x0059ED28..0x0059ED38) are listed as read but folded into FPU literals by the decompiler; their exact use sites are unproven.
- Corner-geometry field evidence at *(this+0x141C)+0x4..0x5C, *(this+0x15F0)+0x4..0x5C and *(this+0x15B0)+0xAC could not be localized to specific statements in the decompiled text.
- Globals unk_5EC6D0 and dword_8ADB00 (0x00433ED0), dword_8AD254 (0x00439210), and flt_59E43C/flt_59E450 (0x00404250) are listed as read but do not appear in the raw source text.
- The 1124-byte wheel stride and the sub-offsets consumed by the wheel setters in 0x0043E230 are evidenced only via source:raw, not enumerated fields.
- Destination offsets this+6200/this+6300, the six 24-byte loop copies (this+6496/6708/6932) and their 24-byte tails (this+6640/6852/7076) in 0x0043BC20 have no packet field entries; internal layout is inferred from copy sizes only.
- The duplicate re-copies in 0x0043BC20 (source lines 74-93) are treated as redundant double-writes; their semantic significance is unknown.
- The JUMPOUT(0x4F62E6) downshift tail of 0x00426330 lies outside this packet; literal gear requests -1 (reverse) / 0 (neutral) are inferred from surrounding state guards.
- Exact float values behind flt_59E440 (assumed 0.0 zero threshold) and flt_59E8CC (assumed 0.8 traction threshold) are not proven.
- The caller 0x00415090 (ShortComputation_5090) of 0x00415780/0x004159B0 is outside this packet; the this+0x10..0x1C commentary-list bookkeeping role is inferred.
- The guard set (this+0x3EC, 0x15AC, 0x15B4, 0x15BC, 0x15C4) in 0x00439210 is taken from the IDB guard table; the exact branch mapping is not fully verified, and 0x15BC/0x15C4 are described both as loop counts and as roll-stiffness/spring-rate thresholds.
- Vehicle body sub-object init literal 0x3FF00000 is emitted as 1072693248 in the packet; rendered as 1.875f only in the prose tier (DERIVED).
- The 0x00415900 StructDestructor / 0x00418D60 DestructorWithDoubleFreePattern / 0x00418C10 MemoryAllocation_8c10 constant argument 1 significance is unknown.
- VehicleListContainer / VehicleConfigValidator / SuspensionSetup / Matrix3x3 class boundaries are GUESS; the packet provides no named owner for any of them.
