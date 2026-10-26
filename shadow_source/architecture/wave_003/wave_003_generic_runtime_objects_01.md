# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

A heterogeneous set of runtime objects and helpers. SessionController (0x00404890) drives race-mode session transitions over shared globals (0x007D2E44 scoring enable, 0x007D0410/0x0418/0x041C race-mode and timeout override, 0x007CE24D session-transition flag, float scale globals 0x007D0798/0x07A0/0x07A4). AudioStreamSingletonFactory (0x00404FE0) lazily constructs the stream-object singleton at unk_5EA440; AudioStreamObject (0x00406AB0 constructor, 0x00406BA0 destructor with four intrusive lists, vtable off_59E530/off_59E598) is that stream object, while AudioStreamSlotOwner (0x00406750) manages a stream handle at +0xC and a slot index at +0x5C (AIL_close_stream). ManagedCleanupObject (0x00405410/0x004054A0) is a staged destructor over a file handle, two heap buffers and a sub-object. Three keyed intrusive list classes with distinct header offsets hold file-backed resources (KeyedResourceList 0x00407520 insert / 0x00407E40 lookup; KeyedObjectList 0x00407BE0 remove-by-key; NamedResourceList 0x00407F10 id-by-name). KeyedListNodeObject (0x004058A0) is a teardown helper swapping vtables and unlinking from a keyed list. CameraViewSystem (0x00408E20, plus file-load dispatch 0x00409770) owns fixed and dynamic 3D-sound-emitter camera views (200-byte stride, four fixed slots +0x10..+0x1C, dynamic array +0x20 with count +0x38); CameraMenuController (0x0040A910) maps menu slot ids to camera modes; StaticCameraSceneLoader (0x0040B030) loads static camera scene entries. ReciprocalTimeController (0x00408450) computes a safe reciprocal. IndirectStatusByteReader (0x00404F00) reads a status byte from a referenced object. Most packet owners are UnknownObject; class groupings here are DERIVED/GUESS synthesis.

## Function roles

- `0x00404890` **SessionController** — Session race-mode transition setup: path-string init on the session object, then on the race-mode branch (this+0x20 == 1) saves/forces scoring-enable global 0x007D2E44 and race-mode global 0x007D0410 (with timeout clamp 0x007D0418/0x007D041C), raises the session-transition flag via SetGlobalFlag, runs ShortComputation_d360(1,15) and computes the float scale at 0x007D0798; both paths set the activation flag at this+0x14.
- `0x00404F00` **IndirectStatusByteReader** — Indirect byte reader: reads the target pointer stored at this+0x0 and returns the byte at offset +0x14 of the pointed-to object; a thiscall flag/status accessor with no other side effects.
- `0x00404FE0` **AudioStreamSingletonFactory** — One-time singleton initializer gated on byte_5EA4E0 bit 0: sets the gate, constructs the stream object into static buffer unk_5EA440 via 0x00406AB0, registers the load-path wrapper via BooleanToIntConversion, and returns &unk_5EA440 on every call.
- `0x00405410` **ManagedCleanupObject** — Multi-stage destructor: runs ConditionalCleanupWithDualFree (0x004054A0), sub-object cleanup 0x004D4860, hands this+0x30 to VTableDestructorWrapperWithNullCheck, then frees the heap buffer at this+0x4 via FreeWrapper when non-null; returns the destructor or free result.
- `0x004054A0` **ManagedCleanupObject** — Conditional cleanup: vtable sub-struct init/zero-fill, conditional close of the file handle at this+0xC (zeroed after), conditional free of the buffer at this+0x18, then re-initializes the struct via CameraViewStructInitializer and returns its result; used as the first cleanup stage by 0x00405410.
- `0x004058A0` **KeyedListNodeObject** — Object teardown: installs vtable off_59E490, releases the audio resource (0x00405B00), removes this object's node from a keyed list (0x00407BE0), swaps to vtable off_59E4B4, then frees the child allocation at this+0x4 when non-null.
- `0x00406750` **AudioStreamSlotOwner** — Audio stream teardown: closes the Miles stream handle at this+0xC via AIL_close_stream (cleared to 0), runs slot cleanup 0x00406A70 when the slot index at this+0x5C is not -1, obtains a sub-struct from this+0x1C via 0x004080B0 and re-initializes it through the vtable dispatch/zero-fill path.
- `0x00406AB0` **AudioStreamObject** — Stream object constructor: zeroes the data block +0x8..+0x48, installs vtable off_59E530, sets +0x4=1, +0x54=2, +0x8C=1.0f, zeroes tail fields +0x88..+0x9C, calls MilesSoundSystemSampleAllocator(0) and returns this; invoked by the one-time initialization path.
- `0x00406BA0` **AudioStreamObject** — Stream object destructor: walks four intrusive lists at +0x8..+0x44 (nodes passed to UtilityFunction / freed, or data conditionally released via ConditionalFreeWithBit0Flag / vtable[0] destructor), zeroes each list's four headers, swaps the vtable from off_59E530 to off_59E598, and returns the AudioSystemShutdown result.
- `0x00407520` **KeyedResourceList** — Keyed insert of a file-backed resource node: consumes an a2 pair, walks the list from head +0x38 via cursor +0x40 to reject duplicate key a3, allocates a 116-byte node, opens the file (0x00587DB0), reads content, stores key/size, links a 12-byte element and updates head/tail/cursor/count; failure paths close, clean up and free.
- `0x00407BE0` **KeyedObjectList** — Keyed remove: two-pass traversal (cursor +0x10 for the match, head +0x8 for the predecessor), unlinks the matched node, adjusts head/tail/cursor, decrements count +0x14, conditionally calls the value object's vtable release method when the node +8 flag is set, frees the node and returns it (or null).
- `0x00407E40` **KeyedResourceList** — Resource lookup in the keyed list: when a3 != -1 matches the node ID at data+16, when a3 == -1 matches the string name via sub_588410; resets cursor +0x40 to head +0x38 on entry and advances through each node's +4 next; returns the matching data pointer or 0.
- `0x00407F10` **NamedResourceList** — ID-by-name lookup over a named resource list: skips nodes whose ID at +0x5C is -1, compares each node's name via StringPointerAccessor and sub_588410, returns the matching node's +0x5C ID; returns -1 for null/default-name/empty/no-match.
- `0x00408450` **ReciprocalTimeController** — Safe reciprocal helper: resets this+0x4 to 0, writes the reciprocal 1.0/a2 into this+0x8 when a2 is strictly positive, else writes 1.0f and calls FloatClampWithEventDispatch on this; invoked per-frame by several timing callers.
- `0x00408E20` **CameraViewSystem** — Camera view system init: opens an audio stream from the resource handle, parses camera-view definitions (swingman/cockpit/tvcockpit/nosecam plus a capped dynamic localcam array), builds fixed + dynamic 3D sound emitters, applies session-manager camera positions to every emitter and cleans up stack resources; returns 1 on failure, 0 on success.
- `0x00409770` **CameraViewSystem** — File load and dispatch: clears the read-only attribute, loads the file into a stack temp struct via one of two loader variants selected by a3, then dispatches the loaded state to four fixed sub-objects (this+0x10..+0x1C) and each element of the stride-200 array at this+0x20 (count this+0x38) through each object's vtable+8 callback; returns 0 if any sub-object received data, 1 otherwise.
- `0x0040A910` **CameraMenuController** — Menu slot action dispatch: matches slot id a2 against stored slot entries (+0x10..+0x30 for the eight fixed slots, +0x20 stride-200 scan for the variable array) and dispatches ViewCameraModeDispatch with the matching camera-mode index; records the matched array index at this+0x3C and, when a3 is set, invokes the vtable+16 update callback.
- `0x0040B030` **StaticCameraSceneLoader** — Static camera scene load: initializes a 128-entry scratch transform array, searches the string table for MainView (stored at this+0x4), opens the audio stream wrapper, reads up to 128 StaticCam entries, allocates a persistent 160*count+4-byte array, stores it at this+0xC with count this+0x10 (current index this+0x14 reset to 0), and copies the entries; returns 0 on success, 1 on skip/failure.

## Proposed classes

### CameraViewSystem

Owns fixed and dynamic 3D-sound-emitter camera views: parses camera definitions from an audio stream, builds and positions the emitters, and dispatches file-loaded state to its sub-objects.

Methods: `0x00408E20`, `0x00409770`

- `this+0x00000010` `void* fixed_view_slot_0` (read_write, DERIVED)
- `this+0x00000014` `void* fixed_view_slot_1` (read_write, DERIVED)
- `this+0x00000018` `void* fixed_view_slot_2` (read_write, DERIVED)
- `this+0x0000001C` `void* fixed_view_slot_3` (read_write, DERIVED)
- `this+0x00000020` `void* dynamic_view_array` (read_write, DERIVED)
- `this+0x00000024` `void* emitter_ref_0` (read, GUESS)
- `this+0x00000028` `void* emitter_ref_1` (read, GUESS)
- `this+0x0000002C` `void* emitter_ref_2` (read, GUESS)
- `this+0x00000030` `void* emitter_ref_3` (read, GUESS)
- `this+0x00000038` `int dynamic_view_count` (read_write, DERIVED)
- `this+0x0000003C` `int dynamic_view_count_hi` (write, GUESS)

### CameraMenuController

Maps menu slot selection ids to camera-view modes: matches the slot id against stored slot entries and dispatches the matching camera mode, recording the matched variable-array index.

Methods: `0x0040A910`

- `this+0x00000000` `void* vtable` (read, GUESS)
- `this+0x00000010` `int slot_id_0` (read, DERIVED)
- `this+0x00000014` `int slot_id_1` (read, DERIVED)
- `this+0x00000018` `int slot_id_2` (read, DERIVED)
- `this+0x0000001C` `int slot_id_3` (read, DERIVED)
- `this+0x00000020` `void* variable_slot_array` (read, GUESS)
- `this+0x00000024` `int slot_id_5` (read, DERIVED)
- `this+0x00000028` `int slot_id_6` (read, DERIVED)
- `this+0x0000002C` `int slot_id_7` (read, DERIVED)
- `this+0x00000030` `int slot_id_8` (read, DERIVED)
- `this+0x00000038` `int slot_count` (read, DERIVED)
- `this+0x0000003C` `int matched_variable_index` (write, GUESS)

### StaticCameraSceneLoader

Loads static camera scene entries from a file-backed stream into a persistent array, storing the MainView string handle, the array, its count and the current index.

Methods: `0x0040B030`

- `this+0x00000004` `void* mainview_string` (write, GUESS)
- `this+0x0000000C` `void* camera_entry_array` (read_write, DERIVED)
- `this+0x00000010` `int camera_entry_count` (read_write, DERIVED)
- `this+0x00000014` `int current_entry_index` (write, DERIVED)

### SessionController

Transitions the session object between race and non-race modes, saving and forcing scoring/race-mode globals, clamping a timeout override, raising the session-transition flag and computing a float scale.

Methods: `0x00404890`

- `this+0x00000014` `short activation_flag` (read_write, DERIVED)
- `this+0x00000015` `byte activation_flag_second_byte` (write, GUESS)
- `this+0x00000020` `int mode_field` (read, GUESS)
- `this+0x00000050` `int previous_scoring_enable` (write, DERIVED)
- `this+0x00000054` `int previous_race_mode` (write, DERIVED)

### AudioStreamObject

Stream-like object constructed by 0x00406AB0 (vtable off_59E530) and destroyed by 0x00406BA0 (four intrusive linked lists torn down, vtable swapped to off_59E598), returning the AudioSystemShutdown result.

Methods: `0x00406AB0`, `0x00406BA0`

- `this+0x00000000` `void* vtable` (read_write, DERIVED)
- `this+0x00000004` `int scalar_one` (write, GUESS)
- `this+0x00000008` `void* list4_head` (read_write, DERIVED)
- `this+0x0000000C` `void* list4_node` (read_write, DERIVED)
- `this+0x00000010` `void* list4_tail` (read_write, DERIVED)
- `this+0x00000014` `int list4_count` (read_write, DERIVED)
- `this+0x00000018` `void* list3_head` (read_write, DERIVED)
- `this+0x0000001C` `void* list3_node` (read_write, DERIVED)
- `this+0x00000020` `void* list3_tail` (read_write, DERIVED)
- `this+0x00000024` `int list3_count` (read_write, DERIVED)
- `this+0x00000028` `void* list2_head` (read_write, DERIVED)
- `this+0x0000002C` `void* list2_node` (read_write, DERIVED)
- `this+0x00000030` `void* list2_tail` (read_write, DERIVED)
- `this+0x00000034` `int list2_count` (read_write, DERIVED)
- `this+0x00000038` `void* list1_head` (read_write, DERIVED)
- `this+0x0000003C` `void* list1_tail` (read_write, DERIVED)
- `this+0x00000040` `void* list1_next` (read_write, DERIVED)
- `this+0x00000044` `int list1_count` (read_write, DERIVED)
- `this+0x00000048` `int data_block_end` (write, DERIVED)
- `this+0x00000054` `int selector` (write, GUESS)
- `this+0x00000088` `float tail_float_0` (write, DERIVED)
- `this+0x0000008C` `float tail_float_1` (write, DERIVED)
- `this+0x00000090` `float tail_float_2` (write, DERIVED)
- `this+0x00000094` `float tail_float_3` (write, DERIVED)
- `this+0x00000098` `float tail_float_4` (write, DERIVED)
- `this+0x0000009C` `float tail_float_5` (write, DERIVED)

### AudioStreamSlotOwner

Manages an audio stream slot: closes the Miles stream handle at +0xC, runs slot cleanup when the index at +0x5C is live, and re-initializes a sub-struct from +0x1C.

Methods: `0x00406750`

- `this+0x0000000C` `void* stream_handle` (read_write, DERIVED)
- `this+0x0000001C` `void* sub_struct` (read, GUESS)
- `this+0x0000005C` `int slot_index` (read, DERIVED)

### KeyedListNodeObject

Teardown helper for an object living in a keyed list: releases the audio resource, unlinks the object's node, swaps the vtable (off_59E490 to off_59E4B4) and frees the child allocation at +0x4.

Methods: `0x004058A0`

- `this+0x00000000` `void* vtable` (read_write, DERIVED)
- `this+0x00000004` `void* child_allocation` (read, DERIVED)

### KeyedResourceList

Intrusive linked list keyed by integer holding file-backed resource nodes: insert-by-key (0x00407520) and lookup by integer ID or string name (0x00407E40).

Methods: `0x00407520`, `0x00407E40`

- `this+0x00000038` `void* head` (read_write, DERIVED)
- `this+0x0000003C` `void* tail` (read_write, DERIVED)
- `this+0x00000040` `void* cursor` (read_write, DERIVED)
- `this+0x00000044` `int count` (read_write, GUESS)

### KeyedObjectList

Intrusive keyed list whose nodes hold a value object: removes the first node matching the key (0x00407BE0), conditionally releasing the value object via its vtable.

Methods: `0x00407BE0`

- `this+0x00000008` `void* head` (read_write, DERIVED)
- `this+0x0000000C` `void* tail` (read_write, DERIVED)
- `this+0x00000010` `void* cursor` (read_write, DERIVED)
- `this+0x00000014` `int count` (read_write, DERIVED)

### NamedResourceList

List of named resource nodes whose ID lives at +0x5C; returns the ID of the first node whose name matches (skipping unregistered -1 nodes).

Methods: `0x00407F10`

- `this+0x00000018` `void* head` (read, GUESS)
- `this+0x00000020` `void* cursor` (read_write, DERIVED)
- `this+0x00000024` `int count` (read, GUESS)

### ManagedCleanupObject

Staged cleanup/destructor over a file handle, two heap buffers and a sub-object: conditional dual-free cleanup (0x004054A0), sub-object destructor, and optional buffer free (0x00405410).

Methods: `0x00405410`, `0x004054A0`

- `this+0x00000004` `void* heap_buffer` (read, DERIVED)
- `this+0x0000000C` `void* file_handle` (read_write, DERIVED)
- `this+0x00000018` `void* secondary_buffer` (read, DERIVED)
- `this+0x00000030` `void* sub_object` (read, GUESS)

### ReciprocalTimeController

Per-frame timing helper that resets a counter and computes a safe reciprocal into this+0x8, clamping to 1.0f on non-positive input via FloatClampWithEventDispatch.

Methods: `0x00408450`

- `this+0x00000004` `int tick_counter` (write, DERIVED)
- `this+0x00000008` `float reciprocal` (read_write, DERIVED)

### IndirectStatusByteReader

Reads a single status/flag byte at +0x14 of the object referenced by this+0x0.

Methods: `0x00404F00`

- `this+0x00000000` `void* target_pointer` (read, DERIVED)

### AudioStreamSingletonFactory

Lazily constructs the stream-object singleton at unk_5EA440 (gate byte_5EA4E0) and registers the load-path wrapper via BooleanToIntConversion; returns &unk_5EA440.

Methods: `0x00404FE0`


### CameraViewEmitter

Referenced 200-byte emitter object constructed by F_3DSoundEmitter: carries a vtable, a load/dispatch callback slot, and position fields at +0x40/+0x44 to which the session camera position is applied.

Methods: 

- `*(this+0x10)+0x00000000` `void* vtable` (read_write, DERIVED)
- `*(this+0x1C)+0x00000004` `int field_04` (read, GUESS)
- `*(this+0x10)+0x00000008` `void* dispatch_callback` (read, GUESS)
- `*(this+0x10)+0x00000040` `float position_a` (read_write, DERIVED)
- `*(this+0x10)+0x00000044` `float position_b` (read_write, DERIVED)

### KeyedListNode

Referenced node layout of the keyed lists: value/key at +0, next pointer at +4, flag byte at +8.

Methods: 

- `*(this+0x8)+0x00000000` `void* value` (read_write, DERIVED)
- `*(this+0xC)+0x00000004` `void* next` (read_write, DERIVED)

## Compatibility contracts

- **SessionRaceModeGlobalContract** — RaceModeSetup (0x00404890) must preserve the observable session-mode semantics: scoring-enable global 0x007D2E44 forced to 1, race-mode global 0x007D0410 forced to 2 with the timeout clamp from 0x007D0418/0x007D041C, session-transition flag 0x007CE24D raised via SetGlobalFlag, and the float scale at 0x007D0798 (default 0.05, preferring 0x007D07A0/0x007D07A4).
- **KeyedListNodeLayoutContract** — Intrusive list nodes carry a value/key at +0, a next pointer at +4 and a flag byte at +8; list objects maintain head/tail/cursor/count header fields at class-specific offsets (KeyedResourceList 0x38/0x3C/0x40/0x44, KeyedObjectList 0x8/0xC/0x10/0x14, NamedResourceList 0x18/0x20/0x24).
- **CameraViewEmitterSlotContract** — Camera view slots are 200-byte emitter objects: four fixed slots at +0x10/+0x14/+0x18/+0x1C and a dynamic array at +0x20 (count at +0x38) all receive the session camera position at emitter +0x40/+0x44; emitters are constructed by F_3DSoundEmitter (0x00456170) and copied via 0x00457000.
- **MilesStreamHandleContract** — The stream handle at this+0xC is closed via AIL_close_stream (pointer global 0x0059E37C) and cleared to 0; slot cleanup runs only when the slot index at this+0x5C is not -1, and the sub-struct at this+0x1C is re-initialized through the vtable dispatch/zero-fill path.

## Unresolved

- All packet owners are UnknownObject/UNKNOWN except FileResourceProcessor and StaticCameraSceneLoader (DERIVED). The class groupings (CameraViewSystem, CameraMenuController, AudioStreamObject, AudioStreamSlotOwner, KeyedResourceList, KeyedObjectList, NamedResourceList, ManagedCleanupObject, etc.) are worker synthesis at DERIVED/GUESS, not packet evidence. Equal byte offsets on distinct this-bases (e.g. this+0x10..+0x30 on CameraViewSystem vs CameraMenuController, this+0x4 on ManagedCleanupObject vs KeyedListNodeObject) are NOT merged into one class unless the shared layout is argued; common ownership is unproven.
- 0x00409770 was prelabelled FileResourceProcessor but is grouped with CameraViewSystem on a shared field layout (fixed slots +0x10..+0x1C, variable array +0x20 with count +0x38, stride 200); that union is not independently proven.
- CameraViewSystem (+0x10..+0x30 read/written as emitter pointers) and CameraMenuController (+0x10..+0x30 read as slot ids) use equal offsets with different semantics; whether they are one class or two is unresolved.
- AudioStreamObject (four list headers at +0x8..+0x44, vtable off_59E530/off_59E598) and AudioStreamSlotOwner (stream handle +0xC, sub-struct +0x1C, slot index +0x5C) interpret overlapping offsets differently; their relationship is unresolved.
- The three list-like classes (KeyedResourceList, KeyedObjectList, NamedResourceList) use different header offsets for head/tail/cursor/count; a shared template identity is GUESS, not evidenced.
- sub_588410 (0x00588410) is treated as a string comparison returning 0 on match; this is inferred from loop-break polarity, not independently evidenced.
- The vtable release argument differs between the fixed views (1) and the dynamic view array (3); the meaning of that argument is unknown.
- dword_7D0410 carries both race-mode and championship-mode labels in prior analysis; the packet cannot confirm which semantic applies.
- The float-scale semantics (flt_7D0798/flt_7D07A0/dword_7D07A4 against 0.050000001) are not established from this packet alone.
- The resource node vs data struct layouts in the lookups are not reconciled: ID at data+16 (0x00407E40) vs node ID at +0x5C (0x00407F10); the node-vs-data deref is ambiguous.
- The exact return contract of MemoryAllocationWithBufferRead (0x004080F0) is not evidenced; the success branch in 0x00407520 is entered on a zero return.
- Value-object vtables behind the list nodes (field:*(*(this+0x8)+0x0), field:*(*(this+0xC)+0x0)) and the obj+0x10/obj+0x14 status fields reference unidentified object types.
- field:this:0x00000044 is recorded as read by static facts for 0x00407E40 but no read appears in the raw body; the node-count interpretation is DERIVED from the 0x00407520 write.
- Read globals 0x0059E43C/0x0059E440 (SafeDivisionWithZeroGuard) and 0x0059E448 (RaceModeSetup) and 0x008AFE88 (Load) appear in packet facts but not in the raw decompiled source shown.
- The node flag byte at +8 (described in the raw bodies of 0x00407BE0 and 0x00406BA0) has no dedicated packet evidence ref of its own and is therefore prose-only; it is not promoted to a field.
