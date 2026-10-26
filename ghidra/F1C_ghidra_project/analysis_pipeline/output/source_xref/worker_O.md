# Source Cross-Reference: docs/17-physics-collision.md

## RTTI Class Mappings

| rFactor Class | F1C Function(s) | Confidence | Evidence |
|--------------|-----------------|------------|----------|
| `LooseObject` | FUN_004b4b50 (Collision Object List Management), FUN_004b4e10 (Physics Object List Manager) | HIGH | rFactor RTTI has `LooseObject` with subclasses `LooseCone`, `LoosePost`, `LooseSign`, `LooseWheel`, `LooseWing`, `LoosePart`. These are collision-enabled physics objects. F1C collision object list management functions manage linked lists of these proxy objects with stride 0x10 (head/tail/current/count). FUN_004b4e10 references DAT_008ab700/704/708/70c (master physics object chain). |
| `SearchGrid` | FUN_0044a2d0 (BVH Binary Tree Builder), FUN_0044a4b0 (BSPTreeNodeBuilder), FUN_0044a170 (subtree build) | HIGH | rFactor has `SearchGrid` RTTI class from `searchgrid.cpp` source path. The BVH/BSP tree building functions match spatial partitioning for broadphase collision culling using linked-list hierarchy and 14 candidate split positions. |
| `CollObjects` (source) | FUN_0054d080 (Triangle Mesh Face Normal/AABB) | MEDIUM | rFactor source path shows `CollObjects.cpp`. This function processes mesh faces with triangle vertex strides 0x30/0x40, computes face normals via cross product, selects dominant axis. Matches collision mesh building in CollObjects. |
| `DynMan` | FUN_00436870 (Collision Contact Generation and Friction Response), FUN_00454da0, FUN_00455bd0 | MEDIUM | rFactor has `DynMan` RTTI class from `dynman.cpp` source. The contact generation function evaluates Bezier surfaces, computes Coulomb friction, applies impulses to body inertia — this is dynamics-level collision response, likely part of DynMan system. |
| `HDVehicle` (source: `hdvehicle.cpp`) | FUN_004e96c0 (Vehicle Wheel Contact Proximity Check), FUN_004a6b80 (CollisionAvoidanceCheck) | MEDIUM | Vehicle collision feelers and wheel contact checks use vehicle struct offsets (+0x34d4 position, +0x828 wheelActiveFlags). These are called from HDVehicle physics update loop. |
| `Steward` | FUN_00462940 (Collision Event Network Broadcast) | LOW | Broadcasts collision event to network peers via FUN_004b33b0 with collision type 0x20. rFactor has `Steward` as session/race manager. Collision events to network suggest steward-level broadcast. |
| `Weather` | FUN_004628a0 (WeatherSurfaceUpdate) | MEDIUM | rFactor has `Weather` RTTI. This F1C function updates track surface conditions based on rain state — calls rain check, sets track wetness, spawns rain particles. Direct match to weather system that affects collision surface grip. |
| `TvOverlayPageBase` (UI overlay) | FUN_00494a70 (2D Screen Quad Render) | LOW | Renders 2D textured quad for collision visualization overlay. Uses DAT_007cde08 (destination surface), calls D3D render functions. TV overlay system might render collision debug visualization. |

## Parameter-to-Offset Mappings

| Config Param | Section | F1C Struct Offset | Current Name | Proposed Name | Confidence |
|-------------|---------|-------------------|--------------|---------------|------------|
| `FeelerFlags` | HDV:GENERAL | +0x3c (param_1 int) | FeelerFlagsConfig | FeelerFlagsConfig | HIGH — exact match: HDV param directly read by feeler generation code |
| `FeelerFrontLeft` | HDV:GENERAL | +0x870 (float3) | FeelerFrontLeft | FeelerFrontLeftPos | MEDIUM — FUN_004e96c0 uses feeler positions for wheel contact, docs show +0x828 wheelActiveFlags with stride 0x4a |
| `FeelerFrontRight` | HDV:GENERAL | +0x87c | FeelerFrontRight | FeelerFrontRightPos | MEDIUM — symmetric to FeelerFrontLeft |
| `FeelerRearLeft` | HDV:GENERAL | +0x888 | FeelerRearLeft | FeelerRearLeftPos | MEDIUM |
| `FeelerRearRight` | HDV:GENERAL | +0x894 | FeelerRearRight | FeelerRearRightPos | MEDIUM |
| `FeelerFront` | HDV:GENERAL | +0x8a0 | FeelerFront | FeelerFrontCenter | MEDIUM |
| `FeelerRear` | HDV:GENERAL | +0x8ac | FeelerRear | FeelerRearCenter | MEDIUM |
| `FeelerLeft` | HDV:GENERAL | +0x8b8 | FeelerLeft | FeelerLeftCenter | MEDIUM |
| `FeelerRight` | HDV:GENERAL | +0x8c4 | FeelerRight | FeelerRightCenter | MEDIUM |
| `FeelerBottom` | HDV:GENERAL | +0x8d0 | FeelerBottom | FeelerBottomPos | MEDIUM |
| `FeelerTopFrontLeft` | HDV:GENERAL | +0x8dc | FeelerTopFrontLeft | FeelerTopFrontLeftPos | MEDIUM |
| `FeelerTopFrontRight` | HDV:GENERAL | +0x8e8 | FeelerTopFrontRight | FeelerTopFrontRightPos | MEDIUM |
| `FeelerTopRearLeft` | HDV:GENERAL | +0x8f4 | FeelerTopRearLeft | FeelerTopRearLeftPos | MEDIUM |
| `FeelerTopRearRight` | HDV:GENERAL | +0x900 | FeelerTopRearRight | FeelerTopRearRightPos | MEDIUM |
| `FeelerOffset` | HDV:GENERAL | +0x90c | FeelerOffset | FeelerCgOffset | MEDIUM — offset from CG for feeler generation |
| `FeelersAtCGHeight` | HDV:GENERAL | +0x918 | FeelersAtCGHeight | FeelersAtCGHeightFlag | MEDIUM |
| `AeroDiv` | damage.ini:PHYSICAL | — | — | AeroDamageDivisor | LOW — multiplied by impulse to affect aero damage, referenced in FUN_004ce3e0 (CollisionEffectDispatch) |
| `AeroMin` | damage.ini:PHYSICAL | — | — | AeroDamageMinImpulse | LOW — minimum impulse to damage aero surfaces |
| `FrontWingCollParams` | damage.ini:PHYSICAL | — | — | FrontWingCollSpringDamperFriction | LOW — spring/damper/friction for front wing collision detachment |
| `FrontWingDetach` | damage.ini:PHYSICAL | — | — | FrontWingDetachThreshold | LOW — minimum impulse to detach front wing |
| `Engine` | damage.ini:PHYSICAL | — | — | EngineSeizeImpulse | LOW — impulse threshold to seize engine |
| `ForceFieldSphere` | damage.ini:VERTEX | — | — | ForceFieldSphereCenterRadius | LOW — Keep body verts out of radiator, used in vertex deformation (FUN_004DF110) |
| `DefaultLimit` | damage.ini:VERTEX | +0x10 (vertex group) | MaxDisplacementRadius | DefaultVertexMoveLimit | MEDIUM — default vertex movement limit for collision deformation |
| `DeformableInstance` | damage.ini:VERTEX | — | — | DeformableSlotKeyword | LOW — marks main body slot as deformable |
| `UndertrayParams` | HDV:GENERAL | — | — | UndertrayCollSpringDamperFriction | MEDIUM — undertray spring rate, damper rate, friction coefficient for bottoming-out collision |
| `AdjustSuspRates` | HDV:SUSPENSION | — | — | SuspMotionRatioAdjust | LOW — affects suspension collision feeler position calculation |
| `AlignWheels` | HDV:SUSPENSION | — | — | WheelGraphicalOffsetCorrect | LOW — corrects graphical wheel positions used in collision feelers |
| `Collision` | VEH file | — | — | CollisionMeshFile | MEDIUM — references .mts collision mesh file for the vehicle |
| `Rules` | HDV:GENERAL | — | — | GarageRulesMode | LOW — affects collision-sensitive setup rules (stockcar vs open-wheel) |
| `BaseDropoff` | HDV:BODYAERO | — | DraftBaseDropoff | DraftWakeDropoff | LOW — drafting influence on vehicle spacing/collision proximity |
| `VehicleWidth` | HDV:BODYAERO | — | — | CollisionVehicleWidth | LOW — used for drafting wake width and collision proximity |
| `Remote Vehicle Collision` | rFactor PLR | — | — | RemoteVehicleCollisionRange | MEDIUM — rFactor string: "Maximum distance from current vehicle that we will run collision on remote vehicles" — F1C equivalent likely in FUN_0045f5f0 or similar remote collision query |
| `Vehicle Removal` | rFactor PLR | — | — | StationaryVehicleRemovalTime | MEDIUM — seconds until stationary vehicle removed from track (collision cleanup) |

## String Matches

| String | Found In | F1C Function | Insight |
|--------|----------|-------------|---------|
| `%s(%d) reported contact (%.2f) with another vehicle %s(%d)` | rFactor + NASCAR | FUN_00462940 (Collision Event Network Broadcast) | Confirms collision contact reporting system. The %s(%d) format matches driver name and vehicle ID pattern. This string is part of the collision event broadcast to network peers. |
| `Adjust vehicle collision feelers to fix visuals` | NASCAR_2004_Dedicated (unique) | FUN_004e96c0 (Vehicle Wheel Contact Proximity Check) | Confirms that collision feelers can be adjusted for visual alignment. FUN_004e96c0 uses +0x828 wheelActiveFlags and +0x34d4 vehiclePos for feeler-based proximity checks. |
| `Vehicle Collision` | rFactor (string) | FUN_004b4b50 (Collision Object List Management) | Menu/option string for remote vehicle collision toggle. References collision object list management which handles vehicle-vehicle collision proxy objects. |
| `Vehicle Width` | rFactor | FUN_004e96c0 | Vehicle width used in collision proximity threshold. String `?VehicleWidth` appears in rFactor's hdvehicle.cpp. FUN_004e96c0 compares against DAT_005ad1d0 and DAT_005ad1c8 thresholds. |
| `CollObjects` | rFactor source path | FUN_0054d080 (Triangle Mesh Face Normal/AABB) | Source file `CollObjects.cpp` builds collision geometry. This function processes mesh faces with 0x30/0x40 vertex strides. |
| `searchgrid.cpp` | rFactor source path | FUN_0044a2d0 (BVH Binary Tree), FUN_0044a4b0 (BSPTreeNodeBuilder) | Source file for spatial search grid / BVH implementation. F1C BVH builder splits nodes by 14 candidate positions. |
| `hdvehicle.cpp` | rFactor source path | FUN_004e96c0 (Wheel Contact) | Vehicle physics file containing wheel contact proximity logic. Uses vehicle struct at +0x34d4. |
| `dynman.cpp` | rFactor source path | FUN_00436870 (Contact Generation) | Dynamics manager file. Contact generation and friction response is dynamics-level collision processing. |
| `Tire` | NASCAR unique strings `APP_TextValue_GarageTireLoad_FrontLeft` etc. | FUN_004e96c0 | Tire load text values reference tire contact loads. FUN_004e96c0 reads suspension bounds at +0x3b6c per wheel. |
| `Safety Car Collidable` | rFactor | FUN_004a6b80 (CollisionAvoidanceCheck) | Safety car collision toggle. FUN_004a6b80 toggles collision response based on obstruction detection. |
| `Force Formation` / `Formation Lap` | rFactor | FUN_004a6b80 | Formation lap settings affect collision avoidance during formation/start phases. |
| `Pitstop Description` | rFactor | — | "Gives extra info about what's taking time in pitstop" — relates to collision damage repair timing. |
| `DamageTime` | rFactor .hdv: PITMENU | — | "Time to fix aero damage, random delay, fix suspension including broken off wheels" — directly matches collision damage decay in FUN_0045b840. |
| `BumpStopSpring` / `BumpStopDamper` | rFactor .hdv: FRONTLEFT | FUN_0044f6f0 (Spring-Damper Controller Update) | Bump stop parameters for suspension collision limits. The spring-damper controller function updates position with integral windup matching bumpstop behavior. |
| `CollFrict` | NASCAR terrain.ini `Dry` section | FUN_00436870 (Contact Friction) | Terrain collision friction parameter. FUN_00436870 uses Coulomb friction with slip/stick threshold matching this terrain property. |
| `ActivateInstance` | damage.ini: PHYSICAL | FUN_004DF110 (Collision Deformation) | "Activate this instance if any parts get knocked off" — matches vertex group activation in deformation system. |
| `SPT` / `vehicledata.spt` | rFactor | — | Vehicle data .spt file — may contain collision-relevant telemetry data. |

## SDK Struct Alignment

Comparing rFactor SDK structs (InternalsPlugin.hpp) against F1C collision struct offsets documented in docs/17-physics-collision.md.

### TelemVect3 vs F1C vehicle position offsets

| SDK Field | SDK Offset | F1C Offset | Status |
|-----------|-----------|------------|--------|
| `TelemVect3.x` | +0x00 | +0x34d4 (VehiclePosX) | SHIFTED — F1C uses game state struct, not SDK telemetry struct. Different context: SDK telemetry vs internal physics state. |
| `TelemVect3.y` | +0x04 | +0x34d8 (VehiclePosY) | SHIFTED — same offset relationship preserved |
| `TelemVect3.z` | +0x08 | +0x34dc (VehiclePosZ) | SHIFTED — same offset relationship preserved |

### TelemWheel vs F1C wheel collision offsets

| SDK Field | SDK Offset | F1C Offset | Status |
|-----------|-----------|------------|--------|
| `mRotation` | +0x00 | — | NEW — not documented in F1C collision doc (belongs in dynamics) |
| `mSuspensionDeflection` | +0x04 | +0x3b6c (suspensionTravel) | MATCH — F1C collision docs show suspensionTravel at +0x3b6c matching deflection |
| `mRideHeight` | +0x08 | — | NEW — not documented in collision (ride height in dynamics) |
| `mTireLoad` | +0x0c | — | NEW — tire load not in collision doc (in tire system docs/04) |
| `mLateralForce` | +0x10 | +0x31c (ContactForce) | SHIFTED — F1C collision stores contact force at +0x31c, SDK at +0x10 from wheel base |
| `mGripFract` | +0x14 | — | NEW — grip fraction from brush model |
| `mBrakeTemp` | +0x18 | — | NEW — brake temperature (docs/03 engine wear) |
| `mPressure` | +0x1c | — | NEW — tire pressure |
| `mTemperature[3]` | +0x20 | — | NEW — tire temperature (docs/04) |

### TelemWheelV2 (extended, F1C-equivalent fields)

| SDK Field | SDK Offset | F1C Offset | Status |
|-----------|-----------|------------|--------|
| `mWear` | +0x2c | — | NEW — tire wear fraction (docs/04) |
| `mTerrainName[16]` | +0x30 | — | NEW — surface material name |
| `mSurfaceType` | +0x40 | — | NEW — 0=dry, 1=wet, 2=grass... |
| `mFlat` | +0x41 | — | NEW — flat tire flag |
| `mDetached` | +0x42 | — | NEW — detached wheel flag |

### Vehicle Scoring Info (VSI) vs F1C collision struct

| SDK Field | SDK Offset | F1C Offset | Status |
|-----------|-----------|------------|--------|
| `mDriverName[32]` | +0x00 | +0x4620 (DriverName) | MATCH — both offset 0x4620 for driver name in F1C vehicle struct |
| `mTotalLaps` | +0x60 | +0x403c (SeasonPoints/CurrentLap) | SHIFTED — SDK uses short, F1C uses int at different position |
| `mFinishStatus` | +0x64 | +0x4064 (FinishState) | MATCH — 0=running, 1=finished, 2=DNF, 3=DSQ |
| `mBestLapTime` | +0x70 | +0x409c (BestLapTime) | MATCH — float position |
| `mNumPitstops` | +0x8c | +0x1162 (PitStopCount) | DIFFERENT STRUCT — SDK VSI vs F1C vehicle struct are separate |
| `mPlace` (V2) | +0x9c (V2) | +0x4060 (FinishPosition) | MATCH — 1-based position |

### ScoringInfoV2 mGamePhase vs F1C RacePhase

| SDK Value | Phase | F1C Equivalent | Status |
|-----------|-------|----------------|--------|
| 0 | Before session | RacePhase? | MATCH — F1C DAT_007c56a8 (RacePhase 0-7) |
| 1 | Reconnaissance laps | — | NEW — not in F1C RacePhase documented mapping |
| 2 | Grid walk-through | — | NEW |
| 3 | Formation lap | DAT_007cebc4 (FormationLap) | MATCH |
| 4 | Starting-light countdown | — | NEW |
| 5 | Green flag | RacePhase 5 (green/racing) | PROBABLE MATCH |
| 6 | Full course yellow | — | NEW — caution state |
| 7 | Session stopped | RacePhase 7 (session over) | PROBABLE MATCH |
| 8 | Session over | RacePhase 7? | SHIFTED — F1C may have different numbering |

### SDK struct: TelemInfoBase position/orientation vs F1C collision node

| SDK Field | SDK Offset | F1C Node Offset | Status |
|-----------|-----------|-----------------|--------|
| `mPos` (TelemVect3) | +0x30 | +0x94/0x98/0x9c (node center X/Y/Z) | MATCH — F1C collision tree nodes use the same float[3] layout for position |
| `mOriX` (TelemVect3) | +0x3c | +0x224 (RotationMatrix row) | SHIFTED — F1C stores rotation matrix at different offsets in collision body |
| `mOriY` | +0x48 | +0x230 | SHIFTED |
| `mOriZ` | +0x54 | +0x23c | SHIFTED |
| `mEngineRPM` | +0x6c | — | NEW — not in collision struct |

## Proposed Renames

| Current | Proposed | Evidence |
|---------|----------|----------|
| CollisionAvoidanceCheck (FUN_004a6b80) | VehicleCollisionObstructionCheck | Uses vehicle position + direction at +0x34e0/+0x34f8, checks obstruction vs thresholds DAT_0059e918. Matches HDVehicle collision feeler checks. |
| ParticleCollisionSpawn (FUN_004c9fb0) | CollisionParticleEmitter | Spawns particles on collision surface with velocity/direction using random offsets. More descriptive verb. |
| CollisionEffectDispatch (FUN_004ce3e0) | CollisionVisualEffectDispatcher | Dispatches 3 effect types (tire spark, body spark, debris) based on collision type. Name clarifies visual effects. |
| CollisionDeformation (FUN_004DF110) | CollisionVertexDeformation | Uses binary search for vertex range, applies deformation with falloff, recomputes normals. Clarifies vertex-level operation. |
| SweptAABBOverlapDetection (FUN_004542d0) | ConstraintAABBOverlapSweep | Tests AABB overlap along one axis for constraint solver, stores contact state in DAT_007d1490 array. Uses constraint sets at +0xd88/+0x1184. |
| SpringDamperControllerUpdate (FUN_0044f6f0) | SuspensionBumpStopSpringDamper | Matches BumpStopSpring/BumpStopDamper from .hdv params. Updates spring-damper with positional tracking and integral windup. |
| CollisionResponseFilter (FUN_004584c0) | ContactVelocityRestitutionFilter | Applies restitution/penalty impulse on contact. Relative velocity resolution with restitution factor at +0xa4. |
| CollisionShapeSizeClassify (FUN_004139c0) | AABBSizeClassToBucket | Classifies collision shape by AABB size into 16 discrete categories (0x20-0x2f). Maps to spatial bucket system. |
| ParamRangeClampedLerp (FUN_0049f530) | CollisionTuningParamInterpolator | 5-case switch computing interpolated parameters for collision response tuning. Uses case-specific global inputs. |
| CollisionContactIteration (FUN_00460dd0) | CollisionResponseTypeDispatch | Iterates collision objects at DAT_005ec6d8 (stride 0x48c0), classifies as heavy/light contact, dispatches FUN_004c7a70/0x4c7aa0. |
| CollisionResponseWithRandomPerturbation (FUN_00457a00) | CollisionRestitutionScatter | Applies randomized restitution impulse to contact point for visual scatter. Three random ±1.0 signs per axis. |
| CollisionGlobalUpdateBroadcast (FUN_00455e50) | CollisionParamSyncFromGlobal | Pushes global DAT_008afe90 value into collision system via FUN_004537b0 then updates via FUN_00455bd0. |
| CollisionSpeedSetter (FUN_00498720) | CollisionBodyVelocitySetter | Sets speed/velocity from global DAT_008afe90 to collision body at +0xc0. Simple one-field setter. |
| CollisionGridCellDecoder (FUN_0049b670) | FloatToGridCellIndex | Decomposes float distance into integer grid cell index and fractional remainder via FUN_0049b630. |
| CollisionSensorInit (FUN_00464a40) | SensorStructInit | Initializes sensor state struct with default value from DAT_0059f130. Not exclusively collision — could be any timer/sensor. |
| CollisionNoiseGenerator (FUN_004962c0) | CollisionRandomInterpolator | Reads float pairs from +0x162c array, generates random values via FUN_005881f0, returns interpolated result. |
| CollisionDamageDecayProcessor (FUN_0045b840) | CollisionContactEnergyDecay | Iterates 8 contact points (stride 0x5c), decays impact energy by DAT_008afe90, spawns effects when energy > 0. |
| CollisionGeometryOperationSelector (FUN_0044bb60) | CollisionGeometryTransformDispatch | Dispatches geometry transform/update operations based on param_1 (0=transform, 1=transform+update, 2=push+transform+update+pop). |
| CollisionCullCleanup (FUN_0044efe0) | CollisionCullObjectRelease | Releases collision culling object via vtable methods at +0x20 and +0x8. |
| CollisionInvMassStore (FUN_00459950) | PhysicsMassInvMassStore | Stores mass (double at +0x180/+0x184) and computes inverse at +0x188. Calls FUN_005697a0 for inertia setup. Generic physics utility. |
| CollisionNormalFromFeature (FUN_0044c550) | CollisionFeatureNormalSolver | Computes collision normal from feature descriptor via FUN_0044c4c0. Dot/cross product then normalizes to 3D direction vector. |
| CollisionCoefficientApplication (FUN_00456f70) | ContactRestitutionCoeffSelect | Selects between DAT_0059ef9c/DAT_0059efa0 based on param_3. Scales by DAT_0059e670 if param_2==0. |
| CollisionContactImpulse (FUN_004599c0) | ContactRelativeVelocityImpulse | Computes impulse from relative velocity at contact. Stores param_3, adds bias DAT_0059e6f8, multiplies velocity by inv mass. |
| CollisionTreeNodeDeserializer (FUN_0044a700) | CollisionByteStreamNodeReader | Reads collision tree node from byte stream. Validates 4B header, reads type code (-2/-1/0/1), loads children from pool. |
| CollisionResponseCompute (FUN_0044f7f0) | ContactConstraintSolverRatio | Computes collision response using constraint data. Calculates penetration ratios and restitution-based impulse factors. |
| QuadraticSurfaceCollisionTest (FUN_0044a070) | DoublePrecisionQuadricCollisionTest | Double-precision collision test against quadratic surface. Tests 3 half-space planes, evaluates signed distance to quadric form. |
| CollisionThresholdCheck (FUN_004636a0) | VehicleSpeedThresholdComparison | Compares vehicle speed at +0x388 against threshold, branching on FUN_00461dc0() flag. |
