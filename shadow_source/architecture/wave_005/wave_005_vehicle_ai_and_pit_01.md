# VehicleAIAndPit

Scope: `vehicle_ai_and_pit`  
Trust: `DERIVED`

This packet reconstructs the vehicle-AI and pit subsystem as a set of object classes and free-form frame-path computations. CommandQueue owns the AI command pair buffer (this+0x44A8, count this+0x44B0) and performs duplicate-command linear search. AIStateBuffer left-shifts two history buffers and sets four 0.5f weight fields plus an activation flag. AISpatialQuery delegates nearest-neighbor queries to the scene spatial tree (dword_5EA2C0). LateralForceModel computes pairwise proximity-weighted lateral interaction forces over the global vehicle pointer array (dword_7C54F0, count dword_5C329C) each frame. VehicleSteering performs front steering-geometry setup and angle computation from suspension-bar lookups. ConstraintSolver iterates 100-byte joint constraint records and 18-dword constraint elements, applies Gram-Schmidt projection, evaluates piecewise responses, and accumulates corrective impulses. TireSlipModel computes per-wheel slip forces, a longitudinal force modifier, and wheel-contact/particle effects on the frame path. F1CPitMachine holds the owner vehicle pointer and the pit-stop circular buffer (data 0x9B0, size 0x9B4, write index 0x9B8, read index 0x9BC), detects pit-stall proximity, and looks up teammate pit status by team ID (obj+0x48A4). SinglyLinkedList is a two-head list container with tail append; MilesAudioPollState, SteeringAssistTolerance, and FixedSizeContainer are small GUESS-owner helpers. SetContactConstraint, SteeringSensitivityInit, and AudioMixerGainInit remain owner-unknown. Ownership across the constraint methods is not independently proven; several raw vehicle-struct and a2-relative offsets are not part of the allowed evidence set and are described in unresolved only.

## Function roles

- `0x00405B50` **MilesAudioPollState** — Poll Miles audio sample playback status via AIL_sample_status; return the loop-mode flag (this+0x14) when the status is DONE(4) or STOPPED(16), otherwise return 2.
- `0x00424E30` **CommandQueue** — Linear search over the AI command queue's 8-byte {commandID,param} pairs for a duplicate command ID; return 1 on match else 0 for duplicate-command detection.
- `0x0042ADD0` **AISpatialQuery** — Delegate a spatial nearest-neighbor query: forward the object position and two search parameters to SpatialTreeNearestNeighborSearch on the scene spatial tree (dword_5EA2C0) with filter 0 and return the nearest-neighbor handle.
- `0x0042CAA0` **LateralForceModel** — Compute pairwise proximity-weighted lateral interaction forces across all active vehicles (dword_7C54F0, count dword_5C329C) and write the resultant (x,0,z) vector into each vehicle at offset 14948; called per frame by MainGameTickUpdate.
- `0x0042EC60` **AIStateBuffer** — Initialize the AI state buffer: left-shift two history buffers (0xC4- and 0xBC4-based, 64-byte stride), set four float fields at 0x1CA8-0x1CB4 to 0.5f, and set the activation byte at this+0x0 to 1; return 1056964608.
- `0x00431930` **UnknownObject** — Store a per-entry wheel contact-constraint value (float slot at dword index a2+1841) and mark the entry active (byte flag at byte offset a2+7360); called during wheel-dynamics initialisation.
- `0x004359A0` **ConstraintSolver** — Solve rigid-body joint constraint records between two bodies: transform anchor directions, form position/angular deltas, apply corrective angular-momentum impulses, and return the number of records processed.
- `0x004380B0` **ConstraintSolver** — Constraint response step: compute displacement error from the reference value (this+0x1F8), write position (this+0x1E8) and velocity (this+0x1F0) error terms, evaluate PiecewiseFunctionEval, and store the response to a caller-derived output pointer.
- `0x00438930` **ConstraintSolver** — Gram-Schmidt projection step: dot the reference constraint direction with the direction being orthogonalized, subtract the scaled projection, and return the dot product used as the projection factor.
- `0x0043B040` **VehicleSteering** — Set up front steering geometry for both wheels: match suspension components by geometry id and name, apply the steering angle via a tan-based formula, and rebuild wheel rotation matrices; log an error when the eight components are missing.
- `0x0043B590` **VehicleSteering** — Compute steering geometry for both front wheels from left/right steering suspension bars and fore upper/lower suspension points; store left/right steering angles at this+0x163C and this+0x1650.
- `0x0043BA20` **ConstraintSolver** — Search the constraint element array (this+0x15C8, count this+0x15C4) for the element whose body-pair identifiers match this+0x15F0/this+0x141C, then accumulate the incoming delta and compute the constraint force for the matched element.
- `0x004472B0` **TireSlipModel** — Compute per-wheel tire slip factors and force slots, a longitudinal force modifier, wheel-contact effects, and normalized per-wheel values on the frame path; called from the vehicle physics tick.
- `0x0044C9F4` **UnknownObject** — Initialize steering-sensitivity globals: write 0.0 to flt_7CCCB8 and 1065353216 to dword_7CCCBC.
- `0x0044CF94` **UnknownObject** — Initialize audio mixer gain globals: write the decimal literal -1082130432 to dword_7CA488 and 0.0 to flt_7CA48C.
- `0x0044DAC0` **ConstraintSolver** — Initialize a six-dword global constraint-solver parameter block: store literal 45 into dword_7CCEB8 and zero dword_7CCEBC..dword_7CCECC; return 0.
- `0x00486480` **SinglyLinkedList** — Append a node to the tail of the singly-linked list rooted at this+0xCC, walking node next-pointers at node+0x18.
- `0x00486500` **SinglyLinkedList** — Append a node to the tail of the singly-linked list rooted at this+0xD4, walking node next-pointers at node+0x18; structural mirror of the sibling append helper.
- `0x004A5C40` **F1CPitMachine** — Look up the team-mate vehicle's part value: scan the global vehicle pointer array dword_7C54F0 for a different vehicle with the same team ID (obj+0x48A4) and return its part value; called by ForcePitExit.
- `0x004B5DA0` **F1CPitMachine** — Pit-stall proximity check: query and lazily reinitialize the pit-stop circular buffer, walk entries backward from this+0x9B8, and register a collision contact when a stall is within reach.
- `0x004B67D0` **SteeringAssistTolerance** — Check whether an angular difference a2 is within a tolerance scaled by a difficulty/assist index (this+0x9AC) and an additional factor a3, using two switch-selected tolerance tables.
- `0x004B6940` **F1CPitMachine** — Append a new entry to the pit-stop circular buffer and write a float into its Z field (array this+0x9B0 + 176*writeIndex + 108), resetting the buffer via PhysicsObjectListManager when indices are invalid.
- `0x004BAA50` **FixedSizeContainer** — Construct a fixed-size element container: allocate 1016*count+4 bytes, store the count in the 4-byte header, and run an element initializer over each 1016-byte element; called by VehicleInstanceListBuilder.

## Proposed classes

### CommandQueue

Owns the AI command pair buffer and its count; supports duplicate-command detection through linear pair search.

Methods: `0x00424E30`

- `this+0x000044A8` `uint8* command_pair_buffer` (read, DERIVED)
- `this+0x000044B0` `int32 command_pair_count` (read, DERIVED)

### AIStateBuffer

Ring/history buffer for AI decision state: left-shifts two history buffers, holds four 0.5f weight fields, and carries an activation flag.

Methods: `0x0042EC60`

- `this+0x00000000` `uint8 activation_flag` (read_write, DERIVED)
- `this+0x000000C4` `float (64-byte stride) history_primary_base` (read_write, DERIVED)
- `this+0x000000C8` `float (64-byte stride) history_primary_successor` (read_write, DERIVED)
- `this+0x00000BC4` `float (64-byte stride) history_secondary_base` (read_write, DERIVED)
- `this+0x00000BC8` `float (64-byte stride) history_secondary_successor` (read_write, DERIVED)
- `this+0x00001CA8` `float weight_field_0` (write, DERIVED)
- `this+0x00001CAC` `float weight_field_1` (write, DERIVED)
- `this+0x00001CB0` `float weight_field_2` (write, DERIVED)
- `this+0x00001CB4` `float weight_field_3` (write, DERIVED)

### AISpatialQuery

Provides nearest-neighbor queries against the scene spatial tree (dword_5EA2C0) on behalf of AI callers.

Methods: `0x0042ADD0`

- `this+0x00004354` `float search_param_a` (read, DERIVED)
- `this+0x00004550` `float search_param_b` (read, DERIVED)

### LateralForceModel

Computes pairwise proximity-weighted lateral interaction forces across all active vehicles each frame and writes the resultant vector into each vehicle.

Methods: `0x0042CAA0`


### VehicleSteering

Performs front steering-geometry setup and angle computation from suspension-bar and steering-data lookups.

Methods: `0x0043B040`, `0x0043B590`

- `this+0x00000084` `float steering_ratio_factor` (read_write, DERIVED)
- `this+0x00000088` `float steering_ratio_zero_pair` (read_write, DERIVED)
- `this+0x0000008C` `float steering_factor_inverse` (read_write, DERIVED)
- `this+0x00000090` `float steering_factor_zero_pair` (read_write, DERIVED)
- `this+0x00000094` `float half_angle_offset` (read_write, DERIVED)
- `this+0x000000A4` `float steering_zero_a` (write, DERIVED)
- `this+0x000000A8` `float steering_zero_b` (write, DERIVED)
- `this+0x000003EC` `float* left_steering_geometry` (read, DERIVED)
- `this+0x00000850` `float* right_steering_geometry` (read, DERIVED)
- `this+0x000015C4` `int32 suspension_component_count` (read, DERIVED)
- `this+0x000015C8` `uint8* suspension_component_array` (read, DERIVED)
- `this+0x000015F0` `uint8* steering_geometry_ref` (read, GUESS)
- `this+0x00001630` `uint8* left_steering_data` (read, DERIVED)
- `this+0x00001634` `uint32 left_steering_data_copy_0` (write, DERIVED)
- `this+0x00001638` `uint32 left_steering_data_copy_1` (write, DERIVED)
- `this+0x0000163C` `float left_steering_angle` (write, DERIVED)
- `this+0x00001644` `uint8* right_steering_data` (read, DERIVED)
- `this+0x00001648` `uint32 right_steering_data_copy_0` (write, DERIVED)
- `this+0x0000164C` `uint32 right_steering_data_copy_1` (write, DERIVED)
- `this+0x00001650` `float right_steering_angle` (write, DERIVED)
- `*(this+0x1630)+0x00000000` `uint32 left_steering_data_dword_0` (read, DERIVED)
- `*(this+0x1630)+0x00000004` `uint32 left_steering_data_dword_1` (read, DERIVED)
- `*(this+0x1644)+0x00000000` `uint32 right_steering_data_dword_0` (read, DERIVED)
- `*(this+0x1644)+0x00000004` `uint32 right_steering_data_dword_1` (read, DERIVED)

### ConstraintSolver

Solves rigid-body joint and per-element constraints: world-space anchor resolution, Gram-Schmidt projection, error evaluation, and force/impulse accumulation.

Methods: `0x004359A0`, `0x004380B0`, `0x00438930`, `0x0043BA20`, `0x0044DAC0`

- `this+0x00000098` `int32 constraint_record_count` (read, DERIVED)
- `this+0x0000009C` `uint8* constraint_records_base` (read, DERIVED)
- `this+0x0000015C` `uint8* constraint_data_ptr` (read, DERIVED)
- `this+0x00000178` `float constraint_reference_dir_x` (read, DERIVED)
- `this+0x00000190` `float constraint_reference_dir_y` (read, DERIVED)
- `this+0x000001A8` `float constraint_reference_dir_z` (read, DERIVED)
- `this+0x000001E8` `float position_error` (read_write, DERIVED)
- `this+0x000001F0` `float velocity_error` (read_write, DERIVED)
- `this+0x000001F8` `float reference_value` (read, DERIVED)
- `this+0x000002A8` `float orthogonalized_dir_x` (read_write, DERIVED)
- `this+0x000002B0` `float orthogonalized_dir_y` (read_write, DERIVED)
- `this+0x000002B8` `float orthogonalized_dir_z` (read_write, DERIVED)
- `this+0x0000141C` `uint32 paired_body_id_b` (read, DERIVED)
- `this+0x00001420` `float incoming_delta` (read, DERIVED)
- `this+0x000015C4` `int32 constraint_element_count` (read, DERIVED)
- `this+0x000015C8` `uint8* constraint_element_array` (read, DERIVED)
- `this+0x000015F0` `uint8* body_ref` (read, GUESS)
- `*(this+0x15C8)+0x00000004` `uint32 element_body_id_a` (read, DERIVED)
- `*(this+0x15C8)+0x00000008` `uint8* element_constraint_ptr_a` (read, DERIVED)
- `*(this+0x15C8)+0x0000000C` `uint32 element_body_id_b` (read, DERIVED)
- `*(this+0x15C8)+0x00000010` `uint8* element_constraint_ptr_b` (read_write, GUESS)
- `*(this+0x15C8)+0x00000018` `float element_field_18` (read, GUESS)
- `*(this+0x15C8)+0x00000020` `float element_force_x` (read_write, DERIVED)
- `*(this+0x15C8)+0x00000028` `float element_force_y` (read_write, DERIVED)
- `*(this+0x15C8)+0x00000030` `float element_force_z` (read_write, DERIVED)
- `*(this+0x15C8)+0x00000038` `unknown element_field_38` (unknown, GUESS)
- `*(this+0x15F0)+0x00000004` `float body_matrix_m01` (read, DERIVED)
- `*(this+0x15F0)+0x0000000C` `float body_matrix_m11` (read, DERIVED)
- `*(this+0x15F0)+0x00000014` `float body_matrix_m21` (read, DERIVED)
- `*(this+0x15F0)+0x0000001C` `float body_matrix_m02` (read, DERIVED)
- `*(this+0x15F0)+0x00000024` `float body_matrix_m12` (read, DERIVED)
- `*(this+0x15F0)+0x0000002C` `float body_matrix_m22` (read, DERIVED)
- `*(this+0x15F0)+0x00000034` `float body_matrix_m03` (read, DERIVED)
- `*(this+0x15F0)+0x0000003C` `float body_matrix_m13` (read, DERIVED)
- `*(this+0x15F0)+0x00000044` `float body_matrix_m23` (read, DERIVED)
- `*(this+0x15F0)+0x0000004C` `float body_matrix_m04` (read, DERIVED)
- `*(this+0x15F0)+0x00000054` `float body_matrix_m14` (read, DERIVED)
- `*(this+0x15F0)+0x0000005C` `float body_matrix_m24` (read, DERIVED)
- `obj+0x00000004` `float body_position_x` (read, DERIVED)
- `obj+0x0000000C` `float body_position_y` (read, DERIVED)
- `obj+0x00000014` `float body_position_z` (read, DERIVED)
- `obj+0x00000064` `float body_vector_x` (read, DERIVED)
- `obj+0x0000006C` `float body_vector_y` (read, DERIVED)
- `obj+0x00000074` `float body_vector_z` (read, DERIVED)
- `obj+0x0000007C` `float body_inertia_row_x` (read, DERIVED)
- `obj+0x00000084` `float body_inertia_row_y` (read, DERIVED)
- `obj+0x0000008C` `float body_inertia_row_z` (read, DERIVED)

### F1CPitMachine

Owns the vehicle pit-machine state: team lookup, pit-stop circular buffer, and pit-stall proximity contact registration.

Methods: `0x004A5C40`, `0x004B5DA0`, `0x004B6940`

- `this+0x00000000` `uint8* owner_vehicle_ptr` (read, DERIVED)
- `this+0x000009B0` `uint8* stall_buffer_data` (read, DERIVED)
- `this+0x000009B4` `int32 stall_buffer_size` (read, DERIVED)
- `this+0x000009B8` `int32 stall_write_index` (read_write, DERIVED)
- `this+0x000009BC` `int32 stall_read_index` (read_write, DERIVED)
- `obj+0x000048A4` `int32 vehicle_team_id` (read, DERIVED)

### TireSlipModel

Computes per-wheel tire slip forces, a longitudinal force modifier, wheel-contact effects, and normalized per-wheel outputs on the frame path.

Methods: `0x004472B0`

- `this+0x00000008` `double mass_factor` (read, DERIVED)
- `this+0x00000060` `double collision_position` (read, DERIVED)
- `this+0x00000690` `double* per_wheel_table` (read, DERIVED)
- `this+0x000015F0` `uint8* vehicle_transform_ptr` (read, DERIVED)
- `this+0x000016E0` `uint32[4] wheel_contact_handles` (read, DERIVED)
- `this+0x000016F0` `double[4] wheel_contact_offsets` (read, DERIVED)
- `this+0x00001C5C` `double longitudinal_force_numerator` (read, DERIVED)
- `this+0x00001CDC` `double longitudinal_force_denominator` (read, DERIVED)
- `this+0x00001DE4` `double per_axis_force_x` (read_write, DERIVED)
- `this+0x00001DEC` `double per_axis_force_y` (read_write, DERIVED)
- `this+0x00001DF4` `double per_axis_force_z` (read_write, DERIVED)
- `this+0x00001F00` `uint8* vehicle_data_ptr` (read, DERIVED)
- `*(this+0x15F0)+0x00000004` `float transform_pos_x` (read, DERIVED)
- `*(this+0x15F0)+0x0000000C` `float transform_pos_y` (read, DERIVED)
- `*(this+0x15F0)+0x00000014` `float transform_pos_z` (read, DERIVED)
- `*(this+0x15F0)+0x00000064` `float transform_dir_x` (read, DERIVED)
- `*(this+0x15F0)+0x0000006C` `float transform_dir_y` (read, DERIVED)
- `*(this+0x15F0)+0x00000074` `float transform_dir_z` (read, DERIVED)
- `*(this+0x15F0)+0x0000007C` `float transform_cross_x` (read, DERIVED)
- `*(this+0x15F0)+0x00000084` `float transform_cross_y` (read, DERIVED)
- `*(this+0x15F0)+0x0000008C` `float transform_cross_z` (read, DERIVED)
- `*(this+0x16E0)+0x00000054` `uint8* wheel_surface_object_ptr` (read, DERIVED)
- `*(*(this+0x16E0)+0x54)+0x00000028` `uint32 wheel_surface_flag` (read, DERIVED)
- `*(this+0x1F00)+0x00004894` `uint32 collision_effect_param` (read, DERIVED)

### SinglyLinkedList

Singly-linked list container with two heads (this+0xCC and this+0xD4); supports tail append via node next-pointers at node+0x18.

Methods: `0x00486480`, `0x00486500`

- `this+0x000000CC` `uint8* list_head_a` (read_write, DERIVED)
- `this+0x000000E4` `uint8* list_tail_holder_a` (read, GUESS)
- `this+0x000000D4` `uint8* list_head_b` (read_write, DERIVED)
- `this+0x000000EC` `uint8* list_tail_holder_b` (read, GUESS)
- `*(*(this+0xE4)+0x18)+0x00000018` `uint8* node_next_ptr_a` (read, GUESS)
- `*(*(this+0xEC)+0x18)+0x00000018` `uint8* node_next_ptr_b` (read, GUESS)

### MilesAudioPollState

Audio-sample playback status polling state used with the Miles AIL API.

Methods: `0x00405B50`

- `this+0x00000014` `int32 loop_mode_flag` (read, DERIVED)
- `this+0x00000058` `uint8* sample_handle_struct` (read, DERIVED)
- `this+0x00000068` `int32 sample_status_slot` (read, DERIVED)

### SteeringAssistTolerance

Difficulty-scaled steering-alignment tolerance check using two switch-selected tolerance tables.

Methods: `0x004B67D0`

- `this+0x000009AC` `int32 difficulty_index` (read, DERIVED)

### FixedSizeContainer

Fixed-size element container with a 4-byte header and 1016-byte elements.

Methods: `0x004BAA50`

- `this+0x00000000` `uint8* element_array_ptr` (read_write, DERIVED)

## Compatibility contracts

- **AICommandQueuePairLayout** — The AI command queue holds 8-byte {commandID,param} pairs at this+0x44A8 with an entry count at this+0x44B0. A linear search over the pairs returns 1 when a pair's first dword equals the probe and 0 otherwise; the caller uses the result as a duplicate-command suppression signal.
- **PitStopCircularBufferLayout** — The pit-stop buffer stores its data array at this+0x9B0, size at this+0x9B4, write index at this+0x9B8, and read index at this+0x9BC. Entries are 176 bytes and the float at entry+108 receives the pit-stop Z position. When the buffer indices are invalid, the data array is reinitialized via PhysicsObjectListManager.
- **PitStallProximityContact** — PitStallProximityCheck walks the pit-stop stall buffer backward from the current index and registers a collision contact via CollisionObjectInsertion when the vehicle Z position is within 1.5 of a stall Z threshold.
- **SpatialNearestNeighborQuery** — Nearest-neighbor queries resolve against the scene spatial tree at dword_5EA2C0 with filter 0 and return a nearest-neighbor handle, or zero when none is found.
- **ConstraintElementArrayLayout** — The constraint element array lives at this+0x15C8 with count at this+0x15C4 and an 18-dword stride. Body-pair identifiers are matched at element+0x4 and element+0xC against this+0x15F0 and this+0x141C; constraint pointers are guarded at element+0x8 and element+0x10, and force components are written at element+0x20/+0x28/+0x30. The packet also reads element+0x10 as the output vector base, so its dual role is unresolved.
- **BodyRotationMatrixLayout** — The body rotation matrix reached via this+0x15F0 exposes rows used for constraint force computation at relative offsets +0x04..+0x5C, and the vehicle transform translation at +0x04/+0x0C/+0x14 with direction/cross vectors at +0x64..+0x8C used by tire effects.
- **AudioSampleStatusContract** — AudioSampleStatusPoll returns the loop-mode flag at this+0x14 when the Miles sample status is 4 (DONE) or 16 (STOPPED), otherwise returns 2; the sample handle is read at this[0x58]+16.

## Unresolved

- Ownership across the ConstraintSolver methods is not independently proven: 0x004359A0 reads a joint object (body A at this+0, records at this+0x98/0x9C), while 0x004380B0/0x00438930 read different field blocks (0x1E8-0x1F8, 0x15C/0x178-0x2B8) and 0x0043BA20 reads the element array at 0x15C4/0x15C8/0x15F0. The packet provides no proof they share one `this` object; they are grouped defensibly as one solver class.
- this+0x15F0 is read both as a body identifier (DWORD) for element matching in 0x0043BA20 and as a pointer to the body/vehicle rotation matrix block in the same function and in 0x004472B0/0x0043B040/0x0043B590; whether these are the same value is unresolved.
- The constraint element at +0x10 is guarded as a non-null constraint pointer AND written as the first element of the constraint output vector in 0x0043BA20; the packet itself is contradictory here.
- In ConstraintForceSolver the element field at relative offset 0x38 (listed RW) is not written by this function; it may be written by RelativeVelocityCompute or sub_56D2D0.
- SetContactConstraint (0x00431930) writes a float slot at dword index a2+1841 (byte 0x1CC4+4*a2) and a byte flag at byte offset a2+7360 (0x1CC0+a2); these parallel-array origins are outside the allowed evidence offsets, so no class fields are declared for them. The enclosing object layout and stride are unknown.
- The four 0.5f fields at 0x1CA8-0x1CB4 in AIStateBuffer are interpreted as weights/confidence only by prior analysis; the packet does not establish their semantic meaning.
- The element type and semantic meaning of the AIStateBuffer history buffers (64-byte stride) and of the FixedSizeContainer 1016-byte elements are not established.
- LateralForceModel and TireSlipModel reach the vehicle struct through raw integer offsets (e.g. +13524/+13528/+13532/+13536/+13544/+13548/+13556/+13568/+13620/+13628/+14948 for lateral force; per-wheel table base unk_7C7810 with 1124-byte stride; AISpatialQuery position pointer at this+13536) that are not part of the allowed evidence set, so their semantic meaning rests on skeleton-fill prose only.
- The packet-annotated constant-pool globals (dbl_59E420/dbl_59E428/dbl_59E430, flt_59E43C/flt_59E440, dbl_59E4E0, dbl_59E7E0, flt_59E7F8, flt_59E84C, dbl_59E880, flt_59E888, flt_59E8A4, flt_59E8A8, dbl_59E974, flt_59E9E0, flt_59E9E4, dbl_59EC10, dbl_59ECA8, dbl_59EEC0, dbl_59EEC8, flt_59EED0, dbl_59EED8, flt_59EEE0, dbl_59EEE8, flt_5ACD44, flt_5ACD58, flt_5ACD5C, flt_5ACD60, dword_8ACEA0) are reported read by the deterministic facts but appear nowhere in the raw decompiled source; they are presumed constant-pool operands, but the exact constant-to-global mapping is not established.
- AudioMixerGainInit writes the decimal literal -1082130432 to dword_7CA488; interpreting it as an IEEE-754 or two's-complement bit pattern is prohibited by worker rules, so its numeric meaning is left as written.
- RigidBodyConstraintJointSolver's summary names the physics integration step 0x00441D60 as a caller, but no caller:0x00441D60 reference is present in the allowed evidence set; this relationship is not asserted.
- AIStateBufferInitialize is described as called by CleanupWrapper (0x00433EB0) in its summary, but no caller:0x00433EB0 reference is in the allowed evidence set; the caller is not asserted.
- The exact mapping between the compiled double constants and the individual literals in VehicleSteering (1.0, 0.0, -0.5, reciprocal) and the semantics of a2+5168/a2+5176/a2+5184/a2+5188 steering factors are not recoverable from this packet.
- Constraint record layout (type dword at base, direction at +4/+28, second anchor at +52, limit at +76, coefficients at +84/+92, 100-byte stride) and constraint type values other than 0 and 2 are inferred from field usage, not a known struct definition.
- In ConstraintEnforce the raw source shows v4 as an uninitialized ecx register; the final output location at v4+516 (0x204) is not linked to a known field of `this`.
- SteeringAlignmentToleranceCheck's field 0x9AC is a difficulty/assist index 0..3; its exact meaning and setter are not evidenced here, and the a3 factor semantics are caller-dependent.
- The meaning of the return value 2 in AudioSampleStatusPoll (still playing or unknown status) is not grounded from the packet.
- The list walk in the append helpers reads node next-pointers at node+0x18, but the packet's indirect base notation does not match the raw register-based traversal; the exact tail-node base is unproven. Whether the two heads (0xCC and 0xD4) belong to one object or two is unknown.
- PitStallProximityCheck's first CircularBufferCheck call appears argument-less in the decompiler output; whether it also receives `this` is unclear.
- SteeringSensitivityInit (0x0044C9F4), AudioMixerGainInit (0x0044CF94), and SetContactConstraint (0x00431930) have no confirmed owning class; the exact runtime roles of flt_7CCCB8/dword_7CCCBC and dword_7CA488/flt_7CA48C are not evidenced beyond the writes.
- The teammate part value at obj+0x3450 read by TeammatePartValueLookup is not part of the allowed evidence offsets; its semantics are inferred from existing analysis only.
- No state machines are evidenced by this packet; state_machines is empty by design.
- The read-only constant-pool globals are also listed in unresolved_evidence_refs because the packet flags them as never appearing by name in the raw source; their placement in function evidence is attribution, not confirmation of constant identity.
