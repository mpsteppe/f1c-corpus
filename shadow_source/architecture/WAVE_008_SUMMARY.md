# Wave 8 summary: final static-function frontier

## Outcome

- Selected functions: 322.
- Function IR: 322 valid, 0 invalid, 0 missing.
- Generated C++ semantic maps: 322.
- Stage-1 architecture: 8 valid packets, 0 invalid, 0 missing.
- Total function-level shadow IR after this wave: 7,132 of 7,132 eligible
  static functions (100%).
- Eligible static functions remaining outside function IR: 0.

## Selection

Wave 8 used the validated Wave-7 frontier to select the final 322 eligible
functions. Eleven had reverse/direct-call edges to the seed and 311 were the
remaining frontier-fill functions. Its immutable evidence packets and metadata
are retained under `shadow_source/waves/wave_008/`.

## Architecture partition

The 322 functions were divided into 8 bounded packets:

- 5 generic-runtime-object packets.
- 1 math-and-collision packet.
- 1 UI/platform/options packet.
- 1 vehicle-physics packet.

The initial architecture pass produced 7 valid and 1 invalid packet. The
exception passed one isolated repair round, and the rejected attempt remains
under `shadow_source/rejected/architecture/wave_008/`.

## Interpretation boundary

`VALID` means schema-correct, packet-grounded, complete with respect to required
material evidence, reference-safe, and trust-gated. It means evidence-grounded,
not behaviorally confirmed. Complete static coverage does not prove original
types/control flow, proposed names or class boundaries, ABI compatibility, or
equivalent runtime behavior. Those claims still require assembly review,
cross-function invariants, runtime observation, and differential testing.

## Verification

- Function validation: 322/322 clean.
- Architecture validation: 8/8 clean.
- Shadow-source, architecture, and reconciliation regression tests passed.
- Replacement-engine CTest passed.
- No production mod or original executable was modified.

## Next step

Static frontier recovery is complete. Shift effort to reconciliation review,
assembly-level corroboration, runtime validation, and implementation of reviewed
contracts in the replacement engine.
