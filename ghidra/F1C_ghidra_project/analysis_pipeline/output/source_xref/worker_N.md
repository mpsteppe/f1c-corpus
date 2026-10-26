# Source Cross-Reference: docs/13-struct-offsets.md

## RTTI Class Mappings

| rFactor Class | F1C Function(s) | Confidence | Evidence |
|--------------|-----------------|------------|----------|
| `.?AVDynMan@@` (DynMan) | FUN_004e2130, FUN_004e2070, FUN_004e8010, FUN_004e9100, FUN_004e9300, FUN_004e8b80, FUN_004e87e0, FUN_004e9980, FUN_004e9bd0, FUN_004ed810, FUN_004ed420, FUN_004ef180, FUN_004ef6c0, FUN_004f17d0, FUN_004f1aa0, FUN_004f1ba0 | HIGH | Vehicle physics struct offsets (position, rotation, suspension, wheel forces) match dynman.cpp vehicle dynamics domain. Dev tree confirms `dynman.cpp` shared across all ISI games. |
| `.?AVSteward@@` (Steward) | FUN_004c0cc0, FUN_0049f870, FUN_004c03f0, FUN_004c07f0, FUN_004c0f60, FUN_004c1370, FUN_004c6920, FUN_004c6980, FUN_004c79e0, FUN_004a0ba0 | HIGH | Session/race management — reads FinishState (+0x4064), FinishPosition (+0x4060), QualifyingPosition (+0x4058), SeasonPoints (+0x403c). rFactor RTTI confirms `Steward` class. Dev tree: `steward.cpp`. |
| `.?AVPitMan@@` (PitMan) | FUN_004a5600, FUN_004b6940, FUN_004b5da0, FUN_004a47e0, FUN_004b6130, FUN_004b68c0, FUN_004b6920 | HIGH | Pit stop/crew state struct (+0x184 PitMode, +0x190 RepairDoneFlag, +0x9b0 PitActionBase). rFactor confirms `PitMan` class. Dev tree: `pitcrew.cpp`. |
| `.?AVReplayMan@@` (ReplayMan) | FUN_004b7500, FUN_004ba1f0, FUN_004b81a0, FUN_004b84f0, FUN_004b85d0, FUN_004b8360, FUN_004b7c80, FUN_004b5f60, FUN_004b5a30, FUN_004b86e0 | HIGH | ReplaySaveStruct — linked-list replay data, save/load state (+0x700 SaveState), header data source (+0x6e8). rFactor RTTI confirms `ReplayMan`. Dev tree: `Replay.cpp`. |
| `.?AVGame@@` (Game) | FUN_00404890, FUN_004049d0 (RaceModeBackup), FUN_004216f0 (GameConfig), FUN_0040c9e0, FUN_0040cce0 (CamMan) | MEDIUM | Game state management — backup of SessionType/GameMode in RaceModeBackup struct (+0x50 SavedSessionType, +0x54 SavedRaceMode). rFactor RTTI confirms `Game`. |
| `.?AVWeather@@` (Weather) | FUN_004d0f10 (SessionStruct timers) | LOW | Weather mode (DAT_007cf080) read by session timer logic. rFactor RTTI confirms `Weather`. Dev tree: `weather.cpp` in F1C source. |
| `.?AVHDVehicle@@` (referenced via "HDVehicle" string) | FUN_004e3aa0 (WheelCornerStruct), FUN_00430750 (tire instance data), FUN_004e9300 (tire state flag), FUN_004e5080, FUN_004e513e | HIGH | High-detail vehicle physics — tire model, wheel corners, brake temp, wear. rFactor binary string "HDVehicle" confirmed. Dev tree: `hdvehicle.cpp` shared across all games. |
| `.?AVSoundMan@@` (SoundMan) | FUN_00519720, FUN_0051bd61, FUN_0051bcfc, FUN_00515db8, FUN_00541810 | HIGH | AudioStreamBuffer struct — double-buffered stream, fill state, callback vtables. rFactor RTTI confirms `SoundMan`. Dev tree: `sound.cpp`. |
| `.?AVSpecialFX@@` (SpecialFX) | FUN_00545d00, FUN_005169ac (VibrationEffectController) | HIGH | Vibration/force feedback effect controller — +0x10 activeFlag, +0x14 state, +0x69 intensity. rFactor RTTI confirms `SpecialFX`. |
| `.?AVRender@@` (Render) | FUN_0054a0a0, FUN_0054b770, FUN_00549fb0, FUN_0054d030, FUN_0054d910, FUN_005425a0, FUN_0054c110, FUN_005453a0 | HIGH | SceneNode/DrawableList, Viewport structs — frustum culling, matrix transforms, render targets. rFactor RTTI confirms `Render`. |
| `.?AVAIDatabase@@` (AIDatabase) | FUN_0042a780, FUN_0042ad00, FUN_0042add0, FUN_0042ae00, FUN_0042aca0, FUN_0042ac70, FUN_0042ae90, FUN_0042adb0, FUN_0042af40, FUN_0042ae20 | HIGH | AIStateStruct — +0x4354 AIStateFlags, +0x454c AISpeedDelta, +0x4580 AggressionFactor, +0x4500 PassScoreBiasAdd. rFactor RTTI confirms `AIDatabase`. Dev tree: `ai_db.cpp`. |
| `.?AVController@@` / `.?AVHWInput@@` | FUN_0040be70 (InputDevice), FUN_00455da0 | MEDIUM | Input device binding struct — +0x13E8 BindingValueA, +0x13EC InputDeviceHandle, +0x1f98 ControllerArray. rFactor RTTI confirms `Controller`, `HWInput`. |
| `.?AVNetComm@@` (NetComm) | FUN_004a3ef0 (NetworkMessage), FUN_00591583 | MEDIUM | Network packet struct — +0x5C4 EventCode, +0x5C8 StringBuffer, +0x618 BufferMutex. rFactor confirms `NetComm`. |
| `.?AVOnScreen@@` / `.?AVOptions@@` (Options UI) | FUN_0047e960 (UIObjectList), FUN_0051a4f2, FUN_0051bc88 (UIListComboBox), FUN_004541d0 (PauseStringTable) | MEDIUM | UI control structs — lists, combo boxes, string tables. rFactor RTTI confirms `OnScreen`, `Options`, and full UI class hierarchy. |
| `.?AVWeather@@` (Weather system) | FUN_004d0f10 | LOW | Session timers with weather-dependent max time. rFactor confirms `Weather`. F1C dev tree: `weather.cpp`. |
| `.?AVPluginManager@@` / `.?AVRFPluginManager@@` | Multiple functions near telemetry | LOW | VehicleTelemetryBroadcast struct — telemetry broadcast mode (+0xcaf). PluginManager manages internals plugins. |

## Parameter-to-Offset Mappings

| Config Param | Section | F1C Struct Offset | Current Name | Proposed Name | Confidence |
|-------------|---------|-------------------|--------------|---------------|------------|
| `CGHeight` | GENERAL | +0x889 config param (documented as .hdv field) | — | Vehicle CG height above ref plane | HIGH |
| `CGRearRange` / `CGRearSetting` | GENERAL | VehicleStruct | — | Rear weight bias range/setting | HIGH |
| `CGRightRange` / `CGRightSetting` | GENERAL | VehicleStruct | — | Left weight bias range/setting | HIGH |
| `Mass` | GENERAL | VehicleStruct | — | Body mass (excluding fuel) | HIGH |
| `Inertia` | GENERAL | VehicleStruct | — | Body inertia (x, y, z) | HIGH |
| `BrakeOptimumTemp` | FRONTLEFT etc | +0xb8 | BrakeOptimumTemp | BrakeOptimumTemp | HIGH (confirmed match) |
| `BrakeWearRate` | FRONTLEFT etc | +0xf0 | BrakeWearRate | BrakeWearRate | HIGH (confirmed match) |
| `BrakeFailure` | FRONTLEFT etc | +0xf8/+0x100 | BrakeFailure min/max | BrakeFailureAvg/BrakeFailureVar | HIGH |
| `BrakeTorque` | FRONTLEFT etc | Not in doc | — | Max brake torque at zero wear | MEDIUM |
| `BrakeCooling` | FRONTLEFT etc | +0x34b8 | CoolingCoeff1 | BrakeCoolingBase | MEDIUM |
| `BrakeHeating` | FRONTLEFT etc | WheelCorner | — | BrakeHeatingRate | MEDIUM |
| `BumpTravel` | FRONTLEFT etc | +0x4c | RestHeight | SuspBumpTravel | MEDIUM |
| `SpringRange` / `SpringSetting` | FRONTLEFT etc | +0x1cc | SpringBias | SpringRangeBase | MEDIUM |
| `FastBumpRange` / `FastBumpSetting` | FRONTLEFT etc | Not in doc | — | Fast bump damper range/setting | MEDIUM |
| `SlowBumpRange` / `SlowBumpSetting` | FRONTLEFT etc | Not in doc | — | Slow bump damper range/setting | MEDIUM |
| `FastReboundRange` / `FastReboundSetting` | FRONTLEFT etc | Not in doc | — | Fast rebound damper range/setting | MEDIUM |
| `CamberRange` / `CamberSetting` | FRONTLEFT etc | +0x2e8 | CamberAngle | CamberSetting | MEDIUM |
| `BumpStopSpring` | FRONTLEFT etc | Not in doc | — | BumpStopSpring | MEDIUM |
| `BumpStopDamper` | FRONTLEFT etc | Not in doc | — | BumpStopDamper | MEDIUM |
| `DiffLockRange` / `DiffLockSetting` | DRIVELINE | Not in doc | — | Differential lock range/setting | MEDIUM |
| `DiffPowerRange` / `DiffPowerSetting` | DRIVELINE | Not in doc | — | Differential power-side range/setting | MEDIUM |
| `DiffCoastRange` / `DiffCoastSetting` | DRIVELINE | Not in doc | — | Differential coast-side range/setting | MEDIUM |
| `DiffPreloadRange` / `DiffPreloadSetting` | DRIVELINE | Not in doc | — | Differential preload range/setting | MEDIUM |
| `FWRange` / `FWSetting` | FRONTWING | +0x4024 | DownforceMultiplier | FrontWingSetting/LiftCoeff | MEDIUM |
| `FuelRange` / `FuelSetting` | GENERAL | Not in doc | — | Fuel load range/setting | MEDIUM |
| `TireBrand` | GENERAL | Not in doc | — | Tire brand reference (.tbc) | MEDIUM |
| `FrontTireCompoundSetting` | GENERAL | +0x1170 | Current front compound index | FrontTireCompoundSetting | HIGH |
| `RearTireCompoundSetting` | GENERAL | +0x1170+0x3c | — | RearTireCompoundSetting | HIGH |
| `FuelTankMotion` | GENERAL | Not in doc | — | Fuel slosh model params | MEDIUM |
| `AIAimSpeedsPerWP` | GENERAL | Not in doc | — | AI lookahead speeds | MEDIUM |
| `AISlipReaction` | GENERAL | Not in doc | — | AI grip loss prediction | MEDIUM |
| `FeelerFront` / `FeelerRear` etc | GENERAL | Not in doc | — | Collision feeler positions | MEDIUM |
| `BumpStopRisingSpring` | FRONTLEFT etc | Not in doc | — | Rising spring rate of bumpstop | MEDIUM |
| `BumpStopRisingDamper` | FRONTLEFT etc | Not in doc | — | Rising damper rate of bumpstop | MEDIUM |
| `BrakeFadeRange` | FRONTLEFT etc | Not in doc | — | Brake fade temperature range | MEDIUM |
| `BrakeGlow` | FRONTLEFT | Not in doc | — | Brake glow temp range | MEDIUM |
| `BrakeResponseCurve` | FRONTLEFT | Not in doc | — | Brake torque vs temp curve | MEDIUM |
| `FrictionTorque` | FRONTLEFT etc | Not in doc | — | Spindle/wheel friction | MEDIUM |
| `EngineInertia` | ENGINE | Not in doc | — | Engine rotational inertia | MEDIUM |

## String Matches

| String | Found In | F1C Function | Insight |
|--------|----------|-------------|---------|
| `..\Source\hdvehicle.cpp` | rFactor, NASCAR, F1C | All vehicle physics functions | Confirms source file for VehicleStruct, WheelCornerStruct physics |
| `..\Source\steward.cpp` | rFactor, NASCAR, F1C | FUN_004c0cc0, FUN_004c03f0 etc | Confirms steward as session/scoring manager |
| `..\Source\pitcrew.cpp` | rFactor, NASCAR, F1C | PitStop/PitCrewStruct functions | Confirms pit crew implementation |
| `..\Source\ai_db.cpp` | rFactor, NASCAR, F1C | AIStateStruct functions | Confirms AI database module |
| `..\Source\weather.cpp` | rFactor, NASCAR, F1C | Weather-dependent session logic | Confirms weather module |
| `..\Source\sound.cpp` | rFactor, NASCAR, F1C | AudioStreamBuffer functions | Confirms sound module |
| `..\Source\options.cpp` | rFactor, NASCAR, F1C | UIListComboBox, UIObjectList functions | Confirms options module |
| `..\Source\onscreen.cpp` | rFactor, NASCAR, F1C | SpriteOverlayList functions | Confirms on-screen display module |
| `..\Source\render.cpp` | rFactor, NASCAR, F1C | SceneNode/DrawableList functions | Confirms renderer module |
| `..\Source\specialfx.cpp` | rFactor, NASCAR, F1C | VibrationEffectController functions | Confirms special effects module |
| `..\Source\setup.cpp` | rFactor, NASCAR, F1C | Setup/garage functions | Confirms setup module |
| `..\Source\game.cpp` | rFactor, NASCAR, F1C | GameConfig, RaceModeBackup | Confirms game state module |
| `..\Source\Replay.cpp` | rFactor, NASCAR, F1C | ReplaySaveStruct functions | Confirms replay module |
| `..\Source\plrfile.cpp` | rFactor, NASCAR, F1C | Player-related options | Confirms player file module |
| `..\Source\dynman.cpp` | rFactor, NASCAR, F1C | Vehicle physics functions | Confirms dynamics manager module |
| `..\Source\NetComm.cpp` | rFactor, NASCAR, F1C | NetworkMessage struct | Confirms network module |
| `..\Source\hwinput.cpp` | rFactor, NASCAR, F1C | InputDevice struct | Confirms hardware input module |
| `..\Source\config.cpp` | rFactor, NASCAR, F1C | Config-related functions | Confirms config module |
| `Vehicle Collision` | rFactor, NASCAR | CollisionContactState | Confirms collision detection context |
| `Pitstop Requested` | rFactor, NASCAR | PitStop struct functions | Confirms pit stop state machine |
| `Vehicle Status N/A` | rFactor, NASCAR | Scoring/standings functions | Confirms vehicle status reporting |
| `FreeVehicle=%d` | rFactor | Vehicle lifecycle functions | Confirms vehicle free/release path |
| `?Vehicle has zero or negative inertia` | rFactor | Rotational inertia struct fields | Confirms inertia tensor validation |
| `?Launch control is not available` | rFactor | Vehicle control functions | Confirms launch control feature |
| `Formation Lap:` | rFactor | SessionStruct timers | Confirms formation lap mode |
| `Scoring?` | rFactor | ScoringDB functions | Confirms scoring database |
| `VehicleSound=%s` | rFactor | Audio struct functions | Confirms vehicle sound path config |
| `Play Movies` | NASCAR shared with F1C | Bink/animation functions | Confirms movie playback feature |
| `Entered Sound::Init()` | NASCAR shared | AudioStreamBuffer | Confirms sound module lifecycle |
| `Vehicle Width` | NASCAR shared | Collision/hull functions | Vehicle width collision parameter |

## SDK Struct Alignment

### TelemWheel (rFactor SDK) vs F1C WheelCornerStruct / VehicleStruct

| SDK Field | SDK Offset | F1C Offset | Status |
|-----------|-----------|------------|--------|
| `mRotation` (float, rad/s) | +0x00 | ~+0x3500+ (WheelSpeed) | MATCH — multiple wheel velocity fields at +0x3500, +0x3570 |
| `mSuspensionDeflection` (float, m) | +0x04 | +0x358c/+0x3594 | MATCH — SuspensionDeflection_L/R in VehicleStruct |
| `mRideHeight` (float, m) | +0x08 | +0x4c (RestHeight) | MATCH — suspension rest position |
| `mTireLoad` (float, N) | +0x0c | +0xcb0/cb8/cc4 (Load triple) | MATCH — tire load bias/scale/factor in VehiclePhysicsState |
| `mLateralForce` (float, N) | +0x10 | +0x35b0, +0x36a8, +0x37a0, +0x3898 | MATCH — LateralForce1-4 per wheel |
| `mGripFract` (float) | +0x14 | ~+0x3a30/+0x3a44 TireRoadFrictionMu | PARTIAL — grip fraction approximation |
| `mBrakeTemp` (float, °C) | +0x18 | +0x39c8 BrakeTemp | MATCH — brake rotor temperature |
| `mPressure` (float, kPa) | +0x1c | Not in doc | MISSING — tire pressure field not documented in struct offsets |
| `mTemperature[3]` (float[3], °C) | +0x20 | +0x48b8 TireTemp | PARTIAL — single TireTemp field, SDK has 3 temps (inside/center/outside) |
| `mWear` (V2, float 0.0-1.0) | +0x2c | Not in doc | MISSING — tire wear fraction not documented |
| `mTerrainName[16]` (V2, char) | +0x30 | Not in doc | MISSING — terrain surface type name |
| `mSurfaceType` (V2, uchar) | +0x40 | Not in doc | MISSING — surface type (0=dry, 1=wet, etc) |
| `mFlat` (V2, bool) | +0x41 | Not in doc | MISSING — flat tire flag |
| `mDetached` (V2, bool) | +0x42 | Not in doc | MISSING — detached wheel flag |

### TelemInfoBase (rFactor SDK) vs F1C VehicleStruct

| SDK Field | SDK Offset | F1C Offset | Status |
|-----------|-----------|------------|--------|
| `mDeltaTime` (float) | +0x00 | Not mapped | MISSING — no frame delta struct field |
| `mLapNumber` (long) | +0x04 | Not mapped | MISSING — tracked via global DAT not struct |
| `mLapStartET` (float) | +0x08 | Not mapped | MISSING |
| `mVehicleName[64]` (char) | +0x0c | +0x4678 VehicleDescription | MATCH (format may differ) |
| `mTrackName[64]` (char) | +0x4c | Not mapped | Track name stored elsewhere |
| `mPos` (TelemVect3 x,y,z) | +0x8c | +0x08 PositionX/Y/Z, +0x34d4-+0x34dc PosX/PosY/PosZ | MATCH — world position in two struct regions |
| `mLocalVel` (TelemVect3) | +0x98 | +0x34ec-+0x34f4 InputVector/Velocity | MATCH — velocity/force input |
| `mLocalAccel` (TelemVect3) | +0xa4 | +0x3504-+0x350c VarA/VarB/VarC | PARTIAL — physics integration state |
| `mOriX/Y/Z` (TelemVect3[3]) | +0xb0 | +0x20-+0x40 RotationMatrix (9 floats) | MATCH — 3×3 orientation matrix |
| `mLocalRot` (TelemVect3) | +0xd4 | Not mapped | MISSING |
| `mLocalRotAccel` (TelemVect3) | +0xe0 | Not mapped | MISSING |
| `mGear` (long) | +0xec | Not mapped | MISSING |
| `mEngineRPM` (float) | +0xf0 | +0x3994 TargetSpeed/CurrentValue | PARTIAL — RPM/load field |
| `mEngineWaterTemp` (float) | +0xf4 | Not mapped | MISSING |
| `mEngineOilTemp` (float) | +0xf8 | +0x1320/+0x1328 LifetimeOilTemp_min/max | PARTIAL — lifetime range, not current temp |
| `mClutchRPM` (float) | +0xfc | Not mapped | MISSING |
| `mUnfilteredThrottle` (float) | +0x100 | Not mapped | Game input, not vehicle struct |
| `mUnfilteredBrake` (float) | +0x104 | Not mapped | Game input |
| `mUnfilteredSteering` (float) | +0x108 | Not mapped | Game input |
| `mUnfilteredClutch` (float) | +0x10c | Not mapped | Game input |
| `mSteeringArmForce` (float) | +0x110 | Not mapped | Force feedback |

### TelemInfoV2 (rFactor SDK) — additional fields vs F1C

| SDK Field | SDK Offset | F1C Offset | Status |
|-----------|-----------|------------|--------|
| `mFuel` (float, L) | +0x114 | Not mapped | MISSING |
| `mEngineMaxRPM` (float) | +0x118 | +0x1318 LifetimeEngineRPM_max | PARTIAL — lifetime limit, not current max |
| `mScheduledStops` (uchar) | +0x11c | +0x1162 PitStopCount | MATCH |
| `mOverheating` (bool) | +0x11d | Not mapped | MISSING |
| `mDetached` (bool) | +0x11e | Not mapped | MISSING |
| `mDentSeverity[8]` (uchar) | +0x11f | +0x26f0-0x2834 BodyParts[7] | PARTIAL — dent/body part damage flags |
| `mLastImpactET` (float) | +0x127 | Not mapped | MISSING |
| `mLastImpactMagnitude` (float) | +0x12b | Not mapped | MISSING |
| `mLastImpactPos` (TelemVect3) | +0x12f | +0x3b88-+0x3b90 ContactPosX/Y/Z | PARTIAL — contact position exists in struct |
| `mWheel[4]` (TelemWheelV2) | +0x174 | See TelemWheel mapping above | PARTIAL — wheel data spread across struct |

### VehicleScoringInfo (rFactor SDK) vs F1C VehicleStruct scoring fields

| SDK Field | SDK Offset | F1C Offset | Status |
|-----------|-----------|------------|--------|
| `mDriverName[32]` (char) | +0x00 | +0x4620 DriverName[64] | MATCH — F1C has double space (64 vs 32) |
| `mVehicleName[64]` (char) | +0x20 | +0x4678 VehicleDescription | MATCH |
| `mTotalLaps` (short) | +0x60 | Not in doc (likely global) | MISSING |
| `mSector` (signed char) | +0x62 | +0x192 CurrentSector | MATCH |
| `mFinishStatus` (signed char) | +0x63 | +0x4064 FinishState (int, 0=running, 1=finished, 2=DNF, 3=DSQ) | MATCH — values identical, F1C uses int vs signed char |
| `mLapDist` (float) | +0x64 | Not mapped | MISSING |
| `mBestSector1` (float) | +0x68 | Not mapped | MISSING |
| `mBestSector2` (float) | +0x6c | Not mapped | MISSING |
| `mBestLapTime` (float) | +0x70 | +0x409c BestLapTime | MATCH |
| `mLastSector1` (float) | +0x74 | Not mapped | MISSING |
| `mLastLapTime` (float) | +0x7c | Not mapped | MISSING |
| `mNumPitstops` (short) | +0x90 | +0x1162 PitStopCount | MATCH |
| `mNumPenalties` (short) | +0x92 | Not in doc | MISSING |

### VehicleScoringInfoV2 — additional fields

| SDK Field | SDK Offset | F1C Offset | Status |
|-----------|-----------|------------|--------|
| `mIsPlayer` (bool) | +0x94 | Not mapped | MISSING |
| `mControl` (signed char) | +0x95 | +0x48bc AIControlFlags/FinishState (bit 0=AI) | PARTIAL — AI control flag |
| `mInPits` (bool) | +0x96 | Not mapped | MISSING |
| `mPlace` (unsigned char) | +0x97 | +0x4060 FinishPosition | MATCH — 1-based placement |
| `mVehicleClass[32]` (char) | +0x98 | Not mapped | MISSING |
| `mTimeBehindNext` (float) | +0xb8 | +0x69c OvertakeGap | PARTIAL |
| `mLapsBehindNext` (long) | +0xbc | Not mapped | MISSING |
| `mTimeBehindLeader` (float) | +0xc0 | Not mapped | MISSING |
| `mLapsBehindLeader` (long) | +0xc4 | Not mapped | MISSING |
| `mLapStartET` (float) | +0xc8 | Not mapped | MISSING |
| `mPos` (TelemVect3) | +0xcc | +0x34d4-+0x34dc PosX/Y/Z | MATCH |
| `mLocalVel` (TelemVect3) | +0xd8 | +0x34ec-+0x34f4 Velocity | MATCH |
| `mOriX/Y/Z` (TelemVect3[3]) | +0xf0 | +0x34b0-+0x34d0 RotMatrix rows | MATCH — orientation matrix rows |

### ScoringInfoBase / ScoringInfoV2 (rFactor SDK) vs F1C SessionStruct

| SDK Field | SDK Offset | F1C Offset | Status |
|-----------|-----------|------------|--------|
| `mTrackName[64]` (char) | +0x00 | Not in SessionStruct | Track stored elsewhere |
| `mSession` (long) | +0x40 | +0xb14c RaceSession/SessionType | MATCH — maps to DAT_007c56a4 |
| `mCurrentET` (float) | +0x44 | Not in struct (global timer) | MISSING |
| `mEndET` (float) | +0x48 | +0xb8 MaxSessionTime | MATCH — session time limit |
| `mMaxLaps` (long) | +0x4c | +0x190 LapCount (short) | PARTIAL — total laps |
| `mLapDist` (float) | +0x50 | Not mapped | MISSING |
| `mResultsStream` (char*) | +0x54 | Not mapped | MISSING |
| `mNumVehicles` (long) | +0x58 | Multiple — VehicleCount DAT_005c329c | MATCH — global rather than struct field |
| `mGamePhase` (uchar) | +0x5c (V2) | +0x184 SessionState (0=idle, 1=active, 4=finished) | MATCH — game phase state machine |
| `mYellowFlagState` (signed char) | +0x5d (V2) | Not mapped | MISSING |
| `mSectorFlag[3]` (signed char) | +0x5e (V2) | +0x128 SectorFlags[26] | PARTIAL — 26 sector flags vs 3 |
| `mDarkCloud` (float) | +0x64 (V2) | Not mapped | Weather global |
| `mRaining` (float) | +0x68 (V2) | Not mapped | Weather global |
| `mAmbientTemp` (float) | +0x6c (V2) | Not mapped | Weather global |
| `mTrackTemp` (float) | +0x70 (V2) | Not mapped | Weather global |
| `mWind` (TelemVect3) | +0x74 (V2) | Not mapped | Weather global |
| `mOnPathWetness` (float) | +0x80 (V2) | Not mapped | Track condition |
| `mOffPathWetness` (float) | +0x84 (V2) | Not mapped | Track condition |
| `mVehicle` (VehicleScoringInfoV2*) | +0x184 (V2) | +0x4c EntryRosterPtr (ScoringGate) | PARTIAL — roster pointer |

## Proposed Renames

| Current | Proposed | Evidence |
|---------|----------|----------|
| VehicleStruct → `TelemInfoV2`-like / `DynMan::VehicleState` | VehicleDynamicsState | Matches dynman.cpp domain, contains physics state, orientation, velocity, wheel data |
| ScoringDB / StandingsEntry → `VehicleScoringInfoV2` | VehicleSeasonScoring | Matches SDK VehicleScoringInfo fields (+0x4064 FinishState, +0x4060 FinishPosition) |
| SessionStruct / SessionTimers → `ScoringInfoV2`-like | SessionState | Matches SDK ScoringInfoV2 game phase, lap count, session type |
| ReplaySaveStruct → `ReplayMan::SessionReplayData` | ReplaySessionData | Matches ReplayMan RTTI class, contains save/load state, linked-list entries |
| AudioStreamBuffer → `SoundMan::StreamBuffer` | AudioStreamBuffer | Matches SoundMan RTTI class, double-buffered streaming |
| TireForceQuadraticModel → `TireForceModel` | TireForceModel | Config params include tire quadratic force coefficients (AIPeakSlip, DryLatLong etc) |
| WheelCornerStruct → `WheelHub` | WheelCorner | Matches SDK TelemWheel fields. Offset +0xcb0 labeled "WheelHubPtr" suggests internal name "WheelHub" |
| CameraStruct → `CameraManager::CameraState` | CameraProjection | Matches CameraManager/BaseCameraManager RTTI |
| CollisionContactState → `CollisionContact` | CollisionContactState | OK as-is, matches collision pipeline |
| AnimationNode / BoneGroup → `AnimationNodeGroup` | AnimationNodeGroup | Matches animation system, contains bone group arrays |
| VibrationEffectController → `SpecialFX::VibrationEffect` | ForceFeedbackEffect | Matches SpecialFX RTTI, contains intensity, state, mode fields |
| SceneNode / DrawableList → `Render::SceneNode` | SceneGraphNode | Matches Render RTTI, 4×4 matrix transforms |
| BitStreamWriter → `NetComm::BitStream` | BitStreamEncoder | NetComm uses bit streams for network messages |
| PenaltySlipAngleStruct → `Steward::PenaltySlipAngle` | PenaltySlipAngleCheck | Matches Steward RTTI, penalty system |
| VehicleTelemetryBroadcast → `PluginManager::TelemetryBroadcast` | TelemetryBroadcastState | Telemetry shared via plugin system to internals plugins |
| UIListComboBox → `Options::ComboBoxControl` | UIComboBox | Matches Options UI class hierarchy (Options_DropDown etc) |
| SpriteOverlayList → `OnScreen::SpriteOverlay` | SpriteOverlay | Matches OnScreen RTTI, HUD overlay system |
| GeometryProximityTest → `Collision::WheelProximity` | WheelProximityTest | Collision detection per-wheel, stride 0x128 |
| GridCellIterate → `Render::GridCellCounter` | GridCellCounter | Render-side cell counting for spatial partitioning |
| PlayerOptionsFailureRates → `Options::FailureRateSlots` | MechFailureRateSlots | Config confirms "MechFailureRate" enum type in rFactor RTTI |
| InputDevice → `Controller::InputBinding` | InputBinding | Matches Controller/HWInput RTTI |
| NetworkMessage → `NetComm::NetPacket` | NetworkPacket | Matches NetComm RTTI, has mutex + event code + buffer |
| FreeableMultiPtr → Generic resource container | FreeableResourceSet | Multiple freeable pointer pattern common in renderer |
| MutexGuard (multiple variants) → `tMotor::Mutex` | tMotorMutex | rFactor RTTI confirms `.?AVMutex@tMotor@@` and `.?AVSync@tMotor@@` |
| HighResTimer / Timer → `tMotor::Sync/Timer` | PerformanceTimer | rFactor RTTI confirms `.?AVSync@tMotor@@` for synchronization/timing |
| DynamicBuffer → `DynamicArray` | DynamicArray | Standard growing array container — common utility pattern |
| BoolFloatToggle → `AnimationToggle` | AnimationToggle | Specific animation/state toggle pattern (byte + float pair) |
