# Chain: VehicleRespawnReset — Vehicle State Reset on Respawn

Seed: FUN_004e0800  |  System: docs/10-vehicle-physics.md  |  Depth: 3  |  Functions: 9

---

## Overview

Called when a vehicle respawns after crash/retirement. Clears collision audio buffer via FUN_005506a0, sets random respawn timer, calls scene setup (FUN_004e0db0), conditionally spawns particle effect (FUN_004b33b0) for team 0/1 vehicles, resets audio state (FUN_004e0ed0), calls extended reset (FUN_004e3890) for param_2 != 0 path, resets suspension intensity (FUN_004e2ca0), clears damage timers and effect accumulators, and flips 17 damage animation slots. Reads DAT_007cf740 for max timer value.

## Call Tree

```
FUN_004e0800 — VehicleRespawnReset  [trigger: vehicle respawn — crash/restart]
  +-- FUN_005506a0 — Audio Buffer Clear  [clears audio/sound buffer for this vehicle]
  +-- FUN_004e0db0 — Scene Setup  [re-initializes vehicle scene graph transform]
  +-- FUN_004b33b0 — Particle Effect  [spawns respawn particle (team 0/1 only)]
  |     [particle system — reads DAT_008afea0 race time]
  +-- FUN_004e3890 — Extended Reset  [additional state reset — param_2 != 0 path]
  |     [may have further sub-calls]
  +-- FUN_004e0ed0 — Audio/Sound Reset  [resets engine audio state for respawn]
  +-- FUN_004e2ca0 — Suspension/Intensity Reset  [resets suspension intensity (1.0)]
  |     +-- [reads suspension struct fields]
  +-- FUN_00551810 — Conditional Entity Call  [resets effect state if active flag set]
        +-- FUN_00551210 — [undocumented lookup]
```

## Step-by-Step Trace

### Level 0: FUN_004e0800 — VehicleRespawnReset

**Trigger:** Called when vehicle is reset after crash, retirement, or pit exit.
**Called by:** Race manager/session code on respawn event.
**Purpose:** Full vehicle state reset for respawn — audio, effects, damage timers, suspension.

**Key actions:**
1. Clears flag at param_1+0x25d
2. If param_1[0x229] != 0: clears audio buffer via FUN_005506a0
3. Sets random respawn timer offset at param_1[0x253]
4. Calls FUN_004e0db0 for scene setup
5. If param_2 == 0 (normal respawn) AND team ID (13000) is 0 or 1: allocates particle slot, spawns effect via FUN_004b33b0
6. If param_2 != 0: calls FUN_004e3890 (extended reset)
7. Sets flags at param_1+0x25b and +0x96d
8. Calls FUN_004e0ed0 for audio/sound reset
9. Clears effect at +0x979
10. Calls FUN_004e2ca0 with intensity 1.0
11. Zeros 7 effect accumulator slots (param_1[0x24d..0x251], +0x252)
12. Sets damage timer indices to -1, stores max timer value from DAT_007cf740
13. If effects active (param_1[0x226]): resets all via FUN_00551810
14. Clears 17 damage animation slots (stride 7) if flag at +0x263 set

**Globals:** DAT_007cf740 (max damage timer), DAT_008afea0 (race time for particle spawn)

**Data passed to callees:** param_1 (vehicle struct), param_2 (respawn type flag)

### Level 1: FUN_004e3890 — Extended Reset

**Trigger:** Called when param_2 != 0 (extended/full reset path).
**Purpose:** Extended vehicle state reset for full respawn (pit exit or full restart).
**Data passed down:** param_1 vehicle struct, reset intensity.

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_004e0800 | param_1+0x229 | Check audio flag | Conditional audio clear |
| FUN_005506a0 | audio buffer handle | Clear buffer | Audio buffer reset |
| FUN_004e0db0 | scene node | Re-init | Scene transform reset |
| FUN_004b33b0 | team ID 0/1 check | Particle spawn | Respawn visual effect |
| FUN_004e0ed0 | audio state | Reset | Engine sound reset |
| FUN_004e2ca0 | suspension state | Reset (1.0) | Suspension intensity |
| FUN_00551810 | flag check | Conditional call | Effects reset |

## Globals Written in This Chain

| Global | Name | Written by | Value meaning |
|--------|------|-----------|---------------|
| DAT_007cf740 | MaxDamageTimer | (read by seed) | Upper bound for damage timer |

## Notes

- Two respawn paths: normal (param_2==0, with particle effect for team 0/1) and extended (param_2!=0)
- 17 damage animation slots at stride 7 suggest 7 frames per damage stage
- FUN_00551810 is a conditional dispatch guard (non-null check before call)
- Particle effect only for team 0/1 — likely player car only

---

---
