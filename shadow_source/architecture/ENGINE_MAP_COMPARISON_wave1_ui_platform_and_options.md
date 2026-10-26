# Whole-engine reconciliation comparison

Three independent DeepSeek V4 Flash/xhigh candidates were validated against the same evidence packet. Agreement is a stability signal, not a trust promotion.

## Candidate totals

| Candidate | Subsystems | Types | State machines | Interfaces | Dependencies | Contracts | Conflicts |
|---|---:|---:|---:|---:|---:|---:|---:|
| wave1_ui_platform_and_options_candidate_01 | 1 | 3 | 2 | 2 | 23 | 5 | 4 |
| wave1_ui_platform_and_options_candidate_02 | 1 | 3 | 2 | 2 | 23 | 5 | 3 |
| wave1_ui_platform_and_options_candidate_03 | 2 | 3 | 2 | 2 | 23 | 5 | 3 |

## Agreement

- Function-to-subsystem assignments: 4/6 exact agreement.
- Class-proposal-to-type assignments: 3/3 exact agreement.

## Type-family disagreements

None.

## Interpretation

Exact subsystem agreement is suitable as the current derived engine partition. Type-family disagreements remain explicit review targets, especially where generic `this` offsets could belong to unrelated layouts. Runtime/static corroboration is still required before promoting any proposal to confirmed SDK ABI.
