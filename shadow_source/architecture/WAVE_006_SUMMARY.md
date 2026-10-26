# Wave 6 summary: expanded engine frontier

## Outcome

- Selected functions: 1,200.
- Function IR: 1,200 valid, 0 invalid, 0 missing.
- Generated C++ semantic maps: 1,200.
- Stage-1 architecture: 48 valid packets, 0 invalid, 0 missing.
- Total function-level shadow IR after this wave: 5,610 of 7,132 static
  functions (78.7%).
- Static functions remaining outside function IR: 1,522.

## Selection

Wave 6 expanded from the validated Wave-5 frontier. Its immutable manifest
selected 1,200 new functions; 586 have reverse edges to the seed, with direct
caller/callee, lifecycle, frame-path, subsystem, and frontier-fill evidence
providing the remaining selection signals. Evidence packets and metadata are
retained under `shadow_source/waves/wave_006/`.

## Architecture partition

The 1,200 functions were divided into 48 bounded packets:

- 37 generic-runtime-object packets.
- 3 math-and-collision packets.
- 2 UI/platform/options packets.
- 1 vehicle-AI-and-pit packet.
- 5 vehicle-physics packets.

The initial architecture pass produced 44 valid, 3 invalid, and 1 missing
packet. All four exceptions passed one isolated repair round. Rejected attempts
remain under `shadow_source/rejected/architecture/wave_006/`.

## Interpretation boundary

`VALID` means schema-correct, packet-grounded, complete with respect to required
material evidence, reference-safe, and trust-gated. It means evidence-grounded,
not behaviorally confirmed. It does not prove original types/control flow,
proposed names or class boundaries, or equivalent runtime behavior. Behavioral
confirmation still requires assembly review, cross-function invariants, runtime
observation, or differential testing.

## Verification

- Function validation: 1,200/1,200 clean.
- Architecture validation: 48/48 clean.
- Shadow-source, architecture, and reconciliation regression tests passed.
- Replacement-engine CTest passed.
- No production mod or original executable was modified.

## Next step

Use `shadow_source/waves/wave_006/manifest.json` as the Wave-7 frontier seed and
continue bounded static recovery.
