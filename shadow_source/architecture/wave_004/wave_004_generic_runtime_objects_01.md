# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

Reconstructs the generic runtime object layer from 22 validated functions. One DERIVED class TrackWaypointDatabase (0x00402690) parses .AIW track databases into feature counts, grid/pit/garage position arrays and a 316-byte-stride waypoint array, with a nested GUESS waypoint-record type. One GUESS class BinaryDataReader (0x004054E0, 0x00405630) deserializes binary data entries through a 40-byte header and vtable-dispatched sub-object. Three GUESS camera classes cover camera-definition construction and mode dispatch (CameraViewSystem: 0x00408870, 0x00409440) and the shared render-dispatch pattern (ViewRenderDispatcher: 0x00408DE0, 0x00409890, 0x00409970). A GUESS ResourceManager routes resource-backed allocation (0x00405160) and a GUESS RaceSetupPathState holds the race-setup path string (0x00404850). Nine functions have UNKNOWN owners and are kept unowned. No defensible state-machine model is proposed; the camera mode switch is described as a dispatcher rather than a state machine because transitions are input/global driven and not fully evidenced.

## Function roles

- `0x00402690` **TrackWaypointDatabase** — Parses a track AI waypoint database file (.AIW) into the track database object. Reads FEATURES (pit lane, starting grid, pit/garage spot counts with minimum clamps), GRID (grid position triples), PITS (team-indexed pit/garage positions and orientations), and per-waypoint properties (branch id, path, event, score, width, groove, bitfields, pointer set). Allocates the waypoint array from the parsed count (316-byte stride plus 4-byte header), falls back to a default two-waypoint array when no count is parsed, remaps indexes, and post-processes each waypoint position delta.
- `0x00404850` **RaceSetupPathState** — Reads a path/directory string pointer from this+0x38, falling back to the default global directory string byte_5EA438 when the field is null. If the resolved string is non-empty, dispatches it through StringCopyFileCheckDispatch with an implicit copy flag; otherwise returns 0. Called by RaceModeSetup (00404890).
- `0x00404B50` **UnknownObject** — Zero-initializes three fields (bytes at offsets 0x14 and 0x15, dword at offset 0x1C) of an object obtained by dereferencing the this pointer, then returns that object pointer.
- `0x00404F70` **UnknownObject** — Conditional two-stage free: frees the inner buffer stored at this+0x0 when it is non-null, then frees the container node itself only when argument a2 has bit 0 set, and returns the container pointer. The caller set (render node list destructor, complex linked-list destructor, profile scanner, UI render pass) is consistent with a shared container teardown helper.
- `0x00405160` **ResourceManager** — Resource-backed allocation/reallocation router. Maps the mode parameter a3 (0, 1, or 2) to an internal flag v4, then looks up the resource node by ID through the resource manager singleton (with linked-list fallbacks) to obtain a base size and offset. Finally calls sub_58C724 with mode-dependent size arguments and normalizes its result: a non-1 return is decremented by the base size before being returned.
- `0x004053E0` **UnknownObject** — Initializes a structure in stages: zeroes the dword at byte offset 0x4, sets the dword at byte offset 0x8 to -1, zero-initializes the integer range starting at byte offset 0x30 (this + 12), initializes the sub-object at byte offset 0x34 (this + 13) via ObjectInit_4840, then calls CameraViewStructInitializer on the base pointer; returns this.
- `0x004054E0` **BinaryDataReader** — Deserializes one binary data entry selected by index a2 from a reader object: validates the file handle and index bounds, seeks to the entry offset, reads a 40-byte header, extracts a type field via bitfield, and dispatches per type (0 = raw offset record, 1 = threaded object creation through a vtable dispatch plus SEH guard, 2 = direct seek past the header). Returns 0 on a successful type 0/2 path and 1 on guards/failures.
- `0x00405630` **BinaryDataReader** — Resets a struct to its default state. Sets the sentinel at 0x1C to -1, zeroes the four dwords at 0x20/0x24/0x28/0x2C, runs VirtualCleanup on the sub-object at 0x30, dispatches the vtable method at slot +4 through the pointer at 0x34, zero-fills the trailing region from 0x44 for 0x2C bytes, clears the byte at 0x70, and returns 0.
- `0x00405880` **UnknownObject** — Scalar-deleting destructor for an unknown object. Invokes the object's destructor body (callee 0x004058A0) on this, then, when the deleting flag a2 has bit 0 set, releases the object's memory via FreeWrapper (0x00587BCF). Returns this unchanged, matching the MSVC scalar-deleting-destructor calling convention.
- `0x00406A70` **UnknownObject** — Conditional slot-resource release. Reads the dword at offset 0x5C of this; when it is not -1, passes it to sub_58C331 for release and resets offset 0x5C to -1. Returns the slot value read (or the release function's result). No-op when the slot is already -1.
- `0x00406B80` **UnknownObject** — Scalar-deleting destructor for an unknown object with complex teardown. Calls the object's destructor body (callee 0x00406BA0, which releases four linked lists) on this, then frees the object memory through FreeWrapper (0x00587BCF) when the deleting flag a2 has bit 0 set. Returns this.
- `0x004080B0` **UnknownObject** — Searches a singly linked list for a node whose data's first DWORD equals a2. Head pointer is stored at this+0x38, traversal cursor at this+0x40, and each node carries its data pointer at +0 and a next-node pointer at +4. Returns the matching data pointer, or 0 when the list is empty or no node matches.
- `0x004080F0` **UnknownObject** — Stream-to-buffer loader. Guards on a live stream handle at this+0xC and an unallocated buffer at this+0x18, seeks the stream, reads a 4-byte element count from this+0x14, allocates a count*4-byte buffer, zero-initializes it, then reads one 4-byte element at a time into the buffer. Returns 0 only when every element is read; on partial/failed reads it cancels the stream handle via pfnAPC, frees the buffer and returns non-zero.
- `0x004081E0` **UnknownObject** — Conditional destructor helper: reads a flag byte at offset 8; when set, runs multi-stage cleanup on the object pointer at offset 0 and then frees it through FreeWrapper_7bcf. Returns the original flag byte value. Called by ComplexDestructorWith4LinkedLists (00406ba0).
- `0x00408290` **UnknownObject** — Initializes struct state from two global DWORD constants plus a fixed flag: calls StructInitWithConditionalNotify first and captures its result, writes dword_5D6D60 cast to float into this+0xC, writes dword_5D6D64 (loaded via a double) cast to float into this+0x10, sets the byte at this+0x14 to 1, and returns the StructInitWithConditionalNotify result. Called by CamMan_Restart to re-initialize state; the globals are proposed as screen width/height only in the skeleton fill (DERIVED).
- `0x004082B0` **UnknownObject** — Per-frame float widget update: computes a scaled fill amount from the current value and a scale factor, dispatches a conditional event when the value is zero versus non-zero (toggling a byte flag), renders two 2D fill rectangles onto a UI surface, then exponentially clamps the current value toward a target bound using a global cooling rate. Runs on the frame path; the ABI lead names it Float_Clamp_with_Event_Dispatch.
- `0x00408490` **UnknownObject** — Scaling helper. Multiplies the first float field of this (offset 0x0) by the global float constant flt_5BE8F8 and returns the product. No guards or side effects.
- `0x00408870` **CameraViewSystem** — Camera view-definition initializer: releases any existing camera definition objects held at this+0x24, this+0x28, this+0x2C and this+0x30, then allocates and constructs four F_3DSoundEmitter objects (2-seater, 3-seater, left-of-pits, right-of-pits) with 200-byte blocks, copies the corresponding label strings (a2seater, a3seater, aLeftOfPits, aRightOfPits), and writes the camera view-parameter block (float FOV/clip/scale/offset presets, flag and reserved-zero fields, this-relative offsets 0x54..0xD8) into each. Each object setup ends with a ClampedFloatSetter call. Called once by CameraViewSystem (0x00408E20) during camera-system setup.
- `0x00408DE0` **ViewRenderDispatcher** — Conditionally invokes a subsystem operation on a2 and optionally a render draw with clipping. Guarded by the enable flag at this[2] (field this+0x8). When enabled, calls sub_541CA0(a2). If after that call a2 evaluates to zero and the sub-object pointer at this[3] (field this+0xC) is non-null, calls RenderDrawOperationWithClipping with the sub-object's dimension fields at +28 and +32 and the global unk_686B75 as the last argument. Otherwise returns the sub_541CA0 result. Part of the camera/view render dispatch path from ViewCameraModeDispatch.
- `0x00409440` **CameraViewSystem** — Camera/view-mode dispatcher driven by player input. Resolves a mode override (forcing mode 2 when a replay or camera-lock condition holds), then dispatches on the mode: cycling cockpit/TV/external views (0-2) via a signed step with wrap and vehicle-index clamping; absolute selection for modes 1 and 2; TV mode 3; sub-mode option cycling for mode 4; and special modes 7-8 that copy UI-state globals into sub-objects and invoke a vtable method. Every active path converges on a shared tail that plays an audio effect and calls the subsystem call before returning the float-keyed field selector.
- `0x00409890` **ViewRenderDispatcher** — Mirror-view render setup invoked from the main camera/director update. Guards on a global handle via ValueGetter, searches the linked list for the mirror bitmap, chooses rear-view vs main-view rendering based on a 0x40000 capability flag on the mirror object, caches the mirror object pointer in this+0xC, arms the physics parameter set and a follow-up dispatch, and finally issues a clipped draw using the mirror object's stored width/height and the unk_686B75 render payload. Always returns 0.
- `0x00409970` **ViewRenderDispatcher** — Conditional camera/render pipeline setup. When this[2] (offset 0x8) is non-null, converts two camera scale globals from degrees to radians (factor 0.01745433), applies them via sub_542050, sets the camera center via sub_541CA0(dword_7CF680), stores (sub_4099E0, 0) as a callback pair via PointerStorePair2, sets a float to 0.5 via ConditionalFloatSetter, and returns the result of Bit5FlagSetReset(dword_7CF6EC). On guard failure the decompiled return value is the uninitialized local result.

## Proposed classes

### TrackWaypointDatabase

Track AI waypoint database object: parsed FEATURES (pit lanes, starting grid, pit/garage spot counts with minimum clamps), GRID and PITS position/orientation arrays, a waypoint array (316-byte stride, count at 0x130, pointer at 0x134), left-handed-pit flag, and per-waypoint adjust fields. Populated by ParseTrackWaypointDatabase (0x00402690).

Methods: `0x00402690`

- `this+0x0000012C` `byte left_handed_pits` (read_write, DERIVED)
- `this+0x00000130` `dword waypoint_count` (read_write, DERIVED)
- `this+0x00000134` `void* waypoint_array` (read_write, DERIVED)
- `this+0x00000150` `position_array grid_positions` (write, GUESS)
- `this+0x00000154` `position_array pit_positions_orientations` (write, GUESS)
- `this+0x00000158` `position_array garage_positions_orientations` (write, GUESS)
- `this+0x00000160` `dword starting_grid_count` (read_write, DERIVED)
- `this+0x00000164` `dword pit_spot_count` (read_write, DERIVED)
- `this+0x00000168` `dword garage_spot_count` (read_write, DERIVED)
- `this+0x0000011C` `float worst_adjust` (read_write, DERIVED)
- `this+0x00000124` `float best_adjust` (read_write, DERIVED)

### TrackWaypoint

Per-waypoint record inside the TrackWaypointDatabase waypoint array (316-byte stride at base *(this+0x134)): flag, state, float parameter and trailing zero/negative sentinel fields default-initialized in the two-waypoint fallback path of 0x00402690.

Methods: 

- `*(this+0x134)+0x00000120` `dword flag` (write, GUESS)
- `*(this+0x134)+0x00000128` `dword state` (write, GUESS)
- `*(this+0x134)+0x000001D8` `float float_param` (write, GUESS)
- `*(this+0x134)+0x0000025C` `dword sentinel_0` (write, GUESS)
- `*(this+0x134)+0x00000260` `dword sentinel_1` (write, GUESS)
- `*(this+0x134)+0x00000264` `dword sentinel_2` (write, GUESS)

### BinaryDataReader

Reader/deserialization target object for binary data entries: live handle at 0x0C, entry count at 0x14, offset table at 0x18, per-entry deserialization state (0x1C..0x2C), sub-object with vtable at 0x34, and resolved object handle at 0x38. Deserializes one entry (0x004054E0) and resets to default (0x00405630).

Methods: `0x004054E0`, `0x00405630`

- `this+0x0000000C` `dword handle` (read, GUESS)
- `this+0x00000010` `dword object_handle_src` (read, GUESS)
- `this+0x00000014` `dword entry_count` (read, GUESS)
- `this+0x00000018` `dword* offset_table` (read, GUESS)
- `this+0x0000001C` `dword current_entry_index` (write, GUESS)
- `this+0x00000020` `dword deserialization_state` (write, GUESS)
- `this+0x00000024` `dword entry_data` (write, GUESS)
- `this+0x00000028` `dword entry_seek_pos` (write, GUESS)
- `this+0x0000002C` `dword type_field` (write, GUESS)
- `this+0x00000034` `void* sub_object` (read, GUESS)
- `*(this+0x34)+0x00000004` `void* vtable_method_slot` (read, GUESS)
- `this+0x00000038` `dword resolved_object_handle` (write, GUESS)

### CameraViewSystem

Camera/view system: builds four F_3DSoundEmitter camera-definition objects (2-seater, 3-seater, left-of-pits, right-of-pits) at 0x24..0x30 and writes view-parameter blocks (0x54..0xD8) in 0x00408870; drives per-frame camera mode/position selection from player input through the mode dispatcher 0x00409440.

Methods: `0x00408870`, `0x00409440`

- `this+0x00000024` `F_3DSoundEmitter* camera_def_2seater` (read_write, GUESS)
- `this+0x00000028` `F_3DSoundEmitter* camera_def_3seater` (read_write, GUESS)
- `this+0x0000002C` `F_3DSoundEmitter* camera_def_left_of_pits` (read_write, GUESS)
- `this+0x00000030` `F_3DSoundEmitter* camera_def_right_of_pits` (read_write, GUESS)
- `*(this+0x24)+0x00000000` `void* camera_def_vtable` (read, GUESS)
- `*(this+0x28)+0x00000000` `void* camera_def_vtable` (read, GUESS)
- `*(this+0x2C)+0x00000000` `void* camera_def_vtable` (read, GUESS)
- `*(this+0x30)+0x00000000` `void* camera_def_vtable` (read, GUESS)
- `this+0x00000034` `dword mode` (read_write, GUESS)
- `this+0x00000038` `dword option_count` (read, GUESS)
- `this+0x0000003C` `dword sub_mode_index` (read_write, GUESS)
- `this+0x00000050` `dword position` (read_write, GUESS)
- `*(this+0x2C)+0x000000BC` `dword ui_state_copy_0` (write, GUESS)
- `*(this+0x2C)+0x000000C0` `dword ui_state_copy_1` (write, GUESS)
- `*(this+0x2C)+0x000000C4` `dword ui_state_copy_2` (write, GUESS)
- `*(this+0x30)+0x000000BC` `dword ui_state_copy_0` (write, GUESS)
- `*(this+0x30)+0x000000C0` `dword ui_state_copy_1` (write, GUESS)
- `*(this+0x30)+0x000000C4` `dword ui_state_copy_2` (write, GUESS)
- `*(*(this+0x30)+0x0)+0x0000001C` `void* vtable_dispatch_slot` (read, GUESS)

### ViewRenderDispatcher

Camera/render dispatch helper object sharing the pattern: enable/data-presence field at 0x08 and a sub-object pointer at 0x0C whose dimension fields (0x28, 0x2C) feed clipped render draws. Holds the conditional subsystem call (0x00408DE0), mirror-view render setup (0x00409890), and the conditional render pipeline dispatch (0x00409970).

Methods: `0x00408DE0`, `0x00409890`, `0x00409970`

- `this+0x00000008` `dword enable_or_data_presence` (read_write, GUESS)
- `this+0x0000000C` `void* sub_object_or_view_param_block` (read, GUESS)
- `this+0x00000028` `dword dimension_width` (read, GUESS)
- `this+0x0000002C` `dword dimension_height` (read, GUESS)

### ResourceManager

Resource manager allocation router (0x00405160): ensures a one-time-initialized singleton, looks up a resource node by string or numeric ID (with linked-list and ID-operation fallbacks) to obtain a base size and offset, and routes mode-adjusted allocation/reallocation through the allocation core. Concrete resource-node fields at node+36 (offset) and node+40 (size) are inferred from usage.

Methods: `0x00405160`


### RaceSetupPathState

Race setup path-string holder: reads the configured path/directory pointer at 0x38 with a default-directory global fallback and dispatches it through the copy/check helper. One method 0x00404850, invoked by RaceModeSetup.

Methods: `0x00404850`

- `this+0x00000038` `char* path_string_ptr` (read, GUESS)

## Compatibility contracts

- **AIWTrackWaypointFormat** — The .AIW waypoint database is parsed line-by-line into tokenized sections (FEATURES, GRID, PITS, then named waypoint tokens). A replacement executable must reproduce the minimum clamps (grid >= 104, pit spots >= 52, garage spots >= 3), the 28-byte position/orientation triples, the 316-byte waypoint stride with 4-byte header, and the fallback two-waypoint default when no count is parsed.
- **ScalarDeletingDestructorFlag** — Conditional teardown helpers interpret the low bit of the deleting/flag argument: bit 0 set frees the container allocation through the shared free wrapper after the destructor body runs. Observed in 0x00404F70, 0x00405880, 0x00406B80, 0x004081E0.
- **BinaryDataEntryHeader** — Binary data entries carry a 40-byte header read through the thread-safe read wrapper; a bitfield-extracted type field drives dispatch (0 raw offset record, 1 threaded object creation, 2 seek past header). A replacement executable must honor entry seek offsets, the type dispatch, and the -1 invalid-type sentinel.
- **ResourceAllocationModes** — Resource-backed allocation accepts a mode parameter (0, 1, 2) that selects whether the node base size is added to the request or the node offset is consumed; the allocation core's non-1 result is normalized by subtracting the node base size.

## Unresolved

- TrackWaypointDatabase: exact per-waypoint field layout beyond the fallback-init sentinels (0x120 flag, 0x128 state, 0x1D8 float, 0x25C/0x260/0x264 sentinels) is not recoverable from ParseTrackWaypointDatabase alone.
- TrackWaypointDatabase: token-string globals such as the .AIW feature/token literals (5BE4xx/5BE5xx block) are consumed inside the token-parsing helpers; the individual global names are not evidence of field meaning in this scope.
- TrackWaypointDatabase: stride/header assumptions (316-byte slot, 4-byte header, 79 dwords per constructor pass) are inferred from allocation size and index arithmetic.
- TrackWaypointDatabase: mid-adjust parse target is not evidenced by an explicit field offset; only worst-adjust (0x11C) and best-adjust (0x124) carry offsets.
- BinaryDataReader: the 40-byte header locals v14/v15/v16 semantics depend on the on-disk entry layout and the bitfield decoder; field 0x40 is listed by the packet but unreferenced in the raw source.
- BinaryDataReader: the role of the aRb string global and the sub-object at 0x34 is caller/format dependent; the identity of the vtable method dispatched at slot +4 in 0x00405630 is unknown.
- CameraViewSystem: the view-parameter writes of 0x00408870 are physically made through four object pointers (0x24/0x28/0x2C/0x30) but recorded as this-relative offsets 0x54..0xD8; per-object assignment of each offset is ambiguous.
- CameraViewSystem: per-offset semantic meaning (FOV vs clip vs scale vs offset) is derived from prior analysis only and not locked by this packet.
- CameraViewSystem: camera-mode lock, dword_7CFCC8, and the vehicle-index comparison use offsets outside this scope; their exact meaning is external.
- ViewRenderDispatcher: offsets 0x28/0x2C are read through the sub-object pointer (v4 = this[3]) yet normalized to this; the two readings agree only if this[3] equals the struct base.
- ViewRenderDispatcher: the identity of the F_3DSoundEmitter/mirror object returned by the linked-list search and the layout of the unk_686B75 render payload are unknown.
- ViewRenderDispatcher: 0x00409970 returns an uninitialized local on its guard-fail path; the actual value depends on caller register state.
- ResourceManager: the meaning of the allocation-core return sentinel (1) and why the result is decremented by the node size are not grounded by raw source.
- ResourceManager: node fields at +36 and +40 are derived from allocation usage, not proven.
- Unknown owners: 0x00404B50, 0x00404F70, 0x004053E0, 0x00405880, 0x00406A70, 0x00406B80, 0x004080B0, 0x004080F0, 0x004081E0, 0x00408290, 0x004082B0, 0x00408490 lack the surrounding type in this packet and are left unowned.
- Read-only globals referenced by fills but absent from the raw bodies (5BE43C/5BE440/5BE450/5BE460/5BE464/5BE65C, 8AD298, 8B78A0, 8AFEC0, 7CE498) have unverifiable roles in this scope.
- 0x004080B0 node-count field at 0x44 is recorded but never read by the find function; only head (0x38) and cursor (0x40) are used.
- 0x004080F0 is invoked from LinkedListNodeInsert (0x00407520); the stream-owner relationship to a linked-list node is not resolved.
- 0x00406A70's -1 sentinel at 0x5C marks an inactive slot; the slot index the handle refers to is not recoverable from this packet.
- 0x00408290: the screen-width/height interpretation of the two global constants is a DERIVED fill claim, not packet evidence.
