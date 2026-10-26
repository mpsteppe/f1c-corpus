# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

The packet covers 25 generic runtime helpers with a common shape: small free functions and accessors operating on unknown owner objects through fixed field offsets. Four families dominate. (1) Linked-list infrastructure: a 12-byte node (value at +0, next at +4, cleanup flag byte at +8) managed by a container holding head/tail/iterator/count at +0/+4/+8/+0xC, with alloc-prepend (0x00583210), removal-by-value (0x005817A0) and head-removal-with-cleanup (0x00582EB0); a mutex-guarded container variant embeds the same list at this+0x544 (and a sibling instance at this+0x560) with append (0x00584C70) and pop-first (0x00584CD0, 0x00584E30) helpers. (2) Mutex-guarded shared-state accessors that wait (accepting wait result 0 and 128), touch a protected field, then release: pointer read (0x00585D20), field write (0x005857C0), timer read (0x00584F90), plus network connection teardown (0x0057DE30) under three mutexes. (3) A vtable-dispatch cluster (0x00585220, 0x00585270, 0x00585380, 0x00585870) that routes objects through vtable slots at offsets +0x38/+0x5C/+0x94/+0xA4/+0xA8 and a decode chain (+0x1C/+0x20/+0xAC/+0xB4/+0xC8/+0xCC), feeding a trigger/decode queue processor. (4) Small utility shims: callback-block allocator (0x005830C0), timer init (0x005835F0), input state updater with payload copy (0x00583700), list builder (0x00583530), list walker with dispatch (0x00585320), APC queue (0x00585DE0), global chain init (0x00585E10), pointer-array cleanup (0x005867B0), and copy wrappers (0x00586A00, 0x00586A10). All owner identities are UNKNOWN in the packet; the classes below are worker GUESS groupings of structurally coherent functions, not recovered class names.

## Function roles

- `0x0057DE30` **ConnectionManager** — Network connection teardown: unlink the connection node from the active list under mutex1, run the node destructor and free it, optionally zero a struct field under mutex2, gracefully close the socket, reset the ring buffer and connection fields under mutex3, reprepend the node to the free list, then invoke the vtable callback at +0x94 when the struct path ran.
- `0x005817A0` **LinkedListContainer** — Singly-linked-list removal by node value: walk from head matching node whose +0 value equals a2, splice it out updating head/tail/iterator/count, clear or honor the +8 flag, free the value when the flag is set, free the node, return 1 (0 on absent/empty paths).
- `0x00582EB0` **LinkedListContainer** — Linked-list head-node removal with cleanup callback: snapshot head data, clear the head cleanup flag, scan for a matching node, unlink it updating head/tail/iterator/count, free data (flag-and-non-null gated) and the node, return the removed data value (0 on empty/absent paths).
- `0x005830C0` **CallbackBlockAllocator** — Socket-address callback-block allocator: allocate an 8316-byte block holding two 4156-byte entries, write entry count 2 into the header, initialize entries through NTimeCallbackLoopWithSEH using SocketAddressInit/EmptyStub callbacks, store block+4 into this[0] (0 on allocation failure), return this.
- `0x00583210` **LinkedListContainer** — Linked-list node alloc-and-prepend: allocate a 12-byte node, set value=+0, next=+4=0, flag=+8=a3, prepend to the container head/tail/count at +0/+4/+8/+0xC, return 1 (0 when payload is null).
- `0x00583530` **ListBuilder** — Linked-list node builder: append node (a2, 1) through the append callee, then prepend two nodes carrying *a2 and *a2+4156 into a list anchored at this+4 (loop step 4156, bound 8312).
- `0x005835F0` **HighResolutionTimer** — High-precision timer initialization: zero the timer data region, configure the QueryPerformanceCounter timer with flag 1, apply the timing float parameter, return this.
- `0x00583700` **InputStateSlot** — Input/event state updater with optional payload copy: guard on type id at +0 and time delta at +4 below 2.0, store the packed double at +0x10/+0x14, set the update flag byte at +0xC, write the blended double v6*0.5+a4 at +0x18, then store/copy a bounded payload into +0x20/+0x120 or clear the size.
- `0x00584C70` **MutexGuardedListContainer** — Mutex-guarded list append: acquire the mutex at this+0x554 with timeout this+0x558, append the node through the append callee, release the mutex, return the append success flag.
- `0x00584CD0` **MutexGuardedListContainer** — Thread-safe pop of the first list node: wait on the mutex at this+0x554 (timeout this+0x558), unlink the head updating head/tail/iterator/count at 0x544/0x548/0x54C/0x550, process-and-free the node data under SEH when the +8 flag is set, free the node, write the popped value to *a2.
- `0x00584E30` **MutexGuardedListContainer** — Variant of the mutex-guarded list pop with higher field offsets: wait on the mutex at this+0x570 (timeout this+0x574), unlink the head updating 0x560/0x564/0x568/0x56C, process-and-free the node data under SEH when the +8 flag is set, free the node, write the popped value to *a2.
- `0x00584F90` **MutexGuardedTimerReader** — Thread-safe timer read: acquire the mutex at this+0xD4 (timeout this+0xD8), read the accumulated timer double through the timer-read callee (NULL timer when the wait is blocked), release the mutex, return the value.
- `0x00585020` **DispatchManager** — Trivial pointer accessor: return the receiver advanced by 100 bytes (this + 0x64), exposing that member region as a sub-object pointer; used by callers as an accessor.
- `0x00585220` **DispatchManager** — Status query with dual condition: optionally write the status byte at this+0x5D through a2, compute (vtable-slot-+0xA4 result on this) < (threshold at this+0x60), optionally write it through a3, return the conjunction.
- `0x00585270` **DispatchManager** — Iterate items from a container and route each through the collect callee, then perform a final vtable dispatch: skip to an alternate conditional-append dispatch when the predicate callee returns non-zero; otherwise iterate via one of two vtable protocols (a1 slots +0xA4/+0xA8, or v5 slots +0x14/+0x18) calling the collect callee per item, then dispatch vtable slot +0x5C.
- `0x00585320` **ListDispatchWalker** — Walk a singly linked list (head at this+0x11C, iterator at this+0x124); for each node whose getter value is not -1, call the dispatch callback and clear the node field via the field setter (-1); return the final iterator pointer.
- `0x00585380` **DispatchManager** — Conditional list-append followed by unconditional vtable dispatch: initialize result to 2, append a2 via the mutex-guarded append callee (result 0) when a2 is non-null, always dispatch vtable slot +0x38, return 0 (appended) or 2 (skipped).
- `0x005857C0` **SharedPointerState** — Thread-safe field write: acquire the mutex at this+0xF0 (timeout this+0xF4), write a2 to the integer field at this+0xEC, release the mutex, return a pointer to the written field.
- `0x00585870` **DispatchManager** — Trigger/event decode-queue processor: release the guarded pointer, read the current object index, initialize scratch state, acquire the decode mutex at this+0x640 (timeout this+0x644), iterate objects through vtable slots (+0xA4 count, +0x1C next, +0xAC predicate, +0x20 release, +0xC8 begin, +0xCC end), collect qualifying objects into 12-byte nodes, walk the chain feeding a decompression decode pipeline (slots +0x5C, +0xB4), tear nodes down, run the tail mutex release when the header-copy path ran, and re-establish the vtable on the header buffer.
- `0x00585D20` **SharedPointerState** — Thread-safe pointer read: acquire the mutex at this+0x5B8 (timeout this+0x5BC), read the pointer at this+0x5B4 under protection, release the mutex, return the read pointer value.
- `0x00585DE0` **APCQueueScheduler** — Queue an asynchronous procedure call: QueueUserAPC(global APC routine 0x0041A160, thread handle at this+0x4, this as ULONG_PTR parameter); return the QueueUserAPC result.
- `0x00585E10` **GlobalChainInitializer** — Module init thunk with reference-counted once-guard: on first entry construct a chain of seven linked global objects (vtable/SEH-chain and locale-style objects) into static buffers, wiring them at vtable-derived offsets; later entries only increment the guard.
- `0x005867B0` **PointerArrayCleanupHelper** — Cleanup helper on a pointer array: free the dual-pointer block at this+5 via the dual-pointer free, then free the single pointer at this+2 via the free-if-nonnull helper and return its result.
- `0x00586A00` **CopyBufferShim** — Trivial forwarding wrapper: forward both arguments unchanged to the realloc-like copy callee and return its result verbatim.
- `0x00586A10` **CopyBufferShim** — Bounded memory copy with size validation: validate the incoming size against the stored limit field, resolve the source pointer and effective size, copy into the caller destination, optionally report the copied size back; return 4/1/0 for the failure and success paths.

## Proposed classes

### ConnectionManager

Owns the network connection lifecycle: an active connection-node list (head/iterator/tail/count) and a node free list, guarded by three mutexes, with socket teardown and ring-buffer reset, and a vtable callback at +0x94 invoked at the end of teardown.

Methods: `0x0057DE30`

- `this+0x00000000` `pointer vtable_ptr` (read, GUESS)
- `this+0x00000AAC` `pointer active_list_head` (read_write, DERIVED)
- `this+0x00000AB0` `pointer active_list_iterator` (read_write, DERIVED)
- `this+0x00000AB4` `pointer active_list_tail` (read_write, DERIVED)
- `this+0x00000AB8` `dword active_list_count` (read_write, DERIVED)
- `this+0x00000ABC` `handle mutex_active_list` (read_write, DERIVED)
- `this+0x00000AC0` `dword mutex_active_list_timeout` (read, DERIVED)
- `this+0x00000AD8` `handle mutex_struct_field` (read_write, DERIVED)
- `this+0x00000ADC` `dword mutex_struct_field_timeout` (read, DERIVED)
- `this+0x00000BEC` `handle mutex_state` (read_write, DERIVED)
- `this+0x00000BF0` `dword mutex_state_timeout` (read, DERIVED)

### LinkedListContainer

Singly-linked-list container holding head/tail/iterator/count and offering node alloc-prepend, removal-by-value, and head-removal-with-cleanup on 12-byte nodes.

Methods: `0x00583210`, `0x005817A0`, `0x00582EB0`

- `this+0x00000000` `pointer head` (read_write, DERIVED)
- `this+0x00000004` `pointer tail` (read_write, DERIVED)
- `this+0x00000008` `pointer iterator` (read_write, DERIVED)
- `this+0x0000000C` `dword count` (read_write, DERIVED)

### LinkedListNode

12-byte node type shared by the list helpers: value/data at +0, next pointer at +4, cleanup flag byte at +8 gating whether the value pointer must be freed with the node.

Methods: 

- `obj+0x00000000` `pointer value` (read_write, DERIVED)
- `obj+0x00000004` `pointer next` (read_write, DERIVED)
- `obj+0x00000008` `byte cleanup_flag` (read_write, DERIVED)

### MutexGuardedListContainer

Mutex-guarded linked-list container; the same list layout (head/tail/iterator/count) and mutex/timeout pair appear twice at different offsets on the owner (this+0x544 and this+0x560 variants), with append and pop-first operations.

Methods: `0x00584C70`, `0x00584CD0`, `0x00584E30`

- `this+0x00000544` `pointer list_head` (read_write, DERIVED)
- `this+0x00000548` `pointer list_tail` (read_write, DERIVED)
- `this+0x0000054C` `pointer list_iterator` (read_write, DERIVED)
- `this+0x00000550` `dword list_count` (read_write, DERIVED)
- `this+0x00000554` `handle mutex_handle` (read_write, DERIVED)
- `this+0x00000558` `dword mutex_timeout` (read, DERIVED)
- `this+0x00000560` `pointer list_head_variant_b` (read_write, DERIVED)
- `this+0x00000564` `pointer list_tail_variant_b` (read_write, DERIVED)
- `this+0x00000568` `pointer list_iterator_variant_b` (read_write, DERIVED)
- `this+0x0000056C` `dword list_count_variant_b` (read_write, DERIVED)
- `this+0x00000570` `handle mutex_handle_variant_b` (read_write, DERIVED)
- `this+0x00000574` `dword mutex_timeout_variant_b` (read, DERIVED)

### InputStateSlot

Typed input/event state slot with a stored timestamp, value and optional bounded payload buffer; updates are guarded on a type id and a 2.0-second freshness window.

Methods: `0x00583700`

- `this+0x00000000` `dword type_id` (read, GUESS)
- `this+0x00000004` `double prev_time` (read, GUESS)
- `this+0x0000000C` `byte updated_flag` (read_write, GUESS)
- `this+0x00000010` `dword value_low` (read_write, GUESS)
- `this+0x00000014` `dword value_high` (read_write, GUESS)
- `this+0x00000018` `double blended_result` (read_write, GUESS)
- `this+0x00000120` `dword payload_size` (read_write, GUESS)

### HighResolutionTimer

QueryPerformanceCounter-based high-precision timer object; zero-initialized then configured with the QPC timer flag, with an applied timing float parameter.

Methods: `0x005835F0`


### MutexGuardedTimerReader

Thread-safe reader of an accumulated timer double: mutex handle and timeout at this+0xD4/this+0xD8, value read through the timer-read callee.

Methods: `0x00584F90`

- `this+0x000000D4` `handle mutex_handle` (read_write, DERIVED)
- `this+0x000000D8` `dword mutex_timeout` (read, DERIVED)

### CallbackBlockAllocator

Allocates and initializes a socket-address callback block (8316 bytes, two 4156-byte entries, count header at +0) and stores the entry pointer at receiver +0.

Methods: `0x005830C0`

- `this+0x00000000` `pointer entry_ptr` (read_write, GUESS)

### DispatchManager

Dispatch object family that routes work through vtable slots (+0x38, +0x5C, +0x94, +0xA4, +0xA8, and the decode-chain slots +0x1C/+0x20/+0xAC/+0xB4/+0xC8/+0xCC), holding status and decode-state fields; includes the status query, item iteration, conditional-append dispatch, the trigger/decode queue processor, and a sub-object accessor. Owner identities are UNKNOWN; this grouping is a worker GUESS.

Methods: `0x00585020`, `0x00585220`, `0x00585270`, `0x00585380`, `0x00585870`

- `this+0x00000000` `pointer vtable_ptr` (read, GUESS)
- `this+0x0000005D` `byte status_byte` (read, GUESS)
- `this+0x00000060` `dword threshold` (read, GUESS)
- `this+0x0000063D` `byte header_copy_flag` (read, GUESS)
- `this+0x00000640` `handle decode_mutex` (read_write, GUESS)
- `this+0x00000644` `dword decode_mutex_timeout` (read, GUESS)

### ListDispatchWalker

Walks a singly linked list stored on the owner (head at this+0x11C, iterator at this+0x124) and dispatches each non-sentinel node through the dispatch callback, clearing its field via the field setter.

Methods: `0x00585320`

- `this+0x0000011C` `pointer list_head` (read_write, GUESS)
- `this+0x00000124` `pointer list_iterator` (read_write, GUESS)

### ListBuilder

Builds linked-list nodes in a two-phase pattern (append then paired prepends at a this+4 anchor) around the shared list helpers; its observed body contradicts its ABI name.

Methods: `0x00583530`

- `this+0x00000004` `pointer prepend_list_anchor` (read_write, GUESS)

### SharedPointerState

Mutex-protected shared state accessors: a protected pointer field at this+0x5B4 and a protected integer field at this+0xEC, each with an adjacent mutex handle and timeout, exposed through thread-safe read/write helpers.

Methods: `0x005857C0`, `0x00585D20`

- `this+0x000000EC` `dword int_field` (read_write, GUESS)
- `this+0x000000F0` `handle write_mutex` (read_write, GUESS)
- `this+0x000000F4` `dword write_mutex_timeout` (read, GUESS)
- `this+0x000005B4` `pointer shared_ptr` (read, GUESS)
- `this+0x000005B8` `handle read_mutex` (read_write, GUESS)
- `this+0x000005BC` `dword read_mutex_timeout` (read, GUESS)

### APCQueueScheduler

Queues the global APC routine on a thread handle stored at receiver +4, passing the receiver as the APC parameter.

Methods: `0x00585DE0`

- `this+0x00000004` `handle thread_handle` (read, GUESS)

### GlobalChainInitializer

Module-level once-guard initializer that constructs a chain of seven linked global objects (vtable/SEH-chain and locale-style objects) into static buffers on first entry, wiring them at vtable-derived offsets.

Methods: `0x00585E10`


### PointerArrayCleanupHelper

Cleanup helper on a pointer array: frees the dual-pointer block at element 5 and the single pointer at element 2 through the respective free helpers.

Methods: `0x005867B0`


### CopyBufferShim

Generic buffer copy/validation shims: a forwarding wrapper and a size-validated bounded copy used from dispatch and session paths.

Methods: `0x00586A00`, `0x00586A10`


## Compatibility contracts

- **MutexGuardedStateAccess** — Accessor objects expose (mutex handle, timeout) pairs at fixed offsets (this+0x554/0x558, +0x570/0x574, +0xD4/0xD8, +0xF0/0xF4, +0x5B8/0x5BC, +0x640/0x644, +0xABC/0xAC0, +0xAD8/0xADC, +0xBEC/0xBF0). Helpers wait, accept wait results 0 and 128, touch the protected field, then ReleaseMutex. A replacement must replicate this acquire/release discipline and the offset layout.
- **LinkedListNodeLifecycle** — 12-byte nodes (value at +0, next at +4, cleanup flag at +8). When the flag byte is non-zero the value pointer is owned and must be freed (via FreeWrapper_7bcf) before the node itself. Containers track head/tail/iterator/count and update them on every insert/remove, including advancing the iterator when it points at a removed node.
- **DispatchVTableSlotStability** — Dispatch objects are reached through vtable slots; observed slots include +0x38, +0x5C, +0x94, +0xA4, +0xA8 and the decode-chain slots +0x1C/+0x20/+0xAC/+0xB4/+0xC8/+0xCC. A replacement that preserves these slots must keep the slot layout or recompile the dispatch sites.

## Unresolved

- All packet owner identities are UNKNOWN; every class name in this proposal is a worker GUESS assignment grouping structurally coherent functions, not a recovered class name.
- The vtable dispatch targets (slots +0x38, +0x5C, +0x94, +0xA4, +0xA8 and the decode-chain slots +0x1C/+0x20/+0xAC/+0xB4/+0xC8/+0xCC) are not statically resolvable; slot semantics (count/next/predicate/release/begin/end/decode/header-fill) are inferred from call sites only.
- The node +8 cleanup-flag semantics (owned-value indicator) are inferred; in the head-removal path (0x00582EB0) the flag is cleared before the data-free decision, so its original meaning is unconfirmed.
- Wait results 0 and 128 (WAIT_ABANDONED / WAIT_TIMEOUT variant) are treated as granted access across all mutex helpers; the original intent is unconfirmed.
- 0x00583530 is named Zero_Fill_Memory_Region_with_Step in the ABI but its body builds linked-list nodes; the name is retained as an artifact and does not describe the observed body.
- The ConnectionManager active-list node field at +8 (field:*(this+0xAAC):0x00000008) is read but its role is unconfirmed.
- The 4156-byte socket-address callback entry type and the 8316-byte block layout (0x005830C0) are not established.
- The blended-update literals 0.5 and 2.0 in 0x00583700 may originate from the read-only globals 0x0059E800/0x0059E880 (DERIVED AmplitudeLimit/HalfStep); unverifiable from this packet.
- 0x00583700 copies a bounded payload into a buffer at this+0x20 sized at this+0x120, but field:this:0x00000020 is absent from the packet's allowed evidence refs, so no field entry is emitted for it; only the size field at +0x120 is represented.
- The global-chain initializer (0x00585E10) constructs seven static objects whose concrete types are unknown; the +vtable[1]+44/+12/+0 offset arithmetic assumes vtable[1] stores a displacement.
- The SEH handler globals (0x0059CE2B, 0x0059CE4B, 0x0059D101, 0x0059D19B) are compiler-generated registrations; their unwind semantics are not reconstructed.
- The a2 connection-struct layout in 0x0057DE30 (sentinel -1 at +32, ring buffer near +54) is partially inferred and not cross-checked against an allocation site.
- 0x00585270's declared_name is the literal 'if' (a prelabel artifact); ignored in favor of the worker fill's IterateAndAllocWithVTableDispatch proposal.
- 0x00586A00 forwards to a realloc-like copy callee visible only in the raw source text; no static call edge is evidenced.
