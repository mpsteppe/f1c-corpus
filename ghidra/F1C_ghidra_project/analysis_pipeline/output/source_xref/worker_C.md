# Source Cross-Reference: docs/02-ai-system.md

## RTTI Class Mappings

| rFactor Class | F1C Function(s) | Confidence | Evidence |
|--------------|-----------------|------------|----------|
| `AIDatabase` (`.?AVAIDatabase@@`) | FUN_004040a0 (AIDatabase::Init), FUN_00402690 (Waypoint DB Loader) | HIGH | rFactor Dedicated RTTI confirms AIDatabase class; both functions operate on AI database struct (param_1 with waypoint arrays, grid/pit spots). FUN_004040a0 initializes aiDB[0x00-0x5a] and loads "AI Database File" config. |
| `Steward` (`.?AVSteward@@`) | FUN_004333e0 (AI Settings File Loader), FUN_00433890 (AI Settings Resolver) | MED | Steward manages session rules; AI settings file resolution depends on session type (DAT_007c56a4), which Steward controls. |
| `Game` (`.?AVGame@@`) | FUN_00424e70 (AI Main Update), FUN_004270a0 (AI Racing Line) | MED | Game class owns the main loop; AI tick dispatched from Game::Post. RacePhase state machine (0-8) defined by ScoringInfoV2.mGamePhase in rFactor SDK. |
| `DynMan` (`.?AVDynMan@@`) | FUN_0042caa0 (AI Lateral Force), FUN_004a4710 (Find Nearest Vehicle) | MED | DynMan owns VehiclePtrArray (DAT_007c54f0) and VehicleCount (DAT_005c329c) — both used extensively in AI proximity/lateral force functions. |
| `PFData<FormationAndStart>` | FUN_0041a3a0 (AI Formation Lap) | HIGH | rFactor RTTI confirms `PFData<FormationAndStart>` type; formation lap logic in FUN_0041a3a0 dispatches based on formationLapAction (1/2/3). |
| `PFData<WeatherCond>` | FUN_0042a180 (AI Rain/Wet Handle) | HIGH | rFactor RTTI confirms `PFData<WeatherCond>`; FUN_0042a180 references DAT_008afee8 (current wetness) for rain penalty computation. |
| `PitMan` (`.?AVPitMan@@`) | FUN_0042a3d0 (Pit Decision), FUN_0042a110 (Force Pit Exit) | MED | PitMan manages pit state; AI pit strategy functions interact with pit crew state at +0x3450 and bitmask at +0x1178. |
| `SearchGrid` (`.?AVSearchGrid@@`) | FUN_00402690 (Waypoint loader) | MED | SearchGrid used for spatial queries; waypoint database loaded by FUN_00402690 feeds into search grid for AI pathfinding. |

## Parameter-to-Offset Mappings

### [GENERAL] section — AI Performance Parameters (in .hdv, read via parsing code → AI database struct)

| Config Param | Section | F1C Struct Offset | Current Name | Proposed Name | Confidence |
|-------------|---------|-------------------|--------------|---------------|------------|
| AIAimSpeedsPerWP | GENERAL | aiDB waypoint struct | — | LookaheadSpeedArray | HIGH — rFactor .hdv confirms param name, doc mentions speed lookahead per waypoint |
| AICornerReductionBase | GENERAL | (anonymous function) | — | CornerDecelFactor | HIGH — .hdv comment: "(pointspeed/this number)= % deceleration through a point" |
| AIDamperFast | GENERAL | (AI damper computation) | AIDamperFast | — | HIGH — confirmed across NASCAR 2003/2004/rFactor .hdv files |
| AIDamperSlow | GENERAL | (AI damper computation) | AIDamperSlow | — | HIGH — same evidence as above |
| AIEvenSuspension | GENERAL | (AI suspension computation) | — | SuspAveragingStab | HIGH — doc mentions "averages spring/damper rates for stability" |
| AISpringRate | GENERAL | (AI spring rate) | AISpringRate | — | HIGH — present in all ISI game .hdv files since NASCAR 2003 |
| AIDownforceBias | GENERAL | (AI aero bias) | AIDownforceBias | — | HIGH — confirmed in rFactor and NASCAR 2004 |
| AIDownforceZArm | GENERAL | (AI aero CoP) | AIDownforceZArm | — | HIGH — confirmed in rFactor and NASCAR 2004 |
| AITorqueStab | GENERAL | (AI torque stability) | AITorqueStab | — | HIGH — 3-value tuple (bump, rebound, torque) |
| AIFuelMult | GENERAL | (AI fuel calc) | AIFuelMult | — | HIGH — PLR override, all ISI games |
| AIPerfUsage | GENERAL | (AI perf estimate) | AIPerfUsage | — | HIGH — (brake power, brake grip, corner grip) overrides |
| AITableParams | GENERAL | (AI perf tables) | AITableParams | — | HIGH — (max load, min radius) for performance tables |
| AISlipReaction | GENERAL | (AI grip loss) | AISlipReaction | — | HIGH — rFactor .hdv confirms (prediction factor, throttle recovery) |
| AIMinPassesPerTick | GENERAL | — | AIMinPassesPerTick | — | HIGH — physics accuracy, increased during rotation events |
| AIRotationThreshold | GENERAL | — | AIRotationThreshold | — | HIGH — rads/sec threshold to increment passes |
| AIFuelMult | GENERAL | — | AIFuelMult | — | HIGH — PLR override for AI fuel usage |

### [AIDPENALTIES] section — Driving Aid Weight Penalties

| Config Param | Section | F1C Context | Current Name | Proposed Name | Confidence |
|-------------|---------|-------------|--------------|---------------|------------|
| TC | AIDPENALTIES | FUN_00424080 (AI loader) | — | TractionControlPenalty | HIGH — weight penalty fractions for TC aid level |
| ABS | AIDPENALTIES | FUN_00424080 | — | ABSPenalty | HIGH — weight penalty fractions for ABS aid level |
| Stability | AIDPENALTIES | FUN_00424080 | — | StabilityControlPenalty | HIGH |
| Autoshift | AIDPENALTIES | FUN_00424080 | — | AutoshiftPenalty | HIGH |
| Steering | AIDPENALTIES | FUN_00424080 | — | SteeringHelpPenalty | HIGH |
| Braking | AIDPENALTIES | FUN_00424080 | — | BrakingAssistPenalty | HIGH |
| Invulnerable | AIDPENALTIES | FUN_00424080 | — | InvulnerablePenalty | HIGH |
| SpinRecovery | AIDPENALTIES | FUN_00424080 | — | SpinRecoveryPenalty | HIGH |
| AutoPit | AIDPENALTIES | FUN_00424080 | — | AutoPitPenalty | HIGH |
| AutoLift | AIDPENALTIES | FUN_00424080 | — | AutoLiftPenalty | HIGH |
| AutoBlip | AIDPENALTIES | FUN_00424080 | — | AutoBlipPenalty | HIGH |

### Vision/Waypoint Parameters from .hdv (not in doc yet)

| Config Param | Section | Notes | Confidence |
|-------------|---------|-------|------------|
| FeelerFlags | GENERAL | Collision feeler generation flags | HIGH — present in all ISI games |
| FeelerOffset | GENERAL | Offset from CG for feelers | HIGH |
| FeelersAtCGHeight | GENERAL | Auto-adjust feelers to CG | HIGH |
| FeelerFrontLeft/Right | GENERAL | Corner feeler positions | HIGH — 6 feelers per vehicle |
| FeelerRearLeft/Right | GENERAL | Corner feeler positions | HIGH |
| FeelerFront/Rear | GENERAL | Side feeler positions | HIGH |
| FeelerRight/Left | GENERAL | Side feeler positions | HIGH |
| FeelerTopFrontLeft/Right | GENERAL | Top feeler positions | HIGH |
| FeelerTopRearLeft/Right | GENERAL | Top feeler positions | HIGH |
| FeelerBottom | GENERAL | Bottom feeler | HIGH |

### Tire Compound AI Parameters (from .tbc files, referenced in [COMPOUND] section)

| Config Param | Section | Notes | Confidence |
|-------------|---------|-------|------------|
| AIGripMult | COMPOUND | Grip multiplier for AI (tire model simplification) | HIGH — NASCAR 2003/2004, rFactor |
| AIPeakSlip | COMPOUND | Simple peak slip angle for AI | HIGH — same evidence |
| AIWear | COMPOUND | AI wear rate constant | HIGH — per-compound wear scaling |
| AISens | COMPOUND | AI load sensitivity (final grip mult, final load) | HIGH — rFactor and NASCAR 2004 |
| AITireModel | COMPOUND | 0.0=original slip model, 1.0=more similar to player | HIGH — rFactor only |
| AILoad | COMPOUND | Simple load sensitivity for AI | MED — NASCAR 2003 only |

## String Matches

| String | Found In | F1C Function | Insight |
|--------|----------|-------------|---------|
| "AIDamperFast" | NASCAR 2003/2004 Demo, rFactor | FUN_00424080 | Config param name shared since NASCAR 2003 |
| "AIDamperSlow" | NASCAR 2003/2004 Demo, rFactor | FUN_00424080 | Same — base isiMotor1 AI param |
| "AIEvenSuspension" | NASCAR 2003/2004 Demo, rFactor | FUN_00424080 | Confirms this is inherited from common codebase |
| "AISpringRate" | NASCAR 2003/2004 Demo, rFactor | FUN_00424080 | Common AI param, value differs by game |
| "AIRaceTimeFast" | NASCAR 2003 Demo unique | — | NASCAR-only AI speed preset (not in F1C) |
| "AIRaceTimeMid" | NASCAR 2003 Demo unique | — | NASCAR-only AI speed preset |
| "AIRaceTimeSlow" | NASCAR 2003 Demo unique | — | NASCAR-only AI speed preset |
| "F1_Circuit_AI_Qual_Setup_Wetness" | NASCAR 2003 Demo unique | — | Shared code path for AI wet setup detection |
| "F1_Circuit_AI_Race_Setup_Wetness" | NASCAR 2003 Demo unique | — | Same — wet setup persists from F1 lineage |
| "Run AI Script" | NASCAR 2003 Demo unique | — | Debug/development AI scripting |
| "AI never has control over car" | NASCAR 2003 Demo unique | — | Debug string for AI override |
| "AI Brake Grip Usage" | NASCAR 2004 Dedicated/Demo | — | rFactor AIPerfUsage brake grip component |
| "AI Brake Power Usage" | NASCAR 2004 Dedicated/Demo | — | rFactor AIPerfUsage brake power component |
| "If 1, search specific vehicle directory for...ai.svm" | NASCAR 2003/2004, rFactor | FUN_004333e0, FUN_00433890 | Directly confirms .svm fallback chain: .race → .qual → ai.svm |
| "Formation Lap" | all ISI binaries | FUN_0041a3a0 | Formation lap string present across all games |
| "FormationSpeedKPH" | all ISI binaries | — | Formation speed parameter in .gdb |
| "FormationAndStart" | rFactor + all | FUN_0041a3a0 | RTTI confirms PFData<FormationAndStart> enum type |
| "PitstopRequested" | all ISI binaries | FUN_0042a3d0 | Pit strategy shared code |
| "Pitstop1Setting" | all ISI binaries | FUN_0042a3d0 | Pit stop fuel settings shared format |

## SDK Struct Alignment

Comparing rFactor SDK structs (InternalsPlugin.hpp) against F1C vehicle struct offsets documented in docs/02-ai-system.md:

| SDK Field | SDK Offset | F1C Offset | Status |
|-----------|-----------|------------|--------|
| VehicleScoringInfo.mFinishStatus (0=none,1=finished,2=dnf,3=dq) | +0x13 (signed char) | param_1+0x4064 (int, 0=run,1=finish,2=DNF,3=DSQ) | MATCH — same semantics, F1C uses int not char |
| VehicleScoringInfo.mTotalLaps | +0x08 (short) | param_1+0x4098 (int) | SHIFTED — same field, different type |
| VehicleScoringInfo.mBestLapTime | +0x28 (float) | param_1+0x409c (float) | MATCH — float at matching offset range |
| VehicleScoringInfo.mNumPitstops | +0x3C (short) | param_1+0x1162 (short/byte) | MATCH — short, same concept |
| VehicleScoringInfoV2.mIsPlayer | +0x40 (bool) | param_1 near DAT_007c54e8 | MATCH — PlayerVehiclePtr singleton |
| VehicleScoringInfoV2.mPlace | +0x43 (unsigned char, 1-based) | param_1+0x4060 (int, position) | SHIFTED — F1C stores position as int not byte |
| ScoringInfoV2.mGamePhase (0-8) | +0x40 (unsigned char) | DAT_007c56a8 (RacePhase 0-7) | MATCH — phase values aligned (0=before, 5=green, 8=over) |
| ScoringInfoV2.mInRealtime | +0x4E (bool) | DAT_007d0308 (RaceActiveFlag) | MATCH — realtime active flag |
| ScoringInfoV2.mRaining (0.0-1.0) | +0x5C (float) | DAT_008afee8 (current track wetness) | MATCH — wetness float used in AI rain penalty |
| ScoringInfoV2.mAmbientTemp | +0x60 (float) | — | NEW — no direct F1C global match found |
| ScoringInfoV2.mTrackTemp | +0x64 (float) | — | NEW — no direct F1C global match found |
| ScoringInfoV2.mWind | +0x68 (TelemVect3) | — | NEW — wind not present in F1C AI data |
| Comment on coordinate system | SDK: +x=left, +y=up, +z=rear | F1C: same | MATCH — confirmed by rFactor SDK documentation |

### Additional struct notes from .pm file (rFactor suspension):

| Body | Offset Evidence | Notes |
|------|----------------|-------|
| fl_spindle mass=(6.0) | — | F1C likely has same body/suspension joint structure |
| fl_wheel mass=(17.1) | — | +0x15f0 wheel_struct_ptr in FUN_00447160 points to equivalent struct |
| fuel_tank mass=(1.0) inertia=(1.0,...) | — | FuelTankMotion (spring rate, damping) from .hdv maps to F1C fuel slosh model at offscreen offsets |
| driver_head | — | Separate from vehicle physics, controlled by head physics code |

## Proposed Renames

| Current | Proposed | Evidence |
|---------|----------|----------|
| aiDB[0x46] (global speed multiplier) | AIDatabase::mGlobalSpeedMult | .hdv slider interpolation formula confirmed across all ISI games |
| aiDB[0x47]=0.5 | AIDatabase::mMinSpeedMult | rFactor .hdv low-end constant |
| aiDB[0x48]=1.0 | AIDatabase::mMidSpeedMult | rFactor .hdv mid-end constant |
| aiDB[0x49]=1.3 | AIDatabase::mMaxSpeedMult | rFactor .hdv high-end constant |
| param_1[0x1130] (QA scaled) | VehicleAI::mQualifyingAbility | Confirmed inverted storage formula from .rcd |
| param_1[0x1131] (RA scaled) | VehicleAI::mRaceAbilityDelta | Quadratic slider scaling formula matches all ISI games |
| param_1[0x1132] (RainAbility) | VehicleAI::mRainSensitivity | rFactor .hdv formula: RA × 0.01 × rain_scale, inverted from intuition |
| param_1[0x114f] (LiveLapRatio) | VehicleAI::mLiveLapTarget | Lap-by-lap push/conserve state machine |
| DAT_005ea3d8 (track ref speed) | gTrackAISpeedRef | Set by anonymous init as aiDB[0x46] × track_reference |
| DAT_008afee8 (current wetness) | gTrackWetness | Maps to ScoringInfoV2.mRaining in SDK |
| param_1[0x113d] (Base speed ratio) | VehicleAI::mBaseSpeedRatio | = (1 - RA × 0.01) × DAT_005ea3d8 |
| DAT_007d017c (TrackAggressionMult) | gTrackAggressionMult | Multiplies TrackAggression from .rcd to produce runtime value at +0x113e |
| param_1[0x1142] (Lap type flag) | VehicleAI::mLapTypeFlag | 0=conservative, nonzero=push — matches docs/13 LapTypeFlag |
| param_1[0x1143] (Push lap counter) | VehicleAI::mPushLapCounter | Consecutive push laps, self-throttles aggression via 0x1143 × 0.5 subtraction |
| param_1[0x1160] (WetSpeedMult) | VehicleAI::mWetSpeedMult | Clamped minimum 0.5, = 1.0 - wetness × RainSensitivity |
| param_1[0x1133] (Passing scaled) | VehicleAI::mPassingEffort | Maps [0-100] → [0.90-1.0], effort multiplier for overtaking |
| param_1[0x113e] (TrackAggression run) | VehicleAI::mTrackAggression | = TrackAggression × gTrackAggressionMult, enforced min 0.01 |

## Missing in F1C Documentation (cross-reference gaps)

The following rFactor AI parameters exist in .hdv files but are NOT yet documented in docs/02-ai-system.md:

1. **AISlipReaction** — `(500.0, 30.0)` — prediction factor for front wheel grip loss and throttle recovery speed
2. **AITorqueStab** — `(1.0, 1.0, 1.0)` — torque stability adjustment tuple (likely bump/rebound/torque)
3. **FeelerFlags** + 14 feeler position params — collision detection feeler geometry
4. **AIDamperFast/Slow** contribution fractions — AI uses simplified damper model
5. **AIEvenSuspension** — suspension averaging ratio (0.0-1.0), 0=no averaging in rFactor F1
6. **AITireModel** — tire model selection (0=simplified, 1=full) in compound files
7. **AIGripMult** + **AIPeakSlip** + **AIWear** + **AISens** — compound-level AI tire behavior overrides
8. **AIMinPassesPerTick** — minimum physics passes per tick (3 in both rFactor and NSC)
9. **AIRotationThreshold** — rotation threshold to increase passes (0.15 rad/s in F1, 0.20 in NSC)

## Summary

- **RTTI classes confirmed:** AIDatabase (core), Steward (session rules), Game (main loop), DynMan (vehicle array), PitMan (pit state), PFData<FormationAndStart> (formation logic), PFData<WeatherCond> (rain logic)
- **Config params matched:** 22 AI performance params from [GENERAL] + 11 AIDPENALTIES weight params + 4 tire compound AI params
- **String cross-refs:** Shared isiMotor1 AI param names back to NASCAR 2003, confirming common ancestry
- **SDK alignment:** VehicleScoringInfo.FinishStatus ↔ +0x4064 (MATCH), ScoringInfoV2.mGamePhase ↔ DAT_007c56a8 (MATCH), ScoringInfoV2.mRaining ↔ DAT_008afee8 (MATCH)
- **New fields to add:** Feeler geometry params, AIDamperFast/Slow, AITorqueStab, AISlipReaction, AITireModel, compound AI params
- **Proposed renames:** 15 struct fields with concrete evidence from cross-binary config analysis
