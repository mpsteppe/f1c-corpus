# Wave 7 summary: expanded engine frontier

## Outcome

- Selected functions: 1,200.
- Function IR: 1,200 valid, 0 invalid, 0 missing.
- Generated C++ semantic maps: 1,200.
- Stage-1 architecture: 34 valid packets, 0 invalid, 0 missing.
- Total function-level shadow IR after this wave: 6,810 of 7,132 static
  functions (95.5%).
- Static functions remaining outside function IR: 322.

## Selection

Wave 7 expanded from the validated Wave-6 frontier. Its immutable manifest
selected 1,200 new functions: 312 had reverse edges to the seed and 888 were
frontier-fill selections, with direct caller/callee evidence contributing to
the scoring. Evidence packets and metadata are retained under
`shadow_source/waves/wave_007/`.

## Architecture partition

The 1,200 functions were divided into 34 bounded packets:

- 27 generic-runtime-object packets.
- 3 math-and-collision packets.
- 2 UI/platform/options packets.
- 2 vehicle-physics packets.

The initial architecture pass produced 24 valid, 8 invalid, and 2 missing
packets. All ten exceptions passed one isolated repair round. Rejected attempts
remain under `shadow_source/rejected/architecture/wave_007/`.

## Interpretation boundary

`VALID` means schema-correct, packet-grounded, complete with respect to required
material evidence, reference-safe, and trust-gated. It means evidence-grounded,
not behaviorally confirmed. It does not prove original types/control flow,
proposed names or class boundaries, or equivalent runtime behavior. Behavioral
confirmation still requires assembly review, cross-function invariants, runtime
observation, or differential testing.

## Verification

- Function validation: 1,200/1,200 clean.
- Architecture validation: 34/34 clean.
- Shadow-source, architecture, and reconciliation regression tests passed.
- Replacement-engine CTest passed.
- No production mod or original executable was modified.

## Next step

Use `shadow_source/waves/wave_007/manifest.json` as the Wave-8 frontier seed and
recover the remaining 322 eligible static functions.
