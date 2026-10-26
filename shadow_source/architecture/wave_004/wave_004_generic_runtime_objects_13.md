# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `GUESS`

Proposes fourteen defensive classes for the generic runtime objects packet: a linked-list container family (eight list destructor/append/index methods sharing the four-dword head/tail/current/count bookkeeping), two node layouts (free-data flag at +0x8 and at +0xC) plus a UI-widget child-node destructor pair, a stored-pointer resolver, a menu action dispatcher, a bounded float array and a clamped grid region, an AI driver state object (state transition, penalty eligibility, performance target speed, random variation scaler), a season-data lookup group, a championship standings/scoring entry object, a scene-name resolver, an audio sample source, and a float-difference helper. Owner classes are proposals only; packet owners are UNKNOWN throughout.

## Function roles

- `0x004B9AC0` **AudioSampleSource** — Audio sample dispatch: fetches a fallback position float when the sentinel -9.9999997e37 is passed, traverses the audio-entry linked list at this+0x0 with a position filter, and selects one of three playback paths from entry state fields at +36.
- `0x004B9CF0` **FloatQueryHelper** — Returns the difference between a FloatGetter value on *this and a float at a 3900-byte offset whose base register was lost in decompilation; used by particle/weather and scoring-gate paths.
- `0x004B9DA0` **MenuActionDispatcher** — Menu UI action dispatch: stores action ids 0-8 into the menu data action slot at obj+0xF8C and delegates ids 9-13 to sorted-list/sprite/linked-list helpers; returns 1 on every path.
- `0x004BA780` **StoredPointerResolver** — Reads the pointer at this+0x0, persists a copy at this+0x8, and returns the pointed-to DWORD, or 0 when the stored pointer is null.
- `0x004BA8C0` **UIWidgetChildNode** — UI widget child-node destructor: frees the payload at this+0x0 when the flag at this+0x8 is set and the pointer is non-null, then frees the node buffer when a2 bit 0 is set.
- `0x004BA900` **UIWidgetChildNode** — UI widget child-node destructor variant: teardown keyed on the flag at this+0xC, frees the secondary pointer at payload+0x4 then the primary block at this+0x0, and frees the node when a2 bit 0 is set.
- `0x004BA9F0` **RuntimeLinkedListContainer** — Linked-list destructor: walks the head at this+0x0, frees flagged node data and every node, zeroes the four container fields, returns 0.
- `0x004BAEB0` **RuntimeLinkedListContainer** — Linked-list destructor with per-node callback stub: frees flagged embedded data and the nodes, zeroes the container fields, returns 0.
- `0x004BB400` **RuntimeLinkedListContainer** — Linked-list destructor (thiscall): frees node data when the node free-data flag at +0xC is set, frees every node, zeroes head/tail/current/count.
- `0x004BB490` **RuntimeLinkedListContainer** — Linked-list append: allocates a 12-byte node, links it into the container at this+0x0 (seeding +0x4/+0x8 on an empty list), increments the count at +0xC.
- `0x004BB4F0` **RuntimeLinkedListContainer** — List destructor for refcounted 884-byte-stride elements: per-element stub, frees the refcount block and data allocation, frees nodes, zeroes the container fields.
- `0x004BB650` **RuntimeLinkedListContainer** — List destructor with two-level data free: frees the inner allocation at data[0] then the outer data block for flagged nodes, frees nodes, zeroes the container fields.
- `0x004BC2A0` **BoundedFloatArray** — Bounds-checked float array lookup: rejects negative or over-capacity indices with a -1.0 return, otherwise returns the float at this+0x90 + 4*index.
- `0x004BC2F0` **AIDriverState** — Conditional AI state setter: notifies AIDriverStateTransition with the old/new pair via global dword_5EB978 and the driver state pointer at this+0x0, then writes this+0x2C.
- `0x004BC340` **AIDriverState** — Penalty-eligibility guard: requires server mode dword_7C569C==5, a permitting penalty state at this+0x30, and race phase dword_7C56A8 in {5,6,8}.
- `0x004BE010` **GridRegion** — Grid region scan: computes clamped [0,7] row/col ranges from origin/scale fields at this+0x924..0x930 and calls the per-cell dispatcher 0x004BD900 for every cell.
- `0x004BE760` **AIDriverState** — AI performance target speed: scans the live vehicle array for the nearest leader and next car, selects the season-config fallback via off_5D2634/off_5D2630 when needed, writes the target to this+0x34C.
- `0x004BEA10` **AIDriverState** — Random performance-variation scaler: two LCG draws via 0x005884ED scaled by a skill reference, with the session-type split at this+0x360==7 choosing +17604 over +17600.
- `0x004BF6A0` **SeasonDataLookup** — Season audio parameter lookup: string-keyed list at off_5D263C, scalar reader 0x0058850F, plus a noise term from the flt_8AAE74 ring buffer.
- `0x004BF730` **RuntimeLinkedListContainer** — Linked-list destructor with conditional release: frees the payload only when the node+8 flag is set, frees nodes, zeroes the container fields; structural twin of 0x00491DB0.
- `0x004BFD40` **RuntimeLinkedListContainer** — Indexed list accessor: guards the index against the count at this+0xC, walks the this+0x8 iterator a2 nodes, returns the first DWORD of the reached node's data.
- `0x004C0260` **SeasonDataLookup** — Qualifying grid index lookup: finds the 'Qualifying' key in the season races section and linearly scans up to 104 entries comparing driver names, returning the 1-based slot.
- `0x004C02D0` **SeasonDataLookup** — Qualifying best-lap lookup by driver name: scans the Qualifying list, reads the entry value via 0x0058850F, rejects values below 10.0, returns -1.0 on failure.
- `0x004C03F0` **SeasonChampionshipData** — Loads one career season standings entry from the token buffer: Name/VehFile/RcdFile strings, indexed FinishPosition/FinishPoints arrays at this+24 and this+216, summary fields this+408..428, active flag at this+0x1B0.
- `0x004C0910` **SeasonChampionshipData** — Season championship scoring: under GameState 5 reads the season position into this+0x1A8 and leader laps this+0x1A0; under 7 accumulates points into this+0x198 and writes per-slot results.
- `0x004C0A80` **SceneNameResolver** — Resolves the current vehicle scene name pointer: reads the vehicle name at this+0x8 (default byte_5EA438), VehicleLookupByName, then the scene name at +124 of the current vehicle, or 0.

## Proposed classes

### RuntimeLinkedListContainer

Singly/doubly linked-list container: walk-and-free destructors (with and without per-node data release), append insertion, and indexed access, all over the four-dword head/tail/current/count bookkeeping block at this+0x0/+0x4/+0x8/+0xC.

Methods: `0x004BA9F0`, `0x004BAEB0`, `0x004BB400`, `0x004BB490`, `0x004BB4F0`, `0x004BB650`, `0x004BF730`, `0x004BFD40`

- `this+0x00000000` `void * head_ptr` (read_write, DERIVED)
- `this+0x00000004` `void * tail_ptr` (read_write, GUESS)
- `this+0x00000008` `void * current_or_iterator_ptr` (read_write, GUESS)
- `this+0x0000000C` `int32_t count` (read_write, GUESS)
- `*(this+0x8)+0x00000000` `uint32_t current_node_data_dword` (read, GUESS)

### RuntimeLinkedListNode

List node with the free-data flag at +0x8: data pointer at +0x0, next link at +0x4, ownership flag at +0x8; also records the inner allocation and next-node-link reads used by the two-level and refcounted destructors.

Methods: 

- `obj+0x00000000` `void * data_ptr` (read_write, DERIVED)
- `obj+0x00000004` `void * next_ptr` (read_write, GUESS)
- `obj+0x00000008` `uint8_t free_data_flag` (read, GUESS)
- `*(obj+0x0)+0x00000000` `void * data_inner_ptr` (read, GUESS)
- `*(obj+0x4)+0x00000004` `void * next_node_link` (read, GUESS)

### RuntimeLinkedListNodeWithLateFlag

List-node layout variant with the free-data flag at +0xC rather than +0x8, used by the late-flag destructor and the UI widget node teardown.

Methods: 

- `obj+0x00000000` `void * data_ptr` (read_write, GUESS)
- `obj+0x00000004` `void * next_ptr` (read_write, GUESS)
- `obj+0x0000000C` `uint8_t free_data_flag` (read, GUESS)

### UIWidgetChildNode

UI widget child node teardown pair called from DestroyUIWidgetHierarchy: frees the embedded payload (and its secondary pointer) when the ownership flag is set, and the node buffer only when the a2 low bit is set.

Methods: `0x004BA8C0`, `0x004BA900`

- `this+0x00000000` `void * payload_ptr` (read_write, DERIVED)
- `this+0x00000008` `uint8_t owns_payload_flag` (read, GUESS)
- `this+0x0000000C` `uint8_t owns_payload_flag_late` (read, GUESS)

### StoredPointerResolver

Resolver that caches a stored pointer from this+0x0 into this+0x8 and dereferences the first DWORD of the pointed object, or 0 on null.

Methods: `0x004BA780`

- `this+0x00000000` `void * stored_ptr` (read_write, DERIVED)
- `this+0x00000008` `void * cached_copy_ptr` (write, GUESS)

### MenuActionDispatcher

Menu UI action dispatcher: stores action ids 0-8 into the menu data action slot at obj+0xF8C and delegates ids 9-13 to sorted-list/sprite/linked-list helper routines.

Methods: `0x004B9DA0`

- `obj+0x00000F8C` `int32_t action_id_slot` (write, GUESS)

### BoundedFloatArray

Bounds-checked float array: two capacity bounds at this+0x8 and this+0x88 and the element base at this+0x90; out-of-range index returns -1.0.

Methods: `0x004BC2A0`

- `this+0x00000008` `int32_t capacity_primary` (read, GUESS)
- `this+0x00000088` `int32_t capacity_secondary` (read, GUESS)
- `this+0x00000090` `float * elements_base` (read, GUESS)

### GridRegion

Clamped rectangular grid region: row/column origin and scale floats at this+0x924..0x930, cell indices clamped to [0,7], per-cell callback dispatched for every cell.

Methods: `0x004BE010`

- `this+0x00000924` `float row_origin` (read, GUESS)
- `this+0x00000928` `float row_scale` (read, GUESS)
- `this+0x0000092C` `float column_origin` (read, GUESS)
- `this+0x00000930` `float column_scale` (read, GUESS)

### AIDriverState

Per-driver AI state object: conditional state transition with notification, penalty-eligibility guard, AI performance target-speed computation, and random variation scaling, over the driver state pointer at this+0x0.

Methods: `0x004BC2F0`, `0x004BC340`, `0x004BE760`, `0x004BEA10`

- `this+0x00000000` `void * state_struct_ptr` (read, GUESS)
- `this+0x0000002C` `int32_t driver_state` (read_write, GUESS)
- `this+0x00000030` `int32_t penalty_state` (read, GUESS)
- `this+0x00000342` `uint8_t performance_activation_flag` (read_write, GUESS)
- `this+0x00000348` `float season_speed_reference` (write, GUESS)
- `this+0x0000034C` `float target_speed` (read_write, GUESS)
- `this+0x00000360` `int32_t session_type_selector` (read, GUESS)

### SeasonDataLookup

Free functions over the season data sections: audio parameter lookup, qualifying grid index lookup, and qualifying best-lap lookup, all resolving entries through string-keyed list search and the scalar reader.

Methods: `0x004BF6A0`, `0x004C0260`, `0x004C02D0`


### SeasonChampionshipData

Career championship season entry: token-buffer standings loading (indexed FinishPosition/FinishPoints arrays, summary fields, active flag) and per-race scoring (leader laps, finished position, season points total) against the season database.

Methods: `0x004C03F0`, `0x004C0910`

- `this+0x00000198` `int32_t season_points_total` (read_write, GUESS)
- `this+0x000001A0` `int32_t leader_lap_counter` (read_write, GUESS)
- `this+0x000001A4` `int32_t vehicle_index` (read, GUESS)
- `this+0x000001A8` `int32_t finished_position` (read_write, GUESS)
- `this+0x000001B0` `uint8_t active_flag` (read_write, GUESS)

### SceneNameResolver

Resolves the current vehicle's scene-name string: reads the vehicle name at this+0x8 (default byte_5EA438), looks the vehicle up by name, and returns the scene name pointer at +124 of the current vehicle.

Methods: `0x004C0A80`

- `this+0x00000008` `char * vehicle_name_ptr` (read, DERIVED)

### AudioSampleSource

Audio sample dispatch source: traverses the audio-entry linked list at this+0x0 by position filter and selects among passthrough/direct pitch-modulated playback paths from entry state fields.

Methods: `0x004B9AC0`

- `this+0x00000000` `void * audio_entry_list_head` (read, GUESS)

### FloatQueryHelper

Float difference helper used by particle/weather and scoring-gate paths: FloatGetter on *this minus a 3900-byte-offset float whose base register was lost.

Methods: `0x004B9CF0`

- `this+0x00000000` `void * source_object_ptr` (read, GUESS)

## Compatibility contracts

- **RuntimeLinkedListLayout** — List container bookkeeping block at this+0x0 (head), +0x4 (tail), +0x8 (current/iterator), +0xC (count); nodes hold data at +0x0, next link at +0x4, and a free-data flag at +0x8 (variant layouts place the flag at +0xC).
- **ListTeardownOwnership** — List and node destructors release per-node payloads only when the node free-data flag is set, always free the node itself, zero the container bookkeeping after the walk, and free the node buffer itself only when the a2 low bit is set.
- **AIDriverStateFieldLayout** — Per-driver AI object: driver state at this+0x2C, penalty state at this+0x30, performance activation byte at +0x342, season speed reference +0x348, target speed +0x34C, session-type selector +0x360; transition notification goes through dword_5EB978 with the state pointer at this+0x0.
- **PenaltyEligibilityGuard** — Penalty logic is gated on a server session (dword_7C569C == 5), a permitting penalty state at this+0x30, and a race phase dword_7C56A8 in {5,6,8}, with an optional penalty-enable plus session-type (dword_7C56A4 == 5) clause.
- **SeasonDataSectionContract** — Season races section is located via SeasonRacesSectionFinder; string-keyed child sections (e.g. the 'Qualifying' key) are resolved by StringKeyedLinkedListSearch; entries are fetched by null-checked index (up to 104), name-compared via sub_588410, and scalar values read via sub_58850F.
- **CareerStandingsEntryLayout** — Season standings entry: indexed FinishPosition array at this+24 and FinishPoints at this+216 (raw-source only), summary fields at this+408..428, active flag at +0x1B0; runtime scoring uses season points total +0x198, leader laps +0x1A0, vehicle index +0x1A4, finished position +0x1A8.
- **BoundedFloatArrayLayout** — Float lookup array with capacities at this+0x8 and this+0x88 and element base at this+0x90; negative or over-capacity indices return the -1.0 sentinel.
- **AudioSampleDispatchContract** — Audio dispatch requires a traversal-filterable entry list at this+0x0 and treats the -9.9999997e37 position parameter as a request for the fallback current float from global flt_5ACD04; playback path selection depends on entry state fields not represented in the packet field table.

## Unresolved

- Audio entry node fields at +36, +38 and +146 (base obj) and the playback-path selection semantics are not packet-confirmed; they are not present in the allowed field table.
- FloatDifference reads a float at a 3900-byte offset from an uninitialized register-derived base; the source register is lost and the field cannot be located or named.
- Menu action ids 0-13 and the semantics of the stored action slot at obj+0xF8C are not established; byte_4B9E1C is adjacent padding or unrelated data.
- The consumer of the cached pointer written to this+0x8 by resolveStoredPointer is not evidenced; callers span collision, model-scene, and network-packet paths.
- EmptyStub_0170 (callee 0x004B0170) is an empty stub; the per-node and per-element behavior it should perform is unknown.
- The 884-byte element stride and refcount-block layout (count dword at data[-1]) in destroyListWithRefCountElements are inferred from addressing, not independently evidenced.
- The two node layouts (free-data flag at +0x8 vs +0xC) are recorded as separate classes; the packet does not prove they are the same node type.
- Common ownership of the four-dword list container block across the destructor/append/index functions is inferred from structural identity, not packet-proven.
- The AIDriverState grouping of state transition, penalty eligibility, performance speed and variation scaling is a proposal; the packet does not prove a single owner object.
- The grid cell dispatcher 0x004BD900 semantics (copy, mark, or notify) and the anchor at this + 576 are unknown; the origin/scale field roles are inferred from arithmetic.
- Vehicle-source offsets +16540, +17600, +17604 and +13000 accessed through the dword_7C54F0 array are not packet field evidence; their identities remain unconfirmed.
- The qualifying/race source split at this+0x360 == 7 is DERIVED from existing analysis, not packet-proven.
- sub_58850F's return semantics (volume, pitch, time or score) are not established by the packet.
- Season-database entry offsets +16480 (position), +16484 (status) and +16444 (distance) used by SeasonScoring are inferred from usage, not proven.
- LoadCareerStandingsEntry's this+24 and this+216 indexed arrays and this+408..428 summary writes have no field evidence entries and are described from raw source only.
- Twenty-one globals listed by the deterministic facts (flt_59E43C..flt_8AD3B4 set) appear nowhere in the raw decompiled sources and are unresolved (see unresolved_evidence_refs).
