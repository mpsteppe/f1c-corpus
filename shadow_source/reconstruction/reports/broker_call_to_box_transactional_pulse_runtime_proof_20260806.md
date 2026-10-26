# Broker CallToBox transactional-pulse runtime proof

Date: 2026-08-06. Broker ABI: 4. Reviewed game function: `0x0042AC70`.

## Decision

The useful safe primitive is a one-update transactional pulse, not a pair of
writes drained before gameplay can observe them. The broker snapshots the exact
prior `F1CVehicle+0x454C` value, invokes `SetCallToBox` before the original
`0x0042C690` update, and restores the snapshot immediately after that update
returns.

Static consumer tracing confirms that `AIRacingLine` (`0x00425920`) and the
path-refresh routine (`0x00426430`) read `+0x454C` when selecting racing-line
versus pit-lane spatial nodes. The transactional API therefore opens a real
consumer execution window while bounding persistence to one original update.

## Runtime result

The full weekend was entered through staged `f1cm_guard.asi`; QuickRace was not
used.

```text
result=PASS slot=1 original=0 applied=1 final=0 queue=0 hook_delta=2 pulse_delta=1 restore_delta=1 game_changed_delta=0 unregister=0
```

- Active AI slot: 1.
- Prior CallToBox value: 0.
- Applied value during the original update: 1.
- Exact prior value restored after return: 0.
- One pulse applied and one restoration completed.
- The game did not overwrite the flag during that update.
- Client unregister succeeded.
- Broker detached with zero active hook/API calls.

The broker log closed with one posted/executed task, no stale work, no budget or
time-budget exhaustion, and `detach=0`.

## Interpretation and limit

This proves a bounded, game-update-visible command window and exact rollback.
It does not claim that one update is long enough for an AI car to visibly commit
to a pit stop. A sustained pit-call behavior test already has broader gameplay
side effects and is not required to validate the transactional rollback
mechanism. Public packaging remains gated on broker discovery/version
negotiation and same-process session-exit/second-session lifecycle evidence.

## Cleanup

- The broker unloaded cleanly before process shutdown.
- The game was closed after the capture.
- The staged guard was removed.
- `config.ini` remained `MODE=Off`, `LAUNCHTIME=77`.
