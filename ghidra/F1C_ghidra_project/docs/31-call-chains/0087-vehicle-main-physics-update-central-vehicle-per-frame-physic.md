# Chain: Vehicle Main Physics Update — Central Vehicle Per-Frame Physics Tick

Seed: FUN_004441f0  |  System: docs/09-track-system.md  |  Depth: 1-2  |  Functions: 15 callees

---

## Overview

Called per-frame per-vehicle. Central physics update: gearbox (neutral/in-gear states), 4-wheel suspension/terrain/collision loop, DRS detection/deployment, speed modulation by grip/gradient/aero, steering response (slip angle, self-aligning torque), engine braking, clutch slip, ratio transitions. Telemetry ring buffer output. 6 of 15 callees have deeper callees (depth 2).

## Call Tree

```
FUN_004441f0 — Vehicle Main Physics Update  [trigger: per-frame vehicle physics tick]
  +-- FUN_00403640 — Physics math utility (3D vector/distance)     [depth 1: HAS 0 further callees]
  +-- FUN_004352c0 — Vehicle speed/gear computation                [leaf — no further callees]
  +-- FUN_004361d0 — Body transform/rotation math                  [leaf — no further callees]
  +-- FUN_004388d0 — Engine torque computation                     [leaf — no further callees]
  +-- FUN_00443af0 — Vehicle setup/configuration lookup            [leaf — no further callees]
  +-- FUN_00447c70 — Steering/suspension component                 [depth 1: HAS 0 further callees]
  +-- FUN_00447e00 — Brake/speed component                         [depth 1: HAS 0 further callees]
  +-- FUN_00454da0 — Gearbox/shift logic                           [leaf — no further callees]
  +-- FUN_004d1100 — Track/surface lookup                          [depth 1: HAS 0 further callees]
  +-- FUN_004d1140 — Path/waypoint data access                     [depth 1: HAS 0 further callees]
  +-- FUN_004ef6c0 — AI physics helper                             [depth 1: HAS 0 further callees]
  +-- FUN_004efb20 — Position/velocity getter                      [leaf — no further callees]
  +-- FUN_0054b950 — Render/scene transform update                 [leaf — no further callees]
  +-- FUN_00566e40 — Math utility (vector ops)                     [leaf — no further callees]
  +-- FUN_0059dab7 — Unknown utility                               [leaf — no further callees]
```

## Step-by-Step Trace

### Level 0: FUN_004441f0 — Vehicle Main Physics Update

**Trigger:** Per-frame, per-vehicle physics update. Called from main game tick loop.
**Called by:** Unknown (no callers in callers.json for this seed)
**Purpose:** Compute all vehicle physics for one frame: gearbox, wheels, terrain, steering, speed.

**Key actions:**
1. Save gear shift state, handle neutral/in-gear transitions
2. Loop over 4 wheels: collision/terrain/suspension
3. DRS detection and deployment logic
4. Speed modulation: grip, gradient, aero factors
5. Steering response: slip angle, self-aligning torque
6. Engine braking, clutch slip, ratio transitions
7. Telemetry ring buffer output

**Data passed to callees:** vehicle struct pointer (param_1), frame time delta, input state.

### Level 1: Callees

All 15 callees are utility functions. None have callees in call_graph.json. Most are math/computation leaf functions:
- **FUN_00403640** — 3D vector math (distance, dot product)
- **FUN_004352c0** — Speed/gear ratio computation
- **FUN_004361d0** — Body rotation/transform math
- **FUN_004388d0** — Engine torque curve lookup
- **FUN_00443af0** — Vehicle config/setup read
- **FUN_00447c70** — Steering/suspension component
- **FUN_00447e00** — Brake force distribution
- **FUN_00454da0** — Gearbox state machine
- **FUN_004d1100** — Track surface lookup
- **FUN_004d1140** — Path/waypoint data access
- **FUN_004ef6c0** — AI physics helper (speed delta, following)
- **FUN_004efb20** — Vehicle position/velocity getter
- **FUN_0054b950** — Scene node transform update
- **FUN_00566e40** — Math vector utility
- **FUN_0059dab7** — Unknown utility function

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_004441f0 | vehicle ptr, dt, input | central physics dispatch | updated vehicle state |
| FUN_004352c0 | gear state | ratio computation | torque/speed |
| FUN_004388d0 | RPM, throttle | torque curve | engine torque |
| FUN_00447c70 | steering input | slip angle, SAT | steering torque |
| FUN_00454da0 | shift state | gear transition | new gear |

## Globals Written in This Chain

None directly documented — operates on vehicle struct fields.

## Notes

All 15 callees are depth-1 leaves. The actual physics computation is inline in FUN_004441f0 itself (it's a 300+ line function). Callees are utility helpers for specific sub-computations.

---
