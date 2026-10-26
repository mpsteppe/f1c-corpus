# SDK lifecycle R1 static review


## Worker result

The immutable `sdk_lifecycle_r1_candidate_anchors_001_manifest.json` launched
six hidden workers: three independent candidates for `RestartGate`
(`0x004A0FD0`) and three for `SessionStateTransition` (`0x004EF5A0`). All 6/6
outputs passed deterministic schema, evidence, coverage, lifecycle, layout, and
dependency validation.

Reconciliation retained six disputed fields for RestartGate and seven for
SessionStateTransition. Both records remain `STATIC_DERIVED`; neither was
promoted.

## Orchestrator review

- RestartGate has no stack arguments, returns an integer, and its entry copies
  live ECX after the first eight bytes. It is thiscall-shaped despite the raw C
  omitting the receiver parameter. Exact entry bytes are
  `A0 5D E2 7C 00 84 C0 56`.
- The raw control flow establishes request-byte consumption and return values,
  but the friendly names “mini restart” and “full restart” still require runtime
  evidence.
- Existing instruction review establishes SessionStateTransition as
  thiscall-shaped with two four-byte stack slots and `ret 8`; candidate semantic
  parameter names remain disputed.
- Neither function is a safe general-purpose public callable. RestartGate is an
  observation/trigger boundary; SessionStateTransition remains an internal
  lifecycle anchor.

The worker wave therefore justified a bounded RestartGate observer and a
game-owned request-byte experiment, not public ABI promotion.
