# Whole-engine reconciliation comparison

Three independent DeepSeek V4 Flash/xhigh candidates were validated against the same evidence packet. Agreement is a stability signal, not a trust promotion.

## Candidate totals

| Candidate | Subsystems | Types | State machines | Interfaces | Dependencies | Contracts | Conflicts |
|---|---:|---:|---:|---:|---:|---:|---:|
| wave1_vehicle_ai_and_pit_candidate_01 | 1 | 15 | 6 | 10 | 66 | 21 | 8 |
| wave1_vehicle_ai_and_pit_candidate_02 | 3 | 14 | 6 | 10 | 37 | 21 | 9 |
| wave1_vehicle_ai_and_pit_candidate_03 | 9 | 14 | 6 | 10 | 58 | 21 | 9 |

## Agreement

- Function-to-subsystem assignments: 0/52 exact agreement.
- Class-proposal-to-type assignments: 15/16 exact agreement.

## Type-family disagreements

- `proposal:class:wave_001_vehicle_ai_and_pit_02:6`: wave1_vehicle_ai_and_pit_candidate_01=F1CVehicleSubObject; wave1_vehicle_ai_and_pit_candidate_02=F1CVehicle; wave1_vehicle_ai_and_pit_candidate_03=F1CVehicle

## Interpretation

Exact subsystem agreement is suitable as the current derived engine partition. Type-family disagreements remain explicit review targets, especially where generic `this` offsets could belong to unrelated layouts. Runtime/static corroboration is still required before promoting any proposal to confirmed SDK ABI.
