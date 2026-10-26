# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

This scope covers generic runtime infrastructure rather than domain gameplay. The strongest structural signal is a repeated singly-linked-list idiom: a 16-byte control block (head@+0x0, tail@+0x4, cursor@+0x8, count@+0xC) over 12-byte nodes (data@+0x0, next@+0x4, owns-data flag@+0x8), destroyed by a family of SEH-protected walkers that run a callback on flagged data before freeing it (0x00582FD0, 0x005833E0, 0x00585FB0, 0x00586240, 0x00586170), a variant that releases via the data object's vtable slot +4 (0x00583050), a block-releasing variant driven by NTimeCallbackLoopWithSEH (0x00583570), plus node removal (0x00583430) and node append (0x00586000). A second thread around a high-resolution timer object (float value@+0x0, QPC double base@+0x4) is evidenced by 0x00583660, 0x00583680 and 0x00583690 calling the QPC helpers 0x00568C60/0x00568CF0/0x00568D90. Synchronization appears as a mutex pair/list initializer (0x00585EA0), a 1 ms mutex flush/yield gate (0x005840D0, mutex at this+0xD4) and guarded OS-handle close slots inside a large complex object destroyed by 0x00583AE0 and whose node pool is managed by 0x00584130 (with the dual-list sub-object built by 0x00586320). Loose virtual dispatch helpers (0x005853B0, 0x00585400, 0x00585BF0) route work through fixed vtable slots; 0x00585BF0 is the only function whose owner the packet classifies DERIVED (TriggerDispatcher). Everything else in this packet carries an UNKNOWN owner, so every class here is a DERIVED/GUESS grouping justified by shared offsets, shared callees and shared control flow, never by proven identity.

## Function roles

- `0x00582FD0` **SinglyLinkedList** — Destroy the linked list: for each node with the flag byte set, run SEHGuardedFunctionWithExceptionHandling on the node data, free the data when non-null, free the node, then clear head/tail/iterator/count and return 0.
- `0x00583050` **SinglyLinkedList** — Destroy the linked list: for each flagged node with non-null data, invoke the data object's virtual release at vtable+4 with argument 1, free the node via FreeWrapper_7bcf, under SEH handler 0x0059CE08, then zero head/tail/iterator/count.
- `0x005833E0` **SinglyLinkedList** — Destroy the linked list (SEH-cleanup variant): free flagged node data via the SEH-guarded callback then FreeWrapper_7bcf, free every node, zero the container fields and return 0; called by 0x00583AE0.
- `0x00583430` **SinglyLinkedList** — Remove the first node whose data pointer matches the key; fix up head/tail/cursor/count, optionally clear the node flag, run the SEH-guarded cleanup on flagged data, free data and node; called by the network packet queue reader path.
- `0x00583570` **SinglyLinkedList** — Destroy the linked list (block-release variant): for each flagged node, run NTimeCallbackLoopWithSEH over the data block with entry size 4156, count read from block-4 and the EmptyStub_aa60 callback, then free block and node; zero the four container dwords.
- `0x00583660` **HiResTimer** — Store the value parameter into the object's first dword and reset the high-precision timer sub-object at this+4 via TimerResetUsingQueryPerformanceCounter; called by timer-init and thread-resume paths.
- `0x00583680` **HiResTimer** — Read the accumulated timer as float at this+0 plus the scaled QPC difference on the double at this+4; used by the mutex-guarded and thread-resume timer read paths.
- `0x00583690` **HiResTimer** — Wrapper that forwards the object's timer-delta double member at this+4 to HighResolutionTimerDelta; called by the thread start path.
- `0x005836A0` **LargeInitializedState** — Constructor-style initializer that zero-fills a large object (explicit dwords/word/byte clears plus a 0xFC-byte memset at this+8) and returns this; called by 0x005837F0.
- `0x005836E0` **CounterLatchState** — Counter helper: store two latched values into this+4/this+8, increment the counter at this+0, write it out through the output pointer and return it; called by the animation-timing update path 0x0057A5A0.
- `0x00583AE0` **ComplexResourceObject** — Complex object destructor: install destructor vtable 0x005B8B60, migrate a sub-object list, close and zero eight guarded OS handle slots, re-initialize a sub-object, destroy linked lists, clean up sub-object lists, then run a timed SEH-protected callback loop.
- `0x005840D0` **WorkerMutexGate** — Mutex flush/yield gate: wait on the mutex handle at this+0xD4 with a 1 ms timeout and, on success, release it and return the release result; called by the thread start path 0x00583D90.
- `0x00584130` **ComplexResourceObject** — Search a node list for a node whose id matches a3, else take a node from the pool list (with pool reset on validation failure), set the node back-pointer, append it, record a3 at +0x410 and run the per-node step; invoked by 0x00585270.
- `0x00584FF0` **NameBufferHolder** — Copy up to 16 characters from the source into the internal buffer at this+0x64 via the capped copy helper and force a null terminator at this+0x74; returns the source pointer.
- `0x00585030` **VirtualDispatchOperationHandler** — Forwarding wrapper: copy the stack argument block into the object region at this+0x2C via ByteAlignedMemoryCopyWithOffset and return the callee pointer result; dispatched by 0x0057A4F0.
- `0x005853B0` **AsyncWorkItem** — Asynchronous work-pipeline step: invoke vtable slot +0x3C, queue an APC, pop a node from a list, process it and hand it to vtable slot +0x5C; returns 0 when the pop fails; called by 0x0057A760.
- `0x00585400` **BitmapSlotRouter** — Conditional dispatcher: on a successful bitmap-range occupancy test append via a list helper, otherwise route through vtable slot +0x2C, a processing helper and vtable slot +0x5C; always returns 1.
- `0x00585860` **VirtualDispatchOperationHandler** — Single-field setter: store a2 into the object field at this+0x60 and return 1; dispatched by 0x0057A4F0.
- `0x00585BF0` **TriggerDispatcher** — Per-tick trigger dispatch: iterate a trigger collection through the object's vtable (slots +0xC8/+0x1C/+0xA4/+0xAC), build handler arguments from query and field helpers, invoke the handler table slot, release and end iteration; called by 0x0057A800.
- `0x00585E50` **GuardedStaticInitScope** — Compiler-style guarded static-initialization wrapper: register an SEH frame from the handler table at 0x008D3E2C, run a one-time guard on the init counter and construct seven static objects linked into the parent exception frame.
- `0x00585EA0` **MutexProtectedList** — Initialize a mutex-pair/list object: clear two pointer slots and two state flags, set two INFINITE timeouts, create two anonymous inheritable mutexes via CreateMutexA storing handles and created flags; returns this.
- `0x00585FB0` **SinglyLinkedList** — Clean up a linked list: per flagged node call the stub then free data when non-null, free every node, clear head/tail/iterator/count and return 0; called by 0x00583AE0.
- `0x00586000` **SinglyLinkedList** — Singly-linked list append: allocate a 12-byte node, store payload, zero next, set the flag byte, link as new tail, bump the count and return 1 (0 when the payload is null).
- `0x00586170` **HandleGuardedList** — Teardown: close the owned handle at this+0x10 when the flag at this+0x18 is set, then walk-destroy the list with the SEH-guarded data cleanup and zero the list fields.
- `0x00586240` **SinglyLinkedList** — Destroy a linked list under SEH record 0x0059D138: per flagged node call the stub then free data, free every node, zero the four list-management fields and return 0.
- `0x00586320` **DoubleListBuffer** — Build two intrusive linked lists over a 2100-byte buffer: allocate a wrapper and the buffer, run NTimeCallbackLoopWithSEH_a6eb with the buffer init callback, link one flagged node into list 1 and two nodes into list 2; called once by 0x00584130.

## Proposed classes

### SinglyLinkedListNode

12-byte node element used by the list containers in this scope: payload pointer, next link and an owns-data flag byte that selects SEH-guarded cleanup.

Methods: 

- `obj+0x00000000` `void* data_ptr` (read_write, DERIVED)
- `obj+0x00000004` `SinglyLinkedListNode* next` (read_write, DERIVED)
- `obj+0x00000008` `bool owns_data_flag` (read, DERIVED)
- `obj+0x0000000C` `void* metadata_or_padding` (unknown, UNKNOWN)

### SinglyLinkedList

SEH-managed singly-linked list: 16-byte control block (head/tail/cursor/count) over 12-byte nodes; destruction walks free flagged node data under an exception guard before releasing nodes.

Methods: `0x00582FD0`, `0x00583050`, `0x005833E0`, `0x00583430`, `0x00583570`, `0x00585FB0`, `0x00586000`, `0x00586240`

- `this+0x00000000` `SinglyLinkedListNode* head` (read_write, DERIVED)
- `this+0x00000004` `SinglyLinkedListNode* tail` (read_write, DERIVED)
- `this+0x00000008` `SinglyLinkedListNode* cursor` (read_write, GUESS)
- `this+0x0000000C` `unsigned int count` (read_write, DERIVED)

### HandleGuardedList

List container extended with a guarded OS handle at +0x10 (validity flag at +0x18) that is closed before the list is destroyed.

Methods: `0x00586170`

- `this+0x00000000` `SinglyLinkedListNode* head` (read, DERIVED)
- `this+0x00000004` `SinglyLinkedListNode* tail` (read, GUESS)
- `this+0x00000008` `SinglyLinkedListNode* cursor` (read, GUESS)
- `this+0x0000000C` `unsigned int count` (read, GUESS)
- `this+0x00000010` `HANDLE owned_handle` (read_write, DERIVED)
- `this+0x00000018` `bool handle_valid_flag` (read, DERIVED)

### MutexProtectedList

Object pairing two anonymous mutexes (handles at +0xC/+0x1C, created flags at +0x14/+0x24, INFINITE timeouts at +0x10/+0x20) with two list/pointer slots and state flags, initialized by 0x00585EA0.

Methods: `0x00585EA0`

- `this+0x00000000` `void* list1_head` (write, GUESS)
- `this+0x00000004` `void* list1_aux` (write, GUESS)
- `this+0x00000008` `bool list1_state_flag` (write, GUESS)
- `this+0x0000000C` `HANDLE mutex1_handle` (write, DERIVED)
- `this+0x00000010` `unsigned int mutex1_timeout` (write, DERIVED)
- `this+0x00000014` `bool mutex1_created_flag` (write, DERIVED)
- `this+0x00000018` `bool list2_state_flag` (write, GUESS)
- `this+0x0000001C` `HANDLE mutex2_handle` (write, DERIVED)
- `this+0x00000020` `unsigned int mutex2_timeout` (write, DERIVED)
- `this+0x00000024` `bool mutex2_created_flag` (write, DERIVED)

### DoubleListBuffer

Sub-object holding two intrusive linked lists (list 1 at +0x0..+0xC, list 2 at +0x10..+0x1C) built over a 2100-byte buffer initialized through the timed callback loop; 0x00586320 is its constructor and the pool lists used by ComplexResourceObject at parent+0xFC.

Methods: `0x00586320`

- `this+0x00000000` `void* list1_head` (write, GUESS)
- `this+0x00000004` `void* list1_tail` (write, GUESS)
- `this+0x00000008` `void* list1_cursor` (write, GUESS)
- `this+0x0000000C` `unsigned int list1_count` (write, GUESS)
- `this+0x00000010` `void* list2_head` (write, GUESS)
- `this+0x00000014` `void* list2_tail` (write, GUESS)
- `this+0x00000018` `void* list2_cursor` (write, GUESS)
- `this+0x0000001C` `unsigned int list2_count` (write, GUESS)

### ComplexResourceObject

Large multi-sub-object resource owner: eight guarded OS handle slots (each with a paired validity flag), a node-pool list and sub-object list with iterators, a destructor that migrates/closes/cleans everything (0x00583AE0) and a node search-or-allocate path (0x00584130).

Methods: `0x00583AE0`, `0x00584130`

- `this+0x00000000` `void* vtable_ptr` (read_write, DERIVED)
- `this+0x000000D4` `HANDLE handle_slot_0` (read_write, DERIVED)
- `this+0x000000DC` `bool handle_flag_0` (read_write, DERIVED)
- `this+0x000000F0` `HANDLE handle_slot_1` (read_write, DERIVED)
- `this+0x000000F8` `bool handle_flag_1` (read_write, DERIVED)
- `this+0x00000570` `HANDLE handle_slot_2` (read_write, DERIVED)
- `this+0x00000578` `bool handle_flag_2` (read_write, DERIVED)
- `this+0x0000058C` `HANDLE handle_slot_3` (read_write, DERIVED)
- `this+0x00000594` `bool handle_flag_3` (read_write, DERIVED)
- `this+0x000005A8` `HANDLE handle_slot_4` (read_write, DERIVED)
- `this+0x000005B0` `bool handle_flag_4` (read_write, DERIVED)
- `this+0x000005B8` `HANDLE handle_slot_5` (read_write, DERIVED)
- `this+0x000005C0` `bool handle_flag_5` (read_write, DERIVED)
- `this+0x00000618` `HANDLE handle_slot_6` (read_write, DERIVED)
- `this+0x00000620` `bool handle_flag_6` (read_write, DERIVED)
- `this+0x00000640` `HANDLE handle_slot_7` (read_write, DERIVED)
- `this+0x00000648` `bool handle_flag_7` (read_write, DERIVED)
- `this+0x0000010C` `void* node_pool_list` (read_write, DERIVED)
- `this+0x00000114` `void* node_pool_cursor` (read_write, DERIVED)
- `this+0x0000011C` `void* subobject_list` (read_write, DERIVED)
- `this+0x00000124` `void* subobject_list_cursor` (read_write, DERIVED)
- `this+0x00000128` `void* unknown_field` (unknown, UNKNOWN)

### HiResTimer

High-resolution timer object: float value/accumulator at +0x0 and a QPC-based double base at +0x4, manipulated through the QPC helpers 0x00568C60/0x00568CF0/0x00568D90.

Methods: `0x00583660`, `0x00583680`, `0x00583690`

- `this+0x00000000` `float value_or_accumulator` (read_write, DERIVED)
- `this+0x00000004` `double qpc_base_double` (read_write, GUESS)

### WorkerMutexGate

Mutex flush/yield gate: waits on a mutex handle at this+0xD4 with a 1 ms timeout and releases when acquired; used by the thread start path.

Methods: `0x005840D0`

- `this+0x000000D4` `HANDLE mutex_handle` (read, DERIVED)

### AsyncWorkItem

Asynchronous worker step that dispatches through vtable slot +0x3C, queues an APC, pops a node from a list, processes it and hands it to vtable slot +0x5C.

Methods: `0x005853B0`

- `obj+0x0000003C` `void (*)(void*) dispatch_slot` (read, GUESS)
- `obj+0x0000005C` `void (*)(void*, void*) consume_slot` (read, GUESS)

### BitmapSlotRouter

Conditional dispatcher that appends on a successful bitmap-range occupancy test or routes through vtable slots +0x2C and +0x5C otherwise.

Methods: `0x00585400`

- `obj+0x0000002C` `void (*)(void*, unsigned int) route_slot` (read, GUESS)
- `obj+0x0000005C` `void (*)(void*, unsigned int) consume_slot` (read, GUESS)

### TriggerDispatcher

Per-tick trigger iteration and handler dispatch over a collection reached through the object's vtable (begin/current/count/predicate/release/end slots); the only owner in this scope the packet classifies DERIVED.

Methods: `0x00585BF0`

- `obj+0x00000000` `void* vtable_ptr` (read, DERIVED)
- `obj+0x0000001C` `void* (*)(void*) current_item_slot` (read, GUESS)
- `obj+0x00000020` `void (*)(void*) release_item_slot` (read, GUESS)
- `obj+0x000000A4` `int (*)(void*) item_count_slot` (read, GUESS)
- `obj+0x000000AC` `bool (*)(void*, int) predicate_slot` (read, GUESS)
- `obj+0x000000C8` `void (*)(void*) begin_iteration_slot` (read, GUESS)
- `obj+0x000000CC` `void (*)(void*) end_iteration_slot` (read, GUESS)

### VirtualDispatchOperationHandler

Dispatched virtual operations on a common object, both invoked by VirtualFunctionDispatchWithStackFrames: copy the stack argument block into +0x2C, or store a scalar into +0x60.

Methods: `0x00585030`, `0x00585860`

- `obj+0x0000002C` `void* copy_region` (write, GUESS)
- `this+0x00000060` `unsigned int field_60` (write, DERIVED)

### NameBufferHolder

Object with an internal 16-byte name buffer at +0x64 (null terminator forced at +0x74) filled through the capped copy helper.

Methods: `0x00584FF0`

- `this+0x00000064` `char[16] name_buffer` (write, DERIVED)
- `this+0x00000074` `char name_null_terminator` (write, DERIVED)

### CounterLatchState

Small counter object holding a counter at +0x0 and two latched values at +0x4/+0x8, updated by the animation-timing helper 0x005836E0.

Methods: `0x005836E0`

- `this+0x00000000` `unsigned int counter` (read_write, DERIVED)
- `this+0x00000004` `unsigned int latch_a` (write, DERIVED)
- `this+0x00000008` `unsigned int latch_b` (write, DERIVED)

### LargeInitializedState

Large object whose constructor-style initializer zero-fills a set of scattered fields and a 0xFC-byte block; the fields' semantic roles are not established in this scope.

Methods: `0x005836A0`

- `this+0x00000000` `unsigned int dword_0` (write, DERIVED)
- `this+0x00000004` `unsigned int dword_1` (write, DERIVED)
- `this+0x00000008` `unsigned int dword_2` (write, DERIVED)
- `this+0x0000000C` `unsigned char byte_0C` (write, DERIVED)
- `this+0x00000010` `unsigned int dword_4` (write, DERIVED)
- `this+0x00000014` `unsigned int dword_5` (write, DERIVED)
- `this+0x00000018` `unsigned int dword_6` (write, DERIVED)
- `this+0x0000001C` `unsigned int dword_7` (write, DERIVED)
- `this+0x0000011C` `unsigned short word_11C` (write, DERIVED)
- `this+0x0000011E` `unsigned char byte_11E` (write, DERIVED)
- `this+0x00000120` `unsigned int dword_120` (write, DERIVED)

### GuardedStaticInitScope

Compiler-style guarded one-time static-initialization scaffolding: SEH frame setup, a one-time guard on a global init counter, and construction of seven static objects linked into the parent exception frame.

Methods: `0x00585E50`


## Compatibility contracts

- **SinglyLinkedListNodeLayout** — Replacement code that owns these lists must preserve the 12-byte node layout: payload pointer at +0x0, next pointer at +0x4, owns-data flag byte at +0x8; flagged nodes have their data released through the SEH-guarded callback before the node is freed.
- **ListContainerControlBlock** — The list container control block is four dwords at base+0x0 (head), +0x4 (tail), +0x8 (cursor) and +0xC (count); destroy paths clear all four after the walk and append/remove update them.
- **OSHandleLifecycle** — Handles are created through CreateMutexA (0x0059E1AC), waited on through WaitForSingleObject (0x0059E1A0), released through ReleaseMutex (0x0059E1A4) and closed through CloseHandle (0x0059E1A8); guarded handle slots pair the handle with a validity byte that gates closing.
- **SEHRegisteredFrames** — Several container and init functions register SEH frames whose handler records are the globals 0x0059CDE8, 0x0059CE08, 0x0059D046, 0x0059D138, 0x0059D166 and 0x00583AA0; a replacement must keep the destruction/cleanup exception-safe against the same failure points.
- **HiResTimerQPCBase** — The timer object stores a float value at +0x0 and a double QPC base at +0x4; accumulated reads add the scaled QPC difference to the float and resets re-arm the base through the 0x00568C60/0x00568CF0/0x00568D90 helpers.

## Unresolved

- Almost every owner in this packet is UNKNOWN; every class here is a DERIVED/GUESS grouping justified by shared offsets, shared callees and shared control flow. Equal offsets on different bases are structural parallels, not proven identity.
- this+0xD4 is read as a mutex handle by 0x005840D0 and closed as a guarded handle slot by 0x00583AE0's destructor; the two functions may share an owner but the packet does not prove common ownership, so they are modeled as separate classes.
- The 16-byte list control layout (head/tail/cursor/count) recurs in SinglyLinkedList, HandleGuardedList, MutexProtectedList and DoubleListBuffer at overlapping offsets; the packet proves each function walks the same node idiom but not that the containing classes are identical.
- The vtable slot semantics at obj+0x1C/0x20/0x2C/0x3C/0x5C/0xA4/0xAC/0xC8/0xCC and the data-object vtable+4 release are object-type dependent and unresolved.
- The node field at +0xC is recorded by the corpus but has no direct access in the raw sources of this scope; it is modeled as UNKNOWN metadata/padding.
- The double at HiResTimer+0x4 has no packet field evidence reference, only raw source text; whether the float at +0x0 is a running accumulator or a fixed offset is unproven.
- The 0xFC-byte memset block in 0x005836A0 overlaps the explicitly cleared fields; the relationship between the memset region and the fields at 0x11C/0x11E/0x120 is not established.
- 0x00586320's list offsets (+0x0..+0x1C) are relative to the sub-object at parent+0xFC, not to the parent base; the embedding of DoubleListBuffer inside ComplexResourceObject is inferred from 0x00584130 calling 0x00586320 with this+63.
- Three write-only globals 0xFF00000000005450/0xFF00000000005451/0xFF00000000005452 appear in the 0x00585EA0 packet with write access but never in the decompiled source; their purpose is unexplained.
- The guarded static-init helpers sub_59A54D and sub_59A5E9 and the seven constructed static objects in 0x00585E50 are opaque at this scope.
- The count passed to NTimeCallbackLoopWithSEH by 0x00583570 is read from the 4 bytes preceding the data block base; that offset is not in the packet field evidence.
- 0x00583050's argument 1 to the vtable+4 call and the exact semantics of the node flag byte and SEH cleanup callback are defined by the data owner, not by these list functions.
- The list append count dword at +0xC is classified read in the packet field table although 0x00586000 increments it; the classification may predate the write.
- Callers outside this scope (0x0057A4F0, 0x0057A5A0, 0x0057A760, 0x0057A800, 0x005835F0, 0x005837F0, 0x00583D90, 0x00584F90, 0x00585270, 0x00585680) are referenced by evidence only; their object ownership is not resolved here.
