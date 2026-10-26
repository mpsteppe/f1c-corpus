# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

Reconstructs the generic runtime object layer from seventeen validated functions. One DERIVED class, TrackObjectManager, owns the constructor 0x0040FE50 that builds the fixed 104-entry vehicle data array (36-byte entries seeded from the static table at 0x005EC6E4 with 18624-byte strides) and nine per-category track-object bucket pairs (small 36-byte-entry arrays and large vtable-led 792/808-byte-entry arrays with off_59E720 initial vtables), then returns a combined pointer array. A GUESS class TextOverlayEventDispatcher (0x00411840) re-primes the byte_5EA438 path buffer and chains CharacterCodeMapper, RaceEventMessageDispatcher, FontCharacterRenderDispatcher and SoundEventDispatcher across 20-byte slots. A GUESS class EventValueResolver groups the four event-parameter resolvers (0x00412490, 0x00412E50, 0x00413820, 0x00413B60) plus TrackNameDisplayIDLookup (0x00417F60), all writing an output record at a1+0x8 and a1+0xC (secondary value from sub_414180/sub_4141A0) with a 1/-1 return convention. A GUESS class TextAttributeResolver groups the four structural twins (0x004133B0, 0x004134D0, 0x00413600, 0x00413710) that copy a string path and three metadata fields into an output struct from linked-list nodes. A GUESS class TextFormatRecord (0x004149A0) resets eight -1/-1/0 slot groups interleaved with StringCopyWithBufferRealloc; a GUESS class DrawableResourceContainer (0x004150C0) tears down three linked lists of drawable resources; a GUESS class FormatList (0x00415550, 0x00415730) scans and marks a format list keyed by driver name. ConditionalFreeFieldPointer (0x00414370) and StructCopy (0x004145C0) are generic unowned helpers. Interface IRaceEventValueResolver captures the shared event-parameter to output-record mapping contract.

## Function roles

- `0x0040FE50` **TrackObjectManager** — TrackObjectManager constructor, invoked by DynMan_Init (0x0042C1A0) on the global instance: writes the fixed vehicle count 104 into this+0x0C; allocates the vehicle data array (104 * 36 + 4 bytes, header count 104, entries via StructInitializerWithSentinelValues) into this+0x10, seeding each 36-byte entry from the static table unk_5EC6E4 at 18624-byte strides via ShortComputation_e860; zeroes eight category-count buckets (this+0x14/+0x1C/+0x24/+0x30/+0x3C/+0x48/+0x54/+0x60); counts scene nodes via AudioNetworkNodeCount(dword_8AFE88) and walks them via LinkedListNodeFinder; classifies each node by name (dspoly, dsindicator, dscone, cone, post, sign, wheel, wing, part literals at 0x005BEB60..0x005BEBA4) through SelfRelativeStringCopy and sub_588640 into per-category buckets, gating flagged nodes (0x10 bit at node+60) through SceneNodeVisibilityToggle; appends the five global node pointers dword_8AD074..dword_8AD084 to the dspoly bucket; allocates the dspoly small array into this+0x18, the non-DSP array into this+0x20 (from the special node list), and per-category small/large array pairs into this+0x28/0x2C (cone), 0x34/0x38 (post), 0x40/0x44 (sign), 0x4C/0x50 (wheel, 808-byte entries), 0x58/0x5C (wing), 0x64/0x68 (part) with reserved capacities (+416/+208/+832), each large entry initialized via ShortComputation_8e30, *entry = &off_59E720, StructInitWithFloatConstants, then *entry = off_59E72C/0x59E738/0x59E744/0x59E750/0x59E75C/0x59E768; writes the summed total into this+0x04, zeroes this+0x00, allocates the combined pointer array into this+0x08 and returns it.
- `0x00411840` **TextOverlayEventDispatcher** — TextOverlayEventDispatcher prepper, called by TextOverlayDisplayTimer (0x004186F0): resolves a generation index and two sub-indices from *a1 via ShortComputation_19d0/1a00/1a50, returning 0 on any -1/negative sentinel; a one-time init block (guarded by byte_5EA5E0 bit 0) sets dword_5EA5D0 = 0, dword_5EA5D4 = -1, dword_5EA5D8 = -1, dword_5EA5DC = -1, re-primes byte_5EA438, and evaluates sub_4119B0 via BooleanToIntConversion; every call re-primes the path buffer through StringCopyWithBufferRealloc and dispatches in sequence through CharacterCodeMapper, RaceEventMessageDispatcher, FontCharacterRenderDispatcher and SoundEventDispatcher, advancing a 20-byte slot offset per successful dispatch and decrementing the caller's counter via DecrementCounterWithFloorAtZero; returns the count of successful dispatches (0-2).
- `0x00412490` **EventValueResolver** — EventValueResolver dispatcher-style mapper: given mode a2 (0 or 1), flag a4, and event parameter a3 (1-24), selects one of four switch tables (jpt_4124C4/jpt_4125BB/jpt_4126A4/jpt_4128B8 at 0x00412AB0/0x00412B10/0x00412B70/0x00412BD0) and computes a mapped value in the 236-387 range; the a2==0 tables further branch on flag a5 between high and low values. On a recognized combination the mapped value is written to a1+0x8, the value returned by sub_414180(a2) is written to a1+0xC, and 1 is returned; any unrecognized input returns -1.
- `0x00412E50` **EventValueResolver** — EventValueResolver event-parameter-to-bucket mapper: dispatch mode a2 selects one of two switch jump tables (jpt_412E78 covering cases 1-26, jpt_413097 covering cases 1-24 at 0x004132E4/0x00413344); each case selects a base bucket index that flag a4 adjusts to one of two variants (a4 != 0 selects the lower base, otherwise the base is offset by 24 for a2==1 or 26 for a2==0); special cases a3=23 (a2==1) and a3=26 (a2==0) compute v5 = (a4 != 0 ? 0xFFFFFFE8 : 0) + 265. On a valid mapping (v5 >= 0) writes the bucket index to a1+0x8 and the sub_414180(a2) value to a1+0xC and returns 1; invalid a2/a3 or negative index returns -1. Called from RaceEventMessageDispatcher and SoundEventDispatcher.
- `0x004133B0` **TextAttributeResolver** — TextAttributeResolver field lookup: fetches the attribute record at index a3 via LinkedListIndexedAccessor_5680; when a record exists and a2 selects a valid field (0 or 1), copies the string path (falling back to byte_5EA438 when null) and three metadata fields (+0x08, +0x0C, +0x10) from one of four record slots (a2==1 selects record+0x5C, or +0x70 when a4==0; a2==0 selects record+0x0C, or +0x20 when a4==0) into the output struct at a1 via StringCopyWithBufferRealloc; normalizes the output to byte_5EA438 and returns -1 when the output still holds all default values (string equals byte_5EA438, metadata == -1/-1, byte field == 0), else 1.
- `0x004134D0` **TextAttributeResolver** — TextAttributeResolver variant resolving an attribute from a list node, called by SessionStringNameLookup (0x004122C0): LinkedListIndexedAccessor_5680(a3) fetches the indexed node; dispatches on attribute mode a2 (0 selects node+52 or node+72 when a4 is clear, 1 selects node+132 or node+152 when a4 is clear); copies the selected string via StringCopyWithBufferRealloc with the empty-sentinel fallback byte_5EA438, copies the node attribute dword/byte components (dword +8, dword +12, byte +16) into a1+0x8/a1+0xC/a1+0x10; re-copies the empty sentinel and returns -1 when the output struct is still the all-empty sentinel, else 1.
- `0x00413600` **TextAttributeResolver** — TextAttributeResolver variant resolving an attribute from a list node, called by SoundEventDispatcher (0x00411E90): LinkedListIndexedAccessor_56c0(a3) fetches the indexed node; the copy path runs only when the node is non-null AND the attribute mode a2 is exactly 1; slot selection a4 set = node+12, a4 clear = node+32; copies the selected string via StringCopyWithBufferRealloc with the empty-sentinel fallback byte_5EA438, copies the node attribute dword/byte components into a1+0x8/a1+0xC/a1+0x10; re-copies the empty sentinel and returns -1 when the output struct is still the all-empty sentinel, else 1.
- `0x00413710` **TextAttributeResolver** — TextAttributeResolver structural twin of 0x004133B0 restricted to a single field selector: fetches the attribute record at index a3 via LinkedListIndexedAccessor_56c0; only when the record is non-null and a2 == 1 copies the string path (fallback byte_5EA438) and metadata from a record slot (record+0x34, or record+0x48 when a4==0) into the output struct at a1 via StringCopyWithBufferRealloc; regardless of the copy path the output string is normalized to byte_5EA438 and the same sentinel test as 0x004133B0 decides the result: -1 when all output fields are default, else 1.
- `0x00413820` **EventValueResolver** — EventValueResolver cascading threshold classifier invoked by SoundEventDispatcher (0x00411E90): when both a2 and a4 are zero, widens integer a3 to double and selects one of 17 bucket indices (1..17) through a chain of comparisons against the read-only double globals dbl_59E420 and dbl_59E788..dbl_59E7E0, with final buckets 14..17 decided by integer checks a3 >= 75, a3 >= 110 and a3 >= 999; writes the bucket index to a1+0x8 and the sub_414180(0) result to a1+0xC, returning 1. When a2 or a4 is non-zero the classifier does not touch a1 and returns -1.
- `0x00413B60` **EventValueResolver** — EventValueResolver season-specific team-id mapper: when a2 equals 1 and the flag a4 is zero, resolves the season database path as dword_7D0434 (fallback byte_5EA438) and probes it against the F11999.GDB/F12000.GDB/F12001.GDB/F12002.GDB filename literals (0x005BF994/0x005BF988/0x005BF97C/0x005BF970) via sub_588410, selecting one of four jump-table switch tables (0x00413EFC/0x00413F40/0x00413F84/0x00413FC8) with base team ids 333, 334, 335 or 336 (each stepping by 4 per entry); on a mapped case (a3 in 1-17) writes the team id to a1+0x8 and the sub_414180(1) result to a1+0xC and returns 1; otherwise returns -1.
- `0x00414370` **UnknownObject** — ConditionalFreeFieldPointer generic teardown helper (thiscall), structural twin of ConditionalFreeWithBit0Flag (0x00404F70): reads the pointer field at this+0; when non-null, frees it through FreeWrapper_7bcf and returns the wrapper's result; otherwise returns the null field value. Widely used as a list/node/drawable cleanup primitive by GlobalListTripleCleanupWithTimerRemoval, DrawableResourceCleanup, NamedEntryLookupInFormatList, FunctionCallWrapper_1470, SortedStringTableBuilder, sub_485EB0, sub_4963D0, StaticInitBulk, DoubleListCleanup, MultiFieldCleanup, FilterPropertiesListNodeRemover, ArrayBlockCleanup and LinkedListDestructorWithChildCleanup.
- `0x004145C0` **UnknownObject** — StructCopy plain field-by-field copy of an 8-DWORD (32-byte) struct: copies a2[0..7] into this[0..7] in a shuffled order (0,2,3,4,5,6,7,1) and returns the destination pointer this; no transformation, validation, or guard. Used as a helper when inserting driver-table entries (InsertDriverTableEntry 0x00418560) and when compacting array slots (ArraySlotCompactionWithGapFilling 0x00418AC0).
- `0x004149A0` **TextFormatRecord** — TextFormatRecord this-call initializer: across eight slot groups at offsets 0x08..0x98 it resets each slot to the inactive state (DWORD -1, DWORD -1, BYTE 0), interleaving every group with a call to StringCopyWithBufferRealloc(&byte_5EA438) that reinitializes the global path-string buffer; a ninth trailing slot group beyond the last field-table entry is reached by advancing this by 156 bytes, with the final StringCopyWithBufferRealloc return value passed through. Called during format-list entry setup/teardown and driver resource cleanup.
- `0x004150C0` **DrawableResourceContainer** — DrawableResourceContainer teardown of three linked lists of drawable resources hanging off the receiver: walks each list node (active flag at node+0x8, next pointer at node+0x4, resource pointer at node+0), frees each active resource through its type-specific destructor (first list: TextFormatStructInitializer then ArrayDestructorIterator passes and ShortComputation_4370 then ConditionalFreeFieldPointer then FreeWrapper_7bcf; second list: MultiFieldPointerFree then FreeWrapper_7bcf; third list: TextFormatStructInitializer_4fe0 then ArrayDestructorIterator passes and ShortComputation_4370 then ConditionalFreeFieldPointer then FreeWrapper_7bcf), then frees each node; finally zeroes each list's four tracking fields (this+0x0..0xC, this+0x10..0x1C, this+0x20..0x2C) and returns 0. Invoked by GlobalListTripleCleanupWithTimerRemoval (0x00414210) and ShortComputation_8900 (0x00418900).
- `0x00415550` **FormatList** — FormatList index scanner with validation: scans the linked list (head at this+0x10, node count at this+0x1C) to find the index of the node whose string matches a2, using sub_566810 for comparison; walks forward via the next pointer at node+0x4 and dereferences the node data pointer (falling back to byte_5EA438 when null); returns the matching index, or -1 when a2 is null, the list is empty, or no node matches.
- `0x00415730` **FormatList** — FormatList driver lookup and active-flag setter: resets the format-list active flags via sub_415700; resolves the current vehicle from the global vehicle-file buffer via CurrentVehicleAccessor(&unk_8AC388) and VehicleLookupByName(a2); when a current vehicle exists, finds or creates a format-list entry keyed by the current vehicle's driver name (char string at vehicle+188) with secondary key a2 via NamedEntryLookupInFormatList, fetches the node at the returned index via LinkedListIndexedAccessor, sets the node's active-flag byte at node+0x0C to 1, and returns the fetched list node (or null when there is no current vehicle).
- `0x00417F60` **EventValueResolver** — EventValueResolver track-name display/commentary-ID mapper: reads the track scene name from a track descriptor at dword_8AC490 + 396*a2, offset +260; calls ShortComputation_41a0(1) for a secondary value gating the success path; compares the track name against all seventeen track scene name literals (0x005C2628..0x005C26E0) via sub_566810 and assigns the alternate-layout (a3 set) or primary-layout display ID for the matching track; copies the track name into the byte_5EA438 buffer via StringCopyWithBufferRealloc; on success stores the resolved ID to a1+0x8, the secondary value to a1+0xC, clears the status byte at a1+0x10 and returns 0; returns 1 on early failure.

## Proposed classes

### TrackObjectManager

Dynamic track-object manager (global instance dword_5EA560, initialized by DynMan_Init): owns a fixed 104-entry vehicle data array, per-category count/array pairs for scene-object buckets (dspoly, dsindicator, dscone, cone, post, sign, wheel, wing, part), and a combined pointer array over all built objects; its constructor walks the scene node graph and materializes the per-category arrays.

Methods: `0x0040FE50`

- `this+0x00000000` `dword combined_index` (write, GUESS)
- `this+0x00000004` `dword total_object_count` (write, DERIVED)
- `this+0x00000008` `void* combined_object_array` (write, DERIVED)
- `this+0x0000000C` `dword fixed_vehicle_count` (write, DERIVED)
- `this+0x00000010` `void* vehicle_data_array` (write, DERIVED)
- `this+0x00000014` `dword dspoly_bucket_count` (write, DERIVED)
- `this+0x00000018` `void* dspoly_small_array` (write, DERIVED)
- `this+0x0000001C` `dword non_dsp_bucket_count` (write, DERIVED)
- `this+0x00000020` `void* non_dsp_array` (write, DERIVED)
- `this+0x00000024` `dword cone_bucket_count` (write, DERIVED)
- `this+0x00000028` `void* cone_small_array` (write, DERIVED)
- `this+0x0000002C` `void* cone_large_array` (write, DERIVED)
- `this+0x00000030` `dword post_bucket_count` (write, DERIVED)
- `this+0x00000034` `void* post_small_array` (write, DERIVED)
- `this+0x00000038` `void* post_large_array` (write, DERIVED)
- `this+0x0000003C` `dword sign_bucket_count` (write, DERIVED)
- `this+0x00000040` `void* sign_small_array` (write, DERIVED)
- `this+0x00000044` `void* sign_large_array` (write, DERIVED)
- `this+0x00000048` `dword wheel_bucket_count` (write, DERIVED)
- `this+0x0000004C` `void* wheel_small_array` (write, DERIVED)
- `this+0x00000050` `void* wheel_large_array` (write, DERIVED)
- `this+0x00000054` `dword wing_bucket_count` (write, DERIVED)
- `this+0x00000058` `void* wing_small_array` (write, DERIVED)
- `this+0x0000005C` `void* wing_large_array` (write, DERIVED)
- `this+0x00000060` `dword part_bucket_count` (write, DERIVED)
- `this+0x00000064` `void* part_small_array` (write, DERIVED)
- `this+0x00000068` `void* part_large_array` (write, DERIVED)

### TextOverlayEventDispatcher

Text-overlay/event dispatch prepper: holds the one-time-init state block (dword_5EA5D0/dword_5EA5D4/dword_5EA5D8/dword_5EA5DC and the bit-0 flag byte_5EA5E0) and the global path-string buffer byte_5EA438; resolves a generation index and two sub-indices, then chains CharacterCodeMapper, RaceEventMessageDispatcher, FontCharacterRenderDispatcher and SoundEventDispatcher over a caller-owned 20-byte slot buffer, returning the number of successful dispatches.

Methods: `0x00411840`


### EventValueResolver

Event-parameter to output-record resolver family: maps a race event parameter (mode, flag, value) to a resolved value written at record+0x8 and a secondary value (from sub_414180(mode) or sub_4141A0) written at record+0xC, returning 1 on success and -1 on unrecognized input; includes the event-id/team-id/bucket/threshold/track-name mappings feeding the race-event and sound-event dispatchers.

Methods: `0x00412490`, `0x00412E50`, `0x00413820`, `0x00413B60`, `0x00417F60`

- `this+0x00000008` `dword resolved_value` (write, DERIVED)
- `this+0x0000000C` `dword secondary_value` (write, DERIVED)
- `this+0x00000010` `byte status_byte` (write, GUESS)

### TextAttributeResolver

Text-attribute resolver family: fetches an attribute record from an indexed linked list and copies a string path (with byte_5EA438 default fallback) plus three metadata components (dword +8, dword +12, byte +16) into a caller output struct; returns -1 when the output still holds all default sentinel values, else 1; four structural twins differ in accessor (0x00415680 vs 0x004156C0), accepted attribute mode and record slot offsets.

Methods: `0x004133B0`, `0x004134D0`, `0x00413600`, `0x00413710`

- `this+0x00000000` `char* result_string` (write, GUESS)
- `this+0x00000008` `dword metadata_dword_a` (write, DERIVED)
- `this+0x0000000C` `dword metadata_dword_b` (write, DERIVED)
- `this+0x00000010` `byte metadata_byte` (write, DERIVED)

### TextFormatRecord

Text-format record: eight slot groups of the form (DWORD -1, DWORD -1, BYTE 0) at offsets 0x08..0x98, reset to the inactive state by the initializer which reinitializes the global path-string buffer (byte_5EA438) at every slot boundary; a ninth trailing slot group is reached by advancing the record pointer by 156 bytes.

Methods: `0x004149A0`

- `this+0x00000008` `dword slot0_inactive_dword_a` (write, GUESS)
- `this+0x0000000C` `dword slot0_inactive_dword_b` (write, GUESS)
- `this+0x00000010` `byte slot0_flag_byte` (write, GUESS)
- `this+0x00000018` `dword slot1_inactive_dword_a` (write, GUESS)
- `this+0x0000001C` `dword slot1_inactive_dword_b` (write, GUESS)
- `this+0x00000020` `byte slot1_flag_byte` (write, GUESS)
- `this+0x0000002C` `dword slot2_inactive_dword_a` (write, GUESS)
- `this+0x00000030` `dword slot2_inactive_dword_b` (write, GUESS)
- `this+0x00000034` `byte slot2_flag_byte` (write, GUESS)
- `this+0x00000040` `dword slot3_inactive_dword_a` (write, GUESS)
- `this+0x00000044` `dword slot3_inactive_dword_b` (write, GUESS)
- `this+0x00000048` `byte slot3_flag_byte` (write, GUESS)
- `this+0x00000054` `dword slot4_inactive_dword_a` (write, GUESS)
- `this+0x00000058` `dword slot4_inactive_dword_b` (write, GUESS)
- `this+0x0000005C` `byte slot4_flag_byte` (write, GUESS)
- `this+0x00000068` `dword slot5_inactive_dword_a` (write, GUESS)
- `this+0x0000006C` `dword slot5_inactive_dword_b` (write, GUESS)
- `this+0x00000070` `byte slot5_flag_byte` (write, GUESS)
- `this+0x0000007C` `dword slot6_inactive_dword_a` (write, GUESS)
- `this+0x00000080` `dword slot6_inactive_dword_b` (write, GUESS)
- `this+0x00000084` `byte slot6_flag_byte` (write, GUESS)
- `this+0x00000090` `dword slot7_inactive_dword_a` (write, GUESS)
- `this+0x00000094` `dword slot7_inactive_dword_b` (write, GUESS)
- `this+0x00000098` `byte slot7_flag_byte` (write, GUESS)

### DrawableResourceContainer

Container of three linked lists of drawable resources (list heads at this+0x0, this+0x10, this+0x20, each with four tracking fields); its teardown walks every node (active flag node+0x8, next node+0x4, resource node+0), frees each active resource via its type-specific destructor, frees the node, and zeroes all twelve tracking fields.

Methods: `0x004150C0`

- `this+0x00000000` `void* list1_head` (read, GUESS)
- `this+0x00000004` `dword list1_tracking_b` (write, GUESS)
- `this+0x00000008` `dword list1_tracking_c` (write, GUESS)
- `this+0x0000000C` `dword list1_tracking_d` (write, GUESS)
- `this+0x00000010` `void* list2_head` (read, GUESS)
- `this+0x00000014` `dword list2_tracking_b` (write, GUESS)
- `this+0x00000018` `dword list2_tracking_c` (write, GUESS)
- `this+0x0000001C` `dword list2_tracking_d` (write, GUESS)
- `this+0x00000020` `void* list3_head` (read, GUESS)
- `this+0x00000024` `dword list3_tracking_b` (write, GUESS)
- `this+0x00000028` `dword list3_tracking_c` (write, GUESS)
- `this+0x0000002C` `dword list3_tracking_d` (write, GUESS)

### FormatList

Format list keyed by string names: linked-list head at this+0x10 with node count at this+0x1C; supports scanning for a node index by string match (sub_566810) and finding/creating an entry keyed by the current vehicle's driver name and marking the matching node's active-flag byte at node+0x0C.

Methods: `0x00415550`, `0x00415730`

- `this+0x00000010` `void* list_head` (read, GUESS)
- `this+0x0000001C` `dword list_count` (read, GUESS)

## Compatibility contracts

- **TrackObjectManagerBuild** — A replacement executable must keep a track-object manager whose constructor writes the fixed vehicle count 104 at +0x0C, allocates a 36-byte-entry vehicle data array at +0x10 seeded from the static table at 0x005EC6E4, builds per-category count/array pairs (dspoly +0x14/+0x18, non-DSP +0x1C/+0x20, cone +0x24/+0x28/+0x2C, post +0x30/+0x34/+0x38, sign +0x3C/+0x40/+0x44, wheel +0x48/+0x4C/+0x50, wing +0x54/+0x58/+0x5C, part +0x60/+0x64/+0x68), writes the summed total at +0x04 and the combined pointer array at +0x08, and returns that combined array; DynMan_Init (0x0042C1A0) invokes it on the global instance.
- **EventValueResolverOutputRecord** — Event-parameter resolvers feeding the race-event and sound-event dispatchers must write the resolved value to record+0x8 and the secondary value (from sub_414180(mode) or sub_4141A0) to record+0xC, return 1 on a recognized input, and return -1 on any unrecognized input without modifying the record.
- **TextAttributeLookupContract** — Text-attribute resolution must fetch an attribute record from an indexed linked list (accessors 0x00415680/0x004156C0), copy a string path (defaulting to byte_5EA438 when null) plus metadata (dword +8, dword +12, byte +16) into the caller output struct, normalize the output to byte_5EA438, and return -1 when the output still holds all default sentinel values (string equals byte_5EA438, metadata -1/-1, byte 0), else 1.
- **ConditionalFreeFieldPointerContract** — The generic conditional-free primitive must read the pointer field at this+0, free it through FreeWrapper_7bcf when non-null and return the wrapper result, and return the (null) field value when the field is null; it must remain a free-standing helper reusable by every list/node/drawable teardown path.
- **DrawableResourceTeardown** — Drawable-resource container teardown must walk each of the three lists (heads at +0x0, +0x10, +0x20), per node read the active flag at node+0x8, the next pointer at node+0x4 and the resource pointer at node+0, free each active resource through its type-specific destructor then free the node, and finally zero all twelve tracking fields (+0x0..+0x2C), returning 0.
- **TextOverlayDispatchLoop** — The text-overlay display timer path must re-prime the global path buffer (byte_5EA438) each call, dispatch in order through CharacterCodeMapper, RaceEventMessageDispatcher, FontCharacterRenderDispatcher and SoundEventDispatcher, advance a 20-byte slot offset per successful dispatch, decrement the caller's counter via DecrementCounterWithFloorAtZero, and return the count of successful dispatches (0-2).
- **FormatListLayout** — A string-keyed format list must keep its linked-list head at +0x10 and its node count at +0x1C, support index-by-string scanning through sub_566810 with the byte_5EA438 null-string fallback, and support find-or-create of an entry keyed by the current vehicle's driver name (vehicle+188) whose node's active-flag byte at node+0x0C is set to 1.

## Unresolved

- The exact role of the reserved capacity (wheel +416, wing +208, part +832) in the large arrays and the static per-object data read past the threshold (local pointer tables) is inferred from the threshold literals matching the capacity additions; the data source beyond the buckets is not confirmed.
- Whether unk_5EC6E4 + 18624*index is a per-vehicle static table or a scene-geometry table is unknown from this packet.
- The meaning of the five global node pointers dword_8AD074..dword_8AD084 (special objects appended to the dspoly bucket) is unknown.
- dword_8AFE88 passed to AudioNetworkNodeCount is assumed to be the scene-root/node-list handle from its call position.
- The named category callees (StructInitializerWithSentinelValues, StructInitWithFloatConstants, etc.) are generic initializer names from the corpus, not confirmed class constructors.
- TextOverlayEventDispatcher's owner object is unidentified; the state block globals (dword_5EA5D0..dword_5EA5DC, byte_5EA5E0) are treated as one contiguous block only by proximity, not proven ownership.
- The meaning of the 20-byte slot stride in FontRenderingPrep and the exact overlay resource it addresses are not documented by this packet.
- sub_4119B0 (0x004119B0) is referenced only as an argument to BooleanToIntConversion during one-time init; its role in the state block is unverified.
- The mapped value ranges (236-387 driver-model indices, 214-266 bucket indices, 1-17 threshold buckets, 333-336 team-id bases) and the a5/a4 flag semantics are DERIVED prose carried from existing analysis, not confirmed by this packet.
- Why case 8 of the a2==1/a4==1 switch falls through to the shared 282 label inside the sibling table is a layout artifact of the compiled switch; the intended source structure is unknown.
- The purpose of the secondary value computed by sub_414180(mode) / sub_4141A0 written to record+0xC is unknown.
- The mapping of the four jump-table globals (0x00413EFC/0x00413F40/0x00413F84/0x00413FC8) to the four season-file switch tables is not asserted; only the selected base ids (333/334/335/336) are confirmed from the case literals.
- The four TextAttributeResolver twins differ in accessor (0x00415680 vs 0x004156C0), accepted attribute mode and record slot offsets (+0x5C/+0x70/+0x0C/+0x20 vs +0x34/+0x48 vs +12/+32 vs +52/+72/+132/+152); the owning list-node type and the meaning of the metadata fields (dword +8, dword +12, byte +16) and the sentinel convention (-1/-1/0) are not established by the packet.
- FreeWrapper_7bcf (callee:0x00587BCF) is listed as a callee of the TextAttributeResolver twins but never appears in their raw decompiled bodies; its use may be inside StringCopyWithBufferRealloc, and it is preserved in unresolved_evidence_refs.
- Global dword_5EA5E8 is flagged as read by the fact table of the TextAttributeResolver twins but is absent from the raw decompiled source; preserved in unresolved_evidence_refs.
- Which threshold global holds which numeric double value in classifyThresholdLevel is not deterministically tied by the packet (the raw decompilation inlines the literals).
- TextFormatRecord: raw source for slot 0 writes a single BYTE 0 at this+0x0C while the deterministic field table records this+0xC with init literal -1; the two packet sources disagree for slot 0.
- TextFormatRecord: the raw source shows a trailing ninth slot group after the last field-table entry (this advanced by 156, then offsets relative to the new base); no field evidence refs cover it, so its offsets are not named.
- The exact meaning of each TextFormatRecord slot (x/y coordinates, active flag) is inferred from the -1/-1/0 reset pattern, not stated in the packet.
- TextFormatStructInitializer (0x004149A0) and TextFormatStructInitializer_4fe0 (0x00414FE0) are called immediately before ArrayDestructorIterator and free in DrawableResourceCleanup, so their names likely mislabel teardown/destructor work.
- The two array groups in the first and third drawable-resource types (v6+34/v6+24/v6+14/v6+4 and v14+13/v14+3, stride 20 count 2) are unnamed; exact element layouts unknown.
- List tracking-field semantics (head/tail/count/tracking per four-field group) in DrawableResourceContainer and the exact meaning of the node+8 guard byte (active vs allocated) are inferred from ordering, not proven.
- The return convention of sub_566810 (truthy on match versus zero on match) is inferred only from usage.
- Offset 188 (driver-name string inside the vehicle record) used by DriverLookupAndFlagSetter is used only as an offset from the current vehicle pointer; the owning vehicle type is not stated in this packet.
- Why the active flag in DriverLookupAndFlagSetter is only set and never cleared is external context; sub_415700 is assumed to perform the clearing.
- Global flt_5EA618 is listed as read by the fact table of TrackNameDisplayIDLookup but does not appear in the raw source body; preserved in unresolved_evidence_refs.
- The exact track-name to display-ID table values in TrackNameDisplayIDLookup are long and mechanical; the semantic purpose (commentary/TV display IDs per track, layout and wet/dry mode) follows the caller CommentaryTVPWSPathBuilder and is not confirmed by this packet.
- The event-to-driver-model-index and track-name naming is carried from the packet's existing analysis as DERIVED prose; it is not confirmed by this packet.
- byte_5EA438 is treated as the default/empty path string, but its actual content is not evidenced.
