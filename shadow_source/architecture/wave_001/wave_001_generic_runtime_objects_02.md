# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `GUESS`

Conservative DERIVED/GUESS architecture for 19 validated functions in the generic_runtime_objects scope. Two functions have CONFIRMED packet ownership (F1CVehicle: 0x0042ACD0 ParameterValueSetter, 0x0042ADB0 SessionCleanupFlagClear); two have DERIVED owners (VehicleSetupConfig: 0x0042E530; VehicleReplayState: 0x0042ECC0). The remaining owners are UNKNOWN and are grouped into GUESS classes only where packet evidence overlaps on the same 'this' base: AIOpponentAwareness (proximity/team scan + overtake decision share +0x403C/+0x4420/+0x45FC/+0x0), VehicleControlAndPositionUIState (gearbox blend, visual-state change and position/lap UI share +0x1C58/+0x1E7C/+0x1EF0/+0x1EF4/+0x1EF8/+0x1F00 and a direct 0x00443B70 -> 0x00447E00 call), plus small GUESS utility classes. GamePost (0x0042DA30) is modelled as a frame-post dispatcher over a FramePostHook interface. No state claimed CONFIRMED by the worker.

## Function roles

- `0x0042A7D0` **AIOpponentAwareness** — Per-frame opponent awareness: reset 5 proximity + 5 team slots, register nearest vehicle or scan active-vehicle list, sorted-insert nearest candidates, match/fill team slots, consume one-shot re-seed flag.
- `0x0042ACD0` **F1CVehicle** — Sets vehicle maxSpeed from an int parameter; value 18 selects the idle/reverse speed target constant, otherwise the raw value cast to float. Recalculated every frame so external pokes do not persist.
- `0x0042ADB0` **F1CVehicle** — Per-frame session-active flag setter: read RetiredFlag, and when not retired clear the cleanup flag and set the AIControlFlag; returns the original retired byte.
- `0x0042AF70` **AIOpponentAwareness** — Overtake acceptance decision: replay bail-out, shared max-speed update, session-type/lap/best-lap gates, target-identity and overtake-state checks, pit/stop eligibility, commit target + direction only when car condition != 2 and fuel-rate factor > 0.001.
- `0x0042DA30` **GameFramePostDispatcher** — Game post-frame dispatch: set game phase word to 6, conditionally log, invoke every engine subsystem Post() hook in sequence, then write dword_7C56A0 = 3; returns the session-state setter result.
- `0x0042E1F0` **SetupScaledValueIndexParser** — Shared setup-value parser: parse token triplet, scale two doubles, store truncated int, parse and clamp an index into [0, count-1].
- `0x0042E530` **VehicleSetupConfig** — Per-frame vehicle setup update: gear-index clamping over the +0xBC4 table, event vs comparator mode over config-value blocks, rear-spoiler / ride-height / setup-index re-matching, session-value decrement, road-course reset.
- `0x0042ECC0` **VehicleReplayState** — Load gear-ratio config via GearRatioConfigFileReader, propagate final-drive value from +0x1978 into +0x1640, replicate the +0x1970 DWORD into 8 replay-state slots at +0x1680 (64-byte stride); returns pointer one past the last slot.
- `0x0042ED00` **SessionRatioLookup** — Weighted-ratio lookup via RatioCalculator with a table base, a row index and the column at +0x1644; negates the result for index 43.
- `0x0042ED50` **BoundedStringCopyHelper** — Bounded string copy of at most 63 chars into the buffer at this+112 with a NUL terminator written at +0xAF.
- `0x004317F0` **UnknownObject** — Indexed call-through: computes &this[4*a3+7336] and passes it with a4 and seven zeros to sub_565870; joint target-position semantics not evidenced by this packet.
- `0x00431DB0` **DirectoryFileEnumerator** — Directory/file enumeration: build search path, clear and refill two linked lists (directories vs files), merge-sort both, increment the counter at +0x1C, free the temp buffer.
- `0x004352C0` **PlaneIntersectionHelper** — Plane/line intersection ratio: computes t for a segment against a plane parameterized on this+0x0/+0x8; returns FLT_MAX on degenerate plane or zero denominator.
- `0x004353F0` **PhysicsBufferObject** — Constructor stub: clear +0x9C, call PhysicsBufferClear, return this; straight-line, no guards.
- `0x004388D0` **Matrix3x3** — 3x3 matrix (this[0..8]) times 3-vector multiply into output vector a3; returns input vector a2. Structural twin of the Matrix3x3VectorMultiply cluster.
- `0x00443AF0` **BoundingVolumeHierarchy** — BVH traversal filter: mode-dependent double threshold comparisons (mode at +0x1E14) returning whether a volume extends beyond the test distance; used for collision pruning.
- `0x00443B70` **VehicleControlAndPositionUIState** — Per-frame gearbox shift / RPM rev-match blend: wheel-speed target averaging, gear-ratio selection, throttle blend coefficient, rev-limit clamp, speed-limiter engagement/decay with HUD and position/lap side-effects, RPM vibration disturbance, random throttle perturbation.
- `0x00447C70` **VehicleControlAndPositionUIState** — HUD visual-state transition: store new state byte when changed, then on the noise path compute noise-modulated scale/alpha and call HUDElementConfig(40, 2, alpha, scale).
- `0x00447E00` **VehicleControlAndPositionUIState** — Position/lap-change state handler: encode direction into +0x1EF8, copy branch reference data, fire branch-specific sound triggers, set UI state 2/3/5/6 and commit UI params.

## Proposed classes

### F1CVehicle

Per-frame vehicle control fields: maxSpeed setter and session-active/cleanup flag handling. Packet-confirmed ownership for both methods.

Methods: `0x0042ACD0`, `0x0042ADB0`

- `this+0x00004538` `float maxSpeed` (write, DERIVED)
- `this+0x00004410` `byte RetiredFlag` (read, DERIVED)
- `this+0x00004424` `byte cleanupDisqualificationFlag` (write, DERIVED)
- `this+0x000045F4` `byte AIControlFlag` (write, DERIVED)

### AIOpponentAwareness

Per-frame opponent proximity/team recognition and overtake decision. GUESS grouping of two UNKNOWN-owner functions whose fields overlap on the same 'this' base (+0x403C, +0x4420, +0x45FC, +0x0) and which both consume dword_7C56A4.

Methods: `0x0042A7D0`, `0x0042AF70`

- `this+0x00000000` `int vehicleIdOrObjectPointer` (read, GUESS)
- `this+0x00000004` `pointer nearestScanSubObject` (read, GUESS)
- `this+0x000034E0` `float selfWorldPositionX` (read, DERIVED)
- `this+0x000034E8` `float selfWorldPositionZ` (read, DERIVED)
- `this+0x00003984` `float fuelRateFactor` (read, GUESS)
- `this+0x00003D6C` `int carConditionState` (read, GUESS)
- `this+0x0000403C` `int lapNumber` (read, DERIVED)
- `this+0x0000409C` `float bestLap` (read, GUESS)
- `this+0x00004174` `int proximitySlot0Id` (read_write, DERIVED)
- `this+0x000041A8` `float proximitySlot0Distance` (write, DERIVED)
- `this+0x000041B4` `int proximitySlot0TeamId` (write, DERIVED)
- `this+0x000041B8` `int proximitySlot1Id` (write, DERIVED)
- `this+0x000041EC` `float proximitySlot1Distance` (write, DERIVED)
- `this+0x000041FC` `int proximitySlot1TeamId` (write, DERIVED)
- `this+0x00004230` `float proximitySlot2Distance` (write, DERIVED)
- `this+0x00004240` `int proximitySlot2TeamId` (write, DERIVED)
- `this+0x00004274` `float proximitySlot3Distance` (write, DERIVED)
- `this+0x00004284` `int proximitySlot3TeamId` (write, DERIVED)
- `this+0x000042B8` `float proximitySlot4Distance` (write, DERIVED)
- `this+0x000042CC` `byte teamSlot0MatchedFlag` (write, DERIVED)
- `this+0x000042D0` `int teamSlot0TeamId` (write, DERIVED)
- `this+0x000042DC` `float teamSlot0Distance` (write, DERIVED)
- `this+0x00004420` `float overtakeDirectionSign` (write, DERIVED)
- `this+0x0000448C` `float headingVectorX` (read, GUESS)
- `this+0x00004494` `float headingVectorZ` (read, GUESS)
- `this+0x0000450C` `float sharedMaxSpeed` (read_write, GUESS)
- `this+0x00004578` `byte oneShotReseedFlag` (read_write, GUESS)
- `this+0x000045F8` `pointer currentOvertakeTarget` (read, GUESS)
- `this+0x000045FC` `pointer overtakeTargetSlot` (write, DERIVED)
- `*(this+0x4174)+0x00004894` `int opponentTeamId` (read, DERIVED)
- `obj+0x000048A8` `dword overtakeState` (read, DERIVED)

### VehicleSetupConfig

Per-frame vehicle setup: gear-index clamping, event/comparator mode config-block updates, rear-spoiler angle matching, ride-height stepping, setup-index re-match, road-course gear reset.

Methods: `0x0042E530`

- `this+0x000003F0` `double setupArrayBase` (read, GUESS)
- `this+0x000003F8` `double setupArrayStep` (read, GUESS)
- `this+0x00000400` `int setupArrayCount` (read, GUESS)
- `this+0x00000404` `int setupIndex` (read_write, GUESS)
- `this+0x00000130` `double frontGearArrayBase` (read, GUESS)
- `this+0x00000138` `double frontGearArrayStep` (read, GUESS)
- `this+0x00000144` `int frontGearIndex` (read, GUESS)
- `this+0x000006B0` `double frontRideHeightArrayBase` (read, GUESS)
- `this+0x000006B8` `double frontRideHeightArrayStep` (read, GUESS)
- `this+0x000006C4` `int frontRideHeightIndex` (read_write, GUESS)
- `this+0x00000970` `double rearRideHeightArrayBase` (read, GUESS)
- `this+0x00000978` `double rearRideHeightArrayStep` (read, GUESS)
- `this+0x00000980` `int rearRideHeightCount` (read, GUESS)
- `this+0x00000984` `int rearRideHeightIndex` (read_write, GUESS)
- `this+0x00000BC4` `int[] gearIndexTable` (read_write, DERIVED)
- `this+0x00000CC0` `int sessionValueGuard` (read, GUESS)
- `this+0x00000CC4` `int sessionValue` (read_write, GUESS)
- `this+0x000012B0` `double rearSpoilerArrayBase` (read, GUESS)
- `this+0x000012B8` `double rearSpoilerArrayStep` (read, GUESS)
- `this+0x000012C0` `int rearSpoilerArrayCount` (read, GUESS)
- `this+0x000012C4` `int rearSpoilerIndex` (write, GUESS)
- `this+0x00001988` `byte eventModeFlag` (read, GUESS)
- `this+0x00001990` `int masterEnable` (read, GUESS)

### VehicleReplayState

Gear-ratio configuration loading and propagation into the replay-state buffer.

Methods: `0x0042ECC0`

- `this+0x00001640` `float replayFinalDriveCountField` (write, DERIVED)
- `this+0x00001680` `dword[] replayStateSlots` (write, DERIVED)
- `this+0x00001970` `dword gearRatioConfigBuffer` (read, DERIVED)
- `this+0x00001978` `float finalDriveValue` (read, DERIVED)

### SessionRatioLookup

Weighted-ratio lookup helper (RatioCalculator) with special negation for index 43; used by brake/tire/suspension lookup code.

Methods: `0x0042ED00`

- `this+0x00001644` `int ratioColumnIndex` (read, GUESS)

### SetupScaledValueIndexParser

Shared config-token parser: parse value triplet, scale by factor, truncate to int, parse and clamp an index. Used by per-wheel, fender, engine-map and vehicle-file sections.

Methods: `0x0042E1F0`

- `this+0x00000000` `double firstScaledValue` (read_write, GUESS)
- `this+0x00000008` `double secondScaledValue` (read_write, GUESS)
- `this+0x00000010` `int parsedCount` (write, GUESS)
- `this+0x00000014` `int clampedIndex` (write, GUESS)

### DirectoryFileEnumerator

Directory/file enumeration producing two merge-sorted linked lists (directories and files) plus an enumeration counter.

Methods: `0x00431DB0`

- `this+0x00000000` `char* baseDirectoryString` (read, GUESS)
- `this+0x00000008` `char* searchPatternString` (read, GUESS)
- `this+0x0000001C` `int enumerationCounter` (read_write, GUESS)
- `this+0x00000020` `pointer directoryListHead` (read_write, GUESS)
- `this+0x00000024` `pointer directoryListTail` (read_write, GUESS)
- `this+0x00000028` `pointer directoryListDuplicateHead` (read_write, GUESS)
- `this+0x0000002C` `int directoryListCount` (read_write, GUESS)
- `this+0x00000030` `pointer fileListHead` (read_write, GUESS)
- `this+0x00000034` `pointer fileListTail` (write, GUESS)
- `this+0x00000038` `pointer fileListDuplicateHead` (write, GUESS)
- `this+0x0000003C` `int fileListCount` (write, GUESS)
- `*(this+0x20)+0x00000008` `pointer directoryListNodeLinkage` (read, GUESS)
- `*(this+0x30)+0x00000008` `pointer fileListNodeLinkage` (read, GUESS)

### BoundedStringCopyHelper

Bounded string copy (max 63 chars) with guaranteed NUL termination.

Methods: `0x0042ED50`

- `this+0x000000AF` `byte nulTerminatorByte` (write, GUESS)

### PlaneIntersectionHelper

Plane/line intersection ratio computation with degenerate handling.

Methods: `0x004352C0`

- `this+0x00000000` `float planeXComponent` (read, GUESS)
- `this+0x00000008` `float planeZComponent` (read, GUESS)

### PhysicsBufferObject

Physics-buffer container whose constructor clears a state field and resets the physics buffer.

Methods: `0x004353F0`

- `this+0x0000009C` `dword dwordIndex39` (write, GUESS)

### Matrix3x3

3x3 matrix container (9 doubles) with vector-multiply; row/column-major order not established.

Methods: `0x004388D0`

- `this+0x00000000` `double matrixElement00` (read, GUESS)
- `this+0x00000008` `double matrixElement01` (read, GUESS)
- `this+0x00000010` `double matrixElement02` (read, GUESS)
- `this+0x00000018` `double matrixElement10` (read, GUESS)
- `this+0x00000020` `double matrixElement11` (read, GUESS)
- `this+0x00000028` `double matrixElement12` (read, GUESS)
- `this+0x00000030` `double matrixElement20` (read, GUESS)
- `this+0x00000038` `double matrixElement21` (read, GUESS)
- `this+0x00000040` `double matrixElement22` (read, GUESS)

### BoundingVolumeHierarchy

Bounding-volume hierarchy with mode-dependent traversal-distance filter for collision pruning.

Methods: `0x00443AF0`

- `this+0x000003D0` `double thresholdA` (read, GUESS)
- `this+0x00000834` `double thresholdB` (read, GUESS)
- `this+0x00000C98` `double thresholdC` (read, GUESS)
- `this+0x000010FC` `double thresholdD` (read, GUESS)
- `this+0x00001E14` `dword filterMode` (read, GUESS)

### VehicleControlAndPositionUIState

Per-frame gearbox shift / RPM rev-match blend, HUD visual-state transitions and position/lap-change UI handling. GUESS grouping on overlapping 'this' fields (+0x1C58, +0x1E7C, +0x1EF0, +0x1EF4, +0x1EF8, +0x1F00) and the direct 0x00443B70 -> 0x00447E00 call.

Methods: `0x00443B70`, `0x00447C70`, `0x00447E00`

- `this+0x00000008` `double throttleBlendDouble` (read_write, GUESS)
- `this+0x0000000C` `dword throttleBlendHighDword` (write, GUESS)
- `this+0x00000010` `int telemetryConditionValue` (read, GUESS)
- `this+0x00000018` `double shiftProgressA` (write, GUESS)
- `this+0x0000001C` `double shiftProgressB` (write, GUESS)
- `this+0x00000020` `double blendFactorMax` (read_write, GUESS)
- `this+0x00000034` `int positionUIState` (write, GUESS)
- `this+0x00000038` `int positionUIParamA` (write, GUESS)
- `this+0x0000003C` `int positionUIParamB` (write, GUESS)
- `this+0x00000060` `int positionUIValueA` (read, GUESS)
- `this+0x00000064` `int positionUIValueB` (read, GUESS)
- `this+0x00000068` `double timeStep` (read, GUESS)
- `this+0x00000080` `dword shiftModeBits` (read, GUESS)
- `this+0x00000170` `double throttleRate` (read_write, GUESS)
- `this+0x0000019C` `int telemetryConditionValueB` (read, GUESS)
- `this+0x00000348` `double wheelSpeedRearRight` (read, GUESS)
- `this+0x00000498` `double wheelSpeedFrontLeft` (read, GUESS)
- `this+0x000007AC` `double wheelSpeedRearLeft` (read, GUESS)
- `this+0x000008FC` `double wheelSpeedFrontRight` (read, GUESS)
- `this+0x00000C10` `double wheelSpeedAxleRear` (read, GUESS)
- `this+0x00000D60` `double wheelSpeedAxleFront` (read, GUESS)
- `this+0x00001074` `double wheelSpeedDrivetrainModeAvg` (read, GUESS)
- `this+0x000011C4` `double wheelSpeedGearboxAvg` (read, GUESS)
- `this+0x00001C58` `byte gearboxStateByte` (read_write, GUESS)
- `this+0x00001C5C` `double engineRpm` (read_write, GUESS)
- `this+0x00001C60` `double speedLimiterCopyTarget` (write, GUESS)
- `this+0x00001C7C` `double speedLimiterValue` (read, GUESS)
- `this+0x00001C84` `double speedLimiterCurrent` (read_write, GUESS)
- `this+0x00001C88` `double speedLimiterTarget` (read, GUESS)
- `this+0x00001C8C` `double speedLimit` (read, GUESS)
- `this+0x00001CDC` `double rpmDivisor` (read, GUESS)
- `this+0x00001CE4` `double revLimitLow` (read, GUESS)
- `this+0x00001CEC` `double revLimitHigh` (read, GUESS)
- `this+0x00001D10` `double speedLimiterTimer` (read_write, GUESS)
- `this+0x00001D28` `double speedLimiterTimerThreshold` (read, GUESS)
- `this+0x00001DAC` `double rpmVibrationDisturbance` (read, GUESS)
- `this+0x00001E14` `dword drivetrainMode` (read, GUESS)
- `this+0x00001E38` `double revMatchTarget` (read, GUESS)
- `this+0x00001E78` `byte autoBlendFlag` (read, GUESS)
- `this+0x00001E7C` `double shiftTimer` (read_write, GUESS)
- `this+0x00001E80` `double positionReferenceCopy` (write, GUESS)
- `this+0x00001E84` `double gainedPositionReferenceA` (read, GUESS)
- `this+0x00001E88` `double gainedPositionReferenceB` (read, GUESS)
- `this+0x00001E8C` `double upshiftDuration` (read, GUESS)
- `this+0x00001E94` `double lostPositionReferenceA` (read, GUESS)
- `this+0x00001E98` `double lostPositionReferenceB` (read, GUESS)
- `this+0x00001E9C` `double downshiftDuration` (read, GUESS)
- `this+0x00001EF0` `int currentGearRecord` (read_write, GUESS)
- `this+0x00001EF4` `int currentGearOrPosition` (read_write, GUESS)
- `this+0x00001EF8` `int shiftStateWord` (read_write, GUESS)
- `this+0x00001F00` `dword hudActivationAndSoundBase` (read, GUESS)

### GameFramePostDispatcher

Post-frame dispatch: set game phase word, log conditionally, invoke every engine subsystem Post() hook, write the multiplayer/flags word.

Methods: `0x0042DA30`

- `this+0x00000000` `dword gamePhaseWord` (write, GUESS)

## Compatibility contracts

- **PostFrameHookSequence** — GamePost (0x0042DA30) must, in the post-frame phase: set the game phase word to 6, conditionally log, invoke the subsystem Post() hooks in documented order (guarded dispatch, nested call loop, sound, FX delegation, special FX, scene computation, global flag clear, steward, hardware input, dynamics, camera, render, on-screen display, video manager, session object, player file, session state), then write dword_7C56A0 = 3 and propagate the session-state setter return value.
- **MaxSpeedRecalculatedPerFrame** — ParameterValueSetter (0x0042ACD0) writes maxSpeed at F1CVehicle+0x4538 every frame from the parameter value (18 selects the idle-speed target constant flt_8ACFB4, otherwise the raw value). Because it is recalculated per frame, an external poke of +0x4538 does not persist; a replacement must preserve the per-frame writer behavior.
- **SessionActiveFlagRule** — SessionCleanupFlagClear (0x0042ADB0) reads the RetiredFlag byte at +0x4410; when not retired it must zero +0x4424 and set +0x45F4 to 1, and it always returns the original retired byte (nonzero when the writes were skipped).
- **ActiveVehicleList** — dword_7C54F0[0 .. dword_5C329C) is the active-vehicle pointer array iterated by the opponent awareness scan; entries are skipped when this+0x0 equals the self id. FindNearestVehicle (0x004A4710) is the fast path for the nearest opponent. A replacement must preserve this list layout and the slot-0 nearest registration behavior.
- **DirectoryEnumerationLists** — EnumerateDirectory (0x00431DB0) clears, refills and merge-sorts two linked lists at this+0x20 (directory entries) and this+0x30 (regular files) and increments the counter at +0x1C; callers (SettingsSetupFileRead, Wrapper, PathNormalizerFileEnumeration) depend on both lists being sorted after each enumeration.
- **OvertakeCommitGuards** — AIOvertakeDecision (0x0042AF70) accepts an overtake only when the replay gate, session-type gate (dword_7C56A4), lap/best-lap comparison, target identity (+0x45F8 == opponent), overtake-state comparison (obj+0x48A8) and pit/stop eligibility all pass, and commits the new target (+0x45FC = a2) with direction +0x4420 set to +-3.0 only when this+0x3D6C != 2 and this+0x3984 > 0.001.
- **GearRatioConfigPropagation** — ReplayStateCopy (0x0042ECC0) loads gear-ratio config into the buffer at +0x1970, propagates the final-drive value at +0x1978 into +0x1640, and replicates the DWORD at +0x1970 into 8 slots starting at +0x1680 with a 64-byte stride; it returns the pointer one past the last written slot.

## Unresolved

- Owner identity is UNKNOWN for 13 of the 19 functions. GUESS classes AIOpponentAwareness and VehicleControlAndPositionUIState merge functions whose packet owners are UNKNOWN; the merges rest only on overlapping 'this' fields and the 0x00443B70 -> 0x00447E00 call, not on packet-proven single-class ownership.
- 0x0042A7D0: the sorted-insertion outer guard reads as `v41 >= farthest-slot OR heading projection >= -5.5` while the chain inserts only when v41 < a slot distance; the conditions appear inverted (possible decompiler artifact) and the true control flow is ambiguous.
- 0x0042A7D0: team-slot block includes sentinel fields at +0x42C8 and +0x42D8 (values -1 and -1000.0f) that are written but not listed as packet fields; globals flt_59E440, flt_59E980, flt_59E984, flt_59E988 and unk_7CE2F0 are read per the extractor but absent from the raw source (roles likely inside callees).
- 0x0042AF70: opponent fields a2+0x44C4 (speed), a2+0x403C/+0x409C (lap/best-lap), a2+0x48A8 (overtake state) and pit/stop-state fields at +0xCD4/+0xD14/+0xD18/+0xD58 are not individually enumerated in the packet; semantics of a3 (direction) and the pit/stop AND/OR combination are DERIVED, not proven.
- F1CVehicle +0x45F4 is named 'AIControlFlag' (CONFIRMED) by the packet while existing analysis calls it 'ActiveFlag' [FACT]; the two names are not reconciled.
- 0x0042E530: identities of the six config-value block pairs are unnamed; the magic threshold 0.1523746 and DBL_MAX sentinel (dbl_59E9F8) have DERIVED semantics; the a2/a3 component/subcomponent index encoding is only partially established; owner is DERIVED from a LEGACY ABI lead, not a confirmed symbol.
- 0x0042ECC0: the copy loop writes the same source DWORD (+0x1970) into 8 slots spaced 64 bytes apart; why the source is held constant and the implied 16-DWORD destination layout are not explained.
- 0x0042ED00: the row-index array this[16*a2+753] and table base this+1628 are not evidenced by field records; the meaning of the special index 43 (negation) is not established.
- 0x0042ED50: the destination buffer start (this+112) is evidenced only by the source literal, not by a field record.
- 0x004317F0: sub_565870 behavior is unknown, so joint/target-position semantics cannot be confirmed; argument a2 is unused in the body; the indexed region at 7336*4 is unnamed.
- 0x00431DB0: raw source appends directory entries to this+0x20 while the packet prose labels it the 'file list'; the two disagree. The node +8 linkage field role is only observable through merge/append helpers. Globals asc_5C2AB4 and the FF-prefixed byte_FF00000000005396/0539E are extractor-flagged but absent from the source text (sign-extension artifacts).
- 0x00443B70: external ratio table dword_5C7530 and internal per-gear table base this+0x1EB0 are present in the source but absent from packet fields; the v13/v14 condition-code flags deciding the this+0x1EF0 write are not decoded; a2/a3 (shift direction/manual override) semantics are inferred, not confirmed; ten globals (dbl_59E420..dbl_59EDC0) are extractor-flagged but unused in the source.
- 0x00447C70: noise/trig table semantics and the HUD element constants (id 40, sub-type 2) are DERIVED; globals flt_59E43C, flt_59E84C, flt_59E868 are extractor-flagged but absent from the source.
- GamePost (0x0042DA30): each _Post call receives a global object pointer but no owner evidence for those subsystem objects is present in this packet; subsystem role names come from callee names only; global unk_5EC6D0 is extractor-flagged but absent from the source; StringSplitLoop's return semantics (why it gates the debug log) are outside this packet.
- 0x0042E1F0: semantics of the a3/a4 token arguments and the a5 scale factor are unknown; object identity beyond the four listed fields is unproven.
- 0x004352C0: the mapping of plane parameters a2/a4 onto this+0x0/+0x8 is DERIVED; flt_59E440 as zero-threshold vs physics clamp is DERIVED.
- 0x004353F0: the 'Constructor_stub' LEGACY abi label is not confirmed against live evidence; caller DynamicsObjectInitialization role not established.
- 0x004388D0: matrix layout (row-major vs column-major) is not distinguishable; the a2/a3 vector pointer bases are not enumerated among packet fields.
- 0x00443AF0: the four double thresholds and the mode selector are interpreted as BVH extents for collision pruning (DERIVED); the geometric meaning of input a2 is unresolved; mode 1 sharing the default path after its combined check is a structural oddity left as-is.
