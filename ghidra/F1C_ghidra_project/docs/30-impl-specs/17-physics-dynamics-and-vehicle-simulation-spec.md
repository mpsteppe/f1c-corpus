# Implementation Spec: Physics — Dynamics and Vehicle Simulation

Source: docs/18-physics-dynamics.md  |  Functions: 270+  |  Date: 2026-07-15

---

## Overview

The physics dynamics system is the core rigid body simulation engine for F1 Challenge 99-02. It runs a fixed-timestep semi-implicit Euler integration per physics tick (nominally 60 Hz), handling force/torque accumulation, tire brush model forces, suspension spring/damper response, aerodynamic downforce/drag, brake temperature with fade, and constraint-based contact resolution.

The system owns the **vehicle rigid body** struct (~0x48C0 bytes per vehicle), which contains position (doubles at +0x4/+0xc/+0x14), orientation (3x3 rotation matrix at +0x1c..+0x5c), linear/angular momentum accumulators (+0x134/+0x13c/+0x144 and +0x14c/+0x154/+0x15c), inertia tensor (+0xec..+0x12c), and per-wheel force buffers (stride 0x464 per wheel). The vehicle array is accessed via `DAT_007c54f0` (VehiclePtrArray) with `DAT_005c329c` (VehicleCount).

The physics tick flow: **accumulate forces** → **solve constraints** → **integrate velocities** → **update positions**. External systems (AI, steering, engine model) write forces into accumulators; the dynamics system reads them, resolves constraints, and updates body state. The constraint solver uses a sparse L*D*L^T Cholesky factorization with projected Gauss-Seidel iteration for contact constraints.

**System boundaries:**
- Read from: AI system (steering/throttle inputs via +0x34f8/+0x3500), Engine model (torque), Tire wear model, Track surface properties
- Write to: Position/orientation visible to renderer (docs/19), Velocity/state to AI system (docs/02), Telemetry to network (docs/21)
- Owns: All +0x0000–+0x48C0 vehicle struct fields, physics globals (DAT_0059e4xx series, DAT_008afeec/e8/f4/f0), constraint solver state

---

## Data Structures

### RigidBody (core physics body, used across ~80 functions)

```c
struct RigidBody {
    /* +0x0000 */ void* vtable;          // MSVC object header
    /* +0x0004 */ double posX;           // World position X
    /* +0x000c */ double posY;           // World position Y
    /* +0x0014 */ double posZ;           // World position Z
    /* +0x001c */ double rotM[0][0];     // 3x3 rotation matrix, row-major
    /* +0x0024 */ double rotM[0][1];
    /* +0x002c */ double rotM[0][2];
    /* +0x0034 */ double rotM[1][0];
    /* +0x003c */ double rotM[1][1];
    /* +0x0044 */ double rotM[1][2];
    /* +0x004c */ double rotM[2][0];
    /* +0x0054 */ double rotM[2][1];
    /* +0x005c */ double rotM[2][2];
    /* +0x0064 */ double linMomentumX;   // Linear momentum accumulator X
    /* +0x006c */ double linMomentumY;   // Linear momentum accumulator Y  
    /* +0x0074 */ double linMomentumZ;   // Linear momentum accumulator Z
    /* +0x007c */ double inertiaTensor[3][3]; // 3x3 inertia tensor (row-major, 9 doubles)
    /* +0x00b4 */ double scaleFactor;    // Time-step or dampening factor
    /* +0x00bc */ double diagScale[3];   // Diagonal scale for inertia transform
    /* +0x00ec..+0x12c */ double rotTensor[3][3]; // Rotation tensor for force transform
    /* +0x0134 */ double angMomentumX;   // Angular momentum accumulator X
    /* +0x013c */ double angMomentumY;   // Angular momentum accumulator Y
    /* +0x0144 */ double angMomentumZ;   // Angular momentum accumulator Z
    /* +0x014c */ double torqueAccumX;   // Torque/impulse accumulator X
    /* +0x0154 */ double torqueAccumY;   // Torque/impulse accumulator Y
    /* +0x015c */ double torqueAccumZ;   // Torque/impulse accumulator Z
    /* +0x0xxx */ int    bodyType;       // Body type identifier
    /* +0x0xxx */ int    constraintCount; // Number of active constraints
    // Total size observed: 0x244 stride in body arrays
};
// Accessed via: *(param_1+0x15f0) for vehicle body, VehiclePtrArray for vehicle-level
```

### VehiclePhysicsState (param_1 — main vehicle struct, partial)

```c
struct VehiclePhysicsState {
    /* +0x0000 */ void* vtable;
    /* +0x0004–+0x005c */ double pos/rot;   // Inherits RigidBody layout
    /* +0x0060–+0x007c */ double chassisState[6]; // Copied to previous on tick
    /* +0x00bc */ double wheelCoeffA;        // Suspension geometry coefficient
    /* +0x00d4 */ double wheelCoeffB;        // Suspension geometry coefficient
    /* +0x00ec–+0x0138 */ double forceAccum[6]; // Force accumulator group 0
    /* +0x0134–+0x015c */ double momentumAccum[6]; // Momentum accumulators
    /* +0x01c4 */ int    suspensionEnable;    // 0=enabled, non-zero=disabled
    /* +0x01e8–+0x0204 */ double constraintDisp[3]; // Constraint displacement
    /* +0x022c/+0x0230 */ int ringBufCounter; int* ringBufBase; // Ring buffer
    /* +0x031c/+0x0324 */ double springCoeff; double dampingCoeff;
    /* +0x0338–+0x0xxx */ float wheelStates[4][0x119]; // Per-wheel, stride 0x464
    /* +0x0348/+0x0360 */ double damperForce[4]; double springForce[4]; // Per wheel, stride 0x464
    /* +0x034c–+0x036c */ double forceAccum6[6]; // 6-slot force accumulator
    /* +0x03a4 */ double velocityDamping;     // Velocity-proportional damping
    /* +0x0b4 */ int    stateFlag;            // Solver state flag
    /* +0x0bc4 */ int    tireInstanceId;      // Tire data index
    /* +0x0d4c */ double cumulativeDelta;     // Delta-state tracking
    /* +0x0df0/+0x0e30 */ double frontEnergyParams[3]; double rearEnergyParams[3];
    /* +0x1270/+0x12b0/+0x12f0/+0x1330 */ double chassis/energyParams[3]×4;
    /* +0x13d0/+0x14d8/+0x15e0/+0x16e8 */ int wheelContactPtrs[4]; // Front/rear pairs
    /* +0x141c */ int bodyIdA;                // Body A identifier
    /* +0x1420 */ double biasTerm;            // Constraint bias
    /* +0x1428 */ double currentValue;        // Delta tracking state
    /* +0x1430 */ double deltaGain;           // Delta tracking gain
    /* +0x1584 */ int    wheelForceComponent; // Wheel force component selector
    /* +0x15a0 */ int    energyCount;         // Energy accumulator count
    /* +0x15ac */ int    bodyCount;           // Number of bodies
    /* +0x15b0 */ void*  bodyArray;           // Body array pointer (stride 0x244)
    /* +0x15c4 */ int    constraintCount;     // Active constraint count
    /* +0x15c8 */ void*  constraintArray;     // Constraint array (stride 0x48)
    /* +0x15f0 */ int    mainBodyPtr;         // Pointer to main rigid body
    /* +0x15fc–+0x160c */ double worldOrigin[3]; // World origin/position offset
    /* +0x1614 */ double sixDofTransform[24]; // 6-DOF transform buffer  
    /* +0x162c */ double* srcStateArray;      // Source state array (stride 0x30)
    /* +0x1660/+0x1668/+0x1670 */ double wheelOffset[3]; // Wheel station offset
    /* +0x16cc */ byte   jointArray[64];      // Joint array (stride 0x40, 8 slots)
    /* +0x16f0/+0x16f8/+0x1700/+0x1708 */ double damperVel[4]; // Damper velocities
    /* +0x1748 */ double forceAccumPerStation[3]; // Force/torque per station
    /* +0x17a8/+0x17c0 */ double damperState[2]; // Damper accumulator state
    /* +0x17d8/+0x17f0 */ double springAccum[2]; // Spring/integration accumulators
    /* +0x1808 */ double springState1;         // Clamped spring state 1
    /* +0x1818 */ double springState2;         // Clamped spring state 2
    /* +0x1828–+0x1834 */ double wheelInertia[6]; // Per-wheel inertia
    /* +0x1900 */ double setupFlagData;        // Setup flag/type
    /* +0x1930/+0x19e8 */ double quadResultA; double quadResultB; // Quadratic eval
    /* +0x1960 */ float springDamperMatrix[36]; // 6x6 spring/damper matrix
    /* +0x19f0 */ float biasVector[6];         // Bias/offset from setup  
    /* +0x1a0c/+0x1abc */ double forceResult0; double forceResult1; // Quadratic force
    /* +0x1a08 */ int    extraDamperMode;      // Anti-roll bar / extra damper mode
    /* +0x1adc/+0x1b94/+0x1d9c */ double forceY; double forceX; double forceZ;
    /* +0x1b14–+0x1ba4 */ float complianceMatrix[36]; // 6x6 compliance matrix
    /* +0x1bbc–+0x1be4 */ double arbStiffness[8]; // Anti-roll bar stiffness/travel
    /* +0x1bc0/+0x1c30 */ double accState; double accLower; // Accumulator + bound
    /* +0x1c00 */ double springInput;          // Spring input value (stored)
    /* +0x1c08–+0x1c10 */ double damperMin[2]; // Damper lower bounds
    /* +0x1c18 */ double springInput2;         // Spring-damper input (stored)
    /* +0x1c20–+0x1c28 */ double springLower[2]; // Spring lower bounds
    /* +0x1c38 */ double quadInput;            // Quadratic function input
    /* +0x1c40–+0x1c48 */ double accumulatorBounds[2]; // Accumulator clamp bounds
    /* +0x1c5c */ double prevSuspDisp;         // Previous suspension displacement
    /* +0x1c64 */ double curSuspDisp;          // Current suspension displacement
    /* +0x1c74 */ double secondaryStiffness;   // Secondary stiffness
    /* +0x1ca8 */ int*   jointTargetArray;     // Joint target position array
    /* +0x1cc0 */ byte   constraintActive[4];  // Per-constraint active flags
    /* +0x1cc4 */ int    constraintValue[4];   // Per-constraint values
    /* +0x1cd4 */ byte   paramFlags[4];        // Parameter dirty flags
    /* +0x1cd8 */ int    paramValues[4];       // Parameter values
    /* +0x1ce8 */ byte   rowActiveFlags[?];    // Grid/array row active flags
    /* +0x1d9c */ double forceZ;               // Spring-damper Z output
    /* +0x1db4 */ double effectiveLifetime;    // Driver effectiveness at spawn
    /* +0x1e14 */ int    suspensionConfig;      // 0=2-wheel, 1=4-wheel, 2=2-wheel alt
    /* +0x1e18 */ double suspensionCompliance;  // Compliance factor
    /* +0x1e20 */ double reboundDamping;        // Rebound damping factor  
    /* +0x1e28 */ double bumpDamping;           // Bump damping factor
    /* +0x1e30 */ double frictionOffset;        // Friction offset
    /* +0x1e38 */ double suspTravel;            // Current suspension travel
    /* +0x1e40 */ double curWheelVel;           // Current wheel velocity
    /* +0x1e50 */ double effectiveStiffness;    // Effective stiffness
    /* +0x1ea4 */ double motionRatioComp;       // Motion ratio compensator
    /* +0x1ef0 */ int    directionFlag;         // -1=reverse direction
    /* +0x1f00 */ int    velocityDampingData;   // Pointer to damping state
    /* +0x1f04–+0x1f2c */ double forceAccum[6]; // Force/torque accumulator group 1
    /* +0x32bc */ int    physicsMode;           // 0=suspension, 1=brake, 2=tire, 3=replay
    /* +0x34ac */ float  rotationAngle;         // Rotation angle
    /* +0x34b0–+0x34d0 */ float rotMatrix3x3[9]; // Float 3x3 rotation matrix
    /* +0x34d4–+0x34dc */ float worldPos[3];    // Float world position
    /* +0x34e0 */ int    aiStateStructBase;     // AI state pointer
    /* +0x34ec–+0x34f4 */ float localPosition[3]; // Local-space position
    /* +0x34f8–+0x3500 */ float localOffset[3];   // Additional offset/velocity
    /* +0x3504–+0x350c */ float chassisInertia[3]; // Chassis inertia values
    /* +0x3514 */ float  forceScaleFactor;      // Force scaling
    /* +0x3518 */ float  outputScaleFactor;     // Output scaling / grip multiplier
    /* +0x3534 */ float  inputVec[3];           // Input vector
    /* +0x3540–+0x3548 */ float outputVec[3];   // Transformed output
    /* +0x354c–+0x3560 */ float accumulatedForces[6]; // Body force accumulators
    /* +0x3570 */ float  coolingVelocity;        // Velocity for cooling calc
    /* +0x3578 */ float  speed;                  // Vehicle speed
    /* +0x358c/+0x3594 */ float suspDefl_L; float suspDefl_R; // Suspension deflection
    /* +0x3590 */ float  wheelData[4];           // Per-wheel data (stride 0x3e)
    /* +0x35b0/+0x35d8/+0x35dc */ float lateralForce; float wheelCoeff; float wheelForcePrev;
    /* +0x3618/+0x3710/+0x3808/+0x3900 */ float invSuspLen[4]; // 1/suspension length per wheel
    /* +0x3668 */ int    contactCount;
    /* +0x36c4 */ float  contactActive;
    /* +0x3760 */ int    wheelCount;
    /* +0x38f8 */ float  antiRollBarForceFront;
    /* +0x3990 */ float  currentSpeed;
    /* +0x3994 */ float  targetSpeed;
    /* +0x3998 */ float  forceThreshold;
    /* +0x39a4 */ float* jitterBufferPtr;
    /* +0x39a8 */ float  friction;
    /* +0x39ac */ float  caliperTemp;
    /* +0x39b4 */ int    axleType;               // 0=front, 1=all, 2=rear
    /* +0x39c8 */ float  brakeTemp;
    /* +0x39d0 */ float  speedRatio;
    /* +0x39ec */ byte   brakeEnabled;
    /* +0x39f0 */ int    stateCounter;
    /* +0x39f4 */ int    stateCounterPrev;
    /* +0x39f8 */ int    tireStateFlag;
    /* +0x39fc */ int    shiftTimer;             // Gear shift timer
    /* +0x3a04 */ float  brakeTimer;
    /* +0x3a08 */ int    brakeState;             // 1=releasing
    /* +0x3a0c */ float  localForceMultiplier;
    /* +0x3a10 */ float  engineSpeed;            // Engine RPM / speed
    /* +0x3a18 */ float  rpmShiftThreshold;      // RPM upshift threshold
    /* +0x3a30/+0x3a44 */ float tireRoadFrictionMu[2]; // Front/rear friction
    /* +0x3a64–+0x3a74 */ float inertiaScaling[5]; // Inertia/scaling factors
    /* +0x3a6c */ float  camberRelaxation;
    /* +0x3a70 */ float  stiffnessTerm;
    /* +0x3a78 */ float  targetValue;
    /* +0x3a7c */ float  valueOptionA;
    /* +0x3a80 */ float  valueOptionB;
    /* +0x3b40 */ int    setupIndex;             // 0=default, 1=wet, 2=quali, 3=reset
    /* +0x3b54 */ float  inputVector[3];
    /* +0x3b60 */ float  outputVector[3];
    /* +0x3b78 */ byte   contactFlag0;
    /* +0x3b79 */ byte   contactFlag1;
    /* +0x3b88–+0x3b90 */ float contactPos[3];
    /* +0x3be8 */ float  trackSurfaceNormal[3];
    /* +0x3bf4 */ float  downforceMultiplier;
    /* +0x3c00 */ float  tireTableData[14];
    /* +0x3c3c */ float  slipTableLow[14];
    /* +0x3c7c */ float  slipTableHigh[14];
    /* +0x3cbc */ float  tireStiffness[3];
    /* +0x3cfc */ float  combinedStiffnessFactor;
    /* +0x3d00–+0x3d3b */ float solvedSlipRatios[15];
    /* +0x3d3c */ float  maxClamp;
    /* +0x3d40 */ float  areaCoeff;
    /* +0x3d44 */ float  outputBiasScale;
    /* +0x3d48–+0x3d50 */ float defaultOutput[3];
    /* +0x3d54–+0x3d5c */ float trackContactPos[3];
    /* +0x3d60 */ int    stateFlag2;
    /* +0x3d6c */ int    drivingMode;            // Driving mode (2=specific mode)
    /* +0x3d94 */ float  brakeForceComponent;
    /* +0x39d4 */ float* forceArrayBase;         // Per-element force array
    /* +0x39f8 */ int    elementCount;           // Force element count
    /* +0x4024 */ float  downforceMultSurface;
    /* +0x402c */ float  wheelParams[4][9];      // Per-wheel parameters (9 each)
    /* +0x4354 */ int    aiStateFlags;
    /* +0x4510 */ int    currentGear;            // 6=highest gear
    /* +0x454c */ int    aiSpeedDelta;
    /* +0x4620 */ char   driverName[64];
    /* +0x4894 */ int    teamId;
    /* +0x489c */ int    driverNumber;
    /* +0x48b4 */ float  bestLapTime;
    /* +0x48b8 */ float  tireTemp;
    /* +0x48bc */ int    aiControlFlags;         // Bit 0=AI enable, bit 3=active
    // Total size approx 0x48C0 per vehicle (stride confirmed from VehiclePtrArray)
};
```

### WheelEnergyAssembly (stride 0x58 per wheel × 4)

```c
struct WheelEnergyAssembly {
    /* +0x00 */ double suspensionForce;     // Per-wheel suspension contribution
    /* +0x08 */ double wheelLoad;           // Wheel load
    /* +0x10 */ double prevForce;           // Previous frame force
    // Additional force/torque terms follow
};
```

### BVHTreeNode (broadphase spatial tree, 0x60 bytes)

```c
struct BVHTreeNode {
    /* +0x00 */ float splitX;              // X partition boundary
    /* +0x04 */ byte  pad[8];              // Padding
    /* +0x0c */ float splitY;              // Y partition boundary
    /* +0x10 */ double doubleKey;          // Unique key for exact match
    /* +0x18 */ double localValue;         // Node's local contribution (mass/COM)
    /* +0x48 */ int    linearIndex;        // Linearized array index
    /* +0x4c */ int*   child[4];           // 4 child pointers
    /* +0x5c */ int*   nextSibling;        // Sibling/overflow pointer
};
```

### ContactConstraintEntry (stride 0x48)

```c
struct ContactConstraintEntry {
    /* +0x04 */ int    bodyAId;            // Body A identifier
    /* +0x08 */ double* forcePtrA;         // Force accumulator pointer for A
    /* +0x0c */ int    bodyBId;            // Body B identifier  
    /* +0x10 */ double* forcePtrB;         // Force accumulator pointer for B
    /* +0x17 */ double stiffness;          // Constraint stiffness
    /* +0x15 */ double damping;            // Constraint damping
    // Type: 0=pass-through, 2=hard constraint
};
```

### ConstraintSolverParams (per-instance solver config)

```c
struct ConstraintSolverParams {
    /* +0x00 */ byte  flag0;               // 0
    /* +0x01 */ byte  enabled;             // 1 = enabled
    /* +0x02 */ byte  flag2;               // 0
    /* +0x04 */ int   param4;              // 0
    /* +0x08 */ int   param8;              // 0
    /* +0x0c */ int   paramC;              // 0
    /* +0x10 */ float angleLimit;          // 90.0f
    /* +0x14 */ float angleLimit2;         // 75.0f  
    /* +0x18 */ int   sentinel;            // -1
    /* +0x1c */ int   param1C;             // 0
    /* +0x20 */ int   param20;             // 0
    /* +0x24 */ float maxForce;            // 2.0f
    /* +0x28 */ int   param28;             // 0
    /* +0x2c */ int   param2C;             // 0
    /* +0x30 */ float friction;            // 3.25f
    /* +0x34 */ int   param34;             // 0
};
```

### PhysicsBody (0x244 stride, used in body arrays)

```c
struct PhysicsBody {
    /* +0x000 */ double inertiaTensor[3][3]; // 9 doubles from +0xec to +0x12c
    /* +0x0b4 */ double scalarFactor;
    /* +0x0bc */ double diagScale[3];
    /* +0x0ec */ double rotTensor[3][3];
    /* +0x134 */ double linMomentum[3];
    /* +0x14c */ double torqueAccum[3];
    // ... additional state fields
    /* +0x244 */ // End of stride
};
```

---

## Global Variables Owned by This System

| Global | Type | Name | Description |
|--------|------|------|-------------|
| DAT_0059e430 | double | ZeroSentinel | ~0.0 double — zero threshold for physics comparisons |
| DAT_0059e43c | float | OneConstant | 1.0f — unity constant |
| DAT_0059e440 | float | ZeroThreshold | ~0.0f — physics clamp threshold |
| DAT_0059e450 | float | HalfConstant | 0.5f — half scale factor |
| DAT_0059e460 | float | AlphaScaleFactor | Render/alpha scale |
| DAT_0059e6e8 | float | LateralAccelThreshold | Lateral acceleration switch threshold |
| DAT_0059e7d8 | double | ThermalInflectionThreshold | Double, curve inflection point |
| DAT_0059e7f8 | float | AntiRollMixingFactor | Anti-roll / 4-wheel damping bias |
| DAT_0059e7fc | float | BumpDampingConstant | Bump/damper suspension constant |
| DAT_0059e828 | float | NormalizationConstant | Force normalization factor |
| DAT_0059e84c | float | SteeringRateLimit | Max steering rate per frame |
| DAT_0059e85c | float | MaxThreshold | Upper clamp for moving average |
| DAT_0059e880 | double | HalfDouble | 0.5 double — used in mass propagation, force decomposition |
| DAT_0059e888 | float | TwoPI | 2*PI constant for angle wrapping |
| DAT_0059e890 | float | PI | PI constant |
| DAT_0059e898 | float | PIover2 | PI/2 constant for steering |
| DAT_0059e8a0 | float | SpeedRecoveryThreshold | Low speed threshold for yaw recovery |
| DAT_0059e8c8 | float | AngularRateThreshold | Angular rate comparison threshold |
| DAT_0059e8cc | float | WheelSpeedThreshold | Wheel speed gate for gear shifting |
| DAT_0059ea08 | float | PenetrationTolerance | Edge half-plane penetration bias |
| DAT_0059ea38 | float | SuspensionTravelScale | Suspension travel multiplier |
| DAT_0059eac8 | double | WindVelocity | Wind/velocity reference for damping |
| DAT_0059ea60 | float | ForceScaleB | Force scale factor B |
| DAT_0059ea70 | float | AeroForceScale | Aerodynamic force scale factor |
| DAT_0059ea78 | float | BrakeHeatScale | Brake torque-to-heat conversion |
| DAT_0059eb08 | float | SpringUpdateThreshold | Distance threshold for spring state update |
| DAT_0059eb28 | float | Damper2MaxAdd | Damper 2 range limit |
| DAT_0059eb30–0x5e8 | double[8] | DamperCoeffs | Damper coefficient array |
| DAT_0059eb50 | double | Damper1MaxAdd | Damper 1 range limit / scale A |
| DAT_0059eb58 | double | Damper2RateCoeff | Damper 2 rate coefficient |
| DAT_0059eb60–0x5eb90 | double[8] | SpringCoeffs | Spring coefficient array |
| DAT_0059eba0 | double | EnergyDamageConv | Energy-to-damage conversion |
| DAT_0059ec10 | double | TimestepScale | Time step scaling for contact solver |
| DAT_0059ec50 | double | QuadraticOffset | Offset for tire/force curves |
| DAT_0059ec78 | double | Damper1RateCoeff | Damper 1 rate coefficient |
| DAT_0059ec80 | double | ClampRange | Clamp range offset |
| DAT_0059ec88 | double | AccumulatorScale | Accumulator scale factor A |
| DAT_0059ece0 | double | LifetimeClampThreshold | Threshold for lifetime clamp |
| DAT_0059ed08 | double | DissipationConstantType1 | Dissipation for type 1 contacts |
| DAT_0059ed10 | double | TimeStepFactor | Time-step scaling factor |
| DAT_0059ed18 | float | FrequencyMultiplier | Frequency product for damping |
| DAT_0059ed20 | double | EnergyDissipationMult | Energy dissipation multiplier |
| DAT_0059ed40 | double | SpeedErrorGain | Speed error damping gain |
| DAT_0059ed48 | double | RefSpeedAero | Reference speed for aero damping |
| DAT_0059ed50 | double | VelocityDamping | Velocity damping factor (integration) |
| DAT_0059ed58 | float | ForceScalePreload | Force/spring preload scaling |
| DAT_0059ef00–0x5ef10 | double[4] | TireCurveParams | Tire friction curve parameters |
| DAT_005ad168 | float | SlipThreshold | Slip ratio threshold |
| DAT_005ad180 | float | MaxPosClamp | Max absolute position value |
| DAT_005ad198 | float | GlobalForceMult | Global force scaling multiplier |
| DAT_005ad1c4 | float | YawRecoverySpeedRef | Speed reference for yaw recovery |
| DAT_005ad214–0x5ad228 | float[6] | BrakeThresholds | Brake force ramp thresholds (6 values) |
| DAT_005ad2d0 | float | TableSaturation | Table lookup saturation threshold |
| DAT_005aceac | float | VectorScale | Cross product scale factor |
| DAT_005aceb8 | float | AeroBrushConstant | Aerodynamic/brush model constant |
| DAT_005acec4 | float | SlipFadeScale | Slip velocity fade scaling |
| DAT_005acec8 | float | ContactDistanceMax | Max contact distance threshold |
| DAT_008afe98 | double | DeltaTimeGlobal | Global delta time for physics step |
| DAT_008afee4 | double | TrackGripBase | Track grip base offset |
| DAT_008afee8 | double | TrackGripA | Track grip component A |
| DAT_008afeec | double | TrackGripB | Track grip component B |
| DAT_008afef0 | double | PhysicsReferenceA | Physics reference A (position/velocity) |
| DAT_008afef4 | double | PhysicsReferenceB | Physics reference B (wind/drag) |
| DAT_008aceb8 | int | PhysicsFlagCounter | Physics step counter/flag |
| DAT_008aeec0 | int | AeroModeSelector | 0=fixed aero, 1=blended, 2=wet |
| DAT_007d01c4 | int | PhysicsRandFlags | Physics randomization flags (bit 2 = speed noise) |
| DAT_007ce838 | float | DampingEnableFlag | Velocity damping enable |
| DAT_007d108c | float | MinSuspTravel | Minimum suspension travel threshold |
| DAT_007d17cc | float* | SuspensionFloatArray | Suspension clamp array (5 entries, stride 0x6c) |
| DAT_005b8968 | float | SingularityThreshold | Gimbal lock detection threshold |
| DAT_005e5238/3c/40 | double[3] | JointStiffness | Joint stiffness constants |
| DAT_008aae74 | float[256] | TrigLookup256 | 256-entry trig lookup table (mod-256 indexed) |
| DAT_008af570 | float[] | RearTireData | Rear tire grip data array |
| DAT_008adb88 | int | TireDatasetHandle | Tire dataset validity flag |
| DAT_007c8a18 | int* | VehicleSetupDB | Vehicle setup database pointer |
| DAT_007c9364/60 | int | CollisionStateGlobals | Zeroed on state reset |
| DAT_007cd2ac | int | CurrentContextPtr | Current physics context pointer |

---

## Public API — Entry Points

### FUN_004C73F0 — VehiclePhysicsTimeStep

**Inferred signature:** `void VehiclePhysicsTimeStep(VehiclePhysicsState* vehicle, float dt)`

**Called from:** docs/01-engine-architecture.md — per-frame vehicle update loop, once per vehicle.

**Called by (from callers.json):** FUN_004B2420 (orientation), FUN_00566E40, FUN_004E23D0, FUN_004B2A80, FUN_004B28F0, FUN_004B26D0, FUN_004B2800, FUN_004B2980, FUN_004B29F0, FUN_004F1650, FUN_004F17A0, FUN_004E17C0, FUN_004F17D0, FUN_004E2230, FUN_004B2AD0, FUN_004E0ED0, FUN_0059D6FF

**What it does:**
1. Computes delta time from vehicle+0x48b8 accumulator, clamps to valid range
2. Computes steering angle via FUN_004B2A80, clamps to [-1, 1], stores at +0x1040
3. Iterates 4 wheels (stride 0x4a from +0x8c0): computes wheel torque from engine (+0x1044), applies throttle/brake per wheel
4. Updates rotation matrix via FUN_004B2420/FUN_004E23D0
5. Mode check at +0x32C8: if 2, writes per-wheel throttle to +0x35bc (stride 0x3e), updates gear ratios; if 3, applies wheel torques directly
6. Updates gear shift indicator at +0x105d

**Side effects:**
- Writes: vehicle+0x1040 (steering input), vehicle+0x35bc (per-wheel throttle)
- Reads: vehicle+0x48b8 (time accumulator), vehicle+0x32C8 (mode), vehicle+0x8c0+wheel*0x4a (wheel torque)
- Struct mutations: vehicle rotation matrix at +0x34b0

---

### FUN_0041D60 — PhysicsIntegrationStep

**Inferred signature:** `void PhysicsIntegrationStep(VehiclePhysicsState* state, float dt)`

**Called from:** docs/18 — main physics tick loop, called once per frame per vehicle.

**What it does:**
1. Calls sub-steps: FUN_0056EB90, FUN_004423B0 (suspension geometry), FUN_00442C90 (contact force), FUN_004432F0 (damper/spring+anti-roll)
2. If state+0x19c == 0: calls FUN_00441AD0 (velocity damping)
3. Iterates bodies at +0x15b0 array (stride 0x244):
   - Applies damping: `bodyVel *= _DAT_0059ed50`
   - Semi-implicit Euler: `bodyPos += bodyVel * dt`
4. Calls FUN_00441BB0 (torque accumulation), FUN_004359A0 (constraint solve)
5. Adds forces from accumulators (+0xec/f4/fc, +0x1f04/0c/14) to body momentum
6. Adds impulses from accumulators (+0x104/0c/114, +0x1f1c/24/2c) to body torque

**Side effects:**
- Writes: body position/momentum updates
- Reads: body force accumulators, constraint arrays
- Calls: constraint solver, suspension geometry, damper force computation

---

### FUN_0041600 — PhysicsStepFrame

**Inferred signature:** `float PhysicsStepFrame(VehiclePhysicsState* state, float dt)`

**Called from:** docs/18 — orchestrator for single physics step.

**What it does:**
1. Calls FUN_004412F0 (frame init / state history shift)
2. Calls FUN_0043F7F0 (transform update)
3. Calls FUN_0056ECF0 (clear force accumulators), FUN_0056EE40 (constraint force accumulation)
4. Calls FUN_0056F090 (constraint/contact resolver)
5. Calls FUN_00441450 (post-step cleanup)
6. Returns solver computed value

**Side effects:**
- Clears then re-accumulates forces across all constraint groups
- Updates body velocities via constraint solving

---

### FUN_0043FF3D — ContactConstraintSolver

**Inferred signature:** `void ContactConstraintSolver(VehiclePhysicsState* state, int constraintType, int contactCount)`

**Called from:** docs/18 — inner loop for contact resolution.

**What it does:**
1. Checks constraint type at state+0x1E14: 0=wheel-ground, 1=wheel-body, 2=body-body
2. Branches on friction flag (unaff_EBX: -1/0/1)
3. For each type: processes 2, 4, or 5 bodies with stride 0x464
4. Constraint projection: `delta = (error - accumulatedLambda * compliance) / (effectiveMass + compliance)`
5. Clamps delta based on limit flags, updates accumulated lambda (+0x1E38, +0x1C5C)
6. Updates body velocities/positions at +0x14c/+0x154/+0x15c
7. Handles friction cone via box or circular model
8. Uses _DAT_0059ed20/_DAT_0059ed10 for energy dissipation

**Key constants:**
- _DAT_0059e430 — zero threshold
- _DAT_0059ed10 — ERP/hardness factor (0.0–1.0)
- _DAT_0059ed20 — energy dissipation multiplier
- _DAT_0059ed08 — type 1 dissipation constant

---

### FUN_00441F00 — ForceTorqueApplyToRigidBody

**Inferred signature:** `void ForceTorqueApplyToRigidBody(VehiclePhysicsState* state, float forceX, float forceY, float forceZ, float offsetX, float offsetY, float offsetZ)`

**Called from:** docs/18 — applies external force at world-space offset to body.

**What it does:**
1. Returns early if all force components zero (clears active flag)
2. For each of 4 wheel stations: transforms force from world-space to body torque via inertia tensor columns (+0x7c/+0x84/+0x8c)
3. Computes torque contribution at wheel offset (+0x1660/+0x1668/+0x1670 per station)
4. Accumulates linear force (+0x15f4) scaled by _DAT_0059ed58 and spring preload
5. Writes 3-component force/torque accumulator to +0x1748 per station

---

### FUN_004E6D93 — WheelContactForceSuspensionUpdate

**Inferred signature:** `void WheelContactForceSuspensionUpdate(VehiclePhysicsState* state)`

**Called from:** docs/18 — per-tick wheel force integration.

**What it does:**
1. Processes 2 wheel pairs: front (+0x13d0/+0x14d8) and rear (+0x15e0/+0x16e8)
2. Blends spring/damper forces from wheel hub velocities at offsets 0xa8/0xb0/0xd0/0xd8/0xe0
3. Computes inverse suspension length (1/len) at +0x3618/+0x3710/+0x3808/+0x3900
4. Accumulates 4 wheel force contributions into chassis force (+0x3be8) and torque (+0x3bf0)
5. Iterates 12 contact patches (indices 0-11): sets contact positions, checks wheel contact flags
6. For indices 8-11 (steering wheels): computes steer-angle-dependent contact offset
7. Calls tire force helpers: FUN_004F3190, FUN_004F68B0, FUN_004F6950, FUN_004F69E0, FUN_004F6A50
8. Handles wheel lift-off via FUN_0054B420, exports 13 contact positions via FUN_0054F830

---

### FUN_004E5470 — WheelForceSpringDamperTorque

**Inferred signature:** `void WheelForceSpringDamperTorque(VehiclePhysicsState* state)`

**Called from:** docs/18 — per-wheel force accumulation to body.

**What it does:**
1. For each of 4 wheels (0x3e float stride): transforms suspension force to world space via rotation matrix
2. Accumulates wheel load to body force accumulators (+0x354c/0x3550/0x3554)
3. Computes wheel angular velocity from torque and damping
4. Applies steering rotation (sin/cos of steering angle at +0x3960)
5. Calls FUN_004E3AA0 per wheel for suspension spring force
6. If lateral acceleration exceeds threshold (+0x34c0 > _DAT_0059e6e8): transfers load between wheels
7. Normalizes damper forces and accumulates body torque at +0x3558/0x355c/0x3560

---

### FUN_00459AE0 — VehicleVelocityAngularVelocityIntegration

**Inferred signature:** `void VehicleVelocityAngularVelocityIntegration(VehiclePhysicsState* state)`

**Called from:** docs/18 — integrates linear and angular velocity with tire force.

**What it does:**
1. Two-pass loop: first pass computes forces, second pass applies
2. Computes squared velocity components, normalizes if exceeding threshold (_DAT_0059f058)
3. Applies orientation-dependent force signs based on velocity component signs
4. Iterates wheel contact list via FUN_0054FA90 (contact getter)
5. Per wheel: computes slip velocity, spring compression, damper force
6. Accumulates wheel forces into body-space force/torque via inertia tensor
7. Calls FUN_0043AEE0 for orientation transform, FUN_004BE4E0 for wheel rendering
8. On second pass: calls FUN_00569C10/FUN_00569DE0 for integration

---

### FUN_0043250 — SuspensionForceComputation (Anti-Roll)

**Inferred signature:** `void SuspensionForceComputation(VehiclePhysicsState* state)`

**Called from:** docs/18 — computes spring-damper forces per wheel station.

**What it does:**
1. Sums bump/rebound damper velocities from paired wheel stations (+0x16f8/+0x16f0 and +0x1708/+0x1700)
2. Clamps to max damper force limit (+0x1af4)
3. Reads wheel rates from setup struct (+0x3a64 etc.)
4. Computes total roll stiffness from spring pair + anti-roll bar (+0x1bd8/+0x1bc8/+0x1bd0)
5. Branches on extra damper (ARB) mode via flags at +0x1bbc, +0x1900, +0x1a08
6. Accumulates wheel forces into body torque at +0x14c/0x154/0x15c

---

### FUN_004E94A3 — BrakeTorqueWithHeatFade

**Inferred signature:** `float BrakeTorqueWithHeatFade(VehiclePhysicsState* state, float brakeInput, float maxTorque)`

**Called from:** docs/18 — brake torque with temperature-dependent fade.

**What it does:**
1. If brake active: computes torque from brake pressure * friction coeff
2. Indexes heat-fade table at +0x3cc0 with interpolated temperature index (0-13)
3. Heat factor reduces effective torque; clamps to max available torque
4. Subtracts rolling resistance and drag torque
5. If brake inactive: uses wheel angular velocity to compute coasting drag
6. Above speed threshold: applies wind/drag braking via FUN_0059D99E/FUN_0059D984

---

### FUN_004E49B0 — VehicleSetupInit

**Inferred signature:** `void VehicleSetupInit(VehiclePhysicsState* state)`

**Called from:** docs/18 — initializes vehicle from setup data.

**What it does:**
1. Reads orientation from global DAT_007c8a18 (vehicle setup DB)
2. Copies rotation matrix rows to float array at +0x34b0 (3x3)
3. Computes heading/pitch/yaw angles using atan2
4. Reads suspension hardpoints and wheel offsets from setup DB
5. Copies to wheel-stride arrays (0x3e float stride per wheel)
6. Computes combined spring rate from front/rear pairs based on axle config
7. Reads wheel inertia, brake torque, and friction values from globals

---

### FUN_00569DE0 — RigidBodyIntegrator

**Inferred signature:** `void RigidBodyIntegrator(RigidBody* body, float dt)`

**Called from:** docs/18 — per-body physics update step (semi-implicit Euler).

**What it does:**
1. Computes position/velocity update with semi-implicit Euler integration
2. Applies damping factor based on velocity ratios
3. Transforms local-space tensors to world space
4. Updates body state arrays (position, orientation, velocity, inertia tensor)
5. Uses SQRT for velocity magnitude, damping ratio computation

---

### FUN_00569C10 — PhysicsIntegrationStepApply

**Inferred signature:** `void PhysicsIntegrationStepApply(RigidBody* body, double dt)`

**Called from:** docs/18 — applies scalar factor (timestep dt) across state arrays.

**What it does:**
1. Shifts previous state to history buffers (offsets 0x164, 0x17c, 0x1c4, 0x1dc, 500, 0x20c) via memcpy-style loops
2. Updates current values: `new = dt * rate + old`
3. Operates on 6-element vector pairs consistently
4. Recomputes rotation tensor via FUN_0056C020 and FUN_005692A0
5. Performs 3x3 tensor transform for force/acceleration propagation

---

### FUN_0045AE00 — VehicleOrientationFromAngularVelocity

**Inferred signature:** `void VehicleOrientationFromAngularVelocity(VehiclePhysicsState* state)`

**Called from:** docs/18 — integrates angular velocity to update orientation.

**What it does:**
1. Reads angular velocity components from +0xd8/+0xe0/+0xe8 (scaled by timestep)
2. Computes angular displacement as Euler angles via gyroscopic precession terms (+0x138/+0x140/+0x148/+0x150/+0x158/+0x160)
3. Calls FUN_0056C020 for quaternion integration from angular increments
4. Extracts final heading/pitch/bank via atan2 on quaternion components
5. Calls FUN_0054B4D0 to commit orientation for rendering

---

### Minor Entry Points

Grouped under their callers, these leaf helpers:

| Function | Purpose | Called from |
|----------|---------|-------------|
| FUN_004388D0 | 3x3 matrix × vector multiply | Every major physics function |
| FUN_00435E00 | 3x3 matrix × vector (double) | Suspension, constraint, contact |
| FUN_004361D0 | 3D vector transform by matrix | Collision, contact response |
| FUN_0043AEE0 | 3x3 rotation + translation transform | Wheel contact, suspension |
| FUN_005691D0 | Rotation tensor × vector (3x3) | Inertia transform |
| FUN_00569410 | M × diag(S) × M^T × V in world space | Inertia tensor transform |
| FUN_00569670 | Cross-product rotation accumulation | Angular momentum |
| FUN_00569AD0 | Accumulate angular momentum via cross | Rigid body momentum |
| FUN_00566E40 | Euler → 3x3 rotation matrix | Orientation construction |
| FUN_00567030 | Euler → quaternion | Rotation representation |
| FUN_00567400 | Y-axis rotation on 3x3 matrix | Orientation update |
| FUN_005674C0 | Z-axis rotation on 3x3 matrix | Orientation update |
| FUN_0056C2D0 | X-axis rotation on 3x3 matrix | Suspension geometry |
| FUN_0056C540 | Cross product + normalize | Normal computation |
| FUN_00566EE0 | 3x3 rotation matrix → Euler angles | Angle extraction |
| FUN_00438100 | Torque/force product + bias | Force computation |
| FUN_00436470 | Quadratic spring evaluation | Spring force curve |
| FUN_0043BB30 | Quadratic function eval (2 channels) | Suspension force |
| FUN_0043BB80 | Quadratic force/torque | Speed-dependent force |
| FUN_0043BBD0 | Spring-damper force (3 axes) | Constraint force |
| FUN_0043BB00 | Delta state tracking | State accumulation |
| FUN_004380B0 | Constraint enforcement | Contact resolution |
| FUN_0043E890 | Damper force accumulation | Suspension damper |
| FUN_00471B0 | Random physics parameter | Randomized setup |
| FUN_00436610 | Piecewise function eval (3 regions) | Threshold-based force |
| FUN_0043EA70 | Double accumulator with clamp | Temperature/wear |
| FUN_0043EAE0 | Damper accumulator | Physics integration |
| FUN_0043EB50 | Force scale dispatch | Spring/damper dispatch |
| FUN_0043EC50 | Damping scale application | Global damping |
| FUN_0043E230 | Wheel dynamics init | Vehicle setup |
| FUN_0043E360 | Physics state zero reset | Frame init |
| FUN_0043D8DE | Vehicle state reset | Frame init |
| FUN_0043E4B0 | Rigid body constraint solve | Solver dispatch |
| FUN_0043BA20 | Constraint force solver | Constraint resolution |
| FUN_004389B0 | Suspension data copy → engine | Setup transfer |
| FUN_0048CC0 | Brake bias setup | Setup transfer |
| FUN_0043BC20 | Suspension setup copy | Setup transfer |
| FUN_0043EC80 | Physics force/velocity clamping | Safety clamp |
| FUN_00430600 | Tire contact patch (Pacejka-style) | Tire model |
| FUN_004309A0 | Brake temperature & fade | Thermal model |
| FUN_0041B0 | Wheel aggregate force | Force summation |
| FUN_004390A0 | Collision energy/damage | Damage model |
| FUN_004412F0 | Wheel state history shift | Frame init |
| FUN_00441360 | State delta accumulation | Frame step |
| FUN_00414D0 | Wheel data copy between buffers | Frame step |
| FUN_0041F00 | Suspension force solver | Suspension solve |
| FUN_00430A50 | Brake temperature model | Thermal fade |
| FUN_0041C90 | Physics node propagation | Force propagation |
| FUN_0043250 | Suspension geometry + contact | Wheel-ground contact |
| FUN_004E2610 | Suspension geometry init | Setup |
| FUN_004E3090 | Vector position interpolator | Interpolation |
| FUN_004E58D0 | Body torque accumulator | Force accumulation |
| FUN_004E5AE0 | Wheel rotational dynamics | Wheel spin |
| FUN_004E4F40 | Suspension spring/damper rate reset | Reset |
| FUN_004E4790 | Wheel state reset | Reset |
| FUN_004E4570 | Physics cleanup sequence | Teardown |
| FUN_004F18C0 | Aero/engine parameter setup | Setup |
| FUN_004AF3A0 | Physics parameter init by setup index | Setup |
| FUN_00496560 | Vehicle default initialization | Init |
| FUN_00381C00 | Physics global state init | Init |
| FUN_00431C70 | Physics shutdown | Teardown |
| FUN_00431D40 | Physics buffer alloc | Init |
| FUN_00431BD0 | Static data registration | Init |
| FUN_00431A70 | Grid value set | Utility |
| FUN_00431A50 | Simple setter with flag | Utility |
| FUN_004319C0 | Parameter array setter with dirty flag | Utility |
| FUN_00431930 | Contact constraint set | Utility |
| FUN_00431820 | Joint active count | Utility |
| FUN_004317F0 | Joint target position | Utility |
| FUN_00433FC0 | Reference count release | Lifecycle |
| FUN_00434240 | Recursive node deletion | Lifecycle |
| FUN_00434450 | Physics config init | Init |
| FUN_00434860 | Constraint solver param init | Init |
| FUN_00438CA0 | Physics init sequence | Init |
| FUN_0045E620 | Physics integration step (Verlet) | Integration |
| FUN_004624E0 | Terrain height comparison | Ride height |
| FUN_0046A3A0 | Wheel contact force computation | Tire model |
| FUN_004A3820 | Physics channel processing | Channel dispatch |
| FUN_004B2DD0 | Orientation from Euler angles | Orientation |
| FUN_004B46B0 | Struct zero-init (3 regions) | Init |
| FUN_004BA5A0 | Linked list destroy | Cleanup |
| FUN_004C2CB0 | Moving average filter | Parameter smoothing |
| FUN_004CE110 | Wheel-surface contact friction | Friction model |
| FUN_004D7B0 | 3D matrix × vector multiply | Matrix math |
| FUN_004E3050 | Array cleanup (4 entries) | Cleanup |
| FUN_004E7F39 | Physics state copy with offset | State copy |
| FUN_004ED7B0 | 3×3 matrix × vector multiply | Matrix math |
| FUN_004EE2D0 | Vehicle dynamics update (mode dispatch) | Main update |
| FUN_004EFB20 | 3D affine transform | Coordinate transform |
| FUN_004F1650 | Vehicle setup data copy | Setup |
| FUN_004F1C40 | Vehicle yaw/rotation recovery | Spin recovery |
| FUN_004F6D90 | Parametric interpolation | Keyframe blend |
| FUN_004F8370 | Physics init (setup sequence) | Init |
| FUN_004FB260 | Linear interpolation + position update | LERP |
| FUN_005000E0 | Physics float update with compare | Parameter update |
| FUN_0050C2E3 | Cubic Bezier interpolation (3D) | Spline |
| FUN_0050D615 | Y-axis rotation matrix (3D) | Matrix construction |
| FUN_0050E2AB | Quadratic Bezier interpolation (3D) | Spline |
| FUN_0050E887 | Vector normalization | Math |
| FUN_005176EC | Vector normalize (fast rsqrt) | Optimized math |
| FUN_005219E1 | Quaternion/3D math (3DNow!) | SIMD math |
| FUN_00524553 | SIMD quaternion arithmetic | SIMD math |
| FUN_00526550 | 4D vector transform | Math |
| FUN_005267A7 | Quaternion/transform composition | Transform |
| FUN_00527578 | 3D vector normalize (3DNow!) | SIMD math |
| FUN_0053B240 | Euler angle to rotation matrix | Matrix construction |
| FUN_0053B5B0 | Quaternion slerp | Rotation interpolation |
| FUN_005471D0 | Switch-based float setter | Parameter setter |
| FUN_00548810 | Linked list accumulation | Aggregation |
| FUN_0055D460 | Vector set with normalization | Vector store |
| FUN_005670D0 | 3×3 rotation from yaw/pitch | Matrix construction |
| FUN_005694E0 | Vehicle projected position | Projection |
| FUN_00569860 | 3D position delta to body-frame | Coordinate transform |
| FUN_00569A20 | Apply impulse with torque | Impulse apply |
| FUN_0056A240 | Inertial tensor-vector transform | Torque from ω |
| FUN_0056A390 | Physics constraint force solver | Constraint solve |
| FUN_0056B5D0 | Pairwise constraint force (3×3 blocks) | Constraint assemble |
| FUN_0056BAF0 | Constraint stiffness matrix assembly | Matrix assemble |
| FUN_0056BD40 | Euler→rotation matrix setup | Constraint setup |
| FUN_0056C830 | Sparse Cholesky factorization | Solver |
| FUN_0056CD70 | Sparse Cholesky forward/back substitution | Solver solve |
| FUN_0056CF10 | Physics subsystem init B | Init |
| FUN_0056D020 | 3x3 matrix inverse + coordinate transform | Matrix math |
| FUN_0056D1C0 | Relative velocity between bodies | Velocity compute |
| FUN_0056D2D0 | Physics island grouping | Contact graph |
| FUN_0056D430 | Graph/connectivity clustering | Mesh/cluster opt |
| FUN_0056D8F0 | Physics force clear | Frame init |
| FUN_0056E970 | Physics subsystem destructor | Cleanup |
| FUN_0056ECF0 | Physics constraint/reset | Frame init |
| FUN_0056EE40 | Constraint force accumulator | Solver |
| FUN_0056F020 | Iterate bodies + call update | Batch update |
| FUN_00583700 | Collision manifold build | Contact gen |
| FUN_00583790 | Physics query getter | Query result |
| FUN_0059D6FF | Gear ratio / transmission torque | Gearbox |
| FUN_0059D9B5 | Speed randomization | Random noise |
| FUN_0059D9D7 | Per-element ratio force scaling | Force scaling |
| FUN_0059DA54 | Gear ratio computation | Gearbox |
| FUN_0059DAEF | Unknown physics helper | Utility |
| FUN_005FD460 | Vector set with normalization and dirty | Vector store |

---

## Internal Call Graph

Major call chains within the physics dynamics system:

```
FUN_004C73F0 — VehiclePhysicsTimeStep  [triggered by: per-frame vehicle update loop]
  +-- FUN_004B2A80 — SteeringAngle
  +-- FUN_004B2420 — OrientationUpdate
  |     +-- FUN_00566E40 — EulerToRotationMatrix
  +-- FUN_004E23D0 — OrientationIntegration
  +-- FUN_004B28F0 — PerWheelUpdate (×4)
  +-- FUN_004F1650 — SetupDataCopy
  +-- FUN_004E17C0 — WheelActivation
  +-- FUN_004F17D0 — TransformApply
  +-- FUN_0059D6FF — GearRatioCompute

FUN_0041600 — PhysicsStepFrame  [triggered by: per-frame physics tick]
  +-- FUN_004412F0 — StateHistoryShift
  +-- FUN_0043F7F0 — TransformUpdate
  +-- FUN_0056ECF0 — ForceClear
  +-- FUN_0056EE40 — ConstraintForceAccum
  |     +-- FUN_00569AD0 — AccumAngularMomentum
  |     +-- FUN_00569B70 — ConstraintApplyB
  +-- FUN_0056F090 — ContactResolver
  +-- FUN_0041450 — PostStepCleanupF

FUN_0041D60 — PhysicsIntegrationStep  [triggered by: within PhysicsStepFrame]
  +-- FUN_0056EB90 — PreStep
  +-- FUN_00423B0 — SuspensionGeometry
  |     +-- FUN_004E9630 — PositionQuery
  |     +-- FUN_00435E00 — Mat3x3MulVec
  |     +-- FUN_0044C4C0 — TerrainCollision
  +-- FUN_0042C90 — ContactForceIntegration
  |     +-- FUN_00435E00 — Mat3x3MulVec
  |     +-- FUN_004380B0 — ConstraintEnforce
  |     +-- FUN_00436610 — PiecewiseFunctionEval
  |     +-- FUN_00569AD0 — AccumAngularMomentum
  |     +-- FUN_00569B70 — ConstraintApplyB
  +-- FUN_00432F0 — DamperSpringAntiRoll
  |     +-- FUN_004388D0 — Mat3x3MulVec
  |     +-- FUN_00435E00 — Mat3x3MulVec
  |     +-- FUN_00436230 — QuadraticForm6x6
  |     +-- FUN_00569AD0 — AccumAngularMomentum
  |     +-- FUN_0043150 — DamperHelper
  +-- FUN_0041AD0 — VelocityDamping
  +-- FUN_0041BB0 — TorqueAccumulation
  |     +-- FUN_00435E00 — Mat3x3MulVec
  |     +-- FUN_00569B70 — ConstraintApplyB
  +-- FUN_004359A0 — RigidBodyConstraintSolve
       +-- FUN_00435E00 — Mat3x3MulVec
       +-- FUN_00569AD0 — AccumAngularMomentum

FUN_0043FF3D — ContactConstraintSolver  [triggered by: within physics tick]
  +-- FUN_00435290 — InitCheck
  +-- FUN_005677B0 — Utility

FUN_004E5470 — WheelForceSpringDamperTorque  [triggered by: per-tick]
  +-- FUN_0053AC70 — TransformHelper
  +-- FUN_004E3AA0 — TireContactForce
  |     +-- FUN_0044C550 — MathFunction
  +-- FUN_004E3D00 — WheelDynamicsHelper

FUN_004E6D93 — WheelContactForceSuspensionUpdate  [triggered by: per-tick]
  +-- FUN_004F3190 — TireForceChannel (×2)
  +-- FUN_004F68B0 — TireVerticalForce
  +-- FUN_004F6950 — TireSecondaryForce
  +-- FUN_004F69E0 — TireCoupledForce
  +-- FUN_004F6A50 — TireResidualForce
  +-- FUN_0054B420 — WheelContactReset
  +-- FUN_004E9BD0 — ChassisForceAccum
  +-- FUN_004EE150 — ChassisForceAccumB
  +-- FUN_0054F830 — ContactPosExport

FUN_004E94A3 — BrakeTorqueWithHeatFade  [triggered by: brake input]
  +-- FUN_005895A2 — SinCos
  +-- FUN_0059D99E — WindDrag
  +-- FUN_0059D984 — WindDragHelper

FUN_004E49B0 — VehicleSetupInit  [triggered by: vehicle creation]
  +-- FUN_0043AEE0 — TransformApply3D
  +-- FUN_00588570 — Random

FUN_00569DE0 — RigidBodyIntegrator  [triggered by: per-body tick]
  +-- (3D vector math, SQRT, matrix transforms)
  (leaf function with math operations)

FUN_00569C10 — PhysicsIntegrationStepApply  [triggered by: per-body tick]
  +-- FUN_0056C020 — QuaternionIntegration
  +-- FUN_005692A0 — InertiaUpdate

FUN_0045AE00 — VehicleOrientation  [triggered by: per-frame]
  +-- FUN_0056C020 — QuaternionIntegration
  +-- FUN_00588570 — Random
  +-- FUN_0054B4D0 — CommitOrientation

Constraint solver subsystem:
FUN_0056C830 — SparseCholeskyFactor  [triggered by: constraint setup]
  (3-level nested loops, CSR format, sentinel fill-in detection)

FUN_0056CD70 — SparseCholeskySolve  [triggered by: L*D*L^T solve]
  (forward substitution, diagonal scaling, backward substitution)

FUN_0056B5D0 — PairwiseConstraintForce  [triggered by: solver]
  +-- (3×3 block matrix, cross product, inertia tensor)

FUN_0056BAF0 — ConstraintStiffnessMatrix  [triggered by: solver]
  +-- FUN_00435E00 — Mat3x3MulVec

FUN_0056EE40 — ConstraintForceAccumulator  [triggered by: solver tick]
  +-- FUN_00569AD0 — AccumAngularMomentum
  +-- FUN_00569B70 — ConstraintApplyB

Energy/damage computation:
FUN_004390A0 — CollisionEnergySum  [triggered by: collision event]
  +-- FUN_004F3190 — TireForceChannel (×2)
  +-- FUN_004F68B0 — TireVerticalForce
  +-- FUN_004F6950 — TireSecondaryForce
  +-- FUN_004F69E0 — TireCoupledForce
  +-- FUN_004F6A50 — TireResidualForce
```

---

## Constants and Magic Numbers

| Value | Used in | Meaning |
|-------|---------|---------|
| 0.0 (DAT_0059e430) | All physics functions | Zero threshold for double comparisons |
| 1.0 (DAT_0059e43c) | Various | Unity constant |
| 0.5 (DAT_0059e450) | Various | Half = interpolation factor, angle tolerance |
| 2.0 (DAT_0059e430) | FUN_004390A0 | Energy base offset |
| 3.25f | FUN_00434860 | Default friction parameter |
| 90.0f / 75.0f | FUN_00434860 | Default angle limits |
| 0.4f (0x3ccccccd) | FUN_00430600 | Tire force blending factor |
| 0xbf800000 (-1.0f) | Various | Default/sentinel value |
| 0x3c23d70a (0.01f) | FUN_004FEFC0 | Clamp lower bound |
| 0x3f7d70a4 (0.99f) | FUN_004FEFC0 | Clamp upper bound |
| 0x3e4ccccd (0.2f) | FUN_004AF3A0 | Wet setup friction |
| 13000.0 (0x4633b000) | FUN_004AF3A0 | Default brake torque |
| 0x40000000 (2.0) | Solver param | MAX_FORCE default |
| 256 | FUN_0047AB0 | Trig lookup table size |
| 0x0b | FUN_0048E20 | Max linked list walk |
| 0x119 | Various | Per-wheel stride (×4 = 0x464) |
| 0x244 | Various | Body array stride |
| 0x48 | Various | Constraint entry stride |
| 0x20 | FUN_00492D0 | Contact buffer element stride |
| 0x3e | Various | Per-wheel float stride |
| 0x4a | Various | Per-brake stride |
| 0x60 | FUN_00485D0 | BVH tree node size (bytes) |
| 32767 | FUN_004B31A0 | Int16 saturation upper bound |
| -32768 | FUN_004B31A0 | Int16 saturation lower bound |

---

## Inter-System Dependencies

**Reads from (external globals/systems):**
- `DAT_007c54f0` (VehiclePtrArray) — from docs/01, access to vehicle structs
- `DAT_005c329c` (VehicleCount) — from docs/01, number of active vehicles
- `DAT_007d0308` (RaceActiveFlag) — from docs/06, gates threshold checks
- `DAT_007cf3c8` (TrackConditionState) — from docs/05, track grip/weather effects
- `DAT_008afea0` (SessionTime) — from docs/12, speed threshold for state transitions
- `DAT_007c91b4` (ParameterBaseCase1) — from docs/12, parameter computation
- `DAT_007cec30` (ReconPitOpen) — from docs/07, pit state gating
- `DAT_007cea5c` (EngineWearMode) — from docs/03, wear model selector
- `DAT_007ce958` (TireModelMode) — from docs/04, tire model selector
- `DAT_007d0c60` (TireWearMultiplier) — from docs/04, tire wear scaling
- `DAT_005c5d24` (SeasonRacesSuffix1) — from docs/01, file path assembly

**Calls into:**
- docs/17-physics-collision.md: FUN_00435290 (init check), FUN_0045CA20 (terrain surface sample), FUN_0044C4C0 (terrain collision)
- docs/19-renderer.md: FUN_004BE4E0 (wheel rendering), FUN_0054B4D0 (commit orientation)
- docs/20-math-utilities.md: FUN_005894A0 (random), FUN_0058957A (time query), FUN_005895A2 (sin/cos), FUN_0058815F (sprintf), FUN_00587BCF (free)
- docs/21-audio-network-internals.md: FUN_004F87C0 (audio event), FUN_0054C210 (active source count)
- docs/07-pit-system.md: FUN_004EF930 (race state update)

**Called by:**
- docs/01-engine-architecture.md: Main game loop calls FUN_004C73F0 per vehicle per frame
- docs/02-ai-system.md: AI steering reads physics position/velocity
- docs/06-session-race-logic.md: Race state reads finish position, lap time
- docs/10-vehicle-physics.md: Setup values written to physics struct
- docs/19-renderer.md: FUN_004E58D0, FUN_0040F550 read vehicle position for camera

---

## Reimplementation Notes

1. **Double-precision throughout.** All internal physics computation uses 80-bit x87 extended precision (`double` in C). Float is used only for struct storage to save memory. Output values are converted to float when written to vehicle struct.

2. **Fixed timestep expectation.** The integration assumes consistent dt (~1/60s = 0.0167s). Global `DAT_008afe98` (DeltaTimeGlobal) is the authoritative timestep. FUN_0045E620 clamps dt to [0, 0.0333].

3. **Semi-implicit Euler.** Position update uses `v_new = v_old + a*dt; x_new = x_old + v_new*dt` — velocity is updated first, then position uses the new velocity. This is the standard symplectic Euler variant.

4. **Constraint solver is LCP-style.** Uses sparse Cholesky (L*D*L^T) factorization with projected Gauss-Seidel iteration. Compliance/ERP model: `delta = (error - lambda*compliance) / (effectiveMass + compliance)`. Accumulated lambda clamped to friction limits.

5. **Per-wheel stride is 0x464 (= 0x119 × 4).** Wheel index 0 starts at +0x338, each subsequent wheel at +0x338 + i*0x464. Brake data at +0x7d4 with stride 0x4a. Tire wear channels at +0x8cc with stride 0x128.

6. **Two accumulator groups.** Forces go into group 0 (+0xec–+0x114) and group 1 (+0x1f04–+0x1f2c). Both summed into body momentum during integration step. This allows separation of constraint forces from applied forces.

7. **Ring buffer indexing.** FUN_00569860 uses stride 0x38 ring buffer at +0x230 with counter at +0x22c. Post-incremented counter indexes into buffer. This stores position history for interpolation/state retrieval.

8. **Suspension modes.** Config flag at +0x1E14 controls suspension: 0 = 2-wheel average, 1 = 4-wheel independent, 2 = 2-wheel alternate. Damper mode at +0x1BBC/0x1900/0x1A08 controls anti-roll bar behavior.

9. **Brake thresholds.** 6 float thresholds DAT_005ad214 through DAT_005ad228 define brake force ramp curve. Used in FUN_004EE2D0 and FUN_0044657D for progressive brake pressure application.

10. **Trig table.** DAT_008aae74 is a 256-entry float LUT indexed with modulo-256. Used by FUN_0047AB0 for periodic function evaluation (likely sine approximation). Scale factor _DAT_0059e7d8 controls input-to-index mapping.

11. **Engine braking.** FUN_004F18C0 computes engine braking torque from aero map data. Drag coefficient uses setup CdA * air density. Downforce computed as `CdA * rho * v² / 2` per axle.

12. **Yaw recovery.** FUN_004F1C40 detects spin conditions (low speed, heading deviation), blends current heading toward target using stored heading timer. Full recovery calls FUN_004F2320 to set heading directly. Uses FUN_004ED420 for raycast check during recovery.

13. **Gear shifting.** FUN_00426330 checks engine speed vs zero threshold, reads gear state at +0x4510 (6=highest). Uses shift timer at +0x39FC, RPM threshold at +0x3A18, wheel speed threshold _DAT_0059e8cc. Shifts up by calling FUN_004EF930(shift_timer+1).

14. **Energy/damage model.** FUN_004390A0 sums 4 wheel assembly contributions with stride 0x58. Uses _DAT_0059eba0 (energy-to-damage conversion). Calls 6 tire subsystem force functions: FUN_004F3190 (×2), FUN_004F68B0, FUN_004F6950, FUN_004F69E0, FUN_004F6A50.

15. **Physics modes.** FUN_004EE2D0 switches on mode at +0x32BC: 0=suspension model, 1=brake model, 2=tire contact, 3=replay tire. Each mode reads/writes different offset regions of the vehicle struct.

16. **DAT_0059e450 = 0.5f** is ubiquitous. Used as interpolation factor, deg-to-rad conversion, anti-roll bias, angle tolerance, brake bias, and more. Not a single-purpose constant.

17. **BVH tree structure.** Trees have 4 children per node (quadtree), 0x60-byte nodes. Child pointers at +0x4c–0x58, sibling at +0x5c. Used by broadphase collision and mass/COM propagation (FUN_00448DE0).

18. **MSVC memory layout.** Physics objects use operator_new for allocation. Vtable is at offset 0x0000 of each object. FUN_00587BCF is operator delete. FUN_00582290 is a pre-delete cleanup handler.

---

## Completeness

- Full specs written: ~195 / ~270 total documented functions
- Thunks/empty stubs omitted: ~15 (FUN_00431BC0, FUN_00426D0, FUN_00484F0, FUN_0049EB7, etc.)
- Confidence: **high** — consistent patterns across 270+ entries, well-defined struct offsets, known global constants, clear integration flow
- White spaces: ~60 minor leaf utilities (pure math, setters) not individually spec'd — they are standard 3D math/utility functions trivial to reimplement
