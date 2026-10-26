# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `GUESS`

Derived architecture proposal for 26 validated functions in scope generic_runtime_objects. All packet owners are UNKNOWN, so six GUESS classes are proposed from call structure and shared field patterns: CameraManager (0x0040C140 config loader, 0x0040C240 scene cam-file loader, 0x0040C3B0 module-asset resolver, 0x0040C520 cross-link; init chain called from CamMan_Init 0x0040C920), CameraDirector (0x0040BE70 input mapper, 0x0040C070 random countdown trigger, 0x0040C5B0/0x0040C650 mode change/assignment, 0x0040C7A0 target update, 0x0040C8D0 mode-state resolver, 0x0040D290 race-leader target, 0x0040D360 random-range compute, 0x0040DB00 target-name resolver; driven from MainCameraDirectorUpdate 0x0040CA30), RaceCommentaryDirector (0x0040DD30 conditional delegation, 0x0040DD80 pit-timer advance, 0x0040DDF0 cinematic-event state machines feeding RaceCommentaryDirectorSystem 0x0040D4C0), DispatchHelper (0x0040C870 vtable+0x18 cached dispatch, 0x0040C910 sub-object field fetch), GameActionStateMachine (0x0040D450 state reset wrapper around 0x0040CDE0), and ModeDispatchObject (0x0040E6D0/0x0040E860/0x0040E880/0x0040E8B0 struct initializers with mode discriminator at +0x1C, 0x0040ED10 position/magnitude computation, 0x0040F380 eight-mode state handler, 0x0040E480 light-frustum closest-point). CameraDirector, RaceCommentaryDirector and GameActionStateMachine all feed the shared GameActionStateMachine interface (0x0040CDE0); the camera layer reads vehicle offsets +0x4894/+0x48CC through the dword_7C54F0 pointer array. Equal offsets on distinct `this` objects were kept separate; see unresolved.

## Function roles

- `0x0040BE70` **CameraDirector** — Maps 16-bit input action codes (word_7CB21C / dword_7CB218) to camera actions: 74/78 CameraTargetRaceLeader(1/0), 156 CameraTargetCurrentTrackedVehicle, 199/201/209/210 gated camera-mode changes via CameraLockCheck + GameActionStateMachine pairs; one-shot flag at this+0x2C forces return 1
- `0x0040C070` **CameraDirector** — Random countdown-triggered camera state machine: gate this+0x24, float timer this+0x3C decremented by ScoringGateConditionCheck per tick; on expiry picks a random state {0,3,4,5} via LCG, issues GameActionStateMachine transition(s), 1-in-3 chance CameraTargetRaceLeader(1), runs ShortComputation_d360 over this+0x30/0x34
- `0x0040C140` **CameraManager** — Lazy camera configuration loader: allocates/initializes the 84-byte config object at this+0x18, loads cams.cfg then default.cfg through its vtable+4 method from dword_5EC440 (fallback byte_5EA438), runs F_3DTransformObjectAllocator, then GameStateBranchDispatch
- `0x0040C240` **CameraManager** — Scene cam-file loader: lazily allocates/initializes the 24-byte scene loader at this+0x1C, derives a <name>cam path from the scene array entry (dword_8AC490 + 396*dword_8AC48C) and loads it via the loader's vtable+4 method
- `0x0040C3B0` **CameraManager** — Module asset path resolver: lazily allocates/initializes the 24-byte module loader at this+0x20, builds the same <name>cam scene-array path and invokes the loader's vtable+4 method
- `0x0040C520` **CameraManager** — Cross-links two objects: writes this+0x1C into *(this+0x20)+8 and this+0x20 into *(this+0x1C)+8, returning this+0x1C
- `0x0040C5B0` **CameraDirector** — Requests a camera mode change: early-exit when player vehicle (dword_7C54F0[dword_7C54DC]) and current vehicle (dword_7C54F0[dword_7C54E4]) carry the same +0x4894 mode; applies requested mode this+0xC (-1/1/2, mode 2 gated on dword_7CFCC8) by writing this+0x14 and calling GameActionStateMachine(5, 0)
- `0x0040C650` **CameraDirector** — Assigns the camera view based on whether target a2 equals the occupant at VehiclePtrArray[CurrentVehicleIndex]+18580: re-applies stored mode this+0x14 via GameActionStateMachine and clears it, dispatches modes 1-2 through the 0x0040C610 gate, and handles mode 3 (gated on the byte at dword_7C54E0+13388) via GameActionStateMachine(2,0) or (5,0)
- `0x0040C7A0` **CameraDirector** — Updates the camera target when the player's vehicle changes: compares this[14]=0x38 with the player vehicle's target field (0x48CC); on change stops per-vehicle sound over the unk_5ECDC8 array (stride 18624, byte_7C5BC8 sentinel), picks a new mode from dword_7CFDC4/dword_7CFCC8 or via StateCheckWithTernaryLogic, emits it through AudioSoundEffectController, and stores the new target
- `0x0040C870` **DispatchHelper** — Virtual dispatch helper with cached-result early-out: returns cached this+0x28 when non-zero, else calls the component at this+0x8 vtable+0x18 slot; returns 0 on null component
- `0x0040C8D0` **CameraDirector** — Camera-mode state resolver with fallback: primary value this+0xC, fallback from *(this+0x18)+0x40 when zero; maps resolved 0 -> 3, 1 -> 1, 2 -> (dword_7CFCC8==0), else 0
- `0x0040C910` **DispatchHelper** — Trivial field accessor: returns the dword at *(this+0x8)+4; shared by camera director, car-selection, render-setup and comparison callers
- `0x0040D290` **CameraDirector** — Targets the race leader relative to the player: reads player vehicle (dword_7C54F0[dword_7C54DC]) +0x4894 finish position, shifts +1/-1 from flag a2, resolves the team id via GetTeamIDByFinishPosition, dispatches through GameStateDispatchChain
- `0x0040D360` **CameraDirector** — Random-range compute/store: sets the updated flag this+0x2E, clamps min (this+0x30) and max (this+0x34, fallback min+5), draws an LCG value, stores min+(rand%(max-min)) as float this+0x3C, returns the LCG quotient
- `0x0040D450` **GameActionStateMachine** — Conditional state reset: when the state dword this+0x14 equals 3, resets it to -1 and dispatches GameActionStateMachine(this, 3, 0), returning its result; otherwise returns without action
- `0x0040DB00` **CameraDirector** — Camera target name resolver: empty name returns 0; compares against Player (0x005BEB3C) -> ModeDispatchedSubsystemCall(&dword_5EA510), Original (0x005BEB30) -> this+0x8C, Last (0x005BEB28) -> this+0x90, AnyTrackside (0x005BEB18) -> 0, else unless None (0x005BEB10) TracksideCameraTargetLookup(*(this+4), a2)
- `0x0040DD30` **RaceCommentaryDirector** — Conditional delegation to the race-commentary director: returns 0 when this[34]=0x88 is null or *(this[34]+4) fails ShortComputation_adb0; otherwise re-derives the value and delegates to RaceCommentaryDirectorSystem(this[34], value)
- `0x0040DD80` **RaceCommentaryDirector** — Pit-timer advance state machine: states -1/0/1/5 blocked, 2/3 run VirtualDispatchHelper on this+0x4, store the result at this+0x8C/0x90, write dword_7C54DC to this+0x94, transition to state 4; state 4 active returns 1; any other state is an error (state=-1)
- `0x0040DDF0` **RaceCommentaryDirector** — Cinematic-event state machine: states 2-5 search the string-keyed list for CinematicEvent (0x005BEB50) and hand it with this+0x88 to RaceCommentaryDirectorSystem; success clears this+0x98/0x9C and sets state 2, failure sets state -1; states -1/0/1 blocked
- `0x0040E480` **ModeDispatchObject** — Light-frustum closest-point search: computes the bounding box, derives center and half-diagonal radius, then a 5x5x5 grid search keeps the sample minimizing max squared distance to any packed-array element (via LinkedListIndexedAccessor_c230/PackedArrayTotalSize/PackedArrayIndexLookup); writes result to a2 and radius to *a3
- `0x0040E6D0` **ModeDispatchObject** — Straight-line struct initializer with sentinels: this+0 = -1, +4 = 0x7FFFFFFF, +8 word = -1, +0xA byte = 0, +0xC/+0x10/+0x14/+0x18 = 0, +0x1C = 9, +0x20 = 0; returns this
- `0x0040E860` **ModeDispatchObject** — Straight-line field setter: word this+0x8 = a2, dword this+0x1C = 6, dword this+0x20 = a3; returns a2
- `0x0040E880` **ModeDispatchObject** — Struct field initializer: word this+0x8 = a2, dword this+0x1C = 7, dword this+0x20 = a3, then calls the un-resolvable ShortComputation_e770(this, a3, 0) and returns its result
- `0x0040E8B0` **ModeDispatchObject** — Struct setup (subtype 8): word this+0x8 = a2, dword this+0x1C = 8, dword this+0x20 = a3, calls LightFrustumClosestPoint(a3, this+0x0C, this+0x18) and returns NestedLoopRangeTraversal(this)
- `0x0040ED10` **ModeDispatchObject** — Mode-dispatch position/magnitude computation (modes 0-7 on this[7]=0x1C): modes 0-5 query sub-object +0xD0 via TripleFieldQuery + sqrt(MaxSquaredMagnitudeSearch); mode 6 copies sub-object +0x34D4/0x34D8/0x34DC/0x3B70; mode 7 uses bounding-box center/half-diagonal unless sub-object +0x3C bit 0x10 is set
- `0x0040F380` **ModeDispatchObject** — Eight-mode state handler (this[7]=0x1C): modes 0/1/3/4/5 run AABB collision + contact response via F_3DCollisionDetectionWithAABBTestAndContactResp; mode 2 runs wheel-contact distance, visibility toggles and a UI-focus change; mode 6 gates the same path on *(this+0x20)+0x48BC bit 0; mode 7 uses a null vector

## Proposed classes

### CameraManager

Camera-manager initialization layer (called from CamMan_Init 0x0040C920): lazily allocates and vtable-initializes a config object (this+0x18), a scene cam-file loader (this+0x1C) and a module-asset loader (this+0x20), loads cams.cfg/default.cfg and the scene cam file, cross-links the two loaders, and processes 3D transforms. All packet owners are UNKNOWN; this grouping is GUESS.

Methods: `0x0040C140`, `0x0040C240`, `0x0040C3B0`, `0x0040C520`

- `this+0x00000018` `pointer configObjectPtr` (read_write, DERIVED)
- `this+0x0000001C` `pointer sceneLoaderPtr` (read_write, DERIVED)
- `this+0x00000020` `pointer moduleLoaderPtr` (read_write, DERIVED)
- `this+0x00000024` `unknown recordedUnused_24` (unknown, GUESS)
- `this+0x00000028` `unknown recordedUnused_28` (unknown, GUESS)
- `*(this+0x18)+0x00000004` `function_pointer configVtableLoadSlot` (read, DERIVED)
- `*(this+0x1C)+0x00000004` `function_pointer sceneLoaderVtableLoadSlot` (read, DERIVED)
- `*(this+0x20)+0x00000004` `function_pointer moduleLoaderVtableLoadSlot` (read, DERIVED)

### CameraDirector

Runtime camera-control object driven by MainCameraDirectorUpdate (0x0040CA30): maps input action codes to camera actions, runs a random countdown camera-mode trigger, requests/assigns camera modes through GameActionStateMachine, updates the target on player-vehicle change, resolves camera target names, targets the race leader, and holds the random-range state (this+0x30/0x34/0x3C) and stored/requested mode slots. All packet owners are UNKNOWN; grouping is GUESS.

Methods: `0x0040BE70`, `0x0040C070`, `0x0040C5B0`, `0x0040C650`, `0x0040C7A0`, `0x0040C8D0`, `0x0040D290`, `0x0040D360`, `0x0040DB00`

- `this+0x00000008` `pointer trackedTargetPtr` (read, GUESS)
- `this+0x0000000C` `int requestedMode` (read, DERIVED)
- `this+0x00000014` `int storedMode` (read_write, DERIVED)
- `this+0x00000018` `pointer trackedTargetPtr2` (read, GUESS)
- `this+0x00000024` `byte actionDisableGate` (read, GUESS)
- `this+0x0000002C` `byte oneShotFlag` (read_write, GUESS)
- `this+0x0000002E` `byte rangeUpdatedFlag` (write, DERIVED)
- `this+0x00000030` `float randomRangeMin` (read_write, DERIVED)
- `this+0x00000034` `float randomRangeMax` (read_write, DERIVED)
- `this+0x00000038` `int currentTargetId` (read, DERIVED)
- `this+0x0000003C` `float randomTimerOrValue` (read_write, DERIVED)
- `this+0x0000004C` `unknown recordedUnused_4C` (unknown, GUESS)
- `this+0x0000008C` `pointer originalTargetPtr` (read, GUESS)
- `this+0x00000090` `pointer lastTargetPtr` (read, GUESS)
- `this+0x000048A0` `unknown recordedUnused_48A0` (unknown, GUESS)
- `this+0x000048CC` `int playerVehicleTargetField` (read, GUESS)
- `*(this+0x18)+0x00000040` `int targetValidityFlag` (read, GUESS)

### RaceCommentaryDirector

State-machine layer that feeds RaceCommentaryDirectorSystem (0x0040D4C0): a pit-timer advance state machine (state word this+0x0, dispatch via VirtualDispatchHelper on this+0x4, results at this+0x8C/0x90, current player index this+0x94) and a cinematic-event state machine (string-keyed CinematicEvent lookup, substruct this+0x88, counters this+0x98/0x9C), plus a conditional delegation guard. All packet owners are UNKNOWN; grouping is GUESS.

Methods: `0x0040DD30`, `0x0040DD80`, `0x0040DDF0`

- `this+0x00000000` `int stateWord` (read_write, DERIVED)
- `this+0x00000004` `pointer dispatchComponentPtr` (read, DERIVED)
- `this+0x00000088` `pointer substructPtr` (read, DERIVED)
- `this+0x0000008C` `int dispatchResultSlot1` (read_write, DERIVED)
- `this+0x00000090` `int dispatchResultSlot2` (write, GUESS)
- `this+0x00000094` `int currentPlayerIndex` (write, DERIVED)
- `this+0x00000098` `int counter_98` (write, DERIVED)
- `this+0x0000009C` `int counter_9C` (write, DERIVED)

### DispatchHelper

Generic virtual-dispatch and field-access helpers reused across many subsystems (callers include MainCameraDirectorUpdate, PitTimer, car selection, render setup): 0x0040C870 caches a vtable+0x18 dispatch result at this+0x28 and 0x0040C910 returns the dword at *(this+0x8)+4. All packet owners are UNKNOWN; grouping is GUESS.

Methods: `0x0040C870`, `0x0040C910`

- `this+0x00000008` `pointer componentPtr` (read, DERIVED)
- `this+0x00000028` `int cachedResult` (read, DERIVED)
- `*(this+0x8)+0x00000018` `function_pointer componentVtableSlot18` (read, DERIVED)

### GameActionStateMachine

Game-wide action/state transition dispatcher (callee 0x0040CDE0) plus thin wrappers. 0x0040D450 resets the state dword this+0x14 to -1 when it equals 3 and dispatches action 3. Owns no packet-confirmed fields beyond the wrapper state slot; the main 0x0040CDE0 implementation is outside this packet. GUESS.

Methods: `0x0040D450`

- `this+0x00000014` `int stateCode` (read_write, DERIVED)

### ModeDispatchObject

GUESS grouping of a shared struct-with-subtype initialized by 0x0040E6D0/0x0040E860/0x0040E880/0x0040E8B0 (word subtype at +0x8, mode discriminator constant 6/7/8/9 at +0x1C, external data at +0x20) and dispatched by 0x0040ED10 (position/magnitude computation, modes 0-7) and 0x0040F380 (state handling, modes 0-7), with 0x0040E480 as a light-frustum closest-point helper. All packet owners are UNKNOWN; grouping is GUESS.

Methods: `0x0040E480`, `0x0040E6D0`, `0x0040E860`, `0x0040E880`, `0x0040E8B0`, `0x0040ED10`, `0x0040F380`

- `this+0x00000000` `int sentinelMinusOne` (write, DERIVED)
- `this+0x00000004` `int sentinelMax` (write, DERIVED)
- `this+0x00000008` `word subtypeWord` (read_write, DERIVED)
- `this+0x0000000A` `byte subtypeHighByte` (write, DERIVED)
- `this+0x0000000C` `float positionX` (read_write, DERIVED)
- `this+0x00000010` `float positionY` (read_write, DERIVED)
- `this+0x00000014` `float positionZ` (read_write, DERIVED)
- `this+0x00000018` `float magnitudeRadius` (read_write, DERIVED)
- `this+0x0000001C` `int modeDiscriminator` (read_write, DERIVED)
- `this+0x00000020` `pointer subObjectPtr` (read, DERIVED)
- `this+0x000000F0` `int uiFocusTarget` (read, GUESS)
- `this+0x00000158` `double vectorDouble_158` (read, GUESS)
- `this+0x00000160` `double vectorDouble_160` (read, GUESS)
- `this+0x00000168` `double vectorDouble_168` (read, GUESS)
- `this+0x00000708` `pointer wheelContactPtr` (read, GUESS)
- `*(this+0x20)+0x0000003C` `byte subObjectFlag3C` (read, GUESS)
- `*(this+0x20)+0x000000D0` `pointer subObjectPtrD0` (read, GUESS)
- `*(this+0x20)+0x000034D4` `float subObjectPosX` (read, DERIVED)
- `*(this+0x20)+0x000034D8` `float subObjectPosY` (read, DERIVED)
- `*(this+0x20)+0x000034DC` `float subObjectPosZ` (read, DERIVED)
- `*(this+0x20)+0x00003B70` `float subObjectRadius` (read, DERIVED)
- `*(this+0x20)+0x000048BC` `byte subObjectVtableFlag48BC` (read, GUESS)

## Compatibility contracts

- **CameraConfigFileLoad** — CameraConfigLoader (0x0040C140) truncates the 512-byte path buffer via PathTruncationUtility, appends 'cams.cfg', loads it through a lazily allocated 84-byte config object's vtable+4 method from the settings directory dword_5EC440 (fallback byte_5EA438), then appends 'default.cfg' and loads that too; on success it runs F_3DTransformObjectAllocator and GameStateBranchDispatch. A replacement must preserve the two config filenames, the load order and the directory globals.
- **SceneCamFileNaming** — SceneFileLoadByCurrentIndex (0x0040C240) and ModuleAssetPathResolver (0x0040C3B0) derive a '<basename>cam' asset path from the current scene-array entry (dword_8AC490 + 396*dword_8AC48C): the entry's file name is trimmed at the last backslash and dot, then the 'cam' suffix string (0x005BE880) is appended, and the result is loaded through a 24-byte loader object's vtable+4 method. A replacement must preserve the 396-byte scene stride and the '<name>cam' suffix.
- **GameActionStateMachineCallingConvention** — Camera and state-machine functions dispatch through GameActionStateMachine(actionId, immediateFlag) (0x0040CDE0) using action ids 0/3/4/5 (camera modes) and 2/5 (occupant views), usually gated by CameraLockCheck (0x0040C720); a non-zero return means the action was consumed. CameraModeChangeRequest (0x0040C5B0) records the requested mode at this+0x14 and calls (5,0). A replacement must keep the action-id and consumed-return convention.
- **VehicleTargetOffsetContract** — The camera layer reads the current occupant/finish-position id at vehicle+18580 (0x4894) from the active pointer array dword_7C54F0 indexed by CurrentPlayerIndex dword_7C54DC / CurrentVehicleIndex dword_7C54E4, and reads the player's stored camera target at vehicle+0x48CC (packet field this+0x48CC); GetTeamIDByFinishPosition (0x0040C540) consumes the +0x4894 value. A replacement must preserve these vehicle offsets and pointer-array indices.
- **CameraTargetNameStrings** — CameraTargetNameResolver (0x0040DB00) compares a2 against the string literals at 0x005BEB10 (None), 0x005BEB18 (AnyTrackside), 0x005BEB28 (Last), 0x005BEB30 (Original) and 0x005BEB3C (Player) using sub_588410 (0 means equal), returning this+0x8C/0x90 target pointers or delegating to TracksideCameraTargetLookup. A replacement must keep the exact string spellings and the sub_588410 return convention.
- **ModeDispatchObjectLayout** — StructInitializerWithSentinelValues/StructFieldTripletSetter/InitializeStructFields/StructSetupWithTwoCalls initialize a common layout: dword +0x0 sentinel -1, +0x4 sentinel 0x7FFFFFFF, word +0x8 subtype, byte +0xA, dword +0x1C mode discriminator (6/7/8/9), dword +0x20 external data, position vector +0xC/+0x10/+0x14 and radius +0x18; ComputePositionMagnitude (0x0040ED10) and SwitchBasedStateHandler (0x0040F380) dispatch on the +0x1C mode. A replacement must preserve this layout and dispatch.

## Unresolved

- All 26 packet owners are UnknownObject/UNKNOWN; every proposed class (CameraManager, CameraDirector, RaceCommentaryDirector, DispatchHelper, GameActionStateMachine, ModeDispatchObject) is GUESS. No CONFIRMED/FACT ownership is claimed.
- Equal offsets on distinct `this` objects are deliberately NOT merged across classes (rule: base+offset identity). Examples kept separate: this+0x8C/0x90 in both CameraDirector (Original/Last target pointers) and RaceCommentaryDirector (dispatch result slots); this+0x14 in CameraDirector (storedMode), ModeDispatchObject (positionZ) and GameActionStateMachine (stateCode); this+0x18 in CameraDirector (trackedTargetPtr2) and ModeDispatchObject (magnitudeRadius); this+0x8 and this+0x28 in CameraManager/DispatchHelper. The packet does not prove common ownership.
- RandomRangeCompute (0x0040D360) and RandomStateMachineWithTimerAndTrigger (0x0040C070) both touch this+0x30/0x34/0x3C, and 0x0040C070 calls 0x0040D360 passing its +0x30/+0x34 fields, which suggests one shared random-range state; modeled here as a single CameraDirector owning those offsets, but identical-this is not proven.
- Semantics of the per-action camera-mode ids (0/3/4/5), the GameActionStateMachine state transitions, and the 16-bit input action codes 74/78/156/199/201/209/210 in the input system are unresolved (mapping derived from case bodies only).
- Meaning of the byte at dword_7C54E0+13388 and of byte_7CFE88 in the action-201 gate (0x0040BE70); why dword_7CFCC8 gates only mode 2 in CameraModeChangeRequest (0x0040C5B0) is unproven.
- The camera-mode dispatch selector dword_7CFDC4 vs queued-flag dword_7CFCC8 mapping and the emitted mode values (0/1/2/3) in CameraTargetUpdateOnPlayerChange (0x0040C7A0) are not established.
- The vehicle byte offset 18580 (0x4894) is read via a literal in some raw code while the packet field table labels the player target field this+0x48CC; the exact vehicle field names are unknown.
- Whether AudioSoundEffectController (0x004E0ED0) plays a mode-indexed sound or drives a state selector is unresolved.
- VirtualDispatchHelper (0x0040C870) vtable+0x18 slot semantics (getter/update/state transition) are unknown; why AdvancePitTimerStateMachine (0x0040DD80) stores the dispatch result into both this+0x8C and this+0x90 is unresolved.
- Jump-table globals (0x0040BFC4, 0x0040BFE4, 0x0040C128, 0x0040C600, 0x0040DDC8, 0x0040DE4C, 0x0040DE54, 0x0040EEA0, 0x0040F484) are structural evidence; byte_40DE54 (0x0040DE54) is flagged read but never appears in the raw decompiled bodies.
- Globals flt_59E440, flt_59E450, off_59E604, flt_59E6EC, dword_8AB710 and byte_7CE498 are flagged read by packet facts but absent from the raw decompiled source; their roles are unverifiable from this packet.
- ModeDispatchObject mode enums (0-7), the sub-object +0x3C flag bit 0x10, +0xD0 pointer, 0x34D4/0x34D8/0x34DC/0x3B70 fields and +0x48BC bit-0 gate, and the F380 offsets 0xF0/0x158/0x160/0x168/0x708 have no established semantics.
- The scene-array layout (base dword_8AC490, index dword_8AC48C, stride 396, file name at entry+4) is derived from pointer arithmetic, not a named struct; aCam (0x005BE880) has a dual role (cam suffix here, vehicle-data string elsewhere) that is unresolved.
- StateResetOnCondition (0x0040D450) returns an uninitialized register on its non-matching path (likely dead code or a decompiler artifact); the caller TrackTemperatureDisplay (0x004D37B0) context is outside this packet.
- ShortComputation_e770 called by InitializeStructFields (0x0040E880) has no address and no packet callee entry; its identity and side effects are unverified.
- First argument a1 of LightFrustumClosestPoint (0x0040E480) is unused in the decompiled body; its field labels this+0x0/0x4/0x8 correspond to the output vector and the owning object type is unknown.
- RaceCommentaryDirectorSystem (0x0040D4C0) return-value semantics and the substructs at this+0x88/0x8C/0x90 in the commentary director object are unevidenced.
- dword_5EA510 (target of ModeDispatchedSubsystemCall in 0x0040DB00; existing fill labels it SessionManager at DERIVED level) role is unresolved.
- Whether the CameraDirector object is vehicle-anchored (fields at 0x48A0/0x48CC, reads of vehicle +0x4894) is GUESS, not established.
