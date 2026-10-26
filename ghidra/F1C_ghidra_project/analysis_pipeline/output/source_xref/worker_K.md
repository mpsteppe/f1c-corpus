# Source Cross-Reference: docs/10-vehicle-physics.md

## RTTI Class Mappings

| rFactor Class | F1C Function(s) | Confidence | Evidence |
|--------------|-----------------|------------|----------|
| `DynMan` | FUN_00439210 (Vehicle Physics Initializer), FUN_00438da0 (Body Name Mapping), FUN_00443c07 (Speed Limiter), FUN_00443f71 (Target Speed Blending), FUN_004e5f60 (SuspensionAndWheelPhysics) | HIGH | rFactor Dedicated.exe RTTI has `.?AVDynMan@@` (line 557). Doc sources cite `hdvehicle.cpp` which dev tree (line 23-25) maps to `D:\dev\F1_1999_2002\Source\`. rFactor source paths (line 125) also confirm `..\Source\dynman.cpp`. These functions manage vehicle dynamics — core DynMan responsibility. |
| `HDVehicle` | FUN_00439210, FUN_0043da10 (Tire Compound Apply), FUN_0043b040 (Steering Setup), FUN_0043b590 (Steering Geometry), FUN_00435410 (Suspension Setup Reader) | HIGH | rFactor source paths (line 424) and dev tree (line 24) confirm `hdvehicle.cpp` as source. Function descriptions cite `hdvehicle.cpp` explicitly. RTTI class name string `HDVehicle` found in crossref strings (line 895). |
| `Steward` | FUN_00438690 (Collision Damage & DNF) | MEDIUM | Damage/DNF detection is steward function. rFactor source (line 131) confirms `..\Source\steward.cpp`. But doc source says "physics_damage.cpp" — may be separate module that evolved into Steward in rFactor. |
| `Weather` | FUN_00449a80 (HAT Polygon Surface Fit) | LOW | HAT terrain generation is related to track/weather systems, but rFactor's Weather class (line 679) handles weather conditions, not terrain mesh. Likely separate module. |
| `LooseObject` / `LooseWheel` / `LooseWing` / `LoosePart` | FUN_004ec1a0 (Collision/Spark/Particle Effects) | MEDIUM | Particle/spark effects from collisions — loose parts would use this. rFactor RTTI (lines 502-508) confirms these as separate classes. F1C likely has equivalent structs. |
| `Options_SpinBox` | FUN_00447d00 (Brake Bias Adjustment) | MEDIUM | Brake bias HUD control uses display formatting consistent with options UI pattern. rFactor RTTI line 601 confirms `Options_SpinBox` class. |
| `Options_SliderBar` | FUN_0042f470 (Setup Value Formatter) | MEDIUM | Setup value formatting dispatches display types — consistent with slider bar formatting. rFactor RTTI line 610 confirms `Options_SliderBar`. |
| `Options_MenuItemText` | FUN_0042f2f0 (Setup Value Format Dispatcher), FUN_0042f260, FUN_00431aa0 (Setup Date/Angle Display) | MEDIUM | Setup UI display formatting functions. rFactor RTTI line 593 confirms `Options_MenuItemText`. |
| `PFController` | FUN_00451720 (Driver Input Controller) | HIGH | `PFController` (line 574) handles all driver input processing — exactly what FUN_00451720 does. Maps AI/human inputs to throttle/brake/steering/clutch. |
| `HWInput` | FUN_0046a9c0 (Controller Shifter Mapping) | HIGH | `HWInput` (line 580) maps hardware controller inputs to game actions. FUN_0046a9c0 maps controller actions to shift commands via global action arrays. |
| `Controller` | FUN_0046a9c0 | MEDIUM | `Controller` class (line 579) wraps HWInput. Controller shifter mapping falls under both. |
| `GameComponent` | FUN_0049d070 (Steering Wheel Animation), FUN_0049d280 (Wheel Rotation Animation) | MEDIUM | `GameComponent` (line 492) is base class for game objects. Wheel animation functions likely inherit from it. |
| `Render` | FUN_004b3ba0 (IterateVehicles) | MEDIUM | Vehicle iteration for rendering. rFactor RTTI (line 572) confirms `Render` class. FUN_004b3ba0 loops vehicles calling FUN_004c77d0 (render dispatch). |
| `ReplayMan` | FUN_004e0800 (VehicleRespawnReset) | MEDIUM | Respawn/reset often involves replay state management. rFactor RTTI line 535 confirms `ReplayMan`. |
| `SoundMan` | FUN_0049e4e0 (Audio/Effect Trigger), FUN_004efae0 (TireScrubReset) | MEDIUM | Audio trigger and scrub reset use sound system. rFactor RTTI line 670 confirms `SoundMan`. |
| `PitMan` | FUN_0042ad50 (Fuel/Weight Limit Check) | MEDIUM | Fuel weight check during pit stops. rFactor RTTI line 677 confirms `PitMan`. |
| `PuppetMaster` | FUN_004e5f60 (SuspensionAndWheelPhysics) — collision offset adjustment | LOW | Collision offset handling in physics integration could relate to PuppetMaster (line 678) for remote vehicle physics blending. Low confidence — speculative. |
| `SpecialFX` | FUN_004ec1a0 (Collision/Spark/Particle Effects) | MEDIUM | Visual effects triggered by collisions. rFactor RTTI line 573 confirms `SpecialFX`. |
| `VidMan` | FUN_004dfce0 (Vehicle Graphics Scene Loader) | LOW | Graphics scene loading — rFactor RTTI line 571 confirms `VidMan`. But doc says `vehgf.cpp` not `vidman.cpp`. |
| `TvOverlayPageRaceHUD` | FUN_00430f00 (Vehicle Stats Estimation Display) | LOW | Stats estimation display appears in HUD/tuning screen. rFactor RTTI line 638 confirms overlay class. Low confidence. |
| `InternalsPlugin` | FUN_004b5c50 (Vehicle Instance List Builder) | LOW | Instance list building for plugin access. rFactor TrackIRPlugin.dll RTTI line 1256 confirms `InternalsPlugin`. Low confidence — generic utility. |
| `TireManager` | FUN_004f34e0 (Tire Model Data Init), FUN_0043da10 (Tire Compound Apply), FUN_004f1630 (Tire Name Accessor) | HIGH | rFactor source path line 748 confirms `..\Source\tire_manager.cpp`. Dev tree (line 25) confirms `tire_manager.cpp` in F1C source tree. Tire compound, model init, and name access are all tire_manager responsibilities. |

## Parameter-to-Offset Mappings

| Config Param | Section | F1C Struct Offset | Current Name | Proposed Name | Confidence |
|-------------|---------|-------------------|--------------|---------------|------------|
| `BumpTravel` | FRONTLEFT | +0x00 per wheel (FUN_004f2c60) | BumpTravel | BumpTravel | HIGH — exact match from .hdv section field name |
| `ReboundTravel` | FRONTLEFT | +0x08 per wheel | ReboundTravel | ReboundTravel | HIGH |
| `BrakeTorque` | FRONTLEFT | +0xb0 per wheel | BrakeTorque | BrakeTorque | HIGH |
| `BrakeOptimumTemp` | FRONTLEFT | +0xb8 | BrakeOptimumTemp | BrakeOptimumTemp | HIGH — doc notes +273.15 K offset at load |
| `BrakeWearRate` | FRONTLEFT | +0xf0 | BrakeWearRate | BrakeWearRate | HIGH |
| `BrakeFailure` | FRONTLEFT | +0xf8/+0x100 | BrakeFailure (min/max) | BrakeFailure | HIGH — two doubles: avg, variance |
| `BrakeDiscRange` | FRONTLEFT | per wheel | BrakeDiscRange | BrakeDiscRange | HIGH |
| `BrakePadRange` | FRONTLEFT | per wheel | BrakePadRange | BrakePadRange | HIGH |
| `BrakeDiscInertia` | FRONTLEFT | per wheel | — | BrakeDiscInertia | HIGH — .hdv has this at same section |
| `BrakeResponseCurve` | FRONTLEFT | per wheel | — | BrakeResponseCurve | HIGH |
| `BrakeHeating` | FRONTLEFT | per wheel | — | BrakeHeating | HIGH |
| `BrakeCooling` | FRONTLEFT | per wheel | — | BrakeCooling | HIGH |
| `BrakeDuctCooling` | FRONTLEFT | per wheel | — | BrakeDuctCooling | HIGH |
| `BrakeGlow` | FRONTLEFT | per wheel | — | BrakeGlow | HIGH |
| `CamberRange` | FRONTLEFT | +0x?? per wheel | — | CamberRange | HIGH — standard setup field |
| `CamberSetting` | FRONTLEFT | +0x104 per wheel (stride 0x2c0, FUN_0042fd00) | CamberSetting | CamberSetting | HIGH |
| `PressureRange` | FRONTLEFT | per wheel | — | PressureRange | HIGH |
| `PressureSetting` | FRONTLEFT | per wheel | — | PressureSetting | HIGH |
| `PackerRange` | FRONTLEFT | per wheel | — | PackerRange | HIGH |
| `PackerSetting` | FRONTLEFT | per wheel | — | PackerSetting | HIGH |
| `SpringRange` | FRONTLEFT | per wheel | — | SpringRange | HIGH |
| `SpringSetting` | FRONTLEFT | +0x1c4 per wheel | SpringSetting | SpringSetting | HIGH |
| `RideHeightRange` | FRONTLEFT | per wheel | — | RideHeightRange | HIGH |
| `RideHeightSetting` | FRONTLEFT | +0x144 per wheel | RideHeightSetting | RideHeightSetting | HIGH |
| `SlowBumpRange` | FRONTLEFT | per wheel | — | SlowBumpRange | HIGH |
| `SlowBumpSetting` | FRONTLEFT | +0x204 per wheel | SlowBumpSetting | SlowBumpSetting | HIGH |
| `FastBumpRange` | FRONTLEFT | per wheel | — | FastBumpRange | HIGH |
| `FastBumpSetting` | FRONTLEFT | +0x244 per wheel | FastBumpSetting | FastBumpSetting | HIGH |
| `SlowReboundRange` | FRONTLEFT | per wheel | — | SlowReboundRange | HIGH |
| `SlowReboundSetting` | FRONTLEFT | +0x284 per wheel | SlowReboundSetting | SlowReboundSetting | HIGH |
| `FastReboundRange` | FRONTLEFT | per wheel | — | FastReboundRange | HIGH |
| `FastReboundSetting` | FRONTLEFT | +0x2c4 per wheel | FastReboundSetting | FastReboundSetting | HIGH |
| `BumpStopSpring` | FRONTLEFT | per wheel | BumpStopSpring | BumpStopSpring | HIGH |
| `BumpStopRisingSpring` | FRONTLEFT | per wheel | BumpStopRisingSpring | BumpStopRisingSpring | HIGH |
| `BumpStopDamper` | FRONTLEFT | per wheel | BumpStopDamper | BumpStopDamper | HIGH |
| `BumpStopRisingDamper` | FRONTLEFT | per wheel | BumpStopRisingDamper | BumpStopRisingDamper | HIGH |
| `BumpStage2` | FRONTLEFT | per wheel | BumpStage2 | BumpStage2 | HIGH |
| `ReboundStage2` | FRONTLEFT | per wheel | ReboundStage2 | ReboundStage2 | HIGH |
| `FrictionTorque` | FRONTLEFT | per wheel | — | FrictionTorque | HIGH |
| `SpinInertia` | FRONTLEFT | per wheel | — | SpinInertia | HIGH |
| `CGOffsetX` | FRONTLEFT | per wheel | — | CGOffsetX | HIGH |
| `PushrodSpindle` | FRONTLEFT | per wheel | — | PushrodSpindle | HIGH |
| `PushrodBody` | FRONTLEFT | per wheel | — | PushrodBody | HIGH |
| `SpringRubberRange` | FRONTLEFT | per wheel | — | SpringRubberRange | HIGH |
| `SpringRubberSetting` | FRONTLEFT | per wheel | — | SpringRubberSetting | HIGH |
| `DamperMult` | FRONTLEFT | per wheel | — | DamperMult | HIGH |
| `SpringMult` | FRONTLEFT | per wheel | — | SpringMult | HIGH |
| `CGHeight` | GENERAL | param_1+0x1720 | CGHeight | CGHeight | HIGH — .hdv line 51 |
| `CGRightRange` | GENERAL | param_1+? | — | CGRightRange | HIGH — .hdv line 52 |
| `CGRearRange` | GENERAL | param_1+? | — | CGRearRange | HIGH — .hdv line 54 |
| `Mass` | GENERAL | +0x15f4 (FUN_00439210) | total mass | Mass | HIGH |
| `Inertia` | GENERAL | +0xbc-0xcc per body | inertia diagonal | Inertia | HIGH — physics body struct |
| `FuelTankPos` | GENERAL | +0x1d4 (FUN_00438da0) | fuel_tank | FuelTankPos | HIGH |
| `FuelRange` | GENERAL | +0xcc4 | FuelSetting | FuelSetting | HIGH |
| `FuelSetting` | GENERAL | +0xcc4 | FuelSetting | FuelSetting | HIGH |
| `NumPitstopsRange` | GENERAL | +0x1884 | NumPitstopsSetting | NumPitstopsSetting | HIGH |
| `WedgeSetting` | GENERAL | +0xc84 | WedgeSetting | WedgeSetting | HIGH |
| `TireBrand` | GENERAL | +0x? | — | TireBrand | HIGH — .hdv line 72 |
| `FrontTireCompoundSetting` | GENERAL | +0xbc4 | TireCompoundSetting | FrontTireCompoundSetting | HIGH — .hdv line 73 |
| `FeelerFrontLeft` | GENERAL | per feeler (FUN_004ea970) | — | FeelerFrontLeft | HIGH — .hdv line 103 |
| `FeelerFrontRight` | GENERAL | per feeler | — | FeelerFrontRight | HIGH |
| `FeelerRearLeft` | GENERAL | per feeler | — | FeelerRearLeft | HIGH |
| `FeelerRearRight` | GENERAL | per feeler | — | FeelerRearRight | HIGH |
| `FeelerFront` | GENERAL | per feeler | — | FeelerFront | HIGH |
| `FeelerRear` | GENERAL | per feeler | — | FeelerRear | HIGH |
| `FeelerLeft` | GENERAL | per feeler | — | FeelerLeft | HIGH |
| `FeelerRight` | GENERAL | per feeler | — | FeelerRight | HIGH |
| `FeelerTopFrontLeft` | GENERAL | per feeler | — | FeelerTopFrontLeft | HIGH |
| `FeelerTopFrontRight` | GENERAL | per feeler | — | FeelerTopFrontRight | HIGH |
| `FeelerTopRearLeft` | GENERAL | per feeler | — | FeelerTopRearLeft | HIGH |
| `FeelerTopRearRight` | GENERAL | per feeler | — | FeelerTopRearRight | HIGH |
| `FeelerBottom` | GENERAL | per feeler | — | FeelerBottom | HIGH |
| `FeelerFlags` | GENERAL | param_1? | — | FeelerFlags | HIGH |
| `FeelersAtCGHeight` | GENERAL | param_1? | — | FeelersAtCGHeight | HIGH |
| `AIAimSpeedsPerWP` | GENERAL | (AI struct) | — | AIAimSpeedsPerWP | HIGH — .hdv line 85 |
| `AISlipReaction` | GENERAL | (AI struct) | — | AISlipReaction | HIGH |
| `AICornerReductionBase` | GENERAL | (AI struct) | — | AICornerReductionBase | HIGH |
| `AIMinPassesPerTick` | GENERAL | (AI struct) | — | AIMinPassesPerTick | HIGH |
| `AIRotationThreshold` | GENERAL | (AI struct) | — | AIRotationThreshold | HIGH |
| `AIEvenSuspension` | GENERAL | (AI struct) | — | AIEvenSuspension | HIGH |
| `AISpringRate` | GENERAL | (AI struct) | — | AISpringRate | HIGH |
| `AIDamperSlow` | GENERAL | (AI struct) | — | AIDamperSlow | HIGH |
| `AIDamperFast` | GENERAL | (AI struct) | — | AIDamperFast | HIGH |
| `FWSetting` | FRONTWING | +0x1284 | FWSetting | FWSetting | HIGH |
| `FWRange` | FRONTWING | (setup struct) | — | FWRange | HIGH |
| `FWDragParams` | FRONTWING | — | — | FWDragParams | HIGH |
| `FWLiftParams` | FRONTWING | — | — | FWLiftParams | HIGH |
| `RWSetting` | REARWING | +0x12c4 | RWSetting | RWSetting | HIGH |
| `RadiatorSetting` | BODYAERO | +0x1304 | RadiatorSetting | RadiatorSetting | HIGH |
| `BrakeDuctSetting` | BODYAERO | +0x1344 | BrakeDuctSetting | BrakeDuctSetting | HIGH |
| `BodyDragBase` | BODYAERO | — | — | BodyDragBase | HIGH |
| `BodyDragHeightAvg` | BODYAERO | — | — | BodyDragHeightAvg | HIGH |
| `BodyDragHeightDiff` | BODYAERO | — | — | BodyDragHeightDiff | HIGH |
| `BodyCenter` | BODYAERO | — | — | BodyCenter | HIGH |
| `BodyFore` | BODYAERO | — | — | BodyFore | HIGH |
| `BodyRot` | BODYAERO | — | — | BodyRot | HIGH |
| `DiffuserBase` | DIFFUSER | — | — | DiffuserBase | HIGH |
| `DiffuserCenter` | DIFFUSER | — | — | DiffuserCenter | HIGH |
| `DiffuserRake` | DIFFUSER | — | — | DiffuserRake | HIGH |
| `SteerLockSetting` | CONTROLS | +0x1444 | SteerLockSetting | SteerLockSetting | HIGH — FUN_0042fd00 |
| `RearBrakeSetting` | CONTROLS | +0x1384 | RearBrakeSetting | RearBrakeSetting | HIGH |
| `BrakePressureSetting` | CONTROLS | +0x13c4 | BrakePressureSetting | BrakePressureSetting | HIGH |
| `RevLimitSetting` | ENGINE | +0x1584 | RevLimitSetting | RevLimitSetting | HIGH |
| `EngineMapSetting` | ENGINE | +0x15c4 | EngineMapSetting | EngineMapSetting | HIGH |
| `EngineBrakeMapSetting` | ENGINE | +0x1604 | EngineBrakeMapSetting | EngineBrakeMapSetting | HIGH |
| `FinalDriveSetting` | DRIVELINE | +0x1644 | FinalDriveSetting | FinalDriveSetting | HIGH |
| `ReverseSetting` | DRIVELINE | +0x1684 | ReverseSetting | ReverseSetting | HIGH |
| `DiffPumpSetting` | DRIVELINE | +0x1484 | DiffPumpSetting | DiffPumpSetting | HIGH |
| `DiffPowerSetting` | DRIVELINE | +0x14c4 | DiffPowerSetting | DiffPowerSetting | HIGH |
| `DiffCoastSetting` | DRIVELINE | +0x1504 | DiffCoastSetting | DiffCoastSetting | HIGH |
| `DiffPreloadSetting` | DRIVELINE | +0x1544 | DiffPreloadSetting | DiffPreloadSetting | HIGH |
| `ForwardGears` | DRIVELINE | param_2+0x? | — | ForwardGears | HIGH |
| `WheelDrive` | DRIVELINE | param_2+0x? | — | WheelDrive | HIGH — enum REAR/FOUR/FRONT |
| `GearFile` | DRIVELINE | — | — | GearFile | HIGH |
| `ClutchEngageRate` | DRIVELINE | — | — | ClutchEngageRate | HIGH |
| `ClutchTorque` | DRIVELINE | — | — | ClutchTorque | HIGH |
| `ClutchInertia` | DRIVELINE | — | — | ClutchInertia | HIGH |
| `DownshiftDelay` | DRIVELINE | — | — | DownshiftDelay | HIGH |
| `UpshiftDelay` | DRIVELINE | — | — | UpshiftDelay | HIGH |
| `AllowGearingChanges` | DRIVELINE | — | — | AllowGearingChanges | HIGH |
| `AllowFinalDriveChanges` | DRIVELINE | — | — | AllowFinalDriveChanges | HIGH |
| `FenderCenter` | LEFTFENDER | +0x3c-0x4c (FUN_004f3090) | Center position | FenderCenter | HIGH |
| `FenderDragParams` | LEFTFENDER | +0x04-0x14 | Drag params | FenderDragParams | HIGH |
| `FenderLiftParams` | LEFTFENDER | +0x1c-0x2c | Lift params | FenderLiftParams | HIGH |
| `FenderSideways` | LEFTFENDER | +0x34 | Sideways coefficient | FenderSideways | HIGH |
| `FenderFlareSetting` | LEFTFENDER | +0xe04/+0xe44 | FenderFlareSetting | FenderFlareSetting | HIGH |
| `FrontAntiSwaySetting` | SUSPENSION | +0xd04 | AntiSway front | FrontAntiSwaySetting | HIGH |
| `RearAntiSwaySetting` | SUSPENSION | +0xd44 | AntiSway rear | RearAntiSwaySetting | HIGH |
| `FrontToeInSetting` | SUSPENSION | +0xd84 | ToeIn front | FrontToeInSetting | HIGH |
| `RearToeInSetting` | SUSPENSION | +0xdc4 | ToeIn rear | RearToeInSetting | HIGH |
| `LeftCasterSetting` | SUSPENSION | +0xe84 | Caster left | LeftCasterSetting | HIGH |
| `RightCasterSetting` | SUSPENSION | +0xec4 | Caster right | RightCasterSetting | HIGH |
| `LeftTrackBarSetting` | SUSPENSION | +0xf04 | TrackBar left | LeftTrackBarSetting | HIGH |
| `RightTrackBarSetting` | SUSPENSION | +0xf44 | TrackBar right | RightTrackBarSetting | HIGH |
| `Front3rdSpringSetting` | SUSPENSION | +0xf84 | 3rd spring front | Front3rdSpringSetting | HIGH |
| `Rear3rdSpringSetting` | SUSPENSION | +0x1084 | 3rd spring rear | Rear3rdSpringSetting | HIGH |
| `Front3rdPackerSetting` | SUSPENSION | +0xfc4 | packer front | Front3rdPackerSetting | HIGH |
| `Rear3rdPackerSetting` | SUSPENSION | +0x10c4 | packer rear | Rear3rdPackerSetting | HIGH |
| `Front3rdSlowBumpSetting` | SUSPENSION | +0x1004 | slow bump front | Front3rdSlowBumpSetting | HIGH |
| `Rear3rdSlowBumpSetting` | SUSPENSION | +0x1104 | slow bump rear | Rear3rdSlowBumpSetting | HIGH |
| `Front3rdFastBumpSetting` | SUSPENSION | +0x1044 | fast bump front | Front3rdFastBumpSetting | HIGH |
| `Rear3rdFastBumpSetting` | SUSPENSION | +0x1144 | fast bump rear | Rear3rdFastBumpSetting | HIGH |
| `Front3rdSlowReboundSetting` | SUSPENSION | +0x1084+? | slow rebound front | Front3rdSlowReboundSetting | HIGH |
| `Rear3rdSlowReboundSetting` | SUSPENSION | +0x1184? | slow rebound rear | Rear3rdSlowReboundSetting | HIGH |
| `Front3rdFastReboundSetting` | SUSPENSION | +0x10c4? | fast rebound front | Front3rdFastReboundSetting | HIGH |
| `Rear3rdFastReboundSetting` | SUSPENSION | +0x11c4? | fast rebound rear | Rear3rdFastReboundSetting | HIGH |
| `AdjustSuspRates` | SUSPENSION | — | — | AdjustSuspRates | HIGH — .hdv line 269 |
| `AlignWheels` | SUSPENSION | — | — | AlignWheels | HIGH |
| `ApplySlowToFastDampers` | SUSPENSION | — | — | ApplySlowToFastDampers | HIGH |
| `PhysicalModelFile` | SUSPENSION | — | — | PhysicalModelFile | HIGH — .pm file ref |
| `AIDifficultySlider` | — | — | AIDifficultySlider (global) | — | — (global reference) |

## String Matches

| String | Found In | F1C Function | Insight |
|--------|----------|-------------|---------|
| `Gaussian elimination for HAT poly failed once` | F1C (unique to doc) | FUN_00449a80 | Uniquely identifies HAT terrain surface fitting. Not shared with NASCAR/rFactor binaries — confirms HTree is F1C-specific. |
| `"Failed to open %s for writing"` | F1C (setup writer) | FUN_0042fd00 | Standard file I/O error shared across all ISI games. |
| `"Unknown [name]"` | F1C (setup formatter) | FUN_0042f470 | Setup UI display string, shared pattern across ISI options UI. |
| `"Sorry, only support independent 5-link front suspensions right now"` | F1C (assert) | FUN_0043b040 | F1C-specific assert. Not found in NASCAR/rFactor crossref — confirms NASCAR used solid axle front suspension. |
| `"BRAKE BIAS %4.1f:%4.1f"` | F1C (HUD) | FUN_00447d00 | Format string shared with NASCAR 2003 (line 115-166 shows APP_SpinBox_Garage_BrakeBalance). UI pattern consistent across ISI games. |
| `"Settings"` / `"SettingsCopy"` | F1C | FUN_00432180, FUN_00432220 | Setup file naming convention. "SettingsCopy" string not found in NASCAR crossref — may be F1C-specific. |
| `"Failed to open"` | All ISI binaries | FUN_0042fd00 | Standard error format throughout ISI codebase. |
| `*.hdv file references unknown tire compound` | NASCAR 2003 (line 116) | FUN_004f34e0 | Tire compound loading validation. Confirms .hdv->.tbc reference chain. NASCAR 2003 line 116: `*.hdv file references unknown tire compound "%s"`. |
| `D:\Dev\AudioDev\Shared\Engine\Dev\LbMpeg.cpp` | NASCAR 2003 (line 110) | — | Audio engine shared across all ISI games. F1C uses same codec layer. |
| `D:\Dev\Common\Source\` shared files | dev_tree (line 11-18) | Many | 25 shared isiMotor1 source files including `hdvehicle.cpp`, `vehicle.cpp`, `pitcrew.cpp`. Confirms F1C shares core with F1 2002 Demo. |
| `D:\dev\F1_1999_2002\Source\` | dev_tree (line 23) | All vehicle physics | Root source path for F1C. Confirms 31 files including `hdvehicle.cpp`, `config.cpp`, `weather.cpp`, `f1sounds.cpp`. |
| `HDVehicle` string | rFactor (line 895) | FUN_00439210 | Class/component name matches the HDVehicle module. dev_tree line 24 confirms `hdvehicle.cpp` in F1C source tree. |
| `..\Source\hdvehicle.cpp` | rFactor (lines 424, 747, 1009) | Multiple | Source path confirmed across 3 rFactor binaries. F1C dev_tree line 24 confirms `D:\dev\F1_1999_2002\Source\hdvehicle.cpp`. |
| `..\Source\tire_manager.cpp` | rFactor (lines 155, 748) | FUN_004f34e0 | Tire management source confirmed in rFactor and F1C dev tree. |
| `VehicleWidth` | rFactor (line 255) | — | Parameter name for drafting calculation. .hdv line 248. |
| `FeelerFlags` | rFactor (line 100) | FUN_004ea970 | Collision feeler configuration. .hdv line 100. |
| `PitstopDescription` | rFactor (lines 191, 788) | — | Pit stop UI description. Not documented in F1C but appears in rFactor. |
| `HeadPhysics` | rFactor (lines 205-207, 803) | — | Head physics multiplier. Not documented in F1C physics doc. |
| `FormationAndStart` | rFactor RTTI (line 543) | — | rFactor has full enum type `W4FormationAndStart`. F1C has similar enum at `DAT_007cebc4`. |

## SDK Struct Alignment

Comparing rFactor SDK structs (InternalsPlugin.hpp) against F1C vehicle struct offsets documented in docs/10-vehicle-physics.md.

### TelemWheel (SDK) vs F1C Per-Wheel Physics Struct

| SDK Field | SDK Offset | F1C Offset | Status |
|-----------|-----------|------------|--------|
| mRotation (rad/s) | +0x00 | +0x? | MISMATCH — SDK telemetry struct differs from internal physics wheel struct. Internal struct starts with BumpTravel (double at +0x00) not rotation. |
| mSuspensionDeflection | +0x04 | +0x1e38 (FUN_0043f7f0) | MATCH — named WheelDeflection in F1C. Different struct layout though. |
| mRideHeight | +0x08 | +0x11 (wheel float array, FUN_004e3d00) | MATCH — rideHeight field exists at float offset +0x11 (44 bytes) in wheel float array. |
| mTireLoad (Newtons) | +0x0c | +0x? (tire load per wheel) | NOT FOUND — but FUN_004e5f60 computes tire loads per corner. |
| mLateralForce | +0x10 | +0x70 per wheel (FUN_00401340) | MATCH — lateralForce at +0x70 in wheel struct (stride 0x13c). |
| mGripFract | +0x14 | +0x? | NOT FOUND — grip fraction not explicitly named in doc. |
| mBrakeTemp (Celsius) | +0x18 | +0xb8 (FUN_004f2c60) | MATCH — BrakeTorque/optimum temp area. F1C stores in Kelvin (+273.15). |
| mPressure (kPa) | +0x1c | per wheel PressureSetting | MATCH — tyre pressure parameter. |
| mTemperature[3] | +0x20 | +0x334 (FUN_0043da10) | PARTIAL — optimum temp at +0x334. Three-layer temp not documented. |
| mWear (V2) | +0x30 | +0x3d64 (FUN_004ee150) | MATCH — tire wear accumulator at +0x3d64. |
| mTerrainName[16] (V2) | +0x34 | — | NOT FOUND — terrain name not in physics doc (likely loaded separately). |
| mSurfaceType (V2) | +0x44 | — | NOT FOUND — surface type handled by collision/track systems. |
| mFlat (V2) | +0x45 | — | NOT FOUND. |
| mDetached (V2) | +0x46 | +0x? (wheel struct has detached flag) | — |

### VehicleScoringInfo (SDK) vs F1C Vehicle Struct

| SDK Field | SDK Offset | F1C Offset | Status |
|-----------|-----------|------------|--------|
| mDriverName[32] | +0x00 | +0x4620 | MATCH — docs/10 references DriverName at +0x4620. |
| mVehicleName[64] | +0x20 | +0x4678 | MATCH — VehicleDescription at +0x4678. |
| mTotalLaps | +0x60 | — | NOT FOUND in 10-vehicle-physics.md |
| mFinishStatus | +0x64 | +0x4064 (FinishState) | MATCH — 0=running, 1=finished, 2=DNF, 3=DSQ |
| mLapDist | +0x68 | — | NOT FOUND |
| mBestSector1 | +0x74 | — | NOT FOUND |
| mBestLapTime | +0x7c | +0x409c (BestLapTime) | MATCH — float at +0x409c |
| mLastLapTime | +0x88 | — | NOT FOUND |
| mNumPitstops | +0x98 | +0x1162 (PitStopCount) | MATCH |
| mIsPlayer (V2) | +0xa0 | — | NOT FOUND |
| mPlace (V2) | +0xa5 | +0x4058 (QualifyingPosition) | PARTIAL — SDK uses 1-based unsigned char, F1C uses int at +0x4058 |
| mTimeBehindNext (V2) | +0xa8 | — | NOT FOUND |
| mTimeBehindLeader (V2) | +0xb0 | — | NOT FOUND |
| mPos (V2) | +0xbc | — | NOT FOUND |

### ScoringInfoV2 (SDK) vs F1C Globals

| SDK Field | SDK Size | F1C Equivalent | Status |
|-----------|----------|----------------|--------|
| mGamePhase | 1 byte | DAT_007c56a8 (RacePhase, 0-7) | MATCH — phases match SDK values 0-8 |
| mYellowFlagState | 1 byte | — | NOT FOUND in 10-vehicle-physics.md |
| mRaining | float | DAT_007cf080 (WeatherMode) | PARTIAL — weather mode global, not per-session float |
| mAmbientTemp | float | — | NOT FOUND |
| mTrackTemp | float | — | NOT FOUND |
| mOnPathWetness | float | — | NOT FOUND |
| mOffPathWetness | float | — | NOT FOUND |

### Physics Body Struct (FUN_00439210) vs SDK Generic

| F1C Field | F1C Offset | SDK Equivalent | Status |
|-----------|-----------|----------------|--------|
| position (x,y,z) | +0x04 (body struct) | TelemInfoBase.mPos | MATCH — 3 doubles vs SDK 3 floats (precision difference) |
| orientation matrix (3×3) | +0x1c-0x5c | TelemInfoBase.mOriX/Y/Z | MATCH — 3×3 doubles vs SDK 3×3 floats |
| mass | +0xac | — | NO SDK equivalent (internal) |
| 1/mass | +0xb4 | — | NO SDK equivalent |
| inertia diagonal | +0xbc-0xcc | — | NO SDK equivalent |

### Key Structural Differences

1. **SDK uses floats everywhere; F1C uses doubles internally.** F1C physics structs store all values as 8-byte doubles. SDK telemetry structs use 4-byte floats. This means struct layouts are fundamentally incompatible at binary level.

2. **SDK TelemWheel is compact (44 bytes for V1, 86 bytes for V2).** F1C per-wheel physics structs are much larger (stride 0x464 = 1124 bytes for one representation, 0x13c = 316 bytes for another). F1C internal structs contain intermediate solver state, Jacobians, and multiple backup copies.

3. **SDK structs are leaf output structs.** They provide read-only telemetry. F1C internal structs contain the full physics state including solver matrices, constraint data, and iterative solver workspace.

4. **VehicleScoringInfoV2.**mFinishStatus matches F1C FinishState at +0x4064. SDK uses signed char (0=none, 1=finished, 2=dnf, 3=dq). F1C uses int (0=running, 1=finished, 2=DNF, 3=DSQ). Semantically identical with extra "none" state in SDK.

## Proposed Renames

| Current | Proposed | Evidence |
|---------|----------|----------|
| FUN_00439210 — Vehicle Physics Initializer | HDVehicle::InitPhysics | Source hdvehicle.cpp. rFactor RTTI confirms HDVehicle class. Initializes all physics subsystems. |
| FUN_0043da10 — Tire Compound → Per-Wheel Physics | HDVehicle::ApplyTireCompound | Source hdvehicle.cpp. Tire compound application per wheel. |
| FUN_0043b040 — Front Steering Geometry Setup | HDVehicle::SetupSteering | Source hdvehicle.cpp. Steering link setup with 5-link assert. |
| FUN_00438da0 — Vehicle Physics Body Name Mapping | HDVehicle::MapBodyNames | Maps physics body names to struct offsets. |
| FUN_0043b590 — Steering Geometry Computation | HDVehicle::ComputeSteeringGeom | Computes Ackermann, scrub radius, steering axis. |
| FUN_00435410 — Suspension Setup Section Reader | HDVehicle::ReadSuspensionSetup | Reads suspension section from setup file. |
| FUN_004f2c60 — Per-Wheel Brake/Suspension Data Loader | HDVehicle::ReadWheelData | Loads brake/suspension block for one wheel corner. Called 4x by parent. |
| FUN_004f3090 — Fender/Aero Setup Section Reader | HDVehicle::ReadFenderAero | Reads fender flare aero setup per wheel. |
| FUN_004f3240 — Suspension Force Validation | HDVehicle::ValidateSuspensionForce | Validates suspension/damage force direction. |
| FUN_004326e0 — Player Name Setup | Options_MenuItemText::InitPlayerName | rFactor RTTI confirms Options_MenuItemText. Player name selection in garage UI. |
| FUN_00431db0 — Setup UI Init | Options_ScrollBox::InitSetupUI | rFactor RTTI line 616 confirms Options_ScrollBox. Setup loading/display UI. |
| FUN_0042fd00 — Vehicle Setup File Writer | Garage::SaveSetup | Source garage.cpp. Writes all setup parameters to text file. |
| FUN_0042f470 — Vehicle Setup Value Formatter | Options_MenuItemText::FormatSetupValue | Setup display formatting with 50+ cases. |
| FUN_00447d00 — Brake Bias Adjustment Control | Options_SpinBox::AdjustBrakeBias | HUD brake bias control with display. rFactor RTTI confirms Options_SpinBox. |
| FUN_00430f00 — Vehicle Stats Estimation Display | Options_TextValue::DisplayStats | Shows EST. ACCEL / TOP SPEED / CORNERING in garage. |
| FUN_004dfce0 — Vehicle Graphics Scene Loader | VehGFX::LoadScene | Source vehgf.cpp. Loads .gen vehicle scene file. NOT physics. |
| FUN_004f34e0 — Tire Model Data Init | TireManager::InitTireModel | Source tire_manager.cpp. Tire compound parameter initialization. |
| FUN_004f1630 — Tire Name Accessor | TireManager::GetTireName | Returns tire name string from compound data. |
| FUN_004e5f60 — SuspensionAndWheelPhysics | DynMan::IntegrateSuspension | Main suspension/wheel physics integration. Core DynMan responsibility. |
| FUN_0043f7f0 — Suspension/Wheel Dynamics Solver | DynMan::SolveWheelConstraints | Constraint-based suspension solver with semi-implicit Euler. |
| FUN_004e3d00 — Wheel Spring/Damper Force | DynMan::ComputeWheelForce | Spring/damper/steering force per wheel. |
| FUN_00401340 — Vehicle Suspension Force Calculation | DynMan::CalcSuspensionForces | World-space suspension force computation. |
| FUN_004ec1a0 — Collision/Spark/Particle Effects | SpecialFX::ProcessCollisionFX | Visual/audio feedback from impacts. rFactor RTTI confirms SpecialFX. |
| FUN_004ea970 — Collision Detection System | DynMan::DetectCollisions | 13-point collision detection with wheel overlap. |
| FUN_004ee150 — Engine Wear/Failure Simulation | HDVehicle::SimulateEngineWear | Only active when EngineWearMode 1 or 2. |
| FUN_00442060 — SteeringGeometryUpdate | DynMan::UpdateSteeringGeom | Updates steering/suspension geometry per corner. |
| FUN_00451720 — Driver Input Controller | PFController::ProcessInputs | rFactor RTTI line 574 confirms PFController. AI/human input dispatch. |
| FUN_0046a9c0 — Controller Shifter Mapping | HWInput::MapGearShift | rFactor RTTI line 580 confirms HWInput. Maps controller to shift commands. |
| FUN_004b6a10 — Vehicle Force/Aero Computation | DynMan::CalcAeroForces | Aerodynamic force computation in dynamics. |
| FUN_0049d070 — Steering Wheel Animation | GameComponent::AnimSteeringWheel | Steering wheel visual animation. |
| FUN_0049d280 — Wheel Rotation Animation | GameComponent::AnimWheelRotation | 4-wheel rotation animation. |
| FUN_0049e4e0 — Audio/Effect Trigger | SoundMan::TriggerEffect | Audio/effect dispatch. rFactor RTTI line 670 confirms SoundMan. |
| FUN_0045a8e0 — Vehicle Body Position Update | DynMan::UpdateBodyPosition | World position update with suspension travel check. |
| FUN_00458df0 — Object/Camera Target Positioning | CameraManager::PositionTarget | Follow camera positioning. rFactor RTTI line 495 confirms CameraManager. |
| FUN_0040b850 — Main View / Tracking Camera Scene Loader | CameraManager::LoadCameras | MAINVIEW/TRACKINGCAM scene loading. |
| FUN_00449a80 — HAT Polygon Surface Fit | HTree::FitSurfacePoly | Height Above Terrain surface fit. Source htree.cpp. |
| FUN_0044be70 — HTree Terrain File Format Loader | HTree::LoadTerrainFile | Compiled terrain height/vertex binary parser. |
