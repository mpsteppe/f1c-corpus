# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

Generic runtime object machinery: a network session object with a one-time Winsock init guard, a mutex-protected outbound packet send queue, a keyed node-list lookup, and a file-transfer accept path; three singly-linked-list container shapes (plain, single-list-with-handle, dual-list-with-handle) sharing 12-byte node wrappers (data +0x0, next +0x4, release flag +0x8, metadata +0xC) whose data objects are released through vtable slot 0 or slot 1 with literal arguments 1 or 3; guarded handle-close and mutex-recreation helpers on the +0x10/+0x18 and +0x20/+0x28 handle slots; and flag-dispatched destructor helpers (bit 2 placement / bit 1 free) for placement-allocated blocks. All class assignments are DERIVED or GUESS from shared field layouts; owner identities remain unresolved.

## Function roles

- `0x0057FB90` **CNetworkSession** — One-time Winsock initialization guard: latches the init flag byte at this+0xA74, calls WSAStartup(2.2) writing WSADATA at this+0x778 via import 0x0059E314, sets the flag on success and calls the failure handler sub_57D400 with the invalid-handle sentinel (void*)0xFFFFFFFF on failure; invoked by NetworkConnectionThread (0x0057FC80).
- `0x00580C10` **CNetworkSession** — Allocates and enqueues a network packet on a mutex-protected send queue: builds a 4-DWORD header (first word low 2, first word high htons(0), second word htonl(0)) copied to this+0xA84, increments the send counter at this+0xB38 under mutex this+0xB3C/timeout this+0xB40 and returns the previous value, allocates a 32-byte packet via 0x00587C03 and initializes it via 0x0057B780, optionally copies buffer headers under mutex this+0x640/timeout this+0x644 via 0x00587370 (a4 set) or sub_57DD40 (a4 clear) for 0 < a3 <= 2, links a 12-byte queue node at tail this+0xACC and increments count this+0xAD4; returns 1 on all paths.
- `0x00581070` **CNetworkSession** — Thread-safe keyed lookup in the node list rooted at this+0xAC8: initializes local vtable context via 0x00587030, acquires the list mutex this+0xAD8 (timeout this+0xADC), walks nodes through the cursor this+0xAD0 via each node's next pointer (+4) until the data field at +0x14 equals a2, calls 0x00587370 on the matched data, then under the second mutex this+0x640 (timeout this+0x644) copies into a local 28-byte buffer finalized via 0x005870D0; returns 1 found / 0 not.
- `0x0058119A` **CNetworkSession** — Accept/reject handler for a file transfer request under mutex this+0x640 (timeout this+0x644): evaluates the condition via NegatedPredicate (0x00587100); the reject branch releases the mutex and returns 0, the accept branch increments the transfer counter via 0x00587230, releases the mutex, invokes sub_57E280(this, 1.0) to initiate transfer processing, and returns 1.
- `0x00581600` **CNetworkSession** — Mutex-protected search of the node list rooted at this+0xAC8 keyed by identifier: acquires mutex this+0xAD8 (timeout this+0xADC), walks from the head comparing the node data field +0x14 (read via ReadFieldAtOffset0x14, 0x005871F0) to a2, writes the matched data to a3+4 via BufferWriteWithParams (0x00587620), increments a counter via 0x00587230 when flag a4 is set; returns 1 found / 0 not. The element-count field this+0xAD4 is not consumed by this path.
- `0x005818E0` **CNodeListContainer** — Destroys a linked list whose owner object optionally owns a Windows handle: closes the handle at this+0x10 via CloseHandle when the byte flag at this+0x18 is set (zeroing the slot on success), walks the node list from the head at this+0x0, invokes the data object's vtable[0] with argument 1 when the node flag at +0x8 is set and the data pointer at +0x0 is non-null, frees every node wrapper via 0x00587BCF, and zeroes head/tail/cursor/count (this+0x0..0xC).
- `0x00581940` **CLinkedList** — Linked-list node removal by identifier: walks the chain from the head at this+0x0 for a node whose data pointer (node+0) equals a2, unlinks it, fixes up head (this+0x0), tail (this+0x4) and cursor (this+0x8) when the removed node is one of them, decrements the element count (this+0xC), optionally clears the node release flag (+8) when a3 is zero, dispatches the data object's vtable slot 1 (vtable+4) with refcount 1 when the flag remains set, frees the node via 0x00587BCF; returns 1 removed / 0 not found.
- `0x00581A20` **CNodeListContainer** — Linked-list destructor for a container with an optional owned handle: closes the handle at this+0x10 gated by the byte flag at this+0x18 (slot cleared only on CloseHandle success), walks the node list from the head at this+0x0, invokes the data object's second vtable destructor (vtable+0x4) as a __thiscall with argument 1 when the node flag at +0x8 is set and the data pointer at +0x0 is non-null, frees each node via 0x00587BCF, then zeroes head/tail/cursor/count (this+0x0..0xC).
- `0x00581B30` **CDualListContainer** — Destroys two embedded singly-linked lists with optional handle close: closes the handle at this+0x20 via CloseHandle when the flag at this+0x28 is set (slot zeroed on success), frees list1 (head this+0x10) node data via data vtable[0] with argument 1 and node wrappers via 0x00587BCF, frees list2 (head this+0x0) node data via data vtable[0] with argument 3 plus the data objects and node wrappers, then zeroes all list fields this+0x0..0x1C.
- `0x00581EE0` **CDualListContainer** — Dual-list destructor with handle close: closes the handle at this+0x20 when the flag at this+0x28 is set (slot cleared on CloseHandle success), walks list1 from the head at this+0x10 invoking the data object's vtable destructor at vtable+4 with argument 1 and freeing nodes via 0x00587BCF, walks list2 from the head at this+0x0 invoking the data object's vtable destructor at vtable+4 with argument 3 and freeing data objects, then zeroes all list fields this+0x0..0x1C.
- `0x00582190` **CDualListContainer** — Destroys two owned lists with optional handle close and size-prefixed record cleanup for list2: closes the handle at this+0x20 gated by the flag at this+0x28 (slot cleared on success), frees list1 (head this+0x10) node data and wrappers via 0x00587BCF and zeroes its four fields, then walks list2 (head this+0x0) invoking NTimeCallbackLoopWithSEH (0x0058A5F7) with the EmptyStub_aa60 callback (0x0047AA60) and the SEH_582190 handler (0x0059CC48) on each size-prefixed record before releasing data and wrappers, and zeroes its four fields.
- `0x005822B0` **CLinkedList** — Standard linked-list destructor: walks every node from the head at this+0x0, frees the node data via 0x00587BCF when the node flag at +0x8 is set and the data pointer at +0x0 is non-null, frees each node via 0x00587BCF, then zeroes the four list fields (this+0x0..0xC) and returns the last free result. Invoked by 0x0057BCE0 during list teardown.
- `0x00582310` **CNodeListContainer** — Conditional handle-close helper: reads the byte flag at this+0x18 and, when non-zero, calls CloseHandle on the handle at this+0x10, zeroing the slot on success; returns the CloseHandle result or the flag value when skipped. Called by 0x0057BCE0 and 0x00583AE0.
- `0x00582360` **CNodeListContainer** — Creates or recreates an unnamed Win32 mutex stored on the receiver: closes the existing handle at this+0x10 when the validity flag at this+0x18 is set (slot zeroed on success), creates an unnamed inheritable mutex via CreateMutexA (0x0059E1AC) with a default SECURITY_ATTRIBUTES structure, stores the new handle, sets the flag on success; returns the validity flag (1 ready / 0 failed). Called by 0x0057BA10 and 0x005837F0.
- `0x00582650` **CDualListContainer** — Destroys two embedded node lists without handle close: frees list1 (head this+0x10) node data via data vtable slot 0 called as (data)(data, 1) and node wrappers via 0x00587BCF, frees list2 (head this+0x0) node data via data vtable slot 0 called as (data)(data, 3) plus the data objects, then zeroes all list fields this+0x0..0x1C.
- `0x00582720` **CDualListContainer** — Initializes or reinitializes a mutex on the object: closes the existing handle at this+0x20 when the ready flag at this+0x28 is set (slot cleared on success), creates an unnamed inheritable mutex via CreateMutexA (0x0059E1AC) and stores it at this+0x20, sets the ready flag on success; returns the ready flag byte. Called by 0x0057BA10.
- `0x00582CE0` **CDualListContainer** — Tears down two singly-linked node lists: the list at this+0x10 gets each data block's second vtable entry invoked with argument 1 and every node freed via 0x00587BCF, the list at this+0x0 gets each data block's second vtable entry invoked with argument 3 and data blocks plus nodes freed, then all list fields this+0x0..0x1C are zeroed. Called by 0x0057BCE0.
- `0x00582F60` **CLinkedList** — Standard list destructor: walks from the head at this+0x0, invokes the data block's vtable slot 0 as a __thiscall with the data pointer and literal 1 when the node flag at +0x8 is set and the data pointer at +0x0 is non-null, frees each node via 0x00587BCF, then zeroes the four list fields (this+0x0..0xC) and returns the last free result.
- `0x00583150` **CPlacementAllocationDispatcher** — Destruction dispatch on flag bits of a2: bit 2 (0x2) selects the placement-allocated path where this-1 is a count header — NTimeCallbackLoopWithSEH (0x0058A5F7) walks the 40-byte callback entries with sub_57AEF0 (0x0057AEF0) as the per-entry callback, then optionally frees from the header when bit 1 (0x1) is set, returning this-1; when bit 2 is clear sub_57AEF0 runs directly on this, the object is optionally freed when bit 1 is set, and this is returned.
- `0x005831B0` **CPlacementAllocationDispatcher** — Destruction dispatcher keyed on flag bits of a2: bit 2 selects the placement-allocated block with a count header at this-1 — NTimeCallbackLoopWithSEH (0x0058A5F7) runs over all entries with element size 308 using the SingleVTablePointerSet callback (0x0057BC70), then optionally frees from the header when bit 1 is set, returning this-1; when bit 2 is clear SingleVTablePointerSet runs directly on this, the object is optionally freed when bit 1 is set, and this is returned.
- `0x005832E0` **CLinkedList** — Removes a node by value from a singly-linked list container (head/tail/cursor/count at this+0x0..0xC): walks the chain for a node whose payload equals a2, unlinks it, advances the iterator when the matched node is current, updates the tail when it is last, decrements the count, optionally clears the node cleanup flag when a3 is false, invokes the payload's first vtable entry with argument 1 when the flag remains set, frees the node via 0x00587BCF; returns 1 removed / 0 on null value, empty list, or no match.
- `0x00583650` **UNKNOWN** — Argument-less void wrapper that invokes the callee EmptyStub_0170 with no arguments and returns nothing; an indirection layer reached from 0x00583AE0 and StartAddress (0x00583D90). Owner and purpose are unresolved.

## Proposed classes

### CNetworkSession

Network session object owning Winsock initialization state and a mutex-protected outbound packet send queue with a counter, and exposing a keyed node-list lookup and a file-transfer accept path. The five network functions share these this-relative offsets, so common ownership is evidenced; the enclosing session class name and the WSADATA buffer at this+0x778 are not proven by the packet.

Methods: `0x0057FB90`, `0x00580C10`, `0x00581070`, `0x0058119A`, `0x00581600`

- `this+0x00000640` `HANDLE mutex_buffer_copy_handle` (read_write, DERIVED)
- `this+0x00000644` `DWORD mutex_buffer_copy_timeout` (read, DERIVED)
- `this+0x00000A74` `BYTE winsock_init_flag` (read_write, DERIVED)
- `this+0x00000AC8` `CNodeWrapper* send_queue_head` (read_write, DERIVED)
- `this+0x00000ACC` `CNodeWrapper* send_queue_tail` (write, DERIVED)
- `this+0x00000AD0` `CNodeWrapper* send_queue_cursor` (read_write, DERIVED)
- `this+0x00000AD4` `UINT send_queue_count` (read_write, DERIVED)
- `this+0x00000AD8` `HANDLE queue_mutex_handle` (read_write, DERIVED)
- `this+0x00000ADC` `DWORD queue_mutex_timeout` (read, DERIVED)
- `this+0x00000B38` `UINT send_counter` (read_write, DERIVED)
- `this+0x00000B3C` `HANDLE counter_mutex_handle` (read_write, DERIVED)
- `this+0x00000B40` `DWORD counter_mutex_timeout` (read, DERIVED)

### CLinkedList

Four-field singly-linked-list state (head, tail, cursor, count) that is the receiver of the plain list operations; node wrappers are 12-byte records (data +0x0, next +0x4, release flag +0x8, metadata +0xC) whose data objects are released through a vtable. The same head/tail/cursor/count offsets appear as embedded lists in CNodeListContainer and CDualListContainer, but equal offsets on different bases are not merged.

Methods: `0x00581940`, `0x005822B0`, `0x00582F60`, `0x005832E0`

- `this+0x00000000` `CNodeWrapper* head` (read_write, DERIVED)
- `this+0x00000004` `CNodeWrapper* tail` (read_write, DERIVED)
- `this+0x00000008` `CNodeWrapper* cursor` (read_write, DERIVED)
- `this+0x0000000C` `UINT count` (read_write, DERIVED)

### CNodeListContainer

Container embedding a singly linked list at base+0x0..0xC together with an owned Win32 handle at +0x10 gated by a close-flag byte at +0x18; also owns the handle-close and mutex-recreation helpers that share the +0x10/+0x18 layout (CloseHandleWrapper, RecreateMutex).

Methods: `0x005818E0`, `0x00581A20`, `0x00582310`, `0x00582360`

- `this+0x00000000` `CNodeWrapper* list_head` (read_write, DERIVED)
- `this+0x00000004` `CNodeWrapper* list_tail` (read_write, DERIVED)
- `this+0x00000008` `CNodeWrapper* list_cursor` (read_write, DERIVED)
- `this+0x0000000C` `UINT list_count` (read_write, DERIVED)
- `this+0x00000010` `HANDLE owned_handle` (read_write, DERIVED)
- `this+0x00000018` `BYTE handle_close_flag` (read, DERIVED)

### CDualListContainer

Container embedding two singly linked lists — list2 at +0x0..0xC and list1 at +0x10..0x1C — plus an owned Win32 handle at +0x20 gated by a close-flag byte at +0x28; supports full dual-list teardown (vtable slot 0 or slot 1 release) and a mutex-reinit helper on the +0x20/+0x28 handle slot.

Methods: `0x00581B30`, `0x00581EE0`, `0x00582190`, `0x00582650`, `0x00582720`, `0x00582CE0`

- `this+0x00000000` `CNodeWrapper* list2_head` (read_write, DERIVED)
- `this+0x00000004` `CNodeWrapper* list2_tail` (read_write, DERIVED)
- `this+0x00000008` `CNodeWrapper* list2_cursor` (read_write, DERIVED)
- `this+0x0000000C` `UINT list2_count` (read_write, DERIVED)
- `this+0x00000010` `CNodeWrapper* list1_head` (read_write, DERIVED)
- `this+0x00000014` `CNodeWrapper* list1_tail` (read_write, DERIVED)
- `this+0x00000018` `CNodeWrapper* list1_cursor` (read_write, DERIVED)
- `this+0x0000001C` `UINT list1_count` (read_write, DERIVED)
- `this+0x00000020` `HANDLE owned_handle` (read_write, DERIVED)
- `this+0x00000028` `BYTE handle_close_flag` (read, DERIVED)

### CNodeWrapper

12-byte linked-list node wrapper shared by the list containers: data pointer at +0x0, next link at +0x4, release flag byte at +0x8, metadata dword at +0xC. Destruction dispatch on the data object is gated by the release flag. Note: in DestroyDualLinkedLists (0x00581B30) the node chain is walked via the node link at node+0x0, which may contradict this layout.

Methods: 

- `obj+0x00000000` `void* data` (read_write, DERIVED)
- `obj+0x00000004` `CNodeWrapper* next` (read_write, DERIVED)
- `obj+0x00000008` `BYTE release_flag` (read, DERIVED)
- `obj+0x0000000C` `DWORD metadata` (unknown, GUESS)

### CPlacementAllocationDispatcher

Flag-dispatched destructor/delete helpers for objects and placement-allocated blocks: dispatch on flag bits 2 (0x2) and 1 (0x1) of the flags argument selects the per-object vs count-header block paths and whether memory is freed via FreeWrapper_7bcf. Whether this is a real class or a pair of compiler-generated delete helpers is unknown.

Methods: `0x00583150`, `0x005831B0`


## Compatibility contracts

- **WinsockInitGuardContract** — Winsock initialization must run at most once per session object: WSAStartup(2.2) writes WSADATA at this+0x778, the init flag byte at this+0xA74 is latched (1 after success, 0 after failure), and the failure path invokes the error handler sub_57D400 with the invalid-handle sentinel (void*)0xFFFFFFFF. A replacement must reproduce this guard and failure routing.
- **SendQueueMutexTriadContract** — The outbound send queue is guarded by three distinct mutexes: a counter mutex (handle this+0xB3C, timeout this+0xB40) guarding the send counter at this+0xB38 whose previous value is returned to the caller, a queue mutex (this+0xAD8, timeout this+0xADC) guarding the node queue (head this+0xAC8, tail this+0xACC, cursor this+0xAD0, count this+0xAD4), and a buffer-copy mutex (this+0x640, timeout this+0x644). All waits accept both signaled (0) and WAIT_TIMEOUT (0x80) as proceed conditions, and the send returns 1 on all paths.
- **PacketWireHeaderContract** — Every enqueued packet carries a 4-DWORD header copied to this+0xA84: first DWORD low word 2, first DWORD high word htons(0), second DWORD htonl(0); the 32-byte packet object is allocated via allocator 0x00587C03 and initialized with the vtable, sequence number, queue count and size via 0x0057B780.
- **NodeReleaseDispatchContract** — List node wrappers are 12-byte records (data +0x0, next +0x4, release flag byte +0x8, metadata +0xC). On teardown, when the node release flag is set and the data pointer is non-null, the data object is released through its vtable (slot 0 or slot 1 at vtable+4) with a single literal argument 1 (plain/list1) or 3 (list2); wrappers and, on the list2 path, the data blocks are freed via FreeWrapper_7bcf (0x00587BCF).
- **KeyedNodeLookupContract** — Network node lists are searched by comparing the node data field at +0x14 to a key (a2); matched data is copied via CopyBufferHeaderFieldsCallInit (0x00587370) or written to a caller buffer at a3+4 via BufferWriteWithParams (0x00587620) under the list mutex, and an optional counter increment (0x00587230) is applied when flag a4 is set.
- **HandleAndMutexLifecycleContract** — Owned handles follow a guarded lifecycle: a byte flag (at this+0x18 or this+0x28) gates whether the handle (at this+0x10 or this+0x20) is closed via CloseHandle, and the slot is zeroed only on success. Mutex recreation closes the existing handle when the validity flag is set, then CreateMutexA creates an unnamed inheritable mutex (SECURITY_ATTRIBUTES nLength=12, no descriptor, inheritable), and the validity flag is set only on success.
- **PlacementDeleteDispatchContract** — Destructor dispatch is keyed on flag bits of the flags argument: bit 2 (0x2) selects a placement-allocated block whose count header sits at this-1, processed via NTimeCallbackLoopWithSEH (0x0058A5F7) with a per-entry callback (40-byte stride with sub_57AEF0, or 308-byte stride with SingleVTablePointerSet); bit 1 (0x1) selects whether the block/object is freed via FreeWrapper_7bcf. The placement path returns this-1, the direct path returns this.

## Unresolved

- The network session object identity and the WSADATA buffer at this+0x778 are not evidenced as packet fields (only this+0xA74 appears in the packet refs); the enclosing class of the five network functions is unknown.
- sub_57D400 (failure handler) and the meaning of its 0xFFFFFFFF argument are unknown.
- The wire format of the 4-DWORD packet header and the role of this+0xA84 are unresolved; the behavioral distinction between CopyBufferHeaderFieldsCallInit (0x00587370) and sub_57DD40 on the 0 < a3 <= 2 path is unknown.
- FindNodeByKeyAndCopy (0x00581070) uses a local 28-byte buffer v15 whose semantic role is unknown; the purpose of the second mutex (this+0x640) versus the list mutex (this+0xAD8) — e.g. a reader/writer or buffer-pool split — is unknown.
- The accept/reject criterion of HandleFileTransferAccept (NegatedPredicate arguments a2/a3) and the transfer-processing semantics of sub_57E280 are unknown; Hex-Rays reports a positive sp value at function exit.
- In DestroyDualLinkedLists (0x00581B30) the node chain is walked via the node link at node+0x0, which contradicts the 12-byte node layout (data+0x0, next+0x4, flag+0x8) used by the other list functions; the node layout may differ per list family.
- Vtable dispatch semantics are unresolved: data objects are released via vtable slot 0 or slot 1 (vtable+0x4) with literal arguments 1 or 3; the concrete release/destroy targets and the meaning of the differing arguments are unknown.
- The identity of the resource behind the handle at this+0x20 (close flag this+0x28) on the dual-list container is unknown.
- DestroyOwnedLists (0x00582190) treats list2 records as size-prefixed (a 4156-byte header per NTimeCallbackLoopWithSEH); the record format and the two callback arguments derived from the record prefix are inferred only.
- SingleFunctionCallWrapper_3650 (0x00583650) forwards to EmptyStub_0170 whose identity and behavior are outside this packet; the purpose of the extra wrapper indirection is unresolved.
- The SEH registration globals (0x0059CACB, 0x0059CB08, 0x0059CB50, 0x0059CBF0, 0x0059CC48, 0x0059CCD0, 0x0059CD90, 0x0059CDC8) are referenced by the fact tables but do not appear in the raw decompiled bodies; their role is not modeled.
- The globals 0xFF00000000005450/0x...451/0x...452 are listed as written by RecreateMutex and MutexInitOrReinit but do not appear in the raw bodies; they are treated as stack-struct aliasing artifacts in the IDB and retained unresolved.
- CLinkedList (base CLinkedList) shares the same head/tail/cursor/count offsets as the embedded lists of CNodeListContainer and CDualListContainer (base this); the packet does not prove these are the same class, and equal offsets on different bases are not merged.
- Whether CPlacementAllocationDispatcher is a real class or a pair of compiler-generated scalar-deleting destructor helpers is unknown.
