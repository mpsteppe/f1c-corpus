# VehicleAIAndPit

Scope: `vehicle_ai_and_pit`  
Trust: `DERIVED`

The vehicle-AI-and-pit subsystem centers on the F1CPitMachine object (this base): a state machine that records transitions into a 432-byte-strided ring buffer (StateChangeNotify, PitsUnderRedHandler) and a per-frame pit-stop operation timing coordinator that accumulates operation durations from part/crew/tire/wheel-gun sub-tasks (PitStopOperationTimer). AI driver management is split between opponent candidate selection into a merge-sorted linked list (BuildOpponentList), init-time count/nationality/team setup (AIDriverCountSetup), a session-type flag key classifier (KeyPriorityChain), and per-vehicle engine-failure/collision handling (EngineFailureCheck). Vehicle tire and wheel presentation is covered by a per-wheel-position mesh loader gated by detail level (TireWheelGraphicsMeshLoader) and a per-frame tire temperature simulation (TireTemperatureSimStep). Pit data management includes a career-standings teardown and tire-wear getter (PitStopMemoryCleanup, TireWearGetter), a pit-order data loader with reversible iteration (PitStopOrderLoader) and a driver race-position rank (PitStopOrderRank). Ownership is confirmed in-packet only for F1CPitMachine (three functions); all other class identities are DERIVED from shared field bases and call relationships and must not be promoted without independent evidence.

## Function roles

- `0x004A4ED0` **VehicleTireMeshLoader** — Loads tire/wheel graphics mesh references (.MTS) per wheel position selected by tire-name match (LF/RF/LR/RR), parsing lodin/lodout LOD bounds and applying the caller detail level as a range gate, then allocating 72-byte mesh records and linking them into the per-position singly linked list rooted at a5 + 4*wheelIndex; recurses for nested instance meshes.
- `0x004A58B0` **F1CPitMachine** — Formats and refreshes the pit-repair HUD widget: fuel/time basis computation and fuel quantity string, current part-name resolution through the string table, repair progress counter formatting, and Repair/Do-Not-Repair plus part-label string selection driven by internal mode flags and a vtable-provided part count.
- `0x004A5C80` **F1CPitMachine** — Pit-machine state-change recorder: reads the current state at this+0x184, returns unchanged on equal state, optionally stamps session time dbl_8AFEA0 into this+0x18C, advances the ring-buffer write cursor dword_8AAE64 (bounded by dword_83EE60 < 1023, 432-byte stride), encodes a progress-bar event of type 6 from the event id at this+4, writes the new state at entry+8, and dispatches the AI state machine.
- `0x004A5EA0` **F1CPitMachine** — One-shot handler for entering pits under a red flag: guarded by latch this+0x180, records the state change to 2 via StateChangeNotify, captures the owner vehicle pointer, updates the AI session phase, processes the vehicle pit state, and under the race-start gate (dword_8ACFC8==2) with penalties enabled either disqualifies the driver (session type 7) or applies a time penalty.
- `0x004A6340` **F1CPitMachine** — Per-frame pit-stop operation timing and sequence coordinator: clears the operation-progress block, advances the vehicle progress bar through the physics channel when a pit stop is active, otherwise computes the max duration across base time, part changes, tire-change transitions, wheel-gun operations and audio/visual effect gates, dispatching ConditionalMathDispatch, part resolution, ProgressBarEventEncode and audio effect handling; returns 0.0 while the vehicle pit state obj+0x32C8 is 1 and the blocking condition holds.
- `0x004B8BD0` **SessionTypeClassifier** — Priority-ordered session-type classifier: calls SessionTypeFlagGuard on byte_7CA594 with flags 203, 200, 208 and 205, short-circuiting to keys 0, 1, 3, 4 respectively and defaulting to 2; global-state only, consumed by sub_4B9890 and ConditionalMultiPathDispatcher.
- `0x004BEC55` **AIEngineFailureManager** — Per-vehicle AI engine-failure and collision loop over the car array: guards engine-state flags, applies random variation scaling to negative speed, triggers collision response with a probability-ladder severity, accumulates damage counters and pit-crew progress-bar events, re-enters per car until the remaining count is exhausted, then advances the session-time accumulator and drives the AI tick update.
- `0x004BF790` **AIOpponentSelection** — Builds the AI opponent candidate list: logs a NotAI debug line, may short-circuit via AIPathPerformanceFunction for a2 <= 10, randomly walks the vehicle roster modulo the count from dword_8AC36C, accepts candidates into 8-byte nodes wrapped in 12-byte linked-list nodes appended to a head/tail/iter/count list on 'this', then splits and merge-sorts the list by the float value at node+4; returns the number of candidates appended.
- `0x004BFD90` **AIDriverSetup** — Configures the AI opponent count and per-driver nationality/team assignment at dynamic-manager init: builds the driver-name path, applies a championship single-vehicle override or a deterministic random count, selects opponents via AIOpponentSelection, walks the vehicle array assigning nationality and team id, and always ends with the single-player fallback (name lookup, nationality, team 0, final session transition).
- `0x004C0B10` **CareerStandings** — Career-standings structure teardown: frees two dynamically allocated pointers guarded against null at byte offsets 0xB128 and 0xB120, then runs sub_49A270 cleanup on 104 contiguous per-driver blocks stepping downward by 0x1B4 bytes from byte 0xAF6C down to byte 0.
- `0x004C11C0` **CareerStandings** — Trivial thiscall getter returning the int field at this+0xB14C; no side effects, no callees, no guards; called from SessionInit.
- `0x004C22A0` **GameOptionsIO** — Conditional wrapper that, when argument a2 is non-zero, zero-initializes a stack struct, opens an audio stream for a2, and only on success writes options via GameOptionsWriter, conditionally closes the file handle and always runs conditional-field cleanup before returning the stored writer flag.
- `0x004C77D0` **Vehicle** — Per-frame tire temperature simulation on a vehicle: skips vehicle types above 1, gated by the session-state check on dword_7CD25C, clamps the temperature field this+0x48B8 to [0.0, 5.0], subtracts the cooling rate dbl_8AFE90 and recovers via ClampedPhysicsScaleWithThreshold using the team field this+0x4894, then dispatches car lighting/render through the 432-byte-strided ring buffer and runs the this+3 sub-object update.
- `0x004C9820` **VirtualStateNode** — Boolean check over a dynamically indexed child object: reads the index at this+0x1C, loads the child pointer at this[this[7]+8], returns 0 when null, otherwise dispatches a virtual thiscall at vtable offset 28 of the child and returns 0 when the result equals 2, else 1; called from RendererSceneNodeUpdate.
- `0x004D12C0` **F1CPitMachine** — Loads and parses pit-stop order data for teams: gated on AudioChannelStop(aPitorder), resets the team entry count this+0x1A8, walks the string-keyed team linked list storing DataEntryAccessor results, allocates a count-strided array (entries {0,-1}) into this+0x1AC, and reallocs each team string in forward or reverse order depending on the reverse-pit-order setting.
- `0x004D1BC0` **DriverStandingCalculator** — Computes a driver's race position by counting active drivers ranking ahead via DriverStandingComparator (rank + 1), or by reading a stored position directly from the vehicle array at dword_5F0738[4656*a2] when the session type is 7.

## Proposed classes

### F1CPitMachine

Pit-stop machine: records state transitions into a ring buffer, runs per-frame pit-stop operation timing, formats the pit-repair HUD, handles pits-under-red, and loads pit-stop order data.

Methods: `0x004A58B0`, `0x004A5C80`, `0x004A5EA0`, `0x004A6340`, `0x004D12C0`

- `this+0x00000000` `pointer ownerVehiclePointer` (read, DERIVED)
- `this+0x00000004` `int eventId` (read, DERIVED)
- `this+0x00000008` `pointer physicsChannel` (read, DERIVED)
- `this+0x00000028` `int widgetModeFlag` (read, GUESS)
- `this+0x0000002C` `int pitStopActiveFlag` (read, DERIVED)
- `this+0x00000058` `double fuelTimeBasisAddend` (read, GUESS)
- `this+0x00000060` `double fuelTimeBasisMultiplier` (read, GUESS)
- `this+0x0000006C` `double fuelTimeBasisFactor` (read, GUESS)
- `this+0x000000AC` `int currentPartIndex` (read, DERIVED)
- `this+0x000000D8` `double tireChangeTimeBase` (read, GUESS)
- `this+0x000000E0` `double tireChangeTimeScale` (read, GUESS)
- `this+0x000000EC` `int previousTireState` (read, GUESS)
- `this+0x000000F0` `int currentTireState` (read, GUESS)
- `this+0x00000128` `int repairActionMode` (read, GUESS)
- `this+0x0000012C` `int repairLabelSelector` (read, GUESS)
- `this+0x00000158` `int[] partCountArray` (read, GUESS)
- `this+0x00000160` `int partCount` (read, DERIVED)
- `this+0x00000164` `int[] partSelectionList` (read, DERIVED)
- `this+0x00000168` `int partSelectionPairSecond` (read, GUESS)
- `this+0x0000017C` `double fuelQuantity` (read, GUESS)
- `this+0x00000180` `int pitsUnderRedLatch` (read_write, DERIVED)
- `this+0x00000184` `int currentPitState` (read, DERIVED)
- `this+0x0000018C` `double stateChangeTimestamp` (read_write, DERIVED)
- `this+0x000001A0` `int channelFlagMask` (read, GUESS)
- `this+0x000001A8` `int teamEntryCount` (read_write, DERIVED)
- `this+0x000001AC` `pointer teamDataArray` (read_write, DERIVED)
- `this+0x000001B0` `float vehicleTimeBudget` (read, GUESS)
- `this+0x000001B4` `float runningTime` (write, GUESS)
- `this+0x000001B8` `float totalTimeSnapshot` (write, GUESS)
- `this+0x000001BC` `float operationProgress0` (read_write, GUESS)
- `this+0x000001C0` `float operationProgress1` (read_write, GUESS)
- `this+0x000001C4` `float operationProgress2` (write, GUESS)
- `this+0x000001C8` `float operationProgress3` (write, GUESS)
- `this+0x000001CC` `float operationProgress4` (write, GUESS)
- `this+0x000001D0` `float operationProgress5` (write, GUESS)
- `this+0x000001D4` `float operationProgress6` (write, GUESS)

### Vehicle

Per-vehicle state object carrying pit state, pit-stop type, pit-block and audio flags, plus tire temperature and thermal model fields; fields are evidenced under two bases ('obj' from pit-machine accessors, 'this' from the temperature simulator's own this pointer) and are kept distinct because common ownership is not proven by the packet.

Methods: `0x004C77D0`

- `obj+0x00000CD4` `int pitBlockFlag` (read, DERIVED)
- `obj+0x00001054` `float audioEffectValue` (read, GUESS)
- `obj+0x0000105C` `byte audioEffectGateByte` (read, GUESS)
- `obj+0x000032C8` `int vehiclePitState` (read, DERIVED)
- `obj+0x0000403C` `int lapPartIndex` (read, GUESS)
- `obj+0x00004040` `int pitStopType` (read, GUESS)
- `obj+0x00004074` `vtable_offset partCountVtableOffset` (read, GUESS)
- `this+0x000032C8` `int vehicleTypeGate` (read, DERIVED)
- `this+0x00004894` `int thermalTeamField` (read, GUESS)
- `this+0x000048B8` `float tireTemperature` (read_write, DERIVED)

### VehicleTireMeshLoader

Parses tire/wheel graphics mesh definitions (.MTS) and builds per-wheel-position singly linked lists of mesh records gated by detail level.

Methods: `0x004A4ED0`


### SessionTypeClassifier

Maps the session-type flag byte to a small priority key used to select multi-path dispatch.

Methods: `0x004B8BD0`


### AIEngineFailureManager

Per-vehicle engine-failure and collision handling: speed randomization, severity-ladder collision response, damage accumulation, engine-state gating and pit-crew progress-bar events.

Methods: `0x004BEC55`


### AIOpponentSelection

Builds, counts, splits and merge-sorts the linked list of AI opponent candidates (head/tail/iter/count stored on 'this'; 8-byte candidate nodes with an accessor value and float parameter wrapped in 12-byte list nodes).

Methods: `0x004BF790`

- `this+0x00000000` `pointer listHead` (read_write, DERIVED)
- `this+0x00000004` `pointer listTail` (read_write, DERIVED)
- `this+0x00000008` `pointer listIterator` (read_write, DERIVED)
- `this+0x0000000C` `int listCount` (read_write, DERIVED)
- `obj+0x00000004` `pointer nextPointer` (read_write, DERIVED)
- `*(obj+0x4)+0x00000004` `float floatSortKey` (read, DERIVED)
- `*(*(obj+0x4)+0x4)+0x00000004` `pointer nextPointerWalk` (read, DERIVED)

### AIDriverSetup

Init-time AI driver count, opponent selection, and per-driver nationality/team assignment, with the single-player fallback path.

Methods: `0x004BFD90`


### CareerStandings

Career-standings structure holding two guarded allocations and 104 per-driver blocks plus a tire-wear value read at byte 0xB14C.

Methods: `0x004C0B10`, `0x004C11C0`

- `this+0x0000B120` `pointer driverDataAllocation` (read, GUESS)
- `this+0x0000B128` `pointer pitStopAllocation` (read, GUESS)
- `this+0x0000B14C` `int tireWearValue` (read, GUESS)

### GameOptionsIO

Wraps option writing behind an audio-stream-open gate with conditional file-handle close and cleanup.

Methods: `0x004C22A0`


### VirtualStateNode

Boolean state check over a dynamically indexed child object using an index field and a virtual method at vtable offset 28.

Methods: `0x004C9820`

- `this+0x0000001C` `int childIndex` (read, DERIVED)

### DriverStandingCalculator

Computes a driver's race position either by counting ahead drivers through the standing comparator or from a stored position array for session type 7.

Methods: `0x004D1BC0`


## Compatibility contracts

- **PitMachineStateRingBuffer** — Pit-machine state changes are recorded into a ring buffer with a 432-byte entry stride; the new state is stored at entry+8. The write pointer dword_8AAE64 advances by the stride only while the bounded counter dword_83EE60 < 1023, and each entry encodes a progress-bar event of type 6 using the machine event id at +4 and the session-time global dbl_8AFEA0.
- **PitStopOperationTiming** — The per-frame pit-stop timing coordinator returns the accumulated operation duration except that it returns 0.0 while the vehicle pit state obj+0x32C8 equals 1 and PitStopBlockingCondition holds. The detail-level gate global dword_7CF884 >= 2 forces mesh loading regardless of LOD bounds in the tire mesh loader.
- **SessionTypeFlagKeys** — The session-type flag byte_7CA594 is classified via SessionTypeFlagGuard into keys: flag 203 maps to 0, 200 to 1, 208 to 3, 205 to 4, and anything else defaults to 2.
- **TireTemperatureModel** — Per-frame tire temperature: the field +0x48B8 is clamped to [0.0, 5.0], reduced by the cooling rate dbl_8AFE90, and on dropping to zero is recovered via ClampedPhysicsScaleWithThreshold using the team field +0x4894 (max(-scale, scale + temp)); vehicle types above 1 are skipped.
- **OpponentSelectionAndSort** — Builds an opponent candidate list by randomly walking the vehicle roster modulo the count read from dword_8AC36C, accepting up to a2 candidates, each an 8-byte node (accessor value + float parameter computed by sub_4BF6A0) wrapped in a 12-byte list node; the list is then split at its midpoint and merge-sorted by the float value at candidate node+4.
- **DriverRacePosition** — Race position equals the number of active drivers ranking ahead (via DriverStandingComparator) plus one; for session type 7 the stored position is read directly from the dword_5F0738 vehicle-position array indexed by 4656*a2 instead.
- **PitStopOrderData** — Team pit-stop order is loaded into an array of 8*count+4 bytes with a leading count slot and per-entry pairs initialized to {0, -1}; iteration order is reversible (forward or reverse pit order) selected by comparing aReversepitorde against aFalse_0, and each team string is realloc-copied per entry.
- **PitsUnderRedHandling** — Entering the pits under a red flag is a one-shot handler: on first pass it records the state change to 2, captures the owner vehicle, updates the AI session phase and vehicle pit state; when the race-start gate dword_8ACFC8 equals 2 and penalties are enabled (dword_7CEF84), session type 7 disqualifies the driver via DisqualificationHandler while other sessions apply a time penalty via sub_4BBA90(aEnteringPitsUn, 1000.0).

## Unresolved

- F1CPitMachine ownership is CONFIRMED in-packet for 0x004A5C80, 0x004A5EA0 and 0x004A6340; every other class identity here (Vehicle, AIOpponentSelection, CareerStandings, etc.) is DERIVED from shared field bases and call relationships and must be treated as a proposal, not runtime truth.
- The exact meanings of pit-machine state values 1 and 2, the 432-byte ring-buffer entry layout beyond +8, and the semantics of dbl_8AFEA0 (session time) are not proven by this packet.
- Field 0x32C8 is evidenced under two bases: obj+0x32C8 (vehicle pit state from pit-machine accessors) and this+0x32C8 (vehicle type gate from the temperature simulator); common ownership is not proven, so they are kept as distinct fields.
- sub_588410 match semantics (nonzero-on-match vs strcmp-style zero-on-match) are unverified; the tire-name guard in TireWheelGraphicsMeshLoader yields only the lftire->1 / else->0 reachable path despite the apparent LF/RF/LR/RR to 0/1/2/3 mapping.
- TireWheelGraphicsMeshLoader byte_5CD5F0 is listed in the packet global list but is not referenced by the raw function text.
- PitRepairStatusDisplay string destinations (this+0x36, +0x76, +0xB6, +0xF6, +0x136) are written but absent from the packet field list, so they carry only source:raw evidence.
- The string/data globals 0x0059E440, 0x0059E880, 0x0059EA40 and the PitStopOperationTimer tuning constants (flt_59E43C, flt_59E450, flt_59E4DC, flt_59E8A0/A4, flt_59E918/60/94, flt_5ACB54/58/5C) and EngineFailureCheck constants (flt_59E4E8, flt_59E7FC, flt_59E8B4/FC, flt_5ACAEC/F0, flt_5ACDD8/DC) are listed as packet globals but never appear in the rendered decompiled source; their roles are unknown.
- EngineFailureCheck uses a __userpurge ABI with a positive-stack warning; argument roles are only partially reconstructed, a6 is unused, and the per-car pointer stride v20 is not evidenced.
- BuildOpponentList node+8 active-flag byte and whether the AIPathPerformanceFunction early return is a grid check or performance short-circuit are unresolved.
- PitStopOrderLoader reverse-order index v13[60 + 4*(count-k)] is offset one element back from the forward v13[64 + 4*j]; the intent of the gap is unexplained.
- PitStopMemoryCleanup freed pointers at 0xB120/0xB128 and the 109-dword per-driver block layout torn down by sub_49A270 are undefined; sub_49A270's purpose is proven only as a call.
- AIDriverCountSetup stride 18624 per slot and the exact per-slot field touched by TeamIDSetter are not visible in this packet; globals unk_5EC6D0, unk_5EC6E4 and unk_8AC388 roles are unverifiable.
- VirtualStateCheckViaIndex value-2 virtual-result semantics, child object class, and the container indexed by this[7] are unknown; the 'ai' naming is suggestive only.
- TireWearGetter value semantics (units/lifetime) are assumed from the pit subsystem tag and canonical name only.
- WriteOptionsOnAudioStreamOpen argument a2 semantics and the literal 1 to AudioStreamOpen are unidentified; the GameOptionsWriter result is DERIVED to be a success flag.
- KeyPriorityChain flag-to-session mapping and the returned key's consumer meaning are unconfirmed.
- Guard 3 (this+0x168 > 0) and the vehicle byte gates at obj+3348/3352/3416 attributed to the PitStopOperationTimer time-margin checks are ambiguous in the rendered code.
- The literal vehicle pit-state slot 16436 (0x4034) passed to sub_4BC240 in PitsUnderRedHandler is spelled only in raw source and has no packet field evidence reference.
