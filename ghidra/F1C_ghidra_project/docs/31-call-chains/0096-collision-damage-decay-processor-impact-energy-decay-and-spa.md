# Chain: Collision Damage Decay Processor — Impact Energy Decay and Spark Effects

Seed: FUN_0045b840  |  System: docs/17-physics-collision.md  |  Depth: 1-2  |  Functions: 5 callees

---

## Overview

Processes collision damage decay each frame. Iterates 8 contact points (stride 0x5c), decays impact energy by constant (_DAT_008afe90), spawns spark effects when energy > 0, updates contact state. Limits to 4 active contacts per frame.

## Call Tree

```
FUN_0045b840 — Collision Damage Decay Processor  [trigger: per-frame physics collision post-step]
  +-- FUN_0045bb00 — Pre-process (clear flags)                       [leaf]
  +-- FUN_0045b660 — Setup (initialize contact array)                [depth 1: HAS 0 callees]
  +-- FUN_004dcf30 — Get current frame/tick                          [leaf]
  +-- FUN_004dd030 — Spawn particle/spark effect                     [leaf]
  +-- FUN_0045b430 — Contact update (process active contact)         [leaf]
```

## Step-by-Step Trace

### Level 0: FUN_0045b840 — Collision Damage Decay Processor

**Trigger:** Per-frame, after collision detection resolves contacts.
**Called by:** Unknown (callers.json shows 1 caller — from collision pipeline post-step)
**Purpose:** Decay collision impact energy over time, trigger visual effects on threshold.

**Key actions:**
1. Call FUN_0045bb00 (pre-process): FLAG byte at param_1+800 = 0
2. Call FUN_0045b660 (setup): Initialize contact processing state
3. Call FUN_004dcf30: Get current frame/tick count
4. Loop 8 iterations over contact points (stride 0x5c):
   - If impact energy at +0x90 > 0.0f (DAT_0059e440):
     - Call FUN_004dd030 (spawn effect) with position +0x3c, energy/2
     - Reduce energy by _DAT_008afe90 (decay constant)
     - If energy < 0.0: set param_1+800 = 1 (done flag)
     - Else: call FUN_0045b430 (contact processing)
5. Max 4 active contacts per frame (local_14 < 3)

**Data passed to callees:** collision state struct (param_1), contact indices, energy values.

### Level 1: Callees

- **FUN_0045bb00 (pre-process):** Clears decay done flag, resets per-frame state.
- **FUN_0045b660 (setup):** Initializes contact array, prepares for iteration.
- **FUN_004dcf30 (get tick):** Returns current engine tick/frame counter.
- **FUN_004dd030 (spawn effect):** Creates particle/spark effect at contact position, scaled by energy.
- **FUN_0045b430 (contact update):** Processes active contact — updates penetration, applies residual force.

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_0045b840 | collisionState ptr | iterate 8 contacts | decayed energy, effects |
| FUN_0045bb00 | state ptr | clear flag | ready state |
| FUN_0045b660 | state ptr | init arrays | initialized contacts |
| FUN_004dcf30 | none | tick query | frame count |
| FUN_004dd030 | pos, energy | spawn | particle effect |
| FUN_0045b430 | contact ptr | process | updated contact |

## Globals Written in This Chain

| Global | Name | Written by | Value meaning |
|--------|------|-----------|---------------|
| DAT_0059e440 | ZeroThreshold | FUN_0045b840 (read) | 0.0f compare threshold |
| DAT_008afe90 | EnergyDecayRate | FUN_0045b840 (read/decay) | collision energy decay constant |

## Notes

Chain depth 1. Moddability: configurable — collision energy decay rate can be tuned via physics file fields. 8 contact slots with stride 0x5c, limit 4 active per frame.

---
