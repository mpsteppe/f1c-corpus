# RuntimeObjectLayer

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

24 functions form a set of generic runtime objects with a strong network flavor. Two functions (0x0057ADF0, 0x0057AE70) are compiler-style guarded static-initialization wrappers over distinct SEH tables (unk_8D3BF8, unk_8D3C18) sharing the one-time guard dword_5EA04C. A 4096-byte ring buffer (head this+0x1000, tail/available this+0x1002) is served by three methods (push 0x0057B550, pop 0x0057B5C0, peek 0x0057B630) all called from sub_57CB50. A buffer manager owning two singly-linked lists is torn down by 0x0057B100, freeing each node's data pointer when the node flag byte is set. Socket address structures are initialized (0x0057B8C0), queried via getsockname (0x0057B950), and resolved via getpeername/getsockname (0x0057B9A0). The largest object is a network socket object constructed at 0x0057BA10, installing two vtables (off_5B8A68 at +0, off_5B8B3C at +0x940) and five mutex slot blocks, recorded as the global serialization header dword_8D3E24. A mutex-guarded connection manager (this+0xAAC list base, +0xAB4 cursor, +0xABC mutex, +0xAC0 timeout, +0xAA4/+0xAA8 timers, +0xBEC/+0xBF0 accept mutex) is exercised by lookup (0x0057DFF0), per-frame timeout maintenance (0x0057E0A0), periodic update dispatch (0x0057E280) and accept/drain (0x00580190). Socket helpers include TCP option setup with WSAAsyncSelect (0x0057C860), WSA-error-to-string mapping (0x0057D400), packet unpacking with size check (0x0057D660) and connect-from-IP (0x0057F0C8). Owner trust is LOW overall: only 0x00580190 carries a DERIVED NetworkManager owner in the packet; every other function is UnknownObject/UNKNOWN.

## Function roles

- `0x0057ADF0` **StaticObjectInitGuard** — Compiler-style guarded static-object initialization wrapper; registers SEH frame against unk_8D3BF8, one-time guard on dword_5EA04C, constructs seven static objects
- `0x0057AE70` **StaticObjectInitGuard** — Compiler-style guarded static-object initialization wrapper (twin of 0x0057ADF0); registers SEH frame against unk_8D3C18, one-time guard on dword_5EA04C, constructs seven static objects
- `0x0057AEC0` **VTableInitializedObject** — Constructor-style initializer: stores vtable off_5B8A1C at this+0x0 and zeroes this+0x4..0x24; returns this
- `0x0057B100` **LinkedListBufferManager** — Destructor of a buffer manager owning two singly-linked node lists (heads this+0x8 and this+0x18); clears flag at +0x4, frees both lists via FreeWrapper_7bcf, zeroes bookkeeping
- `0x0057B2E0` **NetworkPacketBuffer** — Trivial getter returning the dword at this+0x24; used by NetworkPacketSendWithQueryMatching and sub_57DE30
- `0x0057B550` **RingBuffer** — Ring-buffer push: copies a3 bytes into the 4096-byte buffer at this, wrap at mod 4096, rejects runs where tail+a3 > 4096, increments tail at +0x1002
- `0x0057B5C0` **RingBuffer** — Ring-buffer pop (consuming read): copies a3 bytes advancing head at +0x1000 modulo 4096 and decrementing available count at +0x1002
- `0x0057B630` **RingBuffer** — Ring-buffer peek (non-consuming read): copies a3 bytes wrapping a local position modulo 4096; head and available count untouched
- `0x0057B6A0` **NetworkPacketBuffer** — Pointer-accessor returning this advanced by a fixed 16-byte stride; used to walk fixed-size 16-byte records by network accept paths
- `0x0057B6B0` **NetworkPacketBuffer** — Offset-accessor returning a pointer 32 bytes past the object base (this + 32); consumed by network packet send/accept callers
- `0x0057B8C0` **SocketAddressPair** — Initializes a two-entry socket-address pair (AF_INET, htonl(0)/htons(0) placeholders), then delegates remaining setup to SockAddrPairInit
- `0x0057B950` **SocketAddressPair** — Queries a socket's local address via getsockname, storing caller metadata (namelen, a3, a4, a5) into the first 16 bytes of the caller buffer; true only when getsockname returns 0
- `0x0057B9A0` **SocketAddressPair** — Resolves both ends of a connected socket: getpeername into name[0], getsockname into name[1]; true only when both calls succeed
- `0x0057B9F0` **NetworkLayerUtility** — Copies four consecutive dwords (this+0x0..0xC) to destination a2 and returns a2; raw 16-byte struct copy heavily used by the network layer
- `0x0057BA10` **NetworkManager** — Network socket object constructor: validates/copies a 0x30-byte config block, installs vtables (off_5B8B3C at +0x940, off_5B8A68 at +0x0), zero-inits five mutex slot blocks plus sub-objects, records this as dword_8D3E24 serialization header, hands off to sub_57E480
- `0x0057BC80` **AudioStreamState** — Resets audio stream state: zeroes the WORD at this+0x12C and the DWORD at this+0x130, then chains to the SmallStructFieldInit helper
- `0x0057C860` **NetworkLayerUtility** — Socket option setup: branches on optval to apply keepalive (setsockopt 6/1 and 0xFFFF/8) or broadcast (setsockopt 0xFFFF/32), then registers async events with WSAAsyncSelect against dword_8D3E28; returns 1
- `0x0057D400` **NetworkLayerUtility** — WSA error-to-string mapping: -1 sentinel resolves the real code via WSAGetLastError, then a switch through jpt_57D423 returns the matching message string (default generic string)
- `0x0057D660` **NetworkLayerUtility** — Unpacks a structured packet from buffer a1: guards declared payload size against the bitfield-derived byte count at a2+36, qmemcpy payload to a2+20 on match, copies trailing data block sized by a1[1] via MemcpyLikeWithRealloc; always returns 1
- `0x0057DFF0` **NetworkManager** — Mutex-guarded lookup over the connection list anchored at this+0xAAC: waits on mutex this+0xABC (timeout +0xAC0), matches node key pairs (+2/+4 and +0x12/+0x14) against HIWORD(a2) and a3, dispatches match to sub_57DE30
- `0x0057E0A0` **NetworkManager** — Per-frame connection maintenance: decrements timer this+0xAA4 by frame delta, on expiry resets to 0.05f and walks the mutex-guarded connection list dropping nodes whose drop flag is set or idle time exceeds the +0xE8 threshold; formats/dispatches drop messages via sub_57DE30
- `0x0057E280` **NetworkManager** — Timer-driven periodic update dispatch: decrements timer this+0xAA8, on expiry resets to 0.125f and iterates managed objects through the vtable at this+0x0 (count via vtable+164, fetch via +172), applying the sub_587220(v16)==2 filter and processing via sub_585870; drains callbacks via MutexCallbackDispatch under mutex this+0xAD8
- `0x0057F0C8` **NetworkLayerUtility** — Builds a sockaddr_in from an IP string and the owning object's port (a2[1160] word), parses with inet_addr, on invalid IP dispatches the a2 vtable+92 error handler, else builds a connection packet via NetworkPacketConstructor(*(a1+72), a3) and issues it under mutex via ThreadSafeCallWithMutex
- `0x00580190` **NetworkManager** — AcceptConnections (NetworkManager): polls the listen socket this+0x938 with select, accepts one connection into the mutex-guarded list (mutex this+0xBEC), applies TCP_NODELAY via sub_57DC10, then drains the pending-connection queue at this+0xAAC; returns an activity flag

## Proposed classes

### StaticObjectInitGuard

Compiler-generated one-time guarded static-object initialization scaffolding; each instance registers its own SEH table, guards the shared init counter dword_5EA04C and constructs seven opaque static objects into parent frame slots.

Methods: `0x0057ADF0`, `0x0057AE70`


### VTableInitializedObject

Small object whose constructor installs a vtable at +0x0 and zero-initializes a 0x24-byte state region. Object identity is unknown; the skeleton-fill label DynamicsSolverObj_VTable for off_5B8A1C is DERIVED prose, not packet evidence.

Methods: `0x0057AEC0`

- `this+0x00000000` `pointer vtable_ptr` (read_write, DERIVED)
- `this+0x00000004` `byte state_byte_0x4` (read_write, GUESS)
- `this+0x00000008` `dword state_dword_0x8` (read_write, GUESS)
- `this+0x0000000C` `dword state_dword_0xC` (read_write, GUESS)
- `this+0x00000010` `dword state_dword_0x10` (read_write, GUESS)
- `this+0x00000014` `dword state_dword_0x14` (read_write, GUESS)
- `this+0x00000018` `dword state_dword_0x18` (read_write, GUESS)
- `this+0x0000001C` `dword state_dword_0x1C` (read_write, GUESS)
- `this+0x00000020` `dword state_dword_0x20` (read_write, GUESS)
- `this+0x00000024` `dword state_dword_0x24` (read_write, GUESS)

### LinkedListBufferManager

Buffer manager owning two singly-linked lists of nodes (head at this+0x8 and this+0x18). Nodes carry a data pointer (+0x0), next pointer (+0x4) and flag byte (+0x8); the destructor frees the data when the flag is set.

Methods: `0x0057B100`

- `this+0x00000004` `byte flag_byte` (read_write, DERIVED)
- `this+0x00000008` `pointer list1_head` (read_write, DERIVED)
- `this+0x0000000C` `pointer list1_tail` (read_write, DERIVED)
- `this+0x00000010` `pointer list1_secondary_tail` (read_write, DERIVED)
- `this+0x00000014` `dword list1_counter` (read_write, DERIVED)
- `this+0x00000018` `pointer list2_head` (read_write, DERIVED)
- `this+0x0000001C` `pointer list2_tail` (read_write, DERIVED)
- `this+0x00000020` `pointer list2_secondary_tail` (read_write, DERIVED)
- `this+0x00000024` `dword list2_counter` (read_write, DERIVED)
- `*(this+0x8)+0x00000000` `pointer list1_node_data` (read, DERIVED)
- `*(this+0x8)+0x00000008` `byte list1_node_flag` (read, DERIVED)
- `*(*(this+0x8)+0x4)+0x00000004` `pointer list1_node_next_of_next` (read, GUESS)
- `*(this+0x18)+0x00000000` `pointer list2_node_data` (read, DERIVED)
- `*(this+0x18)+0x00000008` `byte list2_node_flag` (read, DERIVED)
- `*(*(this+0x18)+0x4)+0x00000004` `pointer list2_node_next_of_next` (read, GUESS)

### RingBuffer

4096-byte ring buffer starting at the object base. Head at +0x1000, tail/available-byte count at +0x1002. Push rejects runs that overflow, pop consumes (advances head), peek reads without consuming.

Methods: `0x0057B550`, `0x0057B5C0`, `0x0057B630`

- `this+0x00001000` `word (signed 16-bit) head_index` (read_write, DERIVED)
- `this+0x00001002` `word (unsigned 16-bit) tail_or_available_count` (read_write, DERIVED)

### NetworkPacketBuffer

Network packet/record object exposing offset accessors: reads the dword at +0x24, returns this+16 to walk 16-byte records and this+32 to reach the data region; consumed by network packet send/accept callers.

Methods: `0x0057B2E0`, `0x0057B6A0`, `0x0057B6B0`

- `this+0x00000024` `dword field_0x24` (read, DERIVED)

### SocketAddressPair

Two-entry socket address structure with AF_INET family words, port and IP at +0x0..0x14. Initialized with zero placeholders (SocketAddressInitialization), queried with metadata prefix via getsockname (NetworkSocketAddressQuery), resolved via getpeername/getsockname (SocketAddressResolution).

Methods: `0x0057B8C0`, `0x0057B950`, `0x0057B9A0`

- `this+0x00000000` `word (family) reinterpreted as dword (namelen) family1_or_namelen` (write, GUESS)
- `this+0x00000002` `word (network byte order) port1` (read_write, DERIVED)
- `this+0x00000004` `dword (network byte order) ip1` (read_write, DERIVED)
- `this+0x00000008` `dword metadata_field_0x8` (read_write, GUESS)
- `this+0x0000000C` `dword metadata_field_0xC` (read_write, GUESS)
- `this+0x00000010` `word family2` (write, DERIVED)
- `this+0x00000012` `word (network byte order) port2` (read_write, DERIVED)
- `this+0x00000014` `dword (network byte order) ip2` (read_write, DERIVED)

### NetworkManager

Mutex-guarded network connection manager. Owns the listen socket (+0x938), pending socket (+0x93C), two vtables (+0x0 and +0x940), maintenance/periodic timers (+0xAA4/+0xAA8), the connection-list base (+0xAAC), traversal cursor (+0xAB4), list mutex (+0xABC) and timeout (+0xAC0), a second managed-object mutex (+0xAD8) with timeout (+0xADC), and an accept-section mutex (+0xBEC) with timeout (+0xBF0). Accepts, looks up, times out and periodically updates connections.

Methods: `0x00580190`, `0x0057DFF0`, `0x0057E0A0`, `0x0057E280`, `0x0057BA10`

- `this+0x00000000` `pointer (off_5B8A68) primary_vtable` (read_write, DERIVED)
- `this+0x000000E8` `float connection_idle_threshold` (read, DERIVED)
- `this+0x00000774` `dword config_field_a2_3` (write, GUESS)
- `this+0x00000938` `SOCKET listen_socket` (read_write, DERIVED)
- `this+0x0000093C` `SOCKET pending_socket` (read, DERIVED)
- `this+0x00000940` `pointer (off_5B8B3C) secondary_vtable` (read_write, GUESS)
- `this+0x00000AA4` `float maintenance_timer` (read_write, DERIVED)
- `this+0x00000AA8` `float periodic_timer` (read_write, DERIVED)
- `this+0x00000AAC` `pointer (linked-list struct) connection_list_base` (read_write, DERIVED)
- `this+0x00000AB4` `pointer traversal_cursor` (read_write, DERIVED)
- `this+0x00000ABC` `HANDLE list_mutex_handle` (read_write, DERIVED)
- `this+0x00000AC0` `dword list_wait_timeout` (read, DERIVED)
- `this+0x00000AD8` `HANDLE managed_object_mutex_handle` (read_write, DERIVED)
- `this+0x00000ADC` `dword managed_object_wait_timeout` (read, DERIVED)
- `this+0x00000BEC` `HANDLE accept_section_mutex_handle` (read_write, DERIVED)
- `this+0x00000BF0` `dword accept_section_wait_timeout` (read, DERIVED)
- `*(this+0xAAC)+0x00000000` `pointer connection_node_head` (read_write, DERIVED)
- `*(*(this+0xAAC)+0x0)+0x00000028` `byte connection_drop_flag` (read, DERIVED)
- `*(*(this+0xAAC)+0x0)+0x0000002C` `float connection_last_activity` (read, DERIVED)
- `*(*(this+0xAAC)+0x0)+0x00000030` `float connection_last_dispatch` (read_write, DERIVED)
- `*(this+0xAB4)+0x00000004` `pointer cursor_next` (read_write, DERIVED)
- `*(*(this+0xAB4)+0x4)+0x00000000` `pointer cursor_entry_data` (read, DERIVED)
- `*(*(*(this+0xAB4)+0x4)+0x0)+0x00000002` `word entry_key_word_0x2` (read, GUESS)
- `*(*(*(this+0xAB4)+0x4)+0x0)+0x00000004` `dword entry_key_dword_0x4` (read, GUESS)
- `*(*(*(this+0xAB4)+0x4)+0x0)+0x00000012` `word entry_key_word_0x12` (read, GUESS)
- `*(*(*(this+0xAB4)+0x4)+0x0)+0x00000014` `dword entry_key_dword_0x14` (read, GUESS)

### NetworkLayerUtility

Socket-layer helper routines with no single evidenced owning object: 16-byte struct copy, TCP option/WSAAsyncSelect setup, WSA error-code-to-string mapping, packet unpacking with size check, and connect-from-IP-sockaddr building.

Methods: `0x0057B9F0`, `0x0057C860`, `0x0057D400`, `0x0057D660`, `0x0057F0C8`

- `this+0x00000000` `dword copy_source_dword_0x0` (read, DERIVED)
- `this+0x00000004` `dword copy_source_dword_0x4` (read, DERIVED)
- `this+0x00000008` `dword copy_source_dword_0x8` (read, DERIVED)
- `this+0x0000000C` `dword copy_source_dword_0xC` (read, DERIVED)
- `this+0x00000048` `dword context_field_0x48` (read, GUESS)

### AudioStreamState

Audio stream state sub-object whose reset routine zeroes a 16-bit state word (+0x12C) and a 32-bit position/count dword (+0x130) before chaining to a small struct-field init helper. Owning audio subsystem not evidenced in this packet.

Methods: `0x0057BC80`

- `this+0x0000012C` `word stream_state_word` (read_write, DERIVED)
- `this+0x00000130` `dword stream_position_or_count` (read_write, DERIVED)

## Compatibility contracts

- **RingBufferBoundsContract** — A replacement ring buffer must reject a push whose tail + byte count exceeds 4096 (return 0) and must reject a pop/peek whose requested byte count exceeds the available-byte count at this+0x1002 (return 0); success returns 1.
- **MutexGuardedListAccessContract** — Traversal of the connection list at this+0xAAC must occur while holding the mutex at this+0xABC (waiting at most the timeout at this+0xAC0) and must release the mutex before returning, including on the no-match path.
- **WSAErrorMappingContract** — WSA error code to message-string mapping: a -1 (SOCKET_ERROR) input is resolved through WSAGetLastError, the switch jump table maps known codes to their strings, and unknown codes fall back to the generic WSAGetLastError string.
- **SocketObjectConstructorLifecycleContract** — The network socket object constructor must install two vtables (off_5B8A68 at +0x0, off_5B8B3C at +0x940), zero-initialize five mutex slot blocks plus sub-objects, record the instance as the dword_8D3E24 serialization header, and pass the finished object to sub_57E480.

## Unresolved

- Identity and purpose of the seven static objects constructed by each GuardedStaticObjectInit wrapper (unk_8D4510, unk_8D44B8, unk_8D45A0, dword_8D4478, byte_8D4568, dword_8D4400, dword_8D4440, dword_8D446C) and the shared one-time guard counter dword_5EA04C; the object layouts and vtable targets are opaque at this scope.
- Helpers sub_59A54D and sub_59A5E9 bracket the guarded static-init region; their exact roles (SEH enter/leave with refcount) are unverified.
- Whether 0x0057BA10 (SocketObjectConstructor) really constructs the same object as the NetworkManager methods is inferred only from overlapping field offsets (0x938/0x93C/0xAAC/0xABC/0xAC0/0xAA4/0xAA8); the packet does not prove common ownership.
- The 0x30-byte configuration block copied by the constructor (field a2[3] into this+0x774) and the purpose of the five mutex slot blocks / four sub-object initializers (sub_5824F0, sub_582720, sub_5828B0, sub_581D40, sub_581FD0) are not resolvable from this packet.
- SocketAddressPair field 0x0 is read as a family WORD by SocketAddressInitialization but as a namelen DWORD by NetworkSocketAddressQuery; the same base+offset carries two interpretations across the two methods.
- The ring buffer's consumer, the update site of the head at this+0x1000, and the owner of the 4096-byte buffer are outside this packet.
- The meaning of the two linked lists (heads this+0x8 and this+0x18) in LinkedListBufferManager and of the per-node flag byte at node+8 is caller-defined and unknown here.
- The owner of NetworkPacketBuffer (GetField0x24, PointerAdvance, GetDataOffset) is not evidenced; the three methods are grouped only by shared network send/accept callers.
- The success-path return value v20 of 0x0057F0C8 is a decompiler frame-slot artifact; the vtable+92 error method and the a1 context layout are not documented in this packet.
- The numeric setsockopt level/option pairs (6/1, 0xFFFF/8, 0xFFFF/32) and the WSAAsyncSelect event mask 63 / message 0x1A0A are used verbatim; their Winsock constant meanings are not confirmed by packet evidence.
- byte_57D56C is read by 0x0057D400 but does not appear in the decompiled control flow; its purpose is unknown.
- SEH_57BA10, SEH_57E0A0, SEH_57E280 and SEH_580190 are registered exception-handler globals; their frame roles are not expressed as operations in the raw bodies.
- The float globals flt_59E440, flt_59E450, flt_59E7E8 are data-referenced by 0x0057E0A0 but do not appear as named loads in the raw source.
- The socket-address structure reached through this+0xAB8 and its field at +0x2C are referenced in the fact store but no corresponding load is visible in the raw body of 0x0057E0A0.
- The vtable-offset 172 fetch contract and the sub_587220(v16) == 2 filter in 0x0057E280 are DERIVED from call sites; the semantics of the 4 comparison from MutexProtectedPointerReadRelease are unresolved.
- Dispatch semantics of sub_57CB50 and sub_57DC10 (the primary callers of the ring buffer, address query and packet unpacking) are not labelled in packet evidence.
