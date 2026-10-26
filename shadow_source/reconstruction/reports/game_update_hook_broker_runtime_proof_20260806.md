# Game-update hook broker runtime proof

Date: 2026-08-06. Target: canonical `F1 Challenge Online.exe`. Internal hook:
`0x0042C690`.

## Gate result

The isolated single-owner broker and two-client coexistence test passed.

| Measurement | Result |
|---|---:|
| Registered clients | 2 |
| Tasks posted | 512 |
| Tasks executed | 512 |
| Missing tasks | 0 |
| Duplicate executions | 0 |
| Wrong-thread executions | 0 |
| Shared hook thread | TID 40376 |
| Self-unregister attempts | both refused with `WOULD_DEADLOCK` |
| Normal unregisters | both succeeded |
| Posts through stale tokens | both rejected |
| Per-update task budget | 32 |
| Budget exhaustion observations | 10 |
| Broker detach | success; zero active hooks/API calls |

Both clients registered before posting. Each independently posted 256
persistent no-op tasks, verified exactly-once execution, unregistered, checked
that its stale token was rejected, and self-unloaded before broker shutdown.

## Conflict test

While the primary broker owned the hook, a second broker image attempted to
install the same exact-byte detour. Installation failed closed with
`F1C_DETOUR_BYTES_MISMATCH` (`result=3`). The primary broker remained live and
later detached normally.

## Capability boundary

This proves one broker can safely own the observed hook and transport bounded
tasks for two cooperative clients in the exercised session. It does not prove
fair scheduling under hostile sustained producers, lifecycle behavior outside
the exercised session, native callback fault containment, or the semantic
safety of any state-changing command.

The implementation remains isolated under
`mods/sdk_sandbox/game_update_broker`. Arbitrary callback registration is not
promoted into the canonical public SDK. The preferred production surface is a
small set of broker-owned semantic commands and observations.

## Cleanup

- Launch used staged `f1cm_guard.asi`; QuickRace remained disabled.
- Both clients self-unloaded, then the broker self-unloaded cleanly.
- The game was closed and the staged guard removed.
- The temporary second-broker image and log were removed.
- `config.ini` remained `MODE=Off`, `LAUNCHTIME=77`.

## Next gates

1. Observe broker install, idle operation, and detach across loading, garage,
   active race, session exit, and a second session.
2. Test a sustained hostile producer and a deliberately slow callback against
   the global/per-client budgets.
3. Replace arbitrary callbacks with the first independently reviewed semantic
   command and an observation subscription that cannot call into unloaded code.
4. Define process-wide broker discovery/version negotiation for packaged mods.
