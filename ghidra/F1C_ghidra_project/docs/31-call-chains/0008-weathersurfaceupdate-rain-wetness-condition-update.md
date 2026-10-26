# Chain: WeatherSurfaceUpdate — Rain/Wetness Condition Update

Seed: FUN_004628a0  |  System: docs/17-physics-collision.md  |  Depth: 2  |  Functions: 8

---

## Overview

Called per-frame during race session when weather conditions are active. Updates weather timer/phase, checks for rain activity via FUN_004630d0. If rain is detected, updates track grip (FUN_00463760), updates weather particle system (FUN_00461610), modifies surface material properties (FUN_00462760), spawns rain particles (FUN_004b33b0), updates sky/atmosphere (FUN_00462250), and refreshes HUD (FUN_004a0dc0). Returns 1 if rain active, 0 if dry.

## Call Tree

```
FUN_004628a0 — WeatherSurfaceUpdate  [trigger: per-frame during race with weather]
  +-- FUN_00461550 — [undocumented weather timer/phase update]
  +-- FUN_004630d0 — Rain Check  [detects if rain active — returns non-zero]
  |     [reads WeatherMode global]
  +-- FUN_00463760 — Track Grip  [sets track wetness/grip coefficient]
  +-- FUN_00461610 — [undocumented weather particle system update]
  +-- FUN_00462760 — Surface Material Update  [updates surface friction properties]
  +-- FUN_004b33b0 — Particles  [spawn rain particles: params (4,5,0,0,race_time,1)]
  +-- FUN_00462250 — Sky/Atmosphere Update  [updates sky color/cloud rendering]
  +-- FUN_004a0dc0 — HUD Update  [rain indicators on HUD]
```

## Step-by-Step Trace

### Level 0: FUN_004628a0 — WeatherSurfaceUpdate

**Trigger:** Called every frame during a race session when weather is enabled.
**Called by:** Race physics update loop (per-tick).
**Purpose:** Updates all weather-dependent systems: track grip, particles, sky, HUD.

**Key actions:**
1. Calls FUN_00461550() — updates weather timer/phase
2. Calls FUN_004630d0() — detects if rain active (returns non-zero)
3. If rain active:
   - FUN_00463760(0) — sets track wetness/grip
   - FUN_00461610() — updates weather particle system
   - FUN_00462760() — updates surface material properties
   - FUN_004b33b0(4, 5, 0, 0, DAT_008afea0, 1) — spawns rain particles with current time
   - FUN_00462250() — updates sky/atmosphere rendering
   - FUN_004a0dc0() — updates HUD (rain indicators)
   - Returns 1 (rain active)
4. Returns 0 (no rain)

**Globals:**
- DAT_008afea0 — current race time (float)

**Data passed to callees:** weather state, particle type IDs (4, 5), race time from DAT_008afea0

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_004628a0 | weather state | Phase update | Updated weather phase |
| FUN_004630d0 | WeatherMode global | Rain detection | Non-zero if raining |
| FUN_00463760 | rain flag | Set grip | Track grip coefficient |
| FUN_00462760 | weather state | Surface update | Modified friction |
| FUN_004b33b0 | particle IDs (4,5), time | Spawn particles | Rain particles active |
| FUN_00462250 | weather state | Sky update | Sky color/clouds |
| FUN_004a0dc0 | weather state | HUD refresh | Rain HUD indicators |

## Globals Written in This Chain

| Global | Name | Written by | Value meaning |
|--------|------|-----------|---------------|
| DAT_008afea0 | RaceTime | (callers) | Elapsed race time, read by FUN_004b33b0 |

## Notes

- All 8 callees are leaf-level — no further recursion beyond depth 2
- FUN_00463760(track grip) gates tire friction in physics simulation
- Particle IDs 4 and 5 likely correspond to "rain spray" and "wet road" effects
- Cross-system: touches physics (track grip), renderer (particles/sky), and UI (HUD)

---

---
