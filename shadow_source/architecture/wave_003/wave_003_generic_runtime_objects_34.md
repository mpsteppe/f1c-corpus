# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

Packet wave_003_generic_runtime_objects_34 covers 28 functions in the generic runtime-object band (0x0054A600-0x005508A0). Object constructors (0x0054A600, 0x0054FE10, 0x00550760, 0x005507E0) share the GlobalZeroInit_c2a0 base-zeroing pattern. A large mesh/scene-node layout (0x0..0x238) is initialized by 0x0054A600 and consumed by render-flag, child-list and vertex-buffer helpers (0x0054C110, 0x0054C210, 0x0054C230, 0x0054C510, 0x0054E190, 0x0054FB40, 0x005506A0); this grouping is GUESS because equal this offsets are not proof of common ownership. Two mesh loaders (0x0054A870, 0x005508A0) implement the same direct-open / path-directory-array / MAS-list search flow with identical error reporting. Leaf dword setters (0x0054FC40, 0x0054FC80, 0x0054FCA0, 0x0054FCB0, 0x0054FCC0, 0x0054FD30) write contiguous render-state fields and are invoked by render-state setup helpers. Remaining helpers (string copy/normalize, float setter, list relink, node destruction, audio-emitter factory, session-log dispatcher) are structurally identified but their owning classes remain unnamed.

## Function roles

- `0x0054A600` **MeshSceneNode** — ObjectConstructorInitializer: constructor for the large mesh/scene-node layout; delegates base zeroing to GlobalZeroInit_c2a0, initializes an embedded float struct at +0x6C via F_10FloatStructInitializer, sets default 6 at +0x50, writes identity floats 1.0f at +0x194/+0x198/+0x19C, zeroes two 0x40-byte buffers (+0xD4, +0x1A0) and the remaining dword fields, returns `this`.
- `0x0054A730` **UnknownObject** — copyStringWithValidation: copies string a2 into lpSrcStr via strcpy, post-processes it through sub_589901, then returns -1 when sub_54A870(a3) is nonzero and 0 otherwise; the a3 validation meaning is uninterpreted.
- `0x0054A870` **MeshResourceLoader** — loadAndRegisterMesh: validate the name is non-empty and prefixed with 'mts_', attempt a direct binary open, walk the registered path-directory array (byte_8B5A3C / count dword_8B8E30, stride 132), then the MAS list (dword_8B8F14); read the located file via sub_54AC70, optionally report dimensions via sub_54B4D0, register via sub_54B570 and LinkedListAppend_abe0, clear bit 0x8000 of this+0x3C and return 0; every failure reports through sub_53C590 and returns -1.
- `0x0054B190` **MeshGeometryData** — CopyMeshHeaderToOutputBuffer: serializes a source mesh header plus bounding/geometry and OBB/plane-data blocks into a caller buffer; writes the 'cube.mts' name, two header dwords, a 96-byte bulk copy, the +0x7C..+0x84 bounding block and the +0x94..+0xD4 OBB block; returns 0. Invoked during mesh serialization from sub_54AC70.
- `0x0054B450` **UnknownObject** — SetThreeFloatsAndClearBitmask: stores three floats into +0x2C/+0x30/+0x34 (each passed through InterruptDispatch before the store) and clears the bitmask at +64 via BitmaskClear; the owning state/vehicle object is unidentified.
- `0x0054B9E0` **SessionLogger** — LogSessionEvent: thin dispatcher that forwards a session log event by calling EnumToVTableCallMapper with selector 1 and the event payload pointer at this+0x1A0, returning the dispatch result; reached from the session subsystem.
- `0x0054BA00` **DoublyLinkedNodeList** — RelinkNodeToListTail: unlinks node a2 from its doubly-linked list by patching neighbour prev/next pointers, updates the global container head at dword_8B8F28 when a2 was head, optionally runs tree-node accumulation (a3), appends a2 to this's list tail (+0x44), rewrites a2's back-pointers, and merges sublists (this+0x230, a2+560) when both exist.
- `0x0054BDA0` **UnknownObject** — SelfRelativeStringCopy: computes delta = a2 - this, then copies the byte string from this to this+delta through the null terminator, returning the last copied byte.
- `0x0054C110` **MeshSceneNode** — RenderFlagSetter: selects a render flag mode from the a3 mask; bit 0x800 stores a2 at +0x234 and ORs 0x800 into the flags word at +0x3C; bit 0x1000 stores a2 at +0x238 and ORs 0x1000 into +0x3C; returns a3 when neither bit is set.
- `0x0054C210` **MeshSceneNode** — SceneGraphChildCount: counts nodes of the singly-linked child list rooted at this+0x204 (next link at node+0x10); returns 0 when the head is null.
- `0x0054C230` **MeshSceneNode** — LinkedListIndexedAccessor: returns the a2-th node of the singly-linked list rooted at this+0x204 (next at node+0x10); returns 0 when the head is null or the list ends before the requested index.
- `0x0054C510` **MeshSceneNode** — updateMeshVertexBuffers: advances four vertex-buffer base pointers (+0x11C/+0x124/+0x12C/+0x134) by (this+a3), resolves each primary element's material via sub_548850 and ArithmeticComparisonBinarySearch over the global material library (dword_8B8F28+272), stores the material back, sets render-flag byte bits (+0x16 0x08/0x10), re-bases secondary elements and ORs 0x800000 into +0x14; material-not-found reports via sub_53C590 and returns -1.
- `0x0054E190` **MeshSceneNode** — CameraDistanceGetter: trivial thiscall getter returning the int field at this+0x120 (this[72]); no side effects.
- `0x0054FA50` **LinkedDataNode** — LinkedNodeDestruction: frees the data-array pointer held at descriptor offset +8 (mapped to this+0x1E8), then frees the descriptor at this+0x1E0 via FreeWrapper_7bcf, clears the descriptor pointer and returns the freed descriptor address (or null when already null).
- `0x0054FB40` **MeshSceneNode** — SceneNodeVisibilityToggle: loads the render node from this+0x204 and sets (OR 0x40) or clears (AND ~0x40) the visibility bit on the node flag word at node+0x14 (this+0x218), returning the node pointer.
- `0x0054FC10` **UnknownObject** — SelfRelativeCopyNormalize: copies input string a2 into lpSrcStr via strcpy, then hands the buffer to sub_589901 and returns its result; the actual normalization lives outside this packet.
- `0x0054FC40` **RenderStateFieldSetter** — SimpleSetter_fc40: leaf dword setter storing a2 into this+0x60 (this[24]) and returning the stored value; used as a callback/action by render-state and linked-list helpers.
- `0x0054FC80` **RenderStateFieldSetter** — DualFieldSetter: stores a2 into this+0x70 and a3 into this+0x74, returning a2; called by five render-state setup helpers.
- `0x0054FCA0` **RenderStateFieldSetter** — setField64: thiscall setter storing argument a2 into this+0x64 (this[25]) and returning the stored value.
- `0x0054FCB0` **RenderStateFieldSetter** — SetField80: unconditional setter storing a2 into this+0x80 (this[32]) and returning a2 unchanged.
- `0x0054FCC0` **RenderStateFieldSetter** — SetRenderStateDefault: switch on a2 dispatching through the jump table at 0x0054FD20; every path writes 191 to this+0x84 (the 127/63/0 intermediate writes are dead), returning a2 unchanged.
- `0x0054FD30` **RenderStateFieldSetter** — SetPairedIntFields: stores a2 into this+0x78 and a3 into this+0x7C, returning a2; used by render-state / vertex-buffer setup routines.
- `0x0054FE10` **UnknownObject** — StructInitWithZeroFill: constructor calling GlobalZeroInit_c2a0, zero-filling 0x40 bytes at this+4, then writing explicit defaults (0 at +0x0/+0x44/+0x48/+0x54/+0x58/+0x5C, 1 at +0x4C/+0x50); shared by vehicle-node and audio-sound construction.
- `0x0054FE50` **AudioEmitterResource** — audioEmitterCreateFromPath: allocates a 60-byte block via OperatorNewNhMallocWrapper, initializes the audio emitter via AudioEmitterCreate, stores it at +0x54, extracts the filename after the last backslash from the resource path into the string buffer at +0x4, post-processes via sub_589901 and returns 0.
- `0x005506A0` **MeshSceneNode** — LinkedListTimerValueAssign: walks the tracker list rooted at this+0x204 (next at node+0x10) and conditionally writes a2 into tracker element value slots (element+52), filtered by owner equality (a3 branch) or by sub-object count/threshold (all-elements pass); the a3 sub-object stride is 148.
- `0x00550760` **UnknownObject** — StructInitWithScaleDefaults: constructor calling GlobalZeroInit_c2a0, clearing a byte flag at +0x44, writing -1 at +0x0, zeroing 0x40 dwords from this[1], setting 1.0f scale defaults at +0x4/+0x18/+0x2C/+0x40, clearing +0x84 and returning this.
- `0x005507E0` **UnknownObject** — StructInitWithVtableZero: constructor calling GlobalZeroInit_c2a0 then explicitly zeroing the first byte at +0x0 and dwords at +0x20/+0x24/+0x28; called from MeshVertexIndexBufferLoader.
- `0x005508A0` **MeshResourceLoader** — LoadMeshFileWithPathSearch: zeroes the output struct (+0x0..+0x1C), normalizes the file name, validates the extension against off_5DC050, attempts a direct open, searches the path-directory list (byte_8B5A3C/dword_8B8E30), then walks the MAS list (dword_8B8F14), loading via MeshVertexIndexBufferLoader; each failure reports a specific error string through sub_53C590 and returns -1, success returns 0.

## Proposed classes

### MeshSceneNode

Large mesh/scene render node initialized by ObjectConstructorInitializer (0x0054A600): carries render flags (0x3C, 0x14, 0x16), identity floats, vertex-buffer element arrays (0x118..0x134), a singly-linked child list (head +0x204, next node+0x10) and render value fields (+0x234/+0x238). Grouped by overlapping this offsets; class identity is GUESS, not proven by shared layout alone.

Methods: `0x0054A600`, `0x0054C110`, `0x0054C210`, `0x0054C230`, `0x0054C510`, `0x0054E190`, `0x0054FB40`, `0x005506A0`

- `this+0x00000000` `u8 typeOrFlagsByte` (write, GUESS)
- `this+0x00000014` `u32 renderFlagsWord` (read_write, DERIVED)
- `this+0x00000016` `u8 renderFlagByte` (read_write, DERIVED)
- `this+0x0000003C` `u32 flagsWord` (read_write, DERIVED)
- `this+0x00000118` `u32 primaryElementCount` (read_write, DERIVED)
- `this+0x0000011C` `ptr primaryElementArrayBase` (read_write, DERIVED)
- `this+0x00000120` `u32 secondaryCountOrCameraDistance` (read_write, DERIVED)
- `this+0x00000124` `ptr secondaryElementArrayBase` (read_write, DERIVED)
- `this+0x0000012C` `ptr tertiaryArrayBase` (read_write, DERIVED)
- `this+0x00000130` `u32 tailFlagPassGuard` (read, DERIVED)
- `this+0x00000134` `ptr quaternaryArrayBase` (read_write, DERIVED)
- `this+0x00000194` `f32 identityFloatA` (write, GUESS)
- `this+0x00000198` `f32 identityFloatB` (write, GUESS)
- `this+0x0000019C` `f32 identityFloatC` (write, GUESS)
- `this+0x00000204` `ptr childListHead` (read_write, DERIVED)
- `*(this+0x214)+0x00000010` `ptr childNodeNextLink` (read, DERIVED)
- `this+0x00000218` `u32 renderNodeFlags` (read_write, DERIVED)
- `this+0x00000234` `u32 renderValueFlag800` (write, DERIVED)
- `this+0x00000238` `u32 renderValueFlag1000` (write, DERIVED)

### MeshResourceLoader

Locates, validates, loads and registers mesh/animation resource files: name and extension validation, direct binary open, registered path-directory search (byte_8B5A3C / dword_8B8E30, stride 132) and MAS linked-list fallback (dword_8B8F14), with uniform sub_53C590 error reporting returning -1 on every failure.

Methods: `0x0054A870`, `0x005508A0`

- `this+0x00000000` `u32 loadOutputHeader0` (write, DERIVED)
- `this+0x00000004` `u32 loadOutputHeader1` (write, DERIVED)
- `this+0x00000008` `u32 loadOutputHeader2` (write, DERIVED)
- `this+0x0000000C` `u32 loadOutputHeader3` (write, DERIVED)
- `this+0x00000010` `u32 loadOutputHeader4` (write, DERIVED)
- `this+0x00000014` `u32 loadOutputHeader5` (write, DERIVED)
- `this+0x00000018` `u32 loadOutputHeader6` (write, DERIVED)
- `this+0x0000001C` `u8 loadOutputTailByte` (write, DERIVED)
- `this+0x0000003C` `u32 loadFlagsWord` (read_write, DERIVED)

### MeshGeometryData

Mesh header plus bounding-volume/geometry and OBB/plane-data blocks serialized by CopyMeshHeaderToOutputBuffer into a caller-supplied buffer; layout is inferred from the copy offsets, not independently attested.

Methods: `0x0054B190`

- `this+0x00000014` `u32 meshHeaderDword0` (read, GUESS)
- `this+0x00000018` `u32 meshHeaderDword1` (read, GUESS)
- `this+0x0000007C` `f32 boundingDword0` (read, GUESS)
- `this+0x00000080` `f32 boundingDword1` (read, GUESS)
- `this+0x00000084` `f32 boundingDword2` (read, GUESS)
- `this+0x00000094` `f32 obbPlaneData0` (read, GUESS)
- `this+0x00000098` `f32 obbPlaneData1` (read, GUESS)
- `this+0x0000009C` `f32 obbPlaneData2` (read, GUESS)
- `this+0x000000A0` `f32 obbPlaneData3` (read, GUESS)
- `this+0x000000A4` `f32 obbPlaneData4` (read, GUESS)
- `this+0x000000A8` `f32 obbPlaneData5` (read, GUESS)
- `this+0x000000AC` `f32 obbPlaneData6` (read, GUESS)
- `this+0x000000B0` `f32 obbPlaneData7` (read, GUESS)
- `this+0x000000B4` `f32 obbPlaneData8` (read, GUESS)
- `this+0x000000B8` `f32 obbPlaneData9` (read, GUESS)
- `this+0x000000BC` `f32 obbPlaneData10` (read, GUESS)
- `this+0x000000C0` `f32 obbPlaneData11` (read, GUESS)
- `this+0x000000C4` `f32 obbPlaneData12` (read, GUESS)
- `this+0x000000C8` `f32 obbPlaneData13` (read, GUESS)
- `this+0x000000CC` `f32 obbPlaneData14` (read, GUESS)
- `this+0x000000D0` `f32 obbPlaneData15` (read, GUESS)
- `this+0x000000D4` `f32 obbPlaneData16` (read, GUESS)

### RenderStateFieldSetter

Family of leaf dword setters writing contiguous render-state parameter fields at +0x60..+0x84; invoked as callbacks by render-state setup helpers (sub_546F70, sub_546FE0, ConditionalRenderStateSetup, GuardedRenderStateSet, ConditionalCheckCall, DirectXMeshVertexBufferParsingAndLoading). Field semantics are caller-owned and unknown here.

Methods: `0x0054FC40`, `0x0054FC80`, `0x0054FCA0`, `0x0054FCB0`, `0x0054FCC0`, `0x0054FD30`

- `this+0x00000060` `u32 stateParam0` (write, GUESS)
- `this+0x00000064` `u32 stateParam1` (write, GUESS)
- `this+0x00000070` `u32 stateParam2` (write, GUESS)
- `this+0x00000074` `u32 stateParam3` (write, GUESS)
- `this+0x00000078` `u32 stateParam4` (write, GUESS)
- `this+0x0000007C` `u32 stateParam5` (write, GUESS)
- `this+0x00000080` `u32 stateParam6` (write, GUESS)
- `this+0x00000084` `u32 stateParam7` (read_write, GUESS)

### AudioEmitterResource

Resource object owning a created audio emitter: allocates a 60-byte emitter via OperatorNewNhMallocWrapper, initializes it via AudioEmitterCreate, stores the emitter pointer at +0x54 and keeps the extracted filename in the string buffer at +0x4.

Methods: `0x0054FE50`

- `this+0x00000054` `ptr emitterPointer` (write, DERIVED)

### SessionLogger

Dispatches session log events by forwarding an event payload (at this+0x1A0) through EnumToVTableCallMapper with selector 1; the payload layout and selector meaning are not evidenced.

Methods: `0x0054B9E0`


### DoublyLinkedNodeList

Doubly-linked list container supporting node relink to tail: unlink with neighbour pointer patching, global container head update, tail append and sublist merge; also covers a global list container (dword_8B8F28) whose head lives at +264.

Methods: `0x0054BA00`

- `this+0x00000044` `ptr listHead` (read_write, DERIVED)
- `this+0x00000230` `ptr sublistHead` (read_write, DERIVED)
- `*(this+0x90)+0x0000004C` `ptr containerHeadNextPtr` (read, GUESS)

### LinkedDataNode

Node owning a data-array descriptor at +0x1E0 whose +8 slot holds the data array; destruction frees both and clears the descriptor pointer.

Methods: `0x0054FA50`

- `this+0x000001E0` `ptr descriptorPtr` (read_write, DERIVED)
- `this+0x000001E8` `ptr dataArraySlot` (read, GUESS)

## Compatibility contracts

- **MeshFileNameValidation** — Mesh file names must be non-empty and prefixed with 'mts_' (validated via sub_587C20 against the aMts_0 table); loaders additionally validate the extension against the off_5DC050 table. Violations produce the 'Illegal mesh file name %s' message reported through sub_53C590.
- **MeshOpenBinaryMode** — Mesh files are opened for binary read with the mode string aRb (0x005BE828) via sub_587DB0 and closed via FileCloseWithLock (0x00587D02). When the direct open fails, a registered path-directory array at byte_8B5A3C (count dword_8B8E30, element stride 132) is searched, formatting each candidate with the '%s\\%s' pattern from aSS_3 (0x005C2D64).
- **MasMeshFallback** — When direct open and path-directory search fail, a MAS animation/mesh list headed at dword_8B8F14 is walked: entries are tested via sub_560230 and loaded through MeshVertexIndexBufferLoader or sub_54AC70. Exhaustion against dword_8B6AC0 yields the 'Could not locate mesh file %s' message.
- **MeshSceneNodeListLayout** — The scene node keeps a singly-linked child list whose head is stored at this+0x204 and whose next link lives at node+0x10 (also encoded as offset 0x10 reached through this+0x214). The render-node flag word lives at node+0x14 (this+0x218) with visibility bit 0x40.
- **MeshMaterialLibraryLookup** — Vertex-buffer update resolves each element's material by converting the element key via sub_548850 and binary-searching the global material-library array reached through dword_8B8F28+272 via ArithmeticComparisonBinarySearch (0x005477F0). A null result reports through sub_53C590 and returns -1.
- **RenderFlagBits** — The flags word at +0x3C is OR-accumulated: bit 0x800 pairs with the render value field +0x234, bit 0x1000 with +0x238, bit 0x8000 marks the mesh as loaded, and bit 0x10 gates mesh-dimension reporting into sub_54B4D0. The word at +0x14 is ORed with 0x800000 when +0x130 is positive.
- **ErrorReportingConvention** — Loader and render failures format a message via StringFormatWithBufferOverflowCheck (0x0058815F) and report it through sub_53C590(-1, message), returning -1 on every failure path and 0 on success.

## Unresolved

- Object class identities remain unnamed for the string helpers (0x0054A730, 0x0054BDA0, 0x0054FC10), the float setter (0x0054B450) and the three remaining constructors (0x0054FE10, 0x00550760, 0x005507E0); equal this offsets across functions do not prove common ownership.
- MeshSceneNode is a GUESS grouping: functions 0x0054C210/0x0054C230/0x0054FB40/0x005506A0 share only the +0x204 list head and node+0x10 next link; LinkedListTimerValueAssign in particular may belong to a distinct timer-tracker type.
- The two 0x40-byte memset buffers inside ObjectConstructorInitializer (+0xD4, +0x1A0) carry no per-field evidence refs and their individual fields are not enumerated.
- The embedded float struct initialized at +0x6C by F_10FloatStructInitializer has no field-level evidence; only its initializer call is attested.
- dword_8B8F28 serves both the mesh material-library array base (+272) and a linked-list container head (+264); the dual role is not reconciled by this packet.
- RenderStateFieldSetter fields at +0x60..+0x84 have unknown semantics; SetRenderStateDefault's switch carries dead intermediate writes (127/63/0), possibly compiler artifacts.
- The three floats set by SetThreeFloatsAndClearBitmask and the cleared bitmask at +64 belong to an unidentified owning object; the stored-meaning is not established.
- The delta (this + a3) applied to each vertex-buffer array base in updateMeshVertexBuffers is uninterpreted; per-element layout (stride 64) is inferred.
- Meaning of sub_54A870's 0/-1 result and of the a3 argument in copyStringWithValidation is unknown; sub_589901's normalization behaviour is defined only by its legacy ABI name.
- The exact exhaustion semantics of the MAS fallback walk (comparison against dword_8B6AC0 as -1 sentinel vs list-length count) are not resolved from the raw code.
- The intermediate (non-0, non-1) return values of sub_54AC70 that continue the fallback walk are uninterpreted.
