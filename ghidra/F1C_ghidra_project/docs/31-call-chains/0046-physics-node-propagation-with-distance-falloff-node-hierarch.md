# Chain 45: Physics Node Propagation with Distance Falloff — Node hierarchy influence propagation

Seed: FUN_00401c90  |  System: docs/18-physics-dynamics.md  |  Depth: 3  |  Functions: 7 callees

---

## Overview

Triggered during collision detection pass. Propagates physics state through a linked node hierarchy with distance-based influence decay. Forward pass propagates influence radius outward through child links, reverse pass propagates stiffness back through parent links. Applies external force with track-grip offset.

## Call Tree

```
FUN_00401c90 — Physics Node Propagation with Distance Falloff  [trigger: collision detection update]
  +-- FUN_00401910 — Collision Detection  [initialization]
  +-- FUN_00401340 — Vehicle Suspension Force Calculation  [initialization — docs/10]
  |     +-- FUN_0044c4c0 — matrix transform
  |     +-- FUN_0044c550 — vector transform
  |     +-- FUN_00401180 — angle computation
  +-- FUN_004e8ce0 — TireForceSolver  [tire slip/lateral force — docs/06]
  |     +-- 1 leaf callee omitted
  +-- FUN_004e9100 — Tire Force / Slip Lookup with Table Interpolation  [tire look-up — docs/06]
  |     +-- 1 leaf callee omitted
  +-- FUN_004e9300 — Tire Grip/Lateral Force Calculation  [tire grip — docs/06]
  |     +-- FUN_005895a2 — sqrt
  |     +-- FUN_0059d99e — force computation
  |     +-- FUN_0059d984 — force computation
  +-- FUN_004fb260 — Linear Interpolation + Position Update  [position update — docs/18]
  +-- FUN_004faf60 — AI Opponent Relative Positioning  [relative positioning — docs/02]
        +-- FUN_005894a0 — RNG
        +-- FUN_00588570 — utility
```

## Step-by-Step Trace

### Level 0: FUN_00401c90 — Physics Node Propagation with Distance Falloff

**Trigger:** Collision detection update (called from collision detection pass).
**Called by:** FUN_004e4910 (collision detection, docs/18).
**Purpose:** Propagates physics state through linked node hierarchy with distance-based influence decay.

**Key actions:**
1. Calls FUN_00401910 and FUN_00401340 for initialization
2. For each node (stride 0x13c): computes influence radius via FUN_004e8ce0
3. Forward pass: propagates radius outward through child links (+0x10c chain)
4. Scales influence by distance ratio and parent radius
5. Reverse pass: propagates stiffness back through parent links (+0x110 chain)
6. Captures maximum influence distance at param_1+0x148
7. Applies external force DAT_0059e43c minus track-grip offset to all nodes

**Globals:** DAT_0059e43c (physics constant)

### Level 1: Key callees

**FUN_00401340 — Vehicle Suspension Force Calculation** — From docs/10. Computes suspension forces for node initialization. 3 callees: matrix transform, vector transform, angle computation.

**FUN_004e9300 — Tire Grip/Lateral Force Calculation** — From docs/06. Computes tire grip. 3 callees: sqrt, two force computation helpers.

**FUN_004faf60 — AI Opponent Relative Positioning** — From docs/02. Computes relative positions. 2 callees: RNG and utility function.

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_00401c90 | Node hierarchy | Init + forward pass + reverse pass | Propagated influence radii |
| FUN_004e8ce0 | Tire params | Tire force solve | Tire grip values |
| FUN_004e9300 | Tire grip | Lateral force calc | Lateral force |
| DAT_0059e43c | External force constant | Apply to all nodes | Node forces |

## Globals Written in This Chain

None directly — reads DAT_0059e43c.

## Notes

- Cross-system calls to docs/06 (tire functions), docs/10 (suspension), docs/02 (AI positioning)
- `hardcoded`

---
