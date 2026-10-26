# Broker session/environment snapshot runtime proof

Date: 2026-08-07. Broker ABI: 7.

The full-weekend path was entered with staged `f1cm_guard.asi`; QuickRace was
not used. Canonical process-local discovery negotiated ABI 7 and capability
mask `0x1F`.

```text
result=PASS discovery=0 negotiated=7 abi=7 caps=0x1F generation=1 handles=22 handle_result=0 size_result=11 stale_session=10 stale_object=12 snapshot_result=0 snapshot_seq=1 slot=0 driver=9 speed=0.000000 lap=0 events=23 cursor=23 latest=23 dropped=0 event_result=0 session_snapshot=0 session_type=5 race_phase=0 vehicles=22 wetness=0.800000 ambient=20.000 track_temp=20.000 unregister=0
```

The immutable session snapshot contains the runtime-backed session generation,
active flag, session type, race phase, vehicle count, race-active flag, race
length/time threshold, track-condition scalar, online/offline wetness, ambient
and track temperatures, and spectated slot. Numeric widths follow existing
instruction-supported global evidence.

This run proves coherent capture and retrieval on the exercised startup path.
It does not assign richer semantics to unknown enum values or prove weather
transitions, second-session retrieval, replay, or multiplayer.

The broker detached with zero active hooks/API calls and both detach results
zero. The game was stopped, all staged ASIs were removed, and configuration
remained `MODE=Off`, `LAUNCHTIME=77`.

