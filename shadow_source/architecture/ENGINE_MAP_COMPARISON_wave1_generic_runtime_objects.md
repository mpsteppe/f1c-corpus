# Whole-engine reconciliation comparison

Three independent DeepSeek V4 Flash/xhigh candidates were validated against the same evidence packet. Agreement is a stability signal, not a trust promotion.

## Candidate totals

| Candidate | Subsystems | Types | State machines | Interfaces | Dependencies | Contracts | Conflicts |
|---|---:|---:|---:|---:|---:|---:|---:|
| wave1_generic_runtime_objects_candidate_01 | 1 | 78 | 10 | 21 | 297 | 45 | 6 |
| wave1_generic_runtime_objects_candidate_02 | 8 | 78 | 10 | 21 | 297 | 45 | 10 |
| wave1_generic_runtime_objects_candidate_03 | 1 | 78 | 10 | 21 | 297 | 45 | 8 |

## Agreement

- Function-to-subsystem assignments: 0/180 exact agreement.
- Class-proposal-to-type assignments: 80/80 exact agreement.

## Type-family disagreements

None.

## Interpretation

Exact subsystem agreement is suitable as the current derived engine partition. Type-family disagreements remain explicit review targets, especially where generic `this` offsets could belong to unrelated layouts. Runtime/static corroboration is still required before promoting any proposal to confirmed SDK ABI.
