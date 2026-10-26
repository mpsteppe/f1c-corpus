# Whole-engine reconciliation comparison

Three independent DeepSeek V4 Flash/xhigh candidates were validated against the same evidence packet. Agreement is a stability signal, not a trust promotion.

## Candidate totals

| Candidate | Subsystems | Types | State machines | Interfaces | Dependencies | Contracts | Conflicts |
|---|---:|---:|---:|---:|---:|---:|---:|
| wave1_math_and_collision_candidate_01 | 4 | 8 | 0 | 2 | 18 | 7 | 3 |
| wave1_math_and_collision_candidate_02 | 1 | 8 | 0 | 2 | 18 | 7 | 6 |
| wave1_math_and_collision_candidate_03 | 1 | 7 | 0 | 2 | 18 | 7 | 5 |

## Agreement

- Function-to-subsystem assignments: 0/18 exact agreement.
- Class-proposal-to-type assignments: 7/8 exact agreement.

## Type-family disagreements

- `proposal:class:wave_001_math_and_collision_01:0`: wave1_math_and_collision_candidate_01=SpatialNearestNeighborQuery; wave1_math_and_collision_candidate_02=CollisionModel,SpatialNearestNeighborQuery; wave1_math_and_collision_candidate_03=CollisionModel

## Interpretation

Exact subsystem agreement is suitable as the current derived engine partition. Type-family disagreements remain explicit review targets, especially where generic `this` offsets could belong to unrelated layouts. Runtime/static corroboration is still required before promoting any proposal to confirmed SDK ABI.
