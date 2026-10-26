# SDK lifecycle R1 instruction review

Date: 2026-08-06. Scope: the bounded lifecycle anchors `0x004A0FD0`
(`RestartGate`) and `0x004EF5A0` (`SessionStateTransition`).

## Gate result

- The immutable six-task candidate wave completed with 6 valid, 0 invalid,
  and 0 missing outputs. No repair or quarantine action was required.
- Three-way reconciliation produced two `STATIC_DERIVED` records. Packet 000
  retains 6 disputes and packet 001 retains 7 disputes.
- Neither record is dependency-closed or promotion-eligible. No SDK callable,
  command, event, or hook was promoted.

`VALID` and `STATIC_DERIVED` mean evidence-grounded static results, not owner,
ABI, thread, lifecycle, hook-safety, or runtime confirmation.

## Instruction-level ABI, owner, thread, lifecycle, and hook review

| Address | Instruction-supported ABI shape | Owner/thread/lifecycle review | Whole-instruction entry window | Decision |
|---|---|---|---|---|
| `0x004A0FD0` | Live incoming `ECX`, zero explicit stack arguments, plain `ret`; thiscall-shaped. Entry copies `ECX` to `ESI`, and `0x004A111B` restores it to `ECX` for `ConditionalInitGuard`. | Its sole direct caller `0x0042D8A0` loads `ECX = 0x007CE24D`. This proves an opaque global receiver for one path, not a public owner type. Main/post-loop ancestry is static only. Flag priority, cleanup order, and the nested transition call have broad unresolved side effects; same-process second-session lifetime and reentrancy are unobserved. | 5 bytes: `A0 5D E2 7C 00`. | Keep internal as a lifecycle observation anchor; block callable and hook exposure. |
| `0x004EF5A0` | Live incoming `ECX`, exactly two 4-byte ABI slots, `ret 8`; the second slot is byte-tested. The first slot is stored at receiver `+0x32BC`. Return value is path-dependent (`a2` or a downstream helper result), so a stable semantic return contract is not proven. | Twenty-two direct calls prove broad reuse, not a concrete owner or safe standalone transition. The function overwrites the state pointer before conditional exit/entry effects and can touch a nested session object, position helpers, cleanup flags, AI speed state, and two nested fields. Thread affinity, construction/destruction ownership, recursion, stale-owner behavior, and second-session cleanup remain open. | 7 bytes: `8B 44 24 04 83 EC 30`. | Keep internal as a lifecycle investigation anchor; block callable, command, and hook exposure. |

The call at `0x004A1037` supplies two zero stack slots and sets
`ECX = player_vehicle + 0x0C` before calling `0x004EF5A0`. That call site proves
one receiver expression only. It does not establish that all 22 callers share
the same concrete owner type, nor that invoking the transition independently
preserves session lifecycle invariants.

## Promotion decision and next bounded work

No record reaches `ABI_REVIEWED`: mechanical cleanup and receiver shape are
known, but owner, thread, lifecycle, and hook unload/reentrancy gates remain
open. Do not dispatch another broad static wave. The next useful evidence is a
passive, same-process garage/session-exit/second-session trace joined to broker
discovery and ABI negotiation. Raw `0x0042C690`, `0x004A0FD0`, and
`0x004EF5A0` entry points remain internal.

Evidence artifacts:

- `reports/sdk_lifecycle_r1_candidate_validation.json`
- `reports/sdk_lifecycle_r1_instruction_export.json`
- `reconciled/sdk_lifecycle_r1.packet_000.v1.json`
- `reconciled/sdk_lifecycle_r1.packet_001.v1.json`

