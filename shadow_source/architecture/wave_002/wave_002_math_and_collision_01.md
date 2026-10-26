# MathAndCollision

Scope: `math_and_collision`  
Trust: `DERIVED`

Twelve validated functions proposed as twelve single-method classes, grouped by two behavioral interfaces. The dominant pattern is reverse-walk counted-array teardown: 0x00401030 is a generic stdcall driver (base, stride, count, caller-supplied __thiscall destructor), and 0x00408800 (200-byte stride), 0x004A29A0 (120-byte stride plus optional 3D sound source), 0x005478B0 (96-byte stride, doubly-linked list removal) and 0x005511A0 (136-byte stride, single child object) are concrete instantiations reading the element count from the DWORD header at base-4 and freeing the block via FreeWrapper_7bcf; a 0x0049B1C0 static slot sweep double-cleans each slot. Collision content: 0x0040EB30 initializes a collision shape header (discriminator +0x8, subtype 3 +0x1C, external data pointer +0x20, inverse mass 15.0) while 0x004532D0 copies per-scene collision parameters from the global unk_7D1448 into base+866 and base+1121. Audio and session content: 0x004072E0 (owner DERIVED MilesSoundSystem) rebuilds a 20-byte-entry AIL sample array; 0x004C07F0 and 0x004C2810 initialize session data and validate a session/scene container node. One bitmask builder 0x00586DE0 packs a bitmap range into a mask. All packet owners except MilesSoundSystem are UnknownObject; every class name and the interfaces are DERIVED/GUESS proposals, not confirmed source names.

## Function roles

- `0x00401030` **ArrayTeardownHelper** — Generic reverse array teardown driver (stdcall): given base a1, element stride a2, element count a3, invokes the caller-supplied __thiscall destructor a4 on each element in reverse order and returns the last destructor result (or a3-1 when the count is zero); used by resource/list teardown paths.
- `0x004072E0` **MilesSoundSystem** — Reallocate the Miles sound-system sample array: tear down the existing 20-byte-entry array at this+0x48 (per-entry virtual release, AIL_release_sample_handle on entry+16, free header), store the new count into this+0x4C, allocate a fresh zero-filled 20*count+4 buffer, and when the driver handle this+0x90 is set allocate and initialize an AIL sample handle per entry.
- `0x00408800` **FilePathEntryTable** — Flag-selected destructor: when (a2 & 2) treats this as one DWORD past an array header, reads the count from *(this - 1), reverse-walks the 200-byte-stride array calling ShortComputation_62a0 per element, and frees the header block at this - 1; when (a2 & 2) is clear calls ShortComputation_62a0 on this directly; on both paths (a2 & 1) additionally frees the block via FreeWrapper_7bcf; returns the processed base pointer.
- `0x0040EB30` **CollisionShapeGeometry** — Physics/collision shape initializer (the packet name is a legacy/ABI label that conflicts with the summary's collision-shape semantics): stores discriminator word a2 at this+0x8, subtype/kind constant 3 at this+0x1C, external data pointer a3 at this+0x20; passes inverse-mass scalar 15.0 and a six-dword constant array through CollisionInvMassStore, bulk-sets six floats via F_6FieldBulkSetter; when a4 is non-zero delegates to ShortComputation_e770(this, a4, 0).
- `0x004532D0` **SceneCollisionParameterStore** — Per-scene collision parameter update: for the scene count at this+0xD80, processes two 864-byte source blocks of the global unk_7D1448 into destination buffers (this + 866 for the first pass, this + 1121 for the second), computing double the source float[9] plus source floats [0] and [18] via CollisionParameterClampAndStore for each of the 8 sub-elements at 27-float stride; returns the final loop counter.
- `0x0049B1C0` **StaticResourceTable** — Static teardown sweep: iterates the dword array at dword_7CE23C up to the unk_7CE24C end sentinel, runs ResourceCleanup_cd10 twice on each non-null slot, frees the saved pointer via FreeWrapper_7bcf, then zeroes the slot; returns the last cleanup result.
- `0x004A29A0` **CountedArrayResource** — Destructor for a struct managing a counted 120-byte-element array plus an optional 3D sound source: zeroes header DWORDs this+0x0/0x4/0x8, zeroes the per-element field at +100 for the this+0xC counted elements, nulls the count; when this+0x10 is non-null reverse-walks the 120-byte array calling sub_4A2220 per element, frees the block via FreeWrapper_7bcf, nulls this+0x10; when global dword_8AFE88 is set and this+0x14 is non-null destroys the 3D sound source via F_3DSoundSourceDestructor.
- `0x004C07F0` **SessionLapData** — Constructor-style session initializer: 48-iteration loop writing -1 into dword pairs across a contiguous span of the object, then explicitly zeroes this+0x198, this+0x19C, this+0x1A0 and this+0x1A8, writes -1 to this+0x1AC, zeroes the byte at this+0x1B0, and returns 0; no reads, no globals, no calls.
- `0x004C2810` **SessionSceneNodeContainer** — Session/scene container init helper: dereferences the container's linked-list node via LinkedListDereference(this); returns 0 immediately if the node is null, otherwise initializes the node via sub_4C1050 and returns 1; on session/scene setup paths.
- `0x005478B0` **DoublyLinkedListWithElementArray** — Remove node a2 from a doubly linked list (links at a2+88 and a2+92), promote the successor to the list head this+0x28 when a2 is the head, then free a2's trailing counted array (count at a2-4, reverse 96-byte-stride walk calling EmptyStub_7470 per element, block free via FreeWrapper_7bcf); decrements the node counter this+0xC and returns the new count.
- `0x005511A0` **QueueResourceObject** — Object-and-array destructor: frees the single allocated object at this+0x0 (EmptyStub_7470 then FreeWrapper_7bcf, zero the pointer), then destroys the counted 136-byte-element array at this+0x18 (count read from the header DWORD at base-4, reverse EmptyStub_7470 walk, whole-buffer free via FreeWrapper_7bcf, zero the pointer); called by QueueResourceCleanup. The raw source also contains an EmptyStub_0170 call with no callee evidence entry.
- `0x00586DE0` **BitmapRangeMaskBuilder** — Build occupancy bitmask from a bitmap range: read the range index from this+0x44, index the 4-byte descriptor entry (start WORD + count WORD) in the table at this+0x1C, iterate count bit positions from the bitmap at this+0x14, pack set bits into the bitmask result; returns 0 when the descriptor count is zero.

## Proposed classes

### ArrayTeardownHelper

Generic reverse array teardown driver: given a base pointer, element stride and element count, invokes a caller-supplied __thiscall destructor on each element in reverse order and returns the last destructor result (or count-1 when the count is zero). Operates purely on arguments; carries no this state, so it has no fields.

Methods: `0x00401030`


### MilesSoundSystem

Miles (RAD) sound integration object holding the AIL sample-handle array (this+0x48), its count (this+0x4C) and the AIL driver handle (this+0x90); AllocateSampleArray tears down and rebuilds the 20-byte-entry sample array, allocating and initializing AIL sample handles when the driver handle is set. Owner is DERIVED from the packet's ABI lead and the constructor caller; the array block is 20*count+4 bytes allocated via OperatorNewNhMallocWrapper.

Methods: `0x004072E0`

- `this+0x00000048` `pointer sample_array_base` (read_write, DERIVED)
- `this+0x0000004C` `int sample_count` (read_write, DERIVED)
- `this+0x00000090` `pointer driver_handle` (read, DERIVED)

### FilePathEntryTable

Counted table of 200-byte file-path entries with a one-DWORD count header; FilePathEntryArrayDestructor tears down either the whole array (reverse per-element ShortComputation_62a0 then header free) or a single entry, selected by flag bits. Layout is inferred only from the flag-selected destructor; owner is unidentified.

Methods: `0x00408800`


### CollisionShapeGeometry

Physics/collision shape geometry record: discriminator word at this+0x8, subtype/kind constant (3) at this+0x1C and external data pointer at this+0x20 in the header, with collision data (inverse mass 15.0 plus a six-float constant set) populated through CollisionInvMassStore and F_6FieldBulkSetter and an optional ShortComputation_e770 continuation. The packet's function name is a legacy label that conflicts with the collision-shape semantics in the summary.

Methods: `0x0040EB30`

- `this+0x00000008` `word discriminator` (write, DERIVED)
- `this+0x0000001C` `int subtype_kind` (write, DERIVED)
- `this+0x00000020` `pointer external_data_ptr` (write, DERIVED)

### SceneCollisionParameterStore

Scene-scoped collision parameter store: holds a scene count (this+0xD80) and per-scene destination buffers; UpdateSceneCollisionParameters copies two 864-byte parameter blocks from the global unk_7D1448 into this+866 and this+1121, transforming each 27-float sub-element (2*source[9] alongside source[0] and source[18]) via CollisionParameterClampAndStore.

Methods: `0x004532D0`

- `this+0x00000D80` `int scene_count` (read, DERIVED)

### StaticResourceTable

Static/UI resource slot table spanning dword_7CE23C..unk_7CE24C; StaticArrayCleanup double-cleans each non-null slot via ResourceCleanup_cd10, frees it via FreeWrapper_7bcf and zeroes the slot during teardown. Slot element type and owner are unverified; the double-clean is taken from raw source verbatim.

Methods: `0x0049B1C0`


### CountedArrayResource

Resource object owning a counted 120-byte-element array (this+0x10, count this+0xC) plus an optional 3D sound source (this+0x14); ArrayResourceCleanup zeroes the header DWORDs (this+0x0/0x4/0x8) and per-element +100 field, reverse-walks the array calling sub_4A2220 per element, frees the block, and conditionally destroys the 3D sound source when global dword_8AFE88 is set.

Methods: `0x004A29A0`

- `this+0x00000000` `dword header_dword_0` (write, DERIVED)
- `this+0x00000004` `dword header_dword_1` (write, DERIVED)
- `this+0x00000008` `dword header_dword_2` (write, DERIVED)
- `this+0x0000000C` `int element_count` (read_write, DERIVED)
- `this+0x00000010` `pointer array_base` (read_write, DERIVED)
- `this+0x00000014` `pointer sound_source_ptr` (read_write, DERIVED)

### SessionLapData

Session object lap/data record: a -1-filled dword span followed by explicit sentinel state (zeroed this+0x198/0x19C/0x1A0/0x1A8, -1 at this+0x1AC, zero byte at this+0x1B0). LapSessionDataArrayInitializer sets this cleared/default state on session data-loading paths; the -1-filled span is not packet-listed as fields so the entry table shape is unevidenced.

Methods: `0x004C07F0`

- `this+0x00000198` `int sentinel_dword_198` (write, DERIVED)
- `this+0x0000019C` `int sentinel_dword_19C` (write, DERIVED)
- `this+0x000001A0` `int sentinel_dword_1A0` (write, DERIVED)
- `this+0x000001A8` `int sentinel_dword_1A8` (write, DERIVED)
- `this+0x000001AC` `int init_marker_minus_one` (write, DERIVED)
- `this+0x000001B0` `byte init_flag_byte` (write, DERIVED)

### SessionSceneNodeContainer

Session/scene setup container whose linked-list node is validated and initialized on scene setup paths (SessionSceneInitChain, SceneClearReset, SessionInit, sub_4A0760 callers); ArrayCheckInit dereferences the node via LinkedListDereference and routes a non-null node to sub_4C1050, returning 1 on success. Node and container layouts are unidentified.

Methods: `0x004C2810`


### DoublyLinkedListWithElementArray

Doubly linked list whose nodes each carry a counted 96-byte-element trailing array; DoublyLinkedListNodeRemovalWithArrayCleanup unlinks a node, promotes the successor to the head (this+0x28) when needed, reverse-walks and frees the node's element array, and decrements the node counter (this+0xC). Node layout (links at node+88/+92, count header at node-4) is known only as offsets from raw source.

Methods: `0x005478B0`

- `this+0x00000028` `pointer list_head` (write, DERIVED)
- `this+0x0000000C` `int node_count` (read_write, DERIVED)

### QueueResourceObject

Queued resource object owning a single child object (this+0x0) and a counted 136-byte-element array (this+0x18); ObjectDestructorWithArrayCleanup frees both, reverse-walking the array via EmptyStub_7470 and freeing the block via FreeWrapper_7bcf. Called from QueueResourceCleanup to tear down a queued resource object; the raw source also contains an unaddressed EmptyStub_0170 call.

Methods: `0x005511A0`

- `this+0x00000000` `pointer child_object_ptr` (read_write, DERIVED)
- `this+0x00000018` `pointer array_base` (read_write, DERIVED)

### BitmapRangeMaskBuilder

Bitmap range-index object: a descriptor table (this+0x1C) of 4-byte start/count entries indexed by this+0x44, backed by a bitmap at this+0x14; BitmaskGenerationFromBitArray packs the range's set bits into a mask, returning 0 when the descriptor count is zero.

Methods: `0x00586DE0`

- `this+0x00000044` `int range_index` (read, DERIVED)
- `this+0x0000001C` `pointer descriptor_table_base` (read, DERIVED)
- `this+0x00000014` `pointer bitmap_base` (read, DERIVED)

## Compatibility contracts

- **ReverseElementTeardownSemantics** — Counted-array teardown must invoke the per-element cleanup in reverse element order before freeing the allocation block. The concrete instantiations read the element count from the DWORD header at base-4 (stride 200 for 0x00408800, 120 for 0x004A29A0, 96 for 0x005478B0, 136 for 0x005511A0) and free the block including the header via FreeWrapper_7bcf; the generic driver 0x00401030 returns the last destructor result, or count-1 when the count is zero.
- **AILSampleArrayLifecycle** — The Miles sample array must preserve the packet's entry layout (20 bytes per entry, AIL sample handle stored at entry+16), the teardown order (per-entry virtual release, AIL_release_sample_handle on the handle, then header free via FreeWrapper_7bcf), and the rebuild rule: allocation block size 20*count+4, with AIL_allocate_sample_handle (0x0059E3EC) plus AIL_init_sample (0x0059E3DC) applied to each entry only when the driver handle (this+0x90) is set.
- **CollisionShapeHeaderLayout** — Collision shape initialization must keep the discriminator word at base+0x8, the subtype/kind constant 3 at base+0x1C and the external data pointer at base+0x20, and populate the collision data with the inverse-mass scalar 15.0 plus the six-float constant set through CollisionInvMassStore (0x00459950) and F_6FieldBulkSetter (0x00459990); when the continuation flag is non-zero, ShortComputation_e770(this, a4, 0) runs and its result is returned.
- **SceneCollisionParameterTransform** — Scene collision parameter copy must preserve the documented transform: two 864-byte source blocks of the global unk_7D1448, 8 sub-elements per block at a 27-float stride, destination offsets base+866 (first pass) and base+1121 (second pass), and per sub-element a computed value of 2*source[9] stored together with source[0] and source[18] via CollisionParameterClampAndStore (0x0044FC20).

## Unresolved

- Cross-function equal offsets on the same 'this' label are NOT proven to be the same object, and the packet gives no common-ownership evidence, so each class keeps its own field entries: field:this:0x00000000 and 0x00000018 appear in both 0x004A29A0 (CountedArrayResource) and 0x005511A0 (QueueResourceObject); 0x00000008 in 0x0040EB30 and 0x004A29A0; 0x0000000C in 0x004A29A0 and 0x005478B0; 0x00000014 in 0x004A29A0 and 0x00586DE0.
- The function name for 0x0040EB30 ('CameraProjectionMatrixInitWithFloatConstants') conflicts with its packet summary, which describes a physics/collision shape initializer storing subtype 3 and inverse mass 15.0; the collision-shape semantics are DERIVED from operations, and the name is treated as a legacy/ABI label.
- The exact float semantics of the constant bit patterns passed to CollisionInvMassStore (0x00459950) and F_6FieldBulkSetter (0x00459990) are not interpretable from this packet.
- The purpose of the destination buffers this+866 and this+1121 in 0x004532D0, and why the source-block index (0 or 1) selects 864-byte regions of the global unk_7D1448, are unknown.
- Per-element cleanup callbacks ShortComputation_62a0 (0x004562A0), sub_4A2220 (0x004A2220) and EmptyStub_7470 (0x00557470), and the double-cleaned ResourceCleanup_cd10 (0x004DCD10), are known only as callee addresses; element types and cleanup semantics are unverified.
- The allocation header pattern (count DWORD at base-4) is read in raw source by 0x00408800, 0x005478B0, 0x005511A0 and 0x004A29A0 but is not a declared packet field, so it is not placed as a class field.
- 0x005511A0's raw source contains a call to EmptyStub_0170 that has no callee evidence entry or address in the packet; its purpose is unknown.
- The node layout for 0x005478B0 (links at node+88/+92, 96-byte element stride) and the flag semantics (bits 0x1 and 0x2) for 0x00408800 are inferred from the branch structure only.
- The dword span filled with -1 by the 48-iteration pair loop in 0x004C07F0 is not packet-listed as fields, so it has no field evidence refs; the element count and stride of that -1-filled table are unevidenced.
- The role of global dword_8AFE88 gating the 3D sound-source destruction in 0x004A29A0 is unknown.
- The meaning of the bitmask built by 0x00586DE0 and of the descriptor start/count entries depends on caller 0x00587730's usage, which is not in the packet.
- All packet owners except MilesSoundSystem are UnknownObject; class names (FilePathEntryTable, StaticResourceTable, SessionLapData, SessionSceneNodeContainer, QueueResourceObject, DoublyLinkedListWithElementArray) are DERIVED/GUESS proposals, not confirmed source names.
- The AIL globals 0x0059E3DC/EC/F0 are treated as function pointers invoked as calls; the packet lists them as globals, so their function-pointer nature is DERIVED.
- The raw source for 0x004072E0 is elided after AIL_allocate_sample_handle; the exact per-entry call ordering after the elision is not fully visible.
