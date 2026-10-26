# Broker vehicle snapshot and polling-event runtime proof

Date: 2026-08-06. Broker ABI: 6.

## Implemented boundary

- Capability discovery with explicit current/minimum ABI versions.
- Immutable vehicle snapshots copied by the broker on the owned game thread.
- Handles containing session generation, object generation, and slot; no game
  pointer crosses the API.
- A fixed 256-record polling ring for session, phase, and vehicle lifecycle
  events with explicit dropped-record accounting.

## Runtime result

The supported executable was launched into the full-weekend path using staged
`f1cm_guard.asi`; QuickRace was not used. The broker and passive probe were
loaded through the normal ASI loader.

```text
result=PASS discovery=0 negotiated=6 abi=6 caps=0xF generation=1 handles=22 handle_result=0 size_result=11 stale_session=10 stale_object=12 snapshot_result=0 snapshot_seq=1 slot=0 driver=9 speed=0.000000 lap=0 events=23 cursor=23 latest=23 dropped=0 event_result=0 unregister=0
```

- Load-path-independent discovery selected and pinned the broker, negotiated
  ABI 6, and verified the required capabilities.
- The active session exposed 22 handles. Slot 0 returned a versioned snapshot
  from snapshot sequence 1.
- The initial event poll returned one session-start and 22 vehicle-created
  records, with no lost records.
- A zero-capacity handle query returned `F1C_BROKER_BUFFER_TOO_SMALL` (11).
- A wrong session generation returned `F1C_BROKER_STALE_SESSION` (10).
- A forged object generation returned `F1C_BROKER_STALE_OBJECT` (12).
- Client unregister succeeded.

The broker then detached cleanly:

```text
broker stopped: hook_calls=2575 posted=0 executed=0 stale=0 task_budget=0 time_budget=0 quarantines=0 max_callback_us=0 phase_mask=0x00000001 phase_transitions=0 session_generation=1 session_entries=1 session_exits=0 restart_calls=2577 return4=1 return6=0 stale_session=0 mini_restarts=0 active_hooks=0 restart_hooks=0 api_calls=0 restart_detach=0 main_detach=0
```

Raw logs are preserved beside the broker build as
`broker_snapshot_probe_runtime_log.txt` and
`f1c_game_update_broker_snapshot_v1_log.txt`.

## Scope and remaining gates

This proves the first vehicle snapshot and lifecycle-event boundary on the
exercised single-player startup path. It does not yet prove event-ring overflow,
within-session slot destruction/reuse, concurrent hostile readers, second-
session snapshot use, replay, multiplayer, or semantic lap/pit/damage events.

## Cleanup

- The probe unregistered before broker unload and both hooks detached cleanly.
- The game was stopped and all three staged ASIs were removed.
- Configuration remained `MODE=Off`, `LAUNCHTIME=77`.
