# Chain: Vehicle Physics Velocity/Angular-Velocity Integrator — Two-Pass Force Integration

Seed: 0x00459ae0  |  System: docs/18-physics-dynamics.md  |  Depth: 1  |  Functions: 11

---

## Overview

Called from physics step (0x00438c00) each frame. Implements two-pass velocity integration: first pass computes tire contact forces across all 4 wheels, second pass applies accumulated forces to body linear/angular velocity. Iterates wheel contact list, computes slip/spring/damper forces, and integrates using sub-step solver. All 11 callees are leaf utilities — math helpers, orientation transform, wheel renderer, integration steps.

## Call Tree

```
0x00459ae0 — Vehicle Physics Velocity/Angular-Velocity Integrator  [trigger: per-frame physics step]
  +-- 0x004361d0 — [undocumented math util]
  +-- 0x0054fa00 — [undocumented physics helper]
  +-- 0x00588570 — math/random utility
  +-- 0x0054b4d0 — [undocumented]
  +-- 0x004be4e0 — wheel rendering (docs/19)
  +-- 0x0043aee0 — orientation transform
  +-- 0x0054fa90 — contact getter
  +-- 0x00459a40 — [undocumented physics helper]
  +-- 0x0054fae0 — [undocumented]
  +-- 0x00569c10 — integration step
  +-- 0x00569de0 — integration step
```

## Step-by-Step Trace

### Level 0: 0x00459ae0 — Vehicle Physics Velocity/Angular-Velocity Integrator

**Trigger:** Called per physics frame from vehicle physics step (0x00438c00)
**Called by:** 0x00438c00 (physics step, docs/18-physics-dynamics.md)
**Purpose:** Two-pass velocity integration with tire contact force computation

**Key actions:**
1. Pass 1: iterates 4 wheels via FUN_0054fa90 (contact getter), computes slip velocity, spring compression, damper force
2. Computes squared velocity components, normalizes if above _DAT_0059f058 threshold
3. Accumulates per-wheel forces into body-space force/torque via inertia tensor
4. Calls FUN_0043aee0 for orientation transform, FUN_004be4e0 for wheel rendering
5. Pass 2: calls FUN_00569c10/FUN_00569de0 for velocity integration

**Data passed to callees:** vehicle struct pointer (param_1), wheel force data, timestep

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| 0x00459ae0 | vehicle struct, dt | Pass 1: force computation | per-wheel forces |
| 0x0054fa90 | wheel index | Get contact | contact state |
| 0x0043aee0 | orientation | Transform | body-space forces |
| 0x00569c10/0x00569de0 | accumulated forces | Integrate | updated velocity |

## Globals Written in This Chain

None — all state changes on vehicle physics struct (param_1)

## Notes

- All 11 callees are leaf functions (call_count 0–2)
- Contact getter (0x0054fa90) and orientation transform (0x0043aee0) are reused across physics pipeline
- Integration step functions (0x00569c10, 0x00569de0) handle Euler/semi-implicit integration
---
