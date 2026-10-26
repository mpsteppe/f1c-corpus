# Source Cross-Reference: docs/12-globals-reference.md

## RTTI Class Mappings

F1C Module names (from the "Module" column in docs/12) mapped to corresponding rFactor RTTI classes. The F1C executable has no RTTI itself (compiled `/GR-`), so these mappings are inferred from rFactor's RTTI + shared source paths.

| rFactor Class | F1C Module | Confidence | Evidence |
|---------------|-----------|------------|----------|
| `Steward` | steward | **HIGH** | rFactor Dedicated.exe RTTI includes `.?AVSteward@@`; shared source path `steward.cpp`; globals `SessionType`, `PenaltiesEnabled`, `MultiplayerFlags` all steward-domain |
| `AIDatabase` | ai_db | **HIGH** | rFactor RTTI includes `.?AVAIDatabase@@`; rFactor source `ai_db.cpp` matches F1C assert path; globals `AIDifficultySlider`, `DriverDataTable`, `RingBufferCounter` all AI-domain |
| `Game` | game | **HIGH** | rFactor RTTI includes `.?AVGame@@`; shared source path `game.cpp`; globals `GameState`, `RaceMode`, `SeasonPath` all game-domain |
| `DynMan` | physics/dynamics | **HIGH** | rFactor RTTI includes `.?AVDynMan@@`; rFactor source `dynman.cpp`; vehicle physics globals (`AntiRollMixingFactor`, `BumpDampingConstant`, `SuspensionForceLimit`) map to dynamics manager |
| `Weather` | weather | **HIGH** | rFactor RTTI includes `.?AVWeather@@`; shared source `weather.cpp`; globals `WeatherMode`, `WeatherDir`, `TrackConditionState` all weather-domain |
| `HDVehicle` | hdvehicle | **HIGH** | rFactor RTTI no dedicated class but source `hdvehicle.cpp` confirmed across NASCAR/rFactor binaries; globals `EngineWearMode`, `TireModelMode`, `TireWearMultiplier` all hdvehicle-domain |
| `Render` | renderer | **HIGH** | rFactor RTTI includes `.?AVRender@@`; shared source `render.cpp`; globals `AlphaScaleFactor`, `RGBChannelMultiplier`, `VertexScaleFactor` all renderer-domain |
| `VidMan` | renderer/scene | **HIGH** | rFactor RTTI includes `.?AVVidMan@@`; shared source `vidman.cpp`; globals `VisibilityHorizonConstant`, `D3DDeviceWrapperPtr` |
| `SoundMan` | audio | **HIGH** | rFactor RTTI includes `.?AVSoundMan@@`; shared source `sound.cpp`; globals `SoundVolumeLowThreshold`, `AudioRaceModeFlag`, `AudioOutputHandle` |
| `SpecialFX` | renderer/particles | **HIGH** | rFactor RTTI includes `.?AVSpecialFX@@`; shared source `specialfx.cpp`; globals `ParticleArrayCurrentIndex`, `ParticleIndexCounter` |
| `NetComm` | network | **HIGH** | rFactor RTTI includes `.?AVNetComm@@`; shared source `NetComm.cpp`; globals `NetTimeoutInterval`, `NetBufferData`, `DriverTeamIndexTable` |
| `PlayerFile` | plrfile | **HIGH** | rFactor RTTI includes `.?AVPlayerFile@@`; shared source `plrfile.cpp`; globals `PlayerDataPath` |
| `Setup` (GenericManager) | setup | **MEDIUM** | rFactor has `GenericManager` base class; shared source `setup.cpp`; globals `VehicleFileCount`, `VehicleArray`, `SceneArray`, `TrackDir` |
| `OSMan` | game/ai | **MEDIUM** | rFactor RTTI includes `.?AVOSMan@@`; shared source `osman.cpp`; globals `TimeScalingConstant` likely used in OS timing |
| `PitMan` | pit | **MEDIUM** | rFactor RTTI includes `.?AVPitMan@@`; shared source `pitcrew.cpp`; no direct pit globals in docs/12 but pit-system globals exist in docs/07 |
| `HWInput` | input | **MEDIUM** | rFactor RTTI includes `.?AVHWInput@@`; shared source `hwinput.cpp`; globals `InputDeviceListHead` |
| `OnScreen` | UI | **MEDIUM** | rFactor RTTI includes `.?AVOnScreen@@`; shared source `onscreen.cpp`; UI string globals (`FilterPropertiesString`, `AbbreviationFormat`) |
| `Options` | UI/options | **MEDIUM** | rFactor RTTI includes `.?AVOptions@@`; shared source `options.cpp`; UI display/settings globals |
| `Garage` (not RTTI) | setup/vehicle | **MEDIUM** | Shared source `garage.cpp` in NASCAR binaries; vehicle setup globals (CamberRange, RideHeight, SpringRange string constants) |
| `tire_manager` | tire/physics | **MEDIUM** | NASCAR source includes `tire_manager.cpp` in binary paths; globals `TireModelConstants`, `TireWearArray`, `TireTractionConstant` |
| `Collision` (not RTTI) | collision | **MEDIUM** | No direct RTTI class but `CollObjects.cpp` in rFactor source; rFactor has `LooseObject`, `LooseWheel`, `LoosePart` classes; globals `CollisionGridSize`, `CollisionCellCount`, `CollisionMaxSearchDist` |

## Parameter-to-Offset Mappings

Config parameters from config_params.txt that match string constants in docs/12. These string constants are used for INI/.hdv/.svm file parsing — they map field names in config files to struct offsets in vehicle physics.

| Config Param | Section | F1C String Global | Current Name | Proposed Rename | Confidence |
|-------------|---------|-------------------|--------------|-----------------|------------|
| BrakeDuctSetting | BODYAERO | DAT_005d61f0 | BrakeDuctSettingField | BrakeDuctSettingStr | **HIGH** — exact match to rFactor HDV parameter |
| BrakeDuctDrag | BODYAERO | DAT_005d6214 | BrakeductdragString | BrakeDuctDragStr | **HIGH** — exact match |
| BrakeDuctLift | BODYAERO | DAT_005d6204 | BrakeDuctLiftString | BrakeDuctLiftStr | **HIGH** — exact match |
| BrakeDuctRange | BODYAERO | DAT_005d61e0 | BrakeDuctRange | BrakeDuctRangeStr | **HIGH** — exact match |
| BrakeCooling | FRONTLEFT | DAT_005d51e0 | BrakeCooling | BrakeCoolingStr | **HIGH** — exact match, same param in rFactor HDV |
| BrakeDuctCooling | FRONTLEFT | DAT_005d51cc | BrakeDuctCoolingString | BrakeDuctCoolingStr | **HIGH** — exact match |
| BrakePressureSetting | CONTROLS | DAT_005d5a38 | BrakePressureSettingString | BrakePressureSettingStr | **HIGH** — exact match |
| BrakePressureRear | CONTROLS | DAT_005d5a24 | StringBrakePressureR | BrakePressureRearStr | **HIGH** — config_params has "BrakePressures" in NASCAR / rFactor |
| Damper | FRONTLEFT | DAT_005d4810 | aDamper | DamperStr | **HIGH** — matches "Damper" INI key |
| Damper | COMPOUND | DAT_005d38b8 | DamperString | DamperHdvStr | **HIGH** — second "Damper" string constant for tire compound section |
| DamperMult | FRONTLEFT | DAT_005d5a38 | (not in docs/12 as string) | — | **MEDIUM** — "DamperMult" appears in FRONTLEFT section of HDV |
| CamberRange | FRONTLEFT | DAT_005d517c | aCamberRange | CamberRangeStr | **HIGH** — exact HDV section match |
| CamberSetting | FRONTLEFT | DAT_005c3954 | CamberSettingString | CamberSettingStr | **HIGH** — exact match to HDV INI key |
| CamberSetting | FRONTLEFT | DAT_005d5188 | String_CamberSetting | CamberSettingStr2 | **MEDIUM** — second instance |
| CamberLatLong | COMPOUND | DAT_005d47e0 | CamberLatLongString | CamberLatLongStr | **HIGH** — exact match to TBC parameter |
| RideHeightRange | FRONTLEFT | DAT_005c3900 | RideHeightSetString | RideHeightSettingStr | **HIGH** — parameter is "RideHeight" + "Range" in HDV |
| RideHeightSetting | FRONTLEFT | DAT_005d5148 | RideHeightSettingStr | RideHeightSettingStr | **HIGH** — confirmed match |
| PressureRange | FRONTLEFT | DAT_005d4271 | PressureRangeString | PressureRangeStr | **HIGH** — exact HDV match |
| PressureSetting | FRONTLEFT | DAT_005d516c | PressureSettingField | PressureSettingStr | **HIGH** — exact HDV match |
| SpringRange | FRONTLEFT | DAT_005d5100 | Str_Springrange | SpringRangeStr | **HIGH** — exact HDV match |
| BumpStopSpring | FRONTLEFT | DAT_005d52d0 | String_BumpStopSpring | BumpStopSpringStr | **HIGH** — exact HDV match |
| BumpStopDamper | FRONTLEFT | DAT_005d52a8 | BumpStopDamperField | BumpStopDamperStr | **HIGH** — exact HDV match |
| CGRearSetting | GENERAL | DAT_005c3e8c | CGRearSettingString | CGRearSettingStr | **HIGH** — exact HDV match |
| CGRearSetting | GENERAL | DAT_005d654c | CgRearSettingString | CGRearSettingStr2 | **MEDIUM** — duplicate string constant |
| CGRearRange | GENERAL | DAT_005d6540 | StringCGRearRange | CGRearRangeStr | **HIGH** — exact match |
| CGRightRange | GENERAL | DAT_005d655c | CGRightRangeString | CGRightRangeStr | **HIGH** — exact match |
| AIEvenSuspension | GENERAL | DAT_005d65fc | AIEvenSuspensionString | AIEvenSuspensionStr | **HIGH** — matches config_params entry |
| AiDamperSlow | GENERAL | DAT_005d65dc | AiDamperSlowString | AiDamperSlowStr | **HIGH** — matches config_params: "AIDamperSlow" |
| UndertrayRideHeight | GENERAL | DAT_005d4478 | UndertrayRideHeightString | UndertrayRideHeightStr | **HIGH** — exact match to HDV parameter concept |
| Front3rdBumpStop | SUSPENSION | DAT_005d6048 | Front3rdBumpStopString | Front3rdBumpStopStr | **HIGH** — matches "Front3rd" parameters in HDV |
| Suspension | SUSPENSION | DAT_005d617c | String_Suspension_1 | SuspensionSectionStr | **HIGH** — "Suspension" section name in HDV |
| BrakePressures | CONTROLS | DAT_005c3ac0 | StringBrakePressures | BrakePressuresStr | **HIGH** — config_params has "BrakePressures" in NASCAR |
| OptimumPressure | COMPOUND | DAT_005d4744 | OptimumPressureString | OptimumPressureStr | **HIGH** — matches tire TBC parameter |
| OptimumPressure | COMPOUND | DAT_005d4758 | String_OptimumPressure | OptimumPressureStr2 | **MEDIUM** — second instance |
| TireWearMultiplier | — (PLR) | DAT_005cfce8 | StringTireWearMultip | TireWearMultiplierStr | **HIGH** — matches UI option string |
| FuelMult | — (PLR) | DAT_005d3dd8 | Str_FuelMultD | FuelMultStr | **MEDIUM** — "FuelMultD" display variant of "FuelMult" |
| GameOptFuelMult | — (UI) | DAT_005d2bac | GameoptFuelMult | GameOptFuelMultStr | **MEDIUM** — UI label for FuelMult option |
| Rear3rdSpringRange | SUSPENSION | DAT_005d5be8 | Rear3rdSpringRangeString | Rear3rdSpringRangeStr | **HIGH** — exact match |
| FfbSteerDamper | — (PLR) | DAT_005cde08 | FfbSteerDamperString | FfbSteerDamperStr | **HIGH** — matches PLR config key |
| HeaveSpring | SUSPENSION | DAT_005d5f4c | Rear3rdBumpstopString | Rear3rdBumpstopStr | **MEDIUM** — "Rear3rdBumpStop" is the HDV key |
| CG Offset | GENERAL | DAT_005c3e8c | CGRearSettingString | CGRearSettingStr | **HIGH** — confirmed |

## String Matches

Shared strings between F1C and other ISI binaries that confirm global purpose.

| String | Found In | F1C Global | Insight |
|--------|----------|-----------|---------|
| `HDVehicle` | rFactor Dedicated.exe | DAT_007cea5c (EngineWearMode) | Confirms hdvehicle.cpp as source module for wear/damage mode globals |
| `"Suspension not allowed here"` | NASCAR_2003_3DConfig, NASCAR_2003_Retail | DAT_005d617c / DAT_005d4810 | Suspension string constants shared across all ISI titles; validates field name mapping |
| `AIDamperSlow` / `AIDamperFast` | NASCAR_2003_Demo, NASCAR_2004_Demo | DAT_005d65dc (AiDamperSlowString) | Exact config parameter name match across games — F1C AI Global uses same naming |
| `AIEvenSuspension` | NASCAR_2003_Demo, NASCAR_2004_Demo | DAT_005d65fc (AIEvenSuspensionString) | Cross-game consistency for AI suspension simplification parameter |
| `FormationAndStart` | rFactor Dedicated.exe (RTTI: `.?AV?$PFData@W4FormationAndStart@@@@`) | DAT_007cebc4 (FormationLap) | rFactor has `FormationAndStart` enum type; F1C stores as int flag. Confirms source = steward.cpp / game.cpp |
| `WeatherCond` | rFactor Dedicated.exe (RTTI: `.?AV?$PFData@W4WeatherCond@@@@`) | DAT_007cf080 (WeatherMode) | rFactor uses enum `WeatherCond` (0-5) for weather conditions; F1C `WeatherMode` matches same range |
| `MechFailureRate` | rFactor Dedicated.exe (RTTI: `.?AV?$PFData@W4MechFailureRate@@@@`) | DAT_007cea5c (EngineWearMode) | rFactor's mech failure rate enum maps to F1C engine wear mode (0/2/3) |
| `FlagRuleSetting` | rFactor Dedicated.exe (RTTI: `.?AV?$PFData@W4FlagRuleSetting@@@@`) | (penalty-related globals) | rFactor has flag rule setting enum; F1C penalty/session globals map to steward.cpp |
| `binkw32.dll` / `_BinkOpen@8` | NASCAR_2003_Demo, NASCAR_2004_Demo | D3D/renderer globals | Confirms Bink video library shared across all isiMotor1 binaries |
| `Miles Sound System` strings | All NASCAR & rFactor binaries | DAT_008c5f40 (AudioOutputHandle) | Miles Sound System integration consistent across all ISI titles |
| `GameData\Vehicles\` | rFactor, NASCAR 2003/2004 | DAT_005ec3d8 (SeasonDir) / DAT_005ec420 (TrackDir) | Directory path structure shared; F1C uses same layout pattern |
| `CUBE` / `D3DXCreateCubeTexture` | All binaries | DAT_008b8f24 (D3DDeviceWrapperPtr) | CUBE renderer engine shared across all ISI titles |
| `HotPacket_over_Winsock` | rFactor, NASCAR 2003/2004 | DAT_007d0418 (SessionTimeoutOverride) | Network layer (HotPacket/Winsock) shared; confirms NetComm-related globals |
| `?VehicleWidth` | rFactor Dedicated.exe | DAT_005ea3d8 (TrackRefSpeed?) | Vehicle width drafting parameter (2.10m) referenced in HDV BODYAERO section |
| `TireWearMulti` | NASCAR_2003_Patch | DAT_007d0c60 (TireWearMultiplier) | String shared; confirms global as tire wear scaling factor |
| `engine_lifetime` / `engine_variance` | F1_2000 | DAT_0059ece0 (LifetimeClampThreshold) | F1_2000 engine lifetime parameters directly match F1C engine lifetime globals; engine lifetime model carried forward from F1 2000 |
| `brake_lifetime` / `brake_variance` | F1_2000 | DAT_005ad21c / DAT_005ad224 (Brake thresholds) | F1_2000 had per-wheel brake lifetime parameters; F1C evolved to threshold-based brake model |
| `FormationSpeedKPH` | rFactor Dedicated.exe | DAT_007cebc4 (FormationLap) | Formation lap speed threshold; confirms formation lap flag controls pace speed |
| `CountCautionLaps` | rFactor Dedicated.exe | (laps/penalty globals) | Caution lap counting logic shared; F1C uses similar race-timing globals |
| `FinishUnderCaution` | rFactor Dedicated.exe | DAT_008acfa0 (HalfDistanceFlag) | Race finish condition flag; half-distance/finish-under-caution logic shared |
| `Max Vehicles` | rFactor Dedicated.exe | DAT_005c329c (VehicleCount) / DAT_008ac390 (VehicleFileCount) | Vehicle count limits shared; confirms setup/game vehicle management |

## SDK Struct Alignment

Alignment of rFactor SDK struct fields against F1C documented globals.

| SDK Field | SDK Struct | SDK Offset | F1C Global | Status |
|-----------|-----------|-----------|-----------|--------|
| `ScoringInfoV2.mGamePhase` (0-8) | ScoringInfoV2 | +0x30 (after base + V2 fields) | DAT_007c56a8 (RacePhase) | **MATCH** — rFactor game phase enum matches F1C RacePhase 0-8; phases: 0=before session, 1=recon, 2=grid walk, 3=formation, 4=start lights, 5=green, 6=caution, 7=stopped, 8=over |
| `ScoringInfoV2.mYellowFlagState` (-1 to 7) | ScoringInfoV2 | +0x31 | — (likely flag-adjacent globals) | **NEW** — F1C may store yellow flag state in session globals (DAT_007ce2e8 SessionCatchupFlag could be related) |
| `ScoringInfoV2.mDarkCloud` / `mRaining` / `mAmbientTemp` / `mTrackTemp` | ScoringInfoV2 | +0x40 / +0x44 / +0x48 / +0x4c | DAT_007cf080 (WeatherMode) / DAT_007cf3c8 (TrackConditionState) | **SHIFTED** — F1C stores weather as discrete mode (0-5) rather than continuous float; rFactor had both |
| `ScoringInfoV2.mOnPathWetness` / `mOffPathWetness` | ScoringInfoV2 | +0x5c / +0x60 | (not in docs/12) | **NEW** — F1C may store wetness in track condition globals |
| `VehicleScoringInfoV2.mFinishStatus` (0=none, 1=finished, 2=DNF, 3=DSQ) | VehicleScoringInfoV2 | +0x03 (offset from VSI base) | (vehicle struct +0x4064) | **MATCH** — documented in STRUCT OFFSETS TABLE; FinishState uses same 0-3 encoding |
| `VehicleScoringInfoV2.mPlace` (1-based) | VehicleScoringInfoV2 | +0x63 | (vehicle struct +0x4060 FinishPosition) | **MATCH** — race position tracking |
| `VehicleScoringInfoV2.mTimeBehindLeader` | VehicleScoringInfoV2 | +0x70 | (not in docs/12) | **NEW** — likely stored per-vehicle rather than globally |
| `TelemInfoBase.mGear` (-1=R, 0=N, 1+) | TelemInfoBase | +0x98 | (not in docs/12) | **MATCH** — gear is per-vehicle state, not a global |
| `TelemInfoBase.mEngineRPM` | TelemInfoBase | +0x9c | (not global) | **PER-VEHICLE** |
| `TelemInfoBase.mEngineWaterTemp` / `mEngineOilTemp` | TelemInfoBase | +0xa0 / +0xa4 | (vehicle struct offsets) | **MATCH** — engine thermal globals DAT_0059e7d8 (ThermalInflectionThreshold) used for temp model |
| `TelemInfoV2.mFuel` | TelemInfoV2 | +0x78 (from base end) | DAT_007d0b64 (FuelMult) | **RELATED** — fuel state per-vehicle, FuelMult is a global multiplier |
| `GraphicsInfo.mCamPos` / `mCamOri` | GraphicsInfo | +0x0 / +0xc | DAT_007cf680 (CameraCenterTargetPos) | **MATCH** — camera position target global |
| `GraphicsInfoV2.mAmbientRed/Green/Blue` | GraphicsInfoV2 | +0x18 / +0x1c / +0x20 | DAT_007cbb0c (EnvFlagMixed) | **RELATED** — environment lighting globals |
| `TelemWheel.mRotation` | TelemWheel | +0x0 | (wheel speed globals DAT_0059e8cc) | **RELATED** — WheelSpeedThreshold gates rotation-dependent logic |
| `TelemWheel.mBrakeTemp` | TelemWheel | +0x18 | DAT_005ad224 (BrakePressureThreshold) | **RELATED** — brake temp/pressure model |
| `TelemWheelV2.mWear` | TelemWheelV2 | +0x28 | DAT_0059ee30 (TireWearAccumFactor) | **RELATED** — tire wear accumulation factor |
| `TelemWheelV2.mSurfaceType` (0=dry, 1=wet, 2=grass, 3=dirt, 4=gravel, 5=rumblestrip) | TelemWheelV2 | +0x3a | DAT_007cf3c8 (TrackConditionState) | **RELATED** — track surface type affects tire behavior |
| `TelemVect3` (x, y, z floats) | — | 0 / 4 / 8 | DAT_008d7220 (ConstantVector3Array) | **MATCH** — math constant vectors used in 3D transforms |

## Proposed Renames

Globals in docs/12 with names that could be improved based on cross-reference evidence.

| Current Name | Proposed Name | Evidence |
|-------------|--------------|----------|
| DAT_005ea3d8 — `DAT_005ea3d8 (track ref speed)` | `TrackRefSpeed` | rFactor HDV BODYAERO section has `BaseDropoff` and `VehicleWidth` params; F1C uses this as track reference speed for AI (already in GLOBALS TABLE as TrackRefSpeed) |
| DAT_005ea438 — `unknown directory/file path` | `MaskPath` or `FilterFilePath` | Adjacent to DAT_005ce64c (GameFilterDataPath); used in setup filter configuration |
| DAT_005be714 — `serialization constant` | `SerializationMagicA` | All 5 serialization constants (DAT_005be714/82c/834/83c/844) are consecutive; consistent naming prefix pattern |
| DAT_0059e43c — `physics constant` | `PhysicsBaseSpeed` | Compared against speed values in suspension brake/tire functions; rFactor HDV has reference speed concept |
| DAT_0059e4d8 — `physics constant` | `PhysicsTimeStep` or `PhysicsScale0` | Used as scaling multiplier in physics integrator |
| DAT_0059e7e8 — `TimeScalingConstant` | `AITimeScalingFactor` or `GameTimeDelta` | Used in game/ai context with DAT_005d00ec (GameState). Not a pure time constant but an AI tick scaling factor |
| DAT_005d91a0 — `PolynomialC2Coefficients` | `AudioFilterCoeffs` | Config_params and rFactor strings confirm these are audio/DSP coefficients (used in FUN_00528cc0 with DAT_008d73f8 AudioPMADDWDTable) |
| DAT_008b8f20 — `ResourceHandle` | `D3DResourceManagerPtr` | Adjacent to DAT_008b8f24 (D3DDeviceWrapperPtr). Both are renderer subsystem pointers |
| DAT_005f0708 — `SessionConfigArray` | `SessionDataArray` | Stride 0x48c0 matches SeasonScoringDB; naming should match companion DAT_007d2e48 |
| DAT_005ed3ec — `DriverValidationFlag` | `DriverValidationArray` | Stride 0x48c0, not a single flag but a per-driver array |
| DAT_007c74dc — `CurrentPlayerIndex` | `LocalPlayerSlotIndex` | Used in network context; rFactor uses "PlayerVehicleID" concept. "PlayerIndex" ambiguous with vehicle index |
| DAT_007cfe88 — `unknown (found in 0x0040cde0)` | `RenderPassStateFlag` | Checked in render/session context; likely a rendering pass gate |
| DAT_008aceb8 — `PhysicsFlagCounter` | `DynamicsSubstepCounter` | Incremented in physics integration loop; controls sub-stepping rather than flag counting |
| DAT_007cde0c — `CollisionSoundHandles (x8)` | `CollisionAudioBufferArray` | 8 handles for collision impact sounds; stored as audio buffer handles not raw handles |
| DAT_007c56a0 — `MultiplayerFlags` | `SessionFlags` | Bit 0 gates multiplayer but bit 1+ may be session/race flags (already correct but scope broader than name implies) |
| DAT_008aae70 — `RingBufferCounter (QA/weather noise)` | `WeatherNoiseRingBufferIdx` | Used in weather/tire wobble simulation; indexing into noise ring buffer |
| DAT_0059ef7c — `ComparisonThreshold` | `CollisionDeepPenetrationThreshold` | Used in collision resolution to detect deep interpenetration (FUN_0044a450); name too generic |
| DAT_0059f078 — `PenaltyScaleFactor` | `StewardPenaltyTimeMult` | Scales penalty duration in steward.cpp; matching rFactor steward's penalty system |
| DAT_005cc9e8 — `SessionInitState` | `NetCommSessionInitPhase` | Used in NetComm.cpp session initialization; -1=uninit, 0=waiting, 1=ready |
| DAT_005d77e4 — `IndirectJumpTarget` | `AudioDSPJumpTable` | Used in FUN_00528cc0 audio/DSP processing as indirect jump target — likely a DSP operation dispatch table |
| DAT_008afe6c — `ParticleArrayCurrentIndex` | `ParticleAllocatorIndex` | Cyclic allocator index (0-0x7F), not "current index" in array traversal sense |
| DAT_0059e458 — `ConstraintForceEpsilon` | `ConstraintSolverEpsilon` | rFactor physics uses iterative constraint solver with force termination threshold |
| DAT_0059e480 — `PhysicsTolerance` | `PositionUpdateTolerance` | Gates position update in dynamics integration, not general physics tolerance |
| DAT_005ad21c — `BrakeRampThreshold1` | `BrakePressureRampLow` | First of three thresholds defining brake pressure ramp curve; naming should indicate ordinal |
| DAT_005ad214 — `BrakeForceRampThresholds` | `BrakeForceRampThresholds` | Already correctly named but description should reference HDV `BrakePressureRange` parameter |

## Notes

1. **No new globals discovered** — all DAT_ addresses in the reference data map to existing entries in docs/12.

2. **Module-to-RTTI mapping is reliable** — The rFactor Dedicated.exe RTTI names provide near-certain class-to-source mappings for F1C. The absence of RTTI in F1C itself (compiled `/GR-`) means class boundaries must be inferred from binary patterns, but the shared source paths and rFactor class hierarchy make the mapping robust.

3. **Config parameter strings as field name evidence** — Every `DAT_005dXXXX` string constant that matches a config_params.txt entry IS the field name used in `sscanf()` parsing. These should be renamed to `XxxStr` or `XxxFieldName` consistently across docs/12. This confirms the field exists at a struct offset but does NOT confirm what offset without decompilation of the parsing function.

4. **SDK struct alignment evidence is strong for session/race** — The `ScoringInfoV2.mGamePhase` → `RacePhase` mapping (0-8 values match exactly) is the strongest single cross-reference finding. This confirms that F1C's race state machine architecture was carried forward nearly unchanged into rFactor's isiMotor 2.0.

5. **F1_2000 engine lifetime model** — `engine_lifetime`/`engine_variance` from F1_2000 .veh files directly correspond to F1C engine lifetime globals (`LifetimeAvg`, `LifetimeVar`, `LifetimeEngineRPM_min/max`). The lifetime model evolved from F1 2000's simpler parameters to F1C's more complex per-engine-part statistical model, then to rFactor's `MechFailureRate` enum system.
