# Source Cross-Reference: docs/08-file-formats.md

## RTTI Class Mappings

| rFactor Class | F1C Function(s) | Confidence | Evidence |
|--------------|-----------------|------------|----------|
| `PlayerFile` | FUN_004b1820, FUN_004b1870, FUN_004b18d0, FUN_004b1900, FUN_004b0770, FUN_004b0540 | HIGH | Exact source path `plrfile.cpp` matches rFactor source path list. Class has Save/Load lifecycle mirrors F1C's PlayerFile::Enter/Setup/Restart/Post. |
| `PFString` | FUN_00559e20, FUN_00565520, FUN_00559e20, FUN_005897ca | HIGH | Configuration key-value parsers. PFString is rFactor's string-based config parameter class, matching format string tokenizer pattern. |
| `PFData<MechFailureRate>` | FUN_004c18b0 (career stats reader, field +0x15=MECHFAIL_rate) | HIGH | `MechFailureRate` enum type used as PFData template param in rFactor RTTI. F1C reads `MECHFAIL_rate` from player config. |
| `PFData<FormationAndStart>` | FUN_004c18b0 (field +0x18=RACECOND_formation), FUN_004c0b70 (SEASONSTATUS), FUN_00432cc0 | HIGH | `FormationAndStart` enum as PFData template — matches F1C formation lap config fields. |
| `PFData<FlagRuleSetting>` | FUN_004c18b0 (field +0x19=RACECOND_flag_rules) | HIGH | `FlagRuleSetting` enum as PFData template — matches F1C flag rules config. |
| `PFData<WeatherCond>` | FUN_004c18b0 (field +0x1a=RACECOND_weather) | HIGH | `WeatherCond` enum — matches F1C weather condition config field. |
| `PFData<cubeFileType>` | FUN_0045c240 (file scanner — scans .gdb/.hdv/terrain.ini by type) | MEDIUM | `cubeFileType` = file type classification enum. F1C's file scanner dispatches by extension type matching file type categories. |
| `PFData<RaceFinishCriteria>` | FUN_004c2a80 (season scoring), FUN_004c0910 (race finish processing) | MEDIUM | Race finish criteria enum matches scoring logic that checks finish state conditions. |
| `MPFile` | FUN_004c6330 (filter builder), FUN_004c5840 (SeasonRaces section finder), FUN_004c5ae0 (SeasonRaces writer) | MEDIUM | MPFile manages multiplayer file access. F1C's section-based file readers for SeasonRaces match this pattern. |
| `SmartFile` / `EncryptedSmartFile` / `GoldEncryptedFile` | FUN_0058c43c (file open mode parser), FUN_0058ae69 (mode string parser) | HIGH | SmartFile = ISI file I/O wrapper supporting encryption. Mode string parsing ("rb", "wt", etc.) is the file open layer. |
| `Game` | FUN_004c3d80 (VehicleFile loader), FUN_004c52c0 (SceneFile loader), FUN_004c40d0 (file finder) | HIGH | Game class manages file loading lifecycle. Source path `setup.cpp` confirmed. |
| `DynMan` | FUN_004b70b0 (LoadVehicleEntries), FUN_004b8da0 (ProcessDriverEntries) | MEDIUM | DynMan = dynamics manager that initializes vehicle entries. Matches driver/vehicle entry processing. |
| `Steward` | FUN_004c0b70 (Season state reader), FUN_004c2a80 (season scoring) | MEDIUM | Steward class manages race rules/scoring. Season state file reader matches steward module. |
| `SearchGrid` | FUN_004c3f80 (vehicle lookup by name), FUN_004c3fe0 (vehicle name enum) | MEDIUM | SearchGrid = spatial search. Vehicle array iteration for name lookup uses similar pattern. |
| `BasePF` | FUN_00551560 (config tree allocator), FUN_005518a0 (config tree leaf insert) | HIGH | BasePF is the base class for rFactor's config parameter system. Tree-based config section loader matches pattern. |
| `Options_SliderBar` | FUN_004f3c10 (EngineMapRange/Setting reader — reads range+setting pairs) | MEDIUM | Slider/SpinBox range+setting field pairs match the Options UI control data binding pattern. |
| `Options_SpinBox` | FUN_004f61d6 (Gear/FinalDrive/Reverse setting range readers), FUN_004f3c10 | MEDIUM | Same range+setting field pattern — SpinBox stores (min, step, count) + current index. |
| `TvOverlayPageRaceHUD` | FUN_0046b5f0 (FTIM timer bitmap selector) | LOW | Timing display overlay matches RaceHUD pattern. |
| `CommentaryRequestInfo` | FUN_004201e0, FUN_00420000 (track→commentary format ID), FUN_00417640, FUN_00417af0 (team→commentary format) | HIGH | Commentary format ID mapping functions directly correspond to commentary event system. |
| `Weather` | FUN_00460a10 (terrain.ini parser/validator) | MEDIUM | Weather class reads track condition data. terrain.ini parsing includes weather context. |
| `Options_BaseMenuItem` / `Options_MenuItemText` | FUN_004c0690 (settings/ini writer), FUN_004a1ec0 (settings path builder) | MEDIUM | Menu item config writing follows the Options/AppOptions hierarchy. |

## Parameter-to-Offset Mappings

### .hdv GENERAL section parser (FUN_004f4270)

| Config Param | Section | F1C Context | Confidence |
|-------------|---------|-------------|------------|
| `Mass` | GENERAL | .hdv parser reads Mass= value | HIGH |
| `Inertia` | GENERAL | .hdv parser reads 3-component inertia vector | HIGH |
| `FuelRange` / `FuelSetting` | GENERAL | F1C doc confirms FuelRange/Setting parsed (FUN_004f4270) | HIGH |
| `NumPitstopsRange` / `NumPitstopsSetting` | GENERAL | Doc confirms pit strategy fields in parser | HIGH |
| `Pitstop1Range`–`Pitstop3Range` / Setting | GENERAL | Doc confirms all pit strategy format fields | HIGH |
| `CGHeight` | GENERAL | F1C doc CGHeight listed | HIGH |
| `CGRightRange` / `CGRightSetting` | GENERAL | doc lists these fields | HIGH |
| `CGRearRange` / `CGRearSetting` | GENERAL | doc lists these fields | HIGH |
| `TireBrand` | GENERAL | Tire brand lookup via FUN_004d7880 | HIGH |
| `FrontTireCompoundSetting` / `RearTireCompoundSetting` | GENERAL | compound selection | HIGH |
| `DamageFile` | GENERAL | points to .ini for damage | HIGH |
| `FeelerFlags` / `Feeler*` (all 12 feeler fields) | GENERAL | collision feeler definitions | HIGH |
| `Undertray00`–`Undertray10` | GENERAL | undertray points | HIGH |
| `UndertrayParams` | GENERAL | spring/damper/friction | HIGH |
| `Rules` | GENERAL | 0=none, 1=stock car | HIGH |
| `GarageDisplayFlags` | GENERAL | display mode flags | HIGH |
| `WedgeRange` / `WedgeSetting` / `WedgePushrod` | GENERAL | wedge adjustment config | HIGH |
| `GraphicalOffset` | GENERAL | visual offset only | HIGH |
| `FuelTankPos` / `FuelTankMotion` | GENERAL | fuel tank physics | HIGH |
| `Notes` | GENERAL | string note | HIGH |
| `Symmetric` | GENERAL | symmetric flag | HIGH |

### SUSPENSION section parser

| Config Param | Section | F1C Context | Confidence |
|-------------|---------|-------------|------------|
| `PhysicalModelFile` | SUSPENSION | refs .pm file (FUN_004f2c60 per wheel) | HIGH |
| `AdjustSuspRates` | SUSPENSION | 0=direct, 1=wheel rates | HIGH |
| `FrontAntiSwayRange`–`RearAntiSwaySetting` | SUSPENSION | all anti-sway fields | HIGH |
| `FrontToeInRange` / `FrontToeInSetting` | SUSPENSION | toe-in per corner adjusted | HIGH |
| `RearToeInRange` / `RearToeInSetting` | SUSPENSION | rear toe-in | HIGH |
| `CamberRange` / `CamberSetting` | FRONTLEFT/FRONTRIGHT/REARLEFT/REARRIGHT | camber per corner | HIGH |
| `SpringRange` / `SpringSetting` | per-corner | spring rate config | HIGH |
| `RideHeightRange` / `RideHeightSetting` | per-corner | ride height | HIGH |
| `SlowBumpRange`–`FastReboundSetting` | per-corner | all 8 damper fields (Slow/Fast Bump/Rebound × Range/Setting) | HIGH |
| `BumpTravel` / `ReboundTravel` | per-corner | suspension travel limits | HIGH |
| `BumpStopSpring`–`BumpStopRisingDamper` | per-corner | bumpstop parameters | HIGH |
| `PackerRange` / `PackerSetting` | per-corner | packer adjustment | HIGH |
| `PressureRange` / `PressureSetting` | per-corner | tire pressure | HIGH |
| `SpringRubberRange` / `SpringRubberSetting` | per-corner | spring rubber | HIGH |
| `DamperMult` / `SpringMult` | per-corner | motion ratio corrections | HIGH |
| `FrictionTorque` | per-corner | spindle friction | HIGH |
| `SpinInertia` | per-corner | wheel spin inertia | HIGH |
| `CGOffsetX` | per-corner | CG offset (unimplemented) | HIGH |
| `PushrodSpindle` / `PushrodBody` | per-corner | suspension geometry | HIGH |
| `CorrectedInnerSuspHeight` | SUSPENSION | suspension height correction | HIGH |
| `ApplySlowToFastDampers` | SUSPENSION | damper mixing flag | HIGH |
| `AlignWheels` | SUSPENSION | graphical offset correction | HIGH |
| `FrontWheelTrack` / `RearWheelTrack` | SUSPENSION | track width | HIGH |
| `LeftWheelBase` / `RightWheelBase` | SUSPENSION | wheelbase | HIGH |
| `SpringBasedAntiSway` | SUSPENSION | 0=diameter, 1=spring | HIGH |
| `AllowNoAntiSway` | SUSPENSION | first setting = none | HIGH |
| `FrontAntiSwayBase` / `RearAntiSwayBase` | SUSPENSION | tube twist extra | HIGH |
| `LeftCasterRange`–`RightCasterSetting` | SUSPENSION | caster angle | HIGH |
| `LeftTrackBarRange`–`RightTrackBarSetting` | SUSPENSION | track bar | HIGH |
| `FrontAntiSwayRate` / `RearAntiSwayRate` | SUSPENSION | spring-based rate calc | HIGH |

### CONTROLS section parser

| Config Param | Section | F1C Context | Confidence |
|-------------|---------|-------------|------------|
| `SteeringFFBMult` | CONTROLS | force feedback | HIGH |
| `SteerLockRange` / `SteerLockSetting` | CONTROLS | steering lock | HIGH |
| `RearBrakeRange` / `RearBrakeSetting` | CONTROLS | brake bias | HIGH |
| `BrakePressureRange` / `BrakePressureSetting` | CONTROLS | brake pressure | HIGH |
| `UpshiftAlgorithm` / `DownshiftAlgorithm` | CONTROLS | shift points | HIGH |
| `AutoUpshiftGripThresh` / `AutoDownshiftGripThresh` | CONTROLS | grip-based shift | HIGH |
| `TractionControlGrip` / `TractionControlLevel` | CONTROLS | TC params | HIGH |
| `ABS4Wheel`, `ABSGrip`, `ABSLevel` | CONTROLS | ABS params | HIGH |

### Brake section parser (per-corner FRONTLEFT etc.)

| Config Param | Section | F1C Context | Confidence |
|-------------|---------|-------------|------------|
| `BrakeDiscRange` / `BrakeDiscSetting` | per-corner | disc thickness | HIGH |
| `BrakePadRange` / `BrakePadSetting` | per-corner | pad type | HIGH |
| `BrakeDiscInertia` | per-corner | inertia per meter | HIGH |
| `BrakeTorque` | per-corner | max torque | HIGH |
| `BrakeHeating` | per-corner | heat per torque | HIGH |
| `BrakeCooling` | per-corner | cooling rate | HIGH |
| `BrakeDuctCooling` | per-corner | duct cooling | HIGH |
| `BrakeWearRate` | per-corner | wear per second | HIGH |
| `BrakeFailure` | per-corner | failure thickness | HIGH |
| `BrakeResponseCurve` | per-corner | temp response curve | HIGH |
| `BrakeGlow` | per-corner | glow temp range | HIGH |
| `BrakeOptimumTemp` | per-corner | optimum temp (not in rFactor F1 .hdv shown, but in NASCAR) | HIGH |

### DRIVELINE section parser

| Config Param | Section | F1C Context | Confidence |
|-------------|---------|-------------|------------|
| `GearFile` | DRIVELINE | refs .ini file for ratios | HIGH |
| `FinalDriveSetting` | DRIVELINE | indexed into GearFile | HIGH |
| `ForwardGears` | DRIVELINE | gear count | HIGH |
| `ReverseSetting` | DRIVELINE | reverse ratio index | HIGH |
| `Gear1Setting`–`GearNSetting` | DRIVELINE | per-gear ratio indices | HIGH |
| `ClutchEngageRate`–`ClutchWear` | DRIVELINE | all clutch params | HIGH |
| `BaulkTorque` | DRIVELINE | max engagement torque | HIGH |
| `AllowManualOverride` | DRIVELINE | auto-shift override | HIGH |
| `SemiAutomatic` | DRIVELINE | throttle/clutch auto | HIGH |
| `UpshiftDelay`–`DownshiftBlipThrottle` | DRIVELINE | shift timing params | HIGH |
| `WheelDrive` | DRIVELINE | REAR/FOUR/FRONT | HIGH |
| `AllowGearingChanges` / `AllowFinalDriveChanges` | DRIVELINE | upgrade locks | HIGH |
| `DiffPumpRange`–`Preload4WDEffect` | DRIVELINE | all diff settings | HIGH |

### BODYAERO section parser

| Config Param | Section | F1C Context | Confidence |
|-------------|---------|-------------|------------|
| `BodyDragBase` | BODYAERO | base drag | HIGH |
| `BodyDragHeightAvg` / `BodyDragHeightDiff` | BODYAERO | ride height effects | HIGH |
| `BodyMaxHeight` | BODYAERO | max height for aero | HIGH |
| `DraftBalanceMult` | BODYAERO | draft balance | HIGH |
| `BodyDraftLiftMult` | BODYAERO | draft lift effect | HIGH |
| `BodyLeft`–`BodyRot` | BODYAERO | all 6-DOF aero forces | HIGH |
| `BodyCenter` | BODYAERO | aero center offset | HIGH |
| `RadiatorRange`–`RadiatorSetting` | BODYAERO | radiator/grille tape | HIGH |
| `RadiatorDrag` / `RadiatorLift` | BODYAERO | drag/lift per setting | HIGH |
| `BrakeDuctRange`–`BrakeDuctSetting` | BODYAERO | brake duct params | HIGH |
| `BrakeDuctDrag` / `BrakeDuctLift` | BODYAERO | drag/lift per brake duct | HIGH |
| `BaseDropoff`–`SideFollowingExponent` | BODYAERO | drafting override params | HIGH |

### FRONTWING / REARWING section parser

| Config Param | Section | F1C Context | Confidence |
|-------------|---------|-------------|------------|
| `FWRange` / `FWSetting` | FRONTWING | wing angle range | HIGH |
| `FWMaxHeight` | FRONTWING | max height for DF | HIGH |
| `FWDragParams` / `FWLiftParams` | FRONTWING | base+1st+2nd order | HIGH |
| `FWDraftLiftMult` | FRONTWING | draft effect | HIGH |
| `FWLiftHeight` / `FWLiftSideways` | FRONTWING | height/yaw effects | HIGH |
| `FWLiftPeakYaw` | FRONTWING | peak yaw angle | HIGH |
| `FWLeft`–`FWRot` | FRONTWING | 6-DOF force/torque | HIGH |
| `FWCenter` | FRONTWING | center offset | HIGH |
| (Same set for RW/RearWing: `RWRange`, `RWSetting`, `RWDragParams`, etc.) | REARWING | same pattern | HIGH |

### DIFFUSER section parser

| Config Param | Section | F1C Context | Confidence |
|-------------|---------|-------------|------------|
| `DiffuserBase` | DIFFUSER | base lift + orders | HIGH |
| `DiffuserFrontHeight` | DIFFUSER | front ride height effect | HIGH |
| `DiffuserRake` | DIFFUSER | optimum rake | HIGH |
| `DiffuserLimits` | DIFFUSER | stall limits | HIGH |
| `DiffuserStall` | DIFFUSER | stall function | HIGH |
| `DiffuserDraftLiftMult` | DIFFUSER | draft effect | HIGH |
| `DiffuserSideways` | DIFFUSER | yaw dropoff | HIGH |
| `DiffuserPeakYaw` | DIFFUSER | peak yaw | HIGH |
| `DiffuserCenter` | DIFFUSER | center offset | HIGH |

### AIDPENALTIES section parser

| Config Param | Section | F1C Context | Confidence |
|-------------|---------|-------------|------------|
| `TC`, `ABS`, `Stability`, `Autoshift`, `Steering`, `Braking`, `Invulnerable`, `Opposite`, `SpinRecovery`, `AutoPit`, `AutoLift`, `AutoBlip` | AIDPENALTIES | all aid penalty weight fields | HIGH |

### PITMENU section parser

| Config Param | Section | F1C Context | Confidence |
|-------------|---------|-------------|------------|
| `StopGo`, `Fuel`, `AllTires`, `FrontRearTires`, `LeftRightTires`, `IndividualTires`, `FenderFlare`, `FrontWing`, `RearWing`, `Driver`, `Wedge`, `Radiator`, `TrackBar`, `Pressure`, `SpringRubber`, `Damage` | PITMENU | availability toggles | HIGH |
| `StopGoSimultaneous`, `PressureOnTheFly`, `DamagedTiresOnly`, `CompoundRestrictions` | PITMENU | restrictions | HIGH |
| `Preparation`, `FuelTime`, `TireTime`, `FenderFlareTime`, `FrontWingTime`, `RearWingTime`, `DriverTime`, etc. | PITMENU | timing parameters | HIGH |

### ENGINE section parser

| Config Param | Section | F1C Context | Confidence |
|-------------|---------|-------------|------------|
| `Normal` | ENGINE | points to engine .ini | HIGH |
| `RestrictorPlate` | ENGINE | restricted engine .ini | HIGH |

### Player career stats config (FUN_004c18b0, FUN_004c2420)

| Config Param | Section | F1C Offset | F1C Field Name | Confidence |
|-------------|---------|-------------|----------------|------------|
| `ABORTEDSEASONS` | CAREER | +0x08 | ABORTEDSEASONS | HIGH |
| `TOTALLAPS` | CAREER | +0x09 | TOTALLAPS | HIGH |
| `TOTALRACES` | CAREER | +0x0a | TOTALRACES | HIGH |
| `TOTALRACESWITHAI` | CAREER | +0x0b | TOTALRACESWITHAI | HIGH |
| `TOTALPOINTSSCORED` | CAREER | +0x0c | TOTALPOINTSSCORED | HIGH |
| `TOTALCHAMPIONSHIPS` | CAREER | +0x0d | TOTALCHAMPIONSHIPS | HIGH |
| `TOTALWINS` | CAREER | +0x0e | TOTALWINS | HIGH |
| `TOTALPOLES` | CAREER | +0x0f | TOTALPOLES | HIGH |
| `MECHFAIL_rate` | RACEOPTIONS | +0x15 | MECHFAIL_rate | HIGH |
| `RACECOND_reconnaissance` | RACEOPTIONS | +0x16 | RACECOND_reconnaissance | HIGH |
| `RACECOND_walkthrough` | RACEOPTIONS | +0x17 | RACECOND_walkthrough | HIGH |
| `RACECOND_formation` | RACEOPTIONS | +0x18 | RACECOND_formation | HIGH |
| `RACECOND_flag_rules` | RACEOPTIONS | +0x19 | RACECOND_flag_rules | HIGH |
| `RACECOND_weather` | RACEOPTIONS | +0x1a | RACECOND_weather | HIGH |
| `GAMEOPT_qualify_laps` | RACEOPTIONS | +0x1c | GAMEOPT_qualify_laps | HIGH |
| `GAMEOPT_race_laps` | RACEOPTIONS | +0x1d | GAMEOPT_race_laps | HIGH |
| `GAMEOPT_race_time` | RACEOPTIONS | +0x1e | GAMEOPT_race_time | HIGH |
| `GAMEOPT_race_length` | RACEOPTIONS | +0x1f | GAMEOPT_race_length | HIGH |
| `GAMEOPT_opponents` | RACEOPTIONS | +0x20 | GAMEOPT_opponents | HIGH |
| `GAMEOPT_fuel_mult` | RACEOPTIONS | +0x21 | GAMEOPT_fuel_mult | HIGH |
| `GAMEOPT_tire_mult` | RACEOPTIONS | +0x22 | GAMEOPT_tire_mult | HIGH |
| `GAMEOPT_speed_comp` | RACEOPTIONS | +0x23 | GAMEOPT_speed_comp | HIGH |

### Vehicle setup file fields (FUN_004f6300, FUN_004f61d6, FUN_004f3c10)

| Config Param | Section | F1C Context | Confidence |
|-------------|---------|-------------|------------|
| `FinalDriveSetting` | GEAR_RATIOS | Gear ratio reader FUN_0042de10 | HIGH |
| `ReverseSetting` | GEAR_RATIOS | gear ratio setup | HIGH |
| `Gear1Setting`–`Gear6Setting` | GEAR_RATIOS | per-gear settings | HIGH |
| `RevLimitRange` / `RevLimitSetting` | ENGINE | FUN_004f3c10 | HIGH |
| `EngineMapRange` / `EngineMapSetting` | ENGINE | FUN_004f3c10 | HIGH |
| `EngineBrakingMapRange` / `EngineBrakingMapSetting` | ENGINE | FUN_004f3c10 | HIGH |
| `SetupType` | BASIC | 0=Custom, 1=Gearing, 2=Balance, 3=Downforce | HIGH |

### .veh file parser (FUN_004c3200)

| Config Param | Section | F1C Offset | F1C Field | Confidence |
|-------------|---------|-------------|-----------|------------|
| `HDVehicle` | VEHICLE | +0x02 | HDVehicle file path | HIGH |
| `HeadPhysics` | VEHICLE | +0x04 | HeadPhysics path | HIGH |
| `Sounds` | VEHICLE | +0x06 | Sounds file path | HIGH |
| `Graphics` | VEHICLE | +0x08 | Graphics file path | HIGH |
| `GenString` | VEHICLE | +0x0a | GenString | HIGH |
| `Eyepoint` | VEHICLE | +0x0e–0x10 | 3 floats | HIGH |
| `CameraTarget` | VEHICLE | +0x11–0x13 | 3 floats | HIGH |
| `MirrorPos` | VEHICLE | +0x14–0x16 | 3 floats | HIGH |
| `MirrorNorm` | VEHICLE | +0x17–0x19 | 3 floats | HIGH |
| `Number` | VEHICLE | +0x1d | Driver number | HIGH |
| `Driver` | VEHICLE | +0x2f | Driver name | HIGH |
| `Description` | VEHICLE | +0x3f | Description | HIGH |
| `Engine` | VEHICLE | +0x4f | Engine file | HIGH |
| `Manufacturer` | VEHICLE | +0x5f | Manufacturer | HIGH |
| `Classes` | VEHICLE | +0x6f | Vehicle classes | HIGH |
| `FullTeamName` | VEHICLE | +0xaf | Full team name | HIGH |
| `TrackLivery` | VEHICLE | +0xf5 | Track→livery linked list | HIGH |
| `DefaultLivery` | VEHICLE | — | default livery | HIGH |

### Season/GDB parser functions

| Config Param | Section | F1C Context | Confidence |
|-------------|---------|-------------|------------|
| `SceneOrder` | SeasonRaces | FUN_004c1190, FUN_004c5cb0, FUN_004c5840 | HIGH |
| `SettingsFolder` | SeasonRaces | FUN_004326a0 | HIGH |
| `EventName` | SeasonRaces | FUN_004c5900 | HIGH |
| `TrackName` | SeasonRaces | FUN_004c5920 | HIGH |
| `SeasonRaces` | SeasonRaces | FUN_004c5ae0 (writer), FUN_004c5940 (sorter) | HIGH |
| `SeasonScoringInfo` | SeasonRaces | FUN_004c2a80, FUN_004c0910 | HIGH |
| `Filter Properties` | Scene | FUN_004c6330, FUN_004c5e50, FUN_004c5fd0, FUN_004c6150 | HIGH |
| `AutoLoadEntry` | Config | FUN_00432bf0 (writer), FUN_00432a70 (reader), FUN_00432e70 (list loader) | HIGH |
| `[CAREER]` | Player | FUN_004c2700 | HIGH |
| `[CAREERSEASON]` | Player | FUN_004c2420 | HIGH |
| `[PLAYERTRACKSTAT]` | Player | FUN_004c2420 | HIGH |
| `[OPPONENT]` | Player | FUN_004c0b70 | HIGH |
| `[PLAYER]` | Player | FUN_004c0b70 | HIGH |
| `SEASONSTATUS` | Player | FUN_004c0b70 (+0xb144) | HIGH |
| `RACESESSION` | Player | FUN_004c0b70 (+0xb14c) | HIGH |
| `RACEOVER` | Player | FUN_004c0b70 (+0xb150) | HIGH |
| `CURRENTRACE` | Player | FUN_004c0b70 (+0xb148) | HIGH |
| `Nationality` | Vehicle | FUN_004c78f0 (+0x4660) | HIGH |
| `Game Filter` | Config | FUN_004c0db0 | HIGH |
| `Abbreviation` | Scene | FUN_004c6a10 | HIGH |

## String Matches

| String | Found In | F1C Function(s) | Insight |
|--------|----------|-----------------|---------|
| `*.hdv file references unknown tire compound "%s"` | NASCAR_2003/2004/Dedicated/Demo, rFactor | FUN_004f4270 (hdv parser) | Shared error message across all ISI games — validates tire compound references in .hdv files |
| `CUBEMAS4.00` / `CUBEMAS4.01` / `CUBEMAS4.10` | NASCAR_2003_3DConfig, NASCAR_2003_Demo, NASCAR_2004_3DConfig/Dedicated/Demo | MAS archive loader functions | MAS = CUBE engine archive format. Version strings compatible across generations. |
| `FONT.MAS` / `PITANIMS.MAS` / `PITS.MAS` / `CMAPS.MAS` / `ingame.mas` / `options.mas` | NASCAR_2003/2004 | file scanner/archive functions | Standard MAS archive names shared across all ISI games |
| `GAME.DIC` / `options.dic` | NASCAR_2003_3DConfig/Demo/Patch | FUN_005897ca (tokenizer) | Dictionary files for UI text localization. Present across all ISI titles. |
| `GameData\Vehicles\` | rFactor, rFactor Dedicated | FUN_004c3d80 (VehicleFile loader) | Vehicle directory path pattern matching |
| `VehiclesDir` / `VehicleSound` | Multiple ISI games | FUN_0043d80 | Config path registration constants |
| `UserData\Log\osc.information` | rFactor | FUN_00559e20 (config parser stub) | OSC debug logging path |
| `OSC Read Error` / `OSC %s on line %d` | rFactor | FUN_00559e20 / OSC parser | OSC (OnScreen Control) UI definition file parser errors |
| `Prelinked Gizmo - %s` | rFactor | UI gizmo reader functions | Gizmo = reusable UI widget. Prelinking = widget assembly optimization. |
| `PitStopStrategies` | rFactor, rFactor Dedicated | FUN_004f4270 (pit strategy fields) | Parameter name for pit strategy override file |
| `Force Formation` / `Formation Lap` / `FormationAndStart` | rFactor, NASCAR | FUN_004c18b0 (+0x18), FUN_004c32cc0 | Formation lap config param shared across all ISI games |
| `FormationSpeedKPH` / `FormationStandingStartloc` | rFactor | formation lap config | Specific formation lap velocity/location params in rFactor |
| `Press SPACE To Skip Formation Lap` / `Skipping Formation Lap ...` | rFactor | race state UI | Formation lap skip UI text |
| `CountCautionLaps` / `FinishUnderCaution` | rFactor, rFactor Dedicated | FUN_004c2a80 (season scoring) | Caution lap counting and finish-under-caution rule |
| `Safety Car Thresh` / `Safety Car Collidable` | rFactor, rFactor Dedicated | steward/race logic | Safety car configuration parameters |
| `Stay Behind The Safety Car` | rFactor | race state HUD | Safety car instruction text |
| `Pitstop Description` | rFactor, rFactor Dedicated | FUN_004f4270 (PITMENU fields) | Pitstop info display toggle |
| `F1_Circuit_AI_Qual_Setup_Wetness` / `F1_Circuit_AI_Race_Setup_Wetness` | NASCAR_2003_Demo | FUN_004c6c40 (vehgen.scn loader) | AI wet setup config keys — NASCAR had F1 circuit AI config |
| `SetupType` | rFactor (implied) | FUN_004f6300 (+0x13c0) | Setup type selector: Custom/Gearing/Balance/Downforce |
| `TrackLivery` | — | FUN_004c3200 (.veh parser) | Track-specific livery format: `TrackLivery=<track>,<livery>` |
| `PlayerNameNeverUsed` | — | FUN_004b03f0, FUN_00469550, FUN_0046cb50 | Special reserved name for first-time profile creation — unique to F1C |
| `ProfileIcon.bmp` / `ProfileIcon_DFT.bmp` | — | FUN_00468ee0, FUN_004692b0, FUN_00478020 | Profile icon filenames — unique to F1C's UI system |
| `credits.txt` | — | FUN_00467e40 | Credits file in game data dir |
| `Q_Order0000.bmp` | — | FUN_0046c820 | Qualifying order background bitmap |
| `FTIM14REDOUTLINED.BMP` / `GREENOUTLINED` / `GreyOutlined` | — | FUN_0046b5f0 | Lap time comparison bitmap names |
| `World Championships:` / `Wins:` / `Points:` / `Pole Positions:` | — | FUN_00468910 | HTML results page labels — F1-specific terminology |
| `%s%scan't open %s` (implied `Could not find %s`) | — | FUN_004c40d0 (file finder) | File-not-found error format |
| `%s.SCN` / `%s.AIW` | — | FUN_004c54f0 | Scene/AI waypoint file naming convention |
| `vehgen.scn` | — | FUN_004c6c40 | Vehicle generation scene filename |
| `terrain.ini` | — | FUN_004c60a10 | Terrain config filename |
| `Game Filter` | — | FUN_004c0db0 | Filter config section name |
| `AutoLoadEntry` | — | FUN_00432bf0, FUN_00432a70, FUN_00432e70 | Autoload config section |
| `Abbreviation` | — | FUN_004c6a10 | Driver abbreviation section |
| `Filter Properties` | — | FUN_004c6330, FUN_004c5e50, FUN_004c5fd0, FUN_004c6150 | Scene filter property section |
| `SeasonRaces` | — | FUN_004c5ae0, FUN_004c5940, FUN_004c5840, FUN_004c326a0, FUN_004c11e0 | Season race schedule section — present in rFactor as well |
| `AppName` / `CPURATING` / `CPURating` / `CameraEditorResourceDir` | NASCAR_2003_Retail, rFactor | Config.ini readers | Shared config system settings |
| `DefaultScoring` / `Scoring` / `OtherScoringInfo` / `SeasonScoringInfo` | rFactor | FUN_004c2a80, FUN_004c0910 | Scoring section names shared across ISI |
| `FreeVehicle` / `PLAYERVEHICLEID` / `CURRENTRACE` / `RACESESSION` / `RACECOND_formation=%d` | rFactor | FUN_004c0b70 | Race state logging format strings |
| `%s(%d) reported contact (%.2f) with another vehicle %s(%d)` | rFactor | contact reporting | Shared contact log format |
| `Slot=%d Vehicle="%s" Old="%s" New="%s"` | rFactor | vehicle swap logging | Vehicle slot change log format |

## SDK Struct Alignment

### TelemWheel → Vehicle wheel struct

| SDK Field | SDK Offset (bytes) | F1C Offset | Status |
|-----------|-----------|------------|--------|
| `mRotation` | 0 | varies | NOT MAPPED — F1C wheel rotation likely in physics struct, not file parser. The file format doc covers .hdv parser, not runtime physics. |
| `mSuspensionDeflection` | 4 | varies | NOT MAPPED — runtime suspension state, not file format |
| `mRideHeight` | 8 | varies | NOT MAPPED — runtime state |
| `mTireLoad` | 12 | varies | NOT MAPPED — runtime state |
| `mBrakeTemp` | 24 | varies | NOT MAPPED — runtime state |
| `mPressure` | 28 | `PressureSetting` / `PressureRange` | MATCH — config fields in .hdv per-corner section map to mPressure target |
| `mTemperature[3]` | 32 | varies | NOT MAPPED — runtime tire temp state |

### TelemWheelV2 (extends TelemWheel)

| SDK Field | SDK Offset | F1C Context | Status |
|-----------|-----------|-------------|--------|
| `mWear` | 44 | `BrakeWearRate` in .hdv; tire wear from tire model | PARTIAL — wear rate is file config, runtime wear is computed |
| `mTerrainName[16]` | 48 | `terrain.ini` parser (FUN_00460a10) | MATCH — terrain material name lookup |
| `mSurfaceType` | 64 | terrain validation check 2 (surface type hash) | MATCH |
| `mFlat` | 65 | tire flat detection (runtime) | NOT MAPPED — runtime |
| `mDetached` | 66 | wheel detachment (runtime) | NOT MAPPED — runtime |

### VehicleScoringInfo → Season/race scoring struct

| SDK Field | SDK Offset | F1C Offset | Status |
|-----------|-----------|------------|--------|
| `mDriverName[32]` | 0 | param_1+0x4620 (driver name) | SHIFTED — F1C driver name at 0x4620, not at struct base |
| `mVehicleName[64]` | 32 | param_1+0x4678 (VehicleDescription) | PARTIAL — vehicle description string |
| `mTotalLaps` | 96 | `TotalLaps` in career stats (+0x09) | MATCH — int field |
| `mFinishStatus` | 99 | +0x4064 (FinishState: 0=running, 1=finished, 2=DNF, 3=DSQ) | MATCH — same enum semantics |
| `mBestSector1` | 116 | NOT MAPPED | MISSING — sector times not explicitly mapped in doc |
| `mBestSector2` | 120 | NOT MAPPED | MISSING |
| `mBestLapTime` | 124 | +0x409c (BestLapTime) | MATCH — float field at known offset |
| `mLastSector1` | 128 | NOT MAPPED | MISSING |
| `mLastSector2` | 132 | NOT MAPPED | MISSING |
| `mLastLapTime` | 136 | NOT MAPPED | MISSING |
| `mNumPitstops` | 148 | +0x1162 (PitStopCount) | MATCH |
| `mNumPenalties` | 150 | NOT MAPPED | MISSING |

### VehicleScoringInfoV2 (extends VehicleScoringInfo)

| SDK Field | SDK Offset | F1C Offset | Status |
|-----------|-----------|------------|--------|
| `mIsPlayer` | 152 | — | NOT MAPPED — implicit via PlayerVehiclePtr |
| `mControl` | 153 | — | NOT MAPPED |
| `mInPits` | 154 | — | NOT MAPPED |
| `mPlace` | 155 | +0x4058 (QualifyingPosition), +0x4060 (FinishPosition) | PARTIAL — F1C has separate qual/finish position fields |
| `mVehicleClass[32]` | 156 | Classes field in .veh parser | MATCH — class name string |
| `mTimeBehindNext` | 188 | — | NOT MAPPED — computed at runtime |
| `mTimeBehindLeader` | 200 | — | NOT MAPPED |
| `mPos` | 212 | — | NOT MAPPED — runtime |
| `mLocalVel` | 224 | — | NOT MAPPED — runtime |
| `mOriX/Y/Z` | 236+ | — | NOT MAPPED — runtime orientation matrix |

### ScoringInfoV2 → Session/Race state struct

| SDK Field | SDK Offset | F1C Context | Status |
|-----------|-----------|-------------|--------|
| `mGamePhase` (0=Before, 1=Recon, 2=Walk, 3=Formation, 4=Start lights, 5=Green, 6=FCY, 7=Stopped, 8=Over) | 224 (after base) | `DAT_007c56a8` (RacePhase 0–7) | MATCH — same phase enum, F1C has slightly fewer states (0–7 vs 0–8) |
| `mYellowFlagState` | 225 | NOT MAPPED | MISSING — yellow flag state machine |
| `mStartLight` | 227 | NOT MAPPED | MISSING |
| `mRaining` | 240 | Weather state (DAT_007cf080) | MATCH — weather mode |
| `mAmbientTemp` | 244 | NOT MAPPED in file format doc | MISSING — weather/track temp |
| `mTrackTemp` | 248 | NOT MAPPED in file format doc | MISSING |
| `mWind` | 252 | NOT MAPPED | MISSING |
| `mOnPathWetness` | 264 | NOT MAPPED | MISSING |
| `mOffPathWetness` | 268 | NOT MAPPED | MISSING |

### GraphicsInfo / GraphicsInfoV2 → Camera/View struct

| SDK Field | SDK Offset | F1C Context | Status |
|-----------|-----------|-------------|--------|
| `mCamPos` (TelemVect3 = 12 bytes) | 0 | FUN_00405440 (camera init), FUN_004057f0 (view init with FOV, near/far plane) | PARTIAL — F1C camera struct has FOV (0.04f), near plane (0.003f), far clip (0.5f), fog distance (40000.0f) |
| `mHWND` | 24 | FUN_004057f0 | PARTIAL — window handle stored in view struct |

## Proposed Renames

| Current | Proposed | Evidence |
|---------|----------|----------|
| FUN_004f4270 — "The .svm/.hdv Vehicle File Parser" | `.hdv File Parser (HDVeh::Parse or VehiclePhysicsFile::Load)` | rFactor class name likely `VehiclePhysicsFile` or similar. Parses all HDV sections in a defined sequence. RTTI shows `PFData<>` template for each config param type. |
| FUN_004c3200 — ".veh File Parser" | `.veh File Parser (VehicleFile::Load or Setup::ParseVehicleFile)` | Source file `setup.cpp` per rFactor paths. Reads top-level vehicle definition. |
| FUN_004c18b0 — "Player Career Stats + Game Options Loader" | `PlayerFile::LoadGameOptions (PlrFile::ReadGameOptions)` | Matches rFactor `PlayerFile` class. Reads `[CAREERSEASON]`, `[PLAYERTRACKSTAT]`, and race option sections. |
| FUN_004c1e80 — "Game Options Writer (Save)" | `PlayerFile::SaveGameOptions (PlrFile::WriteGameOptions)` | Companion writer to FUN_004c18b0. |
| FUN_004c2420 — "Career Stats Writer" | `PlayerFile::WriteCareerStats` | Writes career season + track stat sections. |
| FUN_004b0540 — "PlayerFileInit" | `PlayerFile::InitFromData` | Post-load init with clamping, validation. |
| FUN_004b70b0 — "LoadVehicleEntries" | `DynMan::LoadVehicleEntries` | Matches rFactor `DynMan` class responsible for vehicle dynamics setup. |
| FUN_004b7300 — "GameDataFileIO" | `Game::SaveLoadGameData` | Save/load of game data, session time, team/type info. |
| FUN_004b8da0 — "ProcessDriverEntries" | `DynMan::ProcessDriverEntries` | Linked list driver entry processing. |
| FUN_004c6330 — "Scene File Filter Builder" | `MPFile::BuildSceneFilterList` | Matches rFactor `MPFile` class pattern. Category-based track selection filtering. |
| FUN_004f6300 — "Vehicle Setup File Parser" | `VehicleSetup::LoadFromFile (VehLoad::ParseSetup)` | Source path `vehload.cpp`. Reads setup sections [BASIC], per-wheel, gearing, balance, downforce. |
| FUN_004c6c40 — "vehgen.scn File Loader" | `SceneGen::LoadVehicleGenConfig (or Garage::SetupVehicleGen)` | Reads `vehgen.scn` to configure vehicle at track. |
| FUN_00460a10 — "terrain.ini Parser/Validator" | `TrackDB::ValidateTerrainConfig` | 5-check validation against expected track DB values (terrain type, surface, CRC, track name, path). |
| FUN_004c54f0 — ".AIW/.SCN Filename Builder" | `TrackDB::BuildTrackFilenames` | Builds .SCN and .AIW paths from track name. |
| FUN_004c0db0 — "Game Filter Data Loader" | `FilterManager::InitFromConfig` | Reads per-driver filter data, initializes game filter system. |
| FUN_0041f8a0 — "Constructor Championship Clinch Detection" | `Steward::CheckConstructorClinched` | Checks if any team has unbeatable constructor lead. |
| FUN_00413b60 — "Season-Specific Team ID Lookup" | `SeasonDB::GetTeamDisplayID` | Maps team index to season-specific display ID. |
| FUN_004c78f0 — "Nationality/Driver Info Loader" | `VehicleDB::LoadDriverNationality` | Reads nationality from file into vehicle struct. |
| FUN_004c6a10 — "Driver Abbreviation Name Formatter" | `SceneDisplay::FormatDriverAbbreviation` | Formats driver name as "M. Schumacher" for HUD/scene lists. |
| FUN_004b41e0 — "File Stream Writer" | `FileIO::WriteString` | Writes length-prefixed string to file stream. |
| FUN_004b4250 — "File Stream Reader" | `FileIO::ReadString` | Reads length-prefixed string from file stream. |
| FUN_004c3f80 — "Vehicle Lookup by Name" | `VehicleDB::FindByName` | Searches vehicle array for name match. |
| FUN_0045c240 — "File Scanner / Track Config Loader" | `Setup::ScanDataDirectory` | Scans directory for .gdb/.hdv/terrain.ini files. |
| FUN_0058c43c — "File Open Mode Parser" | `SmartFile::ParseOpenMode` | rFactor `SmartFile` class file mode parsing. |
| FUN_00551560 — "Config Tree Allocator/Copier" | `BasePF::AllocConfigNode` | rFactor `BasePF` base class for parameter system. |
| FUN_005518a0 — "Config Tree Leaf Insertion" | `BasePF::InsertLeafNode` | Tree-based config hierarchy builder. |
| FUN_00559e20 / FUN_00565520 — "Config Key-Value Parser" | `PFString::ParseKeyValue` | Key=value config parser matching rFactor PFString. |
