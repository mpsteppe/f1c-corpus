# VehiclePhysics

Scope: `vehicle_physics`  
Trust: `DERIVED`

Conservative architecture proposal for 25 validated vehicle-physics functions. Four functions (0x00442C90, 0x00435E60, 0x00443150, 0x00438F00) form the coherent per-frame suspension/wheel physics core sharing body/hub transform pointers at this+0x141C/0x15F0 and a rotation-matrix block at this+0x160C..0x164C; 0x0043E890 and 0x0043EC80 share a damper-accumulator layout (this+0x17A8/0x17C0/0x1C00/0x1C08/0x1C10) and 0x004412F0/0x00441360 share the wheel-state history layout. The six collision material coefficient initializers plus CollisionStateClear form a GUESS config group over consecutive module globals. All owners are packet-UNKNOWN; class boundaries are DERIVED/GUESS from field-layout coherence. Several receiver objects reuse the same generic 'this' base at equal offsets (0x00..0x48, 0x84, 0x15F0, 0x160C..0x164C) without proven common ownership; each offset is attributed to one class and the reuse is recorded in unresolved.

## Function roles

- `0x00405E60` **CollisionAudioFeedbackState** — Collision-response intensity computation for audio feedback: stores the collision parameter (this+0x48), position (this+0x28/0x2C/0x30) and velocity (this+0x34/0x38/0x3C), queries the collision object (this+0x54) contact-type check and intensity-multiplier vtable entries, clamps intensity into this+0x40, and computes a position-delta magnitude when active.
- `0x00431D40` **PhysicsBufferAllocator** — Constructor-style initializer for the physics buffer allocator: allocates two 80-byte and one 128-byte buffer via OperatorNewNhMallocWrapper (0x00587C03), stores pointer/size pairs at this+0x0/0x4, this+0x8/0xC and this+0x10/0x14, zeroes the first byte of each buffer and the ten trailing DWORDs this+0x18..0x3C, and returns this.
- `0x00432810` **VehicleIdentifierAccessor** — Simple __thiscall accessor: dereferences this->field0 and returns the DWORD at +0x2C of the pointed-to object; invoked by HTMLSeasonOutput (0x0046EE60).
- `0x00435E60` **SuspensionSpringDamper** — Per-frame suspension spring-damper force/torque computation for a wheel assembly: null-body guard on this+0x0, transforms a suspension-frame vector through the chassis matrix, subtracts the attach-point offset (this+0x4/0xC/0x14), scales by flt_7CFB48, clamps force per-axis (this+0x1C..0x44), derives torque via matrix/atan2 with a gimbal branch, scales by flt_7CFB6C and clamps torque per-axis (this+0x64..0x8C, 64-bit double pairs).
- `0x00438F00` **WheelContactGeometry** — Wheel contact-point world-space transform: reads a suspension offset vector (this+0x1614/0x161C/0x1624), adds a caller delta, transforms through the geometry rotation matrix and translation (this+0x15F0 region) into body+4 when the body pointer this+0x1E8 is set, derives euler angles with a pole branch, then calls SuspensionSetupSectionReader (0x00435410).
- `0x0043AEE0` **AffineTransform3D** — 3D affine transform helper: computes a4 = this*a3 + a2 where this is a row-major 3x3 double matrix (offsets +0x0..+0x40) and a2 the translation vector; returns a2. Pure coordinate transform on the physics frame path.
- `0x0043AF50` **SuspensionAntiRollBar** — Suspension anti-roll-bar lookup by name: searches a struct array via LinearSearchInStructArrayByString (0x0056EB30), selects a rotation row, computes a transformed position into a3, and on miss zeroes a3 and conditionally logs via DebugLogWrite (0x004D7AA0) gated by dword_7C569C and StringSplitLoop (0x004D7A50).
- `0x0043E890` **WheelDamperAccumulator** — Damper-force accumulation: accumulates a2 scaled by 0.23 into this+0x17A8 and by 0.18 into this+0x17C0, clamps each into [reference, reference+bound] using this+0x1C08/0x1C10, and evaluates the quadratic damper curve via QuadFunctionEval (0x0043BB30) with selector this+0x1C00.
- `0x0043EC80` **WheelDamperAccumulator** — Wheel/tyre physics step over a double-array state object: clamps states this+0x17A8/0x17C0 onto references this+0x1C08/0x1C10, evaluates a quadratic force via QuadFunctionEval (0x0043BB30), applies three bias clamps (0.15/0.12/0.25 literals), runs SpringDamperCompute (0x0043BBD0) and QuadraticForceTorqueCalculator (0x0043BB80).
- `0x004412F0` **WheelStateHistory** — Shifts wheel-state history buffers forward one frame: copies current slots of three scalar buffers (this+0x1C5C/0x1C64, this+0x1E38/0x1E40, this+0x1E3C/0x1E44) to previous slots, then shifts four per-wheel history blocks (281-dword stride) from this+0x338, moving four dword pairs and a 32-byte sub-record.
- `0x00441360` **WheelStateHistory** — Per-frame wheel-state delta accumulation: shifts history via WheelStateHistoryShift (0x004412F0), reads the wheel count at this+0x162C, and for each wheel (48-byte current stride from this+0x15AC vs 580-byte previous stride from this+0x15B0) accumulates position and velocity deltas back into the previous-state buffer.
- `0x00442C90` **SuspensionIntegrator** — Per-frame suspension/wheel physics tick: loop 1 walks four 1124-byte wheel blocks from this+0x410, resolves each wheel's geometry base, transforms anchors through body (this+0x141C) and hub (this+0x15F0) matrices, builds/normalizes the suspension direction, computes cross-product torque terms and applies ConstraintEnforce (0x004380B0) per wheel; gates front/rear anti-roll blocks by bypass bytes; loop 2 scales stored directions by block forces and feeds AccumulateAngularMomentum (0x00569AD0) and F_3DVectorSubtractWithCrossProduct (0x00569B70).
- `0x00443150` **WheelContactNormalForceSolver** — Solves wheel-ground contact normal force: guarded by the contact-active flag (a2[0]); rotates the contact point into world space via the body matrix (this+0x160C), builds contact-point velocity from the body angular-velocity and vector terms (this+0x1654..0x167C), and when the normal slip is negative computes a friction-modulated normal force and damping force, accumulating angular momentum via AccumulateAngularMomentum (0x00569AD0).
- `0x0044C5E0` **CollisionAllocatorShim** — Thin thunk that calls MemoryAllocation_31a0 with the address of global ppvOut (0x007CA590) and returns its result directly.
- `0x0044C860` **CollisionMaterialConfig** — Unconditional initializer of a collision material coefficient block: writes material type 7 to dword_7CCBB0, zeroes flt_7CCBB4/flt_7CCBB8, and writes the raw dword literal 1065353216 to dword_7CCBBC.
- `0x0044CFE0` **CollisionMaterialConfig** — Straight-line initializer writing 40 to dword_7CC9EC and 0.0 to flt_7CC9F0, then calling the helper FloatFloatInitTo.
- `0x0044D5E0` **CollisionMaterialConfig** — Unconditional initializer of collision material coefficients set 1: writes material ID 19 to dword_7CCC80 and zeroes five following coefficient fields (0x007CCC84..0x007CCC94); returns 0.
- `0x0044DD60` **CollisionMaterialConfig** — Unconditional initializer of collision material coefficients set 2: writes material ID 52 to dword_7CCE10 and zeroes five following coefficient fields (0x007CCE14..0x007CCE24); returns 0.
- `0x0044E060` **CollisionStateConfig** — Unconditional init of a six-dword collision state block: sets dword_7CCD68 to 68 (version/magic identifier), zeroes dword_7CCD6C..dword_7CCD7C, returns 0.
- `0x0044E4E0` **CollisionMaterialConfig** — Unconditional init of a six-dword collision material coefficients block: sets dword_7CD0C8 to 80, zeroes dword_7CD0CC..dword_7CD0D8, sets dword_7CD0DC to 18000 (range threshold); returns 0.
- `0x0044EC60` **CollisionMaterialConfig** — Straight-line initializer of a six-dword global block (0x007CA4A0..0x007CA4B4): sets the first dword to 100, clears four, sets the last to 18000 (collision world range), returns 0.
- `0x0044EE00` **CollisionNode** — Side-effect-free getter: reads field this+0x0 and returns this+76 when nonzero, otherwise null (next-child accessor).
- `0x0044EFC0` **CollisionObjectStore** — Stores a type id (a2) at this+0x278, bulk-copies 0x244 bytes (145 DWORDs) from stack parameters a3..a63 into this+0x8, and returns a2; called by sub_44ED10.
- `0x0044FBB0` **CollisionObjectStore** — Copies a device capability/configuration block into the object: stores argument a2 at this+0x2F4, memcpy-copies 0x244 bytes from stack arguments a3..a62 into this+0x84, returns the stored value; called by device-enumeration callback sub_44ED10.
- `0x00456F70` **CollisionForceAccumulator** — Collision force accumulator update: selects a signed coefficient (0.4 default, 6.0 when a3==1, negated when a2==0), multiplies by input a4, adds to the accumulator this+0xAC, clamps via ClampedFloatSetter (0x00456FB0) and returns its result.

## Proposed classes

### CollisionAudioFeedbackState

Collision-response feedback record: stores the last collision parameter, position/velocity pair and computed clamped intensity, plus a reference to the collision object whose vtable supplies the contact-type check and intensity multiplier.

Methods: `0x00405E60`

- `this+0x00000018` `byte collision_type_flags` (read, DERIVED)
- `this+0x00000028` `float collision_position_x` (write, DERIVED)
- `this+0x0000002C` `float collision_position_y` (write, DERIVED)
- `this+0x00000030` `float collision_position_z` (write, DERIVED)
- `this+0x00000034` `float collision_velocity_x` (write, DERIVED)
- `this+0x00000038` `float collision_velocity_y` (write, DERIVED)
- `this+0x0000003C` `float collision_velocity_z` (write, DERIVED)
- `this+0x00000040` `float collision_intensity` (read_write, DERIVED)
- `this+0x00000048` `dword collision_parameter` (write, DERIVED)
- `this+0x00000054` `pointer collision_object_ptr` (read, DERIVED)
- `*(this+0x54)+0x00000000` `pointer collision_object_vtable` (read, GUESS)
- `*(this+0x54)+0x00000058` `double collision_object_reference_x` (read, DERIVED)
- `*(this+0x54)+0x0000005C` `double collision_object_reference_y` (read, DERIVED)
- `*(this+0x54)+0x00000060` `double collision_object_reference_z` (read, DERIVED)
- `*(*(this+0x54)+0x0)+0x00000030` `function_ptr intensity_multiplier_getter` (read, GUESS)
- `*(*(this+0x54)+0x0)+0x00000058` `function_ptr contact_type_check` (read, GUESS)

### PhysicsBufferAllocator

Physics buffer allocator record: three (pointer,size) buffer pairs and ten reserved/zeroed trailing DWORDs; initialized by the constructor-style allocator path from Thunk_1bc0.

Methods: `0x00431D40`

- `this+0x00000000` `pointer buffer0_ptr` (write, DERIVED)
- `this+0x00000004` `dword buffer0_size` (write, DERIVED)
- `this+0x00000008` `pointer buffer1_ptr` (write, DERIVED)
- `this+0x0000000C` `dword buffer1_size` (write, DERIVED)
- `this+0x00000010` `pointer buffer2_ptr` (write, DERIVED)
- `this+0x00000014` `dword buffer2_size` (write, DERIVED)
- `this+0x00000018` `dword reserved_dword_0` (write, GUESS)
- `this+0x0000001C` `dword reserved_dword_1` (write, GUESS)
- `this+0x00000020` `dword reserved_dword_2` (write, GUESS)
- `this+0x00000024` `dword reserved_dword_3` (write, GUESS)
- `this+0x00000028` `dword reserved_dword_4` (write, GUESS)
- `this+0x0000002C` `dword reserved_dword_5` (write, GUESS)
- `this+0x00000030` `dword reserved_dword_6` (write, GUESS)
- `this+0x00000034` `dword reserved_dword_7` (write, GUESS)
- `this+0x00000038` `dword reserved_dword_8` (write, GUESS)
- `this+0x0000003C` `dword reserved_dword_9` (write, GUESS)

### VehicleIdentifierAccessor

Accessor holding a target pointer whose +0x2C DWORD is returned; identity of the target object is unknown.

Methods: `0x00432810`

- `this+0x00000000` `pointer target_ptr` (read, GUESS)
- `obj+0x0000002C` `dword identifier_value` (read, GUESS)

### SuspensionSpringDamper

Per-wheel suspension spring-damper: attach-point offset, per-axis force and torque clamp windows (double-pair bounds) used to clamp the computed spring-damper force/torque each frame.

Methods: `0x00435E60`

- `this+0x00000004` `float attach_offset_x` (read, DERIVED)
- `this+0x0000000C` `float attach_offset_y` (read, DERIVED)
- `this+0x00000014` `float attach_offset_z` (read, DERIVED)
- `this+0x0000001C` `double force_clamp_min_x` (read, DERIVED)
- `this+0x00000024` `double force_clamp_min_y` (read, DERIVED)
- `this+0x0000002C` `double force_clamp_min_z` (read, DERIVED)
- `this+0x00000034` `double force_clamp_max_x` (read, DERIVED)
- `this+0x0000003C` `double force_clamp_max_y` (read, DERIVED)
- `this+0x00000044` `double force_clamp_max_z` (read, DERIVED)
- `this+0x00000064` `double torque_clamp_min_x` (read, DERIVED)
- `this+0x00000068` `dword torque_clamp_min_x_hi` (read, GUESS)
- `this+0x0000006C` `double torque_clamp_min_y` (read, DERIVED)
- `this+0x00000074` `double torque_clamp_min_z` (read, DERIVED)
- `this+0x0000007C` `double torque_clamp_max_x` (read, DERIVED)
- `this+0x00000080` `dword torque_clamp_max_x_hi` (read, GUESS)
- `this+0x00000084` `double torque_clamp_max_y` (read, DERIVED)
- `this+0x0000008C` `double torque_clamp_max_z` (read, DERIVED)

### WheelContactGeometry

Wheel contact geometry: geometry translation and rotation-matrix block (this+0x15F0 region) plus the attached-body pointer used to write the world-space contact point into body+4.

Methods: `0x00438F00`

- `this+0x000015F4` `double geometry_translation_x` (read, DERIVED)
- `this+0x000015FC` `double geometry_translation_y` (read, DERIVED)
- `this+0x00001604` `double geometry_translation_z` (read, DERIVED)
- `this+0x0000160C` `double rotation_row0_col0` (read, DERIVED)
- `this+0x00001614` `double rotation_row0_col1` (read, DERIVED)
- `this+0x0000161C` `double rotation_row0_col2` (read, DERIVED)
- `this+0x00001624` `double rotation_row1_col0` (read, DERIVED)
- `this+0x0000162C` `double rotation_row1_col1` (read, DERIVED)
- `this+0x00001634` `double rotation_row1_col2` (read, DERIVED)
- `this+0x0000163C` `double rotation_row2_col0` (read, DERIVED)
- `this+0x00001644` `double rotation_row2_col1` (read, DERIVED)
- `this+0x0000164C` `double rotation_row2_col2` (read, DERIVED)
- `this+0x000001E8` `pointer body_ptr` (read, DERIVED)

### AffineTransform3D

Row-major 3x3 double matrix used as a coordinate transform (a4 = this*a3 + translation); pure helper, no owned state beyond the matrix.

Methods: `0x0043AEE0`

- `this+0x00000000` `double matrix_row0_col0` (read, DERIVED)
- `this+0x00000008` `double matrix_row0_col1` (read, DERIVED)
- `this+0x00000010` `double matrix_row0_col2` (read, DERIVED)
- `this+0x00000018` `double matrix_row1_col0` (read, DERIVED)
- `this+0x00000020` `double matrix_row1_col1` (read, DERIVED)
- `this+0x00000028` `double matrix_row1_col2` (read, DERIVED)
- `this+0x00000030` `double matrix_row2_col0` (read, DERIVED)
- `this+0x00000038` `double matrix_row2_col1` (read, DERIVED)
- `this+0x00000040` `double matrix_row2_col2` (read, DERIVED)

### SuspensionAntiRollBar

Name-driven suspension anti-roll-bar lookup returning a transformed position; no owned fields are evidenced (operates on caller buffers and module globals).

Methods: `0x0043AF50`


### WheelDamperAccumulator

Per-wheel damper force accumulation and clamping: two scaled accumulators (this+0x17A8/0x17C0), two reference limits (this+0x1C08/0x1C10) and the quadratic-curve selector (this+0x1C00).

Methods: `0x0043E890`, `0x0043EC80`

- `this+0x000017A8` `double damper_accumulator_0` (read_write, DERIVED)
- `this+0x000017C0` `double damper_accumulator_1` (read_write, DERIVED)
- `this+0x00001C00` `dword damper_curve_selector` (read, DERIVED)
- `this+0x00001C08` `double damper_reference_0` (read, DERIVED)
- `this+0x00001C10` `double damper_reference_1` (read, DERIVED)

### WheelStateHistory

Per-frame wheel-state history: current/previous wheel-state arrays (this+0x15AC/0x15B0), wheel count (this+0x162C), three shifted scalar buffers and four per-wheel history blocks from this+0x338.

Methods: `0x004412F0`, `0x00441360`

- `this+0x000015AC` `pointer current_wheel_state_array` (read, DERIVED)
- `this+0x000015B0` `pointer previous_wheel_state_array` (read_write, DERIVED)
- `this+0x0000162C` `dword wheel_count` (read, DERIVED)
- `this+0x00000338` `dword history_block_base` (read_write, GUESS)
- `this+0x0000033C` `dword history_slot_1` (read_write, GUESS)
- `this+0x00000340` `dword history_slot_2` (read_write, GUESS)
- `this+0x00000344` `dword history_slot_3` (read_write, GUESS)
- `this+0x00000348` `dword history_slot_4` (read_write, GUESS)
- `this+0x0000034C` `dword history_slot_5` (read_write, GUESS)
- `this+0x00000350` `dword history_slot_6` (read_write, GUESS)
- `this+0x00000354` `dword history_slot_7` (read_write, GUESS)
- `this+0x00001C5C` `dword buffer_slot_0` (read_write, DERIVED)
- `this+0x00001C60` `dword buffer_slot_1` (read_write, DERIVED)
- `this+0x00001C64` `dword buffer_slot_2` (read_write, DERIVED)
- `this+0x00001C68` `dword buffer_slot_3` (read_write, DERIVED)
- `this+0x00001E38` `dword third_buffer_slot_0` (read_write, DERIVED)
- `this+0x00001E3C` `dword third_buffer_slot_1` (read_write, DERIVED)
- `this+0x00001E40` `dword third_buffer_slot_2` (read_write, DERIVED)
- `this+0x00001E44` `dword third_buffer_slot_3` (read_write, DERIVED)

### SuspensionIntegrator

Per-frame vehicle suspension/wheel integrator: four 1124-byte wheel blocks from this+0x410, body and hub transform pointers (this+0x141C/0x15F0), anti-roll torque accumulators and bypass bytes, plus the pointed-to body/hub transform layouts (translation, secondary and rotation rows).

Methods: `0x00442C90`

- `this+0x00000410` `dword wheel_block_base` (read, DERIVED)
- `this+0x00000418` `dword wheel_offset_b` (read, DERIVED)
- `this+0x00000438` `dword wheel_state_position` (read, DERIVED)
- `this+0x00000440` `dword wheel_offset_d` (read, DERIVED)
- `this+0x00000448` `dword wheel_offset_a` (read, DERIVED)
- `this+0x00000474` `double front_damper_load_a` (read, DERIVED)
- `this+0x0000047C` `double front_damper_load_a_alt` (read, DERIVED)
- `this+0x00000484` `double front_damper_load_b` (read, DERIVED)
- `this+0x0000048C` `byte wheel_bypass_flag_0` (read, DERIVED)
- `this+0x00000490` `double wheel_accumulator_0` (read_write, DERIVED)
- `this+0x000008D8` `double front_damper_load_c` (read, DERIVED)
- `this+0x000008E0` `double front_damper_load_c_alt` (read, DERIVED)
- `this+0x000008E8` `double front_damper_load_d` (read, DERIVED)
- `this+0x000008F0` `byte wheel_bypass_flag_1` (read, DERIVED)
- `this+0x000008F4` `double wheel_accumulator_1` (read_write, DERIVED)
- `this+0x00000D3C` `double rear_damper_load_a` (read, DERIVED)
- `this+0x00000D44` `double rear_damper_load_a_alt` (read, DERIVED)
- `this+0x00000D4C` `double rear_damper_load_b` (read, DERIVED)
- `this+0x00000D54` `byte wheel_bypass_flag_2` (read, DERIVED)
- `this+0x00000D58` `double wheel_accumulator_2` (read_write, DERIVED)
- `this+0x000011A0` `double rear_damper_load_c` (read, DERIVED)
- `this+0x000011A8` `double rear_damper_load_c_alt` (read, DERIVED)
- `this+0x000011B0` `double rear_damper_load_d` (read, DERIVED)
- `this+0x000011B8` `byte wheel_bypass_flag_3` (read, DERIVED)
- `this+0x000011BC` `double wheel_accumulator_3` (read_write, DERIVED)
- `this+0x0000141C` `pointer body_transform_ptr` (read, DERIVED)
- `this+0x00001438` `double anti_roll_scale_front` (read, DERIVED)
- `this+0x00001440` `double anti_roll_scale_rear` (read, DERIVED)
- `this+0x00001448` `double torque_scale_a` (read, DERIVED)
- `this+0x00001450` `double torque_scale_b` (read, DERIVED)
- `this+0x00001460` `byte piecewise_correction_flag` (read, DERIVED)
- `this+0x000015F0` `pointer hub_transform_ptr` (read, DERIVED)
- `*(this+0x141C)+0x00000004` `double body_translation_x` (read, DERIVED)
- `*(this+0x141C)+0x0000000C` `double body_translation_y` (read, DERIVED)
- `*(this+0x141C)+0x00000014` `double body_translation_z` (read, DERIVED)
- `*(this+0x141C)+0x00000064` `double body_secondary_x` (read, DERIVED)
- `*(this+0x141C)+0x0000006C` `double body_secondary_y` (read, DERIVED)
- `*(this+0x141C)+0x00000074` `double body_secondary_z` (read, DERIVED)
- `*(this+0x141C)+0x0000007C` `double body_rotation_row0` (read, DERIVED)
- `*(this+0x141C)+0x00000084` `double body_rotation_row1` (read, DERIVED)
- `*(this+0x141C)+0x0000008C` `double body_rotation_row2` (read, DERIVED)
- `*(this+0x15F0)+0x00000004` `double hub_translation_x` (read, DERIVED)
- `*(this+0x15F0)+0x0000000C` `double hub_translation_y` (read, DERIVED)
- `*(this+0x15F0)+0x00000014` `double hub_translation_z` (read, DERIVED)
- `*(this+0x15F0)+0x00000064` `double hub_secondary_x` (read, DERIVED)
- `*(this+0x15F0)+0x0000006C` `double hub_secondary_y` (read, DERIVED)
- `*(this+0x15F0)+0x00000074` `double hub_secondary_z` (read, DERIVED)
- `*(this+0x15F0)+0x0000007C` `double hub_rotation_row0` (read, DERIVED)
- `*(this+0x15F0)+0x00000084` `double hub_rotation_row1` (read, DERIVED)
- `*(this+0x15F0)+0x0000008C` `double hub_rotation_row2` (read, DERIVED)

### WheelContactNormalForceSolver

Per-contact wheel-ground normal force solve: body angular-velocity terms and an ambiguous body-vector term (this+0x1654..0x167C) used to form the contact-point velocity for the friction-modulated force.

Methods: `0x00443150`

- `this+0x00001654` `double body_angular_velocity_x` (read, DERIVED)
- `this+0x0000165C` `double body_angular_velocity_y` (read, DERIVED)
- `this+0x00001664` `double body_angular_velocity_z` (read, DERIVED)
- `this+0x0000166C` `double body_vector_x` (read, GUESS)
- `this+0x00001674` `double body_vector_y` (read, GUESS)
- `this+0x0000167C` `double body_vector_z` (read, GUESS)

### CollisionAllocatorShim

One-expression shim forwarding the module-global allocation target ppvOut (0x007CA590) to the allocation routine.

Methods: `0x0044C5E0`


### CollisionMaterialConfig

Collision material coefficient configuration: unconditional initializers that write per-set material-type IDs and coefficient blocks into consecutive module globals; no owned instance state is evidenced.

Methods: `0x0044C860`, `0x0044CFE0`, `0x0044D5E0`, `0x0044DD60`, `0x0044E4E0`, `0x0044EC60`


### CollisionStateConfig

Collision state configuration: unconditional init of the version/magic identifier and zeroed reset fields of a six-dword collision state block.

Methods: `0x0044E060`


### CollisionNode

Collision tree node accessor returning a child offset (this+76) when the presence/link flag at this+0x0 is set.

Methods: `0x0044EE00`

- `this+0x00000000` `dword presence_link_flag` (read, GUESS)

### CollisionObjectStore

Collision/device capability store: keeps a type id (this+0x278) or capability version (this+0x2F4) and the copied 0x244-byte capability payload at this+0x8/this+0x84; populated by the device-enumeration callback path.

Methods: `0x0044EFC0`, `0x0044FBB0`

- `this+0x00000084` `pointer payload_store` (write, DERIVED)
- `this+0x00000278` `dword type_id` (write, DERIVED)
- `this+0x000002F4` `dword capability_version` (write, DERIVED)

### CollisionForceAccumulator

Collision force accumulator holding the clamped accumulated force at this+0xAC; updated with a signed coefficient selected by caller flags.

Methods: `0x00456F70`

- `this+0x000000AC` `float force_accumulator` (read_write, DERIVED)

## Compatibility contracts

- **CollisionAudioFeedbackPreparation** — MilesAudioSamplePlaybackSetup (0x00405900) invokes 0x00405E60 to prepare collision audio feedback. The function stores the collision parameter (this+0x48), position (this+0x28/0x2C/0x30) and velocity (this+0x34/0x38/0x3C), computes a clamped [0,1] intensity into this+0x40 using the collision object's vtable getters (vtable+0x30, +0x58), and returns 1 (cleanup, no feedback) when intensity is zero or 0 (active) with the position-delta magnitude emitted into the output pair a6/a7.
- **SuspensionSpringDamperTick** — GetBodyMotionState (0x00447100) calls 0x00435E60 each frame with a suspension-frame vector (a2) and outputs force (a3) and torque (a4). A null body pointer at this+0x0 zeroes both outputs; otherwise the force is clamped to per-axis windows (this+0x1C..0x44) and the torque to 64-bit double-pair windows (this+0x64..0x8C), scaled by globals flt_7CFB48 and flt_7CFB6C. A replacement must preserve the per-axis clamp windows and the 64-bit bound layout.
- **WheelContactNormalForceSolve** — DamperSpringForceComputationWithAntiRoll (0x004432F0) invokes 0x00443150 per wheel corner. The solve runs only when the contact-active flag byte (a2[0]) is nonzero; it assembles a world-space contact force from the body rotation matrix and slip velocity and accumulates angular momentum into the body through AccumulateAngularMomentum (0x00569AD0).
- **VehicleSuspensionPhysicsTick** — PhysicsIntegrationStep (0x00441D60) calls 0x00442C90 every frame. It walks four 1124-byte wheel blocks from this+0x410 (skipping any block whose bypass byte at this+0x48C/0x8F0/0xD54/0x11B8 is set), applies ConstraintEnforce (0x004380B0) per wheel, accumulates front/rear anti-roll torque (gated by the same bypass bytes, optionally adding half of a PiecewiseFunctionEval correction when this+0x1460 is set), and in a second pass feeds AccumulateAngularMomentum (0x00569AD0) and F_3DVectorSubtractWithCrossProduct (0x00569B70). It returns 0. Tire-model mode is gated by dword_7CE958.
- **PhysicsBufferAllocatorInit** — Thunk_1bc0 (0x00431BC0) constructs the allocator through 0x00431D40, which allocates two 80-byte and one 128-byte buffer via OperatorNewNhMallocWrapper (0x00587C03), stores (pointer,size) pairs at this+0x0/0x4, this+0x8/0xC and this+0x10/0x14, zeroes each buffer's first byte and the trailing this+0x18..0x3C, and returns this. No deallocation path is evidenced in this packet.
- **CollisionMaterialConfigInit** — CollisionMaterialCoefficientsSet1/2/3/4/5/6 (0x0044D5E0, 0x0044DD60, 0x0044E4E0, 0x0044EC60, 0x0044C860, 0x0044CFE0) unconditionally write per-set material-type IDs (19, 52, 80, 100, 7) and coefficient fields (range threshold 18000) into consecutive module-global blocks, and CollisionStateClear (0x0044E060) writes the collision version/magic 68 to dword_7CCD68 and zeroes the block. A replacement must preserve the block IDs and the 18000/68 literals.
- **DeviceCapabilityBlockCopy** — Device-enumeration callback sub_44ED10 (0x0044ED10) drives CollisionStructDataStore (0x0044EFC0) and CollisionDataCopy (0x0044FBB0), which store a type id at this+0x278 / capability version at this+0x2F4 and bulk-copy a 0x244-byte capability block into this+0x8 / this+0x84. A replacement must preserve the 0x244-byte payload size and the +0x278/+0x2F4 tag fields.
- **SuspensionBarLookupDiagnostics** — SuspensionBarLookup (0x0043AF50) searches a struct array by string via LinearSearchInStructArrayByString (0x0056EB30); on a miss it zeroes the output a3 and, gated by dword_7C569C != 5 and StringSplitLoop (0x004D7A50), logs the failure through DebugLogWrite (0x004D7AA0) with the buffer at dword_8AD25C and the aCouldNotFindSu string.

## Unresolved

- Offset reuse across distinct receiver objects: this+0x00..0x48 (vtable vs buffer pairs vs matrix doubles vs target pointer), this+0x84 (torque clamp max y vs capability payload store), this+0x15F0 (geometry base vs hub transform pointer vs body-state pointer), this+0x160C..0x164C (geometry rotation matrix vs body rotation matrix) are read/written by unrelated functions. No common ownership is proven; per the no-merge rule each offset is declared on the class whose evidence is strongest and the reuse is recorded here.
- The exact values and roles of the constant globals dbl_59E420, dbl_59E430, flt_59E43C, flt_59E440, flt_59E4D8, flt_59E670, dbl_59E880, dbl_59EB28, dbl_59EB50, dbl_59EB58, dbl_59EC60, dbl_59EC78, dbl_59EC90, flt_59EF9C, flt_59EFA0 are not evidenced in the raw decompiled source; they appear to be compiler-folded constants (1.0/0.0, the 0.15/0.12/0.25 bias literals) and the existing InputScaleFactor/SuspensionTravelOffset/WearAccumulationRate labels are DERIVED/GUESS.
- CollisionAudioFeedbackState: the semantics of the collision object's vtable entries at +0x30 (intensity multiplier) and +0x58 (contact-type check, valid when it returns 1) are inferred from call shape only.
- PhysicsBufferAllocator: the ten zeroed DWORDs at this+0x18..+0x3C have no named role, and no deallocation path is evidenced in the packet.
- VehicleIdentifierAccessor: the object pointed to by this->field0 and the meaning of its +0x2C DWORD are unknown beyond an accessor role; caller HTMLSeasonOutput does not inform the field semantics.
- SuspensionSpringDamper: the layout of a2 (suspension-frame vector input) and the exact role of the scale globals flt_7CFB48/flt_7CFB6C follow skeleton-fill labels (DERIVED) and are not independently proven; dbl_59E420 is consumed inside a called helper (F_33MatrixMultiply or FloatConvertWrapper).
- WheelContactGeometry: the region at this+0x1614/0x161C/0x1624 serves both as a rotation-matrix row and as the suspension offset vector in different reads; the two interpretations cannot be resolved from this packet.
- WheelContactNormalForceSolver: the body vector at v3+124/132/140 (this+0x166C..0x167C) conflicts with the fill's body force/torque-accumulator label; a3 is consumed only at components [0] and [2]; whether AccumulateAngularMomentum also applies a linear force path is not visible here.
- VehicleSuspensionPhysicsTick: the mapping of dbl_59E420/dbl_59E880 to the normalization arithmetic is DERIVED; the per-wheel block-relative offsets (28, 76, 164, -388) and the 1124-byte wheel-block layout are not linked to named struct fields.
- SuspensionBarLookup: the searched struct-array entry layout (v3[0..4]) and the raw a2+28..92 double semantics are inferred from arithmetic; owner is unknown (free __stdcall function).
- WheelDamperAccumulator: the identity of the quadratic curve selected by this+0x1C00 is unestablished; PhysicsForceVelocityClamping clamps the same state fields and applies SpringDamperCompute / QuadraticForceTorqueCalculator whose output destinations are not shown in the packet.
- WheelStateHistory: the per-wheel history block stride (281 dwords), slot topology and the 32-byte sub-record copy are inferred from the loop; caller expectations for the returned pointer (0x00441360, 0x00441600) are outside this packet.
- accumulateWheelStateDelta: the pairing of the current-state array at this+0x15AC (48-byte stride) with the previous-state array at this+0x15B0 (580-byte stride) is inferred from the loop increments only.
- CollisionAllocationThunk: MemoryAllocation_31a0's address and semantics are absent from the packet callee set.
- CollisionMaterialConfig / CollisionStateConfig: the material-type and threshold semantics (IDs 7/19/52/80/100, range 18000, version 68) are DERIVED labels with no consumer evidence; the relationship of the Set1..Set6/StateClear initializers to a larger material table is not proven.
- CollisionNodeNextChild: the object type and the layout at this+76 are unknown; field this+0x0 is also read as a vtable pointer by 0x00405E60 and as a buffer pointer by 0x00431D40 (offset reuse).
- CollisionStructDataStore/CollisionDataCopy: the 0x244-byte payload is carried across 62 stack arguments; its original frame layout and the meaning of the type id (this+0x278) / capability version (this+0x2F4) are unproven.
- CollisionCoefficientApplication: the a3==1 (6.0) vs default (0.4) selector and the a2 negation semantics come from the skeleton fill (DERIVED); the three float globals (0x59E670, 0x59EF9C, 0x59EFA0) are not visible in the raw source.
- FloatFloatInitTo (called by 0x0044CFE0) and MemoryAllocation_31a0 (called by 0x0044C5E0) are absent from the packet callee set, so their targets and semantics cannot be verified.
- The exact contact-type validity value (1) and the active-flag location (a2[0]) of solveWheelContactNormalForce depend on the caller contact-buffer layout, which is not defined in this packet.
