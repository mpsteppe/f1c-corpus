# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `GUESS`

Reconstruction of generic runtime objects from 27 validated function IR records. The packet supplies one DERIVED owner (MutexSynchronizationObject for 0x00406700) and labels everything else UNKNOWN. Five audio functions (0x00405900, 0x00405B90, 0x00405F80, 0x00406060, 0x004060C0) share the same this-base fields (sample-info slot at +0x58, listener pointer at +0x54, loop/state flag at +0x14, behavior bitmask at +0x18, processor/filter state at +0x60/+0x64/+0x68) and are directly connected by call edges, so they are grouped as one DERIVED-proposed MilesSoundSourceObject. 0x00407D40 writes int/float triples into overlapping offsets (this+0x58..0x78) with a different interpretation and a different caller (0x004071F0), so it is kept as a separate AudioSampleDirectionObject and the offset overlap is recorded as an explicit contradiction. The three list-insert functions use the same 12-byte-node pattern but different list-field offsets and are kept as separate classes per rule 8. Free helpers (0x00405020, 0x004057E4, 0x00408210, 0x004084A0, 0x00408500) are assigned owner FreeFunction. State machinery is proposed for the per-frame scene-object loader and the collision-mode dispatcher; the Miles sample playback lazy-init is modeled as a first-call initialization pattern.

## Function roles

- `0x00403FC0` **IndexedStructArrayAccessor** — Reads one 28-byte entry from a 2D-indexed struct array (base this+0x158, second-dimension stride this+0x164, linear index = a2 + a3*stride), copies entry bytes 0..11 to a4 and 12..23 to a5, returns the second dword of the second group; consumed by the render-path callers 0x004C6F10 and 0x004D1140.
- `0x00405020` **FreeFunction** — Thin wrapper: calls ComplexDestructorWith4LinkedLists with global unk_5EA440 (0x005EA440) as its argument and returns the result; the callee address and the purpose of the global are not established by the packet, so the init/load-path reading is unconfirmed.
- `0x00405670` **MemoryBlockCopyHelper** — stdcall memory-copy helper: copies a3 bytes from a2 into a1 via an inline block copy and returns the one-past-the-end pointer a1+a3; invoked by MemoryAllocation_56a0 (0x004056A0) on the allocation/copy path.
- `0x004057E4` **FreeFunction** — __usercall helper with a custom register ABI: adds BYTE5(result) (bits 32..39 of the returned 64-bit value) into the byte at *a2, clears the byte at a3+112, returns result unchanged; the decompiler warns the stack may be mis-rendered.
- `0x004058D0` **VTableSwapDestructorObject** — thiscall destructor: overwrites the vtable at this+0x0 with off_59E4B4, frees the child allocation at this+0x4 via FreeWrapper_7bcf when non-null, frees the object itself when deallocation flag bit 0 (a2 & 1) is set, returns this.
- `0x00405900` **MilesSoundSourceObject** — Lazy Miles sample-playback setup: aborts (return 1) when the collision/spatial response computation (0x00405E60) triggers; on first call (handle slot this+0x58 null) allocates a playback handle via 0x004070E0, stores a back-reference, and when the sample and file reference this+0x5C are valid sets the sample file, loop count (flag this+0x14: 1 = infinite -> 0, else 1), and passes this to sample-processor setup (0x004060C0); then writes position params and the active flag into the handle; a 3D request (a7 non-zero) applies the 3D update (0x00405B90) and clears the active flag; returns 0 on success, 1 on abort.
- `0x00405B90` **MilesSoundSourceObject** — Per-frame 3D positional-audio recompute for one source vs a listener: distance attenuation (SmoothstepInterpolation 0x00406020 when bitmask bit 3 clear), stereo pan via ScaledDotProductWithClamp (0x00405F80) and DotProductWithScaleOffset (0x00406060), channel volumes and playback rate pushed through the Miles imports, then follow-up sample-state computation (0x00406100) and start/position/resume via 0x00587BDC; always returns 0; called by 0x00405900.
- `0x00405F80` **MilesSoundSourceObject** — Orientation-scaled attenuation factor: dot(a2, orientation sub-struct via this+0x54 at +0x7C/+0x80/+0x84) + 330.0 over dot(a2, listener-direction at this+0x34/+0x38/+0x3C) + 330.0, times current gain at this+0x48, clamped to [0.125, 8.0] and written back to this+0x48; called from 0x00405B90.
- `0x00406060` **MilesSoundSourceObject** — Pan/balance factor: dot of the stored vector (sub-struct via this+0x54, components at this+0xC4/+0xC8/+0xCC) against input a2, scaled and biased as (dot*0.60000002 + 1.0) * 0.5 into the [0.2, 0.8] range; used by 0x00405B90.
- `0x004060C0` **MilesSoundSourceObject** — Miles sample processor/filter setup: loads sample-info from this+0x58, takes the Miles handle at its +0x10, calls AIL_set_sample_processor with this+0x64 as the processor value, and when the filter index this+0x60 is not -1 resolves it via sub_404FC0 and applies AIL_set_filter_sample_preference with this+0x68 as the filter data buffer; early-returns the null result when the sample-info or handle is null.
- `0x00406250` **SyncTeardownObject** — Destructor-style cleanup for a synchronization-style object: installs vtable off_59E4EC, runs ViewCameraReset (0x004064C0), removes the object from its linked list via 0x00407C90, closes the handle at this+0x50 when the byte at this+0x58 is set (CloseHandle import 0x0059E1A8), frees three dword slots at 20-byte stride via FreeWrapper_7bcf when non-null, reverts the vtable to off_59E50C, returns the last free result.
- `0x004062B0` **SlotStringListObject** — Slot-based string-list mutator on this: insert mode scans up to 3 fixed 20-byte-stride slots at this+0x28 for an empty slot (slot id -1 plus zero byte flag), copies a string pointer, two int fields and a byte flag from the 5-dword-stride input a2, reports the result through the vtable method at obj+0x8, and finalizes via sub_406790 on failure; clear mode resets all 3 slots and repopulates them from a2's first a3 entries, then runs sub_406790.
- `0x00406700` **MutexSynchronizationObject** — Mutex-protected write with bounded wait: returns 0 when the mutex handle at this+0x50 is null or the WaitForSingleObject result is non-zero and not 128 (WAIT_ABANDONED); otherwise writes a2 into the protected value at this+0x4C, releases via ReleaseMutex when the handle is still non-null, returns 1; the timeout is read from this+0x54.
- `0x00406A90` **IndexPairOwnerObject** — Reads two int values from the object (this+0x18 and this+0x1C) through optional NULL-checked output pointers a2/a3 and returns the a3 pointer; consistent with returning a per-entry ID/index pair to caller LinkedListNodeSearchByIDOperation.
- `0x00407450` **UniqueStringList** — Unique-string linked-list insertion: guards null input, traverses from head this+0x28 via cursor this+0x30 comparing each node string (fallback global byte_5EA438) through sub_588410, returns without inserting on match; otherwise allocates an 8-byte string node and a 12-byte list node (OperatorNewNhMallocWrapper), copies the string via StringCopyWithBufferRealloc, appends the node to the tail this+0x2C (or makes it head) and increments the count this+0x34.
- `0x00407810` **ProjectionViewList** — Allocates a 108-byte view/projection structure, initializes it via ViewProjectionStructInit (0x004057F0), allocates a 12-byte node holding it and appends the node at the tail of the list rooted at this (head this+0x8, tail this+0xC, first-reference this+0x10, count this+0x14); gated on the enable flag this+0x88 and non-null a2; returns the initialized structure even when node allocation fails.
- `0x004078A0` **MutexSlotList** — Structurally identical sibling of 0x00407810 but for a 96-byte mutex/synchronization object initialized via MutexSynchronizationObjectInit (0x00406130); list fields sit at different offsets (head this+0x18, tail this+0x1C, first-reference this+0x20, count this+0x24); same enable gate this+0x88; kept as a separate class from ProjectionViewList.
- `0x00407D40` **AudioSampleDirectionObject** — Direction/angle store helper on an audio sample object: copies a 3-int triple into this+0x58/+0x5C/+0x60 and a 3-float angle triple into this+0x64/+0x68/+0x6C, computes trig terms and stores them at this+0x70/+0x74/+0x78; returns the low dword of the float at this+0x78; called by AudioSamplePositionVolumeSetter (0x004071F0).
- `0x00408210` **FreeFunction** — Initialization/teardown delegation wrapper: clears slot 17 in the global block algn_5EA4EC, invokes StructInitWithConditionalNotify (0x004083E0), returns the address of the adjacent global float flt_5EA4E8 (0x005EA4E8); callee identity and slot meaning are caller-supplied.
- `0x004084A0` **FreeFunction** — No-argument cdecl reader returning the double value at global dbl_8AFE90 (0x008AFE90); no computation or side effects; consumed by camera-related paths 0x004085F0, 0x00409A00, 0x0040ADB0 and 0x0040B710, suggesting a shared camera configuration constant.
- `0x00408500` **FreeFunction** — Conditional-free helper: notifies the vtable entry of cleanup via VtableEntryNotifyCleanup (0x00408520), then releases the object memory via FreeWrapper_7bcf only when flag bit 0 (a2 & 1) is set; returns this.
- `0x004085F0` **SubObjectEffectDispatcher** — Sub-object effect parameter dispatcher: selects a sub-object pointer by the mode field this+0x34 (cases 0..8 read this+0x10..this+0x30; case 4 computes this+0x20 + 200 * this+0x3C; others return early), then dispatches per-argument parameter bytes (a2/a3/a4 selecting between -1 context global byte_5EA55C and 1 context byte_5BE870) through virtual calls at vtable slots +12 and +16 on the selected sub-object, feeding a float from ShortComputation_84a0 and CollisionCoefficientApplication (0x00456F70); the jump table is global 0x00408714.
- `0x0040A890` **MultiSlotMembershipObject** — Multi-slot membership check: returns 1 when input a2 matches any of the eight fixed entry slots (this+0x10..+0x1C and this+0x24..+0x30) or lies on the stride-200 grid of the variable-length array at this+0x20 within the count this+0x38; returns 0 otherwise, including a non-positive count.
- `0x0040CCE0` **CameraManager** — Camera manager post/teardown: optionally logs entry when StringSplitLoop(2, source-string, 3785) is true, zeroes the main camera pointer at this+0x8, calls StructInitWithConditionalNotify on global flt_5EA4E8, releases three loader objects at this+0x18/+0x1C/+0x20 via their vtable[0] method with argument 1 and nulls each pointer, clears the byte flag at this+0x2E, returns the last call result.
- `0x0040F0D0` **GuardedIDListNode** — Guarded chain on the object's ID field: when *this == -1, inserts the node via LinkedListNodeInsert_0ad0 (0x00410AD0), runs a nested loop pass (0x004BE180), and returns the result of cleanup sub_4BDE20(this); the fall-through path when *this != -1 returns an uninitialized local.
- `0x0040F4B0` **ModeDispatchContactObject** — Collision-processing mode dispatcher: reads the mode selector at this+0x1C and switches on it through jump table global 0x0040F52C; modes 0-5 run the guarded computation ShortComputation_f0d0 (0x0040F0D0) and a collision contact-impulse computation (0x004599C0) from a2/a3; mode 6 accumulates vehicle contact force from a2 with constant 1 (0x004EBC60); any other value returns the mode unchanged.
- `0x00410980` **SceneObjectArrayOwner** — Per-frame scene-object tick: clears the UI widget matrix dword_8AB710 via MatrixClear (0x004BDFE0), then iterates this[0] scene objects from the array at this+0x8 running SceneObjectLoaderStateMachine (0x0040F1C0) on each with the frame argument; when it returns false the element is pulled, ConditionalCleanupChain (0x0040F100) runs on it, and the index is decremented so the slot is revisited; returns the element count.

## Proposed classes

### MilesSoundSourceObject

Miles Sound System sample-playback source object: owns the lazily-allocated playback handle/sample-info slot at this+0x58, the loaded-file reference at this+0x5C, the loop/state flag at this+0x14, the behavior bitmask at this+0x18, positional source fields this+0x28/+0x2C/+0x30, listener-direction components this+0x34/+0x38/+0x3C, baseline attenuation this+0x40, rate components this+0x44/+0x48, the listener pointer this+0x54, processor/filter state this+0x60/+0x64/+0x68, and the pan vector components this+0xC4/+0xC8/+0xCC. Grouping is DERIVED-proposed from shared this-base fields plus the direct call edges 0x00405900 -> 0x00405B90/0x004060C0 and 0x00405B90 -> 0x00405F80/0x00406060.

Methods: `0x00405900`, `0x00405B90`, `0x00405F80`, `0x00406060`, `0x004060C0`

- `this+0x00000000` `pointer vtable_ptr` (read, GUESS)
- `obj+0x0000001C` `pointer state_query_vslot` (read, GUESS)
- `this+0x00000014` `int loop_state_flag` (read, GUESS)
- `this+0x00000018` `int behavior_bitmask` (read, GUESS)
- `this+0x00000028` `float source_pos_x` (read, GUESS)
- `this+0x0000002C` `float source_pos_y` (read, GUESS)
- `this+0x00000030` `float source_pos_z` (read, GUESS)
- `this+0x00000034` `float listener_dir_x` (read, GUESS)
- `this+0x00000038` `float listener_dir_y` (read, GUESS)
- `this+0x0000003C` `float listener_dir_z` (read, GUESS)
- `this+0x00000040` `float baseline_attenuation` (read, GUESS)
- `this+0x00000044` `float rate_component` (read, GUESS)
- `this+0x00000048` `float gain` (read_write, GUESS)
- `this+0x00000054` `pointer listener_ptr` (read, GUESS)
- `this+0x00000058` `pointer sample_info_ptr` (read_write, GUESS)
- `this+0x0000005C` `pointer sample_file_ref` (read, GUESS)
- `this+0x00000060` `int filter_index` (read, GUESS)
- `this+0x00000064` `int processor_value` (read, GUESS)
- `this+0x00000068` `pointer filter_data_ptr` (read, GUESS)
- `this+0x000000C4` `float stored_vec_x` (read, GUESS)
- `this+0x000000C8` `float stored_vec_y` (read, GUESS)
- `this+0x000000CC` `float stored_vec_z` (read, GUESS)

### MilesSampleInformationObject

Object holding the Miles sample handle at +0x10; referenced through two different container paths (this+0x58 in the positioning update, this+0x68 in the processor setup). The two paths share the same +0x10 handle offset but are not proven to be the same allocation.

Methods: 

- `*(this+0x58)+0x00000010` `pointer sample_handle` (read, GUESS)
- `*(this+0x68)+0x00000010` `pointer sample_handle` (read, GUESS)

### AudioListenerObject

Listener object reached through the sound-source field this+0x54: supplies the source-relative position window at +0x58/+0x5C/+0x60, the orientation sub-struct at +0x7C/+0x80/+0x84, and the Doppler reference float at +0x8C.

Methods: 

- `*(this+0x54)+0x00000058` `float listener_pos_x` (read, GUESS)
- `*(this+0x54)+0x0000005C` `float listener_pos_y` (read, GUESS)
- `*(this+0x54)+0x00000060` `float listener_pos_z` (read, GUESS)
- `*(this+0x54)+0x0000007C` `float orientation_x` (read, GUESS)
- `*(this+0x54)+0x00000080` `float orientation_y` (read, GUESS)
- `*(this+0x54)+0x00000084` `float orientation_z` (read, GUESS)
- `*(this+0x54)+0x0000008C` `float doppler_reference` (read, GUESS)

### AudioSampleDirectionObject

Audio sample object whose direction/angle store (0x00407D40) writes a 3-int triple into this+0x58/+0x5C/+0x60, a 3-float angle triple into this+0x64/+0x68/+0x6C, and trig terms into this+0x70/+0x74/+0x78. Kept separate from MilesSoundSourceObject because the packet gives it UNKNOWN owner and a different caller (0x004071F0), and the overlapping offsets are interpreted differently by the two clusters.

Methods: `0x00407D40`

- `this+0x00000058` `int dir_int_x` (write, GUESS)
- `this+0x0000005C` `int dir_int_y` (write, GUESS)
- `this+0x00000060` `int dir_int_z` (write, GUESS)
- `this+0x00000064` `float angle_float_x` (write, GUESS)
- `this+0x00000068` `float angle_float_y` (write, GUESS)
- `this+0x0000006C` `float angle_float_z` (write, GUESS)
- `this+0x00000070` `float trig_term_cos_derived` (write, GUESS)
- `this+0x00000074` `float trig_term_zero` (write, GUESS)
- `this+0x00000078` `float trig_term_sin_derived` (write, GUESS)

### UniqueStringList

Unique-string linked-list container with head this+0x28, tail this+0x2C, traversal cursor this+0x30 and node count this+0x34; inserts strings only when absent, comparing against global byte_5EA438 when a node has no string. The 8-byte string node and 12-byte list node allocations are heap records whose layout is visible only through decompiler casts.

Methods: `0x00407450`

- `this+0x00000028` `pointer list_head` (read_write, GUESS)
- `this+0x0000002C` `pointer list_tail` (read_write, GUESS)
- `this+0x00000030` `pointer traversal_cursor` (read_write, GUESS)
- `this+0x00000034` `int node_count` (read_write, GUESS)

### ProjectionViewList

View/projection-object linked-list container: holds head this+0x8, tail this+0xC, first-reference this+0x10 and count this+0x14; insertion (0x00407810) is gated on the enable flag this+0x88 and a non-null input, allocates a 108-byte payload initialized by ViewProjectionStructInit and a 12-byte node, and returns the payload even when node allocation fails.

Methods: `0x00407810`

- `this+0x00000008` `pointer list_head` (read_write, GUESS)
- `this+0x0000000C` `pointer list_tail` (read_write, GUESS)
- `this+0x00000010` `pointer first_reference` (read_write, GUESS)
- `this+0x00000014` `int node_count` (read_write, GUESS)
- `this+0x00000088` `int enable_flag` (read, GUESS)

### MutexSlotList

Mutex/synchronization-object linked-list container: holds head this+0x18, tail this+0x1C, first-reference this+0x20 and count this+0x24 at different offsets than the structurally identical ProjectionViewList, so it is kept as a separate class (rule 8); insertion (0x004078A0) is gated on the enable flag this+0x88 and initializes a 96-byte payload via MutexSynchronizationObjectInit.

Methods: `0x004078A0`

- `this+0x00000018` `pointer list_head` (read_write, GUESS)
- `this+0x0000001C` `pointer list_tail` (read_write, GUESS)
- `this+0x00000020` `pointer first_reference` (read_write, GUESS)
- `this+0x00000024` `int node_count` (read_write, GUESS)
- `this+0x00000088` `int enable_flag` (read, GUESS)

### MutexSynchronizationObject

Mutex synchronization object (packet DERIVED owner for 0x00406700): stores the OS mutex handle at this+0x50, the wait timeout at this+0x54 and the protected value at this+0x4C. MutexLockWithTimeout performs a bounded write of the protected value, treating a WaitForSingleObject result of 128 as WAIT_ABANDONED takeover.

Methods: `0x00406700`

- `this+0x0000004C` `int protected_value` (write, DERIVED)
- `this+0x00000050` `pointer mutex_handle` (read_write, DERIVED)
- `this+0x00000054` `int lock_timeout` (read, DERIVED)

### SyncTeardownObject

Synchronization-style object whose destructor cleanup (0x00406250) swaps the vtable between off_59E4EC and off_59E50C, closes the handle at this+0x50 when the flag byte at this+0x58 is set, frees three dword slots at 20-byte stride, and removes the object from a linked list via LinkedListNodeRemovalWithVTableRelease. Class identity and the concrete slot meanings are not established by the packet.

Methods: `0x00406250`

- `this+0x00000000` `pointer vtable_ptr` (write, GUESS)
- `this+0x00000010` `pointer freed_slot_a` (read, GUESS)
- `this+0x00000024` `pointer freed_slot_b` (read, GUESS)
- `this+0x00000038` `pointer freed_slot_c` (read, GUESS)
- `this+0x00000050` `pointer handle` (read_write, GUESS)
- `this+0x00000058` `byte handle_open_flag` (read, GUESS)

### VTableSwapDestructorObject

Object destroyed by a vtable-swap destructor (0x004058D0): the vtable at this+0x0 is set to off_59E4B4, the child allocation at this+0x4 is freed when non-null, and the object itself is freed when the caller deallocation flag bit 0 is set. The concrete class owning vtable 0x0059E4B4 is not identified.

Methods: `0x004058D0`

- `this+0x00000000` `pointer vtable_ptr` (write, GUESS)
- `this+0x00000004` `pointer child_alloc_ptr` (read, GUESS)

### IndexedStructArrayAccessor

Object owning a 2D-indexed array of 28-byte struct entries at this+0x158 with a second-dimension stride at this+0x164; 0x00403FC0 reads one entry and splits it into two 12-byte output groups. The entry layout semantics (position vs orientation) come only from skeleton prose.

Methods: `0x00403FC0`

- `this+0x00000158` `pointer entry_array_base` (read, GUESS)
- `this+0x00000164` `int second_dim_stride` (read, GUESS)

### SceneObjectArrayOwner

Container of per-frame scene objects: element count at this+0x00, array base at this+0x08. UpdateSceneObjects (0x00410980) ticks each element through SceneObjectLoaderStateMachine and removes/cleanup-chains failed elements.

Methods: `0x00410980`

- `this+0x00000000` `int element_count` (read, GUESS)
- `this+0x00000008` `pointer element_array_base` (read, GUESS)

### IndexPairOwnerObject

Object exposing an index/ID pair at this+0x18 and this+0x1C; 0x00406A90 reads the pair through optional output pointers. The pair semantics are inferred from the caller context only.

Methods: `0x00406A90`

- `this+0x00000018` `int index_a` (read, GUESS)
- `this+0x0000001C` `int index_b` (read, GUESS)

### MultiSlotMembershipObject

Object with eight fixed entry slots (this+0x10..0x1C and this+0x24..0x30) plus a variable-length array (base this+0x20, 200-byte-stride entries, count this+0x38); MultiFieldMembershipCheck tests whether an input matches any fixed slot or array grid position.

Methods: `0x0040A890`

- `this+0x00000010` `pointer fixed_entry_0` (read, GUESS)
- `this+0x00000014` `pointer fixed_entry_1` (read, GUESS)
- `this+0x00000018` `pointer fixed_entry_2` (read, GUESS)
- `this+0x0000001C` `pointer fixed_entry_3` (read, GUESS)
- `this+0x00000020` `pointer variable_array_base` (read, GUESS)
- `this+0x00000024` `pointer fixed_entry_4` (read, GUESS)
- `this+0x00000028` `pointer fixed_entry_5` (read, GUESS)
- `this+0x0000002C` `pointer fixed_entry_6` (read, GUESS)
- `this+0x00000030` `pointer fixed_entry_7` (read, GUESS)
- `this+0x00000038` `int entry_count` (read, GUESS)

### SlotStringListObject

Slot-based string-list object: three 20-byte-stride slots whose identifiers sit at this+0x1C and byte flags at this+0x20, with a vtable method at obj+0x8 reporting mutation results; SortedStringListInsert (0x004062B0) mutates or rebuilds the slots and finalizes via sub_406790.

Methods: `0x004062B0`

- `obj+0x00000008` `pointer mutation_result_vslot` (read, GUESS)
- `this+0x0000001C` `int slot_identifier` (read_write, GUESS)
- `this+0x00000020` `byte slot_byte_flag` (read_write, GUESS)

### SubObjectEffectDispatcher

Object dispatching effect parameters to one of nine sub-object pointers (this+0x10..0x30, with case 4 computed as this+0x20 + 200 * this+0x3C) selected by the mode field this+0x34; virtual calls at vtable slots +12 and +16 receive the selected parameter byte and a float from ShortComputation_84a0. The vtable base registers of the virtual calls are uninitialized in the decompilation.

Methods: `0x004085F0`

- `this+0x00000010` `pointer sub_object_0` (read, GUESS)
- `this+0x00000014` `pointer sub_object_1` (read, GUESS)
- `this+0x00000018` `pointer sub_object_2` (read, GUESS)
- `this+0x0000001C` `pointer sub_object_3` (read, GUESS)
- `this+0x00000020` `pointer sub_object_4_base` (read, GUESS)
- `this+0x00000024` `pointer sub_object_5` (read, GUESS)
- `this+0x00000028` `pointer sub_object_6` (read, GUESS)
- `this+0x0000002C` `pointer sub_object_7` (read, GUESS)
- `this+0x00000030` `pointer sub_object_8` (read, GUESS)
- `this+0x00000034` `int mode` (read, GUESS)
- `this+0x0000003C` `int case4_scale_index` (read, GUESS)

### ModeDispatchContactObject

Collision-processing object with a mode selector at this+0x1C; ModeDispatchWithSwitch (0x0040F4B0) dispatches modes 0-5 to the collision-impulse path and mode 6 to the vehicle-contact-accumulation path through the jump table at 0x0040F52C.

Methods: `0x0040F4B0`

- `this+0x0000001C` `int mode_selector` (read, GUESS)

### GuardedIDListNode

Node object whose ID field at this+0x00 gates a processing chain: when *this == -1 it is inserted into a linked list (0x00410AD0), runs a nested loop pass (0x004BE180) and is finalized by sub_4BDE20. The fall-through path returns an uninitialized local.

Methods: `0x0040F0D0`

- `this+0x00000000` `int id` (read, GUESS)

### CameraManager

Camera manager with a main camera pointer at this+0x8, three released vtable loader objects at this+0x18/+0x1C/+0x20 and an active byte flag at this+0x2E; CamMan_Post (0x0040CCE0) releases each loader through its vtable slot-0 method with argument 1, nulls the pointers and resets the flag. Loader class identities are unconfirmed.

Methods: `0x0040CCE0`

- `this+0x00000008` `pointer main_camera_ptr` (write, GUESS)
- `this+0x00000018` `pointer loader_object_a` (read_write, GUESS)
- `*(this+0x18)+0x00000000` `pointer loader_a_vtable_release_slot` (read, GUESS)
- `*(*(this+0x18)+0x0)+0x00000000` `pointer loader_a_release_method` (read, GUESS)
- `this+0x0000001C` `pointer loader_object_b` (read_write, GUESS)
- `*(this+0x1C)+0x00000000` `pointer loader_b_vtable_release_slot` (read, GUESS)
- `*(*(this+0x1C)+0x0)+0x00000000` `pointer loader_b_release_method` (read, GUESS)
- `this+0x00000020` `pointer loader_object_c` (read_write, GUESS)
- `*(this+0x20)+0x00000000` `pointer loader_c_vtable_release_slot` (read, GUESS)
- `*(*(this+0x20)+0x0)+0x00000000` `pointer loader_c_release_method` (read, GUESS)
- `this+0x0000002E` `byte active_byte_flag` (write, GUESS)

### MemoryBlockCopyHelper

Stateless stdcall block-copy helper returning the one-past-the-end destination pointer; used by the allocation/copy path at 0x004056A0. No owned fields.

Methods: `0x00405670`


## Compatibility contracts

- **MilesSamplePlaybackContract** — Sample playback setup must lazily allocate the playback handle into this+0x58 on first call (back-reference to this), use the loaded-file reference at this+0x5C, select the loop count from the flag at this+0x14 (1 = infinite -> AIL loop count 0, else 1), configure processor/filter state through this+0x60/+0x64/+0x68, and return 0 on success or 1 when the spatial-response computation (0x00405E60) triggers or handle allocation fails.
- **Miles3DPositioningContract** — The per-frame 3D positional update must read the source position at this+0x28/+0x2C/+0x30, the listener pointer at this+0x54 (listener position at +0x58/+0x5C/+0x60, orientation at +0x7C/+0x80/+0x84, Doppler reference at +0x8C), gate on the state flag this+0x14 and behavior bitmask this+0x18, clamp the gain at this+0x48 to [0.125, 8.0] after the dot-product scaling, compute the pan factor as (dot*0.60000002 + 1.0) * 0.5, set the playback rate from the Doppler reference times this+0x44 and this+0x48, and return 0 on every path.
- **MutexLockContract** — Mutex-protected write must return 0 when the mutex handle at this+0x50 is null or when the WaitForSingleObject result is non-zero and not 128 (WAIT_ABANDONED); on success it must write the caller value into the protected slot at this+0x4C, release the mutex via ReleaseMutex when the handle is still non-null, and return 1. The wait timeout is read from this+0x54.
- **SyncObjectTeardownContract** — Synchronization-object teardown must swap the vtable to off_59E4EC, run the reset routine (0x004064C0), remove the object from its linked list via 0x00407C90, close the handle at this+0x50 via CloseHandle only when the byte at this+0x58 is set (then clearing the handle), free the three dword slots at 20-byte stride when non-null, and revert the vtable to off_59E50C before returning.
- **ListInsertEnableGateContract** — List insertion (0x00407810 and 0x004078A0) must gate on the enable flag at this+0x88 and a non-null input, allocate the payload and a 12-byte node, make the node both head and first-reference when the list is empty, otherwise append after the tail, advance the tail, increment the count, and return the initialized payload even when the node allocation fails. The two siblings keep their head/tail/first/count fields at different offsets and must not be assumed to share a base type.
- **UniqueStringListContract** — The unique-string list must traverse from the head this+0x28 comparing each node string (falling back to global byte_5EA438 when a node has no string) and skip insertion on a match; otherwise it allocates an 8-byte string node and a 12-byte list node, appends at the tail this+0x2C and increments the count this+0x34.
- **IndexedStructArrayReadContract** — The 2D-indexed array reader must compute the linear entry index as a2 + a3 * (this+0x164) over 28-byte entries at base this+0x158, copy entry bytes 0..11 to the first output and 12..23 to the second, and return the second dword of the second group.
- **CameraManagerTeardownContract** — Camera-manager teardown must optionally emit a debug log line, zero the main camera pointer at this+0x8, run the global struct-init (0x004083E0 on flt_5EA4E8), release each of the three loader objects at this+0x18/+0x1C/+0x20 through its vtable slot-0 method with argument 1 and null the pointer, and clear the byte flag at this+0x2E.
- **SceneObjectTickContract** — The per-frame scene-object update must clear the UI widget matrix dword_8AB710, iterate the element count this+0x00 over the array at this+0x08, advance each element through SceneObjectLoaderStateMachine with the frame argument, and on a false result remove the element, run ConditionalCleanupChain on it and revisit the same slot (index decrement).

## Unresolved

- 0x00403FC0 (IndexedStructDataRead): the semantics of the two 12-byte output groups (position vs orientation) and the meaning of the 28-byte entry layout come only from skeleton prose, not from the raw source; the owner class providing this+0x158/this+0x164 is unidentified.
- 0x00405020 (InitLoadPathWrapper): unk_5EA440 is unnamed (type, content, lifecycle unknown); ComplexDestructorWith4LinkedLists is named only in the raw source text and has no packet callee address; the init/load-path name is not corroborated by the destructor-style body.
- 0x004057E4 (AudioBufferByteAdd): the __usercall register placement is nonstandard and its caller is unknown; the BYTE5(result) addend and the byte cleared at a3+112 have no named evidence; the decompiler warns the stack may be mis-rendered.
- 0x004058D0 (DestructorWithVTableAndFree): the concrete class owning vtable 0x0059E4B4 is not identified; the meaning of a2 flag bits beyond bit 0 (object deallocation) is unknown.
- 0x00405900 (MilesAudioSamplePlaybackSetup): the owning class is unidentified; the per-handle fields at +0x4/+0x8/+0xC and +0x10 are read/written but not semantically confirmed; the roles of this+0x60/+0x64/+0x68 inside the processor setup are defined outside this packet.
- 0x00405B90 (Update3DSoundPositioning): the obj+0x1C vtable state query is caller-defined; the this+0x18 bitmask bit meanings (0/2/3/4) are inferred from branch structure; the listener (this+0x54) vs sample-information (this+0x58) relationship is not expressed in the raw text; globals 0x0059E43C/0x0059E440 are packet-flagged but absent from the raw source.
- 0x00405F80 (ScaledDotProductWithClamp): the exact mapping of globals 0x0059E4DC/0x0059E4E0/0x0059E4E4 to the 330.0/0.125/8.0 literals is unconfirmed; the a2 direction-vector reading is DERIVED from the sole caller; the orientation sub-struct semantics of +0x7C/+0x80/+0x84 are not in the raw text.
- 0x00406060 (DotProductWithScaleOffset): float globals 0x0059E43C/0x0059E450/0x0059E4E8 may back the 0.6/1.0/0.5 scale literals but the mapping is unproven; the [0.2, 0.8] pan range is a DERIVED interpretation.
- 0x004060C0 (MilesSoundSampleProcessorSetup): the meaning of the processor type literal 1 and of this+0x64 is not grounded in the packet; sub_404FC0's resolution mechanism is outside packet evidence; the owning class is unknown.
- 0x00406250 (SynchronizationObjectDestructorCleanup): the identities of vtable globals off_59E4EC/off_59E50C and the three freed dword slots are not established; the flag at this+0x58 and handle at this+0x50 beyond 'initialized'/'close' are inferences; ViewCameraReset (0x004064C0) is a legacy name whose role in the destructor path is unclear.
- 0x004062B0 (SortedStringListInsert): the vtable method at obj+0x8 and sub_406790 (finalization/re-sort) are not observable from this function alone; the adjacent slot identifier at this+0x18 has no packet field evidence ref; packet-listed callee FreeWrapper_7bcf does not appear in the raw body (possibly inlined).
- 0x00406700 (MutexLockWithTimeout): the constant 128 is read as Win32 WAIT_ABANDONED from API semantics, not named by the packet; this mutex layout (handle 0x50, timeout 0x54, value 0x4C) differs from the MutexCreateRecreate object, so class identity is DERIVED and unconfirmed; the meaning of the protected value is unknown.
- 0x00406A90 (GetIndexPair): the semantics of the two values at +0x18/+0x1C (an index pair) are inferred from the caller context only; how LinkedListNodeSearchByIDOperation interprets the returned pointers is outside this packet.
- 0x00407450 (LinkedListStringInsertUnique): the node traversal pointer chain is visible only through decompiler type casts; the content and purpose of global byte_5EA438 as a default comparison string are not resolved from this packet.
- 0x00407810 / 0x004078A0: the owner objects and the meaning of the shared enable flag at this+0x88 are unidentified; the 12-byte node layout beyond payload pointer and byte flag is an assumed minimum; why both return the initialized payload when node allocation failed is unexplained. The two siblings are structurally identical but use different list-field offsets and are therefore kept as separate classes (rule 8).
- 0x00407D40 (setAudioDirectionFromAngles): global 0x0059E440 is packet-flagged but absent from the raw source (possibly the folded zero constant); the 3-int triple role is established only by caller 0x004071F0; the multiply-by-0.0 terms are compiler artifacts whose original formula is not recoverable. CONTRADICTION: this function writes int/float triples into this+0x58..0x78 while the MilesSoundSourceObject cluster interprets this+0x58/0x60/0x64/0x68 differently; the two are kept as separate classes.
- 0x00408210 (InitializeAndReturnFloatGlobal): StructInitWithConditionalNotify (0x004083E0) semantics are caller-supplied; algn_5EA4EC slot 17 and its relation to flt_5EA4E8 are unknown; whether &flt_5EA4E8 is a single float or an array start is unknown.
- 0x004084A0 (ShortComputation_84a0): the meaning and initializer of dbl_8AFE90 are unknown; the name carries no semantic weight beyond 'reads a global float'; which camera property it feeds is not evidenced.
- 0x00408500 (ConditionalFreeByFlag): flag bit semantics beyond bit 0 (defer-free) are unknown; the owner object type is unknown.
- 0x004085F0 (DispatchSubObjectEffectParameters): the switch jump table at 0x00408714 is not modeled; the vtable bases of the +12/+16 virtual calls (registers v7/v10/v11) are uninitialized in the decompilation so the call targets are unresolved; the CollisionCoefficientApplication second argument on the a2 == 1 path is an uninitialized register.
- 0x0040A890 (MultiFieldMembershipCheck): whether a2 is a raw address (grid-position membership) or a stored entry id is not resolvable from this packet; the 200-byte array entry layout is a structural fact with no per-entry field documentation.
- 0x0040CCE0 (CamMan_Post): the three released objects at this+0x18/+0x1C/+0x20 are typed as loaders by existing analysis only; the argument-1 semantics of the vtable slot-0 release method and the role of flt_5EA4E8 are unconfirmed.
- 0x0040F0D0 (ShortComputation_f0d0): the fall-through path returns an uninitialized local (undefined value); globals 0x005EA560/0x008AB710 are packet-flagged but absent from the raw source; the guard direction (branch when *this == -1) is taken from the raw source and contradicts the prior fill's guard-table interpretation.
- 0x0040F4B0 (ModeDispatchWithSwitch): the semantic meaning of mode values 0-6 is not established; the roles of arguments a2 (likely contact/impulse descriptor) and a3 are caller-defined.
- 0x00410980 (UpdateSceneObjects): the identity of the scene-object type and the meaning of SceneObjectLoaderStateMachine's false return (failure vs unload) are not established by this packet.
- General: equal offsets on different this bases or on different list classes are never merged into a shared type without packet proof of common ownership (rule 8); every class here except the packet-supplied DERIVED owners (MutexSynchronizationObject, plus the DERIVED-proposed clusters) is a GUESS proposal; worker agreement cannot create runtime truth.
