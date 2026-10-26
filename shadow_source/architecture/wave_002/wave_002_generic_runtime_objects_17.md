# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `GUESS`

Sixteen runtime-infrastructure functions share no single owner type but cohere as generic runtime objects: a render-display state dispatcher (0x005550E0) driving a render-context vtable command interface, a high-resolution timer initializer (0x00556260), scene-graph loading (0x0055B6B0, 0x0055A910) and teardown helpers, network receive/startup/dispatch (0x00561E30, 0x005622C0, 0x00564660), config value resolution (0x00565520), particle vertex-buffer setup (0x00557670), generic cleanup stubs (0x00557280, 0x00557470, 0x00560E50), and two-level list destruction/reset (0x00565E20, 0x00565EB0). Ownership is largely UNKNOWN; the classes below are DERIVED proposals grounded in shared field bases and callee sets.

## Function roles

- `0x005550E0` **RenderDisplayState** — Per-frame render-display state dispatcher: resets the session-ID cache (this+0x13CC), reads camera/audio field pairs off a3, one-time-initializes the render context (this+0x1100) via vtable+200, computes and pushes a packed color blend (command 60), iterates four display slots through a jump table, runs rich/plain element-group draw paths through context vtable+340/+284/+200 with camera/sound sync and session-change logging, and finishes with a vehicle sync block.
- `0x00556260` **HighResolutionTimer** — High-resolution timer initializer: mode 1 uses QueryPerformanceFrequency/QueryPerformanceCounter (globals 0x0059E240/0x0059E23C), mode 2 snapshots RDTSC and stores 1000000 * v11 as the base; both paths copy the last-query pair to previous, zero accumulator fields, store the mode at offset 0x48 and compute the 2^32/base conversion factor double at offset 0x8. Returns 0.
- `0x00557280` **UnknownObject** — Cleanup routine: frees the sub-resource pointer at this+0x20C via FreeWrapper_7bcf when non-null, zeroes the pointer, and calls the empty stub EmptyStub_0170. Owner type unidentified.
- `0x00557470` **UnknownObject** — Empty stub thunk: ignores this and forwards to the empty-stub target EmptyStub_0170 (name-level reading only; no callee evidence record in the packet). Used by cleanup/destructor and resource-release paths.
- `0x00557630` **UnknownObject** — Conditional flag-clear dispatch on the flag DWORD at this+0x20: bit 8 selects Return0Stub vs ResourceTeardownWithStateArrayReset, both gated on bit 0x400; on success clears bit 0x400 and returns 0, nonzero helper result returns -1.
- `0x00557670` **ParticleVertexBuffer** — Particle-system vertex/index buffer setup: allocates and constructs a 572-byte particle object, validates a name string, reads the linked-list head, copies the source data block, allocates element/group arrays (this+0x34/+0x50), fills vertices/index buffers, registers groups with the audio/rendering subsystem, and reports errors via sub_53C590.
- `0x0055A910` **SceneNode** — Scene-file node parser: allocates a 572-byte node, attaches it to a parent, consumes a keyword token stream (mesh/anim/LOD/collision/shadow/render/visgroup keywords setting bit flags and float/view fields), links the node into the scene graph, and frees it on parse failure or visgroup rejection.
- `0x0055B6B0` **SceneFileLoader** — Scene file loader with path search: opens the named file directly, then tries each registered path entry (byte_8B5A3C, stride 132), then walks the resource list anchored at dword_8B8F14; each success is parsed by SceneFileTopLevelParser. Reports 'Could not locate scene file %s' and returns -1 when unfound.
- `0x0055C9A0` **UnknownObject** — Side-effect-free field getter: reads the dword at this+0x13A8 and returns it masked with 0xF1000. Consumed by D3DTextureCreation during texture creation.
- `0x00560E50` **UnknownObject** — Destructor that null-guard frees three sub-objects at this+0xC, this+0x1C and this+0x20 (first two via EmptyStub_7470/FreeWrapper_7bcf, third via ConditionalFreeOfField/FreeWrapper_7bcf). Invoked by F_3DSoundSourceDestructor, consistent with 3D sound source teardown.
- `0x00561E30` **NetworkSocketReceiver** — UDP socket poller: gated on the enable flag at this+0xE4; builds a single-socket fd_set, loops on select() with zero timeout, recvfrom()s up to 255 bytes into the global buffer (0x008CEF80), null-terminates it, and dispatches via FilePathNameLookup with the sender address. Returns the last select result.
- `0x005622C0` **UnknownObject** — Path/request string dispatcher: a leading ';' routes to a virtual handler (context dword index 63, default context off_5E4DFC); otherwise counters are bumped and the 9-entry table off_5E4CD4 is scanned via sub_562530, with hit cases running buffer-init routines that feed sub_5629B0 for the final composition.
- `0x00564660` **UnknownObject** — One-call Winsock bootstrap: returns the result of WSAStartup(0x101, &localWSAData), requesting Winsock 1.1. Free-standing initializer with no this-object evidence.
- `0x00565520` **ConfigValueResolver** — Config value resolver: guards on the token string at this+0x198, dispatches the query by '=' count (exactly one to StringBasedLookup, otherwise to the dot-path parser sub_565400), copies the resolved text from this+0x180 into this, splits on the delimiter asc_5D251C into up to two output segments, and returns 1.
- `0x00565E20` **ResourceList** — Two-level linked-list destruction: cleans the inner list via EnhancedListCleanupWithSubObjectDelete, frees the extra sub-resource at head+0x210, walks the outer nodes releasing each node's data (with ShortComputation_4370 teardown when node+8 flag set) and the node itself, zeroes the four head fields, and frees the head.
- `0x00565EB0` **ResourceList** — Resource-list cleanup: passes the list head to EnhancedListCleanupWithSubObjectDelete, then unconditionally zeroes the 32-bit field at head+0x21C and returns the list-head pointer. No guards.

## Proposed classes

### RenderDisplayState

Per-frame render-display state dispatcher that drives a render-context command interface across four display slots, tracks session changes, blend color, element-display mode, and audio state.

Methods: `0x005550E0`

- `this+0x00001100` `RenderContext* renderContext` (read, GUESS)
- `this+0x000013A8` `unsigned int modeFlagsWord` (read, GUESS)
- `this+0x000013B0` `int subElementMaxCount` (read, GUESS)
- `this+0x000013C4` `int contextInitGuard` (read_write, GUESS)
- `this+0x000013C8` `unsigned int cachedColorBlend` (read_write, GUESS)
- `this+0x000013CC` `int sessionIdCache` (read_write, GUESS)
- `this+0x000013D0` `int elementDisplayModeFlag` (read, GUESS)
- `this+0x000013D8` `int audioEnabledFlag` (read, GUESS)
- `this+0x000014F0` `int extraRenderStateCount` (read, GUESS)
- `this+0x00000000` `int resultSlot` (write, GUESS)
- `this+0x00001148` `int* subElementSlotChainBase` (read, GUESS)
- `this+0x0000114C` `int subElementSlotChainStride` (read, GUESS)

### RenderContext

Render command-dispatch target object referenced from RenderDisplayState at this+0x1100. Only its vtable command slots are evidenced; no concrete methods are present in this packet.

Methods: 

- `*(this+0x1100)+0x00000094` `vtable dispatch slot (offset +148) commandSlot148` (read, GUESS)
- `*(this+0x1100)+0x000000A8` `vtable dispatch slot (offset +168) commandSlot168` (read, GUESS)
- `*(this+0x1100)+0x000000C8` `vtable dispatch slot (offset +200) commandSlot200` (read, GUESS)
- `*(this+0x1100)+0x00000118` `vtable dispatch slot (offset +280) commandSlot280` (read, GUESS)
- `*(this+0x1100)+0x0000011C` `vtable dispatch slot (offset +284) commandSlot284` (read, GUESS)
- `*(this+0x1100)+0x00000154` `vtable dispatch slot (offset +340) commandSlot340` (read, GUESS)

### HighResolutionTimer

High-resolution timer structure initialized by HighResolutionTimerInit with QPC or RDTSC backend, base ticks, 2^32/base conversion factor, last/previous query pairs, accumulators, and mode selector.

Methods: `0x00556260`

- `this+0x00000000` `unsigned int baseTicks` (write, GUESS)
- `this+0x00000008` `double tickToTimeFactor` (write, GUESS)
- `this+0x00000010` `int accumulatorA` (write, GUESS)
- `this+0x00000014` `int accumulatorB` (write, GUESS)
- `this+0x00000018` `unsigned int lastQueryLow` (write, GUESS)
- `this+0x0000001C` `unsigned int lastQueryHigh` (write, GUESS)
- `this+0x00000020` `unsigned int previousQueryLow` (write, GUESS)
- `this+0x00000024` `unsigned int previousQueryHigh` (write, GUESS)
- `this+0x00000028` `int accumulatorC` (write, GUESS)
- `this+0x0000002C` `int accumulatorD` (write, GUESS)
- `this+0x00000048` `int modeSelector` (write, GUESS)

### ParticleVertexBuffer

Particle-system vertex/index buffer: element and group arrays, count buffers, accumulators, and flags populated by ParticleVertexBufferSetup from a source particle object.

Methods: `0x00557670`

- `this+0x00000020` `unsigned int flags` (read_write, GUESS)
- `this+0x00000024` `int vertexCountAccumulator` (read_write, GUESS)
- `this+0x00000028` `int indexCountAccumulator` (read_write, GUESS)
- `this+0x0000002C` `int elementCount` (read_write, GUESS)
- `this+0x00000034` `void* elementArray` (read_write, GUESS)
- `this+0x0000003C` `int* countBufferA` (read_write, GUESS)
- `this+0x00000040` `int* countBufferB` (read_write, GUESS)
- `this+0x00000044` `int* groupCountBufferA` (read_write, GUESS)
- `this+0x00000048` `int* groupCountBufferB` (read_write, GUESS)
- `this+0x0000004C` `int groupCount` (read_write, GUESS)
- `this+0x00000050` `void* groupArray` (read_write, GUESS)

### SceneNode

Scene-file node parser that consumes a keyword token stream, links nodes into the scene graph, and maintains container-level shadow-receiver/reflector counts.

Methods: `0x0055A910`

- `this+0x0000013C` `int shadowReceiverCount` (read_write, GUESS)
- `this+0x00000174` `int reflectorCount` (read_write, GUESS)

### SceneFileLoader

Locates and parses named scene files by direct open, registered path-entry array (byte_8B5A3C, stride 132), and resource-list walk; delegates parsing to SceneFileTopLevelParser.

Methods: `0x0055B6B0`


### NetworkSocketReceiver

Polls a UDP socket (this+0x0) gated on the enable flag (this+0xE4), receives datagrams into the shared buffer, and dispatches them.

Methods: `0x00561E30`

- `this+0x00000000` `SOCKET socket` (read, GUESS)
- `this+0x000000E4` `int receiveEnabledFlag` (read, GUESS)

### ConfigValueResolver

Resolves config queries against the token at this+0x198 via '='-count dispatch and dot-path parsing, and splits resolved text into up to two value segments.

Methods: `0x00565520`

- `this+0x00000180` `char* resolvedTextBufferPtr` (read, GUESS)
- `this+0x00000198` `char* tokenString` (read, GUESS)

### ResourceList

Two-level resource list head with inner-list cleanup, optional extra sub-resource (head+0x210) and a count/flag (head+0x21C); node data is torn down only when the node+8 flag is set.

Methods: `0x00565E20`, `0x00565EB0`

- `obj+0x00000000` `void* listHeadLinkA` (read_write, GUESS)
- `obj+0x00000004` `void* listHeadLinkB` (read_write, GUESS)
- `obj+0x00000008` `void* listHeadLinkC` (read_write, GUESS)
- `obj+0x0000000C` `void* listHeadLinkD` (read_write, GUESS)
- `obj+0x00000210` `void* extraSubResource` (write, GUESS)
- `obj+0x0000021C` `int countFlag` (write, GUESS)
- `*(obj+0x0)+0x00000000` `void* nodeData` (read, GUESS)
- `*(obj+0x0)+0x00000008` `char nodeCleanupFlag` (read, GUESS)

## Compatibility contracts

- **HighResolutionTimerLayout** — A replacement must preserve the high-resolution timer struct layout (base ticks at 0x0, 2^32/base conversion-factor double at 0x8, accumulator pairs at 0x10/0x14 and 0x28/0x2C, last-query pair at 0x18/0x1C, previous pair at 0x20/0x24, mode selector at 0x48) and both initialization backends: QueryPerformanceCounter (mode 1) and RDTSC scaled by 1000000 (mode 2).
- **RenderContextCommandDispatch** — Render-state changes must be issued through the render context vtable command slots (+148, +168, +200, +280, +284, +340) with the evidenced argument shapes: one-time context init command 136, packed color-blend command 60 with change detection, element display-mode commands 23, render-state push/pop command 28, vehicle-sync command 47, sprite draw at +340 and camera draw at +284. Slot meanings beyond these arguments are not established.
- **SceneFileKeywordGrammar** — Scene files are parsed as keyword/value lines; a replacement scene loader must recognize the keyword set and their effects: aInstance (nested node recursion), aMeshfile, aAnimfile/aAutostart, aLodin/aLodout (float fields), aHattarget/aColltarget/aSpheretarget/aZbuffer/aShadowcaster/aShadowobject/aShadowreceiver/aReflector/aMorphtarget/aLightobject (node flag bits), aOrient/view floats, aMoveable/aStamp/aBillboard/aRender/aChange (node +60 flag bits), aSpecial1/aSpecial2/aPlanes, aActor/aHatactor/aResponse, and aVisgroups mask acceptance.
- **NetworkPacketReceiveDispatch** — Incoming UDP datagrams (up to 255 bytes) are received into the shared buffer (0x008CEF80), null-terminated, and dispatched with the sender address; a leading ';' routes the request to a virtual handler on the context object, otherwise a table scan composes the result. Polling uses select() with a zero timeout.
- **Winsock11Bootstrap** — Network startup must call WSAStartup requesting Winsock version 1.1 (0x101); the WSAStartup result code is returned to the caller and the local WSAData contents are discarded.
- **ConfigKeyValueResolution** — Config value resolution dispatches the query by '=' count (exactly one '=' uses the string lookup, otherwise the dot-delimited path parser), copies the resolved text from the buffer pointer at this+0x180, and splits it on the delimiter to extract up to two value segments, returning 1 on success and 0 on a null lookup result.

## Unresolved

- Owners of most packet functions are UNKNOWN; class groupings (RenderDisplayState, RenderContext, HighResolutionTimer, ParticleVertexBuffer, SceneNode, SceneFileLoader, NetworkSocketReceiver, ConfigValueResolver, ResourceList) are DERIVED proposals inferred from shared field bases and callee sets, not packet-confirmed types.
- The render context vtable dispatch slots (+148/+168/+200/+280/+284/+340) have no runtime command meanings established by this packet.
- Field this+0x13A8 is read by both UpdateRenderDisplayState (0x005550E0, bit 0x100 mode) and MaskedFieldGetter (0x0055C9A0, mask 0xF1000); common ownership of the two receivers is not proven.
- Globals flt_59E868, flt_59FEC8, flt_5B8980 (read by 0x005550E0) and dbl_5AF448 (possible backing for the 2^32 constant in 0x00556260) do not appear in the raw decompiled bodies; their mappings are inferred.
- Globals byte_FF00000000005406 and byte_FF00000000005435/36/38/39 carry 0xFF-prefixed addresses outside the image range and look like stale decompiler extraction artifacts; roles unresolved.
- EmptyStub_0170 (callee 0x004B0170) and the emptyStubForward thunk target are not resolvable to concrete implementations in this packet.
- SceneNode (0x0055A910) node-layout offsets (v6[15] state, v6[16] parent, v6[20] and +60 flag dwords, +56 visgroup mask, +80 planes, +516 mesh list, +532 audio handle) are DERIVED from decompilation, not packet field facts.
- Display-slot element arrays (a2+436..464) and the element-group struct layout (v14 at *(*hdr+1)+12, fields at +39/+41/+42/+43) have no concrete types; sub-element slot chains (this+1118 onward, stride 17) are evidenced only in raw source.
- jpt_562391 (global 0x0056250C) jump-table role in FilePathNameLookup is unverifiable; select()'s first argument (64) and the semantics of the this+0xE4 flag in 0x00561E30 are unestablished.
- ResourceList head field semantics (obj+0x4/0x8/0xC linkage roles) and the count/flag zeroed at obj+0x21C are unestablished; the different teardown shape of the third sub-object in 0x00560E50 suggests distinct sub-object types that are not documented.
- The linked-list node size derivation ((node[73] << 8) + node[74] + 8) in SceneFileLoadWithPathSearch is described only at the index level; the node header layout is unresolved.
- Globals dword_8B78A0, dword_8B8F28 and dword_8B8EE8 act as module roots for audio/rendering registration in 0x00557670/0x0055A910; their concrete types are not evidenced.
