# Current shadow-engine scope

The current architecture map covers the complete eligible static function
corpus, but it is still an evidence-grounded reconstruction rather than a
behaviorally confirmed recovered engine.

## Evidence coverage

- Static recovery corpus: 7,132 functions.
- Function-level shadow IR: 7,132 functions (100% of the static corpus).
- Infrastructure Wave 2 function validation: 480/480 valid, 0 invalid,
  0 missing.
- Valid stage-1 architecture packets: 7/7.
- Valid wave-1 architecture packets: 16/16, covering 280 additional functions.
- Valid wave-2 architecture packets: 26/26, covering 480 additional
  infrastructure-focused functions.
- Wave-3 function validation: 1,200/1,200 valid, 0 invalid, 0 missing.
- Valid wave-3 architecture packets: 59/59, covering 1,200 additional
  frontier-selected functions.
- Wave-4 function validation: 1,200/1,200 valid, 0 invalid, 0 missing.
- Valid wave-4 architecture packets: 51/51, covering 1,200 additional
  frontier-selected functions.
- Wave-5 function validation: 1,200/1,200 valid, 0 invalid, 0 missing.
- Valid wave-5 architecture packets: 48/48, covering 1,200 additional
  frontier-selected functions.
- Wave-6 function validation: 1,200/1,200 valid, 0 invalid, 0 missing.
- Valid wave-6 architecture packets: 48/48, covering 1,200 additional
  frontier-selected functions.
- Wave-7 function validation: 1,200/1,200 valid, 0 invalid, 0 missing.
- Valid wave-7 architecture packets: 34/34, covering 1,200 additional
  frontier-selected functions.
- Wave-8 function validation: 322/322 valid, 0 invalid, 0 missing.
- Valid wave-8 architecture packets: 8/8, covering the final 322 eligible
  static functions.
- Independent whole-map reconciliation candidates: 3/3 valid.
- Exact function-to-subsystem agreement: 50/50 pilot functions.
- Exact class-proposal-to-type agreement: 16/21 proposals.
- Explicit disputed type mappings: 5.
- Hierarchical wave-1 reconciliation: 5/5 scopes have 3/3 valid candidates.
- Hierarchical exact assignment agreement: 4/330 functions and 124/149 class
  proposals. Low exact function agreement primarily reflects independently
  chosen subsystem labels and remains an explicit dispute, not a promotion.

## Meaning of validation

`VALID` means the result is schema-correct, numerically grounded in its bounded
packet, accounts for required material evidence, uses allowed evidence
references, and obeys trust-gating rules. It does **not** prove that IDA's
decompilation, inferred types, proposed names, object boundaries, or behavioral
interpretation match the original program. These outputs remain
evidence-grounded hypotheses until corroborated with assembly review,
cross-function invariants, runtime traces, or differential behavior tests.

## Stable pilot partition

All three independent candidates assigned the pilot functions to the same five
derived subsystems:

1. `GenericRuntimeObjects`
2. `MathAndCollision`
3. `UiPlatformAndOptions`
4. `VehicleAIPitControl`
5. `VehiclePhysics`

This agreement is a prioritization signal only. It does not promote worker
proposals to confirmed ABI or prove the original source used these boundaries.

## Next scaling milestone

All 7,132 eligible static functions now have clean function IR and architecture
coverage. Review reconciliation disputes and prioritize assembly/runtime
corroboration; promote only independently corroborated layouts and contracts
into the replacement-engine specification.
Use runtime observation and differential tests to convert the highest-value
infrastructure hypotheses from `PROPOSED` to `LIKELY` or `CONFIRMED`.
