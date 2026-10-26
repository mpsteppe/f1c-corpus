# Chain: UI Layout Dispatch with Data Prep — Position/Speed Display Layout

Seed: FUN_004db550  |  System: docs/01-engine-architecture.md  |  Depth: 2  |  Functions: 9

---

## Overview

Conditional dispatch function that reads UI layout state from DAT_007d0474, computes position/order display values, and dispatches to layout-specific render functions. Used for on-screen position/standings display during race sessions.

## Call Tree

```
FUN_004db550 — UI Layout Dispatch with Data Prep  [trigger: per-frame UI update]
  +-- FUN_0049b950 — Speed Magnitude (Alternate)  [reads vehicle speed]
  +-- FUN_0049b900 — Speed Magnitude (Rounded)  [reads rounded vehicle speed]
  +-- FUN_0049b8f0 — Engine/Rev Value Accessor  [reads engine RPM/lap data]
  +-- FUN_004db6f0 — Position/Order Name Display  [renders position/name text]
  |     +-- FUN_0049b8a0 [undocumented]
  |     +-- FUN_0049ba50 — Fuel/Weight Computation
  +-- FUN_004db9a0 — Utility Function (Number Format + UI Draw)  [number formatting]
  |     +-- FUN_004db6f0 — Position/Order Name Display
  |     +-- FUN_0049ba50 — Fuel/Weight Computation
  +-- FUN_0049b7a0 — SteeringInputToGear  [reads steering/throttle input]
  |     +-- FUN_0049b8a0 [undocumented]
  +-- FUN_004db7f0 — 8-Directional UI/Sprite Render  [renders 8-dir sprite]
  |     +-- FUN_0049b8a0 [undocumented]
  |     +-- FUN_0049ba50 — Fuel/Weight Computation
```

## Key Actions

1. Checks DAT_007d0474 for current layout/display mode
2. Reads vehicle speed (FUN_0049b950, FUN_0049b900), RPM (FUN_0049b8f0)
3. Reads steering/throttle input (FUN_0049b7a0)
4. Computes position/order name display (FUN_004db6f0)
5. Formats numbers and renders UI text (FUN_004db9a0)
6. Renders 8-directional indicator sprite (FUN_004db7f0)

## Globals Read

- `DAT_007d0474` — UI layout/display mode selector

## Notes

- 7 direct callees, all in docs/10-vehicle-physics.md or docs/06-session-race-logic.md
- Heavy use of vehicle struct accessors (speed, RPM, fuel, steering)
- Called per-frame during race UI update
- DAT_007d0474 is the layout mode gate — controls which display elements are active

---
