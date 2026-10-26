# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

Twenty functions grouped by evidence into six candidate classes plus unowned helpers. CubeMapMasFileLoader (0x0055FBE0, 0x0055FC40, 0x0055FE30, 0x00560230) shares one layout: magic header at base, file handle at +0x10, filename buffer at +0x14, entry count at +0x118, data size at +0x11C, table/buffer at +0x128. NetworkAudioReceiver (0x00563410) is a TCP/UDP/alternate mode state machine over a socket at +0x88 with an optional RC4/XOR decrypt path. SystemCapabilitiesInfo (0x0055F080, 0x0055F0D0) is inferred (GUESS) from the shared RenderUISystemGlobalInit caller and overlapping offsets: performance tier at +0x0, MHz at +0x28, memory stats at +0x7C..+0x90, feature flags at +0x9C. PathNameResolver (0x005626B0, 0x00562830, 0x00562890, 0x005628F0) is four near-identical 1400-byte stack-buffer builders differing only in the indirect handler slot. VertexProjectionUpdater (0x005613E0) and ConfigKeyLookupParser (0x00565400) are single-function GUESS classes. Remaining functions keep UNKNOWN owners. The packet's large read-only global tables (jump tables, doubles, dword/word/byte tables around 0x5DC47C) and non-canonical 0xFF00.. MMX/3DNow artifacts are folded into unresolved evidence.

## Function roles

- `0x0055F080` **SystemCapabilitiesInfo** — Zeroes the base structure via GlobalZeroInit_c2a0 then explicitly clears fifteen heterogeneous fields (DWORD +0x0; BYTEs +0x4/+0x2C/+0x54; DWORDs +0x24/+0x28/+0x4C/+0x50/+0x74/+0x78/+0x7C/+0x80/+0x94/+0x98/+0x9C); returns this. Constructor-style initializer invoked by RenderUISystemGlobalInit and sub_556260 during render/UI global init.
- `0x0055F0D0` **SystemCapabilitiesInfo** — CPU/system capability detection and benchmark: GetSystemInfo/CPUID/GetPriorityClass benchmark, vendor-specific (Intel/AMD/Cyrix) CPU name and tier/feature-flag assignment, GlobalMemoryStatus memory totals, and optional hand-off of name plus +0x94/+0x98 fields to sub_55BE20. Invoked by RenderUISystemGlobalInit.
- `0x0055FBE0` **CubeMapMasFileLoader** — Cube map texture struct initializer: bulk-zeros the object, strcpy's the aCubemas410 filename constant onto the base, then clears offsets 12/16/20 and 276-304. Returns this.
- `0x0055FC40` **CubeMapMasFileLoader** — Loads a cube map MAS file: copies the filename to +0x14, opens via direct path then audio-entry directories (byte_8B5A3C/dword_8B8E30), validates a 12-byte magic against three constants, reads header fields, allocates payload = field@+0x118<<8 into +0x128, reads payload, bumps +0x11C by 24. Returns 0/-1/-2 on the error paths. Called by 0x0053CBC0.
- `0x0055FE30` **CubeMapMasFileLoader** — Two-field resource cleanup: closes the +0x10 file handle and frees the +0x128 buffer, each null-guarded and zeroed after release. Always returns 0.
- `0x00560230` **CubeMapMasFileLoader** — Looks up a filename in the packed resource table (256-byte entries at this+0x128, name at entry+20) and seeks the +0x10 handle to the entry data offset via sub_587F64. Stores matched index at +0x124. Returns 0 or -2.
- `0x00560BA0` **UnknownObject** — Object initializer (thiscall): zero-init via GlobalZeroInit_c2a0, stamp float 0.2f at +0x0, clear scalar words, store a2 at +0x18 and a3 at +0x28, set state word +0x24 to 2, and link this into a2's child list (a2+312 deref, slot +560). Invoked by LinkedListNodeInsert_5930.
- `0x00560C00` **UnknownObject** — Sets the 32-bit state/flag field at +0x24 to 2, then calls the empty stub EmptyStub_0170. Runs during 3D sound source destruction.
- `0x005613E0` **VertexProjectionUpdater** — Timed 3D-to-2D vertex projection update for the render tree: guards on status byte +0x24 bit 2 and render-state +0x18 flags, and on interval expiry (this+0x0 vs timer at +0x1C) walks the node tree, interpolates triangle vertices and projects them through vtable slot 4 of dword_8B8F24 into the +0x8 output buffer; otherwise resets the timer and rebuilds the node collection via RecursiveTreeNodeTraversal. Called by 0x005550E0.
- `0x00561940` **UnknownObject** — Field cleanup helper: if the pointer at +0x1EC is non-null, free it via FreeWrapper_7bcf, pass the wrapper return through, and clear the field. Runs during SceneGraph cleanup.
- `0x005626B0` **PathNameResolver** — Path/file-name helper (thiscall): builds a 1400-byte stack buffer seeded from byte_5EA438, invokes the callback held at this+0xC8 with (buffer, 1400, *(this+0x100)), and delegates composition to sub_562710. Called by FilePathNameLookup.
- `0x00562830` **PathNameResolver** — Variant of the stack-buffer path resolver that calls the handler pointer at a1+204 instead of this+0xC8; identical buffer build and sub_562710 delegation. One branch of FilePathNameLookup entry-table dispatch.
- `0x00562890` **PathNameResolver** — Variant of the stack-buffer path resolver that calls the handler pointer at a1+208 instead of this+0xC8; identical buffer build and sub_562710 delegation. One branch of FilePathNameLookup entry-table dispatch.
- `0x005628F0` **PathNameResolver** — Variant of the stack-buffer path resolver that calls the handler pointer at a1+212 instead of this+0xC8; identical buffer build and sub_562710 delegation. One branch of FilePathNameLookup entry-table dispatch.
- `0x00563410` **NetworkAudioReceiver** — Polls a network socket and processes incoming audio-stream packets. State machine on the +0x0 mode field: case 1 TCP receiver (select/recv into byte_8CF288/dword_8CFAE0, XOR/RC4 decrypt, 6-byte header parse, audio note/param dispatch), case 2 UDP receiver (select/recvfrom, port dispatch), case 3 alternate handler. Closes and resets +0x88 on failure/timeout/end-of-stream and notifies AudioValueSetterCall.
- `0x00563870` **UnknownObject** — Three-state path-segment processor driven by the state field at a1+1460: state 0 validates and counts path segments (dword_8CFA88), state 1 extracts each segment, runs it through the a1+148 callback and stores results in dword_8CFA90, state 2 runs QueryWithContextCleanup and the a1+120 final callback. Invoked by receiveAudioStreamPacket.
- `0x005653F0` **UnknownObject** — Forwarding thunk (__stdcall): passes a1 straight through to the real implementation and returns its result. On the frame path, called only by 0x00565520.
- `0x00565400` **ConfigKeyLookupParser** — Parses a dot-delimited config key path: copies the string at this+0x198 onto the object base, tokenizes at the '.' delimiter (asc_5C30AC), walks matching segments against a2 via sub_588410, finishes with a word_5C32D8 segment. Returns 0/1. Called by five config-key consumers.
- `0x00565D50` **UnknownObject** — Linked-list destructor with per-node sub-object cleanup: walks the list from *a1, and when the node+8 flag is set frees data and its sub-resource at data+0x144; frees every node; zeroes the four list-head dwords and returns the last FreeWrapper result.
- `0x00565DC0` **UnknownObject** — thiscall factory: allocates a 548-byte object via OperatorNewNhMallocWrapper, default-initializes leading fields and a -1 sentinel at offset 532, stores the pointer into *this (0 on allocation failure). Callers span resource cleanup, file enumeration, profile loading, and texture scanning.

## Proposed classes

### CubeMapMasFileLoader

Cube-map MAS file resource object: constructor-style init, file open/validate/read, resource-table filename lookup/seek, and dual-field cleanup. Layout shared across four functions: magic/header at base, file handle at +0x10, filename at +0x14, entry count at +0x118, data size at +0x11C, matched index at +0x124, table/data buffer at +0x128.

Methods: `0x0055FBE0`, `0x0055FC40`, `0x0055FE30`, `0x00560230`

- `this+0x00000000` `char[16] magicHeaderBuffer` (read_write, DERIVED)
- `this+0x0000000C` `uint32_t scalarDword` (write, GUESS)
- `this+0x00000010` `void* fileHandle` (read_write, DERIVED)
- `this+0x00000014` `char[256] filenameBuffer` (write, DERIVED)
- `this+0x00000114` `uint32_t headerField` (read, GUESS)
- `this+0x00000118` `uint32_t dataSizeField` (read_write, DERIVED)
- `this+0x0000011C` `uint32_t dataSizeBytes` (read_write, DERIVED)
- `this+0x00000120` `uint32_t headerField2` (read, GUESS)
- `this+0x00000124` `uint32_t matchedEntryIndex` (write, DERIVED)
- `this+0x00000128` `void* dataBuffer` (read_write, DERIVED)
- `this+0x0000012C` `uint32_t entryFieldUnknown` (unknown, UNKNOWN)
- `this+0x00000130` `uint32_t scalarDwordHigh` (write, GUESS)

### NetworkAudioReceiver

Receives streaming audio over a network socket. Mode field at +0x0 selects TCP (select/recv/decrypt/parse), UDP (select/recvfrom/port dispatch), or an alternate handler. Shares the byte_8CF288/dword_8CFAE0 receive buffer with the audio system and notifies AudioValueSetterCall on stream end or failure.

Methods: `0x00563410`

- `this+0x00000000` `int32_t receiverMode` (read, DERIVED)
- `this+0x00000074` `uint8_t streamEndFlag` (read, GUESS)
- `this+0x00000088` `SOCKET socketHandle` (read_write, DERIVED)
- `this+0x0000008C` `uint32_t lastActivityTimestamp` (read, GUESS)
- `this+0x00000090` `uint8_t protocolFlag` (read, GUESS)
- `this+0x00000098` `int32_t sessionId` (read, GUESS)
- `this+0x0000055C` `int32_t encryptionFlag` (read, DERIVED)

### SystemCapabilitiesInfo

System capability/output structure produced by CPU detection and used by render/UI global init. Performance tier at +0x0, MHz at +0x28, memory stats at +0x7C..+0x90, feature flags at +0x9C. GUESS: ownership inferred only from the shared RenderUISystemGlobalInit caller and overlapping field offsets between zeroInitStruct and CPUDetectionAndBenchmark.

Methods: `0x0055F080`, `0x0055F0D0`

- `this+0x00000000` `uint32_t performanceTier` (read_write, GUESS)
- `this+0x00000004` `uint8_t reservedByte` (write, GUESS)
- `this+0x00000024` `uint32_t unsupportedMark` (write, GUESS)
- `this+0x00000028` `uint32_t cpuClockMhz` (write, GUESS)
- `this+0x0000002C` `uint8_t reservedByte2` (write, GUESS)
- `this+0x0000004C` `uint32_t reservedDwordA` (write, GUESS)
- `this+0x00000050` `uint32_t reservedDwordB` (write, GUESS)
- `this+0x00000054` `uint8_t reservedByte3` (write, GUESS)
- `this+0x00000074` `uint32_t reservedDwordC` (write, GUESS)
- `this+0x00000078` `uint32_t reservedDwordD` (write, GUESS)
- `this+0x0000007C` `uint32_t totalPhysicalMemory` (write, GUESS)
- `this+0x00000080` `uint32_t availablePhysicalMemory` (write, GUESS)
- `this+0x00000084` `uint32_t totalPageFile` (write, GUESS)
- `this+0x00000088` `uint32_t availablePageFile` (write, GUESS)
- `this+0x0000008C` `uint32_t totalPhysicalMemoryDuplicate` (write, GUESS)
- `this+0x00000090` `uint32_t availablePhysicalMemoryDuplicate` (write, GUESS)
- `this+0x00000094` `uint32_t capabilityOutputA` (write, GUESS)
- `this+0x00000098` `uint32_t capabilityOutputB` (write, GUESS)
- `this+0x0000009C` `uint32_t featureFlags` (write, GUESS)

### PathNameResolver

Resolves file paths by building a 1400-byte stack buffer (first byte from byte_5EA438, rest zeroed), populating it through an object-held handler pointer, and composing the result via sub_562710. Four entry points differ only in the handler slot used (this+0xC8 or a1+204/+208/+212). GUESS: grouped by identical shape; the owning object type is unproven.

Methods: `0x005626B0`, `0x00562830`, `0x00562890`, `0x005628F0`

- `this+0x000000C8` `void (*)(char*,int,void*) pathFillCallback` (read, GUESS)
- `this+0x00000100` `void* callbackArgument` (read, GUESS)

### VertexProjectionUpdater

Timed render-tree vertex projection: interval at +0x0, emitted-vertex counter at +0x4, output buffer at +0x8, render-tree node at +0xC, render-state object at +0x18, high-precision timer at +0x1C, vertex buffer at +0x20, status byte at +0x24. Projects interpolated triangle vertices through vtable slot 4 of the dword_8B8F24 object. GUESS: single function, owner unproven.

Methods: `0x005613E0`

- `this+0x00000000` `float updateIntervalSeconds` (read, GUESS)
- `this+0x00000004` `uint32_t emittedVertexCounter` (read_write, GUESS)
- `this+0x00000008` `void* screenOutputBuffer` (write, GUESS)
- `this+0x0000000C` `void* renderTreeNode` (read, GUESS)
- `this+0x00000018` `void* renderStateObject` (read, GUESS)
- `this+0x0000001C` `void* highPrecisionTimer` (read, GUESS)
- `this+0x00000020` `void* vertexBuffer` (read, GUESS)
- `this+0x00000024` `uint8_t statusByte` (read, GUESS)

### ConfigKeyLookupParser

Parses a dot-delimited config key path on the object buffer: source string at +0x198, current token pointer at +0x180. Tokenizes at the '.' delimiter and matches segments against a caller-supplied key. GUESS: single function; the owning config object is unproven.

Methods: `0x00565400`

- `this+0x00000180` `char* currentToken` (read_write, GUESS)
- `this+0x00000198` `char* sourceKeyString` (read, GUESS)

## Compatibility contracts

- **CubeMapMasFileLayout** — A replacement executable must read cube-map MAS files whose first 12 bytes match one of three magic constants (0x005DBC08/0x005DBBF0/0x005DBBFC), followed by three 4-byte header fields (targets +0x114/+0x118/+0x120); the payload size is field@+0x118 << 8 and the payload is allocated and read into +0x128; the stored size at +0x11C is then inflated by 24. Open failure at the direct path falls back to '%s\%s' candidates over registered audio entry directories and returns -2 when all fail.
- **NetworkAudioStreamWireProtocol** — A replacement executable must receive audio-stream packets on a socket: TCP mode recv's into the shared 2047-byte buffer byte_8CF288 and parses 6-byte headers (packet id dword + subtype word swapped with ntohs), dispatching through audio note/param search; an optional per-byte XOR/RC4 decrypt is keyed by an object string and the +0x55C encryption flag. Packets are delimited by the 7-byte aFinal marker (0x005E4EAC). UDP mode recvfrom's up to 1499 bytes and dispatches by ntohs source port.
- **ResourceEntryTableLayout** — A replacement executable that reads the packed resource table must lay out 256-byte entries starting at this+0x128 with the entry name at entry+20 and the data offset at entry+4; entry count is at this+0x118 and the matched index is stored at +0x124, after which the +0x10 file handle is seeked to the entry data offset (this+0x11C + *(entry+4)).
- **PathResolutionStackBufferContract** — A replacement executable must preserve the path-resolution helper ABI: a 1400-byte stack buffer whose first byte is seeded from byte_5EA438 and whose remaining bytes are zeroed is passed to an object-held handler as (buffer, 1400, argument at +0x100); the handler populates the buffer and sub_562710 composes the final path.

## Unresolved

- Owners of most objects are UNKNOWN: only CubeMapMasFileLoader and NetworkAudioReceiver are DERIVED from packet evidence; SystemCapabilitiesInfo, PathNameResolver, VertexProjectionUpdater and ConfigKeyLookupParser are GUESS groupings and could be wrong.
- SystemCapabilitiesInfo merges zeroInitStruct (0x0055F080) and CPUDetectionAndBenchmark (0x0055F0D0) on the strength of the shared RenderUISystemGlobalInit caller and overlapping offsets (+0x0, +0x24, +0x28, +0x7C, +0x80, +0x94, +0x98, +0x9C). The packet does not prove common ownership; equal offsets from different bases were not merged elsewhere.
- GlobalZeroInit_c2a0 bulk-zeroing plus explicit field writes in zeroInitStruct and cubeMapTextureInit is redundant unless the structures are partially reused; purpose unknown.
- Meaning of the three 4-byte MAS header fields (only +0x118 feeds the data-size computation; +0x114 and +0x120 are read but unrepresented as packet fields) and the trailing +24 adjustment to +0x11C are unknown.
- The resource-table entry layout (256-byte stride, name at +20, data offset at +4) is inferred from the raw source only and not individually flagged; this+0x12C is listed as accessed but never read or written in FilenameLookupAndSeek.
- EmptyStub_0170 (0x00560C00), EmptyStub_7470 and EmptyStubWithFlagCheck (CPU detection) have no in-packet callee addresses; MilesSoundSystemStreamVolumeSet (0x00406659) is listed as a callee of receiveAudioStreamPacket but no call appears in its body.
- Case 3 of receiveAudioStreamPacket delegates to sub_563AB0, which has no packet evidence reference; its identity and return contract are unknown.
- The XOR key string at this+44 and the RC4 key-schedule buffer at this+156 are mentioned in operation prose but are not in the packet field evidence, so only the +0x55C encryption flag is bound.
- The multistatePathProcessor object (state at +1460, callbacks at +120/+148, context at +144/+124) is unidentified and has no packet-listed fields.
- The byte_8CF288 first-byte XOR 0xEC marker and aFinal frame-delimiter semantics are DERIVED from branch structure, not proven.
- The PathNameResolver handler slots at a1+204/+208/+212 and the value at a1+256 are not packet field evidence; whether a1 is a vtable-backed object or a plain function-pointer table is unverified.
- The float defaults (0.2f at +0x0 of ObjectInitWithParameterLinking; 0.050000001 blend in TimedVertexProjectionUpdate) and the state literal 2 at +0x24 (linked-list child object and 3D-sound-source state flag) are semantic GUESSes not established by this packet.
- The tier/feature semantics of CPUDetectionAndBenchmark (0-4, feature bits 1/3/5) are DERIVED from prior fill analysis, not the raw source; vendor string literals are inlined and their numeric global tables unknown.
- The node+8 cleanup flag and data+0x144 sub-resource in EnhancedListCleanupWithSubObjectDelete are unknown; FreeWrapper_7bcf's return value meaning is unknown.
- The 548-byte factory object from AllocateStructWithDefaultValues and its -1 sentinel at +532 are unidentified; the duplicate byte-zero write at +16 may be two booleans sharing the byte.
- sub_565400 (real implementation behind the StringBasedLookup thunk) and the sub_588410/sub_5897CA match-test semantics are not described by this packet; word_5C32D8 as a 'HotExtension' context is DERIVED and unconfirmed.
- The packet marks a large block of read-only globals (jump tables jpt_55F413/55F663/55F73F and neighbors, dword/word/byte tables 0x005DC47C..0x005DC5B4, doubles dbl_59E7D8/dbl_59EB50/dbl_5ADB68/dbl_5AF448) as read but they do not appear by name in the raw listing; Hex-Rays folded them into switch dispatch and inline constants.
- Non-canonical 0xFF0000000000541x/5429/543x addresses are MMX/3DNow register-file artifacts from inline asm (CPU detection) or jump-table artifacts near jpt_563421 (receiveAudioStreamPacket), not ordinary globals.
- Global aSS_3 (0x005C2D64) appears in packet evidence for LoadCubeMapMasFile but is not visible in the raw source body; role of byte_5EA438 (seed byte) and this+0x8C/+0x90 duplicate memory stores is unknown.
- A large block of read-only globals (jump tables jpt_55F413/55F663/55F73F and their byte neighbors, the dword/word/byte tables dword_5DC47C..byte_5DC590, doubles dbl_59E7D8/dbl_59EB50/dbl_5ADB68/dbl_5AF448, dword_8B8F24, and the MMX-style byte_FF0000000000541x/5429 registers) are packet-marked read but do not appear by name in the raw listing; Hex-Rays folded them into switch dispatch and inline constants.
- The byte_FF0000000000541x/5429 addresses are rendered as fixed memory addresses by Hex-Rays and are likely MMX/3DNow register-file accesses from inline asm, not ordinary globals.
- Exact semantics of this+0x24 (set to 1 on unsupported paths) and this+0x94/0x98 (dword indices 37/38 handed to sub_55BE20) are not confirmed in this packet.
- The tier/feature semantics (0-4, bits 1/3/5) are DERIVED from the fill's existing analysis, not stated in the raw source.
- Vendor string literals are rendered inline in the raw listing; the numeric global tables they alias are unknown.
- Floats flt_59E43C and flt_59E448 are flagged as read by the packet but do not appear as named symbols in the decompiled body; they are likely consumed by inlined constant loads (e.g. the 0.050000001 blend factor) and their exact read site is unresolved.
- The exact render-tree node layout behind this+0xC (index array, vertex base and per-node stride 48) is inferred from the loop arithmetic and not independently verified.
- The object behind multistatePathProcessor a1 (state field at +1460, callback at +120, context values at +144 and +148) is not identified; the packet lists no fields for it.
- The meaning of the globals dword_8CFA88 (entry count) and dword_8CFA90 (entry array) as a socket/entry collection is inferred from the state machine flow, not confirmed by independent evidence.
- What QueryWithContextCleanup resolves and what the a1+120 callback consumes is not established beyond the argument shapes seen here.
- The stack buffers v17 and v18 are NUL-terminated around the copied segments, but their exact role (path reconstruction) is inferred from the surrounding path calls.
