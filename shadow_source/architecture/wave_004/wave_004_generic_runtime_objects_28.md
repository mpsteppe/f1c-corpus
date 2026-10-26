# RuntimeObjectServices

Scope: `generic_runtime_objects`  
Trust: `GUESS`

This scope aggregates 24 generic runtime-object behaviors. The strongest evidence clusters are: (1) a mesh rendering helper set (ProcessMeshVerticesWithLighting, VertexColorBlendMMX, BillboardDirectionCompute) sharing a render-descriptor `this` layout and the device-wrapper vtable at dword_8B8F24; (2) a bitmap/resource loading pair (BitmapFileLoad, RenderingBitmapFileLoad) that share the resource-table pattern `*(this+0x128) << 8 + this+0x124` plus a guarded D3D resource loader (loadRenderingResources) driving a loader vtable at this+0x1100; (3) a socket/network cluster (SocketCloseAndCleanup, AppendQueryIdAndSend, SendBufferChunkedOnBackslash, NetworkCleanup, NetworkConnection) handling teardown, query-id wire tokens and connection management; (4) two complementary flag operators on a UI widget state word (Bit1FlagSet / StateFlagBitClear); (5) a recursive shadow-cascade view initializer with its own DERIVED owner; and (6) small dispatcher/allocator helpers (AudioValueSetterCall, ConditionalNetworkUtility, TwoStepDispatch, AudioNoteParamIndexSearchLoop, QueryWithContextCleanup, SetRunningFlagIfInitialized, StructAllocInitWithSwitchBasedType, AudioMixerSampleGetWithFallback, StringMallocCopy). Class boundaries below are GUESS proposals; several functions keep UNKNOWN owners in the packet and could belong to other objects. Field identities are per base+offset and were not merged across bases without packet support.

## Function roles

- `0x0055DA50` **MeshRenderProcessor** — Per-triangle mesh vertex lighting, normal/specular packing and per-vertex color write into the render output vertex buffer.
- `0x0055EB30` **MeshRenderProcessor** — Per-vertex MMX color blend between source and destination vertex buffers.
- `0x0055EBA0` **MeshRenderProcessor** — Per-vertex billboard reflection texcoord computation via device vtable transforms.
- `0x0055FE70` **RenderingResourceLoader** — Bitmap resource load from archive with raw or processed read and resource-manager registration.
- `0x00560050` **RenderingResourceLoader** — Rendering-composition bitmap load variant gated by the initialization global dword_8B8E28.
- `0x00560340` **RenderingResourceLoader** — Guarded load of three D3D rendering resources plus a finalizer call through the loader vtable at this+0x1100.
- `0x00560C10` **ShadowCascadeViewInitializer** — Recursive shadow-map cascade view creation, naming, projection setup and sibling/child recursion.
- `0x00560FC0` **UIWidgetStateNode** — Raise state flag bit 1 at this+0x24.
- `0x00560FD0` **UIWidgetStateNode** — Clear state flag bit 1 at this+0x24.
- `0x00561620` **SceneGraphTreeNode** — Recursive tree node traversal visiting guarded children then processing the current node.
- `0x00561F80` **NetworkSocketSession** — Socket handle teardown, struct release and WSACleanup.
- `0x00562610` **NetworkSocketSession** — Append a \queryid\ token to the send buffer and transmit it via sendto.
- `0x00562710` **NetworkSocketSession** — Recursive backslash-safe chunked socket send under a 0x546-byte buffer limit.
- `0x00562C50` **NetworkSocketSession** — Network session teardown of the batch sub-object, audio array, sub-object and the session itself.
- `0x00562FE0` **StateValueDispatcher** — Store a value at the object base and dispatch through the per-object callable, returning its result.
- `0x00563160` **NetworkStructAllocator** — Null-guarded network struct allocation and dispatch through a stored callback.
- `0x005631A0` **ParamIndexSearch** — Two-step dispatch deriving an index then searching the note-param space.
- `0x005631D0` **ParamIndexSearch** — Linear search for an element index matching a short field and a derived comparison value.
- `0x00563260` **NetworkConnectionManager** — Network session connection handling: entry lookup/tag/removal, socket array creation, state signal and polling.
- `0x00563A30` **ContextQueryDispatcher** — Query helper computing a value from per-query context and dispatching the result through a stored callable.
- `0x00563DF0` **RunningStateController** — Raise the running flag at this+0x74 when the this+0x00 pointer is initialized.
- `0x005642F0` **NetworkStructAllocator** — Allocate and initialize a 20-byte struct with a type-switched typed array.
- `0x00564580` **AudioMixer** — Resolve an audio mixer sample through double-call indirection with a caller-supplied fallback.
- `0x00564690` **StringBufferAllocator** — Allocate and copy a C string buffer, returning the owned copy.

## Proposed classes

### MeshRenderProcessor

Mesh vertex processing and color generation for rendering: per-triangle lighting, per-vertex MMX color blend and billboard reflection texcoord computation, driven through the device-wrapper vtable at dword_8B8F24.

Methods: `0x0055DA50`, `0x0055EB30`, `0x0055EBA0`

- `this+0x00000000` `unsigned int renderFlags` (read, GUESS)
- `this+0x00000004` `void* materialPtr` (read, GUESS)
- `this+0x00000008` `int vertexCount` (read, GUESS)
- `this+0x0000000C` `void* sourceVertexBuffer` (read, GUESS)
- `this+0x00000010` `int triangleIndexCount` (read, GUESS)
- `this+0x00000014` `unsigned short* indexBuffer` (read, GUESS)
- `this+0x00000018` `void* meshBlockPtr` (read, GUESS)
- `this+0x00000020` `void* destinationVertexBuffer` (read_write, GUESS)
- `this+0x00000068` `float materialColorX` (read, GUESS)
- `this+0x0000006C` `float materialColorY` (read, GUESS)
- `this+0x000000A0` `int lightingModeSelector` (read, GUESS)
- `this+0x00000124` `int meshIndexBaseOffset` (read, GUESS)
- `this+0x00000128` `void* influenceWeightBlockPtr` (read, GUESS)
- `this+0x0000013C` `int vertexStrideSelector` (read, GUESS)
- `this+0x00000154` `int worldTransformOffset` (read, GUESS)
- `*(this+0x128)+0x00000000` `unsigned int weightFlags` (read, GUESS)
- `*(this+0x128)+0x00000010` `float blendWeightR` (read, GUESS)
- `*(this+0x128)+0x00000014` `float blendWeightG` (read, GUESS)
- `*(this+0x128)+0x00000018` `float blendWeightB` (read, GUESS)
- `*(this+0x128)+0x0000001C` `float blendWeightA` (read, GUESS)
- `*(*(this+0x128)+0x0)+0x00000000` `unsigned int vertexFlags` (read, GUESS)
- `*(*(this+0x128)+0x0)+0x00000038` `float vertexPosX` (read, GUESS)
- `*(*(this+0x128)+0x0)+0x0000003C` `float vertexPosY` (read, GUESS)
- `*(*(this+0x128)+0x0)+0x00000040` `float vertexPosZ` (read, GUESS)
- `*(*(this+0x128)+0x0)+0x00000050` `float influenceRadius` (read, GUESS)

### RenderingResourceLoader

Loads bitmap and D3D rendering resources: filename validation, resource-table entry resolution through this+0x128/this+0x124, buffer allocation, raw/processed archive read, and registration into the resource manager global dword_8B78A0 or through the loader vtable at this+0x1100.

Methods: `0x0055FE70`, `0x00560050`, `0x00560340`

- `this+0x00000000` `int loadResult` (write, GUESS)
- `this+0x00000010` `void* archiveFileHandle` (read, GUESS)
- `this+0x00000124` `int resourceIndex` (read, GUESS)
- `this+0x00000128` `void* resourceTablePtr` (read, GUESS)
- `this+0x00001100` `void* loaderObjectPtr` (read, GUESS)
- `this+0x000013D4` `int resourceFeatureFlag` (read, GUESS)
- `*(this+0x1100)+0x000000C8` `void (*)() loadResourceMethod` (read, GUESS)
- `*(this+0x1100)+0x0000012C` `void (*)() finalizeResourceMethod` (read, GUESS)

### ShadowCascadeViewInitializer

Recursively constructs and configures one shadow-map cascade view for directional-light rendering: detects existing cascades through the this+0x18 -> +0x138 -> +0x40 pointer chain, allocates and names a 444-byte view object, sets near/far projection and rotation from the light, allocates a secondary object and a 1024-int array, then recurses into sibling/child views.

Methods: `0x00560C10`

- `this+0x0000000C` `void* constructedViewPtr` (write, GUESS)
- `this+0x00000018` `void* lightDescriptorPtr` (read, GUESS)
- `this+0x0000001C` `void* secondaryObjectPtr` (write, GUESS)
- `this+0x00000020` `void* intArrayPtr` (write, GUESS)
- `this+0x00000024` `unsigned int initFlags` (read_write, GUESS)
- `this+0x00000028` `int viewIndex` (read, GUESS)
- `this+0x0000002C` `void* siblingViewPtr` (read, GUESS)
- `this+0x00000034` `void* childViewPtr` (read, GUESS)
- `*(this+0x18)+0x00000018` `float lightNearPlane` (read, GUESS)
- `*(this+0x18)+0x00000138` `void* cascadeConfigPtr` (read, GUESS)
- `*(*(this+0x18)+0x138)+0x00000040` `void* cascadeViewPtr` (read, GUESS)
- `*(*(*(this+0x18)+0x138)+0x40)+0x00000230` `int cascadeValidityFlag` (read, GUESS)

### UIWidgetStateNode

Holds a state dword at this+0x24 whose bit 1 is raised or lowered by the paired set/clear helpers invoked while the UI widget recursive state update descends the widget tree.

Methods: `0x00560FC0`, `0x00560FD0`

- `this+0x00000024` `unsigned int stateFlags` (read_write, DERIVED)

### SceneGraphTreeNode

Recursive tree node traversal: a skip flag at this+0x3C gates the whole walk, a child pointer at this+0x44 is always recursed when non-null, and a second pointer at this+0x4C is recursed only when both this+0x40 and this+0x4C are non-null, after which the current node is processed.

Methods: `0x00561620`

- `this+0x0000003C` `unsigned char skipFlag` (read, GUESS)
- `this+0x00000040` `void* secondChildGate` (read, GUESS)
- `this+0x00000044` `void* childPtr` (read, GUESS)
- `this+0x0000004C` `void* secondChildPtr` (read, GUESS)

### NetworkSocketSession

Socket session lifecycle and wire transmission: closes and resets the primary/secondary socket handles, frees the session struct unless it is the default singleton, appends \queryid\ tokens and sends buffers over UDP, recursively chunk-sends long strings under a 0x546-byte limit, and tears down sub-objects and arrays.

Methods: `0x00561F80`, `0x00562610`, `0x00562710`, `0x00562C50`

- `this+0x00000000` `int primarySocketHandle` (read_write, GUESS)
- `this+0x00000004` `int secondarySocketHandle` (read_write, GUESS)
- `this+0x00000008` `void* batchSubObjectPtr` (read, GUESS)
- `this+0x00000094` `void* audioArrayPtr` (read, GUESS)
- `this+0x000000D8` `int clearedField` (write, GUESS)
- `this+0x000000E4` `int activeFlag` (read, GUESS)

### NetworkConnectionManager

Network session connection handling: validates the server address, resolves a server entry by ID, tags and removes entries, creates the socket array, signals connection state through the state dispatcher and enters the polling loop.

Methods: `0x00563260`

- `this+0x00000000` `void* socketArrayPtr` (read, GUESS)
- `this+0x00000004` `void* elementArrayPtr` (read, GUESS)
- `this+0x00000008` `void* matchedStructArrayPtr` (read, GUESS)
- `this+0x00000070` `int liveCount` (read_write, GUESS)
- `this+0x00000074` `int runningFlag` (write, GUESS)

### StateValueDispatcher

Stores an incoming value at the object base and dispatches through a per-object callable (function pointer at byte offset 120), passing the captured previous value at byte offset 124 as an argument, and propagates the callable's result.

Methods: `0x00562FE0`


### ParamIndexSearch

Parameter-index lookup: TwoStepDispatch derives an index/limit from the object field at this+0x04 and AudioNoteParamIndexSearchLoop linearly searches an element array for an index whose short field and derived value both match.

Methods: `0x005631A0`, `0x005631D0`

- `this+0x00000004` `void* elementArrayPtr` (read, GUESS)

### NetworkStructAllocator

Allocates and dispatches network structs: ConditionalNetworkUtility null-guards then allocates a struct by the type selector at this+0x94 and dispatches through the callback at this+0x04; StructAllocInitWithSwitchBasedType builds the 20-byte struct header and a type-switched typed array.

Methods: `0x00563160`, `0x005642F0`

- `this+0x00000004` `void (*)() dispatchCallbackPtr` (read, GUESS)
- `this+0x00000094` `int typeSelector` (read, GUESS)

### ContextQueryDispatcher

Query helper: computes a value via sub_564110 using the per-query context at this+0x94, then routes the result through the invocable target held at this+0x04 via the single-function-call wrapper.

Methods: `0x00563A30`

- `this+0x00000004` `void (*)() invocableTargetPtr` (read, GUESS)
- `this+0x00000094` `int contextValue` (read, GUESS)

### RunningStateController

Raises an activity flag at this+0x74 when the sub-object pointer at this+0x00 is non-null, signaling that the network update loop is running.

Methods: `0x00563DF0`

- `this+0x00000000` `void* initializedObjectPtr` (read, GUESS)
- `this+0x00000074` `int runningFlag` (write, GUESS)

### AudioMixer

Resolves an audio-mixer sample object through a double-call indirection and returns the sample stored at element 1 of the resolved object, falling back to a caller-supplied default when the indirection yields null.

Methods: `0x00564580`


### StringBufferAllocator

Allocate-and-copy helper for C strings: allocates strlen+1 bytes and copies the source, returning the owned buffer or NULL on null input or allocation failure.

Methods: `0x00564690`


## Compatibility contracts

- **MeshVertexOutputLayout** — The render output vertex buffer uses a 64-byte stride with a packed color dword at +24, a specular color dword at +28 and reflection texcoord floats at +40/+44; the source vertex buffer uses a 48-byte stride with its color at +24. A nonzero flag at this+0x13C selects the 64-byte format.
- **MMXColorBlendInvariant** — Per-lane byte color blend unpacks source and destination bytes to words with the zero word-mask qword_8B6C20, adds the blend offset qword_8B8E40, multiplies, shifts right by 8, packs back to bytes, and clears MMX state afterwards.
- **BitmapResourceTableEntryLayout** — Resource-table entries expose a data size at entry+8, a second size at entry+12, a flag byte whose bit 0x10 selects a processed (decompressed/transformed) read path, and a filename at entry+20; raw reads must return the exact byte count.
- **SocketTeardownContract** — The primary socket handle is closed only when it differs from -1 and the active flag at +0xE4 is non-zero; the secondary handle only when it differs from both -1 and the primary; both are reset to -1, the field at +0xD8 is zeroed, and the struct is freed unless it is the default singleton at unk_5E4CF8.
- **QueryIdWireToken** — A non-empty send buffer is extended with a \queryid\%d.%d token (built from the stored base id and the incremented per-socket counter), transmitted via sendto over a 16-byte sockaddr, and cleared afterwards.
- **ChunkedSendBufferLimit** — Outbound socket sends are constrained to a 0x546-byte buffer; long tails are split at backslash positions chosen so that even consecutive backslash runs (escaped pairs) are not cut apart.
- **ShadowViewObjectLayout** — A 444-byte shadow view object is constructed, named with the 'SHADOWVIEW%.3d' format, carries a validity flag at +0x230, and has its projection derived from the light near plane and dword_8B8DF4.
- **NetworkEntryTagLayout** — Resolved server entries are tagged by storing a5 at +8 and the literal 9999 into the +6 word, then removed from the element array via ArrayElementRemovalWithShift with the live count decremented.

## Unresolved

- Mesh render descriptor offsets this+0x54, this+0x70, this+0xB8 and this+0x150 are listed as accessed in the fact tables but do not appear in the decompiled bodies; their roles remain unknown.
- Float globals dbl_59E430, flt_59E43C, flt_59E450 and flt_59FEC8 are listed as read but absent from the visible bodies; they are likely constants folded into the numeric code and their roles are unestablished.
- The deterministic guard on mesh this+0xA0 (value less than 0) is interpreted as the selector between the blended per-vertex lighting path and the simple flat pack; that interpretation is derived from skeleton analysis, not proven.
- The two device-wrapper vtable method groups (vtable+0/+4 versus vtable+20/+24) and the exact meaning of the output-buffer +24/+28/+40/+44 slot layout are inferred from use, not from a known struct contract.
- Billboard function fields this[11] (0x2C) and this[84] (0x150) are listed as read but do not appear in the raw body; flt_59E43C and flt_59E450 are likewise absent and likely consumed inside the D3D transforms.
- The shadow packet global dbl_5B8998 is not referenced by the raw body of 0x00560C10; the body uses flt_5DD848, aShadowview3d and dword_8B8DF4 only.
- Semantics of the two word constants qword_8B6C20 and qword_8B8E40 (unpack mask versus fixed-point blend offset) are interpreted from the MMX idiom, not from a labeled source.
- The 0x546 byte limit and the 1350-character scan window in the chunked send are structural wire limits whose packet-level meaning (likely a wire-packet size cap) is not established.
- The resource-table entry layout (flag bit 0x10 semantics, filename at entry+20) and sub_59B260 post-processing semantics are not further evidenced by this packet.
- The WSACleanup thunk is invoked at return in SocketCloseAndCleanup and NetworkCleanup but has no callee evidence entry, so its address is not recorded.
- AudioValueSetterCall's fixed indirect-call arguments (1, 0, 0) and the role of the byte-offset-124 previous value are not established; its dispatcher object is unknown.
- The literal 9999 stored into the +6 word of network entries and the value 3 passed to AudioValueSetterCall by NetworkConnection have unestablished semantics.
- NetworkConnection's a1 indices (0, 1, 2, 28, 29, 38) and sub-fields (+8, +6, +28*v12+4) are read directly from the decompiled body with no packet field evidence; a1[38] (the display-mode query counter) has no allowed field evidence ref and is therefore not expressed as a class field; the class merge of its this+0x74 running flag with RunningStateController's is a GUESS.
- The element array element type, the semantics of sub_563E70, and the interpolation semantics of LinearInterpolation (0x005648B0) are not defined in the packet; the equality match criteria cannot be interpreted beyond the equality test.
- StructAllocInitWithSwitchBasedType stores the constant 9999 at offset +6 and switches element count by type selector (0-3 gives 2, default gives 4); the type selector meaning is undocumented.
- All class boundaries in this proposal are GUESS: the packet assigns DERIVED owners only to ShadowCascadeViewInitializer and AudioMixer and UNKNOWN to every other function.
- StateValueDispatcher byte offsets 120/124 and StringMallocCopy/AudioMixer internals are described in packet text but carry no allowed field evidence refs, so no class field entries were made for them.
