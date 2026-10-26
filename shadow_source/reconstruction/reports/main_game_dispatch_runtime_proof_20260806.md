# Main game-thread dispatch runtime proof

Date: 2026-08-06. Target: canonical `F1 Challenge Online.exe`. Internal hook:
`0x0042C690`.

## Gate result

The bounded single-producer/single-consumer dispatch proof passed:

| Measurement | Result |
|---|---:|
| Tasks posted from DLL worker | 256 |
| Tasks executed in update hook | 256 |
| Missing tasks | 0 |
| Duplicate executions | 0 |
| Wrong-thread executions | 0 |
| Hook thread | TID 18252 |
| Queue drain thread | TID 18252 |

The probe recorded 3,843 update calls during this short run. It detached with
zero active calls, zero sample overflow, and zero removal failures.

## Interpretation

The existing `F1CGameDispatch` queue can carry bounded tasks from one worker to
the observed game thread when an SDK-owned hook drains it at `0x0042C690`.
This proves the transport mechanism and exactly-once behavior for the exercised
run. It does not make arbitrary game functions safe to invoke: each semantic
command still requires its own ABI, ownership, lifetime, and phase contract.

The raw update function remains internal. Independent mods must not install
competing detours at this address; a single hook broker must own the entry patch
and provide dispatch/subscription services.

## Scenario and cleanup

- The launch used staged `f1cm_guard.asi` and the clean weekend `Restart` path.
- `[AUTOLAUNCH] MODE` remained `Off`; QuickRace was not used.
- Tasks were persistent no-op records; they did not mutate semantic game state.
- The probe self-unloaded before the process was closed.
- The staged guard was removed after process exit.
- `config.ini` remained `MODE=Off`, `LAUNCHTIME=77`.

## Remaining gates

1. Give one SDK broker exclusive ownership of the hook and detect conflicts.
2. Observe loading, garage, session exit, and a second session.
3. Integrate the SDK's bounded drain into the broker and prove its declared
   per-update task budget under a continuously replenished queue.
4. Validate the first semantic command independently before dispatch exposure.
5. Add executable-variant resolution before supporting another binary.
