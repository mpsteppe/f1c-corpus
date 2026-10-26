# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

This proposal organizes 22 generic runtime functions into conservative classes: a UIElementLayout cluster (position/alignment fields 0x8-0x1C rendering through 0x004DCA80), scene-graph classes (SceneGraphNode child query/classification, SceneGraphGeometryBuilder, FreeableResourceHolder destructor), the WheelGroundContactDatabase, HUD-related classes (UIElementRegistry, HUDElementConfigArray, SubsystemSlotProvider), the VehiclePhysicsActor grouping over the contiguous 0x32BC-0x3D60 region, and small single-purpose classes (RPMRangeTable, SegmentInterpolationTable, TeamColorRenderObject, ScoringFieldSelector). All ownership tiers stay within DERIVED/GUESS/UNKNOWN; every packet field offset is preserved on its own base; the unbound read-only globals and the indirectly dispatched callees are recorded as unresolved.

## Function roles

- `0x004DCDD0` **UIElementLayout** — Compute and store a screen position under one of nine alignment modes (0-8) then render via the element render sink
- `0x004DCF20` **UIElementLayout** — Write the caller-supplied value into this+0x1C then forward to the element render sink and propagate its result
- `0x004DCF30` **UIElementLayout** — Two-field getter: copy this+0x14 and this+0x18 into caller outputs guarded on non-null
- `0x004DCF50` **UIElementLayout** — Three-field getter: copy this+0x08/+0x0C/+0x10 into caller outputs guarded on non-null
- `0x004DD4D0` **FreeableResourceHolder** — Single-resource destructor: free the resource pointer at this+0x14 through the free wrapper when non-null
- `0x004DD4E0` **SceneGraphNode** — Compute the maximum per-child classification across scene-graph children using child-count and indexed accessor
- `0x004DD8F0` **SceneGraphNode** — Search scene-graph children for the maximum squared 3D vector magnitude, gated by per-child detail level
- `0x004DE610` **SceneGraphGeometryBuilder** — Build scene-graph geometry: per-child vertex records, triangle adjacency, and a transform array
- `0x004DF110` **WheelGroundContactDatabase** — Update the wheel-ground contact database after inserting a new contact depth; return whether any contact data changed
- `0x004E0D00` **UIElementRegistry** — One-time lazy initialization of a UI element: list-front move, position/color apply, initialized flag, activation sound, registry registration
- `0x004E18C0` **SubsystemSlotProvider** — Query subsystem readiness by index 0-13 across two slot arrays and two dedicated subsystem slots
- `0x004E2A00` **SceneGraphNode** — Scale two per-child floats across scene-graph children, optionally climbing the parent chain
- `0x004E2C70` **ScoringFieldSelector** — Select the value written to the scoring field at +0x984: delegated result or global default depending on the scoring gate flag
- `0x004E51A0` **VehiclePhysicsActor** — Per-frame axle damping update: clear wheel-force accumulators, handle the idle path, interpolate damper velocity, distribute anti-roll force
- `0x004ED030` **VehiclePhysicsActor** — Per-actor motion post-processing: lazy-init subsystems, advance the state machine, interpolate damping, select force-feedback source, solve tire-brush forces, conditionally clamp velocity
- `0x004EFF00` **VehiclePhysicsActor** — Compute the negated scalar projection of a force vector onto a direction vector; 0.0 when the direction is zero
- `0x004F01B0` **VehiclePhysicsActor** — Compute an interpolated along-track distance relative to a track segment with lap-wraparound correction
- `0x004F0D20` **TeamColorRenderObject** — Apply a team-color scale to a render object and propagate it downstream when the object's team color differs from the player's vehicle
- `0x004F1860` **VehiclePhysicsActor** — Conditional physics solver dispatch gated on the constraint field at +0x32BC
- `0x004F6BF0` **RPMRangeTable** — Parse minimum/maximum/natural RPM key-values for a gear index 0-4 into the receiver's float range array
- `0x004F6D90` **SegmentInterpolationTable** — Piecewise interpolation over a segment table with vtable-dispatch of each participating segment object
- `0x004F8850` **HUDElementConfigArray** — Per-index element configuration: delegate to HUD element config, flag the element, copy a 3-float payload

## Proposed classes

### UIElementLayout

UI element carrying a position (X/Y at +0x8/+0xC, Z or size at +0x10), width/height at +0x14/+0x18, and a setter field at +0x1C. Alignment-mode position computation (0x004DCDD0), a field-setter trampoline (0x004DCF20), a two-field getter (0x004DCF30) and a three-field getter (0x004DCF50) all render/forward through the shared element render sink 0x004DCA80.

Methods: `0x004DCDD0`, `0x004DCF20`, `0x004DCF30`, `0x004DCF50`

- `this+0x00000008` `float position_x` (read_write, DERIVED)
- `this+0x0000000C` `float position_y` (read_write, DERIVED)
- `this+0x00000010` `float z_or_size` (read_write, DERIVED)
- `this+0x00000014` `float width` (read, GUESS)
- `this+0x00000018` `float height` (read, GUESS)
- `this+0x0000001C` `int32 setter_field` (write, GUESS)

### SceneGraphNode

Scene-graph node owning children (enumerated via SceneGraphChildCount 0x0054C210 and LinkedListIndexedAccessor 0x0054C230), a parent pointer at +0x4C for chain climbing, and flag/classification state at +0x20 and +0x46. Children carry per-child floats at +244/+248 (velocity/fade per DERIVED names) and a flags dword at +20 documented only by raw source.

Methods: `0x004DD4E0`, `0x004DD8F0`, `0x004E2A00`

- `this+0x00000020` `uint32 child_class_flags` (read, GUESS)
- `this+0x00000046` `uint8 offset_subtract_flag` (read, GUESS)
- `this+0x0000004C` `pointer parent_node` (read, GUESS)

### SceneGraphGeometryBuilder

Geometry setup object (this of 0x004DE610): stores the root scene node at +0x4, child count at +0x8, per-child record array at +0xC, transform count at +0x10, transform array at +0x14, and a fill flag at +0x18. Builds per-child vertex records, triangle adjacency, and a two-pass index buffer.

Methods: `0x004DE610`

- `this+0x00000004` `pointer root_scene_node` (read_write, DERIVED)
- `this+0x00000008` `int32 child_count` (read_write, DERIVED)
- `this+0x0000000C` `pointer child_record_array` (write, DERIVED)
- `this+0x00000010` `int32 transform_count` (write, DERIVED)
- `this+0x00000014` `pointer transform_array` (read_write, DERIVED)
- `this+0x00000018` `uint8 transform_fill_done` (write, GUESS)

### FreeableResourceHolder

Object holding a single resource pointer at +0x14 that is freed through FreeWrapper_7bcf (0x00587BCF) by its destructor 0x004DD4D0 when non-null; used by array-cleanup and dual-array destructor paths.

Methods: `0x004DD4D0`

- `this+0x00000014` `pointer resource_ptr` (read, DERIVED)

### WheelGroundContactDatabase

Wheel-ground contact bookkeeping object: current depth key at +0x0, group count at +0x8 with descriptor array at +0xC, secondary contact count at +0x10 with array at +0x14, sorted entry count at +0x18, and per-entry contact data at +0x20. 0x004DF110 maintains the sorted contact-entry list and mutates vertex contact groups with soft-sphere deformation, relaxation, secondary resolution, and normal recompute.

Methods: `0x004DF110`

- `this+0x00000000` `float current_depth_key` (read_write, DERIVED)
- `this+0x00000008` `int32 group_count` (read, DERIVED)
- `this+0x0000000C` `pointer group_descriptor_array` (read, DERIVED)
- `this+0x00000010` `int32 secondary_contact_count` (read, DERIVED)
- `this+0x00000014` `pointer secondary_contact_array` (read, DERIVED)
- `this+0x00000018` `int32 sorted_entry_count` (read, DERIVED)
- `this+0x00000020` `byte[] per_entry_contact_data` (read, GUESS)

### UIElementRegistry

UI element registry object: 0x004E0D00 lazily initializes an element (list-front move, position/color apply, initialized flag at a2+64), plays the activation sound indexed by this+0x964, and registers/updates the element in global lookup arrays against the registry handle dword_5EA560 unless the global mode flag dword_8AB6E4 equals 2.

Methods: `0x004E0D00`

- `this+0x00000964` `int32 ui_sound_index` (read, DERIVED)

### SubsystemSlotProvider

Owner of subsystem readiness state: 0x004E18C0 queries readiness for indices 0-13, using a stride-296 slot array anchored at this+324 and a stride-68 array at this+1236 (raw constants, no packet field refs) plus dedicated pointer/ready-byte pairs for subsystems 4 (+0x5E4/+0x624) and 5 (+0x628/+0x668). Ready iff the slot pointer is allocated and its ready byte at slot+64 is zero.

Methods: `0x004E18C0`

- `this+0x000005E4` `pointer subsystem4_ptr` (read, DERIVED)
- `this+0x00000624` `uint8 subsystem4_ready_byte` (read, DERIVED)
- `this+0x00000628` `pointer subsystem5_ptr` (read, DERIVED)
- `this+0x00000668` `uint8 subsystem5_ready_byte` (read, DERIVED)

### VehiclePhysicsActor

Vehicle/actor physics state over the contiguous offset region 0x32BC-0x3D60 plus contact-subsystem anchors at +0xD0C/+0xD4C. Anti-roll axle damping and wheel-force distribution (0x004E51A0), per-actor motion post-processing with force-feedback selection and velocity clamping (0x004ED030), negated force-direction projection (0x004EFF00), along-track distance with lap wrap (0x004F01B0), and the gated solver dispatch (0x004F1860). Grouping is an inference from the shared +0x32BC gate and contiguous offsets; single-object ownership is not proven by the packet.

Methods: `0x004E51A0`, `0x004ED030`, `0x004EFF00`, `0x004F01B0`, `0x004F1860`

- `this+0x000032BC` `int32 physics_gate_flag` (read, DERIVED)
- `this+0x000034A8` `float suspension_travel` (read, DERIVED)
- `this+0x000034B8` `float force_vector_x` (read, DERIVED)
- `this+0x000034C4` `float force_vector_y` (read, DERIVED)
- `this+0x000034D0` `float force_vector_z` (read, DERIVED)
- `this+0x000034D4` `float position_x` (read, DERIVED)
- `this+0x000034D8` `float position_y` (read, DERIVED)
- `this+0x000034DC` `float position_z` (read, DERIVED)
- `this+0x000034EC` `float direction_x` (read, DERIVED)
- `this+0x000034F0` `float direction_y` (read, DERIVED)
- `this+0x000034F4` `float direction_z` (read, DERIVED)
- `this+0x00003570` `float leading_force_term` (read_write, DERIVED)
- `this+0x00003578` `float damper_scale` (read_write, DERIVED)
- `this+0x000035D4` `float wheel_force_front_left` (read_write, DERIVED)
- `this+0x000035D8` `float front_axle_damping_left` (write, DERIVED)
- `this+0x000036CC` `float wheel_force_front_right` (read_write, DERIVED)
- `this+0x000036D0` `float front_axle_damping_right` (write, DERIVED)
- `this+0x000037C4` `float wheel_force_rear_left` (read_write, DERIVED)
- `this+0x000037C8` `float rear_axle_damping_left` (write, DERIVED)
- `this+0x000038BC` `float wheel_force_rear_right` (read_write, DERIVED)
- `this+0x000038C0` `float rear_axle_damping_right` (write, DERIVED)
- `this+0x00003964` `int32 wheel_travel_compare_flag` (read, GUESS)
- `this+0x00003978` `float suspension_stiffness` (read, DERIVED)
- `this+0x00003994` `float wheel_travel` (read_write, DERIVED)
- `this+0x0000399C` `float travel_clamp_threshold` (read, DERIVED)
- `this+0x000039A0` `float anti_roll_force` (read_write, DERIVED)
- `this+0x000039A4` `pointer damper_lookup_table` (read, DERIVED)
- `this+0x000039A8` `float damped_baseline` (read_write, DERIVED)
- `this+0x000039AC` `float damped_velocity` (read_write, DERIVED)
- `this+0x000039B4` `int32 distribution_mode` (read, DERIVED)
- `this+0x000039B8` `float travel_accumulator` (read_write, DERIVED)
- `this+0x000039C4` `float accumulator_threshold` (read, DERIVED)
- `this+0x000039C8` `float force_factor` (read, DERIVED)
- `this+0x000039F0` `pointer distribution_gate` (read, DERIVED)
- `this+0x00003A30` `float damping_coef_a` (read, DERIVED)
- `this+0x00003A34` `float damping_coef_b` (read, DERIVED)
- `this+0x00003A44` `float damping_coef_c` (read, DERIVED)
- `this+0x00003A48` `float damping_coef_d` (read, DERIVED)
- `this+0x00003A6C` `float damping_value` (read_write, DERIVED)
- `this+0x00003A70` `float force_feedback_output` (read_write, DERIVED)
- `this+0x00003A78` `float damping_target` (read, DERIVED)
- `this+0x00003A7C` `float inactive_contact_source` (read, DERIVED)
- `this+0x00003A80` `float active_contact_source` (read, DERIVED)
- `this+0x00003D60` `int32 one_shot_reset_flag` (read_write, DERIVED)
- `this+0x00000D0C` `pointer contact_subsystem_ptr` (read, DERIVED)
- `this+0x00000D4C` `uint8 contact_ready_byte` (read, DERIVED)

### RPMRangeTable

Receiver object holding per-gear RPM range floats at this[3*a3+1..3] (minimum, maximum, natural). 0x004F6BF0 parses the aMinimumrpm/aMaximumrpm/aNaturalrpm config keys for a guarded gear index 0-4, scaling RPM values by the rad/s conversion constant.

Methods: `0x004F6BF0`


### SegmentInterpolationTable

Piecewise interpolation table: segment count at +0x0, segment low/high/third float triples from +0x4 with 12-byte stride, and a callback-object array at +0x40. 0x004F6D90 scans the parameter window, invokes each skipped segment's object via vtable+8, and blends between adjacent segments invoking vtable+4.

Methods: `0x004F6D90`

- `this+0x00000000` `int32 segment_count` (read, DERIVED)
- `this+0x00000004` `float[3] segment_low_bounds` (read, DERIVED)
- `this+0x00000008` `float[3] segment_high_bounds` (read, DERIVED)
- `this+0x00000040` `pointer[] callback_object_array` (read, DERIVED)

### TeamColorRenderObject

Render/team-color object: render-object pointer at +0x0 and team-color identifier at +0x4. 0x004F0D20 defaults the scale to 1.0, and when the identifier differs from the current player's vehicle field at +18580 (dword_7C54F0 indexed by dword_7C54DC) it runs a guarded render call and a 3D matrix transform whose carry flags select the renderer team-color scale at dword_7CF83C, then propagates the scale downstream.

Methods: `0x004F0D20`

- `this+0x00000000` `pointer render_object_ptr` (read, DERIVED)
- `this+0x00000004` `int32 team_color_id` (read, DERIVED)

### ScoringFieldSelector

Object with a scoring field at +0x984. 0x004E2C70 writes either the delegated x87 result (when the scoring gate flag dword_8AB6E4 equals 2, delegating to 0x004B9CE0 with &dword_8AB6EC) or the global default double dbl_8AFEA0 cast to float.

Methods: `0x004E2C70`

- `this+0x00000984` `float scoring_field` (write, DERIVED)

### HUDElementConfigArray

Float-array HUD element table: 0x004F8850 configures the element indexed by a2 through HUDElementConfig (0x004F87C0), flags it by writing 1 to this[8*a2+49], and copies a 3-float payload into this[8*a2+50..52]. Element stride of 32 floats is implied by the expressions.

Methods: `0x004F8850`


## Compatibility contracts

- **UIElementLayoutAlignmentDispatch** — Alignment mode a5 (0-8) selects how the X/Y anchors are computed from width/height; a4 is stored unconditionally into the +0x10 field at entry; an out-of-range mode takes the default path that renders via 0x004DCA80 without recomputing position (previous position is rendered). A replacement must preserve the nine modes and the default-fall-through behavior.
- **SceneGraphChildEnumeration** — Scene-graph children are enumerated via SceneGraphChildCount (0x0054C210) and LinkedListIndexedAccessor (0x0054C230); parent-chain climbs read the parent pointer at node+0x4C and terminate on a null pointer. Child classification reads the child flags dword at +20 and the float at +244.
- **WheelContactDirtyNotification** — When the wheel-ground contact database mutates any contact data, the change flag is set and every group target is marked by clearing flags with 0xFEFFFFDF and setting 0x400000; the normal recompute follows. A replacement must emit the dirty notification so renderers recompute face normals.
- **SubsystemReadyQuerySemantics** — Readiness for subsystem index 0-13: a subsystem is ready only when its slot pointer is allocated AND its ready byte (slot+64) is zero; an out-of-range index reports not ready. Subsystem 4 uses +0x5E4/+0x624, subsystem 5 uses +0x628/+0x668.
- **UIRegistryElementKeying** — UI elements are registered/updated in global lookup arrays keyed by their first dword matching the element pointer; a matched entry whose first value is -1 is handed to a lookup helper; the global mode flag dword_8AB6E4 equal to 2 bypasses the registry tail. The element lookup arrays are indexed via the registry handle dword_5EA560.
- **RPMRangeParseSemantics** — Gear index a3 is guarded to 0..4; minimum/maximum RPM values are scaled by the rad/s conversion constant; natural RPM stores the reciprocal of the converted value, or 0.0 when the parsed natural RPM is not positive; a read status of exactly 2 terminates parsing early. Receiver layout is this[3*a3+1..3].
- **ScoringGateFlagDispatch** — When the scoring gate flag dword_8AB6E4 equals 2, the scoring field at +0x984 receives the delegated x87 result from 0x004B9CE0(&dword_8AB6EC); otherwise it receives dbl_8AFEA0 cast to float.
- **ForceFeedbackSourceSelection** — The force-feedback output at +0x3A70 is copied from the active-contact source (+0x3A80) when the contact pointer at +0xD0C is non-null and the contact-ready byte at +0xD4C is clear; otherwise the inactive-contact source (+0x3A7C) is used.
- **DampingHalfStepInterpolation** — Each actor update steps the damping value at +0x3A6C halfway toward its target at +0x3A78 when they differ: (target + value) * 0.5.

## Unresolved

- Object owners for most functions are UNKNOWN in the packet; the classes here are conservative groupings by shared offset ranges and shared callees, not proven single objects.
- The vehicle physics offsets 0x32BC-0x3D60 form one contiguous region used by five functions, but no packet evidence proves a single owning object; the VehiclePhysicsActor grouping is an inference (shared +0x32BC gate is the strongest link).
- Equal offsets on different bases are kept as separate fields (e.g. +0x14 on UIElementLayout/FreeableResourceHolder/SceneGraphGeometryBuilder, +0x20 on SceneGraphNode/WheelGroundContactDatabase, +0x00/+0x04/+0x08 on WheelGroundContactDatabase vs SegmentInterpolationTable vs TeamColorRenderObject); common ownership is not proven.
- Read-only globals flt_59E420/59E430/59E43C/59E440/59E450/59E46C/59E670/59E7F8/59ED18/59EF78, flt_5ACD3C/5AD13C/5AD144/5AD148 and dword_8ACEE0 are flagged by packet facts but do not appear in the raw bodies; none is bound to a specific instruction.
- global:0x004E1958 follows the SubsystemReadyQuery jump table in memory and is flagged as data; it is not referenced by the function body.
- Child struct offsets +244/+248 (scene-graph floats) and +288 (triangle count) and the +20 flag bits are documented only by the raw source, not by packet field evidence.
- field:this:0x00000020 has different meaning per class: child-class flags on SceneGraphNode, per-entry contact data on WheelGroundContactDatabase.
- field:obj:0x00004040 (the session-state flag object read by ProjectedDistanceWithLapWrap) has no named owner.
- The vtable +4/+8 dispatch in SegmentInterpolationTable is indirect; callee identities, the argument literal 2, and the trailing 0 are unresolved.
- The caller relationship of SegmentInterpolationTable to SuspensionForceComputationWithPerCornerVirtualDi (0x004F8440) is inferred from the call graph; 0x004F8440 is outside the packet's allowed evidence refs.
- SubsystemSlotProvider's stride-296 (this+324) and stride-68 (this+1236) slot arrays come from raw constants and have no packet field refs; only the dedicated subsystem 4/5 fields are typed.
- HUDElementConfigArray's 32-float element stride and the flag/payload positions are implied by the index expressions, not confirmed by packet fields.
- UIElementRegistry's global lookup arrays unk_5EA5A8..5EA5C8 and the helper calls sub_410AF0, ArithmeticComparison_df90 and NestedLoopCall are present in raw source but absent from the packet fact surface.
- RPMRangeTable's receiver array layout (this[3*a3+1..3]) is untyped; parameter a2 is passed by the caller but never referenced by the body.
- The ABI lead names Camera_FOV_Zoom_by_Proximity (for 0x004F0D20) and other LEGACY abi leads contradict observed behavior and are not treated as evidence.
