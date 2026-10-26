# Chain 186: CollisionSparkParticleEffects — Impact Force → Visual/Audio Feedback

Seed: FUN_004ec1a0  |  System: docs/10-vehicle-physics.md  |  Depth: 3  |  Functions: 9 direct

---

## Overview

Processes collision impact forces and produces visual (spark/particle) and audio feedback. Computes impact force clamped by thresholds, dispatches to four effect groups (proximity spark, secondary contact, 8-point contact array, wheel scraping), and manages a ring buffer for spark data. Key sub-chain through SteeringGeometryUpdate (FUN_00442060) and Repair/Service Dispatcher (FUN_004ed250).

## Call Tree

```
FUN_004ec1a0 — CollisionSparkParticleEffects  [per-frame collision feedback]
  +-- FUN_004efae0 — TireScrubReset  [resets tire scrub state]
  |     +-- FUN_00447280 — [unnamed — scrub reset helper]
  +-- FUN_004ed1c0 — Float Parameter Forwarder  [passes collision params]
  +-- FUN_004ed1f0 — Force Application Router  [routes force data to effect groups]
  +-- FUN_004ed220 — PhysicsTimeStep  [reads time delta for effect intensity]
  +-- FUN_004b33b0 — [shared utility]  [random/ring buffer access]
  +-- FUN_004a56b0 — StateTransition  [audio event trigger]
  +-- FUN_004ed250 — Repair/Service State Dispatcher  [6 callees — wheel/suspension/wing state]
  |     +-- FUN_004e0e70 — Wheel Repair  [wheel state check]
  |     +-- FUN_0043e770 — Suspension?  [suspension damage check]
  |     +-- FUN_0041afd0 — Part Repair  [generic part state]
  |     +-- FUN_004e0d70 — Wing/Part Service  [wing damage check]
  |     +-- FUN_004a56b0 — Audio  [additional audio trigger]
  |     +-- FUN_004e8010 — Tire Model Solver  [tire state computation]
  +-- FUN_004ed250 — [duplicate from above — repair/service path]
  +-- FUN_00411330 — Short Computation (Vehicle Parameter Setter)  [3 callees — spawn position]
  |     +-- FUN_0040e770 — [position helper]
  |     +-- FUN_0040eec0 — [position helper]
  |     +-- FUN_0040ef70 — [position helper]
  +-- FUN_00442060 — SteeringGeometryUpdate  [4 callees — wheel geometry update]
        +-- FUN_00441450 — [geometry refresh]
        +-- FUN_00435e00 — [math/transform]
        +-- FUN_004388d0 — [vehicle setup]
        +-- FUN_0056d020 — [math utility]
```

## Step-by-Step Trace

### Level 0: FUN_004ec1a0 — CollisionSparkParticleEffects

**Trigger:** Called per-frame from physics update when a collision/contact event occurs.

**Called by:** Vehicle physics update dispatch (callers.json shows 1 caller from docs/10-vehicle-physics.md).

**Purpose:** Processes impact forces, produces visual/audio feedback (sparks, particles, scraping sounds).

**Key actions:**
1. Computes impact force, clamped by threshold values
2. Four effect groups:
   - Proximity spark (near-miss effect)
   - Secondary contact (light touch)
   - 8 contact points array (full collision)
   - Wheel scraping (continuous contact)
3. Lock/unlock effect management
4. Ring buffer for spark position/intensity data
5. Threshold comparison for effect intensity scaling

**Data passed to callees:** Impact force (float), vehicle pointer, contact point data, threshold constants

### Level 1: Key Callees

**FUN_004efae0 — TireScrubReset**
- 1 callee (FUN_00447280)
- Resets tire scrub state after collision event
- Clears accumulated scrub data for fresh computation

**FUN_004ed250 — Repair/Service State Dispatcher**
- 6 callees — the largest sub-tree in this chain
- Checks wheel repair state, suspension damage, part wear, wing service status, tire state
- Routes to specific repair handlers per component
- Dual occurrence in call tree due to being called for two different contact types

**FUN_00442060 — SteeringGeometryUpdate**
- 4 callees — updates steering/suspension geometry after impact
- Computes per-wheel steering angle, applies rotation to suspension components
- Checks accumulated steering angle against damage threshold

**FUN_00411330 — Short Computation (Vehicle Parameter Setter)**
- 3 callees — helper functions for position/spawn data
- Sets vehicle position parameters after collision displacement

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| Impact force | velocity delta | Clamp by threshold | Effective impact force |
| Effect group dispatch | force, contact type | Route to 4 groups | Spark/particle/audio commands |
| FUN_004ed250 | vehicle ptr, contact type | Check component states | Damage state per component |
| FUN_00442060 | steering angle delta | Update geometry | Steering/suspension updated |
| Ring buffer | spark data (pos, intensity) | Store/rotate | Buffered spark data |

## Notes

- FUN_004ed250 and FUN_00411330 have the deepest sub-trees (levels 2-3)
- Audio feedback is triggered through FUN_004a56b0 (nested inside FUN_004ed250)
- Four effect groups have independent threshold-based activation
- The ring buffer (DAT_008aae70 indexed) provides random variation for spark positioning
- FUN_00442060 (SteeringGeometryUpdate) is documented separately at docs/10-vehicle-physics.md:997

---
