# Chain: NetComm Player Slot Sync — Multiplayer Join/Leave Detection and Player State Management

Seed: FUN_0045fc50  |  System: docs/09-track-system.md  |  Depth: 3  |  Functions: 30

---

## Overview

Triggered per-frame from the NetComm update loop. Scans all player slots in the session struct, detects new joins (slot became active) and departures (slot went inactive). On join: loads season/scene data, initializes per-player state, rebuilds vehicle array, notifies UI with "[name] has entered the game!" message. On leave: cleans up scene data, decrements vehicle count, reassigns current player index if the leaver was the local player. Writes DAT_005c329c (VehicleCount), DAT_007c54dc (CurrentPlayerIndex), DAT_007c54e0 (current vehicle pointer).

## Call Tree

```
FUN_0045fc50 — NetComm Player Slot Sync  [per-frame: NetComm update tick]
  +-- FUN_00461530 — Slot Active Bit Test  [checks activity mask at +0x88]
  +-- FUN_004c69e0 — Path Filename Extractor  [season data path]
  +-- FUN_00588410 — String Compare  [compares scene paths]
  +-- FUN_004c7b20 — Two-Call Delegation  [season load trigger]
  +-- FUN_00566650 — String Copy with Buffer Realloc  [path registry]
  +-- FUN_0045c030 — Struct Init with Float Defaults  [player state init]
  +-- FUN_0045c850 — Per-Element Array Reset  [player state init]
  +-- FUN_00462330 — ID Lookup in Array  [get slot ID]
  +-- FUN_004ef5a0 — SessionStateTransition  [vehicle unload: host=0/0, client=2/0]
  +-- FUN_0042bc40 — Set Player Vehicle Index (E8)  [track re-init]
  +-- FUN_004bc2f0 — Conditional Field Setter  [lap data init]
  +-- FUN_004bc320 — Field Copy (+0x68->+0x28, +0x2c->+0x24)  [lap data init]
  +-- FUN_0042bc80 — Build Active Vehicle Pointer Array  [rebuilds DAT_007c54f0]
  +-- FUN_004c6c40 — vehgen.scn File Loader  [scene generation]
  +-- FUN_004c6d90 — SceneRenderUpdate  [session render state]
  +-- FUN_004d1030 — Loop Over Two Parallel Arrays  [session state cleanup]
  +-- FUN_004e0ed0 — Audio/Sound Effect Controller  [per-vehicle audio]
  +-- FUN_0042bbd0 — Set Player Vehicle Index (DC)  [track update]
  +-- FUN_0040d100 — Game State Branch Dispatch  [session timer]
  +-- FUN_0049ca00 — Cockpit Dashboard LED/Gauge Setup  [score update]
  +-- FUN_00433870 — PhysicsSubsystemStep  [player physics init]
  +-- FUN_00465430 — Short Computation / Player Control Set  [set player control]
  +-- FUN_004c6e80 — ResetDriverGridState  [scene cleanup on leave]
  +-- FUN_00460cb0 — Clear Player Slots  [slot cleanup]
  +-- FUN_004c8de0 — Sound Effect Load/Play  [notify sound]
  +-- FUN_00423a00 — Binary Search in String Table  [string formatting]
  +-- FUN_0058815f — String Format with Buffer Overflow Check  [message format]
  +-- FUN_0045bd10 — Text Line Wrapping and Rendering  [message display]
  +-- FUN_004d7a50 — String Split Loop  [debug logging gate]
  +-- FUN_004d7aa0 — Debug Log Write  [debug trace]
```

## Step-by-Step Trace

### Level 0: FUN_0045fc50 — NetComm Player Slot Sync

**Trigger:** Per-frame — called from NetComm update tick (no callers in call_graph.json, likely called from a main loop or timer callback)
**Purpose:** Scans player slots on each tick, detects join/leave events. Loads new players and unloads disconnected ones during a multiplayer session.

**Key actions:**
1. Iterates active player slots (param_1 + 0x3e14 count, stride 0x8c starting at param_1 + 0x3d0)
2. For each slot: checks activity via FUN_00461530 (bit test at +0x88)
3. **Player join**: loads season/scene data, inits player state, rebuilds vehicle array, displays join message
4. **Player leave**: cleans up scene data, decrements VehicleCount, reassigns player index if needed
5. Updates DAT_005c3299 to match actual active count if mismatch detected

**Data passed to callees:** param_1 = session struct pointer; path strings from slot data structure

### Level 1: Key Sub-functions

**FUN_004ef5a0 — SessionStateTransition** [docs/06-session-race-logic.md]
- Called with (0,0) for host slot, (2,0) for client slot, (-1,0) on leave
- Transitions session state machine for vehicle add/remove

**FUN_004c6c40 — vehgen.scn File Loader** [docs/08-file-formats.md]
- Loads scene generation data from .scn files
- Generates vehicle appearance in the 3D world

**FUN_0042bc80 — Build Active Vehicle Pointer Array** [docs/06-session-race-logic.md]
- Scans DAT_007c54f0 (VehiclePtrArray) and rebuilds active pointer list
- Called after every join/leave to keep vehicle array consistent

**FUN_0049ca00 — Cockpit Dashboard LED/Gauge Setup** [docs/09-track-system.md]
- Updates score/position display data after roster change

**FUN_00433870 — PhysicsSubsystemStep** [docs/18-physics-dynamics.md]
- Initializes physics state for newly joined player

**FUN_004c6e80 — ResetDriverGridState** [docs/06-session-race-logic.md]
- Called on leave: resets grid position for departing driver

**FUN_0045bd10 — Text Line Wrapping and Rendering** [docs/19-renderer.md]
- Displays "[name] has entered/left the game!" messages

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_0045fc50 | Player slots array (stride 0x8c) | Iterate, check activity bit | Active/inactive slot list |
| FUN_00461530 | slot+0x88, activity mask | Bit test | bool active |
| FUN_004c69e0 | slot path string | Extract filename | Season/scene path |
| FUN_004ef5a0 | session state, mode | Transition state machine | Updated session state |
| FUN_0042bc80 | VehiclePtrArray | Rebuild active array | Consistent vehicle list |
| DAT_005c329c | VehicleCount | Increment/decrement | Updated count |

## Globals Written in This Chain

| Global | Name | Written by | Value meaning |
|--------|------|-----------|---------------|
| DAT_005c329c | VehicleCount | FUN_0045fc50 | Current active vehicle count |
| DAT_007c54dc | CurrentPlayerIndex | FUN_0045fc50 | Index of current local player |
| DAT_007c54e0 | CurrentVehiclePtr | FUN_0045fc50 | Current vehicle pointer (reassigned on leave) |
| DAT_007c54f0 | VehiclePtrArray | FUN_0042bc80 | Array of active vehicle pointers |
| DAT_005ef9a0 | VehicleGridArray | FUN_0045fc50 | Vehicle grid layout (stride 0x1230) |

## Notes

- 30 callees total, many are trivial utility functions (clamp, copy, compare)
- Heavy branching on host vs. client slot role
- Called from NetComm module — considered infrastructure, not game logic
- Cross-system: docs/09-track → docs/06-session-race (FUN_004ef5a0), docs/08-file-formats (FUN_004c6c40), docs/18-physics (FUN_00433870)

---
