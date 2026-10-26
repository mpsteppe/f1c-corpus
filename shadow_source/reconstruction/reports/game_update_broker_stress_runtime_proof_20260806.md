# Game-update broker stress runtime proof

Date: 2026-08-06. Target: canonical `F1 Challenge Online.exe`. Broker ABI: 2.

## Gate result

The combined hostile-producer, polite-producer, and slow-callback test passed.

| Client/result | Observation |
|---|---:|
| Hostile accepted/executed | 14,040 / 14,040 |
| Hostile quota/full rejections | 8,757,488 |
| Hostile maximum accepted-task latency | 12.063 ms |
| Polite accepted/executed | 40 / 40 |
| Polite maximum latency during flood | 9.772 ms |
| Slow tasks posted/executed | 8 / 1 |
| Slow callback duration | 10.148 ms |
| Slow client quarantines | 1 |
| Slow queued tasks purged | 7 |
| Duplicate/wrong-thread executions | 0 / 0 |
| Task-count budget exhaustions | 436 |
| Aggregate-time budget exhaustions | 1 |

The broker refused an unload signal while a client registration remained, then
continued operating. After all clients retired, the repaired detach path ran
with zero active hook calls and zero API calls.

## Hardened policy

- Global task capacity: 256.
- Per-client outstanding quota: 32.
- Per-update task limit: 32.
- Per-update aggregate callback-time target: 2 ms.
- A callback exceeding 5 ms is quarantined after it returns; its token is
  invalidated and its remaining queued callbacks are purged.

The 2 ms target cannot preempt a callback already executing. The deliberately
slow callback therefore stalled one update for about 10 ms, but could not do so
again. This is a fundamental limitation of arbitrary in-process native
callbacks and supports exposing broker-owned semantic commands instead.

## Lifecycle observation

The broker was injected after the guard loaded but before the clean weekend
restart. It observed phase mask `0x00000021`: phase 0 followed by active-race
phase 5, with one transition. This expands evidence beyond phase 5 but does not
cover garage interaction, session exit, teardown, or a second session in the
same process.

## Cleanup

- QuickRace remained disabled.
- Stress clients and broker self-unloaded before process shutdown.
- The game was closed and staged guard removed.
- `config.ini` remained `MODE=Off`, `LAUNCHTIME=77`.

## Remaining gates

1. Observe session exit and a second session in the same process.
2. Remove arbitrary callback registration from the intended public surface;
   introduce a first reviewed semantic command.
3. Define packaged broker discovery/version negotiation.
4. Decide whether native fault containment is feasible; fail closed to semantic
   commands if it is not.
