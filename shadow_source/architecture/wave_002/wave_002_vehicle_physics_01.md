# VehiclePhysics

Scope: `vehicle_physics`  
Trust: `DERIVED`

The vehicle_physics scope spans ten loosely coupled clusters that share no proven common owner: (1) a mode-dispatched transform helper (0x0040F300) routing through orientation integration or wheel-contact transforms; (2) a multiplayer session placement state machine (0x0042CF10) copying vehicle fields across the shared vehicle array on 4->5->6->7 transitions; (3) text-file vehicle setup serialization (0x0042FD00) and the auto-load vehicle config list service (0x004339E0, 0x00433B60); (4) a physics-file path builder (0x00432CF0); (5) guarded one-time engine initialization (0x004347C0); (6) the physics-system module teardown (0x00431C70) owning global node lists; (7) a collision subsystem global-state initializer family (0x0044CB00, 0x0044D280, 0x0044D880, 0x0044E000, 0x0044E780); (8) collision object/body scalar handling (0x00448DE0 tree propagation, 0x00459950 mass/inverse-mass store) and surface-holder cleanup (0x0044EFE0, 0x0044FBE0); and (9) a two-block per-vehicle telemetry broadcast into fixed process globals (0x004537B0). Most class boundaries and all field semantics are GUESS/DERIVED; the collision object vtable release pattern (+0x20 then +0x8) is consistent with a Direct3D-style unacquire/release but is not proven.

## Function roles

- `0x0040F300` **PhysicsModeDispatcher** — Mode-dispatched physics transform helper: reads mode at this+0x1C and routes modes 0-5 through orientation integration (callee 0x0045AE00), mode 6 through sub_4F0430 then the wheel-contact transform on this+0x20, otherwise returns the raw mode.
- `0x0042CF10` **SessionPlacementController** — Multiplayer session placement state machine over states 0-7: copies vehicle fields (FieldCopy / FieldCopy_c330) and reorders standings when the session is active, applies transition predicates when it is not, and commits the clamped state to dword_7D00EC.
- `0x0042FD00` **VehicleSetupSerializer** — Serializes a complete vehicle setup configuration into a text file (General header, notes, and labeled key-value sections), min-clamping gear ratios, closing the file, and returning 0 on success or -1 on open failure.
- `0x00431C70` **PhysicsSystemModule** — Shuts down the global physics system module: cleans the doubly-linked list header, walks and frees the two global node lists and two flagged allocation blocks, and zeroes all list head/tail state.
- `0x00432CF0` **PhysicsPathBuilder** — Builds a physics file path into a caller buffer from an identifier produced by ShortComputation_0b10 plus the extension at off_5C3F84[0], stripping any existing dot-suffix.
- `0x004339E0` **VehicleConfigList** — Searches the auto-load vehicle config entry list for the entry matching the settings folder and session-type filter, copying the result path into the caller buffer (or the default path when no match).
- `0x00433B60` **VehicleConfigList** — Adds or updates a vehicle config entry in the config list object (head 0x1C, tail 0x20, iterator 0x24, count 0x28), linking a 28-byte entry via a 12-byte node, and persists the list through ConfigFileParser.
- `0x004347C0` **EngineInitializer** — Guarded one-time engine initialization: initializes engine subsystems twice, invokes a sound-system vtable method, fills a default-float buffer, dispatches the session phase, then sets the guard byte at this+0x2.
- `0x00448DE0` **CollisionTreeNode** — Recursive collision-tree mass/contact propagation: blends the stored double at this+0x10 halfway toward this+0x4, recurses into four children at this+0x4C, and follows the sibling link at this+0x5C.
- `0x0044CB00` **CollisionSubsystem** — Collision subsystem initializer: seeds dword_7CCFDC (103) and flt_7CCFE0 (0.0) and invokes the shared GlobalInitializer path.
- `0x0044D280` **CollisionSubsystem** — Initializes collision force-feedback and bound globals: 0x007CA57C (61), 0x007CA580 (0), 0x007CA584 (-1082130432), 0x007CA588 (0).
- `0x0044D880` **CollisionSubsystem** — Writes the six-dword collision state block 0x007CCC38 (26) with 0x007CCC3C..0x007CCC4C zeroed.
- `0x0044E000` **CollisionSubsystem** — Writes the six-dword collision comparison/substate block 0x007CCD80 (67) with 0x007CCD84..0x007CCD94 zeroed.
- `0x0044E780` **CollisionSubsystem** — Writes the six-word collision block 0x007CCFEC..0x007CD000: tag 87, four zeroed state words, render state 9000.
- `0x0044EFE0` **CollisionSurfaceHolder** — Releases a held surface object: zeroes the surface type at this+0x278, calls the surface vtable at +0x20 then +0x8 when non-null, and invalidates the pointer at this+0x4.
- `0x0044FBE0` **CollisionSurfaceHolder** — Releases a held object: zeroes this+0x2F4, calls the object vtable at +0x20 then +0x8 when non-null, and clears the pointer at this+0x80.
- `0x004537B0` **VehicleStateBroadcaster** — Broadcasts two gated blocks of per-vehicle state from this-struct fields into process telemetry globals: clamped float channels, byte-flag dword dispatches, and bit-gated equality-comparison tiers.
- `0x00459950` **CollisionBody** — Stores body mass at this+0x180 and inverse mass (1.0 / value) at this+0x188, then forwards a third argument to StructCopyWithReciprocalDivision.

## Proposed classes

### PhysicsModeDispatcher

Routes a physics/render transform request by a mode selector: orientation integration for modes 0-5 and a wheel-contact transform for mode 6.

Methods: `0x0040F300`

- `this+0x0000001C` `int modeSelector` (read, GUESS)
- `this+0x00000020` `void* contactObject` (read, GUESS)

### SessionPlacementController

Drives multiplayer session placement state (0-7): copies per-vehicle fields to and from the shared vehicle array and reorders standings on session transitions.

Methods: `0x0042CF10`

- `this+0x00000008` `int placementState` (read_write, GUESS)

### VehicleSetupSerializer

Serializes a vehicle setup configuration into a text file with labeled sections, gear-ratio min-clamping, and open/close/cleanup lifecycle.

Methods: `0x0042FD00`

- `this+0x00000000` `bool writePendingFlag` (read_write, GUESS)
- `this+0x00000068` `char* setupNotes` (read, GUESS)
- `this+0x000016CC` `byte gearEnabled` (read, GUESS)
- `this+0x00001704` `float[6] gearMinClampEntries` (read_write, GUESS)

### PhysicsSystemModule

Owns the global physics-system node lists (heads 0x007C7418 and 0x007C7404) and flagged allocation blocks (0x007C73F8, 0x007C73F0) and tears them down on engine shutdown.

Methods: `0x00431C70`


### PhysicsPathBuilder

Builds physics file paths from a computed identifier plus an extension string, bounded by a caller-supplied buffer size.

Methods: `0x00432CF0`


### VehicleConfigList

Maintains the linked list of auto-load vehicle config entries (loaded flag 0x18, head 0x1C, tail 0x20, iterator 0x24, count 0x28) for the active game, with on-demand load, lookup, and add/update persistence.

Methods: `0x004339E0`, `0x00433B60`

- `this+0x00000018` `byte loadedFlag` (read_write, GUESS)
- `this+0x0000001C` `ListLink* listHead` (read_write, GUESS)
- `this+0x00000020` `ListLink* listTail` (write, GUESS)
- `this+0x00000024` `ListLink* iterator` (read_write, GUESS)
- `this+0x00000028` `int entryCount` (read_write, GUESS)
- `*(this+0x1C)+0x00000000` `VehicleConfigEntry* headNodeEntry` (read, GUESS)
- `*(this+0x24)+0x00000004` `ListLink* nextLink` (read_write, GUESS)
- `*(*(this+0x24)+0x4)+0x00000000` `VehicleConfigEntry* nextNodeEntry` (read, GUESS)

### VehicleConfigEntry

A single auto-load vehicle config entry: folder path, filter name, session value, and result path.

Methods: 

- `*(*(this+0x1C)+0x0)+0x00000000` `char* folderPath` (read, GUESS)
- `*(*(this+0x1C)+0x0)+0x00000008` `char* filterName` (read, GUESS)
- `*(*(this+0x1C)+0x0)+0x00000010` `int sessionValue` (read, GUESS)
- `*(*(this+0x1C)+0x0)+0x00000014` `char* resultPath` (read, GUESS)
- `*(*(*(this+0x1C)+0x0)+0x8)+0x00000000` `char filterStringBytes` (read, GUESS)

### EngineInitializer

Performs guarded one-time engine subsystem initialization (engine subsystems, sound interface vtable method, default-float buffer, session phase dispatch) and records completion in a flag byte.

Methods: `0x004347C0`

- `this+0x00000002` `byte initializedFlag` (read_write, GUESS)
- `this+0x00000008` `int sessionPhaseArg` (read, GUESS)

### CollisionTreeNode

Node in a collision contact tree; propagates a mass/contact double toward a target value, recursing into children (this+0x4C) and following the sibling link (this+0x5C).

Methods: `0x00448DE0`

- `this+0x00000004` `double targetValue` (read, GUESS)
- `this+0x00000010` `double storedValue` (read_write, GUESS)
- `this+0x0000004C` `CollisionTreeNode*[4] children` (read, GUESS)
- `this+0x0000005C` `CollisionTreeNode* sibling` (read, GUESS)

### CollisionSubsystem

Initializes the collision subsystem's global state blocks: config/render ids (0x007CCC38=26, 0x007CCD80=67, 0x007CCFDC=103, 0x007CCFEC=87), render state (0x007CD000=9000), and force-feedback/bound values (0x007CA57C..0x007CA588).

Methods: `0x0044CB00`, `0x0044D280`, `0x0044D880`, `0x0044E000`, `0x0044E780`


### CollisionSurfaceHolder

Holds a releasable surface/device object pointer and releases it through its vtable (+0x20, then +0x8) during cleanup, invalidating the pointer afterward.

Methods: `0x0044EFE0`, `0x0044FBE0`

- `this+0x00000004` `void* surfacePtr` (read_write, GUESS)
- `this+0x00000278` `int surfaceType` (write, GUESS)
- `this+0x00000080` `void* heldObjectPtr` (read_write, GUESS)
- `this+0x000002F4` `int versionCount` (write, GUESS)
- `*(this+0x4)+0x00000020` `vtable_fn surfaceReleasePrep` (read, GUESS)
- `*(this+0x4)+0x00000008` `vtable_fn surfaceRelease` (read, GUESS)
- `*(this+0x80)+0x00000020` `vtable_fn heldReleasePrep` (read, GUESS)
- `*(this+0x80)+0x00000008` `vtable_fn heldRelease` (read, GUESS)

### VehicleStateBroadcaster

Broadcasts two gated blocks of per-vehicle state (clamped float channels, byte-flag dwords, equality-comparison tiers) from this-struct fields into fixed process telemetry globals.

Methods: `0x004537B0`

- `this+0x00001140` `float block0FloatChannel00` (read, GUESS)
- `this+0x00001144` `float block0FloatChannel01` (read, GUESS)
- `this+0x00001148` `float block0FloatChannel02` (read, GUESS)
- `this+0x0000114C` `float block0FloatChannel03` (read, GUESS)
- `this+0x00001150` `float block0FloatChannel04` (read, GUESS)
- `this+0x00001154` `float block0FloatChannel05` (read, GUESS)
- `this+0x00001158` `float block0FloatChannel06` (read, GUESS)
- `this+0x0000115C` `float block0FloatChannel07` (read, GUESS)
- `this+0x00001160` `byte block0Flag00` (read, GUESS)
- `this+0x00001161` `byte block0Flag01` (read, GUESS)
- `this+0x00001162` `byte block0Flag02` (read, GUESS)
- `this+0x00001163` `byte block0Flag03` (read, GUESS)
- `this+0x00001164` `byte block0Flag04` (read, GUESS)
- `this+0x00001165` `byte block0Flag05` (read, GUESS)
- `this+0x00001166` `byte block0Flag06` (read, GUESS)
- `this+0x00001167` `byte block0Flag07` (read, GUESS)
- `this+0x00001168` `byte block0Flag08` (read, GUESS)
- `this+0x00001169` `byte block0Flag09` (read, GUESS)
- `this+0x0000116A` `byte block0Flag10` (read, GUESS)
- `this+0x0000116B` `byte block0Flag11` (read, GUESS)
- `this+0x0000116C` `byte block0Flag12` (read, GUESS)
- `this+0x0000116D` `byte block0Flag13` (read, GUESS)
- `this+0x0000116E` `byte block0Flag14` (read, GUESS)
- `this+0x0000116F` `byte block0Flag15` (read, GUESS)
- `this+0x00001170` `int block0EqualityValue0` (read, GUESS)
- `this+0x00001174` `int block0EqualityValue1` (read, GUESS)
- `this+0x00001178` `int block0EqualityValue2` (read, GUESS)
- `this+0x0000117C` `int block0EqualityValue3` (read, GUESS)
- `this+0x00001180` `int block0Enable` (read, GUESS)
- `this+0x0000153C` `float block1FloatChannel00` (read, GUESS)
- `this+0x00001540` `float block1FloatChannel01` (read, GUESS)
- `this+0x00001544` `float block1FloatChannel02` (read, GUESS)
- `this+0x00001548` `float block1FloatChannel03` (read, GUESS)
- `this+0x0000154C` `float block1FloatChannel04` (read, GUESS)
- `this+0x00001550` `float block1FloatChannel05` (read, GUESS)
- `this+0x00001554` `float block1FloatChannel06` (read, GUESS)
- `this+0x00001558` `float block1FloatChannel07` (read, GUESS)
- `this+0x0000155C` `byte block1Flag00` (read, GUESS)
- `this+0x0000155D` `byte block1Flag01` (read, GUESS)
- `this+0x0000155E` `byte block1Flag02` (read, GUESS)
- `this+0x0000155F` `byte block1Flag03` (read, GUESS)
- `this+0x00001560` `byte block1Flag04` (read, GUESS)
- `this+0x00001561` `byte block1Flag05` (read, GUESS)
- `this+0x00001562` `byte block1Flag06` (read, GUESS)
- `this+0x00001563` `byte block1Flag07` (read, GUESS)
- `this+0x00001564` `byte block1Flag08` (read, GUESS)
- `this+0x00001565` `byte block1Flag09` (read, GUESS)
- `this+0x00001566` `byte block1Flag10` (read, GUESS)
- `this+0x00001567` `byte block1Flag11` (read, GUESS)
- `this+0x00001568` `byte block1Flag12` (read, GUESS)
- `this+0x00001569` `byte block1Flag13` (read, GUESS)
- `this+0x0000156A` `byte block1Flag14` (read, GUESS)
- `this+0x0000156B` `byte block1Flag15` (read, GUESS)
- `this+0x0000157C` `int block1Enable` (read, GUESS)

### CollisionBody

Collision/body object storing body mass and inverse mass for a rigid body.

Methods: `0x00459950`

- `this+0x00000180` `double bodyMass` (write, GUESS)
- `this+0x00000188` `double inverseMass` (write, GUESS)

## Compatibility contracts

- **VehicleSetupFileFormat** — Text setup file layout written by VehicleSetupSerializer: a 'General' header, multi-chunk notes section copied 128 bytes at a time, and labeled key/value blocks for symmetric/CG/wedge/tire/fuel/pitstops, fenders/wings, body aero, suspension, controls, engine, gear ratios, driveline, differential, per-wheel corner settings, and a basic setup section; repeated values separated by the word_5C30B4 token; gear ratios min-clamped before the driveline block. The numeric formatting of each parameter is not evidenced by the packet.
- **VehicleTelemetryGlobalState** — Two gated broadcast blocks in BroadcastVehicleStateToGlobals: each pushes 8 float channels (zeroed when a channel crosses a low or high threshold global) into a fixed output global pair, dispatches 16 byte flags into fixed dword globals via ConditionalFieldSetterWithState, and when the enable word sign bit is set writes equality-comparison booleans from four this-struct dwords against reference globals (bit-gated tiers 0x100/0x200/0x400). A replacement executable must write the same globals when the enable bits are set.
- **CollisionSubsystemGlobalState** — Collision subsystem global-state blocks established by the CollisionSubsystem initializer family: config/render ids 0x007CCC38=26, 0x007CCD80=67, 0x007CCFDC=103 (with 0x007CCFE0=0.0), block tag 0x007CCFEC=87 and render state 0x007CD000=9000, plus force-feedback/bound values 0x007CA57C=61, 0x007CA580=0, 0x007CA584=-1082130432, 0x007CA588=0. A replacement must seed the same blocks.
- **PhysicsSystemGlobalState** — Physics-system module owns a doubly-linked list header (0x007C73E8), two node lists (heads 0x007C7418 and 0x007C7404 with their tail words) and two flagged allocation blocks (0x007C73F8, 0x007C73F0) that are released and zeroed on shutdown. A replacement must own and release the same global list state.
- **VehicleSessionPlacementContract** — Multiplayer placement state 0-7 semantics: session-active state 5 copies every vehicle via FieldCopy(+16436) and transitions to 7 reorder standings and FieldCopy_c330 all vehicles; inactive-session transitions 4->5, 5->6, 6->7 copy vehicle fields (with season-data free when championship dword_7D0410==4); committed state is written to dword_7D00EC clamped into [dword_7D00F4, dword_7D00F8], returning the previous dword_7D00F4. Vehicle array base is dword_7C54F0 with count dword_5C329C.
- **VehicleConfigListFileContract** — Auto-load vehicle config list persisted via ConfigFileParser to the path buffer byte_7CE498; entries carry a folder path, a filter name, a session value, and a result path, and are matched against the resolved settings folder (dword_7CE5EC) and active game filter (dword_7CE64C dispatch record, filter string at +444) with the session type mapped by dword_7C56A4.

## Unresolved

- The owning object of the mode-dispatched transform helper (0x0040F300) is unknown; why SessionStructureCleanup reaches this render/physics dispatch is not established, and the wheel-contact input contract of WheelContactTransform is outside the function.
- Semantics of the placement states 0-7 and the transition-state enum for MultiplayerVehiclePlacement are only partially evidenced (DERIVED from guards and caller context).
- sub_462E20 (non-active-session counterpart of ChampionshipStandingsReOrdering) and sub_4C01A0's mutation of the local a2 are unknown; sub_4C01A0 receives &a2 so mutations are invisible in the decompilation.
- Global dword_7D2DB0 (race-standings sort buffer) is listed as read but never referenced in the raw source.
- Semantics of the setup-file string literals and the numeric formatting of each parameter are inferred only from symbol names; the mapping of the per-wheel write loop to setup fields beyond this+0x16C4/this+0x1704 is not established.
- Global jump table jpt_4303CA (0x004305E4) is listed in globals evidence but does not appear directly in the decompiled switch.
- ShortComputation_0b10 (0x004B0B10) identifier meaning and the contents of off_5C3F84[0] (presumed extension) are not resolvable from the packet.
- unk_8AC388 and dword_8AD298 are listed as accessed globals but absent from the raw source; their roles are unknown.
- The collision node list layout (only a next pointer at node+4 observed) and the distinct roles of the two freed node lists / two flagged blocks in shutdownPhysicsSystem are inferred, not proven.
- Semantics of the four collision init literals (103, 26, 67, 87, 9000, 61, -1082130432) and the owning subsystem objects are DERIVED from existing analysis, not proven by the packet.
- The vtable methods invoked at +0x20 and +0x8 on the surface/held objects (0x0044EFE0, 0x0044FBE0) have no callee addresses; existing analysis interprets them as Direct3D unacquire/Release, which is an interpretation only.
- The collision-tree double (0x00448DE0) is described as mass-related but its physical meaning and why children are visited before the sibling are not determinable from this packet.
- The D3DShaderConstantSetup source regions and the this+4 substruct passed to sub_44F150 are not in the packet field list; their layouts are unknown here.
- The float clamp threshold/output global pairs in BroadcastVehicleStateToGlobals write two output globals per source channel; the downstream subsystem meaning of each output global is not determinable from this function alone.
- BroadcastVehicleStateToGlobals and CollisionSubsystemInit write overlapping global ranges (0x007CCC38, 0x007CCFDC, 0x007CCFE0, 0x007CD000 appear in both); the shared ownership of these blocks is not proven.
- The recursive child argument passed to PhysicsTreeMassPropagation (the child pointer from this+0x4C) is inferred rather than proven.
- Global flt_59E440 is flagged by packet facts but appears nowhere in the raw source for 0x004537B0; its role (possibly an initialization constant for sub_44F150) is not verifiable.
