# VehicleAIPitControl

Scope: `vehicle_ai_and_pit`  
Trust: `DERIVED`

The vehicle AI subsystem drives one race vehicle per frame. AIMainUpdate (0x00424E70) is the tick orchestrator: it gates on aiEnableFlag, runs a pre-race/formation init branch and a racing branch, and commits control outputs into the vehicle input fields (0x3580/0x3584/0x357C). AIDriverStructInit (0x00424790) reinitialises the per-vehicle AI field block. The racing path delegates to AIWaypointSteeringUpdate (0x00426430), AIRacingLine (0x00425920), computeSteeringTarget (0x004270A0) and a driverStatus state machine (0..7) that dispatches SteeringAngleController (0x00425670) and related sub-functions. updateAIAbility (0x00429470) drifts the driver ability value and drives pit-stop decisions; PitStopDecisionTireCompound (0x0042A3D0) schedules tire compounds and can retire the vehicle. AISteeringRacingLineCorrection (0x0042B0E0) adjusts steering against the racing line. Two UNKNOWN-owner dispatch helpers (0x00409F40, 0x0040B360) perform chained vtable dispatch.

## Function roles

- `0x00409F40` **UnknownObject** — Chained vtable dispatch helper: calls slot vtable+0x18 on this, then slot +0x1C on the non-null result and returns the second result, else the first.
- `0x0040B360` **UnknownObject** — Chained virtual dispatch helper: calls slot vtable+24 on this, then slot +28 on the non-null result, else returns the first result.
- `0x00424790` **F1CVehicle** — Per-frame AI driver subsystem reinitialization: clears AI state flags/timers/counters, seeds waypoint sentinels, resets pace/grip/pit/speed defaults, optionally reloads waypoint data and command-queue buffers.
- `0x00424E70` **F1CVehicle** — Per-frame AI tick orchestrator: entry gate on AIEnableFlag, pre-race/formation init path, and racing path (heading vectors, driveability gate, lap-push, AIAbility refresh, pit entry/exit transitions, driverStatus 0..7 dispatch).
- `0x00425670` **UnknownObject** — AI steering-angle and driver-status controller: follow-target steering (state 6) vs direction-vector steering, steering-error accumulator, position-snapshot timer toggling states 6/0.
- `0x00425920` **F1CVehicle** — AI racing-line and speed-profile update: waypoint chain resolution, lead-car aero drag, tire-force energy-decay speed profile, overtaking threat scoring, throttle/brake targets and overtaking-window flag.
- `0x00426430` **F1CVehicle** — AI waypoint-following and steering update: speed magnitude, waypoint re-query on drift, 20-node look-ahead chain rebuild, pit-lane entry command dispatch, tire-force grip solve, 0..3 speed zone, boundary-clamped steering targets.
- `0x004270A0` **RacingLineSteeringController** — AI steering-target computation: 5-lane boundary scan, centre steering, lane scoring via spatial queries, overtaking state transitions and session-time steering overrides.
- `0x00429470` **UnknownObject** — Per-frame AI ability/driver tick: engagement-mode selection, difficulty scaling, per-frame ability drift and probability override, steering-target recompute, pit-stop decision logic (pit exit, tire-compound duration, fuel-weight pit exit).
- `0x0042A3D0` **F1CVehicle** — Per-frame AI pit-stop logic: tire-compound selection vs lap count and session state, wing-repair lap records re-arm, vehicle retirement on blocking condition.
- `0x0042B0E0` **UnknownObject** — AI steering correction relative to the racing line: reference-opponent scan in race phase, wrapped-distance track parameter, overtaking/timing decisions and rotation-matrix steering recompute.

## Proposed classes

### F1CVehicle

Race vehicle: the AI field block (this base, roughly +0x4000..+0x461C) plus the shared vehicle fields (position, velocity, heading, gear, engine RPM, fuel, car conditions) that the AI tick reads and writes. The obj base is the vehicle root reached via this+0x0.

Methods: `0x00424790`, `0x00424E70`, `0x00425920`, `0x00426430`, `0x0042A3D0`

- `this+0x00000000` `pointer objectSelfPointer` (read, DERIVED)
- `this+0x00000004` `float speedScalar` (read, DERIVED)
- `this+0x00000008` `int32 gridIndexOffset` (read_write, GUESS)
- `this+0x000032C8` `int32 aiEnableFlag` (read, DERIVED)
- `this+0x00003378` `int32 tireChoiceIndex` (read_write, DERIVED)
- `this+0x000034BC` `float rotationAxis0` (read, GUESS)
- `this+0x000034C4` `float rotationAxis1` (read, GUESS)
- `this+0x000034C8` `float rotationAxis2` (read, GUESS)
- `this+0x000034D0` `float rotationAxis3` (read, GUESS)
- `this+0x000034D4` `float rotationAxis4` (read, GUESS)
- `this+0x000034DC` `float rotationAxis5` (read, GUESS)
- `this+0x000034E0` `float positionX` (read, DERIVED)
- `this+0x000034E4` `float positionY` (read, DERIVED)
- `this+0x000034E8` `float positionZ` (read, DERIVED)
- `this+0x000034F0` `float headingYaw` (read, DERIVED)
- `this+0x000034F8` `float velocityX` (read_write, DERIVED)
- `this+0x000034FC` `float velocityY` (read_write, DERIVED)
- `this+0x00003500` `float velocityZ` (read_write, DERIVED)
- `this+0x0000357C` `float controlInputSteering` (write, DERIVED)
- `this+0x00003580` `float controlInputThrottle` (write, DERIVED)
- `this+0x00003584` `float controlInputBrake` (write, DERIVED)
- `this+0x0000396C` `float gripSourceField` (read, GUESS)
- `this+0x00003984` `float fuelLevel` (read, DERIVED)
- `this+0x00003988` `float elapsedCap` (read, DERIVED)
- `this+0x0000399C` `float engineRpmLower` (read, GUESS)
- `this+0x000039A0` `float engineRpm` (read, DERIVED)
- `this+0x000039A8` `float targetRpm` (read, DERIVED)
- `this+0x000039FA` `byte pitLapTriggerByte` (read, DERIVED)
- `this+0x000039FC` `int32 currentGear` (read, DERIVED)
- `this+0x00003AA8` `pointer opponentPointer` (read, DERIVED)
- `this+0x00003D6C` `int32 carConditions` (read, DERIVED)
- `this+0x00004000` `float positiveGateField` (read, GUESS)
- `this+0x00004028` `int32 aiInternalCounter` (read_write, GUESS)
- `this+0x0000403C` `int32 lapCounter` (read, DERIVED)
- `this+0x00004040` `int32 finishValue` (read, GUESS)
- `this+0x00004044` `int32 ringBufferInputIndex` (read, DERIVED)
- `this+0x00004060` `int32 targetIndex` (read, GUESS)
- `this+0x00004064` `int32 finishState` (read, DERIVED)
- `this+0x00004068` `int32 reasonCode` (read_write, DERIVED)
- `this+0x0000409C` `float pitWaitMinBuffer` (read, GUESS)
- `this+0x0000413C` `float pitDecisionTimer` (read_write, DERIVED)
- `this+0x00004140` `byte processedByte` (read_write, DERIVED)
- `this+0x00004144` `int32 pitRingEntryLap` (read_write, DERIVED)
- `this+0x00004148` `int32 pitRingEntryState` (read_write, DERIVED)
- `this+0x0000416C` `float lapPitBuffer` (read_write, GUESS)
- `this+0x00004170` `float pitWaitTimer` (read_write, DERIVED)
- `this+0x00004174` `pointer laneTable` (read_write, GUESS)
- `this+0x00004180` `float laneFrontDistance` (read_write, GUESS)
- `this+0x000041A4` `float laneGap` (read_write, GUESS)
- `this+0x000041A8` `float laneDistanceRange` (read, GUESS)
- `this+0x000041AC` `int32 laneNearestIndex` (read_write, GUESS)
- `this+0x000041B4` `int32 laneSlot` (read_write, GUESS)
- `this+0x000042D8` `int32 strideSlot` (read_write, GUESS)
- `this+0x00004354` `pointer currentWaypointPtr` (read_write, DERIVED)
- `this+0x00004358` `pointer waypointChainBase` (read_write, DERIVED)
- `this+0x00004364` `pointer chainNodeThreePtr` (read, GUESS)
- `this+0x000043A4` `float[20] speedProfile` (read_write, GUESS)
- `this+0x000043F4` `float distanceToWaypoint` (write, GUESS)
- `this+0x000043F8` `int32 targetWaypoint` (read_write, DERIVED)
- `this+0x000043FC` `float targetSpeed` (read_write, DERIVED)
- `this+0x00004400` `pointer leadReference` (read, DERIVED)
- `this+0x00004404` `float nextAbilityTime` (read_write, DERIVED)
- `this+0x00004408` `float steeringOutput` (read_write, DERIVED)
- `this+0x0000440C` `float steeringTarget` (read_write, DERIVED)
- `this+0x00004410` `byte retiredFlag` (write, DERIVED)
- `this+0x00004414` `float steeringLeftBound` (read_write, DERIVED)
- `this+0x00004418` `float steeringRightBound` (read_write, DERIVED)
- `this+0x0000441C` `float steeringLateral` (read_write, DERIVED)
- `this+0x00004420` `float centreSteering` (read_write, DERIVED)
- `this+0x00004424` `float passWindow` (read_write, DERIVED)
- `this+0x00004428` `float lateralDeviation` (read_write, DERIVED)
- `this+0x0000442C` `float steeringAccumulator` (read_write, DERIVED)
- `this+0x00004430` `int32 aiStateField` (read_write, GUESS)
- `this+0x00004434` `float brakeTarget` (read_write, DERIVED)
- `this+0x00004438` `float throttleTarget` (read_write, DERIVED)
- `this+0x0000443C` `float dragActiveFlag` (read_write, DERIVED)
- `this+0x00004440` `float speed` (read_write, DERIVED)
- `this+0x00004444` `float speedRatio` (read_write, DERIVED)
- `this+0x00004448` `float countdownField` (read_write, GUESS)
- `this+0x0000444C` `int32 sessionPhaseField` (read_write, DERIVED)
- `this+0x00004450` `float trackDistance` (read_write, DERIVED)
- `this+0x00004454` `float trackPositionBlend` (read_write, GUESS)
- `this+0x00004458` `int32 waypointCounter` (read_write, DERIVED)
- `this+0x0000445C` `byte overtakeWindowByte` (write, DERIVED)
- `this+0x00004460` `float maneuverTime` (read_write, GUESS)
- `this+0x00004464` `float paceField` (read_write, GUESS)
- `this+0x00004468` `int32 speedZone` (read_write, DERIVED)
- `this+0x0000446C` `float steeringErrorAccumulator` (read_write, DERIVED)
- `this+0x00004470` `float snapshotPosX` (read_write, GUESS)
- `this+0x00004474` `float snapshotPosY` (read_write, GUESS)
- `this+0x00004478` `float snapshotPosZ` (read_write, GUESS)
- `this+0x0000447C` `float pitExitTimer` (read_write, DERIVED)
- `this+0x00004480` `double lastAiUpdateTime` (read_write, DERIVED)
- `this+0x00004484` `float passScoreSentinel` (read_write, DERIVED)
- `this+0x00004488` `byte chainRebuildByte` (read_write, DERIVED)
- `this+0x0000448C` `float directionVectorX` (read_write, DERIVED)
- `this+0x00004490` `float directionVectorY` (read_write, DERIVED)
- `this+0x00004494` `float directionVectorZ` (read_write, DERIVED)
- `this+0x00004498` `float waypointOffsetX` (write, GUESS)
- `this+0x000044A0` `float waypointOffsetZ` (write, GUESS)
- `this+0x000044A4` `float lanePenaltyField` (read, GUESS)
- `this+0x000044A8` `pointer commandQueueBuffer` (read_write, DERIVED)
- `this+0x000044AC` `int32 commandQueueCount` (read_write, DERIVED)
- `this+0x000044B0` `int32 slotIndexField` (read_write, DERIVED)
- `this+0x000044B4` `float steeringDivisor` (read, DERIVED)
- `this+0x000044B8` `float paceA` (read, GUESS)
- `this+0x000044C4` `float paceB` (read, GUESS)
- `this+0x000044CC` `float passingNorm` (read_write, DERIVED)
- `this+0x000044D4` `float abilityProbField` (read, GUESS)
- `this+0x000044D8` `float abilityUpperBound` (read, GUESS)
- `this+0x000044F4` `float abilityClamp` (read, GUESS)
- `this+0x000044F8` `float trackAggressionEffective` (read_write, DERIVED)
- `this+0x000044FC` `int32 opponentIndex` (read, GUESS)
- `this+0x00004500` `float paceParamA` (read, GUESS)
- `this+0x00004504` `float paceParamB` (read, GUESS)
- `this+0x00004508` `int32 frameLatchA` (read_write, DERIVED)
- `this+0x0000450C` `int32 frameLatchB` (read_write, DERIVED)
- `this+0x00004510` `int32 driverStatus` (read_write, DERIVED)
- `this+0x00004524` `float gapDistance` (read_write, DERIVED)
- `this+0x00004528` `float steeringSignA` (read_write, GUESS)
- `this+0x0000452C` `float steeringSignB` (read_write, GUESS)
- `this+0x00004534` `float timeOfNextExit` (read_write, DERIVED)
- `this+0x00004538` `float maxSpeed` (read_write, DERIVED)
- `this+0x0000453C` `float driverAbility` (read_write, DERIVED)
- `this+0x00004540` `float countdownStagger` (write, GUESS)
- `this+0x00004544` `byte activeFlag` (read_write, DERIVED)
- `this+0x00004548` `byte pitLaneRouteFlag` (read_write, DERIVED)
- `this+0x0000454C` `int32 callToBox` (read_write, DERIVED)
- `this+0x00004550` `int32 waypointSetSelector` (read_write, DERIVED)
- `this+0x00004554` `float paceFactor` (read_write, DERIVED)
- `this+0x00004558` `float thresholdField` (read_write, DERIVED)
- `this+0x0000455C` `int32 overtakeCounter` (read_write, DERIVED)
- `this+0x00004560` `float countdownLightTimerA` (read_write, GUESS)
- `this+0x00004564` `float countdownLightTimerB` (read_write, GUESS)
- `this+0x00004568` `float countdownLightTimerC` (read_write, GUESS)
- `this+0x0000456C` `byte blockFlagByte` (read_write, GUESS)
- `this+0x00004570` `int32 overtakeSideIndexA` (read_write, GUESS)
- `this+0x00004574` `int32 overtakeSideIndexB` (read_write, GUESS)
- `this+0x00004578` `byte byteFlag` (write, GUESS)
- `this+0x00004579` `byte steeringLatchByte` (read_write, DERIVED)
- `this+0x0000457C` `float difficultyScalar` (read_write, GUESS)
- `this+0x00004584` `byte pitFlag` (read_write, GUESS)
- `this+0x00004588` `int32 lapCount` (read, DERIVED)
- `this+0x0000458C` `int32 nextChosenTires` (read, GUESS)
- `this+0x000045E0` `int32 tireCompoundSlot` (read_write, DERIVED)
- `this+0x000045E8` `float compoundScale` (read, GUESS)
- `this+0x000045F4` `byte aiControlFlag` (read_write, DERIVED)
- `this+0x000045F8` `pointer otherVehiclePtr` (read_write, DERIVED)
- `this+0x000045FC` `int32 statusField` (read_write, DERIVED)
- `this+0x00004600` `int32 tireRecordScanBase` (read_write, GUESS)
- `this+0x0000461C` `float maxSpeedDistanceSq` (read_write, DERIVED)
- `obj+0x00000CD4` `int32 frontWingRepairLap` (read, DERIVED)
- `obj+0x00000D14` `int32 frontWingRecordClear` (read, DERIVED)
- `obj+0x00000D18` `int32 rearWingRepairLap` (read, DERIVED)
- `obj+0x00000D58` `int32 rearWingRecordClear` (read, DERIVED)
- `obj+0x000032C8` `int32 objAiEnable` (read, DERIVED)
- `obj+0x000048A4` `int32 overtakeAllowanceCounterA` (read, DERIVED)
- `obj+0x000048A8` `int32 overtakeAllowanceCounterB` (read, DERIVED)

### WaypointNode

Waypoint-graph node reached through the vehicle pointer fields (0x4354 current, 0x4358 chain base, 0x4364 third chain node, 0x4400 lead reference, forward-link at +0x114). Holds position, tangent, up-vector, track distance, lateral boundaries, grip/traction, heading and node-id/pit-entry flag.

Methods: 

- `*(this+0x4400)+0x00000000` `float positionX` (read, GUESS)
- `*(this+0x4400)+0x00000008` `float positionZ` (read, GUESS)
- `*(this+0x4354)+0x0000000C` `float tangentComponentA` (read, GUESS)
- `*(this+0x4354)+0x00000014` `float tangentComponentB` (read, GUESS)
- `*(this+0x4400)+0x00000018` `float passWindowSize` (read, GUESS)
- `*(this+0x4354)+0x00000020` `float upVectorComponentA` (read, GUESS)
- `*(this+0x4354)+0x00000028` `float upVectorComponentB` (read, GUESS)
- `*(this+0x4354)+0x00000034` `float setupBoundA` (read, GUESS)
- `*(this+0x4354)+0x00000038` `float setupBoundB` (read, GUESS)
- `*(this+0x4354)+0x00000048` `float trackDistance` (read, GUESS)
- `*(this+0x4354)+0x00000050` `float boundaryLeft` (read, GUESS)
- `*(this+0x4354)+0x00000054` `float boundaryRight` (read, GUESS)
- `*(this+0x4354)+0x00000070` `float grip` (read, GUESS)
- `*(this+0x4354)+0x00000074` `float traction` (read, GUESS)
- `*(this+0x4354)+0x00000094` `float positionXCopy` (read, GUESS)
- `*(this+0x4354)+0x0000009C` `float positionZCopy` (read, GUESS)
- `*(this+0x4354)+0x000000B8` `float heading` (read, GUESS)
- `*(this+0x4400)+0x00000114` `pointer forwardLink` (read, GUESS)
- `*(this+0x4354)+0x0000012C` `int32 nodeId` (read, GUESS)

### RacingLineSteeringController

Per-frame AI steering-target computation: 5-lane boundary scan, centre-steering computation, lane scoring via spatial nearest-neighbour queries, and overtaking state transitions on the vehicle.

Methods: `0x004270A0`


## Compatibility contracts

- **ControlOutputCommitContract** — Every AI tick path must write committed control outputs into the input fields this+0x3580 (throttle), this+0x3584 (brake), this+0x357C (steering) before returning; the racing fallthrough writes neutral (0, 1.0, 0). A replacement executable must preserve this commit location and neutrality.
- **DriverStatusContract** — driverStatus at this+0x4510 must keep the documented 0..7 semantics: pit entry forces 4 or 5 (session type 0x7C56A4==7 selects 4), 6 is follow-target steering, 7 stops the car until Speed<0.2, and the racing-line reset forces 4/5 by the same session-type rule.
- **AIEnableGateContract** — aiEnableFlag at this+0x32C8 gates the whole AI tick: AIMainUpdate returns immediately when >1, and the racing tick re-checks obj+0x32C8==1. A replacement must preserve both guards.
- **PitLaneFlagContract** — PitLaneRouteFlag this+0x4548 and the pit-lane byte this+0x45F4 steer the pit-box/pit-lane steering overrides in computeSteeringTarget and gate the pre-race init path in AIMainUpdate; PitStopDecisionTireCompound sets 0x4548=1 on entry.
- **WaypointTreeContract** — The waypoint spatial tree dword_5EA2C0 and its count/global neighbours (0x5EA2CC, 0x5EA2D0) back the nearest-neighbour queries; waypoint node id at +0x12C and the set selector this+0x4550 drive pit-lane command dispatch (message id 14).
- **SessionPhaseContract** — Global session type dword_7C56A4 and phase dword_7C56A8 select the driver-status pit values, the countdown/launch ramp (dword_5C30E0 / dword_5C3144 tables, global byte_5C3160), the ability drift, and the retirement path; simulation time dbl_8AFEA0 is the shared clock for all timers.
- **RetiredFlagContract** — Retirement sets RetiredFlag at this+0x4410 and clears AIControlFlag at this+0x45F4, then logs through sub_4BC060; AIDriverStructInit clears both when a session (re)starts.

## Unresolved

- Owner identity for 0x00425670, 0x00429470, 0x0042B0E0, 0x00409F40 and 0x0040B360 is UNKNOWN in the packet; they are not assigned to a class and only reach the F1CVehicle AI field block through their confirmed callers.
- Dual role of this+0x454C (CallToBox command input in computeSteeringTarget vs waypoint node-id key for chain-link resolution in AIRacingLine/AIWaypointSteeringUpdate) is not resolved.
- Vtable dispatch targets behind 0x00409F40 (slot +0x18 then +0x1C) and 0x0040B360 (slots +24/+28) are unresolved; concrete callees are unknown.
- Speed-profile array length (20) and the tire-record scan base (0x4600, up to 7 entries) are literals not present in packet field metadata.
- Indexed array write at this + 4*(this+0x4148) + 0x3D70 lands inside the car-conditions buffer; element meaning unresolved.
- Lane-table (0x4174) 68-byte entry layout and the candidate ownership of the obj+0x48A4/0x48A8 overtake-allowance counters are inferred from pointer arithmetic, not a named struct.
- Dozens of read-only float/double tuning constants in 0x59E43C..0x59E99C and unk_7CE2F0 / dword_7CEC30 / dword_8ACEE0 are read by the functions but have no visible use in the decompiled bodies; presumed consumed inside inlined callees.
- AI command-queue message id 14 and the semantics of sub_4A46F0 are not established from packet evidence.
- Stride-slot targets of the reinit loops (anchors +0x41B4, +0x42D8, +0x4144) beyond the packet-listed anchors are not named.
- Waypoint-graph link navigation is by array index in the raw; the node layout beyond the packet-listed offsets stays unresolved.
- Field pairs this+0x4560/0x4564/0x4568 (countdown light timers) and this+0x442C/0x4438 (brake/throttle output pair) keep offset-based names; the packet provided no semantic names.
