# Chain: Brake Temperature & Fade Model

Seed: FUN_00430a50  |  System: docs/18-physics-dynamics.md  |  Depth: 2  |  Functions: 7

---

## Overview

Computes brake disc temperature based on brake torque, cooling airflow, and material properties. Returns effective brake torque coefficient after temperature fade. Supports 3 cooling modes: dry brake (no ducts), ducted cooling, and wet/rain cooling. Uses 47 iterative thermal calculations.

## Call Tree

```
FUN_00430a50 — Brake Temperature & Fade Model  [trigger: per-vehicle brake physics update]
  +-- FUN_004d7880 — TireBrandLookup  [tire brand data — docs/10/06]
  +-- FUN_004d7570 — TireDataLookup  [tire data — docs/10/06]
  +-- FUN_004d5c70 — BrakeDataLookup  [brake material data — docs/10]
  +-- FUN_00430600 — FadeCurveLookup  [brake fade curve — leaf]
  +-- FUN_0042ed00 — SessionStateIndexedLookup  [random/state lookup — leaf]
  +-- FUN_004f6720 — EffectiveTorqueCompute  [temperature-dependent torque — docs/06]
```

## Step-by-Step Trace

### Level 0: FUN_00430a50 — Brake Temperature & Fade Model

**Trigger:** Per-vehicle brake physics update from main tick
**Called by:** FUN_004e5f60 (SuspensionAndWheelPhysics), main tick
**Purpose:** Computes brake disc temperature and fade.

**Key actions:**
1. Calls FUN_004d7880 and FUN_004d7570 to get vehicle setup data
2. Reads brake torque input (param_1+0xc44 * 0xc38 + 0xc30)
3. DAT_008aeec0 switch: 0 = dry brake (no cooling ducts), 1 = ducted cooling, 2 = wet/rain
4. For each mode: computes cooling coefficient, thermal mass, heat capacity
5. Brake fade model cases:
   - Mode 0: heat = torque * DAT_0059ea78; cooling from ambient temp; heat capacity=2
   - Mode 1: blended cooling from duct + ambient; heat capacity=4
   - Mode 2: ambient cooling only (wet brakes)
6. Computes brake torque vs temperature curve: calls FUN_00430600 (fade curve lookup)
7. For each brake disc (47 iterations): calls FUN_0042ed00 for temperature-dependent friction
8. Computes fade multiplier = sqrt(friction / temperature_factor)
9. Calls FUN_004f6720 to compute effective torque at temperature
10. Returns effective brake coefficient = (temp_friction - torque * speed^2) / inv_thermal_mass

**Data passed to callees:** Brake setup data, temperature state

### Level 1: All 6 callees

All callees are data lookup or math functions — all leaf functions.

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_00430a50 | DAT_008aeec0 | Mode select (dry/ducted/wet) | Cooling params |
| FUN_00430a50 | Brake torque + speed | Temperature change per iteration | Disc temperature |
| FUN_00430600 | Temperature | Fade curve lookup | Friction coefficient |
| FUN_00430a50 | Temperature friction | Fade multiplier | Effective brake coefficient |

## Notes

- DAT_008aeec0 controls brake duct cooling mode (moddable)
- 47 thermal iterations for disc temperature resolution
- All 6 callees are leaf data/utility functions
- Called from SuspensionAndWheelPhysics (docs/10) as part of per-vehicle physics tick

---
