# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

Reconstructs the generic runtime object layer from 19 validated functions. One DERIVED class NetworkPacketQueueReader (0x005805C0) reads elements from a dual mutex-protected list queue, falling back to sub_582780/0x00582B10 and sub_5823C0 list servicing and writing the second-list result into the first-list element at +0x48. Two network list functions (0x00580DE0 network-query response, 0x005813E0 transfer-context lookup-or-create) share an identical mutex-protected singly linked list layout (head 0xAC8, tail 0xACC, iterator 0xAD0, count 0xAD4, mutex 0xAD8, timeout 0xADC, key at node+0x14) and are merged into a GUESS class NetworkConnectionManager on that structural match, with query state semantics (2, 3, 4) left unresolved. A DERIVED SocketAddressListManager (0x00581FD0) builds a dual list over two 4156-byte socket-address slots with a CreateMutexA guard; a GUESS SocketAddress initializer (0x00582110) fills two sockaddr_in blocks and resets a ring buffer. A GUESS AudioStreamListManager (0x00581D40) and GUESS AudioStream (0x00581E80) construct 308-byte audio stream objects, and a GUESS TimerCallbackList (0x00582780, 0x005828B0, 0x00582A10) plus a GUESS AudioStreamTimerCallbackList (0x00582BA0) manage 84- and 308-byte callback-entry blocks. Seven teardown/list helpers (0x00581820, 0x00581880, 0x005819C0, 0x00581A80, 0x00581AD0, 0x00581C20, 0x00582DC0) have UNKNOWN owners and are kept unowned; a shared 12-byte node layout (data at +0, next at +4, flag byte at +8) and a four-DWORD list object (head/tail/iterator/count) are captured as a compatibility contract rather than a forced class. One GUESS query-state machine and two GUESS vtable-slot interfaces are proposed with the explicit caveat that vtable slot identities are unknown.

## Function roles

- `0x005805C0` **NetworkPacketQueueReader** — Reads one element from a dual mutex-protected list queue. First list (mutex at this+0xB94, timeout at this+0xB98): waits on the mutex, runs ShortComputation_a780 on the cursor, validates the head element through sub_583430, and on empty calls sub_582780 and 0x00582B10 to pull an element. Second list (mutex at this+0xB68, timeout at this+0xB6C): reads the cursor element (this+0xB58 into this+0xB60), validates through sub_5832E0, and on empty calls sub_5823C0 and re-reads. The second-list result is written into the first-list element data field at +0x48 (base this+0xB8C) and returned.
- `0x00580DE0` **UnknownObject** — Handles a network query response. Runs a virtual accept check at vtable slot 208 (obj field 0xD0), builds a packet object via ObjectInitWithVTableFieldSet (0x0057B780), acquires the worker object through vtable slot 88 (obj field 0x58), reports a callback via sub_586800, invokes a virtual method on the worker packet object, sends via NetworkPacketSendWithQueryMatching (0x0057D8D0) and completes via vtable slot 92 (obj field 0x5C). Searches the mutex-protected pending-query list (head 0xAC8, tail 0xACC, iterator 0xAD0, count 0xAD4, mutex 0xAD8, timeout 0xADC) for the node matching a2 (key at node+0x14), marks the result object complete (result ptr at node+0x1C, completion flag at +0x28, setter 0x0057B6C0), unlinks and frees the node (0x00587BCF), sweeps the remainder (0x00587200, 0x00587230) and releases the mutex. Depending on query state via MutexProtectedPointerReadRelease (0x00585D20) re-sends (state 4, via 0x00586A00/0x0057D8D0) or invokes the vtable slot 116 callback (state 3). Returns the found-and-processed flag.
- `0x005813E0` **UnknownObject** — Looks up or creates a transfer context from a parsed request. Parses the binary request buffer a2 into a stack object via BinaryPacketFieldParserWithOffsetMath (0x00587310), then searches the mutex-protected singly linked list (head this+0xAC8, tail 0xACC, iterator 0xAD0, count 0xAD4, mutex 0xAD8, timeout 0xADC) comparing each node's +0x14 field against the parsed key. On a match merges via ObjectInitWithCopy (0x0057B820); otherwise allocates a 32-byte node (0x00587C03) + 12-byte link wrapper via ObjectCopyInitWithVTableSetup (0x0057B7D0) and appends it. When the node type from sub_587220 is 2 under the a4 flag or MutexProtectedPointerReadRelease (0x00585D20) == 3, copies a 4-dword sockaddr {family 2, htonl(0), htons(0)} from this+0xA84 via Copy4DwordsStructToStruct (0x0057B9F0) and sends it through sub_57DD40. Adjusts the node reference counter (0x00587230), releases the mutex, finalizes the stack object (0x005870D0) and returns 0.
- `0x00581820` **UnknownObject** — Destroys a linked list owned by this. When the byte flag at this+0x18 is set and CloseHandle (global 0x0059E1A8) on the handle at this+0x10 succeeds, the handle is zeroed. Walks the list from the head at this+0x0 via node next-links at node+0x4; per node, when the node free-flag at node+0x8 is set and the data pointer at node+0x0 is non-null, the data is freed via FreeWrapper_7bcf (0x00587BCF), then the node wrapper itself is freed. Finally zeroes the four list fields at this+0x0 through this+0xC.
- `0x00581880` **UnknownObject** — Destroys a linked list and zeroes the list structure. Walks from the head at this+0x0 following node+4 next pointers; per node with the byte flag at node+8 non-zero and the data pointer at node+0 non-null, invokes the first vtable entry of the data object (field *(*(obj+0x0)+0x0), a thiscall Release/destructor) with the data pointer and constant 1. Every visited node wrapper is freed via FreeWrapper_7bcf (0x00587BCF), whose return value becomes the function result. After the walk zeroes this+0x0, this+0x4, this+0x8, this+0xC. Invoked by 0x0057BCE0.
- `0x005819C0` **UnknownObject** — Destroys a linked list rooted at this[0]. Walks nodes via the +4 next-link pointer; for each node whose flag byte at +8 is non-zero and whose data pointer at +0 is non-null, dispatches through the data object's vtable entry at +4 (field *(*(obj+0x0)+0x0):0x4) with argument 1. Frees every node wrapper via FreeWrapper_7bcf (0x00587BCF) and zeros all four list-structure DWORDs this[0], this[4], this[8], this[0xC]. Returns the last free result, which is compiler-unspecified when the list is empty.
- `0x00581A80` **UnknownObject** — Walks a singly linked list from the head at this+0, freeing each node's payload when the node+8 flag is set and freeing every node itself via FreeWrapper_7bcf (0x00587BCF), then nulls the four header words at this+0..0xC and returns the last free result. Called by 0x0057BCE0.
- `0x00581AD0` **UnknownObject** — Structural twin of LinkedListDestroyCloseHandle (0x00581820): when the byte flag at this+0x18 is set and CloseHandle (global 0x0059E1A8) on the handle at this+0x10 succeeds, the handle is zeroed. Walks the list from the head at this+0x0 via node next-links at node+0x4; per node, when the node free-flag at node+0x8 is set the data pointer at node+0x0 is freed via FreeWrapper_7bcf (0x00587BCF) without the null-data guard, then the node wrapper itself is freed. Finally zeroes the four list fields at this+0x0 through this+0xC.
- `0x00581C20` **UnknownObject** — Destructor-style cleanup of two embedded linked lists. When the byte flag at this+0x28 is set, closes the handle at this+0x20 via CloseHandle (global 0x0059E1A8) and zeroes it on success. Walks the first list (head this+0x10, fields +0x14/+0x18/+0x1C) invoking SEHGuardedFunctionWithExceptionHandling (0x005867B0) on each node's data and freeing it (0x00587BCF) when the node+8 flag and node+0 data are set, then zeroes this+0x10..0x1C. Walks the second list (head this+0x0) running NTimeCallbackLoopWithSEH (0x0058A5F7) with constant 84 over adjusted data blocks, frees the adjusted data, the data block and the node, then zeroes this+0x0..0xC. Returns the last free result.
- `0x00581D40` **UnknownObject** — Constructor for an audio-stream list manager. Zero-initializes the eight list fields this[0..7] (offsets 0x0-0x1C), allocates a 4-byte node wrapper and a 620-byte stream-manager buffer via OperatorNewNhMallocWrapper (0x00587C03), runs NTimeCallbackLoopWithSEH_a6eb (0x0058A6EB) to construct two 308-byte audio stream objects using AudioStreamConstructWithVTableInit (global 0x00581E80) and SingleVTablePointerSet (global 0x0057BC70), appends the wrapper via LinkedListNodeAppend_6000 (0x00586000), and pre-allocates two empty 308-byte nodes into the second list via LinkedListNodeAllocPrepend (0x00583210). Sets this+0x20 = 0, this+0x24 = -1 and the byte flag at this+0x28 = 0, creates an unnamed mutex via CreateMutexA (global 0x0059E1AC) into this+0x20, and sets the flag byte to 1 only when the mutex handle is non-null. Returns this.
- `0x00581E80` **UnknownObject** — __thiscall constructor for an audio stream object. Runs the generic constructor prologue ConstructorVTableSetInit (0x0057A160), installs the audio stream vtable off_5B8B3C (global 0x005B8B3C) into the vtable slot at this+0x0, zeroes the WORD-sized field at this+0x12C and the DWORD-sized field at this+0x130, runs SmallStructFieldInit (0x0057A1E0) over the object, and returns the this pointer.
- `0x00581FD0` **SocketAddressListManager** — Constructor for a dual linked-list manager that owns socket-address storage and a mutex. Zero-initializes the eight list-manager dwords (this+0x0..0x1C), allocates a 4-byte node and an 8316-byte block via OperatorNewNhMallocWrapper (0x00587C03), initializes two 4156-byte SocketAddress slots inside the block via NTimeCallbackLoopWithSEH_a6eb (0x0058A6EB) with SocketAddressInit (global 0x00582110) and EmptyStub_aa60 (global 0x0047AA60), stores the block base into the node, appends the node via LinkedListNodeAppend_6000 (0x00586000), and pre-allocates two empty list nodes via LinkedListNodeAllocPrepend (0x00583210). Sets this+0x20 = 0, this+0x24 = -1 and the byte flag this+0x28 = 0, creates an unnamed mutex via CreateMutexA (global 0x0059E1AC) into this+0x20, and sets the byte flag to 1 only when the mutex handle is non-zero. Returns this. Single static caller 0x0057BA10.
- `0x00582110` **UnknownObject** — Socket/endpoint structure initializer (this-call, returns this). Builds two temporary sockaddr_in-style blocks: WORD family fields this+0x0 and this+0x10 set to 2 (AF_INET), IP dwords this+0x4 and this+0x14 set via htonl (global 0x0059E2D8), port WORDs this+0x2 and this+0x12 set via htons (global 0x0059E2F4). Resets a ring-buffer region at word offset 27 via RingBufferHeadTailReset (0x0057B530), then zeroes every field from this+0x0 through this+0x34 except this+0x20 which is set to -1. Returns this.
- `0x00582780` **UnknownObject** — Initializes a timer callback list object with 4 entries. Allocates a 340-byte callback block holding 4 entries of 84 bytes via OperatorNewNhMallocWrapper (0x00587C03), initializes the entries via NTimeCallbackLoopWithSEH_a6eb (0x0058A6EB) with SEHProtectedDirectXRenderStateSetup (global 0x00586700) and SEHGuardedFunctionWithExceptionHandling (global 0x005867B0), links the block node into the first linked list (head 0x0, tail 0x4, iterator 0x8, count 0xC), then allocates one 12-byte node per callback entry into a second linked list (head 0x10, tail 0x14, iterator 0x18, count 0x1C). Called by NetworkPacketQueueReader (0x005805C0). Returns the final second-list count this+0x1C.
- `0x005828B0` **UnknownObject** — Zeros the eight fields of a timer callback list object, then allocates a 1348-byte callback block holding 16 entries of 84 bytes, links the block node into the object's first linked list, and allocates one 12-byte node per callback entry into a second linked list, using the same per-entry callback pair (globals 0x00586700, 0x005867B0). Same pattern as the sibling 4-entry init (0x00582780) with 16 entries instead of 4. Called by 0x0057BA10. Returns this (unlike the sibling's count).
- `0x00582A10` **TimerCallbackList** — Destructor/cleanup for a two-list timer-callback structure. Walks the second list (head at this+0x10): for each node with a non-zero +8 flag invokes SEHGuardedFunctionWithExceptionHandling (0x005867B0) on the node's data block and frees the data via FreeWrapper_7bcf (0x00587BCF), then frees the node; clears this+0x4..0x10. Walks the first list (head at this+0x0): for flagged nodes resolves the data block, and when the block's first dword is non-zero runs NTimeCallbackLoopWithSEH (0x0058A5F7) over 84-byte entries with the block header count, frees the allocation base and the data pointer, then frees each node; clears this+0x0..0xC and returns 0. Called by 0x0057BCE0.
- `0x00582B10` **UnknownObject** — Removes a node from a linked list whose data value equals the head node's data value. Sets the iterator pointer (this+0x8) to the head on entry, walks the list from the head searching for the node whose data matches the captured head data, unlinks the matched node, updates head (this+0x0)/tail (this+0x4)/iterator pointers, decrements the node count (this+0xC) and frees the node. If the removed node's cleanup flag (node+8) is set and its data (node+0) is non-null, an SEH-guarded cleanup callback (0x005867B0) runs on the data before it is freed (0x00587BCF). Returns the matched data value on success, or 0 when the list is empty or the node is not found. Called by NetworkPacketQueueReader (0x005805C0).
- `0x00582BA0` **UnknownObject** — Initializes a timer callback list for audio stream construction: allocates a 620-byte callback block holding 2 entries of 308 bytes via OperatorNewNhMallocWrapper (0x00587C03), initializes the entries via NTimeCallbackLoopWithSEH_a6eb (0x0058A6EB) with AudioStreamConstructWithVTableInit (global 0x00581E80) and SingleVTablePointerSet (global 0x0057BC70), links the block node into the first linked list, and allocates one 12-byte node per callback entry into a second linked list (dual-list fields this+0x0..0x1C). No static callers recorded. Returns the final second-list count this+0x1C.
- `0x00582DC0` **UnknownObject** — Teardown of a two-list buffer structure. The second list (head at this+0x10) is walked and freed, freeing each node's owned data block first when the node+8 flag and node+0 data pointer are both non-zero, then the node itself. The first list (head at this+0x0) is then walked; flagged nodes whose data block starts with a non-null callback-block pointer run NTimeCallbackLoopWithSEH (0x0058A5F7) over 4156-byte entries with the block's own entry count and EmptyStub_aa60 (global 0x0047AA60), then free the block header and data block, then the node. All eight list bookkeeping fields (this+0x0..0x1C) are cleared after teardown. Called by 0x0057BCE0.

## Proposed classes

### NetworkPacketQueueReader

Dual mutex-protected list queue reader: first list with mutex at 0xB94 and timeout at 0xB98, second list with mutex at 0xB68 and timeout at 0xB6C, cursor movement from 0xB58 to 0xB60, element data written at first-list element +0x48 (base pointer at 0xB8C). Populated by ReadPacketQueue (0x005805C0).

Methods: `0x005805C0`

- `this+0x00000B58` `dword second_list_cursor` (read_write, DERIVED)
- `this+0x00000B60` `dword second_list_cursor_advance` (read_write, DERIVED)
- `this+0x00000B68` `dword second_list_mutex` (read, DERIVED)
- `this+0x00000B6C` `dword second_list_mutex_timeout` (read, DERIVED)
- `this+0x00000B8C` `void* first_list_element_ptr` (read_write, DERIVED)
- `this+0x00000B94` `dword first_list_mutex` (read, DERIVED)
- `this+0x00000B98` `dword first_list_mutex_timeout` (read, DERIVED)
- `*(this+0xB8C)+0x00000048` `void* element_data_field` (write, GUESS)

### NetworkConnectionManager

Mutex-protected pending-query / transfer-context registry. Holds a singly linked list (head 0xAC8, tail 0xACC, iterator 0xAD0, count 0xAD4, mutex 0xAD8, timeout 0xADC, match key at node+0x14), a prebuilt sockaddr area at 0xA84, and a vtable-dispatched worker interface (obj slots 0x58/0x5C/0x74/0xD0). ProcessQueryResponse (0x00580DE0) completes and unlinks matching queries; LookupOrCreateTransferContext (0x005813E0) parses a request and inserts/updates a context. Both packet owners are UNKNOWN; the merge is GUESS based on the identical list layout and shared callees (0x00585D20, 0x00587220, 0x00587230, 0x0057D8D0).

Methods: `0x00580DE0`, `0x005813E0`

- `this+0x00000000` `void* vtable_ptr` (read, GUESS)
- `obj+0x00000058` `void* worker_packet_obj_slot` (read, GUESS)
- `obj+0x0000005C` `void* send_complete_slot` (read, GUESS)
- `obj+0x00000074` `void* state3_callback_slot` (read, GUESS)
- `obj+0x000000D0` `void* accept_check_slot` (read, GUESS)
- `this+0x00000AC8` `void* list_head` (read_write, GUESS)
- `this+0x00000ACC` `void* list_tail` (read_write, GUESS)
- `this+0x00000AD0` `void* list_iterator` (read_write, GUESS)
- `this+0x00000AD4` `dword list_count` (read_write, GUESS)
- `this+0x00000AD8` `dword list_mutex` (read, GUESS)
- `this+0x00000ADC` `dword list_mutex_timeout` (read, GUESS)
- `*(*(this+0xAD4)+0x0)+0x0000001C` `void* result_object_ptr` (read, GUESS)
- `*(*(*(this+0xAD4)+0x0)+0x1C)+0x00000028` `byte result_complete_flag` (write, GUESS)
- `*(*(*(this+0xAC8)+0x4)+0x0)+0x00000000` `dword node_walk_deref` (read, GUESS)

### SocketAddressListManager

Dual linked-list manager owning socket-address storage (two 4156-byte SocketAddress slots in an 8316-byte block) and a mutex. Eight list dwords at 0x0..0x1C, mutex handle at 0x20, state id at 0x24 (set to -1) and a validity byte flag at 0x28 set only when the CreateMutexA handle is non-null. Populated by SocketAddressListManagerInit (0x00581FD0), the single static caller of which is 0x0057BA10.

Methods: `0x00581FD0`

- `this+0x00000000` `void* list1_head` (write, GUESS)
- `this+0x00000004` `void* list1_tail` (write, GUESS)
- `this+0x00000008` `void* list1_iterator` (write, GUESS)
- `this+0x0000000C` `dword list1_count` (write, GUESS)
- `this+0x00000010` `void* list2_head` (write, GUESS)
- `this+0x00000014` `void* list2_tail` (write, GUESS)
- `this+0x00000018` `void* list2_iterator` (write, GUESS)
- `this+0x0000001C` `dword list2_count` (write, GUESS)
- `this+0x00000020` `dword mutex_handle` (write, DERIVED)
- `this+0x00000024` `dword state_id` (write, DERIVED)
- `this+0x00000028` `byte mutex_valid_flag` (write, DERIVED)

### SocketAddress

Socket/endpoint structure initializer: builds two temporary sockaddr_in blocks (WORD family at +0x0/+0x10, IP dword at +0x4/+0x14, port WORD at +0x2/+0x12), resets a ring-buffer region at word offset 27, then zeroes the field run +0x0..0x34 with +0x20 set to -1. Populated by SocketAddressInit (0x00582110), used as the per-element init callback of SocketAddressListManagerInit.

Methods: `0x00582110`

- `this+0x00000000` `word sockaddr1_family` (write, GUESS)
- `this+0x00000002` `word sockaddr1_port` (write, GUESS)
- `this+0x00000004` `dword sockaddr1_ip` (write, GUESS)
- `this+0x00000008` `dword reset_field_0x08` (write, GUESS)
- `this+0x0000000C` `dword reset_field_0x0C` (write, GUESS)
- `this+0x00000010` `word sockaddr2_family` (write, GUESS)
- `this+0x00000012` `word sockaddr2_port` (write, GUESS)
- `this+0x00000014` `dword sockaddr2_ip` (write, GUESS)
- `this+0x00000018` `dword reset_field_0x18` (write, GUESS)
- `this+0x0000001C` `dword reset_field_0x1C` (write, GUESS)
- `this+0x00000020` `dword invalid_marker` (write, GUESS)
- `this+0x00000024` `dword reset_field_0x24` (write, GUESS)
- `this+0x00000028` `byte reset_field_0x28` (write, GUESS)
- `this+0x0000002C` `dword reset_field_0x2C` (write, GUESS)
- `this+0x00000030` `dword reset_field_0x30` (write, GUESS)
- `this+0x00000034` `word reset_field_0x34` (write, GUESS)

### TimerCallbackList

Two-list timer-callback container: the first linked list (head 0x0, tail 0x4, iterator 0x8, count 0xC) holds the single callback-block node, and the second linked list (head 0x10, tail 0x14, iterator 0x18, count 0x1C) holds one 12-byte node per 84-byte callback entry. Entry-count variants: 4 entries in a 340-byte block (0x00582780) and 16 entries in a 1348-byte block (0x005828B0); teardown by 0x00582A10. Per-entry callbacks are SEHProtectedDirectXRenderStateSetup (0x00586700) and SEHGuardedFunctionWithExceptionHandling (0x005867B0).

Methods: `0x00582780`, `0x005828B0`, `0x00582A10`

- `this+0x00000000` `void* list1_head` (read_write, GUESS)
- `this+0x00000004` `void* list1_tail` (read_write, GUESS)
- `this+0x00000008` `void* list1_iterator` (read_write, GUESS)
- `this+0x0000000C` `dword list1_count` (read_write, GUESS)
- `this+0x00000010` `void* list2_head` (read_write, GUESS)
- `this+0x00000014` `void* list2_tail` (read_write, GUESS)
- `this+0x00000018` `void* list2_iterator` (read_write, GUESS)
- `this+0x0000001C` `dword list2_count` (read_write, GUESS)

### AudioStreamTimerCallbackList

Audio-stream variant of the two-list timer-callback container: the first linked list holds the callback-block node and the second holds one 12-byte node per 308-byte audio-stream entry (2 entries in a 620-byte block), constructed with AudioStreamConstructWithVTableInit (global 0x00581E80) and SingleVTablePointerSet (global 0x0057BC70). Same dual-list field layout (0x0..0x1C) as TimerCallbackList. Populated by 0x00582BA0; no static callers recorded.

Methods: `0x00582BA0`

- `this+0x00000000` `void* list1_head` (read_write, GUESS)
- `this+0x00000004` `void* list1_tail` (read_write, GUESS)
- `this+0x00000008` `void* list1_iterator` (read_write, GUESS)
- `this+0x0000000C` `dword list1_count` (read_write, GUESS)
- `this+0x00000010` `void* list2_head` (read_write, GUESS)
- `this+0x00000014` `void* list2_tail` (read_write, GUESS)
- `this+0x00000018` `void* list2_iterator` (read_write, GUESS)
- `this+0x0000001C` `dword list2_count` (read_write, GUESS)

### AudioStreamListManager

Audio-stream list manager: two linked lists (this+0x0..0x1C) over a 620-byte stream-manager buffer containing two 308-byte audio stream objects, plus a mutex handle at this+0x20, a state id at this+0x24 (set to -1) and a validity byte flag at this+0x28 set only when the CreateMutexA handle is non-null. Constructed by 0x00581D40.

Methods: `0x00581D40`

- `this+0x00000000` `void* list1_head` (write, GUESS)
- `this+0x00000004` `void* list1_tail` (write, GUESS)
- `this+0x00000008` `void* list1_iterator` (write, GUESS)
- `this+0x0000000C` `dword list1_count` (write, GUESS)
- `this+0x00000010` `void* list2_head` (write, GUESS)
- `this+0x00000014` `void* list2_tail` (write, GUESS)
- `this+0x00000018` `void* list2_iterator` (write, GUESS)
- `this+0x0000001C` `dword list2_count` (write, GUESS)
- `this+0x00000020` `dword mutex_handle` (write, DERIVED)
- `this+0x00000024` `dword state_id` (write, DERIVED)
- `this+0x00000028` `byte mutex_valid_flag` (write, DERIVED)

### AudioStream

Audio stream object constructed by 0x00581E80: audio stream vtable off_5B8B3C installed at +0x0, WORD at +0x12C and DWORD at +0x130 zeroed, followed by the generic constructor prologue (0x0057A160) and small-struct init (0x0057A1E0). Used as the per-entry constructor of AudioStreamTimerCallbackList and the two streams of AudioStreamListManager.

Methods: `0x00581E80`

- `this+0x00000000` `void* vtable_ptr` (write, GUESS)
- `this+0x0000012C` `word state_or_flags` (write, GUESS)
- `this+0x00000130` `dword buffer_size_or_timer` (write, GUESS)

## Compatibility contracts

- **DualMutexQueueLayout** — The queue reader (0x005805C0) walks two mutex-protected lists: each list carries a mutex handle plus a timeout DWORD (first list 0xB94/0xB98, second list 0xB68/0xB6C) and a cursor element pair (0xB58 -> 0xB60); the read element data is written into the first-list element at +0x48 under the pointer base 0xB8C. A replacement executable must preserve the per-list mutex-guarded walk and the element +0x48 data write.
- **LinkedListNodeLayout** — List nodes are 12-byte wrappers {data at +0, next at +4, flag byte at +8}; list objects keep four DWORDs {head 0, tail 4, iterator 8, count 0xC}. Teardown helpers (0x00581820, 0x00581880, 0x005819C0, 0x00581A80, 0x00581AD0) interpret the +8 flag to gate payload freeing or a vtable destructor call, always free the node wrapper, and reset the four DWORDs. A replacement executable must reproduce this node/list layout and the teardown semantics.
- **MutexBackedListRegistryLayout** — The network query/transfer-context registry owns a mutex-protected singly linked list with head 0xAC8, tail 0xACC, iterator 0xAD0, count 0xAD4, mutex 0xAD8 and timeout 0xADC; each node carries a match key at +0x14 and (for query results) a result-object pointer at +0x1C with a completion flag at +0x28. Wait/release is via WaitForSingleObject/ReleaseMutex with the 0/128 accepted result convention. A replacement executable must preserve this list and key convention.
- **MutexInitValidityFlag** — List-manager constructors (0x00581D40, 0x00581FD0) create an unnamed mutex via CreateMutexA (import global 0x0059E1AC) into the mutex-handle field (0x20), reset the state id (0x24) to -1, and set the validity byte (0x28) to 1 only when the handle is non-null. Teardown then closes the handle when the byte flag is set. A replacement executable must reproduce the create-validated-mutex contract.
- **CallbackBlockEntryStride** — NTimeCallbackLoopWithSEH_a6eb (0x0058A6EB) and NTimeCallbackLoopWithSEH (0x0058A5F7) build and drain callback blocks whose entry count is stored in the block header DWORD and whose entries have a fixed stride (84 bytes for timer callbacks, 308 bytes for audio streams, 4156 bytes for socket-address slots). Teardown (0x00582A10, 0x00582DC0, 0x00581C20) reads the header count and frees both the header allocation base and the data block. A replacement executable must preserve the header-count/stride encoding.

## Unresolved

- NetworkPacketQueueReader: the first/second-list head offsets (this+0xB74, this+0xB48) appear only in packet prose and are absent from the allowed evidence refs, so the two-list layout is described textually and cannot be locked to specific fields in this output.
- NetworkPacketQueueReader: element data structure layout and the meaning of the element +0x48 write are unknown; the validation semantics of sub_583430 and sub_5832E0 (second argument 1) that gate element acceptance are unknown.
- 0x00580DE0: interpretation of query states (2, 3, 4) is caller/system-defined; vtable slots read through obj fields 0x58/0x5C/0x74/0xD0 and the exact packet-object layout behind the worker are unresolved.
- 0x00580DE0: global 0x0059CAE8 appears in packet facts but nowhere in the raw decompiled body; its role is unresolved (SEH/event bookkeeping candidate).
- 0x005813E0: the ABI lead names the owning class NetworkConnectionManager (trust LEGACY) but the owner is unconfirmed by static or runtime evidence; the merge with 0x00580DE0 on the identical list layout (0xAC8..0xADC) is GUESS, not packet-proven common ownership.
- 0x005813E0: the semantic role of the 0x14 field match key and the meaning of sub_587220 type 2 are not established beyond this function; the this+0xA84 sockaddr area is pre-built, copied rather than constructed here.
- 0x00581820 / 0x00581AD0: the roles of this+0x4, this+0x8 and this+0xC (tail/cursor/count per the twin's skeleton-fill prose) are DERIVED and not confirmed by this packet; no callers appear, so the owning list type and destruction call sites are unknown.
- 0x00581AD0: why the data-free path omits the null-data check present in the structural twin 0x00581820 is unexplained by this packet.
- 0x00581880 / 0x005819C0 / 0x00581A80: the meaning of the node byte flag at +8 (gating the vtable destructor call) is not evidenced here; the data-object vtable slot identity (slot 0 vs slot 4) and the constant argument 1 are inferred from the calling pattern only; 0x005819C0's result is compiler-unspecified when the list is empty.
- 0x00581C20: global 0x0059CB70 (SEH_581C20) and the field:*(this+0x14):0x4 extraction artifact appear in packet facts but not in the raw body; the two teardown lists differ (the second list carries an extra 4-byte header before each callback block) and the exact flag semantics are unknown.
- 0x00581D40: the three byte_FF0000000000545x globals are reported as written but never appear as named operands in the body; they are likely IDA SEH-frame artifacts with an unestablished bit mapping. The 308-byte stride / count-2 audio-stream layout inside the 620-byte buffer is not reconstructed.
- 0x00581E80: global 0x0059CBC8 (SEH_581E80) is a compiler-generated exception-handler registration not visible in the body; semantics of the zeroed fields +0x12C and +0x130 depend on the unestablished audio-stream object layout.
- 0x00581FD0: the 0xFF0000000000545x globals are likely compiler-emitted SEH/stack bookkeeping bytes; the split of this+0x0..0x1C into two linked lists and the -1 state id at 0x24 are DERIVED from prior analysis text, not confirmed by raw decompilation.
- 0x00582110: identity of the owning class is unknown (no caller/RTTI evidence); the temporary sockaddr_in values are overwritten by the later zero pass so their intermediate role is inferred from ordering only; the ring-buffer region at word offset 27 is evidenced only by the RingBufferHeadTailReset call.
- 0x00582780 / 0x005828B0 / 0x00582BA0: NTimeCallbackLoopWithSEH_a6eb semantics (entry size 84/308, counts 4/16/2, two callback pointers) are inferred from call shape; the node+8 flag meaning (1 for the block node, 0 for entry nodes) is unknown; the SEH guard globals (0x0059CCF6, 0x0059CD29, 0x0059CD76) do not appear in the decompiled bodies; 0x005828B0 returns this while the siblings return the count, with no documented rationale; 0x00582BA0 records no static callers so list consumption is unknown.
- 0x00582A10: this+0x14, this+0x18 and this+0x1C (second-list tail, iterator and count fields) are not touched by the visible body; global 0x0059CD50 is the compiler-generated SEH scope table; the per-node timer callback structure is unknown.
- 0x00582B10: the match value is the head node's data captured before the walk, so the first node examined already matches in the nominal path; whether the intended semantic is 'remove head' or 'remove first data-equal node' is ambiguous.
- 0x00582DC0: the owning object class is unknown (single static caller 0x0057BCE0); the 4156-byte entry stride and the callback-block header-count semantics are unknown; SEH_582DC0 (0x0059CDA8) is consumed inside the NTimeCallbackLoopWithSEH call; the field:*(this+0x14):0x4 extraction artifact has an ambiguous base.
- Merged class NetworkConnectionManager: both constituent packet owners are UNKNOWN; the merge rests on the identical list layout and shared callees (0x00585D20, 0x00587220, 0x00587230), which is structural evidence but not proof of common ownership.
