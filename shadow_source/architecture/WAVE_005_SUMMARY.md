# Wave 5 summary: expanded engine frontier

## Outcome

- Selected functions: 1,200.
- Function IR: 1,200 valid, 0 invalid, 0 missing.
- Generated C++ semantic maps: 1,200.
- Stage-1 architecture: 48 valid packets, 0 invalid, 0 missing.
- Total function-level shadow IR after this wave: 4,410 of 7,132 static
  functions (61.8%).
- Static functions remaining outside function IR: 2,722.

## Selection

Wave 5 expanded from the validated Wave-4 frontier. Its immutable manifest
selected 1,200 new functions; 960 were direct-edge neighbors and the remainder
came from the frontier selector's subsystem, lifecycle, and frame-path scoring.
Evidence packets and metadata are retained under
`shadow_source/waves/wave_005/`.

## Architecture partition

The 1,200 functions were divided into 48 bounded packets:

- 32 generic-runtime-object packets.
- 3 math-and-collision packets.
- 3 UI/platform/options packets.
- 3 vehicle-AI-and-pit packets.
- 7 vehicle-physics packets.

All packets passed deterministic validation after one isolated architecture
repair round. Rejected attempts remain under
`shadow_source/rejected/architecture/wave_005/`.

## Interpretation boundary

`VALID` means schema-correct, packet-grounded, complete with respect to required
material evidence, reference-safe, and trust-gated. It does not prove original
types/control flow, proposed names or class boundaries, or equivalent runtime
behavior. Behavioral confirmation still requires assembly review,
cross-function invariants, runtime observation, or differential testing.

## Verification

- Function validation: 1,200/1,200 clean.
- Architecture validation: 48/48 clean.
- Shadow-source, architecture, and reconciliation regression tests passed.
- Replacement-engine CTest passed.
- No production mod or original executable was modified.

## Next step

Use `shadow_source/waves/wave_005/manifest.json` as the Wave-6 frontier seed and
continue bounded static recovery.
