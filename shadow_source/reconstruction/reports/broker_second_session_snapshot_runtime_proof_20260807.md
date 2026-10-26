# Broker second-session snapshot runtime proof

Date: 2026-08-07. Broker ABI: 7.

The supported game entered a full weekend through staged `f1cm_guard.asi`.
QuickRace was not used. Canonical discovery selected and pinned the broker. At
active phase 5, the probe captured handles and a vehicle snapshot, requested
the reviewed game-owned mini restart, then repeated the observation in the new
session without changing process.

```text
result=PASS pid=40292 old_generation=1 new_generation=2 request=0 stale_old=10 first_handles=0 first_count=22 first_snapshot=0 old_snapshot=10 second_handles=0 second_count=22 second_snapshot=0 entries_delta=1 exits_delta=1 return4_delta=1 hook_delta=5843 active=1 phase=5 unregister=0
```

- Session 1 returned 22 generation-safe handles and a valid snapshot.
- The process remained PID 40292 while generation advanced 1 to 2.
- The retained session-1 handle failed with `F1C_BROKER_STALE_SESSION`.
- Session 2 returned 22 fresh handles and a valid snapshot.
- The broker observed one exit, one entry, one return-4 boundary, and 5,843
  intervening update calls.
- Client unregister and canonical discovery release succeeded.

The broker subsequently reported zero active hooks/API calls and zero detach
errors. The game was stopped, staged ASIs were removed, and configuration
remained `MODE=Off`, `LAUNCHTIME=77`.

This closes the second-session gate for vehicle handles/snapshots on the
exercised single-player mini-restart path. Within-session slot destruction/reuse,
hostile concurrent readers, replay, and multiplayer remain separate gates.

