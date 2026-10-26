# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `GUESS`

Proposed DERIVED/GUESS architecture for the generic runtime object cluster. The 21 functions group into a few defensible classes: SpatialGrid (world-to-cell collision query with cached-surface invalidation), HdvVehicleFileParserHelper (accumulates .hdv parameter values into a caller dword), CollisionSensorContainer (constructor-style init of 104 sensor entries on a 560-byte stride plus the per-frame visibility/dispatch grid update over linked lists at +0xE5B0/+0xE5C0; ctor uses base 'this', update uses base 'obj', shared scale defaults at +0x60/+0x64), BroadphasePairList (inner proxy list with head/tail/current/count refined against an outer list), OwnershipListContainer (vtable + five owned pointers + three ownership-flag lists, destructor), ProfileCreatePageHandler (unique-name create vs already-exists flow), TireCompoundSelector (mode/flag switch at +0x128..+0x130, 64-byte-stride cyclic index navigation, float-to-index clamp, part-name to compound-ID mapping), CameraObject (target-tracking / rotation-matrix pose update with spatial-grid height adjustment), AIIncidentCooldownManager (cooldown timestamp at +0x1A0 gates per-frame incident firing), SettingsRegistrationObject (flag at +0x10 mirrored into global dword_7CE2E8 which gates linked-list append), and BitFlagByteAccessor (bit-7 set/clear). Three functions stay owner UNKNOWN: NoopStub, the per-frame post-update dispatcher, and the indexed-slot setter. Function IR and packet evidence outrank this synthesis; all structure is DERIVED or GUESS.

## Function roles

- `0x0044C4C0` **SpatialGrid** — SpatialGridQuery: maps a world position through the grid origin/scale doubles into 32x32 cell indices and returns the cached colliding surface, re-traversing the cell BVH on cache miss; used by suspension, contact generation and camera paths.
- `0x0045C400` **HdvVehicleFileParserHelper** — ParseHdvFileAccumulateValues: parses a .hdv file into a session struct, accumulates six parameter values plus a tyre-model contribution into the caller's output dword, frees all parsed-data allocations, returns AND-combined success.
- `0x004649F0` **BitFlagByteAccessor** — BitFlagSetter: sets or clears bit 7 (0x80) of the byte at this+0x0 depending on argument a2; returns a2 unchanged.
- `0x00464C10` **CollisionSensorContainer** — LargeStructInitialization: constructor-style init of the large collision-sensor container - zeroes leading block and tail dwords, creates 104 sensor entries on a 560-byte stride with callback sub_464D20 and CollisionSensorInit, initializes the QPC timer, sets scale defaults (1.0f) and -1 sentinels, fills a 0x1A0-byte block with 0xFF.
- `0x00465460` **CollisionSensorContainer** — UpdateEntityVisibilityGrid: per-frame visibility manager update - derives a budget, classifies rank into an LOD factor, rebuilds and merge-sorts the candidate entity list, dispatches visibility/computation work per entity under the budget cap, appends progress-bar events for rank-out entities, publishes the object base to dword_7CD2AC.
- `0x0046CB50` **ProfileCreatePageHandler** — ProfileAlreadyExistsPageHandler: UI page handler for profile creation - unique name path creates the profile (result 0); already-exists path shows the message and dispatches the prompt (result -1); finalizes via two dispatch objects fetched from dword_7CD8C0.
- `0x0047AA60` **UnknownObject** — NoopStub (nullsub_2): empty function body; no reads, writes, calls or guards; placeholder or intentionally disabled handler called once by PlayerOptionsInitializer.
- `0x00485EB0` **OwnershipListContainer** — ListAndPointerDestructor: destructor - resets the vtable pointer at this+0x0, runs MultiListDestructorWithCleanup, conditionally frees five single pointers (this+0xA0..0xC0), walks and frees three ownership-flag linked lists (heads at +0x70, +0x54, +0x44), zeroes every list header, returns a final cleanup helper result.
- `0x00490D00` **BroadphasePairList** — BroadphasePairPartition: broadphase collision-partition pass over two proxy lists - non-overlapping pairs are refined with sub_491680/RectangleClipping and re-appended to the inner list; overlapping pairs are unlinked from the inner list and re-prepended to the outer list.
- `0x0049F070` **UnknownObject** — ShortComputation_f070: per-frame post-update dispatcher - mode dispatch, camera-shake clamp, booted/kicked check, session-mode update, steering-wheel animation, conditional resource thunk when dword_8AB6E4 != 2, post-frame sub-handler, and a gated position/speed overlay rendering path.
- `0x004A1B70` **SettingsRegistrationObject** — ShortComputation_1b70: conditional linked-list append - when global dword_7CE2E8 is non-zero appends `this` to a linked list via LinkedListAppend_1dc0 and returns its result, otherwise returns `this`; shared tail hook for eight setter/wrapper functions.
- `0x004A1DA0` **SettingsRegistrationObject** — FlagSetterWithGlobalUpdate: writes byte flag a3 into the object at +0x10, mirrors it as an object pointer into global dword_7CE2E8, returns the mirrored pointer.
- `0x004A1E20` **SettingsRegistrationObject** — TripleDispatchWrapper: copies three string arguments via StringCopyWithBufferRealloc then finalizes via ShortComputation_1b70; string-copy setter wrapper.
- `0x004A3B50` **CameraObject** — Camera: camera position/yaw update - target-tracking path (normalized offset, clamped orientation, ring-buffer noise, atan2 yaw) or rotation-matrix path (EulerToRotationMatrix + noise); spatial-grid collision query adjusts camera height when the sound-source handle at this+0x64 is valid; writes the final pose back via Vec3CopyToStruct.
- `0x004A4110` **AIIncidentCooldownManager** — AIIncidentCooldownCheck: per-frame AI incident trigger - blocks incidents for slow AI cars (speed delta in (-55,0) with state guards), then fires only when the cooldown timestamp at this+0x1A0 is expired (writes now+18.0); weighted by session type, race progress, active-vehicle ratio and session-time progress.
- `0x004A46F0` **UnknownObject** — Indexed_Field_Setter_with_Flag: indexed slot setter - reads the slot index from a2+4 and stores a2 (flag a3 non-zero) or NULL into this[index]; returns a2 unchanged.
- `0x004A56B0` **TireCompoundSelector** — StateTransition: mode/flag switch - a2==0 resets this+0x128 to 1 and clears +0x12C/+0x130 (returns 0); a2 non-zero activates (mode 2, flags 1/1, returns 1) unless already active (returns 2).
- `0x004A5750` **TireCompoundSelector** — IncrementIndexWithWrap: increments a per-entry index in a 64-byte-stride table (this + 16*a2 dwords), wraps via the flag byte at base+53 when it reaches the bound at base+40; entry 0 returns a conditional dispatch call; selector 2 normalizes via FindZeroResultIndex.
- `0x004A57A0` **TireCompoundSelector** — DecrementIndexWithWrap: decrements a per-entry index in a 64-byte-stride table and wraps below zero; wrap direction is the inverse of IncrementIndexWithWrap; entry 0 returns a conditional dispatch call; selector 2 normalizes via FindZeroResultIndex.
- `0x004A5BD0` **TireCompoundSelector** — ClampedIndexAssignment: converts a float into a clamped table index - CRTFtol((a2 - this+0x58) / this+0x60 + 0.5), clamps into [0, this+0x68-1], stores at this+0x6C, returns the unclamped index.
- `0x004A5C10` **TireCompoundSelector** — GuardedCallWithCheck: resolves the nth valid part via NthValidPartLookup(this, a2), substitutes fallback byte_5EA438 when the part string is empty, and maps it through TireCompoundNameIDMapping to a tire-compound name ID; returns null when no valid part exists.

## Proposed classes

### SpatialGrid

2D collision grid: maps a world position through origin and inverse-cell-size doubles into 32x32 cell indices; each cell holds a BVH tree pointer used to resolve the colliding surface for a query position, with a per-query cached-surface pointer that is invalidated and recomputed on cache miss.

Methods: `0x0044C4C0`

- `this+0x00000008` `double grid_origin_x` (read, DERIVED)
- `this+0x00000010` `double grid_origin_z` (read, DERIVED)
- `this+0x00000018` `double inverse_cell_size_x` (read, DERIVED)
- `this+0x00000020` `double inverse_cell_size_z` (read, DERIVED)

### HdvVehicleFileParserHelper

Parses a vehicle .hdv file into a session struct and accumulates a set of selected parameter values plus a tyre-model contribution into a caller-supplied output dword; frees all parsed-data allocations and AND-combines the selector-call success flag.

Methods: `0x0045C400`

- `this+0x00000001` `uint8 parameter_selector_byte` (read, DERIVED)

### CollisionSensorContainer

Large runtime object owning 104 collision-sensor entries on a 560-byte stride (constructor-style initialization) and the per-frame entity-visibility/dispatch grid update that rebuilds, sorts and drains candidate (obj+0xE5B0) and visibility (obj+0xE5C0) linked lists under a per-frame budget. The constructor uses packet base 'this' while the update uses base 'obj'; common ownership is DERIVED from the shared scale defaults at +0x60/+0x64 and the shared 4-slot list headers at +0xE5B0..0xE5CC.

Methods: `0x00464C10`, `0x00465460`

- `this+0x00000050` `int32 sentinel_int_a` (write, DERIVED)
- `this+0x00000054` `int32 sentinel_int_b` (write, DERIVED)
- `this+0x00000060` `float scale_factor_x` (read_write, DERIVED)
- `this+0x00000064` `float scale_factor_y` (read_write, DERIVED)
- `this+0x0000006C` `pointer entity_list_head` (read_write, DERIVED)
- `this+0x00000070` `dword entity_list_field_70` (write, GUESS)
- `this+0x00000074` `pointer entity_list_cursor` (read_write, DERIVED)
- `this+0x00000078` `dword unknown_dword_78` (unknown, GUESS)
- `this+0x0000007C` `pointer dispatch_list_head` (read, DERIVED)
- `this+0x00000080` `dword unknown_dword_80` (write, GUESS)
- `this+0x00000084` `pointer dispatch_list_cursor` (read, DERIVED)
- `this+0x00000088` `dword unknown_dword_88` (unknown, GUESS)
- `this+0x000002AC` `dword sensor_entry_dword_a` (write, DERIVED)
- `this+0x000002B0` `dword sensor_entry_dword_b` (write, DERIVED)
- `this+0x000002B4` `word sensor_entry_word` (write, DERIVED)
- `this+0x000002B8` `pointer sensor_tracking_node_ptr` (write, DERIVED)
- `this+0x0000E40C` `dword unknown_dword_e40c` (write, GUESS)
- `this+0x0000E5B0` `pointer candidate_list_head` (read_write, DERIVED)
- `this+0x0000E5B4` `pointer candidate_list_tail` (read_write, DERIVED)
- `this+0x0000E5B8` `pointer candidate_list_cursor` (read_write, DERIVED)
- `this+0x0000E5BC` `dword candidate_list_count` (read_write, DERIVED)
- `this+0x0000E5C0` `pointer visibility_list_head` (read_write, DERIVED)
- `this+0x0000E5C4` `pointer visibility_list_tail` (read_write, DERIVED)
- `this+0x0000E5C8` `pointer visibility_list_dup_ref` (read_write, DERIVED)
- `this+0x0000E5CC` `dword visibility_list_count` (read_write, DERIVED)
- `obj+0x00000060` `float scale_factor_x` (read, DERIVED)
- `obj+0x00000064` `float scale_factor_y` (read, DERIVED)
- `obj+0x0000006C` `pointer entity_list_head` (read, DERIVED)
- `obj+0x00000074` `pointer entity_list_cursor` (read, DERIVED)
- `obj+0x00000078` `dword unknown_dword_78` (read, GUESS)
- `obj+0x0000007C` `pointer dispatch_list_head` (read, DERIVED)
- `obj+0x00000084` `pointer dispatch_list_cursor` (read, DERIVED)
- `obj+0x00000088` `dword unknown_dword_88` (read, GUESS)
- `obj+0x0000E5B0` `pointer candidate_list_head` (read_write, DERIVED)
- `obj+0x0000E5B4` `pointer candidate_list_tail` (read_write, DERIVED)
- `obj+0x0000E5B8` `pointer candidate_list_cursor` (read_write, DERIVED)
- `obj+0x0000E5BC` `dword candidate_list_count` (read_write, DERIVED)
- `obj+0x0000E5C0` `pointer visibility_list_head` (read_write, DERIVED)
- `obj+0x0000E5C4` `pointer visibility_list_tail` (read_write, DERIVED)
- `obj+0x0000E5C8` `pointer visibility_list_dup_ref` (read_write, DERIVED)
- `obj+0x0000E5CC` `dword visibility_list_count` (read_write, DERIVED)
- `*(obj+0x6C)+0x00000000` `pointer entity_ptr` (read, DERIVED)
- `*(obj+0x6C)+0x000001AC` `dword entity_slot_id` (read, DERIVED)
- `*(obj+0x74)+0x00000000` `pointer next_entity` (read, DERIVED)
- `*(obj+0x7C)+0x00000000` `pointer entity_ptr` (read, DERIVED)
- `*(obj+0x84)+0x00000000` `pointer next_entity` (read, DERIVED)
- `*(obj+0xE5B0)+0x00000000` `pointer node_value` (read, DERIVED)
- `*(*(obj+0xE5B0)+0x0)+0x0000006D` `uint8 entity_data_byte` (read, DERIVED)
- `*(obj+0xE5B8)+0x00000000` `pointer next_node` (read, DERIVED)
- `*(obj+0xE5C0)+0x00000008` `dword node_next_field` (read, DERIVED)
- `*(*(obj+0xE5B8)+0x0)+0x00000000` `pointer node_value` (read, DERIVED)
- `*(*(*(obj+0xE5B8)+0x0)+0x0)+0x0000006C` `uint8 entity_active_byte` (read, DERIVED)
- `*(*(*(obj+0xE5B8)+0x0)+0x0)+0x0000006D` `uint8 entity_rank_byte` (read, DERIVED)
- `*(*(*(obj+0xE5B8)+0x0)+0x0)+0x00000071` `float entity_progress_float` (read, DERIVED)
- `*(*(*(obj+0xE5B8)+0x0)+0x0)+0x00000219` `dword entity_dispatch_dword` (read, DERIVED)
- `*(*(obj+0x7C)+0x0)+0x000001AC` `dword entity_slot_id` (read, DERIVED)

### BroadphasePairList

Collision broadphase partition list: maintains an inner linked list of AABB proxies (head/tail/current/count at +0x0..+0xC) and repartitions pairs against an outer proxy list - non-overlapping pairs are refined via sub_491680/RectangleClipping and re-appended, overlapping pairs are unlinked and re-prepended to the outer list.

Methods: `0x00490D00`

- `this+0x00000000` `pointer list_head` (read_write, DERIVED)
- `this+0x00000004` `pointer list_tail` (read_write, DERIVED)
- `this+0x00000008` `pointer list_current` (read_write, DERIVED)
- `this+0x0000000C` `dword list_count` (read_write, DERIVED)
- `obj+0x00000000` `pointer node_value` (read, DERIVED)
- `obj+0x00000004` `pointer node_next` (read_write, DERIVED)
- `obj+0x00000008` `uint8 node_liveness_flag` (read, GUESS)
- `*(this+0x4)+0x00000004` `pointer tail_node_next` (read_write, DERIVED)
- `*(this+0x8)+0x00000000` `pointer current_node_value` (read, DERIVED)

### OwnershipListContainer

Container owning a vtable pointer at +0x0, five optional single pointers (this+0xA0..0xC0) and three ownership-flag linked lists (heads at +0x70, +0x54, +0x44); the destructor tears down all three lists, conditionally frees the single pointers and the per-node data, and zeroes every list header.

Methods: `0x00485EB0`

- `this+0x00000000` `pointer vtable_ptr` (write, DERIVED)
- `this+0x00000044` `pointer list3_head` (read_write, DERIVED)
- `this+0x00000048` `dword list3_field_48` (read_write, GUESS)
- `this+0x0000004C` `dword list3_field_4c` (read_write, GUESS)
- `this+0x00000050` `dword list3_field_50` (read_write, GUESS)
- `this+0x00000054` `pointer list2_head` (read_write, DERIVED)
- `this+0x00000058` `dword list2_field_58` (read_write, GUESS)
- `this+0x0000005C` `dword list2_field_5c` (read_write, GUESS)
- `this+0x00000060` `dword list2_field_60` (read_write, GUESS)
- `this+0x00000070` `pointer list1_head` (read_write, DERIVED)
- `this+0x00000074` `dword list1_field_74` (read_write, GUESS)
- `this+0x00000078` `dword list1_field_78` (read_write, GUESS)
- `this+0x0000007C` `dword list1_field_7c` (read_write, GUESS)
- `this+0x000000A0` `pointer owned_ptr_a0` (read, GUESS)
- `this+0x000000A8` `pointer owned_ptr_a8` (read, GUESS)
- `this+0x000000B0` `pointer owned_ptr_b0` (read, GUESS)
- `this+0x000000B8` `pointer owned_ptr_b8` (read, GUESS)
- `this+0x000000C0` `pointer owned_ptr_c0` (read, GUESS)
- `*(this+0x44)+0x00000000` `pointer node_data` (read, DERIVED)

### ProfileCreatePageHandler

UI page handler for profile creation: pulls child control 3 from the page control (this+0x40) via its vtable, validates the entered player name for uniqueness, creates the profile on success (result 0) or shows the 'profile already exists' message and dispatches the prompt (result -1), then finalizes through two dispatch objects fetched from dword_7CD8C0.

Methods: `0x0046CB50`

- `this+0x00000040` `pointer page_control` (read, DERIVED)
- `*(this+0x40)+0x00000004` `method_pointer vtable_display_message` (read, DERIVED)
- `*(this+0x40)+0x0000001C` `method_pointer vtable_fetch_child` (read, DERIVED)

### TireCompoundSelector

Per-object tire-compound/part selection: a mode/flag switch at +0x128..+0x130 (codes 0/1/2), cyclic index navigation over a 64-byte-stride entry table (index at base+44, bound at base+40, wrap-direction flag at base+53), float-to-index clamping via this+0x58/+0x60/+0x68/+0x6C, and part-name to compound-ID resolution. Grouping is GUESS, largely linked by the shared pit-stop tire-compound decision caller.

Methods: `0x004A56B0`, `0x004A5750`, `0x004A57A0`, `0x004A5BD0`, `0x004A5C10`

- `this+0x00000058` `float reference_base_value` (read, DERIVED)
- `this+0x00000060` `float step_interval` (read, DERIVED)
- `this+0x00000068` `dword index_upper_bound` (read, DERIVED)
- `this+0x0000006C` `dword clamped_index` (write, DERIVED)
- `this+0x00000128` `dword mode_field` (read_write, DERIVED)
- `this+0x0000012C` `dword status_flag_a` (read_write, DERIVED)
- `this+0x00000130` `dword status_flag_b` (read_write, DERIVED)

### CameraObject

Camera position/yaw update for a 3D object (vehicle/pit-crew camera): target-tracking path (normalized offset, clamped orientation, ring-buffer noise, atan2 yaw) or rotation-matrix path (EulerToRotationMatrix + noise); when the sound-source handle at this+0x64 is valid a spatial-grid collision query adjusts the camera height; the final pose is written back via Vec3CopyToStruct.

Methods: `0x004A3B50`

- `this+0x00000064` `dword sound_source_handle` (read, DERIVED)

### AIIncidentCooldownManager

Per-frame AI incident trigger gate: iterates the vehicle slot array (count dword_5C329C), zeroes inactive slots, blocks incidents for slow AI cars near the player (speed delta in (-55,0) plus state guards), then fires an incident only when the cooldown timestamp at this+0x1A0 is expired (writes now+18.0); firing is weighted by session type, race progress, active-vehicle ratio and session-time progress.

Methods: `0x004A4110`

- `this+0x000001A0` `double cooldown_timestamp` (read_write, DERIVED)

### SettingsRegistrationObject

Object registered into a global-flag-gated linked list by string-setting setters: the flag byte at +0x10 is mirrored into global dword_7CE2E8, and ShortComputation_1b70 appends the object to the list only while that global is non-zero; TripleDispatchWrapper copies three strings then runs the shared tail hook.

Methods: `0x004A1B70`, `0x004A1DA0`, `0x004A1E20`

- `this+0x00000010` `uint8 registered_flag` (read_write, DERIVED)

### BitFlagByteAccessor

Tiny flag manipulator: sets or clears bit 7 (0x80) of the byte at this+0x0 based on an incoming boolean; returns the requested state unchanged.

Methods: `0x004649F0`

- `this+0x00000000` `uint8 bit7_flag` (read_write, DERIVED)

## Compatibility contracts

- **SpatialGridQueryCacheContract** — The grid object stores origin and inverse-cell-size doubles at +0x8..+0x20 and addresses 32x32 cell slots from a grid base (indexed by cell indices), each slot holding a BVH tree pointer. A query struct holds a cached surface pointer (a2+48) and a validity byte (a2+88); SpatialGridQuery returns the cached pointer on a hit, otherwise clears it, maps the world position into cells, and re-traverses the cell BVH. A replacement must preserve the cache-invalidation semantics (cached surface invalid when NULL, validity byte set, or QuadraticSurfaceCollisionTest fails).
- **VehicleRankArrayStrides** — The visibility grid indexes a 0x48C0-stride vehicle array at 0x005EC6D8 (per-rank entity data base, 18624 = 0x48C0 bytes per rank), and rank tables at 0x005EF9A0 (4656-byte stride entries, -1 marks an invalid rank that falls back to the slot index) and 0x005F0F88 (9312-byte stride). A replacement must preserve these strides and the -1 invalid-rank sentinel.
- **ProfileCreatePageResultContract** — The profile-create page returns 0 when the entered name (byte_7CD818) is unique and the profile is created, and -1 when the name already exists, showing the 'profile already exists' message on the page control and dispatching the prompt via LookupDispatch(-1). The one-shot 'player name never used' message is gated by byte_7D2E41 and cleared after display.
- **AIIncidentCooldownContract** — An AI incident fires only when the cooldown timestamp at this+0x1A0 is expired relative to the session-time global dbl_8AFEA0, and then rewrites the timestamp to now+18.0 seconds. Session type 7 (dword_7C56A4) always passes; incidents are blocked when a vehicle's speed delta vs the player is in (-55,0) while its state words are in the active/guard configuration. A replacement must preserve the 18-second cooldown and the (-55,0) block window.
- **TireCompoundModeSwitchContract** — The mode/flag switch at +0x128/+0x12C/+0x130 must preserve its three observable outcomes: reset request returns 0 (mode 1, flags cleared), activation returns 1 (mode 2, flags set), and redundant activation returns 2 without state change.
- **GlobalFlagGatedRegistrationContract** — Global dword_7CE2E8 gates the linked-list append performed by ShortComputation_1b70 (LinkedListAppend_1dc0); FlagSetterWithGlobalUpdate mirrors the +0x10 flag byte into that global as an object pointer or NULL. A replacement must keep the append gated on the same global flag so setter callers observe identical registration semantics.
- **VisibilityDispatchBudgetContract** — The per-frame visibility update derives a work budget from DivisionWithCapComputation and the product of the scale defaults at +0x60/+0x64, dispatches entities under a budget cap (converted to 60-unit steps), appends progress-bar events for rank-out entities, and writes leftover budget headroom back into the per-slot word obj+560*a2+692. A replacement must preserve the budget-accounting discipline (dispatch cost 8+(bits>>8)&0x3FF per payload, 60 per entity).

## Unresolved

- The collision-sensor container's constructor uses packet base 'this' while the visibility-grid update uses base 'obj'; common ownership is DERIVED from shared scale defaults at +0x60/+0x64 and shared 4-slot list headers at +0xE5B0..0xE5CC, but the packet never states the two bases refer to the same object.
- The memset region at this+0xE410 (0x1A0 bytes) in the sensor-container constructor is not enumerated among the packet fields; its role is unknown.
- ShortComputation_a990 in ListAndPointerDestructor (0x00485EB0) has no callee evidence reference in the packet, so its address is unknown; MultiListDestructorWithCleanup is invoked without visible arguments and the embedded sub-object it tears down is unidentified.
- The -109 (0xFFFFFF93) sentinel checked by guard 0 in the visibility update has unknown meaning; existing analysis labels it the entity data block sentinel.
- StateTransition (0x004A56B0) has five callers across pit-stop, collision-particle, motion-post-processing and repair-service subsystems; it may belong to a shared mode-flag mechanism rather than the tire-compound selector specifically.
- The tire-compound table's 64-byte-stride entry fields (index at base+44, bound at base+40, wrap flag at base+53) are not enumerated as packet fields; only the computed access is evidenced.
- The utility selector semantics of UtilityFunction_8a60 (which six parameter keys are selected by this+0x1) and the tyre-model data contribution are not resolvable from this packet alone.
- byte_5EA438 is listed as referenced by ParseHdvFileAccumulateValues but the decompiled body contains no direct reference to it; its intended fallback use is unconfirmed (it is confirmed as a fallback string in GuardedCallWithCheck and ProfileCreatePageHandler).
- Twenty-four physics/threshold globals read by AIIncidentCooldownCheck (flt_59E43C..flt_59E9B8, flt_5ACB0C..flt_5ACB48) never appear in the raw source text; their operations are not visible.
- The AI incident function carries a legacy ABI lead 'AI_Overtaking_Aggression_Probability' conflicting with the existing-analysis title 'AIIncidentCooldownCheck'; the recovered flow fits the cooldown/trigger interpretation.
- Vehicle state-word semantics in AIIncidentCooldownCheck (+17744 active, +17680 driving-state enum with 4/5 special values, +17472 threshold > 2.0) and race-context fields (a2+17800, a2+17888, a2+18596) are unnamed.
- The byte_7CD818 profile-name buffer writer is external to ProfileCreatePageHandler; dispatch objects 3 and 45 fetched from dword_7CD8C0 and their +160/+56 vtable methods are unnamed.
- The overlay-rendering block in the per-frame dispatcher (0x0049F070) is inferred to be a position/speed UI overlay from the PositionComputationWithAlignment/TwoFieldSetterUpdate calls; not confirmed.
- Sixteen float/int constants cited for the camera function (flt_59E43C..flt_5ACB30, dword_8ACEE0) do not appear in its source text; presumed read by callees or compiler-hoisted.
- The query-struct layout of SpatialGridQuery (position X/Z, cached surface, validity byte) is not enumerated as packet fields because a2 is an argument rather than a 'this'/'obj' base.
- obj+0x78 and obj+0x88 in the visibility update are recorded as read but no exact access site was identified in the cleaned source; v19 at the UtilityFunction_4bb0 call site is read uninitialized in the raw source.
- The four v5 shorts passed to AABBOverlapTest/sub_491680 in BroadphasePairPartition (box coords) are not named; the loose-vs-strict test purpose of sub_491680 vs AABBOverlapTest is inferred.
- Argument a2 of FlagSetterWithGlobalUpdate is never read; argument a4 of Indexed_Field_Setter_with_Flag is unused; the field semantics of a2+4 (index source) are unknown.
- Index wrap-direction flag byte at entry base+53 and the conditional-dispatch return for entry 0 in IncrementIndexWithWrap/DecrementIndexWithWrap are undocumented.
- The exact role of global dbl_59E880 (DERIVED name HalfStep) in ClampedIndexAssignment is not visible in the raw source, which inlines the 0.5 rounding literal.
- dbl_7C9360 (the spatial grid instance queried by the camera) and the ring-buffer noise table flt_8AB274 indexed by dword_8AAE70 have DERIVED-only roles.
