# RuntimeObjectManagement

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

Twenty-one heterogeneous runtime-object helpers operating across the session tick, display, config, path and physics-init paths. DriverAssistInputHandler (0x0042C440) is the per-frame assist dispatcher: while the session guard at dword_7C54E8+13000 and byte_7CE254 are clear it walks the 16-bit action-code array (dword_7CB218 entries at word_7CB21C) and shifts assist config-pattern buffers through AIShiftPattern, then conditionally dispatches session-transition, visual-state, brake-bias, assist-toggle and vibration behaviors from one-shot command flags. Display state is handled by FormationLapDisplayState (0x0042D140) and PauseStateDisplayToggle (0x0042D210), both resolving strings through the game string table into the shared message buffer byte_5EC4CC. Session lifecycle helpers include SessionReset (0x0042D350), the six-dword SmallDataStructInit (0x0042DC60), ScoreSlotDeallocator (0x0042DDD0) and the penalty sub-struct PenaltyStructInit (0x0042E400). Config/path/file helpers cover validated string copy (0x0042F140), player-name setup (0x004326E0), directory enumeration (0x00432980), auto-load config writing (0x00432BF0), path directory extraction (0x00432DF0, 0x00433290), named-node list removal (0x00433D60), vehicle-setup registration and flag-preserving load (0x00433FC0, 0x00434000). updateCarSelectionStateMachine (0x00434460) with its fallback initializer (0x00434820) drive the pre-race grid-camera phase machine, and the vehicle-side initializers DynamicsObjectInitialization (0x00438C10), BrakeBiasSetup (0x00438CC0) and RigidBodyPositionAndOrientationUpdate (0x0043E6A0) set up dynamics/control state. Ownership is largely unknown; the class groupings are GUESS-level architectural proposals except RigidBodyTransformUpdate which the packet names.

## Function roles

- `0x0042C440` **DriverAssistController** — Per-frame driver-assist input dispatcher: guards on the session guard (dword_7C54E8+13000) and byte_7CE254, walks the 16-bit action-code array, dispatches AIShiftPattern calls for each assist, then session transition, visual state change, brake bias, assist toggle and vehicle vibration from one-shot command flags.
- `0x0042D140` **RaceMessageDisplay** — Formation-lap / pit-timer display state setter: stores the new state at this+0xC on change, runs a session-accumulator comparison for states greater than 2, and on server sessions renders the 'Begin Formation' string and drives the per-vehicle loop.
- `0x0042D210` **RaceMessageDisplay** — Pause-state flag setter: stores the pause state at this+0x10; on unpause it looks up the 'Paused' string, copies it into the message buffer and triggers the screen update.
- `0x0042D350` **SessionShutdown** — Session teardown helper: destroys the texture surfaces of the dword_8AD254 object and delegates the season parent path dword_5EC3D0 through the teardown helper with a zero flag.
- `0x0042DC60` **SessionSubStructBuilder** — Six-dword sub-struct constructor: zeroes four dwords, seeds 30/42 defaults and returns this for chaining; called only from SessionStructInit.
- `0x0042DDD0` **ScoreSlotBufferOwner** — Four-slot score/config buffer deallocator: saves and frees the this+0x4 and this+0xC buffers when non-null and zeroes all four slots.
- `0x0042E400` **SessionSubStructBuilder** — Penalty sub-structure initializer of the session object: writes an offset float (293.16f) and flag byte, then a 4-iteration repeating pattern of floats and flags into array fields.
- `0x0042F140` **ValidatedStringBufferOwner** — Validated string copy: looks up a2 in the owner string table and copies it into (or clears) the this+0xC buffer, returning the destination buffer.
- `0x004326E0` **PlayerProfileManager** — Startup player-name/settings setup: reads the settings setup file, copies setup files, resolves the settings folder path, searches the string table for the player name and walks the per-driver list to enumerate the first matching driver's file.
- `0x00432980` **DirectoryPathEnumerator** — Directory path normalizer and file enumerator: defaults the path, appends a trailing backslash when missing and enumerates the directory's files.
- `0x00432BF0` **AutoLoadConfigWriter** — Writes a fixed six-format-string auto-load configuration entry into a caller-owned buffer with length checks, returning 0 on success.
- `0x00432DF0` **PathDirectoryNormalizer** — Path directory extraction: computes a derived string, copies it through the owning-buffer copy, truncates the first path string at its last backslash and routes the directory-only path through the path-processing table slot.
- `0x00433290` **PathDirectoryExtractor** — Directory-path extraction and extension comparison: fetches the module directory path, copies it into the output buffer, strips a trailing extension and optionally concatenates a dot-extension.
- `0x00433D60` **NamedNodeList** — Removes every node of an intrusive list whose name matches a2, repairing head/tail/count bookkeeping, destroying owned data and freeing the node; clears the object's own stored name on match.
- `0x00433FC0` **VehicleSetupRegistration** — Registration/release helper: writes the caller-supplied path into the global buffer byte_7C56C0; on write failure records the path into this+8 when the flag is set and returns a success indicator.
- `0x00434000` **VehicleSetupFileLoader** — Vehicle-setup file load that preserves the global flag byte byte_7C56C0 around the load and restores it afterwards; returns the load result.
- `0x00434460` **CarSelectionCameraStateMachine** — Pre-race car-selection / grid-camera state machine: init, countdown, wait, advance and end-countdown phases, vehicle-slot scan of the active-vehicle pointer array, pit-exit triggering, and a camera block feeding session-object parameters.
- `0x00434820` **CarSelectionCameraStateMachine** — Module initialization with fallback: initializes constraint-solver parameters, stores a virtual dispatch result, runs the primary init and on failure drives the game action state machine and sets the fallback flag.
- `0x00438C10` **VehicleDynamicsState** — Vehicle dynamics state initializer: zeroes the main struct, runs sub-component initializers, initializes four per-wheel 6-dword state blocks and finishes wheel dynamics setup.
- `0x00438CC0` **VehicleControlConfig** — Per-object control configuration initializer: copies eleven assist-config bytes from the global settings block, derives the control-mode selector, applies bitmask and cross-field fix-ups and stores the scaled driver factor.
- `0x0043E6A0` **RigidBodyTransformUpdate** — Rigid-body position/orientation update: applies a caller-supplied delta vector, extracts Euler angles via atan2 (with a gimbal-lock branch) and applies the transform under an FPU control-word save/restore.

## Proposed classes

### DriverAssistController

Per-frame driver-assist input dispatcher. Reads the action-code array and one-shot command flag globals and shifts assist config-pattern buffers through AIShiftPattern; drives session-transition, visual-state, brake-bias, assist-toggle and vehicle-vibration behaviors on the session object at dword_7C54E8.

Methods: `0x0042C440`


### RaceMessageDisplay

Display-state and pause-message handling on a session display object: sets display/pause state fields, resolves display strings through the game string table and renders them into the shared message buffer byte_5EC4CC.

Methods: `0x0042D140`, `0x0042D210`

- `this+0x0000000C` `int displayState` (write, GUESS)
- `this+0x00000010` `int pauseState` (write, GUESS)

### CarSelectionCameraStateMachine

Pre-race car-selection / grid-camera phase machine and its fallback-capable initializer. Tracks an init flag, phase dword, two timers, a vehicle-slot counter, a grid-scan index and a camera/session object pointer; advances the slot through the active-vehicle array and drives the camera block.

Methods: `0x00434460`, `0x00434820`

- `this+0x00000000` `byte initOrFallbackFlag` (read_write, GUESS)
- `this+0x00000004` `int phase` (read_write, GUESS)
- `this+0x00000008` `ptr dispatchResult` (write, GUESS)
- `this+0x0000000C` `ptr cameraSessionObject` (read, GUESS)
- `this+0x00000018` `int vehicleSlotCounter` (read_write, GUESS)
- `this+0x0000001C` `int matchedGridIndex` (write, GUESS)
- `this+0x00000024` `float countdownTimer` (read_write, GUESS)
- `this+0x00000028` `float accumulator` (read_write, GUESS)
- `this+0x0000002C` `int targetIndex` (read_write, GUESS)
- `this+0x00000034` `float waitTimer` (read_write, GUESS)
- `*(this+0xC)+0x0000000C` `int cameraParamA` (read, GUESS)
- `*(this+0xC)+0x00000010` `int cameraParamB` (read, GUESS)
- `*(this+0xC)+0x00000014` `float cameraParamC` (read, GUESS)
- `*(this+0xC)+0x00000018` `int cameraParamD` (read, GUESS)
- `*(this+0xC)+0x0000001C` `int cameraParamE` (read, GUESS)
- `*(this+0xC)+0x00000020` `int cameraParamF` (read, GUESS)
- `*(this+0xC)+0x00000048` `float cameraFloat` (read, GUESS)
- `*(this+0xC)+0x000000B0` `byte validityByte` (read, GUESS)
- `*(this+0xC)+0x000000BC` `float thresholdFloat` (read, GUESS)

### PlayerProfileManager

Startup settings/player-name setup: reads and copies setup files, resolves the settings folder, validates the player name against the string table and walks the per-driver linked list to locate and enumerate the matching driver's file.

Methods: `0x004326E0`

- `obj+0x00000020` `ptr driverListHead` (read, GUESS)
- `obj+0x0000002C` `int driverListCount` (read, GUESS)
- `*(*(obj+0x20)+0x4)+0x00000000` `char* nodeNamePtr` (read, GUESS)
- `*(*(obj+0x20)+0x4)+0x00000004` `ptr nodeNext` (read, GUESS)
- `*(*(*(obj+0x20)+0x4)+0x0)+0x00000000` `char* candidateName` (read, GUESS)

### VehicleControlConfig

Per-object vehicle control configuration derived from the global assist settings block: copies the eleven assist-config bytes, derives a control-mode selector, applies bitmask and cross-field fix-ups and stores the scaled driver factor.

Methods: `0x00438CC0`

- `this+0x00000072` `byte assistConfig0` (read_write, GUESS)
- `this+0x00000073` `byte assistConfig1` (read_write, GUESS)
- `this+0x00000074` `byte assistConfig2` (read_write, GUESS)
- `this+0x00000075` `byte assistConfig3` (read_write, GUESS)
- `this+0x00000076` `byte assistConfig4` (read_write, GUESS)
- `this+0x00000077` `byte assistConfig5` (read_write, GUESS)
- `this+0x00000078` `byte assistConfig6` (read_write, GUESS)
- `this+0x00000079` `byte assistConfig7` (read_write, GUESS)
- `this+0x0000007A` `byte assistConfig8` (read_write, GUESS)
- `this+0x0000007B` `byte assistConfig9` (read_write, GUESS)
- `this+0x0000007C` `byte assistConfig10` (read_write, GUESS)
- `this+0x00000080` `byte controlModeSelector` (write, GUESS)
- `this+0x0000009C` `double driverFactor` (write, GUESS)

### VehicleDynamicsState

Vehicle dynamics state initializer: zeroes the main struct, runs the sub-component initializers and initializes the four per-wheel 6-dword state blocks before wheel dynamics setup.

Methods: `0x00438C10`

- `this+0x000005D8` `dword wheelState0` (write, GUESS)
- `this+0x000005DC` `float wheelState1` (write, GUESS)
- `this+0x000005E0` `dword wheelState2` (write, GUESS)
- `this+0x000005E4` `float wheelState3` (write, GUESS)
- `this+0x000005E8` `dword wheelState4` (write, GUESS)
- `this+0x000005EC` `float wheelState5` (write, GUESS)

### RigidBodyTransformUpdate

Rigid-body world-position/orientation update: applies a delta vector to the stored position, extracts Euler angles from the orientation matrix via atan2 (including a gimbal-lock branch) and applies the transform under an FPU control-word save/restore.

Methods: `0x0043E6A0`

- `this+0x000015F0` `ptr bodyStatePtr` (read, DERIVED)
- `this+0x000015F4` `double positionX` (read_write, DERIVED)
- `this+0x000015FC` `double positionY` (read_write, DERIVED)
- `this+0x00001604` `double positionZ` (read_write, DERIVED)
- `this+0x0000160C` `double orientationComponentA` (read, DERIVED)
- `this+0x0000161C` `double orientationComponentB` (read, DERIVED)
- `this+0x00001624` `double orientationComponentC` (read, DERIVED)
- `this+0x0000162C` `double orientationComponentD` (read, DERIVED)
- `this+0x00001634` `double pitchCosine` (read, DERIVED)
- `this+0x0000163C` `double orientationComponentE` (read, DERIVED)
- `this+0x0000164C` `double orientationComponentF` (read, DERIVED)

### NamedNodeList

Intrusive linked list keyed by node name: removal by name unlinks the node, repairs head/tail/count bookkeeping, destroys owned data and frees the node; the object's own stored name is cleared on match.

Methods: `0x00433D60`

- `this+0x00000010` `char* storedName` (read_write, GUESS)
- `this+0x0000001C` `ptr listHead` (read_write, GUESS)
- `this+0x00000020` `ptr listTail` (read_write, GUESS)
- `this+0x00000024` `ptr iterator` (read_write, GUESS)
- `this+0x00000028` `int nodeCount` (read_write, GUESS)
- `*(this+0x1C)+0x00000014` `char* nodeName` (read, GUESS)

### SessionSubStructBuilder

Session sub-struct initializers: builds the six-dword small struct (zeroed dwords plus 30/42 defaults) and the penalty sub-structure (offset float/flag plus the 4-iteration float/flag pattern); both are invoked from SessionStructInit.

Methods: `0x0042DC60`, `0x0042E400`

- `this+0x00000000` `dword smallDword0` (write, GUESS)
- `this+0x00000004` `dword smallDword1` (write, GUESS)
- `this+0x00000008` `dword smallDword2` (write, GUESS)
- `this+0x0000000C` `dword smallDword3` (write, GUESS)
- `this+0x00000010` `dword default30` (write, GUESS)
- `this+0x00000014` `dword default42` (write, GUESS)
- `this+0x00001CB8` `byte penaltyFlagByte` (read_write, GUESS)
- `this+0x00001CBC` `float penaltyOffsetFloat` (read_write, GUESS)
- `this+0x00001CD4` `ptr penaltyPatternCursorA` (write, GUESS)
- `this+0x00001CD8` `ptr penaltyPatternCursorB` (write, GUESS)
- `this+0x00001CE8` `byte penaltyPatternByteA` (write, GUESS)
- `this+0x00001CEC` `float[3] penaltyFloatBlock` (write, GUESS)
- `this+0x00001CF0` `float penaltyFloatBlock1` (write, GUESS)
- `this+0x00001CF4` `float penaltyFloatBlock2` (write, GUESS)

### SessionShutdown

Session teardown: destroys the texture surfaces of the global state-flag-pair object and delegates the season parent path through the teardown helper.

Methods: `0x0042D350`


### ScoreSlotBufferOwner

Owner of a four-slot score/configuration buffer record: deallocates the two optional buffers and zeroes all four slots.

Methods: `0x0042DDD0`

- `this+0x00000000` `dword slot0` (write, GUESS)
- `this+0x00000004` `ptr bufferA` (read_write, GUESS)
- `this+0x00000008` `dword slot2` (write, GUESS)
- `this+0x0000000C` `ptr bufferB` (read_write, GUESS)

### ValidatedStringBufferOwner

Holds a string buffer at this+0xC that is only written after the source string validates against the owner's string table; the buffer pointer is returned on every path.

Methods: `0x0042F140`

- `this+0x0000000C` `char* validatedTextBuffer` (read_write, GUESS)

### DirectoryPathEnumerator

Directory enumeration helper: reads a directory path from the path array at offset 0x8, defaults it to the application directory, normalizes the trailing backslash and enumerates the directory's files.

Methods: `0x00432980`

- `obj+0x00000008` `char* pathArrayOffset` (read, GUESS)
- `this+0x00000000` `ptr objectPointer` (read, GUESS)

### AutoLoadConfigWriter

Writes a fixed six-format-string auto-load configuration entry into a caller-owned write buffer with length checks.

Methods: `0x00432BF0`

- `this+0x00000000` `dword* bufferValidityPtr` (read, GUESS)

### PathDirectoryNormalizer

Path directory extraction: copies a derived string into an owning buffer, truncates the first path string at its last backslash and routes the directory-only path through the path-processing table slot.

Methods: `0x00432DF0`

- `this+0x00000000` `char* firstStringPtr` (read, GUESS)

### PathDirectoryExtractor

Directory-path extraction and extension comparison: fetches the module directory path into the output buffer, strips a trailing file extension and optionally concatenates a dot-extension.

Methods: `0x00433290`

- `this+0x00000000` `char* outputStringPtr` (read_write, GUESS)

### VehicleSetupRegistration

Registration/release helper for vehicle-setup paths: writes the caller path into the shared flag buffer and, on write failure, records the path into this+8 when flagged.

Methods: `0x00433FC0`

- `this+0x00000008` `char* registeredPath` (write, GUESS)

### VehicleSetupFileLoader

Vehicle-setup file load that preserves the global flag byte around the load and restores it afterwards; returns the load result.

Methods: `0x00434000`

- `this+0x00000000` `char* setupPath` (read, GUESS)

## Compatibility contracts

- **AssistPatternDispatchContract** — While the session guard (dword_7C54E8+13000) and input flag byte_7CE254 are both clear, the per-frame dispatcher must walk the 16-bit action-code array (dword_7CB218 entries at word_7CB21C) and shift the corresponding assist config-pattern buffer through AIShiftPattern. A replacement must preserve the config key strings (0x005C33A8..0x005C3480) and the pattern ids used for the steering/opposite-lock/braking-point/stability/spin-recovery/invulnerability/auto-shift/traction/ABS/pit-lane/clutch assists.
- **MessageDisplayBufferContract** — Display-state and pause changes resolve strings via the game string table (byte_5EC4C0/byte_5EC4CC) and render through TextLineWrappingAndRendering / ShortComputation_bde0. The 'Begin Formation' message must render only in server sessions (dword_7C569C==5) with the pit-timer visible (byte_7CEC78).
- **VehicleSetupFlagPreservationContract** — Vehicle-setup loads route through VehicleSetupFileWriter with the shared flag byte byte_7C56C0; the flag-preserving loader must save and restore that byte around the load so the global flag state is unchanged.
- **CarSelectionCameraContract** — Pre-race car selection advances a vehicle-slot counter, scans the active vehicle-pointer array dword_7C54F0 against the grid-size bound dword_5C329C, triggers IteratorCheck/PitExit per slot, and finishes in a camera block that feeds session-object fields into the steering-interpolation camera and the angle setters.
- **StringTableValidatedCopyContract** — Callers that copy a string into an owned buffer after a string-table lookup must copy only when the lookup succeeds and clear the buffer when the source is null; the destination buffer pointer is returned on every path.
- **SessionResetContract** — Session teardown must destroy the texture surfaces of the dword_8AD254 state-flag-pair object and delegate the season parent path dword_5EC3D0 through the teardown helper with a zero flag, returning the helper's result.
- **DriverListWalkContract** — Player-name setup must walk the per-driver list rooted at *(this+0x20) with bound *(this+0x2C), advancing through node +4 next pointers and reading each node's name at +0x0, and enumerate the matching driver's file when the name comparison matches.

## Unresolved

- AIShiftPattern pattern-id semantics and the meaning of each dword_7CExxx assist config-pattern buffer are defined by the callee and unknown here.
- The session-structure fields at dword_7C54E8 + 13000 and + 13004 have unknown meaning beyond the guard and session-transition roles.
- Meaning of the one-shot command flag globals (0x7CC260, 0x7CC394, 0x7CC3C0, 0x7CC3EC, 0x7CC6D8, 0x7CC704) is assumed to be set elsewhere in the input system.
- dbl_7C7428 as a vehicle-object reference for VehicleActive is presumed from the call shape, not confirmed.
- Common ownership of the display-state field (this+0xC) and pause-state field (this+0x10) by a single RaceMessageDisplay object is an architectural assumption; the packet does not prove both methods share one receiver.
- The penalty sub-struct offsets this+0x1CB8..0x1CF4 and the six-dword small struct this+0x0..0x14 are grouped under SessionSubStructBuilder because both are called from SessionStructInit (0x0042E320); the full session layout is unknown.
- States 3 and 4 of the car-selection machine both fall through to the score-gate advance block; the semantic difference between sub_4D8760's first arguments (0 vs 2) is not established.
- Read-only globals 0x0059E440, 0x0059E65C and 0x005EA618 (car-selection), and 0x0059EB98 and 0x007CE498 (brake-bias) are recorded by the packet but do not appear in the raw decompiled text; their role is unplaced.
- Globals 0x005C3F88..0x005C3F98 and byte_5EA438 are listed in the packet for WriteAutoLoadEntry but not referenced by the decompiled body.
- The literals 3 (render mode) and 16909060 (color/value) in the TextLineWrappingAndRendering call have no confirmed semantics.
- The meaning of the 30/42 default literals in SmallDataStructInit and the 293.16f/359.86f literals in PenaltyStructInit is unknown.
- sub_568910's behavior and sub_587DD0's exact append semantics (whether a3-1 is respected as a bound) are not provable from this packet.
- The backslash-scan loop in PathDirectoryExtractionAndComparison computes a cursor that is never consumed; likely dead code or a decompiler artifact.
- byte_7C56C0's flag bits and why the flag-preserving loader must restore it around vehicle-setup loads are unknown.
- The meaning of the string field at this+8 in the registration helper (released/registered path) is not packet-evidenced.
- The 512 constant and the EmptyStub_7780 diversion on FPU control-word mismatch in RigidBodyPositionAndOrientationUpdate are FPU-state hygiene whose game-specific intent is unknown.
- dword_7CD204 is referenced by static facts for 0x0042D140 and 0x0042D210 but does not appear in the raw bodies; role unknown.
