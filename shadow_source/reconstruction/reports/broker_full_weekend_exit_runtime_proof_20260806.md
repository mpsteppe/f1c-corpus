# Broker full-weekend exit runtime proof

Date: 2026-08-06. Broker ABI: 5.

## Scenario

The supported executable entered a full single-player race weekend through the
staged `f1cm_guard.asi` path. QuickRace was not used. The session reached the
interactive qualifying garage/monitor screen and was then exited through the
game UI.

## Preserved result

```text
broker ready: ABI=5 clients=16 queue=256 quota=32 budget=32 time_budget_us=2000 slow_us=5000
broker stopped: hook_calls=14471 posted=0 executed=0 stale=0 task_budget=0 time_budget=0 quarantines=0 max_callback_us=0 phase_mask=0x00000020 phase_transitions=0 session_generation=1 session_entries=1 session_exits=1 restart_calls=14471 return4=0 return6=1 stale_session=0 mini_restarts=0 active_hooks=0 restart_hooks=0 api_calls=0 restart_detach=0 main_detach=0
```

The raw log remains at
`mods/sdk_sandbox/game_update_broker/build/f1c_game_update_broker_log.txt`.

## Interpretation

- `RestartGate` return 6 is runtime-observed at a natural full-weekend exit on
  the exercised single-player path.
- The broker observed exactly one session entry and one exit.
- Both owned hooks detached without a byte mismatch and no API or hook calls
  remained active.
- This complements, but does not replace, the separate same-process return-4
  mini-restart and stale-generation proof.

This run does not establish replay, multiplayer, process-shutdown, or unrelated
executable-variant behavior.

## Cleanup

- The game process was stopped.
- The staged guard was removed.
- Guard configuration remained `MODE=Off`, `LAUNCHTIME=77`.

