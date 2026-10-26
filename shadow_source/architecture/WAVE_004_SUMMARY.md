# Wave 4 summary: expanded engine frontier

## Outcome

- Selected functions: 1,200.
- Function IR: 1,200 valid, 0 invalid, 0 missing.
- Generated C++ semantic maps: 1,200.
- Stage-1 architecture: 51 valid packets, 0 invalid, 0 missing.
- Total function-level shadow IR after this wave: 3,210 of 7,132 static
  functions (45.0%).
- Static functions remaining outside function IR: 3,922.

## Selection

Wave 4 expanded breadth-first from the validated Wave-3 frontier. Its immutable
manifest selected 1,200 new direct-edge functions, with additional typed-field,
subsystem, lifecycle, and frame-path scoring. Evidence packets and selection
metadata are retained under `shadow_source/waves/wave_004/`.

## Architecture partition

The 1,200 functions were divided into 51 bounded packets:

- 38 generic-runtime-object packets.
- 2 math-and-collision packets.
- 4 UI/platform/options packets.
- 2 vehicle-AI-and-pit packets.
- 5 vehicle-physics packets.

All packets passed deterministic validation after one isolated architecture
repair round. Rejected attempts remain under
`shadow_source/rejected/architecture/wave_004/`.

## Interpretation boundary

`VALID` means schema-correct, packet-grounded, complete with respect to required
material evidence, reference-safe, and trust-gated. It does not prove that IDA
recovered original types/control flow, that proposed names or class boundaries
are correct, or that runtime behavior matches the interpretation. Behavioral
confirmation still requires assembly review, cross-function invariants,
runtime observation, or differential testing.

## Verification

- Function validation: 1,200/1,200 clean.
- Architecture validation: 51/51 clean.
- Shadow-source, architecture, and reconciliation regression tests passed.
- Replacement-engine CTest passed.
- No production mod or original executable was modified.

## Next step

Use `shadow_source/waves/wave_004/manifest.json` as the Wave-5 frontier seed and
continue bounded static recovery with the newly verified DeepSeek credential.
