# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

DERIVED grouping of 21 validated IR functions around a few runtime object families. (1) Texture-atlas allocation (0x00540940) draws rectangular regions from sorted horizontal/vertical free-space lists, allocating 36-byte and 28-byte region nodes via OperatorNewNhMallocWrapper and validating placements through 0x00540DF0 / 0x00540FC0. (2) An audio-emitter family (0x005426A0 / 0x00542E50) plus a texture-surface-set creator (0x005429B0), a two-phase stream allocator with fallback emitters (0x00543A80), and a sound-manager instance-list updater (0x00541810) all route through the global dword_8B78A0. (3) A graphics/resource object acquires buffer and surface-blit locks by flag bits (0x00540D40), with two mirror release helpers (0x00540F90 / 0x005410F0) invoking a virtual method at vtable offset +48. (4) Camera projection/view updates (0x00541B70), a bit-3 flag setter on this+0x80 (0x00541CA0), a rect-clip helper (0x00543540), and a constructor-style initializer (0x005418B0). (5) Bitmap location/loading (0x005427D0 / 0x00543050 / 0x00543130) and an argument-reordering dispatch wrapper (0x00543230). (6) Scene-graph helpers: node release (0x005437E0) and recursive activity check (0x00544E20), plus shadow-texture resource management (0x00544740) which tears down the dword_8B78A0 sub-buffer via 0x00541420. Owners are almost entirely UNKNOWN in the packet; AudioEmitter is the only DERIVED named owner. Contradiction kept explicit: dword_8B78A0 is labeled SoundManager in existing fills (DERIVED) yet is used as the rendering/resource context for surface, composition and bitmap calls, so it is modeled both as the SoundManager class base and as a RenderResourceContext interface.

## Function roles

- `0x00540940` **TextureAtlasAllocator** — Allocates rectangular regions in a texture atlas from sorted horizontal/vertical free-space lists: allocates 36-byte horizontal and 28-byte vertical region nodes via OperatorNewNhMallocWrapper, links them into doubly-linked lists keyed by remaining space, consumes space on fit, and reports aErrorCreatingV through 0x0053C590 with return -1 on validation failure; returns 0 on success.
- `0x00540D40` **SurfaceLockOwner** — Flag-driven lock acquisition on a graphics/resource object: when a2 bit 4 is set allocates a buffer lock via 0x00540F00(a1[7], a2, a1[11], a1[2]) stored at a1[8]; when a2 bit 8 is set allocates a surface blit lock via 0x00541090(a1[9], a2, a1[12], a1[4]) stored at a1[10]; the two branches are independent; no-op when a1 is null.
- `0x00540F90` **LockReleaseHelper** — Release helper: when a2 and the object pointer at a2+32 are non-null, invokes the virtual __stdcall method at vtable offset +48, stores the return into *this, and decrements the counter at a2+20 when the return is zero.
- `0x005410F0` **LockReleaseHelper** — Release helper mirror of 0x00540F90: when a2 and the object pointer at a2+24 are non-null, invokes the virtual __stdcall method at vtable offset +48, stores the return into *this, and decrements the counter at a2+12 when the return is zero.
- `0x00541420` **SubBufferOwner** — Frees the sub-buffer descriptor at this+0x114C: resets the base allocation and base+36 via 0x00540EB0, frees the descriptor memory via FreeWrapper_7bcf at pointer-minus-4, and nulls the field; returns the last freed or read pointer. Shared teardown for 0x00544740 and 0x00544AF0.
- `0x00541810` **SoundManager** — Updates the sound instance ID list of a sound-manager object: when flag this+0x13D8 is non-zero, clears every existing instance (count this+0x155C, array this+0x1560) via the vtable method at *(this+0x1100)+0xB8 with flag 0, then repopulates the array from a 56-byte-strided source (IDs at *(*(a3))+4) using the same vtable method with flag 1; returns the new instance count.
- `0x005418B0` **UnknownObject** — Constructor-style initializer: calls GlobalZeroInit_c2a0 to zero the whole object, then explicitly re-zeroes dwords at 0x80, 0x19C, 0x1B4 and 0x1B8 before returning this. Callers span unrelated subsystems so the owning object type is unknown.
- `0x00541B70` **Camera** — Builds camera projection (orthographic when a2 bit 0x10 set, perspective otherwise) and view matrices gated by a2 bits (4=projection, 2=view, 8=additional sub_55CC20 update): reads near/far planes (this+4, this+8), fov (this+28), aspect (this+32) and a flag byte at this+128, and uploads matrices through EnumToVTableCallMapper (0x0055CA40).
- `0x00541CA0` **RenderStateFlags** — Flag setter that sets or clears bit 3 (0x8) of the dword at this+0x80 based on boolean a2, stores the updated value back and returns it; invoked on render, scene-loading and subsystem-init paths.
- `0x005426A0` **AudioEmitter** — Constructor-style initializer for an audio emitter: zero-initializes via GlobalZeroInit_c2a0, explicitly clears fourteen dwords at offsets 0x0..0x34, sets non-zero defaults this[11]=1 (0x2C) and this[12]=6 (0x30), and returns this.
- `0x005427D0` **BitmapResourceLoader** — Searches for a bitmap file on behalf of texture creation: copies and normalizes the path (truncating to 0x300 bytes), tests it directly via 0x00543130, then each registered data-directory entry (byte_8B5A3C, stride 132, dword_8B8E30) formatted with a %s path, and finally an object linked list headed by dword_8B8F14 via 0x0055FE70; when the found count differs from dword_8B6AC0 it logs 'Could not locate bitmap file %s' through 0x0053C590 and returns -1.
- `0x005429B0` **TextureSurfaceSet** — Creates a texture surface set on this from an audio-emitter-backed source using the global context dword_8B78A0: gated on (a6 & 0xF), allocates and configures primary/secondary AudioEmitter objects, binds bitmap or stream sources, registers them with the sound manager, generates MIP-level filenames, and creates one DirectX surface per set channel mode via 0x0053FD40; returns 0 on success and -1 after cleanup on every failure path.
- `0x00542E50` **AudioEmitter** — Destructor/reset path for an audio emitter: unregisters from the global context dword_8B78A0 via 0x0053FB80 (logging 'Error deallocating' through 0x0053C590 and returning -1 on failure), drains and frees the buffer at field 0x4, zeroes all state fields, resets the mode field 0x30 to 6 and returns 0.
- `0x00543050` **BitmapResourceLoader** — Loads a bitmap file into a freshly allocated buffer and hands the raw bytes to RenderingCompositionSetup (0x0053FED0) on the global context dword_8B78A0; returns 0 on success, -1 on setup failure, and -2 with 'Error opening bitmap file %s' logged through 0x0053C590 when the file cannot be opened.
- `0x00543130` **BitmapResourceLoader** — Structural twin of BitmapFileLoader: loads a file into an allocated buffer and hands it to ResourceLoadWithOutput (0x00540050) on the global context dword_8B78A0 where a2/a3/a4 are output parameters; returns 0 on success, -1 on load failure, and -2 with 'Error opening bitmap file %s' through 0x0053C590 when the file cannot be opened.
- `0x00543230` **BitmaskDispatcher** — Argument-reordering wrapper: forwards this (as int) and a3/a2 swapped to BitmaskVirtualDispatch (0x00540150) and returns the dispatch result unchanged; the global dword_8B78A0 is read somewhere in the dispatch path but not in this function's visible body.
- `0x00543540` **RectClipOwner** — Thiscall rectangle-clipping helper: clips two coordinate/extent pairs (a2 with a4, a3 with a5) against surface bounds read from this+0x1C and this+0x20, folding negative coordinates into extents and clamping so coordinate plus extent stays within the bound; returns a5.
- `0x005437E0` **SceneNode** — Releases a scene-graph node: unconditionally calls 0x0053CAF0 on the child-node pointer at this+0x110, then calls the no-op stub; called from MutexSemaphoreCleanup (0x005461B0).
- `0x00543A80` **AudioStreamAllocator** — Two-phase audio emitter allocation with fallback: when flag this+0xEC bit 0x4 is clear, allocates and registers two 60-byte AudioEmitter objects into globals dword_8B8DBC/dword_8B8DC0 via 0x00542950, runs primary stream init via 0x0055B6B0, retaining the fallbacks (OR bit 0x10800 into this+0xEC) when primary init fails or releasing them when it succeeds.
- `0x00544740` **ShadowTextureResourceAllocator** — Manages the lifecycle of a shadow-texture resource array on this: gated by flag bit 0x100000 of this+0xEC (must be clear) and a positive requested count at this+0x158, destroys existing 96-byte items (count this+0x160, array this+0x164) before reallocation, names each item SHADOWTEXnnn, creates its surface via 0x00542950, submits the array via 0x00547860, then drains two dependent-object priority queues (heads this+0x100, this+0x108) and a flag-check list (head this+0x148); also tears down the dword_8B78A0 sub-buffer via 0x00541420.
- `0x00544E20` **SceneNode** — Recursive tree-activity check: recurses on child pointers at this+0x44 and (gated by flag a2) this+0x4C, walks a sibling list headed at this+0x204 following the next pointer at node+0x10, and returns -1 when a sibling node satisfies SceneNodeChildrenClear (0x0054D030) or a recursion reports true; returns 0 when the list is exhausted.

## Proposed classes

### TextureAtlasAllocator

Allocates rectangular regions in a texture atlas from sorted horizontal/vertical free-space lists; keeps list heads, a secondary dimension, a request anchor and an allocator-enabled flag. Node layout ownership is ambiguous so region-node fields are modeled on the deterministic derived bases.

Methods: `0x00540940`

- `this+0x00001150` `AtlasFreeListNode* horizontalFreeListHeadDefault` (read, GUESS)
- `this+0x00001154` `AtlasFreeListNode* horizontalFreeListHead` (read_write, GUESS)
- `this+0x00001158` `AtlasFreeListNode* horizontalFreeListHeadAlternate` (read, GUESS)
- `this+0x00001160` `int secondaryDimension` (read, GUESS)
- `this+0x00001164` `AtlasFreeListNode* verticalFreeListHead` (read_write, GUESS)
- `this+0x0000118C` `void* requestAnchor` (read_write, GUESS)
- `this+0x000013DC` `int allocatorEnabledFlag` (read, GUESS)

### AtlasFreeListNode

Free-space region node used by the atlas allocator's horizontal/vertical lists: carries next/back links, a bound, a current offset and a region id. Layout is ambiguous from the packet; offsets are kept on the deterministic base *(this+0x1154) as GUESS.

Methods: 

- `*(this+0x1154)+0x0000001C` `void* listHeadNextLink` (read, GUESS)
- `*(this+0x1154)+0x00000028` `void* verticalNodeNextLinkA` (read, GUESS)
- `*(this+0x1154)+0x0000002C` `void* verticalNodeNextLinkB` (read, GUESS)
- `*(this+0x1154)+0x00000038` `void* verticalNodeNextLinkC` (read, GUESS)
- `*(this+0x1154)+0x00000054` `int nodeBound` (read_write, GUESS)
- `*(this+0x1154)+0x00000058` `void* tailBackLink` (read_write, GUESS)
- `*(this+0x1154)+0x0000005C` `void* tailForwardLink` (read_write, GUESS)
- `*(this+0x1154)+0x00000060` `int currentOffset` (read_write, GUESS)
- `*(this+0x1154)+0x00000064` `int regionId` (read_write, GUESS)
- `*(this+0x1154)+0x00000074` `void* nodeNextLink` (read, GUESS)

### AtlasRequestNode

Request-side region node anchored through *(this+0x118C)+0x14: carries flags, a width and a height for the requested atlas region plus a next link. Base is the deterministic derived anchor; the packet does not prove this is the same type as the free-list nodes.

Methods: 

- `*(*(this+0x118C)+0x14)+0x00000000` `int flags` (write, GUESS)
- `*(*(this+0x118C)+0x14)+0x00000004` `int width` (write, GUESS)
- `*(*(this+0x118C)+0x14)+0x00000008` `int height` (write, GUESS)
- `*(*(this+0x118C)+0x14)+0x00000018` `void* nextLink` (read, GUESS)

### AudioEmitter

Audio emitter object: constructed via GlobalZeroInit with a non-zero default on 0x2C and a mode default of 6 on 0x30; on teardown it unregisters from the global context dword_8B78A0, drains/frees its buffer at 0x4 and zeroes its state fields. The only named DERIVED owner in the packet.

Methods: `0x005426A0`, `0x00542E50`

- `this+0x00000000` `int flags` (read_write, GUESS)
- `this+0x00000004` `void* buffer` (read_write, GUESS)
- `this+0x00000008` `int stateField` (read_write, GUESS)
- `this+0x0000000C` `int stateField` (read_write, GUESS)
- `this+0x00000010` `int stateField` (read_write, GUESS)
- `this+0x00000014` `int stateField` (read_write, GUESS)
- `this+0x00000018` `int stateField` (read_write, GUESS)
- `this+0x0000001C` `int stateField` (read_write, GUESS)
- `this+0x00000020` `int stateField` (read_write, GUESS)
- `this+0x00000024` `int stateField` (read_write, GUESS)
- `this+0x00000028` `int stateField` (read_write, GUESS)
- `this+0x0000002C` `int defaultOnValue` (read_write, GUESS)
- `this+0x00000030` `int mode` (read_write, GUESS)
- `this+0x00000034` `int stateField` (read_write, GUESS)

### SoundManager

Sound-manager object owning a sound engine pointer (this+0x1100), an instance-update enable flag (this+0x13D8), and an instance-count / instance-ID-array pair (this+0x155C / this+0x1560); updates its instance list through a vtable method at *(this+0x1100)+0xB8. The identity of this object with the global dword_8B78A0 is not proven; the packet only anchors instance-list behavior here.

Methods: `0x00541810`

- `this+0x00000000` `int lastCallResult` (write, GUESS)
- `this+0x00001100` `void* soundEngine` (read, GUESS)
- `this+0x000013D8` `int instanceUpdateEnabled` (read, GUESS)
- `this+0x0000155C` `int instanceCount` (read_write, GUESS)
- `this+0x00001560` `int* instanceIdArray` (read_write, GUESS)

### Camera

Camera object with near/far planes, field of view, aspect and a flag byte; builds projection (orthographic/perspective) and view matrices and uploads them through the matrix upload dispatcher. The view matrix read at this+348 is described by the packet but carries no field evidence ref, so no field entry is made for it.

Methods: `0x00541B70`

- `this+0x00000004` `float nearPlane` (read, GUESS)
- `this+0x00000008` `float farPlane` (read, GUESS)
- `this+0x0000001C` `float fieldOfView` (read, GUESS)
- `this+0x00000020` `float aspectRatio` (read, GUESS)
- `this+0x00000080` `int cameraFlags` (read, GUESS)

### RenderStateFlags

Object exposing a bitmask flag field at this+0x80 whose bit 3 is toggled by callers across render, scene-loading and subsystem-init paths. The offset 0x80 is shared with the Camera flag byte but common ownership is not proven, so this is modeled separately.

Methods: `0x00541CA0`

- `this+0x00000080` `int flags` (read_write, GUESS)

### SurfaceLockOwner

Graphics/resource object holding a buffer pointer, a surface pointer, lock control/sizing fields and the lock-result slots; acquires buffer and surface-blit locks based on flag bits of the requested mask.

Methods: `0x00540D40`

- `this+0x00000008` `void* buffer` (read, GUESS)
- `this+0x00000010` `void* surface` (read, GUESS)
- `this+0x0000001C` `int bufferLockControl` (read, GUESS)
- `this+0x00000020` `void* bufferLock` (write, GUESS)
- `this+0x00000024` `int surfaceBlitControl` (read, GUESS)
- `this+0x00000028` `void* surfaceBlitLock` (write, GUESS)
- `this+0x0000002C` `int bufferLockSizing` (read, GUESS)
- `this+0x00000030` `int surfaceBlitSizing` (read, GUESS)

### LockReleaseHelper

Release helpers that invoke a virtual __stdcall method at vtable offset +48 on a wrapped object and decrement a counter when it returns zero, storing the return into the caller's result slot. The two variants differ in wrapped-object offset (+32 and counter +20 versus +24 and counter +12) so their a2 layouts are treated as distinct.

Methods: `0x00540F90`, `0x005410F0`

- `this+0x00000000` `int resultSlot` (write, GUESS)

### SubBufferOwner

Object carrying a sub-buffer descriptor at this+0x114C; SubBufferFree resets its base allocation and base+36 then frees the descriptor memory and nulls the field. Called with the global context dword_8B78A0 as this, suggesting the global itself owns a sub-buffer.

Methods: `0x00541420`

- `this+0x0000114C` `void* subBuffer` (read_write, GUESS)

### BitmapResourceLoader

Locates and loads bitmap files: normalizes and tests candidate paths across data directories and a global object list, loads file bytes into allocated buffers, and hands them to rendering-composition or resource-load consumers; shares the 'Error opening bitmap file %s' and 'Could not locate bitmap file %s' diagnostic paths through the error reporter.

Methods: `0x005427D0`, `0x00543050`, `0x00543130`


### TextureSurfaceSet

Texture surface set created from an audio-emitter-backed source: commits flags (this+0x18), dimensions (this+0x1C, this+0x20), MIP count (this+0x2C) and an audio source field (this+0x34), and drives per-channel DirectX surface creation. Field roles are DERIVED from usage only.

Methods: `0x005429B0`

- `this+0x00000018` `int flags` (read_write, DERIVED)
- `this+0x0000001C` `int width` (read_write, DERIVED)
- `this+0x00000020` `int height` (read_write, DERIVED)
- `this+0x0000002C` `int mipCount` (read_write, DERIVED)
- `this+0x00000034` `int audioSourceField` (read, DERIVED)

### BitmaskDispatcher

Thin argument-reordering dispatcher that forwards to BitmaskVirtualDispatch (0x00540150); the wrapper swaps its second and third parameters before dispatch.

Methods: `0x00543230`


### RectClipOwner

Object exposing surface bounds (width this+0x1C, height this+0x20) used to clip rectangle coordinates/extents; roles carried over from existing fills as DERIVED, not independently proven.

Methods: `0x00543540`

- `this+0x0000001C` `int width` (read, GUESS)
- `this+0x00000020` `int height` (read, GUESS)

### SceneNode

Scene-graph node with child pointers (this+0x44, this+0x4C), a released child-node pointer (this+0x110), and a sibling list headed at this+0x204 whose nodes carry a next pointer at +0x10. Grouping the release function and the activity check into one class is structural inference, not proven common ownership.

Methods: `0x005437E0`, `0x00544E20`

- `this+0x00000044` `SceneNode* childA` (read, GUESS)
- `this+0x0000004C` `SceneNode* childB` (read, GUESS)
- `this+0x00000110` `void* childNode` (read, GUESS)
- `this+0x00000204` `void* siblingListHead` (read, GUESS)
- `*(this+0x214)+0x00000010` `void* siblingNext` (read, GUESS)

### AudioStreamAllocator

Allocates audio emitter streams with a fallback pair of globally-held emitters (dword_8B8DBC/dword_8B8DC0), gated by flag bits of this+0xEC; retains the fallbacks when primary stream initialization fails.

Methods: `0x00543A80`

- `this+0x000000EC` `int flags` (read_write, GUESS)

### ShadowTextureResourceAllocator

Manages a shadow-texture resource array on this: gated by flag bit 0x100000 of this+0xEC and the requested count at this+0x158, allocates 96-byte items with a count header, names and creates their surfaces, submits them to the renderer, and drains two dependent-object priority queues and a flag-check list.

Methods: `0x00544740`

- `this+0x000000EC` `int flags` (read_write, DERIVED)
- `this+0x00000100` `void* priorityQueueListA` (read, GUESS)
- `this+0x00000108` `void* priorityQueueListB` (read, GUESS)
- `this+0x00000148` `void* flagCheckList` (read, GUESS)
- `this+0x00000158` `int requestedCount` (read, GUESS)
- `this+0x00000160` `int itemCount` (read_write, GUESS)
- `this+0x00000164` `void* itemArray` (read_write, GUESS)

## Compatibility contracts

- **TextureAllocationErrorConvention** — Texture and resource creation returns 0 on success and -1 on any allocation, file, registration or surface-creation failure; bitmap loaders additionally return -2 when the file cannot be opened, after logging 'Error opening bitmap file %s' (string 0x005DBDEC) through the error reporter 0x0053C590. A replacement must preserve these distinct failure codes.
- **AtlasAllocationContract** — Texture-atlas allocation allocates regions from horizontal and vertical free-space lists and validates placements with 0x00540DF0 / 0x00540FC0; when a placement validation fails the allocator reports the aErrorCreatingV message (string 0x005DBD40) through the error reporter and returns -1, otherwise 0.
- **SoundInstanceListContract** — Sound-manager instance lists are updated by clearing all existing entries (vtable method at *(this+0x1100)+0xB8 with mode flag 0) and repopulating from a 56-byte-strided source taking each ID at +4 (mode flag 1); the instance count lives at this+0x155C and the ID array at this+0x1560, gated by the flag at this+0x13D8.
- **LockReleaseContract** — Release helpers call a virtual __stdcall method at vtable offset +48 on a wrapped object; when the call returns zero the owning counter is decremented (a2+20 in the buffer variant, a2+12 in the guarded variant) and the call result is stored into the caller's result slot at this+0.
- **ShadowResourceGateContract** — Shadow-texture array allocation is gated by flag bit 0x100000 of this+0xEC (clear to allocate, set marks resources loaded) and by a positive requested count at this+0x158; the loaded flag and item count at this+0x160 are committed together after successful array submission.

## Unresolved

- Read-only allocator fields at this+0x1178, this+0x117C and this+0x1180 are not referenced by any visible decompiled body; their role in the atlas allocator/request object is unknown.
- The exact atlas node layout (which offsets belong to the horizontal 36-byte node versus the vertical 28-byte node versus the list heads) is ambiguous; the deterministic bases *(*(this+0x118C)+0x14) and *(this+0x1154) were kept as-is and modeled as separate GUESS classes.
- The meaning of the flag bits in the lock-acquisition mask (4 = buffer lock, 8 = surface blit lock) and of the other bits of a2 is not documented in the packet.
- The vtable method at offset +48 invoked by 0x00540F90 and 0x005410F0 has no concrete address; the two helpers also use different wrapped-object layouts (+32/counter+20 versus +24/counter+12) so their a2 structures are treated as distinct even though the helpers are mirror twins.
- Four dereferenced-field facts from the deterministic store are not visible in the raw decompiled body of 0x00544740: *(*(this+0x1EC)+0x4C), *(this+0x154)+0x4C, *(this+0x1B0)+0x68 and *(this+0x204)+0x104. The last resembles the +104 next-pointer walk of the flag-check list, but its base (this+0x204) differs from the list head at this+0x148, so it is not assigned to an operation.
- The identity of the global context dword_8B78A0 is contested: existing fills label it SoundManager (DERIVED), yet it is passed as the rendering/resource context to surface, composition, resource-loading and sound calls and carries the sub-buffer descriptor freed by 0x00541420. It is modeled both as the SoundManager class base and as a RenderResourceContext interface; this contradiction is not resolved by the packet.
- Globals 0x0059E420 (double 1.0), 0x008B78A0 and 0x008B8F24 are read by 0x00541B70 per the fact table, but the read sites are not visible in the Hex-Rays pseudocode.
- The Camera view matrix read at this + 348 is described by the packet summary but carries no field evidence reference, so no class field entry is made for it.
- The owning object of 0x005418B0 (constructor initializer) is unknown; its four caller addresses span unrelated subsystems and the semantic role of the four re-zeroed fields beyond GlobalZeroInit is not established.
- 0x00543540 parameter roles (which of a2/a3/a4/a5 are x/y/width/height and which pair is source versus destination) and its unusual returning of a5 while using it as an output pointer are not established.
- The 0x00541CA0 bit-3 flag and the Camera flag byte both live at this+0x80 but common ownership is not proven; they are modeled as separate classes (RenderStateFlags vs Camera).
- The shared this+0xEC flag field used by 0x00543A80 (bits 0x4, 0x10800) and 0x00544740 (bit 0x100000) suggests a possible common owner with multiple flag bits, but the packet does not prove it; they are kept in separate classes.
- The trigger for allocating the fallback emitters (this+0xEC bit 0x4) is read by 0x00543A80 but its writers are outside the function; both fallback emitters are registered with the same parameter set (dword_8B8DF4 twice, dword_8B8DF8, constant 262152).
- The object linked list headed by dword_8B8F14 walked by 0x005427D0 and the exact roles of its a2/a3/a4 parameters and the expected count dword_8B6AC0 are not established.
- The role of the count-header/pointer-minus-4 free base in the sub-buffer descriptor (0x00541420) and what the two ObjectResetWithVirtualRelease targets at +0 and +36 represent are inferred only from the sibling call pattern.
- EmptyStub_0170 invoked by 0x005437E0 is referenced only by name in the raw source; the packet records no address for it. The concrete contract of 0x0053CAF0 (refcount decrement versus free) is not established.
- The exact matrix-element semantics of the D3D projection convention (row versus column major) are not resolved from the packet alone.
- The success/failure convention of 0x005429B0 (0 on success, -1 on error) is observed only locally and is not corroborated by caller context in this packet.
- The v8/v10 emitter object layout used by 0x005429B0 (flag dword at index 6, stream/connect fields at indices 7, 8, 11, 12) is not a packet field; the per-bit meanings of the a6 flags (0x800, 0x800000, 0x4000, 0x1000000) are inferred from usage rather than evidenced.
