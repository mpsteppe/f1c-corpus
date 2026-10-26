# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

This packet spans nineteen functions that implement generic runtime plumbing rather than any single feature. A cluster of four functions (0x0057A680, 0x0057A690, 0x0057A6A0, 0x0057A730) operate through a COM-style handle: *this holds an interface object pointer, the vtable base is *obj, and a __thiscall method at a fixed slot (0x60, 0x64, or 0x58) is dispatched on obj. Four more functions (0x0057A950, 0x0057A990, 0x0057AA70, 0x0057AE80) are trivial wrappers that forward a cleanup/free routine's address to BooleanToIntConversion (0x00587B3E). 0x0057A980 is compiler-style once-guarded static initialization. A large server-side command dispatcher (0x0057BF00) handles prefix-checked network commands: UDP status replies built from getsockname data, a mutex-protected lobby-state word at this+0x5C4 (values 1-5) gated on this+0x5D and this+0x618 mutexes, and a direct-connect sequence with a bind-port scan retry loop and a peer node registered under the this+0xBEC mutex. Socket lifecycle (0x0057C8E0) and a config-string parser into a 5-byte record (0x0057CA10) are isolated helpers. Four list-teardown functions (0x0057E570, 0x0057E6E0, 0x0057E760, 0x0057E7E0) each destroy a mutex-protected singly-linked list, all invoked by NetworkCleanup_fbe0 (0x0057FBE0); they share the node shape {data@+0, next@+4, flag@+8} and free node data via FreeWrapper_7bcf when the flag byte is set. 0x005804A0 initializes a network listener (UDP bind at this+0x910, TCP bind at +50, vtable+72 init and vtable+144 post-listen callbacks). 0x00584230 is a 15-case session-protocol message dispatcher driven by a bitmask decoded from a packet entry table, and 0x00585040 drains a vtable-dispatched queue plus a mutex-guarded node list. Class ownership is uncertain (owner trust UNKNOWN throughout the packet); the class grouping below is DERIVED from shared this+0x offset usage, and must not be read as proven single-owner structures.

## Function roles

- `0x0057A680` **ComInterfaceHandle** — COM-style single-slot virtual dispatch: reads interface object from *this, loads vtable base from *obj, calls __thiscall method at vtable slot +96 (0x60) and returns its result.
- `0x0057A690` **ComInterfaceHandle** — COM-style single-slot virtual dispatch: reads interface object from *this, loads vtable base from *obj, calls __thiscall method at vtable slot +100 (0x64) and returns its result.
- `0x0057A6A0` **ComInterfaceHandle** — Dispatch a network data send: obtain sender object via vtable slot 0x58 through *this; block with return 10 when null; forward payload through the sub-object at v8+72 (slot 0x20) or set its flag byte 4; then sub_586800/sub_586A00 and route via 0x00585380 or sub_585270.
- `0x0057A730` **ComInterfaceHandle** — Two-step dispatch helper: walk a linked structure via LinkedListWalkWithInputDispatch (0x00585320) passing a2, then queue an APC-style async procedure call on *this via QueueUserAPCAsyncProcedureCall (0x00585DE0) with a null argument and return its result.
- `0x0057A950` **CleanupCallbackRegistrar** — Cleanup wrapper: materialize the address of sub_57A960 and forward it as an integer to BooleanToIntConversion (0x00587B3E); return that helper's result.
- `0x0057A980` **GuardedStaticInitScope** — Compiler-style once-guarded static initialization: register SEH frame (unk_8D3BF4), run a one-time guard on global init counter dword_5EA04C, construct six static objects via vtable-setup/allocation/SEH-frame helpers, link them into the parent frame, return the saved context value.
- `0x0057A990` **CleanupCallbackRegistrar** — Free-callback wrapper: materialize the address of sub_57A9A0 and forward it as an integer to BooleanToIntConversion (0x00587B3E); return that helper's result.
- `0x0057AA70` **CleanupCallbackRegistrar** — Cleanup wrapper: materialize the address of sub_57AA80 and forward it as an integer to BooleanToIntConversion (0x00587B3E); return that helper's result.
- `0x0057AE80` **CleanupCallbackRegistrar** — Cleanup-callback registration thunk: read the address of sub_57AE90 and pass it to BooleanToIntConversion (0x00587B3E); return the integer result.
- `0x0057BF00` **NetworkSessionListener** — Server-side network command dispatch: one-time cache of prefix length into dword_8D3C14, prefix reject (return 0), bounded command-token split, then three branches: UDP status reply built from getsockname with reply-code lowered by this+0x5D; mutex-protected lobby-state write (1-5) at this+0x5C4 gated by this+0x618; and a direct-connect sequence (bind-port scan with WSAEADDRINUSE retry, peer registration under this+0xBEC, two notify rounds, teardown). Returns 1 on handled paths.
- `0x0057C8E0` **SocketHandleLifecycle** — Graceful socket close: when the stored handle is not INVALID_SOCKET (-1), shutdown(SD_SEND) when the graceful flag is set, drain via recv until 0/-1, closesocket, write -1 back; return the closesocket result.
- `0x0057CA10` **ConfigCommandStringParser** — Parse a config/command string with two delimiter types into a 5-byte output record: primary delimiter byte_5C3F6C segments (bounded copies via sub_587DD0), secondary delimiter word_5BEB48 sub-segments converted to bytes via sub_587ECE; word result at a2+2, four bytes at a2+4..a2+7; return 1 on full success, 0 on any null segment.
- `0x0057E570` **NetworkConnectionListOwner** — Mutex-protected connection-list cleanup: acquire this+0xABC (timeout this+0xAC0), walk nodes until the shared head record, unlink, destroy via sub_491E40 and free via FreeWrapper_7bcf, reset head-record fields and ring buffer under the this+0xBEC handle, re-queue the record, release mutexes.
- `0x0057E6E0` **NetworkConnectionListOwner** — Mutex-protected linked-list teardown: acquire mutex at this+0xAD8 (timeout this+0xADC), walk nodes from this+0xAC8, call the first vtable entry (destructor, argument 1) on node data only when node+0x8 flag and node+0x0 data are set, free every node via FreeWrapper_7bcf, clear this+0xAC8..0xAD4, release mutex.
- `0x0057E760` **NetworkConnectionListOwner** — Mutex-protected singly-linked-list flush/destroy: wait on this+0xB10 (timeout this+0xB14), walk from this+0xB00 following node+0x4, free node data via FreeWrapper_7bcf when node+0x8 flag is set, free each node, zero this+0xB00..0xB0C, release this+0xB10 mutex.
- `0x0057E7E0` **NetworkConnectionListOwner** — Mutex-protected singly-linked-list destruction: wait on this+0xB2C (timeout this+0xB30), walk from this+0xB1C following node+0x4, free node data via FreeWrapper_7bcf when node+0x8 flag is set, free every node, zero this+0xB1C..0xB28, release this+0xB2C mutex.
- `0x005804A0` **NetworkSessionListener** — Network listener initialization: vtable+72 init callback, thread resume (0x00585680), UDP bind at this+0x93C to base port this+0x910 and TCP bind at this+0x938 to base port+50, IP-string copy via sub_587DD0, config byte flags this+0x967..0x96B, then on success listen() with 0x7FFFFFFF backlog, ThreadSafeWriteWithMutex(4), vtable+144 post-listen callback, and MutexProtectedFieldWrite; returns 6 on bind failure.
- `0x00584230` **NetworkSessionListener** — Session-protocol message dispatcher: decode a bitmask of pending connection/handshake IDs from the packet entry table a2 (base a2[7]+4*a2[14], mask a2[5]) via IndexToBitmaskConversion (0x00585E80), then route one of 15 message types (connection request, ping/latency, HST/clock, node add/remove, data transfer, clock sync) through this-object vtable slots with mutex-guarded shared fields (this+0x5C4, this+0x618); unhandled masks return 0.
- `0x00585040` **QueueDrainListOwner** — Drain two queues and release the owning mutex: pop a mutex-guarded queue via sub_584CD0 dispatching each value through vtable +0x5C, then drain a second linked list under mutex this+0x5A8 (unlink matching node, free data via SEHGuardedFunctionWithExceptionHandling and FreeWrapper_7bcf, free node), then ReleaseMutex.

## Proposed classes

### NetworkSessionListener

Owning object for server-side network session handling: command dispatch, listener initialization, session-protocol message dispatch, plus the sockets, mutexes, state word, flag bytes, and peer-node list referenced by those three methods. Class grouping is DERIVED from shared this+0x offsets; the packet never proves a single owner type.

Methods: `0x0057BF00`, `0x005804A0`, `0x00584230`

- `this+0x00000000` `void_ptr vtable_base` (read, GUESS)
- `this+0x0000005D` `uint8 server_state_byte` (read, DERIVED)
- `this+0x000005C4` `int32 session_state_word` (read_write, DERIVED)
- `this+0x000005C8` `uint8_array session_state_payload_buffer` (write, DERIVED)
- `this+0x00000618` `handle state_mutex_handle` (read, DERIVED)
- `this+0x0000061C` `uint32 state_mutex_timeout` (read, DERIVED)
- `this+0x00000640` `handle cleanup_mutex_handle` (read, GUESS)
- `this+0x00000644` `uint32 cleanup_mutex_timeout` (read, GUESS)
- `this+0x00000910` `uint16 base_port` (read, DERIVED)
- `this+0x00000938` `SOCKET tcp_socket_handle` (read_write, DERIVED)
- `this+0x0000093C` `SOCKET udp_socket_handle` (read_write, DERIVED)
- `this+0x00000967` `uint8 config_flag_byte_967` (write, GUESS)
- `this+0x00000968` `uint8 config_flag_byte_968` (write, GUESS)
- `this+0x0000096A` `uint8 config_flag_byte_96A` (write, GUESS)
- `this+0x0000096B` `uint8 config_flag_byte_96B` (write, GUESS)
- `this+0x00000BE4` `void_ptr peer_node_list_head` (read, DERIVED)
- `this+0x00000BEC` `handle peer_node_list_mutex` (read, DERIVED)
- `this+0x00000BF0` `uint32 peer_node_list_timeout` (read, DERIVED)
- `*(this+0xBE4)+0x00000000` `void_ptr peer_node_data` (read, DERIVED)
- `*(this+0xBE4)+0x00000008` `uint8 peer_node_active_flag_byte` (write, DERIVED)
- `obj+0x00000000` `void_ptr vtable_base_obj` (read, GUESS)
- `obj+0x00000004` `int32 packet_entry_field_04` (read, GUESS)
- `obj+0x00000014` `int32 packet_entry_count` (read, DERIVED)
- `obj+0x00000048` `method_ptr vtable_init_callback_slot_72` (read, DERIVED)
- `obj+0x00000058` `method_ptr vtable_slot_88` (read, DERIVED)
- `obj+0x00000090` `method_ptr vtable_post_listen_callback_slot_144` (read, DERIVED)

### NetworkConnectionListOwner

Holds several mutex-guarded singly-linked lists with the shared node shape {data@+0, next@+4, flag@+8} and provides their teardown/cleanup. The four methods are grouped because they are all invoked by NetworkCleanup_fbe0 (0x0057FBE0) and share the same list-walk/free pattern; they operate on distinct offset blocks (0xAAC/0xAC8/0xB00/0xB1C) that may belong to one large struct or several objects.

Methods: `0x0057E570`, `0x0057E6E0`, `0x0057E760`, `0x0057E7E0`

- `this+0x00000AAC` `void_ptr list_a_control_block` (read, DERIVED)
- `this+0x00000AB0` `void_ptr list_a_head` (read, GUESS)
- `this+0x00000AB4` `void_ptr list_a_tail` (read, GUESS)
- `this+0x00000AB8` `int32 list_a_count` (read, GUESS)
- `this+0x00000ABC` `handle list_a_mutex_handle` (read, DERIVED)
- `this+0x00000AC0` `uint32 list_a_mutex_timeout` (read, DERIVED)
- `this+0x00000AC8` `void_ptr list_b_head` (read_write, DERIVED)
- `this+0x00000ACC` `void_ptr list_b_tail` (read_write, GUESS)
- `this+0x00000AD0` `void_ptr list_b_cursor` (read_write, GUESS)
- `this+0x00000AD4` `int32 list_b_count` (read_write, GUESS)
- `this+0x00000AD8` `handle list_b_mutex_handle` (read, DERIVED)
- `this+0x00000ADC` `uint32 list_b_mutex_timeout` (read, DERIVED)
- `this+0x00000B00` `void_ptr list_c_head` (read_write, DERIVED)
- `this+0x00000B04` `void_ptr list_c_tail` (read_write, GUESS)
- `this+0x00000B08` `void_ptr list_c_cursor` (read_write, GUESS)
- `this+0x00000B0C` `int32 list_c_field_0B0C` (read_write, GUESS)
- `this+0x00000B10` `handle list_c_mutex_handle` (read, DERIVED)
- `this+0x00000B14` `uint32 list_c_mutex_timeout` (read, DERIVED)
- `this+0x00000B1C` `void_ptr list_d_head` (read_write, DERIVED)
- `this+0x00000B20` `void_ptr list_d_tail` (read_write, GUESS)
- `this+0x00000B24` `void_ptr list_d_cursor` (read_write, GUESS)
- `this+0x00000B28` `int32 list_d_count` (read_write, GUESS)
- `this+0x00000B2C` `handle list_d_mutex_handle` (read, DERIVED)
- `this+0x00000B30` `uint32 list_d_mutex_timeout` (read, DERIVED)
- `*(this+0xAAC)+0x00000000` `void_ptr list_a_block_head` (read, DERIVED)
- `*(this+0xAAC)+0x00000004` `void_ptr list_a_block_tail_or_iter` (read, GUESS)
- `*(this+0xAAC)+0x00000008` `void_ptr list_a_block_cursor` (read, DERIVED)
- `*(*(this+0xAAC)+0x0)+0x00000000` `int32 head_record_field_00` (read_write, GUESS)
- `*(*(this+0xAAC)+0x0)+0x00000004` `int32 head_record_field_04` (read_write, GUESS)
- `*(*(this+0xAAC)+0x0)+0x00000008` `int32 head_record_field_08` (read_write, GUESS)
- `*(*(this+0xAAC)+0x0)+0x0000000C` `int32 head_record_field_0C` (read_write, GUESS)
- `*(*(this+0xAAC)+0x0)+0x00000010` `int32 head_record_field_10` (read_write, GUESS)
- `*(*(this+0xAAC)+0x0)+0x00000014` `int32 head_record_field_14` (read_write, GUESS)
- `*(*(this+0xAAC)+0x0)+0x00000018` `int32 head_record_field_18` (read_write, GUESS)
- `*(*(this+0xAAC)+0x0)+0x0000001C` `int32 head_record_field_1C` (read_write, GUESS)
- `*(*(this+0xAAC)+0x0)+0x00000020` `int32 head_record_field_20` (read_write, GUESS)
- `*(*(this+0xAAC)+0x0)+0x00000024` `int32 head_record_field_24` (read_write, GUESS)
- `*(*(this+0xAAC)+0x0)+0x00000028` `int32 head_record_field_28` (read_write, GUESS)
- `*(*(this+0xAAC)+0x0)+0x0000002C` `int32 head_record_field_2C` (read_write, GUESS)
- `*(*(this+0xAAC)+0x0)+0x00000030` `int32 head_record_field_30` (read_write, GUESS)
- `*(*(this+0xAAC)+0x0)+0x00000034` `int32 head_record_field_34` (read_write, GUESS)
- `*(this+0xAC8)+0x00000000` `void_ptr list_b_node_data` (read, DERIVED)
- `*(this+0xAC8)+0x00000008` `uint8 list_b_node_flag_byte` (read, DERIVED)
- `*(*(this+0xAC8)+0x0)+0x00000000` `method_ptr list_b_node_data_vtable_slot` (read, GUESS)
- `*(*(*(this+0xAC8)+0x0)+0x0)+0x00000000` `method_ptr list_b_node_data_destructor_slot` (read, GUESS)
- `*(this+0xB00)+0x00000000` `void_ptr list_c_node_data` (read, DERIVED)
- `*(this+0xB00)+0x00000008` `uint8 list_c_node_flag_byte` (read, DERIVED)
- `*(*(this+0xB00)+0x4)+0x00000004` `void_ptr list_c_node_next` (read, DERIVED)
- `*(this+0xB1C)+0x00000000` `void_ptr list_d_node_data` (read, DERIVED)
- `*(this+0xB1C)+0x00000008` `uint8 list_d_node_flag_byte` (read, DERIVED)
- `*(*(this+0xB1C)+0x4)+0x00000004` `void_ptr list_d_node_next` (read, DERIVED)

### ComInterfaceHandle

Pointer-to-pointer COM-style handle object: *this holds an interface object pointer, the vtable base is loaded from *obj, and a fixed __thiscall slot (0x58, 0x60, or 0x64) is dispatched on obj. The dispatched method identities are unknown.

Methods: `0x0057A680`, `0x0057A690`, `0x0057A6A0`, `0x0057A730`

- `this+0x00000000` `void_ptr interface_object_ptr` (read, DERIVED)
- `obj+0x00000000` `void_ptr vtable_base` (read, DERIVED)
- `*(obj+0x0)+0x00000058` `method_ptr vtable_slot_58` (read, DERIVED)
- `*(obj+0x0)+0x00000060` `method_ptr vtable_slot_60` (read, DERIVED)
- `*(obj+0x0)+0x00000064` `method_ptr vtable_slot_64` (read, DERIVED)

### CleanupCallbackRegistrar

Set of near-identical thunks that materialize the address of a cleanup/free routine (sub_57A960, sub_57A9A0, sub_57AA80, sub_57AE90) and forward it as an integer argument to BooleanToIntConversion (0x00587B3E), returning its result. Whether the helper dereferences/invokes the address or merely converts a numeric value is not established.

Methods: `0x0057A950`, `0x0057A990`, `0x0057AA70`, `0x0057AE80`


### GuardedStaticInitScope

Compiler-style once-guarded static initialization: registers an SEH frame, runs a one-time guard on a global init counter, and constructs six static objects linked into a parent frame. The constructed object identities are unresolved.

Methods: `0x0057A980`


### SocketHandleLifecycle

Graceful closing of a socket handle stored at *a1: INVALID_SOCKET (-1) sentinel, optional shutdown(SD_SEND) + recv drain, closesocket, and write-back of -1. The owning module/object is unknown.

Methods: `0x0057C8E0`

- `this+0x00000000` `SOCKET socket_handle` (read_write, DERIVED)

### ConfigCommandStringParser

Parses a configuration/command string using a primary byte delimiter and a secondary word delimiter into a 5-byte output record (word at a2+2, four bytes at a2+4..a2+7). The record layout and the consumer are unresolved; no callers appear in the packet.

Methods: `0x0057CA10`


### QueueDrainListOwner

Owning object for a vtable-dispatched queue and a mutex-guarded node list drained together during shutdown: pops values via sub_584CD0 dispatching through vtable slot +0x5C, then unlinks and frees matching nodes (payload freed via SEHGuardedFunctionWithExceptionHandling when the node+0x8 flag is set) under the this+0x5A8 mutex.

Methods: `0x00585040`

- `this+0x00000598` `void_ptr queue_control_block` (read, DERIVED)
- `this+0x0000059C` `void_ptr queue_iter_ptr` (read_write, GUESS)
- `this+0x000005A0` `void_ptr queue_tail_ptr` (read_write, GUESS)
- `this+0x000005A4` `int32 queue_node_count` (read_write, DERIVED)
- `this+0x000005A8` `handle queue_mutex_handle` (read, DERIVED)
- `this+0x000005AC` `uint32 queue_mutex_timeout` (read, DERIVED)
- `*(this+0x598)+0x00000000` `void_ptr queue_block_head` (read, DERIVED)
- `*(this+0x598)+0x00000004` `void_ptr queue_block_iter` (read_write, GUESS)
- `*(this+0x598)+0x00000008` `void_ptr queue_block_tail` (read_write, GUESS)
- `*(this+0x598)+0x0000000C` `int32 queue_block_count` (read_write, DERIVED)
- `obj+0x0000005C` `method_ptr vtable_slot_92` (read, DERIVED)

## Compatibility contracts

- **ComStyleHandleDispatchContract** — A caller passes a pointer-to-pointer handle: *this holds the interface object, *obj holds the vtable base, and a __thiscall method at vtable slot 0x58/0x60/0x64 is invoked on obj with *this as the this pointer, returning the method's integer result. A replacement must reproduce the single-dereference handle layout and these slot conventions.
- **MutexGuardedLinkedListNodeContract** — Mutex-guarded singly-linked lists expose nodes of shape {data@+0, next@+4, flag@+8}; teardown frees the node data via FreeWrapper_7bcf (0x00587BCF) only when the +8 flag byte is set, always frees the node, then zeroes the four list-head dwords (head/tail/cursor/count) and releases the mutex. A replacement list container must preserve this node layout and the data-ownership flag semantics.
- **SocketGracefulCloseContract** — A socket handle stored at *a1 is closed gracefully: if it equals -1 (INVALID_SOCKET) nothing happens; otherwise when the graceful flag is set shutdown(SD_SEND) runs and inbound data is drained with recv(*a1, buf, 256, 0) until it returns 0 or -1, then closesocket(*a1) and the handle is written back as -1. The closesocket result is returned.
- **NetworkCommandPrefixProtocol** — Incoming network commands must carry a prefix whose length is cached once into dword_8D3C14 (from off_5E537C); a string not starting with that prefix is rejected with return 0. The suffix (capped at 79) is split against follow-up prefixes off_5E5384/off_5E5388/off_5E538C selecting status-reply, state-change (lobby-state word 1-5 at this+0x5C4), or direct-connect handling. The reply code is lowered from 4 to 3 when the this+0x5D byte is non-zero. Direct-connect binds base port this+0x910 + offset (TCP +50) with WSAEADDRINUSE retry. Wire semantics are reconstructed only to DERIVED level.

## Unresolved

- The identity and interface contract of the COM-style handle (this pointer-to-pointer) and of the methods at vtable slots 0x58/0x60/0x64 are unknown; the relationship between this and obj is only the single dereference shown in the raw source.
- Whether BooleanToIntConversion (0x00587B3E) dereferences/invokes the passed target address or merely converts a numeric value is not established; the target routines sub_57A960, sub_57A9A0, sub_57AA80, sub_57AE90 are outside this packet's evidence.
- The six static objects constructed by 0x0057A980 (unk_8D4510, unk_8D44B8, unk_8D45A0, dword_8D4478, byte_8D4568, dword_8D4400, dword_8D4440, dword_8D446C) and the one-time guard counter dword_5EA04C are unresolved; helpers sub_59A54D/sub_59A5E9 are unverified.
- The exact wire protocol of dispatchNetworkCommand (0x0057BF00): the byte meaning of a2/a3/a4, the four prefixes, and the 1-5 state values are reconstructed only to DERIVED level and need runtime observation to confirm. Format constants aS_9, aDDDDDD, aSSDDDDDD, aSSD (0x5C721C, 0x5E53F8, 0x5E540C, 0x5E5424) and jump table jpt_57C718 / SEH handler SEH_57BF00 are referenced but not visible as operands of the decompiled body.
- byte_FF00000000005430 and byte_FF00000000005431 sit far outside the image (non-image addresses) with write access; their role is unexplained and may originate from a patched/hooked data reference.
- Whether the handles at this+0xABC (list A) are mutexes or events is not evidenced; only the packet-named WaitForSingleObject/ReleaseMutex usage on both this+0xABC and this+0xBEC is known.
- The object type owning the mutex/socket/state fields is unknown; only the vtable-dispatch pattern at slot this+0x58 is evidenced. Class grouping (NetworkSessionListener, NetworkConnectionListOwner) is DERIVED and may merge distinct objects.
- In 0x0057E570 the meaning of the -1 sentinel at record offset 32 and the ring-buffer reset at offset 54 are inferred; sub_491E40's exact role (node destructor vs other teardown) is unknown.
- The precise wire format of each of the 15 session-protocol message payloads is not recoverable from 0x00584230 alone; SEH scope handler SEH_584230 and constants flt_59E450/dbl_59ECC8 do not appear in the raw decompiled source.
- Node layout beyond {data@+0, next@+4, flag@+8} is unconfirmed; the meaning of the key value used in the 0x00585040 unlink walk and the identity of the vtable +0x5C dispatch target are unknown.
- The 5-byte output record of ParseConfigStringToOutputBuffer (0x0057CA10) has unresolved layout/consumer; the delimiter values behind byte_5C3F6C and word_5BEB48 are unknown; no callers appear in the packet.
- The meaning of error code 6 in 0x005804A0, of the vtable+144 call arguments (2, 1), and of ThreadSafeWriteWithMutex constant 4 is not evidenced; global 0x0059CA8B (SEH_5804A0) role is unknown.
- Sixteen read-only packet-entry fields on obj (a2[0], a2[2], a2[13], a2[16], a2[22], a2[23], a2[30], a2[31], a2[33], a2[35], a2[36], a2[37], a2[38], a2[44], a2[48], a2[49]) are not referenced by the visible raw source and are consumed indirectly inside dispatch helpers.
