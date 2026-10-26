# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

Reconstruction of the generic runtime-object helpers in the packet address range 0x004A0D30-0x004B0540. The functions group into: (1) a SessionStateManager over a compact global block (byte_7CE254 state with guard-on-change reset of dword_7CE250, one-way set-only flag byte_7CE25D, and a five-global restart reset); (2) an OSManagerSingleton that builds a named CreateMutexA single-instance guard and logs entry; (3) a LinkedListIterator that walks a node chain and dispatches each node's first vtable entry with (node, arg) plus an optional dual-path resource lookup; (4) a RangeProportion initializer storing min/max and the precomputed inverse range with a zero-width guard; (5) a PitCrewMeshObject family (mode/parameter setter, string-to-loader forwarding with a trailing flag byte, animation-frame array append with header-counted growth, and a two-vector copy into 0x4C-0x60 that dispatches to the 3D layer) plus a PitCrewMemberOrientation helper that converts Euler angles and applies a 180-degree Y rotation; (6) a UIComponent set of base/ext struct init and cleanup stubs; (7) free StringUtils and PathUtilities helpers (quote stripping, path truncation, last-backslash extraction); (8) a ChampionshipThresholdNotifier that fires a state change when the player score plus one crosses a stride-2 threshold array; (9) a LargeAggregateObject bulk destructor with fixed-count descending free loops and a singly-linked node walk; (10) a SaveFileUtility appending a metadata block to the destination filename; (11) TrackEnvironmentSetup selecting the environment variant, clamping the camera index, loading the track scene, and running the physics/driving-mode/visibility/tire-compound chain, plus InitDamagePartState writing paired flag/type-ID part tables per mode; and (12) a PlayerFileLoader chain (directory check, then the audio-stream-gated init chain ending in the active-vehicle array and autoload entries). All class boundaries and field names are DERIVED or GUESS proposals on top of packet evidence; raw source and validated IR outrank worker synthesis.

## Function roles

- `0x004A0D30` **SessionStateManager** — Session-state setter: capture input byte a1, and only when it differs from the current global byte_7CE254 write it to byte_7CE254 and reset dword_7CE250 to 0; always return the requested state byte.
- `0x004A0DA0` **SessionStateManager** — One-way session flag setter: unconditionally write 1 to byte_7CE25D and return; no guards, arguments or clearing counterpart.
- `0x004A0FB0` **SessionStateManager** — Session-state restart reset: zero dword_7CE250, dword_7CE258, byte_7CE260, byte_7CE269 and dword_7CE26C, then return 0; part of the Game_Restart path.
- `0x004A18D0` **OSManagerSingleton** — Single-instance guard: conditionally log OS-manager entry after StringSplitLoop(2, build-version string, 420), create a named mutex (global hObject = CreateMutexA(0, 1, Name)), and return TRUE when the mutex already exists (GetLastError() == 183) or creation failed (null handle); FALSE only when this instance created and owns it.
- `0x004A1D50` **LinkedListIterator** — Linked-list dispatch with vtable calls: optionally run the dual-path resource lookup (0x00566CF0) when a3 is non-zero, reset the iterator to the head (this+0x8 = this+0x0), and walk the chain calling each node's first vtable entry with (node, a2); return the last visited node or null.
- `0x004A1FD0` **RangeProportion** — Range proportion initializer: store a2 as the range minimum (field 0x0) and a3 as the maximum (field 0x4), then precompute 1/(a3-a2) into field 0x8 when the width is positive, else 0.0; used to set up min/max/inverse-range triples before per-frame proportion lookups.
- `0x004A21D0` **PitCrewMeshObject** — Mesh-load forwarding stub: copy the input string into a 68-byte local buffer, append the constant flag byte 1 at index 64, then call PitCrewMeshLoader(this, a2, buffer, a4, a5) and return its result; no reversal operation appears in this body despite the legacy name.
- `0x004A22D0` **PitCrewMeshObject** — Pit-crew animation frame append: grow the 28-byte element array (4-byte count header plus this[28]+1 elements), construct new slots, copy the old elements from this+0x74, destroy and free the old array, then populate the new last element's scratch buffer per entry (string-handle conversion, wide-string list walk) and increment the element count only when every entry is populated; log a cube loading error on an early break.
- `0x004A2770` **PitCrewMeshObject** — Mode-dependent pit-crew mesh load: store a mode byte at this+0x2 and a DWORD parameter at this+0x48, load the mesh via PitCrewMeshLoader(this, a4, a5, a6, 0), then when the guard at this+0x64 is non-zero run FlagFieldBitManipulation with (1,1,0,0) when the mode byte is non-zero else (0,0,0,0) and return its result.
- `0x004A2800` **PitCrewMeshObject** — Two-vector copy: copy a2 into this+0x4C/0x50/0x54 and a3 into this+0x58/0x5C/0x60, then forward the updated data to the 3D subsystem via ConditionalDispatch_27d0(this) and return its result.
- `0x004A2980` **UIComponent** — Struct field reinitialization stub: zero this+0xC, this+0x10 and this+0x14, then call ArrayResourceCleanup (0x004A29A0) to release prior array resources before the object is reused; return this.
- `0x004A2A40` **StringUtils** — Quote-stripping copy: copy the source string into the output buffer skipping every double-quote character (0x22), null-terminate the compacted result, and return the outcome of sub_589901(lpSrcStr).
- `0x004A3320` **PitCrewMemberOrientation** — Pit-crew member orientation setup: guarded by this[5] (offset +0x14); when non-zero convert Euler angles a3 to a rotation matrix, build a 180-degree Y-axis rotation (pi), forward the three transform fields from a2 via ThreeFieldSetterWithSubCall, apply the Y rotation through sub_54B450, set the state flag this[2] (offset +0x8) to 2, and return the sub_54B450 result.
- `0x004A3B30` **UIComponent** — Extended struct initializer: zero the four consecutive DWORDs at this+0x78, this+0x7C, this+0x80 and this+0x84, then call sub_4A2220(this) unconditionally and return its result.
- `0x004A40E0` **UnknownObject** — Large buffer zero-init: memset(this, 0, 0x1A0u) clears the 416-byte buffer at this and returns 0; called from the startup init path.
- `0x004A48C0` **UIComponent** — Five-sub-struct initializer: run StructInitializer on five consecutive 0x40-byte sub-structures starting at this[6] and advancing by 16 dwords, zero this+0xC/0x10/0x14, then call UIComponentCleanup(this) and return this; part of physics tire system construction.
- `0x004A6D50` **ChampionshipThresholdNotifier** — Championship threshold notifier: in a championship session (dword_7C56A4 == 7), when the enable flag at obj+0x4040 is non-zero and at least one threshold entry exists (this+0x160 > 0), check whether the player score plus one (obj+0x403C) matches any even-indexed entry of the stride-2 array at this+0x164 and, on a match, call StateChangeNotify(this, 1); returns void.
- `0x004A8B80` **LargeAggregateObject** — Bulk destructor/cleanup for a large aggregate: clean a double-linked-list region, free arrays of 36-byte two-pointer structs in fixed-count descending loops, run a short-field cleanup helper over scattered offsets, free multi-pointer structs, walk the singly-linked list anchored at this+0 freeing each node and its payload, and zero the four head DWORDs.
- `0x004ADD50` **SaveFileUtility** — Save-file copy with metadata: build the source path from a directory global (dword_5EC440, falling back to byte_5EA438) plus a resource-name string, truncate the destination path to 238 characters, append a metadata block (four dwords plus one word at the end of the destination filename), copy with CopyFileA and return its BOOL result.
- `0x004ADE20` **TrackEnvironmentSetup** — Track environment select and physics setup: when a2 is set select the environment variant through sub_4AE750 using the byte_7CB710 / byte_7CBB0C flag bits, otherwise record the environment flag at this[1723]; clamp the camera index this[1732] into the [this[1734], this[1735]] range after stepping dword_5EC4A8 + 1 up to 4; load the track scene via TrackSceneLoader; then run the physics, driving-mode, car-part-visibility, sub_4AE9F0 and tire-compound setup chain, returning the TireCompoundClamp result.
- `0x004AE750` **TrackEnvironmentSetup** — Damage/part-state initializer driven by a clamped mode selector: clamp a2 between this+0x1AF4/this+0x1AF8, store it at this+0x1AEC, then write paired flag/part-type-ID fields at this+0x3670..0x3A2C according to the mode (cases 1/2/3 differ in enabled parts and type IDs) plus a tire-grip multiplier this+0x49C (0.6f) for mode 1, and apply a second block of 19 flag(0)+ID pairs whenever the selector is nonzero; returns 0.
- `0x004B0220` **PathUtilities** — Path truncation at the last directory separator: validate both arguments, copy the input into a 512-byte scratch buffer under a bounded copy, force-terminate at the caller limit, then clear bytes walking backward from the end of the string until a backslash (ASCII 92) is found; returns 0 on success, -1 on null arguments.
- `0x004B0390` **PathUtilities** — Last-backslash extractor: read the source string from this[109] (offset 0x1B4) falling back to global byte_5EA438 when null, scan backward to the last backslash, copy the trailing filename component into a2 via the bounded copy with limit a3-1, null-terminate, and return 1.
- `0x004B04E0` **PlayerFileLoader** — Directory-checked dispatch into player-file init: copy the input string into the internal buffer at this+20, select the target directory (dword_5EC440, falling back to byte_5EA438), verify it against the copied path with sub_566810 and rebuild the full path via sub_4B01B0 when the check fails, then call PlayerFileInit(a3) and return its result.
- `0x004B0540` **PlayerFileLoader** — Player-file load/init: mark this+0x114 read-only when the file attribute bit 0 is set, open an audio stream on the object path (this+20) and on success run the full chain: mode-variant init (sub_4AE750), linked-list walk, normalization of this+0x1F00, clamping of this+0x2F8C by the two condition flags, scene-data parse, gate-adjusted count stored to dword_5C329C (forced 0 in game mode 5), active-vehicle array build, 5-step init, autoload entry loading, and a path-scoped computation into dword_5EA5E8; return 0 on success and -1 when the stream cannot be opened.

## Proposed classes

### SessionStateManager

Owns a compact session-state global block: a guarded state byte that resets a companion counter on change, a one-way set-only flag, and a five-global restart reset.

Methods: `0x004A0D30`, `0x004A0DA0`, `0x004A0FB0`


### OSManagerSingleton

Single-instance guard that creates a named mutex with initial ownership and reports whether this instance is the sole owner or already-running/failed.

Methods: `0x004A18D0`


### LinkedListIterator

Walks a linked list of nodes from the head at this+0x0, keeps a cursor at this+0x8, and dispatches each node's first vtable entry with (node, arg); optionally runs a dual-path resource lookup first.

Methods: `0x004A1D50`

- `this+0x00000000` `void* list_head` (read_write, DERIVED)
- `this+0x00000008` `void* iterator_cursor` (read_write, DERIVED)

### RangeProportion

Stores a float min/max range pair and the precomputed inverse range used for linear proportion lookups, guarding against empty or inverted ranges.

Methods: `0x004A1FD0`

- `this+0x00000000` `float range_min` (write, DERIVED)
- `this+0x00000004` `float range_max` (write, DERIVED)
- `this+0x00000008` `float (1/(max-min), or 0.0 for non-positive width) inverse_range` (write, DERIVED)

### PitCrewMeshObject

Pit-crew mesh/animation object: carries a mode byte at +0x2, a parameter at +0x48, two copied vectors at +0x4C-0x60, an init guard at +0x64, per-frame entry count at +0x68, a 28-byte element array count at +0x70 and its pointer at +0x74; loads meshes, appends animation frames with header-counted growth, and forwards updated vectors to the 3D layer.

Methods: `0x004A21D0`, `0x004A22D0`, `0x004A2770`, `0x004A2800`

- `this+0x00000002` `byte (mode/type selector) mode_byte` (write, DERIVED)
- `this+0x00000048` `int parameter_dword` (write, DERIVED)
- `this+0x0000004C` `float vector_a_x` (write, DERIVED)
- `this+0x00000050` `float vector_a_y` (write, DERIVED)
- `this+0x00000054` `float vector_a_z` (write, DERIVED)
- `this+0x00000058` `float vector_b_x` (write, DERIVED)
- `this+0x0000005C` `float vector_b_y` (write, DERIVED)
- `this+0x00000060` `float vector_b_z` (write, DERIVED)
- `this+0x00000064` `int (non-zero means the object is initialized) init_guard` (read, DERIVED)
- `this+0x00000068` `int (dword per scratch entry) entries_per_frame` (read, DERIVED)
- `this+0x00000070` `int (number of 28-byte animation elements) element_count` (read_write, DERIVED)
- `this+0x00000074` `void* (header-counted array of 28-byte elements) element_array` (read_write, DERIVED)

### PitCrewMemberOrientation

Per-member orientation setup: gated by an activation field at +0x14, converts Euler angles to a rotation matrix, applies a 180-degree Y rotation, forwards a transform, and records a state flag at +0x8.

Methods: `0x004A3320`

- `this+0x00000008` `int (set to 2 after orientation setup) state_flag` (write, DERIVED)
- `this+0x00000014` `int (non-zero enables orientation setup) activation_field` (read, DERIVED)

### UIComponent

Generic UI/pit component struct lifecycle: base fields at +0xC/0x10/0x14 and extended fields at +0x78..0x84 are zeroed during init/cleanup, with array-resource cleanup and a five-sub-struct initializer for the physics tire system.

Methods: `0x004A2980`, `0x004A3B30`, `0x004A48C0`

- `this+0x0000000C` `int (zeroed on init/cleanup) base_field_0` (write, DERIVED)
- `this+0x00000010` `int (zeroed on init/cleanup) base_field_1` (write, DERIVED)
- `this+0x00000014` `int (zeroed on init/cleanup) base_field_2` (write, DERIVED)
- `this+0x00000078` `int (zeroed extended component state) ext_field_0` (write, DERIVED)
- `this+0x0000007C` `int (zeroed extended component state) ext_field_1` (write, DERIVED)
- `this+0x00000080` `int (zeroed extended component state) ext_field_2` (write, DERIVED)
- `this+0x00000084` `int (zeroed extended component state) ext_field_3` (write, DERIVED)

### StringUtils

Free string-processing helper: quote-stripping copy that compacts a string by removing double-quote characters.

Methods: `0x004A2A40`


### ChampionshipThresholdNotifier

In a championship session, monitors whether the player score plus one crosses an entry of a stride-2 threshold array and fires a state-change notification on a match.

Methods: `0x004A6D50`

- `this+0x00000000` `void* (player/championship data object) player_data_ptr` (read, DERIVED)
- `this+0x00000160` `int (number of stride-2 threshold entries) threshold_count` (read, DERIVED)
- `this+0x00000164` `int* (stride-2 threshold entries, even indices compared) threshold_array` (read, DERIVED)
- `obj+0x0000403C` `int (threshold target is score + 1) player_score` (read, DERIVED)
- `obj+0x00004040` `int (non-zero enables the threshold check) threshold_enable` (read, DERIVED)

### LargeAggregateObject

Large aggregate container with a bulk destructor: cleans a double-linked-list region, frees fixed-count arrays of two-pointer/multi-pointer structs in descending loops, runs a short-field cleanup over scattered offsets, and walks a singly-linked list anchored at this+0.

Methods: `0x004A8B80`

- `this+0x00000000` `int (singly-linked list head DWORD, zeroed after walk) list_anchor_dword_0` (read_write, DERIVED)
- `this+0x00000004` `int (list head DWORD, zeroed after walk) list_anchor_dword_1` (read_write, DERIVED)
- `this+0x00000008` `int (list head DWORD, zeroed after walk) list_anchor_dword_2` (read_write, DERIVED)
- `this+0x0000000C` `int (list head DWORD, zeroed after walk) list_anchor_dword_3` (read_write, DERIVED)
- `obj+0x00000000` `void* (node reached from the list anchor at this+0) list_node_anchor` (read, GUESS)
- `obj+0x00000008` `byte (in-use marker read during the walk) node_in_use_byte` (read, GUESS)

### SaveFileUtility

Copies a save/settings file and appends a four-dword-plus-one-word metadata block to the destination filename, truncating the destination path and building the source path from directory and resource-name globals.

Methods: `0x004ADD50`


### TrackEnvironmentSetup

Track environment selection and setup record: selects the environment variant or records a flag, clamps the camera index into a bound range, and drives the physics/driving-mode/visibility/tire-compound chain; also holds the clamped damage/part-state mode selector and the paired flag/type-ID part tables plus the tire-grip multiplier.

Methods: `0x004ADE20`, `0x004AE750`

- `this+0x00001AEC` `int (environment variant flag / clamped mode selector) environment_mode` (read_write, DERIVED)
- `this+0x00001AF4` `int (clamp lower bound for the mode selector) mode_bound_min` (read, DERIVED)
- `this+0x00001AF8` `int (clamp upper bound for the mode selector) mode_bound_max` (read, DERIVED)
- `this+0x00001B10` `int (stepped and clamped camera selector) camera_index` (read_write, DERIVED)
- `this+0x00001B18` `int (lower clamp bound) camera_index_min` (read, DERIVED)
- `this+0x00001B1C` `int (upper clamp bound) camera_index_max` (read, DERIVED)
- `this+0x0000049C` `float (set to 0.6f for mode 1) tire_grip_multiplier` (write, DERIVED)

### PathUtilities

Free path string helpers: truncate an in-place path buffer at its last backslash directory separator, and extract the trailing filename component after the last backslash.

Methods: `0x004B0220`, `0x004B0390`


### PlayerFileLoader

Loads and initializes a player file: carries the file path buffer at +0x14, a read-only marker at +0x114, the scene-data path at +0x138, a path string at +0x1B4, normalization and game-mode fields, and condition-flag clamp state; opens an audio stream and runs the full init chain on success.

Methods: `0x004B04E0`, `0x004B0540`

- `this+0x00000014` `char[] (internal path buffer, this+20) file_path_buffer` (read_write, DERIVED)
- `this+0x00000114` `int (set to 1 when the file attribute read-only bit is set) read_only_flag` (write, DERIVED)
- `this+0x00000138` `char* (path passed to the scene data parser) scene_data_path` (read, DERIVED)
- `this+0x000001B4` `char* (path consumed by the path-scoped computation and the last-backslash extractor) path_string` (read, DERIVED)
- `this+0x00001F00` `int (normalized to its truth value during load) normalized_flag` (read_write, DERIVED)
- `this+0x00001F78` `int (mode used to index the gate-adjusted table; value 5 forces the count to 0) game_mode` (read, DERIVED)
- `this+0x00002ED8` `byte (clamps this+0x2F8C to a floor of 33 when set) condition_flag_b` (read, DERIVED)
- `this+0x00002F08` `byte (clamps this+0x2F8C to a floor of 34 when set) condition_flag_a` (read, DERIVED)
- `this+0x00002F8C` `int (clamped to 33 or 34 by the condition flags) clamp_value` (read_write, DERIVED)

## Compatibility contracts

- **SessionStateGlobalBlockContract** — The session-state block must preserve: a state byte at 0x007CE254 that is only written when it differs from the requested byte and resets the counter at 0x007CE250 to 0 on change, a set-only flag at 0x007CE25D, and a restart reset that zeroes 0x007CE250, 0x007CE258, 0x007CE260, 0x007CE269 and 0x007CE26C. A replacement must reproduce the guard-on-change write and the five-global restart zeroing.
- **SingleInstanceMutexContract** — The OS manager must create a named mutex with initial ownership requested and report: TRUE when the mutex already exists (GetLastError() == 183) or the handle is null (creation failed), FALSE only when this instance created and owns it. A replacement must preserve the exclusive-ownership detection and the ERROR_ALREADY_EXISTS gate.
- **PitCrewAnimationArrayGrowthContract** — Appending an animation frame must grow the element array as a 4-byte count header plus N elements of 28 bytes, default-construct each new slot, copy the existing elements from this+0x74, destroy the old elements in reverse order and free the old array with its header, and increment the element count at this+0x70 only when every entry was populated. A partial population must not count as a new element.
- **PlayerFileLoadChainContract** — Loading a player file must open an audio stream on the path buffer at this+20 and return -1 when it cannot be opened, return 0 on success, mark this+0x114 read-only when the file attribute read-only bit is set, and on success run the init chain including the gate-adjusted count stored to dword_5C329C (forced to 0 in game mode 5), the active-vehicle pointer array build, and the autoload entry loading.
- **DamagePartModeSelectorContract** — The part-state initializer must clamp its mode selector into [this+0x1AF4, this+0x1AF8], store it at this+0x1AEC, and write the paired flag/part-type-ID fields at this+0x3670..0x3A2C according to the clamped mode, with the tire-grip multiplier at this+0x49C set to 0.6f for mode 1. A replacement must reproduce the clamp and the per-mode part table selection.
- **ChampionshipThresholdNotifyContract** — In a championship session (global 0x007C56A4 == 7), when the enable flag at obj+0x4040 is non-zero and at least one threshold entry exists, the loader must compare the player score plus one (obj+0x403C) against the even-indexed entries of the stride-2 array at this+0x164 and call StateChangeNotify(this, 1) on a match.

## Unresolved

- Owner classes for most functions are UnknownObject in the packet; the class grouping here (SessionStateManager, PitCrewMeshObject, UIComponent, TrackEnvironmentSetup, PlayerFileLoader, etc.) is a DERIVED/GUESS proposal, not recovered source.
- The semantics of the byte_7CE254 state and the dword_7CE250 counter it resets are not documented; callers suggest session/OSAPI context, and whether the state write is a full byte store or a masked flag update is not decidable from this packet.
- The byte_7CE25D flag has only a set-to-1 path here; its consumers are outside this packet.
- What StringSplitLoop(2, buildVersionString, 420) detects in the build string is unknown; only its boolean outcome is consumed. The mutex name string global Name resolves to is not visible.
- Global hObject (0x007CE2D8) is written by the OS manager but never read inside that function; later consumers are outside this packet.
- In 0x004A1D50, the vtable pointer is attributed to this+0xC by the field facts while the pseudocode reads the vtable from the first node; the exact node/container layout is not fully reconciled, and the resource lookup's effect on the traversal is unproven.
- For 0x004A1FD0 the packet lists globals flt_59E43C/flt_59E440 as read but the raw source references no globals; both are parked in unresolved_evidence_refs rather than asserted.
- The names StringCopyWithReverse / Copies_string_to_local_buffer_with_reversal imply string reversal but no reversal appears in the body; reversal is likely performed by callers 0x004A2A90, 0x004A3910 or 0x004D0110. The role of the constant flag byte at buffer index 64 is unknown.
- In 0x004A22D0 the global dword_8AFE64 is recorded as read but never appears in the raw body; dword_8AFE88 is a dead store into an unused local. The roles of a2/a3/a4/a5 and sub_5518A0/sub_551560/WideStringComparisonWalkingLinkedList semantics come only from existing analysis names.
- The guard at this+0x64 as a 3D sound-source handle is a fill claim (DERIVED); the raw source only reads the field as a non-zero guard. The FlagFieldBitManipulation argument tuples (1,1,0,0)/(0,0,0,0) meaning is undocumented.
- Semantics of the two copied vectors at 0x4C-0x60 are not established; existing analysis suggests a camera/position context from the callers, which is outside this packet's evidence.
- Whether sub_54B450 writes the resulting orientation into a member of this (beyond the local matrix) is not visible in the raw source of 0x004A3320; the owning class is unidentified.
- sub_4A2220 is invoked by 0x004A3B30 but is absent from the packet's callee list, so its semantics are grounded only in existing analysis (base struct init/cleanup), not packet callee evidence.
- 0x004A40E0's memset has no callee address evidence reference; the buffer's purpose and owning object are unknown (the Game_Init caller is outside the packet's allowed refs).
- The meaning of the obj fields at +0x403C/+0x4040 and of the threshold values in 0x004A6D50 is inferred from context; whether StateChangeNotify can fire multiple times when several thresholds match the same target is unresolved.
- The per-node payload free inside the bulk-destructor list walk uses a heap-free helper visible in the raw source but not catalogued in this packet.
- The meaning of the four-dword-plus-one-word metadata block appended to the destination filename by 0x004ADD50 is unknown; dword_5C5E60 plays a dual role as format argument and first metadata dword.
- The exact environment meaning of the sub_4AE750 arguments (1, 2, 3) and the byte_7CB710 / byte_7CBB0C flag-bit interpretation in 0x004ADE20 are not independently grounded; global 0x008AC368 is in the fact tables but absent from the raw body.
- The packet abi label HUD_Display_Frame_Range_Configuration (LEGACY) for 0x004AE750 conflicts with the existing-analysis reading of a vehicle damage/part-state initializer; not resolvable from this packet alone.
- sub_568620's body is absent from the packet so its role (stack setup / size guard) is unverified; exact caller expectations for a2 in 0x004B0220 (hard buffer capacity vs copy bound) are not verified.
- In 0x004B0390 the semantics of the length limit a3 and the copy primitive sub_587DD0 are not defined; content and role of the default-path global byte_5EA438 depend on its initializer elsewhere.
- Semantics of sub_566810 (directory prefix comparison) and sub_4B01B0 (path building) in 0x004B04E0 are inferred from callers, not confirmed.
- In 0x004B0540 the packet globals unk_5EC6D0 and unk_8AC368 appear in the fact tables but are absent from the raw decompiled source, parameter a2 is unreferenced, and the identity of the this struct is unknown; equal offsets on unrelated objects are not proof of a shared type.
- The five-sub-struct initializer 0x004A48C0 is placed in the physics tire system by its caller, but whether UIComponentCleanup there is a true destructor hook or a generic teardown helper is unknown.
