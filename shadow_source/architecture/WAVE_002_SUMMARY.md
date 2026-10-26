# Wave 2 summary: engine infrastructure

## Outcome

- Selected functions: 480.
- Function IR: 480 valid, 0 invalid, 0 missing.
- Generated C++ semantic maps: 480.
- Stage-1 architecture: 26 valid packets, 0 invalid, 0 missing.
- Total function-level shadow IR after this wave: 810 of 7,132 static
  functions (11.4%).

## Selection

Wave 2 used the `infrastructure` focus. It prioritized startup and main-loop
paths, configuration and INI handling, archive/MAS and filesystem access,
loading, rendering and Direct3D, window/input, audio, sessions, plugins, and
direct callers/callees of those roots. The immutable selection is recorded in
`shadow_source/waves/wave_002/manifest.json`.

## Architecture partition

The 480 functions were divided into 26 bounded packets:

- 19 generic-runtime-object packets.
- 1 math-and-collision packet.
- 2 UI/platform/options packets.
- 2 vehicle-AI-and-pit packets.
- 2 vehicle-physics packets.

All packets passed deterministic architecture validation after isolated repair
of five initial missing/invalid results. Rejected attempts are retained under
`shadow_source/rejected/` for auditability.

## Interpretation boundary

These are validated **pipeline artifacts**, not 480 proven original functions.
Validation establishes schema correctness, packet grounding, required-evidence
coverage, reference integrity, and trust gating. It cannot prove IDA's control
flow or types, the worker's proposed intent, or runtime behavior. Every result
therefore remains a hypothesis unless independently corroborated through raw
assembly review, cross-function consistency, runtime observation, or
differential execution against a replacement implementation.

## Infrastructure improvement made during the wave

auto-closing wrappers. Completed workers now release scheduler slots after a
brief filesystem settle; missing outputs go directly to deterministic retry
instead of leaving dead wrappers occupying slots for 20 minutes.

## Next step

Use `shadow_source/waves/wave_002/manifest.json` as the Wave-3 frontier seed.
In parallel, select high-value Wave-2 infrastructure contracts for assembly
review and runtime/differential validation before the replacement engine relies
on them as confirmed behavior.
