# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `GUESS`

Reconstruction of generic runtime objects from 20 validated function IR records. The packet supplies three DERIVED owners (F3DBufferMesh for 0x00403350, AudioProcessingConfig for 0x004057F0, ChildContainer for 0x00408520); everything else is labeled UNKNOWN and is proposed here as GUESS-level classes. Four functions (0x00407C90, 0x00407FB0, 0x00408000, 0x00408050) share the same container layout (list head at this+0x18, cursor this+0x20, count this+0x24, 12-byte nodes with value at +0, next at +4, ownership flag at +8, node-data ID at +0x5C) and are grouped as one LinkedListContainer. 0x00404AC0 shows an identical node record shape (value/+0, next/+4, flag/+8) under a different container base (list head at obj+0x40) and is kept as a separate RenderNodeList because equal offsets on different bases are not merged. 0x004084B0 is attributed to ChildContainer because it installs the same vtable off_59E60C and zeroes the same child-slot range this+0x10..0x30 that 0x00408520 reads; that membership is a GUESS synthesis flagged in unresolved. Audio, mutex, and camera functions each form single-class clusters with per-class field tables. Free functions 0x00409950/0x004099E0 form the ViewModeControl interface (mutually exclusive toggle of global flag bit 32 and bit 0x8000 of the dword_8AFE88 object).

## Function roles

- `0x00403350` **F3DBufferMesh** — (Re)allocates the three 28-byte-record mesh buffers from dimension fields this+0x15C/0x160/0x164/0x168, frees prior allocations via FreeWrapper, and sets the allocated marker at this+0x8 and layout offsets at this+0xC/0x10/0x14.
- `0x00403540` **IndexRemappingOwner** — Remaps array-index parent/child/sibling references into direct 316-byte-stride pointers over a sub-object array (count at this+0x130, array base this+0x134), resetting invalid indices to -1 and zeroing the matching pointers.
- `0x00404AC0` **RenderNodeList** — Destructor of a render-node list container: walks the singly-linked node list at obj+0x40, conditionally releases node data (via ConditionalFreeWithBit0Flag(1) when the node+8 flag and node+0 data are set), frees each node, zeroes the four list fields obj+0x40..0x4C, frees three auxiliary buffers, then frees the object.
- `0x00405440` **CameraViewStruct** — __thiscall default initializer for a camera/view struct: seeds sentinel -1 fields, copies the default directory path via StringCopyWithBufferRealloc, zeroes most dword fields, runs VirtualCleanup on the sub-object at this+0x30, memset-zeroes 44 bytes from index 17, clears the byte at this+0x70 and returns 0.
- `0x004057F0` **AudioProcessingConfig** — Audio processing configuration constructor: installs the vtable off_59E490, zeroes the counter at +0x4, seeds sentinel +0x8, copies a path string (default fallback byte_5EA438) and two config dwords, stores three caller params, writes audio factors 0.01f/0.975f/0.5f and sample rate 44100.0f, zeroes state fields and seeds the terminal sentinel +0x60; returns this.
- `0x00406130` **MutexSynchronizationObject** — Constructor/initializer of a mutex synchronization object with two-phase setup: three 20-byte file-path slot entries from this+0x10 (StringCopyWithBufferRealloc of byte_5EA438), CreateMutexA into this+0x50, vtable switch off_59E50C to off_59E4EC, timeout 1.0f at +0x4, config param at +0x8, three more slot entries from this+0x1C, and optional MutexLockWithTimeout(0) when the created flag at +0x58 is set; returns this.
- `0x00406790` **AudioStreamSlot** — Opens a Miles audio stream for an audio-stream slot and starts playback: two modes keyed on the byte at this+0x20 (data-driven MP3-filename open vs path-based track update), AIL_open_stream into this+0xC, then either register/start/volume success path (mutex entry via MutexLockWithTimeout(this,2)) or a three-slot reset failure path.
- `0x00406CC0` **AudioDriver** — Initializes the Miles digital audio driver: vtable init dispatch, callback registration, AIL_startup/AIL_set_preference, sample-rate selection from this+0x54 (0->11025, 1->22050, else 44100), AIL_open_digital_driver into this+0x90; on success stores handle, dispatches *this+52, zeroes nine state fields this+0x58..0x84, installs file callbacks, sets this+0x88=1 and returns 0; on failure clears the handle and flag and returns 1.
- `0x00407C90` **LinkedListContainer** — Removes from the singly linked list the node whose value equals a2, then releases the removed value through its vtable (with argument 1) and frees the node; updates head/tail/cursor at this+0x18/0x1C/0x20 and decrements the count at this+0x24.
- `0x00407EF0` **BitfieldFlagStruct** — Side-effect-free getter: reads the unsigned byte at offset 27 (0x1B) of the caller-supplied structure, extracts bit 5 (shift right 4, mask 2), returns 0 or 2.
- `0x00407FB0` **LinkedListContainer** — __thiscall boolean linked-list lookup: walks from head this+0x18 via cursor this+0x20 comparing each node-data ID (data+0x5C) to a2; returns 1 on match, 0 for a2==-1, empty list, or end-of-list. Legacy ABI label Linked_List_Search_by_ID.
- `0x00408000` **LinkedListContainer** — List traversal searching for a node whose data ID (data+0x5C) equals a2; on match invokes sub_406A70 with the matched data object. Returns silently for a2==-1, empty list, or no match.
- `0x00408050` **LinkedListContainer** — ID-based linked-list node search returning 1 and running ShortComputation_6a90 (0x00406A90) with output parameters a3/a4 on match; returns 0 otherwise. Called from MemoryAllocation_5160.
- `0x004083E0` **ResetStructFlagObject** — Struct reset routine: captures the byte flag at this+0x15, zeroes dwords 0x0/0x4/0xC/0x10, sets 0x8 to 1.0f, zeroes the byte at 0x14, calls ConditionalBranchByFlag(1) as a deactivation notification when the flag was previously active, then clears the flag at 0x15.
- `0x004084B0` **ChildContainer** — Straight-line object constructor: installs the vtable off_59E60C at this+0x0, zeroes this+0x4..0x30 and this+0x38..0x4C, sets the sentinel this+0x34 to -1 and this+0x50 to 2; returns this. Attributed to ChildContainer because it installs the same vtable off_59E60C and zeroes the same child-slot range this+0x10..0x30 that NotifyChildrenTeardown reads (GUESS merge).
- `0x00408520` **ChildContainer** — Container notify-and-teardown sequence: switches the container vtable to off_59E60C, dispatches each non-null child's vtable-slot-0 method with argument 1 (argument 3 for the child at this+0x20), switches the container vtable to off_59E634, and returns the last dispatch result. Invoked by ConditionalFreeByFlag (00408500).
- `0x00408740` **FloatKeyedParamObject** — Switch-based field selector keyed on the float argument bit pattern: nine cases select a dword field from this+0x10..0x30 (case 4 adds 200 * this+0x3C); when the selected value and enable flag this+0x4 are both non-zero it extracts two float components, converts degrees to radians with flt_59E65C, runs sub_542050 and stores the key back into this+0x34.
- `0x00409950` **ViewModeControl** — View-mode enable callback: sets global flag bit 32 via GlobalFlagSetClear(32, 1) and clears bit 0x8000 in the dword at offset 236 of the object at dword_8AFE88; returns the GlobalFlagSetClear result.
- `0x004099E0` **ViewModeControl** — View-mode disable callback, inverse of the enable pair: clears global flag bit 32 via GlobalFlagSetClear(32, 0) and sets bit 0x8000 at (dword_8AFE88 + 236); returns the GlobalFlagSetClear result.
- `0x00409A00` **CameraViewportController** — Per-frame camera/viewport update: early-returns when the context at this+0x4 is null, sets camera-update flag bit 4096, dispatches on the mode selector at this+0x34 (cases 0-8 + default) to select a per-mode camera sub-object, runs the 3D transform into viewport position/orientation, applies mirror/Euler adjustments, invokes the sub-object update, feeds position/orientation into utility calls, applies a negated chassis transform on flag, and returns a conditional float setter result.

## Proposed classes

### F3DBufferMesh

3D buffer mesh object owning three 28-byte-record allocation buffers (index, stream, batch) and the dimension/layout fields that size them. Single packet method performs (re)allocation with free-before-alloc.

Methods: `0x00403350`

- `this+0x00000008` `int allocated_marker` (write, DERIVED)
- `this+0x0000000C` `int layout_offset_vertices` (write, DERIVED)
- `this+0x00000010` `int layout_offset_indices` (write, DERIVED)
- `this+0x00000014` `int layout_offset_batches` (write, DERIVED)
- `this+0x00000150` `pointer index_buffer` (read_write, DERIVED)
- `this+0x00000154` `pointer stream_buffer` (read_write, DERIVED)
- `this+0x00000158` `pointer batch_buffer` (read_write, DERIVED)
- `this+0x0000015C` `unsigned int vertex_count` (read, DERIVED)
- `this+0x00000160` `unsigned int index_count` (read, DERIVED)
- `this+0x00000164` `unsigned int batch_count` (read, DERIVED)
- `this+0x00000168` `unsigned int sub_batch_multiplier` (read, DERIVED)

### AudioProcessingConfig

Audio processing configuration object (Miles Sound System cluster per corpus prose): constructor installs the vtable off_59E490, copies path/config inputs from the caller record, and initializes audio factor, sample-rate, sentinel and state fields.

Methods: `0x004057F0`

- `this+0x00000000` `pointer vtable_ptr` (write, DERIVED)
- `this+0x00000004` `int counter` (write, DERIVED)
- `this+0x00000008` `int sentinel` (write, DERIVED)
- `this+0x0000000C` `int config_dword_a` (write, DERIVED)
- `this+0x00000010` `int config_dword_b` (write, DERIVED)
- `this+0x00000014` `int caller_param_a` (write, DERIVED)
- `this+0x00000018` `int caller_param_b` (write, DERIVED)
- `this+0x0000001C` `float gain_float` (write, DERIVED)
- `this+0x00000020` `float decay_float` (write, DERIVED)
- `this+0x00000024` `float pan_float` (write, DERIVED)
- `this+0x00000044` `float sample_rate` (write, DERIVED)
- `this+0x0000004C` `int state_field` (write, DERIVED)
- `this+0x00000054` `int caller_param_c` (write, DERIVED)
- `this+0x00000058` `int state_field` (write, DERIVED)
- `this+0x0000005C` `int state_field` (write, DERIVED)
- `this+0x00000060` `int terminal_sentinel` (write, DERIVED)
- `this+0x00000064` `int state_field` (write, DERIVED)
- `this+0x00000068` `int state_field` (write, DERIVED)

### ChildContainer

Container owning nine child pointers (this+0x10..0x30) and two vtable states (off_59E60C then off_59E634). NotifyChildrenTeardown dispatches a vtable-slot-0 method on each child before disposal; the constructor membership (0x004084B0) is a GUESS merge based on the shared off_59E60C vtable and the overlapping zeroed child range.

Methods: `0x00408520`, `0x004084B0`

- `this+0x00000000` `pointer vtable_ptr` (write, DERIVED)
- `this+0x00000010` `pointer child_0` (read_write, DERIVED)
- `this+0x00000014` `pointer child_1` (read_write, DERIVED)
- `this+0x00000018` `pointer child_2` (read_write, DERIVED)
- `this+0x0000001C` `pointer child_3` (read_write, DERIVED)
- `this+0x00000020` `pointer child_4` (read_write, DERIVED)
- `this+0x00000024` `pointer child_5` (read_write, DERIVED)
- `this+0x00000028` `pointer child_6` (read_write, DERIVED)
- `this+0x0000002C` `pointer child_7` (read_write, DERIVED)
- `this+0x00000030` `pointer child_8` (read_write, DERIVED)
- `this+0x00000034` `int sentinel` (write, GUESS)
- `this+0x00000050` `int count_or_enum` (write, GUESS)

### LinkedListNode

12-byte singly-linked list node record: value pointer at +0, next pointer at +4, ownership flag byte at +8. Layout established by 0x00407C90 (explicit node record) and confirmed by the traversal arithmetic of 0x00407FB0/0x00408000/0x00408050 and the identical record shape used by RenderNodeList at 0x00404AC0.

Methods: 

- `*(obj+0x40)+0x00000000` `pointer value_ptr` (read, GUESS)
- `*(*(obj+0x40)+0x4)+0x00000004` `pointer next_ptr` (read_write, GUESS)
- `*(obj+0x40)+0x00000008` `byte ownership_flag` (read, GUESS)

### LinkedListContainer

Singly-linked list container with head at this+0x18, tail at this+0x1C, traversal cursor at this+0x20 and node count at this+0x24; nodes are 12-byte LinkedListNode records whose data objects carry an ID at +0x5C. Provides ID search (0x00407FB0), ID traversal with dispatch (0x00408000), ID lookup with output (0x00408050) and node removal with vtable release (0x00407C90).

Methods: `0x00407C90`, `0x00407FB0`, `0x00408000`, `0x00408050`

- `this+0x00000018` `pointer list_head` (read_write, GUESS)
- `this+0x0000001C` `pointer list_tail` (read_write, GUESS)
- `this+0x00000020` `pointer traversal_cursor` (read_write, GUESS)
- `this+0x00000024` `int node_count` (read, GUESS)

### LinkedListDataRecord

Data object stored as a node value (node+0) whose ID field at +0x5C is the lookup key used by the linked-list search functions. The concrete record type is unknown.

Methods: 

- `*(this+0x20)+0x0000005C` `int id` (read, GUESS)

### RenderNodeList

Render-node list container (render subsystem per packet prose) destroyed by 0x00404AC0: singly-linked node list at obj+0x40 (12-byte LinkedListNode records), three auxiliary buffers at obj+0x28/0x30/0x38, and four list fields obj+0x40..0x4C zeroed on teardown. Uses the same node record shape as LinkedListContainer but under a different base, so kept separate.

Methods: `0x00404AC0`

- `obj+0x00000028` `pointer aux_buffer` (read, GUESS)
- `obj+0x00000030` `pointer aux_buffer` (read, GUESS)
- `obj+0x00000038` `pointer aux_buffer` (read, GUESS)
- `obj+0x00000040` `pointer node_list_head` (read_write, GUESS)
- `obj+0x00000044` `pointer list_field` (read_write, GUESS)
- `obj+0x00000048` `pointer list_field` (read_write, GUESS)
- `obj+0x0000004C` `pointer list_field` (read_write, GUESS)

### MutexSynchronizationObject

Mutex/thread synchronization object with a two-phase constructor: file-mutex vtable off_59E50C with three 20-byte path slot entries from this+0x10, OS mutex creation (CreateMutexA into this+0x50, created flag at this+0x58), switch to the thread-object vtable off_59E4EC, then three more slot entries from this+0x1C and optional MutexLockWithTimeout(0).

Methods: `0x00406130`

- `this+0x00000000` `pointer vtable_ptr` (write, GUESS)
- `this+0x00000004` `float timeout_float` (write, GUESS)
- `this+0x00000008` `int config_param` (write, GUESS)
- `this+0x00000010` `byte[20] slot_entry_region_first` (write, GUESS)
- `this+0x00000050` `pointer mutex_handle` (write, GUESS)
- `this+0x00000054` `int handle_state` (write, GUESS)
- `this+0x00000058` `byte mutex_created_flag` (write, GUESS)
- `this+0x0000005C` `int trailing_sentinel` (write, GUESS)

### AudioStreamSlot

Miles audio-stream slot: stores the driver object, stream handle, path, deserialization sub-struct, track/mode/slot indices and a volume float; opens and starts a stream via AIL and resets its three 20-byte slot groups on open failure.

Methods: `0x00406790`

- `this+0x00000004` `float volume_float` (read, GUESS)
- `this+0x00000008` `pointer driver_object` (read, GUESS)
- `this+0x0000000C` `pointer stream_handle` (write, GUESS)
- `this+0x00000010` `pointer path_ptr` (read, GUESS)
- `this+0x00000018` `pointer deserialize_substruct` (read, GUESS)
- `this+0x0000001C` `int track_index` (read, GUESS)
- `this+0x00000020` `byte mode_byte` (read, GUESS)
- `this+0x0000005C` `int slot_index` (read, GUESS)

### AudioDriver

Miles digital audio driver object: vtable-dispatched init, sample-rate selector at this+0x54, driver handle at this+0x90, initialized flag at this+0x88, and nine zeroed state fields this+0x58..0x84 on success.

Methods: `0x00406CC0`

- `this+0x00000054` `int sample_rate_selector` (read, GUESS)
- `this+0x00000058` `int state_field` (write, GUESS)
- `this+0x0000005C` `int state_field` (write, GUESS)
- `this+0x00000060` `int state_field` (write, GUESS)
- `this+0x00000070` `int state_field` (write, GUESS)
- `this+0x00000074` `int state_field` (write, GUESS)
- `this+0x00000078` `int state_field` (write, GUESS)
- `this+0x0000007C` `int state_field` (write, GUESS)
- `this+0x00000080` `int state_field` (write, GUESS)
- `this+0x00000084` `int state_field` (write, GUESS)
- `this+0x00000088` `int initialized_flag` (write, GUESS)
- `this+0x00000090` `pointer driver_handle` (write, GUESS)

### IndexRemappingOwner

Object owning a sub-object array (base this+0x134, count this+0x130) whose 316-byte-stride entries carry parent/child/sibling index-pointer pairs; 0x00403540 remaps valid indices into direct pointers and resets invalid ones.

Methods: `0x00403540`

- `this+0x00000130` `int element_count` (read, GUESS)
- `this+0x00000134` `pointer sub_object_array_base` (read, GUESS)

### CameraViewStruct

Camera/view struct whose default initializer (0x00405440) seeds sentinel -1 fields, copies a default directory path, cleans up the sub-object at this+0x30 via VirtualCleanup, and zeroes most of the trailing block. The concrete camera class is unknown.

Methods: `0x00405440`

- `this+0x00000000` `int sentinel_id` (write, GUESS)
- `this+0x0000000C` `int init_zero_field` (write, GUESS)
- `this+0x00000010` `int sentinel_field` (write, GUESS)
- `this+0x00000014` `int init_zero_field` (write, GUESS)
- `this+0x00000018` `int init_zero_field` (write, GUESS)
- `this+0x0000001C` `int sentinel_field` (write, GUESS)
- `this+0x00000020` `int init_zero_field` (write, GUESS)
- `this+0x00000024` `int init_zero_field` (write, GUESS)
- `this+0x00000028` `int init_zero_field` (write, GUESS)
- `this+0x0000002C` `int init_zero_field` (write, GUESS)
- `this+0x00000030` `pointer sub_object` (write, GUESS)
- `this+0x00000038` `int init_zero_field` (write, GUESS)
- `this+0x00000070` `byte trailing_flag_byte` (write, GUESS)

### FloatKeyedParamObject

Object exposing a set of selectable dword fields keyed on a float argument bit pattern; selection is gated by the enable flag at this+0x4, and case 4 scales the field at this+0x20 by 200 * this+0x3C. The camera-shake interpretation of the degrees-to-radians conversion is DERIVED prose only.

Methods: `0x00408740`

- `this+0x00000004` `int enable_flag` (read, GUESS)
- `this+0x00000010` `int selectable_field` (read, GUESS)
- `this+0x00000014` `int selectable_field` (read, GUESS)
- `this+0x00000018` `int selectable_field` (read, GUESS)
- `this+0x0000001C` `int selectable_field` (read, GUESS)
- `this+0x00000020` `int scaled_field` (read, GUESS)
- `this+0x00000024` `int selectable_field` (read, GUESS)
- `this+0x00000028` `int selectable_field` (read, GUESS)
- `this+0x0000002C` `int selectable_field` (read, GUESS)
- `this+0x00000030` `int selectable_field` (read, GUESS)
- `this+0x00000034` `float stored_key` (write, GUESS)
- `this+0x0000003C` `int scale_factor` (read, GUESS)

### ResetStructFlagObject

Struct with an activity flag byte at this+0x15 and a 1.0f float at this+0x8; the reset routine (0x004083E0) zeroes its fields and emits a ConditionalBranchByFlag(1) deactivation notification when the flag was previously active.

Methods: `0x004083E0`

- `this+0x00000000` `int reset_zero_field` (write, GUESS)
- `this+0x00000004` `int reset_zero_field` (write, GUESS)
- `this+0x00000008` `float active_float` (write, GUESS)
- `this+0x0000000C` `int reset_zero_field` (write, GUESS)
- `this+0x00000010` `int reset_zero_field` (write, GUESS)
- `this+0x00000014` `byte byte_flag` (write, GUESS)
- `this+0x00000015` `byte active_flag` (read_write, GUESS)

### CameraViewportController

Per-frame camera/viewport controller: mode selector at this+0x34 picks one of up to nine camera sub-object pointers (this+0x10..0x30), the primary context at this+0x4 gates the update, and mirror/Euler/mode-7/8 offset adjustments modify the resulting viewport transform.

Methods: `0x00409A00`

- `this+0x00000004` `pointer primary_context_ptr` (read, GUESS)
- `this+0x00000010` `pointer camera_sub_object` (read, GUESS)
- `this+0x00000014` `pointer camera_sub_object` (read, GUESS)
- `this+0x00000018` `pointer camera_sub_object` (read, GUESS)
- `this+0x0000001C` `pointer camera_sub_object` (read, GUESS)
- `this+0x00000020` `pointer camera_sub_object` (read, GUESS)
- `this+0x00000024` `pointer camera_sub_object` (read, GUESS)
- `this+0x00000028` `pointer camera_sub_object` (read, GUESS)
- `this+0x0000002C` `pointer camera_sub_object` (read, GUESS)
- `this+0x00000030` `pointer camera_sub_object` (read, GUESS)
- `this+0x00000034` `int mode_selector` (read, GUESS)
- `this+0x0000003C` `int mode4_scale` (read, GUESS)
- `this+0x00000040` `int mirror_flag` (read, GUESS)
- `this+0x00000044` `float euler_adjust` (read, GUESS)
- `this+0x00000048` `float euler_adjust` (read, GUESS)
- `this+0x0000004C` `float euler_adjust` (read, GUESS)
- `*(this+0x1C)+0x00000000` `pointer vtable_ptr` (read, GUESS)
- `*(this+0x1C)+0x0000000C` `float position_x` (write, GUESS)
- `*(this+0x1C)+0x00000010` `float position_y` (write, GUESS)
- `*(this+0x1C)+0x00000014` `float position_z` (write, GUESS)
- `*(this+0x1C)+0x00000018` `float orientation_component` (write, GUESS)
- `*(this+0x1C)+0x0000001C` `float orientation_component` (write, GUESS)
- `*(this+0x1C)+0x00000020` `float orientation_component` (write, GUESS)
- `*(this+0x1C)+0x00000048` `float conditional_float` (read, GUESS)
- `*(this+0x1C)+0x000000A0` `float angle_field` (read_write, GUESS)
- `*(this+0x1C)+0x000000A4` `float copied_component` (write, GUESS)
- `*(this+0x1C)+0x000000A8` `float copied_component` (write, GUESS)
- `*(this+0x2C)+0x000000BC` `float y_offset_component` (read, GUESS)
- `*(this+0x2C)+0x000000C0` `float y_offset` (read_write, GUESS)
- `*(this+0x30)+0x000000C4` `float y_offset_component` (write, GUESS)

### BitfieldFlagStruct

Caller-supplied structure with a bit-field byte at offset 0x1B whose bit 5 is extracted by the getter 0x00407EF0. The structure type and the meaning of the bit are caller-specific and unknown.

Methods: `0x00407EF0`

- `this+0x0000001B` `byte bitfield_byte` (read, GUESS)

## Compatibility contracts

- **F3DBufferMeshAllocationLayout** — A replacement must keep the three 28-byte-record mesh buffers at this+0x150 (index, 28 * indexCount), this+0x154 (stream, 28 * batchCount) and this+0x158 (batch, 28 * batchCount * subBatchMultiplier), sized from the dimension fields this+0x15C/0x160/0x164/0x168, with the allocated marker at this+0x8 set to 1 and layout offsets written to this+0xC/0x10/0x14; existing allocations are freed via 0x00587BCF before reallocation.
- **LinkedListNodeRecordLayout** — Singly-linked list nodes are 12-byte records with the value/data pointer at +0, next pointer at +4 and an ownership flag byte at +8; list containers keep head at this+0x18, tail at this+0x1C, traversal cursor at this+0x20 and count at this+0x24; ID-based lookup reads the node-data ID field at +0x5C and treats -1 as the no-search sentinel.
- **MutexSynchronizationObjectContract** — The mutex object installs the file-mutex vtable off_59E50C before OS mutex creation (CreateMutexA with a SECURITY_ATTRIBUTES block), stores the resulting handle at this+0x50 with the created flag byte at this+0x58, switches to the thread-object vtable off_59E4EC, and sets a 1.0f lock timeout at this+0x4; locking is entered through MutexLockWithTimeout (0x00406700).
- **AudioDriverHandleContract** — The digital audio driver open flow must keep the sample-rate selector at this+0x54 (0 -> 11025, 1 -> 22050, otherwise 44100), store the AIL driver handle at this+0x90, clear nine state fields this+0x58..0x84 on success, install file callbacks (0x00405050 plus three literal addresses), and maintain the initialized flag at this+0x88 (1 success / 0 failure).
- **AudioStreamOpenContract** — The audio-stream slot open flow must read the driver object at this+0x8 (handle at driver+0x90), the requested path at this+0x10, the mode byte at this+0x20 (0 = first-time data-driven open, non-zero = track update), the track index at this+0x1C and slot index at this+0x5C, store the AIL stream handle at this+0xC, set left/right volume from the float at this+0x4, and reset the three 20-byte slot groups on open failure.
- **CameraViewportUpdateContract** — The per-frame camera update must gate on the context pointer at this+0x4, dispatch on the mode selector at this+0x34 to select one of the camera sub-object pointers at this+0x10..0x30, copy the rendered viewport triple from dword_7C54E0 + 88/92/96, clamp the mode-3 angle at sub-object +0xA0 into [-2.95, -0.050000001], apply the mirror flag at this+0x40 and Euler adjustments at this+0x44/0x48/0x4C, apply a negated chassis transform when the flag at context+0x1B0 is set, and sequence the mode-7/8 Y offset through dword_5BE900 with flt_5BE8FC.
- **ViewModeFlagPairContract** — The enable/disable view-mode callbacks are a mutually exclusive pair: enable sets global flag bit 32 and clears bit 0x8000 at (dword_8AFE88 + 236); disable clears flag bit 32 and sets bit 0x8000. A replacement must keep these two operations exact inverses of each other.
- **ContainerTeardownContract** — Container and list teardown must dispatch a virtual method on each live child/owned object (vtable slot 0, argument 1; argument 3 for the child at this+0x20), free node data only when the node ownership flag byte is set and the data pointer is non-null, and release list values through their vtable before freeing nodes.

## Unresolved

- 0x00403540 (IndexRemappingWithStride): the parent/child/sibling meanings of the remapped links are a DERIVED reading; the concrete 316-byte sub-object type is unknown; why invalid indices are reset to -1 while the pointer is zeroed is unexplained.
- 0x00404AC0 (RenderNodeListDestructor): ConditionalFreeWithBit0Flag is called with literal 1 so the freed allocation is not identified here; obj+0x44/0x48/0x4C roles (tail/count/parallel arrays) are not established; result is uninitialized when *this is null.
- 0x00405440 (CameraViewStructInitializer): the destination buffer of StringCopyWithBufferRealloc is not evident; the -1 sentinel fields (0x0/0x10/0x1C) vs zeroed fields are inferred only from init literals.
- 0x004057F0 (AudioProcessingConfigInit): meanings of a3/a4/a5 and the two copied dwords depend on the caller config record at 0x00407810; the vtable object off_59E490 identity is DERIVED (Miles) not resolved here.
- 0x00406130 (MutexSynchronizationObjectInit): the three consecutive byte-store globals 0xFF00000000005450/451/452 are an extractor rendering of the entry byte-flag clears against an unknown base; the class identity and meaning of a2 come from caller 0x004078A0 (not in the allowed refs) and are unverified.
- 0x00406790 (OpenAndStartAudioStream): format constant contents (aSD_1/aSDDMp3) are inferred from decompiled format arguments; the field at this+0x5C as slot index is DERIVED; only the first 20-byte slot write site is named by the field table.
- 0x00406CC0 (AudioDriverInit): the three literal AIL_set_file_callbacks addresses (4215040/4215136/4215424) have no named refs; the nine zeroed state fields and flag this+0x88 semantics are not established; the vtable methods at *this+12 and *this+52 are unnamed.
- 0x00407C90 (LinkedListNodeRemovalWithVTableRelease): the virtual release target is indirect through the value vtable; the ownership flag and release argument 1 are inferred from the call shape; existing corpus analysis labels this a mutex/sync list with offsets shifted by 0x10 - not corroborated by this packet.
- 0x00407EF0 (BitfieldExtractFromStruct): the meaning of the extracted bit and the identity of the caller-supplied structure are unknown.
- 0x00407FB0 / 0x00408000 / 0x00408050 (linked-list lookups): field this+0x24 is listed as read-only in the packet facts but never read in the raw source; its role as a node count is unverifiable from this packet (the count is only decremented by 0x00407C90).
- 0x004083E0 (ResetStructWithConditionalNotify): the return value is uninitialized when the flag at 0x15 was already 0; global dword_8AD298 is flagged by packet facts but appears nowhere in the raw source.
- 0x004084B0 (LargeStructConstructorWithVTable): attribution to ChildContainer is a GUESS merge based on the shared vtable off_59E60C and the overlapping child-slot range this+0x10..0x30; the packet itself gives it UNKNOWN owner and sole caller sub_40C140 (0x0040C140).
- 0x00408520 (NotifyChildrenTeardown): the dispatched child methods are only vtable-slot 0 with arguments 1/3; the two container vtables off_59E60C/off_59E634 contents are unavailable; the return value is undefined when every child pointer is null.
- 0x00408740 (FloatKeyedFieldSelector): the nine selected fields and the 200-scaled case 4 are unconfirmed; the camera-shake interpretation is DERIVED prose, not runtime evidence.
- 0x00409950 / 0x004099E0 (view-mode callbacks): global dword_8AFE64 is listed in the packet globals but never referenced by the raw source; the object at dword_8AFE88 and the meaning of bit 0x8000 at offset 236 are unresolved.
- 0x00409A00 (CameraModeViewportUpdate): globals flt_59E440, flt_59E65C, flt_59E660, flt_59E664, flt_59E668, dword_8AD298 and dword_8AFE88 are recorded as read but absent from the decompiled text (likely folded constants); dword_5BE900 sequencing reset to 0 occurs outside this function; field:obj:0x00000014's owning object is unidentifiable.
- General: the 28-byte record layout of F3DBufferMesh is inferred only from the zero-fill stride; no packet evidence proves common ownership between the different objects that share byte offsets.
- No evidence in the packet establishes runtime truth; every class here except the three DERIVED owners is a GUESS proposal.
