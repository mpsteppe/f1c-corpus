# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

A heterogeneous set of runtime objects and helpers. ByteAlignedMemoryCopyFromStruct (0x0057A230) reads a length at this+0x2C and copies the embedded buffer at this+45; AudioStreamStructInitWithDefaults (0x0057A3F0) sets a small audio-stream header (literals 1, 3397, 472) and zero-fills 32 bytes at +0x10. A family of pointer-to-pointer vtable dispatch shims (0x0057A580, 0x0057A830, 0x0057A880, 0x0057A8B0, 0x0057A8E0) dereference *this to an object and call a virtual slot (0x6C/0x9C/0x78/0x7C/0xC4), and DispatchVirtualInitAllocFinalize (0x0057A4F0) drives a vtable init/finalize lifecycle around a context, sharing the obj+0x5D flag byte with ByteFieldSetterAtOffset0x5d (0x0057A570). MutexGuardedValueReadAndClear (0x0057A590) is a thread-safe read-and-clear over obj+0x5C4/obj+0x5C8 under the mutex at obj+0x618, while the animation-timing pair (0x0057A5A0, 0x0057A610) consume the mutex-guarded timer provider (0x00584F90). Three near-identical MSVC SEH-guarded one-time global initializers (0x0057A940, 0x0057ADB0, 0x0057AE30) build the same fixed global object chain (unk_8D4370..dword_8D423C) gated by dword_5E9EF4, differing only in their SEH seed (0x008D3BF5/0x008D3BF9/0x008D3C19). The Winsock network core owns a connection list (head this+0xAAC, cursor +0xAB4, socket-address ptr +0xAB8, mutex +0xABC, timeout +0xAC0) and a message-event list (head +0xAC8, cursor +0xAD0, mutex +0xAD8, timeout +0xADC) shared by NetworkSocketReceiveAndDispatch (0x0057CB50) and DuplicateConnectionCheckRegister (0x0057DC10), plus NetworkPacketConstructor (0x0057AFA0), Copy16ByteStruct (0x0057B680), NetworkSocketCreate (0x0057BEE0), SocketBindPortScan (0x0057C7B0), StackBufferCopyPredicateCall (0x0057AAF0), PointerCheckWithFallback (0x0057AB20), IterateTriggersViaVtableCallHandlersPerTickWrapper (0x0057A800) and PlaySoundOnStateChangeDispatch (0x0057D890). Most packet owners are UnknownObject; class groupings here are DERIVED/GUESS worker synthesis.

## Function roles

- `0x0057A230` **LengthPrefixedBufferOwner** — Length-prefixed embedded-buffer getter (__thiscall): reads the length field at this+0x2C into the caller's *a3 and, when non-zero, qmemcpy's that many bytes from this+45 into the destination a2; returns the length in the copy path or the original `this` when the length is zero. Used by NetworkEntrantSetupWithIDCheck and UniqueID.
- `0x0057A3F0` **AudioStreamHeader** — Audio-stream structure initializer: sets dword this+0x0=1, this+0x4=0, word this+0x8=3397, word this+0xA=472, this+0xC=0 and zero-fills a 32-byte block at this+0x10 via memset; returns this. Matches the ctor_init template; called by sub_463E20.
- `0x0057A4F0` **VTableLifecycleDriver** — Vtable-lifecycle dispatcher around a context structure a14: feeds the context flag byte at a14+0x2B into SingleFieldSetter and a vtable+0x68 init call, forwards 12 copied stack arguments to AllocationWrapper, calls the vtable+0xC0 finalize entry, clears the byte at obj+0x5D (obj = *this) and copies the string parameter a15 via StringCopyToBufferWithLengthCap; returns the context pointer a14.
- `0x0057A570` **VTableLifecycleDriver** — Trivial byte setter: reads the target object pointer stored at *this and writes the byte argument a2 into that object at offset 0x5D unconditionally, returning the object pointer. Invoked by SynchronizeWithServer during server state synchronization.
- `0x0057A580` **VTableDispatchHandle** — Thin thiscall dispatch shim: loads the object pointer from the this slot, reads the virtual function pointer at vtable offset 0x6C of that object, calls it with the object as the this argument, and returns its result. Invoked by CollisionSpatialQuery as a virtual query dispatch.
- `0x0057A590` **MutexProtectedSharedValue** — Mutex-guarded read-and-clear: waits up to 5 ms on the mutex handle at obj+0x618 (obj = *this), on success reads the shared integer at obj+0x5C4 into the result and clears it, optionally shifts the string buffer at obj+0x5C8 by a2 bytes when non-zero, always zeroes the string's first byte, and releases the mutex when the re-read handle is non-null; returns the read value or 0 on wait timeout/failure.
- `0x0057A5A0` **AnimationTimingContext** — Animation-timing update on a context object: reads the mutex-guarded timer via MutexGuardedTimerRead on *this, copies it into a local counter structure via CounterAssignment, resolves a secondary object through the vtable entry at offset 88 of the context vtable, emits a five-argument telemetry call (0, 14, 0, 3, 500), sets a flag byte at offset 4 of the resolved object's +72 data, persists the timer via SingleFunctionCallWrapper_6a00, and returns the result of a conditional vtable dispatch on the resolved object.
- `0x0057A610` **AnimationTimingContext** — Timed animation-value query wrapper: reads the current timer value via MutexGuardedTimerRead on the object at *this (this+0x0), passes it together with a3 and a4 into PhysicsQueryGetterWithReadyFlag, and on success copies the 8-byte result into the caller's buffer a2 and returns 1; on query failure returns 0 without writing a2. Used by RunCollisionDetectionLoop and SessionSynchronizer during per-frame work.
- `0x0057A800` **TriggerIterationWrapper** — One-line wrapper: invokes IterateTriggersViaVtableCallHandlersPerTick on the object pointed to by *this and returns whether that call returned 0 (as a BOOL). Called by ClearPlayerSlots.
- `0x0057A830` **VTableDispatchHandle** — COM-style boolean-inversion test: reads the interface object obj from *this (this+0x0), loads the vtable base from *obj (obj+0x0), calls the __thiscall method at vtable slot +156 (0x9C) on obj with a2 and a3 forwarded, and returns TRUE exactly when that predicate method returns 0. Invoked by ShortComputation_23b0 as a single-slot virtual predicate test.
- `0x0057A880` **VTableDispatchHandle** — COM-style query wrapper: dereferences the pointer-to-pointer handle *this to the object, then calls the virtual method at vtable offset 0x78 with the object, a pointer to an output int, and a pointer to a 4-byte stack buffer; returns the int the method wrote when it returns non-zero, otherwise 0. Used by DriverEntrantSetupEntry, BufferSendWithLocks, NetworkEntrantSetupWithIDCheck, UniqueID and sub_463E20 (driver/entrant setup and network-ID paths).
- `0x0057A8B0` **VTableDispatchHandle** — COM-style thin forwarder: dereferences the pointer-to-pointer handle *this to the object, then unconditionally calls the virtual method at vtable offset 0x7C with the object as the implicit this, returning the callee's int result unchanged. Used by DriverEntrantSetupEntry, BufferSendWithLocks, NetworkEntrantSetupWithIDCheck, UniqueID and ConditionalObjectCleanup.
- `0x0057A8E0` **VTableDispatchHandle** — COM-style vtable predicate: reads the object pointer stored at this+0x0, fetches the method at vtable offset 0xC4 of that object, invokes it with (object, a2), and returns TRUE iff the method returns 0. Callers (BufferSendWithLocks, NetworkEntrantSetupWithIDCheck, UniqueID) suggest a network/messaging interface contract.
- `0x0057A940` **GlobalObjectChainInitializer** — MSVC-generated SEH-guarded one-time global object initializer thunk: registers a per-frame SEH handler seeded with the read-only global unk_8D3BF5, applies a shared first-entry guard on dword_5E9EF4 (body runs only on the first call; later calls increment the counter), and on the first call builds the fixed chain of global objects (unk_8D4370, unk_8D4248, dword_8D4330, unk_8D42A0, unk_8D42D8, dword_8D43C8, dword_8D4210, dword_8D423C) through SEH/vtable/locale constructor helpers, cross-wiring entries with the address of unk_8D42A0 and OR-ing flag value 2 into one slot. Returns the original ecx saved at frame slot a1-20.
- `0x0057AAF0` **StackBufferPredicateForwarder** — Stack-buffer predicate forwarder: zeroes the output parameter a2 (this+0x0), copies 48 bytes from a1 into a local 12-DWORD stack buffer, then calls sub_57ABB0 passing all twelve buffer DWORDs plus the a2 pointer as individual arguments; returns TRUE exactly when sub_57ABB0 returns 0. Used by sub_463E20 as a copy-and-predicate step.
- `0x0057AB20` **PointerSlotCleanupHelper** — Predicate-with-fallback helper: tests the pointer stored at this+0x0 by calling sub_57ACB0(*this); when the call returns non-zero it returns 0 (pointer is live, nothing to do), otherwise it clears the pointer (*this = 0) and returns 1 to signal the fallback cleared the slot. Used as a cleanup helper by ConditionalObjectCleanup.
- `0x0057ADB0` **GlobalObjectChainInitializer** — MSVC-generated SEH-guarded one-time global object initializer, twin of 0x0057A940 seeded with the read-only global unk_8D3BF9: same first-entry guard on dword_5E9EF4 and the same fixed construction/wiring chain (unk_8D4370, unk_8D4248, dword_8D4330, unk_8D42A0, unk_8D42D8, dword_8D43C8, dword_8D4210, dword_8D423C). Returns the original ecx saved at frame slot a1-20.
- `0x0057AE30` **GlobalObjectChainInitializer** — MSVC-generated SEH-guarded one-time global object initializer, twin of 0x0057A940 seeded with the read-only global unk_8D3C19: same first-entry guard on dword_5E9EF4 and the same fixed construction/wiring chain (unk_8D4370, unk_8D4248, dword_8D4330, unk_8D42A0, unk_8D42D8, dword_8D43C8, dword_8D4210, dword_8D423C). Returns the original ecx saved at frame slot a1-20.
- `0x0057AFA0` **NetworkPacketList** — Appends a new address/packet entry to a linked list embedded in `this`: clears the byte flag at this+0x4, allocates a 16-byte AF_INET address struct (family 2, network-byte-order zero IP/port via htonl/htons) and overwrites it with four DWORDs from a2, allocates a 12-byte list node pointing at the address struct, appends the node to the head/tail chain at this+0x8/0xC/0x10, and increments the insert counter at this+0x14; returns 0.
- `0x0057B680` **Copy16StructOwner** — Fixed-width 16-byte struct copy helper: copies four consecutive dwords (offsets 0x0, 0x4, 0x8, 0xC) from source pointer a2 to receiver `this` and returns the copied tail dword at +0xC as the result. Invoked by sub_57BF00.
- `0x0057BEE0` **NetworkSocketOwner** — Init-and-create socket helper: calls the vtable method at *(this+0x0)+0x74 on this as an unconditional thiscall initializer, then creates a Winsock TCP socket via socket(2, 1, 0) (AF_INET, SOCK_STREAM) and returns the SOCKET handle. Caller sub_57BF00 is recorded but its context is unexamined.
- `0x0057C7B0` **SocketBindPortScanner** — Winsock bind-with-port-scan: binds the socket s to local port a2 and, on failure, scans forward up to 100 ports; each iteration builds a 16-byte AF_INET sockaddr (family 2, zeroed address, candidate port via htons) and calls bind, returning the successfully bound network-order port, or -1 when the scan is exhausted or WSAGetLastError is 10022 (WSAEINVAL). Standalone helper with no `this` object.
- `0x0057CB50` **NetworkConnectionManager** — Network receive-and-dispatch loop driven by a socket and a direction flag a3 (datagram vs stream): select() poll on zero timeout, then recvfrom() (datagram) or recv() (stream) into a per-object buffer obtained from this+2680; stream data is pushed into per-connection ring buffers (2-byte length header, message length v85+v86+4), popped when complete, and dispatched through the vtable entry at obj+0x58; the datagram path resolves the peer address and dispatches through sub_57BF00. Maintains two mutex-protected linked lists on `this`: a connection list (head this+0xAAC, mutex this+0xABC, timeout this+0xAC0) storing last-receive timestamps at conn+0x2C, and a message-event list (head this+0xAC8, mutex this+0xAD8, timeout this+0xADC) mapping sender address to event ID. recv failures are mapped via WSAGetLastError to human-readable strings; WSA 10040 reallocates the receive buffer and retries. Returns 1 when a complete message was dispatched, 0 otherwise. Called by NetworkAccept.
- `0x0057D890` **PlaySoundOnStateChangeDispatcher** — Play-sound-on-state-change dispatch: reads a thread-safe integer from this via ThreadSafeIntReadWithMutex; when the value at offset 0x14 of the a3 object differs from it, and the pointer at a3+28 is non-null, resolves that object through sub_4B3DB0 and dispatches the resulting handle with sub_57D6C0(this, a2, handle). Always returns 0.
- `0x0057DC10` **NetworkConnectionManager** — Registers an incoming network connection after checking it for duplicates: reads a mutex-guarded timestamp, stamps the incoming record at a2+44/a2+48, initializes the socket via OffsetGetter/TCPSocketInit, acquires the connection mutex at this[0xABC] (timeout this[0xAC0]), walks the existing connection list from head this[0xAAC] (cursor this[0xAB4]) comparing family/port fields through the socket-address pointer at this[0xAB8], reports any duplicate via sub_57DE30 with the aDuplicateConne string, appends the new node with LinkedListNodeAppend_6000, releases the mutex, and returns 0.

## Proposed classes

### LengthPrefixedBufferOwner

Holds a length-prefixed embedded buffer: the length at this+0x2C and the payload starting at this+45 are exposed by ByteAlignedMemoryCopyFromStruct to network/driver callers.

Methods: `0x0057A230`

- `this+0x0000002C` `int embedded_buffer_length` (read, DERIVED)

### AudioStreamHeader

Small audio-stream header initialized with fixed default literals (enabled=1, words 3397/472) and a zero-filled 32-byte payload block at +0x10.

Methods: `0x0057A3F0`

- `this+0x00000000` `int enabled_flag` (write, GUESS)
- `this+0x00000004` `int reserved_dword` (write, GUESS)
- `this+0x00000008` `short sample_rate_hint` (write, GUESS)
- `this+0x0000000A` `short channels_hint` (write, GUESS)
- `this+0x0000000C` `int reserved_dword_c` (write, GUESS)
- `this+0x00000010` `byte[32] payload_block` (write, GUESS)

### VTableLifecycleDriver

Drives an object's vtable lifecycle around a context (init at vtable+0x68, allocation, finalize at vtable+0xC0, string copy) and owns the shared synchronization flag byte at obj+0x5D that ByteFieldSetterAtOffset0x5d overwrites.

Methods: `0x0057A4F0`, `0x0057A570`

- `this+0x00000000` `void* target_object_ptr` (read, GUESS)
- `obj+0x0000005D` `byte sync_flag_byte` (read_write, DERIVED)

### MutexProtectedSharedValue

Thread-safe shared slot: an integer value at obj+0x5C4 read-and-cleared under the mutex at obj+0x618, together with a string buffer at obj+0x5C8 that is shifted/truncated under the same lock.

Methods: `0x0057A590`

- `obj+0x000005C4` `int shared_value` (read_write, DERIVED)
- `obj+0x000005C8` `char* shared_string` (read_write, DERIVED)
- `obj+0x00000618` `void* mutex_handle` (read, DERIVED)

### AnimationTimingContext

Context handle for mutex-guarded timer reads (via MutexGuardedTimerRead on *this) used by the animation-timing update and the timed animation-value query.

Methods: `0x0057A5A0`, `0x0057A610`

- `this+0x00000000` `void* timer_handle` (read, GUESS)

### TriggerIterationWrapper

BOOLean wrapper over a per-tick trigger iteration callback invoked on the object pointed to by *this.

Methods: `0x0057A800`

- `this+0x00000000` `void* target_object_ptr` (read, GUESS)

### GlobalObjectChainInitializer

MSVC SEH-guarded one-time global initializer family: three near-identical thunks (SEH seeds 0x008D3BF5/0x008D3BF9/0x008D3C19) share the first-entry guard dword_5E9EF4 and build the same fixed chain of global objects (unk_8D4370, unk_8D4248, dword_8D4330, unk_8D42A0, unk_8D42D8, dword_8D43C8, dword_8D4210, dword_8D423C) with cross-wiring to unk_8D42A0.

Methods: `0x0057A940`, `0x0057ADB0`, `0x0057AE30`


### StackBufferPredicateForwarder

Forwarder that zeroes the caller's output slot at this+0x0, copies a 48-byte stack buffer, and feeds it as twelve DWORD arguments to the sub_57ABB0 predicate.

Methods: `0x0057AAF0`

- `this+0x00000000` `void* output_slot` (write, DERIVED)

### PointerSlotCleanupHelper

Pointer-slot cleanup fallback: probes the pointer at this+0x0 via sub_57ACB0 and clears the slot (*this = 0) when the probe reports the pointer is not live.

Methods: `0x0057AB20`

- `this+0x00000000` `void* pointer_slot` (read_write, DERIVED)

### VTableDispatchHandle

Pointer-to-pointer handle whose *this resolves to an object exposing a vtable; the dispatch shims call specific virtual slots (0x6C, 0x78, 0x7C, 0x9C, 0xC4) with the object as the implicit this and return or invert the result.

Methods: `0x0057A580`, `0x0057A830`, `0x0057A880`, `0x0057A8B0`, `0x0057A8E0`

- `this+0x00000000` `void* object_handle_ptr` (read, DERIVED)
- `obj+0x00000000` `void* vtable` (read, DERIVED)

### NetworkPacketList

Embedded singly-linked list of 12-byte address/packet nodes: dirty byte flag at +0x4, head at +0x8, tail at +0xC, secondary tail at +0x10, insert counter at +0x14.

Methods: `0x0057AFA0`

- `this+0x00000004` `byte dirty_flag` (write, GUESS)
- `this+0x00000008` `void* list_head` (write, DERIVED)
- `this+0x0000000C` `void* list_tail` (read_write, DERIVED)
- `this+0x00000010` `void* list_tail_secondary` (write, DERIVED)
- `this+0x00000014` `int insert_count` (read_write, DERIVED)

### Copy16StructOwner

Receiver of a fixed-width 16-byte struct copy (four dwords at +0x0/+0x4/+0x8/+0xC) fed by sub_57BF00.

Methods: `0x0057B680`

- `this+0x00000000` `dword data_dword_0` (write, DERIVED)
- `this+0x00000004` `dword data_dword_1` (write, DERIVED)
- `this+0x00000008` `dword data_dword_2` (write, DERIVED)
- `this+0x0000000C` `dword data_dword_3` (read_write, DERIVED)

### NetworkSocketOwner

Socket-handle owner initialized through a vtable+0x74 thiscall and used to create an AF_INET/SOCK_STREAM Winsock socket.

Methods: `0x0057BEE0`

- `this+0x00000000` `void* socket_wrapper_ptr` (read, GUESS)
- `obj+0x00000074` `void* init_vtable_slot` (read, GUESS)

### SocketBindPortScanner

Standalone Winsock helper binding a socket to a local port with a forward port-scan on failure (up to 100 attempts, stopping on WSAEINVAL 10022); operates purely on socket and port parameters, no this object.

Methods: `0x0057C7B0`


### NetworkConnectionManager

Network connection registry shared by NetworkSocketReceiveAndDispatch and DuplicateConnectionCheckRegister: a mutex-protected connection list (head this+0xAAC, cursor +0xAB4, socket-address pointer +0xAB8, mutex +0xABC, timeout +0xAC0) storing per-connection receive timestamps, and a message-event list (head +0xAC8, cursor +0xAD0, mutex +0xAD8, timeout +0xADC) mapping sender address to event IDs.

Methods: `0x0057CB50`, `0x0057DC10`

- `this+0x00000AAC` `void* connection_list_head` (read_write, DERIVED)
- `this+0x00000AB4` `void* connection_list_cursor` (read_write, DERIVED)
- `this+0x00000AB8` `void* socket_address_ptr` (read, DERIVED)
- `this+0x00000ABC` `void* connection_list_mutex` (read, DERIVED)
- `this+0x00000AC0` `int connection_list_mutex_timeout` (read, DERIVED)
- `this+0x00000AC8` `void* message_event_list_head` (read, DERIVED)
- `this+0x00000AD0` `void* message_event_list_cursor` (read, DERIVED)
- `this+0x00000AD8` `void* message_event_list_mutex` (read, DERIVED)
- `this+0x00000ADC` `int message_event_list_mutex_timeout` (read, DERIVED)

### NetworkConnectionNode

Referenced layout of a connection-list node: socket at +0x20, primary peer port/IP at +0x2/+0x4, secondary port/IP at +0x12/+0x14, last-receive timestamp (float) at +0x2C, and a ring-buffer used-count at +0x1038. Reachable from both the head-derived base *(*(this+0xAAC)+0x0) and the cursor-derived base *(*(*(this+0xAB4)+0x4)+0x0).

Methods: 

- `*(*(this+0xAAC)+0x0)+0x00000020` `SOCKET socket` (read, DERIVED)
- `*(*(*(this+0xAB4)+0x4)+0x0)+0x00000002` `word peer_port_primary` (read, DERIVED)
- `*(*(*(this+0xAB4)+0x4)+0x0)+0x00000004` `dword peer_ip_primary` (read, DERIVED)
- `*(*(*(this+0xAB4)+0x4)+0x0)+0x00000012` `word peer_port_secondary` (read, DERIVED)
- `*(*(*(this+0xAB4)+0x4)+0x0)+0x00000014` `dword peer_ip_secondary` (read, DERIVED)
- `*(*(*(this+0xAB4)+0x4)+0x0)+0x0000002C` `float last_receive_timestamp` (read_write, DERIVED)
- `*(*(this+0xAAC)+0x0)+0x00001038` `int ring_buffer_used_count` (read, DERIVED)

### SocketAddressCompareRecord

Referenced address record reached through the socket-address pointer at this+0xAB8, compared against incoming connections on family/port fields at +2/+4 and the alternate fields at +0x12/+0x14 for duplicate detection.

Methods: 

- `*(*(this+0xAB8)+0x0)+0x00000002` `word addr_field_02` (read, GUESS)
- `*(*(this+0xAB8)+0x0)+0x00000004` `dword addr_field_04` (read, GUESS)
- `*(*(this+0xAB8)+0x0)+0x00000012` `word addr_field_12` (read, GUESS)
- `*(*(this+0xAB8)+0x0)+0x00000014` `dword addr_field_14` (read, GUESS)

### PlaySoundOnStateChangeDispatcher

State-change audio dispatcher: reads a thread-safe state token from this, compares it against a3+0x14, and on change resolves a3+28 through sub_4B3DB0 and dispatches via sub_57D6C0.

Methods: `0x0057D890`


## Compatibility contracts

- **WinsockSocketImportContract** — The network path uses Winsock through pointer globals at 0x0059E2CC..0x0059E324 (socket 0x0059E2DC, bind 0x0059E2D4, recvfrom 0x0059E2E0, recv 0x0059E304, select 0x0059E2E4, htons 0x0059E2F4, htonl 0x0059E2D8, ntohs 0x0059E2CC, WSAGetLastError 0x0059E324): AF_INET=2, SOCK_STREAM=1, 16-byte sockaddr, port scan capped at 100 attempts, bind failure policy on WSAEINVAL (10022), and WSA 10040 buffer reallocation (BufferReallocationAndDataCopy(512)) with retry.
- **MutexGuardedSharedValueContract** — Thread-safe shared slot semantics: the integer at obj+0x5C4 is read-and-cleared and the string at obj+0x5C8 is shifted/truncated under the mutex at obj+0x618 with a 5 ms wait; the mutex is released only when the re-read handle is non-null, and the read-and-clear returns 0 when the wait times out or fails.
- **NetworkConnectionListContract** — NetworkConnectionManager carries two mutex-protected intrusive lists: a connection list (head this+0xAAC, cursor +0xAB4, socket-address pointer +0xAB8, mutex +0xABC, timeout +0xAC0) whose nodes hold a socket at +0x20, a ring-buffer used count at +0x1038 and a last-receive timestamp (float) at +0x2C, and a message-event list (head +0xAC8, cursor +0xAD0, mutex +0xAD8, timeout +0xADC) mapping sender address to event ID; node next pointers live at +0x4.
- **NetworkMessageFrameContract** — Stream messages are framed with a 2-byte length header in a per-connection ring buffer: the full message length is v86 + v85 + 4 and a message is dispatched only when the buffered count matches (v67 == v86 + v85 + 4); the completeness check caps the stack copy at 0x604. WSA errors are mapped through dispatch tables 0x0057D378/0x0057D3B0 to message-string globals 0x005E542C..0x005E54B8, with aClosedGraceful (0x005E54D0) on a clean close.
- **StaticInitChainContract** — Three MSVC SEH-guarded one-time global initializers (0x0057A940, 0x0057ADB0, 0x0057AE30) share the first-entry guard dword_5E9EF4 and construct the identical fixed global chain (unk_8D4370, unk_8D4248, dword_8D4330, unk_8D42A0, unk_8D42D8, dword_8D43C8, dword_8D4210, dword_8D423C) with cross-wiring to unk_8D42A0 and an OR of flag value 2 into one slot; they differ only in their SEH seed global (0x008D3BF5/0x008D3BF9/0x008D3C19) and return the saved ecx.

## Unresolved

- All packet owners are UnknownObject/UNKNOWN; every class grouping (LengthPrefixedBufferOwner, AudioStreamHeader, VTableLifecycleDriver, MutexProtectedSharedValue, AnimationTimingContext, TriggerIterationWrapper, GlobalObjectChainInitializer, StackBufferPredicateForwarder, PointerSlotCleanupHelper, VTableDispatchHandle, NetworkPacketList, Copy16StructOwner, NetworkSocketOwner, SocketBindPortScanner, NetworkConnectionManager, NetworkConnectionNode, SocketAddressCompareRecord, PlaySoundOnStateChangeDispatcher) is worker synthesis at DERIVED/GUESS, not packet evidence.
- The five vtable dispatch shims (0x0057A580/0x0057A830/0x0057A880/0x0057A8B0/0x0057A8E0) share the pointer-to-pointer *this pattern, but their target object classes and the concrete semantics of slots 0x6C/0x78/0x7C/0x9C/0xC4 are unknown; the VTableDispatchHandle union is argued from the identical handle layout, not proven.
- obj+0x5D is written by both 0x0057A4F0 (cleared to 0) and 0x0057A570 (set from an argument) through the same deref base; common ownership of the flag byte is argued from the shared base/offset, not proven.
- The static-init chain (0x0057A940/0x0057ADB0/0x0057AE30) may be a CRT iostream/locale static-init block or an application global initializer; the vtable tables off_5E6748/unk_5E6768/unk_5E6788 and the frame helpers sub_59A54D/sub_59A5E9 are not separately evidenced, and the purpose of the shared counter dword_5E9EF4 beyond first-time guarding is unknown.
- The ring-buffer and message wire format (2-byte length header, message length v86+v85+4, cap 0x604) is inferred from the completeness check, not evidenced; the exact stream framing contract requires the connection node's ring-buffer descriptor (at conn+54) which has no dedicated field ref.
- The connection node is reached through two different deref bases (head-derived *(*(this+0xAAC)+0x0) and cursor-derived *(*(*(this+0xAB4)+0x4)+0x0)); the ring-buffer used count at 0x1038 is read through both, and treating them as one structure (NetworkConnectionNode) is argued but not proven.
- WSA message-string byte globals 0xFF00000000005430..0x005439 are referenced by the error dispatch but resolve outside the normal data range (bad-address artifacts); their exact encoding/usage is unverified.
- global:0x008D3BFA is recorded by the IDB as read by 0x0057AAF0 and 0x0057AB20 but does not appear in the decompiled bodies; role unknown.
- obj+0x58 is the only 0x58-sized vtable member in the packet (used for message-object dispatch by 0x0057CB50); its handler semantics are unknown.
- AudioStreamHeader literal defaults (1, 3397, 472) and the stream header layout have no consumer evidence; the role of caller sub_463E20 in audio setup is not established.
- The semantics of sub_57ABB0 (predicate contract), sub_57ACB0 (pointer-liveness predicate), sub_57BF00 (datagram pre-dispatch), sub_57D400 (select error hook), sub_57DE30 (duplicate diagnostic) and sub_57D6C0 (audio dispatch) are external to this packet's evidence.
- NetworkSocketReceiveAndDispatch resolves the peer address through this+2692 ((this+673)*4) and the per-object receive buffer through this+2680 via sub_563E70/SimpleFieldGetter_bfc0; these this-offset regions are prose-inferred and have no packet field refs.
- PlaySoundOnStateChangeDispatcher's a2 argument semantics and the a3+0x14 state-token meaning depend on the audio subsystem contract, not recoverable here.
- The distinction between the tail pointers at this+0xC and this+0x10 in NetworkPacketList is unclear; the per-call null-guard branches around the allocator are decompiler artifacts.
- SocketAddressCompareRecord's field semantics (+2/+4/+0x12/+0x14) are duplicate-comparison fields only; the sockaddr layout mapping to family/port/IP is not fully determined.
- SocketBindPortScanner has no this object - it is a free helper over socket and port parameters; the 10022/100-port policy rationale is not stated.
