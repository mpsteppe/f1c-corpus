# VehicleAIAndPit

Scope: `vehicle_ai_and_pit`  
Trust: `DERIVED`

DERIVED architecture for the vehicle_ai_and_pit wave-004 packet. The core is a per-driver pit machine (F1CPitMachine) whose +0x184 state field enumerates idle/entering/in-pit/exiting/post-collision and is driven each frame by PitStateUpdateMachine (0x004A6E50), with StateConditionalAction (0x004A5E40) mapping states 0/4 to a state-1 transition and ExitPitsUnderRedHandler (0x004A5F20) handling the one-shot red-flag exit path including penalties. Supporting pit objects are proposed as F1CPitTimingManager (the pit-timing tick), F1CPitServiceSteering (the pit-service steering animation step state machine) and F1CPitCrewMachine (the pit-entry/exit trigger machine that hides/shows the driver model and resets vehicle AI). Vehicle AI side: AIVehicleState (AI state reset), DriverTargetClassifier (per-slot 0/-1/1/2 plus scoring-target 3), AIOvertakeBehavior (time-gated overtake activation) and TireCompoundSettings plus the ITireCompoundLookup string mapper. Several packet functions are out-of-scope helpers grouped as interfaces (path/rect utilities, camera follow, network/session UI dispatch, collision dispatch, constraint-solver cleanup, contact-pair list builder). All ownership beyond the packet-confirmed pit machine is GUESS/DERIVED; conflicting or weakly-evidenced globals are left in unresolved rather than forced into a clean design.

## Function roles

- `0x0040D9FC` **IConstraintSolverCleanup** — Destructor-chain teardown: frees the this+0x88 block, destroys the linked list at this+0x4C, re-initializes the constraint-solver params sub-struct at this+0x14, and returns the init result. Owner object type unknown.
- `0x00418EE0` **DriverTargetClassifier** — Per-slot driver classification into the this output array (0 default, -1 retired/invalid, 1 player, 2 teammate) over the vehicle entries at unk_5F0CF8; in race mode picks a scoring/overtake target via position and scoring deltas and promotes it to class 3, returning its slot index or -1.
- `0x0041B910` **IAIPitSelection** — Clears pit-selection flags 123/124/125 on the shared pointer-table entry flt_5EA618 via BooleanOROfTwoChecks, gated by race-active dword_7D0308, track-condition flt_7CF3C8, race phase dword_7C56A8!=8 and action id a1==5; invoked once per frame by the AI pit-logic path sub_4BCCC0.
- `0x00421890` **IPathStringUtilities** — Path-string helper: appends a trailing backslash separator (word_5C2AAC two-byte value) to a non-null, non-empty caller-owned buffer and returns the final character.
- `0x0042AF40` **AIVehicleState** — Unconditional AI driver state reset on a vehicle object: notifies StateChangeNotify(0), evaluates ConditionalGate at this+12, sets this+0x4410 to 1, clears this+0x45F4 to 0, and returns the gate result.
- `0x00434D60` **CameraFollowController** — Per-frame camera-follow routine: interpolates a steering/look angle toward the tracked target and issues vtable follow calls; fixed-camera fallback when the vehicle index is invalid or camera mode is 5.
- `0x004496D0` **IContactPairListBuilder** — Links a run of 0x20-byte nodes at this+0x8 into a singly linked list by writing each node's next pointer at +0x1C; returns the buffer base, or 0 when the element count at this+0 is zero.
- `0x004584A0` **CameraNode** — Object initializer: writes the vtable pointer at 0x0059F00C into this[0], runs a cleanup/zero-init helper (ConditionalFreeAndStructZeroInit), and returns a short computation over this.
- `0x0046DA20` **ISessionUiDispatch** — Session/UI dispatch chain: sets a session-type flag via sub_42D210 on dword_7C569C, creates a UI element (id 30) through the vtable slot at this[16], activates it via sub_46BF10, calls the input/force-feedback helper sub_4D2450 with dword_8ACEE0, then invokes the vtable callback at slot 14.
- `0x00475570` **INetworkUiRefresh** — Conditional UI network-list refresh: calls the network-state probe on dword_7CD25C, then refreshes via sub_475150 when the state-change check passes; always returns 0.
- `0x00491600` **IRectClampUtilities** — Clamps a short[4] rectangle (this+0x0..+0x6) in place into the min (a2,a3) / max (a2+a4, a3+a5) bounds, shrinking dimensions as edges move inward, and returns the bottom bound.
- `0x0049D070` **SteeringWheelHud** — Steering-wheel HUD element update/render: selects an engine input mode from dword_7C54E0, conditionally runs a draw pass plus an audio/animation chain, then advances five lerped animation parameters toward their targets.
- `0x004A4830` **ITireCompoundLookup** — Tire-compound name to id mapper: Hard=2, Soft=3, Intermediate=4, Wet=5, Monsoon=6, any other string=1, via chained string comparisons through sub_588410.
- `0x004A5600` **F1CPitMachine** — Pit-stop state machine transition: swaps the active sub-object at this+0x8, cleaning up the outgoing sub-object (unless operation state at this+0x184 is a blocking state) and either reinitializing (sub_4A3390) or activating (FlagBasedLoopConditionalCall) the new sub-object.
- `0x004A5E40` **F1CPitMachine** — Pit-machine state-conditioned action: reads the AI mode state at this+0x184 and, when it is 0 or 4, dispatches a state-1 transition via StateChangeNotify(this, 1); otherwise returns the state unchanged. Called by ForcePitExit on the frame path.
- `0x004A5F20` **F1CPitMachine** — Pit-state handler fired once on the one-shot flag this+0x180: notifies state 0, clears the flag, increments the vehicle pit-exit counter at vehicle+0x406C, calls AIFormationLap, and per race-config applies a disqualification or time penalty; returns the sub-object helper result when this+0x14 is non-null.
- `0x004A6E50` **F1CPitMachine** — Per-frame pit state machine dispatcher: reads the pit state at +0x184 and routes states 0/1/2/3/4 through session gates, collision avoidance, control-disabled collision forcing state 4, entering-timeout, in-pit proximity transition to state 3, exiting pit-stop progress and pit-stop readiness, then runs the tail one-shot handlers (exit-under-red and the +0x1AC flag).
- `0x004AF220` **TireCompoundSettings** — Tire-compound selector and clamp: switches the mode at this+0x1B34 (cases 1-4) writing compound value/index with per-object min/max clamping; any other mode returns without state change.
- `0x004B42E0` **ICollisionDataDispatch** — Dispatches a collision data block through the conditional dispatcher: header (code 4), an optional transformed byte (code 1) when the header tag bits match, and the length-bounded payload; always returns 1.
- `0x004B7A90` **F1CPitTimingManager** — Main pit-timing tick: accumulates elapsed frame time into per-vehicle pit timers, runs pit-stall proximity checks (and car-lighting refresh), dispatches a round-robin slice of vehicle slots, processes queued session-data messages through a ring buffer, and fires pit-stop actions; gated by the disable byte at this+0xF78.
- `0x004B9E40` **F1CPitServiceSteering** — Pit-service steering animation step: switch on the animation step state at obj+0xF8C (states 0-8) selects queue-peek target angles or steering rate integration; default returns without action.
- `0x004BBFC0` **F1CPitCrewMachine** — Pit entry/exit state machine on the this+0x30 pit-state field: a pit-trigger object (type tag 0x680000) while idle sets state 2, hides the driver model (obj+0x105D) and calls AIStateReset; a non-pit object resets state to 0 and re-shows the driver model.
- `0x004BEB10` **AIOvertakeBehavior** — AI overtaking behavior step: clears the output flag, stores race laps/session type into the behavior object, gates activation on the accumulated-time threshold at +0x354/+0x358, scans for a human driver in qualifying, and (re)initializes the AI behavior via AIBehaviorInitialization before tail-jumping into the rest of the behavior update.

## Proposed classes

### F1CPitMachine

Per-driver pit-stop state machine: owns the +0x184 pit state, the active sub-object slot, the one-shot red-flag exit flag, and the per-frame routing between idle/entering/in-pit/exiting/post-collision. Methods confirmed to share this+0x184/this+0x190 ownership by the packet; PitstopStateTransition is grouped here on that field overlap though its owner is packet-UNKNOWN.

Methods: `0x004A5E40`, `0x004A5F20`, `0x004A6E50`, `0x004A5600`

- `this+0x00000000` `F1CVehicle* VehiclePtr` (read, DERIVED)
- `this+0x00000004` `int MachineIndex` (read, GUESS)
- `this+0x00000008` `void* ActiveSubObject` (read_write, GUESS)
- `this+0x00000014` `void* AuxSubObject` (read, GUESS)
- `this+0x00000180` `int ExitPitsUnderRedFlag` (read_write, DERIVED)
- `this+0x00000184` `int PitState` (read, DERIVED)
- `this+0x00000188` `float EnteringTimer` (read, GUESS)
- `this+0x00000190` `char StateByte` (read_write, GUESS)
- `this+0x000001AC` `char TailFlag` (read_write, GUESS)
- `*(this+0x8)+0x00000000` `char SubObjectFlagByte` (read, GUESS)

### F1CPitCrewMachine

Pit-entry/exit trigger machine on a separate object (this+0x30 pit-state, this+0x34 stored index) that drives the vehicle's driver-model visibility and resets vehicle AI state on pit entry. Distinct base offsets from F1CPitMachine; common ownership is not packet-proven.

Methods: `0x004BBFC0`

- `this+0x00000000` `F1CVehicle* VehiclePtr` (read, DERIVED)
- `this+0x00000030` `int PitState` (read_write, GUESS)
- `this+0x00000034` `char PitIndexByte` (read_write, GUESS)
- `obj+0x00001054` `int RenderMode` (read, GUESS)
- `obj+0x0000105D` `char DriverModelVisible` (read_write, DERIVED)

### F1CPitTimingManager

Pit-timing tick owner: disable byte, per-vehicle timer accumulators, round-robin step, proximity threshold and pit-stall scratch fields. All field offsets are packet reads/writes but the object identity is unlabeled.

Methods: `0x004B7A90`

- `this+0x000009B0` `void* PitStallBase` (read, GUESS)
- `this+0x000009B8` `int PitStallIndex` (read, GUESS)
- `this+0x00000D28` `int RoundRobinStep` (read_write, GUESS)
- `this+0x00000D78` `float PreviousInput` (read_write, GUESS)
- `this+0x00000D7C` `float[] VehiclePitTimers` (read_write, GUESS)
- `this+0x00000F78` `char DisableByte` (read, GUESS)
- `this+0x00000F7C` `float ProximityThreshold` (read, GUESS)

### F1CPitServiceSteering

Pit-service steering animation step state machine. The this+0 deref yields the pit-service data block; the step state lives at obj+0xF8C. Owner identity unlabeled by the packet.

Methods: `0x004B9E40`

- `this+0x00000000` `void* PitServiceDataPtr` (read, GUESS)
- `obj+0x00000F8C` `int AnimationStepState` (read_write, GUESS)

### AIVehicleState

Vehicle-side AI driver state flags reset by the AI pit/entry path: the +0x4410 byte set to 1 and the +0x45F4 byte cleared to 0 on every AIStateReset call. Owner DERIVED from fills, not from packet evidence.

Methods: `0x0042AF40`

- `this+0x00004410` `char RetiredFlag` (write, GUESS)
- `this+0x000045F4` `char ActiveFlag` (write, GUESS)

### DriverTargetClassifier

Builds the per-slot driver classification array (0 default, -1 retired/invalid, 1 player, 2 teammate, 3 scoring/overtake target in race mode) over the vehicle grid. this is the caller-provided output array; no persistent state is evident.

Methods: `0x00418EE0`

- `this+0x00000000` `int[] ClassificationOutput` (write, GUESS)

### AIOvertakeBehavior

AI overtaking behavior object: activation flag, time accumulator/threshold, race-laps and session-type snapshots, and the (re)initialization hook into AIBehaviorInitialization. Owner class unlabeled by the packet.

Methods: `0x004BEB10`

- `this+0x00000342` `char ActivationFlag` (read, GUESS)
- `this+0x00000350` `float TimeIncrement` (read, GUESS)
- `this+0x00000354` `float AccumulatedTime` (read_write, GUESS)
- `this+0x00000358` `float TimeThreshold` (read, GUESS)
- `this+0x0000035C` `int TotalRaceLaps` (write, GUESS)
- `this+0x00000360` `int SessionType` (write, GUESS)

### SteeringWheelHud

Steering-wheel HUD element: render context and render flag gate the draw pass, five animation parameter sources lerp toward targets under +0x64/+0xA0..0xAC animation storage. Packet-owner UNKNOWN; grouped on field co-occurrence.

Methods: `0x0049D070`

- `this+0x00000004` `char RenderFlag` (read, GUESS)
- `this+0x00000010` `void* RenderContextPtr` (read, GUESS)
- `this+0x0000004C` `void* AnimParam0` (read, GUESS)
- `this+0x00000050` `void* AnimParam1` (read, GUESS)
- `this+0x00000054` `void* AnimParam2` (read, GUESS)
- `this+0x00000058` `void* AnimParam3` (read, GUESS)
- `this+0x0000005C` `void* AnimParam4` (read, GUESS)
- `this+0x00000064` `void* AnimationTargetStorage` (write, GUESS)
- `this+0x000000A0` `float[4] AnimationTargets` (write, GUESS)
- `this+0x000000A4` `float AnimationTargets` (write, GUESS)
- `this+0x000000A8` `float AnimationTargets` (write, GUESS)
- `this+0x000000AC` `float AnimationTargets` (write, GUESS)
- `*(this+0x64)+0x0000001C` `int SteeringInputField` (read, GUESS)
- `*(this+0x64)+0x00000020` `int SteeringInputField` (read, GUESS)
- `*(this+0xB0)+0x00000054` `int GeometryField` (read, GUESS)

### CameraFollowController

Per-frame camera-follow controller over a target object: steering thresholds, vehicle index, interpolation scale, and the follow vector written to the target. The target is reached through this+0xC. Owner unlabeled by the packet.

Methods: `0x00434D60`

- `this+0x00000001` `char OneShotFlag` (read_write, GUESS)
- `this+0x00000004` `int CameraMode` (read, GUESS)
- `this+0x0000000C` `void* TargetPtr` (read, GUESS)
- `this+0x00000010` `float SteerLowThreshold` (read, GUESS)
- `this+0x00000014` `float SteerHighThreshold` (read, GUESS)
- `this+0x00000018` `int VehicleIndex` (read, GUESS)
- `this+0x0000001C` `int SecondaryIndex` (read, GUESS)
- `this+0x0000002C` `int PrevElementIndex` (read, GUESS)
- `this+0x00000030` `float InterpScale` (read, GUESS)
- `*(this+0xC)+0x00000000` `void** TargetVTable` (read, GUESS)
- `*(this+0xC)+0x00000038` `float SteeringWrite` (write, GUESS)
- `*(this+0xC)+0x0000003C` `float LookWrite` (write, GUESS)
- `*(this+0xC)+0x000000A8` `float SteeringAngle` (read_write, GUESS)
- `*(this+0xC)+0x000000B0` `char ActiveFlag` (read, GUESS)
- `*(this+0xC)+0x000000BC` `float CameraAnchorValue` (read, GUESS)
- `*(*(this+0xC)+0x0)+0x00000018` `char ActiveFlagInVtableStruct` (read, GUESS)

### CameraNode

Camera-related object initializer that installs a vtable pointer and runs a cleanup/zero-init helper. The CameraNode label is DERIVED from existing analysis only; the packet does not identify the object.

Methods: `0x004584A0`

- `this+0x00000000` `void** VTablePtr` (write, GUESS)

### TireCompoundSettings

Tire-compound settings object: compound value + index with per-object min/max clamp bounds and a mode selector. Callers at TrackEnvironmentSelect consume the writes; the object type is unlabeled by the packet.

Methods: `0x004AF220`

- `this+0x00000D98` `int CompoundValue` (write, GUESS)
- `this+0x00000DA0` `int CompoundValueMin` (read, GUESS)
- `this+0x00000DA4` `int CompoundValueMax` (read, GUESS)
- `this+0x00001170` `int CompoundIndex` (read_write, GUESS)
- `this+0x00001178` `int CompoundIndexMin` (read, GUESS)
- `this+0x0000117C` `int CompoundIndexMax` (read, GUESS)
- `this+0x00001B34` `int CompoundModeSelector` (read, GUESS)

## Compatibility contracts

- **PitStateMachineEnumeration** — The pit machine state field at this+0x184 enumerates 0 idle, 1 entering, 2 in-pit, 3 exiting, 4 post-collision. PitStateUpdateMachine routes each state, and both state 0 and state 4 map to a state-1 transition in StateConditionalAction. A replacement executable must preserve these state values and routing.
- **TireCompoundIdMapping** — TireCompoundNameToId maps the compound name strings to Hard=2, Soft=3, Intermediate=4, Wet=5, Monsoon=6 and any other string=1; the ids are consumed by AI and pit callers. A replacement must preserve the mapping.
- **PitStateNotifyContract** — Pit machine transitions are recorded and dispatched through StateChangeNotify(this, state) (0x004A5C80), the same dispatcher used by AIStateReset with argument 0. A replacement must keep this shared dispatcher contract.
- **RedFlagPitExitEffects** — ExitPitsUnderRedHandler increments the vehicle pit-exit counter at vehicle+0x406C, calls AIFormationLap, and per the race-config gate dword_8ACFD4==2 and session type dword_7C56A4==7 applies a disqualification or a 1000.0 time penalty with the exiting-pits message string. A replacement must reproduce these effects on the one-shot this+0x180 flag.
- **PitServiceSteeringStateMap** — Pit-service steering animation advances a step state at obj+0xF8C through values 0-8; states 0/1 peek the event queue and clamp to state 5, states 2-8 integrate a scaled steering rate via FloatAccumulator. A replacement must preserve the step-state values and the queue/accumulator contract.
- **ConditionalDispatchCodes** — DispatchCollisionBlockWithTypeCheck routes a collision block through ConditionalDispatch_6bd0 (0x00566BD0) with dispatch code 4 (header), code 1 (transformed byte when header tag bits match) and a payload whose length is read from header bits [17:8]. A replacement must keep this code/length contract.
- **DriverClassificationValues** — ClassifyDriverTargets writes per-slot classification values 0 default, -1 retired/invalid, 1 player, 2 teammate, and 3 for the promoted scoring/overtake target in race mode. A replacement must preserve these classifications for AI target consumers.

## Unresolved

- F1CPitMachine method set: the packet confirms F1CPitMachine ownership only for 0x004A5E40, 0x004A5F20 and 0x004A6E50; PitstopStateTransition (0x004A5600) is grouped into the same class on the shared this+0x184/this+0x190 field evidence though its packet owner is UNKNOWN.
- F1CPitCrewMachine operates on a separate pit-state field (this+0x30/this+0x34) whose relationship to the F1CPitMachine +0x184 state is unresolved; equal offsets are NOT merged across the two objects.
- F1CPitTimingManager, F1CPitServiceSteering, F1CPitTiming fields and TireCompoundSettings all use packet offsets but their concrete object types are unlabeled; the classes are GUESS groupings, not confirmed ownership.
- flt_59E43C and flt_59E7F4 are declared as referenced globals for ClassifyDriverTargets but do not appear in its raw body; their role in the scoring threshold is unresolved.
- flt_59E440 is flagged by packet facts for several functions (ClearPitSelectionFlags, SteeringInterpolationCameraFollow, SteeringWheelAnimation, AIOvertake) but never appears in any raw body; its role (the skeleton fill labels it a zero threshold) is unverifiable from this packet.
- flt_59E600, flt_5ACD14 and flt_5ACD18 are listed as referenced globals for PitServiceSteeringAnimationStep but do not appear in its raw source.
- flt_59E7EC, flt_59E8A4 and flt_59E8EC are listed as referenced globals for SteeringInterpolationCameraFollow but do not appear in its raw body.
- flt_59E87C and dbl_59EA08 are listed as referenced globals for PitTimingUpdate but the time gate renders the literals 0.025 and 0.001 directly; the existing labels (TimeStepMultiplier, collision skin/clock tolerance) are not adopted here.
- dbl_59E880 and dbl_5ACD28 are referenced by DispatchCollisionBlockWithTypeCheck; their exact association with the inlined constant 0.0001670000056037679 is not determinable from this packet.
- global:0x005ACB08 and global:0x008AD298 are recorded as referenced by PitStateUpdateMachine but are absent from its raw body.
- dword_7C54F0 (VehiclePtrArray) is read by PitStateUpdateMachine and AIOvertake and consumed indirectly inside VehicleInstanceListBuilder/sub_4B6190; no direct operation is assigned in PitTimingUpdate.
- global:0x005EB978 is recorded as read by ExitPitsUnderRedHandler but does not appear in its decompiled text; role unresolved.
- field:obj:0x000032C8 (the this+0 deref vehicle-control sentinel) and field:this:0x00000000 in PitStateUpdateMachine gate the control-disabled collision path; the reached object's identity and full layout are external to the function.
- field:*(this+0x64):0x0000001C, field:*(this+0x64):0x00000020 and field:*(this+0xB0):0x00000054 are flagged by SteeringWheelAnimation packet facts but never appear in its raw source.
- The +16484 per-vehicle field read by the AIOvertake qualifying scan, the exact enum meanings of dword_8ACFD4==2 and dword_7C56A4==7, and the tail-jump logic at 0x4BEC10/0x4BEEF2/0x4BEF10 are not evidenced in this packet.
- Several packet functions are outside the vehicle_ai_and_pit scope: PathTrailingBackslashNormalizer, RectClampToBounds, ConditionalNetworkUiRefresh, DispatchChainWithVTableCalls, SteeringInterpolationCameraFollow, VTableInitCallChain, linkContactPairList and DispatchCollisionBlockWithTypeCheck are recorded here as helper interfaces/classes only.
- SubObjectDestructorChain's ConstraintSolverParamInit callee and the ShortComputation_62a0 tail of VTableInitCallChain are absent from the packet callee lists, so their addresses are unknown.
- The exact meaning of the F1CPitMachine operation states 3/4 (blocking) at this+0x184 and the sub-object flag bit 0 used to pick reinitialization versus direct activation are not explained by the packet.
