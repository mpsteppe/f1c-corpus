# VehicleAIAndPit

Scope: `vehicle_ai_and_pit`  
Trust: `DERIVED`

Conservative DERIVED proposal for the vehicle-AI and pit subsystem. A per-vehicle AI state (F1CVehicle) carrying steering, command-queue, pit, fuel and tire fields is driven by a fixed 400-tick main loop (0x0042C690) that dispatches AI, physics, particle and wear subsystems on tick parity/modulo windows. Difficulty scaling is a small interpolation curve over the slider global. Pit strategy spans fuel-sufficiency checks, pit-entry forcing (ForcePitExit / SetCallToBox), a deduplicated command queue, post-pit cleanup, and a pit-stop part-state copy with scoring intervals. Tire physics is split into per-wheel compound application and per-vehicle model initialization. Owners marked CONFIRMED by the packet are the only members of the F1CVehicle class; every other function keeps the packet's owner or a DERIVED legacy-ABI lead.

## Function roles

- `0x0040F100` **UnknownObject** — Guarded scene-object/widget cleanup chain on an ID field: helper subroutine, arithmetic comparison, and cleanup subroutine; early-returns uninitialized when this+0x0 == -1.
- `0x004199E0` **UnknownObject** — AI retirement / vehicle-failure session event handler; gated to the player's team and race session; inserts driver-table entries (types 41, 1, 2, 273, 272) using lap-time gap calculation and ftol truncation.
- `0x0041A200` **F1CVehicle** — AI pit-strategy event handler restricted to the player vehicle; branches on pitting status to emit event type 42/52 into the session event table via DriverDataTableLookupAndTimeConversion and InsertDriverTableEntry.
- `0x00424750` **UnknownObject** — AI difficulty slider to scalar mapper; returns flat 1.0 at slider >= 95, otherwise a linear ramp from roughly 0.75 to below 1.0.
- `0x00424AC0` **AIDifficultyCurve** — AI difficulty curve interpolation between low/mid/high anchor constants (flt_5EA3DC / flt_5EA3E0 / flt_5EA3E4); slider > 100 interpolates mid-to-high, otherwise low-to-mid.
- `0x00424C80` **UnknownObject** — Per-frame AI ring-buffer noise field update; writes this+0x4448 from a trig lookup plus baseline minus a difficulty-scaled term; invoked by CameraViewportFrustumInitialization and AIMainUpdate.
- `0x00424CD0` **F1CVehicle** — AI command message queue dispatcher; switch on command id for state transitions (4, 5, 1, 15), race-phase cleanup, and a deduplicated {command,value} queue with capacity and idle handling.
- `0x00426CF0` **UnknownObject** — Per-frame AI steering blend, grip-degradation/decay, and racing-line correction applied to per-vehicle steering state; clamps against track-segment or difficulty-scaled limits.
- `0x00429EB0` **UnknownObject** — Per-frame AI pit-entry trigger; when the fuel multiplier drops below 1 during the pit-window phase and no pit stop is already requested, forces a pit exit.
- `0x0042A110` **F1CVehicle** — AI pit-state forcing / pit-entry request on a vehicle; race-session gated on last lap, teammate part value, and finish state; runs pit-controller actions and returns AIStateFlagSetter(1).
- `0x0042A180` **AI_Push_Lap_Closing_Gap** — Per-frame AI push-lap strategy for the player vehicle; adjusts target lap time, writes a performance scalar, selects a recommended tire compound against track-grip bands, and forces a pit exit on mismatch or low average tire wear.
- `0x0042A6F0` **F1CVehicle** — Post-pit-exit cleanup; sentinel slot fill, tire-change flag read and counter increment, session-gated time-of-next-exit clear, and next-exit timestamp scheduling.
- `0x0042A780` **UnknownObject** — AI passing/overtake score computation; first solves opponent tire forces, then combines an input term with AI weight and scaling fields and an opponent factor.
- `0x0042AC70` **F1CVehicle** — Sets the vehicle AI call-to-box flag (+0x454C) to 0 or 1; values greater than 1 are silently ignored; returns the input unchanged.
- `0x0042AD20` **UnknownObject** — Fuel multiplier computation; returns floor(fuelRateFactor * theoreticalLapsPerLitre - 0.2) via ftol when the FuelMult flag is set, otherwise the default value 100.
- `0x0042AD50` **PitStrategy** — AI pit-strategy fuel sufficiency check; returns TRUE immediately when the FuelMult check is disabled, otherwise compares remaining laps (reduced by a stint factor) against a fuel-consumption estimate.
- `0x0042AE00` **UnknownObject** — Zeroes a 0x50-byte per-instance AI state-flag block at this+17236 and returns 0; called from AI and race-struct initialization paths.
- `0x0042AEE0` **F1CVehicle** — Per-frame pit-blocked check; race path ORs lap/phase/byte/rear-wing-damage terms, non-race path returns bit 8 of an indexed pit-schedule slot.
- `0x0042C690` **UnknownObject** — Per-frame main game tick; fixed tick loop dispatching AI, physics, particle, fuel/wear and tire-force subsystems on tick parity and modulo windows; wraps the tick counter at 400 and returns the per-vehicle camera iterator result.
- `0x0042ED30` **UnknownObject** — Branch-free delegate on the frame path; forwards a selector field and a sub-struct to WeightedDataLookup.
- `0x0043DA10` **UnknownObject** — Per-wheel tire compound physics application; resolves the compound record, populates a per-wheel physics record, resolves slip-curve names, runs force/interpolation helpers, and writes the suspension-ratio output at this+0xAC.
- `0x0043E050` **UnknownObject** — Per-vehicle tire physics model initialization; FPU control-word save/restore, step and traction constants from 400 >> dword_7CE958, HDV file parsing, body-name mapping, physics init, brake-bias setup, and temp-buffer cleanup.
- `0x004A5330` **Pit_Part_State_Copy** — Pit-stop part-state copy from a source vehicle state into the pit-stop struct; bulk part data, tire brand/compound resolution, scoring interval computation, session compound override, callback chains, and return of PitstopStateTransition.

## Proposed classes

### F1CVehicle

Per-vehicle container of AI, steering, command-queue, pit, fuel and tire state; six functions with CONFIRMED packet ownership operate on it, and its fields are read/written by the wider set of per-frame AI functions in this packet.

Methods: `0x0041A200`, `0x00424CD0`, `0x0042A110`, `0x0042A6F0`, `0x0042AC70`, `0x0042AEE0`

- `this+0x00000000` `ptr subObjectPtr` (read, DERIVED)
- `obj+0x00000D18` `ptr rearWingDamagePtr` (read, GUESS)
- `obj+0x00000D58` `byte rearWingIntactFlag` (read, GUESS)
- `obj+0x000032C8` `int onTrackFlag` (read, GUESS)
- `this+0x00003448` `float theoreticalLapsPerLitre` (read, GUESS)
- `this+0x00003450` `int pittingStatus` (read, GUESS)
- `this+0x0000363C` `float tireWearSlotA` (read, GUESS)
- `this+0x00003734` `float tireWearSlotB` (read, GUESS)
- `this+0x000037CC` `float racingLineSteeringTarget` (read, GUESS)
- `this+0x0000382C` `float tireWearSlotC` (read, GUESS)
- `this+0x000038C4` `float actualSteering` (read, GUESS)
- `this+0x00003924` `float tireWearSlotD` (read, GUESS)
- `this+0x00003984` `float fuelRateFactor` (read, GUESS)
- `this+0x000039F9` `byte correctionGateByte` (read, GUESS)
- `this+0x000039FA` `byte pitBlockByte` (read, GUESS)
- `this+0x00004028` `float lateralSlipCorrectionOutput` (write, GUESS)
- `this+0x0000403C` `int lapNumber` (read, DERIVED)
- `this+0x00004040` `float stintLapsRemainingFactor` (read, GUESS)
- `this+0x00004060` `int retirementSubjectId` (read, GUESS)
- `this+0x00004064` `int finishState` (read, DERIVED)
- `obj+0x00004064` `int finishState` (read, GUESS)
- `this+0x000040D0` `ptr opponentVehiclePtr` (read, GUESS)
- `this+0x000040D4` `ptr leadingVehiclePtr` (read, GUESS)
- `this+0x0000413C` `double pitDecisionTimer` (read_write, GUESS)
- `this+0x00004410` `byte retiredFlag` (read, GUESS)
- `this+0x0000442C` `float lateralSlip` (read, GUESS)
- `this+0x00004434` `float steeringBlend` (read_write, GUESS)
- `this+0x00004438` `float gripMemory` (read_write, GUESS)
- `this+0x00004440` `float speed` (read, GUESS)
- `this+0x00004448` `float aiVariability` (write, GUESS)
- `this+0x00004464` `float steeringSmoothingLastFrame` (read_write, GUESS)
- `this+0x0000446C` `dword steeringSpeedOrFlagGate` (read, GUESS)
- `this+0x0000447C` `double nextPitExitTimestamp` (write, GUESS)
- `this+0x00004484` `float lapDistance` (read, GUESS)
- `this+0x000044A8` `ptr commandQueueBuffer` (read, DERIVED)
- `this+0x000044AC` `int commandQueueCapacity` (read, DERIVED)
- `this+0x000044B0` `int commandQueueIndex` (read_write, DERIVED)
- `this+0x000044B8` `float trackSegmentSteeringLimit` (read, GUESS)
- `this+0x000044C8` `float trackConditionFactor` (read, GUESS)
- `this+0x000044D8` `int remainingLaps` (read, GUESS)
- `this+0x000044F4` `float trackGrip` (read, GUESS)
- `this+0x00004500` `float passScoreWeightA` (read, GUESS)
- `this+0x00004504` `float passScoreWeightB` (read, GUESS)
- `this+0x00004534` `double timeOfNextExit` (write, GUESS)
- `this+0x00004538` `float trackParameter` (read, GUESS)
- `this+0x0000453C` `float targetLapTime` (read_write, GUESS)
- `this+0x00004544` `int commandCleanupFlag` (write, GUESS)
- `this+0x00004548` `byte pitLaneRouteFlag` (read_write, DERIVED)
- `this+0x0000454C` `int callToBox` (read_write, DERIVED)
- `this+0x00004550` `int waypointSetSelector` (read_write, GUESS)
- `this+0x0000457C` `float difficultyScaledSteeringLimit` (write, GUESS)
- `this+0x00004580` `float performanceScalar` (write, GUESS)
- `this+0x00004584` `byte tireChangeFlag` (read, GUESS)
- `this+0x0000458C` `int nextChosenCompound` (read, GUESS)
- `this+0x000045E0` `int compoundIdOrTireChangeCounter` (read_write, GUESS)
- `this+0x000045F4` `byte aiControlFlag` (write, GUESS)
- `this+0x000045FC` `dword steeringCorrectionFlag` (read, GUESS)
- `this+0x00004894` `int driverId` (read, DERIVED)
- `this+0x00008130` `int opponentPartStatus` (read, GUESS)
- `this+0x00008134` `int leadingPartStatus` (read, GUESS)
- `this+0x00008138` `int leadingVehicleStatus` (read, GUESS)
- `this+0x0000896C` `int opponentGapOut` (write, GUESS)
- `this+0x00008970` `int leadingGapOut` (write, GUESS)

### AIDifficultyCurve

Interpolates the AI difficulty slider onto an ability value using three anchor constants; selected by the packet's DERIVED legacy ABI lead.

Methods: `0x00424AC0`


### PitStrategy

Fuel and stint sufficiency decisions for AI pit timing; the packet names the owner only via the DERIVED legacy ABI lead. Its per-vehicle fields are covered by the F1CVehicle class.

Methods: `0x0042AD50`


### AI_Push_Lap_Closing_Gap

Per-frame qualifying push-lap strategy for the player vehicle: target-lap adjustment, performance scalar and tire-compound recommendation with pit-exit forcing. Named from the packet's DERIVED legacy ABI lead.

Methods: `0x0042A180`


### Pit_Part_State_Copy

Destination pit-stop part-state struct whose fields are filled by copying part data, tire brand/compound, and scoring intervals from a source vehicle state; named from the packet's DERIVED legacy ABI lead.

Methods: `0x004A5330`

- `this+0x0000000C` `ptr callbackList0` (read, GUESS)
- `this+0x00000010` `ptr callbackList1` (read, GUESS)
- `this+0x0000006C` `int partValue` (write, GUESS)
- `this+0x00000075` `byte partFlagByte` (write, GUESS)
- `this+0x000000A8` `int partCount` (read, GUESS)
- `this+0x000000AC` `int validPartIndex` (write, GUESS)
- `this+0x000000EC` `int partDataA` (write, GUESS)
- `this+0x000000F0` `int partDataB` (write, GUESS)
- `this+0x000000F5` `byte partFlagByteF5` (write, GUESS)
- `this+0x00000158` `int tireBrand` (write, GUESS)
- `this+0x0000015C` `int previousCompound` (read_write, GUESS)
- `this+0x00000160` `int scoringBase` (write, GUESS)
- `this+0x00000164` `int scoringInterval1Start` (write, GUESS)
- `this+0x00000168` `int scoringInterval1Value` (write, GUESS)
- `this+0x0000016C` `int scoringInterval2Start` (write, GUESS)
- `this+0x00000170` `int scoringInterval2Value` (write, GUESS)
- `this+0x00000174` `int scoringInterval3Start` (write, GUESS)
- `this+0x00000178` `int scoringInterval3Value` (write, GUESS)
- `this+0x0000017C` `float scoringScale` (write, GUESS)
- `this+0x00000184` `int callbackCount0` (write, GUESS)
- `this+0x00000188` `int callbackCount1` (write, GUESS)
- `this+0x0000018C` `int callbackCount2` (write, GUESS)

### TirePhysicsModel

Per-vehicle tire physics model built from HDV data and applied per wheel; the two tire functions in this packet operate on the same this base and share the compound-index, step and context-handle offsets.

Methods: `0x0043DA10`, `0x0043E050`

- `this+0x00000060` `int stepScaledDummyA` (write, GUESS)
- `this+0x00000064` `int stepScaledDummyB` (write, GUESS)
- `this+0x00000068` `double stepInverse` (write, GUESS)
- `this+0x000000AC` `float suspensionRatioOutput` (write, GUESS)
- `this+0x0000145C` `int compoundIndex` (read, DERIVED)
- `this+0x00001F00` `ptr physicsContextHandle` (write, DERIVED)

## Compatibility contracts

- **CallToBoxValueGate** — SetCallToBox writes only 0 or 1 to vehicle+0x454C; any input value greater than 1 is ignored and the field keeps its prior value. A replacement must preserve this gate.
- **AIPitDecisionTimer** — AI command id 1 writes vehicle+0x413C to session time (dbl_8AFEA0) + 2.0, scheduling the pit decision timer.
- **DriverEventTypeCodes** — InsertDriverTableEntry on the session table at flt_5EA618 consumes driver-table type codes 41, 1, 2, 42, 52, 272 and 273, with the magic sentinel -2.0 used for unfilled time arguments.
- **AICommandQueueLayout** — The AI command queue stores 8-byte {command, value} entries in the buffer at +0x44A8 with capacity at +0x44AC and index at +0x44B0; already-pending commands are deduplicated by re-sending the queued response, and a full queue restores the prior index instead of overwriting.
- **MainTick400** — The main game tick converts session time (dbl_8AFEA0 * 400) to a tick count; the tick counter dword_7C5698 wraps at 400 and dword_7C5694 is clamped so the pending tick delta never exceeds 201.
- **TractionModeShift** — The tire model step is derived as 400 >> dword_7CE958 and its traction constants are published to the globals dbl_5E5238 and dbl_5E5240; consumers outside this packet depend on those globals.
- **PitStopScoringIntervals** — CopyPitPartState fills three scoring interval slots at this+0x164/0x16C/0x174 with fixed starts (1024/2048/3072) when the scoring scale is zero, or with CRTFtol cumulative distances offset by dword_7D0374 otherwise.

## Unresolved

- Name conflict for 0x0042A110: the historical name 'ForcePitExit' conflicts with the packet ABI lead 'RequestPitEntry' (disassembly enters pit state 1 and sets CallToBox=1). Not resolvable from packet evidence alone.
- Field this+0x4550 has dual semantics across functions: 0x00424CD0 names it WaypointSetSelector (set to 1) while 0x00429EB0 treats it as a pit-requested flag; the packet does not reconcile them.
- Field this+0x45E0 has triple use: tire-compound id (0x0042A180), tire-change counter incremented when the change flag is clear (0x0042A6F0), and pit-schedule index (0x0042AEE0).
- dword_7C56A8 == 8 as a race-phase meaning (PitStopBlockingCondition, AIRetirementVehicleFailureEvent, AICommandMessageQueueDispatcher) comes from existing-analysis prose; the packet only evidences the literal comparison.
- RacePhasePitEntryTrigger (0x00429EB0) names ForcePitExit only in raw source text; no call-target address is evidenced in the packet.
- MainGameTickUpdate applies offset literals +13000 (pause flag) and +18620 (race-state flag) to the player vehicle pointer dword_7C54E8; these are direct source literals with no enumerated field evidence refs.
- ForcePitExit passes the pit controller pointer at this+0x32CC (element +3251) to both callees, but the packet lists no field evidence ref for it.
- AIComputePassScore (0x0042A780) uses a1 offsets (a1[4416], a1[4417], a1[4431], a1[4448]) that may be a separate AI-state float array rather than the F1CVehicle struct; only the field:this form is evidenced.
- The flattened offsets 0x8130/0x8134/0x8138/0x896C/0x8970 denote dereferenced fields of the opponent and leading vehicle structs in AIRetirementVehicleFailureEvent; the packet gives no struct-local names for them.
- The float globals in the 0x0059E43C..0x0059EC70 range are listed as read but are folded into FPU literals by Hex-Rays; their one-to-one mapping to specific scaling constants (0.45, 0.15, 0.92, 2500.0, 273.16, 0.003, 0.89999998, ...) is DERIVED, not deterministic.
- Driver-table type codes (41, 1, 2, 42, 52, 272, 273) and the -2.0 sentinel arguments have no meaning given by the packet.
- The sub-object reached through this+0 (finishState at obj+0x4064, onTrack at obj+0x32C8, rear-wing damage at obj+0xD18/0xD58) is never named as a distinct class by the packet.
- The gating constants of the difficulty slider (normalization points 70, 95, 100 and slopes 0.039999999 / 0.033333335 / 0.05) are raw literals; their tuning rationale is unknown.
- AIDifficultyScalar reads four globals (0x0059E43C, 0x0059E7F8, 0x0059E7FC, 0x0059E860) that do not appear in the decompiled body; several other functions similarly list globals absent from their raw source, which the fills attribute to compiler folding.
- The pit-stop state machinery advanced by CopyPitPartState (ArithmeticComparison_5660, StateTransition, PitstopStateTransition) is invoked but its state/transition table is outside this packet.
- AIClearStateFlags semantics (the 0x50-byte block at this+17236) are DERIVED from the function name and AI callers; no field table or callee evidence constrains the cleared-block layout.
- The packet required_material_refs list itself contains a malformed entry ('global:0x0059E420 and global:0x0059EC70 appear in the packet global table but not in the raw source text.'); it is preserved verbatim in unresolved_evidence_refs for traceability.
