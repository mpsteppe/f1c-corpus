# Whole-engine reconciliation comparison

Three independent DeepSeek V4 Flash/xhigh candidates were validated against the same evidence packet. Agreement is a stability signal, not a trust promotion.

## Candidate totals

| Candidate | Subsystems | Types | State machines | Interfaces | Dependencies | Contracts | Conflicts |
|---|---:|---:|---:|---:|---:|---:|---:|
| wave1_vehicle_physics_candidate_01 | 6 | 23 | 9 | 32 | 48 | 36 | 6 |
| wave1_vehicle_physics_candidate_02 | 4 | 36 | 9 | 25 | 36 | 36 | 10 |
| wave1_vehicle_physics_candidate_03 | 3 | 39 | 10 | 15 | 38 | 36 | 8 |

## Agreement

- Function-to-subsystem assignments: 0/74 exact agreement.
- Class-proposal-to-type assignments: 19/42 exact agreement.

## Type-family disagreements

- `proposal:class:vehicle_physics_01:1`: wave1_vehicle_physics_candidate_01=VehicleRuntimeState; wave1_vehicle_physics_candidate_02=VehicleTireModel; wave1_vehicle_physics_candidate_03=VehicleTireModel
- `proposal:class:vehicle_physics_01:2`: wave1_vehicle_physics_candidate_01=VehicleRuntimeState; wave1_vehicle_physics_candidate_02=F1CVehicle; wave1_vehicle_physics_candidate_03=VehiclePhysicsBody
- `proposal:class:vehicle_physics_01:4`: wave1_vehicle_physics_candidate_01=VehicleRuntimeState; wave1_vehicle_physics_candidate_02=VehicleControlState; wave1_vehicle_physics_candidate_03=VehicleControlState
- `proposal:class:vehicle_physics_02a:0`: wave1_vehicle_physics_candidate_01=VehicleRuntimeState; wave1_vehicle_physics_candidate_02=F1CVehicle; wave1_vehicle_physics_candidate_03=Vehicle
- `proposal:class:vehicle_physics_02a:1`: wave1_vehicle_physics_candidate_01=VehicleTireModelData; wave1_vehicle_physics_candidate_02=TireModelData; wave1_vehicle_physics_candidate_03=TireModelData
- `proposal:class:vehicle_physics_02b:0`: wave1_vehicle_physics_candidate_01=VehicleConfigLoader; wave1_vehicle_physics_candidate_02=TheSvmHdvVehicleFileParser; wave1_vehicle_physics_candidate_03=TheSvmHdvVehicleFileParser
- `proposal:class:wave_001_vehicle_physics_01:0`: wave1_vehicle_physics_candidate_01=VehicleRuntimeState; wave1_vehicle_physics_candidate_02=F1CVehicle; wave1_vehicle_physics_candidate_03=VehiclePhysicsBody
- `proposal:class:wave_001_vehicle_physics_01:1`: wave1_vehicle_physics_candidate_01=VehiclePhysicsNode; wave1_vehicle_physics_candidate_02=VehiclePhysicsNode; wave1_vehicle_physics_candidate_03=WheelSurfaceResolver
- `proposal:class:wave_001_vehicle_physics_01:5`: wave1_vehicle_physics_candidate_01=VehicleConfigLoader; wave1_vehicle_physics_candidate_02=VehicleConfigValidator; wave1_vehicle_physics_candidate_03=VehicleConfigValidator
- `proposal:class:wave_001_vehicle_physics_01:6`: wave1_vehicle_physics_candidate_01=VehicleConfigLoader; wave1_vehicle_physics_candidate_02=SuspensionSetup; wave1_vehicle_physics_candidate_03=SuspensionSetup
- `proposal:class:wave_001_vehicle_physics_02:0`: wave1_vehicle_physics_candidate_01=CollisionSystem; wave1_vehicle_physics_candidate_02=CollisionFeatureSolver; wave1_vehicle_physics_candidate_03=CollisionFeatureSolver
- `proposal:class:wave_001_vehicle_physics_02:1`: wave1_vehicle_physics_candidate_01=CollisionSystem; wave1_vehicle_physics_candidate_02=LinkedList; wave1_vehicle_physics_candidate_03=LinkedList
- `proposal:class:wave_001_vehicle_physics_02:10`: wave1_vehicle_physics_candidate_01=VehicleRuntimeState; wave1_vehicle_physics_candidate_02=F1CVehicle; wave1_vehicle_physics_candidate_03=F1CVehicle
- `proposal:class:wave_001_vehicle_physics_02:2`: wave1_vehicle_physics_candidate_01=CollisionSystem; wave1_vehicle_physics_candidate_02=CollisionNode; wave1_vehicle_physics_candidate_03=CollisionNode
- `proposal:class:wave_001_vehicle_physics_02:3`: wave1_vehicle_physics_candidate_01=CollisionSystem; wave1_vehicle_physics_candidate_02=CollisionBroadphaseBuilder; wave1_vehicle_physics_candidate_03=CollisionBroadphaseBuilder
- `proposal:class:wave_001_vehicle_physics_02:4`: wave1_vehicle_physics_candidate_01=CollisionSystem; wave1_vehicle_physics_candidate_02=CollisionObjectListManager; wave1_vehicle_physics_candidate_03=CollisionObjectListManager
- `proposal:class:wave_001_vehicle_physics_03:0`: wave1_vehicle_physics_candidate_01=VehicleRuntimeState; wave1_vehicle_physics_candidate_02=F1CVehicle; wave1_vehicle_physics_candidate_03=VehiclePhysicsObject
- `proposal:class:wave_001_vehicle_physics_04:0`: wave1_vehicle_physics_candidate_01=VehicleRuntimeState; wave1_vehicle_physics_candidate_02=F1CVehicle; wave1_vehicle_physics_candidate_03=Vehicle
- `proposal:class:wave_001_vehicle_physics_04:4`: wave1_vehicle_physics_candidate_01=VehicleConfigLoader; wave1_vehicle_physics_candidate_02=VehicleDamageModel; wave1_vehicle_physics_candidate_03=VehicleDamageModel
- `proposal:class:wave_001_vehicle_physics_04:5`: wave1_vehicle_physics_candidate_01=VehicleConfigLoader; wave1_vehicle_physics_candidate_02=EngineSetup; wave1_vehicle_physics_candidate_03=EngineSetup
- `proposal:class:wave_001_vehicle_physics_04:6`: wave1_vehicle_physics_candidate_01=VehicleConfigLoader; wave1_vehicle_physics_candidate_02=PerWheelBrakeSuspensionDataLoader; wave1_vehicle_physics_candidate_03=PerWheelBrakeSuspensionDataLoader
- `proposal:class:wave_001_vehicle_physics_04:7`: wave1_vehicle_physics_candidate_01=VehicleConfigLoader; wave1_vehicle_physics_candidate_02=HdvFileParser; wave1_vehicle_physics_candidate_03=HdvFileParser
- `proposal:class:wave_001_vehicle_physics_04:8`: wave1_vehicle_physics_candidate_01=VehicleTireModelData; wave1_vehicle_physics_candidate_02=TireModelData; wave1_vehicle_physics_candidate_03=TireModelData

## Interpretation

Exact subsystem agreement is suitable as the current derived engine partition. Type-family disagreements remain explicit review targets, especially where generic `this` offsets could belong to unrelated layouts. Runtime/static corroboration is still required before promoting any proposal to confirmed SDK ABI.
