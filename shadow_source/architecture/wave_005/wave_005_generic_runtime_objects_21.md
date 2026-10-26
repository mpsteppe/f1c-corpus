# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

This packet groups generic runtime objects around seven defensible clusters: (1) a named-string linked-list registry whose two append methods share a 32-byte node type (next link at +0x1C) and the identical callee trio SmallStructInitWithParentCall / StringCopyFieldInit / OperatorNewNhMallocWrapper; (2) a config-line tokenizer and a 36-byte small-struct initializer; (3) an audio-config selection container holding a node list (head this+0x120, count this+0x11C) with a field getter and an indexed accessor; (4) two unrelated doubly-linked list owners (head this+0x1518 with node prev/next at +0x1C/+0x20, and a node-splice owner whose local head is this+0x2C and whose node links sit at +48/+52 with an active flag at +36); (5) a D3D surface-format/D3D binding cluster: a pure format-codec pair, a device-surface binding context around the wrapper at this+0x1100, and a DirectX vertex-buffer state object; (6) an audio-mix lookup-table initializer with four byte-array globals; and (7) the network session object (allocated 1464 bytes, config strings at offsets 12/44/76, socket at +136, state at +144) together with its query, poll, UDP-broadcast, delegate, echo and audio-stream-poll methods. A flagged contradiction: CreateNetworkSessionObject places a 0x18-byte sub-struct pointer at offset 4 while NetworkAudioStreamPoll reads offset 4 as a reference total, and the 28-byte-stride array at offset 8 matches in both, so the poller's base may differ from the session object. All owner classes are UNKNOWN at the evidence level; every class here is a DERIVED/GUESS grouping of packet evidence.

## Function roles

- `0x005594B0` **NamedStringLinkedListRegistry** — Appends a uniquely-named 32-byte actor node to the singly-linked actor list rooted at this+0x0; a duplicate name is rejected with the 'Actor %s already exists' error (return -1); otherwise allocates, zero-inits, links (head or tail) and fills the node, returning 0.
- `0x00559570` **NamedStringLinkedListRegistry** — Appends a uniquely-named 32-byte response node to the singly-linked response list rooted at this+0x4; a duplicate is rejected via BinaryTreeSearch with the 'Response %s already exists' error (return -1); otherwise allocates, zero-inits, links and fills the node, returning 0.
- `0x00559AD0` **ConfigLineTokenizerState** — Parses one key=value configuration line from the buffer at this+0xC: strips a trailing CR, trims leading whitespace, locates the '=' separator (stored at this+0x30C), lowercases the key side; returns 0 for a parsed line, 1 for a blank/comment line, 2 for a format error.
- `0x0055BAF0` **SmallStruct_36Byte** — Zero-initializes a 36-byte structure (fields 0x0, 0x8..0x20) and sets this+0x4 to the -1 sentinel; returns the this pointer. Called by sub_55BC00.
- `0x0055BD20` **AudioConfigSelectionContainer** — Walks the audio-config node list (head this+0x120) matching node dwords [2]/[3]/[5] (and [6] when a6 non-zero) against a2/a3/a4/a6, records the match index at this+0x118, writes four audio/screen globals, calls audio setup sub_53E070 then a stub; returns 0 or -1.
- `0x0055BDC0` **AudioConfigSelectionContainer** — Trivial __thiscall getter returning this[70] (this+0x118) with no side effects; consumed by sub_53E070.
- `0x0055BDE0` **AudioConfigSelectionContainer** — Linked-list node accessor: returns 0 when the requested index a2 is at least the count at this+0x11C; otherwise walks from head this+0x120 via the node next pointer at +0x20 and returns the node at index a2 (or the last reachable node).
- `0x0055C2A0` **DoublyLinkedNodeListOwner** — Appends a node to the tail of a doubly-linked list headed at this+0x1518 (node prev at +0x1C, next at +0x20); sets the head when the list is empty; returns the appended node in all paths.
- `0x0055C3C0` **VirtualFlagSelectorDispatcher** — Flag-selected virtual fetch: reads the flag word at a2[6], picks the target object (bit0 -> a2[2], bit1 -> a2[3], else a2), invokes the vtable slot at offset 32 into an 8-dword out buffer, stores the result at this+0x0, dispatches sub_55C450 with a mapped argument (21 when out[0]==22, else out[0]); returns a2.
- `0x0055C450` **SurfaceFormatCodec** — Pure lookup table for texture/surface format codes: maps an input format key to a (bit depth/block size, aux) output pair; small codes 20-25 and 40-41 map to explicit pairs, the five large FourCC constants map to (1, 9..13), anything else to (0, 0).
- `0x0055C650` **SurfaceFormatCodec** — Maps a (bit depth, format identifier) pair to an output FourCC-style code; explicit bit depths 32/24/16/8 write 21/20/23|25/41, and the zero-depth branch additionally covers formats 9..13 with the large compression codes.
- `0x0055CA90` **D3DDeviceSurfaceBindingContext** — Sets up a D3D texture/render-state binding through the device wrapper at this+0x1100: default vs descriptor path (flag 0x40000 at a2[6]), file/stream vs surface-lock source, device vtable slot 124 load/bind (stream variant flag 0x200000) and slot 160 transform when a3 is non-null; stores the load result at this+0x0.
- `0x0055CDF0` **D3DDeviceSurfaceBindingContext** — Three unconditional vtable queries against the sub-object at this+0x1100: two through vtable entry 0x98 with enum selectors 2 and 3 (outputs &this[1302], &this[1318]), one through vtable entry 0xA4 (output &this[1334]); each result is stored to this[0x0] and the final result returned.
- `0x0055D2A0` **SceneStateConfigurator** — Unconditional scene/sound property initializer: ORs parameter a3 into the flags dword at this+0x0, copies the NUL-terminated string into the buffer at this+0x58, stores SceneStateSetup(dword_8B78A0, a3) into this+0x4, returns 0.
- `0x0055D530` **DirectXVertexBufferState** — Unconditional state-field setter: stores a2 into the state field this+0x50, pushes it to the DirectX vertex-buffer path via DirectXVertexBufferTextureCoordinateSetup(dword_8B78A0, this, this[1], 7), ORs the dirty flag 0x800 into dword_8B8F28 + 236, returns the UI context pointer.
- `0x00560F40` **GlobalListReinsertNodeOwner** — Splices a node out of the local doubly-linked list (local head this+0x2C; node prev +48, next +52) and, when the global context dword_8B8F28 is non-null, re-inserts it at the tail of the global list at dword_8B8F28+348; resets the node links and clears the node active flag bit 2 (a2[9] &= ~4u); returns the prior global-list tail or 0.
- `0x00561B2A` **AudioMixLookupTables** — Builds four fixed audio-mixing/pixel lookup tables: byte_5DECCC (256x32 (i*j)>>8), byte_5E0CCC (256x64 (k*m)>>8), byte_5DD8CC (32x32 sum-clip to 31), byte_5DDCCC (64x64 sum-clip to 63); a __usercall prologue also folds register bytes and calls a function pointer read at a1+0x53.
- `0x00561F60` **NetworkSessionObject** — Fastcall wrapper that defaults a null object pointer to the global off_5E4DFC and delegates to sub_562AC0 with the resolved pointer and constant 2, returning its result.
- `0x00562950` **NetworkEchoSender** — Guards the input length against the 0x546 bound, formats '\echo\%s' into a stack buffer via StringFormatWithBufferOverflowCheck, and forwards the message to sub_562710 along with the socket arguments; over-long input returns null without sending.
- `0x00562B50` **NetworkSessionObject** — Allocates and initializes the 1464-byte network session object: zeroes offset 0, builds a 0x18-byte sub-struct at offset 4 (Malloc0x18ByteStructWithInnerBuffer), a typed dynamic array at offset 148 (AllocateIntArrayViaFactory), a zeroed 28-byte-stride element array at offset 8, copies three config strings to offsets 12/44/76, stores scalars at 108/120/124/128/152, then calls NetworkStartup.
- `0x00562E30` **NetworkSessionObject** — TCP session handshake and server-list query: recv up to 255 bytes on the socket at a1+136, validate the response via sub_587C20 against the 'secure' string, XOR-decode 6 bytes against the key at a1+44, send a gamename/gamever/validate/enctype/queryid handshake line, then send a \list\...\final\ query with a state-selected list argument (state 6 -> aGroups, 7 -> aInfo2, else off_5E4FD4) plus an optional where clause; completion via AudioValueSetterCall(a1, 1); returns 0 on success, 3 on network failure, 5 on validation failure.
- `0x00563000` **NetworkSessionObject** — Blocking poll loop: while the flag at this+0x0 is non-zero, call sub_563410(this) to process the object, then assign SleepWrapper(0xA)'s return as the loop update; returns the last SleepWrapper result.
- `0x005630D0` **NetworkSessionObject** — Broadcasts an 8-byte status payload as a UDP datagram over a contiguous port range: converts each port with htons, fills a sockaddr with the broadcast address 255.255.255.255, calls sendto on the socket at a1+136; after the loop notifies AudioValueSetterCall(a1, 2) and records GetTickCount at a1+140; returns 0.
- `0x005633D0` **NetworkSessionObject** — Allocates and initializes a struct via StructAllocInitWithSwitchBasedType (0x005642F0) with the switch/type selector read from this[37] (this+0x94), then pushes an entry to the audio stack via AudioStackPushWithOverflowRealloc (0x005648D0); returns the allocated struct.
- `0x00563AB0` **NetworkStreamSocketSet** — Network audio stream receiver/poller: builds an fd_set from active entries of the UDP socket array (28-byte stride at this+0x8, count this+0x6C), polls with a zero-timeout select, recvfroms datagrams from verified peers, feeds them into the audio mixer, fires the completion callback at this+0x78 (with this+0x7C and a percentage from this+0x70) on the completion marker, deactivates sockets idle over 3000 ms, then either tears the array down (shutdown flag this+0x74, or reference total this+0x4 reached with no active sockets) or activates new sources from the interpolation pool; returns 0.

## Proposed classes

### NamedStringLinkedListRegistry

Owns two named-string singly-linked lists (a 32-byte node type with next link at +0x1C) and appends uniquely-named actor/response nodes, rejecting duplicates with formatted error strings.

Methods: `0x005594B0`, `0x00559570`

- `this+0x00000000` `pointer (32-byte node) actorListHead` (read_write, GUESS)
- `this+0x00000004` `pointer (32-byte node) responseListHead` (read_write, GUESS)
- `this+0x00000020` `pointer (container) responseListContainer` (read, GUESS)
- `obj+0x0000001C` `pointer (32-byte node) nodeNextLink` (read_write, GUESS)
- `*(*(obj+0x1C)+0x1C)+0x0000001C` `pointer tailNextLink` (write, GUESS)
- `*(*(this+0x20)+0x1C)+0x0000001C` `pointer responseTailNextLink` (write, GUESS)

### ConfigLineTokenizerState

Holds the line buffer and '=' separator pointer of a key=value configuration line parser.

Methods: `0x00559AD0`

- `this+0x0000000C` `char buffer lineBuffer` (read_write, DERIVED)
- `this+0x0000030C` `pointer (char*) equalsSeparatorPointer` (write, DERIVED)

### SmallStruct_36Byte

A 36-byte value object whose constructor zeroes fields and sets the -1 sentinel at this+0x4.

Methods: `0x0055BAF0`

- `this+0x00000000` `dword zeroedDword0` (write, DERIVED)
- `this+0x00000004` `dword sentinelMinusOne` (write, DERIVED)
- `this+0x00000008` `dword zeroedDword8` (write, DERIVED)
- `this+0x0000000C` `dword zeroedDwordC` (write, DERIVED)
- `this+0x00000010` `dword zeroedDword10` (write, DERIVED)
- `this+0x00000014` `dword zeroedDword14` (write, DERIVED)
- `this+0x00000018` `dword zeroedDword18` (write, DERIVED)
- `this+0x0000001C` `dword zeroedDword1C` (write, DERIVED)
- `this+0x00000020` `dword zeroedDword20` (write, DERIVED)

### AudioConfigSelectionContainer

Holds a linked list of audio-config nodes (head this+0x120, count this+0x11C) with a matched-node index, and offers an indexed node accessor; a selected configuration is applied through audio globals.

Methods: `0x0055BD20`, `0x0055BDC0`, `0x0055BDE0`

- `this+0x00000118` `dword matchedNodeIndex` (read_write, GUESS)
- `this+0x0000011C` `dword nodeCount` (read, GUESS)
- `this+0x00000120` `pointer (node) listHead` (read, GUESS)
- `this+0x00000148` `dword nodeMatchField2` (read, GUESS)
- `this+0x0000014C` `dword nodeMatchField3` (read, GUESS)
- `this+0x00000154` `dword nodeMatchField5` (read, GUESS)
- `this+0x00000158` `dword nodeMatchField6` (read, GUESS)
- `this+0x00000160` `pointer (node) nodeNextPointer` (read, GUESS)
- `*(this+0x140)+0x00000020` `pointer nodeNextLink` (read, GUESS)

### DoublyLinkedNodeListOwner

Owns a doubly-linked node list headed at this+0x1518 (node prev at +0x1C, next at +0x20) and appends caller-supplied nodes at the tail.

Methods: `0x0055C2A0`

- `this+0x00001518` `pointer (node) doublyLinkedListHead` (read_write, DERIVED)
- `*(*(this+0x1538)+0x20)+0x00000020` `pointer nodeNextLink` (read_write, GUESS)
- `this+0x00001538` `pointer presumedNodeContainer` (read, GUESS)

### VirtualFlagSelectorDispatcher

Selects a target object by flag bits on a parameter object and dispatches through a vtable slot and the format-parameter lookup.

Methods: `0x0055C3C0`


### SurfaceFormatCodec

Pure lookup functions mapping surface/texture format keys and (bit depth, format identifier) pairs to bit-depth/aux and FourCC-style output codes.

Methods: `0x0055C450`, `0x0055C650`

- `this+0x00000000` `dword (out-parameter) formatCodeOutput` (write, GUESS)

### D3DDeviceSurfaceBindingContext

Binds D3D surfaces/textures through a device wrapper held at this+0x1100, using default or descriptor-driven paths, vtable load/bind/transform slots, and stores the render result at this+0x0.

Methods: `0x0055CA90`, `0x0055CDF0`

- `this+0x00000000` `dword resultSlot` (read_write, DERIVED)
- `this+0x00001100` `pointer (device object) deviceWrapper` (read, DERIVED)
- `this+0x00001528` `pointer defaultTextureParamA` (read, GUESS)
- `this+0x0000152C` `pointer defaultTextureParamB` (read, GUESS)
- `this+0x00001534` `dword textureParamA` (read, GUESS)
- `this+0x00001538` `dword textureParamB` (read, GUESS)
- `*(this+0x1100)+0x0000007C` `vtable entry (load/bind) deviceMethodLoadBindSlot124` (unknown, GUESS)
- `*(this+0x1100)+0x00000098` `vtable entry deviceMethodQuerySlot152` (unknown, GUESS)
- `*(this+0x1100)+0x000000A0` `vtable entry (transform) deviceMethodTransformSlot160` (unknown, GUESS)
- `*(this+0x1100)+0x000000A4` `vtable entry deviceMethodQuerySlot164` (unknown, GUESS)

### SceneStateConfigurator

Initializes a scene/sound property object by OR-ing flag bits into this+0x0, copying a property string into this+0x58, and routing the flag bits through the scene-state setup.

Methods: `0x0055D2A0`

- `this+0x00000000` `dword (bit flags) flags` (read_write, DERIVED)
- `this+0x00000004` `dword sceneStateSetupResult` (write, GUESS)

### DirectXVertexBufferState

Holds DirectX vertex-buffer state (handle at this+0x4, state value at this+0x50) and pushes state changes into the vertex-buffer setup path while marking the global UI context dirty.

Methods: `0x0055D530`

- `this+0x00000004` `dword (handle) vertexBufferHandle` (read, GUESS)
- `this+0x00000050` `dword stateValue` (write, DERIVED)

### GlobalListReinsertNodeOwner

Maintains a local doubly-linked node list (head this+0x2C) whose nodes, when detached, are re-inserted at the tail of a global list anchored at dword_8B8F28+348 with their active-flag bit 2 cleared.

Methods: `0x00560F40`

- `this+0x0000002C` `pointer (node) localListHead` (read_write, DERIVED)

### AudioMixLookupTables

One-time initializer of four global byte tables used by audio mixing and pixel processing (two multiply tables and two sum-clip tables).

Methods: `0x00561B2A`

- `this+0x00000053` `function pointer callbackFunctionPointer` (unknown, GUESS)

### NetworkSessionObject

The network session object: created at 1464 bytes with config strings (offsets 12/44/76), a sub-struct at +0x4, a 28-byte-stride element array at +0x8, socket at +136, tick timestamp at +140 and state at +144; drives server-list queries, UDP broadcast status, a blocking poll loop and delegate wrapping.

Methods: `0x00561F60`, `0x00562B50`, `0x00562E30`, `0x00563000`, `0x005630D0`, `0x005633D0`

- `this+0x00000000` `dword (flag) activeFlag` (read_write, GUESS)
- `this+0x00000004` `pointer (0x18-byte sub-struct) subStructPointer` (read_write, GUESS)
- `this+0x00000008` `pointer (28-byte stride array) elementArray` (read_write, GUESS)
- `this+0x0000000C` `char buffer (gamename) configStringA` (read_write, GUESS)
- `this+0x00000094` `dword (type selector) typeSelector` (read, GUESS)

### NetworkEchoSender

Formats and sends an 'echo' message over a socket, bounding the input length and forwarding to the socket write routine.

Methods: `0x00562950`


### NetworkStreamSocketSet

A UDP socket array (28-byte stride) with active flags, a count, an activated counter, a shutdown flag and a completion callback; polls, receives, feeds the audio mixer, timeout-sweeps idle entries and drives activation or teardown.

Methods: `0x00563AB0`

- `this+0x00000004` `dword referenceTotal` (read, GUESS)
- `this+0x00000008` `pointer (28-byte stride array) socketArray` (read_write, DERIVED)
- `this+0x0000006C` `dword socketCount` (read, DERIVED)
- `this+0x00000070` `dword activatedCount` (read_write, DERIVED)
- `this+0x00000074` `dword (flag) shutdownFlag` (read, DERIVED)
- `this+0x00000078` `function pointer completionCallback` (read, DERIVED)
- `this+0x0000007C` `pointer completionContext` (read, DERIVED)
- `*(this+0x8)+0x00000000` `dword (SOCKET) socketEntrySocket` (read_write, GUESS)
- `*(this+0x8)+0x00000004` `dword (flag) socketEntryActiveFlag` (read_write, GUESS)

## Compatibility contracts

- **NamedListDuplicateRejection** — Inserting a name that already exists in the actor or response list must fail with a formatted error string ('Actor %s already exists' / 'Response %s already exists') and a return of -1; a successful insert returns 0.
- **ConfigLineTokenizerResultContract** — A parsed key=value line returns 0 and stores the '=' separator location in the tokenizer state (offset 0x30C); blank/comment lines return 1; lines failing the start-token check or empty after trimming return 2.
- **EchoMessageLengthBound** — Echo input longer than 0x546 bytes must be dropped (null return) rather than sent; in-range input is formatted as '\echo\%s' and forwarded to the socket write path.
- **SurfaceFormatCodecOutputs** — Format codec functions must map format keys 20-25/40-41 and the five large FourCC constants to their (bit depth, aux) pairs, and (bit depth, format identifier) pairs to the small and large output codes; unknown inputs map to (0, 0) or return without writing.
- **ServerListQueryReturnCodes** — The server-list query returns 0 on success, 3 on a network failure (recv or send error), and 5 on response validation failure; on success it signals completion through the audio-value setter with argument 1.
- **UdpBroadcastPortRangeSend** — Status broadcast must send an 8-byte payload via sendto to the 255.255.255.255 broadcast address across the port range [a2, a3] stepping by a4, converting each port with htons; after broadcasting it records GetTickCount at the socket timestamp field.
- **NetworkStreamIdleTimeout** — Sockets whose last-activity timestamp is more than 3000 ms old are deactivated during the poll; once the shutdown flag is set or the activated count reaches the reference total with no active sockets, the socket array is torn down and the audio value reset.

## Unresolved

- The 32-byte node layout of the actor/response lists is only partially known (next link at +0x1C); the meaning of the integer arguments a3 and a4 consumed by StringCopyFieldInit is unknown.
- Response-list traversal: the raw source walks from this+0x4 while the packet names the tail chain through the container pointer at this+0x20; the relationship between the two fields is not deterministically established.
- Contradiction: CreateNetworkSessionObject places a 0x18-byte sub-struct pointer at offset 4, but NetworkAudioStreamPoll reads offset 4 as a reference total; offset 8 holds a 28-byte-stride array in both. The poller's base object may differ from the session object; not reconciled by this packet.
- The audio-config node match dword semantics (width/height/format/loop in the skeleton) are DERIVED prose, not raw evidence; the enum of type-selector values at this+0x94 (DisplayModeQueryWrapper) is undocumented.
- LinkedListTailAppend never explicitly zeroes a2's next (+0x20) and the empty path does not initialize a2's links; the caller is expected to pre-initialize the node. The 0x1538 base is not read in the raw source (IDB interpretation only).
- The vtable slot roles on the device and surface objects (load/bind/lock/release at slots 124/60/8; query/transform at 152/160/164) are inferred from call shape only; the a2 descriptor fields (flags 0x40000/0x200000, slots a2[1]/a2[3]/a2[5]) are derived, not confirmed.
- The fields this+0x1534 and this+0x1538 are extracted as read-only by the IDB but do not appear in the raw source of 0x0055CA90.
- The AudioMixLookupTableInit first three statements are __usercall register-allocation artifacts; the indirect call through the function pointer at a1+0x53 is a callback whose target and purpose are unknown, and the returned value is an uninitialized stack slot.
- The delegate target sub_562AC0 is present in the raw source of 0x00561F60 but not listed in the packet callees, so its contract is unconfirmed; the meaning of the constant 2 is unknown.
- CreateNetworkSessionObject declares parameter a6 but the body never references it; the three config strings are stored from a1/a2/a3 with a2 and a3 swapped (offset 76 vs 44), suggesting a naming/directory split whose intent is undocumented.
- The network key at a1+44 (XOR decode source) is not determined as static or per-session; the a1+1460 clear and the exact meaning of session states 6 and 7 are skeleton-labeled only.
- SendEchoFormatted's a1 is a SOCKET, not the session object; the object ownership of this helper is uncertain, and the behavior/return contract of callee sub_562710 is unknown here.
- PollWhileActive's flag at this+0x0 is likely an active/running state, but who clears it is not visible in the packet; if the flag is false on entry the loop body never runs and the returned result is uninitialized.
- The byte_FF hardware globals referenced by NetworkAudioStreamPoll and UdpBroadcastStatusSend are absent from the raw source text and look like decompiler artifacts of the sockaddr/layout handling.
- All owner classes are evidence-level UNKNOWN; every class in this proposal is a DERIVED/GUESS grouping of validated IR, and equal offsets on different base objects are not treated as shared fields.
- The exact consumer of the '=' pointer stored at this+0x30C by ConfigLineTokenizer (caller LineReaderFromBuffer) is unproven; sub_587C20/sub_588640/sub_589A35 behaviors are known only from these call sites.
