# Chain: Vehicle Speed Limiter & Gear Threshold Control — Speed limiting, gear change thresholds, TC

Seed: FUN_00443c07  |  System: docs/10-vehicle-physics.md  |  Depth: 6  |  Functions: ~8

---

## Overview

FUN_00443c07 manages vehicle speed limiting, gear change thresholds, and traction control. Called from the main vehicle physics update (called by FUN_00443f71), it computes delta from accumulator, handles upshift/downshift with throttle/engine braking, applies tire grip limiting, checks race phase for pit limiter, and performs traction control decay with ring buffer modulation.

## Call Tree

```
FUN_00443c07 — Vehicle Speed Limiter & Gear Threshold Control  [trigger: per-vehicle physics tick]
  +-- FUN_004ef4f0 — Position Update with Telemetry Recording  [sub: 1]
  +-- FUN_004f87c0 — HUD Element Config  [leaf]
  +-- FUN_00447160 — physics computation  [leaf]
  +-- FUN_00447e00 — Position/Lap State Update  [sub: 2]
  +-- FUN_004471f0 — SuspensionVibration  [leaf]
  +-- FUN_0058957a — Interrupt Dispatch  [leaf]
  +-- FUN_00447b10 — Random Physics Parameter Generator  [sub: 1]
```

## Step-by-Step Trace

### Level 0: FUN_00443c07 — Vehicle Speed Limiter & Gear Threshold Control

**Called by:** FUN_00443f71 (Vehicle Target Speed Blending)
**Purpose:** Manages speed limiting, gear change thresholds, traction control.

**Key actions:**
1. Computes delta from accumulator, records shift event
2. Handles upshift/downshift: throttle, engine braking
3. Tire grip limiting, torque reduction blend
4. Race phase check for pit limiter
5. Traction control decay, ring buffer modulation

### Level 1: FUN_004ef4f0 — Position Update with Telemetry Recording

**Called by:** FUN_00443c07 (position/telemetry)
**Purpose:** Updates vehicle position and records telemetry data.

### Level 1: FUN_00447e00 — Position/Lap State Update

**Called by:** FUN_00443c07 (state tracking)
**Purpose:** Updates position and lap state after speed adjustment.

### Level 1: FUN_004471f0 — SuspensionVibration

**Called by:** FUN_00443c07 (suspension response)
**Purpose:** Computes suspension vibration force based on compression state.

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_00443c07 | Speed, gear, throttle/brake inputs | Speed limiting, gear thresholds, TC | Adjusted speed, gear state, TC modulation |

## Globals Written in This Chain

None documented.

## Notes

- Called by FUN_00443f71 (Vehicle Target Speed Blending) which shares the same callee set.
- Cross-system: FUN_004ef4f0 (Position Update with Telemetry) goes to docs/06-session-race-logic.

---
