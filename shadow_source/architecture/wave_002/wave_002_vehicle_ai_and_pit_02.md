# VehicleAIAndPitOperations

Scope: `vehicle_ai_and_pit`  
Trust: `DERIVED`

The packet groups 16 validated functions into three clusters. (1) A pit-crew asset pipeline (0x004A2010 mesh loader, 0x004A2A90 .ANM parser, 0x004A3220 PITANIMS.MAS wrapper, 0x004A3910 MAS setup) sharing the MeshResourceAllocator/SceneGraphAttachment and text-line reader infrastructure; the loader object owns loadedFlag/+0xC/+0x10/+0x14 while the MAS-setup object owns slotCount +0x70, animation data +0x74 and range ends +0x7C/+0x80 (distinct bases per no-merge rule). (2) A pit-machine AI-mode transition dispatcher (0x004A5E10, owner F1CPitMachine, packet CONFIRMED downgraded to DERIVED per worker policy) with explicit state machine 0->1, 1->0, 4->1. (3) Tire-brand catalog loading (0x004D7660 collection with count +0x0 and 36-byte-entry array +0x4; 0x004D7150 file parser owning slip-curve +0x8/+0xC and compound +0x10/+0x14 arrays), scene path building (0x004C54F0 on globals 0x8AC48C/0x8AC490), and HUD flag rendering (0x004D82D0). The remaining functions (0x00534AAC AIL import thunk, 0x00541040 drain finalizer, 0x0054A710 stub pair, 0x0054EAD0/0x005568E0 heartbeat loops, 0x00551F10 create-with-rollback, 0x00554D70 UI cleanup) are isolated GUESS classes because the packet gives no owner or shared-field evidence linking them.

## Function roles

- `0x004A2010` **PitCrewMeshLoader** — Pit crew member mesh loader: detail-level guard, MeshResourceAllocator at this+0x64, sub-mesh walk, scene-graph attach, child index table build at this+0x6C, optional re-link, error path returning -1.
- `0x004A2A90` **PitCrewAnimationLoader** — Pit crew animation (.ANM) parser: opens the file via .RT helper, two-pass ACTOR/DETAIL/MESH/POSITION/MOVE/ROTATE directive interpretation into a 120-byte actor entry array, wheel-mesh dispatch through ModeDependentSubsystemCall, collision-geometry append, vertex-buffer guard, float scaling, post-processing and per-actor dispatch.
- `0x004A3220` **PitCrewAnimationLoader** — PITANIMS.MAS animation archive loader: cleans up the existing array, resolves the base directory from byte_5EA438, registers the path, opens the MAS archive, delegates to PitCrewAnimationLoader, closes the archive and frees the temporary path copy.
- `0x004A3910` **PitCrewAnimationMASFileLoader** — Pit-crew animation MAS setup: builds the pitguy/season/track path, selects the left/normal hand variant, resolves the MAS name, loads two animation files via sub_4A22D0, and when this+0x70 slot count permits sets animation ranges with RangeProportionInitializer storing ends at this+0x7C/this+0x80.
- `0x004A5E10` **F1CPitMachine** — Pit-machine AI mode transition dispatcher on the frame path: reads this+0x184 and for states 0, 1 and 4 forwards to StateChangeNotify (0->1, 1->0, 4->1); any other state returns state-4 with no transition.
- `0x004C54F0` **SceneFilePathsBuilder** — Scene file path builder: computes the scene entry from index dword_8AC48C and base dword_8AC490 (stride 0x18C), copies the scene base name, formats %s.SCN into byte_8AC3E8 and %s.AIW into byte_8AC438, then persists all three buffers.
- `0x004D7150` **TireBrandDataFileParser** — Tire brand data file parser: clears arrays, derives the base file name from a2, opens the file, counts SlipCurve/Compound sections into this+0x8/this+0x10, allocates the typed arrays at this+0xC/this+0x14, fills them in a second pass and reports count/overflow errors via the debug log gate.
- `0x004D7660` **TireBrandCollection** — Tire brand (.tbc) loader: releases textures, saves the FPU control word, enumerates .tbc files in the season directory, allocates a 36-byte-per-entry array prefixed by count, parses each file via TireBrandDataFileParser and logs a missing-brands warning when empty.
- `0x004D82D0` **HudFlagRenderer** — HUD flag render: collects race-flag bytes (yellow/blue/black/pit/checkered, plus driver-condition flags in display mode 2), null-terminates, overrides colors and renders via sub_553070; skips on global gates and when this+0x8 slot is -1.
- `0x00534AAC` **MilesSoundSystem** — Miles Sound System shutdown import thunk: forwards to the IAT entry __imp__AIL_shutdown@0 (global 0x0059E394) and returns the imported result unchanged.
- `0x00541040` **ResourceTeardownFinalizer** — Resource teardown finalizer: guarded on a2+24, drains the counter at a2+12 via GuardedVirtualDecrement, calls the virtual method at vtable slot 8 of the cached state and stores its result into *this, then clears a2+24.
- `0x0054A710` **CallEmptyStubPair** — Void lifecycle helper: fixed sequence of two no-argument calls (EmptyStub_b160 then EmptyStub_0170); no return value.
- `0x0054EAD0` **MainLoopHeartbeat** — Fixed-iteration heartbeat: 1024 times steps the pointer at global 0x008CBF48 backwards by 24 bytes and calls EmptyStub_0170 (0x004B0170).
- `0x00551F10` **ObjectFactoryWithRollback** — Object creation with rollback: allocates/initializes a 20-byte structure, stores it through the out-parameter, runs object setup, and on failure destroys/frees it, nulls the out-parameter and returns -1.
- `0x00554D70` **UICleanupIterator** — UI cleanup iterator: iterates this+0x13B0 slots releasing each through the device vtable+240 (device at this+0x1100), releases returned handles and the shared resource via vtable+8, resets slot state on match, clears v2 flags and sets v2[14] to -1.0.
- `0x005568E0` **MainLoopHeartbeat** — Fixed-iteration heartbeat: 512 times steps the pointer at global 0x008CEF70 backwards by 24 bytes and calls EmptyStub_0170 (0x004B0170).

## Proposed classes

### PitCrewAnimationLoader

Loads and owns the pit-crew animation set: parses the .ANM definition file into a 120-byte actor entry array, dispatches wheel meshes through mode-dependent subsystem calls, appends collision geometry, and completes with a loaded flag and per-actor dispatch. Also wraps the PITANIMS.MAS archive open/close around the parse.

Methods: `0x004A2A90`, `0x004A3220`

- `this+0x00000000` `int LoadedFlag` (read_write, DERIVED)
- `this+0x0000000C` `int ActorCount` (read_write, DERIVED)
- `this+0x00000010` `void* ActorArrayPtr` (read_write, DERIVED)
- `this+0x00000014` `void* CollisionGeometry` (read, DERIVED)

### PitCrewAnimationMASFileLoader

Sets up pit-crew animation MAS loading: assembles the pitguy/season/track path with a left/normal hand variant, resolves the animation MAS, loads two animation files, and installs animation ranges when the slot count allows.

Methods: `0x004A3910`

- `this+0x00000000` `char[16] HeaderBuffer` (read_write, GUESS)
- `this+0x00000070` `int SlotCount` (read, GUESS)
- `this+0x00000074` `void* AnimationDataPtr` (read, DERIVED)
- `this+0x0000007C` `float RangeEndA` (write, GUESS)
- `this+0x00000080` `float RangeEndB` (write, GUESS)
- `*(this+0x74)+0x00000010` `float FirstAnimDuration` (read, GUESS)
- `*(this+0x74)+0x0000002C` `float SecondAnimRangeData` (read, GUESS)

### PitCrewMeshLoader

Loads pit crew member meshes into the scene graph under a detail-level guard, allocating mesh resources at this+0x64 and building a child index table at this+0x6C from the child count at this+0x68. Owner UNKNOWN in the packet; class and field layout DERIVED from the single function.

Methods: `0x004A2010`

- `this+0x00000000` `__int16 DetailThreshold` (read, GUESS)
- `this+0x00000004` `char[?] MeshName` (write, GUESS)
- `this+0x00000064` `void* MeshNodeListHead` (read_write, GUESS)
- `this+0x00000068` `int ChildCount` (write, GUESS)
- `this+0x0000006C` `int* ChildIndexTable` (write, GUESS)

### F1CPitMachine

Owns the pit-machine AI mode state (this+0x184) and its transitions on the frame path, forwarding states 0/1/4 through StateChangeNotify (0x004A5C80). Packet owner trust CONFIRMED is downgraded to DERIVED per worker policy.

Methods: `0x004A5E10`

- `this+0x00000184` `int AiModeState` (read, DERIVED)

### SceneFilePathsBuilder

Builds the current scene's .SCN and .AIW file path strings into global buffers from the scene index/base globals. No this-field evidence; operates on module globals.

Methods: `0x004C54F0`


### TireBrandCollection

Owns the loaded tire-brand (.tbc) catalog: entry count at this+0x0 and a 36-byte-per-entry array at this+0x4, populated by parsing every .tbc file found in the season directory.

Methods: `0x004D7660`

- `this+0x00000000` `int EntryCount` (write, DERIVED)
- `this+0x00000004` `void* EntryArray` (write, DERIVED)

### TireBrandDataFileParser

Parses a single tire-brand data file into slip-curve (this+0x8/+0xC, 24-byte entries) and compound (this+0x10/+0x14, 680-byte entries) arrays with count validation and debug logging.

Methods: `0x004D7150`

- `this+0x00000008` `int SlipCurveCount` (read_write, DERIVED)
- `this+0x0000000C` `void* SlipCurveArray` (write, DERIVED)
- `this+0x00000010` `int CompoundCount` (read_write, DERIVED)
- `this+0x00000014` `void* CompoundArray` (write, DERIVED)

### HudFlagRenderer

Renders the HUD race-flag set from game-state flag checks, gated by display-mode and scoring globals and the participant slot at this+0x8.

Methods: `0x004D82D0`

- `this+0x00000008` `int ParticipantSlot` (read, DERIVED)

### MilesSoundSystem

External third-party audio library interface; only the AIL_shutdown import thunk is evidenced here. Owner is the external library, so the game-side class is a GUESS boundary.

Methods: `0x00534AAC`


### ResourceTeardownFinalizer

Drains a reference counter at a2+12 via GuardedVirtualDecrement and invokes a virtual method on the cached state at a2+24, storing its result into *this before clearing the state handle.

Methods: `0x00541040`

- `this+0x00000000` `int TeardownResult` (write, DERIVED)

### ObjectFactoryWithRollback

Creates and initializes a 20-byte object through a wrapper allocator, returns it via an out-parameter, and rolls back (destroy, free, null out-param, return -1) when object setup fails.

Methods: `0x00551F10`

- `this+0x00000000` `void* OutObjectPtr` (write, DERIVED)

### UICleanupIterator

Releases all UI device slots (count this+0x13B0, device this+0x1100) through vtable+240 dispatch, releases returned handles and the shared resource via vtable+8, resets matching slot state and clears resource-set flags.

Methods: `0x00554D70`

- `this+0x00000000` `int DispatchResult` (write, DERIVED)
- `this+0x00001100` `void* DeviceObject` (read, DERIVED)
- `this+0x000013B0` `int SlotCount` (read, DERIVED)
- `*(this+0x1100)+0x00000000` `void** DeviceVtable` (read, GUESS)
- `*(*(this+0x1100)+0x0)+0x000000F0` `void* ReleaseSlotMethod` (read, GUESS)

### MainLoopHeartbeat

Fixed-iteration heartbeat loop over a stride-24 pointer walk from a global anchor, calling an empty stub per iteration. Two structural twins (1024 and 512 iterations) on different anchors; per-iteration work has degenerated to a stub.

Methods: `0x0054EAD0`, `0x005568E0`


### CallEmptyStubPair

Void helper invoking a fixed sequence of two no-argument stub calls; caller names hint at object-lifecycle use but the stubs' purpose is not evidenced.

Methods: `0x0054A710`


## Compatibility contracts

- **PitCrewAnimationDataLayoutContract** — The pit-crew animation loader must keep a loaded flag at this+0x0, actor count at this+0xC, the 120-byte-stride actor entry array pointer at this+0x10 (count prefix dword, then entries), and the collision geometry handle at this+0x14.
- **PitCrewAnimationRangeLayoutContract** — The MAS setup object must keep slot count at this+0x70, animation data pointer at this+0x74 (duration at *(this+0x74)+0x10, second-range data at +0x2C), and the two animation range end values at this+0x7C and this+0x80.
- **PitCrewMeshLoaderLayoutContract** — The pit-crew mesh loader must keep the mesh-node list head at this+0x64, child count at this+0x68, child index table at this+0x6C, and record the loaded mesh name at this+0x4.
- **TireBrandCatalogLayoutContract** — The tire-brand collection must keep entry count at this+0x0 and a 36-byte-per-entry array at this+0x4; the file parser must keep slip-curve count/array at this+0x8/+0xC (24-byte entries) and compound count/array at this+0x10/+0x14 (680-byte entries), both arrays count-prefixed.
- **PitMachineStateTransitionContract** — A replacement must preserve the AI mode state at this+0x184 and the frame-path transitions 0->1, 1->0, 4->1 through StateChangeNotify (0x004A5C80); non-matching states must return (state - 4) unchanged.
- **HudFlagRenderContract** — Flag rendering must respect the gates (dword_7CFEA0 nonzero, no conditional flag, dword_8AB6E4 != 2, participant slot this+0x8 == -1), emit the flag codes (yellow 62, blue 65, black 63, pit 102, checkered 66 when race phase dword_7C56A8 == 8, driver-condition codes in mode 2) and render via sub_553070.
- **UICleanupContract** — UI cleanup must iterate this+0x13B0 slots, release each via the device (this+0x1100) vtable+240 method, release returned handles and the shared resource via vtable+8, reset slot state on match via StateParameterSetterWithVirtualDeviceNotify, and clear the resource-set flags.
- **MilesSoundSystemShutdownContract** — A replacement must forward AIL_shutdown@0 through the import slot at global 0x0059E394 and preserve its int return value.

## Unresolved

- The a3 mesh-name table layout in PitCrewAnimationLoader (front wheels from a3+4, rear from a3+8) is caller-supplied and unknown.
- String globals aSAnm, aMoveSSF, aPositionFFF, aRotateF, aMeshS, aDetailD, aActorS and globals dword_8ACEE0, dword_8AFE64, flt_59E65C, dbl_59E7D8 are packet-referenced but absent from the raw bodies (likely xrefs via format-string globals or neighboring functions).
- Semantics of ConditionalDispatch_27d0, FlagBasedLoopConditionalCall, FlagFieldBitManipulation, Camera(this) and ShortComputation_3fe0(this) are unknown beyond their call sites.
- Buffers v41/v42 (12 bytes) and v45 (384 bytes) in PitCrewAnimationLoader pass to sub_5651B0 and sub_4A3320/ConditionalDelegateDispatch without visible initialization.
- In PitCrewAnimationMASSetup the +4 reads at this+0x7C and this+0x80 use uninitialized decompiler registers (v8, v12); the true producers of the range end values are not visible.
- The a2 lifetime in PitCrewAnimationMASSetup is ambiguous: used as input name and then as sub_53CBC0 out-pointer that is later freed.
- In PITANIMSMASAnimationFileLoader the copy buffer v13 is assigned 0 and never written between StringCopyWithBufferRealloc(a2) and use, so the copy result is not visible; the a2/byte_5EA438 relationship is unresolved.
- FreeWrapper_7bcf (0x00587BCF) is listed as a callee of PitCrewAnimationMASSetup but no matching call appears in its raw body.
- The unused integer argument a1 in BuildSceneScnAiwFilePaths and globals 0x007CE498/0x005D31B8/0x005D31C0 (suspected SCN/AIW format literals) are unresolved; no validity checks guard the scene index globals.
- The exact contracts of sub_587C20 (token matcher), sub_5651B0 (line reader), TireSlipCurveBuilder and sub_4D6B00 are not established by this packet.
- The 0x2000000 flag at scene node +20 and the incomplete-mesh byte at +64 in PitCrewMeshLoader are unproven semantics.
- Global 0x007CE234 is reported by deterministic facts as referenced by RenderHudFlags but does not appear in its raw body.
- The virtual methods resolved via vtable slot 8 (ResourceTeardownFinalizer) and vtable+8/+240 (UICleanupIterator) have unknown identity; the a2 struct layouts (a2+12/+24, v2[5]/[6]/[14]) are not described by packet fields.
- In ObjectCreationWithRollbackOnFailure the exact roles of the a2/a3/a4 setup arguments at 0x00551A50 are not evident.
- The stride-24 arrays anchored by dword_8CBF48/0x008CEF70 that the heartbeat loops walk, and why the per-iteration work is an empty stub, are unexplained.
- PitMachine state semantics (which states 0/1/4 mean) and the meaning of the returned state-4 value are DERIVED from the transition pattern only; StateChangeNotify's internal ring-buffer contract is not modeled here.
