# VehiclePhysicsSystem

Scope: `vehicle_physics`  
Trust: `DERIVED`

Vehicle_physics packet covers the vehicle data path (loadVehicleFiles 0x004C3D80, LoadVehicleEntries 0x004B70B0, writeVehicleSceneFileTemplate 0x004DDF90, VehicleGraphicsSceneLoader 0x004DFCE0), the presentation path (VehicleLabel2DRenderer 0x0049F870, VehicleFlagCheck 0x0049BB20), the session/input gate (InputDispatchAndSessionSync 0x00463CD0), teardown (CollisionSystemShutdownCleanup 0x00494900, UnlinkAndFreePhysicsNode 0x0053CE40), and two adjacent initializers (EngineInitBlock 0x0053C2C0, AudioEngine initialize 0x00546010, PhysicsSubsystemInitDispatcher 0x0056D410). The vehicle array is a shared, count-header-prefixed allocation (dword_8AC394, 1060-byte entries) consumed by loader, grid loader, scene template writer and scene graph loader. Ownership of most objects is UNKNOWN or GUESS; class boundaries here are conservative proposals, not proven source structure.

## Function roles

- `0x00463CD0` **SessionSyncController** — Per-call session gate: dispatches queued input commands to entities and synchronizes session state when the state-guard DWORD at obj+0x3FC4 is non-zero, then unconditionally clears the dispatch flag byte at obj+0x374; returns the guard value on the zero path or the object pointer on the sync path.
- `0x00494900` **CollisionResourceCleanup** — Collision-resource shutdown cleanup over six adjacent global handle slots (0x7CDE04..0x7CDE2C): ResourceCascadeCleanup plus zeroing for the three cascade slots, destructor/free-wrapper cleanup for the four destructor slot pairs; returns the last accumulated cleanup result.
- `0x0049BB20` **VehicleStatusQuery** — Pure query of a byte flag at offset 0x4108 (16648) of the vehicle object behind global dword_7C54E0; returns whether the flag is non-zero. Used by HUD flag renderers as a vehicle flag gate.
- `0x0049F870` **VehicleLabelRenderer** — Gather-and-draw 2D overlay labels for visible vehicles: gated by byte_7CE254, sorts a distance-gathered vehicle list with MergeSort, and renders up to three text labels (name, position, timing gap) via scissored 2D text rendering; frees the gather list after the pass.
- `0x004B70B0` **SessionVehicleGridLoader** — Vehicle-grid loader: peeks the queue head, loops the 104 vehicle slots (18624-byte stride) resolving each entry, transitions session state to 3 on a found entry (delegate, string copy, driver-name set) or -1 on a missing entry, then stores the loaded count, rebuilds the active-vehicle pointer array, clears load-state globals, parses scene data, initializes AI, and returns MultiplayerVehiclePlacement.
- `0x004C3D80` **VehicleFileLoader** — Bulk loader of .veh vehicle files from the season directory into the global count-header-prefixed vehicle array (1060-byte entries at dword_8AC394); tears down any prior array, enumerates and parses each file into a slot, logs 'Failed reading %s' on format failure, then delegates to VehicleDataLoader and returns the loaded count.
- `0x004DDF90` **VehicleSceneFileModule** — Writes a per-vehicle .scn scene template: streams a source template line by line substituting directive tags (id, vehdir, teamdir, spin/notspin, high/med/low, dashhigh/dashlow), with detail selection from a per-vehicle detail mode or a backup override file; logs errors unless the console-mode flag equals 5.
- `0x004DFCE0` **VehicleGraphicsSceneLoader** — Loads and initializes the vehicle graphics scene graph for one vehicle slot: reads and optionally post-processes the scene file, resolves the root node by 'SLOT%03d', resolves wheels/spindles/wings/debris/cockpit/arms/light nodes, assigns audio and disc-glow references, copies the source bounding box, pulls vehicle data and sound-effect handles from global tables, and collects tire child nodes into a per-tire array; returns the collected tire count.
- `0x0053C2C0` **EngineBlockInitializer** — Engine-state block initializer: zeroes the whole block, explicitly clears the first, second and eleventh dword fields, runs an init sub-routine with argument 1, writes three global engine/audio constants, flushes MMX state, and returns the block pointer. Unconditional; no guards.
- `0x0053CE40` **PhysicsNodePool** — Shared physics-object node teardown: removes a node from the global doubly-linked list (head dword_8B8F14, prev/next at node+0x12C/+0x130), runs teardown stubs, frees the node, and decrements the physics-object count at dword_8B6AC0; returns 0 on both the not-found and success paths.
- `0x00546010` **AudioEngine** — Audio-engine initialization: probes the driver, allocates and registers a 496-byte mixer channel into *a1 with flags ORed at +0xEC, allocates sample and vertex-buffer resources, accumulates sample sizes under +0x110, walks the audio-node list running the per-node init pipeline, and returns 0 on success or -1 after unlinking on any allocation failure.
- `0x0056D410` **PhysicsSubsystemInitializer** — Physics-subsystem init dispatcher: delegates initialization to sub_56E970(this), then frees the quad-pointer block at this+0x34 and returns that free operation's result; called from PhysicsInitSequence.

## Proposed classes

### SessionSyncController

Gates session-wide input dispatch and state synchronization on a per-call state guard; owns the dispatch flag cleared each call.

Methods: `0x00463CD0`

- `obj+0x00003FC4` `uint32 session_state_guard` (read, GUESS)
- `obj+0x00000374` `uint8 input_dispatch_flag` (write, GUESS)

### CollisionResourceCleanup

Shutdown teardown of collision-resource global handle slots: cascade cleanup plus destructor/free-wrapper cleanup for two distinct slot families.

Methods: `0x00494900`


### VehicleStatusQuery

Read-only gate on a vehicle flag used by HUD flag rendering; reads the flag through the global vehicle pointer dword_7C54E0.

Methods: `0x0049BB20`


### VehicleLabelRenderer

Gathers visible vehicles, sorts them by distance, and renders up to three scissored 2D text labels per vehicle; manages the per-frame label time budget.

Methods: `0x0049F870`

- `this+0x00000008` `uint8 label_forced_enable` (read_write, GUESS)

### SessionVehicleGridLoader

Loads the session vehicle grid: resolves the 104 vehicle slots against a queue, transitions session state per slot, rebuilds the active-vehicle pointer array, parses scene data, and initializes AI.

Methods: `0x004B70B0`

- `this+0x00000724` `char* scene_data_path` (read, GUESS)
- `this+0x00000F20` `void* multiplayer_placement_param` (read, GUESS)

### VehicleFileLoader

Bulk-reloads .veh vehicle files from the season directory into the global count-header-prefixed vehicle array and delegates parsed data to the vehicle data loader.

Methods: `0x004C3D80`


### VehicleSceneFileModule

Generates per-vehicle .scn scene files from a source template by substituting directive tags with per-vehicle runtime values and gating detail sections by a selected detail level.

Methods: `0x004DDF90`


### VehicleGraphicsSceneLoader

Reads a vehicle scene file, resolves the named scene-graph nodes (wheels, spindles, wings, debris, cockpit, arms, lights), assigns audio and disc-glow references, copies bounding boxes and vehicle data, and collects tire child nodes into a per-tire array.

Methods: `0x004DFCE0`

- `this+0x00000004` `SceneNode* root_scene_node` (write, GUESS)
- `this+0x00000060` `float working_bbox_min_x` (write, GUESS)
- `this+0x00000064` `float working_bbox_min_y` (write, GUESS)
- `this+0x00000068` `float working_bbox_min_z` (write, GUESS)
- `this+0x0000006C` `float working_bbox_max_x` (write, GUESS)
- `this+0x00000070` `float working_bbox_max_y` (write, GUESS)
- `this+0x00000074` `float working_bbox_max_z` (write, GUESS)
- `this+0x00000078` `float source_bbox_min_x` (read, GUESS)
- `this+0x0000007C` `float source_bbox_min_y` (read, GUESS)
- `this+0x00000080` `float source_bbox_min_z` (read, GUESS)
- `this+0x00000084` `float source_bbox_max_x` (read, GUESS)
- `this+0x00000088` `float source_bbox_max_y` (read, GUESS)
- `this+0x0000008C` `float source_bbox_max_z` (read, GUESS)
- `this+0x00000144` `SceneNode* wheel_lf_node` (read, GUESS)
- `this+0x00000188` `SceneNode* spindle_lf_node` (read, GUESS)
- `this+0x0000026C` `SceneNode* wheel_rf_node` (read, GUESS)
- `this+0x000002B0` `SceneNode* spindle_rf_node` (read, GUESS)
- `this+0x00000394` `SceneNode* wheel_lr_node` (read, GUESS)
- `this+0x000003D8` `SceneNode* spindle_lr_node` (read, GUESS)
- `this+0x000004BC` `SceneNode* wheel_rr_node` (read, GUESS)
- `this+0x00000500` `SceneNode* spindle_rr_node` (read, GUESS)
- `this+0x0000018C` `SceneNode* wheel_block_tire_node` (write, GUESS)
- `this+0x00000190` `SceneNode* wheel_block_spindle_node` (write, GUESS)
- `this+0x00000194` `unknown wheel_block_spare_1` (write, GUESS)
- `this+0x00000198` `unknown wheel_block_spare_2` (write, GUESS)
- `this+0x0000019C` `unknown wheel_block_spare_3` (write, GUESS)
- `this+0x000001A0` `unknown wheel_block_spare_4` (write, GUESS)
- `this+0x000001E0` `SceneNode* disc_glow_node_first` (write, GUESS)
- `this+0x000001E4` `SceneNode* disc_glow_node_second` (write, GUESS)
- `this+0x000001E8` `uint32 wheel_block_lod_counter` (write, GUESS)
- `this+0x000001EC` `float wheel_block_scaled_radius` (write, GUESS)
- `this+0x000005E4` `SceneNode* front_wing_node` (read, GUESS)
- `this+0x00000628` `SceneNode* rear_wing_node` (read, GUESS)
- `this+0x0000066C` `SceneNode* debris_node_base` (read, GUESS)
- `this+0x0000088C` `SceneNode* cockpit_node` (read, GUESS)
- `this+0x00000890` `SceneNode* suspension_node` (read, GUESS)
- `this+0x00000894` `SceneNode* helmet_node` (read, GUESS)
- `this+0x00000898` `SceneNode* arms_node` (read, GUESS)
- `this+0x0000089C` `SceneNode* body_node` (read, GUESS)
- `this+0x000008A0` `SceneNode* generic_wheel_node` (read, GUESS)
- `this+0x000008A4` `SceneNode* rain_light_node` (read, GUESS)
- `this+0x000008A8` `SceneNode* brake_light_node` (read, GUESS)
- `this+0x000008AC` `SceneNode* headlight_node` (read, GUESS)
- `this+0x000008B0` `SceneNode* backfire_light_node` (read, GUESS)
- `this+0x000008B4` `uint32 arms_child_count` (read_write, GUESS)
- `this+0x000008C0` `uint32 catsteer_match_count` (write, GUESS)
- `this+0x000008C4` `SceneNode*[2] catsteer_match_nodes` (write, GUESS)
- `this+0x000008E8` `unknown vehicle_data_copy_1` (write, GUESS)
- `this+0x000008EC` `unknown vehicle_data_copy_2` (write, GUESS)
- `this+0x000008F0` `unknown vehicle_data_copy_3` (write, GUESS)
- `this+0x000008F4` `unknown vehicle_data_copy_4` (write, GUESS)
- `this+0x000008F8` `unknown vehicle_data_copy_5` (write, GUESS)
- `this+0x000008FC` `unknown vehicle_data_copy_6` (write, GUESS)
- `this+0x00000900` `unknown vehicle_data_zero_1` (write, GUESS)
- `this+0x00000904` `unknown vehicle_data_zero_2` (write, GUESS)
- `this+0x00000908` `unknown vehicle_data_zero_3` (write, GUESS)
- `this+0x0000090C` `unknown vehicle_data_zero_4` (write, GUESS)
- `this+0x00000910` `unknown vehicle_data_zero_5` (write, GUESS)
- `this+0x00000914` `unknown vehicle_data_zero_6` (write, GUESS)
- `this+0x00000918` `unknown vehicle_data_copy_7` (write, GUESS)
- `this+0x0000091C` `unknown vehicle_data_copy_8` (write, GUESS)
- `this+0x00000920` `unknown vehicle_data_copy_9` (write, GUESS)
- `this+0x00000924` `unknown vehicle_data_copy_10` (write, GUESS)
- `this+0x00000928` `unknown vehicle_data_copy_11` (write, GUESS)
- `this+0x0000092C` `unknown vehicle_data_copy_12` (write, GUESS)
- `this+0x00000930` `float[3] helmet_float_query` (write, GUESS)
- `this+0x00000934` `unknown zeroed_block_1` (write, GUESS)
- `this+0x00000938` `unknown zeroed_block_2` (write, GUESS)
- `this+0x0000093C` `unknown zeroed_block_3` (write, GUESS)
- `this+0x00000940` `unknown zeroed_block_4` (write, GUESS)
- `this+0x00000944` `unknown zeroed_block_5` (write, GUESS)
- `this+0x00000948` `uint16 zeroed_block_word` (write, GUESS)
- `this+0x00000950` `unknown zeroed_field` (write, GUESS)
- `this+0x00000958` `unknown trailing_copy_1` (write, GUESS)
- `this+0x0000095C` `unknown trailing_copy_2` (write, GUESS)
- `this+0x00000960` `unknown trailing_copy_3` (write, GUESS)
- `this+0x0000096C` `uint8 state_flag_a` (write, GUESS)
- `this+0x0000096D` `uint8 state_flag_b` (write, GUESS)
- `this+0x00000970` `float init_value_float` (write, GUESS)
- `this+0x00000975` `uint8 state_flag_c` (write, GUESS)
- `this+0x00000976` `uint8 state_flag_d` (write, GUESS)
- `this+0x00000977` `uint8 state_flag_e` (write, GUESS)
- `this+0x00000978` `uint8 state_flag_f` (write, GUESS)
- `this+0x00000979` `uint8 state_flag_g` (write, GUESS)
- `this+0x0000097C` `float tire_brightness_factor` (write, GUESS)
- `this+0x00000B6C` `unknown effect_field` (write, GUESS)
- `this+0x00002BD0` `uint32 tire_count` (read_write, GUESS)
- `this+0x00002BD4` `void* tire_data_array` (read_write, GUESS)
- `obj+0x00004894` `uint32 parent_slot_index` (read, GUESS)
- `obj+0x00004898` `uint32 vehicle_array_index` (read, GUESS)

### EngineBlockInitializer

Zero-initializes an engine-state block, clears selected fields, runs an init sub-routine, and writes global engine/audio constants.

Methods: `0x0053C2C0`

- `this+0x00000000` `uint32 first_dword` (write, GUESS)
- `this+0x00000004` `uint32 second_dword` (write, GUESS)
- `this+0x0000002C` `uint32 eleventh_dword` (write, GUESS)

### PhysicsNodePool

Shared doubly-linked pool of physics-object nodes with a tracked global count; removal patches both links, updates the head, runs teardown stubs, and frees the node.

Methods: `0x0053CE40`

- `this+0x0000012C` `void* prev_link` (read_write, GUESS)
- `this+0x00000130` `void* next_link` (read_write, GUESS)

### AudioEngine

Audio-engine initialization: probes the audio driver, creates and registers a mixer channel, allocates sample and vertex-buffer resources, accumulates sample sizes, and runs the per-node audio-node init pipeline.

Methods: `0x00546010`

- `obj+0x000000EC` `uint32 channel_flags` (read_write, GUESS)
- `obj+0x00000100` `void* audio_node_list_head` (read, GUESS)
- `obj+0x00000110` `void* sample_size_block_ptr` (read, GUESS)
- `this+0x00000000` `void* mixer_channel_out` (write, GUESS)
- `*(obj+0x110)+0x00000014` `uint32 sample_size_1` (read, GUESS)
- `*(obj+0x110)+0x00000018` `uint32 sample_size_2` (read, GUESS)
- `*(obj+0x110)+0x0000001C` `uint32 sample_size_3` (read, GUESS)
- `*(obj+0x110)+0x00000020` `uint32 sample_size_4` (read, GUESS)
- `*(*(obj+0x100)+0x104)+0x00000104` `void* node_next_link` (read, GUESS)

### PhysicsSubsystemInitializer

Dispatcher for physics-subsystem initialization: delegates to an init routine then frees the quad-pointer block at offset 0x34.

Methods: `0x0056D410`


## Compatibility contracts

- **VehicleArrayCountHeaderLayout** — The global vehicle array (dword_8AC394) is a payload pointer 4 bytes after a count-header block; entries are 1060 bytes (265 dwords), the count lives in the header and is mirrored in dword_8AC390. A replacement loader must preserve this header-plus-payload allocation scheme and the per-entry stride.
- **PhysicsNodeDoublyLinkedPool** — Physics-object nodes live in a global doubly-linked list (head dword_8B8F14, prev/next at node+0x12C/+0x130) with a tracked count at dword_8B6AC0. Removal patches both links, updates the head, runs teardown stubs, frees the node, and decrements the count.
- **VehicleSceneFileDirectives** — The .scn template writer substitutes the directive tags id, vehdir, teamdir, spin, notspin, med/high/low and dashlow/dashhigh with per-vehicle values; non-matching detail levels emit the placeholder marker. A replacement generator must reproduce these directives and the detail-level gate (v29/v30).
- **VehicleSceneInstanceNaming** — Vehicle graphics scenes are instanced by 'SLOT%03d' name derived from the parent slot index obj+0x4894, and child nodes are resolved by fixed names (wheels, spindles, wings, DEBRIS%d, catsteer, tire names rftire/lrtire/rrtire, sound names tread/treadmed/treadlow). A replacement scene loader must honor these names.
- **SessionStateGuardSemantics** — Session dispatch is gated by a state guard DWORD at obj+0x3FC4; a non-zero guard runs input dispatch then session sync and returns the object pointer, a zero guard returns the guard value; either path clears the flag byte at obj+0x374.
- **AudioEngineInitReturnContract** — Audio-engine initialization writes a 496-byte mixer channel into *a1, appends it to the mixer list, ORs flag bits into its +0xEC flags, allocates sample and vertex buffers, accumulates sample sizes under the +0x110 block, walks the audio-node list, and returns 0 on success or -1 (after unlinking) on allocation failure.

## Unresolved

- Most function owner objects are UNKNOWN: the object types behind dword_7C54E0 (VehicleStatusQuery), the SessionSyncController object, and the EngineBlockInitializer block are not established.
- dword_8AFE64 is flagged as read by packet facts for 0x00494900, 0x0049F870 and 0x004DFCE0 but is absent from every raw decompiled body; its role is unverifiable here.
- Ten read-only float globals (flt_59E440, flt_59E444, flt_59E448, flt_59E478, flt_59E874, flt_59E970, flt_59F0C0, flt_59F124, flt_5A68E8, dbl_5ACB18) are flagged for 0x0049F870 and never appear in the rendered source.
- Four read-only globals (flt_59E43C, flt_59E854, flt_59ED18, flt_5AD14C) are flagged for 0x004DFCE0 and never appear in the rendered source.
- unresolved packet globals for the vehicle grid loader and scene module: unk_5EC6D0, dword_7D2E48, unk_8AC368 (0x004B70B0) and global 0x005C67E0 (0x004DDF90); none are consumed by any evidenced operation.
- unresolved packet globals for the audio and engine blocks: unk_8B6BD0 (0x0053C2C0) and global 0x008B8F24 (0x00546010).
- The vehicle record layout behind dword_8AC394 entries (1060-byte stride) is only partially evidenced: the .veh record bytes at v4+65, v4+97, v4+1 (LoadVehicleEntries) and record fields +0/+32 (writeVehicleSceneFileTemplate) are not named fields in the packet.
- The wheel-setup loop writes float data at byte offsets inside the wheel blocks that are not represented in the packet field table; only 0x1EC is listed, so those write sites are under-evidenced.
- The arms-child collection stores matched child handles at dword indices 558..559, conflated with the comparison-result region 0x8C4 in the operation evidence.
- The distinction between ResourceCascadeCleanup slots and DestructorWithConditionalFreeFlagClear slots in CollisionSystemShutdownCleanup is structural, not semantic.
- QuadPointerFree is named in the raw source of 0x0056D410 but is absent from the packet callee list, so its address cannot be recorded here.
- The per-character vehicle-record offset mapping for unknown .scn tokens (v14[k] + v32 - 9) has unclear semantics.
- The AudioEngine owner type is DERIVED from a legacy ABI name and audio subsystem tag, not CONFIRMED; the callback dword_8B8F00 and constants 16/0 are unevidenced.
- Equal field offsets observed on different function objects (e.g. this+0x4 in EngineBlockInitializer and VehicleGraphicsSceneLoader) are NOT merged into a common class because the packet does not prove common ownership.
