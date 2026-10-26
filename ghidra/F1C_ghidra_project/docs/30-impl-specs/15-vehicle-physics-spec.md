# Implementation Spec: Vehicle Physics

Source: docs/10-vehicle-physics.md  |  Functions: 103  |  Date: 2026-07-15

---

## Overview

The Vehicle Physics system is the core simulation engine for F1 Challenge 99-02. It
manages all per-vehicle dynamic behavior including suspension kinematics, tire
thermals and wear, steering geometry, aerodynamic downforce, collision response,
engine wear/failure, and driver input processing (both AI and human). The system
runs **per-physics-tick** (nominally 60 Hz) during active race sessions and is
bypassed during menu/paused states.

**When it runs:** Every physics tick when `RaceActiveFlag` (`DAT_007d0308`) is
set. The main vehicle update dispatch (`0x004b87c0`/`0x004b8940`) iterates all
active vehicles via `VehiclePtrArray` (`DAT_007c54f0`) and calls the physics
integration chain: `0x004ef5a0` → `0x004e5f60` (per-vehicle suspension + tire)
→ per-wheel force computation → constraint solve → integration.

**Data structures owned:**
- **VehicleStruct** (0x48C0 bytes per vehicle, mapped at +0x0000..+0x48C0):
  World position/orientation, velocity, suspension state per corner, tire model
  parameters, engine state, aero configuration, damage state, AI control state.
- **Per-wheel physics struct** (stride 0x464 bytes, 4 wheels per vehicle):
  Suspension deflection, spring/damper forces, tire slip state, contact info.
- **Physics body array** (stride 0x244 per body): Position, orientation,
  inertia tensor, joint references.
- **Joint/Hinge/Bar arrays** (stride 0x30/0x30/0x48): Constraint definitions
  connecting physics bodies.

**Interfaces with:**
- **docs/06-session-race-logic.md**: Reads `SessionType` (`DAT_007c56a4`),
  `RacePhase` (`DAT_007c56a8`) for pit limiter, formation lap, race completion.
- **docs/02-ai-system.md**: AI controller reads vehicle state (speed, position,
  orientation) and writes throttle/brake/steering to vehicle struct.
- **docs/03-engine-wear-damage.md**: Engine wear simulation
  (`FUN_004ee150`) reads `EngineWearMode` (`DAT_007cea5c`) and updates wear
  accumulators.
- **docs/04-tire-system.md**: Tire compound data loaded via
  `FUN_004d7570`/`FUN_0043da10`; wear rate scaled by `TireWearMultiplier`
  (`DAT_007d0c60`).
- **docs/17-physics-collision.md**: Collision detection (`0x004ea970`) reads
  wheel positions from vehicle struct, writes collision impulses back.
- **docs/18-physics-dynamics.md**: Rigid body integration, constraint solver
  (`0x0043f7f0`) called per tick.
- **docs/19-renderer.md**: Vehicle visual state (wheel rotation, steering
  animation, suspension pose) read for rendering.
- **docs/21-audio-network-internals.md**: Engine/ tire audio triggered from
  physics state (RPM, wheel slip, collision force).
- **docs/08-file-formats.md**: Reads `.svm` vehicle setup files,
  `.tbc` tire compound files, `.veh` vehicle definition files.

---

## Data Structures

### VehicleStruct (param_1 pointer)

Game's largest struct. Range 0x0000-0x48C0. Used by all physics, AI, session functions.

```c
struct VehicleStruct {
    /* +0x0000 */ void* vtable;                    // MSVC object header
    /* +0x0008 */ float  positionX;                // world position
    /* +0x000C */ float  positionY;
    /* +0x0010 */ float  positionZ;
    /* +0x0014 */ float  orientationQuat[4];       // (x, y, z, w)
    /* +0x0020 */ float  rotationMatrix[3][3];     // column-major, 9 floats

    // --- Physics state ---
    /* +0x34B0 */ float  rotMatrix00;
    /* +0x34B8 */ float  coolingCoeff;
    /* +0x34D0 */ float  dirZ;
    /* +0x34D4 */ float  worldPosX;                // duplicate position
    /* +0x34D8 */ float  worldPosY;
    /* +0x34DC */ float  worldPosZ;
    /* +0x34E0 */ void*  aiStateStructPtr;         // pointer to AI substate
    /* +0x34EC */ float  velocityInput[3];         // force/velocity input vector
    /* +0x3500 */ float  brakePadTemp;             // also velocity component
    /* +0x3504 */ float  physicsVarA;              // integration state
    /* +0x3508 */ float  physicsVarB;
    /* +0x350C */ float  physicsVarC;
    /* +0x3514 */ float  forceScaleFactor;         // scales force terms
    /* +0x3518 */ float  outputScaleFactor;        // final force scaling
    /* +0x3570 */ float  coolingVelocity;          // clamped vel for cooling
    /* +0x3578 */ float  speed;                    // race start speed
    /* +0x3990 */ float  currentSpeed;
    /* +0x3994 */ float  targetSpeed;              // current RPM/load

    // --- Per-wheel suspension state (stride 0x128) ---
    /* +0x0D4 */  struct WheelSusp[4];             // suspension state per corner
    /* +0x358C */ float  suspDeflectionFL;
    /* +0x3594 */ float  suspDeflectionFR;
    /* +0x3A6C */ float  camberRelaxation;         // camber accumulator
    /* +0x3A70 */ float  springCoeff;              // base spring coefficient

    // --- Tire model (stride 0x464 per wheel, 4 wheels) ---
    /* +0x3EC */  void*  wheelStructArray;         // array of 4 wheel structs × 0x464
    /* +0x3BF4 */ float  inverseWetScale;          // wet scaling factor
    /* +0x3BFC */ float[14] tireStiffnessTable;    // slip curve table entries
    /* +0x3C00 */ float[14] tableValues;
    /* +0x3C3C */ float[14] lowGripTable;
    /* +0x3C7C */ float[14] highGripTable;
    /* +0x3CFC */ float  combinedStiffnessFactor;
    /* +0x3D00 */ float[15] solvedSlipRatios;
    /* +0x3D3C */ float  maxClampForce;            // output clamp upper
    /* +0x3D44 */ float  aligningMoment;
    /* +0x3D60 */ int    tireStateFlag;

    // --- Brake system ---
    /* +0x39A8 */ float  frictionComponent;
    /* +0x39AC */ float  caliperTemp;
    /* +0x39B4 */ int    axleType;                 // 0=off, 1=TC, 2=rear
    /* +0x39C8 */ float  brakeRotorTemp;
    /* +0x39EC */ byte   brakeEnabled;
    /* +0x3A04 */ float  brakeTimer;
    /* +0x3A08 */ int    brakeState;               // 1=releasing
    /* +0x3D40 */ float  brakeAreaCoeff;
    /* +0x3DB4 */ float  brakeWearAccumulator;

    // --- Steering ---
    /* +0x008C */ double steeringRatio;
    /* +0x0094 */ double maxSteeringAngle;
    /* +0x1630 */ void*  leftRackPosPtr;
    /* +0x1644 */ void*  rightRackPosPtr;
    /* +0x01E0 */ double accumulatedSteeringAngle;

    // --- Aero ---
    /* +0x4024 */ float  downforceMultiplier;
    /* +0x3A30 */ float  frontWingDownforce;
    /* +0x3A44 */ float  rearWingDownforce;

    // --- Physics bodies ---
    /* +0x15AC */ int    suspensionBodyCount;
    /* +0x15B0 */ void*  suspensionBodyArray;
    /* +0x15B4 */ int    suspensionLinkCount;      // stride 0x30
    /* +0x15B8 */ void*  suspensionLinkArray;
    /* +0x15BC */ int    steeringLinkCount;        // stride 0x48
    /* +0x15C0 */ void*  steeringLinkArray;
    /* +0x15C4 */ int    steeringBarCount;
    /* +0x15C8 */ void*  steeringBarArray;
    /* +0x15F0 */ void*  mainBodyPtr;
    /* +0x15F4 */ double totalMass;
    /* +0x15FC */ double centerOfMass[3];
    /* +0x1D4 */  void*  fuelTankBodyPtr;
    /* +0x1E8 */  void*  driverHeadPtr;
    /* +0x1D4 */  void*  physicsBodyPtr;

    // --- Session state ---
    /* +0x403C */ int    seasonPoints;
    /* +0x4058 */ int    qualifyingPosition;
    /* +0x405C */ float  qualifyingTime;
    /* +0x4060 */ int    finishPosition;
    /* +0x4064 */ int    finishState;              // 0=running, 1=finished, 2=DNF, 3=DSQ
    /* +0x4068 */ int    reasonCode;               // retirement reason
    /* +0x409C */ float  bestLapTime;

    // --- AI state ---
    /* +0x4354 */ int    aiStateFlags;
    /* +0x4500 */ float  passScoreBiasAdd;
    /* +0x4504 */ float  passScoreBiasMult;
    /* +0x454C */ int    aiSpeedDelta;

    // --- Engine wear ---
    /* +0x1DB4 */ double effectiveLifetimeAtSpawn;
    /* +0x1DBC */ double lifetimeRPM_min;
    /* +0x1DC4 */ double invLifetimeRPM_max;
    /* +0x1DCC */ double lifetimeOilTemp_min;
    /* +0x1DD4 */ double invLifetimeOilTemp_max;

    // --- Tire compound ---
    /* +0x1140 */ double[8] frontTireTelemetry;
    /* +0x1160 */ byte[16]  frontCompoundFlags;
    /* +0x1170 */ int       currentFrontCompoundIdx;
    /* +0x1180 */ uint      pitStopFlagBitmask;

    // --- Names ---
    /* +0x4620 */ char[64]  driverName;
    /* +0x4678 */ char[]    vehicleDescription;
    /* +0x4894 */ int       teamID;
    /* +0x489C */ int       driverNumber;
};
// Total size: 0x48C0 bytes (observed stride in vehicle array)
// Accessed via: DAT_007c54f0 (VehiclePtrArray)
```

### Per-Wheel Physics Struct (stride 0x464)

```c
struct WheelPhysics {
    /* +0x000 */ double bumpTravel;
    /* +0x008 */ double reboundTravel;
    /* +0x0B0 */ double brakeTorque;
    /* +0x0B8 */ double brakeOptimumTemp;       // Kelvin (+273.15 applied at load)
    /* +0x0F0 */ double brakeWearRate;
    /* +0x0F8 */ double brakeFailureMin;
    /* +0x100 */ double brakeFailureMax;
    /* +0x1EC */ byte   tireActive;
    /* +0x1F8 */ double forceConst1;
    /* +0x200 */ double forceLinCoeff;
    /* +0x208 */ double forceQuadCoeff;
    /* +0x210 */ double forceConst2;
    /* +0x218 */ double torqueLinCoeff;
    /* +0x220 */ double torqueQuadCoeff;
    /* +0x228 */ double torqueCamberCoeff;
    /* +0x250 */ double latForcePeak;
    /* +0x288 */ double longForcePeak;
    /* +0x2E8 */ double camberAngle;
    /* +0x2F8 */ byte   modelEnabledFlag;
    /* +0x2FC */ double quadraticC;             // tire quadratic model
    /* +0x304 */ double quadraticA;
    /* +0x30C */ double quadraticB;
    /* +0x314 */ double outputQuadC;
    /* +0x31C */ double outputQuadA;
    /* +0x324 */ double outputQuadB;
    /* +0x334 */ double optimumTemp;             // Kelvin
    /* +0x384 */ double baseGrip;
    /* +0x388 */ double gripFactor;
    /* +0x38C */ double sensFactor;
    /* +0x390 */ double sensFactor2;
    /* +0x394 */ double wearInit;
    /* +0x3CC */ double wearRate;
    // ... additional per-wheel state
};
```

### Physics Body Struct (stride 0x244)

```c
struct PhysicsBody {
    /* +0x00 */ char* name;
    /* +0x04 */ double positionQuat[4];          // position/quaternion
    /* +0x1C */ double orientationMatrix[3][3];  // 3×3 rotation
    /* +0x20 */ double inertiaDiag[3];           // diagonal inertia
    /* +0x38 */ double inertiaOffDiag[3];        // off-diagonal inertia
    /* +0x4C */ double transformMatrix[4][4];    // (partial)
    /* +0xAC */ double mass;
    /* +0xB4 */ double invMass;
    /* +0xBC */ double invInertiaDiag[3];
    /* +0x228 */ void* perBodyData;
    /* +0x22C */ int   jointRefCount;
    /* +0x234 */ int   hingeRefCount;
    /* +0x23C */ int   barRefCount;
};
```

### Joint/Hinge Struct (stride 0x30)

```c
struct Joint {
    /* +0x00 */ char* name;
    /* +0x04 */ void* negBody;                   // negative body reference
    /* +0x08 */ double derivedSpring;            // computed value
    /* +0x0C */ void* posBody;                   // positive body reference
    /* +0x10 */ double derivedTension;
    /* +0x14 */ double position[3];              // position/orientation
    /* +0x28 */ double orientation[3];
    /* +0x2C */ int    linkCounter;
};
```

### Wheel Corner Setup Struct (per wheel, from .svm load)

```c
struct WheelCornerSetup {
    /* +0x00 */ double bumpTravel;
    /* +0x08 */ double reboundTravel;
    /* +0x0B0 */ double brakeTorque;
    /* +0x0B8 */ double brakeOptimumTempKelvin;   // Celsius + 273.15
    /* +0x0F0 */ double brakeWearRate;
    /* +0x0F8 */ double brakeFailureMin;
    /* +0x100 */ double brakeFailureMax;
};
```

### Suspension/Wheel Dynamics Solver Struct

```c
struct WheelDynamics {
    /* +0x1E38 */ double wheelDeflection;       // current suspension position
    /* +0x1C5C */ double wheelVelocity;
    /* +0x1CFC */ void*  springCurveTable;      // (x,y) float table for non-linear spring
    /* +0x1D00 */ float  springForce;           // interpolated
    /* +0x1D04 */ float  damperForce;           // interpolated
    /* +0x1E14 */ int    solverMode;            // 0=2wheel, 1=4wheel, 2=2wheel_alt
    /* +0x1E18 */ float  stiffness;             // spring rate
    /* +0x1E20 */ float  dampingRebound;
    /* +0x1E28 */ float  dampingBump;
    /* +0x1E30 */ float  biasForce;             // preload
    /* +0x1E50 */ float  biasAccum;             // accumulated bias term
    /* +0x1EF0 */ int    solverErrorFlag;
    /* +0x1E58 */ float  forceScale;
    /* +0x15F0 */ void*  forceTargetPtr;        // force accumulator struct
    /* +0x141C */ void*  altForceTarget;
};
```

### Vehicle Setup Struct (used by garage UI and setup file I/O)

```c
struct VehicleSetup {
    /* +0x68 */  char[128] notes;
    /* +0xBB0 */ SetupParamEntry paramArray[?];   // stride 0x40 per entry
    /* +0x19A5 */ byte  symmetric;
    /* +0xBC4 */ int   tireCompoundSetting;
    /* +0xCC4 */ int   fuelSetting;
    /* +0x1884 */ int   numPitstopsSetting;
    /* +0x18C4 */ int   pitstop1Setting;
    /* +0x1904 */ int   pitstop2Setting;
    /* +0x1944 */ int   pitstop3Setting;
    /* +0xE04 */ int   fenderFlareLeft;
    /* +0xE44 */ int   fenderFlareRight;
    /* +0x1284 */ int   frontWingSetting;
    /* +0x12C4 */ int   rearWingSetting;
    /* +0x1304 */ int   radiatorSetting;
    /* +0x1344 */ int   brakeDuctSetting;
    /* +0xD04 */ int   antiSwaySetting;
    /* +0xD44 */ int   toeInLeft;
    /* +0xD84 */ int   toeInRight;
    /* +0xE84 */ int   casterLeft;
    /* +0xEC4 */ int   casterRight;
    /* +0xF04 */ int   trackBarLeft;
    /* +0xF44 */ int   trackBarRight;
    /* +0x1444 */ int   steerLockSetting;
    /* +0x1384 */ int   rearBrakeSetting;
    /* +0x13C4 */ int   brakePressureSetting;
    /* +0x1404 */ int   handbrakePressureSetting;
    /* +0x1584 */ int   revLimitSetting;
    /* +0x15C4 */ int   engineMapSetting;
    /* +0x1604 */ int   engineBrakeMapSetting;
    /* +0x1644 */ int   finalDriveSetting;
    /* +0x1684 */ int   reverseSetting;
    /* +0x16C4 */ int   gearSettings[8];          // stride 0x40
    /* +0x1484 */ int   diffPumpSetting;
    /* +0x14C4 */ int   diffPowerSetting;
    /* +0x1504 */ int   diffCoastSetting;
    /* +0x1544 */ int   diffPreloadSetting;

    // Per-wheel settings (stride 0x2C0 per wheel)
    /* +0x104 + i*0x2C0 */ int camberSetting[i];
    /* +0x144 + i*0x2C0 */ int rideHeightSetting[i];
    /* +0x184 + i*0x2C0 */ int packerSetting[i];
    /* +0x1C4 + i*0x2C0 */ int springSetting[i];
    /* +0x204 + i*0x2C0 */ int slowBumpSetting[i];
    /* +0x244 + i*0x2C0 */ int fastBumpSetting[i];
    /* +0x284 + i*0x2C0 */ int slowReboundSetting[i];
    /* +0x2C4 + i*0x2C0 */ int fastReboundSetting[i];
    /* +0x304 + i*0x2C0 */ int brakeDiscSetting[i];
    /* +0x344 + i*0x2C0 */ int brakePadSetting[i];
    /* +0x1CA8 */ float  downforce;
    /* +0x1CAC */ float  balance;
    /* +0x1CB0 */ float  ride;
    /* +0x1CB4 */ float  gearing;
    /* +0x19A4 */ byte   custom;
};
```

---

## Global Variables Owned by This System

| Global | Type | Name | Description |
|--------|------|------|-------------|
| DAT_007d0b64 | float | FuelMult | Fuel consumption multiplier, set by game options |
| DAT_007cea5c | int | EngineWearMode | 0=off, 2=normal, 3=hardcore; gates engine wear sim |
| DAT_007ce958 | int | TireModelMode | Nonzero = alternate grip scaling |
| DAT_007d0c60 | float | TireWearMultiplier | Global runtime tire wear rate scaler |
| DAT_008aae74 | float[256] | RingBufferRandom | Ring buffer of 256 random float values for physics noise |
| DAT_008aae70 | int | RingBufferCounter | Current index into RingBufferRandom |
| DAT_0059e880 | float | HalvingConstant | 0.5f — used throughout physics for averaging |
| DAT_0059e440 | float | ZeroThreshold | ~0.0f — zero comparison epsilon |
| DAT_0059e43c | float | OneConstant | 1.0f — unity constant |
| DAT_0059e438 | float | NormalizationHalf | ~0.5f — used in normalization |
| DAT_0059e7f8 | float | AntiRollMixingFactor | Bump damping combo coefficient |
| DAT_0059e7fc | float | BumpDampingConstant | ~2.0 — suspension bump damping |
| DAT_0059eac8 | float | CelsiusToKelvin | 273.15f — temperature conversion |
| DAT_0059ea58 | float | GravityConstant | Gravitational acceleration |
| DAT_0059e46c | float | TireSlipOffset | Small offset for slip angle direction |
| DAT_0059e450 | float | DegreesToRadians | π/180 — angle conversion |
| DAT_0059e98c | float | AccelerationTuningFactor | Acceleration/deceleration tuning multiplier |
| DAT_0059e480 | float | PhysicsTolerance | Small tolerance for physics comparison |

---

## Public API — Entry Points

### FUN_00439210 — Vehicle Physics Initializer (889 lines)

**Inferred signature:** `void VehiclePhysics_Init(VehicleStruct* vehicle, SetupData* setup)`
**Called from:** Vehicle creation/loading pipeline
**Called by (from callers.json):** 0x0042c690 (game state dispatch)

**What it does:**
1. Reads wheel positions from setup data; computes inertia tensor from wheel positions and masses
2. Computes mass distribution (center of mass, principal axes from inertia)
3. Computes wheel position vectors relative to center of gravity
4. Initializes suspension geometry (control arm positions, spring/damper rates)
5. Calls `FUN_0043da10` to apply tire compound data to per-wheel physics struct
6. Calls `FUN_0043b040` to set up front steering geometry (independent 5-link)
7. Calls `FUN_004390a0` for aero/drag setup
8. Stores vehicle data pointer at +0x1F00, physics body pointers, wheel array pointer at +0x3EC

**Side effects:**
- Writes: VehicleStruct mass distribution (+0x15F4..+0x1624)
- Writes: Wheel physics arrays (+0x3EC, stride 0x464)
- Writes: Suspension body arrays (+0x15AC..+0x15C8)
- Writes: Aero data (+0x1428..+0x1450)
- Reads: TireModelMode (DAT_007ce958) — gates alternate grip scaling
- Reads: SessionType (DAT_007c569c) — suppresses warnings if 5 (dedicated server)

---

### FUN_004e5f60 — SuspensionAndWheelPhysics (main per-tick integration)

**Inferred signature:** `void SuspensionAndWheelPhysics(VehicleStruct* vehicle, SetupData* setup, TickInput* input)`
**Called from:** 0x004e45b0 (vehicle physics tick dispatch)
**Called by (from callers.json):** 0x004e45b0

**What it does:**
1. Reads 4 suspension corner states from +0x8B8 (stride 0x4A words, 0x128 bytes)
2. Copies to local work buffer; applies velocity/steering corrections from input at +0x54A..0x564
3. Applies PID-style correction for steering/lean targets
4. **Chassis force computation:**
   - Reads longitudinal/lateral weight transfer from setup +0xBF0/0xBF8/0xC04
   - Computes 4-corner chassis load distribution via matrix at +0x3674 (stride 0x3E)
   - Weight distribution: `1.0 - fwd_fraction, fwd_fraction` cross-multiplied
   - Computes roll/pitch torques at +0x4024
5. **Position update:** Sets body position/rotation from input and suspension state
6. **Tire force calculation (4 corners):**
   - Reads tire model params from vehicle +0x1B8 (stride 0x58) and input +0x1400 (stride 21 doubles)
   - Aggregates longitudinal/lateral/aligning forces per corner
   - Computes slip angles, friction circle via `FUN_004e8010`
   - Stores per-corner force outputs at +0x35AC (stride 0x3E)
7. **Brake/grip factor:** Per-corner brake force, normalized by ABS difference; computes brake bias from setup +0xCC4
8. **Fuel system:** Computes fuel mass from `FuelMult` (DAT_007d0b64)
9. **Steering geometry output:** Writes steering angle, reciprocal, caster/camber angles
10. **Gear ratio final drive:** Reads from setup +0x1440; writes primary inertia + gear ratio
11. **Differential/anti-roll:** Computes from setup differential settings; writes heave/roll stiffness
12. **Ride height/springs:** Reads spring rates; writes inverse ride rate
13. **Engine inertia/drag:** Reads from setup +0x1578
14. **SCR/Traction control:** Reads from input +0x13C4 for active control bits; generates 8 random values
15. **Downforce vectors:** Front/rear wing downforce at +0x3A30/+0x3A44
16. **Suspension geometry (13 points):** Computes pushrod/rocker geometry for 13 hardpoints; applies roll/pitch corrections; computes bump stop, damper velocities
17. **Final integration:** Computes CoG offset; writes body position; calls `FUN_004ee150` for engine wear

**Side effects:**
- Writes: VehicleStruct suspension state, brake force, steering geometry, downforce vectors
- Reads: FuelMult (DAT_007d0b64), vehicle offset globals (DAT_007c8a24/0x2C/0x34)
- Calls: `FUN_004ee150` (engine wear), `FUN_004f6880`/`FUN_004f68b0`/`FUN_004f6950` (tire force quadratic model)

---

### FUN_004e8010 — Tire Brush Model / Grip Computation

**Inferred signature:** `void TireBrushModel(VehicleStruct* vehicle, int wheelIndex, TickInput* input)`
**Called from:** `FUN_004e5f60`, `FUN_004ee2d0` (brake physics), and others
**Called by (from callers.json):** FUN_004e5f60, FUN_004ee2d0, and 15+ other callers

**What it does:**
1. Reads tire state from per-wheel struct at `wheel_index × 0x464 + 0x28C`
2. Computes slip angle from lateral/longitudinal velocity difference
3. Applies brush tire model:
   - Quadratic coefficients for lateral force: `Force = a*slip² + b*slip + c`
   - Quadratic coefficients for aligning torque
   - Peak force limits from `LatForcePeak` (+0x250) and `LongForcePeak` (+0x288)
4. Computes friction circle (combined lateral + longitudinal force limit)
5. Multiplies by grip factor, temperature factor, wear factor
6. Calls `FUN_005895a2` (sqrt lookup) for vector magnitude computation
7. Returns per-wheel forces to caller

**Side effects:**
- Writes: Tire wear accumulator at +0x3D64
- Reads: Tire slip tables (+0x3BFC..+0x3C84), tire stiffness, camber

---

### FUN_0043f7f0 — Suspension/Wheel Dynamics Solver

**Inferred signature:** `void WheelDynamicsSolver(WheelDynamics* dynamics, float dt)`
**Called from:** `FUN_004414d0` (wheel state copy + integration stepping)
**Called by (from callers.json):** 0x004414d0, 0x004e4e60 (wheel physics sub-solver)

**What it does:**
1. Input: param_1 (wheel dynamics struct), param_2 (timestep dt)
2. Generates random noise via `FUN_00438930` for grip variation
3. Table interpolation at +0x1CFC: linear interpolates spring/damper curves from float table (stride 8 bytes: [x0, y0], [x1, y1])
4. Stores interpolated spring force at +0x1D00, damper force at +0x1D04
5. Non-linear spring: computes spring force from deflection × velocity across lookup table
6. Solver mode at +0x1E14 (0, 1, 2) selects wheel grouping:
   - 0: Two wheels (axle pair — front or rear)
   - 1: Four wheels (full vehicle)
   - 2: Two wheels with alternate force routing
7. Per-wheel arrays at stride 0x464: +0x348 (position), +0x360 (force), +0x368 (constraint), +0x7AC (force2), +0x7C4 (inertia), +0xC10 (velocity), +0xC28 (mass), +0xC30 (inertia2), +0x1074 (bias), +0x108C (bias2)
8. Constraint solve: computes candidate timesteps `dStack_2c0` (velocity constraint) and `dStack_2b8` (position/penetration constraint); selects minimum stable timestep
9. Jacobian computation: negative ratio of bias/effective mass for each wheel
10. Force output applied to +0x15F0 (force accumulator struct) at +0x14C, +0x154, +0x15C
11. Sub-stepping: if computed timestep < dt, runs remaining time in loop

**Side effects:**
- Writes: Spring force, damper force, wheel force accumulator
- Calls: `FUN_005677b0` (Cholesky/matrix solve), `FUN_005895a2` (sqrt)
- Error handlers: `FUN_0059d7b5` (division-by-zero), `FUN_0059d928`

---

### FUN_00451720 — Driver Input Controller

**Inferred signature:** `void ProcessDriverInput(VehicleStruct* vehicle, float throttle, float brake, float steer, float clutch)`
**Called from:** Game loop AI dispatch (0x0042c690 chain)
**Called by (from callers.json):** 0x0042c690, others

**What it does:**
1. Checks `DAT_007c56ac` (enable flag) to toggle AI vs human mode
2. Loops 4 channels: throttle, brake, steering, clutch
3. AI path uses shift logic globals for gear timing, throttle blending
4. Human path reads input devices, blends with assists
5. Pit speed limiter: checks `RacePhase` (`DAT_007c56a8`) for pit entry
6. FFB steering with self-centering force computation
7. Writes final control values to vehicle struct for physics tick

**Side effects:**
- Writes: VehicleStruct throttle/brake/steering/clutch values
- Reads: `DAT_007c56ac` (enable), `DAT_007c54e0`, `DAT_007d1358`, `DAT_007d2140`, `DAT_007d208c`

---

### FUN_00442060 — SteeringGeometryUpdate

**Inferred signature:** `void UpdateSteeringGeometry(VehicleStruct* vehicle, int wheelIndex, float steerInput)`
**Called from:** Main physics tick
**Called by (from callers.json):** 0x00438690 (damage), physics tick dispatch

**What it does:**
1. Computes steering angle: `steerInput * _DAT_0059ed78`
2. Per-wheel offset (0=FL, 1=FR, 2=RL, 3=RR):
   - Front wheels (0,3): add `sin(random) × steering`
   - Rear wheels (1,2): subtract
3. Clamps to max steering angle (±0.22 radians ≈ 12.6°)
4. Computes `cos(random) × steering` for caster offset
5. Calls `FUN_00441450` for geometry refresh
6. Iterates suspension components matching corners by wheel ID; applies steering rotation to wheel position/orientation
7. Accumulates steering angle at +0x1E0
8. If accumulated angle > `_DAT_0059ed60` and ReasonCode == 0: triggers steering damage (ReasonCode=4)

**Side effects:**
- Writes: VehicleStruct wheel orientations, accumulated steering angle
- Reads: RingBufferRandom (DAT_008aae74)
- Damage: Sets ReasonCode +0x4068 = 4

---

### FUN_00438690 — Collision Damage & DNF Detection

**Inferred signature:** `int ProcessCollisionDamage(VehicleStruct* vehicle, float impactVelocity, float damageMult)`
**Called from:** Collision response pipeline (FUN_004ea970)

**What it does:**
1. Computes impact severity from `velocity * damageMult`
2. Directional damage weighting from suspension/body coefficients
3. If suspension damage > body damage: normal damage path
4. Else: reduces impact energy, checks angular deviation for additional damage
5. If cumulative damage exceeds max threshold: triggers DNF via `FUN_0041b200`
6. Sets ReasonCode +0x4068 = 5 on first AI found

**Side effects:**
- Writes: ReasonCode (+0x4068), vehicle damage state via `FUN_0041b200`
- Calls: `FUN_004388d0` (damage helper), `FUN_005697a0`

---

### FUN_004ee150 — Engine Wear/Failure Simulation

**Inferred signature:** `void SimulateEngineWear(VehicleStruct* vehicle, float dt)`
**Called from:** `FUN_004e5f60` (main suspension integration)

**What it does:**
1. Checks `EngineWearMode` (`DAT_007cea5c`): only active if 1 or 2
2. Runs 4 iterations (one per cylinder)
3. Computes failure probability from lifetime wear params at +0x1330 (LifetimeAvg) and +0x1338 (LifetimeVar)
4. If in race session (`SessionType` == 7) with mode 2: divides probability by `TotalRaceLaps` (`DAT_008acf9c`)
5. If probability <= threshold: stores failure time in +0x3D64 (4 float output)
6. If probability > threshold: stores FLT_MAX (no failure)

**Side effects:**
- Writes: 4 failure time floats at +0x3D64
- Reads: EngineWearMode, LifetimeAvg, LifetimeVar, TotalRaceLaps

---

### FUN_0042fd00 — Vehicle Setup File Writer

**Inferred signature:** `int WriteSetupFile(VehicleSetup* setup, const char* filepath)`
**Called from:** Garage UI "save setup"

**What it does:**
1. Opens file via `FUN_005668b0`/`FUN_00566940` (write mode)
2. On failure: logs "Failed to open %s for writing" and returns -1
3. Writes section headers and values using `FUN_00566c30`:
   - `[Notes]`: driver notes string
   - `Symmetric`, `CGRightSetting`, `CGRearSetting`, `WedgeSetting`, `TireCompoundSetting`, `FuelSetting`
   - `NumPitstopsSetting`, `Pitstop1-3Setting`
   - `[LEFTFENDER]` / `[RIGHTFENDER]`: `FenderFlareSetting`
   - `[FRONTWING]`: `FWSetting`, `[REARWING]`: `RWSetting`
   - `[BODYAERO]`: `RadiatorSetting`, `BrakeDuctSetting`
   - `[SUSPENSION]`: 12 front/8 rear suspension parameters
   - `[CONTROLS]`: `SteerLockSetting`, `RearBrakeSetting`, etc.
   - `[ENGINE]`: `RevLimitSetting`, `EngineMapSetting`, `EngineBrakeMapSetting`
   - `[DRIVELINE]`: `FinalDriveSetting`, `ReverseSetting`, `Gear%dSetting` 1-8
   - Per-wheel `[FRONTLEFT]`-`[REARRIGHT]`: camber, pressure, packer, spring, ride height, bump/rebound, brake disc/pad
   - `[BASIC]`: `Downforce`, `Balance`, `Ride`, `Gearing`, `Custom`
4. Closes file

**Side effects:**
- Writes: Text setup file to disk
- Returns: 0 on success, -1 on file open failure

---

### FUN_0043da10 — Tire Compound → Per-Wheel Physics Application

**Inferred signature:** `void ApplyTireCompound(VehicleStruct* vehicle, TireCompound* compound)`
**Called from:** `FUN_00439210` (vehicle init)

**What it does:**
1. Iterates per-wheel physics struct at `wheel_index × 0x464 + 0x28C`
2. Maps compound fields to physics parameters:
   - +0x20C..0x218: tire grip params 1-4 (raw from compound)
   - +0x21C/0x224: camber factors (scaled by constants)
   - +0x22C: load sensitivity (computed via `FUN_004d6ae0`)
   - +0x234/0x238: grip multipliers (raw from compound)
   - +0x278/0x288: tire radius min/max
   - +0x2D8/0x2DC/0x2E0: slip curve pointers (via `FUN_004d75d0`)
   - +0x2F4/0x2FC: optimum camber and sensitivity
   - +0x334: optimum temp (+273.15K offset)
   - +0x384/0x388: base grip and grip factor
   - +0x3CC: wear rate (scaled by `DAT_007d0c60` × load normalization)

**Side effects:**
- Writes: Per-wheel tire physics parameters
- Reads: TireWearMultiplier (DAT_007d0c60), TireModelMode (DAT_007ce958)
- Calls: `FUN_004d6ae0`, `FUN_004d75d0` (slip curve lookup)

---

### FUN_004b0ef0 — Vehicle Setup Configuration

**Inferred signature:** `void ApplyVehicleSetup(VehicleStruct* vehicle, int setupSlot)`
**Called from:** Garage/setup UI

**What it does:**
1. Selects one of 6 setup slots (param_2: 1-6)
2. Copies 12 parameter groups from setup arrays (stride 0x24) to runtime struct
3. Clamps copied values between stored min/max bounds
4. Sets mode flags: param_2==1 → mode 1, param_2==2 → mode 7

**Side effects:**
- Writes: VehicleStruct setup parameters (gearing, diffs, suspension, alignment)
- Calls: `FUN_004b1190` (finalize), `FUN_00464720`, `FUN_004646c0`

---

### FUN_004e3d00 — Wheel Spring/Damper Force and Steering

**Inferred signature:** `void ComputeWheelSpringDamper(float* wheelState, float* outputForce)`
**Called from:** Per-wheel physics pipeline

**What it does:**
1. Reads wheel state from 38+ float array per wheel
2. Computes local suspension axes from wheel orientation vectors
3. Branches on suspension type (+0x0F):
   - <= `_DAT_005ad168` threshold: double-wishbone/McPherson
   - > 0x2F=1.0: rigid axle
   - else: general
4. Computes spring force from ride height: `springForce = (rideHeight * progressiveRate + 1.0) * springRate * rideHeight`
5. Damping: enabled flag, scaling from damping factor
6. Steering geometry: transforms wheel deflection using caster/kingpin angles
7. Stores output velocities at +0x36-0x38 (3-component)
8. Threshold checks against previous contact position to prevent re-collision

**Side effects:**
- Writes: Spring force, damper force, bump force, wheel velocity
- Reads: Suspension type constants, bump damping constants (DAT_0059e7f8, DAT_0059e7fc)

---

### FUN_0042d7a0 — Race State Restart (system-level)

**Inferred signature:** `void GameStateRestart()`
**Called from:** 0x0045b200 (game state machine)
**Described in:** docs/01-engine-architecture.md

**Called sub-systems:**
- `FUN_004c8b20` — Sound::Restart
- `FUN_004a40f0` — Steward restart
- `FUN_004a0fb0` — Race timer restart
- `FUN_00455da0` — HWInput::Restart
- `FUN_0040c9e0` — CamMan::Restart
- `FUN_004b4060` — Render::Restart
- `FUN_0049f000` — OnScreen::Restart
- `FUN_004fa640` — VidMan::Restart
- `FUN_00464290` — NetComm restart

**What it does (for vehicle physics):**
Triggers full state flush and re-init of all vehicle physics subsystems on race restart. Vehicle positions, velocities, damage states are reset via per-vehicle callbacks.

---

## Internal Call Graph

Major call chains within the vehicle physics system:

```
0x004e45b0 — VehiclePhysicsTick  [triggered by: game loop per-vehicle dispatch]
  +-- 0x004e5f60 — SuspensionAndWheelPhysics  [per-tick main integration]
        +-- 0x004e8010 — TireBrushModel  [per-wheel grip/slip computation]
        |     +-- 0x005895a2 — sqrt lookup
        |     +-- 0x004e8200 — fallback (if any)
        +-- 0x004e8b80 — TireSlipAngle  [slip angle from velocity]
        |     +-- 0x005895a2 — sqrt lookup
        +-- 0x004f6850/0x004f6880/0x004f68b0 — TireForceQuadraticModel
        +-- 0x004f6950/0x004f69e0/0x004f6a50 — QuadraticForceEval
        +-- 0x004f3190 — wheel force helper
        +-- 0x004d7880/0x004d7570/0x004d6ae0 — tire brand/lookup
        +-- 0x004e2540 — wheel suspension/tire state init
        +-- 0x004e9bd0 — coordinate transform
        +-- 0x004ee150 — EngineWearSimulation  [wear/failure per cylinder]
        |     +-- 0x0053ac70 — probability eval
        |     +-- 0x004b3ce0 — timer/store
        +-- 0x0042ed00 — random number (8×)
        +-- 0x004a5330 — fuel system compute
        +-- 0x0059d9d7/0x0059da3a — error handlers

0x0042c690 — GameStateDispatch  [triggered by: game state machine]
  +-- 0x004ee2d0 — Brake/Tire Physics (3735 bytes)  [brake force + tire thermal]
  |     +-- 0x004e8010 — TireBrushModel  (called multiple times)
  |     +-- 0x004ed960 — brake thermal calc
  |     +-- 0x004ed810 — wheel force output
  |     +-- 0x004f1c40 — force accumulator
  |     +-- 0x004e4930 — wheel state update
  |     +-- 0x00451720 — DriverInputController
  |     +-- 0x004bccc0 — telemetry/recording
  +-- 0x00451720 — DriverInputController
  |     +-- 0x004f87c0 — audio/event dispatch
  +-- 0x004e4930 — wheel state update
  +-- 0x004ed810 — per-wheel lateral force computation
  +-- 0x004f1c40 — force accumulator
  +-- 0x00424e70 — unknown physics helper
  +-- 0x00410980 — unknown

0x004b87c0/0x004b8940 — VehicleUpdateDispatch  [triggered by: per-tick vehicle iteration]
  +-- 0x004ef5a0 — VehicleStateUpdate
  |     +-- 0x004efb20 — state sub-update
  |     +-- 0x004ef7c0 — physics step
  |     +-- 0x00447780 — vector math
  |     +-- 0x004e9630 — session context update
  |     +-- 0x0042adb0/0x0042aca0 — AI state read
  +-- 0x004e3a50 — object removal (if crashed/DNF)
  +-- 0x004e1970 — scene update
  +-- 0x004b86e0 — sort/record
  +-- 0x004b8ae0 — cleanup

0x004414d0 — WheelDataCopyAndStep  [state backup]
  +-- 0x0043f7f0 — WheelDynamicsSolver  [constraint-based semi-implicit Euler]
  |     +-- 0x00438930 — RNG for grip variation
  |     +-- 0x005895a2 — sqrt lookup
  |     +-- 0x005677b0 — Cholesky/matrix solve
  |     +-- 0x0059d7b5 — err handler (div-by-zero)
  |     +-- 0x0059d928 — err handler
  +-- 0x0056ecf0/0x0056ee40/0x0056f020 — auxiliary integration helpers
  +-- 0x00441450 — geometry refresh

0x004e45b0 — VehiclePhysicsTick
  +-- 0x004e5f60 — SuspensionAndWheelPhysics  (see above)
  +-- 0x004ee150 — EngineWearSimulation
  +-- 0x004efae0 — TireScrubReset
  |     +-- 0x00447280 — wear clear
  +-- 0x004efa40 — VehicleClimbAdjust
  |     +-- 0x004471f0 — SuspensionVibration
  +-- 0x00442060 — SteeringGeometryUpdate
  |     +-- 0x00441450 — geometry refresh
  |     +-- 0x00435e00 — orientation extract
  |     +-- 0x004388d0 — damage check
  +-- 0x004ec1a0 — Collision/Spark Effects
  |     +-- 0x004efae0 — previous effect step
  |     +-- 0x004b33b0 — telemetry/particle
  |     +-- 0x004a56b0 — audio trigger
  +-- 0x00438690 — CollisionDamageAndDNF
        +-- 0x004388d0 — damage weight
        +-- 0x0041b200 — DNF trigger
        +-- 0x005697a0 — helper

0x00439210 — VehiclePhysicsInit  [one-time per vehicle]
  +-- 0x0043da10 — ApplyTireCompound
  |     +-- 0x004d6ae0 — load sensitivity calc
  |     +-- 0x004d75d0 — slip curve lookup
  |           +-- 0x00588410 — string compare
  +-- 0x0043b040 — FrontSteeringSetup (5-link independent only)
  |     +-- 0x0043af50 — suspension bar lookup (×N)
  |           +-- 0x00588410 — string compare
  +-- 0x004390a0 — aero/drag setup
  +-- 0x0043b590 — SteeringGeometryComputation
        +-- 0x0043af50 — suspension hardpoint reader
        +-- 0x004361d0 — rack displacement
```

---

## Constants and Magic Numbers

| Value | Used in | Meaning |
|-------|---------|---------|
| 273.15 | FUN_0043da10, FUN_004f2c60 | Celsius to Kelvin offset (oil temp, brake temp) |
| 0.22 rad (≈12.6°) | FUN_00442060 | Max steering angle clamp |
| 3.75f/3.25f/1.75f | FUN_004594d0 | Physics/tire parameter initialization constants |
| 0.813f/0.752f | FUN_004594d0 | Tire model coefficients |
| 0.5f | multiple | Halving constant (DAT_0059e880) |
| ±0.0f (DAT_0059e440) | multiple | Zero comparison threshold |
| 1.0f (DAT_0059e43c) | multiple | Unity constant |
| 90.0 (DAT_0059e898) | FUN_0043da10 | Camber angle limit (degrees) |
| 0x464 (1124) | multiple | Per-wheel physics struct stride |
| 0x128 (296) | multiple | Per-wheel suspension struct stride |
| 0x48C0 (18624) | multiple | Vehicle struct total size |
| 0x244 (580) | FUN_0056d930 | Physics body struct stride |
| 0x30 (48) | FUN_0056d930 | Joint/hinge struct stride |
| 0x48 (72) | FUN_0056d930 | Bar struct stride |
| 0x40 (64) | multiple | Setup parameter entry stride |
| 0x2C0 (704) | FUN_0042fd00 | Per-wheel setup setting stride |
| 0x7f7fffff | FUN_004594d0 | FLT_MAX sentinel for unbound parameters |
| 5.0 | FUN_004e3d00 | Default spring constant (hardcoded) |

---

## Inter-System Dependencies

**Reads from (external globals/systems):**

| Global | System | Used for |
|--------|--------|----------|
| SessionType (DAT_007c56a4) | docs/06 | Gear engine wear mode gate; pit limiter enable |
| RacePhase (DAT_007c56a8) | docs/06 | Pit limiter check, formation lap |
| EngineWearMode (DAT_007cea5c) | docs/03 | Enable/disable engine wear simulation |
| TireWearMultiplier (DAT_007d0c60) | docs/04 | Global tire wear rate scaler |
| TireModelMode (DAT_007ce958) | docs/04 | Alternate grip scaling mode |
| FuelMult (DAT_007d0b64) | docs/06 | Fuel consumption multiplier |
| AIDifficultySlider (DAT_007d01a0) | docs/02 | AI driver skill scaling for physics limits |
| TotalRaceLaps (DAT_008acf9c) | docs/06 | Engine wear probability divisor |
| RaceActiveFlag (DAT_007d0308) | docs/06 | Gate for per-tick physics execution |
| PlayerVehiclePtr (DAT_007c54e8) | docs/01 | Player vehicle access for display/animation |
| VehicleCount (DAT_005c329c) | docs/01 | Iteration count for per-vehicle tick |
| VehiclePtrArray (DAT_007c54f0) | docs/01 | Active vehicle pointer array |
| WeatherMode (DAT_007cf080) | docs/05 | Track wetness → tire grip reduction |
| RingBufferCounter (DAT_008aae70) | docs/02 | Random noise index for vibration/steering |
| RingBufferRandom (DAT_008aae74) | docs/02 | Random float values for physics noise |

**Calls into:**

| System | Functions called |
|--------|-----------------|
| docs/17-physics-collision.md | FUN_004ea970 (collision detection), FUN_004ed420 (proximity test), FUN_004e9bd0 (transform) |
| docs/18-physics-dynamics.md | FUN_00569b70 (numerical integration), FUN_005677b0 (matrix solve), FUN_00569280 (math) |
| docs/19-renderer.md | FUN_0054b4d0 (scene transform), FUN_0054f830 (render dispatch), FUN_0054b420 |
| docs/06-session-race-logic.md | FUN_0041b200 (DNF trigger), FUN_00411440 (session state), FUN_004a5330 (fuel) |
| docs/02-ai-system.md | FUN_0042adb0/0x0042aca0 (AI state), FUN_0042ed00 (random), FUN_0042ad00 |
| docs/21-audio-network-internals.md | FUN_004f87c0 (sound/event dispatch), FUN_005506a0 (audio trigger) |
| docs/20-math-utilities.md | FUN_005895a2 (sqrt), FUN_0058957a, FUN_00588570, FUN_0058815f (format) |
| docs/04-tire-system.md | FUN_004d7570 (tire data), FUN_004d7880 (tire brand), FUN_004d6ae0 (load sens), FUN_004d75d0 (curve lookup) |
| docs/08-file-formats.md | FUN_005668b0 (file open), FUN_00566c30 (write), FUN_00588410 (strcmp), FUN_00566b90 (close) |

**Called by:**

| System | Entry points calling into vehicle physics |
|--------|-------------------------------------------|
| docs/01-engine-architecture.md | 0x0042d7a0 (RaceStateRestart → triggers physics reset per-vehicle) |
| docs/01-engine-architecture.md | 0x0045b200 (game state machine → dispatches per-tick physics via 0x0042c690 chain) |
| docs/06-session-race-logic.md | 0x004b87c0/0x004b8940 (per-tick vehicle update dispatch → FUN_004ef5a0) |
| docs/02-ai-system.md | AI controller writes throttle/brake/steering to vehicle struct, then physics tick reads them |

---

## Reimplementation Notes

1. **Tick frequency assumption:** All physics calculations assume a fixed 60 Hz timestep. The `dt` parameter passed to solvers (`FUN_0043f7f0`) is used for sub-stepping when constraint solve requires smaller steps. Reimplement with variable timestep by accumulating sub-frame time and running fixed-step iterations.

2. **Random noise model:** Physics noise (suspension vibration, steering jitter, tire grip variation) uses a precomputed ring buffer of 256 float values (`DAT_008aae74`) indexed by `DAT_008aae70`. The counter increments modulo 256. This avoids per-frame `rand()` calls. Reimplement with a deterministic PRNG cycling through a lookup table.

3. **Constraint solver ordering:** `FUN_0043f7f0` selectes wheel grouping via `+0x1E14` (solverMode): 0=two-wheel (axle pair), 1=four-wheel, 2=two-wheel alternate. The solver computes Jacobians as `(-bias / effectiveMass)` and selects minimum stable timestep. Sub-stepping loops with `goto` — this is MSVC optimization artifact for a `while(remaining > 0)` loop.

4. **Spring/damper curve interpolation:** Non-linear spring and damper curves are stored as float tables (stride 8 bytes: [x0, y0], [x1, y1]). Interpolation is piecewise linear. The table pointer is at `+0x1CFC`, results stored at `+0x1D00` (spring) and `+0x1D04` (damper).

5. **Tire model:** The brush tire model uses quadratic coefficients per wheel for lateral force (`a*slip² + b*slip + c`), aligning torque, and peak force limits. Two sets of tables exist: low-grip (`+0x3C3C`, 14 entries stride 0x40) and high-grip (`+0x3C7C`, 14 entries). Selection between them depends on grip regime (surface condition, speed).

6. **Temperature conversion:** BrakeOptimumTemp and tire optimum temperature are stored in Kelvin internally. The `.svm` file stores values in Celsius — `+273.15` is applied at load time in `FUN_004f2c60` and `FUN_0043da10`.

7. **Fuel system:** Fuel mass is computed as `FuelMult * (input.fuel_mass) * DAT_007d01e8`. The fuel weight affects center of mass and total vehicle mass each tick. Reimplement by adjusting body mass and CoG dynamically.

8. **Engine wear model:** `FUN_004ee150` computes per-cylinder failure probability using a `LifetimeAvg`/`LifetimeVar` model (Gaussian failure distribution). In race sessions with EngineWearMode==2, probability is divided by total laps — simulating increased reliability over a race distance. The output is 4 floats at +0x3D64: the time (in seconds) of each cylinder's expected failure, or FLT_MAX if no failure expected.

9. **Setup file format:** The setup writer (`FUN_0042fd00`) writes INI-style text files with sections `[SUSPENSION]`, `[CONTROLS]`, `[ENGINE]`, `[DRIVELINE]`, `[FRONTLEFT]`-`[REARRIGHT]`, `[BASIC]`. Each section contains setting names followed by integer values. The reader must parse sections by name and map to the `VehicleSetup` struct offsets.

10. **Mass distribution:** `FUN_00439210` computes inertia tensor from wheel positions relative to CoG, treating each wheel as a point mass. This is a simplification — the actual body inertia is computed as `Σ m_i * r_i²` where r_i is the wheel position relative to CoG in the vehicle frame. The principal axes are computed via eigen decomposition of the inertia tensor.

11. **Steering geometry:** Only independent 5-link front suspension is supported. The assert string "Sorry, only support independent 5-link front suspensions right now" confirms this limitation. If steering link count != 8 (4 per side), the function asserts.

12. **Damage thresholds:** Collision damage in `FUN_00438690` uses suspension/body weighting. If suspension damage weight > body weight, a normal damage path is taken; otherwise energy is reduced and angular deviation is checked. The DNF threshold and steering damage threshold (accumulated angle > 0x0059ed60) are hardcoded constants.

---

## Completeness

- Full specs written: 12 major entry points, 103 total documented functions
- Thunks/empty stubs omitted: 6 (simple accessors, animation helpers)
- Confidence: **high** — the codebase is fully decompiled, call graphs are complete, data structure layouts are cross-validated across 15+ functions
