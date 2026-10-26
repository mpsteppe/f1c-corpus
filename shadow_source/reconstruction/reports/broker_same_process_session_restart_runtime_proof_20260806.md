# Broker same-process session-restart runtime proof

Date: 2026-08-06. Broker ABI: 5.

## Scenario

The game entered a full race weekend through staged `f1cm_guard.asi`; QuickRace
was not used. The broker observed RestartGate and the existing main-update
anchor. A registered probe requested one mini restart through the game-owned
`byte_7CE25D` trigger while session generation 1 and race phase 5 were active.

## Result

```text
result=PASS pid=28116 old_generation=1 new_generation=2 request=0 stale_old=10 entries_delta=1 exits_delta=1 return4_delta=1 hook_delta=6183 active=1 phase=5 unregister=0
```

- The Windows process ID remained 28116 throughout.
- RestartGate returned 4 exactly once after the request.
- The broker observed one session exit and one new session entry.
- Session generation advanced from 1 to 2.
- The second session reached active phase 5 and produced 6,183 additional main
  update calls before the result was recorded.
- A request carrying generation 1 was rejected synchronously with
  `F1C_BROKER_STALE_SESSION` (result 10).
- Client unregister succeeded.

The broker later detached both owned hooks cleanly:

```text
session_generation=2 session_entries=2 session_exits=1 return4=1
active_hooks=0 restart_hooks=0 api_calls=0 restart_detach=0 main_detach=0
```

## Interpretation

Return 4 is now runtime-observed as a same-process mini-restart boundary for the
exercised single-player path. A raw vehicle slot address is reused by the next
session, so slot address alone cannot represent object identity. The broker's
session generation is required for commands or future handles retained across
session boundaries.

This run did not observe an interactive garage state, a full return-to-menu
exit, process shutdown through the game's own UI, replay, or multiplayer.

## Cleanup

- The lifecycle client self-unloaded after unregistering.
- Both broker hooks detached byte-exactly before process shutdown.
- The game was closed after capture.
- The staged guard was removed.
- `config.ini` remained `MODE=Off`, `LAUNCHTIME=77`.
