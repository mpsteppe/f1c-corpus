# Chain: Game::Exit() — Full Game Shutdown

Seed: FUN_0042db20  |  System: docs/01-engine-architecture.md  |  Depth: 3  |  Functions: 19

---

## Overview

Full game teardown sequence called when the game state transitions to 7 (Exit). Logs entry, then calls shutdown for every subsystem in order: Sound → String buffers → Hardware Input → Game variables → OnScreen display → Video manager → UI manager → Game state machine → Session cleanup.

## Call Tree

```
FUN_0042db20 — Game::Exit()  [trigger: Game Main Entry sets state=7]
  +-- FUN_004c8d00 — Sound::Exit  [shuts down audio subsystem]
  |     +-- FUN_004c8ca0 — Sound::Post  [post-tick sound cleanup]
  |     +-- FUN_004c8630 — Virtual Dispatch + State Reset  [sound buffer teardown]
  |     +-- FUN_004c7dd0 — Field Zero +4  [zero sound system fields]
  |     +-- FUN_004c7ca0 — Network Message Receive and Dispatch  [sound net cleanup]
  |     +-- FUN_004c8ae0 — Sound::Init (teardown path)  [de-init]
  |     +-- FUN_004ba1f0 — Replay Playback Loader (Prepping Replay)  [replay cleanup]
  +-- FUN_004cfff0 — SpecialFX::Exit  [shuts down special effects]
  |     +-- FUN_00587bcf — Free Wrapper  [heap dealloc ×2]
  +-- FUN_004b0170 — Empty Stub (vtable slot)  [no-op]
  +-- FUN_00455f00 — HWInput::Exit  [shuts down DirectInput]
  |     +-- FUN_0044fbe0 [undocumented]
  |     +-- FUN_0044f5f0 [undocumented]
  |     +-- FUN_0044efe0 [undocumented]
  |     +-- FUN_004f8c90 [undocumented]
  +-- FUN_0042ca70 — DynMan::Exit  [game variables cleanup]
  |     +-- FUN_004d7a50 — debug gate
  |     +-- FUN_004d7aa0 — debug log write
  +-- FUN_004ba770 — Single Call Wrapper  [delegation call]
  |     +-- FUN_004b4030 — Render::Init (teardown path)
  +-- FUN_0049f120 — OnScreen::Exit  [shuts down HUD/display layers]
  |     +-- FUN_0049f150 — Display layer reset (forwarding call)
  |     +-- FUN_004d82a0 — Array Iteration Conditional Call (25 slots)
  +-- FUN_004fad00 — VidMan::Exit  [shuts down video manager]
  |     +-- FUN_00494900 — texture manager cleanup
  |     +-- FUN_0055c040 [undocumented]
  |     +-- FUN_004a1830 ×2 — memory cleanup
  |     +-- FUN_004a14e0 — scene object release
  |     +-- FUN_0053d4c0 — device release
  +-- FUN_00464670 — Conditional Object Cleanup  [UI manager shutdown]
  |     +-- FUN_00587bcf — Free Wrapper (×2)
  |     +-- FUN_0042d370 — game state machine teardown
  +-- FUN_0042d350 — Session Reset  [session data cleanup]
  |     +-- FUN_004a1930 — OSMan::Exit
  |     +-- FUN_00587bcf — Free Wrapper
  +-- FUN_004a1930 — OSMan::Exit  [OS manager shutdown — leaf]
```

## Key Actions

1. Writes `*param_1 = 7` — transitions game state to Exit
2. Logs "Entered Game::Exit()" via debug channel
3. Calls Sound::Exit — shuts down audio buffers, channels, network audio
4. Calls SpecialFX::Exit — effect system teardown
5. Calls HWInput::Exit — DirectInput release
6. Calls DynMan::Exit — game variable cleanup
7. Calls OnScreen::Exit — HUD/display layer shutdown
8. Calls VidMan::Exit — texture manager, device release
9. Calls UI manager + game state machine + session teardown
10. Calls OSMan::Exit — OS-level cleanup

## Globals Written

| Global | Name | Written by | Value meaning |
|--------|------|-----------|---------------|
| DAT_008afe64 | Display device handle | FUN_004fad00 → FUN_0053d4c0 | Cleared to 0 after device release |

## Notes

- Called from Game Main Entry (FUN_0045b200) state machine when state=7
- Cleanup order: audio → input → display → video → UI → session → OS
- 11 direct callees, 5 with sub-callees (depth 2-3)
- Cross-system handoffs: docs/01 (all subsystem Exit functions), docs/06 (replay), docs/09 (special FX)

---
