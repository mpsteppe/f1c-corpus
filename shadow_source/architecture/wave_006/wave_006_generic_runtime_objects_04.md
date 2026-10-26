# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

Proposal for 32 functions spanning generic runtime objects. The packet proves a recursive BVH traversal that runs QuadraticSurfaceCollisionTest on leaf nodes (with a 0xFFFE two-surface sentinel) and recurses/iterates interior nodes by split coordinate, a triangle-proximity test whose comparison body was not recovered, a cursor scroll-tracker update that clamps a center within viewport bounds and writes normalized deltas/clamped positions, a large per-frame driver input controller tick (steering/brake/throttle/rotation-FF/rumble channel dispatch plus audio sub-controller enable/disable), a control-value dispatcher, a large object initializer with three 17-count groups and 44 fixed structs, a vehicle setup/damage diagnostic classifier producing state IDs 1-109 with a label copy, and ~25 unconditional global-state initializers that write adjacent pairs or six-dword blocks with tag/zero/tail literal patterns. All owner types are UNKNOWN at packet level; class membership is GUESS.

## Function roles

- `0x0044AA30` **BoundingVolumeHierarchyTraverser** — Recursive BVH (bounding-volume hierarchy) traversal for collision surface queries. Reads the node type word at this+0x8: negative marks a leaf that runs QuadraticSurfaceCollisionTest (0x0044A070) against the surface pointer at this+0x10, with sentinel 0xFFFE additionally testing a second surface at surface+92. Non-negative marks an interior node: computes a split coordinate from query a2 via the axis tables indexed by the split-axis word at this+0xA (global 0x007CA3A4) with sign selection from this+0xC, recurses into the child subtree at this+0x1C when the split coordinate falls inside the child bounding interval, then walks the next sibling at this+0x20 while the coordinate stays within the next node's bound at this+0x24, re-checking the leaf sentinel after each step. Called by SpatialGridQuery (0x0044C4C0) to resolve which surfaces a query intersects.
- `0x0044B090` **TriangleProximityTest** — Returns (v4 | v5) != 0 assembled from two comparison status-flag captures (c0, c2). The decompiler did not recover the comparison body; deterministic facts show the function reads the double global dbl_59EF40 (0x0059EF40), so the flags are presumed to come from a floating-point comparison involving that global. Parameters a1, a2, a3 are not referenced by the recovered body. Called by sub_44B110 (0x0044B110) as the triangle proximity test on the frame path.
- `0x0044C680` **GlobalStateBlockInitializer** — Unconditional initialization of four global spatial-node parameters: dword_7CCA44 = 2, flt_7CCA48 = 0.0, dword_7CCA4C = -1082130432 (skeleton analysis: -1.0f radius/sentinel bit pattern), flt_7CCA50 = 0.0.
- `0x0044C6E0` **GlobalStateBlockInitializer** — Unconditional one-time initialization of four module globals: engine-type selector dword_7CA3E8 = 3, float thresholds flt_7CA3EC and flt_7CA3F0 cleared to 0.0, and dword_7CA3F4 = 1065353216 (stored float 1.0 bit pattern).
- `0x0044CAA0` **MouseAxisGlobalInitializer** — Initializes mouse absolute X-axis state: stores the constant 102 into global dword_7CD148, clears global flt_7CD14C to zero, then invokes RenderStateFloatInitialization to re-initialize the render-state float pipeline (callee identity inferred from raw source only; it has no callee evidence reference in the packet).
- `0x0044CB14` **GlobalStatePairInitializer** — Trivial void global-initializer: writes -1082130432 into dword_7CCFE4 and 0.0 into flt_7CCFE8. No parameters, no guards, no calls, no return value.
- `0x0044CB74` **GlobalStatePairInitializer** — Trivial void global-reset routine: stores 0.0 into flt_7CD110 and 1065353216 into dword_7CD114. No parameters, no guards, no calls, no return value.
- `0x0044CBD4` **GlobalStatePairInitializer** — Trivial void global-state initializer: stores -1082130432 into dword_7CD190 and 0.0 into flt_7CD194. No parameters, no guards, no calls, no return value.
- `0x0044CE00` **GlobalStateBlockInitializer** — Straight-line initializer at 0x0044CE00: stores the integer 35 into dword_7CA438, zeroes the adjacent float flt_7CA43C, then invokes GlobalStateInitializer_ce14() (named callee in the raw source; its address is absent from the packet callee facts). No branches.
- `0x0044CE14` **GlobalStatePairInitializer** — Straight-line initializer at 0x0044CE14: stores the raw 32-bit integer -1082130432 into dword_7CA440 and zeroes the adjacent float flt_7CA444. Called by SpatialNodeInitCe00 per that function's raw source. No branches and no callees.
- `0x0044CE60` **GlobalStateBlockInitializer** — Straight-line initializer at 0x0044CE60: stores the integer 36 into dword_7CA448, zeroes the adjacent float flt_7CA44C, then invokes InitFloatGlobals() (named callee in the raw source; its address is absent from the packet callee facts). No branches.
- `0x0044CE74` **GlobalStatePairInitializer** — Startup-time initializer writing two globals at 0x7CA450/0x7CA454: flt_7CA450 set to 0.0 and dword_7CA454 set to the decimal literal 1065353216. No guards, no callees, no parameters.
- `0x0044CED4` **GlobalStatePairInitializer** — Startup-time initializer writing two globals at 0x7CCBFC/0x7CCC00: dword_7CCBFC set to the decimal literal -1082130432 and flt_7CCC00 set to 0.0. No guards, no callees, no parameters.
- `0x0044CF34` **GlobalStatePairInitializer** — Startup-time initializer writing two globals at 0x7CA3B0/0x7CA3B4: flt_7CA3B0 set to 0.0 and dword_7CA3B4 set to the decimal literal 1065353216. No guards, no callees, no parameters.
- `0x0044CFF4` **GlobalStatePairInitializer** — Straight-line initializer for two adjacent 4-byte globals at 0x007CC9F4: flt_7CC9F4 set to 0.0 and dword_7CC9F8 set to 1065353216, the raw integer spelling for the float 1.0. Likely seeds a (zero, one) pair used as a float-scale baseline.
- `0x0044D054` **GlobalStatePairInitializer** — Straight-line initializer for two adjacent 4-byte globals at 0x007CA3E0: dword_7CA3E0 set to -1082130432, the raw integer spelling for the float -1.0, and flt_7CA3E4 set to 0.0. Likely seeds a (minus-one, zero) pair used as a float-range default.
- `0x0044D220` **MouseAxisGlobalInitializer** — Unconditional one-time initialization of four module globals: dword_7CA4F8 set to literal 60 (axis/steering value), dword_7CA4FC and dword_7CA500 cleared to 0, and dword_7CA504 set to 1065353216 (stored float 1.0).
- `0x0044D400` **GlobalStateBlockInitializer** — Unconditional state initializer writing six dword globals: dword_7CCD38 = 14 (only non-zero constant) and dword_7CCD3C/0x40/0x44/0x48/0x4C = 0, then returns 0. No callees, no guards, and no static callers evidenced.
- `0x0044D460` **GlobalStateBlockInitializer** — Unconditional state initializer writing six dword globals: dword_7CCCF0 = 15 (only non-zero constant) and dword_7CCCF4/0xF8/0xFC/0x7CCD00/0x04 = 0, then returns 0. No callees, no guards, and no static callers evidenced.
- `0x0044D820` **GlobalStateBlockInitializer** — Initializes a six-dword keyboard-axis configuration block at 0x7CCC50: dword_7CCC50 = 25, with the following five fields (0x7CCC54/0x58/0x5C/0x60/0x64) zeroed. Unconditional straight-line write with no calls, guards, or parameters; returns 0.
- `0x0044DB80` **GlobalStateBlockInitializer** — Initializes a six-dword spatial-node configuration block at 0x7CCEE8: dword_7CCEE8 = 47, with the following five fields (0x7CCEEC/0xF0/0xF4/0xF8/0xFC) zeroed. Unconditional straight-line write with no calls, guards, or parameters; returns 0.
- `0x0044DFA0` **GlobalStateBlockInitializer** — Resets a six-dword scoring-database entry block at 0x7CCDB0: dword_7CCDB0 = 66, with the following five fields (0x7CCDB4/0xB8/0xBC/0xC0/0xC4) zeroed. Unconditional straight-line write with no calls, guards, or parameters; returns 0.
- `0x0044E300` **GlobalStateBlockInitializer** — Unconditional single-block initialization of six adjacent DWORD globals: dword_7CD0B0 = 75 (tag / element-count-like literal), dword_7CD0B4/0xB8/0xBC/0xC0 = 0, and dword_7CD0C4 = 9000 (max-search-distance-like literal). Returns constant 0.
- `0x0044E360` **GlobalStateBlockInitializer** — Unconditional init of a six-dword block: dword_7CD118 = 76 (filter type/identifier), dword_7CD11C/0x120/0x124/0x128 = 0, and dword_7CD12C = 18000 (render threshold literal). Returns constant 0. Audio subsystem association is inferred from the ABI name only; no callers or callees are recorded statically.
- `0x0044E720` **MouseAxisGlobalInitializer** — Unconditional single-block initialization of six adjacent DWORD globals: dword_7CCFC4 = 86 (tag literal) and dword_7CCFC8/0xCC/0xD0/0xD4/0xD8 = 0. Returns constant 0. The LEGACY ABI name InitMouseAxis is unverified against packet evidence (the globals are collision-block-like; semantics may be mislabeled).
- `0x0044EA80` **GlobalStateBlockInitializer** — Unconditional single-block initialization of six adjacent DWORD globals: dword_7CA4E0 = 95 (tag / element-count-like literal), dword_7CA4E4/0xE8/0xEC/0xF0 = 0, and dword_7CA4F4 = 9000 (max-search-distance-like literal). Returns constant 0.
- `0x0044EAE0` **GlobalStateBlockInitializer** — Unconditional one-shot initializer of a contiguous block of six global state words at 0x7CA54C-0x7CA560: dword_7CA54C = 96 (block tag literal), dword_7CA550/0x554/0x558/0x55C = 0, and dword_7CA560 = 18000 (range literal), then returns 0. No guards, no calls, and no static callers.
- `0x0044F73C` **CursorScrollTracker** — Updates a cursor scroll/drag center to new input coordinates, clamps the center within viewport bounds, and writes both normalized deltas and normalized clamped positions into the tracker's float fields. Reads viewport bounds at this+0x0/0x4/0x8/0xC and per-axis scaling factors at this+0x18/0x1C; writes the center at this+0x10/0x14, normalized delta X at this+0x20, normalized delta Y at this+0x24, normalized clamped X at this+0x28 and normalized clamped Y at this+0x2C. Returns the maximum Y bound stored at this+0x4. Parameters a4/a5 are unused.
- `0x00451720` **DriverInputController** — Per-frame driver input controller tick called by MainGameTickUpdate (0x0042C690). Dispatches enable/disable to four audio sub-controllers (pointers this+0x4E8/0x4EC/0x4F0/0x4F4, inner object at +0x80, vtable slot +0x58 called with argument 32 to enable / 16 to disable) gated by global byte_7C56AC and the latched init byte this+0x418; derives wheel-speed magnitudes from the player vehicle global dword_7C54E0; folds wheel-contact types into per-frame gains and flags (this+0x4D0/0x4D4/0x4D8/0x4DC/0x4E0/0x4E4); then runs a ten-channel dispatch over stride-104 records laid out from 'this' (channel live when the byte at +4 is nonzero and its object pointer at +100 is present) covering steering, brake, throttle, rotation force-feedback and rumble, computing effort/headroom/raw outputs through CRTFtol (0x00587BDC) and the feedback-curve shape helper (0x005881F0) and pushing channel messages via each channel object's vtable (+24/+28/+32). Zeroes the six rotation doubles at this+0x560..0x574 and returns 0. Owner type UNKNOWN; class membership GUESS.
- `0x004530A0` **ControlStateDispatcher** — Small thiscall dispatcher keyed on the control value *a2. When *a2 is 0, forwards to StructInitWithSubCall (0x004527E0) with (this, a2[1], a3) and returns its result immediately. When *a2 is 1, calls sub_452B10 (0x00452B10) with (this, a2[1], a3 == 2); if that returns non-zero, returns DeviceObjectSelector (0x00452810) with (this, a2[1]). Otherwise returns *a2 - 1.
- `0x004531A0` **DeviceContextInitializer** — Large object initializer (this) that zeroes several data regions, sets three axis/group count fields to 17 at this+0x27C/0x107C/0x1478, builds 44 fixed structs at this+0x1B20 via StructInitWithFixedValues (0x00452780), writes 44 {value, -1} sentinel pairs at this+0x22B0, resets state/tail fields, sets the activation byte to 1 at this+0xD7C, stores a -2 tail sentinel at this+0x2424 and a self-reference at this+0x1580, returning this. Device-context (force-feedback per existing analysis) semantics are unconfirmed.
- `0x00454350` **SetupDiagnosticClassifier** — Classifies the current vehicle setup/damage state into a numeric state ID written to a3 and copies a human-readable label from the aEmpty string table (stride 9, global 0x005C44B0) into a2. When a4 is non-zero, first fills two float scratch buffers at globals 0x007CD168 and 0x007CCA8C from per-wheel physics values; then runs ordered ConstraintForceEval (0x00454250) and SweptAABBOverlapDetection (0x004542D0) passes (indices 0-7) to assign state IDs 1-12/102-105 and 30-41/106-109; checks 16 byte-flag fields at this+0x1160..0x116F (states 13-28) and this+0x155C..0x156B (states 42-57); and evaluates two compound sign+value-match blocks gated on the sign of this+0x1180 (states 70-85) and this+0x157C (states 86-101), comparing this+0x1170/0x1174/0x1178/0x117C and this+0x156C/0x1570/0x1574/0x1578 against packet globals with bit-gate tests (& 0x100/0x200/0x400). Returns 1 with label copy when any state matched, 0 when the default -1 persisted. Sole caller is ParameterLookupWithFallback (0x00454D30).

## Proposed classes

### BoundingVolumeHierarchyTraverser

Recursively walks a bounding-volume hierarchy over collision surfaces: leaves run QuadraticSurfaceCollisionTest, interior nodes split the query on an axis table and recurse into child/sibling subtrees.

Methods: `0x0044AA30`

- `this+0x00000008` `word node_type_word` (read, GUESS)
- `this+0x0000000A` `word split_axis_word` (read, GUESS)
- `this+0x0000000C` `word sign_word` (read, GUESS)
- `this+0x00000010` `ptr surface_ptr` (read, GUESS)
- `this+0x0000001C` `ptr child_subtree_ptr` (read, GUESS)
- `this+0x00000020` `ptr next_sibling_ptr` (read, GUESS)
- `this+0x00000024` `dword next_bound_value` (read, GUESS)

### TriangleProximityTest

Boolean triangle proximity predicate; the comparison body is missing from the recovered source and the return is assembled from two status-flag captures.

Methods: `0x0044B090`


### GlobalStatePairInitializer

Branch-free startup writers of two adjacent 4-byte globals (one zero, one a float bit pattern / decimal literal).

Methods: `0x0044CB14`, `0x0044CB74`, `0x0044CBD4`, `0x0044CE14`, `0x0044CE74`, `0x0044CED4`, `0x0044CF34`, `0x0044CFF4`, `0x0044D054`


### MouseAxisGlobalInitializer

One-time initialization of mouse-absolute-axis globals (pair and block writers named InitMouseAbsAxisX / initMouseAbsoluteAxis / InitMouseAxis).

Methods: `0x0044CAA0`, `0x0044D220`, `0x0044E720`


### GlobalStateBlockInitializer

Unconditional writers of contiguous multi-dword global blocks following a tag/count-first, zeroed-middle, tail-literal pattern; returns constant 0.

Methods: `0x0044C680`, `0x0044C6E0`, `0x0044CE00`, `0x0044CE60`, `0x0044D400`, `0x0044D460`, `0x0044D820`, `0x0044DB80`, `0x0044DFA0`, `0x0044E300`, `0x0044E360`, `0x0044EA80`, `0x0044EAE0`


### CursorScrollTracker

Tracks a cursor scroll/drag center, clamps it within viewport bounds, and emits normalized deltas and normalized clamped positions scaled per axis.

Methods: `0x0044F73C`

- `this+0x00000000` `float min_y_bound` (read, GUESS)
- `this+0x00000004` `float max_y_bound` (read, GUESS)
- `this+0x00000008` `dword min_x_bound` (read, GUESS)
- `this+0x0000000C` `dword max_x_bound` (read, GUESS)
- `this+0x00000010` `dword center_x` (read_write, GUESS)
- `this+0x00000014` `dword center_y` (read_write, GUESS)
- `this+0x00000018` `dword scale_x` (read, GUESS)
- `this+0x0000001C` `dword scale_y` (read, GUESS)
- `this+0x00000020` `dword normalized_delta_x` (write, GUESS)
- `this+0x00000024` `dword normalized_delta_y` (write, GUESS)
- `this+0x00000028` `dword normalized_clamped_x` (write, GUESS)
- `this+0x0000002C` `dword normalized_clamped_y` (write, GUESS)

### DriverInputController

Per-frame driver input controller: enables/disables four audio sub-controllers, derives wheel-speed magnitudes from the player vehicle, folds wheel-contact types into gains/flags, and dispatches steering/brake/throttle/rotation-FF/rumble channel messages through channel-object vtables.

Methods: `0x00451720`

- `this+0x000002D4` `dword position_mismatch_value` (read, GUESS)
- `this+0x00000418` `byte init_latch_byte` (read_write, GUESS)
- `this+0x0000041C` `dword steering_effort` (read_write, GUESS)
- `this+0x00000420` `dword steering_raw_output` (read_write, GUESS)
- `this+0x00000428` `dword steering_headroom` (read_write, GUESS)
- `this+0x0000048C` `dword brake_tolerance_a` (read, GUESS)
- `this+0x00000490` `dword brake_tolerance_b` (read, GUESS)
- `this+0x00000498` `dword brake_stored_output` (read, GUESS)
- `this+0x0000049C` `dword throttle_effort` (read_write, GUESS)
- `this+0x000004A8` `dword throttle_headroom` (read_write, GUESS)
- `this+0x000004AC` `dword rotation_ff_output` (read_write, GUESS)
- `this+0x000004B0` `dword rumble_raw_output` (read_write, GUESS)
- `this+0x000004B4` `dword rumble_effort` (read_write, GUESS)
- `this+0x000004BC` `dword rumble_headroom` (read_write, GUESS)
- `this+0x000004C0` `dword wheel_speed` (read, GUESS)
- `this+0x000004C4` `dword brake_delta_source` (read, GUESS)
- `this+0x000004C8` `dword throttle_delta_source` (read, GUESS)
- `this+0x000004CC` `dword rumble_effort_source` (read, GUESS)
- `this+0x000004D0` `dword wheel_contact_flag_set` (read_write, GUESS)
- `this+0x000004D4` `dword wheel_contact_flag_mirror` (read_write, GUESS)
- `this+0x000004D8` `dword wheel_contact_type_alt` (read_write, GUESS)
- `this+0x000004DC` `dword wheel_contact_type_alt_mirror` (read_write, GUESS)
- `this+0x000004E0` `dword wheel_type_accumulator` (read_write, GUESS)
- `this+0x000004E4` `dword wheel_type_prev` (read, GUESS)
- `this+0x000004E8` `ptr sub_controller_0` (read, GUESS)
- `this+0x000004EC` `ptr sub_controller_1` (read, GUESS)
- `this+0x000004F0` `ptr sub_controller_2` (read, GUESS)
- `this+0x000004F4` `ptr sub_controller_3` (read, GUESS)
- `this+0x00000510` `dword steer_position_a` (read, GUESS)
- `this+0x00000514` `dword steer_position_b` (read, GUESS)
- `this+0x00000560` `double rotation_accel_0` (write, GUESS)
- `this+0x00000564` `double rotation_accel_1` (write, GUESS)
- `this+0x00000568` `double rotation_accel_2` (write, GUESS)
- `this+0x0000056C` `double rotation_accel_3` (write, GUESS)
- `this+0x00000570` `double rotation_accel_4` (write, GUESS)
- `this+0x00000574` `double rotation_accel_5` (write, GUESS)
- `*(this+0x4E8)+0x00000080` `ptr sub_controller_0_inner` (read, GUESS)
- `*(this+0x4EC)+0x00000080` `ptr sub_controller_1_inner` (read, GUESS)
- `*(this+0x4F0)+0x00000080` `ptr sub_controller_2_inner` (read, GUESS)
- `*(this+0x4F4)+0x00000080` `ptr sub_controller_3_inner` (read, GUESS)
- `*(*(this+0x4E8)+0x80)+0x00000000` `ptr sub_controller_0_vtable` (read, GUESS)
- `*(*(this+0x4EC)+0x80)+0x00000000` `ptr sub_controller_1_vtable` (read, GUESS)
- `*(*(this+0x4F0)+0x80)+0x00000000` `ptr sub_controller_2_vtable` (read, GUESS)
- `*(*(this+0x4F4)+0x80)+0x00000000` `ptr sub_controller_3_vtable` (read, GUESS)
- `*(*(*(this+0x4E8)+0x80)+0x0)+0x00000058` `ptr sub_controller_0_enable_disable_slot` (read, GUESS)
- `*(*(*(this+0x4EC)+0x80)+0x0)+0x00000058` `ptr sub_controller_1_enable_disable_slot` (read, GUESS)
- `*(*(*(this+0x4F0)+0x80)+0x0)+0x00000058` `ptr sub_controller_2_enable_disable_slot` (read, GUESS)
- `*(*(*(this+0x4F4)+0x80)+0x0)+0x00000058` `ptr sub_controller_3_enable_disable_slot` (read, GUESS)

### ControlStateDispatcher

Small control-value dispatcher: *a2==0 routes to a struct-init helper, *a2==1 routes through a compute-and-select path to a device object selector, otherwise returns *a2-1.

Methods: `0x004530A0`


### DeviceContextInitializer

Large object initialization: zeroed regions, three 17-count groups, 44 fixed structs built via StructInitWithFixedValues, 44 {value, -1} sentinel pairs, activation byte and tail sentinel, ending in a self-reference.

Methods: `0x004531A0`

- `this+0x00000008` `dword state_flag` (write, GUESS)
- `this+0x0000027C` `dword group_a_count` (write, GUESS)
- `this+0x00000D7C` `byte activation_flag` (write, GUESS)
- `this+0x00000D80` `dword deactivation_counter` (write, GUESS)
- `this+0x00000E08` `dword group_a_state` (write, GUESS)
- `this+0x0000107C` `dword group_b_count` (write, GUESS)
- `this+0x00001204` `dword group_b_state` (write, GUESS)
- `this+0x00001478` `dword group_c_count` (write, GUESS)
- `this+0x00001580` `ptr self_reference` (write, GUESS)
- `this+0x000022B0` `dword sentinel_pairs_start` (write, GUESS)
- `this+0x000022B4` `dword sentinel_pairs_value` (write, GUESS)
- `this+0x00002410` `dword tail_0` (write, GUESS)
- `this+0x00002414` `dword tail_1` (write, GUESS)
- `this+0x00002418` `dword tail_2` (write, GUESS)
- `this+0x0000241C` `dword tail_3` (write, GUESS)
- `this+0x00002420` `dword tail_4` (write, GUESS)
- `this+0x00002424` `dword tail_sentinel` (write, GUESS)
- `this+0x00002428` `byte end_marker_byte` (write, GUESS)

### SetupDiagnosticClassifier

Classifies vehicle setup/damage state into numeric state IDs (1-109) using constraint-force and swept-AABB passes over scratch buffers, byte-flag fan-outs, and sign/bit-gated value-match blocks, copying a human-readable label on a match.

Methods: `0x00454350`

- `this+0x00001160` `byte diagnostic_flag_00` (read, GUESS)
- `this+0x00001161` `byte diagnostic_flag_01` (read, GUESS)
- `this+0x00001162` `byte diagnostic_flag_02` (read, GUESS)
- `this+0x00001163` `byte diagnostic_flag_03` (read, GUESS)
- `this+0x00001164` `byte diagnostic_flag_04` (read, GUESS)
- `this+0x00001165` `byte diagnostic_flag_05` (read, GUESS)
- `this+0x00001166` `byte diagnostic_flag_06` (read, GUESS)
- `this+0x00001167` `byte diagnostic_flag_07` (read, GUESS)
- `this+0x00001168` `byte diagnostic_flag_08` (read, GUESS)
- `this+0x00001169` `byte diagnostic_flag_09` (read, GUESS)
- `this+0x0000116A` `byte diagnostic_flag_0A` (read, GUESS)
- `this+0x0000116B` `byte diagnostic_flag_0B` (read, GUESS)
- `this+0x0000116C` `byte diagnostic_flag_0C` (read, GUESS)
- `this+0x0000116D` `byte diagnostic_flag_0D` (read, GUESS)
- `this+0x0000116E` `byte diagnostic_flag_0E` (read, GUESS)
- `this+0x0000116F` `byte diagnostic_flag_0F` (read, GUESS)
- `this+0x00001170` `dword value_match_block_1` (read, GUESS)
- `this+0x00001174` `dword value_match_block_2` (read, GUESS)
- `this+0x00001178` `dword value_match_block_3` (read, GUESS)
- `this+0x0000117C` `dword value_match_block_4` (read, GUESS)
- `this+0x00001180` `dword sign_and_bit_guard_1` (read, GUESS)
- `this+0x0000155C` `byte diagnostic_flag_2_00` (read, GUESS)
- `this+0x0000155D` `byte diagnostic_flag_2_01` (read, GUESS)
- `this+0x0000155E` `byte diagnostic_flag_2_02` (read, GUESS)
- `this+0x0000155F` `byte diagnostic_flag_2_03` (read, GUESS)
- `this+0x00001560` `byte diagnostic_flag_2_04` (read, GUESS)
- `this+0x00001561` `byte diagnostic_flag_2_05` (read, GUESS)
- `this+0x00001562` `byte diagnostic_flag_2_06` (read, GUESS)
- `this+0x00001563` `byte diagnostic_flag_2_07` (read, GUESS)
- `this+0x00001564` `byte diagnostic_flag_2_08` (read, GUESS)
- `this+0x00001565` `byte diagnostic_flag_2_09` (read, GUESS)
- `this+0x00001566` `byte diagnostic_flag_2_0A` (read, GUESS)
- `this+0x00001567` `byte diagnostic_flag_2_0B` (read, GUESS)
- `this+0x00001568` `byte diagnostic_flag_2_0C` (read, GUESS)
- `this+0x00001569` `byte diagnostic_flag_2_0D` (read, GUESS)
- `this+0x0000156A` `byte diagnostic_flag_2_0E` (read, GUESS)
- `this+0x0000156B` `byte diagnostic_flag_2_0F` (read, GUESS)
- `this+0x0000156C` `dword value_match_block_2_1` (read, GUESS)
- `this+0x00001570` `dword value_match_block_2_2` (read, GUESS)
- `this+0x00001574` `dword value_match_block_2_3` (read, GUESS)
- `this+0x00001578` `dword value_match_block_2_4` (read, GUESS)
- `this+0x0000157C` `dword sign_and_bit_guard_2` (read, GUESS)

## Compatibility contracts

- **BVHNodeTraversalLayout** — Replacement must preserve the BVH node layout traversed at 0x0044AA30: node type word at this+0x8 (negative = leaf, 0xFFFE = two-surface sentinel testing a second surface at surface+92), surface pointer at this+0x10, split-axis word at this+0xA with sign word at this+0xC, axis table global 0x007CA3A4, child subtree at this+0x1C, next sibling at this+0x20 and next bound at this+0x24; leaf hits run QuadraticSurfaceCollisionTest (0x0044A070).
- **CursorScrollTrackerLayout** — Replacement must preserve the scroll-tracker layout updated at 0x0044F73C: viewport Y bounds this+0x0/0x4 (this+0x4 is also the return value), clamp bounds this+0x8/0xC, center this+0x10/0x14, per-axis scale factors this+0x18/0x1C, normalized deltas this+0x20/0x24, and normalized clamped positions this+0x28/0x2C.
- **DriverInputControllerChannelDispatch** — Replacement must preserve the per-frame driver input controller contract at 0x00451720: ten channel records laid out stride 104 from 'this' (channel live when the byte at +4 is nonzero and its object pointer at +100 is present); outputs pushed through each channel object's vtable at +24/+28/+32; audio sub-controllers at this+0x4E8/0x4EC/0x4F0/0x4F4 with inner object at +0x80 and vtable slot +0x58 dispatched with argument 32 (enable) or 16 (disable) gated by global byte_7C56AC and latch this+0x418; CRTFtol at 0x00587BDC.
- **GlobalStatePairInitValues** — The two-global initializers must run with the packet constants: dword_7CCFE4=-1082130432/flt_7CCFE8=0.0; flt_7CD110=0.0/dword_7CD114=1065353216; dword_7CD190=-1082130432/flt_7CD194=0.0; dword_7CA440=-1082130432/flt_7CA444=0.0; flt_7CA450=0.0/dword_7CA454=1065353216; dword_7CCBFC=-1082130432/flt_7CCC00=0.0; flt_7CA3B0=0.0/dword_7CA3B4=1065353216; flt_7CC9F4=0.0/dword_7CC9F8=1065353216; dword_7CA3E0=-1082130432/flt_7CA3E4=0.0.
- **GlobalStateBlockInitValues** — The six-dword block initializers must write the packet tag/zero/tail pattern: tag literals as first dword (2, 3, 14, 15, 25, 35, 36, 47, 66, 75, 76, 86, 95, 96), zeroed intervening fields, and tail literals 9000 (0x007CD0C4, 0x007CA4F4) or 18000 (0x007CD12C, 0x007CA560); the 0x0044C6E0/0x0044D220 blocks additionally hold the float 1.0 bit pattern in their last dword.
- **SetupDiagnosticStateClassification** — Replacement must preserve the state classifier at 0x00454350: ordered ConstraintForceEval (0x00454250) / SweptAABBOverlapDetection (0x004542D0) passes against scratch buffers 0x007CD168/0x007CCA8C assign state IDs 1-12/102-105 and 30-41/106-109; the 16 byte-flag fields at this+0x1160..0x116F and this+0x155C..0x156B assign states 13-28 and 42-57; the sign+bit-gated value-match blocks on this+0x1180/0x157C assign states 70-85 and 86-101; the final label is copied from aEmpty (0x005C44B0) with a 9-byte stride when any state matched.
- **ControlStateDispatchContract** — Replacement must preserve the control dispatcher at 0x004530A0: *a2==0 routes to StructInitWithSubCall (0x004527E0); *a2==1 routes through sub_452B10 (0x00452B10, with a3==2 coerced to a boolean) to DeviceObjectSelector (0x00452810) when that returns non-zero; otherwise returns *a2-1.
- **DeviceContextInitLayout** — Replacement must preserve the large object initialization at 0x004531A0: three group count fields = 17 at this+0x27C/0x107C/0x1478, 44 fixed 11-dword structs at this+0x1B20 built via StructInitWithFixedValues (0x00452780), 44 {value, -1} sentinel pairs at this+0x22B0, activation byte this+0xD7C = 1, tail sentinel this+0x2424 = -2 and self-reference this+0x1580 = this.

## Unresolved

- BVHTreeTraversal: the exact node layout mapping the packet fields (bounds at this+0x1C, next sibling at this+0x20, next bound at this+0x24) onto the raw pointer/float arithmetic follows the skeleton fill at DERIVED trust and is not independently verified here. The axis table is rendered by the raw source as both dword_7CA388 and the indexed float access unk_7CA3A4; only the single global 0x007CA3A4 is granted by the packet, so the second table address is not referenced.
- TriangleProximityTest: the comparison body that sets flags c0/c2 is missing from the raw source (only the flag OR-return survived); the role of the double global dbl_59EF40 (0x0059EF40) in the comparison is inferred from deterministic facts, not from the raw text; semantics of a1/a2/a3 are unrecoverable from this body.
- Global state initializers: semantic roles of every written global are not established by the packet; interpretations of the repeated literals 1065353216 (float 1.0 bit pattern) and -1082130432 (float -1.0 bit pattern) are DERIVED, not asserted. Most initializers have no static callers in the packet, so invocation context is unknown.
- InitMouseAbsAxisX (0x0044CAA0): the callee RenderStateFloatInitialization has no callee evidence reference in the packet; its identity is inferred from the raw source text only. Callers are unknown.
- SpatialNodeInitCe00 / GlobalStateInitializerCe60: the named callees GlobalStateInitializer_ce14() and InitFloatGlobals() have addresses absent from the packet callee facts; the 0x0044CE00->0x0044CE14 and 0x0044CE60->0x0044CE74 call edges are taken from the raw source text, not from callee facts.
- InitMouseAxis (0x0044E720): the LEGACY ABI name is unverified; the globals it writes are collision-block-like, so the mouse-axis semantics may be mislabeled.
- SpatialNodeInit_e300 / AudioFilterParameterDefaults / SpatialNodeInit_ea80: DERIVED labels (element count, max search distance, render threshold, filter type) are unverified; owner object identity and invocation context are unknown.
- UpdateCursorScrollPosition: the exact meaning of the scale factors at this+0x18/0x1C (interpreted as reciprocal half-width/height by existing analysis) is DERIVED; parameters a4/a5 are unused; owner object and class are not evidenced; no callers recorded.
- DriverInputControllerUpdateTick: three switch jump tables (0x00452668, 0x00452680, 0x00452690), a block of read-only FPU constant globals (0x0059E430..0x0059EF74) and flt_7D24A0 are listed as accessed but do not appear in the raw text; the meaning of the large channel-message constants passed to vtable slots +24/+28/+32 is not evidenced; the precise owner type and the object at +0x80 inside each sub-controller are not evidenced here.
- DispatchOnControlState: the meaning of the control values in a2[0] (0 = init, 1 = compute-and-select) and the payload a2[1], and why a3 == 2 is coerced to a boolean for sub_452B10, are not established; the owning object and the device-selection domain are unidentified.
- MemoryAllocation_31a0: exact device-context semantics (force-feedback per existing analysis) are not provable from this packet alone; the 17 axis count and the role of the 44 fixed structs and 44 {value, -1} sentinel pairs are unconfirmed; region memsets at this+0x4, this+0xCBC, this+0xD88, this+0x1184, this+0x1580 have no per-field evidence refs.
- ClassifySetupDiagnosticState: the semantic meaning of each numeric state ID (1-109) and of the aEmpty label table is not derivable from this packet; the float scratch fills read offsets this+3428/3460/4288/5308 that are not listed as named fields; the a2 label-table relationship assumes aEmpty has 9-byte entries whose content is not in this packet.
- InitFloatGlobals (0x0044CE74): the decimal literal 1065353216 stored to dword_7CA454 has no established interpretation and the calling context is absent from the packet; the owning object is unknown.
- InitFloatConstants (0x0044CED4): the decimal literal -1082130432 stored to dword_7CCBFC has no established interpretation; calling context and owner are unknown.
- GlobalStateInitializer_cf34: the decimal literal 1065353216 stored to dword_7CA3B4 has no established interpretation; calling context and owner are unknown.
- Class grouping is structural: ABI names suggesting semantic domains (SpatialNode, Audio, Mouse, Scoring, Input) are unverified, and equal offsets on unrelated 'this' pointers (e.g. 0x0-0x2C used by both BVHTreeTraversal and UpdateCursorScrollPosition) are not merged across classes.
