# Whole-engine reconciliation comparison

Three independent DeepSeek V4 Flash/xhigh candidates were validated against the same evidence packet. Agreement is a stability signal, not a trust promotion.

## Candidate totals

| Candidate | Subsystems | Types | State machines | Interfaces | Dependencies | Contracts | Conflicts |
|---|---:|---:|---:|---:|---:|---:|---:|
| engine_map_candidate_01 | 5 | 17 | 7 | 16 | 39 | 29 | 10 |
| engine_map_candidate_02 | 5 | 21 | 7 | 16 | 239 | 29 | 12 |
| engine_map_candidate_03 | 5 | 19 | 7 | 16 | 45 | 29 | 8 |

## Agreement

- Function-to-subsystem assignments: 50/50 exact agreement.
- Class-proposal-to-type assignments: 16/21 exact agreement.

## Type-family disagreements

- `proposal:class:generic_runtime_objects_01:1`: engine_map_candidate_01=VehiclePhysicsBody; engine_map_candidate_02=VehiclePhysicsBody_generic_runtime_objects_01; engine_map_candidate_03=VehiclePhysicsBody
- `proposal:class:generic_runtime_objects_01:2`: engine_map_candidate_01=VehiclePhysicsNode; engine_map_candidate_02=HeightfieldProximityProcessor; engine_map_candidate_03=HeightfieldProximityProcessor
- `proposal:class:math_and_collision_01:1`: engine_map_candidate_01=VehiclePhysicsNode; engine_map_candidate_02=CollisionModel; engine_map_candidate_03=CollisionModel
- `proposal:class:vehicle_physics_01:2`: engine_map_candidate_01=VehiclePhysicsBody; engine_map_candidate_02=VehiclePhysicsBody_vehicle_physics_01; engine_map_candidate_03=F1CVehicle
- `proposal:class:vehicle_physics_02a:0`: engine_map_candidate_01=VehiclePhysicsBody; engine_map_candidate_02=Vehicle; engine_map_candidate_03=F1CVehicle

## Interpretation

Exact subsystem agreement is suitable as the current derived engine partition. Type-family disagreements remain explicit review targets, especially where generic `this` offsets could belong to unrelated layouts. Runtime/static corroboration is still required before promoting any proposal to confirmed SDK ABI.
