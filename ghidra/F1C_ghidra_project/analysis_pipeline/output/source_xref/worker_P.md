# Source Cross-Reference: docs/18-physics-dynamics.md

Processed by Worker P. Reference sources: rFactor binaries, config_params.txt (1034 params), string_crossref.txt (3100 lines), sdk_structs.txt (InternalsPlugin.hpp), dev_tree.txt (ISI evolution).

---

## RTTI Class Mappings

| rFactor Class | F1C Function(s) | Confidence | Evidence |
|--------------|-----------------|------------|----------|
| DynMan | FUN_00438130, FUN_00459ae0, FUN_004c73f0, FUN_0045e620, FUN_00441bb0, FUN_0043e5d0, FUN_0043ba20 | HIGH | DynMan is the dynamics manager — all rigid body force/torque integration functions match its role. F1C likely has an equivalent class (maybe CCarDyn or similar). These functions read/write vehicle body struct at +0x15f0, manage force accumulators at +0x1f04..+0x1f2c. |
| HDVehicle | FUN_004e49b0, FUN_004f1650, FUN_004e4790, FUN_004af3a0, FUN_004e4f40, FUN_004e2610 | HIGH | HDVehicle is the high-detail vehicle physics handler. Setup initialization, wheel state reset, suspension geometry init all match HDVehicle responsibilities. |
| Steward | FUN_00496030 (crash damage), FUN_00430a50 (brake temp) | MEDIUM | Steward manages penalties and race conditions. Crash damage processing relates to steward. Brake temperature with fade indirectly. |
| Weather | FUN_00404250 (surface heightfield collision) | MEDIUM | Weather manages track conditions. Surface friction and material blending in terrain collision callback. |
| PitMan | none directly | MEDIUM | PitMan not directly represented in physics dynamics — pit functions in docs/07. |
| LooseWheel / LoosePart | none directly — collision physics | MEDIUM | LooseObject family is in collision system (docs/17). |
| Render | FUN_005054ec (vertex shader palette), FUN_00504933 (texture resample), FUN_00459070 | HIGH | Render functions confirmed by Direct3D API calls and texture/vertex operations. |
| SoundMan | FUN_00448330 (Audio DSP) | HIGH | Audio DSP state update — references DAT_007cf2cc, calls FUN_0054c210 (active source count). |
| SpecialFX | FUN_00496030 (crash sparks/effects) | MEDIUM | Crash damage processing triggers effects via FUN_00498740 (sparks), FUN_00495dc0. |
| OnScreen | FUN_00495440 (FPS overlay) | MEDIUM | FPS overlay rendering matches OnScreen HUD display responsibility. |
| VidMan | FUN_004347c0 (engine guarded init) | MEDIUM | Engine init includes renderer/display init via FUN_0040d1b0. |
| Game | FUN_004347c0 (init guard), FUN_00434820 (module init) | MEDIUM | Game class orchestrates init sequence — checks DAT_005eb10c engine singleton. |
| Options | none directly | LOW | Options not represented in physics dynamics — settings UI in docs/05-onscreen. |
| Controller / HWInput | FUN_00425670 (steering angle controller), FUN_004e2760 (FFB output) | HIGH | Steering angle target computation and force feedback packing match Controller/HWInput class roles. |
| PFController | FUN_00425670 (steering state machine) | MEDIUM | PFController manages persistent config — steering controller reads state at +0x4510. |
| PlayerFile | none directly | LOW | Player file handling not in physics dynamics. |
| AIFollowTarget (not RTTI) | FUN_004e9ca0 (AI racing line path following) | MEDIUM | Path following waypoint node walking matches AI path follow logic. |
| ReplayMan | none directly | LOW | Replay not in physics dynamics. |
| PluginManager | none directly | LOW | Plugin system not in physics dynamics. |
| InternalsPlugin | none directly | MEDIUM | rFactor plugin API structs (TelemInfo, ScoringInfo) are useful for struct validation (see SDK section). |

## Parameter-to-Offset Mappings

| Config Param | Section | F1C Struct Offset | Current Name | Proposed Name | Confidence |
|-------------|---------|-------------------|--------------|---------------|------------|
| AdjustSuspRates | SUSPENSION | +0x1e14 | suspensionConfig | SuspMotionRatioMode | HIGH — controls 0/1/2 mode for motion ratio |
| BumpStopSpring | FRONTLEFT | +0x1e50 | anti-roll bar stiffness | BumpStopSpring | HIGH — bump stop spring constant in FUN_0043fffb |
| BumpStopDamper | FRONTLEFT | +0x1e20 | rebound damping factor | BumpStopDamper | HIGH — bump stop damping rate |
| BumpTravel | FRONTLEFT | +0x660 | maxTravel (per wheel) | BumpTravel | HIGH — suspension travel limit |
| BumpStage2 | FRONTLEFT | — | — | BumpStage2 | MEDIUM — damper bump-speed transition point |
| SpringRange / SpringSetting | FRONTLEFT | +0x360 | springForce | SpringStiffness | HIGH — per-wheel spring constant |
| DamperRange / DamperSetting | FRONTLEFT | +0x348 | damperForce | DamperRate | HIGH — per-wheel damper coefficient |
| BrakeTorque | FRONTLEFT | +0x39c8 | brake torque factor | BrakeTorque | HIGH — maximum brake torque at wheel |
| BrakeHeating | FRONTLEFT | — | — | BrakeHeating | MEDIUM — heat generation rate from braking |
| BrakeCooling | FRONTLEFT | — | — | BrakeCooling | MEDIUM — cooling coefficient |
| BrakeOptimumTemp | FRONTLEFT | +0x3cc0 | heat-fade table | BrakeOptimumTemp | HIGH — indexed by temperature (0-13) in FUN_004e94a3 |
| BrakeFadeRange | FRONTLEFT | +0x3cc0+idx | fade curve values | BrakeFadeRange | HIGH — temperature outlier half-grip point |
| BrakeDiscInertia | FRONTLEFT | — | — | BrakeDiscInertia | MEDIUM — inertia per meter disc thickness |
| BrakeDiscRange | FRONTLEFT | — | — | BrakeDiscRange | MEDIUM — disc thickness adjustment |
| CGHeight | GENERAL | +0x3504/+0x3508/+0x350c | chassis inertia | CGHeight | MEDIUM — offset stored near inertia values |
| CGRearRange | GENERAL | — | — | CGRearSetting | MEDIUM — fraction weight on rear |
| Mass | GENERAL | - | - | TotalMass | MEDIUM — vehicle mass (not in struct offsets shown) |
| Inertia | GENERAL | +0x3504-0x350c | chassis inertia values | Inertia | HIGH — 3-axis inertia tensor |
| FuelTankPos | GENERAL | — | — | FuelTankPos | MEDIUM — fuel CG offset |
| FuelTankMotion | GENERAL | — | — | FuelTankMotion | MEDIUM — fuel slosh spring/damper |
| BodyFore | BODYAERO | +0x34b0 (aero rot matrix) | aero forward force | BodyFore | HIGH — aero forward forces |
| BodyDown | BODYAERO | +0xa0 | front downforce | BodyDown | HIGH — downforce from downward motion |
| BodyCenter | BODYAERO | +0x94 | center of pressure | BodyCenter | HIGH — CoP offset from rear axle |
| BodyDragBase | BODYAERO | +0x90 | drag coefficient | BodyDragBase | HIGH — base aerodynamic drag |
| DiffPreloadRange | DRIVELINE | +0x39c8 | diff preload torque | DiffPreload | MEDIUM — preload for limited-slip diff |
| DiffPowerRange | DRIVELINE | +0x39c8 | power-side bias | DiffPowerRatio | MEDIUM — fraction torque to driven wheel |
| DiffCoastRange | DRIVELINE | — | — | DiffCoastRatio | MEDIUM — coast-side torque transfer |
| CamberRange / CamberSetting | FRONTLEFT | +0x84 | camber (rad) | Camber | HIGH — camber angle in FUN_004e2610 |
| CamberLatLong | COMPOUND | — | — | CamberLatGain | MEDIUM — lateral gain at peak camber |
| BrakePressureRange | CONTROLS | +0x39c8 | brake pressure scaling | BrakePressure | HIGH — max brake pressure setting |
| BrakePressureSetting | CONTROLS | +0x39f0 | control mode | BrakeMode | MEDIUM — 0=direct, 1=ABS-modulated |
| Damper | COMPOUND | +0x34a8 | wheel damping factor | TireDamper | HIGH — tire damping rate from .tbc file |
| AIGripMult | COMPOUND | — | — | AIGripMult | MEDIUM — AI tire grip multiplier |
| AIPeakSlip | COMPOUND | — | — | AIPeakSlip | MEDIUM — AI peak slip angle |
| AIWear | COMPOUND | — | — | AIWearRate | MEDIUM — AI tire wear constant |
| BrakingCurve | COMPOUND | — | — | BrakingSlipCurve | MEDIUM — longitudinal braking slip curve name |
| FuelRange / FuelSetting | GENERAL | — | — | FuelCapacity | MEDIUM — fuel load and pit strategy |
| FrontTireCompoundSetting | GENERAL | +0x39b4 | axle selection mode | TireCompoundIdx | MEDIUM — tire compound index |
| Rules | GENERAL | +0x39f0 | suspension mode | GarageRules | MEDIUM — garage setup rules (0=none, 1=stock car) |
| UndertrayParams | GENERAL | — | — | UndertraySpring/Damper/Friction | MEDIUM — undertray contact params |

## String Matches

| String | Found In | F1C Function | Insight |
|--------|----------|-------------|---------|
| `*.hdv file references unknown tire compound "%s"` | NASCAR_2003_Demo | tire compound loading | Confirms tire compound from .tbc referenced in .hdv |
| `AIDamperFast` | NASCAR_2003_Demo | AI physics helper | AI uses simplified damper in physics |
| `AIDamperSlow` | NASCAR_2003_Demo | AI physics helper | Same — slow damper for AI |
| `AIEvenSuspension` | NASCAR_2003_Demo | AI physics | Averages suspension rates |
| `AISpringRate` | NASCAR_2003_Demo | AI physics | AI spring rate multiplier |
| `D:\Dev\F1_1999_2002\Source\` | F1C | all functions | Confirms F1C source tree root |
| `..\Source\hdvehicle.cpp` | rFactor | FUN_004e49b0, FUN_004af3a0, etc | HDVehicle physics handler name confirmed across binaries |
| `..\Source\dynman.cpp` | rFactor | FUN_00438130, FUN_00459ae0 | Dynamics manager source file name |
| `..\Source\steward.cpp` | rFactor | PENALTY/SCORING | Steward manages race penalties |
| `..\Source\weather.cpp` | rFactor | SURFACE/TEMP | Weather/track condition functions |
| `Vehicle Collision` | rFactor | collision pipeline | Vehicle-to-vehicle collision system |
| `Launch control is not available on this vehicle` | rFactor | FUN_004c73f0 | Vehicle physics update checks launch control |
| `Disabling suspension deformation` | rFactor | FUN_004e4f40 | Suspension deformation disabled when no mesh LOD |
| `Pitstop Requested` | rFactor | unrelated | Pit logic (docs/07) |
| `HeadPhysics` | rFactor | FUN_004e9ca0? | Head movement physics — cockpit view pitch/roll |
| `FormationSpeedKPH` | rFactor | unrelated | Formation lap speed for AI |
| `FormationAndStart` | rFactor | unrelated | Formation type enum |
| `CUBE error loading scene file` | rFactor | renderer functions | CUBE rendering engine name |
| `Source map for render target %s CANNOT be a DXTn format` | rFactor | FUN_00504933 | Texture resampling in renderer |
| `VehicleWidth` | rFactor | unrelated | Vehicle width for collision feelers |
| `Force Formation` | rFactor | unrelated | Standing/rolling start type |
| `CountCautionLaps` | rFactor | unrelated | Caution lap counting |
| `FinishUnderCaution` | rFactor | unrelated | Finish-under-caution flag |
| `Vehicle has zero or negative inertia` | rFactor | FUN_004e49b0 | Inertia validation check |
| `VehicleFlowOffset` / `VehicleFlowRadius` | rFactor | unrelated | Smoke/dust flow for rendering |
| `TireBrand` | rFactor .hdv | FUN_004af3a0 | Tire compound brand name |
| `TireCompoundSetting` | rFactor .hdv | FUN_004af3a0 | Front/rear compound index |

## SDK Struct Alignment

### TelemWheel vs F1C wheel telemetry packing (FUN_00447f30)

| SDK Field | SDK Offset | F1C Offset | Status |
|-----------|-----------|------------|--------|
| mRotation | 0 (float) | telemetry[0x14] (float) | MATCH — wheel rotation speed |
| mSuspensionDeflection | 4 (float) | telemetry[0x15] (float) | MATCH — suspension travel |
| mRideHeight | 8 (float) | telemetry[0x16] (float) | MATCH — ride height |
| mTireLoad | 12 (float) | telemetry[0x17] (float) | MATCH — contact patch load |
| mLateralForce | 16 (float) | telemetry[0x18] (float) | MATCH — lateral force at contact |
| mGripFract | 20 (float) | telemetry[0x19] (float) | MATCH — grip fraction sliding |
| mBrakeTemp | 24 (float) | telemetry[0x1a] (float) | MATCH — brake disc temp |
| mPressure | 28 (float) | telemetry[0x1b] (float) | MATCH — tire pressure |
| mTemperature[3] | 32 (float[3]) | telemetry[0x1c-0x1e] (float[3]) | MATCH — 3 temperatures |

**Assessment:** F1C telemetry packing confirms 9 floats per wheel (0x14-0x4a = 9×4 = 36 bytes gap per wheel slot). Wheel telemetry structure is fully aligned with rFactor's TelemWheel v1 layout.

### TelemInfoBase vs F1C body telemetry (FUN_00447f30)

| SDK Field | SDK Offset | F1C Offset | Status |
|-----------|-----------|------------|--------|
| mDeltaTime | 0 (float) | — | MISSING — no time in F1C telemetry |
| mLapNumber | 4 (long) | — | MISSING |
| mLapStartET | 8 (float) | — | MISSING |
| mVehicleName | 12 (char[64]) | — | MISSING |
| mTrackName | 76 (char[64]) | — | MISSING |
| mPos | 140 (12 floats) | telemetry[0-2] (float[3]) | MATCH — body position from +0x2be |
| mLocalVel | 152 (12 floats) | telemetry[3-5] (float[3]) | MATCH — body velocity from +0x60 |
| mLocalAccel | 164 (12 floats) | — | MISSING (not in base telemetry) |
| mOriX/Y/Z | 176-208 (36 floats) | partial in +0x2be (6-DOF) | SHIFTED — F1C packs 6-DOF transform (24 bytes) |
| mLocalRot | 212 (12 floats) | telemetry[6-8] (float[3]) | MATCH — angular velocity |
| mGear | 236 (long) | telemetry[?] | MEDIUM — gear from FUN_004c73f0+0x105d |
| mEngineRPM | 240 (float) | — | MISSING in physics telemetry (docs/03-engine) |
| mSteeringArmForce | 272 (float) | steering wheel angle | PARTIAL — computed from rotation matrix |

**Assessment:** F1C telemetry struct is a compact subset of TelemInfoBase — body position, velocity, angular velocity, and orientation only. F1C predates the full rFactor telemetry API and uses a simpler format.

### VehicleScoringInfo vs F1C vehicle/scoring struct

| SDK Field | SDK Offset | F1C Offset | Status |
|-----------|-----------|------------|--------|
| mDriverName | 0 (char[32]) | +0x4620 | MATCH — DriverName |
| mVehicleName | 32 (char[64]) | +0x4678 | MATCH — VehicleDescription |
| mTotalLaps | 96 (short) | +0x?? | MISSING — scoring doc 06 |
| mFinishStatus | 99 (signed char) | +0x4064 | MATCH — FinishState (0=running, 1=finished, 2=DNF, 3=DSQ) |
| mBestLapTime | 112 (float) | +0x409c | MATCH — BestLapTime |
| mNumPitstops | 144 (short) | +0x1162 | MATCH — PitStopCount |
| mNumPenalties | 146 (short) | — | MISSING |

**Assessment:** VehicleScoringInfo matches F1C vehicle struct fields at +0x4620 (name), +0x4678 (vehicle), +0x4064 (finish state), +0x409c (best lap). Offsets are shifted because F1C uses a different layout (likely derived from earlier isiMotor 1.x format).

### Vehicle scoring V2 (FUN_00447f30, FUN_004e6d93)

| SDK Field V2 | SDK Offset | F1C Offset | Status |
|-------------|-----------|------------|--------|
| mIsPlayer | 0 (bool) | — | MISSING |
| mControl | 1 (signed char) | — | MISSING |
| mInPits | 2 (bool) | — | MISSING |
| mPlace | 3 (unsigned char) | +0x4060 | SHIFTED — FinishPosition |
| mVehicleClass | 4 (char[32]) | — | MISSING |
| mTimeBehindNext | 36 (float) | — | MISSING |
| mPos | 52 (12 floats) | +0x94/0x98/0x9c | MATCH — position offsets confirmed in doc overview |
| mLocalVel | 64 (12 floats) | +0xa0/0xa4/0xa8 | MATCH — velocity offsets confirmed |
| mLocalRot | 88 (12 floats) | +0xd8/0xe0/0xe8 | MATCH — angular velocity |

**Assessment:** F1C vehicle position at +0x94/+0xa0 matches V2 scoring info layout. F1C appears to use a struct closer to VehicleScoringInfoV2 but with different ordering and missing some scoring-only fields.

### TelemVect3 usage in F1C dynamics

| SDK Field | SDK Size | F1C Usage | Status |
|-----------|---------|-----------|--------|
| x | 4 (float) | +0x94 (pos_x), +0xa0 (vel_x), +0xd8 (angvel_x) | MATCH |
| y | 4 (float) | +0x98 (pos_y), +0xa4 (vel_y), +0xe0 (angvel_y) | MATCH |
| z | 4 (float) | +0x9c (pos_z), +0xa8 (vel_z), +0xe8 (angvel_z) | MATCH |

**Assessment:** TelemVect3 is the standard 3-float vector format used throughout F1C dynamics for position, velocity, and angular velocity. Confirmed at doc overview stride: position +0x94/0x98/0x9c, velocity +0xa0/0xa4/0xa8, angular velocity +0xd8/0xe0/0xe8.

### Dynamics body struct (from FUN_004359a0 body offsets)

| SDK/Concept | Expected | F1C Offset | Status |
|------------|---------|------------|--------|
| Position X | float | +0x4 | NEW (not in SDK telemetry) |
| Position Y | float | +0xc | NEW |
| Position Z | float | +0x14 | NEW |
| Rotation col0 | float[3] | +0x7c | NEW |
| Rotation col1 | float[3] | +0x84 | NEW |
| Rotation col2 | float[3] | +0x8c | NEW |
| Inertia row0 | float[3] | +0x6c | NEW |
| Inertia row1 | float[3] | +0x74 | NEW |
| Inertia row2 | float[3] | +0x64? (doc says +100) | SHIFTED |

**Assessment:** F1C's rigid body struct (stride 0x13c) is specific to its physics solver — not directly mapped to SDK structs. It has position, rotation matrix columns, and inertia tensor rows at offsets consistent with a hand-rolled isiMotor 1.x rigid body format.

### Collision/Constraint struct (from FUN_0056baf0, FUN_0056ee40)

| SDK/Concept | Expected | F1C Offset | Status |
|------------|---------|------------|--------|
| Constraint body count | — | +0x08 | NEW — F1C-specific |
| Constraint group arrays | — | +0x0c/+0x14/+0x1c | NEW |
| Body constraint axes (3) | — | +0x48/+0x50/+0x58 | NEW |
| Force accumulator X/Y/Z | — | +0x14c/+0x154/+0x15c | NEW |

**Assessment:** F1C uses a custom sparse constraint format with grouped bodies and per-axis constraint directions. Not present in rFactor SDK but functionally equivalent to constraint solving in the physics engine.

## Proposed Renames

| Current | Proposed | Evidence |
|---------|----------|----------|
| +0x4500-0x4580 fields | AI controller state (AI_FollowTarget, AI_State, etc.) | FUN_00425670 uses +0x4510 for steerState, +0x446c for headingTimer — matches AI steering from docs/02 |
| +0x34b0-0x34d0 | Rotation matrix (3x3 floats) | FUN_004e49b0 copies rotation matrix here; FUN_004e6d93 reads as local frame for wheel transforms |
| +0x34d4/0x34d8/0x34dc | BodyPosition (float xyz) | Updated by FUN_004f1650, read by FUN_004e3090 as position source |
| +0x34e0/0x34e4/0x34e8 | BodyOrientationAngles (yaw/pitch/roll) | Set from FUN_004f1650, used for atan2 extraction |
| +0x34f8/0x34fc/0x3500 | BodyVelocity (local space) | FUN_004e5ae0 reads for wheel dynamics; FUN_00425670 reads for AI steering |
| +0x3504/0x3508/0x350c | ChassisInertia (3-axis) | Set by FUN_004f1650 from param_6; read by FUN_004e6d93 for torque transforms |
| +0x354c/0x3550/0x3554 | ForceAccumulator (body torque) | Accumulated by FUN_004e5470, FUN_004e58d0 per axis |
| +0x39c8 | BrakeTorqueCoefficient | FUN_004e5ae0 multiplies brake torque inverse against this; the BrakeTorque config param |
| +0x39f0 | ControlMode | FUN_004e5ae0: 0=direct, 1=ABS-modulated. Maps to BrakePressureSetting |
| +0x3bf4 | DownforceMultiplier | FUN_004f18c0 multiplies front downforce by this |
| +0x3a64/0x3a68/0x3a6c/0x3a70/0x3a74 | WheelRateParameters | FUN_004e58d0 reads 5 floats at these offsets for inertia/scaling factors |
| +0x3cc0 | BrakeFadeTable (13 float entries) | FUN_004e94a3 indexes this by temperature |
| +0x15f0 | BodyPtr (rigid body struct pointer) | Consistent across FUN_004e6d93, FUN_004e58d0, FUN_00441bb0, FUN_0043e5d0 |
| +0x141c | ContactDataPtr | Used by FUN_0043fffb to access wheel contact state |
| +0x1e14 | SuspensionConfig | 0=2-wheel, 1=4-wheel, 2=2-wheel alternate — matches AdjustSuspRates concept |
| +0x1e38 | SuspensionTravelAccumulator | FUN_0043fffb updates this from spring/damper travel |
| +0x1c5c | SecondarySuspensionTravel | Additional travel state for two-stage dampers |
| DAT_0059e450 | HalfConstant_0.5f | Used pervasively as 0.5f — scaling factor for averaging |
| DAT_0059e880 | HalfConstant_0.5 | Used pervasively as 0.5 double — scaling factor for double ops |
| DAT_0059e43c | One_1.0f | Used as 1.0f constant |
| DAT_0059e440 | Zero_0.0f | Used as 0.0f constant |
| DAT_0059e420 | One_1.0 | Used as 1.0 double constant |
| DAT_0059e430 | Zero_0.0 | Used as 0.0 double constant |
| DAT_0059ec10 | TimestepScale (physics DT) | Used in force scaling by delta time |
| DAT_0059e888 | TwoPi | Used for angle normalization |
| DAT_0059e890 | Pi | Used for angle comparison |
| DAT_0059eb50 | DamperRangeLimit1 | Used across FUN_0043e980, FUN_0043e890, FUN_0043eae0 for damper 1 range |
| DAT_0059eb28 | DamperRangeLimit2 | Used for damper 2 range |
| DAT_0059ec78 | DamperRate1 | Frequency/rate coefficient for damper 1 |
| DAT_0059eb58 | DamperRate2 | Frequency/rate coefficient for damper 2 |
| DAT_008aeec0 | BrakeCoolingMode | 0=dry, 1=ducted, 2=wet — used in FUN_00430a50, FUN_00431850 |
| DAT_007ce958 | TireModelMode (from globals table) | Used in FUN_00442c90 for downforce-dependent energy dissipation |
| DAT_0059ea38 | SuspensionTravelScale | Used in FUN_00447f30 to scale suspension travel for telemetry |
| DAT_008afee4/8 | WindVelocity | Used in FUN_00438130 for aerodynamic velocity damping |
| DAT_0059e6e8 | LateralAccelThreshold | FUN_004e5470 checks lateral acceleration against this |
| DAT_008afe98 | FrameDeltaTime | FUN_0045e620 reads this, clamps to 0-0.0333s |
| DAT_008ad07c/80/84 | VCRRecordingFlags | FUN_004e9ca0 checks these for AI path recording |

## Additional Notes

1. **F1C physics struct vs rFactor SDK**: F1C uses a dense monolith struct (~3KB+ for vehicle) compared to rFactor's cleanly separated classes. This is expected for isiMotor 1.x code.

2. **Missing rFactor features in F1C**: No evidence of mExpansion fields, compound restriction logic, or plugin telemetry API. F1C predates these.

3. **Double-precision core**: F1C physics uses double-precision throughout (force accumulators, spring states, constraint axes) — rFactor SDK uses float. F1C's higher precision suggests more focus on stability at lower tick rates.

4. **Constraint solver approach**: F1C uses grouped constraint bodies with explicit per-axis stiffness/damping. rFactor evolved to a unified constraint solver (DynMan). The grouped approach matches the 3-group pattern seen in FUN_0056ee40 and FUN_0056baf0.

5. **No RTTI in F1C**: F1C was compiled with `/GR-` (RTTI disabled), confirmed by zero RTTI strings in the binary. Class hierarchy is virtual-dispatch-only without type info.

6. **Source file mapping**: F1C source files (from assert strings) include hdvehicle.cpp, dynman.cpp, suspension.cpp, tire_data.cpp, vehicle.cpp, ai_steer.cpp, collision_*.cpp — confirming the same module structure as rFactor source paths from dev_tree.txt.

7. **Config param completeness**: Of ~1034 unique params across all ISI games, ~120 are directly physics/dynamics relevant. F1C uses a subset matching its simpler isiMotor 1.x feature set.
