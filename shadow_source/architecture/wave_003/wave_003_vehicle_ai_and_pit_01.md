# VehicleAIAndPitSubsystem

Scope: `vehicle_ai_and_pit`  
Trust: `DERIVED`

DERIVED proposal for the vehicle_ai_and_pit scope from 14 validated functions. Nine functions (0x00419120, 0x00419500, 0x00419690, 0x004198B0, 0x0041A0C0, 0x0041A170, 0x0041A3A0, 0x0041A500, 0x0041AB30) form the AI driver-behavior/event core: they share the race-active/track/phase guards (dword_7D0308, flt_7CF3C8, dword_7C56A8), the player-identity compare (dword_7C54E8), the session type (dword_7C56A4) and the shared session event table at flt_5EA618 built with the helper trio 0x004144D0/0x004144F0/0x00418560, so they are grouped as a GUESS class AISessionEventHandler with vehicle-base fields at +0x4894/+0x489C/+0x48A0, +0x342C/+0x3430/+0x3450/+0x403C and pit flags at +0xA44. 0x004040A0 owns the AI difficulty database object (GUESS class AIDifficultyDatabase) with aggression baselines and config indices at 0x118..0x168. Camera support (0x0040B850, 0x0040CA30) and the game-state dispatch (0x0040D240) are kept as separate GUESS classes or free transition handlers because no common ownership with the AI event core is proven; the menu transition (0x00404F30) is a GUESS session-transition handler over the obj layout +0x14/+0x20/+0x50/+0x54. All class owners except the subsystem-level grouping are GUESS; function_roles carries the evidence for every required function exactly once.

## Function roles

- `0x004040A0` **AIDifficultyDatabase** — AI difficulty database initializer: seeds track-position speed-curve slots (3.0/1.0/2.0), zeroes three slots, sets aggression baselines (0.5/1.0/1.3) and configuration indices (1/104/52/3), opens the AI database file (dword_7CE608 or byte_5EA438 fallback path), processes it, then interpolates a difficulty-scaled output into this[70] from dword_7D01A0; called once from Game_Init.
- `0x00404F30` **SessionMenuTransition** — Menu/restart transition handler: enters the session critical section on unk_7CE24C, calls the system OS API, and when ConditionalFlagReturn passes dispatches the 'Main Menu' scene; on the restore path (obj+0x14 activation flag set and obj+0x20 == 1) restores saved globals from obj+0x50 and obj+0x54 (the latter clamped), resets byte_5EA53E, runs a zero-guarded division, and conditionally resets virtual dispatch state at byte_8AC494.
- `0x0040B850` **MainViewCameraSetLoader** — Main-view camera set loader: searches for the 'MainView' string via TwoLevelWideStringSearch(dword_8AFE88, aMainview), stores the handle into this+4, opens an audio stream, collects up to 128 'TrackingCam' entries into a temp array, and on success allocates a persistent array into this+12 with count this+16 and index 0 in this+20; returns 0 on success and 1 after disposal on any failure.
- `0x0040CA30` **MainCameraDirector** — Per-frame main camera director update: retargets the camera on player change, runs the one-time setup guard (this+0x2D), negates a triple-field offset vector, then picks the camera action from the AI random state machine (this+0x2E) versus keyboard input, requests the mode change, applies per-vehicle and camera-controller callbacks (vtable slots +12/+16 on the controller object at this+0x8), and runs position/velocity tracking through the tracking object at dword_8AC4C4, optionally adding a particle and emitting the final velocity update.
- `0x0040D240` **GameStateTransitionDispatcher** — Unconditional game-state change dispatch: sets the player vehicle index to a2, retargets the camera and assigns the camera view, dispatches conditional audio/virtual state, emits the AI out-of-track event for the new target, then calls the completion handler sub_4D8760(1, 0) and returns its result; no guards.
- `0x00419120` **AISessionEventHandler** — AI driver state-transition handler: gated on race active/track/phase, a real state change and a distinct requested target; for session type 7 and the player vehicle performs up to two random draws from the trig/noise table (dword_8AAE70/flt_8AAE74) to pick a behavior table (198/259/120), resolves a row through DriverDataTableLookupAndTimeConversion, and on the shared exit commits the target state to this[a2[4645] + 108] after InsertDriverTableEntry.
- `0x00419500` **AISessionEventHandler** — AI corner-speed comparison handler: for session type 5 compares the vehicle's corner speed (a1 + 4*a2 + 16460) against the reference speed row flt_5F0780[4656 * sub_4D1B50(0) + a2]; faster selects driver-table entry 13/14, slower 19/20, then inserts the resolved entry into the driver table; on corner 2 while the pitting field at +0x3450 equals 1 raises AIVehicleDamageEvent.
- `0x00419690` **AISessionEventHandler** — AI overtake/defend/pit state-change handler: for session types 5 and 7 selects a driver-behavior lookup index from the action selector a2 and the driver-slot/player relationship (10/16 or 3/33 when a3 is the player slot, 4 defend, 5 pit, 72/262 qualifying outlap), resolves it through DriverDataTableLookupAndTimeConversion with the per-driver ID from dword_5F0F74, and inserts the entry into the driver action table.
- `0x004198B0` **AISessionEventHandler** — Per-frame AI race-commentary handler: detects a driver's position change (this[a2[4645]+108] versus a2[4120]), persists the new position, selects the event type by player identity and direction (17/18 player, 7/8/9 AI), fills the record via DriverDataTableLookupAndTimeConversion, and inserts it into the session event table.
- `0x0041A0C0` **AISessionEventHandler** — AI off-track event handler: toggles the off-track driver-table flag for index 264 via BooleanOROfTwoChecks, then for a non-player/offending vehicle initializes an entry, converts it from the driver data row (dword_5F0F74 stride 4656), and inserts it into the driver table.
- `0x0041A170` **AISessionEventHandler** — AI vehicle damage event: selects driver-table behavior index 52 when the session-status query sub_4C7BD0(a1) is nonzero, else 196 only for session type 7, fills the entry via DriverDataTableLookupAndTimeConversion using the team id at vehicle offset 0x48A0, and inserts it into the driver action table.
- `0x0041A3A0` **AISessionEventHandler** — Formation-lap race-start event handler: emits per-driver session commentary (generic code 6, or championship-weekend position codes 180/181/182 selected by field 0x342C when the position counter at 0x3430 is within one lap of the lap number at 0x403C), filling the event buffer via DriverDataTableLookupAndTimeConversion and inserting it into the session event table.
- `0x0041A500` **AISessionEventHandler** — Time-based race message dispatcher: computes elapsed/cumulative time from dbl_8AFEA0/dbl_8AFE98, selects a message selector (35/34/277/276/279/278) as descending thresholds (2700/1800/900/600/300/180) are crossed, inserts the driver-table entry, and when elapsed falls to <= 0.0 invokes a virtual thiscall at vtable offset 12 on dword_5EB10C and reinitializes the flt_5EA618 buffer via BufferInitWith10fDefaults.
- `0x0041AB30` **AISessionEventHandler** — Pit-state slot activation tracker: marks slot a2 activated (value 2) at this + 0xA44 + a2*4, counts the 4 consecutive slot flags, and emits a per-slot driver-table event (switch on a2: 94/96/98/100 via jump table jpt_41ABBC) or the combined event 104 when 3+ slots are active, inserting into the session event table.

## Proposed classes

### AIDifficultyDatabase

AI difficulty database object: aggression baselines, track-position speed-curve slots, configuration indices and the difficulty-scaled output, initialized from built-in constants and an on-disk AI database file.

Methods: `0x004040A0`

- `this+0x00000000` `FLOAT baseAggressivenessMultiplier` (write, GUESS)
- `this+0x00000004` `FLOAT secondaryAggressivenessMultiplier` (write, GUESS)
- `this+0x00000118` `FLOAT difficultyScaledOutput` (write, GUESS)
- `this+0x0000011C` `FLOAT aggressionBaselineLow` (write, GUESS)
- `this+0x00000120` `FLOAT aggressionBaselineMid` (write, GUESS)
- `this+0x00000124` `FLOAT aggressionBaselineHigh` (write, GUESS)
- `this+0x00000130` `FLOAT speedCurveSlot0` (write, GUESS)
- `this+0x00000134` `FLOAT speedCurveSlot1` (write, GUESS)
- `this+0x00000138` `FLOAT speedCurveSlot2` (write, GUESS)
- `this+0x00000148` `FLOAT sentinelFloat` (write, GUESS)
- `this+0x0000015C` `DWORD configIndex0` (write, GUESS)
- `this+0x00000160` `DWORD configIndex1` (write, GUESS)
- `this+0x00000164` `DWORD configIndex2` (write, GUESS)
- `this+0x00000168` `DWORD configIndex3` (write, GUESS)

### SessionMenuTransition

Menu/restart transition handler: acquires the session lock, dispatches the Main Menu scene, and on the restore path restores saved session globals from the transition object and resets dispatch state.

Methods: `0x00404F30`

- `this+0x00000000` `void* transitionObjectPtr` (read, GUESS)
- `obj+0x00000014` `BYTE activationFlag` (read, GUESS)
- `obj+0x00000020` `DWORD stateDword` (read, GUESS)
- `obj+0x00000050` `DWORD savedGlobalA` (read, GUESS)
- `obj+0x00000054` `DWORD savedGlobalB` (read, GUESS)

### MainViewCameraSetLoader

Loads the main-view camera set: resolves the 'MainView' handle, collects 'TrackingCam' entries, and allocates a persistent camera array.

Methods: `0x0040B850`

- `this+0x00000004` `void* mainViewHandle` (write, GUESS)
- `this+0x0000000C` `void* cameraArrayPtr` (write, GUESS)
- `this+0x00000010` `DWORD cameraArrayCount` (write, GUESS)
- `this+0x00000014` `DWORD cameraArrayIndex` (write, GUESS)

### MainCameraDirector

Per-frame main camera director: tracks the player vehicle, selects camera actions from the AI random state machine or keyboard, requests mode changes, and feeds position/velocity tracking.

Methods: `0x0040CA30`

- `this+0x00000008` `void* currentCameraEntity` (read_write, GUESS)
- `this+0x00000018` `void* previousCameraEntity` (read_write, GUESS)
- `this+0x00000025` `BYTE perFrameSkipFlag` (read_write, GUESS)
- `this+0x00000028` `DWORD cameraActionCounter` (write, GUESS)
- `this+0x0000002D` `BYTE oneTimeSetupFlag` (read_write, GUESS)
- `this+0x0000002E` `BYTE aiModeFlag` (read, GUESS)
- `*(this+0x8)+0x00000000` `void** controllerVtable` (read, GUESS)
- `*(*(this+0x8)+0x0)+0x0000000C` `void* controllerStateVirtualSlot` (read, GUESS)
- `*(*(this+0x8)+0x0)+0x00000010` `void* controllerModeChangeVirtualSlot` (read, GUESS)
- `*(*(this+0x8)+0x0)+0x00000018` `void* controllerPositionVirtualSlot` (read, GUESS)

### GameStateTransitionDispatcher

Unconditional game-state change dispatch: sets the player vehicle index, retargets the camera and view, dispatches audio/virtual state, and triggers the AI out-of-track event for the new target.

Methods: `0x0040D240`


### AISessionEventHandler

Per-driver AI session event/behavior emission: state transitions, corner-speed comparison, overtake/defend/pit and position-change commentary, off-track and damage events, formation-lap and time-milestone messages, and pit-state slot tracking, gated by race-active/track/phase guards and written into the shared session event table.

Methods: `0x00419120`, `0x00419500`, `0x00419690`, `0x004198B0`, `0x0041A0C0`, `0x0041A170`, `0x0041A3A0`, `0x0041A500`, `0x0041AB30`

- `this+0x00000A44` `DWORD[4] pitStateSlotFlags` (read_write, GUESS)
- `this+0x0000342C` `DWORD formationLapStatus` (read, GUESS)
- `this+0x00003430` `DWORD formationLapPositionCounter` (read, GUESS)
- `this+0x00003450` `DWORD pittingStatus` (read, GUESS)
- `this+0x0000403C` `DWORD lapNumberCounter` (read, GUESS)
- `this+0x00004894` `DWORD teamConstructorId` (read, GUESS)
- `this+0x0000489C` `DWORD driverIndex` (read, GUESS)
- `this+0x000048A0` `DWORD driverTeamId` (read, GUESS)

## Compatibility contracts

- **SessionStateGlobals** — A replacement executable must maintain the runtime globals that gate the AI event pipeline: race-active flag dword_7D0308, track-condition float flt_7CF3C8, race phase dword_7C56A8 (value 8 is a phase-excluded state), session type dword_7C56A4 (5 = race, 7 = qualifying/championship weekend), championship/race-mode dword_7D0410 (value 5 = World Championship), and the player-vehicle identity global dword_7C54E8.
- **SessionEventTableContract** — The session event table anchored at flt_5EA618 holds 8-dword entries initialized with sentinel values (default index -1, time -2.0) by StructInitWithSentinelValues, filled by DriverDataTableLookupAndTimeConversion with event/behavior ids (e.g. 13/14/19/20 corner-speed, 3/4/5/10/16/33 overtake/defend/pit, 72/262 outlap, 94/96/98/100/104 pit-slot, 180/181/182 formation-lap, 264 off-track), appended by InsertDriverTableEntry, gated by BooleanOROfTwoChecks, primed by ArraySearchReturningIndex and re-seeded by BufferInitWith10fDefaults.
- **AIDifficultyDatabaseContract** — The AI difficulty database object carries aggression baselines at +0x11C/+0x120/+0x124 (0.5/1.0/1.3), the difficulty-scaled output at +0x118 interpolated from dword_7D01A0 between baseline pairs, track-position speed-curve slots at +0x130..+0x138, sentinel -1.0 at +0x148, and configuration indices at +0x15C..+0x168 (1/104/52/3); the database file name is resolved from dword_7CE608 with byte_5EA438 fallback.
- **DriverIdentityContract** — Per-driver/vehicle identity fields used to compare the player driver against AI drivers: team/constructor id at vehicle offset +0x4894 (18580), driver index at +0x489C (a1[4647]) and driver team id at +0x48A0 (18592); per-driver lap values at dword_5F0714 and driver ids at dword_5F0F74 are indexed with stride 4656.
- **CameraControllerVtableContract** — The camera controller object at this+0x8 exposes a vtable whose slots +12 (state query), +16 (mode change) and +24 (entity position) are invoked by the director; the global tracking object at dword_8AC4C4 carries position/velocity update vtables (slots +28/+32), and the per-frame update also reads the vehicle-track global dword_7C54E0 and the speed/velocity limit globals 0x7C56AC/0x7CFE28/0x7CFE4C/0x7CFE54.
- **PitStateSlotFlagsContract** — Pit-state slot activation is tracked in four consecutive flags at this + 0xA44 (value 2 = activated); fewer than 3 active slots emit per-slot event ids 94/96/98/100 via the jump table at 0x41AC3C, while 3 or more emit the combined event id 104 into the session event table.

## Unresolved

- Class owners are all GUESS: the packet keeps every function owner UNKNOWN (UnknownObject), so AISessionEventHandler, AIDifficultyDatabase, MainCameraDirector, MainViewCameraSetLoader, SessionMenuTransition and GameStateTransitionDispatcher are grouped on shared responsibility only.
- flt_59E440 (and the flt_59E4xx / flt_59E7F8-804 / flt_59E808-81C family) are listed as read globals in packet facts but never appear as named operands in the raw decompiled bodies; their zero-threshold/force-feedback roles are inferred, not verified.
- The loop in 0x004040A0 writes this[79..81] at offsets 0x13C onward (track-position speed-curve seeds 3.0/1.0/2.0), which fall outside the packet's deterministic field list; packet fields 0x130/0x134/0x138 are the zeroed slots, not the curve seeds.
- dword_7D2E44, dword_7D0410, dword_7D0418, dword_7D041C, byte_5EA53E, flt_7CF380 and byte_8AC494 (0x00404F30) and dword_8AC494-reset semantics appear in the raw source but are absent from the packet global list, so their addresses cannot be cited as evidence here.
- SafeDivisionWithZeroGuard(0.1) and VirtualDispatchStateReset(&byte_8AC494) call targets in 0x00404F30 are absent from the packet callee list; their addresses are unknown.
- Identity of the tracking object behind global 0x008AC4C4 and the meaning of its vtable slots +28/+32 is unresolved; the six values produced by 0x00542420 and the byte-array scratch are unresolved.
- The per-vehicle sub-call sub_4F0D20 role on camera mode transitions is caller-context dependent and unresolved here.
- The matching semantics of TwoLevelWideStringSearch and sub_565520 against the 'MainView'/'TrackingCam' literals, the 208-byte camera-record layout copied by sub_4585E0/sub_459330, and dword_8AFE88's type are not established by this packet.
- The mapping performed by sub_4D1B50 from target state to vehicle slot index, and the meaning of the 0x68 (104) index bound, are unverified.
- Semantics of sub_4C7BD0 and why its non-zero result selects damage index 52 are not established.
- Vehicle offsets +16460 (0x404C per-corner speed array) and +13392 (0x3450 pitting status) are DERIVED from usage; +16460 is not in the packet field table.
- Driver-behavior-table index semantics (13/14/19/20 overtake vs overtaken, 3/4/5/10/16/33 overtake/defend/pit, 72/262 outlap, 180/181/182 formation-lap position, 264 off-track, message selectors 35/34/277/276/279/278) are DERIVED from prose, not independently grounded in this packet.
- The 8-entry local record layout filled by DriverDataTableLookupAndTimeConversion and the meanings of the -1 / -2.0 sentinel arguments are not established.
- a2[4111] (driver state flag: 1 early-returns, 2 selects event type 7) and a2[4647] semantics in 0x004198B0 are DERIVED at best.
- The pairwise meaning of dbl_8AFEA0 versus dbl_8AFE98 (session offset versus last-message time) is only partially determined; the virtual thiscall at vtable offset 12 on dword_5EB10C (SoundSystemPtr, DERIVED) is unidentified.
- The owner class of the session event table anchored at flt_5EA618 is unresolved; flt_5EA618 is passed both as a table base and to BufferInitWith10fDefaults for re-seeding.
- Global 0x0041AC3C is the jump-table address jpt_41ABBC for the pit-slot per-slot event switch; the semantic event names behind ids 94/96/98/100/104 are not present in the packet.
