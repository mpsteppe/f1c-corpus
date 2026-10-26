# GenericRuntimeObjectLayer

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

Reconstruction of the generic runtime object layer. The dominant object, SessionDataObject, loads/resets game data files (GameDataFileIO), deserializes binary model/scene streams (ModelSceneFileLoader), walks its third linked node list to dispatch byte ranges (NetworkBufferRead), and drives the two-phase session loading sequence (LoadingPhase1, runLoadingPhase2, ProcessDriverEntries, LoadingPhaseOrchestrator). Supporting objects: ReplayRecordingController wraps a SessionDataObject to start/poll replay recording; SessionWeatherDispatcher routes by a type sentinel to session or weather update; LapTimingObject handles per-driver lap/sector completion; SceneExtentObject computes normalized scene extents; LapSessionDataObject is a constructor-style initializer; SettingsIniWriterObject emits a career standings ini block; SceneNodeWriter emits model node records. All ownership is UNKNOWN in the packet and this proposal is DERIVED/GUESS only.

## Function roles

- `0x004B44A0` **SceneNodeWriter** — Model/scene node record writer: resolves a resource handle via ResourceLookupDispatcher into this+0x04, then writes the object through FileWriteWithBackendDispatch as 4 dword-bytes then 2 dword-bytes; always returns 1. Consumed by ModelSceneFileLoader's third-list rebuild.
- `0x004B6C90` **SessionDataObject** — Binary model/scene file deserializer on the session data object: reads string tables and byte flags into this+0xF1C/0xF20, rebuilds the first list (this+0x18 block, count this+0x40, pool this+0x38), tears down and rebuilds the second list (this+0x6C0..0x6CC) from stream nodes, reads three dwords into this+0xF24/0xF28/0xF2C, transfers linked buffers, rebuilds the third list (this+0x714..0x720) via SceneNodeWriter (0x004B44A0), consumes per-node format headers, and computes bounding extents into this+0xF30/0xF34; returns 1 on success.
- `0x004B7300` **SessionDataObject** — Loads or resets game data files for a track/vehicle on the session data object: with the cleanup flag (a3 nonzero) it frees the node list at this+0x6C0, zeroes list state, rebuilds directory/name path strings from dword_7CE5D0 / dword_7CE608 (backslash scan), re-reads vehicle field +18580 into this+0xF1C and session type into this+0xF20, and stores 1/0 in this+0x700 per settings-file presence; with the flag clear it opens an audio stream, loads the model/scene file via ModelSceneFileLoader, stores 2 in this+0x700 on success, and closes the handle on failure. Returns *(this+0x6E4) != 0.
- `0x004B7C80` **SessionDataObject** — Walks a linked list of data entries (list head this+0x714, walk pointer this+0x71C), selects entries whose float key lands in [a4, a5], seeks the resource to the entry payload offset via sub_566DB0, and dispatches the byte delta in 1024-byte chunks through FileWriteWithBackendDispatch plus ConditionalDispatch_6bd0, accumulating the total. Falls back to FileSizeQueryWithFallback + ResourceLookupDispatcher when the walk ends. Returns the total bytes dispatched, or 0 when the list head or its first entry is empty.
- `0x004B87C0` **SessionDataObject** — First phase of session loading on the session data object: pops the session queue, early-returns 0 when the range width (this+0xF34 minus this+0xF30) is not positive, resolves a loading resource into this+0xF40, iterates the vehicle array (dword_7C54F0, count dword_5C329C) initializing per-vehicle effect tables and state/visibility bytes (this+0x734 / this+0x93C), transitions the session state to 3, sets clamp mode this+0xF81, marks the loading-phase flag this+0xF80, and runs state-trigger checks in a loop bounded by a 0.75 accumulator; returns 1 on success.
- `0x004B8940` **SessionDataObject** — Second phase of session loading on the session data object: sets this+0xF80 to 1, runs SafeDivisionWithZeroGuard over flt_5EA4E8 with a 0.75*1.5 threshold and a StateTriggerCheck loop accumulating dbl_8AFE90, applies AngleClampWrap with dbl_8AFEA0, sets clamp mode this+0xF81 to 0 (wrap), and when the vehicle count is positive iterates dword_7C54F0 driving SessionStateTransition over this+0x734, UIElementIterateUpdate, visibility propagation (this+0x93C), MultiObjectRemove and SetDriverVisibility. Then cleans the session structure (dword_5EA560), calls GuardedVirtualCall, releases the resource handle this+0xF40 via sub_566DB0, sets it to -1, and returns 1.
- `0x004B8DA0` **SessionDataObject** — Driver/vehicle entry loader on the session data object: iterates the vehicle entry array from unk_5EC6D8 (stride 4656) to the byte_7C54D8 end sentinel, walks each entry's linked list (head this+0x40, cursor this+0x48) matching the float key this+0xF38, copies name/path strings from the matched node, and when the path is new loads the vehicle-generation scene, transitions session state and adjusts dword_5C329C; empty previously-active entries are deactivated; finally updates the driver name via SetDriverName. Returns the one-past-end entry pointer.
- `0x004B9890` **SessionDataObject** — Session loading orchestrator: when the disable flag byte_7CE254 is clear, forces the session-type global dword_7C569C to 1, decodes the phase, runs LoadingPhase1, clamps the time offset to [10.0, 180.0], polls the key-priority chain while advancing the game state machine, sets the player vehicle index, runs LoadingPhase2, restores the session type, and returns a dispatcher result via ArithmeticComparison_8d60 or ShortComputation_8d70; stores the incoming time into the object at +0xF84 and the delegation result into +0xF88.
- `0x004BA460` **ReplayRecordingController** — Replay recording controller: when the session state allows it and (dword_7D0038 || dword_7D005C) with session type dword_7C56A4 == 7, creates the replay directory, reads the track name, builds the replay file path, starts the recorder sub-struct (this+0x08) via ThunkToFUN004b7300 (GameDataFileIO), and drives/polls it with SingleFunctionDispatch_9800 / SingleFunctionCallWrapper_9860; state 2 sets a flag byte on the recorder sub-struct. Otherwise shows a 'recording not available' message via TextLineWrappingAndRendering. Invoked by Game_Restart (0x0042D7A0).
- `0x004BA6C0` **SessionWeatherDispatcher** — Type-sentinel two-path dispatcher: reads the sentinel at this[0]; value 1 runs the session update path (a ring-buffer/session wrapper via CallWrapper_9870 on this+0x08, a session-state check, and an optional scoring/state update via sub_4B9890); value 2 runs the weather path (a packed-flag read via PackedFlagRead_9a00 gated by a second update call). Returns a char status from whichever path ran.
- `0x004BC4E0` **LapTimingObject** — Session lap/sector completion handler on the per-driver lap-timing object: early-returns when the session is finished (obj+0x32C8 == 3). On the full-lap path (a4 == 0) records the lap split into the per-lap array, updates best-lap/best-sector state and the pit-stop order rank, dispatches on dword_7C56A4 (retirement, penalty/stop-go, disqualification, finish, last-lap menus), runs a pending-penalty countdown, and writes the common tail (last time, lap-time array, phase flag). On the sector path updates per-sector bests and flags.
- `0x004BDC10` **SceneExtentObject** — Scene extent computation: walks the collision geometry node list (count from AudioNetworkNodeCount(dword_8AFE88)), folds per-node bounding boxes (BoundingBoxComputation) into min/max accumulators, and on the degenerate/empty path emits the 'could not get extent' debug log; otherwise stores this[585]/this[587] as scene minima and this[586]/this[588] as 8.0/(range) scales.
- `0x004C03C0` **LapSessionDataObject** — Constructor-style initializer: writes alternating 0 and -1 literals into six DWORD fields at +0, +4, +8, +0xC, +0x10 and +0x14, delegates the backing array setup to LapSessionDataArrayInitializer (0x004C07F0), and returns the this pointer.
- `0x004C0690` **SettingsIniWriterObject** — Career standings ini writer (__thiscall): writes a settings/standings block into the caller-owned buffer a2 as key-value pairs. Optionally resolves resource paths via ResourceLookupWithDualPath when a3 is nonzero. Writes Name/VehFile/RcdFile keys, then a per-entry loop over up to 48 finish entries at this+0x18 (negative-sentinel-terminated) emitting FinishPosition/FinishPoints pairs, followed by SeasonPoints/PointsPosition/PolesTaken/OriginalGridPos/CurrentGridPos/ControlType/Active keys and a trailing word_5C30B4 separator token. Called by PlayerOpponentStateWriter (0x004C0CC0).

## Proposed classes

### SessionDataObject

Session/game-data runtime object. Owns the loaded data file handle and load-state flag, three linked node lists (first/pool, second at 0x6C0, third at 0x714), the path/filename buffers, per-vehicle session-state and visibility arrays, the loading-phase and angle-clamp-mode bytes, the loading resource handle, and the session-time/delta fields. Its methods deserialize data files, load/reset them, walk replay entries, and drive the two-phase session loading sequence.

Methods: `0x004B6C90`, `0x004B7300`, `0x004B7C80`, `0x004B87C0`, `0x004B8940`, `0x004B8DA0`, `0x004B9890`

- `this+0x00000018` `struct_list_block list_a_management_block` (read_write, GUESS)
- `this+0x00000038` `struct_list_block free_pool_block` (read_write, GUESS)
- `this+0x00000040` `dword first_list_count` (read_write, GUESS)
- `this+0x00000048` `pointer list_traversal_cursor` (read_write, GUESS)
- `this+0x000006C0` `pointer second_list_head` (read_write, GUESS)
- `this+0x000006C4` `pointer second_list_tail_ptr` (read_write, GUESS)
- `this+0x000006C8` `pointer second_list_tail` (read_write, GUESS)
- `this+0x000006CC` `dword second_list_count` (read_write, GUESS)
- `this+0x000006E4` `dword loaded_data_handle` (read_write, GUESS)
- `this+0x00000700` `dword load_state_flag` (read_write, GUESS)
- `this+0x00000704` `char_array filename_path_buffer` (read_write, GUESS)
- `this+0x00000714` `pointer third_list_head` (read_write, GUESS)
- `this+0x00000718` `pointer third_list_tail_ptr` (read_write, GUESS)
- `this+0x0000071C` `pointer third_list_tail_and_walk_cursor` (read_write, GUESS)
- `this+0x00000720` `dword third_list_count` (read, GUESS)
- `this+0x00000734` `dword_array session_state_array` (read_write, GUESS)
- `this+0x0000093C` `byte_array driver_visibility_array` (read_write, GUESS)
- `this+0x00000D28` `dword state_dword` (read_write, GUESS)
- `this+0x00000F1C` `byte vehicle_data_ref_byte` (read_write, GUESS)
- `this+0x00000F20` `byte session_type_mirror_byte` (read_write, GUESS)
- `this+0x00000F24` `dword third_list_rebuild_count` (read_write, GUESS)
- `this+0x00000F28` `dword unnamed_dword` (read_write, UNKNOWN)
- `this+0x00000F2C` `float extent_additive_float` (read_write, GUESS)
- `this+0x00000F30` `float lower_bound_float` (read_write, GUESS)
- `this+0x00000F34` `float upper_bound_float` (read_write, GUESS)
- `this+0x00000F38` `float entry_float_key` (read, GUESS)
- `this+0x00000F40` `dword loading_resource_handle` (read_write, GUESS)
- `this+0x00000F78` `byte state_byte` (read_write, GUESS)
- `this+0x00000F80` `byte loading_phase_flag` (read_write, GUESS)
- `this+0x00000F81` `byte angle_clamp_mode` (read_write, GUESS)
- `obj+0x00000F84` `dword incoming_time_value` (read_write, GUESS)
- `obj+0x00000F88` `dword delegation_result` (read_write, GUESS)

### RaceSessionObject

Race/session state object referenced cross-object by lap timing and data loading: exposes the session-finished phase flag and the vehicle data reference dword. No required function owns it in this packet; ownership stays UNKNOWN.

Methods: 

- `obj+0x000032C8` `dword session_phase_flag` (read, GUESS)
- `obj+0x0000344C` `dword unresolved_field` (read, UNKNOWN)
- `obj+0x00004894` `dword vehicle_data_ref` (read, GUESS)

### SceneNodeWriter

Writes a model/scene node record: resolves a resource handle via ResourceLookupDispatcher into this+0x04 and emits the object through the file-write backend in two lengths (4 then 2 dword-bytes); always returns 1. Structurally a twin of FileHandleCloseRegistration (0x004B4470) per cluster copy (DERIVED).

Methods: `0x004B44A0`

- `this+0x00000004` `dword resolved_resource_identity` (read_write, GUESS)

### ReplayRecordingController

Controls replay recording: guards the session state and session type, creates the replay directory, builds the replay file path, starts a recorder SessionDataObject at this+0x08 via ThunkToFUN004b7300 (GameDataFileIO), drives and polls it, and otherwise renders a 'recording not available' message.

Methods: `0x004BA460`

- `this+0x00000000` `dword recording_state` (read_write, GUESS)
- `this+0x00000008` `pointer recorder_substruct_ptr` (read, GUESS)

### SessionWeatherDispatcher

Type-sentinel two-path dispatcher: sentinel 1 routes to the session update path (operating on a SessionDataObject at this+0x08), sentinel 2 routes to the weather path; returns a char status from whichever path ran.

Methods: `0x004BA6C0`

- `this+0x00000000` `dword type_sentinel` (read, GUESS)

### LapTimingObject

Per-driver lap/sector timing state: records lap splits, best lap/best sector state, pit-stop order ranks, pending penalties, and finish/retirement flags; the LapCompletion method dispatches on session type to retire, penalize, disqualify, or finish a driver.

Methods: `0x004BC4E0`

- `this+0x00000000` `pointer race_object_ptr` (read, GUESS)
- `this+0x00000004` `pointer pit_stop_order_ptr` (read, GUESS)
- `this+0x00000008` `dword lap_counter` (read_write, GUESS)
- `this+0x0000000C` `dword sector_indicator` (read_write, GUESS)
- `this+0x00000018` `float running_split_time` (read_write, GUESS)
- `this+0x0000001C` `pointer sector_pointer_a` (read_write, GUESS)
- `this+0x00000020` `pointer sector_pointer_b` (read_write, GUESS)
- `this+0x00000030` `dword finished_flag` (read_write, GUESS)
- `this+0x0000003C` `dword pending_penalty_count` (read, GUESS)
- `this+0x00000040` `dword_array penalty_timer_slots` (read, GUESS)
- `this+0x00000060` `dword phase_flag` (read_write, GUESS)
- `this+0x00000064` `float last_lap_time` (read_write, GUESS)
- `this+0x00000068` `float best_lap_time` (read_write, GUESS)
- `this+0x00000074` `float best_sector_time` (read_write, GUESS)
- `this+0x00000078` `pointer best_sector_pointer_a` (read_write, GUESS)
- `this+0x0000007C` `pointer best_sector_pointer_b` (read_write, GUESS)
- `this+0x00000080` `float best_lap_snapshot` (read_write, GUESS)
- `this+0x00000084` `float gap_time` (read_write, GUESS)
- `this+0x00000088` `dword total_lap_count` (read, GUESS)
- `this+0x0000008C` `float_array lap_time_array` (read_write, GUESS)
- `this+0x00000090` `float_array per_lap_split_array` (read_write, GUESS)
- `this+0x00000094` `dword_array pit_stop_order_rank_array` (read_write, GUESS)

### SceneExtentObject

Computes normalized scene extents from the collision geometry bounding boxes: stores two axis minima and two 8.0/(max-min) scale values on itself (this[585]..this[588]); emits a debug log when no non-degenerate bounds are found.

Methods: `0x004BDC10`

- `this+0x00000924` `float scene_min_axis_a` (write, GUESS)
- `this+0x00000928` `float scene_scale_axis_a` (write, GUESS)
- `this+0x0000092C` `float scene_min_axis_c` (write, GUESS)
- `this+0x00000930` `float scene_scale_axis_c` (write, GUESS)

### LapSessionDataObject

Constructor-style lap session data initializer: writes an alternating 0/-1 pattern into six leading DWORD fields and delegates the backing array setup to LapSessionDataArrayInitializer (0x004C07F0); returns the this pointer.

Methods: `0x004C03C0`

- `this+0x00000000` `dword state_pair_0` (write, GUESS)
- `this+0x00000004` `dword state_pair_1` (write, GUESS)
- `this+0x00000008` `dword state_pair_2` (write, GUESS)
- `this+0x0000000C` `dword state_pair_3` (write, GUESS)
- `this+0x00000010` `dword state_pair_4` (write, GUESS)
- `this+0x00000014` `dword state_pair_5` (write, GUESS)

### SettingsIniWriterObject

Career standings ini writer: emits a key-value settings/standings block (Name/VehFile/RcdFile, per-entry FinishPosition/FinishPoints, season keys, trailing separator) into a caller-owned buffer; optionally resolves resource paths.

Methods: `0x004C0690`

- `this+0x00000018` `dword_array finish_entries_array` (read, GUESS)

## Compatibility contracts

- **LoadedDataHandleGuard** — Data-loading entry points report readiness by returning *(this+0x6E4) != 0; a nonzero loaded-data handle at this+0x6E4 means a data file is loaded.
- **LoadStateFlagEnum** — this+0x700 encodes the data load state: 0 = settings file not found, 1 = settings file found, 2 = model/scene loaded.
- **SessionTypeDispatch** — Global dword_7C56A4 is the session-type selector: value 7 enables replay recording (with dword_7D0038/dword_7D005C), and in LapCompletion it selects retirement/penalty/finish/last-lap handling via the jump table at 0x004BC984.
- **VehicleArrayAccess** — The current vehicle is dword_7C54F0[dword_7C54E4] and the vehicle count is dword_5C329C. Vehicle field +0x4894 (18580 bytes) is mirrored into SessionDataObject+0xF1C on reset, per-vehicle state byte +0x105D (4189) is mirrored through the this+0x93C visibility array, and vehicle effect tables live at +0x32C8/+13000 (initialized via 0x004E1970, driven via 0x004E19A0).
- **BackslashDirectorySeparator** — Directory extraction scans the path globals dword_7CE5D0 / dword_7CE608 for the last byte 0x5C (92) and advances one byte past it; each falls back to byte_5EA438 when null.
- **SettingsIniKeySchema** — The career standings ini block writes keys Name/VehFile/RcdFile, per-entry FinishPosition/FinishPoints (up to 48 entries, negative sentinel at this+0x18), then SeasonPoints/PointsPosition/PolesTaken/OriginalGridPos/CurrentGridPos/ControlType/Active and a trailing separator token at word_5C30B4.
- **SessionFinishedPhase** — RaceSessionObject+0x32C8 value 3 marks the session finished and short-circuits LapCompletion; penalty countdown processing requires 0x32C8 <= 1.
- **ReplayFileNaming** — Replay path is assembled from the track name (TrackNameReader 0x004C5920, looked up in byte_5EC4C0/byte_5EC4CC), truncated at the asc_5D251C delimiter by sub_587C20, appended with the replay file name from the global at 0x005BE714, in a directory created via CreateDirectoryAWrapper.

## Unresolved

- The stream dword read into this+0xF28 (GameDataFileIO reset, ModelSceneFileLoader) has no packet field entry; its role is unknown.
- The float-key range [a4, a5] in NetworkBufferRead (replay time window vs data offsets) is not determinable from this packet alone.
- Field this+0x720 (third-list count) is flagged read-only but never referenced in the decompiled body of NetworkBufferRead.
- The two write lengths (4 then 2 dword-bytes) in SceneNodeWriter and the meaning of the resolved value at this+0x04 are unresolved.
- Semantics of the byte flags read into this+0xF1C / this+0xF20 from the stream, and the load-path mirroring of vehicle field +0x4894, are only inferred.
- The three 16-byte list blocks are indexed by a node type byte (this + 16 * (type + 4)); the exact type enum is unknown.
- The second-list nodes are wrapped with flag byte +0xC = 1 while third-list nodes are wrapped with it zeroed; the flag's meaning (e.g. deep-cleanup eligibility) is only inferred.
- The bounding-extent semantics of this+0xF30/0xF34 and the SceneExtent 8.0 normalization are inferred; the identity of the six bounding-box outputs (minX/maxX/minY/maxY/minZ/maxZ) is not determinable from SceneExtentComputation alone.
- The identity of the loaded resource handle at this+0xF40 (resolved by ResourceLookupDispatcher) is not derivable here.
- The vehicle-entry array base unk_5EC6D8 with stride 4656 (0x1230) used by ProcessDriverEntries, and the meaning of the float key this+0xF38, are not established; the packet lists unk_5EC6D0 as an accessed global but only unk_5EC6D8 is used as the array base.
- The meaning of the accumulated dbl_8AFE90 value and its 0.75 / 0.75*1.5 loop thresholds in the loading phases is not explained by the packet.
- The semantics of the GuardedVirtualCall argument 1065353216 (a 32-bit float bit pattern for 1.0f) in LoadingPhase2 are DERIVED, not proven.
- The 104-byte relationship between the this+0x93C visibility array and the driver state byte read is an x87/codegen artifact of the loading loops, not a named field.
- The dword_7D0410 window (values 5 and 6 suppress the replay status message) is not established.
- The penalty slots (from this+0x40) layout and the meaning of the per-vehicle penalty exempt flag at obj+13388 are not defined here.
- obj+0x32C8 value 3 as 'session finished' and value 1 as 'not finished' are inferred from guard structure; the full session-phase enum is not evidenced.
- The exact condition sources for guards this+0x30 == 1 and this+0x40 != 1 in LapCompletion overlap several code paths; they are mapped to the closest matching branch.
- The free-pool eligibility flag read at *(this+0x38)+0x8 is not visibly accessed in the raw source text; its exact use is inferred.
- Globals listed in packet facts but absent from the recovered decompiled bodies (their roles remain unknown here): flt_59E440, flt_59E4DC, flt_59E5FC, flt_59E808, flt_59E8A4, flt_5ACD1C, dword_8AD298, byte_8AC494, byte_8AC368, byte_5BE718, dword_5EB978, dword_8ACEE0, unk_5EC6D0, byte_5EA438 (in SettingsIniWriterObject).
- The 18580-byte offset read from the current vehicle object dword_7C54F0[dword_7C54E4] is copied to this+0xF1C, but the meaning of that vehicle field is not defined in this packet.
- sub_566940's exact contract (arguments 0, 0, 1 and its return semantics) is treated as a boolean file-presence test from the skeleton fill; it is not proven by this packet.
- The purpose of the StringCopyWithBufferRealloc(byte_5EA438) call on the settings-not-found path is unclear beyond storing the fallback string.
- The per-entry data at this+0x18 in SettingsIniWriterObject is an int array terminated by a negative sentinel and capped at 48 entries, but the per-field meaning of each int (position vs points) is not proven by the raw source.
- The identity of the object behind `this` in all packet functions and of the linked-list nodes freed with NodeDataFree then FreeWrapper_7bcf is not established; the packet owner is UnknownObject for every function.
