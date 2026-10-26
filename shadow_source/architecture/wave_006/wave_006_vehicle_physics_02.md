# VehiclePhysics

Scope: `vehicle_physics`  
Trust: `DERIVED`

DERIVED architecture for the vehicle_physics scope from 25 validated functions. A VehiclePhysicsState object (DERIVED) carries the per-frame suspension and wheel-contact physics: 0x004E58D0 (AccumulateSuspensionSpringDamperForce) accumulates a -9.81 gravity-scaled, stiffness-combined spring/damper force per corner into this[0x354C]/[0x3550]/[0x3554]; 0x004E8780 (SuspensionRatioClamp) returns the negated, [0,1]-clamped travel ratio this[0x39A8]/this[0x39AC]; 0x004E96C0 (Vehicle_Wheel_Contact_Proximity_Check) checks wheel-contact proximity with movement dead-zones, a rotation alignment split, and PositionChangeMonitor (0x004E9630) against the threshold at this+0x3B6C; 0x004B9CC0 (VehicleSpeedAccessor) reads the nested speed float at obj+0xF34. A VehiclePoseTransform group (GUESS) promotes float position/rotation to double (0x00459830) and builds the orientation matrix with network serialization (0x0045B050); a VehicleChassisTransform group (GUESS) applies local-to-world and chassis point transforms (0x004E2070, 0x004E2130). VehicleWheelContact (DERIVED) writes per-wheel contact flags (0x004EF560). Collision support classes (all GUESS): CollisionBroadphaseTraversal (0x00491170), CollisionPositionStepper (0x0048CB00), CollisionNodeList (0x004BAD70) and CollisionGlobalState (0x00475D30 configuration sync, 0x00494600 global zeroing). PhysicsObjectFactory (GUESS) dispatches through dword_7CD8C0 (0x004780B0, 0x0047A290); PhysicsConstantGlobals (GUESS) manages tire-model constant frees and the global physics vector (0x004F23C0, 0x004C7C50); TireStateBlock (GUESS) is zeroed by 0x004DFB90. VehicleHudDisplay (GUESS) covers the description getter, UI edit init, position/count formatting and the vehicle-list count (0x00463C80, 0x00474AB0, 0x0049C6D0, 0x004B8140); PhysicsChannelSet (GUESS) scans active physics channels (0x0045B580); SuspensionForceVisualizer (GUESS) draws the 2D suspension-force view (0x00475A90). All owners except the packet-listed VehicleWheelContact are worker proposals; none are packet-confirmed.

## Function roles

- `0x00459830` **VehiclePoseTransform** — Promotes float position (this+0x4/+0x8/+0xC) and rotation (this+0x10/+0x14/+0x18) to double: stores the position as three doubles at this+0xD8 and the computed 3x3 rotation tensor at this+0x138 via F_3x3RotationTensorMatrixTransform (0x005691D0), propagates the six dwords via Copy6DwordsToStructCall (0x00569280), copies the float position into this+0xC0/+0xC4/+0xC8 and into output a2, and returns a2. When the trigger flag at this+0xD0 is set, the external-processing call sub_54B4D0 (0x0054B4D0) and BufferEntryClear(0x8000000) (0x0054FAE0) run before the conversion. Invoked by StateDependentUpdateDispatch (0x0040F130).
- `0x0045B050` **VehiclePoseTransform** — Builds the vehicle orientation matrix as consecutive float triplets from this+0x60 using the negated velocity/direction components at this+0x108/+0x110/+0x118 and a sign-adjusted up component from this+0x318 with horizontal normalization from this+0x320 (zero-magnitude guarded), fills the matrix rows this+0x6C..0xBC, then serializes eight 12-byte matrix rows through NetworkPacketDataWriter (0x0054FA00). Returns the last writer result.
- `0x0045B580` **PhysicsChannelSet** — Scans up to 8 physics channels (23-float / 0x5C-byte stride) starting at this+36 (0x90). A channel is active when its first float is greater than 0.0. Returns the flat channel index (0-7) of the (a2+1)-th active channel, or 0 when fewer than a2+1 active channels exist. Invoked by sub_45B5C0 (0x0045B5C0).
- `0x00463C80` **VehicleHudDisplay** — Gets the vehicle description string: reads the object vtable first dword, adds 0xB4, and dereferences the resulting address as char*; returns the string when non-null, otherwise the fallback global byte_5EA438.
- `0x00474AB0` **VehicleHudDisplay** — Initializes a UI edit control: stores a pointer to the visible-vehicle-index global dword_7CFC8C at this+0x320 and a snapshot of the championship/race-mode global dword_7D0410 at this+0x324, formats the vehicle index with the '%d' format string global (0x005C3280) via StringFormatWithBufferOverflowCheck (0x0058815F), and pushes the text into the edit buffer via EditBufferStringUpdate (0x0048B810). Returns 0. Invoked by UIListInitWithDefault (0x00474A10).
- `0x00475A90` **SuspensionForceVisualizer** — Draws a 2D suspension-force visualization for the vehicle context at byte_7C56C0: after context setup sub_4881F0 (0x004881F0), guards on two UtilityFunction_7160 (0x00487160) anchor lookups, computes a wheel-speed pixel offset from dword_7C6C44/dbl_7C6C38/dbl_7C6C30 scaled by 9.549296585513721*0.0001, selects km/h (3.6) or mph (2.236936292054402) by byte_7D0474, reads the joint count via DynamicsJointCount (0x00431820), accumulates per-joint forces via TireSuspensionForceComputation (0x00431850), and draws line segments via ConditionalDraw (0x00475C80) and OffsetPositionComputation (0x00475CC0) with CRTFtol (0x00587BDC). Returns 0.
- `0x00475D30` **CollisionGlobalState** — Frame-change collision configuration sync: when the stored version dword_7CD614 differs from the current frame counter/version dword_7CE250, stamps the new version, updates physics module data from the module pointer array 0x007CA590 via ShortComputation_5bd0 (0x00455BD0), and reconfigures the contact stiffness and collision arrays (0x007CD458, 0x007CD45C, 0x007CD2B0, 0x007CD610) plus the value read from dbl_8AFE90 via sub_454DA0 (0x00454DA0). Invoked from F_2DRectangleDrawingWithOutline (0x00475D90).
- `0x004780B0` **PhysicsObjectFactory** — Indirect factory-style store: calls the virtual method at vtable offset 28 on the object referenced by dword_7CD8C0 with literal argument 21; when the returned pointer is non-null it is stored at this+0xE0 (this[56]). Returns 0.
- `0x0047A290` **PhysicsObjectFactory** — Clamps a suspension float across a global array: initializes display/dispatch state via SetupValueDisplayFormatter (0x00466910), fetches a source object through the dword_7CD8C0 dispatch interface (slot +0x1C, command 9), and when the source exists and the enable flag byte at this+0x100 is set, retrieves the value through this vtable slot +0xB4, validates the source with ZeroCheckGetter (0x00490190), and writes/clamps the value across the array from unk_7D17CC to flt_7D1B2C (27 dwords per element, bounds in element dwords 3 and 4). Returns 0.
- `0x0048CB00` **CollisionPositionStepper** — Steps a collision/animation position toward a target over time: total range = step (this+0x32C) x multiplier (this+0x328); accumulates a2 into this+0x340 and converts to a step count via CRTFtol(accumulator * 14.999999) (0x00587BDC); per step recomputes the target offset from this+0x338/this+0x334, wraps modulo the range, moves by the direction sign (byte this+0x33C) at a 0.444 rate with a minimum step of 1, wraps this+0x334, invokes the update callback through vtable slot 11 (obj+0x2C) with argument 1, and decrements the accumulator by 0.06666667 (1/15, flt_5AC108). Early-outs when the range or step count is non-positive.
- `0x00491170` **CollisionBroadphaseTraversal** — Recursive broadphase AABB traversal over a linked list: copies the head (this+0x0) into the cursor (this+0x8), walks nodes testing each node's four short AABB coordinates (offsets 0x0/0x2/0x4/0x6) against the next node with AABBOverlapTest (0x004915A0) returning 1 on the first overlap; when sub_491680 (0x00491680) accepts an AABB, RectangleClipping (0x00491350) produces a clip-result list that is recursed into (self 0x00491170) and re-linked via LinkedListNodePrepend (0x00490AA0). Returns 1 on a hit, 0 when the list is exhausted without overlap.
- `0x00494600` **CollisionGlobalState** — Zeroes four collision-system global DWORDs at 0x007CDDF0-0x007CDDFC and returns 0; runs on the collision system reset/shutdown path. No static callers are recorded in the packet.
- `0x0049C6D0` **VehicleHudDisplay** — Formats the current race position and total vehicle count into the output buffer a1 as the '%d/%d' pattern via StringFormatWithBufferOverflowCheck (0x0058815F): the position numerator is read from dword_7C54E0 + 16480, the vehicle-count denominator from dword_5C329C. Returns 0. Called by FormatRegisterDispatch (0x0049D440), DrawDebugTextOverlay (0x004DBB60) and MultiLayerTextStringRenderer (0x004DBC90).
- `0x004B8140` **VehicleHudDisplay** — Trivial getter returning the dword at this+0x6CC (this[435]); no side effects, no guards, no callees. The vehicle-list-count interpretation comes from the legacy ABI name; the raw source only reads the field.
- `0x004B9CC0` **VehiclePhysicsState** — Read accessor: loads the object pointer at this[0], reads the float at offset 0xF34 of the nested object, and returns it widened to double. The speed interpretation is not proven by this packet.
- `0x004BAD70` **CollisionNodeList** — Linked-list insertion on a list object with head/tail/count at this+0x0..0xC: when a2 is non-null, allocates a 12-byte node (flag byte 1, data = a2) via OperatorNewNhMallocWrapper(12) (0x00587C03) and appends it to the primary list. When byte a3 is zero, a second staggered pass walks *a2 plus a 884-byte stride and appends one flag-byte-0 node per stride position to a second list at this+0x10..0x1C. Returns the countdown result (0 after the loop). Called by NetworkMessageDispatch (0x004B54E0).
- `0x004C7C50` **PhysicsConstantGlobals** — Forwards to sub_4C7E80 with the address of the global float flt_8AC4B0 (0x008AC4B0) and returns the callee's result. The packet lists no callee entry for the target.
- `0x004DFB90` **TireStateBlock** — Constructor-style zero-initializer for a small tire-related state block: clears the byte fields at this+0x0/+0x1 and the six dword fields at this+0x4/+0x8/+0xC/+0x10/+0x14/+0x18, then returns 0. Invoked from PhysicsTireSystemConstructor (0x004E4500), VehicleResetClear (0x004E09E0) and sub_4DFBB0 (0x004DFBB0).
- `0x004E2070` **VehicleChassisTransform** — 3D local-to-world coordinate transform: builds a combined offset vector from the camera-relative offset (this[573..575], 0x8F4/0x8F8/0x8FC) summed with an additional offset (this[576..578], 0x900/0x904/0x908), multiplies by the 3x3 rotation matrix (this+0x20..0x40) into output a2, adds the base position (this+0x8..0x10), copies the matrix block into a local buffer (never read), then calls sub_567120 (0x00567120) with this+579 and forwards a3; returns the callee result. Invoked by CameraModeViewportUpdate (0x00409A00).
- `0x004E2130` **VehicleChassisTransform** — Transforms a 3D point by the chassis rotation/scale at this+0x14..0x40 combined with per-component scale factors at this+0x918..0x920, adds the translation read from the three floats preceding the matrix origin (this+0x8..0x10), writes output a2, copies three DWORDs at this+0x14..0x1C into output a3, and returns a3. No guards; the transform is always applied.
- `0x004E58D0` **VehiclePhysicsState** — Per-frame suspension spring/damper force accumulation for one corner: computes the gravity-scaled force from this[0x3514] * -9.81, projects it via the rotation matrix at 0x34B0..0x34D0, derives the displacement as the mount position (0x34F8..0x3500) minus the rotated rest anchor (0x3A58..0x3A60), squares each component, combines each squared displacement with its axis stiffness (0x3A64/0x3A68/0x3A6C) with FCOM-selected add/subtract, folds a cross-coupling term (0x3A70/0x3A74) into this[0x3558] on one axis, and accumulates the three results into this[0x354C]/[0x3550]/[0x3554]. No callees. Invoked from PhysicsIntegrationStateMachine (0x004E4E60).
- `0x004E8780` **VehiclePhysicsState** — Computes the negated ratio of two suspension travel values (numerator this+0x39A8, denominator this+0x39AC) and clamps the result into [0.0, 1.0]: a zero-denominator guard returns 0.0, a negative ratio returns 0.0, a ratio above 1.0 returns 1.0. Per-frame path, called by AISteeringCorrection (0x00426CF0).
- `0x004E96C0` **VehiclePhysicsState** — Per-vehicle wheel-contact proximity check on the frame path: computes the squared position delta between the current history slots (0x3AAC/0x3AB0/0x3AB4) and the recorded position triplet (0x34D4/0x34D8/0x34DC), returns 0 in the dead-zone (flag this+0x32BC, thresholds dbl_5AD1C8 / dbl_5AD1D0), rolls the recorded position into history; on high rotation alignment (dot this+0x34C0 >= 0.94999999, flt_59EE8C) runs the full proximity test through PositionChangeMonitor (0x004E9630), projecting the recorded offset onto the monitor basis and testing extents at offsets 88/92 against the threshold at this+0x3B6C; on low alignment scans up to 4 active contact entries at this+0x828 (stride 296, active byte +0x868); returns 1 when alignment drops below 0.70710677 (flt_5AD1C4) or when no condition disqualifies.
- `0x004EF560` **VehicleWheelContact** — Per-wheel contact writer reached from the tire slip-force path: indexes this by a 28-byte stride a2 to select one wheel record, stores the contact/state flag bytes a3/a4 at byte offsets 15224 and 15225 of the record, copies the 3-dword vector at a5 into byte offset 15240, and returns a pointer to the copied vector. Packet owner tag: VehicleWheelContact.
- `0x004F23C0` **PhysicsConstantGlobals** — Cleanup routine freeing six heap allocations (global pointers 0x008ADB00, 0x008ADB0C, 0x008ADB14, 0x008ADB1C, 0x008ADB24, 0x008ADB2C) via FreeWrapper_7bcf (0x00587BCF). Each pointer is individually null-guarded; the last FreeWrapper return value (or 0) is returned. No static callers are recorded in the packet.

## Proposed classes

### VehiclePoseTransform

Pose promotion and orientation build on a vehicle-like object: promotes float position/rotation to double and builds the orientation matrix, then serializes it for network transmission.

Methods: `0x00459830`, `0x0045B050`

- `this+0x00000004` `float position_float_x` (write, DERIVED)
- `this+0x00000008` `float position_float_y` (write, DERIVED)
- `this+0x0000000C` `float position_float_z` (write, DERIVED)
- `this+0x00000010` `float rotation_float_x` (read, DERIVED)
- `this+0x00000014` `float rotation_float_y` (read, DERIVED)
- `this+0x00000018` `float rotation_float_z` (read, DERIVED)
- `this+0x000000C0` `dword position_dword_x` (write, GUESS)
- `this+0x000000C4` `dword position_dword_y` (write, GUESS)
- `this+0x000000C8` `dword position_dword_z` (write, GUESS)
- `this+0x000000D0` `byte transform_trigger_flag` (read, GUESS)
- `this+0x00000060` `float orientation_matrix_m00` (write, GUESS)
- `this+0x00000064` `float orientation_matrix_m01` (write, GUESS)
- `this+0x00000068` `float orientation_matrix_m02` (write, GUESS)
- `this+0x0000006C` `float orientation_matrix_row1_c0` (write, GUESS)
- `this+0x00000070` `float orientation_matrix_row1_c1` (write, GUESS)
- `this+0x00000074` `float orientation_matrix_row1_c2` (write, GUESS)
- `this+0x00000078` `float orientation_matrix_row2_c0` (write, GUESS)
- `this+0x0000007C` `float orientation_matrix_row2_c1` (write, GUESS)
- `this+0x00000080` `float orientation_matrix_row2_c2` (write, GUESS)
- `this+0x00000084` `float orientation_matrix_row3_c0` (write, GUESS)
- `this+0x00000088` `float orientation_matrix_row3_c1` (write, GUESS)
- `this+0x0000008C` `float orientation_matrix_row3_c2` (write, GUESS)
- `this+0x00000090` `float orientation_matrix_row4_c0` (write, GUESS)
- `this+0x00000094` `float orientation_matrix_row4_c1` (write, GUESS)
- `this+0x00000098` `float orientation_matrix_row4_c2` (write, GUESS)
- `this+0x0000009C` `float orientation_matrix_row5_c0` (write, GUESS)
- `this+0x000000A0` `float orientation_matrix_row5_c1` (write, GUESS)
- `this+0x000000A4` `float orientation_matrix_row5_c2` (write, GUESS)
- `this+0x000000A8` `float orientation_matrix_row6_c0` (write, GUESS)
- `this+0x000000AC` `float orientation_matrix_row6_c1` (write, GUESS)
- `this+0x000000B0` `float orientation_matrix_row6_c2` (write, GUESS)
- `this+0x000000B4` `float orientation_matrix_row7_c0` (write, GUESS)
- `this+0x000000B8` `float orientation_matrix_row7_c1` (write, GUESS)
- `this+0x000000BC` `float orientation_matrix_row7_c2` (write, GUESS)
- `this+0x00000108` `float direction_component_x` (read, GUESS)
- `this+0x00000110` `float direction_component_y` (read, GUESS)
- `this+0x00000118` `float direction_component_z` (read, GUESS)
- `this+0x00000318` `float up_component` (read, GUESS)
- `this+0x00000320` `float up_horizontal_component` (read, GUESS)

### VehicleChassisTransform

Local-to-world and chassis point transforms: rotates/scales a local point by the object matrix and per-component scale factors, adds the base translation, and emits a DWORD triple copy.

Methods: `0x004E2070`, `0x004E2130`

- `this+0x00000008` `float base_position_x` (read, DERIVED)
- `this+0x0000000C` `float base_position_y` (read, DERIVED)
- `this+0x00000010` `float base_position_z` (read, DERIVED)
- `this+0x00000014` `dword transform_row_copy_0` (read, GUESS)
- `this+0x00000018` `dword transform_row_copy_1` (read, GUESS)
- `this+0x0000001C` `dword transform_row_copy_2` (read, GUESS)
- `this+0x00000020` `float rotation_matrix_m00` (read, DERIVED)
- `this+0x00000024` `float rotation_matrix_m01` (read, DERIVED)
- `this+0x00000028` `float rotation_matrix_m02` (read, DERIVED)
- `this+0x0000002C` `float rotation_matrix_m10` (read, DERIVED)
- `this+0x00000030` `float rotation_matrix_m11` (read, DERIVED)
- `this+0x00000034` `float rotation_matrix_m12` (read, DERIVED)
- `this+0x00000038` `float rotation_matrix_m20` (read, DERIVED)
- `this+0x0000003C` `float rotation_matrix_m21` (read, DERIVED)
- `this+0x00000040` `float rotation_matrix_m22` (read, DERIVED)
- `this+0x000008F4` `float camera_offset_x` (read, GUESS)
- `this+0x000008F8` `float camera_offset_y` (read, GUESS)
- `this+0x000008FC` `float camera_offset_z` (read, GUESS)
- `this+0x00000900` `float extra_offset_x` (read, GUESS)
- `this+0x00000904` `float extra_offset_y` (read, GUESS)
- `this+0x00000908` `float extra_offset_z` (read, GUESS)
- `this+0x00000918` `float scale_factor_x` (read, GUESS)
- `this+0x0000091C` `float scale_factor_y` (read, GUESS)
- `this+0x00000920` `float scale_factor_z` (read, GUESS)

### VehiclePhysicsState

Per-frame vehicle suspension and wheel-contact physics state: spring/damper force accumulation, travel-ratio clamping, wheel-contact proximity checking and speed access, over the 0x32BC..0x3B6C suspension/contact region plus the nested speed field at obj+0xF34.

Methods: `0x004B9CC0`, `0x004E58D0`, `0x004E8780`, `0x004E96C0`

- `obj+0x00000F34` `float vehicle_speed_float` (read, GUESS)
- `this+0x00000828` `array contact_entry_array_base` (read, DERIVED)
- `this+0x00000868` `byte contact_entry_active_byte` (read, GUESS)
- `this+0x000032BC` `byte proximity_dead_zone_flag` (read, GUESS)
- `this+0x00000020` `double rotation_matrix_m00` (read, DERIVED)
- `this+0x00000024` `double rotation_matrix_m01` (read, DERIVED)
- `this+0x00000028` `double rotation_matrix_m02` (read, DERIVED)
- `this+0x0000002C` `double rotation_matrix_m10` (read, DERIVED)
- `this+0x00000030` `double rotation_matrix_m11` (read, DERIVED)
- `this+0x00000034` `double rotation_matrix_m12` (read, DERIVED)
- `this+0x00000038` `double rotation_matrix_m20` (read, DERIVED)
- `this+0x0000003C` `double rotation_matrix_m21` (read, DERIVED)
- `this+0x00000040` `double rotation_matrix_m22` (read, DERIVED)
- `this+0x000034C0` `double rotation_alignment_dot` (read, DERIVED)
- `this+0x000034D4` `float recorded_position_x` (read_write, DERIVED)
- `this+0x000034D8` `float recorded_position_y` (read_write, DERIVED)
- `this+0x000034DC` `float recorded_position_z` (read_write, DERIVED)
- `this+0x000034F8` `double suspension_mount_x` (read, GUESS)
- `this+0x000034FC` `double suspension_mount_y` (read, GUESS)
- `this+0x00003500` `double suspension_mount_z` (read, GUESS)
- `this+0x00003514` `double gravity_scaled_input` (read, GUESS)
- `this+0x0000354C` `double force_accumulator_x` (read_write, GUESS)
- `this+0x00003550` `double force_accumulator_y` (read_write, GUESS)
- `this+0x00003554` `double force_accumulator_z` (read_write, GUESS)
- `this+0x00003558` `double cross_coupling_accumulator` (read_write, GUESS)
- `this+0x000039A8` `double suspension_travel_numerator` (read, DERIVED)
- `this+0x000039AC` `double suspension_travel_denominator` (read, DERIVED)
- `this+0x00003A58` `double rest_anchor_x` (read, GUESS)
- `this+0x00003A5C` `double rest_anchor_y` (read, GUESS)
- `this+0x00003A60` `double rest_anchor_z` (read, GUESS)
- `this+0x00003A64` `double axis_stiffness_x` (read, GUESS)
- `this+0x00003A68` `double axis_stiffness_y` (read, GUESS)
- `this+0x00003A6C` `double axis_stiffness_z` (read, GUESS)
- `this+0x00003A70` `double cross_coupling_term_a` (read, GUESS)
- `this+0x00003A74` `double cross_coupling_term_b` (read, GUESS)
- `this+0x00003AAC` `float position_history_x` (read_write, GUESS)
- `this+0x00003AB0` `float position_history_y` (read_write, GUESS)
- `this+0x00003AB4` `float position_history_z` (read_write, GUESS)
- `this+0x00003B6C` `double proximity_threshold` (read, DERIVED)

### VehicleWheelContact

Per-wheel contact record writer: stores two contact/state flag bytes and a 3-dword vector into the 28-byte-stride wheel record selected by the caller.

Methods: `0x004EF560`


### CollisionBroadphaseTraversal

Recursive broadphase AABB linked-list traversal with rectangle clipping of accepted nodes and output re-linking.

Methods: `0x00491170`

- `this+0x00000000` `pointer list_head_ptr` (read_write, DERIVED)
- `this+0x00000008` `pointer list_cursor_ptr` (read_write, DERIVED)
- `obj+0x00000000` `pointer node_value_ptr` (read, DERIVED)
- `*(obj+0x0)+0x00000000` `short aabb_min_x` (read, DERIVED)
- `*(obj+0x0)+0x00000002` `short aabb_min_y` (read, DERIVED)
- `*(obj+0x0)+0x00000004` `short aabb_max_x` (read, DERIVED)
- `*(obj+0x0)+0x00000006` `short aabb_max_y` (read, DERIVED)
- `*(this+0x8)+0x00000004` `pointer node_next_ptr` (read, DERIVED)
- `*(*(this+0x8)+0x4)+0x00000000` `pointer next_node_value_ptr` (read, DERIVED)
- `*(*(*(this+0x8)+0x4)+0x0)+0x00000000` `short next_aabb_min_x` (read, DERIVED)
- `*(*(*(this+0x8)+0x4)+0x0)+0x00000002` `short next_aabb_min_y` (read, DERIVED)
- `*(*(*(this+0x8)+0x4)+0x0)+0x00000004` `short next_aabb_max_x` (read, DERIVED)
- `*(*(*(this+0x8)+0x4)+0x0)+0x00000006` `short next_aabb_max_y` (read, DERIVED)

### CollisionPositionStepper

Time-based position stepping for a collision/animation position: converts an accumulated time into steps, moves toward a target at a fixed rate with wrap-around, and invokes a vtable-slot-11 update callback.

Methods: `0x0048CB00`

- `this+0x00000328` `float step_multiplier` (read, GUESS)
- `this+0x0000032C` `float step_size` (read, GUESS)
- `this+0x00000334` `float current_position` (read_write, DERIVED)
- `this+0x00000338` `float target_offset_factor` (read, GUESS)
- `this+0x0000033C` `byte direction_byte` (read, DERIVED)
- `this+0x00000340` `float time_accumulator` (read_write, DERIVED)
- `obj+0x0000002C` `pointer update_callback_ptr` (read, DERIVED)

### CollisionNodeList

Dual linked list (primary at this+0x0..0xC, secondary at this+0x10..0x1C) of 12-byte nodes with a flag byte; the insertion appends primary data nodes and a staggered 884-byte-stride secondary pass.

Methods: `0x004BAD70`

- `this+0x00000000` `pointer list_head_ptr` (read_write, DERIVED)
- `this+0x00000004` `pointer list_tail_ptr` (read_write, DERIVED)
- `this+0x00000008` `pointer list_head_alt_ptr` (write, GUESS)
- `this+0x0000000C` `int list_count` (read_write, GUESS)
- `this+0x00000010` `pointer secondary_tail_ptr` (read_write, GUESS)
- `this+0x00000014` `pointer secondary_head_ptr` (write, GUESS)
- `this+0x00000018` `pointer secondary_head_alt_ptr` (write, GUESS)
- `this+0x0000001C` `int secondary_count` (read_write, GUESS)

### CollisionGlobalState

Collision subsystem global configuration and state: frame-change configuration version sync over the 0x7CDxxx globals and reset-path zeroing of the 0x7CDDF0 block. No object fields; operates on globals only.

Methods: `0x00475D30`, `0x00494600`


### PhysicsObjectFactory

Indirect object store and value dispatch through the dword_7CD8C0 interface: creates/stores an object via a vtable-offset-28 call with argument 21, and dispatches command 9 through slot +0x1C to clamp a suspension float across a global array.

Methods: `0x004780B0`, `0x0047A290`

- `this+0x00000000` `pointer vtable_ptr` (read, DERIVED)
- `this+0x000000E0` `pointer stored_object_ptr` (write, GUESS)
- `this+0x00000100` `byte enable_flag` (read, DERIVED)
- `obj+0x000000B4` `pointer retrieved_value_ptr` (read, GUESS)

### SuspensionForceVisualizer

Draws the 2D suspension-force visualization for the shared vehicle context at byte_7C56C0: computes wheel-speed pixel offsets, accumulates per-joint suspension forces, and draws interpolated segments.

Methods: `0x00475A90`


### PhysicsChannelSet

Fixed 8-entry array of physics channels at this+0x90 (23-float stride); scans for the (a2+1)-th channel whose first float is positive.

Methods: `0x0045B580`

- `this+0x00000090` `array channel_array_base` (read, DERIVED)

### PhysicsConstantGlobals

Global physics constants and buffers in the 0x8Axxxx region: the freed tire-model constant pointers (0x008ADB00..0x008ADB2C) and the global physics vector at flt_8AC4B0. Free functions; no object context.

Methods: `0x004C7C50`, `0x004F23C0`


### TireStateBlock

Small tire-related state block (two byte flags plus six dwords) reset by a constructor-style zero-initializer on tire-system construction, vehicle reset and sub_4DFBB0 paths.

Methods: `0x004DFB90`

- `this+0x00000000` `byte state_byte_0` (write, GUESS)
- `this+0x00000001` `byte state_byte_1` (write, GUESS)
- `this+0x00000004` `dword state_dword_0` (write, GUESS)
- `this+0x00000008` `dword state_dword_1` (write, GUESS)
- `this+0x0000000C` `dword state_dword_2` (write, GUESS)
- `this+0x00000010` `dword state_dword_3` (write, GUESS)
- `this+0x00000014` `dword state_dword_4` (write, GUESS)
- `this+0x00000018` `dword state_dword_5` (write, GUESS)

### VehicleHudDisplay

HUD/UI vehicle-display accessors: vehicle description string getter with a fallback global, UI edit control binding of the visible vehicle index and race mode, position/vehicle-count text formatting, and a vehicle-list count getter.

Methods: `0x00463C80`, `0x00474AB0`, `0x0049C6D0`, `0x004B8140`

- `this+0x00000320` `pointer visible_vehicle_index_ptr` (write, DERIVED)
- `this+0x00000324` `dword race_mode_snapshot` (write, GUESS)
- `this+0x000006CC` `dword vehicle_list_count` (read, GUESS)
- `obj+0x000000B4` `pointer description_string_ptr` (read, DERIVED)

## Compatibility contracts

- **FloatToDoubleCoordinateTransform** — 0x00459830 must store the double position at this+0xD8 (0x18 bytes) and the computed 3x3 rotation tensor at this+0x138 (0x18 bytes) via F_3x3RotationTensorMatrixTransform (0x005691D0), propagate the six dwords via Copy6DwordsToStructCall (0x00569280), and copy the float position as three dwords into this+0xC0/+0xC4/+0xC8 and the output a2; when the trigger flag at this+0xD0 is non-zero the external-processing call sub_54B4D0 (0x0054B4D0) and BufferEntryClear(0x8000000) (0x0054FAE0) must run before the conversion.
- **OrientationMatrixNetworkSerialization** — 0x0045B050 must serialize exactly eight 12-byte orientation-matrix rows through NetworkPacketDataWriter (0x0054FA00), reading the rows back through the this+0x64/0x68/0x60 row pointers; the matrix at this+0x60..0xBC is built from the negated direction components (0x108/0x110/0x118) and the normalized up component (0x318/0x320) with a zero-magnitude guard on the this+0x64/this+0x68 slot.
- **CollisionConfigurationVersionSync** — 0x00475D30 must compare the stored version dword_7CD614 against dword_7CE250 and, when different, stamp the new version, call ShortComputation_5bd0 (0x00455BD0) on the module pointer array at 0x007CA590, and call sub_454DA0 (0x00454DA0) with the collision parameter arrays 0x007CD458/0x007CD45C/0x007CD2B0/0x007CD610 and the value read from dbl_8AFE90.
- **WheelContactProximityThresholds** — 0x004E96C0 must preserve the movement dead-zones (squared delta below 0.0009 then 0.000009 via dbl_5AD1C8/dbl_5AD1D0, gated by the dead-zone flag at this+0x32BC), the rotation alignment split at 0.94999999 (flt_59EE8C), the very-low-alignment exit at 0.70710677 (flt_5AD1C4), and the threshold at this+0x3B6C; the recorded position triplet (this+0x34D4..0x34DC) is rolled into the history slots (this+0x3AAC..0x3AB4) before the monitor test.
- **SuspensionSpringDamperAccumulation** — 0x004E58D0 must compute the gravity-scaled force from this[0x3514] * -9.81, project it by the rotation matrix at 0x34B0..0x34D0, combine each squared displacement component (mount 0x34F8..0x3500 minus rest anchor 0x3A58..0x3A60) with its axis stiffness (0x3A64/0x3A68/0x3A6C), fold the cross-coupling term (0x3A70/0x3A74) into this[0x3558] on the third axis, and accumulate the per-axis results into this[0x354C]/[0x3550]/[0x3554].
- **SuspensionRatioClampContract** — 0x004E8780 must return 0.0 when the denominator this+0x39AC is zero, compute the negated ratio -(this[0x39A8] / this[0x39AC]), and clamp the result into [0.0, 1.0].
- **CollisionPositionStepSequence** — 0x0048CB00 must accumulate the time delta a2 into this+0x340, convert to a step count with CRTFtol(accumulator * 14.999999) (0x00587BDC), step at a 0.444 rate with a minimum step of 1, wrap the position at this+0x334 modulo the range this+0x32C * this+0x328 in both directions, invoke the vtable-slot-11 (obj+0x2C) update callback with argument 1, and decrement the accumulator by 0.06666667 (1/15, flt_5AC108) per step.
- **BroadphaseAABBTraversalContract** — 0x00491170 must test each node's four short AABB coordinates (offsets 0x0/0x2/0x4/0x6) against the next node via AABBOverlapTest (0x004915A0), recurse into RectangleClipping (0x00491350) clip results (self-call 0x00491170) and re-link them with LinkedListNodePrepend (0x00490AA0), returning 1 on the first overlap and 0 when the list is exhausted.
- **PhysicsChannelStrideContract** — 0x0045B580 must scan at most 8 channels of stride 0x5C (23 floats) from this+0x90 and treat a channel as active when its first float is greater than 0.0, returning the (a2+1)-th active flat index (0-7) or 0.
- **CollisionGlobalZeroContract** — 0x00494600 must zero the four collision-system global DWORDs at 0x007CDDF0-0x007CDDFC and return 0.
- **TireStateResetContract** — 0x004DFB90 must clear the byte pair at this+0x0/+0x1 and the six dwords at this+0x4/+0x8/+0xC/+0x10/+0x14/+0x18 of the tire state block and return 0; it is invoked on tire-system construction, vehicle reset and the sub_4DFBB0 path.
- **TireModelConstantsFreeContract** — 0x004F23C0 must null-guard and free the six pointer globals 0x008ADB00/0x008ADB0C/0x008ADB14/0x008ADB1C/0x008ADB24/0x008ADB2C via FreeWrapper_7bcf (0x00587BCF), returning the last FreeWrapper result or 0.
- **CollisionNodeInsertionLayout** — 0x004BAD70 must allocate 12-byte nodes (data pointer, next pointer, flag byte at +8) via OperatorNewNhMallocWrapper(12) (0x00587C03), append them to the primary list at this+0x0..0xC and, when a3 == 0, to the secondary list at this+0x10..0x1C while walking a 884-byte stride over *a2.

## Unresolved

- All class owners except the packet-listed VehicleWheelContact (DERIVED for 0x004EF560) are worker proposals; every other packet owner tag is UnknownObject, so ownership is unproven.
- The grouping of the this+0x4..0x138 (pose promotion), this+0x60..0x320 (orientation build) and this+0x8F4..0x920 (transform scales) regions into VehiclePoseTransform/VehicleChassisTransform is a worker proposal; the packet provides no common-ownership proof between the functions.
- Whether the double reads at this+0x108/0x110/0x118 and this+0x318/0x320 in 0x0045B050 alias the float matrix region is not expressible from the raw text; the serialized network row layout overlaps the freshly-written matrix.
- The trigger flag at this+0xD0, the buffer identifier 0x8000000, and the destination struct written by Copy6DwordsToStructCall (0x00569280) in 0x00459830 are not established by the packet.
- The 884-byte stride and the *a2 base walked by the secondary pass of 0x004BAD70 imply a fixed-size per-entry layout that is unknown; the meaning of the node flag byte at +8 (1 primary / 0 secondary) and of argument a3 is caller-defined.
- The 23-float channel stride and the first-float-greater-than-zero active rule of 0x0045B580 are DERIVED from loop increments, not confirmed by a consumer; the role of flt_59E440 as a zero threshold is unclear.
- The semantics of the byte_5EA438 fallback string, the dword_7D0410 (championship/race mode) and dword_7CFC8C (visible vehicle index) labels, and the position field at dword_7C54E0 + 16480 are from existing-analysis prose only.
- The screen-space meaning of the visualization coordinates v20/v21/v22 and of arguments a2..a5 forwarded unmodified to sub_4881F0 in 0x00475A90 is unknown; the read-only globals 0x0059EA38/0x0059EA90/0x0059EA98/0x0059EB20/0x005A4420 never appear in the raw body.
- The dword_7CD8C0 dispatch interface identity and the object type produced by command 9 in 0x0047A290 are unknown; the meaning of literal argument 21 and of field this+0xE0 in 0x004780B0 is unproven.
- Globals flt_59E440 and dbl_59ED50 likely supply the -9.81 gravity and ~0.0 literals in 0x004E58D0, but the mapping is not proven; the same holds for flt_59E43C/flt_59E440 in 0x004E8780.
- The PositionChangeMonitor (0x004E9630) record layout (basis offsets 32/36/40, neighbor offsets 268/272, extent offsets 88/92) is not documented in the packet; the projection and extent checks are interpreted from raw arithmetic.
- Whether fields this+0x918..0x920 are per-component scale factors or stored rotation basis vectors is unresolved, and whether the a3 DWORD triple copied by 0x004E2130 is a quaternion or the first rotation-matrix row is unconfirmed.
- The local 36-byte matrix copy in 0x004E2070 has no observable effect; the semantics of a3 and of sub_567120's second argument are unknown.
- The FCOM-flag-selected add/subtract signs in 0x004E58D0 and the trailing v21/v22/v24/v25 compare-flag exits in 0x004E96C0 depend on compare instructions the packet does not show.
- sub_491680 filter semantics and the accepted-but-unused argument a2 in 0x00491170 are unresolved; the two pointer chains (obj and the cursor-derived chain) are treated as reading the same node value, which is DERIVED.
- The element structure of the unk_7D17CC array in 0x0047A290 (stride 27 dwords) and the meaning of its third/fourth dwords as clamp bounds are inferred from comparison order only.
- flt_5AC10C and flt_5AC110 in 0x0048CB00 and aDD_1 (0x005CCE80) in 0x0049C6D0 are listed by packet facts but absent from the raw decompiled source.
- The read-only access classification of the count fields this+0xC and this+0x1C in 0x004BAD70 is unresolved; the packet records them read-only although the function increments them.
- The wheel-record byte offsets 15224/15225/15240 written by 0x004EF560 are computed from the caller-provided 28-byte stride and are not covered by packet field evidence; VehicleWheelContact therefore carries no fields.
- Semantics of each cleared field of the 0x004DFB90 state block, of the six freed tire-model pointers in 0x004F23C0, and of the type behind dword_7CD8C0 are caller/context-defined and not established here.
