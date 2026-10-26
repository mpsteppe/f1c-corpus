# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `GUESS`

The packet covers generic runtime objects with no confirmed C++ owners. Largest cluster is season/career scoring: a 104-record standings object (103 opponents at 436-byte stride from base, player record at offset 44908) with season-status/race-session/race-over trailer fields, read/written from ini-style buffers and post-race scored and ranked, plus a per-driver career record that restores driver/vehicle/grid/session data into 18624-stride season-scoring entries. A second cluster manages scene data: scene-node list registration, SceneOrder list lookup/comparison on scene-order nodes, and SeasonRaces section search over the 396-stride scene array. A third cluster is vehicle-list handling: rebuild of a filtered vehicle list from a driver string and name-based search of vehicle indices. A fourth cluster is generic pointer-list containers with object-resident metadata (head/count), removal with cleanup, and destructor-style multi-field freeing. Remaining functions are standalone initializers (zero/-1 sentinel fills), accessor wrappers and a track-name copy helper. Class boundaries are GUESS-level synthesis over UNKNOWN packet owners; field offsets are grounded in the raw source operations.

## Function roles

- `0x004C01A0` **VehicleSlotRecord** — Assigns ascending-score grid/starting positions to vehicles: builds a 104-slot slot->score map from the active vehicle pointers (dword_7C54F0), selection-sorts it, and writes each running position via ConditionalFieldSetter to the vehicle grid field.
- `0x004C0370` **AudioSubsystemState** — Constructor-style initializer writing a zero/-1 sentinel-heavy default state (0x0 and 0x8 to 0, remaining seven dwords to -1) on the audio-subsystem object; returns this.
- `0x004C03A0` **TrackSceneNode** — Straight-line initializer writing the 0/-1 alternating sentinel pattern into the first six dwords of a node (0x0/0x8/0x10/0x14 to 0, 0x4/0xC to -1); shared by track-scene node allocation and career-stats options loading.
- `0x004C0850` **CareerRecord** — Restores a loaded career record's runtime state into the season-scoring database entry indexed by the record's vehicle index: driver name, vehicle file name, grid position and a session-state transition, all guarded by the record's active flag.
- `0x004C0B70` **SeasonStandingsState** — Reads career/season state from an ini-style buffer into the standings object: per-opponent slots (436-byte stride), the player slot at +44908, season-status, race-session, race-over and current-race fields; early-terminates on scene-setup dispatch codes 1 and 4.
- `0x004C0CC0` **SeasonStandingsState** — Serializes career/season state back into an ini-style text buffer: season-status/race-session/race-over/current-race keys, the Player section and one indexed section per active opponent slot.
- `0x004C0F60` **SeasonStandingsState** — After a race, scores season points for the player and every active driver entry, then ranks active drivers by position value and stores the rank count; latches the race-over flag so the computation runs once.
- `0x004C1190` **SceneDataManager** — Stops the SceneOrder audio channel and returns the resulting SceneOrder list count, or 0 when no list was produced; cdecl helper for commentary and countdown paths.
- `0x004C13C0` **SeasonEntityCollection** — Walks the season entity collection (player plus active entries), sums a per-entity dword (element 102) for every entity whose 32-byte scene name matches the argument, and returns the total.
- `0x004C1450` **SeasonEntityCollection** — Counts season scene-path entries whose per-name computed value (from sub_4C13C0) exceeds the reference value for a target name, flagging already-visited same-name entries so each name is counted once.
- `0x004C1820` **RuntimePtrList** — Removes a node from a this-owned singly-linked list: relinks head/auxiliary/count metadata, conditionally frees the node payload (PitStopMemoryCleanup + free) and the node itself, returning 1 on success.
- `0x004C2700` **CareerStatsObject** — Reads the 'Career' section from a settings-file handle into a stack structure and writes the parsed career stats into this via CareerStatsWriter; returns 1 on a successful read+parse.
- `0x004C2760` **SeasonDataListNode** — Null-safe delegated field accessor: dereferences the list node held by this and returns the dword at offset 0xB144 of the resolved season object, else 0.
- `0x004C2830` **SeasonDataListNode** — Dereferences the list node held by this and, when non-null, runs the standings ranking computation on the payload, returning the low byte of its result (0 for a null node).
- `0x004C28D0` **SceneNodeList** — Dedup-registers a named track scene node into the scene-node list: parses scene data, resolves the current scene-array entry, allocates/initializes a 24-byte node, copies two entry strings, wraps it in a 12-byte list node and appends it.
- `0x004C3130` **VehicleDataContainer** — Destructor-style cleanup releasing every pointer field: frees a node list (head at +0x3D4) with per-node payload/resource/node frees, then null-guards and frees seven direct pointer fields of the object.
- `0x004C4D50` **VehicleSelectionList** — Clears and rebuilds the vehicle selection list from a driver/filter string: full-grid fallback (one node per grid slot) or tokenized default/AND/NOT groups applied via the vehicle-list filters; returns the NOT-group exclusion count.
- `0x004C4FF0` **VehicleSelectionList** — Searches the vehicle-index list (cursor at +0x10 from head at +0x8) for a node whose vehicle name matches, resolving each index through the 1060-stride vehicle array and recording the 0-based match position in +0x18.
- `0x004C5840` **SceneDataManager** — Returns the string-keyed linked-list result for the 'SeasonRaces' section, keyed by an explicit key or by the current scene-array entry name (base + 396*index + 260); gated by a name-lookup check.
- `0x004C5920` **TrackNameProvider** — stdcall wrapper copying the global track-name buffer (0x005C6984) into a caller destination via StringCopyWithValidation; returns the copy helper's result unchanged.
- `0x004C5CB0` **SceneOrderNode** — Finds a node's position in the SceneOrder list by matching the scene-array entry name: seeds the +0xC slot with the 0x7FFFFFFF sentinel, scans the list, and stores the matching node index.
- `0x004C5D30` **SceneOrderNode** — Comparison functor ordering filter/property nodes by SceneOrder slot value (+0xC), tie-broken by scene-name strings resolved through the scene array (stride 396, name at +260) with a node-name fallback.

## Proposed classes

### SeasonStandingsState

104-record (436-byte stride) season standings object: 103 opponent records, the player record at offset 44908, and a trailing block holding season-status, race-session and race-over fields. Reads/writes career season state from ini-style buffers and computes post-race rankings.

Methods: `0x004C0B70`, `0x004C0CC0`, `0x004C0F60`

- `this+0x0000B104` `dword player_position` (read, DERIVED)
- `this+0x0000B108` `dword player_rank` (write, DERIVED)
- `this+0x0000B11C` `byte player_active_flag` (read, GUESS)
- `this+0x0000B144` `dword season_status` (read_write, DERIVED)
- `this+0x0000B14C` `dword race_session` (read_write, DERIVED)
- `this+0x0000B150` `dword race_over_flag` (read_write, DERIVED)

### CareerRecord

436-byte per-driver career/season record: driver name at +0x0, vehicle file name at +0x8, vehicle index at +0x1A4, grid value at +0x1A8, session parameter at +0x1AC and active flag at +0x1B0. One instance per standings slot; the player record is the last slot (its +0x1B0 active flag is the object-level +0xB11C). Restores the runtime state into a season-scoring entry.

Methods: `0x004C0850`

- `this+0x00000000` `char* driver_name_ptr` (read, DERIVED)
- `this+0x00000008` `char* vehicle_file_name_ptr` (read, DERIVED)
- `this+0x000001A4` `dword vehicle_index` (read, DERIVED)
- `this+0x000001A8` `dword grid_value` (read, DERIVED)
- `this+0x000001AC` `dword session_param` (read, DERIVED)
- `this+0x000001B0` `byte active_flag` (read, DERIVED)

### SeasonScoringEntry

18624-byte-stride season-scoring database entry (array base dword_7D2E48) into which a career record is restored: grid position written through ConditionalFieldSetter at +0x4034, grid write-back at +0x4088, driver name at +0x4620 and vehicle file name at +0x4714 (byte_5EA438 as the null-string fallback).

Methods: 


### VehicleSlotRecord

Per-vehicle grid-assignment record read and written during starting-grid ordering: the sort score (+18192) and sort/slot-index (+18580) fields read from each active vehicle pointer, and the grid position field at +0x4034 written through ConditionalFieldSetter. The entry base used is unk_5F070C (VEH[0]+0x4034) with the same 18624-byte stride as SeasonScoringEntry, but the two arrays are not merged.

Methods: `0x004C01A0`


### SeasonEntityCollection

Collection of season entities (player plus active entries) that supports per-index entity resolution (ActiveEntityCounter / FixedOffsetReturn / ShortComputation_13a0) and 32-byte scene-name lookup; used to sum season points and count matching scene paths.

Methods: `0x004C13C0`, `0x004C1450`


### RuntimePtrList

Singly-linked list whose head and auxiliary/count metadata lives on the owning object (head at +0x0, count at +0xC); removal relinks around the node, decrements the count and conditionally frees payload and node.

Methods: `0x004C1820`

- `this+0x00000000` `RuntimeListNode* head` (read_write, DERIVED)
- `this+0x00000004` `RuntimeListNode* link1` (read_write, GUESS)
- `this+0x00000008` `RuntimeListNode* link2` (read_write, GUESS)
- `this+0x0000000C` `dword count` (read_write, DERIVED)

### RuntimeListNode

12-byte list node: data/payload pointer at +0x0, forward link at +0x4, ownership flag byte at +0x8; when the flag is set the payload is released on node removal.

Methods: 

- `*(obj+0x4)+0x00000000` `void* data` (read, DERIVED)
- `*(obj+0x4)+0x00000004` `RuntimeListNode* next` (read_write, DERIVED)
- `*(obj+0x4)+0x00000008` `byte owns_payload` (read, DERIVED)

### SeasonDataListNode

Linked-list node whose payload is a season-standings object; provides a null-safe delegated accessor (0xB144) and a conditional ranking trigger used during season-data cleanup.

Methods: `0x004C2760`, `0x004C2830`


### CareerStatsObject

Object that reads its own 'Career' stats section from a settings-file handle into a stack structure and commits the parsed values via CareerStatsWriter.

Methods: `0x004C2700`


### SceneNodeList

Head/tail/count scene-node list (metadata at +0x10/+0x14/+0x18/+0x1C) that registers named track scene nodes with dedup by name and appends wrapped 24-byte scene nodes.

Methods: `0x004C28D0`

- `this+0x00000010` `void* head` (read_write, DERIVED)
- `this+0x00000014` `void* tail` (read_write, DERIVED)
- `this+0x00000018` `void* secondary` (read_write, GUESS)
- `this+0x0000001C` `dword count` (read_write, DERIVED)

### TrackSceneNode

24-byte track scene node block holding two strings copied from the scene entry; its first six dwords receive the 0/-1 alternating sentinel pattern from AlternatingInit on allocation.

Methods: `0x004C03A0`

- `this+0x00000000` `dword slot0` (write, GUESS)
- `this+0x00000004` `dword slot1` (write, GUESS)
- `this+0x00000008` `dword slot2` (write, GUESS)
- `this+0x0000000C` `dword slot3` (write, GUESS)
- `this+0x00000010` `dword slot4` (write, GUESS)
- `this+0x00000014` `dword slot5` (write, GUESS)

### VehicleDataContainer

Vehicle data container whose destructor-style cleanup releases a node list (head at +0x3D4, nodes with payload at +8 and next at +0x10) plus seven direct pointer fields; invoked from vehicle file/data loading paths.

Methods: `0x004C3130`

- `this+0x00000000` `void* field0` (read_write, GUESS)
- `this+0x00000008` `void* field8` (read_write, GUESS)
- `this+0x00000010` `void* field10` (read_write, GUESS)
- `this+0x00000018` `void* field18` (read_write, GUESS)
- `this+0x00000020` `void* field20` (read_write, GUESS)
- `this+0x000003CC` `void* field3CC` (read_write, GUESS)
- `this+0x000003D4` `void* list_head` (read_write, DERIVED)
- `this+0x000003D8` `void* field3D8` (read_write, GUESS)

### VehicleSelectionList

Vehicle index/selection list container (head +0x8, tail +0xC, iterator +0x10, count +0x14, auxiliary/match-position +0x18) rebuilt from a driver/filter string and searched by vehicle name.

Methods: `0x004C4D50`, `0x004C4FF0`

- `this+0x00000008` `void* head` (read_write, DERIVED)
- `this+0x0000000C` `void* tail` (write, GUESS)
- `this+0x00000010` `void* iterator` (read_write, DERIVED)
- `this+0x00000014` `dword count` (read_write, DERIVED)
- `this+0x00000018` `dword aux_or_match_pos` (read_write, GUESS)

### SceneOrderNode

SceneOrder list node: scene index at +0x0, node name at +0x4, SceneOrder slot at +0xC; resolves its own position in the SceneOrder list and compares two nodes by slot value then scene name.

Methods: `0x004C5CB0`, `0x004C5D30`

- `this+0x00000000` `dword scene_index` (read, DERIVED)
- `this+0x00000004` `char* name` (read, GUESS)
- `this+0x0000000C` `dword scene_order_slot` (read_write, DERIVED)

### SceneDataManager

Scene-data management helpers operating on the global scene array (dword_8AC490, index dword_8AC48C, 396-byte stride) and the SceneOrder audio channel: scene-order list size reporting and SeasonRaces section lookup.

Methods: `0x004C1190`, `0x004C5840`


### TrackNameProvider

Provides the global track-name buffer to session/server and game-filter setup paths via a stdcall copy wrapper.

Methods: `0x004C5920`


### AudioSubsystemState

Audio-subsystem object whose constructor-style initializer writes a zero/-1 sentinel-heavy default state across nine dwords during audio subsystem setup.

Methods: `0x004C0370`

- `this+0x00000000` `dword field0` (write, DERIVED)
- `this+0x00000004` `dword field4` (write, DERIVED)
- `this+0x00000008` `dword field8` (write, DERIVED)
- `this+0x0000000C` `dword fieldC` (write, DERIVED)
- `this+0x00000010` `dword field10` (write, DERIVED)
- `this+0x00000014` `dword field14` (write, DERIVED)
- `this+0x00000018` `dword field18` (write, DERIVED)
- `this+0x0000001C` `dword field1C` (write, DERIVED)
- `this+0x00000020` `dword field20` (write, DERIVED)

## Compatibility contracts

- **SeasonStandingsRecordLayout** — A replacement must keep the standings object as 104 records of 436 bytes each: opponents at 436*index from the base, the player record at offset 44908, the active-flag byte at record+0x1B0, position at record+0x198, rank at record+0x19C, and the season-status (+0xB144), race-session (+0xB14C) and race-over (+0xB150) trailer fields at the object level.
- **GridPositionFieldAt0x4034** — Both starting-grid ordering and career restore write the grid/starting position through ConditionalFieldSetter into field +0x4034 of a 18624-stride entry (vehicle slots and season-scoring entries). Shared offset does not prove the two arrays are the same object.
- **SceneArrayLayout** — A replacement must keep the global scene array addressable as base dword_8AC490 plus 396 * dword_8AC48C with the scene name at entry+260 and a secondary string at entry+4, as used by track-scene registration, SeasonRaces lookup, SceneOrder slot matching and scene sorting.
- **SeasonScoringEntryLayout** — A replacement restoring career data must write, into the 18624-stride entry indexed from dword_7D2E48: grid position at +0x4034 (via ConditionalFieldSetter), grid write-back at +0x4088, driver name at +0x4620 and vehicle file name at +0x4714, using byte_5EA438 as the null-string fallback.
- **SceneOrderNodeLayout** — Scene-order nodes expose a scene index at +0x0, a node name at +0x4 and a SceneOrder slot at +0xC (seeded with 0x7FFFFFFF when unresolved); sorting and slot-finding depend on these three fields and the 396-stride scene array.

## Unresolved

- All packet owners are UNKNOWN; every class here is worker GUESS synthesis, not confirmed C++ ownership.
- The exact semantics of the vehicle fields used by SortDriverInitOrder (score at +18192, sort index at +18580) and the meaning of the value written to +0x4034 are inferred from call context only.
- dword_7D2E48 is unverified as base vs pointer; the season-scoring entry stride equals the vehicle-slot stride and both carry a grid field at +0x4034, but per rule 8 the two 18624-stride arrays are kept as separate classes (VehicleSlotRecord vs SeasonScoringEntry) until common ownership is proven.
- The standings record layout (436-byte stride, base slot, player record at 44908) and the sizes of the standings slots are derived from raw-source arithmetic, not an independent field table.
- AlternatingInit (0x004C03A0) is invoked both on track-scene nodes and by PlayerCareerStatsGameOptionsLoader for a career-stats object; those two object types share the 0/-1 sentinel pattern but are not proven to be the same class.
- CareerRecord field offsets overlap SeasonStandingsState absolute offsets (player active flag at +0xB11C equals the player record's +0x1B0 at base 44908); the two classes are kept separate because the packet does not prove the career record and the standings slot are identical.
- sub_588410 is treated throughout as a strcmp-like comparison where zero means equality and a negative result means first-sorts-before-second; that semantic is DERIVED from control-flow tests, not independently evidenced.
- LinkedListCount (in SceneOrderReader) and StringKeyedLinkedListSearch (in SeasonRacesSectionFinder) are referenced only in raw-source text and are not listed as callees in this packet.
- The early-termination dispatch codes (1 and 4) and the SessionStateTransition second argument (0) in CareerSeasonStateFileReader/CopyDriverDataToScoringDB have unresolved meaning.
- The meaning of dword element 102 of a season entity and whether sub_4C13C0's result is a points value used as a threshold in PathFileComparisonCounter are unresolved.
- Semantic roles of this[1]/this[2] in LinkedListNodeRemovalWithCleanup, of SceneNodeList secondary (+0x18), and of the ownership byte + PitStopMemoryCleanup payload contract are not independently confirmed.
- RuntimePtrList and the various list containers differ in head offsets (+0x0 vs +0x8 vs +0x10); they are modeled as distinct classes, not one generic list.
- VehicleSelectionList merges ParseDriverListString and SeasonSceneMatchByIndex on shared head/iterator offsets, but the packet does not prove both operate on the same object type; the +0x14 field read in SeasonSceneMatchByIndex is flagged unresolved.
- SceneOrderSlotFinder's return value varies by path (match, null, array base) and is not a single status code; the caller sub_4C5C80's purpose is not established.
- TrackSceneNode's 24-byte block fields beyond the alternating sentinel pattern (which slots hold the two copied strings) are not evidenced.
- Global byte_5EA438 content and the config-block globals dword_5D30C0..byte_5D30D8 in ParseDriverListString have unresolved meaning.
- Whether dword_8AD3B4 (GameDataDir) is consumed by AudioChannelStop in SceneOrderReader, SeasonRacesSectionFinder and SceneOrderSlotFinder is undetermined.
