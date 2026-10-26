# Broker SetCallToBox semantic-command runtime proof

Date: 2026-08-06. Broker ABI: 3. Reviewed game function: `0x0042AC70`.

## Decision

`SetCallToBox` is the first observed broker-owned semantic command candidate.
The broker copies `{client token, vehicle slot, enabled}` into its own queue and
executes the reviewed leaf setter on the observed game thread. No client
callback or client-owned pointer is retained.

## Runtime result

- Active AI slot selected: 1 (`+0x32C8 == 1`).
- Player slot detected: 0 (`+0x32C8 == 0`).
- Original AI `CallToBox` value: 0.
- Queued AI values: 1 followed immediately by 0.
- Semantic commands executed: 2.
- Final AI value: 0, matching the original.
- Invalid value 2: rejected synchronously with `BAD_ARGUMENT`.
- Player-slot command: queued, then rejected on the game thread.
- Normal unregister: succeeded.
- Command through stale token: rejected.
- Broker detach: clean, with zero active hook/API calls.

The opposite and restoration commands were drained back-to-back before the
original game update ran, so gameplay never observed the transient value. This
proves validation, queueing, game-thread execution, and restoration without
forcing an AI strategy change during the test.

## Contract boundary

The underlying reviewed leaf accepts only 0 or 1, writes the established
`F1CVehicle+0x454C` field, and returns the input. The broker additionally
requires phase 5 and an AI-live marker equal to 1.

This does not yet prove downstream behavior after leaving the flag asserted
across a game update. Public packaging also awaits broker discovery/version
negotiation and same-process session-exit lifecycle evidence.

## Cleanup

- QuickRace remained disabled.
- Probe and broker self-unloaded before process shutdown.
- The game was closed and staged guard removed.
- `config.ini` remained `MODE=Off`, `LAUNCHTIME=77`.
