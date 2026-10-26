# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

Twenty-six generic runtime objects and helpers. Two nearly identical multi-phase vtable-switch destructors (0x00476100, 0x004761E0) transition the vtable through off_5A4450 (HUD layer) and off_5A443C (control base) while freeing owned children (+0x50/+0x30/+0x4 and +0x40/+0x30/+0x4), destroying the +0x3C interface-node list, and conditionally freeing self on a2 bit 0; they are grouped as UILayerObjectTearDown (GUESS). MediaBufferManagerDestructor (0x00476730) frees a +0x188 buffer, resets the vtable to off_5A4550, drains the +0xF0 buffer-reference list, zeroes +0xF0..+0xFC and chains sub_485EB0. SeasonPathMatchSearch (0x00476660) walks the +0xF0 season-scene list comparing node paths to global dword_7D0434 (fallback byte_5EA438) and stores the match index at +0x174; dispatchSceneCommandByMode (0x00477810) dispatches through global dword_7CD8C0 vtable slot +28 with command 23 when +0x180 == 24 else command 21; both are called by SeasonSceneInitialization (0x00477720) and are grouped as SeasonSceneController (GUESS). BoundsCheckWithPositionQuery (0x004773A0) guards the DualFieldRead position against +0x120/+0x124/+0x140/+0x144 ranges. HitTest (0x00479320) does a +/-20-window hit test over the +0x164 coordinate node list and writes the hit index to +0x158. SeasonDBObjectInit (0x0047A9E0) initializes a season DB object (vtable off_5A66E0, -1 sentinel fields) and is produced by the SeasonDatabaseObjectFactory (0x0047F440), which caches 1-45 per-type objects at dword index (id-1)+1607 and special-cases id 436. Return0Stub (0x0047ABB0) is a shared constant-zero provider for five flag/dispatch call sites. updateScroll (0x0047B1E0, UIComponentScroll DERIVED) is a per-frame scroll update switching on state +0x104. StateChangeNotification (0x00486660) and PropagateByteToLinkedChildren (0x004866AD) propagate UI state through subscriber/child chains using vtable slots +44/+56/+60 and StructFieldAccessor (0x00486320). The remaining functions are linked-list container helpers (destroy at +0x444/+0xE8, index lookup and unlink at +0x90, tail appends at +0xD0/+0xD8), a multi-container cleanup (0x00486080), constructors chaining ConstructorInitVTable (0x0047EFF0, 0x0047F080), a field reset (0x00486010), and small setters/stubs. All packet owners are UnknownObject except ScrollableUiList; every class here is DERIVED/GUESS synthesis.

## Function roles

- `0x00476100` **UILayerObjectTearDown** — Multi-phase destructor (thiscall): installs the DB-object vtable off_5A4464, frees the child at +0x50, destroys the +0x3C interface-node list (node vtable slot 0 called with argument 1 when the node +12 flag is set), clears list fields, transitions the vtable through off_5A4450 and off_5A443C while freeing +0x30 and +0x4, then conditionally frees self on a2 bit 0 and returns this
- `0x004761E0` **UILayerObjectTearDown** — Multi-phase destructor (thiscall): transitions the vtable through off_5A4478, off_5A4450 and off_5A443C, freeing the child pointers at +0x40, +0x30 and +0x4 in turn when non-null, then conditionally frees self on a2 bit 0 and returns this
- `0x00476660` **SeasonSceneController** — Season scene path-match search (thiscall): walks the +0xF0 list, compares each node's path string at node+0x3C against global dword_7D0434 (fallback byte_5EA438) via 0x00588410, stores the visited-node count as the match index at +0x174, and always finishes by dispatching the virtual method at vtable offset 152; invoked from SeasonSceneInitialization
- `0x00476730` **MediaBufferManager** — Media buffer manager destructor (thiscall): frees the +0x188 buffer when present, resets the vtable to off_5A4550, drains the +0xF0 buffer-reference node list (destroying each node's child object through its own vtable and freeing the node), zeroes +0xF0..+0xFC, chains the base destructor sub_485EB0, then conditionally frees self on a2 bit 0
- `0x004773A0` **RectangleBoundsChecker** — Bounds check with position query (thiscall): reads current X/Y via DualFieldRead (0x00498880), guards a2 non-null, the X range (+0x120 min, +0x124 max) and the Y range (+0x140 min, +0x144 max), then finishes with RectangleBoundsCheck (0x0048EA60); returns the logical AND of all conditions; invoked by LinkedListTraversalVirtualCall
- `0x00477810` **SeasonSceneController** — Scene command dispatch by mode (thiscall): if the discriminator at +0x180 equals 24 calls vtable slot +28 of global dword_7CD8C0 with command ID 23, otherwise with command ID 21, and returns the dispatch result; called by ShortComputation_75f0 and SeasonSceneInitialization
- `0x00479320` **CoordinateListHitTester** — UI hit test (thiscall): reads reference coordinates via DualFieldRead from the object at +0x40, walks the +0x164 coordinate-node list (cursor +0x16C), compares reference position against node coordinates offset by +0xC/+0x4 within a +/-20 window, and writes the hit node index to +0x158 (-1 on miss); called by sub_478ED0
- `0x0047A9E0` **SeasonDatabaseObject** — Season database object initializer (thiscall): chains the base constructor ShortComputation_5e30, installs vtable off_5A66E0, fills eleven DWORD fields (+0xE4..+0x100, +0x110..+0x118) with -1 sentinels, zeroes +0xE0/+0x104/+0x108/+0x10C, and returns this; called by SeasonDatabaseObjectFactory
- `0x0047ABB0` **ZeroResultStubProvider** — Parameterless constant-zero stub: returns integer 0 unconditionally with no state changes and no reads; shared as a zero-result provider by five flag/dispatch call sites
- `0x0047B1E0` **ScrollableUiList** — Per-frame scroll update (thiscall): invokes vtable slot +44, reads selection/layout references via DualFieldRead from +0x40, advances the +0x108 float accumulator, switches on scroll state +0x104 (states 1-5 via jump table 0x0047B3C0: layout recompute + bounded counter, step down/up, clamped scroll delta via 0x0047BE00, step scroll via 0x0047BB40), and always finishes with vtable slot +84 and returns its result
- `0x0047C6C0` **UiStateCleanupReceiver** — State cleanup and byte reset (thiscall): notifies state machinery via StateCleanupNotification (0x00489CB0), writes 0 to the byte field at offset 0xe0 via ByteSetterAt0xe0 (0x0048A3B0), and unconditionally returns 0
- `0x0047EFF0` **BaseInitializedObject** — Minimal object constructor (thiscall): invokes the base-object constructor ConstructorInitVTable (0x00488B00) with constants 1 and -1, writes the vtable pointer off_5A6D20 at +0x0, and returns this
- `0x0047F080` **BaseInitializedObject** — Minimal object constructor (thiscall): invokes the base-object constructor ConstructorInitVTable (0x00488B00) with constants 1 and -1, writes the vtable pointer off_5A6DC8 at +0x0, and returns this
- `0x0047F0A0` **VehicleDescriptionUiUpdater** — Load and process message buffer: reads the current vehicle description via VehicleDescriptionAccessor (0x00463C80) on global dword_7CD25C, validates it against the string table (byte_5EC4C0 / byte_5EC4CC) via BinarySearchInStringTable (0x00423A00), copies it into byte_5EC4CC when valid, drives the UI text update via UIStringComparison (0x00488B40), and falls back to byte_5EA438 on the null/empty path; returns 0 on both paths
- `0x0047F440` **SeasonDatabaseRegistry** — Season/career database object factory: validates a type id against cache bounds, returns cached/out-of-range pointers directly, allocates per-type buffers for ids 1-45, runs the matching constructor, installs per-type vtable, caches at this[(id-1)+1607] and returns; id 436 uses a 772-byte bulk-init object; on allocation failure the cache slot is zeroed and 0 returned
- `0x0047FBD0` **OwnedBufferListContainer** — Linked-list destructor (thiscall): walks the +0x444 list through node+4 next pointers, frees each node's double-indirect data buffer when the node+8 flag is set, frees every node, zeroes +0x444..+0x450, chains to LinkedListDestructor (0x0048CA50), then frees self on a2 bit 0 and returns this
- `0x004857E0` **OwnedBufferListContainerE8** — Linked-list buffer destructor (thiscall): walks the +0xE8 list through node+4 next pointers, frees each node's double-indirect data buffer when the node+12 flag is set, frees every node, zeroes +0xE8..+0xF4, chains to InitWithVTableCleanup (0x00487250), then frees self on a2 bit 0 and returns this
- `0x00486010` **StateFieldInitializer** — Field initializer (thiscall): zeroes sixteen fields (byte +0x64, byte +0x6C, dwords +0x80..+0x9C and +0xC8..+0xDC), sets the byte at +0x65 to 1, and returns 0; called by sub_485E30
- `0x00486080` **MultiContainerCleanupObject** — Multi-container cleanup (thiscall, no return value): frees four singly-linked node lists at +0xCC/+0xD0/+0xD4/+0xD8 (DualConditionalFree then FreeWrapper_7bcf, advanced via node[6]), drains a vtable-object list at +0x90 (StructFieldAccessor advance, first vtable entry invoked with argument 1, head zeroed), and frees an owned-data node list at +0x54 (data chain when the node+8 flag is set), zeroing +0x54..+0x60
- `0x00486330` **IntFieldSetter** — Trivial inline setter (thiscall): stores the integer argument a2 into this[35] (byte offset +0x8C) and returns the same value; used by sub_486340 and ObjectRegistration
- `0x004863C0` **UiListIndexAccessor** — Zero-based index lookup into the singly-linked list rooted at this+0x90: rejects negative indices, returns the head for index zero, walks node+0x8C next pointers for positive indices, and returns null on an out-of-range walk; called by UIListManagementHandler
- `0x00486400` **UiListIndexAccessor** — Linked-list node unlink (thiscall): if the head at this[36] (+0x90) is null returns 0; if the head is the target advances the head; otherwise walks node+0x8C next pointers, bypasses the removed node, zeroes its next pointer, decrements the counter at this[37] (+0x94), and returns the removed node; called by UIListManagementHandler
- `0x004864C0` **LinkedListTailAppender** — Linked-list tail append (thiscall, void): appends node a2 to the list whose head is at this+0xD0, walking node+0x18 next pointers to find the tail (or making a2 the head when the list is empty); called by sub_493480
- `0x00486540` **LinkedListTailAppender** — Linked-list tail append (thiscall, void): appends node a2 to the list whose head is at this+0xD8, walking node+0x18 next pointers to find the tail (or making a2 the head when the list is empty); called by sub_493480
- `0x00486660` **StatePropagationComponent** — UI state propagation (thiscall): stores the state byte a2 at +0x64, fires the vtable slot +44 pre-change notification (argument 1) when the value changed, then walks the subscriber linked list at +0x90 invoking each node's vtable slot +56 with a2 and advancing via StructFieldAccessor
- `0x004866AD` **ChildValuePropagator** — __userpurge UI widget value propagator: calls the virtual at vtable+44 (cdecl, argument 1), stores byte parameter a1 at this+101, then walks the child-node chain headed at this+144 invoking each node's vtable+60 virtual with a1 and advancing via StructFieldAccessor; returns the final next-pointer read (or the vtable+44 result when the chain is empty)

## Proposed classes

### UILayerObjectTearDown

Multi-phase vtable-switching teardown shared by two UI/DB object flavors: the vtable is walked through the HUD-layer vtable off_5A4450 and the control-base vtable off_5A443C (each flavor begins at its own vtable, off_5A4464 or off_5A4478), owned children are freed per phase, an interface-node linked list at +0x3C is destroyed via each node's vtable slot 0 with argument 1, and self is freed only when bit 0 of the deletion flag is set.

Methods: `0x00476100`, `0x004761E0`

- `this+0x00000000` `ptr vtable_ptr` (read_write, DERIVED)
- `this+0x00000004` `ptr owned_resource` (read_write, DERIVED)
- `this+0x00000030` `ptr child_hud_node` (read_write, GUESS)
- `this+0x0000003C` `ptr node_list_head` (read_write, DERIVED)
- `this+0x00000040` `ptr owned_child_ptr` (read_write, GUESS)
- `this+0x00000044` `dword list_bookkeeping_a` (read_write, GUESS)
- `this+0x00000048` `dword list_bookkeeping_b` (read_write, GUESS)
- `this+0x00000050` `ptr db_child_resource` (read_write, GUESS)

### MediaBufferManager

Destructor for a media buffer manager: frees the main media buffer at +0x188, resets the vtable to off_5A4550, drains a buffer-reference node list at +0xF0 (each node's child destroyed through the node's own vtable, then the node freed), zeroes the list state +0xF0..+0xFC, and chains the common base destructor sub_485EB0 before the conditional self-delete.

Methods: `0x00476730`

- `this+0x00000000` `ptr vtable_ptr` (read_write, DERIVED)
- `this+0x000000F0` `ptr buffer_ref_list_head` (read_write, DERIVED)
- `this+0x000000F4` `dword list_state_a` (read_write, GUESS)
- `this+0x000000F8` `dword list_state_b` (read_write, GUESS)
- `this+0x000000FC` `dword list_sentinel` (read_write, GUESS)
- `this+0x00000188` `ptr main_media_buffer` (read_write, DERIVED)

### SeasonSceneController

Season-scene list controller: SeasonPathMatchSearch walks the +0xF0 season-scene node list, compares node path strings (node+0x3C, fallback byte_5EA438) against the global season path dword_7D0434 (fallback byte_5EA438) via 0x00588410, stores the visited-node count as the match index at +0x174, and always finishes by dispatching vtable slot 152; dispatchSceneCommandByMode selects command 23 or 21 through global dword_7CD8C0 vtable slot +28 based on the +0x180 discriminator.

Methods: `0x00476660`, `0x00477810`

- `this+0x00000000` `ptr vtable_ptr` (read, DERIVED)
- `this+0x000000F0` `ptr season_scene_list_head` (read, DERIVED)
- `this+0x000000F8` `ptr traversal_cursor` (read_write, DERIVED)
- `this+0x00000174` `dword match_index` (write, DERIVED)
- `this+0x00000180` `dword mode_discriminator` (read, DERIVED)

### RectangleBoundsChecker

Bounds containment check: reads the current X/Y position via DualFieldRead (0x00498880) and validates it against the bounding rectangle at +0x120/+0x124 (X) and +0x140/+0x144 (Y), finishing with RectangleBoundsCheck (0x0048EA60); returns true only when every condition holds.

Methods: `0x004773A0`

- `this+0x00000120` `dword bounds_min_x` (read, GUESS)
- `this+0x00000124` `dword bounds_max_x` (read, GUESS)
- `this+0x00000140` `dword bounds_min_y` (read, GUESS)
- `this+0x00000144` `dword bounds_max_y` (read, GUESS)

### CoordinateListHitTester

UI hit test over a linked list of coordinate nodes: reads reference coordinates via DualFieldRead from the object at +0x40, walks the node list headed at +0x164 (cursor +0x16C, nodes carry a data pointer at +0 and next at +4), compares the reference position against node coordinates offset by +0xC/+0x4 within a +/-20 window, re-walks the list on a hit to compute the node index, and writes it to +0x158 (-1 on a miss).

Methods: `0x00479320`

- `this+0x00000004` `int center_offset_y` (read, GUESS)
- `this+0x0000000C` `int center_offset_x` (read, GUESS)
- `this+0x00000040` `ptr source_object` (read, DERIVED)
- `this+0x00000158` `int hit_index` (write, DERIVED)
- `this+0x00000164` `ptr node_list_head` (read_write, DERIVED)
- `this+0x0000016C` `ptr traversal_cursor` (read_write, DERIVED)

### SeasonDatabaseObject

Initializer for a season/career database object: chains the base constructor ShortComputation_5e30 (0x00485E30), installs the vtable off_5A66E0, fills eleven DWORD fields with -1 sentinels (+0xE4..+0x100 and +0x110..+0x118), and zeroes +0xE0/+0x104/+0x108/+0x10C. The sentinel semantics are not documented in the packet.

Methods: `0x0047A9E0`

- `this+0x00000000` `ptr vtable_ptr` (write, DERIVED)
- `this+0x000000E0` `dword zeroed_field_56` (write, DERIVED)
- `this+0x000000E4` `dword sentinel_field_57` (write, DERIVED)
- `this+0x000000E8` `dword sentinel_field_58` (write, DERIVED)
- `this+0x000000EC` `dword sentinel_field_59` (write, DERIVED)
- `this+0x000000F0` `dword sentinel_field_60` (write, DERIVED)
- `this+0x000000F4` `dword sentinel_field_61` (write, DERIVED)
- `this+0x000000F8` `dword sentinel_field_62` (write, DERIVED)
- `this+0x000000FC` `dword sentinel_field_63` (write, DERIVED)
- `this+0x00000100` `dword sentinel_field_64` (write, DERIVED)
- `this+0x00000104` `dword zeroed_field_65` (write, DERIVED)
- `this+0x00000108` `dword zeroed_field_66` (write, DERIVED)
- `this+0x0000010C` `dword zeroed_field_67` (write, DERIVED)
- `this+0x00000110` `dword sentinel_field_68` (write, DERIVED)
- `this+0x00000114` `dword sentinel_field_69` (write, DERIVED)
- `this+0x00000118` `dword sentinel_field_70` (write, DERIVED)

### ZeroResultStubProvider

Parameterless stub returning the integer constant 0 with no state changes and no reads; shared as a constant-zero result provider by five flag/dispatch call sites (FlagSetInit, CallFlagSet, DeferredDeactivation, FlagCheckWithConditionalPathDispatch, TextureFlagTestWithDispatch).

Methods: `0x0047ABB0`


### ScrollableUiList

Per-frame update of a scrollable UI component: invokes vtable slot +44, reads selection/layout references from the dual-field object at +0x40, advances the float accumulator +0x108, and switches on the scroll state +0x104 (states 1-5): relayout + bounded counter (0x0047B850, 0x0047BAE0), step down/up, clamped scroll delta (0x0047BE00) over +0x110/[0..+0x114], or step scroll (0x0047BB40); always ends with vtable slot +84 and returns its result.

Methods: `0x0047B1E0`

- `this+0x00000000` `ptr vtable_ptr` (read, DERIVED)
- `this+0x00000004` `int counter_min` (read, GUESS)
- `this+0x00000008` `int counter_max` (read, GUESS)
- `this+0x00000040` `ptr dual_field_source` (read, DERIVED)
- `this+0x000000E4` `dword layout_result` (write, DERIVED)
- `this+0x000000FC` `int counter_bound` (read, GUESS)
- `this+0x00000104` `dword scroll_state` (read_write, DERIVED)
- `this+0x00000108` `float accumulator` (read_write, DERIVED)
- `this+0x00000110` `float scroll_delta` (write, DERIVED)
- `this+0x00000114` `float scroll_clamp_max` (read, GUESS)
- `this+0x0000011C` `float scroll_reference` (read, GUESS)

### UiStateCleanupReceiver

Receiver of a state-cleanup notification and a byte reset: signals the state machinery via StateCleanupNotification (0x00489CB0), writes 0 to the byte at offset 0xe0 via ByteSetterAt0xe0 (0x0048A3B0), and returns 0. The offset 0xe0 is carried only by the callee's legacy name, not by field evidence in the packet.

Methods: `0x0047C6C0`


### BaseInitializedObject

Two minimal thiscall constructors that chain the shared base-object initializer ConstructorInitVTable (0x00488B00) with constant arguments 1 and -1, then install their own vtable pointer at +0x0 (off_5A6D20 or off_5A6DC8) and return this. The literal pair (1, -1) and the vtable owners are not established.

Methods: `0x0047EFF0`, `0x0047F080`

- `this+0x00000000` `ptr vtable_ptr` (write, DERIVED)

### VehicleDescriptionUiUpdater

Loads the current vehicle description through VehicleDescriptionAccessor (0x00463C80) on the module-manager global dword_7CD25C, validates it against the string table (byte_5EC4C0 / byte_5EC4CC) via BinarySearchInStringTable (0x00423A00), copies the validated description into the message buffer byte_5EC4CC, drives the UI text update through UIStringComparison (0x00488B40), and falls back to the default path string byte_5EA438 when the description is null/empty; returns 0 on both paths.

Methods: `0x0047F0A0`


### SeasonDatabaseRegistry

Season/career database object factory with per-type caching: validates a type id against the cache bounds, returns the already-cached pointer or 0 for out-of-range ids, and for ids 1-45 allocates a per-type buffer, runs the matching constructor, installs the per-type vtable, caches the result at dword index (id-1)+1607, and returns it. Id 436 uses a 772-byte bulk-init object. On allocation failure the cache slot is zeroed and 0 returned.

Methods: `0x0047F440`


### OwnedBufferListContainer

Destructor for a linked list whose head lives at +0x444: walks nodes through +4 next pointers, frees each node's double-indirect data buffer (outer pointer at node+0, inner pointer freed first) when the node+8 flag is set, frees every node, zeroes +0x444..+0x450, chains the base LinkedListDestructor (0x0048CA50), and frees self when bit 0 of a2 is set.

Methods: `0x0047FBD0`

- `this+0x00000444` `ptr list_head` (read_write, DERIVED)
- `this+0x00000448` `ptr list_next` (read, DERIVED)
- `this+0x0000044C` `dword list_state_a` (write, GUESS)
- `this+0x00000450` `dword list_state_b` (write, GUESS)

### OwnedBufferListContainerE8

Destructor for a linked list whose head lives at +0xE8: walks nodes through +4 next pointers, frees each node's double-indirect data buffer (outer pointer at node+0, inner pointer freed first) when the node+12 flag is set, frees every node, zeroes +0xE8..+0xF4, chains the common cleanup InitWithVTableCleanup (0x00487250), and frees self when bit 0 of a2 is set.

Methods: `0x004857E0`

- `this+0x000000E8` `ptr list_head` (read_write, DERIVED)
- `this+0x000000EC` `ptr list_next` (read, DERIVED)
- `this+0x000000F0` `dword list_state_a` (write, GUESS)
- `this+0x000000F4` `dword list_state_b` (write, GUESS)

### StateFieldInitializer

Field initializer that zeroes sixteen fields of the this-object (byte +0x64, byte +0x6C, dwords +0x80..+0x9C and +0xC8..+0xDC) and sets the byte at +0x65 to 1, returning 0; no reads, globals or calls. Called by sub_485E30.

Methods: `0x00486010`

- `this+0x00000064` `byte state_byte` (write, DERIVED)
- `this+0x00000065` `byte enabled_flag` (write, DERIVED)
- `this+0x0000006C` `byte control_byte` (write, DERIVED)
- `this+0x00000080` `dword zeroed_dword_a` (write, DERIVED)
- `this+0x00000084` `dword zeroed_dword_b` (write, DERIVED)
- `this+0x00000088` `dword zeroed_dword_c` (write, DERIVED)
- `this+0x0000008C` `dword zeroed_dword_d` (write, DERIVED)
- `this+0x00000090` `dword zeroed_dword_e` (write, DERIVED)
- `this+0x00000094` `dword zeroed_dword_f` (write, DERIVED)
- `this+0x00000098` `dword zeroed_dword_g` (write, DERIVED)
- `this+0x0000009C` `dword zeroed_dword_h` (write, DERIVED)
- `this+0x000000C8` `dword zeroed_dword_i` (write, DERIVED)
- `this+0x000000CC` `dword zeroed_dword_j` (write, DERIVED)
- `this+0x000000D0` `dword zeroed_dword_k` (write, DERIVED)
- `this+0x000000D4` `dword zeroed_dword_l` (write, DERIVED)
- `this+0x000000D8` `dword zeroed_dword_m` (write, DERIVED)
- `this+0x000000DC` `dword zeroed_dword_n` (write, DERIVED)

### MultiContainerCleanupObject

Destructor-style cleanup of several heterogeneous container lists on one object: walks and frees four singly-linked node lists at +0xCC/+0xD0/+0xD4/+0xD8 (each node freed with DualConditionalFree (0x0049A5A0) then FreeWrapper_7bcf, advanced via node[6]), drains a vtable-object list at +0x90 (advancing via StructFieldAccessor and invoking the first vtable entry with argument 1, then zeroing the head), and walks an owned-data node list at +0x54 (freeing data chains when the node+8 flag is set), zeroing +0x54..+0x60.

Methods: `0x00486080`

- `this+0x00000054` `ptr owned_data_list_head` (read_write, DERIVED)
- `this+0x00000058` `ptr owned_data_next` (read, DERIVED)
- `this+0x0000005C` `dword owned_data_state_a` (write, GUESS)
- `this+0x00000060` `dword owned_data_state_b` (write, GUESS)
- `this+0x00000090` `ptr vtable_object_list_head` (read_write, DERIVED)
- `this+0x000000CC` `ptr list_a_head` (read, DERIVED)
- `this+0x000000D0` `ptr list_b_head` (read, DERIVED)
- `this+0x000000D4` `ptr list_c_head` (read, DERIVED)
- `this+0x000000D8` `ptr list_d_head` (read, DERIVED)
- `this+0x000000FC` `ptr list_a_node_base` (read, GUESS)
- `this+0x00000100` `ptr list_b_node_base` (read, GUESS)
- `this+0x00000104` `ptr list_c_node_base` (read, GUESS)
- `this+0x00000108` `ptr list_d_node_base` (read, GUESS)

### IntFieldSetter

Trivial inline setter storing an integer argument into the dword field at +0x8C and returning the stored value; used by sub_486340 and ObjectRegistration.

Methods: `0x00486330`

- `this+0x0000008C` `int int_field` (write, DERIVED)

### UiListIndexAccessor

Index lookup and unlink operations on a singly-linked list rooted at this+0x90 with a node counter at +0x94 and nodes linked by a +0x8C next pointer: index lookup rejects negative indices, returns the head for index zero, and walks +0x8C next pointers; unlink bypasses a target node and decrements the counter. Both methods are called by UIListManagementHandler (0x0048A3C0).

Methods: `0x004863C0`, `0x00486400`

- `this+0x00000090` `ptr list_head` (read_write, DERIVED)
- `this+0x00000094` `dword node_count` (read_write, DERIVED)
- `this+0x0000011C` `ptr node_base` (read, GUESS)

### LinkedListTailAppender

Two tail-append methods for sibling linked lists whose heads live at +0xD0 and +0xD8: each appends a node by walking node+0x18 next pointers to the tail (or making the node the head when the list is empty). The indirect write base fields +0xE8/+0xF0 are decompiler attribution; both methods are called by sub_493480.

Methods: `0x004864C0`, `0x00486540`

- `this+0x000000D0` `ptr list_a_head` (read_write, DERIVED)
- `this+0x000000D8` `ptr list_b_head` (read_write, DERIVED)
- `this+0x000000E8` `ptr indirect_next_base_a` (read, GUESS)
- `this+0x000000F0` `ptr indirect_next_base_b` (read, GUESS)

### StatePropagationComponent

UI state propagation: stores the incoming state byte at +0x64, fires the vtable slot +44 pre-change notification (argument 1) when the new value differs, then walks the subscriber linked list at +0x90 invoking each node's vtable slot +56 with the new byte and advancing via StructFieldAccessor (0x00486320).

Methods: `0x00486660`

- `this+0x00000064` `byte state_byte` (read_write, DERIVED)
- `this+0x00000090` `ptr subscriber_list_head` (read, DERIVED)

### ChildValuePropagator

__userpurge UI widget value propagator: calls the virtual at vtable+44 (cdecl, argument 1), stores the byte parameter a1 at this+101, then walks a child-node chain headed at this+144 invoking each node's vtable+60 virtual with a1 and advancing via StructFieldAccessor, returning the final next-pointer read (or the vtable+44 result when the chain is empty).

Methods: `0x004866AD`


## Compatibility contracts

- **UiControlMultiPhaseTearDownContract** — A replacement must preserve the multi-phase teardown of 0x00476100 and 0x004761E0: the vtable pointer walks through the HUD-layer vtable off_5A4450 and the control-base vtable off_5A443C (from initial vtables off_5A4464 / off_5A4478), owned children are freed in phase order (+0x50/+0x30/+0x4 for one flavor, +0x40/+0x30/+0x4 for the other), the +0x3C interface-node list is destroyed by calling each node's vtable slot 0 with argument 1 when its +12 flag is set and its vtable is non-null, list fields +0x3C/+0x40/+0x44/+0x48 are cleared, and self is freed through FreeWrapper_7bcf only when bit 0 of the deletion flag is set; the this pointer is returned.
- **MediaBufferManagerDestructorContract** — A replacement must preserve the media buffer manager teardown of 0x00476730: the +0x188 main buffer is freed only when non-null, the vtable resets to off_5A4550, the +0xF0 buffer-reference list is drained (each node's child object destroyed through the node's own vtable when the node+12 flag is set and node value is non-null, then the node freed), the list state +0xF0..+0xFC is zeroed, the base destructor sub_485EB0 runs, and self is freed only when bit 0 of a2 is set.
- **SeasonPathMatchContract** — A replacement must preserve the season-scene path search of 0x00476660: the list at +0xF0 is walked comparing each node's path string at node+0x3C (fallback byte_5EA438) against the season path global dword_7D0434 (fallback byte_5EA438) using 0x00588410 (0 == equality), the visited-node count is stored as the match index at +0x174, and the virtual method at vtable slot 152 is always dispatched at the end.
- **SceneCommandDispatchContract** — A replacement must preserve the mode-dependent dispatch of 0x00477810: when the discriminator at +0x180 equals 24, vtable slot +28 of global dword_7CD8C0 is called with command ID 23; otherwise the same slot is called with command ID 21; the dispatch result is returned.
- **SeasonDatabaseFactoryContract** — A replacement must preserve the factory semantics of 0x0047F440: ids 1-45 allocate a per-type buffer, run the matching constructor, install the per-type vtable and cache the result at dword index (id-1)+1607; repeat or out-of-range ids return the cached/zero pointer without rebuilding; id 436 allocates a 772-byte bulk-init object via 0x00470230; allocation failure zeroes the cache slot and returns 0; id 1 (track database) initializes the string-buffer state and copies the filename literal (global 0x005BF970).
- **UiHitTestContract** — A replacement must preserve the hit-test reporting of 0x00479320: reference coordinates are read via DualFieldRead from the object at +0x40, the +0x164 coordinate-node list is walked (cursor +0x16C), a hit requires the reference position to lie within +/-20 of the node center (node coordinates plus this+0xC/this+0x4), and on a hit the list is re-walked to compute the node index written to +0x158 (-1 on a miss).
- **ScrollableListUpdateContract** — A replacement must preserve the per-frame scroll update of 0x0047B1E0: vtable slot +44 is invoked before and vtable slot +84 after the scroll-state dispatch on +0x104, the +0x108 float accumulator advances per frame, and scroll states 1-5 drive layout recompute plus bounded counter movement (0x0047B850, 0x0047BAE0), step down/up, a clamped scroll delta (0x0047BE00 over +0x110 clamped to [0,+0x114]), or step scroll (0x0047BB40); the final vtable slot +84 result is returned.
- **UiStatePropagationContract** — A replacement must preserve the state propagation of 0x00486660: the incoming state byte is stored at +0x64, the vtable slot +44 pre-change notification fires with argument 1 when the byte changed, and every subscriber in the +0x90 linked list is notified through its vtable slot +56 with the new byte, advancing via StructFieldAccessor.

## Unresolved

- All packet owners are UnknownObject except ScrollableUiList (DERIVED); every class here is GUESS synthesis and must not be treated as confirmed source structure.
- The three vtables off_5A4464/off_5A4450/off_5A443C (and off_5A4478, off_5A4550, off_5A66E0, off_5A6D20, off_5A6DC8) are not tied to confirmed classes; their corpus identities are DERIVED at best.
- The grouping of 0x00476100 and 0x004761E0 into UILayerObjectTearDown rests on the shared vtable chain off_5A4450 -> off_5A443C and the shared +0x4 owned resource; 0x00476730 is kept separate because it chains sub_485EB0 and owns a different list (+0xF0).
- The virtual destructor invoked through each node's vtable in 0x00476100/0x00476730 is an indirect call; the concrete node class is unknown.
- The a2 deletion-mode flag (bit 0 controls freeing self) has an unknown caller contract; 0x00476100 has no static callers.
- The node layouts inside the +0x3C, +0x90, +0xE8, +0xF0, +0x164, +0x444, +0x54 lists (data/value pointer at +0, next at +4 / +0x8C / +0x18, flag byte at node+8 or node+12) are decompiler field attribution, not confirmed structs.
- 0x00476730's deterministic guard records the this+0xFC == 0 test as the walk guard while the raw source keys the loop on the head pointer this+0xF0; the sentinel-versus-head role is not fully resolvable from this packet.
- The +0xE8/+0xF0 indirect write bases in 0x004864C0/0x00486540 are not visible in the raw source (which addresses the tail node directly via a local), so the identity of those base fields is unevidenced.
- The semantics of the -1 sentinel fields and zeroed fields of the SeasonDatabaseObject are not documented; the cache slot base index 1607 (dword index) and its backing allocation are not independently confirmed.
- dword_7CD8C0 is proposed as a game-command dispatch interface elsewhere; the interface type and command IDs 21/23 are not established by this function alone.
- The owning object type and the +0xe0 byte-reset semantics of 0x0047C6C0 are unknown; the offset is carried only by the callee's legacy name.
- The +/-20 hit-tolerance window, the +/-0.125/0.25 accumulator decrement constants (possibly backed by read-only globals flt_59E4E0 / flt_59E7F8), and the scroll-state meaning at +0x104 are inferred from literals, not confirmed by named fields.
- 0x004866AD's third parameter a3 is present in the signature but unused in the decompiled body.
- The 0x00486080 caller relationship to sub_485EB0 is stated in the summary but not present in the packet's evidence refs; the sub_485EB0 edge is evidenced only through MediaBufferManagerDestructor.
- Id 4 in 0x0047F440 jumps out of line to a block whose logic is not present in this function.
- The DoubleIndirectFreeContract for 0x0047FBD0/0x004857E0 assumes the flag byte at node+8/node+12 gates a double-indirect buffer; the purpose of that buffering and of the extra header fields is unconfirmed.
