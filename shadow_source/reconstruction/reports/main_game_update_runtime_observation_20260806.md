# Main game update runtime observation

Date: 2026-08-06. Target: canonical `F1 Challenge Online.exe`. Function:
`0x0042C690`, statically named `MainGameTickUpdate`.

## Decision

`0x0042C690` is an observed internal game-thread dispatch anchor for the
exercised active-race scenario. It is not a conventional once-per-frame event
and is not promoted as a public callable function or public event.

The useful SDK boundary is a bounded command-queue drain associated with this
hook. A future public event must describe batched simulation progress rather
than imply one callback equals one rendered frame or one simulation tick.

## Scenario and safety

- The race weekend was entered through the staged `f1cm_guard.asi` menu-skip
  path. `[AUTOLAUNCH] MODE` remained `Off`; QuickRace was not used for the
  successful sample.
- `mods/sdk_sandbox/main_tick_probe/main_tick_probe.c` validated the canonical
  PE identity and exact six-byte entry window `55 8B EC 83 E4 F8` before a
  reversible detour was installed.
- The replacement called the original trampoline and only sampled mapped
  globals. Samples were buffered in memory and written after detachment.
- Detachment completed with zero active calls, zero sample overflows, and zero
  removal failures. The game remained live until the experiment was closed.
- The staged guard was removed after process exit. `config.ini` was restored to
  its prior `MODE=Off`, `LAUNCHTIME=77` state.

## Observations

| Measurement | Result |
|---|---:|
| Samples | 21,209 |
| QPC/session span | 79.897 seconds |
| Calls per second | 265.45 |
| Inter-call p50 / p95 / p99 | 3.7019 / 4.7572 / 5.3711 ms |
| Threads | one: TID 33644 |
| Receiver values | one: `0x005EC6D0` |
| Race phases | phase 5 for all samples |
| Simulation-tick advance | 31,961 ticks |
| Simulation ticks per session-second | 400.027 |
| Tick-counter regressions | 0 |
| Modulo-400 transition mismatches | 0 |

Per-call simulation deltas were 1 tick for 10,558 calls, 2 ticks for 10,570,
3 ticks for 75, 4 ticks for one, 6 ticks for one, and 7 ticks for four. This is
direct evidence that the function advances a variable-sized simulation batch.

The measured entry-to-exit duration includes the original game function; it is
not a standalone estimate of probe overhead.

## Evidence boundary

This observation proves the exercised active-race behavior only. It does not
establish garage, loading, replay, multiplayer, session transition, teardown,
or process-shutdown cadence. The receiver remains an opaque stable address;
its concrete C++ owner type is not inferred from address stability.

Raw samples are produced locally at
`mods/sdk_sandbox/main_tick_probe/build/main_tick_probe_samples.csv` and are
deliberately excluded from source control with generated DLL and log output.
That generated path was overwritten by the later dispatch-proof run; the
21,209-sample run is retained here as its adjudicated measurements rather than
as a permanent raw-data artifact.

## Next gate

Run an isolated dispatch proof: post bounded no-op tasks from one worker,
drain them at this hook, and demonstrate exactly-once execution on the observed
game thread with clean detach. Do not expose arbitrary callbacks or semantic
game mutations until that proof passes and hook coexistence has a broker.
