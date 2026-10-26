# RuntimeObjectRegistries

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

Proposal for wave_002_generic_runtime_objects_11 (21 functions). One DERIVED session-record class (SessionRecord: 103-entry 436-byte-stride array from this, trailing path strings at +0xAF6C/+0xAF74, config/status scalars at +0xB110..+0xB150; methods 0x004C0AB0/0x004C0DB0/0x004C1050/0x004C11D0/0x004C11E0/0x004C1370/0x004C1390/0x004C13A0). Two list containers using the shared 12-byte node layout (payload@0/next@4/owns@8): GameFilterList (head/tail/secondary/count at +0x0..+0xC; methods 0x004C2780/0x004C2850) and ResourceList (header at +0x8..+0x18; method 0x004C62C0); the node layout is captured as the field-only class ListNode12. One DERIVED VehicleDefinition class (methods 0x004C3200/0x004C38D0) with base directory, companion paths, eyepoint/camera/mirror vectors, metadata strings, livery list and texture-scan result fields; the TGA scanner (0x004C3A00) is kept as its own GUESS utility class. The scene registry (methods 0x004C52C0/0x004C55B0/0x004C5690/0x004C5940/0x004C5BB0) operates on the global scene array rather than an object. The vehicle-by-name lookup facade (0x004C0A20/0x004C40B0) is a GUESS class. Six material refs are unresolved (two TGA-suffix globals, three accessor globals, one never-read node field). No trust above DERIVED.

## Function roles

- `0x004C0A20` **VehicleRegistry** — Resolve the current vehicle by name and copy its scene name (vehicle+124) into the caller buffer with length cap a3-1; clear the buffer and null-terminate the copy; no-op when the buffer, the vehicle or the capacity is too small.
- `0x004C0AB0` **SessionRecord** — Session-record initializer: zero-init 103 sub-blocks at a 436-byte stride from this, one trailing block at this+44908 (0xAF6C), a defaults sub-structure at this+45344 (0xB120), then set trailing scalars +0xB144=0, +0xB148=-1, +0xB14C=1, +0xB150=0; returns this.
- `0x004C0DB0` **SessionRecord** — Game-filter/career session loader: capture the driver count, set session status fields, initialize the 103-entry array and the trailing block, resolve directory strings (default dir fallback), write vehicle-count/active fields, dispatch the game-filter configuration, build the AI opponent selection list, fill per-driver records (436-byte stride, index/flag fields at +0x1A4/+0x1A8/+0x1AC/+0x1B0), destroy the selection list; returns 0.
- `0x004C1050` **SessionRecord** — Race-session init once the session config is resolved: load the track scene, reset the AI world, zero +0xB118, reset 103 entries (436-byte stride) with the active flag at +0x1AC set to 1, transition the remaining empty slots via SessionStateTransition, clamp the game-state global from +0xB14C, copy the +0xAF6C/+0xAF74 path strings (registering the second into a global list); returns 0.
- `0x004C11D0` **SessionRecord** — Pure getter returning the dword at this+0xB148 (session race-index/flags field); no side effects; read by scoring, commentary, championship and session-state computations.
- `0x004C11E0` **SessionRecord** — Session config parser: guarded keyed-list fetch, null-guard the session index, find the season races section, load the track scene, copy the scene name/path strings into the string buffer at +0xB120/+0xB128, parse qualifylaps/qualifytime/racelaps/racetime into +0xB130..+0xB13C (each defaulting to -1 when absent), store the selected session index at +0xB140 bounded by +0xB148, return the string buffer pointer.
- `0x004C1370` **SessionRecord** — Count active entries: iterate exactly 103 slots at a 436-byte stride starting at this+0x1B0 and count slots whose leading byte is non-zero; return the count.
- `0x004C1390` **SessionRecord** — Accessor returning a pointer to this + 44908 (the +0xAF6C trailing region of the session record).
- `0x004C13A0` **SessionRecord** — Indexer returning a pointer to this + 436*index inside the 103-entry fixed array; rejects indexes above 102 (returns null); used by scoring, commentary, session-search and config-lookup helpers.
- `0x004C2780` **GameFilterList** — List insert: when DelegatedFieldGetter returns 2, first remove an existing node with cleanup; allocate a 45396-byte session block, initialize it and load game filter data into it; wrap the payload in a 12-byte node (payload@0, next@4, flag=1@8); on an empty list set head/tail/secondary all to the new node, otherwise append at the tail; increment the count at +0xC; returns 0.
- `0x004C2850` **GameFilterList** — Linked-list cursor read: snapshot the node at this+0x4 into this+0x8 and return its payload pointer (node data at node+0); returns 0 when the cursor node is null; 40 callers imply a generic list utility.
- `0x004C3200` **VehicleDefinition** — Vehicle .R definition parser: resolve the base directory (byte_5EA438 fallback), open the file, per line extract the section file tokens (hdvehicle/headphysics/sounds/graphics/genstring), parse eyepoint/camera-target/mirror-pos/mirror-normal/steering-wheel vectors, extract number/team/driver/description/engine/manufacturer/classes and team-metadata strings, build track-livery records (prepend 20-byte nodes to the +0x3D4 list head), load the companion .ini, auto-generate the description when empty, and resolve HDV/INI/GEN/SFX companion paths via FileFinder; returns 0 on success, -1 when the file cannot be opened.
- `0x004C38D0` **VehicleDefinition** — Texture-filename resolver: read the base path, extract the filename after the last backslash, copy to this+992, truncate at the last dot, append '.tga', enumerate matching files via TGATextureFileScanner, store the scanner result at this+0x420 and return it; walk and free the scanner's linked list.
- `0x004C3A00` **TextureFileScanner** — TGA texture scanner: build a filter from byte_5D3074, set up a directory scan over the input path, iterate directory entries, strip directory/extension, resolve base names, and collect matches into the caller's 4-dword result list (exact path match appends, others prepend, count at a2[3]); returns the scan-structure destructor result.
- `0x004C40B0` **VehicleRegistry** — Name-guarded vehicle dispatch: default result 0; when the name argument a1 is non-null, call VehicleLookupByName (return discarded) and return CurrentVehicleAccessor; on null input return 0. Callers span vehicle-config lookup/insertion, netcomm session dispatch, particle spawn, season scene lookup.
- `0x004C52C0` **SceneRegistry** — Scene (.SCN) file-array builder: reset the scene-state globals, form a path from the track/season directories, register it with the scan, free any prior scene array, allocate a 396-byte-per-entry array sized by the directory count (logging four diagnostics when empty), iterate entries building full paths and handing each opened file to TrackFilePathBuilder, tear down the directory list, sort the array by season races, return the scene count.
- `0x004C55B0` **SceneRegistry** — Find and select a scene by normalized name: copy and normalize the input, linearly scan the registry (dword_8AC488 entries, 396-byte stride at dword_8AC490, name at entry+260), strcmp against normalized names, and on a match set dword_8AC48C to the index; returns the scene count when absent.
- `0x004C5690` **SceneRegistry** — Find the scene registry index by base filename: strip directory and extension from the input path and from each registry entry (396-byte stride, path at entry+4), skip entries with empty stripped names, compare via sub_596C80, and on equality set dword_8AC48C and return 0; otherwise return the scene count.
- `0x004C5940` **SceneRegistry** — Reorder the global scene array into season-races order: fetch the 'seasonraces' linked list (null skips the whole function), build a temporary index array mapping each scene to its first matching race position, selection-sort the indices while swapping the corresponding 396-byte scene records, free the index array; null result when the list is absent.
- `0x004C5BB0` **SceneRegistry** — Scene file path formatter: seed a buffer from the default directory, copy and normalize the input path, truncate at the last dot, append a 5-byte suffix assembled from dword_5C5D24 and byte_5C5D28, compute the result via UtilityFunction_8a60; returns the computed result on success (return value 1) and -1 otherwise.
- `0x004C62C0` **ResourceList** — Resource-list teardown: copy the default directory path (result propagated out), walk the list from head this+0x8, for each node read the flag byte at node+8 and the next pointer at node+4, free owned payload data (and its secondary pointer at data+4 when present) then the node itself, and zero the management fields at +0x8..+0x18.

## Proposed classes

### SessionRecord

Large runtime record owned by the session/game-filter subsystem: a 103-entry fixed array at a 436-byte stride starting at this (per-entry index/flag fields at +0x1A4/+0x1A8/+0x1AC and the active byte at +0x1B0, addressed by the entry-indexer and the active-entity counter), trailing path strings at +0xAF6C/+0xAF74, and a scalar/config region at +0xB110..+0xB150 (vehicle counts, active flag, qualify/race laps and times, selected session index, status, race index, game-state value). The initializer (0x004C0AB0), loader (0x004C0DB0), session-init (0x004C1050), getter (0x004C11D0), config parser (0x004C11E0), counter (0x004C1370) and indexers (0x004C1390/0x004C13A0) all operate on the same base offsets, so common ownership is DERIVED; the object's true class name is unknown (legacy ABI lead and existing analysis disagree on the label: audio-subsystem vs career standings).

Methods: `0x004C0AB0`, `0x004C0DB0`, `0x004C1050`, `0x004C11D0`, `0x004C11E0`, `0x004C1370`, `0x004C1390`, `0x004C13A0`

- `this+0x00000000` `records[103] entry_array` (read_write, DERIVED)
- `this+0x000001A4` `int entry_index` (write, GUESS)
- `this+0x000001A8` `int entry_index_2` (write, GUESS)
- `this+0x000001AC` `int entry_active_flag` (write, GUESS)
- `this+0x000001B0` `byte entry_active_byte` (read_write, GUESS)
- `this+0x0000AF6C` `char[128] path_string_a` (read_write, DERIVED)
- `this+0x0000AF74` `char[128] path_string_b` (read_write, DERIVED)
- `this+0x0000B110` `int vehicle_count` (write, DERIVED)
- `this+0x0000B114` `int vehicle_count_2` (write, DERIVED)
- `this+0x0000B118` `int session_field_b118` (write, DERIVED)
- `this+0x0000B11C` `byte active_flag_byte` (write, DERIVED)
- `this+0x0000B130` `int qualify_laps` (write, DERIVED)
- `this+0x0000B134` `int qualify_time` (write, DERIVED)
- `this+0x0000B138` `int race_laps` (write, DERIVED)
- `this+0x0000B13C` `int race_time` (write, DERIVED)
- `this+0x0000B140` `int selected_session_index` (write, GUESS)
- `this+0x0000B144` `int session_status` (write, DERIVED)
- `this+0x0000B148` `int race_index` (read_write, DERIVED)
- `this+0x0000B14C` `int game_state_value` (read_write, DERIVED)
- `this+0x0000B150` `int session_flag_b150` (write, DERIVED)

### GameFilterList

Linked list of session-record payloads using the shared 12-byte node layout (payload@0, next@4, flag@8). Header at +0x0 (head), +0x4 (tail/cursor), +0x8 (secondary/iterator snapshot), +0xC (count). Insert (0x004C2780) optionally removes an existing node first when the delegated field reads 2, then allocates/initializes/loads a SessionRecord and appends a wrapped node; cursor read (0x004C2850) snapshots the node at +0x4 into +0x8 and returns its payload. The header semantics of +0x4/+0x8 across the two methods are compatible but not independently proven, so the class merge is GUESS.

Methods: `0x004C2780`, `0x004C2850`

- `this+0x00000000` `ListNode12* head` (read_write, GUESS)
- `this+0x00000004` `ListNode12* tail` (read_write, DERIVED)
- `this+0x00000008` `ListNode12* secondary` (read_write, GUESS)
- `this+0x0000000C` `int count` (write, DERIVED)

### ResourceList

Resource list whose management header lives at +0x8 (head), +0xC (tail), +0x10 (first/iterator), +0x14 (count), +0x18 (extra), with nodes following the shared 12-byte layout. Teardown (0x004C62C0) frees owned payload data (and a secondary pointer at data+4 when present) before freeing nodes, then zeroes the header. The header offsets differ from GameFilterList (head at +8 rather than +0), so this is a distinct list type even though the node layout is shared.

Methods: `0x004C62C0`

- `this+0x00000008` `ListNode12* head` (write, DERIVED)
- `this+0x0000000C` `ListNode12* tail` (write, DERIVED)
- `this+0x00000010` `ListNode12* first` (write, GUESS)
- `this+0x00000014` `int count` (write, DERIVED)
- `this+0x00000018` `int extra` (write, GUESS)

### ListNode12

Shared 12-byte singly-linked node layout used by the runtime lists: payload/data pointer at +0, next pointer at +4, ownership flag byte at +8. Only the next field has a packet-evidenced base (the node reached through the list header), so only that field is declared here; the payload and flag offsets are DERIVED from the raw source of the insert, cursor-read and teardown functions, not from a dedicated packet field reference.

Methods: 

- `*(this+0x8)+0x00000004` `ListNode12* next` (read, DERIVED)

### VehicleDefinition

Vehicle definition record loaded from a .R file: base directory at +0x0, companion paths (hdv@+0x8, ini@+0x10, sfx@+0x18, gen@+0x20), genstring at +0x28, eyepoint at +0x38/+0x3C/+0x40, camera target at +0x44/+0x48/+0x4C, mirror position at +0x50/+0x54/+0x58, mirror normal and steering-wheel vectors, number/team/driver strings, description at +0xFC, engine/manufacturer/classes and team-metadata strings, livery list head at +0x3D4, and the FileINILoader texture-scan result at +0x420. Common ownership of FileINILoader (which also reads +0x0 and writes +0x420) is DERIVED from the direct caller edge VehFileParser -> FileINILoader and the shared base-directory field; the full struct span 0x0..0x420+ is inferred, not proven.

Methods: `0x004C3200`, `0x004C38D0`

- `this+0x00000000` `char* base_dir` (read, DERIVED)
- `this+0x00000008` `char[64] hdv_path` (write, DERIVED)
- `this+0x00000010` `char[64] ini_path` (write, DERIVED)
- `this+0x00000018` `char[64] sfx_path` (write, DERIVED)
- `this+0x00000038` `float eyepoint_x` (write, DERIVED)
- `this+0x0000003C` `float eyepoint_y` (write, DERIVED)
- `this+0x00000040` `float eyepoint_z` (write, DERIVED)
- `this+0x00000044` `float camera_target_x` (write, DERIVED)
- `this+0x00000048` `float camera_target_y` (write, DERIVED)
- `this+0x0000004C` `float camera_target_z` (write, DERIVED)
- `this+0x00000050` `float mirror_pos_x` (write, DERIVED)
- `this+0x00000054` `float mirror_pos_y` (write, DERIVED)
- `this+0x00000058` `float mirror_pos_z` (write, DERIVED)
- `this+0x000000FC` `char[64] description` (write, DERIVED)
- `this+0x000003D4` `int livery_list_head` (read_write, DERIVED)
- `this+0x00000420` `int texture_scan_result` (write, GUESS)

### TextureFileScanner

Directory scanner that enumerates entries matching the byte_5D3074 TGA filter, strips directory/extension from each entry, resolves base names, and collects matches into a caller-supplied 4-dword result list (head/tail/secondary/count); exact path matches append, other matches prepend. No object fields are evidenced for the scanner itself; the 'this' base pointer is consumed only as the input path, so no fields are declared.

Methods: `0x004C3A00`


### SceneRegistry

Global scene-file registry module: builds the 396-byte-entry scene array from the track/season directories (dword_8AC490, count dword_8AC488, current index dword_8AC48C, current-scene pointer dword_8AC490 + 396*dword_8AC48C), finds scenes by normalized name or stripped base filename, reorders the array into season-races order, and formats scene file paths. All functions operate on globals rather than an object 'this', so this is a module-level grouping (GUESS), not a proven class with a this pointer.

Methods: `0x004C52C0`, `0x004C55B0`, `0x004C5690`, `0x004C5940`, `0x004C5BB0`


### VehicleRegistry

Facade over vehicle lookup and current-vehicle access: both methods resolve the current vehicle by name (VehicleLookupByName with its return discarded, then CurrentVehicleAccessor). SceneNameLookupBySeason additionally reads a vehicle-name string from this+0x8 and copies the resolved vehicle's scene name into a caller buffer. Grouping is GUESS: the two methods share the lookup-then-accessor pattern and the read/write of the same name source but their owners are UNKNOWN in the packet.

Methods: `0x004C0A20`, `0x004C40B0`

- `this+0x00000008` `char* vehicle_name_source` (read, GUESS)

## Compatibility contracts

- **SessionRecordLayout** — The session record owns a 103-entry fixed array at a 436-byte stride starting at the object base, with per-entry fields at +0x1A4/+0x1A8/+0x1AC and the active byte at +0x1B0 (addressed by the entry indexer 0x004C13A0 and the active-entity counter 0x004C1370), plus trailing path strings at +0xAF6C/+0xAF74 and scalar/config fields at +0xB110..+0xB150. A replacement executable that reuses these helpers must preserve these offsets; the record is allocated at 45396 bytes and initialized by 0x004C0AB0.
- **SceneRegistryLayout** — Global scene array at dword_8AC490 with 396-byte entries (name/path field at entry+260, path also readable at entry+4), count at dword_8AC488, current index at dword_8AC48C, and the current scene entry derived as dword_8AC490 + 396*dword_8AC48C. Find/select/sort functions (0x004C52C0/0x004C55B0/0x004C5690/0x004C5940) contract on this layout; selection returns 0 on match and the scene count on no match.
- **ListNodeLayout** — Runtime lists use 12-byte nodes: payload/data pointer at +0, next pointer at +4, ownership flag byte at +8. Teardown must free owned payload data (and a secondary pointer at data+4 when present) before freeing the node itself. List headers differ per list type (GameFilterList head at +0, ResourceList head at +8), so the header layout is not shared.
- **SessionConfigParse** — Session config parsing (0x004C11E0) reads the keyed configuration values qualifylaps/qualifytime/racelaps/racetime as integers into +0xB130..+0xB13C, defaulting each to -1 when the key is absent, stores the selected session index at +0xB140 bounded by the session count at +0xB148, and returns a pointer to the session string buffer at +0xB120. Callers depend on the -1 default and the string-buffer return pointer.
- **VehicleFileParseContract** — Vehicle .R parsing (0x004C3200) extracts the section file tokens hdvehicle/headphysics/sounds/graphics/genstring, parses eyepoint/camera/mirror/steering vectors, and resolves companion files with the extensions .hdv/.ini/.gen/.sfx via FileFinder; the function returns 0 on success and -1 when the file cannot be opened. A replacement must keep the section-key and extension contract to stay compatible with the shipped vehicle data.
- **VehicleCurrentSelection** — VehicleLookupByName (0x004C3F80) selects the current vehicle as a side effect even though both call sites discard its return value, and CurrentVehicleAccessor (0x004C4080) then returns the current vehicle. Consumers of the registry (season scene lookup, vehicle config lookup/insertion, netcomm dispatch) depend on this selection-then-access ordering.

## Unresolved

- Owner identity of the session record is disputed: the legacy ABI lead names 0x004C0AB0 an audio-subsystem initializer while existing analysis labels it a career-standings initializer; the 103-entry array plus the trailing scalars are shared by the initializer, the game-filter loader and the session init, but the object's real class name is unknown.
- SceneNameLookupBySeason discards the VehicleLookupByName return and obtains the vehicle from CurrentVehicleAccessor instead, so the lookup-result linkage is inferred only; the 'by season' naming is not evidenced by the function body.
- Purpose and contents of the unk_8AC388 buffer consumed by CurrentVehicleAccessor are unknown.
- The two stride-436 iteration paths (the 103-entry session array initialization and the per-driver record fill) overlap the same address range; whether they address the same objects is unresolved.
- The scene-name offset vehicle+124 read by SceneNameLookupBySeason has no packet field entry.
- SessionConfigReader copies strings to this+11336 and this+11338 (byte offsets 0xB120 and 0xB128) which have no packet field evidence; the closest packet fields (0xB130+) are the parsed value slots, not the string buffers.
- sub_587ECE is treated as an opaque integer parser and sub_589901 as an opaque string normalizer; their exact semantics are outside this packet.
- The scene entry stride (396 bytes), the name offset +260 and the +4 path offset are derived from loop arithmetic, not from packet field records.
- The 5-byte suffix assembled from dword_5C5D24 and byte_5C5D28 in SceneFilePathFormatter has no evidenced meaning (extension, version or separator).
- The node ownership flag at node+8 and the allocation source of node/data pointers are not established.
- FileINILoader's offsets (buffer at +992, result at +0x420) are merged onto VehicleDefinition through the direct caller edge and the shared base-directory field only; the full struct span 0x0..0x420+ is inferred.
- The field evidence for offset 4 of the node stored at this+0xC is recorded but never read inside ResourceListCleanup; only this+0xC itself is zeroed.
- The exact meaning of dword_8AD3B4 and the container it selects in the keyed-list calls (AudioChannelStop-style fetch) is not established; the same global is used by the session config parser and the scene sorter.
- The two list header layouts (GameFilterList head at +0, ResourceList head at +8) are both GUESS; the packet does not prove they describe the same list abstraction beyond the shared 12-byte node layout.
