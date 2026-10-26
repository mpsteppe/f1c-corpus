# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

Proposal for the generic_runtime_objects_04 packet (23 functions). Central motif is a 12-byte linked-list node {data+0, next+4, flag+8} whose data blocks are 28-byte session-config objects (SessionConfigDefaultInit at 0x00432CC0; owned sub-allocations at +0, +8, +0x14). AutoLoadEntryListLoader (0x00432E70) rebuilds such a list from a config file, ConfigFileParser (0x004330D0) serializes it back, DualLinkedListCleanup (0x004331A0) tears down an object owning two such lists, DoublyLinkedListAppend (0x00434030) is a generic head/tail/count append, and RecursiveNodeDeletion (0x00434240) frees a node plus its data block. A second coherent cluster is the hardware-input subsystem: HWInput_Enter/Setup/Init/Restart/Post/Exit (0x00455BF0..0x00455F00) plus CursorResourceCleanup (0x0044F5F0). SceneTrackFileLoader (0x0044C0E0) reloads track terrain and rebuilds collision geometry. Text rendering helpers are IDToColorMaskMapper (0x0045BB60), StringCopyWithFormatQuery (0x0045BC50) and TextLineWrappingAndRendering (0x0045BD10). Several functions (PathStringModifier, SafeStringCopy, CameraViewportConfigBatch, RegisterRendererObject, AudioRendererFloatConstantInitializer, DestructorWithResourceCleanup) have no provable owner and are left unresolved or assigned GUESS owners. All groupings are DERIVED; ownership of most `this` pointers is UNKNOWN.

## Function roles

- `0x00432E70` **AutoLoadEntryList** — Loads the auto-load session-config entry list from the config file path at byte_7CE498: frees the existing node list (destroying physics objects for flagged nodes), resets head/tail/first/count, builds a physics file path, reads lines, filters via sub_5651B0/sub_588410, wraps accepted 28-byte session-config objects in 12-byte nodes, appends to the list, and sets the this+0x18 completion flag.
- `0x004330D0` **AutoLoadEntryList** — Serializes the auto-load entry linked list to the physics config file: builds the file path via PhysicsFilePathBuild (guard), opens the file, walks nodes from this+0x1C through node+4 next pointers writing each via AutoLoadEntryWriter, then closes and performs conditional cleanup.
- `0x004331A0` **DualLinkedListOwner** — Teardown for an object owning two linked lists: flushes a global string buffer, then walks and frees every node of the first list (this+0x1C; reinit + free session-config data blocks) and of the second list (this+0x30), zeroing all list bookkeeping on exit. Called from PhysicsShutdown and TextFileReader.
- `0x00433370` **Unknown** — Runs directory-path extraction/comparison on this+0x8; when global byte_7C56C0 is set and room remains, appends the word_5C406C marker to the path and sets the a4 modified flag to 1, else 0. Returns the a4 pointer.
- `0x004336D0` **Unknown** — Safe bounded string copy wrapper: copies at most a3 bytes via sub_587DD0, forces a null terminator at a1+a3, returns the callee result. Used by the AI settings file loader and session config builder.
- `0x00434030` **GenericLinkedList** — Appends a node to a head/tail/count linked list: allocates a 12-byte node, stores the data pointer and flag byte, links after the tail (or as first node), updates tail and count, returns 1; returns 0 on a null data argument.
- `0x00434240` **LinkedListNode** — Destroys a node and its owned session-config data struct: when the node flag at +8 is set and data at +0 is non-null, resets via SessionConfigDefaultInit, frees owned pointer fields at +0/+8/+0x14, frees the data struct and node; returns the flag byte.
- `0x00434D40` **ConstraintSolverParams** — RAII-style cleanup of a heap-allocated polymorphic sub-object held at this+0xC: dispatches its first vtable method with argument 1 (interpreted as destructor/delete), clears the pointer, returns 0. Called from ConstraintSolverParamInit and sub_4348B0.
- `0x0044C0E0` **SceneTrackTerrain** — Loads and rebuilds the track scene/terrain: builds a weather-dependent path buffer ('.hat' + track basename + '^' + '.scn'), queries registry timestamps to detect a newer source, and when newer or when byte_7CFEE8 (weather mode) is set loads terrain via HTreeTerrainFileFormatLoader and rebuilds collision geometry (CollisionShapeInit, CollisionGeometryOperationSelector, bounding boxes, sub_44BC50, grid raycast). Frees the temp path buffer on exit.
- `0x0044CC94` **Unknown** — Initializes two adjacent audio-renderer constants: writes -1082130432 to dword_7CC9C4 and 0.0 to flt_7CC9C8. No branches, calls, or arguments.
- `0x0044D3D0` **Unknown** — Trivial render-subsystem registration helper: reads the address of no-op nullsub_72 at 0x0044D3E0 and passes it to BooleanToIntConversion, returning the coercion result.
- `0x0044F5F0` **CursorManager** — Cursor resource teardown: clears the active cursor via SetCursor(0), destroys six handle slots at this+0x30 (20-byte stride) via DestroyCursor, resets count/index at this+0xA8, returns the last handle. Called from HWInputExit and sub_4963D0.
- `0x00453560` **Unknown** — Batches collision-node property configuration: issues about 57 CollisionNodePropertySetter calls assigning modes 0/1/2 to node identifiers, then walks a 44-entry array of 11-dword records starting at this+1736 dispatching each through ConditionalCollisionDispatch; returns the last dispatch result.
- `0x00455BF0` **HWInputManager** — HWInput game-state enter hook: debug log, cursor/timing setup via sub_44F4E0, cursor hide, input action registration, and dual-source device acquire at this+6928 when render flag byte_7D13A0 equals 1. Returns 0.
- `0x00455C60` **HWInputManager** — Hardware input setup: logs entry when session type dword_7C569C != 5, creates a DirectInput8 interface, then on success builds/re-initializes input sub-device slots in the ppvOut array (window surface plus slots 866 and 1121, each initialized, destroyed and re-initialized). Returns the final global-state initializer result or the HRESULT on failure.
- `0x00455D50` **HWInputManager** — Initializes HWInput state: logs entry unless session type is 5, calls an audio scene update, initializes global state with enum defaults, and returns the result of a camera viewport configuration batch.
- `0x00455DA0` **HWInputManager** — Restart routine for the HWInput object: conditional debug log, frustum viewport setup at this+0xCBC from dword_5D6D60/dword_5D6D64, BVH tree-node array init at this+4, optional audio re-init at this+0x1580, clears active flag this+0x2428, scans the device array at this+0x1F98 (11-DWORD stride) for an entry whose second DWORD differs from 89, and sets the active flag when found. Invoked by Game_Restart.
- `0x00455E70` **HWInputManager** — HWInput post-frame teardown hook: optional debug log, fills collision data, destructs the array at a1+1376 when the a1[1637] flag is set, destructs collision objects at a1+1121 and a1+866, cleans up collision culling, and releases the DirectInput-style device interface behind *a1 via its vtable+8 Release, clearing the pointer.
- `0x00455F00` **HWInputManager** — Hardware-input subsystem teardown: debug log, destructs two collision objects (this+1121 and this+866), cleans up cursor resources (this+815) and collision culling (this+1), releases the DirectInput device via its vtable Release and clears the stored pointer, then when render flag byte_7D13A0 is 1 unloads the input module and marks this+0x1B10 as -1.
- `0x0045B400` **RenderResourceObject** — Object destructor: restores the vtable pointer at this+0x0 to the off_59F080 table, cleans up the sub-object at this+0x4, frees the heap allocation at this+0x2C when non-null, then performs resource cleanup on the sub-object and returns its result.
- `0x0045BB60` **TextRenderHelper** — Maps a small identifier (1 or 2) to a 32-bit color mask constant (-65536 and -256); any other value returns the default mask -1. Called by TextLineWrappingAndRendering on the frame path.
- `0x0045BC50` **TextRenderHelper** — Builds a formatted string plus an appended suffix into a bounded destination: formats a1 into a 512-byte scratch via StringFormatWrapper, appends suffix a2, bounded-copies a4-1 bytes into a3 via sub_587DD0 and forces a terminator at a3[a4-1], returning 1; on an empty suffix clears a3 and returns 0.
- `0x0045BD10` **TextRenderHelper** — Renders a text line with word wrap onto an output context: special color marker 16909060 is mapped via IDToColorMaskMapper; 79-character segments are cut at the last space boundary after position 40 and rendered via UtilityFunction_b9c0, then the remaining text; rendering is skipped when the width parameter exceeds the global bound dword_7D02E4.

## Proposed classes

### AutoLoadEntryList

Owns the auto-load session-config entry linked list and its config-file load/serialize pair. Nodes are 12-byte entries {data, next, flag}; data blocks are 28-byte session-config objects. Completion flag at +0x18 distinguishes a finished load.

Methods: `0x00432E70`, `0x004330D0`

- `this+0x00000018` `int32 completionFlag` (write, DERIVED)
- `this+0x0000001C` `LinkedListNode* head` (read_write, DERIVED)
- `this+0x00000020` `LinkedListNode* tail` (read_write, DERIVED)
- `this+0x00000024` `LinkedListNode* first` (read_write, DERIVED)
- `this+0x00000028` `int32 count` (read_write, DERIVED)

### LinkedListNode

12-byte singly-linked-list node carrying a data pointer, a next pointer and a flag byte. Shared node layout used by the auto-load list, the dual-list cleanup walk, the generic append and the recursive node deletion.

Methods: `0x00434240`

- `this+0x00000000` `void* data` (read_write, DERIVED)
- `this+0x00000004` `LinkedListNode* next` (read_write, DERIVED)
- `this+0x00000008` `uint8 flag` (read_write, DERIVED)

### SessionConfigEntry

28-byte session-config object stored as the data block of auto-load list nodes. Owns three optional pointer fields at +0, +8 and +0x14 that must be freed before the block itself. Reset via SessionConfigDefaultInit.

Methods: 

- `obj+0x00000000` `void* leadingPointer` (read_write, DERIVED)
- `obj+0x00000008` `void* subAllocation1` (read_write, DERIVED)
- `obj+0x00000014` `void* subAllocation2` (read_write, DERIVED)

### DualLinkedListOwner

Object that owns two singly-linked lists (first list at this+0x1C, second at this+0x30) of session-config nodes; teardown walks both lists freeing nodes and their data blocks and zeroes all list bookkeeping. Distinct base from AutoLoadEntryList; same offsets are not merged (no common-ownership proof in the packet).

Methods: `0x004331A0`

- `this+0x00000018` `uint8 stateFlag` (write, DERIVED)
- `this+0x0000001C` `LinkedListNode* firstListHead` (read_write, DERIVED)
- `this+0x00000020` `LinkedListNode* firstListTail` (read_write, DERIVED)
- `this+0x00000024` `LinkedListNode* firstListFirst` (read_write, DERIVED)
- `this+0x00000028` `int32 firstListCount` (read_write, DERIVED)
- `this+0x0000002C` `uint8 firstListFlags` (write, DERIVED)
- `this+0x00000030` `LinkedListNode* secondListHead` (read_write, DERIVED)
- `this+0x00000034` `LinkedListNode* secondListTail` (write, DERIVED)
- `this+0x00000038` `void* secondListExtra` (write, DERIVED)
- `this+0x0000003C` `int32 secondListCount` (write, DERIVED)

### GenericLinkedList

Minimal head/tail/first/count linked list with an append operation that allocates 12-byte nodes. Separate base from AutoLoadEntryList and DualLinkedListOwner; no common ownership proven.

Methods: `0x00434030`

- `this+0x00000000` `LinkedListNode* head` (read_write, DERIVED)
- `this+0x00000004` `LinkedListNode* tail` (read_write, DERIVED)
- `this+0x00000008` `LinkedListNode* first` (read_write, DERIVED)
- `this+0x0000000C` `int32 count` (read_write, DERIVED)

### HWInputManager

Hardware-input subsystem object with a full lifecycle (enter/setup/init/restart/post/exit). Holds a DirectInput-style device interface pointer at +0, a device array at +0x1F98 used to derive an active flag at +0x2428, and a module-unloaded marker at +0x1B10.

Methods: `0x00455BF0`, `0x00455C60`, `0x00455D50`, `0x00455DA0`, `0x00455E70`, `0x00455F00`

- `this+0x00000000` `IDirectInput8* deviceInterface` (read_write, DERIVED)
- `this+0x00001B10` `int32 moduleUnloadedMarker` (write, DERIVED)
- `this+0x00001F98` `int32[?] deviceArray` (read, DERIVED)
- `this+0x00001F9C` `int32 firstDeviceEntryTypeId` (read, DERIVED)
- `this+0x00002428` `uint8 activeFlag` (read_write, DERIVED)

### ConstraintSolverParams

Parameter object (owner inferred only from callers ConstraintSolverParamInit and sub_4348B0) holding a heap-allocated polymorphic sub-object at +0xC whose first vtable method (arg 1) deletes it.

Methods: `0x00434D40`

- `this+0x0000000C` `void* polymorphicSubObject` (read_write, DERIVED)

### SceneTrackTerrain

Track scene/terrain object that loads terrain via the HTree file format and rebuilds collision geometry (shape init, geometry operation selection, bounding boxes, grid raycast setup). Ownership of `this` inferred from CollisionTreeNodeCleanup(this) on the load path.

Methods: `0x0044C0E0`


### CursorManager

Cursor handle resource manager holding six 20-byte handle slots at +0x30 and a cursor count/index at +0xA8; teardown destroys each non-null handle and clears the active cursor.

Methods: `0x0044F5F0`

- `this+0x00000030` `HCURSOR[6] handleSlots` (read_write, DERIVED)
- `this+0x000000A8` `int32 cursorCount` (write, DERIVED)

### TextRenderHelper

Text rendering helpers on the UI frame path: identifier-to-color-mask mapping, bounded formatted string build with suffix, and word-wrapped line rendering onto an output context at +0.

Methods: `0x0045BB60`, `0x0045BC50`, `0x0045BD10`

- `this+0x00000000` `void* outputContext` (read, DERIVED)

### RenderResourceObject

Heap object whose destructor restores its vtable (off_59F080), cleans a sub-object at +4, frees an allocation at +0x2C, and performs resource cleanup on the sub-object. Owner identity (a UI/render object) is unconfirmed.

Methods: `0x0045B400`

- `this+0x00000000` `void** vtable` (write, DERIVED)
- `this+0x00000004` `void* subObject` (read_write, GUESS)
- `this+0x0000002C` `void* heapAllocation` (read_write, DERIVED)

## Compatibility contracts

- **AutoLoadEntryListPersistence** — The auto-load entry list is loaded from and serialized back to a physics config file whose path is derived from the global at byte_7CE498. A load first frees any existing node list (destroying physics objects for flagged nodes), resets head/tail/first/count, wraps each accepted 28-byte session-config object in a 12-byte node {data, next, flag}, and sets the completion flag at this+0x18. A serializer must walk the list from this+0x1C through node+4 next pointers and write each node.
- **HWInputLifecycle** — The hardware-input subsystem exposes enter/setup/init/restart/post/exit entry points. The DirectInput-style device interface behind this+0 is released via the virtual method at vtable+8 and the pointer cleared; the active flag at this+0x2428 is derived from a scan of the device array at this+0x1F98 (11-DWORD stride, second DWORD != 89); module unload marks this+0x1B10 as -1. Element-strided sub-objects (slots 866, 1121, 815, arrays at +1376) are created/destroyed in lockstep.
- **SceneTerrainReloadGate** — Track scene/terrain reload is gated by registry timestamp comparisons (RegistryKeyQuery on the built path and scene path) and by the weather-mode flag byte_7CFEE8, which bypasses the timestamp checks. Path composition uses the '.hat' extension, the track basename, a '^' separator, and '.scn' handling. On reload the collision geometry is rebuilt through shape init, geometry selection, bounding-box computation and a 32x32 grid raycast setup.
- **BoundedStringCopy** — String construction into caller buffers is bounded: SafeStringCopy copies at most a3 bytes and forces a terminator at a1+a3; StringCopyWithFormatQuery formats into a 512-byte scratch, appends the suffix, copies a4-1 bytes into the destination and forces a terminator at a3[a4-1]. A replacement must preserve the capacity-minus-one bound and the forced terminator.
- **TextRenderWrap** — Word-wrapped text rendering uses 79-character segments cut at the last space boundary after position 40 (or at 79 when no space is found). The special color marker 16909060 is remapped through IDToColorMaskMapper (1 -> -65536, 2 -> -256, default -1). Rendering is skipped when the width parameter exceeds the global bound dword_7D02E4.

## Unresolved

- Owner types are unknown for PathStringModifier, SafeStringCopy, CameraViewportConfigBatch, RegisterRendererObject and AudioRendererFloatConstantInitializer; their `this`/arguments could belong to objects outside this packet.
- off_5C3F88 is labeled Off_ButtonBinding by existing analysis, but that label is not grounded in this packet's raw source.
- The full layout of the 28-byte session-config object beyond +0/+8/+0x14 is unknown; the exact parse-state contracts of ConditionalDispatchBasedOnFlag / sub_588410 are unknown.
- DoublyLinkedListAppend's allocation-failure path still appends a null node (tail null, count incremented, returns 1); caller behavior on a null node is unknown.
- VtableMethodShutdown's virtual dispatch target is dynamic; calling the first vtable method with argument 1 is assumed to be a destructor/delete request but is not statically resolvable.
- CameraViewportConfigBatch's node arguments v2..v57 are uninitialized in the decompiled view (compiler artifact of a macro-generated call chain); the numeric node identifiers and mode values map to collision-node properties not documented in the packet.
- HWInput element strides (this+866, this+1121, this+815, arrays at +1376, flag a1[1637]) are raw-source element indices whose byte equivalents are not packet evidence refs.
- The identity and purpose of sub_44F4E0 (cursor/timing setup in HWInput_Enter) are unknown from this packet.
- HWInput_Setup's final success-path call (GlobalStateInitializerWithEnumValues per raw source) has no callee address in the packet, so its target cannot be pinned.
- The device-array scan guard (second DWORD == 89) and the 11-DWORD entry layout in HWInput_Restart are inferred from the fill analysis, not proven by an external contract.
- StringSplitLoop debug-log predicate semantics (constants 2 and message ids 5205..5321) are undocumented.
- The meaning of the word_5C406C path marker and the global flag byte_7C56C0 is unverified from packet evidence alone.
- RegistryKeyQuery timestamp-freshness semantics and the registry-value contract are not proven; dword_8ACEA0 is listed as a read global but does not appear in the raw function text.
- RegisterRendererObject registers the no-op nullsub_72 address as a renderer object; BooleanToIntConversion semantics and the registration intent are unproven.
- AudioRendererFloatConstantInitializer's constant bit pattern (-1082130432) and the zero float have no evidenced semantics; no callers are known.
- TextLineWrappingAndRendering's fixed render parameter 1084227584 and the meaning of the width/size parameter a3 vs the bound dword_7D02E4 are unconfirmed; global dword_59F07C does not appear in the recovered source.
- The generic head/tail/first/count layout (GenericLinkedList), the auto-load list fields and the dual-list bookkeeping are not proven to describe the same or compatible classes despite offset similarity.
- DestructorWithResourceCleanup's cleanup routine (ResourceCleanup_cd10 per raw source) has no callee address in the packet; sub-object type at +4 and vtable owner identity are unverified.
