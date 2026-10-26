# Wave 3 summary: expanded engine frontier

## Outcome

- Selected functions: 1,200.
- Function IR: 1,200 valid, 0 invalid, 0 missing.
- Generated C++ semantic maps: 1,200.
- Stage-1 architecture: 59 valid packets, 0 invalid, 0 missing.
- Total function-level shadow IR after this wave: 2,010 of 7,132 static
  functions (28.2%).
- Static functions remaining outside function IR: 5,122.

## Selection

Wave 3 expanded breadth-first from the validated Wave-2 frontier. Its immutable
manifest selected 1,200 new direct-edge functions, with additional typed-field,
subsystem, lifecycle, and frame-path scoring supplied by the frontier selector.
The exact selection and evidence packets are retained under
`shadow_source/waves/wave_003/`.

## Architecture partition

The 1,200 functions were divided into 59 bounded packets:

- 42 generic-runtime-object packets.
- 2 math-and-collision packets.
- 5 UI/platform/options packets.
- 4 vehicle-AI-and-pit packets.
- 6 vehicle-physics packets.

All packets passed deterministic validation after two isolated architecture
repair rounds. Rejected attempts remain under
`shadow_source/rejected/architecture/wave_003/`.

## Interpretation boundary

`VALID` here means schema-correct, packet-grounded, complete with respect to
required material evidence, reference-safe, and trust-gated. It does not prove
that IDA recovered the original types/control flow, that a proposed name or
class boundary is correct, or that runtime behavior matches the interpretation.
Behavioral confirmation still requires assembly review, cross-function
invariants, runtime observation, or differential tests.

## Verification

- Function validation: 1,200/1,200 clean.
- Architecture validation: 59/59 clean.
- Shadow-source, architecture, and reconciliation regression tests passed.
- Replacement-engine CTest passed.
- No production mod or original executable was modified.

## Next step

Use `shadow_source/waves/wave_003/manifest.json` as the Wave-4 frontier seed and
continue bounded static recovery. In parallel, runtime-confirm high-value
contracts before relying on them as replacement-engine behavior.
